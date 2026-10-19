#ifndef LIB_WINDOW_H_
#define LIB_WINDOW_H_

#include <lib/winapp.h>
#include <winapi/types.h>
#include <SDL3/SDL.h>

namespace win32
{

extern bool g_isNFS3;
/* true from the moment a track is loaded until the front end is loaded again (see file.cpp) */
extern bool g_inRace;
/* true while a row of the controls menu waits for the key to assign (set by the game code) */
extern bool g_capturingKey;

/* called by the game when a text input field gets focus (opens the system keyboard on the Switch) */
void requestTextInput(unsigned buffer);
extern Uint32 g_userEvent;
extern Uint32 g_userEvent1;
extern Uint32 g_userEvent2;
extern Uint32 g_wmCharEvent;

class WindowClass : public GenericResource
{
    friend class Window;
public:
    WindowClass(x86::reg32 windowProc);
    ~WindowClass();

private:
    x86::reg32 m_wndProc;
};

class Window : public GenericResource
{
    friend class Renderer;
public:
    Window(const char* title, int x, int y, int w, int h);
    ~Window();

    static x86::reg32 getMessage(const x86::CPU& cpu, MSG* result, Window* window, x86::reg32 filterMin, x86::reg32 msgMax);
    static x86::reg32 postMessage(x86::reg32 hWnd, x86::reg32 message, x86::reg32 wParam, x86::reg32 lParam);
    static x86::reg32 getMessageHandler();

private:
    SDL_Window*     m_window;
};

}

#endif
