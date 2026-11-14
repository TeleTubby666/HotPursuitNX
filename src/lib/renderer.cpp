#include <lib/renderer.h>
#include <lib/window.h>
#include <lib/gamepad.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>
#include <GL/gl.h>

namespace win32
{

/* measurement: where the time of a frame goes (one line every 5 seconds) */
namespace
{
    struct Perf
    {
        Uint64 windowStart, uploadNs, drawNs, swapNs, contextNs, lastFlip, flipGapMaxNs;
        unsigned flips, frontUnlocks;
    };
    Perf s_perf = {};

    void perfReport()
    {
        const Uint64 now = SDL_GetTicksNS();
        if (!s_perf.windowStart)
            s_perf.windowStart = now;
        const Uint64 span = now - s_perf.windowStart;
        if (span < 5000000000ull)
            return;
        const unsigned presents = s_perf.flips + s_perf.frontUnlocks;
        const double seconds = span / 1e9;
        const double inPresent = (s_perf.uploadNs + s_perf.drawNs + s_perf.swapNs + s_perf.contextNs) / 1e6;
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                    "perf: %.1f flips/s, %.1f front unlocks/s; per present: upload %.2f ms, draw %.2f ms, swap %.2f ms, context %.2f ms; "
                    "%.0f%% of the time in present, longest frame %.0f ms",
                    s_perf.flips / seconds, s_perf.frontUnlocks / seconds,
                    presents ? s_perf.uploadNs / 1e6 / presents : 0.0, presents ? s_perf.drawNs / 1e6 / presents : 0.0,
                    presents ? s_perf.swapNs / 1e6 / presents : 0.0, presents ? s_perf.contextNs / 1e6 / presents : 0.0,
                    inPresent / (seconds * 10.0), s_perf.flipGapMaxNs / 1e6);
        const Uint64 lastFlip = s_perf.lastFlip;
        s_perf = Perf();
        s_perf.windowStart = now;
        s_perf.lastFlip = lastFlip;
    }
}

void GLAPIENTRY errorCallback(GLenum /*source*/, GLenum type, GLuint /*id*/, GLenum severity, GLsizei /*length*/, const GLchar* message, const void* /*userParam*/)
{
    if (severity != GL_DEBUG_SEVERITY_NOTIFICATION)
    SDL_LogError(SDL_LOG_CATEGORY_RENDER, "OpenGL: %s type = 0x%x, severity = 0x%x, \"%s\"\n",
            (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
            type, severity, message);
}
PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;

Renderer::Renderer(WinApplication* application, Window *window)
    :   m_application(application)
    ,   m_window(window)
    ,   m_renderer(SDL_GL_CreateContext(m_window->m_window))
    ,   m_videoMemory(new MemMap(800*600*2*2)) // double buffer 16 bits 800x600
    ,   m_currentBuffer(0)
    ,   m_depth(16)
    ,   m_colorPalette()
{
    setCurrent();
    SDL_GL_SetSwapInterval(1);
    glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)SDL_GL_GetProcAddress("glDebugMessageCallback");
    if (glDebugMessageCallback)
    {
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(errorCallback, 0);
    }

    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);
    glEnable(GL_TEXTURE_2D);

    clearCurrent();
}

Renderer::~Renderer()
{
    SDL_GL_DestroyContext(static_cast<SDL_GLContext>(m_renderer));
}

void Renderer::setCurrent()
{
    SDL_GL_MakeCurrent(m_window->m_window, static_cast<SDL_GLContext>(m_renderer));
}

void Renderer::clearCurrent()
{
    SDL_GL_MakeCurrent(m_window->m_window, nullptr);
}

void Renderer::setVideoMode(x86::reg32 w, x86::reg32 h, x86::reg32 bpp)
{
    m_width = w;
    m_height = h;
    m_depth = bpp;
    setCurrent();
    glBindTexture(GL_TEXTURE_2D, m_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, nullptr);
    clearCurrent();
    //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, nullptr);
}

void Renderer::updatePalette(x86::reg32 colorCount, const x86::reg32* colors)
{
    NFS2_ASSERT(colorCount <= 256);
    memcpy(m_colorPalette, colors, colorCount*4);
}

x86::reg32 Renderer::getFrontBuffer() const
{
    return m_videoMemory->getBlockStart() + m_currentBuffer * m_width * m_height * 2;
}

x86::reg32 Renderer::getBackBuffer() const
{
    return m_videoMemory->getBlockStart() + (1 - m_currentBuffer) * m_width * m_height * 2;
}

void Renderer::present()
{
    Gamepad::updateKeys();
    glBindTexture(GL_TEXTURE_2D, m_texture);
    int w, h;
    SDL_GetWindowSizeInPixels(m_window->m_window, &w, &h);

    float gameAspect = float(m_width) / float(m_height);
    float windowAspect = float(w) / float(h);
    int vpX, vpY, vpW, vpH;
    if (windowAspect > gameAspect)
    {
        vpH = h;
        vpW = int(h * gameAspect + 0.5f);
        vpX = (w - vpW) / 2;
        vpY = 0;
    }
    else
    {
        vpW = w;
        vpH = int(w / gameAspect + 0.5f);
        vpX = 0;
        vpY = (h - vpH) / 2;
    }

    Mouse::setView(w, h, vpX, vpY, vpW, vpH, int(m_width), int(m_height));

    glViewport(0, 0, w, h);
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Render the game texture into the aspect-ratio-correct viewport
    glViewport(vpX, vpY, vpW, vpH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, m_width, m_height, 0, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
        glTexCoord2f(0.f, 0.f);
        glVertex3f(0.f, 0.f, 1.f);
        glTexCoord2f(1.f, 0.f);
        glVertex3f(GLfloat(m_width), 0.f, 1.f);
        glTexCoord2f(0.f, 1.f);
        glVertex3f(0.f, GLfloat(m_height), 1.f);

        glTexCoord2f(1.f, 0.f);
        glVertex3f(GLfloat(m_width), 0.f, 1.f);
        glTexCoord2f(1.f, 1.f);
        glVertex3f(GLfloat(m_width), GLfloat(m_height), 1.f);
        glTexCoord2f(0.f, 1.f);
        glVertex3f(0.f, GLfloat(m_height), 1.f);
    glEnd();
    glFlush();
    const Uint64 swapStart = SDL_GetTicksNS();
    SDL_GL_SwapWindow(m_window->m_window);
    s_perf.swapNs += SDL_GetTicksNS() - swapStart;
}

void Renderer::update()
{
    const Uint64 updateStart = SDL_GetTicksNS();
    glBindTexture(GL_TEXTURE_2D, m_texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (m_depth == 16)
    {
        //MemMap::fillDebugGraph(&m_application->getMemory<x86::reg16>(getFrontBuffer()) + m_width*2);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, &m_application->getMemory<x86::reg16>(getFrontBuffer()));
    }
    else
    {
        x86::reg8* srcData = &m_application->getMemory<x86::reg8>(getFrontBuffer());
        x86::reg32* screenData = reinterpret_cast<x86::reg32*>(malloc(m_width * m_height * 4));
        for (x86::reg32 i = 0; i < m_width*m_height; ++i)
        {
            screenData[i] = m_colorPalette[srcData[i]];
        }
        //MemMap::fillDebugGraph(screenData + m_width*2);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, screenData);
        free(screenData);
    }
    const Uint64 uploadEnd = SDL_GetTicksNS();
    s_perf.uploadNs += uploadEnd - updateStart;
    const Uint64 swapBefore = s_perf.swapNs;
    present();
    s_perf.drawNs += (SDL_GetTicksNS() - uploadEnd) - (s_perf.swapNs - swapBefore);
}

x86::reg32 Renderer::lock(x86::reg32 index)
{
    return index == 0 ? getFrontBuffer() : getBackBuffer();
}

void Renderer::unlock(x86::reg32 index)
{
    if (index == 0)
    {
        const Uint64 t0 = SDL_GetTicksNS();
        setCurrent();
        SDL_GL_SetSwapInterval(0);
        const Uint64 t1 = SDL_GetTicksNS();
        update();
        const Uint64 t2 = SDL_GetTicksNS();
        clearCurrent();
        s_perf.contextNs += (t1 - t0) + (SDL_GetTicksNS() - t2);
        ++s_perf.frontUnlocks;
        perfReport();
    }
}

void Renderer::swap()
{
    const Uint64 t0 = SDL_GetTicksNS();
    if (s_perf.lastFlip && t0 - s_perf.lastFlip > s_perf.flipGapMaxNs)
        s_perf.flipGapMaxNs = t0 - s_perf.lastFlip;
    s_perf.lastFlip = t0;
    setCurrent();
    SDL_GL_SetSwapInterval(1);
    m_currentBuffer = 1 - m_currentBuffer;
    const Uint64 t1 = SDL_GetTicksNS();
    update();
    const Uint64 t2 = SDL_GetTicksNS();
    clearCurrent();
    s_perf.contextNs += (t1 - t0) + (SDL_GetTicksNS() - t2);
    ++s_perf.flips;
    perfReport();
}

}
