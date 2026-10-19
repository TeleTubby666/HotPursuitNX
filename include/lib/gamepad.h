#ifndef LIB_GAMEPAD_H_
#define LIB_GAMEPAD_H_

#include <lib/winapp.h>
#include <SDL3/SDL.h>


namespace win32
{

enum InputType
{
    InputType_Keyboard,
    InputType_Mouse,
    InputType_Gamepad
};

class Input : public GenericResource
{
public:
    virtual x86::reg32 getButtonCount() const;
    virtual x86::reg32 getAxesCount() const;
    static void poll();
};

class Keyboard : public Input
{
};

class Mouse : public Input
{
public:
    virtual x86::reg32 getButtonCount() const;
    virtual x86::reg32 getAxesCount() const;

    /* relative movement and button changes are collected here and handed to the game
       by the DirectInput mouse device (GetDeviceState / GetDeviceData) */
    static void addMotion(int dx, int dy);
    static void setButton(int button, bool down);
    /* press now, release a moment later so that the game sees even a very short click */
    static void click(int button);
    /* data for the state based interface (DIMOUSESTATE); clears the collected movement */
    static void takeState(int& dx, int& dy, unsigned char buttons[8]);
    struct Event
    {
        unsigned offset;    /* DIMOFS_X = 0, DIMOFS_Y = 4, DIMOFS_Z = 8, DIMOFS_BUTTON0 = 12 + n */
        int data;
        unsigned timeStamp;
    };
    /* data for the buffered interface (DIDEVICEOBJECTDATA); returns the number of events */
    static unsigned takeEvents(Event* events, unsigned maxEvents, bool peek);
    static void clearEvents();

    /* where the game picture is inside the window (needed to map touch positions) */
    static void setView(int windowW, int windowH, int viewX, int viewY, int viewW, int viewH, int gameW, int gameH);
    /* finger position, normalised 0..1 over the whole window; phase 0 down, 1 move, 2 up */
    static void touch(int phase, float x, float y);
};

struct GamepadState
{
    x86::reg64  buttons;
    x86::sreg16 axes[10];
    x86::reg8   hats[10];
};

class Gamepad : public Input
{
public:
    Gamepad(x86::reg32 gamepadIndex);
    ~Gamepad();

    virtual x86::reg32 getButtonCount() const;
    virtual x86::reg32 getAxesCount() const;

    static x86::reg32 getCount();

    GamepadState getState() const;
    static void updateKeys();
    static void init();
    static Gamepad* getInstance();
private:
    SDL_Joystick* m_joystick;
};

}

#endif

