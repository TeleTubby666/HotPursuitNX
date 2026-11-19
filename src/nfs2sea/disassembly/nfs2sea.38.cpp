#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4c50c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c50c2);
    // 004c50c2  ff2518644c00           -jmp dword ptr [0x4c6418]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006360), cpu);
}

/* align: skip  */
void Application::sub_4c50c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c50c8);
    // 004c50c8  ff257c654c00           -jmp dword ptr [0x4c657c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006716), cpu);
}

/* align: skip  */
void Application::sub_4c50ce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c50ce);
    // 004c50ce  ff25c0654c00           -jmp dword ptr [0x4c65c0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006784), cpu);
}

/* align: skip  */
void Application::sub_4c50d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c50d4);
    // 004c50d4  ff25e4654c00           -jmp dword ptr [0x4c65e4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006820), cpu);
}

/* align: skip  */
void Application::sub_4c50da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c50da);
    // 004c50da  ff2548654c00           -jmp dword ptr [0x4c6548]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006664), cpu);
}

/* align: skip  */
void Application::sub_4c50e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c50e0);
    // 004c50e0  ff2560644c00           -jmp dword ptr [0x4c6460]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006432), cpu);
}

/* align: skip  */
void Application::sub_4c50e6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c50e6);
    // 004c50e6  ff25e4644c00           -jmp dword ptr [0x4c64e4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006564), cpu);
}

/* align: skip  */
void Application::sub_4c50ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c50ec);
    // 004c50ec  ff255c644c00           -jmp dword ptr [0x4c645c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006428), cpu);
}

/* align: skip  */
void Application::sub_4c50f2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c50f2);
    // 004c50f2  ff25c0644c00           -jmp dword ptr [0x4c64c0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006528), cpu);
}

/* align: skip  */
void Application::sub_4c50f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c50f8);
    // 004c50f8  ff2578654c00           -jmp dword ptr [0x4c6578]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006712), cpu);
}

/* align: skip  */
void Application::sub_4c50fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c50fe);
    // 004c50fe  ff25d4644c00           -jmp dword ptr [0x4c64d4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006548), cpu);
}

/* align: skip  */
void Application::sub_4c5104(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5104);
    // 004c5104  ff25f8644c00           -jmp dword ptr [0x4c64f8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006584), cpu);
}

/* align: skip  */
void Application::sub_4c510a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c510a);
    // 004c510a  ff25fc644c00           -jmp dword ptr [0x4c64fc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006588), cpu);
}

/* align: skip  */
void Application::sub_4c5110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5110);
    // 004c5110  ff25f0644c00           -jmp dword ptr [0x4c64f0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006576), cpu);
}

/* align: skip  */
void Application::sub_4c5116(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5116);
    // 004c5116  ff258c644c00           -jmp dword ptr [0x4c648c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006476), cpu);
}

/* align: skip  */
void Application::sub_4c511c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c511c);
    // 004c511c  ff2590644c00           -jmp dword ptr [0x4c6490]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006480), cpu);
}

/* align: skip  */
void Application::sub_4c5122(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5122);
    // 004c5122  ff25c0634c00           -jmp dword ptr [0x4c63c0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006272), cpu);
}

/* align: skip  */
void Application::sub_4c5128(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5128);
    // 004c5128  ff2530654c00           -jmp dword ptr [0x4c6530]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006640), cpu);
}

/* align: skip  */
void Application::sub_4c512e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c512e);
    // 004c512e  ff25ec644c00           -jmp dword ptr [0x4c64ec]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006572), cpu);
}

/* align: skip  */
void Application::sub_4c5134(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5134);
    // 004c5134  ff2560654c00           -jmp dword ptr [0x4c6560]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006688), cpu);
}

/* align: skip  */
void Application::sub_4c513a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c513a);
    // 004c513a  ff2590654c00           -jmp dword ptr [0x4c6590]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006736), cpu);
}

/* align: skip  */
void Application::sub_4c5140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5140);
    // 004c5140  ff258c654c00           -jmp dword ptr [0x4c658c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006732), cpu);
}

/* align: skip  */
void Application::sub_4c5146(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5146);
    // 004c5146  ff2538654c00           -jmp dword ptr [0x4c6538]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006648), cpu);
}

/* align: skip  */
void Application::sub_4c514c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c514c);
    // 004c514c  ff2504644c00           -jmp dword ptr [0x4c6404]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006340), cpu);
}

/* align: skip  */
void Application::sub_4c5152(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5152);
    // 004c5152  ff2514654c00           -jmp dword ptr [0x4c6514]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006612), cpu);
}

/* align: skip  */
void Application::sub_4c5158(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5158);
    // 004c5158  ff259c644c00           -jmp dword ptr [0x4c649c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006492), cpu);
}

/* align: skip  */
void Application::sub_4c515e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c515e);
    // 004c515e  ff2544654c00           -jmp dword ptr [0x4c6544]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006660), cpu);
}

/* align: skip  */
void Application::sub_4c5164(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5164);
    // 004c5164  ff2534654c00           -jmp dword ptr [0x4c6534]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006644), cpu);
}

/* align: skip  */
void Application::sub_4c516a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c516a);
    // 004c516a  ff25d8654c00           -jmp dword ptr [0x4c65d8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006808), cpu);
}

/* align: skip  */
void Application::sub_4c5170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5170);
    // 004c5170  ff2508644c00           -jmp dword ptr [0x4c6408]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006344), cpu);
}

/* align: skip  */
void Application::sub_4c5176(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5176);
    // 004c5176  ff2528644c00           -jmp dword ptr [0x4c6428]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006376), cpu);
}

/* align: skip  */
void Application::sub_4c517c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c517c);
    // 004c517c  ff2588654c00           -jmp dword ptr [0x4c6588]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006728), cpu);
}

/* align: skip  */
void Application::sub_4c5182(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5182);
    // 004c5182  ff2554654c00           -jmp dword ptr [0x4c6554]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006676), cpu);
}

/* align: skip  */
void Application::sub_4c5188(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5188);
    // 004c5188  ff25c8634c00           -jmp dword ptr [0x4c63c8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006280), cpu);
}

/* align: skip  */
void Application::sub_4c518e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c518e);
    // 004c518e  ff2558644c00           -jmp dword ptr [0x4c6458]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006424), cpu);
}

/* align: skip  */
void Application::sub_4c5194(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5194);
    // 004c5194  ff2534644c00           -jmp dword ptr [0x4c6434]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006388), cpu);
}

/* align: skip  */
void Application::sub_4c519a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c519a);
    // 004c519a  ff2520644c00           -jmp dword ptr [0x4c6420]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006368), cpu);
}

/* align: skip  */
void Application::sub_4c51a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51a0);
    // 004c51a0  ff2508654c00           -jmp dword ptr [0x4c6508]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006600), cpu);
}

/* align: skip  */
void Application::sub_4c51a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51a6);
    // 004c51a6  ff2510644c00           -jmp dword ptr [0x4c6410]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006352), cpu);
}

/* align: skip  */
void Application::sub_4c51ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51ac);
    // 004c51ac  ff25d8634c00           -jmp dword ptr [0x4c63d8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006296), cpu);
}

/* align: skip  */
void Application::sub_4c51b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51b2);
    // 004c51b2  ff2540644c00           -jmp dword ptr [0x4c6440]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006400), cpu);
}

/* align: skip  */
void Application::sub_4c51b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51b8);
    // 004c51b8  ff25f4634c00           -jmp dword ptr [0x4c63f4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006324), cpu);
}

/* align: skip  */
void Application::sub_4c51be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51be);
    // 004c51be  ff25ac644c00           -jmp dword ptr [0x4c64ac]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006508), cpu);
}

/* align: skip  */
void Application::sub_4c51c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51c4);
    // 004c51c4  ff25fc634c00           -jmp dword ptr [0x4c63fc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006332), cpu);
}

/* align: skip  */
void Application::sub_4c51ca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51ca);
    // 004c51ca  ff2554644c00           -jmp dword ptr [0x4c6454]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006420), cpu);
}

/* align: skip  */
void Application::sub_4c51d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51d0);
    // 004c51d0  ff254c644c00           -jmp dword ptr [0x4c644c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006412), cpu);
}

/* align: skip  */
void Application::sub_4c51d6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51d6);
    // 004c51d6  ff25f8634c00           -jmp dword ptr [0x4c63f8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006328), cpu);
}

/* align: skip  */
void Application::sub_4c51dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51dc);
    // 004c51dc  ff2524654c00           -jmp dword ptr [0x4c6524]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006628), cpu);
}

/* align: skip  */
void Application::sub_4c51e2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51e2);
    // 004c51e2  ff25c4634c00           -jmp dword ptr [0x4c63c4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006276), cpu);
}

/* align: skip  */
void Application::sub_4c51e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51e8);
    // 004c51e8  ff25a4644c00           -jmp dword ptr [0x4c64a4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006500), cpu);
}

/* align: skip  */
void Application::sub_4c51ee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51ee);
    // 004c51ee  ff250c654c00           -jmp dword ptr [0x4c650c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006604), cpu);
}

/* align: skip  */
void Application::sub_4c51f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51f4);
    // 004c51f4  ff25a0644c00           -jmp dword ptr [0x4c64a0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006496), cpu);
}

/* align: skip  */
void Application::sub_4c51fa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c51fa);
    // 004c51fa  ff25e0654c00           -jmp dword ptr [0x4c65e0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006816), cpu);
}

/* align: skip  */
void Application::sub_4c5200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5200);
    // 004c5200  ff2574654c00           -jmp dword ptr [0x4c6574]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006708), cpu);
}

/* align: skip  */
void Application::sub_4c5206(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5206);
    // 004c5206  ff25bc644c00           -jmp dword ptr [0x4c64bc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006524), cpu);
}

/* align: skip  */
void Application::sub_4c520c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c520c);
    // 004c520c  ff255c654c00           -jmp dword ptr [0x4c655c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006684), cpu);
}

/* align: skip  */
void Application::sub_4c5212(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5212);
    // 004c5212  ff2570654c00           -jmp dword ptr [0x4c6570]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006704), cpu);
}

/* align: skip  */
void Application::sub_4c5218(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5218);
    // 004c5218  ff25dc654c00           -jmp dword ptr [0x4c65dc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006812), cpu);
}

/* align: skip  */
void Application::sub_4c521e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c521e);
    // 004c521e  ff25f0654c00           -jmp dword ptr [0x4c65f0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006832), cpu);
}

/* align: skip  */
void Application::sub_4c5224(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5224);
    // 004c5224  ff25f8654c00           -jmp dword ptr [0x4c65f8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006840), cpu);
}

/* align: skip  */
void Application::sub_4c522a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c522a);
    // 004c522a  ff25fc654c00           -jmp dword ptr [0x4c65fc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006844), cpu);
}

/* align: skip  */
void Application::sub_4c5230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5230);
    // 004c5230  ff25f4654c00           -jmp dword ptr [0x4c65f4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006836), cpu);
}

/* align: skip  */
void Application::sub_4c5236(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5236);
    // 004c5236  ff2500664c00           -jmp dword ptr [0x4c6600]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006848), cpu);
}

/* align: skip  */
void Application::sub_4c523c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c523c);
    // 004c523c  ff25ec654c00           -jmp dword ptr [0x4c65ec]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006828), cpu);
}

/* align: skip  */
void Application::sub_4c5242(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5242);
    // 004c5242  ff250c664c00           -jmp dword ptr [0x4c660c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006860), cpu);
}

/* align: skip  */
void Application::sub_4c5248(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5248);
    // 004c5248  ff2508664c00           -jmp dword ptr [0x4c6608]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006856), cpu);
}

/* align: skip  */
void Application::sub_4c524e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c524e);
    // 004c524e  ff2514664c00           -jmp dword ptr [0x4c6614]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006868), cpu);
}

/* align: skip  */
void Application::sub_4c5254(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5254);
    // 004c5254  ff251c664c00           -jmp dword ptr [0x4c661c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006876), cpu);
}

/* align: skip  */
void Application::sub_4c525a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c525a);
    // 004c525a  ff2520664c00           -jmp dword ptr [0x4c6620]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006880), cpu);
}

/* align: skip  */
void Application::sub_4c5260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5260);
    // 004c5260  ff2524664c00           -jmp dword ptr [0x4c6624]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006884), cpu);
}

/* align: skip  */
void Application::sub_4c5266(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5266);
    // 004c5266  ff2528664c00           -jmp dword ptr [0x4c6628]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006888), cpu);
}

/* align: skip  */
void Application::sub_4c526c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c526c);
    // 004c526c  ff252c664c00           -jmp dword ptr [0x4c662c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006892), cpu);
}

/* align: skip  */
void Application::sub_4c5272(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5272);
    // 004c5272  ff2530664c00           -jmp dword ptr [0x4c6630]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006896), cpu);
}

/* align: skip  */
void Application::sub_4c5278(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5278);
    // 004c5278  ff2534664c00           -jmp dword ptr [0x4c6634]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006900), cpu);
}

/* align: skip  */
void Application::sub_4c527e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c527e);
    // 004c527e  ff2538664c00           -jmp dword ptr [0x4c6638]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006904), cpu);
}

/* align: skip  */
void Application::sub_4c5284(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5284);
    // 004c5284  ff253c664c00           -jmp dword ptr [0x4c663c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006908), cpu);
}

/* align: skip  */
void Application::sub_4c528a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c528a);
    // 004c528a  ff2540664c00           -jmp dword ptr [0x4c6640]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006912), cpu);
}

/* align: skip  */
void Application::sub_4c5290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5290);
    // 004c5290  ff2544664c00           -jmp dword ptr [0x4c6644]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006916), cpu);
}

/* align: skip  */
void Application::sub_4c5296(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c5296);
    // 004c5296  ff2548664c00           -jmp dword ptr [0x4c6648]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006920), cpu);
}

/* align: skip  */
void Application::sub_4c529c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c529c);
    // 004c529c  ff254c664c00           -jmp dword ptr [0x4c664c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006924), cpu);
}

/* align: skip  */
void Application::sub_4c52a2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c52a2);
    // 004c52a2  ff2550664c00           -jmp dword ptr [0x4c6650]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006928), cpu);
}

/* align: skip  */
void Application::sub_4c52a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c52a8);
    // 004c52a8  ff2554664c00           -jmp dword ptr [0x4c6654]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006932), cpu);
}

/* align: skip  */
void Application::sub_4c52ae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c52ae);
    // 004c52ae  ff2558664c00           -jmp dword ptr [0x4c6658]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006936), cpu);
}

/* align: skip  */
void Application::sub_4c52b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c52b4);
    // 004c52b4  ff255c664c00           -jmp dword ptr [0x4c665c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006940), cpu);
}

/* align: skip  */
void Application::sub_4c52ba(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c52ba);
    // 004c52ba  ff2560664c00           -jmp dword ptr [0x4c6660]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006944), cpu);
}

/* align: skip  */
void Application::sub_4c52c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c52c0);
    // 004c52c0  ff2564664c00           -jmp dword ptr [0x4c6664]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006948), cpu);
}

/* align: skip  */
void Application::sub_4c52c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c52c6);
    // 004c52c6  ff2568664c00           -jmp dword ptr [0x4c6668]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006952), cpu);
}

/* align: skip  */
void Application::sub_4c52cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c52cc);
    // 004c52cc  ff256c664c00           -jmp dword ptr [0x4c666c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006956), cpu);
}

/* align: skip  */
void Application::sub_4c52d2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c52d2);
    // 004c52d2  ff2570664c00           -jmp dword ptr [0x4c6670]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006960), cpu);
}

/* align: skip  */
void Application::sub_4c52d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c52d8);
    // 004c52d8  ff2574664c00           -jmp dword ptr [0x4c6674]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006964), cpu);
}

/* align: skip 0x00 0x00 */
void Application::sub_4c52e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004c52e0);
    // 004c52e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c52fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5300  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5302  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5304  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5306  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5308  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c530a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c530c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c530e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5310  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5312  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5314  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5316  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5318  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c531a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c531c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c531e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5320  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5322  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5324  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5326  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5328  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c532a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c532c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c532e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5330  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5332  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5334  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5336  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5338  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c533a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c533c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c533e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5340  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5342  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5344  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5346  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5348  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c534a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c534c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c534e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5350  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5352  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5354  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5356  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5358  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c535a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c535c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c535e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5360  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5362  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5364  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5366  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5368  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c536a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c536c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c536e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5370  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5372  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5374  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5376  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5378  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c537a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c537c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c537e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5380  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5382  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5384  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5386  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5388  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c538a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c538c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c538e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5390  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5392  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5394  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5396  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c5398  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c539a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c539c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c539e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53a0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53a2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53a4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53a6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53a8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53b0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53b4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53b8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53bc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53c0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53c4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53c8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53cc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53ce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53d0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53d2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53d4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53d6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53d8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53da  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53dc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53de  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53e0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53e2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53e4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53e6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53f4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53f8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53fc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004c53fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
}

}
