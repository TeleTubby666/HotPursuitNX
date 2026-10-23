#include <winapi/dinput/idirectinputeffect.h>
#include <winapi/wrapper.h>
#include <lib/gamepad.h>


namespace win32 { namespace dinput
{

x86::reg32 IDirectInputEffect::s_vtable = 0;

/* DIEP_* flags */
enum
{
    DIEP_DURATION           = 0x00000001,
    DIEP_SAMPLEPERIOD       = 0x00000002,
    DIEP_GAIN               = 0x00000004,
    DIEP_TYPESPECIFICPARAMS = 0x00000100,
    DIEP_ALLPARAMS          = 0x000001ff,
    DIEP_START              = 0x20000000
};

/* DIES_* flags of Start */
enum
{
    DIES_SOLO = 0x00000001
};

/* DIEGES_* flags of GetEffectStatus */
enum
{
    DIEGES_PLAYING = 0x00000001
};

static const DWORD DIEFT_CONSTANTFORCE  = 0x00000001;
static const DWORD DIEFT_RAMPFORCE      = 0x00000002;
static const DWORD DIEFT_PERIODIC       = 0x00000003;
static const DWORD DIEFT_CONDITION      = 0x00000004;
static const DWORD DIEFT_CUSTOMFORCE    = 0x00000005;

#define EFFECT_GUID(last) { 0x13541C20 + last, 0x8E33, 0x11D0, { 0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35 } }

struct EffectInfo
{
    GUID                    guid;
    const char*             name;
    DWORD                   type;
    ForceFeedback::Type     kind;
};

static const EffectInfo s_effects[] =
{
    { EFFECT_GUID(0x0), "ConstantForce", DIEFT_CONSTANTFORCE, ForceFeedback::Constant },
    { EFFECT_GUID(0x1), "RampForce",     DIEFT_RAMPFORCE,     ForceFeedback::Ramp },
    { EFFECT_GUID(0x2), "Square",        DIEFT_PERIODIC,      ForceFeedback::Periodic },
    { EFFECT_GUID(0x3), "Sine",          DIEFT_PERIODIC,      ForceFeedback::Periodic },
    { EFFECT_GUID(0x4), "Triangle",      DIEFT_PERIODIC,      ForceFeedback::Periodic },
    { EFFECT_GUID(0x5), "SawtoothUp",    DIEFT_PERIODIC,      ForceFeedback::Periodic },
    { EFFECT_GUID(0x6), "SawtoothDown",  DIEFT_PERIODIC,      ForceFeedback::Periodic },
    { EFFECT_GUID(0x7), "Spring",        DIEFT_CONDITION,     ForceFeedback::Condition },
    { EFFECT_GUID(0x8), "Damper",        DIEFT_CONDITION,     ForceFeedback::Condition },
    { EFFECT_GUID(0x9), "Inertia",       DIEFT_CONDITION,     ForceFeedback::Condition },
    { EFFECT_GUID(0xA), "Friction",      DIEFT_CONDITION,     ForceFeedback::Condition },
    { EFFECT_GUID(0xB), "CustomForce",   DIEFT_CUSTOMFORCE,   ForceFeedback::Custom }
};

static const unsigned s_effectCount = sizeof(s_effects) / sizeof(s_effects[0]);

unsigned IDirectInputEffect::effectCount()                  { return s_effectCount; }
const GUID& IDirectInputEffect::effectGuid(unsigned index)  { return s_effects[index].guid; }
const char* IDirectInputEffect::effectName(unsigned index)  { return s_effects[index].name; }
DWORD IDirectInputEffect::effectType(unsigned index)        { return s_effects[index].type; }

bool IDirectInputEffect::typeFromGuid(const GUID& guid, ForceFeedback::Type& type)
{
    for (unsigned i = 0; i < s_effectCount; ++i)
    {
        if (guid == s_effects[i].guid)
        {
            type = s_effects[i].kind;
            return true;
        }
    }
    return false;
}

static unsigned s_logBudget = 60;

static void logEffect(const char* what, int id)
{
    if (s_logBudget)
    {
        --s_logBudget;
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "force feedback: %s (effect %d)", what, id);
    }
}

void IDirectInputEffect::applyParameters(WinApplication* app, int effectId, const DiEffect* effect, DWORD flags)
{
    if (!effect)
        return;
    ForceFeedback::Params params = ForceFeedback::getParams(effectId);
    if (flags & DIEP_DURATION)
        params.durationMs = effect->dwDuration == 0xffffffffu ? 0 : (effect->dwDuration + 999) / 1000;
    if (flags & DIEP_GAIN)
        params.gain = effect->dwGain > 10000 ? 10000 : effect->dwGain;
    if ((flags & DIEP_TYPESPECIFICPARAMS) && effect->lpvTypeSpecificParams && effect->cbTypeSpecificParams >= 4)
    {
        const x86::reg8* data = &app->getMemory<const x86::reg8>(effect->lpvTypeSpecificParams);
        auto readLong = [&](unsigned offset) -> int { int v = 0; memcpy(&v, data + offset, 4); return v; };
        auto absInt = [](int v) { return v < 0 ? -v : v; };
        switch (params.type)
        {
        case ForceFeedback::Constant:       /* DICONSTANTFORCE: lMagnitude */
            params.magnitude = absInt(readLong(0));
            break;
        case ForceFeedback::Ramp:           /* DIRAMPFORCE: lStart, lEnd */
            if (effect->cbTypeSpecificParams >= 8)
            {
                params.start = readLong(0);
                params.end = readLong(4);
                params.magnitude = absInt(params.start) > absInt(params.end) ? absInt(params.start) : absInt(params.end);
            }
            break;
        case ForceFeedback::Periodic:       /* DIPERIODIC: dwMagnitude, lOffset, dwPhase, dwPeriod (microseconds) */
            params.magnitude = absInt(readLong(0));
            if (effect->cbTypeSpecificParams >= 16)
                params.period = (unsigned) readLong(12) / 1000;
            break;
        default:
            break;
        }
        if (params.magnitude > 10000)
            params.magnitude = 10000;
    }
    ForceFeedback::setParams(effectId, params);
}

DEFINE_GUID(IID_IDirectInputEffect, 0xE7E1F7C0, 0x88D2, 0x11D0, 0x9A, 0xD0, 0x00, 0xA0, 0xC9, 0xA0, 0x6E, 0x35);

IDirectInputEffect::IDirectInputEffect(EffectResource* resource)
    :   IUnknown(IID_IDirectInputEffect)
{
    m_vtable = s_vtable;
    m_resource = resource;
}

EffectResource* IDirectInputEffect::effect() const
{
    return static_cast<EffectResource*>(m_resource);
}

ULONG IDirectInputEffect::ReleaseEffect(WinApplication* app, x86::CPU& cpu)
{
    EffectResource* res = effect();
    const int id = res ? res->id : 0;
    const x86::reg32 resourceIndex = res ? res->getResourceIndex() : 0;
    const ULONG result = com::IUnknown::Release(app, cpu);
    if (result == 0 && res)
    {
        logEffect("effect released", id);
        ForceFeedback::remove(id);
        app->freeResource(resourceIndex);
    }
    return result;
}

HRESULT IDirectInputEffect::Initialize(WinApplication* app, x86::CPU& cpu, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hinst);
    NFS2_USE(dwVersion);
    NFS2_USE(rguid);
    return 0;
}

HRESULT IDirectInputEffect::GetEffectGuid(WinApplication* app, x86::CPU& cpu, LPGUID pguid)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (pguid && effect())
        *pguid = effect()->guid;
    return 0;
}

HRESULT IDirectInputEffect::GetParameters(WinApplication* app, x86::CPU& cpu, DiEffect* peff, DWORD dwFlags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (peff && effect())
    {
        const ForceFeedback::Params params = ForceFeedback::getParams(effect()->id);
        if (dwFlags & DIEP_DURATION)
            peff->dwDuration = params.durationMs ? params.durationMs * 1000 : 0xffffffffu;
        if (dwFlags & DIEP_GAIN)
            peff->dwGain = params.gain;
    }
    return 0;
}

HRESULT IDirectInputEffect::SetParameters(WinApplication* app, x86::CPU& cpu, const DiEffect* peff, DWORD dwFlags)
{
    NFS2_USE(cpu);
    if (!effect())
        return 0;
    applyParameters(app, effect()->id, peff, dwFlags);
    if (dwFlags & DIEP_START)
    {
        logEffect("set parameters and start", effect()->id);
        ForceFeedback::start(effect()->id, 1, false);
    }
    return 0;
}

HRESULT IDirectInputEffect::Start(WinApplication* app, x86::CPU& cpu, DWORD dwIterations, DWORD dwFlags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (effect())
    {
        logEffect("start", effect()->id);
        ForceFeedback::start(effect()->id, dwIterations, !!(dwFlags & DIES_SOLO));
    }
    return 0;
}

HRESULT IDirectInputEffect::Stop(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (effect())
    {
        logEffect("stop", effect()->id);
        ForceFeedback::stop(effect()->id);
    }
    return 0;
}

HRESULT IDirectInputEffect::GetEffectStatus(WinApplication* app, x86::CPU& cpu, LPDWORD pdwFlags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (pdwFlags)
        *pdwFlags = (effect() && ForceFeedback::isPlaying(effect()->id)) ? DIEGES_PLAYING : 0;
    return 0;
}

HRESULT IDirectInputEffect::Download(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return 0;
}

HRESULT IDirectInputEffect::Unload(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (effect())
        ForceFeedback::stop(effect()->id);
    return 0;
}

HRESULT IDirectInputEffect::Escape(WinApplication* app, x86::CPU& cpu, x86::reg32 pesc)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(pesc);
    return 0;
}

x86::reg32 IDirectInputEffect::init(WinApplication *app, x86::reg32 memblockIndex, x86::reg8* memBlock)
{
    x86::reg32* vtable = reinterpret_cast<x86::reg32*>(memBlock);
    app->registerMethod(0x40008a, {"IDirectInputEffect::Release", &Wrapper<decltype(&IDirectInputEffect::ReleaseEffect), &IDirectInputEffect::ReleaseEffect>::stdcall});
    app->registerMethod(0x40008b, {"IDirectInputEffect::Initialize", &Wrapper<decltype(&IDirectInputEffect::Initialize), &IDirectInputEffect::Initialize>::stdcall});
    app->registerMethod(0x40008c, {"IDirectInputEffect::GetEffectGuid", &Wrapper<decltype(&IDirectInputEffect::GetEffectGuid), &IDirectInputEffect::GetEffectGuid>::stdcall});
    app->registerMethod(0x40008d, {"IDirectInputEffect::GetParameters", &Wrapper<decltype(&IDirectInputEffect::GetParameters), &IDirectInputEffect::GetParameters>::stdcall});
    app->registerMethod(0x40008e, {"IDirectInputEffect::SetParameters", &Wrapper<decltype(&IDirectInputEffect::SetParameters), &IDirectInputEffect::SetParameters>::stdcall});
    app->registerMethod(0x40008f, {"IDirectInputEffect::Start", &Wrapper<decltype(&IDirectInputEffect::Start), &IDirectInputEffect::Start>::stdcall});
    app->registerMethod(0x400090, {"IDirectInputEffect::Stop", &Wrapper<decltype(&IDirectInputEffect::Stop), &IDirectInputEffect::Stop>::stdcall});
    app->registerMethod(0x400091, {"IDirectInputEffect::GetEffectStatus", &Wrapper<decltype(&IDirectInputEffect::GetEffectStatus), &IDirectInputEffect::GetEffectStatus>::stdcall});
    app->registerMethod(0x400092, {"IDirectInputEffect::Download", &Wrapper<decltype(&IDirectInputEffect::Download), &IDirectInputEffect::Download>::stdcall});
    app->registerMethod(0x400093, {"IDirectInputEffect::Unload", &Wrapper<decltype(&IDirectInputEffect::Unload), &IDirectInputEffect::Unload>::stdcall});
    app->registerMethod(0x400094, {"IDirectInputEffect::Escape", &Wrapper<decltype(&IDirectInputEffect::Escape), &IDirectInputEffect::Escape>::stdcall});

    s_vtable = memblockIndex;
    vtable[0] = 0x400000;    // IUnknown_QueryInterface
    vtable[1] = 0x400001;    // IUnknown_AddRef
    vtable[2] = 0x40008a;    // Release (also removes the effect)
    vtable[3] = 0x40008b;    // Initialize
    vtable[4] = 0x40008c;    // GetEffectGuid
    vtable[5] = 0x40008d;    // GetParameters
    vtable[6] = 0x40008e;    // SetParameters
    vtable[7] = 0x40008f;    // Start
    vtable[8] = 0x400090;    // Stop
    vtable[9] = 0x400091;    // GetEffectStatus
    vtable[10] = 0x400092;   // Download
    vtable[11] = 0x400093;   // Unload
    vtable[12] = 0x400094;   // Escape
    return 13 * sizeof(x86::reg32);
}

}}
