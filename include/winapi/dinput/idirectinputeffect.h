#ifndef DINPUT_IDIRECTINPUTEFFECT_H_
#define DINPUT_IDIRECTINPUTEFFECT_H_

#include <winapi/com.h>
#include <lib/gamepad.h>

namespace win32 { namespace dinput
{

/* DIEFFECT as the game fills it in (pointers are addresses in the guest memory) */
struct DiEffect
{
    DWORD           dwSize;
    DWORD           dwFlags;
    DWORD           dwDuration;
    DWORD           dwSamplePeriod;
    DWORD           dwGain;
    DWORD           dwTriggerButton;
    DWORD           dwTriggerRepeatInterval;
    DWORD           cAxes;
    x86::reg32      rgdwAxes;
    x86::reg32      rglDirection;
    x86::reg32      lpEnvelope;
    DWORD           cbTypeSpecificParams;
    x86::reg32      lpvTypeSpecificParams;
    DWORD           dwStartDelay;
};

/* what is known about an effect (the COM object itself has no room for more than the base class) */
class EffectResource : public GenericResource
{
public:
    EffectResource(int effectId, const GUID& effectGuid) : id(effectId), guid(effectGuid) {}
    int  id;
    GUID guid;
};

/* force feedback effect object that the game creates with IDirectInputDevice::CreateEffect */
class IDirectInputEffect : public com::IUnknown
{
public:
    IDirectInputEffect(EffectResource* resource);

    static x86::reg32 init(WinApplication* app, x86::reg32 memblockIndex, x86::reg8* memBlock);

    /* kind of force feedback effect for a DirectInput effect GUID; false when it is not known */
    static bool typeFromGuid(const GUID& guid, ForceFeedback::Type& type);
    /* takes over the parameters named by the DIEP_* flags */
    static void applyParameters(WinApplication* app, int effectId, const DiEffect* effect, DWORD flags);
    /* the effect GUIDs that are offered to the game */
    static unsigned effectCount();
    static const GUID& effectGuid(unsigned index);
    static const char* effectName(unsigned index);
    static DWORD effectType(unsigned index);

private:
    ULONG   ReleaseEffect(WinApplication* app, x86::CPU& cpu);
    HRESULT Initialize(WinApplication* app, x86::CPU& cpu, HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
    HRESULT GetEffectGuid(WinApplication* app, x86::CPU& cpu, LPGUID pguid);
    HRESULT GetParameters(WinApplication* app, x86::CPU& cpu, DiEffect* peff, DWORD dwFlags);
    HRESULT SetParameters(WinApplication* app, x86::CPU& cpu, const DiEffect* peff, DWORD dwFlags);
    HRESULT Start(WinApplication* app, x86::CPU& cpu, DWORD dwIterations, DWORD dwFlags);
    HRESULT Stop(WinApplication* app, x86::CPU& cpu);
    HRESULT GetEffectStatus(WinApplication* app, x86::CPU& cpu, LPDWORD pdwFlags);
    HRESULT Download(WinApplication* app, x86::CPU& cpu);
    HRESULT Unload(WinApplication* app, x86::CPU& cpu);
    HRESULT Escape(WinApplication* app, x86::CPU& cpu, x86::reg32 pesc);

private:
    EffectResource* effect() const;
    static x86::reg32 s_vtable;
};

}}

#endif /*!DINPUT_IDIRECTINPUTEFFECT_H_*/
