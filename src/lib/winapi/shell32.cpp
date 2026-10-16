#include <SDL3/SDL.h>
#include <winapi/shell32.h>
#include <x86.h>

namespace win32 { namespace shell32
{



HINSTANCE ShellExecuteA(WinApplication* app, x86::CPU& cpu, HWND hwnd, LPCSTR lpOperation,
                        LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, int nShowCmd)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hwnd);
    NFS2_USE(lpOperation);
    NFS2_USE(lpParameters);
    NFS2_USE(lpDirectory);
    NFS2_USE(nShowCmd);
    /*
     * The game uses this to open web pages (e.g. the "Download car" menu entry).
     * There is no shell to hand it to, so ignore the request. Values above 32
     * mean success for ShellExecute.
     */
    SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "ShellExecuteA ignored: %s", lpFile ? lpFile : "(null)");
    return 33;
}

}}
