#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x8b 0xc0 */
void Application::sub_490308(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490308  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490309  8b15b4a44c00           -mov edx, dword ptr [0x4ca4b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022900) /* 0x4ca4b4 */);
    // 0049030f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490311  7502                   -jne 0x490315
    if (!cpu.flags.zf)
    {
        goto L_0x00490315;
    }
    // 00490313  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490314  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490315:
    // 00490315  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490316  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490318  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049031a  e86da3feff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0049031f  890db4a44c00           -mov dword ptr [0x4ca4b4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022900) /* 0x4ca4b4 */) = cpu.ecx;
    // 00490325  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490326  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490327  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490328(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490328  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490329  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049032a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049032b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049032c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049032d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049032e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00490330  ba00800000             -mov edx, 0x8000
    cpu.edx = 32768 /*0x8000*/;
    // 00490335  b8080e4c00             -mov eax, 0x4c0e08
    cpu.eax = 4984328 /*0x4c0e08*/;
    // 0049033a  8b1d3ca44c00           -mov ebx, dword ptr [0x4ca43c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */);
    // 00490340  e8fb9efeff             -call 0x47a240
    cpu.esp -= 4;
    sub_47a240(app, cpu);
    if (cpu.terminate) return;
    // 00490345  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490347  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00490349  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049034b  7509                   -jne 0x490356
    if (!cpu.flags.zf)
    {
        goto L_0x00490356;
    }
    // 0049034d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049034f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490350  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490351  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490352  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490353  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490354  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490355  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490356:
    // 00490356  ba00000200             -mov edx, 0x20000
    cpu.edx = 131072 /*0x20000*/;
    // 0049035b  b8140e4c00             -mov eax, 0x4c0e14
    cpu.eax = 4984340 /*0x4c0e14*/;
    // 00490360  8b1d3ca44c00           -mov ebx, dword ptr [0x4ca43c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */);
    // 00490366  e8d59efeff             -call 0x47a240
    cpu.esp -= 4;
    sub_47a240(app, cpu);
    if (cpu.terminate) return;
    // 0049036b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049036d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049036f  750b                   -jne 0x49037c
    if (!cpu.flags.zf)
    {
        goto L_0x0049037c;
    }
    // 00490371  31cf                   -xor edi, ecx
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490373  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00490375  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490376  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490377  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490378  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490379  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049037a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049037b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049037c:
    // 0049037c  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 00490381  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490382  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00490384  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490386  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0049038b  e870f7ffff             -call 0x48fb00
    cpu.esp -= 4;
    sub_48fb00(app, cpu);
    if (cpu.terminate) return;
    // 00490390  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00490392  e8f5a2feff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00490397  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00490399  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049039a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049039b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049039c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049039d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049039e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049039f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4903a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004903a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004903a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004903a2  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004903a8  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004903aa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004903ac  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 004903b1  e84a270100             -call 0x4a2b00
    cpu.esp -= 4;
    sub_4a2b00(app, cpu);
    if (cpu.terminate) return;
    // 004903b6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004903b8  e86bffffff             -call 0x490328
    cpu.esp -= 4;
    sub_490328(app, cpu);
    if (cpu.terminate) return;
    // 004903bd  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004903c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004903c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004903c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4903c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004903c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004903c9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004903ca  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004903d0  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004903d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004903d4  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 004903d9  e816280100             -call 0x4a2bf4
    cpu.esp -= 4;
    sub_4a2bf4(app, cpu);
    if (cpu.terminate) return;
    // 004903de  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004903e0  e843ffffff             -call 0x490328
    cpu.esp -= 4;
    sub_490328(app, cpu);
    if (cpu.terminate) return;
    // 004903e5  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004903eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004903ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004903ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4903f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004903f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004903f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004903f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004903f3  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004903f9  e80affffff             -call 0x490308
    cpu.esp -= 4;
    sub_490308(app, cpu);
    if (cpu.terminate) return;
    // 004903fe  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00490400  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00490405  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490407  e87c1a0000             -call 0x491e88
    cpu.esp -= 4;
    sub_491e88(app, cpu);
    if (cpu.terminate) return;
    // 0049040c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049040e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490410  e813ffffff             -call 0x490328
    cpu.esp -= 4;
    sub_490328(app, cpu);
    if (cpu.terminate) return;
    // 00490415  a3b4a44c00             -mov dword ptr [0x4ca4b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5022900) /* 0x4ca4b4 */) = cpu.eax;
    // 0049041a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049041c  7405                   -je 0x490423
    if (cpu.flags.zf)
    {
        goto L_0x00490423;
    }
    // 0049041e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x00490423:
    // 00490423  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490425  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049042b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049042c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049042d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049042e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_490430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490430  e9ae280100             -jmp 0x4a2ce3
    return sub_4a2ce3(app, cpu);
}

/* align: skip  */
/* data blob: 03104000574154434f4d20432f432b2b33322052756e2d54696d652073797374656d2e2028632920436f7079726967687420627920574154434f4d20496e7465726e6174696f6e616c20436f72702e20313938382d313939352e20416c6c207269676874732072657365727665642e */
void Application::sub_4904a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004904a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4904a5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004904a5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004904a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004904a7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004904a9  ff1504c74c00           -call dword ptr [0x4cc704]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5031684) /* 0x4cc704 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004904af  803dcc4f540000         +cmp byte ptr [0x544fcc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5525452) /* 0x544fcc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004904b6  750f                   -jne 0x4904c7
    if (!cpu.flags.zf)
    {
        goto L_0x004904c7;
    }
    // 004904b8  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004904bd  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004904c2  e8a42a0100             -call 0x4a2f6b
    cpu.esp -= 4;
    sub_4a2f6b(app, cpu);
    if (cpu.terminate) return;
L_0x004904c7:
    // 004904c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004904c9  e803000000             -call 0x4904d1
    cpu.esp -= 4;
    sub_4904d1(app, cpu);
    if (cpu.terminate) return;
    // 004904ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004904cf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004904d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4904d1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004904d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004904d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004904d4  ff1504c74c00           -call dword ptr [0x4cc704]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5031684) /* 0x4cc704 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004904da  ff1508c74c00           -call dword ptr [0x4cc708]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5031688) /* 0x4cc708 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004904e0  833d14e44c0000         +cmp dword ptr [0x4ce414], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5039124) /* 0x4ce414 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004904e7  7406                   -je 0x4904ef
    if (cpu.flags.zf)
    {
        goto L_0x004904ef;
    }
    // 004904e9  ff1514e44c00           -call dword ptr [0x4ce414]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039124) /* 0x4ce414 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004904ef:
    // 004904ef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004904f1  e938d60000             -jmp 0x49db2e
    return sub_49db2e(app, cpu);
}

/* align: skip  */
void Application::sub_4904f6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004904f6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004904f7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004904f8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x004904f9:
    // 004904f9  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004904fb  fec2                   -inc dl
    (cpu.dl)++;
    // 004904fd  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00490503  f682c8ea4c0002         +test byte ptr [edx + 0x4ceac8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5040840) /* 0x4ceac8 */) & 2 /*0x2*/));
    // 0049050a  7403                   -je 0x49050f
    if (cpu.flags.zf)
    {
        goto L_0x0049050f;
    }
    // 0049050c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049050d  ebea                   -jmp 0x4904f9
    goto L_0x004904f9;
L_0x0049050f:
    // 0049050f  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00490511  80f92b                 +cmp cl, 0x2b
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490514  7405                   -je 0x49051b
    if (cpu.flags.zf)
    {
        goto L_0x0049051b;
    }
    // 00490516  80f92d                 +cmp cl, 0x2d
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490519  7501                   -jne 0x49051c
    if (!cpu.flags.zf)
    {
        goto L_0x0049051c;
    }
L_0x0049051b:
    // 0049051b  40                     -inc eax
    (cpu.eax)++;
L_0x0049051c:
    // 0049051c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0049051e:
    // 0049051e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00490520  fec2                   -inc dl
    (cpu.dl)++;
    // 00490522  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00490528  f682c8ea4c0020         +test byte ptr [edx + 0x4ceac8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5040840) /* 0x4ceac8 */) & 32 /*0x20*/));
    // 0049052f  740f                   -je 0x490540
    if (cpu.flags.zf)
    {
        goto L_0x00490540;
    }
    // 00490531  6bdb0a                 -imul ebx, ebx, 0xa
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00490534  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00490536  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00490538  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049053a  40                     -inc eax
    (cpu.eax)++;
    // 0049053b  83eb30                 +sub ebx, 0x30
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049053e  ebde                   -jmp 0x49051e
    goto L_0x0049051e;
L_0x00490540:
    // 00490540  80f92d                 +cmp cl, 0x2d
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490543  7502                   -jne 0x490547
    if (!cpu.flags.zf)
    {
        goto L_0x00490547;
    }
    // 00490545  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x00490547:
    // 00490547  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00490549  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049054a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049054b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049054c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_490550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490550  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490551  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490552  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490553  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490554  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00490556  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00490558  8915f8845200           -mov dword ptr [0x5284f8], edx
    app->getMemory<x86::reg32>(x86::reg32(5407992) /* 0x5284f8 */) = cpu.edx;
    // 0049055e  c7403000000000         -mov dword ptr [eax + 0x30], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00490565  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00490568  e8af66ffff             -call 0x486c1c
    cpu.esp -= 4;
    sub_486c1c(app, cpu);
    if (cpu.terminate) return;
    // 0049056d  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 00490570  e86762ffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 00490575  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490577  7508                   -jne 0x490581
    if (!cpu.flags.zf)
    {
        goto L_0x00490581;
    }
    // 00490579  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 0049057c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049057d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049057e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049057f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490580  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490581:
    // 00490581  8b5648                 -mov edx, dword ptr [esi + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00490584  8b4e44                 -mov ecx, dword ptr [esi + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00490587  8b5e40                 -mov ebx, dword ptr [esi + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0049058a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049058b  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049058e  8b563c                 -mov edx, dword ptr [esi + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00490591  e8a668ffff             -call 0x486e3c
    cpu.esp -= 4;
    sub_486e3c(app, cpu);
    if (cpu.terminate) return;
    // 00490596  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 00490599  e8e263ffff             -call 0x486980
    cpu.esp -= 4;
    sub_486980(app, cpu);
    if (cpu.terminate) return;
    // 0049059e  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004905a1  e8fa63ffff             -call 0x4869a0
    cpu.esp -= 4;
    sub_4869a0(app, cpu);
    if (cpu.terminate) return;
    // 004905a6  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004905a9  e8625cffff             -call 0x486210
    cpu.esp -= 4;
    sub_486210(app, cpu);
    if (cpu.terminate) return;
    // 004905ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004905b0  750f                   -jne 0x4905c1
    if (!cpu.flags.zf)
    {
        goto L_0x004905c1;
    }
    // 004905b2  c7463001000000         -mov dword ptr [esi + 0x30], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 1 /*0x1*/;
    // 004905b9  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 004905bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004905c1:
    // 004905c1  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004905c4  e8f763ffff             -call 0x4869c0
    cpu.esp -= 4;
    sub_4869c0(app, cpu);
    if (cpu.terminate) return;
    // 004905c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004905cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4905d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004905d0  c7403000000000         -mov dword ptr [eax + 0x30], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 004905d7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004905dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4905e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004905e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004905e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004905e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004905e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004905e5  8b1df8845200           -mov ebx, dword ptr [0x5284f8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407992) /* 0x5284f8 */);
    // 004905eb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004905ed  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004905ef  7507                   -jne 0x4905f8
    if (!cpu.flags.zf)
    {
        goto L_0x004905f8;
    }
L_0x004905f1:
    // 004905f1  8b4130                 -mov eax, dword ptr [ecx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 004905f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004905f8:
    // 004905f8  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004905fb  e88869ffff             -call 0x486f88
    cpu.esp -= 4;
    sub_486f88(app, cpu);
    if (cpu.terminate) return;
    // 00490600  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490602  74ed                   -je 0x4905f1
    if (cpu.flags.zf)
    {
        goto L_0x004905f1;
    }
    // 00490604  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490606  ff15f8845200           -call dword ptr [0x5284f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5407992) /* 0x5284f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049060c  8b4130                 -mov eax, dword ptr [ecx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 0049060f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490610  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490611  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490612  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_490614(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490614  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00490617  e9c069ffff             -jmp 0x486fdc
    return sub_486fdc(app, cpu);
}

/* align: skip  */
void Application::sub_49061c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049061c  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049061f  e96469ffff             -jmp 0x486f88
    return sub_486f88(app, cpu);
}

/* align: skip  */
void Application::sub_490624(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490624  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490625  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490627  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00490629  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049062b  8b4934                 -mov ecx, dword ptr [ecx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0049062e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490630  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490632  e8c16affff             -call 0x4870f8
    cpu.esp -= 4;
    sub_4870f8(app, cpu);
    if (cpu.terminate) return;
    // 00490637  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490639  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049063b  7c04                   -jl 0x490641
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490641;
    }
    // 0049063d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049063f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490640  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490641:
    // 00490641  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00490643  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490645  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490646  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_490648(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490648  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490649  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049064b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049064d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049064f  8b4934                 -mov ecx, dword ptr [ecx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 00490652  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00490654  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490656  e82d66ffff             -call 0x486c88
    cpu.esp -= 4;
    sub_486c88(app, cpu);
    if (cpu.terminate) return;
    // 0049065b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049065c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490660  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490661  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490662  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00490664  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00490666  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490668  745b                   -je 0x4906c5
    if (cpu.flags.zf)
    {
        goto L_0x004906c5;
    }
    // 0049066a  83782400               +cmp dword ptr [eax + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049066e  7516                   -jne 0x490686
    if (!cpu.flags.zf)
    {
        goto L_0x00490686;
    }
    // 00490670  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00490676  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490678  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049067b  c1e204                 +shl edx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049067e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00490680  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00490683  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00490686:
    // 00490686  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490687  837e2800               +cmp dword ptr [esi + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049068b  7515                   -jne 0x4906a2
    if (!cpu.flags.zf)
    {
        goto L_0x004906a2;
    }
    // 0049068d  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00490693  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 00490698  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049069a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049069d  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049069f  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x004906a2:
    // 004906a2  837e2c00               +cmp dword ptr [esi + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004906a6  7515                   -jne 0x4906bd
    if (!cpu.flags.zf)
    {
        goto L_0x004906bd;
    }
    // 004906a8  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 004906ae  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 004906b3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004906b5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004906b8  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004906ba  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x004906bd:
    // 004906bd  c7460803000000         -mov dword ptr [esi + 8], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 3 /*0x3*/;
    // 004906c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004906c5:
    // 004906c5  ba80494c00             -mov edx, 0x4c4980
    cpu.edx = 4999552 /*0x4c4980*/;
    // 004906ca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004906cb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004906cd  bb0cc74c00             -mov ebx, 0x4cc70c
    cpu.ebx = 5031692 /*0x4cc70c*/;
    // 004906d2  e83107ffff             -call 0x480e08
    cpu.esp -= 4;
    sub_480e08(app, cpu);
    if (cpu.terminate) return;
    // 004906d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004906d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004906d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4906dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004906dc  e9db280100             -jmp 0x4a2fbc
    return sub_4a2fbc(app, cpu);
}

/* align: skip  */
void Application::sub_4906e1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004906e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004906e3  e8bdfdffff             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
    // 004906e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004906ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004906ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004906ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004906f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004906f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004906f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004906f4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004906f6  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004906fd  7405                   -je 0x490704
    if (cpu.flags.zf)
    {
        goto L_0x00490704;
    }
    // 004906ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490701  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490702  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490703  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490704:
    // 00490704  e86f04ffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00490709  a320ae5200             -mov dword ptr [0x52ae20], eax
    app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */) = cpu.eax;
    // 0049070e  e8c5000000             -call 0x4907d8
    cpu.esp -= 4;
    sub_4907d8(app, cpu);
    if (cpu.terminate) return;
    // 00490713  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00490715  e802010000             -call 0x49081c
    cpu.esp -= 4;
    sub_49081c(app, cpu);
    if (cpu.terminate) return;
    // 0049071a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049071c  e893f0feff             -call 0x47f7b4
    cpu.esp -= 4;
    sub_47f7b4(app, cpu);
    if (cpu.terminate) return;
    // 00490721  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490723  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490725  7c0d                   -jl 0x490734
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490734;
    }
    // 00490727  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00490729  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049072b  8815b0cd4c00           -mov byte ptr [0x4ccdb0], dl
    app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */) = cpu.dl;
    // 00490731  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490732  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490733  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490734:
    // 00490734  e8ebf0feff             -call 0x47f824
    cpu.esp -= 4;
    sub_47f824(app, cpu);
    if (cpu.terminate) return;
    // 00490739  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049073b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049073c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049073d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4906f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004906f0;
    // 004906e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004906e3  e8bdfdffff             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
    // 004906e8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004906ea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004906ec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004906ee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x004906f0:
    // 004906f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004906f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004906f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004906f4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004906f6  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004906fd  7405                   -je 0x490704
    if (cpu.flags.zf)
    {
        goto L_0x00490704;
    }
    // 004906ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490701  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490702  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490703  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490704:
    // 00490704  e86f04ffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00490709  a320ae5200             -mov dword ptr [0x52ae20], eax
    app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */) = cpu.eax;
    // 0049070e  e8c5000000             -call 0x4907d8
    cpu.esp -= 4;
    sub_4907d8(app, cpu);
    if (cpu.terminate) return;
    // 00490713  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00490715  e802010000             -call 0x49081c
    cpu.esp -= 4;
    sub_49081c(app, cpu);
    if (cpu.terminate) return;
    // 0049071a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049071c  e893f0feff             -call 0x47f7b4
    cpu.esp -= 4;
    sub_47f7b4(app, cpu);
    if (cpu.terminate) return;
    // 00490721  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490723  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490725  7c0d                   -jl 0x490734
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490734;
    }
    // 00490727  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00490729  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049072b  8815b0cd4c00           -mov byte ptr [0x4ccdb0], dl
    app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */) = cpu.dl;
    // 00490731  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490732  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490733  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490734:
    // 00490734  e8ebf0feff             -call 0x47f824
    cpu.esp -= 4;
    sub_47f824(app, cpu);
    if (cpu.terminate) return;
    // 00490739  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049073b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049073c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049073d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490740  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00490747  7506                   -jne 0x49074f
    if (!cpu.flags.zf)
    {
        goto L_0x0049074f;
    }
    // 00490749  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0049074e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049074f:
    // 0049074f  e8acdcffff             -call 0x48e400
    cpu.esp -= 4;
    sub_48e400(app, cpu);
    if (cpu.terminate) return;
    // 00490754  833dd0cd4c0000         +cmp dword ptr [0x4ccdd0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033424) /* 0x4ccdd0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049075b  7406                   -je 0x490763
    if (cpu.flags.zf)
    {
        goto L_0x00490763;
    }
    // 0049075d  ff15d0cd4c00           -call dword ptr [0x4ccdd0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5033424) /* 0x4ccdd0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00490763:
    // 00490763  833dd4cd4c0000         +cmp dword ptr [0x4ccdd4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033428) /* 0x4ccdd4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049076a  7406                   -je 0x490772
    if (cpu.flags.zf)
    {
        goto L_0x00490772;
    }
    // 0049076c  ff15d4cd4c00           -call dword ptr [0x4ccdd4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5033428) /* 0x4ccdd4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00490772:
    // 00490772  833dd8cd4c0000         +cmp dword ptr [0x4ccdd8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033432) /* 0x4ccdd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490779  7406                   -je 0x490781
    if (cpu.flags.zf)
    {
        goto L_0x00490781;
    }
    // 0049077b  ff15d8cd4c00           -call dword ptr [0x4ccdd8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5033432) /* 0x4ccdd8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00490781:
    // 00490781  833dc8cd4c0000         +cmp dword ptr [0x4ccdc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033416) /* 0x4ccdc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490788  740b                   -je 0x490795
    if (cpu.flags.zf)
    {
        goto L_0x00490795;
    }
    // 0049078a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049078f  ff15c8cd4c00           -call dword ptr [0x4ccdc8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5033416) /* 0x4ccdc8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00490795:
    // 00490795  833ddccd4c0000         +cmp dword ptr [0x4ccddc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033436) /* 0x4ccddc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049079c  7406                   -je 0x4907a4
    if (cpu.flags.zf)
    {
        goto L_0x004907a4;
    }
    // 0049079e  ff15dccd4c00           -call dword ptr [0x4ccddc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5033436) /* 0x4ccddc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004907a4:
    // 004907a4  833dcccd4c0000         +cmp dword ptr [0x4ccdcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033420) /* 0x4ccdcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004907ab  7406                   -je 0x4907b3
    if (cpu.flags.zf)
    {
        goto L_0x004907b3;
    }
    // 004907ad  ff15cccd4c00           -call dword ptr [0x4ccdcc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5033420) /* 0x4ccdcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004907b3:
    // 004907b3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004907b4  e86bf0feff             -call 0x47f824
    cpu.esp -= 4;
    sub_47f824(app, cpu);
    if (cpu.terminate) return;
    // 004907b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004907bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004907bd  7c0a                   -jl 0x4907c9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004907c9;
    }
    // 004907bf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004907c0  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004907c2  881db0cd4c00           -mov byte ptr [0x4ccdb0], bl
    app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */) = cpu.bl;
    // 004907c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004907c9:
    // 004907c9  a120ae5200             -mov eax, dword ptr [0x52ae20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */);
    // 004907ce  e82104ffff             -call 0x480bf4
    cpu.esp -= 4;
    sub_480bf4(app, cpu);
    if (cpu.terminate) return;
    // 004907d3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004907d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004907d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4907d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004907d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004907d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004907db:
    // 004907db  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004907de  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004907e0  88907ca75200           -mov byte ptr [eax + 0x52a77c], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5416828) /* 0x52a77c */) = cpu.dl;
    // 004907e6  3d00060000             +cmp eax, 0x600
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1536 /*0x600*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004907eb  75ee                   -jne 0x4907db
    if (!cpu.flags.zf)
    {
        goto L_0x004907db;
    }
    // 004907ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004907ef:
    // 004907ef  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004907f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004907f4  8990c8ad5200           -mov dword ptr [eax + 0x52adc8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5418440) /* 0x52adc8 */) = cpu.edx;
    // 004907fa  8990ccad5200           -mov dword ptr [eax + 0x52adcc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5418444) /* 0x52adcc */) = cpu.edx;
    // 00490800  83f850                 +cmp eax, 0x50
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490803  75ea                   -jne 0x4907ef
    if (!cpu.flags.zf)
    {
        goto L_0x004907ef;
    }
    // 00490805  891528ae5200           -mov dword ptr [0x52ae28], edx
    app->getMemory<x86::reg32>(x86::reg32(5418536) /* 0x52ae28 */) = cpu.edx;
    // 0049080b  891524ae5200           -mov dword ptr [0x52ae24], edx
    app->getMemory<x86::reg32>(x86::reg32(5418532) /* 0x52ae24 */) = cpu.edx;
    // 00490811  c6052dae52007f         -mov byte ptr [0x52ae2d], 0x7f
    app->getMemory<x86::reg8>(x86::reg32(5418541) /* 0x52ae2d */) = 127 /*0x7f*/;
    // 00490818  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490819  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49081c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049081c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049081d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049081e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049081f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00490821  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490823  e894ecfeff             -call 0x47f4bc
    cpu.esp -= 4;
    sub_47f4bc(app, cpu);
    if (cpu.terminate) return;
    // 00490828  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049082a  83fbff                 +cmp ebx, -1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049082d  754c                   -jne 0x49087b
    if (!cpu.flags.zf)
    {
        goto L_0x0049087b;
    }
L_0x0049082f:
    // 0049082f  21d0                   -and eax, edx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edx));
    // 00490831  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490833  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490835  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00490837  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049083d  81e200ff0000           -and edx, 0xff00
    cpu.edx &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00490843  81e60000ff00           -and esi, 0xff0000
    cpu.esi &= x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
    // 00490849  83fbff                 +cmp ebx, -1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049084c  7502                   -jne 0x490850
    if (!cpu.flags.zf)
    {
        goto L_0x00490850;
    }
    // 0049084e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00490850:
    // 00490850  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00490852  742b                   -je 0x49087f
    if (cpu.flags.zf)
    {
        goto L_0x0049087f;
    }
    // 00490854  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490856  7427                   -je 0x49087f
    if (cpu.flags.zf)
    {
        goto L_0x0049087f;
    }
    // 00490858  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0049085b  7428                   -je 0x490885
    if (cpu.flags.zf)
    {
        goto L_0x00490885;
    }
    // 0049085d  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
L_0x00490862:
    // 00490862  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 00490865  743d                   -je 0x4908a4
    if (cpu.flags.zf)
    {
        goto L_0x004908a4;
    }
    // 00490867  80cc08                 -or ah, 8
    cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0049086a:
    // 0049086a  f7c600000200           +test esi, 0x20000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 131072 /*0x20000*/));
    // 00490870  7405                   -je 0x490877
    if (cpu.flags.zf)
    {
        goto L_0x00490877;
    }
    // 00490872  0d00000200             +or eax, 0x20000
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(131072 /*0x20000*/))));
L_0x00490877:
    // 00490877  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490878  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490879  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049087a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049087b:
    // 0049087b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049087d  ebb0                   -jmp 0x49082f
    goto L_0x0049082f;
L_0x0049087f:
    // 0049087f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490881  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490882  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490883  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490884  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490885:
    // 00490885  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 00490888  7407                   -je 0x490891
    if (cpu.flags.zf)
    {
        goto L_0x00490891;
    }
    // 0049088a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049088f  ebd1                   -jmp 0x490862
    goto L_0x00490862;
L_0x00490891:
    // 00490891  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00490894  7407                   -je 0x49089d
    if (cpu.flags.zf)
    {
        goto L_0x0049089d;
    }
    // 00490896  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049089b  ebc5                   -jmp 0x490862
    goto L_0x00490862;
L_0x0049089d:
    // 0049089d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004908a2  ebbe                   -jmp 0x490862
    goto L_0x00490862;
L_0x004908a4:
    // 004908a4  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 004908a7  7405                   -je 0x4908ae
    if (cpu.flags.zf)
    {
        goto L_0x004908ae;
    }
    // 004908a9  80cc10                 +or ah, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004908ac  ebbc                   -jmp 0x49086a
    goto L_0x0049086a;
L_0x004908ae:
    // 004908ae  f6c604                 +test dh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 4 /*0x4*/));
    // 004908b1  7405                   -je 0x4908b8
    if (cpu.flags.zf)
    {
        goto L_0x004908b8;
    }
    // 004908b3  80cc04                 +or ah, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004908b6  ebb2                   -jmp 0x49086a
    goto L_0x0049086a;
L_0x004908b8:
    // 004908b8  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 004908bb  7405                   -je 0x4908c2
    if (cpu.flags.zf)
    {
        goto L_0x004908c2;
    }
    // 004908bd  80cc20                 +or ah, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004908c0  eba8                   -jmp 0x49086a
    goto L_0x0049086a;
L_0x004908c2:
    // 004908c2  f6c602                 +test dh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 2 /*0x2*/));
    // 004908c5  7405                   -je 0x4908cc
    if (cpu.flags.zf)
    {
        goto L_0x004908cc;
    }
    // 004908c7  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004908ca  eb9e                   -jmp 0x49086a
    goto L_0x0049086a;
L_0x004908cc:
    // 004908cc  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004908cf  eb99                   -jmp 0x49086a
    goto L_0x0049086a;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4908e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004908e0  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004908e7  7506                   -jne 0x4908ef
    if (!cpu.flags.zf)
    {
        goto L_0x004908ef;
    }
    // 004908e9  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004908ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004908ef:
    // 004908ef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004908f0  a100c34c00             -mov eax, dword ptr [0x4cc300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */);
    // 004908f5  e836270100             -call 0x4a3030
    cpu.esp -= 4;
    sub_4a3030(app, cpu);
    if (cpu.terminate) return;
    // 004908fa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004908fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004908fe  7c04                   -jl 0x490904
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490904;
    }
    // 00490900  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490902  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490903  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490904:
    // 00490904  0fbe1572c34c00         -movsx edx, byte ptr [0x4cc372]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5030770) /* 0x4cc372 */)));
    // 0049090b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049090d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049090e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49090f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049090f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490910  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490911  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490912  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00490915  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490916  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490917  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00490919  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0049091b  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049091e  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490924  f6410c02               +test byte ptr [ecx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 00490928  751e                   -jne 0x490948
    if (!cpu.flags.zf)
    {
        goto L_0x00490948;
    }
    // 0049092a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049092f  e8cc970000             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 00490934  80490c20               -or byte ptr [ecx + 0xc], 0x20
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00490938  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049093b  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490941  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00490943  e9c6010000             -jmp 0x490b0e
    goto L_0x00490b0e;
L_0x00490948:
    // 00490948  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049094b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049094d  7510                   -jne 0x49095f
    if (!cpu.flags.zf)
    {
        goto L_0x0049095f;
    }
    // 0049094f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00490952  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490958  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049095a  e9af010000             -jmp 0x490b0e
    goto L_0x00490b0e;
L_0x0049095f:
    // 0049095f  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00490962  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490966  7507                   -jne 0x49096f
    if (!cpu.flags.zf)
    {
        goto L_0x0049096f;
    }
    // 00490968  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049096a  e80c270100             -call 0x4a307b
    cpu.esp -= 4;
    sub_4a307b(app, cpu);
    if (cpu.terminate) return;
L_0x0049096f:
    // 0049096f  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00490972  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00490975  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490977  83e030                 -and eax, 0x30
    cpu.eax &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049097a  80e2cf                 -and dl, 0xcf
    cpu.dl &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 0049097d  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00490981  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00490985  88550c                 -mov byte ptr [ebp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00490988  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 0049098b  0f84e1000000           -je 0x490a72
    if (cpu.flags.zf)
    {
        goto L_0x00490a72;
    }
    // 00490991  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x00490995:
    // 00490995  837d0400               +cmp dword ptr [ebp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490999  7544                   -jne 0x4909df
    if (!cpu.flags.zf)
    {
        goto L_0x004909df;
    }
    // 0049099b  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049099f  3b4514                 +cmp eax, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004909a2  723b                   -jb 0x4909df
    if (cpu.flags.cf)
    {
        goto L_0x004909df;
    }
    // 004909a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004909a6  30c3                   -xor bl, al
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.al));
    // 004909a8  80e7fe                 -and bh, 0xfe
    cpu.bh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004909ab  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004909ad  7502                   -jne 0x4909b1
    if (!cpu.flags.zf)
    {
        goto L_0x004909b1;
    }
    // 004909af  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004909b1:
    // 004909b1  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004909b5  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004909b8  e845270100             -call 0x4a3102
    cpu.esp -= 4;
    sub_4a3102(app, cpu);
    if (cpu.terminate) return;
    // 004909bd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004909bf  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004909c2  7415                   -je 0x4909d9
    if (cpu.flags.zf)
    {
        goto L_0x004909d9;
    }
    // 004909c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004909c6  0f8573000000           -jne 0x490a3f
    if (!cpu.flags.zf)
    {
        goto L_0x00490a3f;
    }
    // 004909cc  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004909d2  c740040c000000         -mov dword ptr [eax + 4], 0xc
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 12 /*0xc*/;
L_0x004909d9:
    // 004909d9  804d0c20               +or byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004909dd  eb60                   -jmp 0x490a3f
    goto L_0x00490a3f;
L_0x004909df:
    // 004909df  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004909e2  8b7504                 -mov esi, dword ptr [ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004909e5  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004909e9  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004909eb  39fa                   +cmp edx, edi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004909ed  7602                   -jbe 0x4909f1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004909f1;
    }
    // 004909ef  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x004909f1:
    // 004909f1  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004909f5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004909f7  8b7d00                 -mov edi, dword ptr [ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp);
    // 004909fa  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004909fb  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004909fd  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004909ff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490a00  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490a02  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00490a05  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 00490a07  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00490a09  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00490a0c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00490a0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a0f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00490a10  8b5d04                 -mov ebx, dword ptr [ebp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00490a13  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00490a16  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490a18  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00490a1b  895d04                 -mov dword ptr [ebp + 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00490a1e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490a20  8a7d0d                 -mov bh, byte ptr [ebp + 0xd]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 00490a23  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00490a26  80cf10                 -or bh, 0x10
    cpu.bh |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00490a29  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00490a2c  887d0d                 -mov byte ptr [ebp + 0xd], bh
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 00490a2f  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490a31  7405                   -je 0x490a38
    if (cpu.flags.zf)
    {
        goto L_0x00490a38;
    }
    // 00490a33  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 00490a36  7407                   -je 0x490a3f
    if (cpu.flags.zf)
    {
        goto L_0x00490a3f;
    }
L_0x00490a38:
    // 00490a38  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00490a3a  e801e40000             -call 0x49ee40
    cpu.esp -= 4;
    sub_49ee40(app, cpu);
    if (cpu.terminate) return;
L_0x00490a3f:
    // 00490a3f  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490a43  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490a47  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00490a4b  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490a4d  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490a4f  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00490a53  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00490a57  29d0                   +sub eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00490a59  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00490a5d  0f847f000000           -je 0x490ae2
    if (cpu.flags.zf)
    {
        goto L_0x00490ae2;
    }
    // 00490a63  f6450c20               +test byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 00490a67  0f8428ffffff           -je 0x490995
    if (cpu.flags.zf)
    {
        goto L_0x00490995;
    }
    // 00490a6d  e970000000             -jmp 0x490ae2
    goto L_0x00490ae2;
L_0x00490a72:
    // 00490a72  8a5d0d                 -mov bl, byte ptr [ebp + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 00490a75  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 00490a78  7414                   -je 0x490a8e
    if (cpu.flags.zf)
    {
        goto L_0x00490a8e;
    }
    // 00490a7a  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00490a7c  80e7fa                 -and bh, 0xfa
    cpu.bh &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 00490a7f  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 00490a81  887d0d                 -mov byte ptr [ebp + 0xd], bh
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 00490a84  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00490a86  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00490a8b  88450d                 -mov byte ptr [ebp + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.al;
L_0x00490a8e:
    // 00490a8e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00490a91  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490a95  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00490a98  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00490a9f:
    // 00490a9f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490aa1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00490aa3  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 00490aa5  e822270100             -call 0x4a31cc
    cpu.esp -= 4;
    sub_4a31cc(app, cpu);
    if (cpu.terminate) return;
    // 00490aaa  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00490aad  43                     -inc ebx
    (cpu.ebx)++;
    // 00490aae  f6c230                 +test dl, 0x30
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 48 /*0x30*/));
    // 00490ab1  750d                   -jne 0x490ac0
    if (!cpu.flags.zf)
    {
        goto L_0x00490ac0;
    }
    // 00490ab3  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490ab7  40                     -inc eax
    (cpu.eax)++;
    // 00490ab8  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00490abc  39c7                   +cmp edi, eax
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490abe  75df                   -jne 0x490a9f
    if (!cpu.flags.zf)
    {
        goto L_0x00490a9f;
    }
L_0x00490ac0:
    // 00490ac0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00490ac3  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00490ac6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00490ac8  7418                   -je 0x490ae2
    if (cpu.flags.zf)
    {
        goto L_0x00490ae2;
    }
    // 00490aca  8a750d                 -mov dh, byte ptr [ebp + 0xd]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 00490acd  80e6fa                 -and dh, 0xfa
    cpu.dh &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 00490ad0  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 00490ad2  88750d                 -mov byte ptr [ebp + 0xd], dh
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.dh;
    // 00490ad5  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00490ad8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00490ada  885d0d                 -mov byte ptr [ebp + 0xd], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 00490add  e85ee30000             -call 0x49ee40
    cpu.esp -= 4;
    sub_49ee40(app, cpu);
    if (cpu.terminate) return;
L_0x00490ae2:
    // 00490ae2  f6450c20               +test byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 00490ae6  7406                   -je 0x490aee
    if (cpu.flags.zf)
    {
        goto L_0x00490aee;
    }
    // 00490ae8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00490aea  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x00490aee:
    // 00490aee  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00490af2  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00490af5  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00490af8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00490afa  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00490afc  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00490aff  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00490b02  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490b08  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490b0c  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00490b0e:
    // 00490b0e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00490b11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b14  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_490b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490b20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490b21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490b22  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490b25  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00490b28  66f7442402ffff         +test word ptr [esp + 2], 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) & 65535 /*0xffff*/));
    // 00490b2f  0f8476000000           -je 0x490bab
    if (cpu.flags.zf)
    {
        goto L_0x00490bab;
    }
    // 00490b35  f6442403ff             +test byte ptr [esp + 3], 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */) & 255 /*0xff*/));
    // 00490b3a  7443                   -je 0x490b7f
    if (cpu.flags.zf)
    {
        goto L_0x00490b7f;
    }
    // 00490b3c  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 00490b3f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00490b41  8a90cbeb4c00           -mov dl, byte ptr [eax + 0x4cebcb]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5041099) /* 0x4cebcb */);
    // 00490b47  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00490b4a  8a80cceb4c00           -mov al, byte ptr [eax + 0x4cebcc]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5041100) /* 0x4cebcc */);
    // 00490b50  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00490b55  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00490b58  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
L_0x00490b5e:
    // 00490b5e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490b5f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490b60  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x00490b64:
    // 00490b64  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490b66  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00490b68  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490b6b  7634                   -jbe 0x490ba1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00490ba1;
    }
    // 00490b6d  8d040a                 -lea eax, [edx + ecx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 00490b70  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 00490b72  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00490b74  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00490b77  39f3                   +cmp ebx, esi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490b79  7622                   -jbe 0x490b9d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00490b9d;
    }
    // 00490b7b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490b7d  ebe5                   -jmp 0x490b64
    goto L_0x00490b64;
L_0x00490b7f:
    // 00490b7f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00490b82  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490b84  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00490b86  8a88cceb4c00           -mov cl, byte ptr [eax + 0x4cebcc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5041100) /* 0x4cebcc */);
    // 00490b8c  8a90cbeb4c00           -mov dl, byte ptr [eax + 0x4cebcb]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5041099) /* 0x4cebcb */);
    // 00490b92  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00490b95  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00490b98  83c110                 +add ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00490b9b  ebc1                   -jmp 0x490b5e
    goto L_0x00490b5e;
L_0x00490b9d:
    // 00490b9d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490b9f  ebc3                   -jmp 0x490b64
    goto L_0x00490b64;
L_0x00490ba1:
    // 00490ba1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490ba3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ba4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00490ba5:
    // 00490ba5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490ba8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ba9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490baa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490bab:
    // 00490bab  8a642401               -mov ah, byte ptr [esp + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00490baf  f6c4ff                 +test ah, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 255 /*0xff*/));
    // 00490bb2  0f84b0000000           -je 0x490c68
    if (cpu.flags.zf)
    {
        goto L_0x00490c68;
    }
    // 00490bb8  f6c4f0                 +test ah, 0xf0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 240 /*0xf0*/));
    // 00490bbb  745f                   -je 0x490c1c
    if (cpu.flags.zf)
    {
        goto L_0x00490c1c;
    }
    // 00490bbd  f6c4c0                 +test ah, 0xc0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 192 /*0xc0*/));
    // 00490bc0  743a                   -je 0x490bfc
    if (cpu.flags.zf)
    {
        goto L_0x00490bfc;
    }
    // 00490bc2  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00490bc5  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00490bc8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490bca  8a82cbeb4c00           -mov al, byte ptr [edx + 0x4cebcb]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5041099) /* 0x4cebcb */);
    // 00490bd0  8a92cceb4c00           -mov dl, byte ptr [edx + 0x4cebcc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5041100) /* 0x4cebcc */);
    // 00490bd6  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x00490bdc:
    // 00490bdc  42                     -inc edx
    (cpu.edx)++;
    // 00490bdd  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00490bdf  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00490be1  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490be4  76bf                   -jbe 0x490ba5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00490ba5;
    }
    // 00490be6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490be8  d1ea                   -shr edx, 1
    cpu.edx >>= 1 /*0x1*/ % 32;
    // 00490bea  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00490bec  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00490bef  3b0c24                 +cmp ecx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490bf2  77b1                   -ja 0x490ba5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00490ba5;
    }
    // 00490bf4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490bf6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490bf9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490bfa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490bfb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490bfc:
    // 00490bfc  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00490bff  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00490c02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490c04  8a82cbeb4c00           -mov al, byte ptr [edx + 0x4cebcb]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5041099) /* 0x4cebcb */);
    // 00490c0a  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00490c0c  8a92cceb4c00           -mov dl, byte ptr [edx + 0x4cebcc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5041100) /* 0x4cebcc */);
    // 00490c12  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00490c18  d1fa                   +sar edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00490c1a  ebc0                   -jmp 0x490bdc
    goto L_0x00490bdc;
L_0x00490c1c:
    // 00490c1c  f6c40c                 +test ah, 0xc
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 12 /*0xc*/));
    // 00490c1f  7422                   -je 0x490c43
    if (cpu.flags.zf)
    {
        goto L_0x00490c43;
    }
    // 00490c21  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00490c24  c1ea04                 -shr edx, 4
    cpu.edx >>= 4 /*0x4*/ % 32;
    // 00490c27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490c29  8a82cbeb4c00           -mov al, byte ptr [edx + 0x4cebcb]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5041099) /* 0x4cebcb */);
    // 00490c2f  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00490c32  8a92cceb4c00           -mov dl, byte ptr [edx + 0x4cebcc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5041100) /* 0x4cebcc */);
    // 00490c38  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00490c3e  c1fa02                 +sar edx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00490c41  eb99                   -jmp 0x490bdc
    goto L_0x00490bdc;
L_0x00490c43:
    // 00490c43  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00490c46  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 00490c49  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490c4b  8a82cbeb4c00           -mov al, byte ptr [edx + 0x4cebcb]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5041099) /* 0x4cebcb */);
    // 00490c51  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00490c54  8a92cceb4c00           -mov dl, byte ptr [edx + 0x4cebcc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5041100) /* 0x4cebcc */);
    // 00490c5a  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00490c60  c1fa03                 +sar edx, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00490c63  e974ffffff             -jmp 0x490bdc
    goto L_0x00490bdc;
L_0x00490c68:
    // 00490c68  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00490c6b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490c6d  7411                   -je 0x490c80
    if (cpu.flags.zf)
    {
        goto L_0x00490c80;
    }
    // 00490c6f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490c71  8a82cbeb4c00           -mov al, byte ptr [edx + 0x4cebcb]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5041099) /* 0x4cebcb */);
    // 00490c77  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00490c7a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490c7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490c7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490c7f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490c80:
    // 00490c80  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490c82  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490c85  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490c86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490c87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_490c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490c90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490c91  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490c93  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490c95  7504                   -jne 0x490c9b
    if (!cpu.flags.zf)
    {
        goto L_0x00490c9b;
    }
L_0x00490c97:
    // 00490c97  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490c99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490c9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490c9b:
    // 00490c9b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00490c9d  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00490ca0  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00490ca6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490ca8  74ed                   -je 0x490c97
    if (cpu.flags.zf)
    {
        goto L_0x00490c97;
    }
L_0x00490caa:
    // 00490caa  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00490cac  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00490cb1  83f822                 +cmp eax, 0x22
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490cb4  7438                   -je 0x490cee
    if (cpu.flags.zf)
    {
        goto L_0x00490cee;
    }
    // 00490cb6  83f824                 +cmp eax, 0x24
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490cb9  7433                   -je 0x490cee
    if (cpu.flags.zf)
    {
        goto L_0x00490cee;
    }
    // 00490cbb  83f823                 +cmp eax, 0x23
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490cbe  742e                   -je 0x490cee
    if (cpu.flags.zf)
    {
        goto L_0x00490cee;
    }
    // 00490cc0  83f829                 +cmp eax, 0x29
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490cc3  7429                   -je 0x490cee
    if (cpu.flags.zf)
    {
        goto L_0x00490cee;
    }
    // 00490cc5  83f82a                 +cmp eax, 0x2a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490cc8  7424                   -je 0x490cee
    if (cpu.flags.zf)
    {
        goto L_0x00490cee;
    }
    // 00490cca  83f82c                 +cmp eax, 0x2c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490ccd  741f                   -je 0x490cee
    if (cpu.flags.zf)
    {
        goto L_0x00490cee;
    }
    // 00490ccf  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490cd2  741a                   -je 0x490cee
    if (cpu.flags.zf)
    {
        goto L_0x00490cee;
    }
    // 00490cd4  83f82e                 +cmp eax, 0x2e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490cd7  7415                   -je 0x490cee
    if (cpu.flags.zf)
    {
        goto L_0x00490cee;
    }
    // 00490cd9  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00490cdb  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00490cde  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490ce0  7402                   -je 0x490ce4
    if (cpu.flags.zf)
    {
        goto L_0x00490ce4;
    }
    // 00490ce2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00490ce4:
    // 00490ce4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490ce6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490ce8  75c0                   -jne 0x490caa
    if (!cpu.flags.zf)
    {
        goto L_0x00490caa;
    }
    // 00490cea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490cec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ced  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490cee:
    // 00490cee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490cf0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cf1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490cf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490cf4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490cf5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490cf7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490cf9  7504                   -jne 0x490cff
    if (!cpu.flags.zf)
    {
        goto L_0x00490cff;
    }
L_0x00490cfb:
    // 00490cfb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490cfd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cfe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490cff:
    // 00490cff  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00490d01  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00490d04  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00490d0a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490d0c  74ed                   -je 0x490cfb
    if (cpu.flags.zf)
    {
        goto L_0x00490cfb;
    }
L_0x00490d0e:
    // 00490d0e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00490d10  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00490d15  83f87c                 +cmp eax, 0x7c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(124 /*0x7c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490d18  7415                   -je 0x490d2f
    if (cpu.flags.zf)
    {
        goto L_0x00490d2f;
    }
    // 00490d1a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00490d1c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00490d1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490d21  7402                   -je 0x490d25
    if (cpu.flags.zf)
    {
        goto L_0x00490d25;
    }
    // 00490d23  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00490d25:
    // 00490d25  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490d27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490d29  75e3                   -jne 0x490d0e
    if (!cpu.flags.zf)
    {
        goto L_0x00490d0e;
    }
    // 00490d2b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490d2d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d2e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490d2f:
    // 00490d2f  8d4208                 -lea eax, [edx + 8]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00490d32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490d34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490d34  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490d35  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490d37  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490d39  7504                   -jne 0x490d3f
    if (!cpu.flags.zf)
    {
        goto L_0x00490d3f;
    }
L_0x00490d3b:
    // 00490d3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490d3d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d3e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490d3f:
    // 00490d3f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00490d41  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00490d44  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00490d4a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490d4c  74ed                   -je 0x490d3b
    if (cpu.flags.zf)
    {
        goto L_0x00490d3b;
    }
L_0x00490d4e:
    // 00490d4e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00490d50  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00490d55  83f86f                 +cmp eax, 0x6f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490d58  7415                   -je 0x490d6f
    if (cpu.flags.zf)
    {
        goto L_0x00490d6f;
    }
    // 00490d5a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00490d5c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00490d5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490d61  7402                   -je 0x490d65
    if (cpu.flags.zf)
    {
        goto L_0x00490d65;
    }
    // 00490d63  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00490d65:
    // 00490d65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490d67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490d69  75e3                   -jne 0x490d4e
    if (!cpu.flags.zf)
    {
        goto L_0x00490d4e;
    }
    // 00490d6b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490d6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490d6f:
    // 00490d6f  8d4208                 -lea eax, [edx + 8]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00490d72  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490d73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_490d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490d80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490d81  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490d85  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00490d89  8b15fc845200           -mov edx, dword ptr [0x5284fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407996) /* 0x5284fc */);
    // 00490d8f  a1dca64c00             -mov eax, dword ptr [0x4ca6dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 00490d94  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00490d97  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00490d99  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00490d9d  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00490d9f  e809250100             -call 0x4a32ad
    cpu.esp -= 4;
    sub_4a32ad(app, cpu);
    if (cpu.terminate) return;
    // 00490da4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490da5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490da8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490da8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490da9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490daa  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00490dae  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00490db2  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490db6  8b15fc845200           -mov edx, dword ptr [0x5284fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407996) /* 0x5284fc */);
    // 00490dbc  a1dca64c00             -mov eax, dword ptr [0x4ca6dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 00490dc1  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00490dc4  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00490dc6  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00490dc8  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00490dca  e8de240100             -call 0x4a32ad
    cpu.esp -= 4;
    sub_4a32ad(app, cpu);
    if (cpu.terminate) return;
    // 00490dcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490dd0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490dd1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490dd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490dd4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490dd5  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490dd9  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00490ddd  8b15fc845200           -mov edx, dword ptr [0x5284fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407996) /* 0x5284fc */);
    // 00490de3  a1dca64c00             -mov eax, dword ptr [0x4ca6dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 00490de8  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00490deb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00490ded  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00490df1  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00490df3  e8b5e40000             -call 0x49f2ad
    cpu.esp -= 4;
    sub_49f2ad(app, cpu);
    if (cpu.terminate) return;
    // 00490df8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490df9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490dfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490dfc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490dfd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490dfe  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00490e02  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00490e06  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490e0a  8b15fc845200           -mov edx, dword ptr [0x5284fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407996) /* 0x5284fc */);
    // 00490e10  a1dca64c00             -mov eax, dword ptr [0x4ca6dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 00490e15  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00490e18  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00490e1a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00490e1c  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00490e1e  e88ae40000             -call 0x49f2ad
    cpu.esp -= 4;
    sub_49f2ad(app, cpu);
    if (cpu.terminate) return;
    // 00490e23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e24  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490e28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490e28  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490e29  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490e2a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490e2b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490e2c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490e2d  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00490e30  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00490e34  8b0d30a44c00           -mov ecx, dword ptr [0x4ca430]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022768) /* 0x4ca430 */);
    // 00490e3a  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00490e3c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00490e3e  7409                   -je 0x490e49
    if (cpu.flags.zf)
    {
        goto L_0x00490e49;
    }
L_0x00490e40:
    // 00490e40  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00490e43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490e49:
    // 00490e49  8d7a08                 -lea edi, [edx + 8]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00490e4c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00490e4e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490e50  ba3cae5200             -mov edx, 0x52ae3c
    cpu.edx = 5418556 /*0x52ae3c*/;
    // 00490e55  668b4702               -mov ax, word ptr [edi + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00490e59  668b37                 -mov si, word ptr [edi]
    cpu.si = app->getMemory<x86::reg16>(cpu.edi);
    // 00490e5c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00490e60  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00490e64  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00490e67  a3fc845200             -mov dword ptr [0x5284fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5407996) /* 0x5284fc */) = cpu.eax;
    // 00490e6c  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00490e6f  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00490e72  e859030000             -call 0x4911d0
    cpu.esp -= 4;
    sub_4911d0(app, cpu);
    if (cpu.terminate) return;
    // 00490e77  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00490e7b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00490e7d  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00490e80  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00490e86  40                     -inc eax
    (cpu.eax)++;
    // 00490e87  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00490e89  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00490e8c  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00490e90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490e92  a0d8a64c00             -mov al, byte ptr [0x4ca6d8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 00490e97  896c242c               -mov dword ptr [esp + 0x2c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebp;
    // 00490e9b  40                     -inc eax
    (cpu.eax)++;
    // 00490e9c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00490e9f  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00490ea1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00490ea4  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00490ea7  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490eaa  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00490eae  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00490eb2  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490eb5  e8569b0000             -call 0x49aa10
    cpu.esp -= 4;
    sub_49aa10(app, cpu);
    if (cpu.terminate) return;
    // 00490eba  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00490ebe  81f900000100           +cmp ecx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490ec4  753f                   -jne 0x490f05
    if (!cpu.flags.zf)
    {
        goto L_0x00490f05;
    }
    // 00490ec6  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490ec8  753b                   -jne 0x490f05
    if (!cpu.flags.zf)
    {
        goto L_0x00490f05;
    }
    // 00490eca  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490ed1  0f8494010000           -je 0x49106b
    if (cpu.flags.zf)
    {
        goto L_0x0049106b;
    }
    // 00490ed7  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00490edb  83fb01                 +cmp ebx, 1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490ede  750e                   -jne 0x490eee
    if (!cpu.flags.zf)
    {
        goto L_0x00490eee;
    }
    // 00490ee0  3b5c2420               +cmp ebx, dword ptr [esp + 0x20]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490ee4  7508                   -jne 0x490eee
    if (!cpu.flags.zf)
    {
        goto L_0x00490eee;
    }
    // 00490ee6  c744242cd40d4900       -mov dword ptr [esp + 0x2c], 0x490dd4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4787668 /*0x490dd4*/;
L_0x00490eee:
    // 00490eee  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00490ef2  83fb02                 +cmp ebx, 2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490ef5  750e                   -jne 0x490f05
    if (!cpu.flags.zf)
    {
        goto L_0x00490f05;
    }
    // 00490ef7  3b5c2420               +cmp ebx, dword ptr [esp + 0x20]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490efb  7508                   -jne 0x490f05
    if (!cpu.flags.zf)
    {
        goto L_0x00490f05;
    }
    // 00490efd  c744242cfc0d4900       -mov dword ptr [esp + 0x2c], 0x490dfc
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4787708 /*0x490dfc*/;
L_0x00490f05:
    // 00490f05  837c242c00             +cmp dword ptr [esp + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490f0a  753f                   -jne 0x490f4b
    if (!cpu.flags.zf)
    {
        goto L_0x00490f4b;
    }
    // 00490f0c  b8a9144900             -mov eax, 0x4914a9
    cpu.eax = 4789417 /*0x4914a9*/;
    // 00490f11  8b15fca34c00           -mov edx, dword ptr [0x4ca3fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022716) /* 0x4ca3fc */);
    // 00490f17  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00490f1b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490f1d  7415                   -je 0x490f34
    if (cpu.flags.zf)
    {
        goto L_0x00490f34;
    }
    // 00490f1f  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490f26  0f847a010000           -je 0x4910a6
    if (cpu.flags.zf)
    {
        goto L_0x004910a6;
    }
    // 00490f2c  c744242c84174900       -mov dword ptr [esp + 0x2c], 0x491784
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4790148 /*0x491784*/;
L_0x00490f34:
    // 00490f34  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00490f38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490f39  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490f3b  b83cae5200             -mov eax, 0x52ae3c
    cpu.eax = 5418556 /*0x52ae3c*/;
    // 00490f40  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490f42  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00490f44  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00490f46  e825a60000             -call 0x49b570
    cpu.esp -= 4;
    sub_49b570(app, cpu);
    if (cpu.terminate) return;
L_0x00490f4b:
    // 00490f4b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00490f4d  0f8e00010000           -jle 0x491053
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491053;
    }
    // 00490f53  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490f55  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 00490f58  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00490f5c  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
L_0x00490f60:
    // 00490f60  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00490f63  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490f65  668b47fe               -mov ax, word ptr [edi - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(-2) /* -0x2 */);
    // 00490f69  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00490f6b  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00490f6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490f71  0f8ec9000000           -jle 0x491040
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491040;
    }
    // 00490f77  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00490f7b  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
L_0x00490f7f:
    // 00490f7f  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00490f83  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00490f85  8b4902                 -mov ecx, dword ptr [ecx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00490f88  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00490f8a  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00490f8d  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00490f8e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00490f90  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00490f92  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00490f95  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00490f98  a134c74c00             -mov eax, dword ptr [0x4cc734]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5031732) /* 0x4cc734 */);
    // 00490f9d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490f9f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490fa3  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00490fa7  a138c74c00             -mov eax, dword ptr [0x4cc738]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5031736) /* 0x4cc738 */);
    // 00490fac  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00490fae  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00490fb2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490fb4  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00490fb8  668b4704               -mov ax, word ptr [edi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00490fbc  8b0dc0a64c00           -mov ecx, dword ptr [0x4ca6c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023424) /* 0x4ca6c0 */);
    // 00490fc2  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00490fc4  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00490fc6  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00490fc7  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00490fc9  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00490fcb  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00490fce  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490fd2  8b0d2cc74c00           -mov ecx, dword ptr [0x4cc72c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5031724) /* 0x4cc72c */);
    // 00490fd8  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00490fda  0faf4c2420             -imul ecx, dword ptr [esp + 0x20]
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 00490fdf  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00490fe2  8b1530c74c00           -mov edx, dword ptr [0x4cc730]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5031728) /* 0x4cc730 */);
    // 00490fe8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490fea  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490fee  0faf74241c             -imul esi, dword ptr [esp + 0x1c]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 00490ff3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00490ff7  0faf442424             -imul eax, dword ptr [esp + 0x24]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 00490ffc  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490ffe  a1e8a64c00             -mov eax, dword ptr [0x4ca6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 00491003  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00491006  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00491008  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049100a  668b4f06               -mov cx, word ptr [edi + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0049100e  8b1534a44c00           -mov edx, dword ptr [0x4ca434]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022772) /* 0x4ca434 */);
    // 00491014  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00491016  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049101a  39d5                   +cmp ebp, edx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049101c  0f8f91000000           -jg 0x4910b3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004910b3;
    }
L_0x00491022:
    // 00491022  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491023  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491024  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00491028  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491029  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049102d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00491030  43                     -inc ebx
    (cpu.ebx)++;
    // 00491031  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00491035  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00491038  39f3                   +cmp ebx, esi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049103a  0f8c3fffffff           -jl 0x490f7f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490f7f;
    }
L_0x00491040:
    // 00491040  66ff44241a             -inc word ptr [esp + 0x1a]
    (app->getMemory<x86::reg16>(cpu.esp + x86::reg32(26) /* 0x1a */))++;
    // 00491045  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00491049  3b742418               +cmp esi, dword ptr [esp + 0x18]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049104d  0f8f0dffffff           -jg 0x490f60
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00490f60;
    }
L_0x00491053:
    // 00491053  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049105a  0f84e0fdffff           -je 0x490e40
    if (cpu.flags.zf)
    {
        goto L_0x00490e40;
    }
    // 00491060  0f77                   -emms 
    cpu.mmx.init();
    // 00491062  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00491065  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491066  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491067  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491068  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491069  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049106a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049106b:
    // 0049106b  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049106f  83fb01                 +cmp ebx, 1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491072  750e                   -jne 0x491082
    if (!cpu.flags.zf)
    {
        goto L_0x00491082;
    }
    // 00491074  3b5c2420               +cmp ebx, dword ptr [esp + 0x20]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491078  7508                   -jne 0x491082
    if (!cpu.flags.zf)
    {
        goto L_0x00491082;
    }
    // 0049107a  c744242c800d4900       -mov dword ptr [esp + 0x2c], 0x490d80
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4787584 /*0x490d80*/;
L_0x00491082:
    // 00491082  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00491086  83fb02                 +cmp ebx, 2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491089  0f8576feffff           -jne 0x490f05
    if (!cpu.flags.zf)
    {
        goto L_0x00490f05;
    }
    // 0049108f  3b5c2420               +cmp ebx, dword ptr [esp + 0x20]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491093  0f856cfeffff           -jne 0x490f05
    if (!cpu.flags.zf)
    {
        goto L_0x00490f05;
    }
    // 00491099  c744242ca80d4900       -mov dword ptr [esp + 0x2c], 0x490da8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4787624 /*0x490da8*/;
    // 004910a1  e95ffeffff             -jmp 0x490f05
    goto L_0x00490f05;
L_0x004910a6:
    // 004910a6  c744242c5e1a4900       -mov dword ptr [esp + 0x2c], 0x491a5e
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4790878 /*0x491a5e*/;
    // 004910ae  e981feffff             -jmp 0x490f34
    goto L_0x00490f34;
L_0x004910b3:
    // 004910b3  e8a08cfeff             -call 0x479d58
    cpu.esp -= 4;
    sub_479d58(app, cpu);
    if (cpu.terminate) return;
    // 004910b8  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004910ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004910bc  0f847efdffff           -je 0x490e40
    if (cpu.flags.zf)
    {
        goto L_0x00490e40;
    }
    // 004910c2  e95bffffff             -jmp 0x491022
    goto L_0x00491022;
}

/* align: skip  */
void Application::sub_4910c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004910c7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004910c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004910c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004910ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004910cb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004910cc  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004910cf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004910d1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004910d3  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004910d6  7507                   -jne 0x4910df
    if (!cpu.flags.zf)
    {
        goto L_0x004910df;
    }
L_0x004910d8:
    // 004910d8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004910da  e99d000000             -jmp 0x49117c
    goto L_0x0049117c;
L_0x004910df:
    // 004910df  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004910e3  751c                   -jne 0x491101
    if (!cpu.flags.zf)
    {
        goto L_0x00491101;
    }
    // 004910e5  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
L_0x004910e7:
    // 004910e7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004910e9  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004910eb  7412                   -je 0x4910ff
    if (cpu.flags.zf)
    {
        goto L_0x004910ff;
    }
    // 004910ed  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004910ef  740c                   -je 0x4910fd
    if (cpu.flags.zf)
    {
        goto L_0x004910fd;
    }
    // 004910f1  46                     -inc esi
    (cpu.esi)++;
    // 004910f2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004910f4  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004910f6  7407                   -je 0x4910ff
    if (cpu.flags.zf)
    {
        goto L_0x004910ff;
    }
    // 004910f8  46                     -inc esi
    (cpu.esi)++;
    // 004910f9  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004910fb  75ea                   -jne 0x4910e7
    if (!cpu.flags.zf)
    {
        goto L_0x004910e7;
    }
L_0x004910fd:
    // 004910fd  2bf6                   +sub esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004910ff:
    // 004910ff  ebd7                   -jmp 0x4910d8
    goto L_0x004910d8;
L_0x00491101:
    // 00491101  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00491106  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00491108  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0049110a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049110b  e30b                   -jecxz 0x491118
    if (cpu.ecx == 0)
    {
        goto L_0x00491118;
    }
    // 0049110d  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 0049110f  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00491111  f2ae                   +repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00491113  7503                   -jne 0x491118
    if (!cpu.flags.zf)
    {
        goto L_0x00491118;
    }
    // 00491115  4f                     -dec edi
    (cpu.edi)--;
    // 00491116  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x0049111a;
L_0x00491118:
    // 00491118  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x0049111a:
    // 0049111a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049111b  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0049111e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00491120  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00491121  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00491123  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00491125  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491127  49                     -dec ecx
    (cpu.ecx)--;
    // 00491128  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049112a  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0049112c  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049112e  49                     -dec ecx
    (cpu.ecx)--;
    // 0049112f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00491130  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
L_0x00491132:
    // 00491132  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00491135  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00491137  39e9                   +cmp ecx, ebp
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491139  723f                   -jb 0x49117a
    if (cpu.flags.cf)
    {
        goto L_0x0049117a;
    }
    // 0049113b  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0049113d  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049113f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00491140  e30b                   -jecxz 0x49114d
    if (cpu.ecx == 0)
    {
        goto L_0x0049114d;
    }
    // 00491142  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00491144  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00491146  f2ae                   +repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00491148  7503                   -jne 0x49114d
    if (!cpu.flags.zf)
    {
        goto L_0x0049114d;
    }
    // 0049114a  4f                     -dec edi
    (cpu.edi)--;
    // 0049114b  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x0049114f;
L_0x0049114d:
    // 0049114d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x0049114f:
    // 0049114f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00491150  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00491152  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00491154  7424                   -je 0x49117a
    if (cpu.flags.zf)
    {
        goto L_0x0049117a;
    }
    // 00491156  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00491158  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049115a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049115c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049115d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049115f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00491161  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00491163  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 00491165  7405                   -je 0x49116c
    if (cpu.flags.zf)
    {
        goto L_0x0049116c;
    }
    // 00491167  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491169  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0049116c:
    // 0049116c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049116d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049116f  7504                   -jne 0x491175
    if (!cpu.flags.zf)
    {
        goto L_0x00491175;
    }
    // 00491171  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491173  eb07                   -jmp 0x49117c
    goto L_0x0049117c;
L_0x00491175:
    // 00491175  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00491178  ebb8                   -jmp 0x491132
    goto L_0x00491132;
L_0x0049117a:
    // 0049117a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049117c:
    // 0049117c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049117f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491180  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491181  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491182  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491183  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491184  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_491188(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491188  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491189  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049118a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049118b  bf3cc74c00             -mov edi, 0x4cc73c
    cpu.edi = 5031740 /*0x4cc73c*/;
    // 00491190  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00491192  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 00491197  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 00491199  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049119a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049119b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049119c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49119d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049119d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049119e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049119f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004911a0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004911a2  be3cc74c00             -mov esi, 0x4cc73c
    cpu.esi = 5031740 /*0x4cc73c*/;
    // 004911a7  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 004911ac  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 004911ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004911af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004911b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004911b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4911b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004911b2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004911b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004911b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004911b5  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004911b7  bf3cc74c00             -mov edi, 0x4cc73c
    cpu.edi = 5031740 /*0x4cc73c*/;
    // 004911bc  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004911be  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004911c0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004911c3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 004911c5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004911c7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004911ca  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
    }
    // 004911cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004911cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004911ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004911cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4911d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004911d0  a344c94c00             -mov dword ptr [0x4cc944], eax
    app->getMemory<x86::reg32>(x86::reg32(5032260) /* 0x4cc944 */) = cpu.eax;
    // 004911d5  891540c94c00           -mov dword ptr [0x4cc940], edx
    app->getMemory<x86::reg32>(x86::reg32(5032256) /* 0x4cc940 */) = cpu.edx;
    // 004911db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4911dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004911dc  a33cc94c00             -mov dword ptr [0x4cc93c], eax
    app->getMemory<x86::reg32>(x86::reg32(5032252) /* 0x4cc93c */) = cpu.eax;
    // 004911e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4911e2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004911e2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004911e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004911e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004911e5  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004911e9  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004911ed  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004911f1  033544c94c00           -add esi, dword ptr [0x4cc944]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5032260) /* 0x4cc944 */)));
    // 004911f7  033ddca64c00           -add edi, dword ptr [0x4ca6dc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 004911fd  8b1540c94c00           -mov edx, dword ptr [0x4cc940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032256) /* 0x4cc940 */);
    // 00491203  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491205  803dd8a64c0008         +cmp byte ptr [0x4ca6d8], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049120c  7f61                   -jg 0x49126f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049126f;
    }
    // 0049120e  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491211  783d                   -js 0x491250
    if (cpu.flags.sf)
    {
        goto L_0x00491250;
    }
L_0x00491213:
    // 00491213  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491215  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 00491218  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049121b  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049121d  7402                   -je 0x491221
    if (cpu.flags.zf)
    {
        goto L_0x00491221;
    }
    // 0049121f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x00491221:
    // 00491221  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 00491224  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00491227  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491229  7403                   -je 0x49122e
    if (cpu.flags.zf)
    {
        goto L_0x0049122e;
    }
    // 0049122b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
L_0x0049122e:
    // 0049122e  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 00491231  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00491234  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491236  7403                   -je 0x49123b
    if (cpu.flags.zf)
    {
        goto L_0x0049123b;
    }
    // 00491238  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
L_0x0049123b:
    // 0049123b  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0049123e  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491240  7403                   -je 0x491245
    if (cpu.flags.zf)
    {
        goto L_0x00491245;
    }
    // 00491242  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
L_0x00491245:
    // 00491245  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491248  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049124b  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049124e  79c3                   -jns 0x491213
    if (!cpu.flags.sf)
    {
        goto L_0x00491213;
    }
L_0x00491250:
    // 00491250  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491253  7816                   -js 0x49126b
    if (cpu.flags.sf)
    {
        goto L_0x0049126b;
    }
L_0x00491255:
    // 00491255  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491257  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0049125a  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049125c  7402                   -je 0x491260
    if (cpu.flags.zf)
    {
        goto L_0x00491260;
    }
    // 0049125e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x00491260:
    // 00491260  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491263  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491266  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00491269  79ea                   -jns 0x491255
    if (!cpu.flags.sf)
    {
        goto L_0x00491255;
    }
L_0x0049126b:
    // 0049126b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049126c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049126d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049126e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049126f:
    // 0049126f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491271  803dd8a64c0010         +cmp byte ptr [0x4ca6d8], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491278  7f21                   -jg 0x49129b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049129b;
    }
    // 0049127a  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049127d  78ec                   -js 0x49126b
    if (cpu.flags.sf)
    {
        goto L_0x0049126b;
    }
L_0x0049127f:
    // 0049127f  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 00491283  6609c0                 +or ax, ax
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(cpu.ax))));
    // 00491286  7403                   -je 0x49128b
    if (cpu.flags.zf)
    {
        goto L_0x0049128b;
    }
    // 00491288  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
L_0x0049128b:
    // 0049128b  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049128e  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491291  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491294  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00491297  79e6                   -jns 0x49127f
    if (!cpu.flags.sf)
    {
        goto L_0x0049127f;
    }
    // 00491299  ebd0                   -jmp 0x49126b
    goto L_0x0049126b;
L_0x0049129b:
    // 0049129b  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049129e  78cb                   -js 0x49126b
    if (cpu.flags.sf)
    {
        goto L_0x0049126b;
    }
L_0x004912a0:
    // 004912a0  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 004912a3  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 004912a5  7402                   -je 0x4912a9
    if (cpu.flags.zf)
    {
        goto L_0x004912a9;
    }
    // 004912a7  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x004912a9:
    // 004912a9  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004912ac  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004912af  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004912b2  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004912b5  79e9                   -jns 0x4912a0
    if (!cpu.flags.sf)
    {
        goto L_0x004912a0;
    }
    // 004912b7  ebb2                   -jmp 0x49126b
    goto L_0x0049126b;
}

/* align: skip  */
void Application::sub_4912b9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004912b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004912ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004912bb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004912bc  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004912c0  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004912c4  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004912c8  033544c94c00           -add esi, dword ptr [0x4cc944]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5032260) /* 0x4cc944 */)));
    // 004912ce  033ddca64c00           -add edi, dword ptr [0x4ca6dc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 004912d4  8b1540c94c00           -mov edx, dword ptr [0x4cc940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032256) /* 0x4cc940 */);
    // 004912da  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004912dc  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004912df  7855                   -js 0x491336
    if (cpu.flags.sf)
    {
        goto L_0x00491336;
    }
L_0x004912e1:
    // 004912e1  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004912e3  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004912e6  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004912e9  8a803cc74c00           -mov al, byte ptr [eax + 0x4cc73c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5031740) /* 0x4cc73c */);
    // 004912ef  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004912f1  7402                   -je 0x4912f5
    if (cpu.flags.zf)
    {
        goto L_0x004912f5;
    }
    // 004912f3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004912f5:
    // 004912f5  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004912f8  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004912fb  8a803cc74c00           -mov al, byte ptr [eax + 0x4cc73c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5031740) /* 0x4cc73c */);
    // 00491301  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491303  7403                   -je 0x491308
    if (cpu.flags.zf)
    {
        goto L_0x00491308;
    }
    // 00491305  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
L_0x00491308:
    // 00491308  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0049130b  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049130e  8a803cc74c00           -mov al, byte ptr [eax + 0x4cc73c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5031740) /* 0x4cc73c */);
    // 00491314  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491316  7403                   -je 0x49131b
    if (cpu.flags.zf)
    {
        goto L_0x0049131b;
    }
    // 00491318  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
L_0x0049131b:
    // 0049131b  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0049131e  8a803cc74c00           -mov al, byte ptr [eax + 0x4cc73c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5031740) /* 0x4cc73c */);
    // 00491324  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491326  7403                   -je 0x49132b
    if (cpu.flags.zf)
    {
        goto L_0x0049132b;
    }
    // 00491328  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
L_0x0049132b:
    // 0049132b  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049132e  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00491331  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00491334  79ab                   -jns 0x4912e1
    if (!cpu.flags.sf)
    {
        goto L_0x004912e1;
    }
L_0x00491336:
    // 00491336  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491339  781c                   -js 0x491357
    if (cpu.flags.sf)
    {
        goto L_0x00491357;
    }
L_0x0049133b:
    // 0049133b  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049133d  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 00491340  8a803cc74c00           -mov al, byte ptr [eax + 0x4cc73c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5031740) /* 0x4cc73c */);
    // 00491346  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491348  7402                   -je 0x49134c
    if (cpu.flags.zf)
    {
        goto L_0x0049134c;
    }
    // 0049134a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x0049134c:
    // 0049134c  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049134f  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491352  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00491355  79e4                   -jns 0x49133b
    if (!cpu.flags.sf)
    {
        goto L_0x0049133b;
    }
L_0x00491357:
    // 00491357  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491358  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491359  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049135a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49135b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049135b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049135c  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049135e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049135f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491360  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491361  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00491364  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00491367  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049136a  033544c94c00           -add esi, dword ptr [0x4cc944]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5032260) /* 0x4cc944 */)));
    // 00491370  033ddca64c00           -add edi, dword ptr [0x4ca6dc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 00491376  8b1540c94c00           -mov edx, dword ptr [0x4cc940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032256) /* 0x4cc940 */);
    // 0049137c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049137e:
    // 0049137e  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491380  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 00491383  8a803cc74c00           -mov al, byte ptr [eax + 0x4cc73c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5031740) /* 0x4cc73c */);
    // 00491389  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049138c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049138e  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491391  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00491394  75e8                   -jne 0x49137e
    if (!cpu.flags.zf)
    {
        goto L_0x0049137e;
    }
    // 00491396  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491397  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491398  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491399  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049139a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49139b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049139b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049139c  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049139e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049139f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004913a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004913a1  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004913a4  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004913a7  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004913aa  033544c94c00           -add esi, dword ptr [0x4cc944]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5032260) /* 0x4cc944 */)));
    // 004913b0  033ddca64c00           -add edi, dword ptr [0x4ca6dc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 004913b6  8b1540c94c00           -mov edx, dword ptr [0x4cc940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032256) /* 0x4cc940 */);
    // 004913bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004913be:
    // 004913be  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004913c0  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 004913c3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004913c6  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004913c8  720a                   -jb 0x4913d4
    if (cpu.flags.cf)
    {
        goto L_0x004913d4;
    }
    // 004913ca  750a                   -jne 0x4913d6
    if (!cpu.flags.zf)
    {
        goto L_0x004913d6;
    }
    // 004913cc  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004913ce  8a803cc84c00           -mov al, byte ptr [eax + 0x4cc83c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5031996) /* 0x4cc83c */);
L_0x004913d4:
    // 004913d4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x004913d6:
    // 004913d6  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004913d9  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004913dc  75e0                   -jne 0x4913be
    if (!cpu.flags.zf)
    {
        goto L_0x004913be;
    }
    // 004913de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004913df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004913e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004913e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004913e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4913e3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004913e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004913e4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004913e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004913e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004913e8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004913e9  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004913ec  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004913ef  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004913f2  033544c94c00           -add esi, dword ptr [0x4cc944]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5032260) /* 0x4cc944 */)));
    // 004913f8  033ddca64c00           -add edi, dword ptr [0x4ca6dc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 004913fe  8b1540c94c00           -mov edx, dword ptr [0x4cc940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032256) /* 0x4cc940 */);
    // 00491404  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00491406:
    // 00491406  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491408  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0049140b  8a803cc74c00           -mov al, byte ptr [eax + 0x4cc73c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5031740) /* 0x4cc73c */);
    // 00491411  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491414  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491416  720a                   -jb 0x491422
    if (cpu.flags.cf)
    {
        goto L_0x00491422;
    }
    // 00491418  750a                   -jne 0x491424
    if (!cpu.flags.zf)
    {
        goto L_0x00491424;
    }
    // 0049141a  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0049141c  8a803cc84c00           -mov al, byte ptr [eax + 0x4cc83c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5031996) /* 0x4cc83c */);
L_0x00491422:
    // 00491422  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x00491424:
    // 00491424  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491427  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0049142a  75da                   -jne 0x491406
    if (!cpu.flags.zf)
    {
        goto L_0x00491406;
    }
    // 0049142c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049142d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049142e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049142f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491430  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491431(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491431  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491432  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491433  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491434  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491435  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00491439  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049143d  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00491441  033544c94c00           -add esi, dword ptr [0x4cc944]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5032260) /* 0x4cc944 */)));
    // 00491447  032ddca64c00           -add ebp, dword ptr [0x4ca6dc]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 0049144d  8b1540c94c00           -mov edx, dword ptr [0x4cc940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032256) /* 0x4cc940 */);
    // 00491453  8b3d3cc94c00           -mov edi, dword ptr [0x4cc93c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5032252) /* 0x4cc93c */);
    // 00491459  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049145b  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049145e  782e                   -js 0x49148e
    if (cpu.flags.sf)
    {
        goto L_0x0049148e;
    }
L_0x00491460:
    // 00491460  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491462  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 00491465  8b1c87                 -mov ebx, dword ptr [edi + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 00491468  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 0049146b  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 0049146e  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 00491471  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491474  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 00491477  8b1c87                 -mov ebx, dword ptr [edi + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 0049147a  8a4501                 -mov al, byte ptr [ebp + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0049147d  8a0418                 -mov al, byte ptr [eax + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 1);
    // 00491480  884501                 -mov byte ptr [ebp + 1], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00491483  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491486  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00491489  8d6d02                 -lea ebp, [ebp + 2]
    cpu.ebp = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0049148c  79d2                   -jns 0x491460
    if (!cpu.flags.sf)
    {
        goto L_0x00491460;
    }
L_0x0049148e:
    // 0049148e  83c101                 +add ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491491  7811                   -js 0x4914a4
    if (cpu.flags.sf)
    {
        goto L_0x004914a4;
    }
    // 00491493  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491495  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 00491498  8b1c87                 -mov ebx, dword ptr [edi + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 0049149b  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 0049149e  8a0418                 -mov al, byte ptr [eax + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 1);
    // 004914a1  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
L_0x004914a4:
    // 004914a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004914a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004914a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004914a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004914a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4914a9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004914a9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004914aa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004914ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004914ac  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004914ad  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004914b1  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004914b5  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004914b9  8b1540c94c00           -mov edx, dword ptr [0x4cc940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032256) /* 0x4cc940 */);
    // 004914bf  033544c94c00           -add esi, dword ptr [0x4cc944]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5032260) /* 0x4cc944 */)));
    // 004914c5  033ddca64c00           -add edi, dword ptr [0x4ca6dc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 004914cb  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004914ce  803dd8a64c0008         +cmp byte ptr [0x4ca6d8], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004914d5  0f8f26010000           -jg 0x491601
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00491601;
    }
    // 004914db  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004914de  0f8c99000000           -jl 0x49157d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049157d;
    }
    // 004914e4  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004914ea  0f85e2000000           -jne 0x4915d2
    if (!cpu.flags.zf)
    {
        goto L_0x004915d2;
    }
L_0x004914f0:
    // 004914f0  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004914f3  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004914f6  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004914f9  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004914fd  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00491500  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00491502  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491505  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00491508  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0049150c  8b6a18                 -mov ebp, dword ptr [edx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049150f  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00491511  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491514  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00491517  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0049151b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049151e  8b6a10                 -mov ebp, dword ptr [edx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00491521  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491524  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 00491527  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0049152b  8b6a28                 -mov ebp, dword ptr [edx + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 0049152e  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00491531  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491534  8b5a24                 -mov ebx, dword ptr [edx + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 00491537  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0049153b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049153e  8b6a20                 -mov ebp, dword ptr [edx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00491541  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491544  8b5a3c                 -mov ebx, dword ptr [edx + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 00491547  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0049154b  8b6a38                 -mov ebp, dword ptr [edx + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    // 0049154e  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00491551  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491554  8b5a34                 -mov ebx, dword ptr [edx + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    // 00491557  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0049155b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049155e  8b6a30                 -mov ebp, dword ptr [edx + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 00491561  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491564  8b5a4c                 -mov ebx, dword ptr [edx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 00491567  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0049156b  8d5240                 -lea edx, [edx + 0x40]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 0049156e  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00491571  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491574  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00491577  0f8973ffffff           -jns 0x4914f0
    if (!cpu.flags.sf)
    {
        goto L_0x004914f0;
    }
L_0x0049157d:
    // 0049157d  83c10c                 +add ecx, 0xc
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491580  7831                   -js 0x4915b3
    if (cpu.flags.sf)
    {
        goto L_0x004915b3;
    }
    // 00491582  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 00491588  7529                   -jne 0x4915b3
    if (!cpu.flags.zf)
    {
        goto L_0x004915b3;
    }
L_0x0049158a:
    // 0049158a  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049158d  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491590  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491593  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 00491597  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049159a  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 0049159c  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0049159f  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004915a2  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 004915a6  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004915a9  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004915ab  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004915ae  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004915b1  79d7                   -jns 0x49158a
    if (!cpu.flags.sf)
    {
        goto L_0x0049158a;
    }
L_0x004915b3:
    // 004915b3  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004915b6  7815                   -js 0x4915cd
    if (cpu.flags.sf)
    {
        goto L_0x004915cd;
    }
    // 004915b8  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004915ba:
    // 004915ba  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004915bd  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004915c0  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004915c2  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004915c5  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004915c8  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004915cb  79ed                   -jns 0x4915ba
    if (!cpu.flags.sf)
    {
        goto L_0x004915ba;
    }
L_0x004915cd:
    // 004915cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004915ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004915cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004915d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004915d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004915d2:
    // 004915d2  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004915d5  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004915d7:
    // 004915d7  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004915da  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004915dd  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004915df  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004915e2  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004915e5  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004915eb  8d49ff                 -lea ecx, [ecx - 1]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004915ee  75e7                   -jne 0x4915d7
    if (!cpu.flags.zf)
    {
        goto L_0x004915d7;
    }
    // 004915f0  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004915f3  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004915f6  0f89f4feffff           -jns 0x4914f0
    if (!cpu.flags.sf)
    {
        goto L_0x004914f0;
    }
    // 004915fc  e97cffffff             -jmp 0x49157d
    goto L_0x0049157d;
L_0x00491601:
    // 00491601  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491603  803dd8a64c0010         +cmp byte ptr [0x4ca6d8], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049160a  7f1c                   -jg 0x491628
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00491628;
    }
    // 0049160c  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049160f  78bc                   -js 0x4915cd
    if (cpu.flags.sf)
    {
        goto L_0x004915cd;
    }
L_0x00491611:
    // 00491611  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 00491615  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491618  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0049161b  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049161e  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491621  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00491624  79eb                   -jns 0x491611
    if (!cpu.flags.sf)
    {
        goto L_0x00491611;
    }
    // 00491626  eba5                   -jmp 0x4915cd
    goto L_0x004915cd;
L_0x00491628:
    // 00491628  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049162b  78a0                   -js 0x4915cd
    if (cpu.flags.sf)
    {
        goto L_0x004915cd;
    }
L_0x0049162d:
    // 0049162d  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 00491630  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491633  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00491635  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491638  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049163b  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049163e  79ed                   -jns 0x49162d
    if (!cpu.flags.sf)
    {
        goto L_0x0049162d;
    }
    // 00491640  eb8b                   -jmp 0x4915cd
    goto L_0x004915cd;
}

/* align: skip  */
void Application::sub_491642(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491642  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491643  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491644  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491645  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491646  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049164a  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049164e  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00491652  8b1540c94c00           -mov edx, dword ptr [0x4cc940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032256) /* 0x4cc940 */);
    // 00491658  033544c94c00           -add esi, dword ptr [0x4cc944]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5032260) /* 0x4cc944 */)));
    // 0049165e  033ddca64c00           -add edi, dword ptr [0x4ca6dc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 00491664  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491666  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491669  7820                   -js 0x49168b
    if (cpu.flags.sf)
    {
        goto L_0x0049168b;
    }
    // 0049166b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049166d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049166f:
    // 0049166f  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491672  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491675  668b0c4570a35200       -mov cx, word ptr [eax*2 + 0x52a370]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5415792) /* 0x52a370 */ + cpu.eax * 2);
    // 0049167d  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491680  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 00491683  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491686  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00491689  79e4                   -jns 0x49166f
    if (!cpu.flags.sf)
    {
        goto L_0x0049166f;
    }
L_0x0049168b:
    // 0049168b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049168c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049168d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049168e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049168f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491690  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491691  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491692  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491693  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491694  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00491698  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049169c  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004916a0  8b1540c94c00           -mov edx, dword ptr [0x4cc940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032256) /* 0x4cc940 */);
    // 004916a6  033544c94c00           -add esi, dword ptr [0x4cc944]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5032260) /* 0x4cc944 */)));
    // 004916ac  033ddca64c00           -add edi, dword ptr [0x4ca6dc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 004916b2  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004916b4  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004916b7  7822                   -js 0x4916db
    if (cpu.flags.sf)
    {
        goto L_0x004916db;
    }
    // 004916b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004916bb:
    // 004916bb  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004916be  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004916c1  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004916c3  740b                   -je 0x4916d0
    if (cpu.flags.zf)
    {
        goto L_0x004916d0;
    }
    // 004916c5  668b0c4570a35200       -mov cx, word ptr [eax*2 + 0x52a370]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5415792) /* 0x52a370 */ + cpu.eax * 2);
    // 004916cd  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
L_0x004916d0:
    // 004916d0  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004916d3  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004916d6  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004916d9  79e0                   -jns 0x4916bb
    if (!cpu.flags.sf)
    {
        goto L_0x004916bb;
    }
L_0x004916db:
    // 004916db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004916dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004916dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004916de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004916df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4916e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004916e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004916e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004916e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004916e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004916e4  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004916e8  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004916ec  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004916f0  8b1540c94c00           -mov edx, dword ptr [0x4cc940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032256) /* 0x4cc940 */);
    // 004916f6  033544c94c00           -add esi, dword ptr [0x4cc944]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5032260) /* 0x4cc944 */)));
    // 004916fc  033ddca64c00           -add edi, dword ptr [0x4ca6dc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 00491702  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491704  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491707  7822                   -js 0x49172b
    if (cpu.flags.sf)
    {
        goto L_0x0049172b;
    }
    // 00491709  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049170b:
    // 0049170b  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0049170e  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491711  3cfd                   +cmp al, 0xfd
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(253 /*0xfd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491713  731b                   -jae 0x491730
    if (!cpu.flags.cf)
    {
        goto L_0x00491730;
    }
    // 00491715  668b0c4570a35200       -mov cx, word ptr [eax*2 + 0x52a370]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5415792) /* 0x52a370 */ + cpu.eax * 2);
    // 0049171d  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 00491720  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491723  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491726  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00491729  79e0                   -jns 0x49170b
    if (!cpu.flags.sf)
    {
        goto L_0x0049170b;
    }
L_0x0049172b:
    // 0049172b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049172c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049172d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049172e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049172f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491730:
    // 00491730  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491732  7435                   -je 0x491769
    if (cpu.flags.zf)
    {
        goto L_0x00491769;
    }
    // 00491734  3cfd                   +cmp al, 0xfd
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(253 /*0xfd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491736  740d                   -je 0x491745
    if (cpu.flags.zf)
    {
        goto L_0x00491745;
    }
    // 00491738  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049173b  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049173e  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00491741  79c8                   -jns 0x49170b
    if (!cpu.flags.sf)
    {
        goto L_0x0049170b;
    }
    // 00491743  ebe6                   -jmp 0x49172b
    goto L_0x0049172b;
L_0x00491745:
    // 00491745  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 00491748  6689c8                 -mov ax, cx
    cpu.ax = cpu.cx;
    // 0049174b  66c1e902               -shr cx, 2
    cpu.cx >>= 2 /*0x2*/ % 32;
    // 0049174f  6681e1e739             -and cx, 0x39e7
    cpu.cx &= x86::reg16(x86::sreg16(14823 /*0x39e7*/));
    // 00491754  6629c8                 -sub ax, cx
    (cpu.ax) -= x86::reg16(x86::sreg16(cpu.cx));
    // 00491757  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0049175a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049175c  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049175f  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491762  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00491765  79a4                   -jns 0x49170b
    if (!cpu.flags.sf)
    {
        goto L_0x0049170b;
    }
    // 00491767  ebc2                   -jmp 0x49172b
    goto L_0x0049172b;
L_0x00491769:
    // 00491769  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 0049176c  66d1e9                 -shr cx, 1
    cpu.cx >>= 1 /*0x1*/ % 32;
    // 0049176f  6681e1ef7b             -and cx, 0x7bef
    cpu.cx &= x86::reg16(x86::sreg16(31727 /*0x7bef*/));
    // 00491774  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 00491777  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049177a  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049177d  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00491780  7989                   -jns 0x49170b
    if (!cpu.flags.sf)
    {
        goto L_0x0049170b;
    }
    // 00491782  eba7                   -jmp 0x49172b
    goto L_0x0049172b;
}

/* align: skip  */
void Application::sub_491784(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491784  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491785  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491786  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491787  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491788  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049178c  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00491790  8b1540c94c00           -mov edx, dword ptr [0x4cc940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032256) /* 0x4cc940 */);
    // 00491796  033544c94c00           -add esi, dword ptr [0x4cc944]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5032260) /* 0x4cc944 */)));
    // 0049179c  033ddca64c00           -add edi, dword ptr [0x4ca6dc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 004917a2  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004917a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004917a6  803dd8a64c0008         +cmp byte ptr [0x4ca6d8], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004917ad  0f8f32010000           -jg 0x4918e5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004918e5;
    }
    // 004917b3  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 004917b9  7421                   -je 0x4917dc
    if (cpu.flags.zf)
    {
        goto L_0x004917dc;
    }
L_0x004917bb:
    // 004917bb  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004917be  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004917c1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004917c3  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004917c8  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004917cb  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004917ce  0f880c010000           -js 0x4918e0
    if (cpu.flags.sf)
    {
        goto L_0x004918e0;
    }
    // 004917d4  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 004917da  75df                   -jne 0x4917bb
    if (!cpu.flags.zf)
    {
        goto L_0x004917bb;
    }
L_0x004917dc:
    // 004917dc  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004917e1  0f8c8d000000           -jl 0x491874
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491874;
    }
L_0x004917e7:
    // 004917e7  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004917ea  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004917ed  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004917f0  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004917f3  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004917f6  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004917f9  0f73f008               -psllq mm0, 8
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 8 /*0x8*/) };
    // 004917fd  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 00491800  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491803  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00491806  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00491809  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 0049180d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 00491810  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491813  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00491816  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00491819  0f73f018               -psllq mm0, 0x18
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 24 /*0x18*/) };
    // 0049181d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 00491820  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491823  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00491826  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00491829  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 0049182d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 00491830  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491833  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00491836  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00491839  0f73f028               -psllq mm0, 0x28
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 40 /*0x28*/) };
    // 0049183d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 00491840  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491843  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00491846  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00491849  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 0049184d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 00491850  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491853  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00491856  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00491859  0f73f038               -psllq mm0, 0x38
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 56 /*0x38*/) };
    // 0049185d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 00491860  0f7f0f                 -movq qword ptr [edi], mm1
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm1;
    // 00491863  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491868  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049186b  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049186e  0f8973ffffff           -jns 0x4917e7
    if (!cpu.flags.sf)
    {
        goto L_0x004917e7;
    }
L_0x00491874:
    // 00491874  8344241c04             +add dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491879  7849                   -js 0x4918c4
    if (cpu.flags.sf)
    {
        goto L_0x004918c4;
    }
L_0x0049187b:
    // 0049187b  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0049187e  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491881  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00491884  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491887  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049188a  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0049188d  0f73f008               -psllq mm0, 8
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 8 /*0x8*/) };
    // 00491891  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 00491894  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491897  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049189a  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0049189d  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 004918a1  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004918a4  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004918a7  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004918aa  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004918ad  0f73f018               -psllq mm0, 0x18
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 24 /*0x18*/) };
    // 004918b1  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004918b4  0f7e0f                 -movd dword ptr [edi], mm1
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm1);
    // 004918b7  836c241c04             +sub dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004918bc  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004918bf  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004918c2  79b7                   -jns 0x49187b
    if (!cpu.flags.sf)
    {
        goto L_0x0049187b;
    }
L_0x004918c4:
    // 004918c4  8344241c03             +add dword ptr [esp + 0x1c], 3
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004918c9  7815                   -js 0x4918e0
    if (cpu.flags.sf)
    {
        goto L_0x004918e0;
    }
L_0x004918cb:
    // 004918cb  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 004918ce  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004918d1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004918d3  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004918d8  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004918db  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004918de  79eb                   -jns 0x4918cb
    if (!cpu.flags.sf)
    {
        goto L_0x004918cb;
    }
L_0x004918e0:
    // 004918e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004918e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004918e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004918e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004918e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004918e5:
    // 004918e5  803dd8a64c0010         +cmp byte ptr [0x4ca6d8], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004918ec  0f8f47010000           -jg 0x491a39
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00491a39;
    }
    // 004918f2  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 004918f8  741f                   -je 0x491919
    if (cpu.flags.zf)
    {
        goto L_0x00491919;
    }
L_0x004918fa:
    // 004918fa  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004918fe  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491901  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 00491904  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491909  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049190c  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0049190f  78cf                   -js 0x4918e0
    if (cpu.flags.sf)
    {
        goto L_0x004918e0;
    }
    // 00491911  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 00491917  75e1                   -jne 0x4918fa
    if (!cpu.flags.zf)
    {
        goto L_0x004918fa;
    }
L_0x00491919:
    // 00491919  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049191e  0f8c92000000           -jl 0x4919b6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004919b6;
    }
L_0x00491924:
    // 00491924  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 00491928  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049192b  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0049192e  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 00491932  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00491935  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00491938  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 0049193c  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0049193f  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 00491943  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00491946  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00491949  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 0049194d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 00491950  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 00491954  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00491957  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0049195a  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 0049195e  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 00491961  0f7f0f                 -movq qword ptr [edi], mm1
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm1;
    // 00491964  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 00491968  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0049196b  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0049196e  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 00491972  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00491975  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00491978  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 0049197c  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0049197f  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 00491983  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00491986  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 00491989  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 0049198d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 00491990  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 00491994  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00491997  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0049199a  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 0049199e  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004919a1  0f7f4f08               -movq qword ptr [edi + 8], mm1
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 004919a5  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004919aa  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004919ad  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004919b0  0f896effffff           -jns 0x491924
    if (!cpu.flags.sf)
    {
        goto L_0x00491924;
    }
L_0x004919b6:
    // 004919b6  8344241c04             +add dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004919bb  7855                   -js 0x491a12
    if (cpu.flags.sf)
    {
        goto L_0x00491a12;
    }
    // 004919bd  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 004919c3  754d                   -jne 0x491a12
    if (!cpu.flags.zf)
    {
        goto L_0x00491a12;
    }
L_0x004919c5:
    // 004919c5  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004919c9  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004919cc  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004919cf  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004919d3  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004919d6  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004919d9  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 004919dd  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004919e0  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004919e4  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004919e7  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004919ea  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 004919ee  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004919f1  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 004919f5  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004919f8  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004919fb  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 004919ff  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 00491a02  0f7f0f                 -movq qword ptr [edi], mm1
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm1;
    // 00491a05  836c241c04             +sub dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491a0a  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00491a0d  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00491a10  79b3                   -jns 0x4919c5
    if (!cpu.flags.sf)
    {
        goto L_0x004919c5;
    }
L_0x00491a12:
    // 00491a12  8344241c03             +add dword ptr [esp + 0x1c], 3
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491a17  0f88c3feffff           -js 0x4918e0
    if (cpu.flags.sf)
    {
        goto L_0x004918e0;
    }
L_0x00491a1d:
    // 00491a1d  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 00491a21  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491a24  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 00491a27  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491a2c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491a2f  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00491a32  79e9                   -jns 0x491a1d
    if (!cpu.flags.sf)
    {
        goto L_0x00491a1d;
    }
    // 00491a34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a35  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a37  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a38  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491a39:
    // 00491a39  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491a3e  0f889cfeffff           -js 0x4918e0
    if (cpu.flags.sf)
    {
        goto L_0x004918e0;
    }
L_0x00491a44:
    // 00491a44  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 00491a47  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491a4a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00491a4c  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491a51  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491a54  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00491a57  79eb                   -jns 0x491a44
    if (!cpu.flags.sf)
    {
        goto L_0x00491a44;
    }
    // 00491a59  e982feffff             -jmp 0x4918e0
    goto L_0x004918e0;
}

/* align: skip  */
void Application::sub_491a5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491a5e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491a5f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491a60  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491a61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491a62  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00491a66  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00491a6a  8b1540c94c00           -mov edx, dword ptr [0x4cc940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032256) /* 0x4cc940 */);
    // 00491a70  033544c94c00           -add esi, dword ptr [0x4cc944]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5032260) /* 0x4cc944 */)));
    // 00491a76  033ddca64c00           -add edi, dword ptr [0x4ca6dc]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */)));
    // 00491a7c  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491a7e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491a80  803dd8a64c0008         +cmp byte ptr [0x4ca6d8], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491a87  0f8ffd000000           -jg 0x491b8a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00491b8a;
    }
    // 00491a8d  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 00491a93  7421                   -je 0x491ab6
    if (cpu.flags.zf)
    {
        goto L_0x00491ab6;
    }
L_0x00491a95:
    // 00491a95  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491a98  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491a9b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00491a9d  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491aa2  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491aa5  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00491aa8  0f88d7000000           -js 0x491b85
    if (cpu.flags.sf)
    {
        goto L_0x00491b85;
    }
    // 00491aae  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 00491ab4  75df                   -jne 0x491a95
    if (!cpu.flags.zf)
    {
        goto L_0x00491a95;
    }
L_0x00491ab6:
    // 00491ab6  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00491ab9  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491abe  7c67                   -jl 0x491b27
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491b27;
    }
L_0x00491ac0:
    // 00491ac0  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00491ac3  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491ac6  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491ac9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491acb  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00491ace  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 00491ad2  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00491ad4  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00491ad6  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00491ad9  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491adc  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00491adf  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00491ae1  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00491ae4  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 00491ae8  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00491aea  8b6a18                 -mov ebp, dword ptr [edx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00491aed  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491af0  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00491af3  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 00491af5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491af7  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00491afa  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 00491afe  8b6a10                 -mov ebp, dword ptr [edx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00491b01  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00491b03  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00491b06  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491b09  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 00491b0c  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00491b0e  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00491b11  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 00491b15  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00491b17  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491b1c  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00491b1f  894f04                 -mov dword ptr [edi + 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00491b22  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00491b25  7999                   -jns 0x491ac0
    if (!cpu.flags.sf)
    {
        goto L_0x00491ac0;
    }
L_0x00491b27:
    // 00491b27  8344241c04             +add dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491b2c  7839                   -js 0x491b67
    if (cpu.flags.sf)
    {
        goto L_0x00491b67;
    }
L_0x00491b2e:
    // 00491b2e  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00491b31  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491b34  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491b37  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491b39  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00491b3c  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 00491b40  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00491b42  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00491b44  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00491b47  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491b4a  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00491b4d  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00491b4f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00491b52  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 00491b56  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00491b58  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 00491b5a  836c241c04             +sub dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491b5f  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00491b62  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00491b65  79c7                   -jns 0x491b2e
    if (!cpu.flags.sf)
    {
        goto L_0x00491b2e;
    }
L_0x00491b67:
    // 00491b67  8344241c03             +add dword ptr [esp + 0x1c], 3
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491b6c  7817                   -js 0x491b85
    if (cpu.flags.sf)
    {
        goto L_0x00491b85;
    }
    // 00491b6e  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
L_0x00491b70:
    // 00491b70  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 00491b73  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491b76  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00491b78  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491b7d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491b80  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00491b83  79eb                   -jns 0x491b70
    if (!cpu.flags.sf)
    {
        goto L_0x00491b70;
    }
L_0x00491b85:
    // 00491b85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b86  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b89  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491b8a:
    // 00491b8a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491b8c  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491b8e  803dd8a64c0010         +cmp byte ptr [0x4ca6d8], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491b95  7f20                   -jg 0x491bb7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00491bb7;
    }
    // 00491b97  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491b9c  78e7                   -js 0x491b85
    if (cpu.flags.sf)
    {
        goto L_0x00491b85;
    }
L_0x00491b9e:
    // 00491b9e  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 00491ba2  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491ba5  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 00491ba8  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491bad  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491bb0  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00491bb3  79e9                   -jns 0x491b9e
    if (!cpu.flags.sf)
    {
        goto L_0x00491b9e;
    }
    // 00491bb5  ebce                   -jmp 0x491b85
    goto L_0x00491b85;
L_0x00491bb7:
    // 00491bb7  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491bbc  78c7                   -js 0x491b85
    if (cpu.flags.sf)
    {
        goto L_0x00491b85;
    }
L_0x00491bbe:
    // 00491bbe  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 00491bc1  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491bc4  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00491bc6  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491bcb  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00491bce  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00491bd1  79eb                   -jns 0x491bbe
    if (!cpu.flags.sf)
    {
        goto L_0x00491bbe;
    }
    // 00491bd3  ebb0                   -jmp 0x491b85
    goto L_0x00491b85;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_491be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491be0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491be1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491be2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491be3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491be4  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00491bea  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00491bec  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 00491bf0  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00491bf2  ff052ca44c00           -inc dword ptr [0x4ca42c]
    (app->getMemory<x86::reg32>(x86::reg32(5022764) /* 0x4ca42c */))++;
    // 00491bf8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491bfa  7505                   -jne 0x491c01
    if (!cpu.flags.zf)
    {
        goto L_0x00491c01;
    }
    // 00491bfc  bd70d35100             -mov ebp, 0x51d370
    cpu.ebp = 5362544 /*0x51d370*/;
L_0x00491c01:
    // 00491c01  833db0a34c0007         +cmp dword ptr [0x4ca3b0], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022640) /* 0x4ca3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491c08  0f8525010000           -jne 0x491d33
    if (!cpu.flags.zf)
    {
        goto L_0x00491d33;
    }
    // 00491c0e  837d1c08               +cmp dword ptr [ebp + 0x1c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491c12  0f8f1b010000           -jg 0x491d33
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00491d33;
    }
    // 00491c18  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00491c1c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00491c1e  48                     -dec eax
    (cpu.eax)--;
    // 00491c1f  8bbd3c040000           -mov edi, dword ptr [ebp + 0x43c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1084) /* 0x43c */);
    // 00491c25  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00491c29  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00491c2b  0f840d010000           -je 0x491d3e
    if (cpu.flags.zf)
    {
        goto L_0x00491d3e;
    }
    // 00491c31  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00491c36:
    // 00491c36  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 00491c3a  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00491c3e  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00491c41  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00491c44  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491c46  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00491c49  05709f5200             -add eax, 0x529f70
    (cpu.eax) += x86::reg32(x86::sreg32(5414768 /*0x529f70*/));
    // 00491c4e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491c50  7e2a                   -jle 0x491c7c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491c7c;
    }
    // 00491c52  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00491c54:
    // 00491c54  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491c56  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00491c59  0fb67802               -movzx edi, byte ptr [eax + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */));
    // 00491c5d  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00491c60  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491c62  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491c64  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00491c66  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491c69  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00491c6c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491c6f  09fb                   -or ebx, edi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00491c71  41                     -inc ecx
    (cpu.ecx)++;
    // 00491c72  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00491c75  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491c77  7cdb                   -jl 0x491c54
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491c54;
    }
    // 00491c79  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00491c7c:
    // 00491c7c  8b852e040000           -mov eax, dword ptr [ebp + 0x42e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1070) /* 0x42e */);
    // 00491c82  8b54247c               -mov edx, dword ptr [esp + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00491c86  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00491c89  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491c8b  7e0b                   -jle 0x491c98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491c98;
    }
    // 00491c8d  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00491c91  66898530040000         -mov word ptr [ebp + 0x430], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(1072) /* 0x430 */) = cpu.ax;
L_0x00491c98:
    // 00491c98  8b8530040000           -mov eax, dword ptr [ebp + 0x430]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1072) /* 0x430 */);
    // 00491c9e  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00491ca2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00491ca5  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491ca7  7d0b                   -jge 0x491cb4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491cb4;
    }
    // 00491ca9  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00491cad  66898532040000         -mov word ptr [ebp + 0x432], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(1074) /* 0x432 */) = cpu.ax;
L_0x00491cb4:
    // 00491cb4  837c247000             +cmp dword ptr [esp + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491cb9  740c                   -je 0x491cc7
    if (cpu.flags.zf)
    {
        goto L_0x00491cc7;
    }
    // 00491cbb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00491cbd  e89e5d0000             -call 0x497a60
    cpu.esp -= 4;
    sub_497a60(app, cpu);
    if (cpu.terminate) return;
    // 00491cc2  e85562feff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
L_0x00491cc7:
    // 00491cc7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00491cc9  e8a26affff             -call 0x488770
    cpu.esp -= 4;
    sub_488770(app, cpu);
    if (cpu.terminate) return;
    // 00491cce  80bd5d04000000         +cmp byte ptr [ebp + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491cd5  7555                   -jne 0x491d2c
    if (!cpu.flags.zf)
    {
        goto L_0x00491d2c;
    }
    // 00491cd7  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00491cdb  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00491cde  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00491ce1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491ce3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491ce5  05709f5200             -add eax, 0x529f70
    (cpu.eax) += x86::reg32(x86::sreg32(5414768 /*0x529f70*/));
    // 00491cea  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491cec  7e3e                   -jle 0x491d2c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491d2c;
    }
L_0x00491cee:
    // 00491cee  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00491cf0  885802                 -mov byte ptr [eax + 2], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00491cf3  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491cf5  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00491cf8  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00491cfe  895c2474               -mov dword ptr [esp + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.ebx;
    // 00491d02  8a5c2474               -mov bl, byte ptr [esp + 0x74]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00491d06  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00491d09  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491d0b  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 00491d0e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00491d14  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491d17  895c2474               -mov dword ptr [esp + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.ebx;
    // 00491d1b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491d1e  8a5c2474               -mov bl, byte ptr [esp + 0x74]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00491d22  41                     -inc ecx
    (cpu.ecx)++;
    // 00491d23  8858fc                 -mov byte ptr [eax - 4], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.bl;
    // 00491d26  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491d28  7cc4                   -jl 0x491cee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491cee;
    }
    // 00491d2a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00491d2c:
    // 00491d2c  837c247000             +cmp dword ptr [esp + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491d31  7512                   -jne 0x491d45
    if (!cpu.flags.zf)
    {
        goto L_0x00491d45;
    }
L_0x00491d33:
    // 00491d33  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00491d39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d3c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491d3e:
    // 00491d3e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00491d40  e9f1feffff             -jmp 0x491c36
    goto L_0x00491c36;
L_0x00491d45:
    // 00491d45  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00491d47  e8385d0000             -call 0x497a84
    cpu.esp -= 4;
    sub_497a84(app, cpu);
    if (cpu.terminate) return;
    // 00491d4c  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00491d52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d53  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d54  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491d58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491d58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491d59  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491d5a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00491d5c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00491d5e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491d60  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
    // 00491d67  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00491d69  81c2709f5200           -add edx, 0x529f70
    (cpu.edx) += x86::reg32(x86::sreg32(5414768 /*0x529f70*/));
    // 00491d6f  e859870000             -call 0x49a4cd
    cpu.esp -= 4;
    sub_49a4cd(app, cpu);
    if (cpu.terminate) return;
    // 00491d74  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00491d79  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00491d7b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00491d7d  e85efeffff             -call 0x491be0
    cpu.esp -= 4;
    sub_491be0(app, cpu);
    if (cpu.terminate) return;
    // 00491d82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_491d88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491d88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491d89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491d8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491d8b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491d8c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00491d8f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00491d93  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00491d96  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00491d99  05709f5200             -add eax, 0x529f70
    (cpu.eax) += x86::reg32(x86::sreg32(5414768 /*0x529f70*/));
L_0x00491d9e:
    // 00491d9e  4a                     -dec edx
    (cpu.edx)--;
    // 00491d9f  83faff                 +cmp edx, -1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491da2  745d                   -je 0x491e01
    if (cpu.flags.zf)
    {
        goto L_0x00491e01;
    }
    // 00491da4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491da6  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 00491da8  8d2c8d00000000         -lea ebp, [ecx*4]
    cpu.ebp = x86::reg32(cpu.ecx * 4);
    // 00491daf  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00491db2  09cd                   -or ebp, ecx
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491db4  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00491db8  0fb67301               -movzx esi, byte ptr [ebx + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */));
    // 00491dbc  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491dc0  0fb67b02               -movzx edi, byte ptr [ebx + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */));
    // 00491dc4  884802                 -mov byte ptr [eax + 2], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 00491dc7  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
    // 00491dce  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 00491dd1  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00491dd3  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00491dd7  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491ddb  884801                 -mov byte ptr [eax + 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00491dde  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 00491de5  43                     -inc ebx
    (cpu.ebx)++;
    // 00491de6  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00491de9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491dec  09f9                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00491dee  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00491def  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00491df3  c640ffff               -mov byte ptr [eax - 1], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = 255 /*0xff*/;
    // 00491df7  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491dfb  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00491dfc  8848fc                 -mov byte ptr [eax - 4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.cl;
    // 00491dff  eb9d                   -jmp 0x491d9e
    goto L_0x00491d9e;
L_0x00491e01:
    // 00491e01  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00491e04  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00491e08  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00491e0d  e8cefdffff             -call 0x491be0
    cpu.esp -= 4;
    sub_491be0(app, cpu);
    if (cpu.terminate) return;
    // 00491e12  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00491e15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_491e1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491e1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491e1d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491e1e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491e20  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00491e22  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491e24  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 00491e2b  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 00491e32  81c2709f5200           -add edx, 0x529f70
    (cpu.edx) += x86::reg32(x86::sreg32(5414768 /*0x529f70*/));
    // 00491e38  e8c3f7feff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00491e3d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00491e42  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00491e44  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00491e46  e895fdffff             -call 0x491be0
    cpu.esp -= 4;
    sub_491be0(app, cpu);
    if (cpu.terminate) return;
    // 00491e4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_491e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491e50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491e51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491e52  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00491e54  b9709f5200             -mov ecx, 0x529f70
    cpu.ecx = 5414768 /*0x529f70*/;
    // 00491e59  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00491e5c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00491e5e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491e60  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491e62  7e20                   -jle 0x491e84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491e84;
    }
    // 00491e64  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00491e66:
    // 00491e66  43                     -inc ebx
    (cpu.ebx)++;
    // 00491e67  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00491e6a  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00491e6d  43                     -inc ebx
    (cpu.ebx)++;
    // 00491e6e  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00491e71  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491e74  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00491e77  43                     -inc ebx
    (cpu.ebx)++;
    // 00491e78  8a48fc                 -mov cl, byte ptr [eax - 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00491e7b  42                     -inc edx
    (cpu.edx)++;
    // 00491e7c  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00491e7f  39f2                   +cmp edx, esi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491e81  7ce3                   -jl 0x491e66
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491e66;
    }
    // 00491e83  90                     -nop 
    ;
L_0x00491e84:
    // 00491e84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491e88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491e88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491e89  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491e8a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00491e8c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00491e8e  b9709f5200             -mov ecx, 0x529f70
    cpu.ecx = 5414768 /*0x529f70*/;
    // 00491e93  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00491e96  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491e98  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491e9a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491e9c  7e12                   -jle 0x491eb0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491eb0;
    }
L_0x00491e9e:
    // 00491e9e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491ea1  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00491ea3  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491ea6  40                     -inc eax
    (cpu.eax)++;
    // 00491ea7  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00491eaa  39f0                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491eac  7cf0                   -jl 0x491e9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491e9e;
    }
    // 00491eae  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00491eb0:
    // 00491eb0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491eb1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491eb2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491eb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491eb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491eb5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491eb6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491eb9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00491ebb  b9709f5200             -mov ecx, 0x529f70
    cpu.ecx = 5414768 /*0x529f70*/;
    // 00491ec0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00491ec3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00491ec5  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491ec7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491ec9  7e41                   -jle 0x491f0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491f0c;
    }
    // 00491ecb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00491ecd:
    // 00491ecd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491ecf  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00491ed2  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 00491ed5  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00491ed8  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 00491edb  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 00491edd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491edf  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00491ee2  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 00491ee5  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00491ee8  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 00491eeb  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00491eee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491ef0  43                     -inc ebx
    (cpu.ebx)++;
    // 00491ef1  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00491ef3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491ef6  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 00491ef9  43                     -inc ebx
    (cpu.ebx)++;
    // 00491efa  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00491efd  43                     -inc ebx
    (cpu.ebx)++;
    // 00491efe  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 00491f01  42                     -inc edx
    (cpu.edx)++;
    // 00491f02  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00491f05  39f2                   +cmp edx, esi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491f07  7cc4                   -jl 0x491ecd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491ecd;
    }
    // 00491f09  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00491f0c:
    // 00491f0c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491f0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f11  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_491f14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491f14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491f15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491f16  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00491f18  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491f1b  780f                   -js 0x491f2c
    if (cpu.flags.sf)
    {
        goto L_0x00491f2c;
    }
L_0x00491f1d:
    // 00491f1d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491f1f  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00491f21  8a1c0a                 -mov bl, byte ptr [edx + ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + cpu.ecx * 1);
    // 00491f24  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00491f26  40                     -inc eax
    (cpu.eax)++;
    // 00491f27  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491f2a  79f1                   -jns 0x491f1d
    if (!cpu.flags.sf)
    {
        goto L_0x00491f1d;
    }
L_0x00491f2c:
    // 00491f2c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_491f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491f30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491f31  8b0d60a44c00           -mov ecx, dword ptr [0x4ca460]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022816) /* 0x4ca460 */);
    // 00491f37  a368a44c00             -mov dword ptr [0x4ca468], eax
    app->getMemory<x86::reg32>(x86::reg32(5022824) /* 0x4ca468 */) = cpu.eax;
    // 00491f3c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00491f3e  a370a44c00             -mov dword ptr [0x4ca470], eax
    app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */) = cpu.eax;
    // 00491f43  a164a44c00             -mov eax, dword ptr [0x4ca464]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022820) /* 0x4ca464 */);
    // 00491f48  89156ca44c00           -mov dword ptr [0x4ca46c], edx
    app->getMemory<x86::reg32>(x86::reg32(5022828) /* 0x4ca46c */) = cpu.edx;
    // 00491f4e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491f50  891574a44c00           -mov dword ptr [0x4ca474], edx
    app->getMemory<x86::reg32>(x86::reg32(5022836) /* 0x4ca474 */) = cpu.edx;
    // 00491f56  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491f58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491f58  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491f59  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491f5a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00491f5c  891588a44c00           -mov dword ptr [0x4ca488], edx
    app->getMemory<x86::reg32>(x86::reg32(5022856) /* 0x4ca488 */) = cpu.edx;
    // 00491f62  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 00491f64  8b1568a44c00           -mov edx, dword ptr [0x4ca468]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022824) /* 0x4ca468 */);
    // 00491f6a  a384a44c00             -mov dword ptr [0x4ca484], eax
    app->getMemory<x86::reg32>(x86::reg32(5022852) /* 0x4ca484 */) = cpu.eax;
    // 00491f6f  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00491f71  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00491f73  891570a44c00           -mov dword ptr [0x4ca470], edx
    app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */) = cpu.edx;
    // 00491f79  8b156ca44c00           -mov edx, dword ptr [0x4ca46c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022828) /* 0x4ca46c */);
    // 00491f7f  891d60a44c00           -mov dword ptr [0x4ca460], ebx
    app->getMemory<x86::reg32>(x86::reg32(5022816) /* 0x4ca460 */) = cpu.ebx;
    // 00491f85  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00491f87  890d64a44c00           -mov dword ptr [0x4ca464], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022820) /* 0x4ca464 */) = cpu.ecx;
    // 00491f8d  891574a44c00           -mov dword ptr [0x4ca474], edx
    app->getMemory<x86::reg32>(x86::reg32(5022836) /* 0x4ca474 */) = cpu.edx;
    // 00491f93  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00491f99  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 00491f9c  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00491f9e  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491fa0  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00491fa2  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491fa4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00491fa9  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491fab  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00491fb2  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00491fb4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00491fb6  8b1d60a44c00           -mov ebx, dword ptr [0x4ca460]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022816) /* 0x4ca460 */);
    // 00491fbc  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00491fbf  a184a44c00             -mov eax, dword ptr [0x4ca484]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022852) /* 0x4ca484 */);
    // 00491fc4  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 00491fc7  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00491fc9  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491fcb  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00491fcd  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491fcf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00491fd4  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491fd6  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00491fdd  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00491fdf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00491fe1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491fe3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00491fe5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491fe7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00491fea  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00491fec  a378a44c00             -mov dword ptr [0x4ca478], eax
    app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */) = cpu.eax;
    // 00491ff1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491ff3  746a                   -je 0x49205f
    if (cpu.flags.zf)
    {
        goto L_0x0049205f;
    }
    // 00491ff5  a188a44c00             -mov eax, dword ptr [0x4ca488]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022856) /* 0x4ca488 */);
    // 00491ffa  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00492000  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 00492003  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00492005  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00492007  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00492009  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049200b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492010  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00492012  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00492019  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049201b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049201d  8b1564a44c00           -mov edx, dword ptr [0x4ca464]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022820) /* 0x4ca464 */);
    // 00492023  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00492025  0fafda                 -imul ebx, edx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00492028  a188a44c00             -mov eax, dword ptr [0x4ca488]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022856) /* 0x4ca488 */);
    // 0049202d  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 00492030  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00492032  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00492034  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00492036  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00492038  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049203d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049203f  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00492046  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00492048  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049204a  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0049204c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049204e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00492050  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00492052  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00492055  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00492057  a37ca44c00             -mov dword ptr [0x4ca47c], eax
    app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */) = cpu.eax;
    // 0049205c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049205d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049205e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049205f:
    // 0049205f  8b158ca44c00           -mov edx, dword ptr [0x4ca48c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022860) /* 0x4ca48c */);
    // 00492065  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00492067  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049206a  c1e810                 +shr eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0049206d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049206f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00492071  8b1564a44c00           -mov edx, dword ptr [0x4ca464]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022820) /* 0x4ca464 */);
    // 00492077  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 00492079  a37ca44c00             -mov dword ptr [0x4ca47c], eax
    app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */) = cpu.eax;
    // 0049207e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00492080  892d7ca44c00           -mov dword ptr [0x4ca47c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */) = cpu.ebp;
    // 00492086  e835c0ffff             -call 0x48e0c0
    cpu.esp -= 4;
    sub_48e0c0(app, cpu);
    if (cpu.terminate) return;
    // 0049208b  a388a44c00             -mov dword ptr [0x4ca488], eax
    app->getMemory<x86::reg32>(x86::reg32(5022856) /* 0x4ca488 */) = cpu.eax;
    // 00492090  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492091  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492092  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_492094(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492094  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492095  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492096  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492098  c1e20a                 -shl edx, 0xa
    cpu.edx <<= 10 /*0xa*/ % 32;
    // 0049209b  be68010000             -mov esi, 0x168
    cpu.esi = 360 /*0x168*/;
    // 004920a0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004920a2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004920a5  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004920a7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004920a9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004920ab  c1e20a                 -shl edx, 0xa
    cpu.edx <<= 10 /*0xa*/ % 32;
    // 004920ae  bf68010000             -mov edi, 0x168
    cpu.edi = 360 /*0x168*/;
    // 004920b3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004920b5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004920b8  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004920ba  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004920bc  e897feffff             -call 0x491f58
    cpu.esp -= 4;
    sub_491f58(app, cpu);
    if (cpu.terminate) return;
    // 004920c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004920c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004920c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4920c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004920c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004920c5  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004920c9  7e46                   -jle 0x492111
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492111;
    }
    // 004920cb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004920cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004920cd  8b0d78a44c00           -mov ecx, dword ptr [0x4ca478]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */);
    // 004920d3  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004920d5  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004920d8  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004920db  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004920dd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004920e0  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004920e2  8b1570a44c00           -mov edx, dword ptr [0x4ca470]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */);
    // 004920e8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004920ea  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004920ec  8b2d7ca44c00           -mov ebp, dword ptr [0x4ca47c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */);
    // 004920f2  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004920f5  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004920f8  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004920fb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004920fd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00492100  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00492102  8b1574a44c00           -mov edx, dword ptr [0x4ca474]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022836) /* 0x4ca474 */);
    // 00492108  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049210a  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049210d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049210e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049210f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492110  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492111:
    // 00492111  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 00492118  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049211b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0049211d  800d80a44c0001         -or byte ptr [0x4ca480], 1
    app->getMemory<x86::reg8>(x86::reg32(5022848) /* 0x4ca480 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00492124  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492125  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_492130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492130  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492131  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492132  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492133  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492134  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492135  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492136  bab81c4d00             -mov edx, 0x4d1cb8
    cpu.edx = 5053624 /*0x4d1cb8*/;
    // 0049213b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049213d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049213f:
    // 0049213f  83bf54c94c0000         +cmp dword ptr [edi + 0x4cc954], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5032276) /* 0x4cc954 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492146  743a                   -je 0x492182
    if (cpu.flags.zf)
    {
        goto L_0x00492182;
    }
L_0x00492148:
    // 00492148  43                     -inc ebx
    (cpu.ebx)++;
    // 00492149  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049214c  83fb0a                 +cmp ebx, 0xa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049214f  7cee                   -jl 0x49213f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049213f;
    }
    // 00492151  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00492154  2db81c4d00             -sub eax, 0x4d1cb8
    (cpu.eax) -= x86::reg32(x86::sreg32(5053624 /*0x4d1cb8*/));
    // 00492159  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0049215c  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049215f  a37cc94c00             -mov dword ptr [0x4cc97c], eax
    app->getMemory<x86::reg32>(x86::reg32(5032316) /* 0x4cc97c */) = cpu.eax;
    // 00492164  b81f855200             -mov eax, 0x52851f
    cpu.eax = 5408031 /*0x52851f*/;
    // 00492169  24e0                   -and al, 0xe0
    cpu.al &= x86::reg8(x86::sreg8(224 /*0xe0*/));
    // 0049216b  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00492171  a348c94c00             -mov dword ptr [0x4cc948], eax
    app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */) = cpu.eax;
    // 00492176  e805230100             -call 0x4a4480
    cpu.esp -= 4;
    sub_4a4480(app, cpu);
    if (cpu.terminate) return;
    // 0049217b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049217c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049217d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049217e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049217f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492180  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492181  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492182:
    // 00492182  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00492188  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049218b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00492190  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00492192  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 00492194  2db81c4d00             -sub eax, 0x4d1cb8
    (cpu.eax) -= x86::reg32(x86::sreg32(5053624 /*0x4d1cb8*/));
    // 00492199  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0049219b  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0049219e  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004921a1  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004921a4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004921a7  898754c94c00           -mov dword ptr [edi + 0x4cc954], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5032276) /* 0x4cc954 */) = cpu.eax;
    // 004921ad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004921af  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004921b1  7e95                   -jle 0x492148
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492148;
    }
    // 004921b3  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
L_0x004921b5:
    // 004921b5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004921b7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004921ba  d3e5                   -shl ebp, cl
    cpu.ebp <<= cpu.cl % 32;
    // 004921bc  40                     -inc eax
    (cpu.eax)++;
    // 004921bd  896afc                 -mov dword ptr [edx - 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 004921c0  39f0                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004921c2  7d84                   -jge 0x492148
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492148;
    }
    // 004921c4  ebef                   -jmp 0x4921b5
    goto L_0x004921b5;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4921c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004921c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004921c9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004921ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004921cb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004921cc  8b2d288f5200           -mov ebp, dword ptr [0x528f28]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5410600) /* 0x528f28 */);
    // 004921d2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004921d4  8b0d2c8f5200           -mov ecx, dword ptr [0x528f2c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5410604) /* 0x528f2c */);
    // 004921da  42                     -inc edx
    (cpu.edx)++;
    // 004921db  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004921dd  751c                   -jne 0x4921fb
    if (!cpu.flags.zf)
    {
        goto L_0x004921fb;
    }
    // 004921df  39ea                   +cmp edx, ebp
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004921e1  7e0d                   -jle 0x4921f0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004921f0;
    }
    // 004921e3  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004921e5  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004921e8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004921ea  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004921ec  39e8                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004921ee  7c26                   -jl 0x492216
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492216;
    }
L_0x004921f0:
    // 004921f0  892d288f5200           -mov dword ptr [0x528f28], ebp
    app->getMemory<x86::reg32>(x86::reg32(5410600) /* 0x528f28 */) = cpu.ebp;
    // 004921f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004921f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004921f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004921f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004921fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004921fb:
    // 004921fb  891d2c8f5200           -mov dword ptr [0x528f2c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5410604) /* 0x528f2c */) = cpu.ebx;
    // 00492201  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00492203  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492205  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00492207  39e8                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492209  7c0b                   -jl 0x492216
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492216;
    }
    // 0049220b  892d288f5200           -mov dword ptr [0x528f28], ebp
    app->getMemory<x86::reg32>(x86::reg32(5410600) /* 0x528f28 */) = cpu.ebp;
    // 00492211  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492212  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492213  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492214  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492215  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492216:
    // 00492216  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492217  8b157cc94c00           -mov edx, dword ptr [0x4cc97c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032316) /* 0x4cc97c */);
    // 0049221d  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 00492224  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00492227  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00492229  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049222c  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049222e  81c2b81c4d00           -add edx, 0x4d1cb8
    (cpu.edx) += x86::reg32(x86::sreg32(5053624 /*0x4d1cb8*/));
    // 00492234  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492236  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492238  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049223a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049223c  892d288f5200           -mov dword ptr [0x528f28], ebp
    app->getMemory<x86::reg32>(x86::reg32(5410600) /* 0x528f28 */) = cpu.ebp;
L_0x00492242:
    // 00492242  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00492244  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492246  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00492249  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049224b  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049224e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492250  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00492253  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492255  8d5b10                 -lea ebx, [ebx + 0x10]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00492258  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049225b  7fe5                   -jg 0x492242
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00492242;
    }
    // 0049225d  8b2d288f5200           -mov ebp, dword ptr [0x528f28]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5410600) /* 0x528f28 */);
    // 00492263  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492264  892d288f5200           -mov dword ptr [0x528f28], ebp
    app->getMemory<x86::reg32>(x86::reg32(5410600) /* 0x528f28 */) = cpu.ebp;
    // 0049226a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049226b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049226c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049226d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049226e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_492270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492270  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492271  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492272  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492273  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00492276  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00492278  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049227a  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049227e  a1dca64c00             -mov eax, dword ptr [0x4ca6dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 00492283  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00492285  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00492288  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049228b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049228d  8b0de4a64c00           -mov ecx, dword ptr [0x4ca6e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023460) /* 0x4ca6e4 */);
    // 00492293  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00492295  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00492297  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00492299  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0049229f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004922a1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004922a4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004922a6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004922a9  0310                   -add edx, dword ptr [eax]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 004922ab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004922ad  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004922af  8b35b01c4d00           -mov esi, dword ptr [0x4d1cb0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5053616) /* 0x4d1cb0 */);
    // 004922b5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004922b7  8a25d8a64c00           -mov ah, byte ptr [0x4ca6d8]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 004922bd  83ee10                 -sub esi, 0x10
    (cpu.esi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004922c0  80fc10                 +cmp ah, 0x10
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004922c3  7733                   -ja 0x4922f8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004922f8;
    }
    // 004922c5  80fc08                 +cmp ah, 8
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004922c8  7602                   -jbe 0x4922cc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004922cc;
    }
    // 004922ca  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
L_0x004922cc:
    // 004922cc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004922ce  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004922d2  e8f9210100             -call 0x4a44d0
    cpu.esp -= 4;
    sub_4a44d0(app, cpu);
    if (cpu.terminate) return;
    // 004922d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004922d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004922d9  a1a81c4d00             -mov eax, dword ptr [0x4d1ca8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5053608) /* 0x4d1ca8 */);
    // 004922de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004922df  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004922e1  8b0da01c4d00           -mov ecx, dword ptr [0x4d1ca0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5053600) /* 0x4d1ca0 */);
    // 004922e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004922e8  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004922ea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004922ec  e81f240100             -call 0x4a4710
    cpu.esp -= 4;
    sub_4a4710(app, cpu);
    if (cpu.terminate) return;
    // 004922f1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004922f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004922f8:
    // 004922f8  c1fa02                 +sar edx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004922fb  ebcf                   -jmp 0x4922cc
    goto L_0x004922cc;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492300  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492301  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492302  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492303  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00492306  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049230a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049230c  8d1ccd00000000         -lea ebx, [ecx*8]
    cpu.ebx = x86::reg32(cpu.ecx * 8);
    // 00492313  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00492316  8d1ced00000000         -lea ebx, [ebp*8]
    cpu.ebx = x86::reg32(cpu.ebp * 8);
    // 0049231d  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00492321  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00492324  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492328  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049232b  3b5f04                 +cmp ebx, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049232e  7e06                   -jle 0x492336
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492336;
    }
    // 00492330  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492332  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00492334  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x00492336:
    // 00492336  c1e503                 -shl ebp, 3
    cpu.ebp <<= 3 /*0x3*/ % 32;
    // 00492339  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0049233c  8d3c2a                 -lea edi, [edx + ebp]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0049233f  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00492341  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00492345  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00492348  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049234b  29d9                   +sub ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049234d  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00492350  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00492353  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00492356  7509                   -jne 0x492361
    if (!cpu.flags.zf)
    {
        goto L_0x00492361;
    }
    // 00492358  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049235b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049235c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049235d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049235e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00492361:
    // 00492361  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00492363  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00492366  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00492369  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049236b  2b1a                   -sub ebx, dword ptr [edx]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049236d  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00492370  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00492374  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00492378  d80c8d80505400         -fmul dword ptr [ecx*4 + 0x545080]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5525632) /* 0x545080 */ + cpu.ecx * 4));
    // 0049237f  d90550c94c00           -fld dword ptr [0x4cc950]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5032272) /* 0x4cc950 */)));
    // 00492385  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492387  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00492389  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049238b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049238d  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00492390  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492394  8b1c2e                 -mov ebx, dword ptr [esi + ebp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 1);
    // 00492397  8b3c32                 -mov edi, dword ptr [edx + esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 1);
    // 0049239a  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049239c  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004923a0  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 004923a4  d80c8d80505400         -fmul dword ptr [ecx*4 + 0x545080]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5525632) /* 0x545080 */ + cpu.ecx * 4));
    // 004923ab  d95810                 -fstp dword ptr [eax + 0x10]
    app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004923ae  8b5c2e04               -mov ebx, dword ptr [esi + ebp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 004923b2  8b6c3204               -mov ebp, dword ptr [edx + esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 004923b6  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004923b8  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004923bc  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 004923c0  d80c8d80505400         -fmul dword ptr [ecx*4 + 0x545080]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5525632) /* 0x545080 */ + cpu.ecx * 4));
    // 004923c7  d95814                 -fstp dword ptr [eax + 0x14]
    app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004923ca  db0432                 -fild dword ptr [edx + esi]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 1))));
    // 004923cd  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004923cf  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004923d1  db443204               -fild dword ptr [edx + esi + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.esi * 1))));
    // 004923d5  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004923d7  dd5808                 -fstp qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004923da  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004923dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004923de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004923df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004923e0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4923e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004923e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004923e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004923e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004923e7  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004923ea  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004923ee  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004923f0  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004923f4  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004923f8  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004923ff  a1e8a64c00             -mov eax, dword ptr [0x4ca6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 00492404  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492406  8b15dca64c00           -mov edx, dword ptr [0x4ca6dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 0049240c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049240e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492410  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00492414  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049241b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049241d  8b3d48c94c00           -mov edi, dword ptr [0x4cc948]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 00492423  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00492426  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00492428  8d3407                 -lea esi, [edi + eax]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0049242b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00492432  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492434  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00492437  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492439  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0049243c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00492440:
    // 00492440  837f2400               +cmp dword ptr [edi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492444  0f8ead000000           -jle 0x4924f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004924f7;
    }
    // 0049244a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0049244e:
    // 0049244e  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00492451  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00492453  0f8ee2000000           -jle 0x49253b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049253b;
    }
    // 00492459  8b4724                 -mov eax, dword ptr [edi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0049245c  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049245e  0f8d0e010000           -jge 0x492572
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492572;
    }
L_0x00492464:
    // 00492464  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00492467  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00492469  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049246d  895724                 -mov dword ptr [edi + 0x24], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00492470  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00492474  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00492477  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492479  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049247b  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0049247f  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00492482  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x00492484:
    // 00492484  74ba                   -je 0x492440
    if (cpu.flags.zf)
    {
        goto L_0x00492440;
    }
    // 00492486  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00492489  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0049248c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049248e  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 00492494  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00492496  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00492499  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049249b  0f8fd8000000           -jg 0x492579
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00492579;
    }
    // 004924a1  0f8c29010000           -jl 0x4925d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004925d0;
    }
L_0x004924a7:
    // 004924a7  d94610                 -fld dword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 004924aa  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004924ae  a1e4a64c00             -mov eax, dword ptr [0x4ca6e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023460) /* 0x4ca6e4 */);
    // 004924b3  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004924b6  dc06                   -fadd qword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi));
    // 004924b8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004924ba  dd1e                   -fstp qword ptr [esi]
    app->getMemory<double>(cpu.esi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004924bc  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004924bf  d94614                 -fld dword ptr [esi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(20) /* 0x14 */)));
    // 004924c2  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004924c4  dc4608                 -fadd qword ptr [esi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 004924c7  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004924ca  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004924ce  dd5e08                 -fstp qword ptr [esi + 8]
    app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004924d1  d94710                 -fld dword ptr [edi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 004924d4  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 004924d7  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004924da  dc07                   -fadd qword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi));
    // 004924dc  01c3                   +add ebx, eax
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004924de  dd1f                   +fstp qword ptr [edi]
    app->getMemory<double>(cpu.edi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004924e0  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004924e3  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004924e7  d94714                 +fld dword ptr [edi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */)));
    // 004924ea  dc4708                 +fadd qword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 004924ed  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004924ee  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004924f2  dd5f08                 +fstp qword ptr [edi + 8]
    app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004924f5  eb8d                   -jmp 0x492484
    goto L_0x00492484;
L_0x004924f7:
    // 004924f7  4d                     -dec ebp
    (cpu.ebp)--;
    // 004924f8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004924fa  7c22                   -jl 0x49251e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049251e;
    }
    // 004924fc  83ef28                 -sub edi, 0x28
    (cpu.edi) -= x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x004924ff:
    // 004924ff  3b6c241c               +cmp ebp, dword ptr [esp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492503  742a                   -je 0x49252f
    if (cpu.flags.zf)
    {
        goto L_0x0049252f;
    }
    // 00492505  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00492509  3b4720                 +cmp eax, dword ptr [edi + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049250c  0f8e2effffff           -jle 0x492440
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492440;
    }
    // 00492512  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00492517  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049251a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049251b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049251c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049251d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049251e:
    // 0049251e  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492522  6bc528                 -imul eax, ebp, 0x28
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 00492525  8b3d48c94c00           -mov edi, dword ptr [0x4cc948]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 0049252b  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049252d  ebd0                   -jmp 0x4924ff
    goto L_0x004924ff;
L_0x0049252f:
    // 0049252f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00492534  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00492537  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492538  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492539  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049253a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049253b:
    // 0049253b  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049253f  40                     -inc eax
    (cpu.eax)++;
    // 00492540  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00492544  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492546  7c25                   -jl 0x49256d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049256d;
    }
    // 00492548  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049254a  8b3548c94c00           -mov esi, dword ptr [0x4cc948]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 00492550  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
L_0x00492554:
    // 00492554  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00492558  3b4620                 +cmp eax, dword ptr [esi + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049255b  0f8eedfeffff           -jle 0x49244e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049244e;
    }
    // 00492561  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00492566  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00492569  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049256a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049256b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049256c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049256d:
    // 0049256d  83c628                 +add esi, 0x28
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00492570  ebe2                   -jmp 0x492554
    goto L_0x00492554;
L_0x00492572:
    // 00492572  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00492574  e9ebfeffff             -jmp 0x492464
    goto L_0x00492464;
L_0x00492579:
    // 00492579  d9048580505400         -fld dword ptr [eax*4 + 0x545080]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5525632) /* 0x545080 */ + cpu.eax * 4)));
    // 00492580  dd07                   -fld qword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi)));
    // 00492582  dc26                   -fsub qword ptr [esi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi));
    // 00492584  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00492586  d90550c94c00           -fld dword ptr [0x4cc950]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5032272) /* 0x4cc950 */)));
    // 0049258c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049258e  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00492590  dd1da01c4d00           -fstp qword ptr [0x4d1ca0]
    app->getMemory<double>(x86::reg32(5053600) /* 0x4d1ca0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492596  dd4708                 -fld qword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 00492599  dc6608                 -fsub qword ptr [esi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 0049259c  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049259e  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004925a2  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 004925a8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004925aa  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004925ad  dd1da81c4d00           -fstp qword ptr [0x4d1ca8]
    app->getMemory<double>(x86::reg32(5053608) /* 0x4d1ca8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004925b3  031c8a                 +add ebx, dword ptr [edx + ecx*4]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004925b6  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004925b8  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004925bb  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004925bf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004925c1  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004925c5  ff1580c94c00           -call dword ptr [0x4cc980]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032320) /* 0x4cc980 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004925cb  e9d7feffff             -jmp 0x4924a7
    goto L_0x004924a7;
L_0x004925d0:
    // 004925d0  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004925d3  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004925d6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004925d8  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 004925de  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004925e0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004925e3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004925e5  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004925e8  7d05                   -jge 0x4925ef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004925ef;
    }
    // 004925ea  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004925ef:
    // 004925ef  d9048d80505400         -fld dword ptr [ecx*4 + 0x545080]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5525632) /* 0x545080 */ + cpu.ecx * 4)));
    // 004925f6  dd06                   -fld qword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi)));
    // 004925f8  dc27                   -fsub qword ptr [edi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi));
    // 004925fa  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004925fc  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 00492602  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00492604  d90550c94c00           -fld dword ptr [0x4cc950]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5032272) /* 0x4cc950 */)));
    // 0049260a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049260c  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0049260e  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492612  dd1da01c4d00           -fstp qword ptr [0x4d1ca0]
    app->getMemory<double>(x86::reg32(5053600) /* 0x4d1ca0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492618  dd4608                 -fld qword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0049261b  dc6708                 -fsub qword ptr [edi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 0049261e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00492621  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00492623  031c82                 +add ebx, dword ptr [edx + eax*4]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00492626  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00492629  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049262b  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049262d  dd1da81c4d00           +fstp qword ptr [0x4d1ca8]
    app->getMemory<double>(x86::reg32(5053608) /* 0x4d1ca8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492633  ff1580c94c00           -call dword ptr [0x4cc980]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032320) /* 0x4cc980 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492639  e969feffff             -jmp 0x4924a7
    goto L_0x004924a7;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_492640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492640  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492641  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492642  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492643  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00492646  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049264a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049264c  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00492650  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00492654  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0049265b  a1e8a64c00             -mov eax, dword ptr [0x4ca6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 00492660  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492662  8b15dca64c00           -mov edx, dword ptr [0x4ca6dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 00492668  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049266a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049266c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049266e  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00492672  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00492679  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049267b  8b3d48c94c00           -mov edi, dword ptr [0x4cc948]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 00492681  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00492684  8d3407                 -lea esi, [edi + eax]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 1);
    // 00492687  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049268e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00492690  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00492693  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492695  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00492698  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0049269c:
    // 0049269c  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004926a0  0f8efe000000           -jle 0x4927a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004927a4;
    }
    // 004926a6  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x004926aa:
    // 004926aa  8b4f24                 -mov ecx, dword ptr [edi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 004926ad  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004926af  0f8433010000           -je 0x4927e8
    if (cpu.flags.zf)
    {
        goto L_0x004927e8;
    }
    // 004926b5  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004926b8  39d9                   +cmp ecx, ebx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004926ba  0f8d5d010000           -jge 0x49281d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049281d;
    }
    // 004926c0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004926c2:
    // 004926c2  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 004926c5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004926c7  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004926cb  895724                 -mov dword ptr [edi + 0x24], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004926ce  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004926d2  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004926d5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004926d7  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004926d9  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004926dd  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004926e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x004926e2:
    // 004926e2  74b8                   -je 0x49269c
    if (cpu.flags.zf)
    {
        goto L_0x0049269c;
    }
    // 004926e4  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004926e7  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004926ea  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004926ec  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 004926f2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004926f4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004926f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004926f9  0f8e25010000           -jle 0x492824
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492824;
    }
    // 004926ff  d9048580505400         -fld dword ptr [eax*4 + 0x545080]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5525632) /* 0x545080 */ + cpu.eax * 4)));
    // 00492706  dd07                   -fld qword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi)));
    // 00492708  dc26                   -fsub qword ptr [esi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi));
    // 0049270a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049270c  d90550c94c00           -fld dword ptr [0x4cc950]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5032272) /* 0x4cc950 */)));
    // 00492712  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492714  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00492716  dd1da01c4d00           -fstp qword ptr [0x4d1ca0]
    app->getMemory<double>(x86::reg32(5053600) /* 0x4d1ca0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049271c  dd4708                 -fld qword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 0049271f  dc6608                 -fsub qword ptr [esi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 00492722  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00492724  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492728  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0049272e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00492730  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00492733  dd1da81c4d00           -fstp qword ptr [0x4d1ca8]
    app->getMemory<double>(x86::reg32(5053608) /* 0x4d1ca8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492739  031c8a                 -add ebx, dword ptr [edx + ecx*4]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4)));
    // 0049273c  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049273e  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00492741  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00492745  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00492747  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x0049274b:
    // 0049274b  ff1580c94c00           -call dword ptr [0x4cc980]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032320) /* 0x4cc980 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00492751:
    // 00492751  d94610                 -fld dword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 00492754  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492758  a1e4a64c00             -mov eax, dword ptr [0x4ca6e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023460) /* 0x4ca6e4 */);
    // 0049275d  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00492760  dc06                   -fadd qword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi));
    // 00492762  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492764  dd1e                   -fstp qword ptr [esi]
    app->getMemory<double>(cpu.esi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492766  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00492769  d94614                 -fld dword ptr [esi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(20) /* 0x14 */)));
    // 0049276c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049276e  dc4608                 -fadd qword ptr [esi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 00492771  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00492774  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00492778  dd5e08                 -fstp qword ptr [esi + 8]
    app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049277b  d94710                 -fld dword ptr [edi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 0049277e  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 00492781  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00492784  dc07                   -fadd qword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi));
    // 00492786  01c3                   +add ebx, eax
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00492788  dd1f                   +fstp qword ptr [edi]
    app->getMemory<double>(cpu.edi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049278a  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049278d  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00492791  d94714                 +fld dword ptr [edi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */)));
    // 00492794  dc4708                 +fadd qword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 00492797  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00492798  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049279c  dd5f08                 +fstp qword ptr [edi + 8]
    app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049279f  e93effffff             -jmp 0x4926e2
    goto L_0x004926e2;
L_0x004927a4:
    // 004927a4  4d                     -dec ebp
    (cpu.ebp)--;
    // 004927a5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004927a7  7c22                   -jl 0x4927cb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004927cb;
    }
    // 004927a9  83ee28                 -sub esi, 0x28
    (cpu.esi) -= x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x004927ac:
    // 004927ac  3b6c241c               +cmp ebp, dword ptr [esp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004927b0  742a                   -je 0x4927dc
    if (cpu.flags.zf)
    {
        goto L_0x004927dc;
    }
    // 004927b2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004927b6  3b4620                 +cmp eax, dword ptr [esi + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004927b9  0f8eddfeffff           -jle 0x49269c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049269c;
    }
    // 004927bf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004927c4  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004927c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927ca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004927cb:
    // 004927cb  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004927cf  6bc528                 -imul eax, ebp, 0x28
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 004927d2  8b3548c94c00           -mov esi, dword ptr [0x4cc948]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 004927d8  01c6                   +add esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004927da  ebd0                   -jmp 0x4927ac
    goto L_0x004927ac;
L_0x004927dc:
    // 004927dc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004927e1  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004927e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004927e8:
    // 004927e8  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004927ec  40                     -inc eax
    (cpu.eax)++;
    // 004927ed  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004927f1  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004927f3  7c23                   -jl 0x492818
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492818;
    }
    // 004927f5  8b3d48c94c00           -mov edi, dword ptr [0x4cc948]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 004927fb  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
L_0x004927ff:
    // 004927ff  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00492803  3b4720                 +cmp eax, dword ptr [edi + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492806  0f8e9efeffff           -jle 0x4926aa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004926aa;
    }
    // 0049280c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00492811  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00492814  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492815  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492816  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492817  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492818:
    // 00492818  83c728                 +add edi, 0x28
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049281b  ebe2                   -jmp 0x4927ff
    goto L_0x004927ff;
L_0x0049281d:
    // 0049281d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049281f  e99efeffff             -jmp 0x4926c2
    goto L_0x004926c2;
L_0x00492824:
    // 00492824  0f8d27ffffff           -jge 0x492751
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492751;
    }
    // 0049282a  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0049282d  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00492830  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00492832  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 00492838  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049283a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049283d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049283f  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492842  7d05                   -jge 0x492849
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492849;
    }
    // 00492844  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x00492849:
    // 00492849  d9048d80505400         -fld dword ptr [ecx*4 + 0x545080]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5525632) /* 0x545080 */ + cpu.ecx * 4)));
    // 00492850  dd06                   -fld qword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi)));
    // 00492852  dc27                   -fsub qword ptr [edi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi));
    // 00492854  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00492856  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0049285c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049285e  d90550c94c00           -fld dword ptr [0x4cc950]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5032272) /* 0x4cc950 */)));
    // 00492864  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492866  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00492868  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049286c  dd1da01c4d00           -fstp qword ptr [0x4d1ca0]
    app->getMemory<double>(x86::reg32(5053600) /* 0x4d1ca0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492872  dd4608                 -fld qword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00492875  dc6708                 -fsub qword ptr [edi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 00492878  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049287b  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049287d  031c82                 +add ebx, dword ptr [edx + eax*4]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00492880  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00492883  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00492885  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00492887  dd1da81c4d00           +fstp qword ptr [0x4d1ca8]
    app->getMemory<double>(x86::reg32(5053608) /* 0x4d1ca8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049288d  e9b9feffff             -jmp 0x49274b
    goto L_0x0049274b;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_492894(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492894  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492895  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492896  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492897  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492898  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492899  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049289a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049289c  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 004928a1  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004928a4  e867810000             -call 0x49aa10
    cpu.esp -= 4;
    sub_49aa10(app, cpu);
    if (cpu.terminate) return;
    // 004928a9  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004928ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004928ae  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004928b0  0fbdc0                 -bsr eax, eax
    if (cpu.eax == 0)
    {
        cpu.flags.zf = 1;
    }
    else
    {
        cpu.flags.zf = 0;
        cpu.eax = x86::reg32(31 - __builtin_clz(cpu.eax));
    }
    // 004928b3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004928b5  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004928bc  892db41c4d00           -mov dword ptr [0x4d1cb4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5053620) /* 0x4d1cb4 */) = cpu.ebp;
    // 004928c2  39c6                   +cmp esi, eax
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004928c4  7e19                   -jle 0x4928df
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004928df;
    }
L_0x004928c6:
    // 004928c6  833db41c4d0000         +cmp dword ptr [0x4d1cb4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5053620) /* 0x4d1cb4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004928cd  7c27                   -jl 0x4928f6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004928f6;
    }
    // 004928cf  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004928d2  890db01c4d00           -mov dword ptr [0x4d1cb0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5053616) /* 0x4d1cb0 */) = cpu.ecx;
    // 004928d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004928d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004928da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004928db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004928dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004928dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004928de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004928df:
    // 004928df  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004928e1  0fbcc0                 -bsf eax, eax
    if (cpu.eax == 0)
    {
        cpu.flags.zf = 1;
    }
    else
    {
        cpu.flags.zf = 0;
        cpu.eax = x86::reg32(__builtin_ctz(cpu.eax));
    }
    // 004928e4  39c3                   +cmp ebx, eax
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004928e6  75de                   -jne 0x4928c6
    if (!cpu.flags.zf)
    {
        goto L_0x004928c6;
    }
    // 004928e8  8b048554c94c00         -mov eax, dword ptr [eax*4 + 0x4cc954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032276) /* 0x4cc954 */ + cpu.eax * 4);
    // 004928ef  a3b41c4d00             -mov dword ptr [0x4d1cb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5053620) /* 0x4d1cb4 */) = cpu.eax;
    // 004928f4  ebd0                   -jmp 0x4928c6
    goto L_0x004928c6;
L_0x004928f6:
    // 004928f6  a17cc94c00             -mov eax, dword ptr [0x4cc97c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032316) /* 0x4cc97c */);
    // 004928fb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004928fd  a3b41c4d00             -mov dword ptr [0x4d1cb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5053620) /* 0x4d1cb4 */) = cpu.eax;
    // 00492902  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492904  e8bff8ffff             -call 0x4921c8
    cpu.esp -= 4;
    sub_4921c8(app, cpu);
    if (cpu.terminate) return;
    // 00492909  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049290c  890db01c4d00           -mov dword ptr [0x4d1cb0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5053616) /* 0x4d1cb0 */) = cpu.ecx;
    // 00492912  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492913  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492914  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492915  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492916  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492917  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492918  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49291c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049291c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049291d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049291e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049291f  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00492922  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00492926  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0049292a  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049292e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00492932  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00492936  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00492938  8b3548c94c00           -mov esi, dword ptr [0x4cc948]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 0049293e  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00492942  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00492946  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00492948  0f8498020000           -je 0x492be6
    if (cpu.flags.zf)
    {
        goto L_0x00492be6;
    }
L_0x0049294e:
    // 0049294e  8b049584c94c00         -mov eax, dword ptr [edx*4 + 0x4cc984]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032324) /* 0x4cc984 */ + cpu.edx * 4);
    // 00492955  a380c94c00             -mov dword ptr [0x4cc980], eax
    app->getMemory<x86::reg32>(x86::reg32(5032320) /* 0x4cc980 */) = cpu.eax;
    // 0049295a  8a25d8a64c00           -mov ah, byte ptr [0x4ca6d8]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 00492960  80fc0f                 +cmp ah, 0xf
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00492963  0f8587020000           -jne 0x492bf0
    if (!cpu.flags.zf)
    {
        goto L_0x00492bf0;
    }
L_0x00492969:
    // 00492969  8b0495a4c94c00         -mov eax, dword ptr [edx*4 + 0x4cc9a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032356) /* 0x4cc9a4 */ + cpu.edx * 4);
    // 00492970  a380c94c00             -mov dword ptr [0x4cc980], eax
    app->getMemory<x86::reg32>(x86::reg32(5032320) /* 0x4cc980 */) = cpu.eax;
L_0x00492975:
    // 00492975  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492979  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049297d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00492982  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00492984  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492988  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 0049298c  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 00492990  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 00492994  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00492997  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00492999  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0049299b  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049299f  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004929a3  39d1                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004929a5  7e3a                   -jle 0x4929e1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004929e1;
    }
    // 004929a7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004929ab  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004929ae:
    // 004929ae  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004929b1  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004929b3  0f8e45020000           -jle 0x492bfe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492bfe;
    }
    // 004929b9  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004929bb  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
L_0x004929bf:
    // 004929bf  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004929c3  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004929c5  39f3                   +cmp ebx, esi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004929c7  0f8d40020000           -jge 0x492c0d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492c0d;
    }
    // 004929cd  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 004929d1  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x004929d5:
    // 004929d5  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004929d9  42                     -inc edx
    (cpu.edx)++;
    // 004929da  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004929dd  39da                   +cmp edx, ebx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004929df  7ccd                   -jl 0x4929ae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004929ae;
    }
L_0x004929e1:
    // 004929e1  3b3dd4a64c00           +cmp edi, dword ptr [0x4ca6d4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004929e7  0f8d37020000           -jge 0x492c24
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492c24;
    }
    // 004929ed  3b2dcca64c00           +cmp ebp, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004929f3  0f8c2b020000           -jl 0x492c24
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492c24;
    }
    // 004929f9  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004929fd  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492a03  0f8d1b020000           -jge 0x492c24
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492c24;
    }
    // 00492a09  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00492a0d  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492a13  0f8c0b020000           -jl 0x492c24
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492c24;
    }
    // 00492a19  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00492a1d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00492a1f  7554                   -jne 0x492a75
    if (!cpu.flags.zf)
    {
        goto L_0x00492a75;
    }
    // 00492a21  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492a25  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00492a28  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00492a2b  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 00492a2f  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00492a33:
    // 00492a33  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00492a37  3b44241c               +cmp eax, dword ptr [esp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492a3b  7d38                   -jge 0x492a75
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492a75;
    }
    // 00492a3d  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00492a41  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492a45  8d5e08                 -lea ebx, [esi + 8]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00492a48  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492a4a  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 00492a4e  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00492a51  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00492a54  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00492a56  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00492a59  2b4608                 -sub eax, dword ptr [esi + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00492a5c  2b5e0c                 -sub ebx, dword ptr [esi + 0xc]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 00492a5f  2b4e08                 -sub ecx, dword ptr [esi + 8]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00492a62  2b560c                 -sub edx, dword ptr [esi + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 00492a65  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00492a68  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00492a6b  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00492a6d  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 00492a71  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00492a73  74be                   -je 0x492a33
    if (cpu.flags.zf)
    {
        goto L_0x00492a33;
    }
L_0x00492a75:
    // 00492a75  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00492a79  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492a7f  0f8caa010000           -jl 0x492c2f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492c2f;
    }
L_0x00492a85:
    // 00492a85  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00492a89  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492a8f  0f8dc1010000           -jge 0x492c56
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492c56;
    }
L_0x00492a95:
    // 00492a95  3b3dcca64c00           +cmp edi, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492a9b  0f8cdc010000           -jl 0x492c7d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492c7d;
    }
L_0x00492aa1:
    // 00492aa1  3b2dd4a64c00           +cmp ebp, dword ptr [0x4ca6d4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492aa7  0f8df7010000           -jge 0x492ca4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492ca4;
    }
    // 00492aad  837c241400             +cmp dword ptr [esp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492ab2  746c                   -je 0x492b20
    if (cpu.flags.zf)
    {
        goto L_0x00492b20;
    }
L_0x00492ab4:
    // 00492ab4  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492ab8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492abc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00492abe  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00492ac3  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00492ac7  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00492acb  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00492acf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00492ad1  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00492ad4  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00492ad8  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00492adc  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492ae0  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00492ae2  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492ae4  7e3a                   -jle 0x492b20
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492b20;
    }
    // 00492ae6  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492aea  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00492aed:
    // 00492aed  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00492af0  39df                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492af2  0f8ed5010000           -jle 0x492ccd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492ccd;
    }
    // 00492af8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00492afa  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
L_0x00492afe:
    // 00492afe  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00492b02  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00492b04  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492b06  0f8dd0010000           -jge 0x492cdc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492cdc;
    }
    // 00492b0c  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 00492b10  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x00492b14:
    // 00492b14  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492b18  42                     -inc edx
    (cpu.edx)++;
    // 00492b19  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00492b1c  39ca                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492b1e  7ccd                   -jl 0x492aed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492aed;
    }
L_0x00492b20:
    // 00492b20  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492b22  0f8dcb010000           -jge 0x492cf3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492cf3;
    }
    // 00492b28  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492b2c  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492b30  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00492b32  48                     -dec eax
    (cpu.eax)--;
    // 00492b33  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00492b35  7e29                   -jle 0x492b60
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492b60;
    }
    // 00492b37  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00492b39:
    // 00492b39  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492b3d  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492b41  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00492b42  a148c94c00             -mov eax, dword ptr [0x4cc948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 00492b47  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00492b49  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492b4b  e8b0f7ffff             -call 0x492300
    cpu.esp -= 4;
    sub_492300(app, cpu);
    if (cpu.terminate) return;
    // 00492b50  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492b54  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492b56  46                     -inc esi
    (cpu.esi)++;
    // 00492b57  83c528                 -add ebp, 0x28
    (cpu.ebp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00492b5a  39ce                   +cmp esi, ecx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492b5c  7cdb                   -jl 0x492b39
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492b39;
    }
    // 00492b5e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00492b60:
    // 00492b60  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00492b64  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00492b67  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492b6b  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00492b6f  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492b71  7c06                   -jl 0x492b79
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492b79;
    }
    // 00492b73  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00492b75  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
L_0x00492b79:
    // 00492b79  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492b7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492b7f  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00492b81  a0d9a64c00             -mov al, byte ptr [0x4ca6d9]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023449) /* 0x4ca6d9 */);
    // 00492b86  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492b8c  39c2                   +cmp edx, eax
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492b8e  7415                   -je 0x492ba5
    if (cpu.flags.zf)
    {
        goto L_0x00492ba5;
    }
    // 00492b90  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00492b92  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00492b94  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492b98  e8db440000             -call 0x497078
    cpu.esp -= 4;
    sub_497078(app, cpu);
    if (cpu.terminate) return;
    // 00492b9d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00492ba1  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00492ba5:
    // 00492ba5  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492ba9  e8e6fcffff             -call 0x492894
    cpu.esp -= 4;
    sub_492894(app, cpu);
    if (cpu.terminate) return;
    // 00492bae  837c244c00             +cmp dword ptr [esp + 0x4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492bb3  0f8c16020000           -jl 0x492dcf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492dcf;
    }
    // 00492bb9  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492bbd  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00492bc1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00492bc3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492bc5  e81af8ffff             -call 0x4923e4
    cpu.esp -= 4;
    sub_4923e4(app, cpu);
    if (cpu.terminate) return;
L_0x00492bca:
    // 00492bca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00492bcc  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00492bd0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00492bd2  7407                   -je 0x492bdb
    if (cpu.flags.zf)
    {
        goto L_0x00492bdb;
    }
    // 00492bd4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00492bd6  e8b17afeff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x00492bdb:
    // 00492bdb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00492bdd  83c43c                 +add esp, 0x3c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00492be0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492be1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492be2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492be3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492be6:
    // 00492be6  e845f5ffff             -call 0x492130
    cpu.esp -= 4;
    sub_492130(app, cpu);
    if (cpu.terminate) return;
    // 00492beb  e95efdffff             -jmp 0x49294e
    goto L_0x0049294e;
L_0x00492bf0:
    // 00492bf0  80fc10                 +cmp ah, 0x10
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00492bf3  0f8470fdffff           -je 0x492969
    if (cpu.flags.zf)
    {
        goto L_0x00492969;
    }
    // 00492bf9  e977fdffff             -jmp 0x492975
    goto L_0x00492975;
L_0x00492bfe:
    // 00492bfe  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492c00  0f8db9fdffff           -jge 0x4929bf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004929bf;
    }
    // 00492c06  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00492c08  e9b2fdffff             -jmp 0x4929bf
    goto L_0x004929bf;
L_0x00492c0d:
    // 00492c0d  3b5c2438               +cmp ebx, dword ptr [esp + 0x38]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492c11  0f8ebefdffff           -jle 0x4929d5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004929d5;
    }
    // 00492c17  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 00492c1b  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00492c1f  e9b1fdffff             -jmp 0x4929d5
    goto L_0x004929d5;
L_0x00492c24:
    // 00492c24  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492c26  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00492c29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492c2a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492c2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492c2c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492c2f:
    // 00492c2f  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492c33  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492c37  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492c3b  e8b8250100             -call 0x4a51f8
    cpu.esp -= 4;
    sub_4a51f8(app, cpu);
    if (cpu.terminate) return;
    // 00492c40  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00492c44  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492c47  7cdb                   -jl 0x492c24
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492c24;
    }
    // 00492c49  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00492c51  e92ffeffff             -jmp 0x492a85
    goto L_0x00492a85;
L_0x00492c56:
    // 00492c56  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492c5a  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492c5e  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492c62  e8f9260100             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 00492c67  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00492c6b  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492c6e  7cb4                   -jl 0x492c24
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492c24;
    }
    // 00492c70  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00492c78  e918feffff             -jmp 0x492a95
    goto L_0x00492a95;
L_0x00492c7d:
    // 00492c7d  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492c81  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492c85  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492c89  e82a280100             -call 0x4a54b8
    cpu.esp -= 4;
    sub_4a54b8(app, cpu);
    if (cpu.terminate) return;
    // 00492c8e  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00492c92  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492c95  7c8d                   -jl 0x492c24
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492c24;
    }
    // 00492c97  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00492c9f  e9fdfdffff             -jmp 0x492aa1
    goto L_0x00492aa1;
L_0x00492ca4:
    // 00492ca4  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492ca8  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492cac  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492cb0  e863290100             -call 0x4a5618
    cpu.esp -= 4;
    sub_4a5618(app, cpu);
    if (cpu.terminate) return;
    // 00492cb5  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00492cb9  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492cbc  0f8df2fdffff           -jge 0x492ab4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492ab4;
    }
L_0x00492cc2:
    // 00492cc2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492cc4  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00492cc7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492cc8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492cc9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492cca  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00492ccd:
    // 00492ccd  39dd                   +cmp ebp, ebx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492ccf  0f8d29feffff           -jge 0x492afe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492afe;
    }
    // 00492cd5  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00492cd7  e922feffff             -jmp 0x492afe
    goto L_0x00492afe;
L_0x00492cdc:
    // 00492cdc  3b5c2438               +cmp ebx, dword ptr [esp + 0x38]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492ce0  0f8e2efeffff           -jle 0x492b14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492b14;
    }
    // 00492ce6  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 00492cea  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00492cee  e921feffff             -jmp 0x492b14
    goto L_0x00492b14;
L_0x00492cf3:
    // 00492cf3  75cd                   -jne 0x492cc2
    if (!cpu.flags.zf)
    {
        goto L_0x00492cc2;
    }
    // 00492cf5  837c244c00             +cmp dword ptr [esp + 0x4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492cfa  0f8cc1000000           -jl 0x492dc1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492dc1;
    }
    // 00492d00  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00492d02:
    // 00492d02  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00492d06  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492d0a  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 00492d0d  8b3548c94c00           -mov esi, dword ptr [0x4cc948]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 00492d13  db0403                 -fild dword ptr [ebx + eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1))));
    // 00492d16  d90550c94c00           -fld dword ptr [0x4cc950]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5032272) /* 0x4cc950 */)));
    // 00492d1c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00492d23  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492d25  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00492d27  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492d29  dd1cc6                 -fstp qword ptr [esi + eax*8]
    app->getMemory<double>(cpu.esi + cpu.eax * 8) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492d2c  035c2408               -add ebx, dword ptr [esp + 8]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00492d30  db4304                 -fild dword ptr [ebx + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 00492d33  c744c62401000000       -mov dword ptr [esi + eax*8 + 0x24], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.eax * 8) = 1 /*0x1*/;
    // 00492d3b  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00492d3f  897cc620               -mov dword ptr [esi + eax*8 + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */ + cpu.eax * 8) = cpu.edi;
    // 00492d43  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00492d45  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00492d48  dd5cc608               -fstp qword ptr [esi + eax*8 + 8]
    app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492d4c  895cc618               -mov dword ptr [esi + eax*8 + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */ + cpu.eax * 8) = cpu.ebx;
    // 00492d50  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00492d52  7577                   -jne 0x492dcb
    if (!cpu.flags.zf)
    {
        goto L_0x00492dcb;
    }
    // 00492d54  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00492d59:
    // 00492d59  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00492d5d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492d61  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 00492d64  db0403                 -fild dword ptr [ebx + eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1))));
    // 00492d67  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00492d6e  d90550c94c00           -fld dword ptr [0x4cc950]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5032272) /* 0x4cc950 */)));
    // 00492d74  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492d76  a148c94c00             -mov eax, dword ptr [0x4cc948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 00492d7b  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00492d7e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00492d80  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00492d82  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492d84  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492d86  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492d8a  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00492d8e  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00492d90  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00492d93  db4304                 -fild dword ptr [ebx + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 00492d96  c7402401000000         -mov dword ptr [eax + 0x24], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 00492d9d  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00492da0  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00492da5  897820                 -mov dword ptr [eax + 0x20], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 00492da8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00492daa  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 00492dae  dd5808                 -fstp qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00492db1  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00492db6  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00492db8  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00492dbc  e9b8fdffff             -jmp 0x492b79
    goto L_0x00492b79;
L_0x00492dc1:
    // 00492dc1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00492dc6  e937ffffff             -jmp 0x492d02
    goto L_0x00492d02;
L_0x00492dcb:
    // 00492dcb  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00492dcd  eb8a                   -jmp 0x492d59
    goto L_0x00492d59;
L_0x00492dcf:
    // 00492dcf  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492dd3  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00492dd7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00492dd9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492ddb  e860f8ffff             -call 0x492640
    cpu.esp -= 4;
    sub_492640(app, cpu);
    if (cpu.terminate) return;
    // 00492de0  e9e5fdffff             -jmp 0x492bca
    goto L_0x00492bca;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492de8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492de8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492de9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492dea  81ec00020000           -sub esp, 0x200
    (cpu.esp) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00492df0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00492df2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00492df4  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00492df8  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00492dfc  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00492e00  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00492e03  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00492e06  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00492e09  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00492e0c  48                     -dec eax
    (cpu.eax)--;
    // 00492e0d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00492e11  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00492e15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492e16  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00492e19  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492e1a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00492e1d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00492e1f  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00492e22  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492e26  48                     -dec eax
    (cpu.eax)--;
    // 00492e27  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00492e2c  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00492e30  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00492e34  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492e36  e8e1faffff             -call 0x49291c
    cpu.esp -= 4;
    sub_49291c(app, cpu);
    if (cpu.terminate) return;
    // 00492e3b  81c400020000           -add esp, 0x200
    (cpu.esp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00492e41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492e42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492e43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_492e44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492e44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492e45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492e46  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492e47  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00492e4d  89842400020000         -mov dword ptr [esp + 0x200], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 00492e54  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00492e56  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00492e58  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00492e5a  7e1c                   -jle 0x492e78
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492e78;
    }
    // 00492e5c  8d0ced00000000         -lea ecx, [ebp*8]
    cpu.ecx = x86::reg32(cpu.ebp * 8);
    // 00492e63  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00492e65:
    // 00492e65  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00492e67  8d3c04                 -lea edi, [esp + eax]
    cpu.edi = x86::reg32(cpu.esp + cpu.eax * 1);
    // 00492e6a  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00492e6d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492e70  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00492e71  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00492e72  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492e74  7cef                   -jl 0x492e65
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492e65;
    }
    // 00492e76  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00492e78:
    // 00492e78  8b942418020000         -mov edx, dword ptr [esp + 0x218]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 00492e7f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00492e80  8b8c2418020000         -mov ecx, dword ptr [esp + 0x218]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 00492e87  8b842404020000         -mov eax, dword ptr [esp + 0x204]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */);
    // 00492e8e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492e8f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00492e91  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492e95  e882faffff             -call 0x49291c
    cpu.esp -= 4;
    sub_49291c(app, cpu);
    if (cpu.terminate) return;
    // 00492e9a  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00492ea0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492ea1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492ea2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492ea3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_492eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492eb0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00492eb2  7501                   -jne 0x492eb5
    if (!cpu.flags.zf)
    {
        goto L_0x00492eb5;
    }
    // 00492eb4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492eb5:
    // 00492eb5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492eb6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492eb7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00492eb9  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00492eba  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00492ebc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00492ebe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492ec0  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 00492ec4  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00492ec7  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00492ec9  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00492ecc  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00492ece  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492ecf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492ed0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492ed4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492ed4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492ed5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492ed6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492ed7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492ed8  81eca4000000           -sub esp, 0xa4
    (cpu.esp) -= x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 00492ede  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00492ee0  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00492ee4  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 00492ee8  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00492eeb  ba31144900             -mov edx, 0x491431
    cpu.edx = 4789297 /*0x491431*/;
    // 00492ef0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00492ef3  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 00492ef7  ba3cae5200             -mov edx, 0x52ae3c
    cpu.edx = 5418556 /*0x52ae3c*/;
    // 00492efc  89842484000000         -mov dword ptr [esp + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 00492f03  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00492f06  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492f08  e8c3e2ffff             -call 0x4911d0
    cpu.esp -= 4;
    sub_4911d0(app, cpu);
    if (cpu.terminate) return;
    // 00492f0d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00492f0f  899c2488000000         -mov dword ptr [esp + 0x88], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.ebx;
    // 00492f16  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00492f18  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00492f1b  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00492f21  83f820                 +cmp eax, 0x20
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492f24  750b                   -jne 0x492f31
    if (!cpu.flags.zf)
    {
        goto L_0x00492f31;
    }
    // 00492f26  c784248800000002000000 -mov dword ptr [esp + 0x88], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = 2 /*0x2*/;
L_0x00492f31:
    // 00492f31  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00492f33  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00492f35  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00492f38  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00492f3e  40                     -inc eax
    (cpu.eax)++;
    // 00492f3f  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00492f41  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492f44  750b                   -jne 0x492f51
    if (!cpu.flags.zf)
    {
        goto L_0x00492f51;
    }
    // 00492f46  c784248800000001000000 -mov dword ptr [esp + 0x88], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = 1 /*0x1*/;
L_0x00492f51:
    // 00492f51  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00492f55  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00492f57  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00492f5b  896c2440               -mov dword ptr [esp + 0x40], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ebp;
    // 00492f5f  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00492f62  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00492f65  896c243c               -mov dword ptr [esp + 0x3c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebp;
    // 00492f69  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492f6b  7e08                   -jle 0x492f75
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492f75;
    }
    // 00492f6d  c744244001000000       -mov dword ptr [esp + 0x40], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 1 /*0x1*/;
L_0x00492f75:
    // 00492f75  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00492f79  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00492f7d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00492f80  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492f82  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00492f86  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00492f89  3b700c                 +cmp esi, dword ptr [eax + 0xc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492f8c  7e08                   -jle 0x492f96
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492f96;
    }
    // 00492f8e  c744243c01000000       -mov dword ptr [esp + 0x3c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 1 /*0x1*/;
L_0x00492f96:
    // 00492f96  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00492f9a  8b6c244c               -mov ebp, dword ptr [esp + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00492f9e  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00492fa1  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492fa3  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00492fa6  3b5004                 +cmp edx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492fa9  7e08                   -jle 0x492fb3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492fb3;
    }
    // 00492fab  c744244002000000       -mov dword ptr [esp + 0x40], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 2 /*0x2*/;
L_0x00492fb3:
    // 00492fb3  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00492fb7  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00492fbb  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00492fbe  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00492fc0  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00492fc3  3b4204                 +cmp eax, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492fc6  7d08                   -jge 0x492fd0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00492fd0;
    }
    // 00492fc8  c744243c02000000       -mov dword ptr [esp + 0x3c], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 2 /*0x2*/;
L_0x00492fd0:
    // 00492fd0  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00492fd4  0b442440               -or eax, dword ptr [esp + 0x40]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */)));
    // 00492fd8  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00492fdd  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00492fdf  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00492fe3  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00492fe7  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00492fee  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00492ff0  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00492ff3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00492ff5  89542448               -mov dword ptr [esp + 0x48], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00492ff9  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00492ffd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00492fff  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00493003  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00493006  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00493008  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049300a  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049300e  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 00493011  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00493014  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00493016  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049301a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049301c  2b01                   -sub eax, dword ptr [ecx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 0049301e  8b6904                 -mov ebp, dword ptr [ecx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00493021  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00493025  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00493028  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049302a  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049302e  3d00000100             +cmp eax, 0x10000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493033  7d18                   -jge 0x49304d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049304d;
    }
    // 00493035  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049303c  750b                   -jne 0x493049
    if (!cpu.flags.zf)
    {
        goto L_0x00493049;
    }
L_0x0049303e:
    // 0049303e  81c4a4000000           +add esp, 0xa4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(164 /*0xa4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493044  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493045  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493046  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493047  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493048  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493049:
    // 00493049  0f77                   -emms 
    cpu.mmx.init();
    // 0049304b  ebf1                   -jmp 0x49303e
    goto L_0x0049303e;
L_0x0049304d:
    // 0049304d  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00493051  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00493053  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00493057  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00493059  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049305b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049305d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049305f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493061  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00493065  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493067  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0049306b  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049306d  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00493071  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00493073  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00493075  7c1e                   -jl 0x493095
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493095;
    }
L_0x00493077:
    // 00493077  81f900000100           +cmp ecx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049307d  7d23                   -jge 0x4930a2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004930a2;
    }
L_0x0049307f:
    // 0049307f  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493086  74b6                   -je 0x49303e
    if (cpu.flags.zf)
    {
        goto L_0x0049303e;
    }
    // 00493088  0f77                   -emms 
    cpu.mmx.init();
    // 0049308a  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 00493090  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493091  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493092  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493093  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493094  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493095:
    // 00493095  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0049309a  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0049309c  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004930a0  ebd5                   -jmp 0x493077
    goto L_0x00493077;
L_0x004930a2:
    // 004930a2  81f900000006           +cmp ecx, 0x6000000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100663296 /*0x6000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004930a8  7dd5                   -jge 0x49307f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049307f;
    }
    // 004930aa  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004930ae  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004930b2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004930b5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004930b7  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 004930bb  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004930bf  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004930c3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004930c5  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004930c9  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004930cd  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004930d0  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 004930d3  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004930d5  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004930d9  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004930dd  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004930df  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004930e1  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004930e5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004930e7  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004930eb  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004930ed  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004930f1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004930f3  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004930f5  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004930f9  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004930fc  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004930ff  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493101  2b542448               -sub edx, dword ptr [esp + 0x48]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */)));
    // 00493105  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00493109  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049310d  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493110  2b4304                 -sub eax, dword ptr [ebx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 00493113  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00493117  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00493119  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049311b  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049311f  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00493122  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493124  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00493128  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049312b  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049312f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493132  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493134  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00493138  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049313a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049313c  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049313e  e86dfdffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 00493143  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00493145  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00493149  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049314c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049314f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00493152  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493154  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00493156  41                     -inc ecx
    (cpu.ecx)++;
    // 00493157  e854fdffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 0049315c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049315d  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00493164  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493165  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00493169  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049316a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049316c  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 00493171  b83cae5200             -mov eax, 0x52ae3c
    cpu.eax = 5418556 /*0x52ae3c*/;
    // 00493176  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00493178  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049317c  e8ef830000             -call 0x49b570
    cpu.esp -= 4;
    sub_49b570(app, cpu);
    if (cpu.terminate) return;
    // 00493181  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00493185  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00493189  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049318b  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0049318d  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00493190  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00493193  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493195  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00493198  89bc249c000000         -mov dword ptr [esp + 0x9c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.edi;
    // 0049319f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004931a1  0f8452010000           -je 0x4932f9
    if (cpu.flags.zf)
    {
        goto L_0x004932f9;
    }
    // 004931a7  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004931ab  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004931ae  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004931b0  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004931b4  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004931b8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004931ba  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 004931bc  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004931c0  e8ebfcffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 004931c5  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 004931cc  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004931cf  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004931d3  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004931d7  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004931d9  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x004931dd:
    // 004931dd  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004931e0  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004931e3  e8c8fcffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 004931e8  89842490000000         -mov dword ptr [esp + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 004931ef  3b5c2414               +cmp ebx, dword ptr [esp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004931f3  0f8d25030000           -jge 0x49351e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049351e;
    }
    // 004931f9  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004931fd  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00493201  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493204  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00493208  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049320a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049320c  0f8438010000           -je 0x49334a
    if (cpu.flags.zf)
    {
        goto L_0x0049334a;
    }
    // 00493212  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00493216  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493219  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049321b  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049321d  2b442444               -sub eax, dword ptr [esp + 0x44]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
    // 00493221  e88afcffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 00493226  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049322a  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 0049322e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00493232  e879fcffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 00493237  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x0049323b:
    // 0049323b  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049323f  a1d4a64c00             -mov eax, dword ptr [0x4ca6d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 00493244  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493246  7d02                   -jge 0x49324a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049324a;
    }
    // 00493248  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0049324a:
    // 0049324a  8b0dcca64c00           -mov ecx, dword ptr [0x4ca6cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 00493250  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 00493254  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493256  0f8d1c010000           -jge 0x493378
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493378;
    }
L_0x0049325c:
    // 0049325c  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00493263  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
L_0x00493267:
    // 00493267  3b5c2450               +cmp ebx, dword ptr [esp + 0x50]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049326b  0f8dad020000           -jge 0x49351e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049351e;
    }
    // 00493271  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00493278  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049327a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049327d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00493280  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493282  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00493285  2b0dd0a64c00           -sub ecx, dword ptr [0x4ca6d0]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
    // 0049328b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049328d  7e02                   -jle 0x493291
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493291;
    }
    // 0049328f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00493291:
    // 00493291  8b0dc8a64c00           -mov ecx, dword ptr [0x4ca6c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 00493297  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493299  898c2494000000         -mov dword ptr [esp + 0x94], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.ecx;
    // 004932a0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004932a2  0f8e01020000           -jle 0x4934a9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004934a9;
    }
    // 004932a8  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004932aa  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004932ac:
    // 004932ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004932ae  7e0c                   -jle 0x4932bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004932bc;
    }
    // 004932b0  3b1dcca64c00           +cmp ebx, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004932b6  0f8dfb010000           -jge 0x4934b7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004934b7;
    }
L_0x004932bc:
    // 004932bc  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004932c3  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 004932ca  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 004932d1  43                     -inc ebx
    (cpu.ebx)++;
    // 004932d2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004932d4  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 004932d6  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004932da  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004932de  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004932e1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004932e3  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004932e7  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 004932ee  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004932f2  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004932f4  e96effffff             -jmp 0x493267
    goto L_0x00493267;
L_0x004932f9:
    // 004932f9  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004932fc  898424a0000000         -mov dword ptr [esp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00493303  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00493307  8b9424a0000000         -mov edx, dword ptr [esp + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0049330e  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493311  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00493313  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00493317  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049331b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049331d  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049331f  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493323  e888fbffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 00493328  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049332c  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 00493333  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00493336  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00493339  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049333b  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049333f  29ca                   +sub edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493341  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00493345  e993feffff             -jmp 0x4931dd
    goto L_0x004931dd;
L_0x0049334a:
    // 0049334a  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049334e  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493351  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00493353  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493355  2b442444               +sub eax, dword ptr [esp + 0x44]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493359  e852fbffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 0049335e  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00493362  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00493366  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049336a  e841fbffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 0049336f  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00493373  e9c3feffff             -jmp 0x49323b
    goto L_0x0049323b;
L_0x00493378:
    // 00493378  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049337c  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00493380  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493383  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00493385  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00493387  3b0dc8a64c00           +cmp ecx, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049338d  0f8cc9feffff           -jl 0x49325c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049325c;
    }
    // 00493393  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493395  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049339b  0f8dbbfeffff           -jge 0x49325c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049325c;
    }
    // 004933a1  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004933a5  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004933ab  0f8cabfeffff           -jl 0x49325c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049325c;
    }
    // 004933b1  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004933b7  0f8d9ffeffff           -jge 0x49325c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049325c;
    }
    // 004933bd  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004933c1  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004933c7  0f8c8ffeffff           -jl 0x49325c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049325c;
    }
    // 004933cd  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004933d3  0f8d83feffff           -jge 0x49325c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049325c;
    }
    // 004933d9  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004933e0  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004933e3  89842480000000         -mov dword ptr [esp + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 004933ea  8954245c               -mov dword ptr [esp + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edx;
L_0x004933ee:
    // 004933ee  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004933f5  3b44245c               +cmp eax, dword ptr [esp + 0x5c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004933f9  0f8d1f010000           -jge 0x49351e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049351e;
    }
    // 004933ff  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00493406  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00493408  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049340b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049340e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00493410  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00493412  7e52                   -jle 0x493466
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493466;
    }
    // 00493414  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493415  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00493417  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0049341e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00493421  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00493424  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00493426  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00493429  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049342b  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049342f  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00493436  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049343a  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0049343c  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00493443  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493444  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0049344a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049344d  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049344f  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 00493455  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493457  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493459  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049345b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049345c  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493463  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00493466:
    // 00493466  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0049346d  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00493474  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0049347b  43                     -inc ebx
    (cpu.ebx)++;
    // 0049347c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049347e  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00493480  8b942480000000         -mov edx, dword ptr [esp + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00493487  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0049348b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049348e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493490  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00493494  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0049349b  89942480000000         -mov dword ptr [esp + 0x80], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 004934a2  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004934a4  e945ffffff             -jmp 0x4933ee
    goto L_0x004933ee;
L_0x004934a9:
    // 004934a9  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004934ab  898c2494000000         -mov dword ptr [esp + 0x94], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.ecx;
    // 004934b2  e9f5fdffff             -jmp 0x4932ac
    goto L_0x004932ac;
L_0x004934b7:
    // 004934b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004934b8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004934ba  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 004934c1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004934c4  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004934c7  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004934c9  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004934cc  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004934ce  8b842498000000         -mov eax, dword ptr [esp + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 004934d5  030c853cae5200         -add ecx, dword ptr [eax*4 + 0x52ae3c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5418556) /* 0x52ae3c */ + cpu.eax * 4)));
    // 004934dc  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004934df  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004934e3  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004934ea  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004934ee  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004934f2  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004934f4  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004934f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004934f9  a1e8a64c00             -mov eax, dword ptr [0x4ca6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 004934fe  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 00493504  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00493506  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0049350a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049350c  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049350e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049350f  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493516  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493519  e99efdffff             -jmp 0x4932bc
    goto L_0x004932bc;
L_0x0049351e:
    // 0049351e  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00493522  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00493526  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493529  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049352b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049352f  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00493532  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00493535  39c3                   +cmp ebx, eax
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493537  0f8d5a030000           -jge 0x493897
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493897;
    }
    // 0049353d  837c242000             +cmp dword ptr [esp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493542  0f8471010000           -je 0x4936b9
    if (cpu.flags.zf)
    {
        goto L_0x004936b9;
    }
    // 00493548  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049354c  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00493550  8b6904                 -mov ebp, dword ptr [ecx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00493553  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493555  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00493557  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00493559  e852f9ffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 0049355e  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00493562  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00493566  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049356a  e841f9ffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 0049356f  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 00493573  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00493577  8984249c000000         -mov dword ptr [esp + 0x9c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.eax;
    // 0049357e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00493582  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00493586  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493589  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049358b  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049358f  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00493593  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00493595  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00493598  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0049359b  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049359f  898424a0000000         -mov dword ptr [esp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 004935a6  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004935aa  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004935ac  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004935b0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004935b4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004935b6  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 004935b8  8b9424a0000000         -mov edx, dword ptr [esp + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 004935bf  e8ecf8ffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 004935c4  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004935c8  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 004935cf  2b5104                 -sub edx, dword ptr [ecx + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004935d2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004935d6  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004935da  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004935dd  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004935e0  e8cbf8ffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 004935e5  89842490000000         -mov dword ptr [esp + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.eax;
L_0x004935ec:
    // 004935ec  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004935f0  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004935f4  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004935f7  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004935f9  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004935fc  a1d4a64c00             -mov eax, dword ptr [0x4ca6d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 00493601  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00493604  39c2                   +cmp edx, eax
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493606  7e02                   -jle 0x49360a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049360a;
    }
    // 00493608  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0049360a:
    // 0049360a  8b0dcca64c00           -mov ecx, dword ptr [0x4ca6cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 00493610  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 00493614  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493616  0f8dcf000000           -jge 0x4936eb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004936eb;
    }
L_0x0049361c:
    // 0049361c  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00493623  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
L_0x00493627:
    // 00493627  3b5c2454               +cmp ebx, dword ptr [esp + 0x54]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049362b  0f8d66020000           -jge 0x493897
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493897;
    }
    // 00493631  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00493638  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049363a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049363d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00493640  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493642  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00493645  2b0dd0a64c00           -sub ecx, dword ptr [0x4ca6d0]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
    // 0049364b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049364d  7e02                   -jle 0x493651
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493651;
    }
    // 0049364f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00493651:
    // 00493651  8b0dc8a64c00           -mov ecx, dword ptr [0x4ca6c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 00493657  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493659  898c2498000000         -mov dword ptr [esp + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 00493660  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00493662  0f8ebb010000           -jle 0x493823
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493823;
    }
    // 00493668  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049366a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049366c:
    // 0049366c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049366e  7e0c                   -jle 0x49367c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049367c;
    }
    // 00493670  3b1dcca64c00           +cmp ebx, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493676  0f8db5010000           -jge 0x493831
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493831;
    }
L_0x0049367c:
    // 0049367c  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00493683  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0049368a  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00493691  43                     -inc ebx
    (cpu.ebx)++;
    // 00493692  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493694  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00493696  8b542470               -mov edx, dword ptr [esp + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0049369a  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0049369e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004936a1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004936a3  8b44246c               -mov eax, dword ptr [esp + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004936a7  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 004936ae  89542470               -mov dword ptr [esp + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 004936b2  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004936b4  e96effffff             -jmp 0x493627
    goto L_0x00493627;
L_0x004936b9:
    // 004936b9  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004936bd  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004936c0  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004936c4  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004936c6  2b01                   +sub eax, dword ptr [ecx]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004936c8  e8e3f7ffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 004936cd  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004936d1  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 004936d5  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004936d9  8b7c2444               -mov edi, dword ptr [esp + 0x44]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004936dd  e8cef7ffff             -call 0x492eb0
    cpu.esp -= 4;
    sub_492eb0(app, cpu);
    if (cpu.terminate) return;
    // 004936e2  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 004936e6  e901ffffff             -jmp 0x4935ec
    goto L_0x004935ec;
L_0x004936eb:
    // 004936eb  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004936ef  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004936f3  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004936f6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004936f8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004936fa  3b0dc8a64c00           +cmp ecx, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493700  0f8c16ffffff           -jl 0x49361c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049361c;
    }
    // 00493706  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493708  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049370e  0f8d08ffffff           -jge 0x49361c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049361c;
    }
    // 00493714  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00493718  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049371e  0f8cf8feffff           -jl 0x49361c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049361c;
    }
    // 00493724  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049372a  0f8decfeffff           -jge 0x49361c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049361c;
    }
    // 00493730  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00493734  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049373a  0f8cdcfeffff           -jl 0x49361c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049361c;
    }
    // 00493740  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493746  0f8dd0feffff           -jge 0x49361c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049361c;
    }
    // 0049374c  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00493753  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00493756  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0049375a  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
L_0x0049375e:
    // 0049375e  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00493762  3b442458               +cmp eax, dword ptr [esp + 0x58]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493766  0f8d2b010000           -jge 0x493897
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493897;
    }
    // 0049376c  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00493773  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00493775  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00493778  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049377b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049377d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049377f  7e65                   -jle 0x4937e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004937e6;
    }
    // 00493781  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493782  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00493784  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0049378b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049378e  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00493791  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00493793  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00493796  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00493798  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049379b  898c24a4000000         -mov dword ptr [esp + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 004937a2  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004937a9  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 004937b0  898424a4000000         -mov dword ptr [esp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 004937b7  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004937b9  8b0de8a64c00           -mov ecx, dword ptr [0x4ca6e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 004937bf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004937c0  8b942480000000         -mov edx, dword ptr [esp + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004937c7  a1eca64c00             -mov eax, dword ptr [0x4ca6ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 004937cc  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004937ce  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 004937d5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004937d7  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004937d9  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 004937db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004937dc  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004937e3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004937e6:
    // 004937e6  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004937ed  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 004937f4  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 004937fb  43                     -inc ebx
    (cpu.ebx)++;
    // 004937fc  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004937fe  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00493800  8b542478               -mov edx, dword ptr [esp + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00493804  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00493808  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049380b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049380d  8b44246c               -mov eax, dword ptr [esp + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00493811  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 00493818  89542478               -mov dword ptr [esp + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 0049381c  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049381e  e93bffffff             -jmp 0x49375e
    goto L_0x0049375e;
L_0x00493823:
    // 00493823  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00493825  898c2498000000         -mov dword ptr [esp + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0049382c  e93bfeffff             -jmp 0x49366c
    goto L_0x0049366c;
L_0x00493831:
    // 00493831  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493832  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00493834  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0049383b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049383e  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00493841  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00493843  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00493846  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493848  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0049384f  030c853cae5200         -add ecx, dword ptr [eax*4 + 0x52ae3c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5418556) /* 0x52ae3c */ + cpu.eax * 4)));
    // 00493856  898c24a4000000         -mov dword ptr [esp + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 0049385d  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00493864  8b8424a4000000         -mov eax, dword ptr [esp + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0049386b  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049386d  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00493871  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493872  a1e8a64c00             -mov eax, dword ptr [0x4ca6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 00493877  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049387a  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049387c  a1eca64c00             -mov eax, dword ptr [0x4ca6ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 00493881  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493883  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493885  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00493887  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493888  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049388f  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493892  e9e5fdffff             -jmp 0x49367c
    goto L_0x0049367c;
L_0x00493897:
    // 00493897  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049389e  0f849af7ffff           -je 0x49303e
    if (cpu.flags.zf)
    {
        goto L_0x0049303e;
    }
    // 004938a4  0f77                   -emms 
    cpu.mmx.init();
    // 004938a6  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 004938ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004938ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004938ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004938af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004938b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4938b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004938b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004938b5  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004938b8  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004938ba  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004938bd  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004938c3  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004938c6  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004938c9  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004938cc  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004938d2  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004938d6  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004938d9  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004938dc  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004938e2  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004938e6  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004938e9  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004938ec  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004938f2  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004938f6  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004938f9  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004938fc  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00493902  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493906  8b5214                 -mov edx, dword ptr [edx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00493909  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049390c  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00493912  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00493916  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00493918  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049391b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00493921  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00493925  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00493928  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049392b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00493931  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00493935  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00493938  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049393b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00493941  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00493945  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00493948  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049394b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00493951  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00493955  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00493958  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049395b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00493961  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00493965  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00493968  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049396b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00493971  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00493975  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00493979  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049397b  e854f5ffff             -call 0x492ed4
    cpu.esp -= 4;
    sub_492ed4(app, cpu);
    if (cpu.terminate) return;
    // 00493980  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00493983  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493984  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_493990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493990  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00493992  7501                   -jne 0x493995
    if (!cpu.flags.zf)
    {
        goto L_0x00493995;
    }
    // 00493994  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493995:
    // 00493995  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493996  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493997  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00493999  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0049399a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049399c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049399e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004939a0  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 004939a4  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004939a7  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004939a9  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004939ac  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004939ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004939af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004939b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4939b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004939b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004939b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004939b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004939b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004939b8  81eca4000000           -sub esp, 0xa4
    (cpu.esp) -= x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 004939be  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004939c0  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 004939c4  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 004939c8  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004939cb  bae2114900             -mov edx, 0x4911e2
    cpu.edx = 4788706 /*0x4911e2*/;
    // 004939d0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004939d3  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 004939d7  ba3cae5200             -mov edx, 0x52ae3c
    cpu.edx = 5418556 /*0x52ae3c*/;
    // 004939dc  89842484000000         -mov dword ptr [esp + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 004939e3  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004939e6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004939e8  e8e3d7ffff             -call 0x4911d0
    cpu.esp -= 4;
    sub_4911d0(app, cpu);
    if (cpu.terminate) return;
    // 004939ed  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004939ef  899c2488000000         -mov dword ptr [esp + 0x88], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.ebx;
    // 004939f6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004939f8  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004939fb  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00493a01  83f820                 +cmp eax, 0x20
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493a04  750b                   -jne 0x493a11
    if (!cpu.flags.zf)
    {
        goto L_0x00493a11;
    }
    // 00493a06  c784248800000002000000 -mov dword ptr [esp + 0x88], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = 2 /*0x2*/;
L_0x00493a11:
    // 00493a11  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493a13  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00493a15  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00493a18  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 00493a1e  40                     -inc eax
    (cpu.eax)++;
    // 00493a1f  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00493a21  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493a24  750b                   -jne 0x493a31
    if (!cpu.flags.zf)
    {
        goto L_0x00493a31;
    }
    // 00493a26  c784248800000001000000 -mov dword ptr [esp + 0x88], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = 1 /*0x1*/;
L_0x00493a31:
    // 00493a31  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00493a35  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00493a37  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00493a3b  896c2440               -mov dword ptr [esp + 0x40], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ebp;
    // 00493a3f  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00493a42  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00493a45  896c243c               -mov dword ptr [esp + 0x3c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebp;
    // 00493a49  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493a4b  7e08                   -jle 0x493a55
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493a55;
    }
    // 00493a4d  c744244001000000       -mov dword ptr [esp + 0x40], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 1 /*0x1*/;
L_0x00493a55:
    // 00493a55  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493a59  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00493a5d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493a60  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493a62  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00493a66  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00493a69  3b700c                 +cmp esi, dword ptr [eax + 0xc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493a6c  7e08                   -jle 0x493a76
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493a76;
    }
    // 00493a6e  c744243c01000000       -mov dword ptr [esp + 0x3c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 1 /*0x1*/;
L_0x00493a76:
    // 00493a76  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00493a7a  8b6c244c               -mov ebp, dword ptr [esp + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00493a7e  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493a81  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00493a83  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00493a86  3b5004                 +cmp edx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493a89  7e08                   -jle 0x493a93
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493a93;
    }
    // 00493a8b  c744244002000000       -mov dword ptr [esp + 0x40], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 2 /*0x2*/;
L_0x00493a93:
    // 00493a93  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493a97  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00493a9b  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00493a9e  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00493aa0  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00493aa3  3b4204                 +cmp eax, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493aa6  7d08                   -jge 0x493ab0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493ab0;
    }
    // 00493aa8  c744243c02000000       -mov dword ptr [esp + 0x3c], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 2 /*0x2*/;
L_0x00493ab0:
    // 00493ab0  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493ab4  0b442440               -or eax, dword ptr [esp + 0x40]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */)));
    // 00493ab8  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00493abd  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00493abf  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00493ac3  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00493ac7  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00493ace  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00493ad0  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493ad3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00493ad5  89542448               -mov dword ptr [esp + 0x48], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00493ad9  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00493add  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00493adf  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00493ae3  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00493ae6  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00493ae8  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00493aea  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493aee  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 00493af1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00493af4  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00493af6  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00493afa  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00493afc  2b01                   -sub eax, dword ptr [ecx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 00493afe  8b6904                 -mov ebp, dword ptr [ecx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00493b01  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00493b05  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00493b08  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00493b0a  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00493b0e  3d00000100             +cmp eax, 0x10000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493b13  7d18                   -jge 0x493b2d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493b2d;
    }
    // 00493b15  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493b1c  750b                   -jne 0x493b29
    if (!cpu.flags.zf)
    {
        goto L_0x00493b29;
    }
L_0x00493b1e:
    // 00493b1e  81c4a4000000           +add esp, 0xa4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(164 /*0xa4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493b24  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b25  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b26  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493b29:
    // 00493b29  0f77                   -emms 
    cpu.mmx.init();
    // 00493b2b  ebf1                   -jmp 0x493b1e
    goto L_0x00493b1e;
L_0x00493b2d:
    // 00493b2d  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00493b31  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00493b33  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00493b37  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00493b39  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00493b3b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00493b3d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00493b3f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493b41  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00493b45  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493b47  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00493b4b  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493b4d  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00493b51  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00493b53  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00493b55  7c1e                   -jl 0x493b75
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493b75;
    }
L_0x00493b57:
    // 00493b57  81f900000100           +cmp ecx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493b5d  7d23                   -jge 0x493b82
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493b82;
    }
L_0x00493b5f:
    // 00493b5f  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493b66  74b6                   -je 0x493b1e
    if (cpu.flags.zf)
    {
        goto L_0x00493b1e;
    }
    // 00493b68  0f77                   -emms 
    cpu.mmx.init();
    // 00493b6a  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 00493b70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b74  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493b75:
    // 00493b75  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00493b7a  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00493b7c  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00493b80  ebd5                   -jmp 0x493b57
    goto L_0x00493b57;
L_0x00493b82:
    // 00493b82  81f900000006           +cmp ecx, 0x6000000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100663296 /*0x6000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493b88  7dd5                   -jge 0x493b5f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493b5f;
    }
    // 00493b8a  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00493b8e  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00493b92  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493b95  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493b97  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00493b9b  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00493b9f  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493ba3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493ba5  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00493ba9  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00493bad  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00493bb0  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 00493bb3  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00493bb5  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00493bb9  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00493bbd  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00493bbf  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 00493bc1  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00493bc5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00493bc7  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00493bcb  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00493bcd  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00493bd1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00493bd3  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00493bd5  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00493bd9  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 00493bdc  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00493bdf  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493be1  2b542448               -sub edx, dword ptr [esp + 0x48]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */)));
    // 00493be5  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00493be9  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00493bed  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493bf0  2b4304                 -sub eax, dword ptr [ebx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 00493bf3  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00493bf7  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00493bf9  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00493bfb  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00493bff  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00493c02  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493c04  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00493c08  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00493c0b  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00493c0f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493c12  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493c14  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00493c18  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00493c1a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00493c1c  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00493c1e  e86dfdffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 00493c23  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00493c25  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00493c29  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00493c2c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493c2f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00493c32  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493c34  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00493c36  41                     -inc ecx
    (cpu.ecx)++;
    // 00493c37  e854fdffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 00493c3c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493c3d  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00493c44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493c45  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00493c49  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493c4a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00493c4c  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 00493c51  b83cae5200             -mov eax, 0x52ae3c
    cpu.eax = 5418556 /*0x52ae3c*/;
    // 00493c56  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00493c58  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493c5c  e80f790000             -call 0x49b570
    cpu.esp -= 4;
    sub_49b570(app, cpu);
    if (cpu.terminate) return;
    // 00493c61  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00493c65  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00493c69  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00493c6b  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 00493c6d  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00493c70  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00493c73  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493c75  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00493c78  89bc249c000000         -mov dword ptr [esp + 0x9c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.edi;
    // 00493c7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493c81  0f8452010000           -je 0x493dd9
    if (cpu.flags.zf)
    {
        goto L_0x00493dd9;
    }
    // 00493c87  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00493c8b  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00493c8e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493c90  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00493c94  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00493c98  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493c9a  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00493c9c  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493ca0  e8ebfcffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 00493ca5  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 00493cac  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00493caf  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00493cb3  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00493cb7  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493cb9  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x00493cbd:
    // 00493cbd  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493cc0  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 00493cc3  e8c8fcffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 00493cc8  89842490000000         -mov dword ptr [esp + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 00493ccf  3b5c2414               +cmp ebx, dword ptr [esp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493cd3  0f8d25030000           -jge 0x493ffe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493ffe;
    }
    // 00493cd9  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493cdd  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00493ce1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493ce4  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00493ce8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00493cea  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00493cec  0f8438010000           -je 0x493e2a
    if (cpu.flags.zf)
    {
        goto L_0x00493e2a;
    }
    // 00493cf2  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00493cf6  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493cf9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00493cfb  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493cfd  2b442444               -sub eax, dword ptr [esp + 0x44]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
    // 00493d01  e88afcffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 00493d06  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00493d0a  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00493d0e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00493d12  e879fcffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 00493d17  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x00493d1b:
    // 00493d1b  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00493d1f  a1d4a64c00             -mov eax, dword ptr [0x4ca6d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 00493d24  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493d26  7d02                   -jge 0x493d2a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493d2a;
    }
    // 00493d28  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00493d2a:
    // 00493d2a  8b0dcca64c00           -mov ecx, dword ptr [0x4ca6cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 00493d30  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 00493d34  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493d36  0f8d1c010000           -jge 0x493e58
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493e58;
    }
L_0x00493d3c:
    // 00493d3c  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00493d43  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
L_0x00493d47:
    // 00493d47  3b5c2450               +cmp ebx, dword ptr [esp + 0x50]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493d4b  0f8dad020000           -jge 0x493ffe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493ffe;
    }
    // 00493d51  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00493d58  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493d5a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00493d5d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00493d60  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493d62  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00493d65  2b0dd0a64c00           -sub ecx, dword ptr [0x4ca6d0]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
    // 00493d6b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00493d6d  7e02                   -jle 0x493d71
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493d71;
    }
    // 00493d6f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00493d71:
    // 00493d71  8b0dc8a64c00           -mov ecx, dword ptr [0x4ca6c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 00493d77  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493d79  898c2494000000         -mov dword ptr [esp + 0x94], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.ecx;
    // 00493d80  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00493d82  0f8e01020000           -jle 0x493f89
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493f89;
    }
    // 00493d88  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493d8a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x00493d8c:
    // 00493d8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493d8e  7e0c                   -jle 0x493d9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493d9c;
    }
    // 00493d90  3b1dcca64c00           +cmp ebx, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493d96  0f8dfb010000           -jge 0x493f97
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493f97;
    }
L_0x00493d9c:
    // 00493d9c  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00493da3  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00493daa  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00493db1  43                     -inc ebx
    (cpu.ebx)++;
    // 00493db2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493db4  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00493db6  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00493dba  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00493dbe  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493dc1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493dc3  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00493dc7  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 00493dce  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00493dd2  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493dd4  e96effffff             -jmp 0x493d47
    goto L_0x00493d47;
L_0x00493dd9:
    // 00493dd9  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00493ddc  898424a0000000         -mov dword ptr [esp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00493de3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00493de7  8b9424a0000000         -mov edx, dword ptr [esp + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 00493dee  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493df1  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00493df3  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00493df7  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00493dfb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493dfd  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00493dff  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493e03  e888fbffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 00493e08  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00493e0c  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 00493e13  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00493e16  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00493e19  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00493e1b  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00493e1f  29ca                   +sub edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493e21  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00493e25  e993feffff             -jmp 0x493cbd
    goto L_0x00493cbd;
L_0x00493e2a:
    // 00493e2a  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00493e2e  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493e31  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00493e33  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493e35  2b442444               +sub eax, dword ptr [esp + 0x44]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493e39  e852fbffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 00493e3e  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00493e42  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00493e46  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00493e4a  e841fbffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 00493e4f  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00493e53  e9c3feffff             -jmp 0x493d1b
    goto L_0x00493d1b;
L_0x00493e58:
    // 00493e58  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00493e5c  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00493e60  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493e63  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00493e65  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00493e67  3b0dc8a64c00           +cmp ecx, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493e6d  0f8cc9feffff           -jl 0x493d3c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493d3c;
    }
    // 00493e73  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493e75  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493e7b  0f8dbbfeffff           -jge 0x493d3c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493d3c;
    }
    // 00493e81  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00493e85  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493e8b  0f8cabfeffff           -jl 0x493d3c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493d3c;
    }
    // 00493e91  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493e97  0f8d9ffeffff           -jge 0x493d3c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493d3c;
    }
    // 00493e9d  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00493ea1  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493ea7  0f8c8ffeffff           -jl 0x493d3c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493d3c;
    }
    // 00493ead  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493eb3  0f8d83feffff           -jge 0x493d3c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493d3c;
    }
    // 00493eb9  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00493ec0  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00493ec3  89842480000000         -mov dword ptr [esp + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 00493eca  8954245c               -mov dword ptr [esp + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edx;
L_0x00493ece:
    // 00493ece  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00493ed5  3b44245c               +cmp eax, dword ptr [esp + 0x5c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493ed9  0f8d1f010000           -jge 0x493ffe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493ffe;
    }
    // 00493edf  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00493ee6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00493ee8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00493eeb  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00493eee  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00493ef0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00493ef2  7e52                   -jle 0x493f46
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493f46;
    }
    // 00493ef4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493ef5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00493ef7  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00493efe  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00493f01  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00493f04  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00493f06  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00493f09  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00493f0b  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00493f0f  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00493f16  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00493f1a  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 00493f1c  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00493f23  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493f24  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 00493f2a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00493f2d  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00493f2f  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 00493f35  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493f37  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493f39  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00493f3b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493f3c  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493f43  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00493f46:
    // 00493f46  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00493f4d  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00493f54  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00493f5b  43                     -inc ebx
    (cpu.ebx)++;
    // 00493f5c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493f5e  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00493f60  8b942480000000         -mov edx, dword ptr [esp + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00493f67  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00493f6b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493f6e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493f70  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00493f74  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 00493f7b  89942480000000         -mov dword ptr [esp + 0x80], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 00493f82  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493f84  e945ffffff             -jmp 0x493ece
    goto L_0x00493ece;
L_0x00493f89:
    // 00493f89  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00493f8b  898c2494000000         -mov dword ptr [esp + 0x94], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.ecx;
    // 00493f92  e9f5fdffff             -jmp 0x493d8c
    goto L_0x00493d8c;
L_0x00493f97:
    // 00493f97  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493f98  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00493f9a  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00493fa1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00493fa4  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00493fa7  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00493fa9  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00493fac  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493fae  8b842498000000         -mov eax, dword ptr [esp + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 00493fb5  030c853cae5200         -add ecx, dword ptr [eax*4 + 0x52ae3c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5418556) /* 0x52ae3c */ + cpu.eax * 4)));
    // 00493fbc  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00493fbf  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00493fc3  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00493fca  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00493fce  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00493fd2  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00493fd4  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00493fd8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493fd9  a1e8a64c00             -mov eax, dword ptr [0x4ca6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 00493fde  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 00493fe4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00493fe6  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00493fea  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00493fec  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00493fee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493fef  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493ff6  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493ff9  e99efdffff             -jmp 0x493d9c
    goto L_0x00493d9c;
L_0x00493ffe:
    // 00493ffe  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00494002  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00494006  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00494009  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049400b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049400f  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00494012  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00494015  39c3                   +cmp ebx, eax
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494017  0f8d5a030000           -jge 0x494377
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494377;
    }
    // 0049401d  837c242000             +cmp dword ptr [esp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494022  0f8471010000           -je 0x494199
    if (cpu.flags.zf)
    {
        goto L_0x00494199;
    }
    // 00494028  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049402c  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00494030  8b6904                 -mov ebp, dword ptr [ecx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00494033  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00494035  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00494037  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00494039  e852f9ffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 0049403e  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00494042  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00494046  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049404a  e841f9ffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 0049404f  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 00494053  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00494057  8984249c000000         -mov dword ptr [esp + 0x9c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.eax;
    // 0049405e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00494062  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00494066  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00494069  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049406b  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049406f  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00494073  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00494075  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00494078  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0049407b  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049407f  898424a0000000         -mov dword ptr [esp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00494086  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049408a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049408c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00494090  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00494094  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00494096  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00494098  8b9424a0000000         -mov edx, dword ptr [esp + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0049409f  e8ecf8ffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 004940a4  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004940a8  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 004940af  2b5104                 -sub edx, dword ptr [ecx + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004940b2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004940b6  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004940ba  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004940bd  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004940c0  e8cbf8ffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 004940c5  89842490000000         -mov dword ptr [esp + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.eax;
L_0x004940cc:
    // 004940cc  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004940d0  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004940d4  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004940d7  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004940d9  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004940dc  a1d4a64c00             -mov eax, dword ptr [0x4ca6d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 004940e1  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004940e4  39c2                   +cmp edx, eax
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004940e6  7e02                   -jle 0x4940ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004940ea;
    }
    // 004940e8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004940ea:
    // 004940ea  8b0dcca64c00           -mov ecx, dword ptr [0x4ca6cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 004940f0  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 004940f4  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004940f6  0f8dcf000000           -jge 0x4941cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004941cb;
    }
L_0x004940fc:
    // 004940fc  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00494103  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
L_0x00494107:
    // 00494107  3b5c2454               +cmp ebx, dword ptr [esp + 0x54]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049410b  0f8d66020000           -jge 0x494377
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494377;
    }
    // 00494111  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00494118  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049411a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049411d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00494120  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00494122  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00494125  2b0dd0a64c00           -sub ecx, dword ptr [0x4ca6d0]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
    // 0049412b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049412d  7e02                   -jle 0x494131
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494131;
    }
    // 0049412f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00494131:
    // 00494131  8b0dc8a64c00           -mov ecx, dword ptr [0x4ca6c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 00494137  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00494139  898c2498000000         -mov dword ptr [esp + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 00494140  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00494142  0f8ebb010000           -jle 0x494303
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494303;
    }
    // 00494148  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049414a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049414c:
    // 0049414c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049414e  7e0c                   -jle 0x49415c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049415c;
    }
    // 00494150  3b1dcca64c00           +cmp ebx, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494156  0f8db5010000           -jge 0x494311
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494311;
    }
L_0x0049415c:
    // 0049415c  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00494163  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0049416a  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00494171  43                     -inc ebx
    (cpu.ebx)++;
    // 00494172  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494174  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494176  8b542470               -mov edx, dword ptr [esp + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0049417a  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0049417e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00494181  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494183  8b44246c               -mov eax, dword ptr [esp + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00494187  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0049418e  89542470               -mov dword ptr [esp + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 00494192  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494194  e96effffff             -jmp 0x494107
    goto L_0x00494107;
L_0x00494199:
    // 00494199  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049419d  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004941a0  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004941a4  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004941a6  2b01                   +sub eax, dword ptr [ecx]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004941a8  e8e3f7ffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 004941ad  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004941b1  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 004941b5  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004941b9  8b7c2444               -mov edi, dword ptr [esp + 0x44]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004941bd  e8cef7ffff             -call 0x493990
    cpu.esp -= 4;
    sub_493990(app, cpu);
    if (cpu.terminate) return;
    // 004941c2  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 004941c6  e901ffffff             -jmp 0x4940cc
    goto L_0x004940cc;
L_0x004941cb:
    // 004941cb  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004941cf  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004941d3  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004941d6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004941d8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004941da  3b0dc8a64c00           +cmp ecx, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004941e0  0f8c16ffffff           -jl 0x4940fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004940fc;
    }
    // 004941e6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004941e8  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004941ee  0f8d08ffffff           -jge 0x4940fc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004940fc;
    }
    // 004941f4  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004941f8  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004941fe  0f8cf8feffff           -jl 0x4940fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004940fc;
    }
    // 00494204  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049420a  0f8decfeffff           -jge 0x4940fc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004940fc;
    }
    // 00494210  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00494214  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049421a  0f8cdcfeffff           -jl 0x4940fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004940fc;
    }
    // 00494220  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494226  0f8dd0feffff           -jge 0x4940fc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004940fc;
    }
    // 0049422c  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00494233  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00494236  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0049423a  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
L_0x0049423e:
    // 0049423e  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00494242  3b442458               +cmp eax, dword ptr [esp + 0x58]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494246  0f8d2b010000           -jge 0x494377
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494377;
    }
    // 0049424c  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00494253  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00494255  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00494258  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049425b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049425d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049425f  7e65                   -jle 0x4942c6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004942c6;
    }
    // 00494261  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00494262  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494264  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0049426b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049426e  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00494271  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00494273  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00494276  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494278  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049427b  898c24a4000000         -mov dword ptr [esp + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 00494282  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00494289  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00494290  898424a4000000         -mov dword ptr [esp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 00494297  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 00494299  8b0de8a64c00           -mov ecx, dword ptr [0x4ca6e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0049429f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004942a0  8b942480000000         -mov edx, dword ptr [esp + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004942a7  a1eca64c00             -mov eax, dword ptr [0x4ca6ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 004942ac  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004942ae  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 004942b5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004942b7  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004942b9  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 004942bb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004942bc  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004942c3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004942c6:
    // 004942c6  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004942cd  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 004942d4  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 004942db  43                     -inc ebx
    (cpu.ebx)++;
    // 004942dc  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004942de  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 004942e0  8b542478               -mov edx, dword ptr [esp + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004942e4  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004942e8  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004942eb  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004942ed  8b44246c               -mov eax, dword ptr [esp + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004942f1  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 004942f8  89542478               -mov dword ptr [esp + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 004942fc  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004942fe  e93bffffff             -jmp 0x49423e
    goto L_0x0049423e;
L_0x00494303:
    // 00494303  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00494305  898c2498000000         -mov dword ptr [esp + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0049430c  e93bfeffff             -jmp 0x49414c
    goto L_0x0049414c;
L_0x00494311:
    // 00494311  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00494312  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00494314  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0049431b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049431e  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00494321  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00494323  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00494326  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494328  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0049432f  030c853cae5200         -add ecx, dword ptr [eax*4 + 0x52ae3c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5418556) /* 0x52ae3c */ + cpu.eax * 4)));
    // 00494336  898c24a4000000         -mov dword ptr [esp + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 0049433d  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00494344  8b8424a4000000         -mov eax, dword ptr [esp + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0049434b  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049434d  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00494351  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00494352  a1e8a64c00             -mov eax, dword ptr [0x4ca6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 00494357  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049435a  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049435c  a1eca64c00             -mov eax, dword ptr [0x4ca6ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 00494361  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494363  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00494365  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00494367  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00494368  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049436f  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494372  e9e5fdffff             -jmp 0x49415c
    goto L_0x0049415c;
L_0x00494377:
    // 00494377  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049437e  0f849af7ffff           -je 0x493b1e
    if (cpu.flags.zf)
    {
        goto L_0x00493b1e;
    }
    // 00494384  0f77                   -emms 
    cpu.mmx.init();
    // 00494386  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0049438c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049438d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049438e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049438f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494390  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_494394(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494394  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494395  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00494398  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049439a  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049439d  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004943a3  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004943a6  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004943a9  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004943ac  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004943b2  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004943b6  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004943b9  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004943bc  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004943c2  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004943c6  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004943c9  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004943cc  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004943d2  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004943d6  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004943d9  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004943dc  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004943e2  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004943e6  8b5214                 -mov edx, dword ptr [edx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004943e9  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004943ec  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004943f2  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004943f6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004943f8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004943fb  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00494401  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00494405  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00494408  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049440b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00494411  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00494415  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00494418  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049441b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00494421  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00494425  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00494428  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049442b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00494431  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00494435  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00494438  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049443b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00494441  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00494445  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00494448  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049444b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00494451  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494455  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00494459  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049445b  e854f5ffff             -call 0x4939b4
    cpu.esp -= 4;
    sub_4939b4(app, cpu);
    if (cpu.terminate) return;
    // 00494460  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00494463  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494464  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_494470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00494471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494472  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494473  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494474  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494475  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00494478  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049447a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049447c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049447e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00494480  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00494484  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494489  8a15d9a64c00           -mov dl, byte ptr [0x4ca6d9]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5023449) /* 0x4ca6d9 */);
    // 0049448f  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494491  7415                   -je 0x4944a8
    if (cpu.flags.zf)
    {
        goto L_0x004944a8;
    }
    // 00494493  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00494495  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00494497  8a15d9a64c00           -mov dl, byte ptr [0x4ca6d9]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5023449) /* 0x4ca6d9 */);
    // 0049449d  e8d62b0000             -call 0x497078
    cpu.esp -= 4;
    sub_497078(app, cpu);
    if (cpu.terminate) return;
    // 004944a2  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004944a6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004944a8:
    // 004944a8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004944ad  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004944b1  8b4102                 -mov eax, dword ptr [ecx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004944b4  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004944b7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004944ba  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004944bd  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004944c1  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004944c5  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004944c9  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004944cc  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004944cf  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004944d1  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004944d5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004944d7  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004944db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004944dd  8974242c               -mov dword ptr [esp + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.esi;
    // 004944e1  e8aa6f0000             -call 0x49b490
    cpu.esp -= 4;
    sub_49b490(app, cpu);
    if (cpu.terminate) return;
    // 004944e6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004944eb  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004944ef  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004944f3  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004944f7  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004944fb  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004944ff  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00494503  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00494505  8d7510                 -lea esi, [ebp + 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00494508  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00494509  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0049450a  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049450e  8d7518                 -lea esi, [ebp + 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00494511  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00494512  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00494513  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00494517  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00494519  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049451b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049451d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0049451e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0049451f  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494523  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00494527  e8646f0000             -call 0x49b490
    cpu.esp -= 4;
    sub_49b490(app, cpu);
    if (cpu.terminate) return;
    // 0049452c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049452e  7509                   -jne 0x494539
    if (!cpu.flags.zf)
    {
        goto L_0x00494539;
    }
    // 00494530  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00494533  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494534  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494535  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494536  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494537  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494538  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494539:
    // 00494539  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049453b  e84c61feff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00494540  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00494543  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494544  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494545  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494546  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494547  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494548  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49454c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049454c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049454d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049454e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049454f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494550  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00494553  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00494555  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00494557  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00494559  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049455b  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049455d  a0d9a64c00             -mov al, byte ptr [0x4ca6d9]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023449) /* 0x4ca6d9 */);
    // 00494562  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494568  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049456a  39c2                   +cmp edx, eax
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049456c  740f                   -je 0x49457d
    if (cpu.flags.zf)
    {
        goto L_0x0049457d;
    }
    // 0049456e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00494570  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00494572  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494574  e8ff2a0000             -call 0x497078
    cpu.esp -= 4;
    sub_497078(app, cpu);
    if (cpu.terminate) return;
    // 00494579  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049457b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0049457d:
    // 0049457d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00494582  8b4702                 -mov eax, dword ptr [edi + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00494585  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00494588  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049458b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049458e  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00494591  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00494595  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00494599  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049459c  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049459f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004945a3  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004945a7  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004945ab  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004945af  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004945b1  8b04c1                 -mov eax, dword ptr [ecx + eax*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 004945b4  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004945b8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004945ba  8b44c104               -mov eax, dword ptr [ecx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 004945be  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004945c2  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004945c5  8b04c1                 -mov eax, dword ptr [ecx + eax*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 004945c8  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004945cc  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004945cf  8b44c104               -mov eax, dword ptr [ecx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 004945d3  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004945d7  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004945da  8b04c1                 -mov eax, dword ptr [ecx + eax*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 004945dd  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004945e1  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004945e4  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004945e8  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 004945ec  8b44c104               -mov eax, dword ptr [ecx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 004945f0  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004945f2  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004945f6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004945f8  e8936e0000             -call 0x49b490
    cpu.esp -= 4;
    sub_49b490(app, cpu);
    if (cpu.terminate) return;
    // 004945fd  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00494601  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00494606  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00494609  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049460d  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00494611  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00494615  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00494619  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049461d  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00494621  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00494624  8b04c1                 -mov eax, dword ptr [ecx + eax*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 00494627  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049462b  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049462e  8b44c104               -mov eax, dword ptr [ecx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 00494632  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00494636  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00494639  8b04c1                 -mov eax, dword ptr [ecx + eax*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 0049463c  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00494640  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00494643  8b44c104               -mov eax, dword ptr [ecx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 00494647  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049464b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049464d  8b04c1                 -mov eax, dword ptr [ecx + eax*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 00494650  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00494654  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00494656  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049465a  8b44c104               -mov eax, dword ptr [ecx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 0049465e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00494660  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00494664  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494666  e8256e0000             -call 0x49b490
    cpu.esp -= 4;
    sub_49b490(app, cpu);
    if (cpu.terminate) return;
    // 0049466b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049466d  7508                   -jne 0x494677
    if (!cpu.flags.zf)
    {
        goto L_0x00494677;
    }
    // 0049466f  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00494672  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494673  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494674  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494675  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494676  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494677:
    // 00494677  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00494679  e80e60feff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0049467e  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00494681  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494682  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494683  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494684  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494685  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_494690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494690  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00494691  8a1dd8a64c00           -mov bl, byte ptr [0x4ca6d8]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 00494697  80fb08                 +cmp bl, 8
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049469a  7411                   -je 0x4946ad
    if (cpu.flags.zf)
    {
        goto L_0x004946ad;
    }
    // 0049469c  80fb10                 +cmp bl, 0x10
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049469f  7419                   -je 0x4946ba
    if (cpu.flags.zf)
    {
        goto L_0x004946ba;
    }
    // 004946a1  80fb0f                 +cmp bl, 0xf
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004946a4  7414                   -je 0x4946ba
    if (cpu.flags.zf)
    {
        goto L_0x004946ba;
    }
    // 004946a6  80fb20                 +cmp bl, 0x20
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004946a9  7421                   -je 0x4946cc
    if (cpu.flags.zf)
    {
        goto L_0x004946cc;
    }
    // 004946ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004946ad:
    // 004946ad  8b1d308f5200           -mov ebx, dword ptr [0x528f30]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5410608) /* 0x528f30 */);
    // 004946b3  e8eec5feff             -call 0x480ca6
    cpu.esp -= 4;
    sub_480ca6(app, cpu);
    if (cpu.terminate) return;
    // 004946b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004946ba:
    // 004946ba  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004946bc  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004946be  668b1d308f5200         -mov bx, word ptr [0x528f30]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5410608) /* 0x528f30 */);
    // 004946c5  e8dec5feff             -call 0x480ca8
    cpu.esp -= 4;
    sub_480ca8(app, cpu);
    if (cpu.terminate) return;
    // 004946ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004946cc:
    // 004946cc  8b1d308f5200           -mov ebx, dword ptr [0x528f30]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5410608) /* 0x528f30 */);
    // 004946d2  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004946d5  e8d7c5feff             -call 0x480cb1
    cpu.esp -= 4;
    sub_480cb1(app, cpu);
    if (cpu.terminate) return;
    // 004946da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4946dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004946dc  e997100100             -jmp 0x4a5778
    return sub_4a5778(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4946e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004946e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004946e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004946e6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004946e9  8b7cda04               -mov edi, dword ptr [edx + ebx*8 + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.ebx * 8);
    // 004946ed  3b7cca04               +cmp edi, dword ptr [edx + ecx*8 + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.ecx * 8)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946f1  7e06                   -jle 0x4946f9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004946f9;
    }
    // 004946f3  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004946f5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004946f7  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004946f9:
    // 004946f9  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 004946fc  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004946ff  8d340a                 -lea esi, [edx + ecx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 00494702  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00494704  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00494707  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049470a  29fb                   +sub ebx, edi
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049470c  895824                 -mov dword ptr [eax + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0049470f  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00494712  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00494715  7506                   -jne 0x49471d
    if (!cpu.flags.zf)
    {
        goto L_0x0049471d;
    }
    // 00494717  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049471a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049471b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049471c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049471d:
    // 0049471d  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049471f  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00494722  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00494725  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00494727  2b0a                   -sub ecx, dword ptr [edx]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00494729  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049472c  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049472f  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00494732  d80c9d80505400         -fmul dword ptr [ebx*4 + 0x545080]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5525632) /* 0x545080 */ + cpu.ebx * 4));
    // 00494739  d80550c94c00           -fadd dword ptr [0x4cc950]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5032272) /* 0x4cc950 */));
    // 0049473f  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00494741  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00494743  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00494746  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00494749  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049474a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049474b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49474c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049474c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049474d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049474e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049474f  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00494752  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00494756  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00494758  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049475a  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049475e  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 00494764  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00494767  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494769  a1dca64c00             -mov eax, dword ptr [0x4ca6dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 0049476e  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00494770  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494772  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00494779  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049477d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049477f  8b1d48c94c00           -mov ebx, dword ptr [0x4cc948]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 00494785  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00494788  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049478a  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0049478d  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00494794  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494796  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00494799  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049479b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049479f  48                     -dec eax
    (cpu.eax)--;
    // 004947a0  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004947a4:
    // 004947a4  837b2400               +cmp dword ptr [ebx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004947a8  0f8e89000000           -jle 0x494837
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494837;
    }
L_0x004947ae:
    // 004947ae  8b6924                 -mov ebp, dword ptr [ecx + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004947b1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004947b3  0f8ebf000000           -jle 0x494878
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494878;
    }
    // 004947b9  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004947bc  39e8                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004947be  0f8de3000000           -jge 0x4948a7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004948a7;
    }
L_0x004947c4:
    // 004947c4  8b6b24                 -mov ebp, dword ptr [ebx + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004947c7  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004947c9  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004947cd  896b24                 -mov dword ptr [ebx + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 004947d0  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004947d4  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004947d7  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004947d9  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004947db  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004947df  895124                 -mov dword ptr [ecx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004947e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x004947e4:
    // 004947e4  74be                   -je 0x4947a4
    if (cpu.flags.zf)
    {
        goto L_0x004947a4;
    }
    // 004947e6  8b6918                 -mov ebp, dword ptr [ecx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004947e9  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004947ec  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004947ee  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 004947f4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004947f6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004947f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004947fb  0f8fad000000           -jg 0x4948ae
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004948ae;
    }
    // 00494801  0f8cce000000           -jl 0x4948d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004948d5;
    }
L_0x00494807:
    // 00494807  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049480b  a1e4a64c00             -mov eax, dword ptr [0x4ca6e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023460) /* 0x4ca6e4 */);
    // 00494810  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00494813  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494815  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00494818  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049481a  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049481d  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00494821  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00494824  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00494827  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494829  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049482d  896b18                 -mov dword ptr [ebx + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00494830  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00494831  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00494835  ebad                   -jmp 0x4947e4
    goto L_0x004947e4;
L_0x00494837:
    // 00494837  4e                     -dec esi
    (cpu.esi)--;
    // 00494838  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049483a  7c20                   -jl 0x49485c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049485c;
    }
    // 0049483c  83eb28                 -sub ebx, 0x28
    (cpu.ebx) -= x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x0049483f:
    // 0049483f  39fe                   +cmp esi, edi
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494841  7429                   -je 0x49486c
    if (cpu.flags.zf)
    {
        goto L_0x0049486c;
    }
    // 00494843  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00494847  3b4320                 +cmp eax, dword ptr [ebx + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049484a  0f8e54ffffff           -jle 0x4947a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004947a4;
    }
    // 00494850  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00494855  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00494858  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494859  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049485a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049485b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049485c:
    // 0049485c  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00494860  6bde28                 -imul ebx, esi, 0x28
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 00494863  a148c94c00             -mov eax, dword ptr [0x4cc948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 00494868  01c3                   +add ebx, eax
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049486a  ebd3                   -jmp 0x49483f
    goto L_0x0049483f;
L_0x0049486c:
    // 0049486c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00494871  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00494874  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494875  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494876  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494877  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494878:
    // 00494878  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049487c  47                     -inc edi
    (cpu.edi)++;
    // 0049487d  39c7                   +cmp edi, eax
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049487f  7c21                   -jl 0x4948a2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004948a2;
    }
    // 00494881  8b0d48c94c00           -mov ecx, dword ptr [0x4cc948]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 00494887  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00494889:
    // 00494889  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049488d  3b4120                 +cmp eax, dword ptr [ecx + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494890  0f8e18ffffff           -jle 0x4947ae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004947ae;
    }
    // 00494896  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049489b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049489e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049489f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004948a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004948a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004948a2:
    // 004948a2  83c128                 +add ecx, 0x28
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004948a5  ebe2                   -jmp 0x494889
    goto L_0x00494889;
L_0x004948a7:
    // 004948a7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004948a9  e916ffffff             -jmp 0x4947c4
    goto L_0x004947c4;
L_0x004948ae:
    // 004948ae  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 004948b1  8d14ad00000000         -lea edx, [ebp*4]
    cpu.edx = x86::reg32(cpu.ebp * 4);
    // 004948b8  8b2deca64c00           -mov ebp, dword ptr [0x4ca6ec]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 004948be  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004948c0  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004948c4  032a                   +add ebp, dword ptr [edx]
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004948c6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004948c8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004948ca  ff15c4c94c00           -call dword ptr [0x4cc9c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032388) /* 0x4cc9c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004948d0  e932ffffff             -jmp 0x494807
    goto L_0x00494807;
L_0x004948d5:
    // 004948d5  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004948d8  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004948dc  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004948e0  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004948e3  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 004948e9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004948eb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004948ee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004948f0  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004948f3  7d05                   -jge 0x4948fa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004948fa;
    }
    // 004948f5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004948fa:
    // 004948fa  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004948fe  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00494901  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00494904  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00494907  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0049490a  a1eca64c00             -mov eax, dword ptr [0x4ca6ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0049490f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00494911  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494915  0328                   +add ebp, dword ptr [eax]
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494917  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00494919  ff15c4c94c00           -call dword ptr [0x4cc9c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032388) /* 0x4cc9c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049491f  e9e3feffff             -jmp 0x494807
    goto L_0x00494807;
}

/* align: skip  */
void Application::sub_494924(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494924  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494925  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494926  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494927  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049492a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049492e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00494930  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00494932  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00494936  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0049493c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049493f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494941  a1dca64c00             -mov eax, dword ptr [0x4ca6dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 00494946  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00494948  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049494a  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049494e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00494950  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00494957  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494959  8b1d48c94c00           -mov ebx, dword ptr [0x4cc948]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 0049495f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00494962  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00494964  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00494967  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049496e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494970  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00494973  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494975  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00494979  48                     -dec eax
    (cpu.eax)--;
    // 0049497a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0049497e:
    // 0049497e  83792400               +cmp dword ptr [ecx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494982  0f8e8b000000           -jle 0x494a13
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494a13;
    }
L_0x00494988:
    // 00494988  8b6b24                 -mov ebp, dword ptr [ebx + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 0049498b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049498d  0f8ec1000000           -jle 0x494a54
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494a54;
    }
    // 00494993  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00494996  39d5                   +cmp ebp, edx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494998  0f8de5000000           -jge 0x494a83
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494a83;
    }
    // 0049499e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004949a0:
    // 004949a0  8b6b24                 -mov ebp, dword ptr [ebx + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004949a3  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004949a5  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004949a9  896b24                 -mov dword ptr [ebx + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 004949ac  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004949b0  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004949b3  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004949b5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004949b7  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004949bb  895124                 -mov dword ptr [ecx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004949be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x004949c0:
    // 004949c0  74bc                   -je 0x49497e
    if (cpu.flags.zf)
    {
        goto L_0x0049497e;
    }
    // 004949c2  8b6918                 -mov ebp, dword ptr [ecx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004949c5  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004949c8  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004949ca  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 004949d0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004949d2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004949d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004949d7  0f8fad000000           -jg 0x494a8a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494a8a;
    }
    // 004949dd  0f8cce000000           -jl 0x494ab1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494ab1;
    }
L_0x004949e3:
    // 004949e3  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004949e7  a1e4a64c00             -mov eax, dword ptr [0x4ca6e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023460) /* 0x4ca6e4 */);
    // 004949ec  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004949ef  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004949f1  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004949f4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004949f6  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004949f9  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004949fd  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00494a00  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00494a03  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494a05  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00494a09  896b18                 -mov dword ptr [ebx + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00494a0c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00494a0d  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00494a11  ebad                   -jmp 0x4949c0
    goto L_0x004949c0;
L_0x00494a13:
    // 00494a13  4e                     -dec esi
    (cpu.esi)--;
    // 00494a14  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00494a16  7c20                   -jl 0x494a38
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494a38;
    }
    // 00494a18  83e928                 -sub ecx, 0x28
    (cpu.ecx) -= x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x00494a1b:
    // 00494a1b  39fe                   +cmp esi, edi
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494a1d  7429                   -je 0x494a48
    if (cpu.flags.zf)
    {
        goto L_0x00494a48;
    }
    // 00494a1f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00494a23  3b4120                 +cmp eax, dword ptr [ecx + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494a26  0f8e52ffffff           -jle 0x49497e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049497e;
    }
    // 00494a2c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00494a31  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00494a34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494a35  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494a36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494a37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494a38:
    // 00494a38  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00494a3c  6bce28                 -imul ecx, esi, 0x28
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 00494a3f  a148c94c00             -mov eax, dword ptr [0x4cc948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 00494a44  01c1                   +add ecx, eax
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494a46  ebd3                   -jmp 0x494a1b
    goto L_0x00494a1b;
L_0x00494a48:
    // 00494a48  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00494a4d  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00494a50  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494a51  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494a52  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494a53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494a54:
    // 00494a54  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00494a58  47                     -inc edi
    (cpu.edi)++;
    // 00494a59  39c7                   +cmp edi, eax
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494a5b  7c21                   -jl 0x494a7e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494a7e;
    }
    // 00494a5d  8b1d48c94c00           -mov ebx, dword ptr [0x4cc948]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 00494a63  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00494a65:
    // 00494a65  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00494a69  3b4320                 +cmp eax, dword ptr [ebx + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494a6c  0f8e16ffffff           -jle 0x494988
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494988;
    }
    // 00494a72  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00494a77  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00494a7a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494a7b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494a7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494a7d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494a7e:
    // 00494a7e  83c328                 +add ebx, 0x28
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494a81  ebe2                   -jmp 0x494a65
    goto L_0x00494a65;
L_0x00494a83:
    // 00494a83  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494a85  e916ffffff             -jmp 0x4949a0
    goto L_0x004949a0;
L_0x00494a8a:
    // 00494a8a  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 00494a8d  8d14ad00000000         -lea edx, [ebp*4]
    cpu.edx = x86::reg32(cpu.ebp * 4);
    // 00494a94  8b2deca64c00           -mov ebp, dword ptr [0x4ca6ec]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 00494a9a  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00494a9c  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494aa0  032a                   +add ebp, dword ptr [edx]
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494aa2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494aa4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00494aa6  ff15c4c94c00           -call dword ptr [0x4cc9c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032388) /* 0x4cc9c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00494aac  e932ffffff             -jmp 0x4949e3
    goto L_0x004949e3;
L_0x00494ab1:
    // 00494ab1  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00494ab4  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00494ab8  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00494abc  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00494abf  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 00494ac5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00494ac7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00494aca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494acc  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494acf  7d05                   -jge 0x494ad6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494ad6;
    }
    // 00494ad1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00494ad6:
    // 00494ad6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00494ada  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00494add  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00494ae0  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00494ae3  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00494ae6  a1eca64c00             -mov eax, dword ptr [0x4ca6ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 00494aeb  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00494aed  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494af1  0328                   +add ebp, dword ptr [eax]
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494af3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00494af5  ff15c4c94c00           -call dword ptr [0x4cc9c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032388) /* 0x4cc9c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00494afb  e9e3feffff             -jmp 0x4949e3
    goto L_0x004949e3;
}

/* align: skip  */
void Application::sub_494b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494b00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494b01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494b02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494b03  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00494b06  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00494b08  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00494b0a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00494b0d  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00494b11  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00494b13  8b0d48c94c00           -mov ecx, dword ptr [0x4cc948]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 00494b19  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00494b1d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00494b1f  0f84e5010000           -je 0x494d0a
    if (cpu.flags.zf)
    {
        goto L_0x00494d0a;
    }
L_0x00494b25:
    // 00494b25  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00494b29  8b0485c8c94c00         -mov eax, dword ptr [eax*4 + 0x4cc9c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032392) /* 0x4cc9c8 */ + cpu.eax * 4);
    // 00494b30  a3c4c94c00             -mov dword ptr [0x4cc9c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5032388) /* 0x4cc9c4 */) = cpu.eax;
    // 00494b35  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00494b38  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00494b3a  8935308f5200           -mov dword ptr [0x528f30], esi
    app->getMemory<x86::reg32>(x86::reg32(5410608) /* 0x528f30 */) = cpu.esi;
    // 00494b40  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00494b44  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00494b48  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00494b4b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494b4d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00494b52  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00494b55  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00494b59  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00494b5d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00494b5f  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494b61  7e31                   -jle 0x494b94
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494b94;
    }
    // 00494b63  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00494b66  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00494b69:
    // 00494b69  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00494b6c  39d7                   +cmp edi, edx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494b6e  0f8ea0010000           -jle 0x494d14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494d14;
    }
    // 00494b74  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00494b76  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
L_0x00494b7a:
    // 00494b7a  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00494b7e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00494b80  39da                   +cmp edx, ebx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494b82  0f8d9f010000           -jge 0x494d27
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494d27;
    }
    // 00494b88  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x00494b8c:
    // 00494b8c  46                     -inc esi
    (cpu.esi)++;
    // 00494b8d  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00494b90  39ee                   +cmp esi, ebp
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494b92  7cd5                   -jl 0x494b69
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494b69;
    }
L_0x00494b94:
    // 00494b94  3b3dd4a64c00           +cmp edi, dword ptr [0x4ca6d4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494b9a  0f8d9a010000           -jge 0x494d3a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494d3a;
    }
    // 00494ba0  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00494ba4  3b05cca64c00           +cmp eax, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494baa  0f8c8a010000           -jl 0x494d3a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494d3a;
    }
    // 00494bb0  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00494bb4  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494bba  0f8d7a010000           -jge 0x494d3a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494d3a;
    }
    // 00494bc0  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00494bc4  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494bca  0f8c6a010000           -jl 0x494d3a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494d3a;
    }
    // 00494bd0  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00494bd4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00494bd6  754f                   -jne 0x494c27
    if (!cpu.flags.zf)
    {
        goto L_0x00494c27;
    }
    // 00494bd8  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00494bdb  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00494bde  89742428               -mov dword ptr [esp + 0x28], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00494be2  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x00494be6:
    // 00494be6  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00494bea  3b442410               +cmp eax, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494bee  7d37                   -jge 0x494c27
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494c27;
    }
    // 00494bf0  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00494bf4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00494bf7  8d5e08                 -lea ebx, [esi + 8]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00494bfa  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494bfc  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00494c00  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00494c03  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00494c06  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00494c08  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00494c0b  2b4608                 -sub eax, dword ptr [esi + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00494c0e  2b5e0c                 -sub ebx, dword ptr [esi + 0xc]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 00494c11  2b4e08                 -sub ecx, dword ptr [esi + 8]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00494c14  2b560c                 -sub edx, dword ptr [esi + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 00494c17  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00494c1a  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00494c1d  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00494c1f  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00494c23  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494c25  74bf                   -je 0x494be6
    if (cpu.flags.zf)
    {
        goto L_0x00494be6;
    }
L_0x00494c27:
    // 00494c27  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00494c2b  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c31  0f8c0e010000           -jl 0x494d45
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494d45;
    }
L_0x00494c37:
    // 00494c37  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00494c3b  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c41  0f8d1b010000           -jge 0x494d62
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494d62;
    }
L_0x00494c47:
    // 00494c47  3b3dcca64c00           +cmp edi, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c4d  0f8c2c010000           -jl 0x494d7f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494d7f;
    }
L_0x00494c53:
    // 00494c53  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00494c57  3b05d4a64c00           +cmp eax, dword ptr [0x4ca6d4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c5d  0f8d39010000           -jge 0x494d9c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494d9c;
    }
    // 00494c63  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c68  7436                   -je 0x494ca0
    if (cpu.flags.zf)
    {
        goto L_0x00494ca0;
    }
L_0x00494c6a:
    // 00494c6a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494c6c  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00494c70  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00494c73  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00494c76  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00494c7b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00494c7d  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c7f  7e1f                   -jle 0x494ca0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494ca0;
    }
    // 00494c81  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00494c84  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00494c87:
    // 00494c87  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00494c8a  39d7                   +cmp edi, edx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c8c  0f8e29010000           -jle 0x494dbb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494dbb;
    }
    // 00494c92  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00494c94  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
L_0x00494c98:
    // 00494c98  46                     -inc esi
    (cpu.esi)++;
    // 00494c99  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00494c9c  39ee                   +cmp esi, ebp
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c9e  7ce7                   -jl 0x494c87
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494c87;
    }
L_0x00494ca0:
    // 00494ca0  8d45ff                 -lea eax, [ebp - 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00494ca3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00494ca5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00494ca7  7e37                   -jle 0x494ce0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494ce0;
    }
    // 00494ca9  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
L_0x00494cad:
    // 00494cad  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00494cb1  8b1d48c94c00           -mov ebx, dword ptr [0x4cc948]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5032264) /* 0x4cc948 */);
    // 00494cb7  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00494cb9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00494cbb  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00494cbf  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00494cc1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00494cc4  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00494cc8  e817faffff             -call 0x4946e4
    cpu.esp -= 4;
    sub_4946e4(app, cpu);
    if (cpu.terminate) return;
    // 00494ccd  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00494cd1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00494cd3  83c328                 -add ebx, 0x28
    (cpu.ebx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00494cd6  46                     -inc esi
    (cpu.esi)++;
    // 00494cd7  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00494cdb  39ee                   +cmp esi, ebp
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494cdd  7cce                   -jl 0x494cad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494cad;
    }
    // 00494cdf  90                     -nop 
    ;
L_0x00494ce0:
    // 00494ce0  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494ce4  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00494ce7  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494ce9  7c02                   -jl 0x494ced
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494ced;
    }
    // 00494ceb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00494ced:
    // 00494ced  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494cf2  0f8cd2000000           -jl 0x494dca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494dca;
    }
    // 00494cf8  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00494cfa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494cfc  e84bfaffff             -call 0x49474c
    cpu.esp -= 4;
    sub_49474c(app, cpu);
    if (cpu.terminate) return;
    // 00494d01  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494d04  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d07  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00494d0a:
    // 00494d0a  e821d4ffff             -call 0x492130
    cpu.esp -= 4;
    sub_492130(app, cpu);
    if (cpu.terminate) return;
    // 00494d0f  e911feffff             -jmp 0x494b25
    goto L_0x00494b25;
L_0x00494d14:
    // 00494d14  3b542420               +cmp edx, dword ptr [esp + 0x20]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494d18  0f8e5cfeffff           -jle 0x494b7a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494b7a;
    }
    // 00494d1e  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00494d22  e953feffff             -jmp 0x494b7a
    goto L_0x00494b7a;
L_0x00494d27:
    // 00494d27  3b54241c               +cmp edx, dword ptr [esp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494d2b  0f8e5bfeffff           -jle 0x494b8c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494b8c;
    }
    // 00494d31  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00494d35  e952feffff             -jmp 0x494b8c
    goto L_0x00494b8c;
L_0x00494d3a:
    // 00494d3a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494d3c  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00494d3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d42  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00494d45:
    // 00494d45  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00494d47  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00494d49  e8960b0100             -call 0x4a58e4
    cpu.esp -= 4;
    sub_4a58e4(app, cpu);
    if (cpu.terminate) return;
    // 00494d4e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00494d50  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494d53  7ce5                   -jl 0x494d3a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494d3a;
    }
    // 00494d55  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 00494d5d  e9d5feffff             -jmp 0x494c37
    goto L_0x00494c37;
L_0x00494d62:
    // 00494d62  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00494d64  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00494d66  e8610c0100             -call 0x4a59cc
    cpu.esp -= 4;
    sub_4a59cc(app, cpu);
    if (cpu.terminate) return;
    // 00494d6b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00494d6d  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494d70  7cc8                   -jl 0x494d3a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494d3a;
    }
    // 00494d72  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 00494d7a  e9c8feffff             -jmp 0x494c47
    goto L_0x00494c47;
L_0x00494d7f:
    // 00494d7f  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00494d81  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00494d83  e81c0d0100             -call 0x4a5aa4
    cpu.esp -= 4;
    sub_4a5aa4(app, cpu);
    if (cpu.terminate) return;
    // 00494d88  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00494d8a  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494d8d  7cab                   -jl 0x494d3a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494d3a;
    }
    // 00494d8f  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 00494d97  e9b7feffff             -jmp 0x494c53
    goto L_0x00494c53;
L_0x00494d9c:
    // 00494d9c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00494d9e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00494da0  e8df0d0100             -call 0x4a5b84
    cpu.esp -= 4;
    sub_4a5b84(app, cpu);
    if (cpu.terminate) return;
    // 00494da5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00494da7  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494daa  0f8dbafeffff           -jge 0x494c6a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494c6a;
    }
    // 00494db0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494db2  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00494db5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494db6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494db7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494db8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00494dbb:
    // 00494dbb  39d3                   +cmp ebx, edx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494dbd  0f8dd5feffff           -jge 0x494c98
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494c98;
    }
    // 00494dc3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00494dc5  e9cefeffff             -jmp 0x494c98
    goto L_0x00494c98;
L_0x00494dca:
    // 00494dca  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00494dcc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00494dce  e851fbffff             -call 0x494924
    cpu.esp -= 4;
    sub_494924(app, cpu);
    if (cpu.terminate) return;
    // 00494dd3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00494dd6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494dd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494dd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494dd9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_494ddc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494ddc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494ddd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494dde  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494ddf  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00494de5  89842400020000         -mov dword ptr [esp + 0x200], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 00494dec  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00494dee  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00494df0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494df2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00494df4  7e1a                   -jle 0x494e10
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494e10;
    }
    // 00494df6  8d0ced00000000         -lea ecx, [ebp*8]
    cpu.ecx = x86::reg32(cpu.ebp * 8);
    // 00494dfd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00494dff:
    // 00494dff  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00494e01  8d3c04                 -lea edi, [esp + eax]
    cpu.edi = x86::reg32(cpu.esp + cpu.eax * 1);
    // 00494e04  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00494e07  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00494e0a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00494e0b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00494e0c  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494e0e  7cef                   -jl 0x494dff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494dff;
    }
L_0x00494e10:
    // 00494e10  8b942414020000         -mov edx, dword ptr [esp + 0x214]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 00494e17  8b842400020000         -mov eax, dword ptr [esp + 0x200]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 00494e1e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00494e20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00494e21  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00494e25  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494e27  e8d4fcffff             -call 0x494b00
    cpu.esp -= 4;
    sub_494b00(app, cpu);
    if (cpu.terminate) return;
    // 00494e2c  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00494e32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494e33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494e34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494e35  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_494e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494e40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494e41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494e42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494e43  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00494e46  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00494e4a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00494e4c  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00494e50  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494e52  7444                   -je 0x494e98
    if (cpu.flags.zf)
    {
        goto L_0x00494e98;
    }
L_0x00494e54:
    // 00494e54  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00494e58  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494e5a  7547                   -jne 0x494ea3
    if (!cpu.flags.zf)
    {
        goto L_0x00494ea3;
    }
    // 00494e5c  c744241c08000000       -mov dword ptr [esp + 0x1c], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 8 /*0x8*/;
L_0x00494e64:
    // 00494e64  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x00494e68:
    // 00494e68  a1a8cd4c00             -mov eax, dword ptr [0x4ccda8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033384) /* 0x4ccda8 */);
    // 00494e6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494e6f  741e                   -je 0x494e8f
    if (cpu.flags.zf)
    {
        goto L_0x00494e8f;
    }
    // 00494e71  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494e75  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00494e77  7c14                   -jl 0x494e8d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494e8d;
    }
    // 00494e79  81fa00400000           +cmp edx, 0x4000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494e7f  7f0c                   -jg 0x494e8d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494e8d;
    }
    // 00494e81  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00494e83  7c08                   -jl 0x494e8d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494e8d;
    }
    // 00494e85  81ff00200000           +cmp edi, 0x2000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494e8b  7e22                   -jle 0x494eaf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494eaf;
    }
L_0x00494e8d:
    // 00494e8d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00494e8f:
    // 00494e8f  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494e92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494e93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494e94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494e95  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00494e98:
    // 00494e98  a1d8a34c00             -mov eax, dword ptr [0x4ca3d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022680) /* 0x4ca3d8 */);
    // 00494e9d  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00494ea1  ebb1                   -jmp 0x494e54
    goto L_0x00494e54;
L_0x00494ea3:
    // 00494ea3  83fb0f                 +cmp ebx, 0xf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494ea6  75bc                   -jne 0x494e64
    if (!cpu.flags.zf)
    {
        goto L_0x00494e64;
    }
    // 00494ea8  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
    // 00494ead  ebb9                   -jmp 0x494e68
    goto L_0x00494e68;
L_0x00494eaf:
    // 00494eaf  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00494eb3  e8a85a0000             -call 0x49a960
    cpu.esp -= 4;
    sub_49a960(app, cpu);
    if (cpu.terminate) return;
    // 00494eb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494eba  74d3                   -je 0x494e8f
    if (cpu.flags.zf)
    {
        goto L_0x00494e8f;
    }
    // 00494ebc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494ebe  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00494ec1  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00494ec4  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00494ec6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494ec8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00494ecb  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00494ecd  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00494ed0  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00494ed3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494ed5  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00494ed8  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00494edc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494edd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494ede  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00494ee2  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00494ee6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00494ee7  682c104c00             -push 0x4c102c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4984876 /*0x4c102c*/;
    cpu.esp -= 4;
    // 00494eec  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00494ef0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00494ef1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00494ef3  e8e970feff             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00494ef8  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00494efb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00494efd  83c248                 -add edx, 0x48
    (cpu.edx) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00494f00  e81753feff             -call 0x47a21c
    cpu.esp -= 4;
    sub_47a21c(app, cpu);
    if (cpu.terminate) return;
    // 00494f05  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00494f09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494f0b  7521                   -jne 0x494f2e
    if (!cpu.flags.zf)
    {
        goto L_0x00494f2e;
    }
    // 00494f0d  837c243000             +cmp dword ptr [esp + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494f12  0f8475ffffff           -je 0x494e8d
    if (cpu.flags.zf)
    {
        goto L_0x00494e8d;
    }
    // 00494f18  ff0548a44c00           -inc dword ptr [0x4ca448]
    (app->getMemory<x86::reg32>(x86::reg32(5022792) /* 0x4ca448 */))++;
    // 00494f1e  e8a959feff             -call 0x47a8cc
    cpu.esp -= 4;
    sub_47a8cc(app, cpu);
    if (cpu.terminate) return;
    // 00494f23  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494f25  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00494f28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494f29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494f2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494f2b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00494f2e:
    // 00494f2e  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00494f30  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00494f32  0f8455ffffff           -je 0x494e8d
    if (cpu.flags.zf)
    {
        goto L_0x00494e8d;
    }
    // 00494f38  ba48000000             -mov edx, 0x48
    cpu.edx = 72 /*0x48*/;
    // 00494f3d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00494f3f  e858bdfeff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00494f44  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00494f48  8d5638                 -lea edx, [esi + 0x38]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00494f4b  e8105a0000             -call 0x49a960
    cpu.esp -= 4;
    sub_49a960(app, cpu);
    if (cpu.terminate) return;
    // 00494f50  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00494f53  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494f58  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00494f5a  66897a06               -mov word ptr [edx + 6], di
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = cpu.di;
    // 00494f5e  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00494f60  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494f64  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00494f66  66894204               -mov word ptr [edx + 4], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 00494f6a  c706444e4957           -mov dword ptr [esi], 0x57494e44
    app->getMemory<x86::reg32>(cpu.esi) = 1464421956 /*0x57494e44*/;
    // 00494f70  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00494f73  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00494f77  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00494f7a  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00494f7d  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494f81  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00494f84  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00494f87  8a44241c               -mov al, byte ptr [esp + 0x1c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00494f8b  88461c                 -mov byte ptr [esi + 0x1c], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.al;
    // 00494f8e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494f90  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00494f92  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00494f94  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494f99  895620                 -mov dword ptr [esi + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00494f9c  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00494fa0  88461d                 -mov byte ptr [esi + 0x1d], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(29) /* 0x1d */) = cpu.al;
    // 00494fa3  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00494fa8  e8d7250000             -call 0x497584
    cpu.esp -= 4;
    sub_497584(app, cpu);
    if (cpu.terminate) return;
    // 00494fad  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494fb1  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00494fb6  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494fb8  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00494fbb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494fbd  e8c2250000             -call 0x497584
    cpu.esp -= 4;
    sub_497584(app, cpu);
    if (cpu.terminate) return;
    // 00494fc2  8b5e2c                 -mov ebx, dword ptr [esi + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00494fc5  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00494fc8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494fca  0f84bdfeffff           -je 0x494e8d
    if (cpu.flags.zf)
    {
        goto L_0x00494e8d;
    }
    // 00494fd0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494fd2  0f84b5feffff           -je 0x494e8d
    if (cpu.flags.zf)
    {
        goto L_0x00494e8d;
    }
    // 00494fd8  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00494fdc  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00494fdf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494fe0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494fe1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494fe2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_494fe8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494fe8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00494fea  e851feffff             -call 0x494e40
    cpu.esp -= 4;
    sub_494e40(app, cpu);
    if (cpu.terminate) return;
    // 00494fef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494ff0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00494ff2  e849feffff             -call 0x494e40
    cpu.esp -= 4;
    sub_494e40(app, cpu);
    if (cpu.terminate) return;
    // 00494ff7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494ff8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494ff8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494ff9  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00494ffd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494ffe  e83dfeffff             -call 0x494e40
    cpu.esp -= 4;
    sub_494e40(app, cpu);
    if (cpu.terminate) return;
    // 00495003  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495005  7402                   -je 0x495009
    if (cpu.flags.zf)
    {
        goto L_0x00495009;
    }
    // 00495007  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00495009:
    // 00495009  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049500a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_495010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495010  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00495012  e829feffff             -call 0x494e40
    cpu.esp -= 4;
    sub_494e40(app, cpu);
    if (cpu.terminate) return;
    // 00495017  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00495019  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49501c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049501c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049501e  e81dfeffff             -call 0x494e40
    cpu.esp -= 4;
    sub_494e40(app, cpu);
    if (cpu.terminate) return;
    // 00495023  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495025  7402                   -je 0x495029
    if (cpu.flags.zf)
    {
        goto L_0x00495029;
    }
    // 00495027  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00495029:
    // 00495029  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_495030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495030  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495031  8b15d0c94c00           -mov edx, dword ptr [0x4cc9d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032400) /* 0x4cc9d0 */);
    // 00495037  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00495039  7532                   -jne 0x49506d
    if (!cpu.flags.zf)
    {
        goto L_0x0049506d;
    }
    // 0049503b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049503c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049503d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00495042  8915408f5200           -mov dword ptr [0x528f40], edx
    app->getMemory<x86::reg32>(x86::reg32(5410624) /* 0x528f40 */) = cpu.edx;
L_0x00495048:
    // 00495048  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049504d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049504f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495052  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495054  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00495056  40                     -inc eax
    (cpu.eax)++;
    // 00495057  89813c8f5200           -mov dword ptr [ecx + 0x528f3c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5410620) /* 0x528f3c */) = cpu.eax;
    // 0049505d  81f900100000           +cmp ecx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495063  75e3                   -jne 0x495048
    if (!cpu.flags.zf)
    {
        goto L_0x00495048;
    }
    // 00495065  ff05d0c94c00           -inc dword ptr [0x4cc9d0]
    (app->getMemory<x86::reg32>(x86::reg32(5032400) /* 0x4cc9d0 */))++;
    // 0049506b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049506c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049506d:
    // 0049506d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049506e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_495070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495070  d1fb                   +sar ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00495072  e935e20000             -jmp 0x4a32ac
    return sub_4a32ac(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_495078(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495078  01db                   +add ebx, ebx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049507a  e92de20000             -jmp 0x4a32ac
    return sub_4a32ac(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_495080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495080  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495081  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495083  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049508a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049508c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049508e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495090  e817e20000             -call 0x4a32ac
    cpu.esp -= 4;
    sub_4a32ac(app, cpu);
    if (cpu.terminate) return;
    // 00495095  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495096  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
