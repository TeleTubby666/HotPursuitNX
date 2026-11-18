#include <winapi/dinput.h>
#include <winapi/com.h>
#include <winapi/dinput/idirectinput2.h>
#include <x86.h>

namespace win32 { namespace dinput
{

HRESULT DirectInputCreateA(WinApplication* app, x86::CPU& cpu,
                           HINSTANCE hinst, DWORD dwVersion, Packed<IDirectInput2>* lplpDirectInput,
                           LPVOID punkOuter)
{
    { static int s_trace = 30; if (s_trace > 0) { --s_trace; SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "trace: DirectInputCreateA"); } }
    NFS2_USE(cpu);
    NFS2_USE(hinst);
    NFS2_USE(dwVersion);
    NFS2_ASSERT(punkOuter == nullptr);
    const auto object = com::ComAlloc(app);
    *lplpDirectInput = Packed<IDirectInput2>(object);
    IDirectInput2* dinput = &app->getMemory<IDirectInput2>(*lplpDirectInput);
    new (dinput) IDirectInput2();
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "DirectInputCreateA: object 0x%08x, returns 0", (unsigned) object);
    return 0;
}

}}
