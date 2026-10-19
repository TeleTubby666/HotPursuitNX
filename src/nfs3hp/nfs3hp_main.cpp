#include <SDL3/SDL_main.h>
#include <lib/file.h>
#include <lib/gamepad.h>
#include <lib/log.h>
#include <lib/registry.h>
#include <lib/window.h>
#include <nfs3hp.h>
#include <cstdlib>
#include <cstdio>
#ifdef __SWITCH__
#include <switch.h>
#endif
#include <string>

#ifndef __SWITCH__
static std::string getExeDirectory(const char* argv0)
{
    std::string path(argv0);
    for (auto& c : path)
        if (c == '\\') c = '/';
    auto pos = path.rfind('/');
    if (pos != std::string::npos)
        return path.substr(0, pos + 1);
    return "./";
}
#endif

int main(int argc, char* argv[])
{
#ifdef __SWITCH__
    (void)argc;
    (void)argv;
    setenv("NVK_I_WANT_A_BROKEN_VULKAN_DRIVER", "1", 1);
    win32::initLog("sdmc:/switch/nfs3hp/log.txt");
    win32::logPrintf("NFS3 HP starting (Switch)");
    win32::logImageBase();
    win32::File::setDataDirectory("sdmc:/switch/nfs3hp/");
    win32::File::setCdDirectory("sdmc:/switch/nfs3hp/");
#else
    if (argc >= 3)
    {
        win32::File::setDataDirectory(argv[1]);
        win32::File::setCdDirectory(argv[2]);
    }
    else if (argc == 2)
    {
        win32::File::setDataDirectory(argv[1]);
        win32::File::setCdDirectory(argv[1]);
    }
    else
    {
        std::string exeDir = getExeDirectory(argv[0]);
        win32::File::setDataDirectory(exeDir.c_str());
        win32::File::setCdDirectory(exeDir.c_str());
    }
#endif
    SDL_Init(SDL_INIT_EVENTS|SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_JOYSTICK);
    win32::Gamepad::init();
    win32::g_isNFS3 = true;
    {
        nfs3hp::Application app("nfs3.exe");
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "3D Device Description", new win32::RegistryValue("3Dfx Voodoo 2"));
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "3D Card", new win32::RegistryValue("3Dfx Voodoo 2"));
        //app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "Thrash Driver", new win32::RegistryValue("softtri"));
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "Thrash Driver", new win32::RegistryValue("voodoo2"));
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "Group", new win32::RegistryValue("3Dfx"));
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "D3D Device", new win32::RegistryValue(x86::reg32(0)));
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "Triple Buffer", new win32::RegistryValue(x86::reg32(0)));
        //app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "Hardware Acceleration", new win32::RegistryValue(x86::reg32(0)));
        app.addRegistryKey(win32::HKEY_LOCAL_MACHINE, "SOFTWARE\\Electronic Arts\\Need For Speed III", "Hardware Acceleration", new win32::RegistryValue(x86::reg32(1)));
        app.execute();
    }
#ifdef __SWITCH__
    /*
     * The way out of the process is still being worked out: exiting crashes on the console.
     * sdmc:/switch/nfs3hp/exitmode.txt (a single digit) selects the variant to try.
     */
    win32::stopWatchdog();
    int exitMode = 0;
    if (FILE* f = fopen("sdmc:/switch/nfs3hp/exitmode.txt", "r"))
    {
        int c = fgetc(f);
        if (c >= '0' && c <= '4')
            exitMode = c - '0';
        fclose(f);
    }
    win32::logPrintf("game finished, exit mode %d", exitMode);
    win32::logImageBase();
    switch (exitMode)
    {
    case 0: /* return from main without any teardown */
        return 0;
    case 1:
        _Exit(0);
    case 2: /* hard exit of the process, skipping libnx cleanup */
        svcExitProcess();
        break;
    case 3: /* SDL teardown first */
        SDL_Quit();
        win32::logPrintf("SDL_Quit done");
        return 0;
    case 4: /* tear down only the video system */
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
        win32::logPrintf("video subsystem closed");
        return 0;
    }
#endif
    SDL_Quit();
    return 0;
}
