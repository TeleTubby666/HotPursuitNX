#include <lib/gamepad.h>
#include <SDL3/SDL.h>
#include <cstring>
#include <vector>


namespace win32
{

static x86::reg32 s_kbPoll = 3;

static GamepadState s_state;
static Gamepad* s_gp1;

void Input::poll()
{
    s_kbPoll = 3;
    SDL_UpdateJoysticks();
}

void Gamepad::updateKeys()
{
#ifdef __SWITCH__
    static SDL_AtomicInt s_sampling;
    if (!SDL_CompareAndSwapAtomicInt(&s_sampling, 0, 1))
        return;
#endif

    if (!s_gp1)
    {
        init();
    }

    if (s_gp1)
    {
        SDL_UpdateJoysticks();
#ifdef __SWITCH__
        GamepadState state = s_gp1->getState();
        SDL_Event event = {};

        for (x86::reg32 button = 0; button < 64; ++button)
        {
            x86::reg64 bMask = 1ll << button;
            if ((s_state.buttons & bMask) != (state.buttons & bMask))
            {
                event.type = state.buttons & bMask ? SDL_EVENT_JOYSTICK_BUTTON_DOWN : SDL_EVENT_JOYSTICK_BUTTON_UP;
                event.jbutton.which = 0;
                event.jbutton.button = button;
                event.jbutton.down = !!(state.buttons & bMask);
                SDL_PushEvent(&event);
            }
        }
        s_state.buttons = state.buttons;

        if (s_kbPoll == 0)
        {
            for (x86::reg32 axis = 0; axis < 10; ++axis)
            {
                if (state.axes[axis] != s_state.axes[axis])
                {
                    event.type = SDL_EVENT_JOYSTICK_AXIS_MOTION;
                    event.jaxis.which = 0;
                    event.jaxis.axis = axis;
                    event.jaxis.value = state.axes[axis];
                    SDL_PushEvent(&event);
                }
                s_state.axes[axis] = state.axes[axis];
            }
        }
        else
        {
            for (x86::reg32 axis = 0; axis < 10; ++axis)
            {
                if (s_state.axes[axis] != 0)
                {
                    event.type = SDL_EVENT_JOYSTICK_AXIS_MOTION;
                    event.jaxis.which = 0;
                    event.jaxis.axis = axis;
                    event.jaxis.value = 0;
                    SDL_PushEvent(&event);
                    s_state.axes[axis] = 0;
                }
            }
            s_kbPoll--;
        }
#else
        if (s_kbPoll == 0)
        {
            GamepadState state = s_gp1->getState();
            SDL_Event event;
            for (x86::reg32 axis = 0; axis < 10; ++axis)
            {
                if (state.axes[axis] != s_state.axes[axis])
                {
                    event.type = SDL_EVENT_JOYSTICK_AXIS_MOTION;
                    event.jaxis.which = 0;
                    event.jaxis.axis = axis;
                    event.jaxis.value = state.axes[axis];
                    SDL_PushEvent(&event);
                }
            }
            for (x86::reg32 button = 0; button < 64; ++button)
            {
                x86::reg64 bMask = 1ll << button;
                if ((s_state.buttons & bMask) != (state.buttons & bMask))
                {
                    event.type = state.buttons & bMask ? SDL_EVENT_JOYSTICK_BUTTON_DOWN : SDL_EVENT_JOYSTICK_BUTTON_UP;
                    event.jbutton.which = 0;
                    event.jbutton.button = button;
                    event.jbutton.down = !!(state.buttons & bMask);
                    SDL_PushEvent(&event);
                }
            }
            s_state = state;
        }
        else
        {
            SDL_Event event;
            for (x86::reg32 button = 0; button < 64; ++button)
            {
                x86::reg64 bMask = 1ll << button;
                if ((s_state.buttons & bMask))
                {
                    event.type = SDL_EVENT_JOYSTICK_BUTTON_UP;
                    event.jbutton.which = 0;
                    event.jbutton.button = button;
                    event.jbutton.down = false;
                    SDL_PushEvent(&event);
                }
            }
            memset(&s_state, 0, sizeof(s_state));
            s_kbPoll--;
        }
#endif
    }

#ifdef __SWITCH__
    SDL_SetAtomicInt(&s_sampling, 0);
#endif
}


/*
 * Mouse: the game reads the mouse through DirectInput, but nothing in the shim produced
 * mouse data so far. Everything that moves the cursor (right stick, touch screen) ends up here.
 */
namespace
{
    struct MouseData
    {
        SDL_Mutex* mutex;
        int dx, dy;
        bool buttons[8];
        Uint64 releaseAt[8];                /* 0 = no delayed release pending */
        std::vector<Mouse::Event> events;

        /* window / picture geometry for touch */
        int windowW, windowH, viewX, viewY, viewW, viewH, gameW, gameH;

        /* touch */
        bool touching;
        float cursorX, cursorY;            /* cursor position in game pixels as the game should see it */
        /*
         * The game only knows relative movement and we do not know where its cursor really is.
         * A touch therefore first pushes the cursor into the top left corner (the game keeps it
         * on the screen) and only then, one game frame later, moves it to the finger.
         * syncStage: 0 = nothing pending, 1 = corner movement not yet handed to the game,
         * 2 = corner movement handed over, target movement still to do.
         */
        int syncStage;
        float targetX, targetY;
        bool pendingPress;
        MouseData()
            :   mutex(SDL_CreateMutex()), dx(0), dy(0), buttons(), releaseAt(),
                windowW(0), windowH(0), viewX(0), viewY(0), viewW(0), viewH(0), gameW(640), gameH(480),
                touching(false), cursorX(320.f), cursorY(240.f), syncStage(0), targetX(0.f), targetY(0.f), pendingPress(false)
        {
        }
    };

    MouseData& mouseData()
    {
        static MouseData data;
        return data;
    }

    const size_t kMaxEvents = 256;

    void pushEvent(MouseData& d, unsigned offset, int value)
    {
        if (d.events.size() >= kMaxEvents)
            d.events.erase(d.events.begin());
        Mouse::Event e;
        e.offset = offset;
        e.data = value;
        e.timeStamp = (unsigned) SDL_GetTicks();
        d.events.push_back(e);
    }

    void applyMotion(MouseData& d, int dx, int dy)
    {
        if (dx)
        {
            d.dx += dx;
            pushEvent(d, 0, dx);
        }
        if (dy)
        {
            d.dy += dy;
            pushEvent(d, 4, dy);
        }
        const int limit = 100000;
        if (d.dx > limit) d.dx = limit;
        if (d.dx < -limit) d.dx = -limit;
        if (d.dy > limit) d.dy = limit;
        if (d.dy < -limit) d.dy = -limit;
    }

    void applyButton(MouseData& d, int button, bool down)
    {
        if (button < 0 || button >= 8 || d.buttons[button] == down)
            return;
        d.buttons[button] = down;
        pushEvent(d, 12 + button, down ? 0x80 : 0);
    }

    /* second step of a touch: the game has seen the corner movement, now go to the finger */
    void advanceSync(MouseData& d)
    {
        if (d.syncStage != 2)
            return;
        d.syncStage = 0;
        const int dx = (int) d.targetX;
        const int dy = (int) d.targetY;
        applyMotion(d, dx, dy);
        d.cursorX = (float) dx;
        d.cursorY = (float) dy;
        if (d.pendingPress)
        {
            d.pendingPress = false;
            applyButton(d, 0, true);
            if (!d.touching)
                d.releaseAt[0] = SDL_GetTicks() + 80;
        }
    }

    /* the corner movement has been handed to the game */
    void finishSyncStep(MouseData& d)
    {
        if (d.syncStage == 1)
            d.syncStage = 2;
    }

    /* releases whose time has come */
    void applyDelayedReleases(MouseData& d)
    {
        const Uint64 now = SDL_GetTicks();
        for (int i = 0; i < 8; ++i)
        {
            if (d.releaseAt[i] && now >= d.releaseAt[i])
            {
                d.releaseAt[i] = 0;
                applyButton(d, i, false);
            }
        }
    }
}

x86::reg32 Mouse::getButtonCount() const
{
    return 3;
}

x86::reg32 Mouse::getAxesCount() const
{
    return 2;
}

void Mouse::addMotion(int dx, int dy)
{
    MouseData& d = mouseData();
    SDL_LockMutex(d.mutex);
    applyMotion(d, dx, dy);
    /* keep our idea of the cursor position in step (the game clamps to its screen as well) */
    d.cursorX += dx;
    d.cursorY += dy;
    if (d.cursorX < 0.f) d.cursorX = 0.f;
    if (d.cursorY < 0.f) d.cursorY = 0.f;
    if (d.cursorX > d.gameW - 1) d.cursorX = (float) (d.gameW - 1);
    if (d.cursorY > d.gameH - 1) d.cursorY = (float) (d.gameH - 1);
    SDL_UnlockMutex(d.mutex);
}

void Mouse::setButton(int button, bool down)
{
    MouseData& d = mouseData();
    SDL_LockMutex(d.mutex);
    if (button >= 0 && button < 8)
        d.releaseAt[button] = 0;
    applyButton(d, button, down);
    SDL_UnlockMutex(d.mutex);
}

void Mouse::click(int button)
{
    MouseData& d = mouseData();
    SDL_LockMutex(d.mutex);
    if (button >= 0 && button < 8)
    {
        applyButton(d, button, true);
        d.releaseAt[button] = SDL_GetTicks() + 100;
    }
    SDL_UnlockMutex(d.mutex);
}

void Mouse::takeState(int& dx, int& dy, unsigned char buttons[8])
{
    MouseData& d = mouseData();
    SDL_LockMutex(d.mutex);
    advanceSync(d);
    applyDelayedReleases(d);
    dx = d.dx;
    dy = d.dy;
    d.dx = d.dy = 0;
    for (int i = 0; i < 8; ++i)
        buttons[i] = d.buttons[i] ? 0x80 : 0x00;
    finishSyncStep(d);
    SDL_UnlockMutex(d.mutex);
}

unsigned Mouse::takeEvents(Event* events, unsigned maxEvents, bool peek)
{
    MouseData& d = mouseData();
    SDL_LockMutex(d.mutex);
    advanceSync(d);
    applyDelayedReleases(d);
    unsigned count = (unsigned) d.events.size();
    if (count > maxEvents)
        count = maxEvents;
    for (unsigned i = 0; i < count; ++i)
        events[i] = d.events[i];
    if (!peek)
    {
        d.events.erase(d.events.begin(), d.events.begin() + count);
        finishSyncStep(d);
    }
    SDL_UnlockMutex(d.mutex);
    return count;
}

void Mouse::clearEvents()
{
    MouseData& d = mouseData();
    SDL_LockMutex(d.mutex);
    d.events.clear();
    SDL_UnlockMutex(d.mutex);
}

void Mouse::setView(int windowW, int windowH, int viewX, int viewY, int viewW, int viewH, int gameW, int gameH)
{
    MouseData& d = mouseData();
    SDL_LockMutex(d.mutex);
    d.windowW = windowW;
    d.windowH = windowH;
    d.viewX = viewX;
    d.viewY = viewY;
    d.viewW = viewW;
    d.viewH = viewH;
    d.gameW = gameW;
    d.gameH = gameH;
    SDL_UnlockMutex(d.mutex);
}

void Mouse::touch(int phase, float x, float y)
{
    MouseData& d = mouseData();
    SDL_LockMutex(d.mutex);
    if (phase == 2)
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "touch up");
        d.touching = false;
        /* keep the button down for a moment so that a quick tap is not lost between two game frames;
           when the corner step is still pending the release is scheduled after the press */
        if (d.syncStage == 0)
            d.releaseAt[0] = SDL_GetTicks() + 80;
        SDL_UnlockMutex(d.mutex);
        return;
    }

    if (d.viewW > 0 && d.viewH > 0 && d.gameW > 0 && d.gameH > 0)
    {
        /* finger position -> pixel of the game picture; touches in the black bars hit the nearest edge */
        float gx = (x * d.windowW - d.viewX) * d.gameW / d.viewW;
        float gy = (y * d.windowH - d.viewY) * d.gameH / d.viewH;
        if (gx < 0.f) gx = 0.f;
        if (gy < 0.f) gy = 0.f;
        if (gx > d.gameW - 1) gx = (float) (d.gameW - 1);
        if (gy > d.gameH - 1) gy = (float) (d.gameH - 1);

        if (!d.touching)
        {
            /* new touch: corner first, then the finger position (see syncStage) */
            d.touching = true;
            d.releaseAt[0] = 0;
            d.targetX = gx;
            d.targetY = gy;
            d.pendingPress = true;
            if (d.syncStage == 0)
            {
                d.syncStage = 1;
                applyMotion(d, -4000, -4000);
                d.cursorX = d.cursorY = 0.f;
            }
            SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "touch down: game position %d,%d", (int) gx, (int) gy);
        }
        else if (d.syncStage != 0)
        {
            d.targetX = gx;
            d.targetY = gy;
        }
        else
        {
            /* finger moves: follow it with relative movement */
            const int dx = (int) (gx - d.cursorX);
            const int dy = (int) (gy - d.cursorY);
            d.cursorX += dx;
            d.cursorY += dy;
            applyMotion(d, dx, dy);
        }
    }
    SDL_UnlockMutex(d.mutex);
}

x86::reg32 Input::getButtonCount() const
{
    return 0;
}

x86::reg32 Input::getAxesCount() const
{
    return 0;
}

Gamepad::Gamepad(x86::reg32 gamepadIndex)
    :   m_joystick(nullptr)
{
    int count = 0;
    SDL_JoystickID *ids = SDL_GetJoysticks(&count);
    if (ids && (int)gamepadIndex < count)
        m_joystick = SDL_OpenJoystick(ids[gamepadIndex]);
    SDL_free(ids);
    SDL_SetJoystickEventsEnabled(false);
    if (!s_gp1 && m_joystick)
        s_gp1 = this;
}

Gamepad::~Gamepad()
{
    if (s_gp1 == this)
        s_gp1 = nullptr;
    if (m_joystick)
        SDL_CloseJoystick(m_joystick);
}

void Gamepad::init()
{
    if (!s_gp1)
    {
        int count = 0;
        SDL_JoystickID *ids = SDL_GetJoysticks(&count);
        if (ids && count > 0)
        {
            s_gp1 = new Gamepad(0);
        }
        SDL_free(ids);
    }
}

Gamepad* Gamepad::getInstance()
{
    return s_gp1;
}

x86::reg32 Gamepad::getCount()
{
    int count = 0;
    SDL_JoystickID *ids = SDL_GetJoysticks(&count);
    SDL_free(ids);
    return (x86::reg32)count;
}

x86::reg32 Gamepad::getButtonCount() const
{
    return m_joystick ? SDL_GetNumJoystickButtons(m_joystick) : 0;
}

x86::reg32 Gamepad::getAxesCount() const
{
    return m_joystick ? SDL_GetNumJoystickAxes(m_joystick) : 0;
}

GamepadState Gamepad::getState() const
{
    GamepadState result;
    memset(&result, 0, sizeof(result));
    if (!m_joystick)
        return result;
    for (x86::reg32 button = 0; button < getButtonCount(); ++button)
    {
        result.buttons |= (SDL_GetJoystickButton(m_joystick, button) ? 1 : 0) << button;
    }
    for (x86::reg32 axis = 0; axis < getAxesCount(); ++axis)
    {
        result.axes[axis] = SDL_GetJoystickAxis(m_joystick, axis);
    }
    return result;
}


}
