#include <lib/window.h>
#include <lib/log.h>
#include <lib/thread.h>
#ifdef __SWITCH__
#include <lib/gamepad.h>
#include <switch.h>
#endif
#include <SDL3/SDL.h>
#include <cstring>

#define WM_KEYDOWN  0x0100
#define WM_KEYUP    0x0101
#define WM_CHAR     0x0102

namespace win32
{

Uint32 g_userEvent   = 0;
Uint32 g_userEvent1  = 0;
Uint32 g_userEvent2  = 0;
Uint32 g_wmCharEvent = 0;
bool g_isNFS3        = false;
bool g_inRace        = false;

static struct CustomEventRegistrar
{
    CustomEventRegistrar()
    {
        Uint32 base = SDL_RegisterEvents(4);
        g_userEvent   = base + 0;
        g_userEvent1  = base + 1;
        g_userEvent2  = base + 2;
        g_wmCharEvent = base + 3;
    }
} s_customEventRegistrar;


static const x86::reg32 WM_QUIT = 0x0012;
static const x86::reg32 WM_USER = 0x0400;
static const x86::reg32 WM_USER_END = 0xC000;
static WindowClass* s_class;

static const x86::reg8 s_scancodeTable[100] =
{
    0x00, 0x00, 0x00, 0x00, 0x1E, 0x30, 0x2E, 0x20, 0x12, 0x21,
    0x22, 0x23, 0x17, 0x24, 0x25, 0x26, 0x32, 0x31, 0x18, 0x19,
    0x10, 0x13, 0x1F, 0x14, 0x16, 0x2F, 0x11, 0x2D, 0x15, 0x2C,
    0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
    0x1C, 0x01, 0x0E, 0x0F, 0x39, 0x0C, 0x0D, 0x1A, 0x1B, 0x2B,
    0x00, 0x27, 0x28, 0x29, 0x33, 0x34, 0x35, 0x3A, 0x3B, 0x3C,
    0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x57, 0x58,
    0x37, 0x46, 0x59, 0x52, 0x47, 0x49, 0x53, 0x4F, 0x51, 0x4D,
    0x4B, 0x50, 0x48, 0x45, 0x35, 0x37, 0x4A, 0x4E, 0x1C, 0x4F,
    0x50, 0x51, 0x4B, 0x4C, 0x4D, 0x47, 0x48, 0x49, 0x52, 0x53
};

#ifdef __SWITCH__
static bool s_keyboardRequested = false;

/*
 * Opens the system keyboard (L3+R3) and feeds the typed text to the game as WM_CHAR
 * messages, the way a real keyboard would. The game has no way to tell us that a text
 * field is active, so the keyboard is requested by hand. Existing text is erased first.
 */
static void runSwitchKeyboard()
{
    SwkbdConfig kbd;
    if (R_FAILED(swkbdCreate(&kbd, 0)))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "swkbdCreate failed");
        return;
    }
    swkbdConfigMakePresetDefault(&kbd);
    swkbdConfigSetGuideText(&kbd, "Name");
    swkbdConfigSetStringLenMax(&kbd, 15);
    char text[64] = "";
    Result rc = swkbdShow(&kbd, text, sizeof(text));
    swkbdClose(&kbd);
    if (R_FAILED(rc))
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "software keyboard cancelled (0x%x)", (unsigned) rc);
        return;
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "software keyboard returned \"%s\"", text);

    const intptr_t lparam = 1;
    for (int i = 0; i < 20; ++i)
    {
        SDL_Event bs;
        SDL_zero(bs);
        bs.type = g_wmCharEvent;
        bs.user.data1 = reinterpret_cast<void*>(static_cast<intptr_t>(8));
        bs.user.data2 = reinterpret_cast<void*>(lparam);
        SDL_PushEvent(&bs);
    }
    for (const char* c = text; *c; ++c)
    {
        SDL_Event ch;
        SDL_zero(ch);
        ch.type = g_wmCharEvent;
        ch.user.data1 = reinterpret_cast<void*>(static_cast<intptr_t>(static_cast<unsigned char>(*c)));
        ch.user.data2 = reinterpret_cast<void*>(lparam);
        SDL_PushEvent(&ch);
    }
}
#endif

#ifdef __SWITCH__
/*
 * Stick directions act as keys of their own, so that they can be assigned in
 * the controls menu like any other button. The keys are digits, which the
 * game does not use by default.
 */
static void stickKey(bool& state, bool active, SDL_Keycode key, SDL_Scancode scancode)
{
    if (state == active)
        return;
    state = active;

    SDL_Event kevent;
    SDL_zero(kevent);
    kevent.type = active ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP;
    kevent.key.key = key;
    kevent.key.scancode = scancode;
    SDL_PushEvent(&kevent);

    if (active)
    {
        SDL_Event cevent;
        SDL_zero(cevent);
        cevent.type = g_wmCharEvent;
        cevent.user.data1 = reinterpret_cast<void*>(static_cast<intptr_t>(key));
        cevent.user.data2 = reinterpret_cast<void*>(static_cast<intptr_t>(1 | s_scancodeTable[scancode] << 16));
        SDL_PushEvent(&cevent);
    }
}
#endif


WindowClass::WindowClass(x86::reg32 windowProc)
    :   m_wndProc(windowProc)
{
    s_class = this;
}

WindowClass::~WindowClass()
{
}

Window::Window(const char *title, int /*x*/, int /*y*/, int w, int h)
    :   m_window(nullptr)
{
#ifdef __SWITCH__
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif
    m_window = SDL_CreateWindow(title, w, h, SDL_WINDOW_RESIZABLE|SDL_WINDOW_OPENGL);
    if (!m_window)
    {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Failed to create window: %s", SDL_GetError());
        return;
    }
#ifndef __SWITCH__
    /* SDL3 delivers no SDL_EVENT_TEXT_INPUT unless text input is started; the game's
       name entry relies on the resulting WM_CHAR messages. On the Switch this would
       bring up the system keyboard, which is opened with L3+R3 instead. */
    SDL_StartTextInput(m_window);
#endif
}

Window::~Window()
{
}

x86::reg32 Window::getMessage(const x86::CPU& cpu, MSG* result, Window *window, x86::reg32 filterMin, x86::reg32 msgMax)
{
    NFS2_USE(window);
    NFS2_USE(filterMin);
    NFS2_USE(msgMax);
    static LPARAM s_lastLParam;
    memset(result, 0, sizeof(MSG));
    SDL_Event event;
    for (;;)
    {
        watchdogHeartbeat();
#ifdef __SWITCH__
        if (s_keyboardRequested)
        {
            s_keyboardRequested = false;
            runSwitchKeyboard();
        }
        bool receivedEvent = SDL_WaitEventTimeout(&event, 8);
#else
        bool receivedEvent = SDL_WaitEvent(&event);
#endif
        if (!receivedEvent)
        {
#ifdef __SWITCH__
            if (cpu.terminate)
                return 0;
            Gamepad::updateKeys();
#endif
        }
        else
        {
            if (cpu.terminate)
                return 0;
            if (event.type == g_userEvent || event.type == g_userEvent1)
            {
                result->message = x86::reg32(event.user.code);
                result->wParam = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data1));
                result->lParam = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data2));
                result->hWindow = event.user.windowID;
                return result->message != WM_QUIT;
            }
            else if (event.type == g_userEvent2)
            {
                const x86::reg32 tid = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data1));
                if (tid == Thread::currentThreadId())
                {
                    return 0;
                }
            }
            else if (event.type == g_wmCharEvent)
            {
                result->message = WM_CHAR;
                result->wParam = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data1));
                result->lParam = static_cast<x86::reg32>(reinterpret_cast<intptr_t>(event.user.data2));
                return 1;
            }
            else
            {
                switch (event.type)
                {
                case SDL_EVENT_QUIT:
                    result->message = WM_QUIT;
                    return 0;
                case SDL_EVENT_KEY_DOWN:
                case SDL_EVENT_KEY_UP:
                    {
                        SDL_Scancode scancode = event.key.scancode;
                        SDL_Keycode sym = event.key.key;

                        BOOL isWMChar = false;

                        result->lParam = 1;

                        if (sym >= SDLK_F1 && sym <= SDLK_F12)
                            result->wParam = 0x70 + (sym - SDLK_F1);

                        switch (sym)
                        {
                            case SDLK_LSHIFT:
                            case SDLK_RSHIFT:
                                result->wParam = 0x10;
                                break;
                            case SDLK_PAGEDOWN:
                                result->wParam = 0x21;
                                break;
                            case SDLK_PAGEUP:
                                result->wParam = 0x22;
                                break;
                            case SDLK_END:
                                result->wParam = 0x23;
                                break;
                            case SDLK_HOME:
                                result->wParam = 0x24;
                                break;
                            case SDLK_LEFT:
                                result->wParam = 0x25;
                                break;
                            case SDLK_UP:
                                result->wParam = 0x26;
                                break;
                            case SDLK_RIGHT:
                                result->wParam = 0x27;
                                break;
                            case SDLK_DOWN:
                                result->wParam = 0x28;
                                break;
                            case SDLK_INSERT:
                                result->wParam = 0x2D;
                                break;
                            case SDLK_DELETE:
                                result->wParam = 0x2E;
                                break;
                            case SDLK_KP_0:
                                result->wParam = 0x60;
                                break;
                            case SDLK_KP_1:
                                result->wParam = 0x61;
                                break;
                            case SDLK_KP_2:
                                result->wParam = 0x62;
                                break;
                            case SDLK_KP_3:
                                result->wParam = 0x63;
                                break;
                            case SDLK_KP_4:
                                result->wParam = 0x64;
                                break;
                            case SDLK_KP_5:
                                result->wParam = 0x65;
                                break;
                            case SDLK_KP_6:
                                result->wParam = 0x66;
                                break;
                            case SDLK_KP_7:
                                result->wParam = 0x67;
                                break;
                            case SDLK_KP_8:
                                result->wParam = 0x68;
                                break;
                            case SDLK_KP_9:
                                result->wParam = 0x69;
                                break;
                            case SDLK_KP_MULTIPLY:
                                result->wParam = 0x6A;
                                break;
                            case SDLK_KP_PLUS:
                                result->wParam = 0x6B;
                                break;
                            case SDLK_KP_MINUS:
                                result->wParam = 0x6D;
                                break;
                            case SDLK_KP_PERIOD:
                                result->wParam = 0x6E;
                                break;
                            case SDLK_KP_DIVIDE:
                                result->wParam = 0x6F;
                                break;
                            case SDLK_EQUALS:
                                result->wParam = 0xBB;
                                break;
                            case SDLK_MINUS:
                                result->wParam = 0xBD;
                                break;
                            case SDLK_PERIOD:
                                result->wParam = 0xBE;
                                break;
                            case SDLK_GRAVE:
                                result->wParam = 0xC0;
                                break;
                            case SDLK_APOSTROPHE:
                                result->wParam = 0xDE;
                                break;
                            case SDLK_KP_ENTER:
                                sym = SDLK_RETURN;
                            [[fallthrough]];
                            default:
                                if (!(sym & 0x40000000))
                                {
                                    isWMChar = sym >= SDLK_BACKSPACE && sym < SDLK_SPACE;
                                    result->wParam = DWORD(sym);
                                }
                        }

                        if (result->lParam == 1 && scancode < 100)
                            result->lParam |= s_scancodeTable[scancode] << 16;
                        s_lastLParam = result->lParam;

                        SDL_Event event2;
                        event2.type = g_wmCharEvent;
                        if (event.type == SDL_EVENT_KEY_UP)
                            result->message = WM_KEYUP;
                        else if (event.type == SDL_EVENT_KEY_DOWN)
                        {
                            result->message = WM_KEYDOWN;
                            if (isWMChar)
                            {
                                event2.user.data1 = reinterpret_cast<void*>(static_cast<intptr_t>(result->wParam));
                                event2.user.data2 = reinterpret_cast<void*>(static_cast<intptr_t>(result->lParam));
                                SDL_PushEvent(&event2);
                            }
                        }

                        if (sym >= SDLK_A && sym <= SDLK_Z)
                            result->wParam = sym & ~0x20;
                    }
                    return 1;
                case SDL_EVENT_JOYSTICK_BUTTON_DOWN:
                case SDL_EVENT_JOYSTICK_BUTTON_UP:
                    {
                        if (event.jbutton.which == 0)
                        {
#ifdef __SWITCH__
                            SDL_Scancode scancode = SDL_SCANCODE_UNKNOWN;
                            BOOL sendCharacter = false;


                            /* L3 + R3 together open the system keyboard (name entry) */
                            static bool s_stickClick[2] = { false, false };
                            if (event.jbutton.button == 4 || event.jbutton.button == 5)
                            {
                                s_stickClick[event.jbutton.button - 4] = event.jbutton.down;
                                if (event.jbutton.down && s_stickClick[0] && s_stickClick[1])
                                    s_keyboardRequested = true;
                            }

                            switch (event.jbutton.button)
                            {
                            case 0: /* A: accept in menus, nitrous in a race (Enter) */
                                result->wParam = DWORD(SDLK_RETURN);
                                scancode = SDL_SCANCODE_RETURN;
                                sendCharacter = true;
                                break;
                            case 1: /* B: back (Esc) in menus, handbrake (Space) in a race */
                                if (g_inRace)
                                {
                                    result->wParam = DWORD(SDLK_SPACE);
                                    scancode = SDL_SCANCODE_SPACE;
                                }
                                else
                                {
                                    result->wParam = DWORD(SDLK_ESCAPE);
                                    scancode = SDL_SCANCODE_ESCAPE;
                                }
                                sendCharacter = true;
                                break;
                            case 2: /* X: weapons/equipment (NFS3 spike strip) / cycle camera (NFS2) */
                                sendCharacter = true;
                                if (g_isNFS3)
                                {
                                    result->wParam = 'S';
                                    scancode = SDL_SCANCODE_S;
                                }
                                else
                                {
                                    result->wParam = 'C';
                                    scancode = SDL_SCANCODE_C;
                                }
                                break;
                            case 3: /* Y: weapons/equipment (horn/siren) */
                                result->wParam = 'H';
                                scancode = SDL_SCANCODE_H;
                                sendCharacter = true;
                                break;
                            case 4: /* Left stick: reset car */
                                result->wParam = 'R';
                                scancode = SDL_SCANCODE_R;
                                sendCharacter = true;
                                break;
                            case 5: /* Right stick: cycle camera */
                                result->wParam = 'C';
                                scancode = SDL_SCANCODE_C;
                                sendCharacter = true;
                                break;
                            case 6: /* L: free key (Q) */
                                result->wParam = 'Q';
                                scancode = SDL_SCANCODE_Q;
                                sendCharacter = true;
                                break;
                            case 7: /* R: look behind */
                                result->wParam = 'B';
                                scancode = SDL_SCANCODE_B;
                                sendCharacter = true;
                                break;
                            case 8: /* ZL: brake/reverse */
                                result->wParam = 0x28;
                                scancode = SDL_SCANCODE_DOWN;
                                break;
                            case 9: /* ZR: accelerate */
                                result->wParam = 0x26;
                                scancode = SDL_SCANCODE_UP;
                                break;
                            case 10: /* Plus: pause menu / back (Esc) */
                                result->wParam = DWORD(SDLK_ESCAPE);
                                scancode = SDL_SCANCODE_ESCAPE;
                                sendCharacter = true;
                                break;
                            case 11: /* Minus: shift down */
                                result->wParam = 'Z';
                                scancode = SDL_SCANCODE_Z;
                                sendCharacter = true;
                                break;
                            case 12: /* D-pad left */
                            case 16: /* Left stick left pseudo-button */
                                result->wParam = 0x25;
                                scancode = SDL_SCANCODE_LEFT;
                                break;
                            case 13: /* D-pad up */
                                result->wParam = 0x26;
                                scancode = SDL_SCANCODE_UP;
                                break;
                            case 14: /* D-pad right */
                            case 18: /* Left stick right pseudo-button */
                                result->wParam = 0x27;
                                scancode = SDL_SCANCODE_RIGHT;
                                break;
                            case 15: /* D-pad down */
                                result->wParam = 0x28;
                                scancode = SDL_SCANCODE_DOWN;
                                break;
                            default:
                                break;
                            }

                            if (scancode == SDL_SCANCODE_UNKNOWN)
                                break;

                            result->lParam = 1 | s_scancodeTable[scancode] << 16;
#else
                            if (event.jbutton.button == 7)
                            {
                                /* simulate Enter */
                                result->wParam = DWORD(SDLK_RETURN);
                                result->lParam = 1 | s_scancodeTable[SDL_SCANCODE_RETURN] << 16;
                            }
                            else if (event.jbutton.button == 6)
                            {
                                /* simulate Escape */
                                result->wParam = DWORD(SDLK_ESCAPE);
                                result->lParam = 1 | s_scancodeTable[SDL_SCANCODE_ESCAPE] << 16;
                            }
                            else
                            {
                                /* simulate Space */
                                result->wParam = DWORD(SDLK_SPACE);
                                result->lParam = 1 | s_scancodeTable[SDL_SCANCODE_SPACE] << 16;
                            }
#endif
                            result->message = event.jbutton.down ? WM_KEYDOWN : WM_KEYUP;
                            result->hWindow = event.user.windowID;

#ifdef __SWITCH__
                            SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "pad button %d %s -> key 0x%x%s",
                                         (int) event.jbutton.button, event.jbutton.down ? "down" : "up", (unsigned) result->wParam,
                                         g_inRace ? " (race)" : " (menu)");
#endif

                            if (event.jbutton.down
#ifdef __SWITCH__
                                && sendCharacter
#endif
                            )
                            {
                                SDL_Event event2;
                                event2.type = g_wmCharEvent;
                                /* WM_CHAR carries the lower-case character, like a real keyboard */
                                DWORD charValue = result->wParam;
                                if (charValue >= 'A' && charValue <= 'Z')
                                    charValue += 'a' - 'A';
                                event2.user.data1 = reinterpret_cast<void*>(static_cast<intptr_t>(charValue));
                                event2.user.data2 = reinterpret_cast<void*>(static_cast<intptr_t>(result->lParam));
                                SDL_PushEvent(&event2);
                            }

                            return 1;
                        }
                    }
                    break;
                case SDL_EVENT_JOYSTICK_AXIS_MOTION:
                    if (event.jaxis.which == 0)
                    {
                        if (event.jaxis.axis == 0)
                        {
                            static x86::sreg16 s_prevAxisValue = 0;
                            if ((s_prevAxisValue > 30000) && (event.jaxis.value < 30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_UP;
                                kevent.key.key = SDLK_RIGHT;
                                kevent.key.scancode = SDL_SCANCODE_RIGHT;
                                SDL_PushEvent(&kevent);
                            }
                            if ((s_prevAxisValue < -30000) && (event.jaxis.value > -30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_UP;
                                kevent.key.key = SDLK_LEFT;
                                kevent.key.scancode = SDL_SCANCODE_LEFT;
                                SDL_PushEvent(&kevent);
                            }
                            if ((s_prevAxisValue < 30000) && (event.jaxis.value > 30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_DOWN;
                                kevent.key.key = SDLK_RIGHT;
                                kevent.key.scancode = SDL_SCANCODE_RIGHT;
                                SDL_PushEvent(&kevent);
                            }
                            if ((s_prevAxisValue > -30000) && (event.jaxis.value < -30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_DOWN;
                                kevent.key.key = SDLK_LEFT;
                                kevent.key.scancode = SDL_SCANCODE_LEFT;
                                SDL_PushEvent(&kevent);
                            }
                            s_prevAxisValue = event.jaxis.value;
                            break;
                        }
#ifndef __SWITCH__
                        if (event.jaxis.axis == 1)
                        {
                            static x86::sreg16 s_prevAxisValue = 0;
                            if ((s_prevAxisValue > 30000) && (event.jaxis.value < 30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_UP;
                                kevent.key.key = SDLK_DOWN;
                                kevent.key.scancode = SDL_SCANCODE_DOWN;
                                SDL_PushEvent(&kevent);
                            }
                            if ((s_prevAxisValue < -30000) && (event.jaxis.value > -30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_UP;
                                kevent.key.key = SDLK_UP;
                                kevent.key.scancode = SDL_SCANCODE_UP;
                                SDL_PushEvent(&kevent);
                            }
                            if ((s_prevAxisValue < 30000) && (event.jaxis.value > 30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_DOWN;
                                kevent.key.key = SDLK_DOWN;
                                kevent.key.scancode = SDL_SCANCODE_DOWN;
                                SDL_PushEvent(&kevent);
                            }
                            if ((s_prevAxisValue > -30000) && (event.jaxis.value < -30000))
                            {
                                SDL_Event kevent;
                                kevent.type = SDL_EVENT_KEY_DOWN;
                                kevent.key.key = SDLK_UP;
                                kevent.key.scancode = SDL_SCANCODE_UP;
                                SDL_PushEvent(&kevent);
                            }
                            s_prevAxisValue = event.jaxis.value;
                            break;
                        }
#endif
#ifdef __SWITCH__
                        if (event.jaxis.axis >= 1 && event.jaxis.axis <= 3)
                        {
                            static bool s_lStickUp, s_lStickDown, s_rStickLeft, s_rStickRight, s_rStickUp, s_rStickDown;
                            const int value = event.jaxis.value;
                            switch (event.jaxis.axis)
                            {
                            case 1: /* left stick vertical: keys 1 (up), 2 (down) */
                                stickKey(s_lStickUp, value < -20000, SDLK_1, SDL_SCANCODE_1);
                                stickKey(s_lStickDown, value > 20000, SDLK_2, SDL_SCANCODE_2);
                                break;
                            case 2: /* right stick horizontal: keys 3 (left), 4 (right) */
                                stickKey(s_rStickLeft, value < -20000, SDLK_3, SDL_SCANCODE_3);
                                stickKey(s_rStickRight, value > 20000, SDLK_4, SDL_SCANCODE_4);
                                break;
                            case 3: /* right stick vertical: key 5 (up), B (down, look behind) */
                                stickKey(s_rStickUp, value < -20000, SDLK_5, SDL_SCANCODE_5);
                                stickKey(s_rStickDown, value > 20000, SDLK_B, SDL_SCANCODE_B);
                                break;
                            }
                            break;
                        }
#endif
                    }
                    break;
                case SDL_EVENT_JOYSTICK_HAT_MOTION:
                    if (event.jhat.which == 0 && event.jhat.hat == 0)
                    {
                        static x86::reg32 s_prevHatButtons = 0;
                        x86::reg32 hatButtons = event.jhat.value;
                        SDL_Event event;
                        if ((s_prevHatButtons & SDL_HAT_LEFT) != (hatButtons & SDL_HAT_LEFT))
                        {
                            event.type = hatButtons & SDL_HAT_LEFT ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP;
                            event.key.key = SDLK_LEFT;
                            event.key.scancode = SDL_SCANCODE_LEFT;
                            SDL_PushEvent(&event);
                        }
                        if ((s_prevHatButtons & SDL_HAT_RIGHT) != (hatButtons & SDL_HAT_RIGHT))
                        {
                            event.type = hatButtons & SDL_HAT_RIGHT ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP;
                            event.key.key = SDLK_RIGHT;
                            event.key.scancode = SDL_SCANCODE_RIGHT;
                            SDL_PushEvent(&event);
                        }
                        if ((s_prevHatButtons & SDL_HAT_UP) != (hatButtons & SDL_HAT_UP))
                        {
                            event.type = hatButtons & SDL_HAT_UP ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP;
                            event.key.key = SDLK_UP;
                            event.key.scancode = SDL_SCANCODE_UP;
                            SDL_PushEvent(&event);
                        }
                        if ((s_prevHatButtons & SDL_HAT_DOWN) != (hatButtons & SDL_HAT_DOWN))
                        {
                            event.type = hatButtons & SDL_HAT_DOWN ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP;
                            event.key.key = SDLK_DOWN;
                            event.key.scancode = SDL_SCANCODE_DOWN;
                            SDL_PushEvent(&event);
                        }
                        break;
                    }
                    break;
                case SDL_EVENT_TEXT_INPUT:
                    {
                        result->message = WM_CHAR;
                        result->wParam = event.text.text[0];
                        result->lParam = s_lastLParam;
                    }
                    return 1;
                default:
                    break;
                }
            }
        }
    }
}

x86::reg32 Window::postMessage(x86::reg32 hWnd, x86::reg32 message, x86::reg32 wParam, x86::reg32 lParam)
{
    SDL_Event event;
    if (message >= WM_USER && message < WM_USER_END)
    {
        event.type = g_userEvent;
    }
    else
    {
        event.type = g_userEvent1;
    }
    event.user.code = int(message);
    event.user.data1 = reinterpret_cast<void*>(static_cast<intptr_t>(wParam));
    event.user.data2 = reinterpret_cast<void*>(static_cast<intptr_t>(lParam));
    event.user.windowID = hWnd;
    SDL_PushEvent(&event);
    return 1;
}

x86::reg32 Window::getMessageHandler()
{
    return s_class->m_wndProc;
}

}
