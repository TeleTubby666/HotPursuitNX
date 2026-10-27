#include <lib/gamepad.h>
#include <SDL3/SDL.h>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>


namespace win32 { namespace ForceFeedback
{

namespace
{
    struct Effect
    {
        int      id;
        Params   params;
        bool     playing;
        Uint64   startTime;
        Uint64   endTime;      /* 0 = no end */
    };

    struct State
    {
        SDL_Mutex* mutex;
        std::vector<Effect> effects;
        int nextId;
        bool paused;
        bool actuators;
        float lastStrength;
        Uint64 lastRumble;
        State() : mutex(SDL_CreateMutex()), nextId(1), paused(false), actuators(true), lastStrength(0.f), lastRumble(0) {}
    };

    State& state()
    {
        static State s;
        return s;
    }

    Effect* find(State& s, int id)
    {
        for (size_t i = 0; i < s.effects.size(); ++i)
            if (s.effects[i].id == id)
                return &s.effects[i];
        return nullptr;
    }
}

int create(Type type)
{
    State& s = state();
    SDL_LockMutex(s.mutex);
    Effect e = {};
    e.id = s.nextId++;
    e.params.type = type;
    e.params.gain = 10000;
    s.effects.push_back(e);
    const int id = e.id;
    SDL_UnlockMutex(s.mutex);
    return id;
}

void remove(int id)
{
    State& s = state();
    SDL_LockMutex(s.mutex);
    for (size_t i = 0; i < s.effects.size(); ++i)
    {
        if (s.effects[i].id == id)
        {
            s.effects.erase(s.effects.begin() + i);
            break;
        }
    }
    SDL_UnlockMutex(s.mutex);
}

void setParams(int id, const Params& params)
{
    State& s = state();
    SDL_LockMutex(s.mutex);
    if (Effect* e = find(s, id))
    {
        e->params = params;
        if (e->playing && params.durationMs)
            e->endTime = e->startTime + params.durationMs;
    }
    SDL_UnlockMutex(s.mutex);
}

Params getParams(int id)
{
    State& s = state();
    Params result = {};
    SDL_LockMutex(s.mutex);
    if (Effect* e = find(s, id))
        result = e->params;
    SDL_UnlockMutex(s.mutex);
    return result;
}

void start(int id, unsigned iterations, bool solo)
{
    State& s = state();
    SDL_LockMutex(s.mutex);
    if (solo)
    {
        for (size_t i = 0; i < s.effects.size(); ++i)
            s.effects[i].playing = false;
    }
    if (Effect* e = find(s, id))
    {
        e->playing = true;
        e->startTime = SDL_GetTicks();
        /* an infinite number of iterations (0xffffffff) or no duration: runs until stopped */
        if (e->params.durationMs && iterations != 0xffffffffu)
            e->endTime = e->startTime + (Uint64) e->params.durationMs * (iterations ? iterations : 1);
        else
            e->endTime = 0;
    }
    SDL_UnlockMutex(s.mutex);
}

void stop(int id)
{
    State& s = state();
    SDL_LockMutex(s.mutex);
    if (Effect* e = find(s, id))
        e->playing = false;
    SDL_UnlockMutex(s.mutex);
}

bool isPlaying(int id)
{
    State& s = state();
    bool result = false;
    SDL_LockMutex(s.mutex);
    if (Effect* e = find(s, id))
        result = e->playing;
    SDL_UnlockMutex(s.mutex);
    return result;
}

void stopAll()
{
    State& s = state();
    SDL_LockMutex(s.mutex);
    for (size_t i = 0; i < s.effects.size(); ++i)
        s.effects[i].playing = false;
    SDL_UnlockMutex(s.mutex);
}

void setPaused(bool paused)
{
    State& s = state();
    SDL_LockMutex(s.mutex);
    s.paused = paused;
    SDL_UnlockMutex(s.mutex);
}

void setActuators(bool on)
{
    State& s = state();
    SDL_LockMutex(s.mutex);
    s.actuators = on;
    SDL_UnlockMutex(s.mutex);
}

void update()
{
    State& s = state();
    const Uint64 now = SDL_GetTicks();
    SDL_LockMutex(s.mutex);
    if (s.effects.empty() && s.lastStrength == 0.f)
    {
        SDL_UnlockMutex(s.mutex);
        return;
    }

    float strength = 0.f;
    char dbgPlaying[64] = "";
    for (size_t i = 0; i < s.effects.size(); ++i)
    {
        Effect& e = s.effects[i];
        if (!e.playing)
            continue;
        {
            char one[12];
            snprintf(one, sizeof(one), "%d ", e.id);
            if (strlen(dbgPlaying) + strlen(one) < sizeof(dbgPlaying))
                strcat(dbgPlaying, one);
        }
        if (e.endTime && now >= e.endTime)
        {
            e.playing = false;
            continue;
        }
        if (s.paused || !s.actuators)
            continue;

        float level = 0.f;
        switch (e.params.type)
        {
        case Constant:
            level = e.params.magnitude / 10000.f;
            break;
        case Ramp:
            {
                float t = 0.f;
                if (e.endTime > e.startTime)
                    t = (float) (now - e.startTime) / (float) (e.endTime - e.startTime);
                const float a = (float) (e.params.start < 0 ? -e.params.start : e.params.start);
                const float b = (float) (e.params.end < 0 ? -e.params.end : e.params.end);
                level = (a + (b - a) * t) / 10000.f;
            }
            break;
        case Periodic:
            level = e.params.magnitude / 10000.f;
            if (e.params.period > 20)
            {
                /* sampling the sine at frame times only gives random flicker; the mean level is what a motor shows */
                level *= 0.6f;
            }
            break;
        default:
            /* spring, damper and friction forces have nothing to do on a game pad */
            break;
        }
        if (level < 0.f)
            level = -level;
        level *= e.params.gain / 10000.f;
        if (level > 1.f)
            level = 1.f;
        if (level > strength)
            strength = level;
    }

    {
        /* diagnosis: a time series of the force while something plays */
        static Uint64 s_lastDbg = 0;
        static int s_dbgBudget = 1500;
        if (s_dbgBudget > 0 && (strength > 0.f || s.lastStrength > 0.f) && now - s_lastDbg >= 100)
        {
            --s_dbgBudget;
            s_lastDbg = now;
            SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "ff: strength %.2f, playing: %s", strength, dbgPlaying);
        }
    }
    /* the rumble is refreshed regularly because it only runs for a short time */
    const bool changed = (strength - s.lastStrength > 0.03f) || (s.lastStrength - strength > 0.03f)
                         || (strength == 0.f) != (s.lastStrength == 0.f);
    const bool refresh = strength > 0.f && now - s.lastRumble >= 150;
    if (changed || refresh)
    {
        s.lastStrength = strength;
        s.lastRumble = now;
        SDL_UnlockMutex(s.mutex);
        /*
         * The games ask for gentle forces (a few percent of the maximum) that a pad's motors
         * hardly show. The curve lifts weak forces; sdmc:/switch/nfs3hp/ffgain.txt can scale
         * the result (default 1.0, e.g. 1.5 for stronger, 0.5 for weaker).
         */
        static float s_userGain = -1.f;
        if (s_userGain < 0.f)
        {
            s_userGain = 1.f;
            FILE* f = fopen("sdmc:/switch/nfs3hp/ffgain.txt", "r");
            if (f)
            {
                float v = 0.f;
                if (fscanf(f, "%f", &v) == 1 && v >= 0.f && v <= 4.f)
                    s_userGain = v;
                fclose(f);
                SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "force feedback: gain factor %.2f from ffgain.txt", s_userGain);
            }
        }
        float shaped = strength > 0.f ? std::pow(strength, 0.4f) * s_userGain : 0.f;
        if (shaped > 1.f)
            shaped = 1.f;
        /* the Switch limits the sum of both motor amplitudes to 1.0: stronger values were lost (no rumble at all) */
        const Uint16 low = (Uint16) (shaped * 0.6f * 65535.f);
        const Uint16 high = (Uint16) (shaped * 0.4f * 65535.f);
        Gamepad::rumble(low, high, strength > 0.f ? 250 : 0);
        return;
    }
    SDL_UnlockMutex(s.mutex);
}

}}
