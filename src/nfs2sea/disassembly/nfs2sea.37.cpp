#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4c2fd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c2fd8);
    // 004c2fd8  ff2554454c00           -jmp dword ptr [0x4c4554]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998484), cpu);
}

/* align: skip  */
void Application::sub_4c2fde(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c2fde);
    // 004c2fde  ff2598454c00           -jmp dword ptr [0x4c4598]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998552), cpu);
}

/* align: skip  */
void Application::sub_4c2fe4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c2fe4);
    // 004c2fe4  ff25f0444c00           -jmp dword ptr [0x4c44f0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998384), cpu);
}

/* align: skip  */
void Application::sub_4c2fea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c2fea);
    // 004c2fea  ff259c454c00           -jmp dword ptr [0x4c459c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998556), cpu);
}

/* align: skip  */
void Application::sub_4c2ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c2ff0);
    // 004c2ff0  ff2570434c00           -jmp dword ptr [0x4c4370]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998000), cpu);
}

/* align: skip  */
void Application::sub_4c2ff6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c2ff6);
    // 004c2ff6  ff253c454c00           -jmp dword ptr [0x4c453c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998460), cpu);
}

/* align: skip  */
void Application::sub_4c2ffc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c2ffc);
    // 004c2ffc  ff2584444c00           -jmp dword ptr [0x4c4484]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998276), cpu);
}

/* align: skip  */
void Application::sub_4c3002(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3002);
    // 004c3002  ff2540454c00           -jmp dword ptr [0x4c4540]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998464), cpu);
}

/* align: skip  */
void Application::sub_4c3008(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3008);
    // 004c3008  ff257c444c00           -jmp dword ptr [0x4c447c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998268), cpu);
}

/* align: skip  */
void Application::sub_4c300e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c300e);
    // 004c300e  ff2554444c00           -jmp dword ptr [0x4c4454]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998228), cpu);
}

/* align: skip  */
void Application::sub_4c3014(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3014);
    // 004c3014  ff252c454c00           -jmp dword ptr [0x4c452c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998444), cpu);
}

/* align: skip  */
void Application::sub_4c301a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c301a);
    // 004c301a  ff25e4444c00           -jmp dword ptr [0x4c44e4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998372), cpu);
}

/* align: skip  */
void Application::sub_4c3020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3020);
    // 004c3020  ff2544444c00           -jmp dword ptr [0x4c4444]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998212), cpu);
}

/* align: skip  */
void Application::sub_4c3026(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3026);
    // 004c3026  ff2514454c00           -jmp dword ptr [0x4c4514]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998420), cpu);
}

/* align: skip  */
void Application::sub_4c302c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c302c);
    // 004c302c  ff2550444c00           -jmp dword ptr [0x4c4450]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998224), cpu);
}

/* align: skip  */
void Application::sub_4c3032(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3032);
    // 004c3032  ff2510454c00           -jmp dword ptr [0x4c4510]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998416), cpu);
}

/* align: skip  */
void Application::sub_4c3038(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3038);
    // 004c3038  ff255c444c00           -jmp dword ptr [0x4c445c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998236), cpu);
}

/* align: skip  */
void Application::sub_4c303e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c303e);
    // 004c303e  ff2570454c00           -jmp dword ptr [0x4c4570]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998512), cpu);
}

/* align: skip  */
void Application::sub_4c3044(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3044);
    // 004c3044  ff25f4444c00           -jmp dword ptr [0x4c44f4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998388), cpu);
}

/* align: skip  */
void Application::sub_4c304a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c304a);
    // 004c304a  ff257c454c00           -jmp dword ptr [0x4c457c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998524), cpu);
}

/* align: skip  */
void Application::sub_4c3050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3050);
    // 004c3050  ff2578454c00           -jmp dword ptr [0x4c4578]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998520), cpu);
}

/* align: skip  */
void Application::sub_4c3056(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3056);
    // 004c3056  ff2538454c00           -jmp dword ptr [0x4c4538]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998456), cpu);
}

/* align: skip  */
void Application::sub_4c305c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c305c);
    // 004c305c  ff253c444c00           -jmp dword ptr [0x4c443c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998204), cpu);
}

/* align: skip  */
void Application::sub_4c3062(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3062);
    // 004c3062  ff254c444c00           -jmp dword ptr [0x4c444c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998220), cpu);
}

/* align: skip  */
void Application::sub_4c3068(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3068);
    // 004c3068  ff25a4444c00           -jmp dword ptr [0x4c44a4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998308), cpu);
}

/* align: skip  */
void Application::sub_4c306e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c306e);
    // 004c306e  ff2598444c00           -jmp dword ptr [0x4c4498]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998296), cpu);
}

/* align: skip  */
void Application::sub_4c3074(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3074);
    // 004c3074  ff25a0444c00           -jmp dword ptr [0x4c44a0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998304), cpu);
}

/* align: skip  */
void Application::sub_4c307a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c307a);
    // 004c307a  ff25a8454c00           -jmp dword ptr [0x4c45a8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998568), cpu);
}

/* align: skip  */
void Application::sub_4c3080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3080);
    // 004c3080  ff25b4444c00           -jmp dword ptr [0x4c44b4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998324), cpu);
}

/* align: skip  */
void Application::sub_4c3086(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3086);
    // 004c3086  ff2568444c00           -jmp dword ptr [0x4c4468]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998248), cpu);
}

/* align: skip  */
void Application::sub_4c308c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c308c);
    // 004c308c  ff2548444c00           -jmp dword ptr [0x4c4448]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998216), cpu);
}

/* align: skip  */
void Application::sub_4c3092(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3092);
    // 004c3092  ff2558444c00           -jmp dword ptr [0x4c4458]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998232), cpu);
}

/* align: skip  */
void Application::sub_4c3098(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3098);
    // 004c3098  ff250c444c00           -jmp dword ptr [0x4c440c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998156), cpu);
}

/* align: skip  */
void Application::sub_4c309e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c309e);
    // 004c309e  ff25b4434c00           -jmp dword ptr [0x4c43b4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998068), cpu);
}

/* align: skip  */
void Application::sub_4c30a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30a4);
    // 004c30a4  ff2538444c00           -jmp dword ptr [0x4c4438]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998200), cpu);
}

/* align: skip  */
void Application::sub_4c30aa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30aa);
    // 004c30aa  ff25f8444c00           -jmp dword ptr [0x4c44f8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998392), cpu);
}

/* align: skip  */
void Application::sub_4c30b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30b0);
    // 004c30b0  ff2504444c00           -jmp dword ptr [0x4c4404]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998148), cpu);
}

/* align: skip  */
void Application::sub_4c30b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30b6);
    // 004c30b6  ff2518444c00           -jmp dword ptr [0x4c4418]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998168), cpu);
}

/* align: skip  */
void Application::sub_4c30bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30bc);
    // 004c30bc  ff2500444c00           -jmp dword ptr [0x4c4400]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998144), cpu);
}

/* align: skip  */
void Application::sub_4c30c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30c2);
    // 004c30c2  ff25e8434c00           -jmp dword ptr [0x4c43e8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998120), cpu);
}

/* align: skip  */
void Application::sub_4c30c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30c8);
    // 004c30c8  ff2580434c00           -jmp dword ptr [0x4c4380]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998016), cpu);
}

/* align: skip  */
void Application::sub_4c30ce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30ce);
    // 004c30ce  ff25d4434c00           -jmp dword ptr [0x4c43d4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998100), cpu);
}

/* align: skip  */
void Application::sub_4c30d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30d4);
    // 004c30d4  ff25a8434c00           -jmp dword ptr [0x4c43a8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998056), cpu);
}

/* align: skip  */
void Application::sub_4c30da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30da);
    // 004c30da  ff25f0434c00           -jmp dword ptr [0x4c43f0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998128), cpu);
}

/* align: skip  */
void Application::sub_4c30e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30e0);
    // 004c30e0  ff25cc434c00           -jmp dword ptr [0x4c43cc]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998092), cpu);
}

/* align: skip  */
void Application::sub_4c30e6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30e6);
    // 004c30e6  ff25a0434c00           -jmp dword ptr [0x4c43a0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998048), cpu);
}

/* align: skip  */
void Application::sub_4c30ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30ec);
    // 004c30ec  ff2588434c00           -jmp dword ptr [0x4c4388]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998024), cpu);
}

/* align: skip  */
void Application::sub_4c30f2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30f2);
    // 004c30f2  ff2590434c00           -jmp dword ptr [0x4c4390]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998032), cpu);
}

/* align: skip  */
void Application::sub_4c30f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30f8);
    // 004c30f8  ff25b8434c00           -jmp dword ptr [0x4c43b8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998072), cpu);
}

/* align: skip  */
void Application::sub_4c30fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c30fe);
    // 004c30fe  ff25a4434c00           -jmp dword ptr [0x4c43a4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998052), cpu);
}

/* align: skip  */
void Application::sub_4c3104(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3104);
    // 004c3104  ff25b0434c00           -jmp dword ptr [0x4c43b0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998064), cpu);
}

/* align: skip  */
void Application::sub_4c310a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c310a);
    // 004c310a  ff258c434c00           -jmp dword ptr [0x4c438c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998028), cpu);
}

/* align: skip  */
void Application::sub_4c3110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3110);
    // 004c3110  ff2540444c00           -jmp dword ptr [0x4c4440]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998208), cpu);
}

/* align: skip  */
void Application::sub_4c3116(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3116);
    // 004c3116  ff25bc434c00           -jmp dword ptr [0x4c43bc]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998076), cpu);
}

/* align: skip  */
void Application::sub_4c311c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c311c);
    // 004c311c  ff2510444c00           -jmp dword ptr [0x4c4410]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998160), cpu);
}

/* align: skip  */
void Application::sub_4c3122(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3122);
    // 004c3122  ff25e0434c00           -jmp dword ptr [0x4c43e0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998112), cpu);
}

/* align: skip  */
void Application::sub_4c3128(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3128);
    // 004c3128  ff25f8434c00           -jmp dword ptr [0x4c43f8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998136), cpu);
}

/* align: skip  */
void Application::sub_4c312e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c312e);
    // 004c312e  ff25ec434c00           -jmp dword ptr [0x4c43ec]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998124), cpu);
}

/* align: skip  */
void Application::sub_4c3134(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3134);
    // 004c3134  ff2550454c00           -jmp dword ptr [0x4c4550]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998480), cpu);
}

/* align: skip  */
void Application::sub_4c313a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c313a);
    // 004c313a  ff2594454c00           -jmp dword ptr [0x4c4594]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998548), cpu);
}

/* align: skip  */
void Application::sub_4c3140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3140);
    // 004c3140  ff25b8454c00           -jmp dword ptr [0x4c45b8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998584), cpu);
}

/* align: skip  */
void Application::sub_4c3146(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3146);
    // 004c3146  ff251c454c00           -jmp dword ptr [0x4c451c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998428), cpu);
}

/* align: skip  */
void Application::sub_4c314c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c314c);
    // 004c314c  ff2534444c00           -jmp dword ptr [0x4c4434]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998196), cpu);
}

/* align: skip  */
void Application::sub_4c3152(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3152);
    // 004c3152  ff25b8444c00           -jmp dword ptr [0x4c44b8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998328), cpu);
}

/* align: skip  */
void Application::sub_4c3158(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3158);
    // 004c3158  ff2530444c00           -jmp dword ptr [0x4c4430]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998192), cpu);
}

/* align: skip  */
void Application::sub_4c315e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c315e);
    // 004c315e  ff2594444c00           -jmp dword ptr [0x4c4494]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998292), cpu);
}

/* align: skip  */
void Application::sub_4c3164(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3164);
    // 004c3164  ff254c454c00           -jmp dword ptr [0x4c454c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998476), cpu);
}

/* align: skip  */
void Application::sub_4c316a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c316a);
    // 004c316a  ff25a8444c00           -jmp dword ptr [0x4c44a8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998312), cpu);
}

/* align: skip  */
void Application::sub_4c3170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3170);
    // 004c3170  ff25cc444c00           -jmp dword ptr [0x4c44cc]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998348), cpu);
}

/* align: skip  */
void Application::sub_4c3176(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3176);
    // 004c3176  ff25d0444c00           -jmp dword ptr [0x4c44d0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998352), cpu);
}

/* align: skip  */
void Application::sub_4c317c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c317c);
    // 004c317c  ff25c4444c00           -jmp dword ptr [0x4c44c4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998340), cpu);
}

/* align: skip  */
void Application::sub_4c3182(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3182);
    // 004c3182  ff2560444c00           -jmp dword ptr [0x4c4460]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998240), cpu);
}

/* align: skip  */
void Application::sub_4c3188(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3188);
    // 004c3188  ff2564444c00           -jmp dword ptr [0x4c4464]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998244), cpu);
}

/* align: skip  */
void Application::sub_4c318e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c318e);
    // 004c318e  ff2594434c00           -jmp dword ptr [0x4c4394]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998036), cpu);
}

/* align: skip  */
void Application::sub_4c3194(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3194);
    // 004c3194  ff2504454c00           -jmp dword ptr [0x4c4504]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998404), cpu);
}

/* align: skip  */
void Application::sub_4c319a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c319a);
    // 004c319a  ff25c0444c00           -jmp dword ptr [0x4c44c0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998336), cpu);
}

/* align: skip  */
void Application::sub_4c31a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31a0);
    // 004c31a0  ff2534454c00           -jmp dword ptr [0x4c4534]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998452), cpu);
}

/* align: skip  */
void Application::sub_4c31a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31a6);
    // 004c31a6  ff2564454c00           -jmp dword ptr [0x4c4564]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998500), cpu);
}

/* align: skip  */
void Application::sub_4c31ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31ac);
    // 004c31ac  ff2560454c00           -jmp dword ptr [0x4c4560]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998496), cpu);
}

/* align: skip  */
void Application::sub_4c31b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31b2);
    // 004c31b2  ff250c454c00           -jmp dword ptr [0x4c450c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998412), cpu);
}

/* align: skip  */
void Application::sub_4c31b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31b8);
    // 004c31b8  ff25d8434c00           -jmp dword ptr [0x4c43d8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998104), cpu);
}

/* align: skip  */
void Application::sub_4c31be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31be);
    // 004c31be  ff25e8444c00           -jmp dword ptr [0x4c44e8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998376), cpu);
}

/* align: skip  */
void Application::sub_4c31c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31c4);
    // 004c31c4  ff2570444c00           -jmp dword ptr [0x4c4470]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998256), cpu);
}

/* align: skip  */
void Application::sub_4c31ca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31ca);
    // 004c31ca  ff2518454c00           -jmp dword ptr [0x4c4518]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998424), cpu);
}

/* align: skip  */
void Application::sub_4c31d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31d0);
    // 004c31d0  ff2508454c00           -jmp dword ptr [0x4c4508]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998408), cpu);
}

/* align: skip  */
void Application::sub_4c31d6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31d6);
    // 004c31d6  ff25ac454c00           -jmp dword ptr [0x4c45ac]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998572), cpu);
}

/* align: skip  */
void Application::sub_4c31dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31dc);
    // 004c31dc  ff25dc434c00           -jmp dword ptr [0x4c43dc]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998108), cpu);
}

/* align: skip  */
void Application::sub_4c31e2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31e2);
    // 004c31e2  ff25fc434c00           -jmp dword ptr [0x4c43fc]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998140), cpu);
}

/* align: skip  */
void Application::sub_4c31e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31e8);
    // 004c31e8  ff255c454c00           -jmp dword ptr [0x4c455c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998492), cpu);
}

/* align: skip  */
void Application::sub_4c31ee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31ee);
    // 004c31ee  ff2528454c00           -jmp dword ptr [0x4c4528]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998440), cpu);
}

/* align: skip  */
void Application::sub_4c31f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31f4);
    // 004c31f4  ff259c434c00           -jmp dword ptr [0x4c439c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998044), cpu);
}

/* align: skip  */
void Application::sub_4c31fa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c31fa);
    // 004c31fa  ff252c444c00           -jmp dword ptr [0x4c442c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998188), cpu);
}

/* align: skip  */
void Application::sub_4c3200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3200);
    // 004c3200  ff2508444c00           -jmp dword ptr [0x4c4408]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998152), cpu);
}

/* align: skip  */
void Application::sub_4c3206(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3206);
    // 004c3206  ff25f4434c00           -jmp dword ptr [0x4c43f4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998132), cpu);
}

/* align: skip  */
void Application::sub_4c320c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c320c);
    // 004c320c  ff25dc444c00           -jmp dword ptr [0x4c44dc]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998364), cpu);
}

/* align: skip  */
void Application::sub_4c3212(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3212);
    // 004c3212  ff25e4434c00           -jmp dword ptr [0x4c43e4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998116), cpu);
}

/* align: skip  */
void Application::sub_4c3218(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3218);
    // 004c3218  ff25ac434c00           -jmp dword ptr [0x4c43ac]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998060), cpu);
}

/* align: skip  */
void Application::sub_4c321e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c321e);
    // 004c321e  ff2514444c00           -jmp dword ptr [0x4c4414]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998164), cpu);
}

/* align: skip  */
void Application::sub_4c3224(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c3224);
    // 004c3224  ff25c8434c00           -jmp dword ptr [0x4c43c8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998088), cpu);
}

/* align: skip  */
void Application::sub_4c322a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c322a);
    // 004c322a  ff2580444c00           -jmp dword ptr [0x4c4480]
    return app->dynamic_call(app->getMemory<x86::reg32>(4998272), cpu);
}

}
