#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x90 */
void Application::sub_4852e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004852e0);
L_0x004852e0:
    // 004852e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004852e2  e839d0ffff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 004852e7  e8e0ffffff             -call 0x4852cc
    cpu.esp -= 4;
    sub_4852cc(app, cpu);
    if (cpu.terminate) return;
    // 004852ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004852ee  74f0                   -je 0x4852e0
    if (cpu.flags.zf)
    {
        goto L_0x004852e0;
    }
    // 004852f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4852f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004852f4);
    // 004852f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004852f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004852f6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004852f7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004852f9:
    // 004852f9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004852fb  e820d0ffff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 00485300  e8c7ffffff             -call 0x4852cc
    cpu.esp -= 4;
    sub_4852cc(app, cpu);
    if (cpu.terminate) return;
    // 00485305  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485307  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485309  e863c5ffff             -call 0x481871
    cpu.esp -= 4;
    sub_481871(app, cpu);
    if (cpu.terminate) return;
    // 0048530e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485310  7508                   -jne 0x48531a
    if (!cpu.flags.zf)
    {
        goto L_0x0048531a;
    }
    // 00485312  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485314  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485316  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485317  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485318  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485319  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048531a:
    // 0048531a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048531c  74db                   -je 0x4852f9
    if (cpu.flags.zf)
    {
        goto L_0x004852f9;
    }
    // 0048531e  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485320  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485322  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485323  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485324  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485325  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485328(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485328);
    // 00485328  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485329  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048532a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048532c  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 00485331  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00485333  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00485335:
    // 00485335  e892ffffff             -call 0x4852cc
    cpu.esp -= 4;
    sub_4852cc(app, cpu);
    if (cpu.terminate) return;
    // 0048533a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048533c  7403                   -je 0x485341
    if (cpu.flags.zf)
    {
        goto L_0x00485341;
    }
    // 0048533e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048533f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485340  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485341:
    // 00485341  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485343  e8d8cfffff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 00485348  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 0048534d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048534f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485351  7ce2                   -jl 0x485335
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485335;
    }
    // 00485353  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485355  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485356  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485357  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485358(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485358);
    // 00485358  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485359  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048535a  833d54894d0000         +cmp dword ptr [0x4d8954], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485361  741d                   -je 0x485380
    if (cpu.flags.zf)
    {
        goto L_0x00485380;
    }
L_0x00485363:
    // 00485363  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00485368  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 0048536d  b810914d00             -mov eax, 0x4d9110
    cpu.eax = 5083408 /*0x4d9110*/;
    // 00485372  890da8135600           -mov dword ptr [0x5613a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5641128) /* 0x5613a8 */) = cpu.ecx;
    // 00485378  e80f310000             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0048537d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048537e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048537f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485380:
    // 00485380  e8e32f0000             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 00485385  a354894d00             -mov dword ptr [0x4d8954], eax
    app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */) = cpu.eax;
    // 0048538a  ebd7                   -jmp 0x485363
    goto L_0x00485363;
}

/* align: skip  */
void Application::sub_48538c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048538c);
    // 0048538c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048538d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048538f  8915a8135600           -mov dword ptr [0x5613a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5641128) /* 0x5613a8 */) = cpu.edx;
    // 00485395  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485396  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_485398(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485398);
L_0x00485398:
    // 00485398  e803b1ffff             -call 0x4804a0
    cpu.esp -= 4;
    sub_4804a0(app, cpu);
    if (cpu.terminate) return;
    // 0048539d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048539f  75f7                   -jne 0x485398
    if (!cpu.flags.zf)
    {
        goto L_0x00485398;
    }
    // 004853a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4853a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004853a4);
    // 004853a4  e847b0ffff             -call 0x4803f0
    cpu.esp -= 4;
    sub_4803f0(app, cpu);
    if (cpu.terminate) return;
    // 004853a9  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004853ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4853b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004853b0);
    // 004853b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004853b1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004853b6  e811000000             -call 0x4853cc
    cpu.esp -= 4;
    sub_4853cc(app, cpu);
    if (cpu.terminate) return;
    // 004853bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4853c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004853c0);
    // 004853c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004853c1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004853c3  e804000000             -call 0x4853cc
    cpu.esp -= 4;
    sub_4853cc(app, cpu);
    if (cpu.terminate) return;
    // 004853c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4853cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004853cc);
    // 004853cc  e823000000             -call 0x4853f4
    cpu.esp -= 4;
    sub_4853f4(app, cpu);
    if (cpu.terminate) return;
    // 004853d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004853d3  7402                   -je 0x4853d7
    if (cpu.flags.zf)
    {
        goto L_0x004853d7;
    }
    // 004853d5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x004853d7:
    // 004853d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4853d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004853d8);
    // 004853d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004853d9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004853de  e811000000             -call 0x4853f4
    cpu.esp -= 4;
    sub_4853f4(app, cpu);
    if (cpu.terminate) return;
    // 004853e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4853e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004853e8);
    // 004853e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004853e9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004853eb  e804000000             -call 0x4853f4
    cpu.esp -= 4;
    sub_4853f4(app, cpu);
    if (cpu.terminate) return;
    // 004853f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4853f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004853f4);
    // 004853f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004853f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004853f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004853f7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004853f8  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004853fb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004853fd  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00485401  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00485403  e88cad0100             -call 0x4a0194
    cpu.esp -= 4;
    sub_4a0194(app, cpu);
    if (cpu.terminate) return;
    // 00485408  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048540a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048540c  7417                   -je 0x485425
    if (cpu.flags.zf)
    {
        goto L_0x00485425;
    }
L_0x0048540e:
    // 0048540e  833d14bb4d0000         +cmp dword ptr [0x4dbb14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094164) /* 0x4dbb14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485415  0f8590000000           -jne 0x4854ab
    if (!cpu.flags.zf)
    {
        goto L_0x004854ab;
    }
    // 0048541b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048541d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00485420  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485421  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485422  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485423  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485424  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485425:
    // 00485425  b8c8000000             -mov eax, 0xc8
    cpu.eax = 200 /*0xc8*/;
    // 0048542a  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048542c  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485430  e85fb80100             -call 0x4a0c94
    cpu.esp -= 4;
    sub_4a0c94(app, cpu);
    if (cpu.terminate) return;
    // 00485435  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485436  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00485438  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048543c  e897060000             -call 0x485ad8
    cpu.esp -= 4;
    sub_485ad8(app, cpu);
    if (cpu.terminate) return;
    // 00485441  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00485444  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00485446  7511                   -jne 0x485459
    if (!cpu.flags.zf)
    {
        goto L_0x00485459;
    }
    // 00485448  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048544c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048544e  74be                   -je 0x48540e
    if (cpu.flags.zf)
    {
        goto L_0x0048540e;
    }
    // 00485450  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485452  e869090000             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
    // 00485457  ebb5                   -jmp 0x48540e
    goto L_0x0048540e;
L_0x00485459:
    // 00485459  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048545d  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0048545f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00485461  e8ded4ffff             -call 0x482944
    cpu.esp -= 4;
    sub_482944(app, cpu);
    if (cpu.terminate) return;
    // 00485466  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485468  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048546a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048546c  742f                   -je 0x48549d
    if (cpu.flags.zf)
    {
        goto L_0x0048549d;
    }
    // 0048546e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00485471  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485473  bbc2010000             -mov ebx, 0x1c2
    cpu.ebx = 450 /*0x1c2*/;
    // 00485478  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048547b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048547d  05c8000000             +add eax, 0xc8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(200 /*0xc8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00485482  e80db80100             -call 0x4a0c94
    cpu.esp -= 4;
    sub_4a0c94(app, cpu);
    if (cpu.terminate) return;
    // 00485487  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048548a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048548e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00485490  e833090000             -call 0x485dc8
    cpu.esp -= 4;
    sub_485dc8(app, cpu);
    if (cpu.terminate) return;
    // 00485495  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00485498  a3088a4d00             -mov dword ptr [0x4d8a08], eax
    app->getMemory<x86::reg32>(x86::reg32(5081608) /* 0x4d8a08 */) = cpu.eax;
L_0x0048549d:
    // 0048549d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004854a1  e81a090000             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
    // 004854a6  e963ffffff             -jmp 0x48540e
    goto L_0x0048540e;
L_0x004854ab:
    // 004854ab  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004854af  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004854b1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004854b3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004854b5  ff1514bb4d00           -call dword ptr [0x4dbb14]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5094164) /* 0x4dbb14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004854bb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004854bd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004854bf  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004854c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4854d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004854d0);
    // 004854d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004854d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004854d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004854d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004854d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004854d5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004854d7  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004854da  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004854dc  8b400d                 -mov eax, dword ptr [eax + 0xd]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004854df  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004854e2  a3b8b44d00             -mov dword ptr [0x4db4b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5092536) /* 0x4db4b8 */) = cpu.eax;
    // 004854e7  8b420e                 -mov eax, dword ptr [edx + 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(14) /* 0xe */);
    // 004854ea  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004854ef  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004854f2  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004854f7  a3bcb44d00             -mov dword ptr [0x4db4bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5092540) /* 0x4db4bc */) = cpu.eax;
    // 004854fc  8b420f                 -mov eax, dword ptr [edx + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004854ff  89152cb54d00           -mov dword ptr [0x4db52c], edx
    app->getMemory<x86::reg32>(x86::reg32(5092652) /* 0x4db52c */) = cpu.edx;
    // 00485505  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00485508  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048550a  a3c8b44d00             -mov dword ptr [0x4db4c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5092552) /* 0x4db4c8 */) = cpu.eax;
    // 0048550f  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00485512  891d28b54d00           -mov dword ptr [0x4db528], ebx
    app->getMemory<x86::reg32>(x86::reg32(5092648) /* 0x4db528 */) = cpu.ebx;
    // 00485518  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0048551b  8935c4b44d00           -mov dword ptr [0x4db4c4], esi
    app->getMemory<x86::reg32>(x86::reg32(5092548) /* 0x4db4c4 */) = cpu.esi;
    // 00485521  a3ccb44d00             -mov dword ptr [0x4db4cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5092556) /* 0x4db4cc */) = cpu.eax;
    // 00485526  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00485528  a1c8b44d00             -mov eax, dword ptr [0x4db4c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092552) /* 0x4db4c8 */);
    // 0048552d  893d5cb54d00           -mov dword ptr [0x4db55c], edi
    app->getMemory<x86::reg32>(x86::reg32(5092700) /* 0x4db55c */) = cpu.edi;
    // 00485533  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00485535  893d58b54d00           -mov dword ptr [0x4db558], edi
    app->getMemory<x86::reg32>(x86::reg32(5092696) /* 0x4db558 */) = cpu.edi;
    // 0048553b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048553d  891dd0b44d00           -mov dword ptr [0x4db4d0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5092560) /* 0x4db4d0 */) = cpu.ebx;
    // 00485543  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485545  891dd4b44d00           -mov dword ptr [0x4db4d4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5092564) /* 0x4db4d4 */) = cpu.ebx;
    // 0048554b  668b420a               -mov ax, word ptr [edx + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0048554f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00485551  a320b54d00             -mov dword ptr [0x4db520], eax
    app->getMemory<x86::reg32>(x86::reg32(5092640) /* 0x4db520 */) = cpu.eax;
    // 00485556  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00485559  890d34b54d00           -mov dword ptr [0x4db534], ecx
    app->getMemory<x86::reg32>(x86::reg32(5092660) /* 0x4db534 */) = cpu.ecx;
    // 0048555f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00485561  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485563  891d30b54d00           -mov dword ptr [0x4db530], ebx
    app->getMemory<x86::reg32>(x86::reg32(5092656) /* 0x4db530 */) = cpu.ebx;
    // 00485569  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048556b  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0048556e  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 00485574  a3c0b44d00             -mov dword ptr [0x4db4c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5092544) /* 0x4db4c0 */) = cpu.eax;
    // 00485579  8b5902                 -mov ebx, dword ptr [ecx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0048557c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048557e  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00485581  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00485583  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00485586  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 0048558c  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048558f  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00485592  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00485594  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00485597  a324b54d00             -mov dword ptr [0x4db524], eax
    app->getMemory<x86::reg32>(x86::reg32(5092644) /* 0x4db524 */) = cpu.eax;
    // 0048559c  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048559f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004855a2  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004855a5  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004855a8  740c                   -je 0x4855b6
    if (cpu.flags.zf)
    {
        goto L_0x004855b6;
    }
    // 004855aa  813d20b54d00ff000000   +cmp dword ptr [0x4db520], 0xff
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092640) /* 0x4db520 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004855b4  7e38                   -jle 0x4855ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004855ee;
    }
L_0x004855b6:
    // 004855b6  c7054cb54d00fc234a00   -mov dword ptr [0x4db54c], 0x4a23fc
    app->getMemory<x86::reg32>(x86::reg32(5092684) /* 0x4db54c */) = 4858876 /*0x4a23fc*/;
L_0x004855c0:
    // 004855c0  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004855c5  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004855c7  b8e0b44d00             -mov eax, 0x4db4e0
    cpu.eax = 5092576 /*0x4db4e0*/;
    // 004855cc  893dd8b44d00           -mov dword ptr [0x4db4d8], edi
    app->getMemory<x86::reg32>(x86::reg32(5092568) /* 0x4db4d8 */) = cpu.edi;
    // 004855d2  893ddcb44d00           -mov dword ptr [0x4db4dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5092572) /* 0x4db4dc */) = cpu.edi;
    // 004855d8  e8af2e0000             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 004855dd  e886c80100             -call 0x4a1e68
    cpu.esp -= 4;
    sub_4a1e68(app, cpu);
    if (cpu.terminate) return;
    // 004855e2  893d50b54d00           -mov dword ptr [0x4db550], edi
    app->getMemory<x86::reg32>(x86::reg32(5092688) /* 0x4db550 */) = cpu.edi;
    // 004855e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004855ee:
    // 004855ee  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004855f3  8d4220                 -lea eax, [edx + 0x20]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004855f6  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004855fa  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004855fc  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00485603  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00485605  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048560a  77aa                   -ja 0x4855b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004855b6;
    }
    // 0048560c  c7054cb54d00d0234a00   -mov dword ptr [0x4db54c], 0x4a23d0
    app->getMemory<x86::reg32>(x86::reg32(5092684) /* 0x4db54c */) = 4858832 /*0x4a23d0*/;
    // 00485616  eba8                   -jmp 0x4855c0
    goto L_0x004855c0;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_485620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485620);
    // 00485620  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485621  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485622  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485623  b92d000000             -mov ecx, 0x2d
    cpu.ecx = 45 /*0x2d*/;
    // 00485628  beacb44d00             -mov esi, 0x4db4ac
    cpu.esi = 5092524 /*0x4db4ac*/;
    // 0048562d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048562f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485631  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485632  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485633  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485634  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485638(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485638);
    // 00485638  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485639  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048563a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048563b  b92d000000             -mov ecx, 0x2d
    cpu.ecx = 45 /*0x2d*/;
    // 00485640  bfacb44d00             -mov edi, 0x4db4ac
    cpu.edi = 5092524 /*0x4db4ac*/;
    // 00485645  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00485647  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485649  e876c80100             -call 0x4a1ec4
    cpu.esp -= 4;
    sub_4a1ec4(app, cpu);
    if (cpu.terminate) return;
    // 0048564e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048564f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485650  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485651  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_485660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485660);
    // 00485660  a1d0b44d00             -mov eax, dword ptr [0x4db4d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092560) /* 0x4db4d0 */);
    // 00485665  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485668(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485668);
    // 00485668  a3b0b44d00             -mov dword ptr [0x4db4b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5092528) /* 0x4db4b0 */) = cpu.eax;
    // 0048566d  8915b4b44d00           -mov dword ptr [0x4db4b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5092532) /* 0x4db4b4 */) = cpu.edx;
    // 00485673  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485674(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485674);
    // 00485674  a3c4b44d00             -mov dword ptr [0x4db4c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5092548) /* 0x4db4c4 */) = cpu.eax;
    // 00485679  e9eac70100             -jmp 0x4a1e68
    return sub_4a1e68(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485680);
    // 00485680  a1c4b44d00             -mov eax, dword ptr [0x4db4c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092548) /* 0x4db4c4 */);
    // 00485685  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_485690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485690);
    // 00485690  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485691  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485692  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485693  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00485696  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00485698  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048569c  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004856a0  0fb63578904d00         -movzx esi, byte ptr [0x4d9078]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */));
    // 004856a7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004856aa  83c607                 -add esi, 7
    (cpu.esi) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004856ad  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004856af  6683e6f8               -and si, 0xfff8
    cpu.si &= x86::reg16(x86::sreg16(65528 /*0xfff8*/));
    // 004856b3  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004856b7:
    // 004856b7  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004856bb  4a                     -dec edx
    (cpu.edx)--;
    // 004856bc  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004856c0  83faff                 +cmp edx, -1
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
    // 004856c3  0f847f000000           -je 0x485748
    if (cpu.flags.zf)
    {
        goto L_0x00485748;
    }
    // 004856c9  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004856cc  3b7c2408               +cmp edi, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004856d0  7d22                   -jge 0x4856f4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004856f4;
    }
L_0x004856d2:
    // 004856d2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004856d4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004856d6  e865cd0100             -call 0x4a2440
    cpu.esp -= 4;
    sub_4a2440(app, cpu);
    if (cpu.terminate) return;
    // 004856db  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004856dd  83fe10                 +cmp esi, 0x10
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004856e0  7315                   -jae 0x4856f7
    if (!cpu.flags.cf)
    {
        goto L_0x004856f7;
    }
    // 004856e2  83fe08                 +cmp esi, 8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004856e5  7504                   -jne 0x4856eb
    if (!cpu.flags.zf)
    {
        goto L_0x004856eb;
    }
    // 004856e7  41                     -inc ecx
    (cpu.ecx)++;
    // 004856e8  8851ff                 -mov byte ptr [ecx - 1], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.dl;
L_0x004856eb:
    // 004856eb  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004856ef  47                     -inc edi
    (cpu.edi)++;
    // 004856f0  39df                   +cmp edi, ebx
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
    // 004856f2  7cde                   -jl 0x4856d2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004856d2;
    }
L_0x004856f4:
    // 004856f4  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004856f5  ebc0                   -jmp 0x4856b7
    goto L_0x004856b7;
L_0x004856f7:
    // 004856f7  7713                   -ja 0x48570c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048570c;
    }
    // 004856f9  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004856fc  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 00485700  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485704  47                     -inc edi
    (cpu.edi)++;
    // 00485705  39df                   +cmp edi, ebx
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
    // 00485707  7cc9                   -jl 0x4856d2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004856d2;
    }
    // 00485709  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048570a  ebab                   -jmp 0x4856b7
    goto L_0x004856b7;
L_0x0048570c:
    // 0048570c  83fe18                 +cmp esi, 0x18
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048570f  72da                   -jb 0x4856eb
    if (cpu.flags.cf)
    {
        goto L_0x004856eb;
    }
    // 00485711  7617                   -jbe 0x48572a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048572a;
    }
    // 00485713  83fe20                 +cmp esi, 0x20
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485716  75d3                   -jne 0x4856eb
    if (!cpu.flags.zf)
    {
        goto L_0x004856eb;
    }
    // 00485718  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048571b  8941fc                 -mov dword ptr [ecx - 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0048571e  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485722  47                     -inc edi
    (cpu.edi)++;
    // 00485723  39df                   +cmp edi, ebx
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
    // 00485725  7cab                   -jl 0x4856d2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004856d2;
    }
    // 00485727  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485728  eb8d                   -jmp 0x4856b7
    goto L_0x004856b7;
L_0x0048572a:
    // 0048572a  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0048572f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485731  e805ce0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 00485736  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00485739  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048573d  47                     -inc edi
    (cpu.edi)++;
    // 0048573e  39df                   +cmp edi, ebx
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
    // 00485740  7c90                   -jl 0x4856d2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004856d2;
    }
    // 00485742  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485743  e96fffffff             -jmp 0x4856b7
    goto L_0x004856b7;
L_0x00485748:
    // 00485748  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048574b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048574c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048574d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048574e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485754(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485754);
    // 00485754  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485755  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485756  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485757  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485759  a078904d00             -mov al, byte ptr [0x4d9078]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 0048575e  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00485761  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00485763  8b1568904d00           -mov edx, dword ptr [0x4d9068]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 00485769  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048576b  a170904d00             -mov eax, dword ptr [0x4d9070]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */);
    // 00485770  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00485772  8b1d6c904d00           -mov ebx, dword ptr [0x4d906c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 00485778  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048577a  a174904d00             -mov eax, dword ptr [0x4d9074]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */);
    // 0048577f  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485781  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00485784  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00485787  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485789  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048578c  c1e203                 +shl edx, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0048578f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00485791  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00485794  83c012                 -add eax, 0x12
    (cpu.eax) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 00485797  83f908                 +cmp ecx, 8
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048579a  7505                   -jne 0x4857a1
    if (!cpu.flags.zf)
    {
        goto L_0x004857a1;
    }
    // 0048579c  0500030000             -add eax, 0x300
    (cpu.eax) += x86::reg32(x86::sreg32(768 /*0x300*/));
L_0x004857a1:
    // 004857a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4857a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004857a8);
    // 004857a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004857a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004857aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004857ab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004857ac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004857ad  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004857ae  81ec08030000           -sub esp, 0x308
    (cpu.esp) -= x86::reg32(x86::sreg32(776 /*0x308*/));
    // 004857b4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004857b6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004857b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004857ba  a078904d00             -mov al, byte ptr [0x4d9078]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 004857bf  8b1568904d00           -mov edx, dword ptr [0x4d9068]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004857c5  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004857c8  8b2d74904d00           -mov ebp, dword ptr [0x4d9074]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */);
    // 004857ce  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004857d0  8b1d6c904d00           -mov ebx, dword ptr [0x4d906c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 004857d6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004857d8  a170904d00             -mov eax, dword ptr [0x4d9070]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */);
    // 004857dd  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004857df  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004857e1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004857e6  89842404030000         -mov dword ptr [esp + 0x304], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.eax;
    // 004857ed  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004857ef  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004857f1  e845cd0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 004857f6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004857fb  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004857fe  0f8564010000           -jne 0x485968
    if (!cpu.flags.zf)
    {
        goto L_0x00485968;
    }
    // 00485804  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00485806:
    // 00485806  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00485809  e82dcd0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 0048580e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00485813  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485816  0f8553010000           -jne 0x48596f
    if (!cpu.flags.zf)
    {
        goto L_0x0048596f;
    }
    // 0048581c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0048581e:
    // 0048581e  8d4102                 -lea eax, [ecx + 2]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00485821  e815cd0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 00485826  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048582b  8d4103                 -lea eax, [ecx + 3]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 0048582e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00485830  e806cd0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 00485835  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048583a  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048583d  0f8536010000           -jne 0x485979
    if (!cpu.flags.zf)
    {
        goto L_0x00485979;
    }
    // 00485843  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x00485848:
    // 00485848  8d4105                 -lea eax, [ecx + 5]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0048584b  e8ebcc0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 00485850  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00485855  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485858  0f8522010000           -jne 0x485980
    if (!cpu.flags.zf)
    {
        goto L_0x00485980;
    }
    // 0048585e  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
L_0x00485863:
    // 00485863  8d4107                 -lea eax, [ecx + 7]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 00485866  e8d0cc0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 0048586b  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00485870  8b1568904d00           -mov edx, dword ptr [0x4d9068]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 00485876  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00485879  e8bdcc0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 0048587e  a164904d00             -mov eax, dword ptr [0x4d9064]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083236) /* 0x4d9064 */);
    // 00485883  2b0574904d00           -sub eax, dword ptr [0x4d9074]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */)));
    // 00485889  8d510a                 -lea edx, [ecx + 0xa]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(10) /* 0xa */);
    // 0048588c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00485891  89942400030000         -mov dword ptr [esp + 0x300], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.edx;
    // 00485898  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048589a  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004858a1  e895cc0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 004858a6  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004858ab  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 004858b2  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004858b5  e881cc0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 004858ba  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004858bf  8d410e                 -lea eax, [ecx + 0xe]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 004858c2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004858c4  e872cc0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 004858c9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004858ce  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004858d1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004858d3  e863cc0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 004858d8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004858dd  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004858e2  8d4111                 -lea eax, [ecx + 0x11]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 004858e5  83c612                 -add esi, 0x12
    (cpu.esi) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 004858e8  e84ecc0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 004858ed  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004858f0  7532                   -jne 0x485924
    if (!cpu.flags.zf)
    {
        goto L_0x00485924;
    }
    // 004858f2  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004858f4  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004858f9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004858fb  e850660100             -call 0x49bf50
    cpu.esp -= 4;
    sub_49bf50(app, cpu);
    if (cpu.terminate) return;
    // 00485900  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00485902:
    // 00485902  46                     -inc esi
    (cpu.esi)++;
    // 00485903  46                     -inc esi
    (cpu.esi)++;
    // 00485904  8a1404                 -mov dl, byte ptr [esp + eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 00485907  46                     -inc esi
    (cpu.esi)++;
    // 00485908  8a5c0402               -mov bl, byte ptr [esp + eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 1);
    // 0048590c  8a4c0401               -mov cl, byte ptr [esp + eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 00485910  885efd                 -mov byte ptr [esi - 3], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-3) /* -0x3 */) = cpu.bl;
    // 00485913  884efe                 -mov byte ptr [esi - 2], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.cl;
    // 00485916  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00485919  8856ff                 -mov byte ptr [esi - 1], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 0048591c  3d00030000             +cmp eax, 0x300
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485921  75df                   -jne 0x485902
    if (!cpu.flags.zf)
    {
        goto L_0x00485902;
    }
    // 00485923  90                     -nop 
    ;
L_0x00485924:
    // 00485924  a174904d00             -mov eax, dword ptr [0x4d9074]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */);
    // 00485929  8b0d6c904d00           -mov ecx, dword ptr [0x4d906c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 0048592f  8b1d68904d00           -mov ebx, dword ptr [0x4d9068]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 00485935  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485937  8b156c904d00           -mov edx, dword ptr [0x4d906c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 0048593d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048593f  a170904d00             -mov eax, dword ptr [0x4d9070]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */);
    // 00485944  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485945  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485947  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00485949  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048594b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048594d  e83efdffff             -call 0x485690
    cpu.esp -= 4;
    sub_485690(app, cpu);
    if (cpu.terminate) return;
    // 00485952  803d78904d0010         +cmp byte ptr [0x4d9078], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485959  742c                   -je 0x485987
    if (cpu.flags.zf)
    {
        goto L_0x00485987;
    }
    // 0048595b  81c408030000           -add esp, 0x308
    (cpu.esp) += x86::reg32(x86::sreg32(776 /*0x308*/));
    // 00485961  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485962  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485963  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485964  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485965  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485966  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485967  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485968:
    // 00485968  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0048596a  e997feffff             -jmp 0x485806
    goto L_0x00485806;
L_0x0048596f:
    // 0048596f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00485974  e9a5feffff             -jmp 0x48581e
    goto L_0x0048581e;
L_0x00485979:
    // 00485979  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0048597b  e9c8feffff             -jmp 0x485848
    goto L_0x00485848;
L_0x00485980:
    // 00485980  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00485982  e9dcfeffff             -jmp 0x485863
    goto L_0x00485863;
L_0x00485987:
    // 00485987  8b9c2404030000         -mov ebx, dword ptr [esp + 0x304]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0048598e  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00485991  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00485993  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00485995  e8bacb0100             -call 0x4a2554
    cpu.esp -= 4;
    sub_4a2554(app, cpu);
    if (cpu.terminate) return;
    // 0048599a  81c408030000           -add esp, 0x308
    (cpu.esp) += x86::reg32(x86::sreg32(776 /*0x308*/));
    // 004859a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4859a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004859a8);
    // 004859a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004859a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004859aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004859ab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004859ac  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004859af  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004859b1  e89efdffff             -call 0x485754
    cpu.esp -= 4;
    sub_485754(app, cpu);
    if (cpu.terminate) return;
    // 004859b6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004859b8  e893390100             -call 0x499350
    cpu.esp -= 4;
    sub_499350(app, cpu);
    if (cpu.terminate) return;
    // 004859bd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004859bf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004859c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004859c3  750a                   -jne 0x4859cf
    if (!cpu.flags.zf)
    {
        goto L_0x004859cf;
    }
    // 004859c5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004859c7  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004859ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004859cf:
    // 004859cf  e8d4fdffff             -call 0x4857a8
    cpu.esp -= 4;
    sub_4857a8(app, cpu);
    if (cpu.terminate) return;
    // 004859d4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004859d6  e8c5a10100             -call 0x49fba0
    cpu.esp -= 4;
    sub_49fba0(app, cpu);
    if (cpu.terminate) return;
    // 004859db  e84cafffff             -call 0x48092c
    cpu.esp -= 4;
    sub_48092c(app, cpu);
    if (cpu.terminate) return;
    // 004859e0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004859e2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004859e4  e837000000             -call 0x485a20
    cpu.esp -= 4;
    sub_485a20(app, cpu);
    if (cpu.terminate) return;
    // 004859e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004859eb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004859ed  e8d2a10100             -call 0x49fbc4
    cpu.esp -= 4;
    sub_49fbc4(app, cpu);
    if (cpu.terminate) return;
    // 004859f2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004859f4  e8bf390100             -call 0x4993b8
    cpu.esp -= 4;
    sub_4993b8(app, cpu);
    if (cpu.terminate) return;
    // 004859f9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004859fb  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004859fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_485a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485a10);
    // 00485a10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485a11  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00485a16  e811000000             -call 0x485a2c
    cpu.esp -= 4;
    sub_485a2c(app, cpu);
    if (cpu.terminate) return;
    // 00485a1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485a20);
    // 00485a20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485a21  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485a23  e804000000             -call 0x485a2c
    cpu.esp -= 4;
    sub_485a2c(app, cpu);
    if (cpu.terminate) return;
    // 00485a28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485a2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485a2c);
    // 00485a2c  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00485a2f  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00485a32  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00485a36  8b15048a4d00           -mov edx, dword ptr [0x4d8a04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */);
    // 00485a3c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00485a3e  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00485a42  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00485a44  e823000000             -call 0x485a6c
    cpu.esp -= 4;
    sub_485a6c(app, cpu);
    if (cpu.terminate) return;
    // 00485a49  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00485a4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485a50);
    // 00485a50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485a51  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00485a56  e811000000             -call 0x485a6c
    cpu.esp -= 4;
    sub_485a6c(app, cpu);
    if (cpu.terminate) return;
    // 00485a5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485a60);
    // 00485a60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485a61  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485a63  e804000000             -call 0x485a6c
    cpu.esp -= 4;
    sub_485a6c(app, cpu);
    if (cpu.terminate) return;
    // 00485a68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485a6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485a6c);
    // 00485a6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485a6d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485a6e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485a6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485a70  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00485a73  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00485a75  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485a77  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485a7b  e894d7ffff             -call 0x483214
    cpu.esp -= 4;
    sub_483214(app, cpu);
    if (cpu.terminate) return;
    // 00485a80  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00485a82  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485a84  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00485a88  e8b3ceffff             -call 0x482940
    cpu.esp -= 4;
    sub_482940(app, cpu);
    if (cpu.terminate) return;
    // 00485a8d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00485a8f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00485a91  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00485a93  e89c010000             -call 0x485c34
    cpu.esp -= 4;
    sub_485c34(app, cpu);
    if (cpu.terminate) return;
    // 00485a98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485a9a  7508                   -jne 0x485aa4
    if (!cpu.flags.zf)
    {
        goto L_0x00485aa4;
    }
    // 00485a9c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00485a9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485aa0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485aa1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485aa2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485aa3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485aa4:
    // 00485aa4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00485aa7  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00485aa9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00485aab  e820030000             -call 0x485dd0
    cpu.esp -= 4;
    sub_485dd0(app, cpu);
    if (cpu.terminate) return;
    // 00485ab0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485ab2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00485ab5  e806030000             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
    // 00485aba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485abc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00485abf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ac0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ac1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ac2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ac3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_485ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485ad0);
    // 00485ad0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00485ad2  e98936fdff             -jmp 0x459160
    return sub_459160(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_485ad8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485ad8);
    // 00485ad8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485ad9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485ada  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485adb  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00485ade  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00485ae2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00485ae4  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00485ae6  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00485ae8  ba05030000             -mov edx, 0x305
    cpu.edx = 773 /*0x305*/;
    // 00485aed  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485aef  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00485af3  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00485af7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00485af9  7504                   -jne 0x485aff
    if (!cpu.flags.zf)
    {
        goto L_0x00485aff;
    }
    // 00485afb  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x00485aff:
    // 00485aff  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00485b01  7502                   -jne 0x485b05
    if (!cpu.flags.zf)
    {
        goto L_0x00485b05;
    }
    // 00485b03  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
L_0x00485b05:
    // 00485b05  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00485b09  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485b0d  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00485b0f  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 00485b15  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485b17  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 00485b1e  e84d2ffdff             -call 0x458a70
    cpu.esp -= 4;
    sub_458a70(app, cpu);
    if (cpu.terminate) return;
    // 00485b23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485b25  0f85b1000000           -jne 0x485bdc
    if (!cpu.flags.zf)
    {
        goto L_0x00485bdc;
    }
    // 00485b2b  833d14944d0000         +cmp dword ptr [0x4d9414], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084180) /* 0x4d9414 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485b32  7409                   -je 0x485b3d
    if (cpu.flags.zf)
    {
        goto L_0x00485b3d;
    }
    // 00485b34  803d90934d0000         +cmp byte ptr [0x4d9390], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5084048) /* 0x4d9390 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485b3b  750d                   -jne 0x485b4a
    if (!cpu.flags.zf)
    {
        goto L_0x00485b4a;
    }
L_0x00485b3d:
    // 00485b3d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00485b41  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00485b44  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b47  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00485b4a:
    // 00485b4a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00485b4e  b890934d00             -mov eax, 0x4d9390
    cpu.eax = 5084048 /*0x4d9390*/;
    // 00485b53  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00485b55  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485b57  e8142ffdff             -call 0x458a70
    cpu.esp -= 4;
    sub_458a70(app, cpu);
    if (cpu.terminate) return;
    // 00485b5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485b5e  74dd                   -je 0x485b3d
    if (cpu.flags.zf)
    {
        goto L_0x00485b3d;
    }
    // 00485b60  8b1d1c944d00           -mov ebx, dword ptr [0x4d941c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5084188) /* 0x4d941c */);
    // 00485b66  8b1510944d00           -mov edx, dword ptr [0x4d9410]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5084176) /* 0x4d9410 */);
    // 00485b6c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00485b6e  e80d2afdff             -call 0x458580
    cpu.esp -= 4;
    sub_458580(app, cpu);
    if (cpu.terminate) return;
    // 00485b73  a31c944d00             -mov dword ptr [0x4d941c], eax
    app->getMemory<x86::reg32>(x86::reg32(5084188) /* 0x4d941c */) = cpu.eax;
    // 00485b78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485b7a  751e                   -jne 0x485b9a
    if (!cpu.flags.zf)
    {
        goto L_0x00485b9a;
    }
L_0x00485b7c:
    // 00485b7c  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00485b80  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485b82  75b9                   -jne 0x485b3d
    if (!cpu.flags.zf)
    {
        goto L_0x00485b3d;
    }
    // 00485b84  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00485b86  e80525fdff             -call 0x458090
    cpu.esp -= 4;
    sub_458090(app, cpu);
    if (cpu.terminate) return;
    // 00485b8b  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00485b8d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00485b91  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00485b94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b97  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00485b9a:
    // 00485b9a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485b9e  a110944d00             -mov eax, dword ptr [0x4d9410]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084176) /* 0x4d9410 */);
    // 00485ba3  ff1514944d00           -call dword ptr [0x4d9414]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5084180) /* 0x4d9414 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00485ba9  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00485bac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485bae  74cc                   -je 0x485b7c
    if (cpu.flags.zf)
    {
        goto L_0x00485b7c;
    }
    // 00485bb0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485bb2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00485bb4  e8b726fdff             -call 0x458270
    cpu.esp -= 4;
    sub_458270(app, cpu);
    if (cpu.terminate) return;
    // 00485bb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485bbb  74bf                   -je 0x485b7c
    if (cpu.flags.zf)
    {
        goto L_0x00485b7c;
    }
    // 00485bbd  a118944d00             -mov eax, dword ptr [0x4d9418]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084184) /* 0x4d9418 */);
    // 00485bc2  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00485bc7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00485bc9  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00485bcd  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00485bcf  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00485bd3  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00485bd6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bd9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00485bdc:
    // 00485bdc  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00485be1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00485be3  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00485be5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00485be7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00485be9  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00485bed  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485bef  e83c2dfdff             -call 0x458930
    cpu.esp -= 4;
    sub_458930(app, cpu);
    if (cpu.terminate) return;
    // 00485bf4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485bf6  0f8541ffffff           -jne 0x485b3d
    if (!cpu.flags.zf)
    {
        goto L_0x00485b3d;
    }
    // 00485bfc  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00485bfe  e88d24fdff             -call 0x458090
    cpu.esp -= 4;
    sub_458090(app, cpu);
    if (cpu.terminate) return;
    // 00485c03  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00485c09  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00485c0b  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 00485c11  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00485c15  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00485c19  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00485c1c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c1f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485c24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485c24);
    // 00485c24  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00485c26  e8adfeffff             -call 0x485ad8
    cpu.esp -= 4;
    sub_485ad8(app, cpu);
    if (cpu.terminate) return;
    // 00485c2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485c2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485c2c);
    // 00485c2c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00485c2e  e8a5feffff             -call 0x485ad8
    cpu.esp -= 4;
    sub_485ad8(app, cpu);
    if (cpu.terminate) return;
    // 00485c33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485c34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485c34);
    // 00485c34  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485c35  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485c36  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485c37  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00485c3a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00485c3c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00485c3e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00485c40  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00485c42  7504                   -jne 0x485c48
    if (!cpu.flags.zf)
    {
        goto L_0x00485c48;
    }
    // 00485c44  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x00485c48:
    // 00485c48  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00485c4a  7502                   -jne 0x485c4e
    if (!cpu.flags.zf)
    {
        goto L_0x00485c4e;
    }
    // 00485c4c  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x00485c4e:
    // 00485c4e  ba32030000             -mov edx, 0x332
    cpu.edx = 818 /*0x332*/;
    // 00485c53  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00485c55  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485c57  e8142efdff             -call 0x458a70
    cpu.esp -= 4;
    sub_458a70(app, cpu);
    if (cpu.terminate) return;
    // 00485c5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485c5e  751a                   -jne 0x485c7a
    if (!cpu.flags.zf)
    {
        goto L_0x00485c7a;
    }
    // 00485c60  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00485c62  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00485c66  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00485c68:
    // 00485c68  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485c6c  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 00485c73  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00485c76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485c7a:
    // 00485c7a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00485c7f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00485c81  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00485c83  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00485c85  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485c87  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00485c8b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00485c8d  e89e2cfdff             -call 0x458930
    cpu.esp -= 4;
    sub_458930(app, cpu);
    if (cpu.terminate) return;
    // 00485c92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485c94  75d2                   -jne 0x485c68
    if (!cpu.flags.zf)
    {
        goto L_0x00485c68;
    }
    // 00485c96  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00485c98  e8f323fdff             -call 0x458090
    cpu.esp -= 4;
    sub_458090(app, cpu);
    if (cpu.terminate) return;
    // 00485c9d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485c9f  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 00485ca5  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00485ca9  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00485caf  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485cb3  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 00485cba  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00485cbd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485cbe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485cbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485cc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485cc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485cc4);
    // 00485cc4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485cc5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485cc6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485cc7  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00485cca  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00485cce  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00485cd0  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00485cd2  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00485cd4  ba05080000             -mov edx, 0x805
    cpu.edx = 2053 /*0x805*/;
    // 00485cd9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485cdb  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00485cdf  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00485ce3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00485ce5  7504                   -jne 0x485ceb
    if (!cpu.flags.zf)
    {
        goto L_0x00485ceb;
    }
    // 00485ce7  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x00485ceb:
    // 00485ceb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00485ced  7502                   -jne 0x485cf1
    if (!cpu.flags.zf)
    {
        goto L_0x00485cf1;
    }
    // 00485cef  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
L_0x00485cf1:
    // 00485cf1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485cf5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00485cf9  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00485cfb  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 00485d01  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485d03  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 00485d0a  e8612dfdff             -call 0x458a70
    cpu.esp -= 4;
    sub_458a70(app, cpu);
    if (cpu.terminate) return;
    // 00485d0f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485d11  751f                   -jne 0x485d32
    if (!cpu.flags.zf)
    {
        goto L_0x00485d32;
    }
    // 00485d13  833d14944d0000         +cmp dword ptr [0x4d9414], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084180) /* 0x4d9414 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485d1a  7409                   -je 0x485d25
    if (cpu.flags.zf)
    {
        goto L_0x00485d25;
    }
    // 00485d1c  803d90934d0000         +cmp byte ptr [0x4d9390], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5084048) /* 0x4d9390 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485d23  7542                   -jne 0x485d67
    if (!cpu.flags.zf)
    {
        goto L_0x00485d67;
    }
L_0x00485d25:
    // 00485d25  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00485d29  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00485d2c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d2f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00485d32:
    // 00485d32  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00485d34  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00485d36  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00485d38  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485d3a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00485d3c  e8ef2bfdff             -call 0x458930
    cpu.esp -= 4;
    sub_458930(app, cpu);
    if (cpu.terminate) return;
    // 00485d41  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485d43  740d                   -je 0x485d52
    if (cpu.flags.zf)
    {
        goto L_0x00485d52;
    }
    // 00485d45  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00485d47  e88422fdff             -call 0x457fd0
    cpu.esp -= 4;
    sub_457fd0(app, cpu);
    if (cpu.terminate) return;
    // 00485d4c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00485d50  ebd3                   -jmp 0x485d25
    goto L_0x00485d25;
L_0x00485d52:
    // 00485d52  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00485d54  e83723fdff             -call 0x458090
    cpu.esp -= 4;
    sub_458090(app, cpu);
    if (cpu.terminate) return;
    // 00485d59  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00485d5f  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 00485d65  ebbe                   -jmp 0x485d25
    goto L_0x00485d25;
L_0x00485d67:
    // 00485d67  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485d6b  b890934d00             -mov eax, 0x4d9390
    cpu.eax = 5084048 /*0x4d9390*/;
    // 00485d70  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00485d72  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485d74  e8f72cfdff             -call 0x458a70
    cpu.esp -= 4;
    sub_458a70(app, cpu);
    if (cpu.terminate) return;
    // 00485d79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485d7b  74a8                   -je 0x485d25
    if (cpu.flags.zf)
    {
        goto L_0x00485d25;
    }
    // 00485d7d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00485d7f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00485d83  e84822fdff             -call 0x457fd0
    cpu.esp -= 4;
    sub_457fd0(app, cpu);
    if (cpu.terminate) return;
    // 00485d88  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00485d8a  ff1514944d00           -call dword ptr [0x4d9414]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5084180) /* 0x4d9414 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00485d90  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00485d93  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00485d95  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00485d99  a118944d00             -mov eax, dword ptr [0x4d9418]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084184) /* 0x4d9418 */);
    // 00485d9e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00485da0  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00485da2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00485da6  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00485da9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485daa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485dab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485dac  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_485db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485db0);
    // 00485db0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00485db2  e80dffffff             -call 0x485cc4
    cpu.esp -= 4;
    sub_485cc4(app, cpu);
    if (cpu.terminate) return;
    // 00485db7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485db8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485db8);
    // 00485db8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00485dba  e805ffffff             -call 0x485cc4
    cpu.esp -= 4;
    sub_485cc4(app, cpu);
    if (cpu.terminate) return;
    // 00485dbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485dc0);
    // 00485dc0  e9cb22fdff             -jmp 0x458090
    return sub_458090(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485dc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485dc8);
    // 00485dc8  e9b327fdff             -jmp 0x458580
    return sub_458580(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485dd0);
    // 00485dd0  e97b25fdff             -jmp 0x458350
    return sub_458350(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485dd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485dd8);
    // 00485dd8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485dd9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485ddb  e89024fdff             -call 0x458270
    cpu.esp -= 4;
    sub_458270(app, cpu);
    if (cpu.terminate) return;
    // 00485de0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485de2  7502                   -jne 0x485de6
    if (!cpu.flags.zf)
    {
        goto L_0x00485de6;
    }
    // 00485de4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485de5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485de6:
    // 00485de6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485de8  e8d323fdff             -call 0x4581c0
    cpu.esp -= 4;
    sub_4581c0(app, cpu);
    if (cpu.terminate) return;
    // 00485ded  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485dee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485def(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485def);
    // 00485def  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485df0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485df1  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00485df4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485df6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00485df8  e881ca0100             -call 0x4a287e
    cpu.esp -= 4;
    sub_4a287e(app, cpu);
    if (cpu.terminate) return;
    // 00485dfd  3df4010000             +cmp eax, 0x1f4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485e02  7c03                   -jl 0x485e07
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485e07;
    }
    // 00485e04  ff0424                 -inc dword ptr [esp]
    (app->getMemory<x86::reg32>(cpu.esp))++;
L_0x00485e07:
    // 00485e07  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00485e09  e8d7ca0100             -call 0x4a28e5
    cpu.esp -= 4;
    sub_4a28e5(app, cpu);
    if (cpu.terminate) return;
    // 00485e0e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00485e10  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00485e12  7402                   -je 0x485e16
    if (cpu.flags.zf)
    {
        goto L_0x00485e16;
    }
    // 00485e14  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00485e16:
    // 00485e16  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00485e18  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00485e1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485e1e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485e1e);
    // 00485e1e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485e1f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485e20  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00485e21  2eff1548444c00         -call dword ptr cs:[0x4c4448]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998216) /* 0x4c4448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00485e28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485e2a  7508                   -jne 0x485e34
    if (!cpu.flags.zf)
    {
        goto L_0x00485e34;
    }
    // 00485e2c  e8f1c20100             -call 0x4a2122
    cpu.esp -= 4;
    sub_4a2122(app, cpu);
    if (cpu.terminate) return;
    // 00485e31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485e34:
    // 00485e34  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485e36  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e37  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_485e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485e40);
    // 00485e40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485e41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485e42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485e43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485e44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485e45  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485e46  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00485e49  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00485e4b  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00485e4d  891538944d00           -mov dword ptr [0x4d9438], edx
    app->getMemory<x86::reg32>(x86::reg32(5084216) /* 0x4d9438 */) = cpu.edx;
    // 00485e53  891534944d00           -mov dword ptr [0x4d9434], edx
    app->getMemory<x86::reg32>(x86::reg32(5084212) /* 0x4d9434 */) = cpu.edx;
    // 00485e59  891530944d00           -mov dword ptr [0x4d9430], edx
    app->getMemory<x86::reg32>(x86::reg32(5084208) /* 0x4d9430 */) = cpu.edx;
    // 00485e5f  8915dc894d00           -mov dword ptr [0x4d89dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5081564) /* 0x4d89dc */) = cpu.edx;
    // 00485e65  8915d8894d00           -mov dword ptr [0x4d89d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5081560) /* 0x4d89d8 */) = cpu.edx;
    // 00485e6b  8915d4894d00           -mov dword ptr [0x4d89d4], edx
    app->getMemory<x86::reg32>(x86::reg32(5081556) /* 0x4d89d4 */) = cpu.edx;
    // 00485e71  8915d0894d00           -mov dword ptr [0x4d89d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5081552) /* 0x4d89d0 */) = cpu.edx;
    // 00485e77  8915cc894d00           -mov dword ptr [0x4d89cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5081548) /* 0x4d89cc */) = cpu.edx;
    // 00485e7d  8915c8894d00           -mov dword ptr [0x4d89c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5081544) /* 0x4d89c8 */) = cpu.edx;
    // 00485e83  8915c4894d00           -mov dword ptr [0x4d89c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5081540) /* 0x4d89c4 */) = cpu.edx;
    // 00485e89  8915c0894d00           -mov dword ptr [0x4d89c0], edx
    app->getMemory<x86::reg32>(x86::reg32(5081536) /* 0x4d89c0 */) = cpu.edx;
    // 00485e8f  882520944d00           -mov byte ptr [0x4d9420], ah
    app->getMemory<x86::reg8>(x86::reg32(5084192) /* 0x4d9420 */) = cpu.ah;
    // 00485e95  e8dacb0100             -call 0x4a2a74
    cpu.esp -= 4;
    sub_4a2a74(app, cpu);
    if (cpu.terminate) return;
    // 00485e9a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485e9c  0f8461010000           -je 0x486003
    if (cpu.flags.zf)
    {
        goto L_0x00486003;
    }
    // 00485ea2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00485ea4  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 00485ea9  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00485ead  bf20944d00             -mov edi, 0x4d9420
    cpu.edi = 5084192 /*0x4d9420*/;
    // 00485eb2  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00485eb6  e8d6cb0100             -call 0x4a2a91
    cpu.esp -= 4;
    sub_4a2a91(app, cpu);
    if (cpu.terminate) return;
    // 00485ebb  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00485ebd  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00485ec0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485ec1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485ec3  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00485ec6  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485ec8  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00485eca  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00485ecd  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00485ecf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ed0  881d2c944d00           -mov byte ptr [0x4d942c], bl
    app->getMemory<x86::reg8>(x86::reg32(5084204) /* 0x4d942c */) = cpu.bl;
    // 00485ed6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00485ed8  7f0a                   -jg 0x485ee4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00485ee4;
    }
    // 00485eda  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00485edd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ede  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485edf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ee0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ee1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ee2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ee3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485ee4:
    // 00485ee4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00485ee9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00485eeb  e8a1cb0100             -call 0x4a2a91
    cpu.esp -= 4;
    sub_4a2a91(app, cpu);
    if (cpu.terminate) return;
    // 00485ef0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00485ef3  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00485ef8  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00485efb  a330944d00             -mov dword ptr [0x4d9430], eax
    app->getMemory<x86::reg32>(x86::reg32(5084208) /* 0x4d9430 */) = cpu.eax;
    // 00485f00  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00485f03  25f0000000             -and eax, 0xf0
    cpu.eax &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00485f08  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00485f0b  a334944d00             -mov dword ptr [0x4d9434], eax
    app->getMemory<x86::reg32>(x86::reg32(5084212) /* 0x4d9434 */) = cpu.eax;
    // 00485f10  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00485f13  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00485f16  8b2d30944d00           -mov ebp, dword ptr [0x4d9430]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5084208) /* 0x4d9430 */);
    // 00485f1c  a338944d00             -mov dword ptr [0x4d9438], eax
    app->getMemory<x86::reg32>(x86::reg32(5084216) /* 0x4d9438 */) = cpu.eax;
    // 00485f21  83fd05                 +cmp ebp, 5
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485f24  7c0a                   -jl 0x485f30
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485f30;
    }
    // 00485f26  c705c0894d0001000000   -mov dword ptr [0x4d89c0], 1
    app->getMemory<x86::reg32>(x86::reg32(5081536) /* 0x4d89c0 */) = 1 /*0x1*/;
L_0x00485f30:
    // 00485f30  833d30944d0006         +cmp dword ptr [0x4d9430], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084208) /* 0x4d9430 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485f37  7c0a                   -jl 0x485f43
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485f43;
    }
    // 00485f39  c705c4894d0001000000   -mov dword ptr [0x4d89c4], 1
    app->getMemory<x86::reg32>(x86::reg32(5081540) /* 0x4d89c4 */) = 1 /*0x1*/;
L_0x00485f43:
    // 00485f43  bac0da4c00             -mov edx, 0x4cdac0
    cpu.edx = 5036736 /*0x4cdac0*/;
    // 00485f48  b820944d00             -mov eax, 0x4d9420
    cpu.eax = 5084192 /*0x4d9420*/;
    // 00485f4d  e83ebcffff             -call 0x481b90
    cpu.esp -= 4;
    sub_481b90(app, cpu);
    if (cpu.terminate) return;
    // 00485f52  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485f54  7553                   -jne 0x485fa9
    if (!cpu.flags.zf)
    {
        goto L_0x00485fa9;
    }
    // 00485f56  c705d4894d0001000000   -mov dword ptr [0x4d89d4], 1
    app->getMemory<x86::reg32>(x86::reg32(5081556) /* 0x4d89d4 */) = 1 /*0x1*/;
L_0x00485f60:
    // 00485f60  f644240a80             +test byte ptr [esp + 0xa], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(10) /* 0xa */) & 128 /*0x80*/));
    // 00485f65  0f847f000000           -je 0x485fea
    if (cpu.flags.zf)
    {
        goto L_0x00485fea;
    }
    // 00485f6b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00485f70:
    // 00485f70  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485f74  a3c8894d00             -mov dword ptr [0x4d89c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5081544) /* 0x4d89c8 */) = cpu.eax;
    // 00485f79  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 00485f7c  0f846c000000           -je 0x485fee
    if (cpu.flags.zf)
    {
        goto L_0x00485fee;
    }
    // 00485f82  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00485f87:
    // 00485f87  8a6c2409               -mov ch, byte ptr [esp + 9]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */);
    // 00485f8b  a3cc894d00             -mov dword ptr [0x4d89cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5081548) /* 0x4d89cc */) = cpu.eax;
    // 00485f90  f6c580                 +test ch, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 128 /*0x80*/));
    // 00485f93  745d                   -je 0x485ff2
    if (cpu.flags.zf)
    {
        goto L_0x00485ff2;
    }
    // 00485f95  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00485f9a  a3d0894d00             -mov dword ptr [0x4d89d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5081552) /* 0x4d89d0 */) = cpu.eax;
    // 00485f9f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00485fa2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485fa3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485fa4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485fa5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485fa6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485fa7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485fa8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485fa9:
    // 00485fa9  bad0da4c00             -mov edx, 0x4cdad0
    cpu.edx = 5036752 /*0x4cdad0*/;
    // 00485fae  b820944d00             -mov eax, 0x4d9420
    cpu.eax = 5084192 /*0x4d9420*/;
    // 00485fb3  e8d8bbffff             -call 0x481b90
    cpu.esp -= 4;
    sub_481b90(app, cpu);
    if (cpu.terminate) return;
    // 00485fb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485fba  750c                   -jne 0x485fc8
    if (!cpu.flags.zf)
    {
        goto L_0x00485fc8;
    }
    // 00485fbc  c705dc894d0001000000   -mov dword ptr [0x4d89dc], 1
    app->getMemory<x86::reg32>(x86::reg32(5081564) /* 0x4d89dc */) = 1 /*0x1*/;
    // 00485fc6  eb98                   -jmp 0x485f60
    goto L_0x00485f60;
L_0x00485fc8:
    // 00485fc8  bae0da4c00             -mov edx, 0x4cdae0
    cpu.edx = 5036768 /*0x4cdae0*/;
    // 00485fcd  b820944d00             -mov eax, 0x4d9420
    cpu.eax = 5084192 /*0x4d9420*/;
    // 00485fd2  e8b9bbffff             -call 0x481b90
    cpu.esp -= 4;
    sub_481b90(app, cpu);
    if (cpu.terminate) return;
    // 00485fd7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485fd9  7585                   -jne 0x485f60
    if (!cpu.flags.zf)
    {
        goto L_0x00485f60;
    }
    // 00485fdb  c705d8894d0001000000   -mov dword ptr [0x4d89d8], 1
    app->getMemory<x86::reg32>(x86::reg32(5081560) /* 0x4d89d8 */) = 1 /*0x1*/;
    // 00485fe5  e976ffffff             -jmp 0x485f60
    goto L_0x00485f60;
L_0x00485fea:
    // 00485fea  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00485fec  eb82                   -jmp 0x485f70
    goto L_0x00485f70;
L_0x00485fee:
    // 00485fee  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00485ff0  eb95                   -jmp 0x485f87
    goto L_0x00485f87;
L_0x00485ff2:
    // 00485ff2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485ff4  a3d0894d00             -mov dword ptr [0x4d89d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5081552) /* 0x4d89d0 */) = cpu.eax;
    // 00485ff9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00485ffc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ffd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ffe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485fff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486000  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486001  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486002  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486003:
    // 00486003  e8a5ca0100             -call 0x4a2aad
    cpu.esp -= 4;
    sub_4a2aad(app, cpu);
    if (cpu.terminate) return;
    // 00486008  a3d8894d00             -mov dword ptr [0x4d89d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5081560) /* 0x4d89d8 */) = cpu.eax;
    // 0048600d  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00486010  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486011  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486012  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486013  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486014  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486015  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486016  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_486020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486020);
    // 00486020  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00486023  29d0                   +sub eax, edx
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
    // 00486025  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00486029  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0048602d  d84c2414               +fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 00486031  d9542408               +fst dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    // 00486035  dd1c24                 +fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00486038  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0048603a  dc1c24                 +fcomp qword ptr [esp]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.esp)));
    cpu.fpu.pop();
    // 0048603d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0048603f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00486040  770a                   -ja 0x48604c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048604c;
    }
    // 00486042  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00486046  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00486049  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048604c:
    // 0048604c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 0048604f  dc0df0da4c00           -fmul qword ptr [0x4cdaf0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036784) /* 0x4cdaf0 */));
    // 00486055  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00486059  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0048605d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00486060  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_486064(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486064);
    // 00486064  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486065  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486066  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486067  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048606a  833dcc894d0000         +cmp dword ptr [0x4d89cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081548) /* 0x4d89cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486071  0f8492010000           -je 0x486209
    if (cpu.flags.zf)
    {
        goto L_0x00486209;
    }
L_0x00486077:
    // 00486077  833dc0894d0000         +cmp dword ptr [0x4d89c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081536) /* 0x4d89c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048607e  0f848f010000           -je 0x486213
    if (cpu.flags.zf)
    {
        goto L_0x00486213;
    }
    // 00486084  833d40944d0000         +cmp dword ptr [0x4d9440], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084224) /* 0x4d9440 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048608b  0f8582010000           -jne 0x486213
    if (!cpu.flags.zf)
    {
        goto L_0x00486213;
    }
    // 00486091  e88a010000             -call 0x486220
    cpu.esp -= 4;
    sub_486220(app, cpu);
    if (cpu.terminate) return;
L_0x00486096:
    // 00486096  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486098  b940420f00             -mov ecx, 0xf4240
    cpu.ecx = 1000000 /*0xf4240*/;
    // 0048609d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048609f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004860a2  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004860a4  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004860a8  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 004860ac  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004860ae  dc05f8da4c00           +fadd qword ptr [0x4cdaf8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5036792) /* 0x4cdaf8 */));
    // 004860b4  dc0d00db4c00           +fmul qword ptr [0x4cdb00]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036800) /* 0x4cdb00 */));
    // 004860ba  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004860bc  e8dfe8ffff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 004860c1  db5c2414               +fistp dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004860c5  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004860c9  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004860cd  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 004860d1  dc0d08db4c00           +fmul qword ptr [0x4cdb08]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036808) /* 0x4cdb08 */));
    // 004860d7  dd0510db4c00           +fld qword ptr [0x4cdb10]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5036816) /* 0x4cdb10 */)));
    // 004860dd  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004860df  d8c1                   +fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004860e1  e8bae8ffff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 004860e6  db5c2410               +fistp dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004860ea  d9c1                   +fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 004860ec  dc0518db4c00           +fadd qword ptr [0x4cdb18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5036824) /* 0x4cdb18 */));
    // 004860f2  dc0d20db4c00           +fmul qword ptr [0x4cdb20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036832) /* 0x4cdb20 */));
    // 004860f8  e8a3e8ffff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 004860fd  db5c2414               +fistp dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00486101  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00486105  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00486109  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0048610d  dc0d28db4c00           +fmul qword ptr [0x4cdb28]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036840) /* 0x4cdb28 */));
    // 00486113  dc0530db4c00           +fadd qword ptr [0x4cdb30]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5036848) /* 0x4cdb30 */));
    // 00486119  e882e8ffff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 0048611e  db5c2408               +fistp dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00486122  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00486124  dc0538db4c00           +fadd qword ptr [0x4cdb38]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5036856) /* 0x4cdb38 */));
    // 0048612a  dc0d40db4c00           +fmul qword ptr [0x4cdb40]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036864) /* 0x4cdb40 */));
    // 00486130  e86be8ffff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 00486135  db5c2414               +fistp dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00486139  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048613d  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00486141  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 00486145  dc0d48db4c00           +fmul qword ptr [0x4cdb48]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036872) /* 0x4cdb48 */));
    // 0048614b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048614d  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0048614f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00486153  e848e8ffff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 00486158  db5c240c               +fistp dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0048615c  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 00486161  e8bafeffff             -call 0x486020
    cpu.esp -= 4;
    sub_486020(app, cpu);
    if (cpu.terminate) return;
    // 00486166  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048616a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048616e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00486170  68cdcc8c3f             -push 0x3f8ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1066192077 /*0x3f8ccccd*/;
    cpu.esp -= 4;
    // 00486175  e8a6feffff             -call 0x486020
    cpu.esp -= 4;
    sub_486020(app, cpu);
    if (cpu.terminate) return;
    // 0048617a  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048617e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00486182  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00486184  689a99993f             -push 0x3f99999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1067030938 /*0x3f99999a*/;
    cpu.esp -= 4;
    // 00486189  e892feffff             -call 0x486020
    cpu.esp -= 4;
    sub_486020(app, cpu);
    if (cpu.terminate) return;
    // 0048618e  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00486192  68cdcc8c3f             -push 0x3f8ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1066192077 /*0x3f8ccccd*/;
    cpu.esp -= 4;
    // 00486197  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048619b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048619d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004861a1  e87afeffff             -call 0x486020
    cpu.esp -= 4;
    sub_486020(app, cpu);
    if (cpu.terminate) return;
    // 004861a6  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004861aa  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004861ac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004861ae  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 004861b3  e868feffff             -call 0x486020
    cpu.esp -= 4;
    sub_486020(app, cpu);
    if (cpu.terminate) return;
    // 004861b8  d85c2414               +fcomp dword ptr [esp + 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    cpu.fpu.pop();
    // 004861bc  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004861be  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004861bf  7604                   -jbe 0x4861c5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004861c5;
    }
    // 004861c1  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x004861c5:
    // 004861c5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004861c9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004861cb  689a99993f             -push 0x3f99999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1067030938 /*0x3f99999a*/;
    cpu.esp -= 4;
    // 004861d0  e84bfeffff             -call 0x486020
    cpu.esp -= 4;
    sub_486020(app, cpu);
    if (cpu.terminate) return;
    // 004861d5  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004861d9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004861db  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004861dd  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 004861e2  e839feffff             -call 0x486020
    cpu.esp -= 4;
    sub_486020(app, cpu);
    if (cpu.terminate) return;
    // 004861e7  d85c2414               +fcomp dword ptr [esp + 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    cpu.fpu.pop();
    // 004861eb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004861ed  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004861ee  7604                   -jbe 0x4861f4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004861f4;
    }
    // 004861f0  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x004861f4:
    // 004861f4  69db40420f00           -imul ebx, ebx, 0xf4240
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(1000000 /*0xf4240*/)));
    // 004861fa  891d3c944d00           -mov dword ptr [0x4d943c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5084220) /* 0x4d943c */) = cpu.ebx;
    // 00486200  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486202  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00486205  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486206  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486207  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486208  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486209:
    // 00486209  e832fcffff             -call 0x485e40
    cpu.esp -= 4;
    sub_485e40(app, cpu);
    if (cpu.terminate) return;
    // 0048620e  e964feffff             -jmp 0x486077
    goto L_0x00486077;
L_0x00486213:
    // 00486213  e888000000             -call 0x4862a0
    cpu.esp -= 4;
    sub_4862a0(app, cpu);
    if (cpu.terminate) return;
    // 00486218  e979feffff             -jmp 0x486096
    goto L_0x00486096;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486220);
    // 00486220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486222  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486223  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486224  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486225  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486226  bd05000000             -mov ebp, 5
    cpu.ebp = 5 /*0x5*/;
    // 0048622b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048622d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048622f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00486231:
    // 00486231  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00486236  e845b6ffff             -call 0x481880
    cpu.esp -= 4;
    sub_481880(app, cpu);
    if (cpu.terminate) return;
    // 0048623b  833dcc894d0000         +cmp dword ptr [0x4d89cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081548) /* 0x4d89cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486242  7402                   -je 0x486246
    if (cpu.flags.zf)
    {
        goto L_0x00486246;
    }
    // 00486244  0f31                   -rdtsc 
    cpu.rdtsc();
L_0x00486246:
    // 00486246  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00486248  a1e8894d00             -mov eax, dword ptr [0x4d89e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0048624d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048624f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00486252  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00486254  e827b6ffff             -call 0x481880
    cpu.esp -= 4;
    sub_481880(app, cpu);
    if (cpu.terminate) return;
    // 00486259  833dcc894d0000         +cmp dword ptr [0x4d89cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081548) /* 0x4d89cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486260  7402                   -je 0x486264
    if (cpu.flags.zf)
    {
        goto L_0x00486264;
    }
    // 00486262  0f31                   -rdtsc 
    cpu.rdtsc();
L_0x00486264:
    // 00486264  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00486266  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00486268  7408                   -je 0x486272
    if (cpu.flags.zf)
    {
        goto L_0x00486272;
    }
    // 0048626a  39d8                   +cmp eax, ebx
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
    // 0048626c  7d20                   -jge 0x48628e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048628e;
    }
L_0x0048626e:
    // 0048626e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00486270  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00486272:
    // 00486272  46                     -inc esi
    (cpu.esi)++;
    // 00486273  83fe05                 +cmp esi, 5
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486276  7cb9                   -jl 0x486231
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486231;
    }
    // 00486278  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048627a  7502                   -jne 0x48627e
    if (!cpu.flags.zf)
    {
        goto L_0x0048627e;
    }
    // 0048627c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x0048627e:
    // 0048627e  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00486285  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00486287  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486288  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486289  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048628a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048628b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048628c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048628d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048628e:
    // 0048628e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00486290  74dc                   -je 0x48626e
    if (cpu.flags.zf)
    {
        goto L_0x0048626e;
    }
    // 00486292  39c8                   +cmp eax, ecx
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
    // 00486294  7d04                   -jge 0x48629a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048629a;
    }
L_0x00486296:
    // 00486296  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486298  ebd8                   -jmp 0x486272
    goto L_0x00486272;
L_0x0048629a:
    // 0048629a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048629c  74f8                   -je 0x486296
    if (cpu.flags.zf)
    {
        goto L_0x00486296;
    }
    // 0048629e  ebd2                   -jmp 0x486272
    goto L_0x00486272;
}

/* align: skip  */
void Application::sub_4862a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004862a0);
    // 004862a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004862a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004862a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004862a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004862a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004862a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004862a6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004862a9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004862ab  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004862ad  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004862b1  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004862b5:
    // 004862b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004862ba  e8c1b5ffff             -call 0x481880
    cpu.esp -= 4;
    sub_481880(app, cpu);
    if (cpu.terminate) return;
    // 004862bf  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 004862c4  8b3de8894d00           -mov edi, dword ptr [0x4d89e8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 004862ca  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 004862cd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004862cf  8b35c4155600           -mov esi, dword ptr [0x5615c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
L_0x004862d5:
    // 004862d5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004862d7  b8aaaa5555             -mov eax, 0x5555aaaa
    cpu.eax = 1431677610 /*0x5555aaaa*/;
    // 004862dc  bb21000000             -mov ebx, 0x21
    cpu.ebx = 33 /*0x21*/;
    // 004862e1  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004862e3  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 004862e8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004862ea  41                     -inc ecx
    (cpu.ecx)++;
    // 004862eb  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 004862ed  7ce6                   -jl 0x4862d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004862d5;
    }
    // 004862ef  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004862f3  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004862f5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004862f7  7414                   -je 0x48630d
    if (cpu.flags.zf)
    {
        goto L_0x0048630d;
    }
    // 004862f9  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004862fd  39f1                   +cmp ecx, esi
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
    // 004862ff  0f8d7c000000           -jge 0x486381
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00486381;
    }
L_0x00486305:
    // 00486305  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00486309  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
L_0x0048630d:
    // 0048630d  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00486311  42                     -inc edx
    (cpu.edx)++;
    // 00486312  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00486316  83fa05                 +cmp edx, 5
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486319  7c9a                   -jl 0x4862b5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004862b5;
    }
    // 0048631b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048631d  7504                   -jne 0x486323
    if (!cpu.flags.zf)
    {
        goto L_0x00486323;
    }
    // 0048631f  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x00486323:
    // 00486323  8b1dc4894d00           -mov ebx, dword ptr [0x4d89c4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081540) /* 0x4d89c4 */);
    // 00486329  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0048632c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048632e  7566                   -jne 0x486396
    if (!cpu.flags.zf)
    {
        goto L_0x00486396;
    }
    // 00486330  833dc0894d0000         +cmp dword ptr [0x4d89c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081536) /* 0x4d89c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486337  0f856f000000           -jne 0x4863ac
    if (!cpu.flags.zf)
    {
        goto L_0x004863ac;
    }
    // 0048633d  833dd8894d0000         +cmp dword ptr [0x4d89d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081560) /* 0x4d89d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486344  0f8478000000           -je 0x4863c2
    if (cpu.flags.zf)
    {
        goto L_0x004863c2;
    }
    // 0048634a  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0048634e  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00486352  dc0da0db4c00           -fmul qword ptr [0x4cdba0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036960) /* 0x4cdba0 */));
    // 00486358  dc0da8db4c00           -fmul qword ptr [0x4cdba8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036968) /* 0x4cdba8 */));
L_0x0048635e:
    // 0048635e  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00486361  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00486364  d80dd0db4c00           -fmul dword ptr [0x4cdbd0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5037008) /* 0x4cdbd0 */));
    // 0048636a  e831e6ffff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 0048636f  db5c240c               -fistp dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00486373  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00486377  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048637a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048637b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048637c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048637d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048637e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048637f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486380  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486381:
    // 00486381  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00486383  7480                   -je 0x486305
    if (cpu.flags.zf)
    {
        goto L_0x00486305;
    }
    // 00486385  39e9                   +cmp ecx, ebp
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
    // 00486387  7d04                   -jge 0x48638d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048638d;
    }
L_0x00486389:
    // 00486389  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0048638b  eb80                   -jmp 0x48630d
    goto L_0x0048630d;
L_0x0048638d:
    // 0048638d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048638f  74f8                   -je 0x486389
    if (cpu.flags.zf)
    {
        goto L_0x00486389;
    }
    // 00486391  e977ffffff             -jmp 0x48630d
    goto L_0x0048630d;
L_0x00486396:
    // 00486396  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0048639a  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0048639e  dc0dc0db4c00           +fmul qword ptr [0x4cdbc0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036992) /* 0x4cdbc0 */));
    // 004863a4  dc0dc8db4c00           +fmul qword ptr [0x4cdbc8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5037000) /* 0x4cdbc8 */));
    // 004863aa  ebb2                   -jmp 0x48635e
    goto L_0x0048635e;
L_0x004863ac:
    // 004863ac  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004863b0  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 004863b4  dc0db0db4c00           +fmul qword ptr [0x4cdbb0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036976) /* 0x4cdbb0 */));
    // 004863ba  dc0db8db4c00           +fmul qword ptr [0x4cdbb8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036984) /* 0x4cdbb8 */));
    // 004863c0  eb9c                   -jmp 0x48635e
    goto L_0x0048635e;
L_0x004863c2:
    // 004863c2  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004863c6  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 004863ca  dc0d90db4c00           +fmul qword ptr [0x4cdb90]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036944) /* 0x4cdb90 */));
    // 004863d0  dc0d98db4c00           +fmul qword ptr [0x4cdb98]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5036952) /* 0x4cdb98 */));
    // 004863d6  eb86                   -jmp 0x48635e
    goto L_0x0048635e;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4863e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004863e0);
    // 004863e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004863e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004863e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004863e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004863e4  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004863ea  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004863ec  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004863ee  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004863f0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004863f1:
    // 004863f1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004863f3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004863f5  3c00                   +cmp al, 0
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
    // 004863f7  7410                   -je 0x486409
    if (cpu.flags.zf)
    {
        goto L_0x00486409;
    }
    // 004863f9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004863fc  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004863ff  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00486402  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00486405  3c00                   +cmp al, 0
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
    // 00486407  75e8                   -jne 0x4863f1
    if (!cpu.flags.zf)
    {
        goto L_0x004863f1;
    }
L_0x00486409:
    // 00486409  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048640a  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048640c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048640e  49                     -dec ecx
    (cpu.ecx)--;
    // 0048640f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00486411  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00486413  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00486415  49                     -dec ecx
    (cpu.ecx)--;
    // 00486416  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00486418  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048641a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048641c  48                     -dec eax
    (cpu.eax)--;
    // 0048641d  39d0                   +cmp eax, edx
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
    // 0048641f  7607                   -jbe 0x486428
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486428;
    }
L_0x00486421:
    // 00486421  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00486423  80fa2e                 +cmp dl, 0x2e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486426  7545                   -jne 0x48646d
    if (!cpu.flags.zf)
    {
        goto L_0x0048646d;
    }
L_0x00486428:
    // 00486428  80382e                 +cmp byte ptr [eax], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048642b  742a                   -je 0x486457
    if (cpu.flags.zf)
    {
        goto L_0x00486457;
    }
    // 0048642d  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048642f  8b3544944d00           -mov esi, dword ptr [0x4d9444]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5084228) /* 0x4d9444 */);
    // 00486435  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486436  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00486438  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00486439  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0048643b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048643d  4f                     -dec edi
    (cpu.edi)--;
L_0x0048643e:
    // 0048643e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00486440  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00486442  3c00                   +cmp al, 0
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
    // 00486444  7410                   -je 0x486456
    if (cpu.flags.zf)
    {
        goto L_0x00486456;
    }
    // 00486446  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00486449  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048644c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048644f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00486452  3c00                   +cmp al, 0
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
    // 00486454  75e8                   -jne 0x48643e
    if (!cpu.flags.zf)
    {
        goto L_0x0048643e;
    }
L_0x00486456:
    // 00486456  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00486457:
    // 00486457  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00486459  e8369d0100             -call 0x4a0194
    cpu.esp -= 4;
    sub_4a0194(app, cpu);
    if (cpu.terminate) return;
    // 0048645e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486460  7423                   -je 0x486485
    if (cpu.flags.zf)
    {
        goto L_0x00486485;
    }
    // 00486462  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00486468  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486469  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048646a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048646b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048646c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048646d:
    // 0048646d  80fa3a                 +cmp dl, 0x3a
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486470  74b6                   -je 0x486428
    if (cpu.flags.zf)
    {
        goto L_0x00486428;
    }
    // 00486472  80fa2f                 +cmp dl, 0x2f
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486475  74b1                   -je 0x486428
    if (cpu.flags.zf)
    {
        goto L_0x00486428;
    }
    // 00486477  80fa5c                 +cmp dl, 0x5c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048647a  74ac                   -je 0x486428
    if (cpu.flags.zf)
    {
        goto L_0x00486428;
    }
    // 0048647c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048647e  48                     -dec eax
    (cpu.eax)--;
    // 0048647f  39d0                   +cmp eax, edx
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
    // 00486481  779e                   -ja 0x486421
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00486421;
    }
    // 00486483  eba3                   -jmp 0x486428
    goto L_0x00486428;
L_0x00486485:
    // 00486485  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00486487  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00486489  e89a240100             -call 0x498928
    cpu.esp -= 4;
    sub_498928(app, cpu);
    if (cpu.terminate) return;
    // 0048648e  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00486494  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486495  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486496  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486497  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486498  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48649c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048649c);
    // 0048649c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048649d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048649f  e83cffffff             -call 0x4863e0
    cpu.esp -= 4;
    sub_4863e0(app, cpu);
    if (cpu.terminate) return;
    // 004864a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004864a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4864a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004864a8);
    // 004864a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004864a9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004864ae  e82dffffff             -call 0x4863e0
    cpu.esp -= 4;
    sub_4863e0(app, cpu);
    if (cpu.terminate) return;
    // 004864b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004864b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4864b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004864b8);
    // 004864b8  e823ffffff             -call 0x4863e0
    cpu.esp -= 4;
    sub_4863e0(app, cpu);
    if (cpu.terminate) return;
    // 004864bd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004864bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004864c1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004864c3  7402                   -je 0x4864c7
    if (cpu.flags.zf)
    {
        goto L_0x004864c7;
    }
    // 004864c5  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
L_0x004864c7:
    // 004864c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4864c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004864c8);
    // 004864c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004864c9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004864cb  e8e8ffffff             -call 0x4864b8
    cpu.esp -= 4;
    sub_4864b8(app, cpu);
    if (cpu.terminate) return;
    // 004864d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004864d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4864d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004864d4);
    // 004864d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004864d5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004864da  e8d9ffffff             -call 0x4864b8
    cpu.esp -= 4;
    sub_4864b8(app, cpu);
    if (cpu.terminate) return;
    // 004864df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004864e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4864e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004864e4);
    // 004864e4  a15c944d00             -mov eax, dword ptr [0x4d945c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084252) /* 0x4d945c */);
    // 004864e9  030558944d00           +add eax, dword ptr [0x4d9458]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5084248) /* 0x4d9458 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004864ef  a358944d00             -mov dword ptr [0x4d9458], eax
    app->getMemory<x86::reg32>(x86::reg32(5084248) /* 0x4d9458 */) = cpu.eax;
    // 004864f4  130554944d00           +adc eax, dword ptr [0x4d9454]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5084244) /* 0x4d9454 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004864fa  a354944d00             -mov dword ptr [0x4d9454], eax
    app->getMemory<x86::reg32>(x86::reg32(5084244) /* 0x4d9454 */) = cpu.eax;
    // 004864ff  130550944d00           +adc eax, dword ptr [0x4d9450]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5084240) /* 0x4d9450 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00486505  a350944d00             -mov dword ptr [0x4d9450], eax
    app->getMemory<x86::reg32>(x86::reg32(5084240) /* 0x4d9450 */) = cpu.eax;
    // 0048650a  13054c944d00           +adc eax, dword ptr [0x4d944c]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5084236) /* 0x4d944c */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00486510  a34c944d00             -mov dword ptr [0x4d944c], eax
    app->getMemory<x86::reg32>(x86::reg32(5084236) /* 0x4d944c */) = cpu.eax;
    // 00486515  130548944d00           +adc eax, dword ptr [0x4d9448]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5084232) /* 0x4d9448 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048651b  ff055c944d00           +inc dword ptr [0x4d945c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5084252) /* 0x4d945c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00486521  7521                   -jne 0x486544
    if (!cpu.flags.zf)
    {
        goto L_0x00486544;
    }
    // 00486523  ff0558944d00           +inc dword ptr [0x4d9458]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5084248) /* 0x4d9458 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00486529  7519                   -jne 0x486544
    if (!cpu.flags.zf)
    {
        goto L_0x00486544;
    }
    // 0048652b  ff0554944d00           +inc dword ptr [0x4d9454]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5084244) /* 0x4d9454 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00486531  7511                   -jne 0x486544
    if (!cpu.flags.zf)
    {
        goto L_0x00486544;
    }
    // 00486533  ff0550944d00           +inc dword ptr [0x4d9450]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5084240) /* 0x4d9450 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00486539  7509                   -jne 0x486544
    if (!cpu.flags.zf)
    {
        goto L_0x00486544;
    }
    // 0048653b  ff054c944d00           +inc dword ptr [0x4d944c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5084236) /* 0x4d944c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00486541  7501                   -jne 0x486544
    if (!cpu.flags.zf)
    {
        goto L_0x00486544;
    }
    // 00486543  40                     -inc eax
    (cpu.eax)++;
L_0x00486544:
    // 00486544  a348944d00             -mov dword ptr [0x4d9448], eax
    app->getMemory<x86::reg32>(x86::reg32(5084232) /* 0x4d9448 */) = cpu.eax;
    // 00486549  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48654a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048654a);
    // 0048654a  05560e2df2             -add eax, 0xf22d0e56
    (cpu.eax) += x86::reg32(x86::sreg32(4063039062 /*0xf22d0e56*/));
    // 0048654f  a348944d00             -mov dword ptr [0x4d9448], eax
    app->getMemory<x86::reg32>(x86::reg32(5084232) /* 0x4d9448 */) = cpu.eax;
    // 00486554  0593180496             -add eax, 0x96041893
    (cpu.eax) += x86::reg32(x86::sreg32(2516850835 /*0x96041893*/));
    // 00486559  a34c944d00             -mov dword ptr [0x4d944c], eax
    app->getMemory<x86::reg32>(x86::reg32(5084236) /* 0x4d944c */) = cpu.eax;
    // 0048655e  0546b6f33d             -add eax, 0x3df3b646
    (cpu.eax) += x86::reg32(x86::sreg32(1039382086 /*0x3df3b646*/));
    // 00486563  a350944d00             -mov dword ptr [0x4d9450], eax
    app->getMemory<x86::reg32>(x86::reg32(5084240) /* 0x4d9450 */) = cpu.eax;
    // 00486568  056de7dd40             -add eax, 0x40dde76d
    (cpu.eax) += x86::reg32(x86::sreg32(1088284525 /*0x40dde76d*/));
    // 0048656d  a354944d00             -mov dword ptr [0x4d9454], eax
    app->getMemory<x86::reg32>(x86::reg32(5084244) /* 0x4d9454 */) = cpu.eax;
    // 00486572  05e17a3297             -add eax, 0x97327ae1
    (cpu.eax) += x86::reg32(x86::sreg32(2536667873 /*0x97327ae1*/));
    // 00486577  a358944d00             -mov dword ptr [0x4d9458], eax
    app->getMemory<x86::reg32>(x86::reg32(5084248) /* 0x4d9458 */) = cpu.eax;
    // 0048657c  05e7fba9d1             -add eax, 0xd1a9fbe7
    (cpu.eax) += x86::reg32(x86::sreg32(3517578215 /*0xd1a9fbe7*/));
    // 00486581  a35c944d00             -mov dword ptr [0x4d945c], eax
    app->getMemory<x86::reg32>(x86::reg32(5084252) /* 0x4d945c */) = cpu.eax;
    // 00486586  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_486590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486590);
    // 00486590  e8c7c7ffff             -call 0x482d5c
    cpu.esp -= 4;
    sub_482d5c(app, cpu);
    if (cpu.terminate) return;
    // 00486595  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00486598  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486599  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048659a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048659b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048659c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048659f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004865a1  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004865a5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004865a7  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004865aa  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004865af  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004865b2  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004865b6  83f803                 +cmp eax, 3
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
    // 004865b9  0f8591000000           -jne 0x486650
    if (!cpu.flags.zf)
    {
        return sub_486650(app, cpu);
    }
    // 004865bf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004865c1  3b4110                 +cmp eax, dword ptr [ecx + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004865c4  7f50                   -jg 0x486616
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        return sub_486616(app, cpu);
    }
    // 004865c6  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004865ca  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004865cd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004865d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4865cd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004865cd);
    goto L_entry_0x004865cd;
    // 00486590  e8c7c7ffff             -call 0x482d5c
    cpu.esp -= 4;
    sub_482d5c(app, cpu);
    if (cpu.terminate) return;
    // 00486595  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00486598  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486599  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048659a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048659b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048659c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048659f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004865a1  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004865a5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004865a7  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004865aa  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004865af  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004865b2  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004865b6  83f803                 +cmp eax, 3
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
    // 004865b9  0f8591000000           -jne 0x486650
    if (!cpu.flags.zf)
    {
        return sub_486650(app, cpu);
    }
    // 004865bf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004865c1  3b4110                 +cmp eax, dword ptr [ecx + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004865c4  7f50                   -jg 0x486616
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        return sub_486616(app, cpu);
    }
    // 004865c6  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004865ca  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_entry_0x004865cd:
    // 004865cd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004865d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486598(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486598);
    goto L_entry_0x00486598;
    // 00486590  e8c7c7ffff             -call 0x482d5c
    cpu.esp -= 4;
    sub_482d5c(app, cpu);
    if (cpu.terminate) return;
    // 00486595  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00486598:
    // 00486598  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486599  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048659a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048659b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048659c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048659f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004865a1  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004865a5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004865a7  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004865aa  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004865af  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004865b2  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004865b6  83f803                 +cmp eax, 3
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
    // 004865b9  0f8591000000           -jne 0x486650
    if (!cpu.flags.zf)
    {
        return sub_486650(app, cpu);
    }
    // 004865bf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004865c1  3b4110                 +cmp eax, dword ptr [ecx + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004865c4  7f50                   -jg 0x486616
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        return sub_486616(app, cpu);
    }
    // 004865c6  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004865ca  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004865cd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004865d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4865d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004865d8);
    // 004865d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004865d9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004865de  e879c7ffff             -call 0x482d5c
    cpu.esp -= 4;
    sub_482d5c(app, cpu);
    if (cpu.terminate) return;
    // 004865e3  e8b0ffffff             -call 0x486598
    cpu.esp -= 4;
    sub_486598(app, cpu);
    if (cpu.terminate) return;
    // 004865e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4865ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004865ec);
    // 004865ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004865ed  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004865ef  e868c7ffff             -call 0x482d5c
    cpu.esp -= 4;
    sub_482d5c(app, cpu);
    if (cpu.terminate) return;
    // 004865f4  e89fffffff             -call 0x486598
    cpu.esp -= 4;
    sub_486598(app, cpu);
    if (cpu.terminate) return;
    // 004865f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4865fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004865fc);
    // 004865fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004865fd  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00486602  e891ffffff             -call 0x486598
    cpu.esp -= 4;
    sub_486598(app, cpu);
    if (cpu.terminate) return;
    // 00486607  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486608  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48660c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048660c);
    // 0048660c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048660d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048660f  e884ffffff             -call 0x486598
    cpu.esp -= 4;
    sub_486598(app, cpu);
    if (cpu.terminate) return;
    // 00486614  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486615  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486616(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486616);
    // 00486616  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00486619  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048661b  e824140100             -call 0x497a44
    cpu.esp -= 4;
    sub_497a44(app, cpu);
    if (cpu.terminate) return;
    // 00486620  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00486622  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486624  74a7                   -je 0x4865cd
    if (cpu.flags.zf)
    {
        return sub_4865cd(app, cpu);
    }
    // 00486626  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00486628  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048662b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048662d  e8ce340000             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 00486632  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00486634  e86f140100             -call 0x497aa8
    cpu.esp -= 4;
    sub_497aa8(app, cpu);
    if (cpu.terminate) return;
    // 00486639  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 0048663b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048663e  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00486641  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00486645  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00486648  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048664b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048664c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048664d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048664e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048664f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486650);
    // 00486650  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486652  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00486655  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00486657  bb501b5600             -mov ebx, 0x561b50
    cpu.ebx = 5643088 /*0x561b50*/;
    // 0048665c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048665f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00486661  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00486666  e8c5950100             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 0048666b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0048666e  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00486670  8b6b14                 -mov ebp, dword ptr [ebx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00486673  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00486675  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00486678  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048667a  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048667d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048667f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00486683  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00486685  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00486687  21cf                   -and edi, ecx
    cpu.edi &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486689  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048668b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048668f  21c1                   -and ecx, eax
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.eax));
    // 00486691  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00486693  7c37                   -jl 0x4866cc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004866cc;
    }
L_0x00486695:
    // 00486695  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00486697:
    // 00486697  39f9                   +cmp ecx, edi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486699  7f4c                   -jg 0x4866e7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004866e7;
    }
    // 0048669b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048669d  7c48                   -jl 0x4866e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004866e7;
    }
    // 0048669f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004866a3  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004866a6  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004866a9  837b1400               +cmp dword ptr [ebx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004866ad  7407                   -je 0x4866b6
    if (cpu.flags.zf)
    {
        goto L_0x004866b6;
    }
    // 004866af  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004866b1  e8ca950100             -call 0x49fc80
    cpu.esp -= 4;
    sub_49fc80(app, cpu);
    if (cpu.terminate) return;
L_0x004866b6:
    // 004866b6  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 004866bb  e878950100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 004866c0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004866c4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004866c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004866cc:
    // 004866cc  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004866ce  83fdff                 +cmp ebp, -1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004866d1  74c2                   -je 0x486695
    if (cpu.flags.zf)
    {
        goto L_0x00486695;
    }
    // 004866d3  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 004866d8  e85b950100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 004866dd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004866df  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004866e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004866e7:
    // 004866e7  833d20904d0000         +cmp dword ptr [0x4d9020], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083168) /* 0x4d9020 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004866ee  740d                   -je 0x4866fd
    if (cpu.flags.zf)
    {
        goto L_0x004866fd;
    }
    // 004866f0  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004866f3  f6401818               +test byte ptr [eax + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 004866f7  7404                   -je 0x4866fd
    if (cpu.flags.zf)
    {
        goto L_0x004866fd;
    }
    // 004866f9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004866fb  742f                   -je 0x48672c
    if (cpu.flags.zf)
    {
        goto L_0x0048672c;
    }
L_0x004866fd:
    // 004866fd  833d20904d0000         +cmp dword ptr [0x4d9020], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083168) /* 0x4d9020 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486704  7406                   -je 0x48670c
    if (cpu.flags.zf)
    {
        goto L_0x0048670c;
    }
    // 00486706  f6461810               +test byte ptr [esi + 0x18], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 16 /*0x10*/));
    // 0048670a  754d                   -jne 0x486759
    if (!cpu.flags.zf)
    {
        goto L_0x00486759;
    }
L_0x0048670c:
    // 0048670c  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00486711  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00486715  e81e950100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 0048671a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048671c  0f8cda000000           -jl 0x4867fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004867fc;
    }
    // 00486722  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486724  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00486727  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486728  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486729  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048672a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048672b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048672c:
    // 0048672c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048672e  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00486731  e882960100             -call 0x49fdb8
    cpu.esp -= 4;
    sub_49fdb8(app, cpu);
    if (cpu.terminate) return;
    // 00486736  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486738  7415                   -je 0x48674f
    if (cpu.flags.zf)
    {
        goto L_0x0048674f;
    }
    // 0048673a  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0048673d  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0048673f  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00486742  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00486744  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 00486746  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00486748  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048674a  e948ffffff             -jmp 0x486697
    goto L_0x00486697;
L_0x0048674f:
    // 0048674f  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00486754  e93effffff             -jmp 0x486697
    goto L_0x00486697;
L_0x00486759:
    // 00486759  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0048675c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048675e  e865970100             -call 0x49fec8
    cpu.esp -= 4;
    sub_49fec8(app, cpu);
    if (cpu.terminate) return;
    // 00486763  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486765  7415                   -je 0x48677c
    if (cpu.flags.zf)
    {
        goto L_0x0048677c;
    }
    // 00486767  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0048676a  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0048676c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048676e  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00486770  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00486773  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 00486775  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 00486777  e91bffffff             -jmp 0x486697
    goto L_0x00486697;
L_0x0048677c:
    // 0048677c  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00486780  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00486784  b8dcdb4c00             -mov eax, 0x4cdbdc
    cpu.eax = 5037020 /*0x4cdbdc*/;
    // 00486789  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048678b  e8f0c1ffff             -call 0x482980
    cpu.esp -= 4;
    sub_482980(app, cpu);
    if (cpu.terminate) return;
    // 00486790  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486792  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486794  0f8472ffffff           -je 0x48670c
    if (cpu.flags.zf)
    {
        goto L_0x0048670c;
    }
    // 0048679a  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048679d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048679f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004867a1  e85a330000             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004867a6  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004867a9  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004867ac  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004867af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004867b1  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004867b4  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004867b7  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004867ba  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004867bd  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004867c0  897024                 -mov dword ptr [eax + 0x24], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004867c3  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004867c5  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004867c7  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004867ca  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004867cd  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004867d0  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004867d3  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004867d6  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004867d9  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004867dc  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004867df  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004867e1  e8f6c9ffff             -call 0x4831dc
    cpu.esp -= 4;
    sub_4831dc(app, cpu);
    if (cpu.terminate) return;
    // 004867e6  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 004867eb  e848940100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 004867f0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004867f4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004867f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004867fc:
    // 004867fc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004867fe  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00486801  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486802  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486803  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486804  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486805  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486806(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486806);
    // 00486806  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486807  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486808  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486809  2eff154c454c00         -call dword ptr cs:[0x4c454c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998476) /* 0x4c454c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486810  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486812  7508                   -jne 0x48681c
    if (!cpu.flags.zf)
    {
        goto L_0x0048681c;
    }
    // 00486814  e809b90100             -call 0x4a2122
    cpu.esp -= 4;
    sub_4a2122(app, cpu);
    if (cpu.terminate) return;
    // 00486819  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048681a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048681b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048681c:
    // 0048681c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048681e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048681f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486820  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_486830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486830);
    // 00486830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486832  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486833  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486834  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486835  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0048683b  8b1560944d00           -mov edx, dword ptr [0x4d9460]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5084256) /* 0x4d9460 */);
    // 00486841  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00486843  83faff                 +cmp edx, -1
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
    // 00486846  7409                   -je 0x486851
    if (cpu.flags.zf)
    {
        goto L_0x00486851;
    }
    // 00486848  bf091e5600             -mov edi, 0x561e09
    cpu.edi = 5643785 /*0x561e09*/;
L_0x0048684d:
    // 0048684d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048684f  740e                   -je 0x48685f
    if (cpu.flags.zf)
    {
        goto L_0x0048685f;
    }
L_0x00486851:
    // 00486851  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486853  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 00486859  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048685a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048685b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048685c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048685d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048685e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048685f:
    // 0048685f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00486861  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486862  8b0d60944d00           -mov ecx, dword ptr [0x4d9460]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084256) /* 0x4d9460 */);
    // 00486868  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486869  2eff1568444c00         -call dword ptr cs:[0x4c4468]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998248) /* 0x4c4468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486870  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486872  743f                   -je 0x4868b3
    if (cpu.flags.zf)
    {
        goto L_0x004868b3;
    }
    // 00486874  8b1d001d5600           -mov ebx, dword ptr [0x561d00]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5643520) /* 0x561d00 */);
    // 0048687a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0048687c  ba041d5600             -mov edx, 0x561d04
    cpu.edx = 5643524 /*0x561d04*/;
    // 00486881  88a3091e5600           -mov byte ptr [ebx + 0x561e09], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5643785) /* 0x561e09 */) = cpu.ah;
    // 00486887  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00486889  e8bee0ffff             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 0048688e  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 00486893  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00486897  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00486899  e833c20100             -call 0x4a2ad1
    cpu.esp -= 4;
    sub_4a2ad1(app, cpu);
    if (cpu.terminate) return;
    // 0048689e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048689f  2eff15b4444c00         -call dword ptr cs:[0x4c44b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998324) /* 0x4c44b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004868a6  83f8ff                 +cmp eax, -1
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
    // 004868a9  74a2                   -je 0x48684d
    if (cpu.flags.zf)
    {
        goto L_0x0048684d;
    }
    // 004868ab  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004868ad  759e                   -jne 0x48684d
    if (!cpu.flags.zf)
    {
        goto L_0x0048684d;
    }
    // 004868af  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004868b1  eb9a                   -jmp 0x48684d
    goto L_0x0048684d;
L_0x004868b3:
    // 004868b3  8b1d60944d00           -mov ebx, dword ptr [0x4d9460]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5084256) /* 0x4d9460 */);
    // 004868b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004868ba  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 004868bf  2eff1560444c00         -call dword ptr cs:[0x4c4460]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998240) /* 0x4c4460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004868c6  893560944d00           -mov dword ptr [0x4d9460], esi
    app->getMemory<x86::reg32>(x86::reg32(5084256) /* 0x4d9460 */) = cpu.esi;
    // 004868cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004868ce  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004868d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004868d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004868d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004868d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004868d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004868d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4868dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004868dc);
    // 004868dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004868dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004868de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004868df  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004868e0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004868e1  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004868e7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004868e9  8b1560944d00           -mov edx, dword ptr [0x4d9460]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5084256) /* 0x4d9460 */);
    // 004868ef  83faff                 +cmp edx, -1
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
    // 004868f2  0f856b000000           -jne 0x486963
    if (!cpu.flags.zf)
    {
        goto L_0x00486963;
    }
L_0x004868f8:
    // 004868f8  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 004868fd  b8041d5600             -mov eax, 0x561d04
    cpu.eax = 5643524 /*0x561d04*/;
    // 00486902  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00486904  bf041d5600             -mov edi, 0x561d04
    cpu.edi = 5643524 /*0x561d04*/;
    // 00486909  e83ee0ffff             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 0048690e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486910  49                     -dec ecx
    (cpu.ecx)--;
    // 00486911  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00486913  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00486915  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00486917  49                     -dec ecx
    (cpu.ecx)--;
    // 00486918  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048691a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048691c  7e15                   -jle 0x486933
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00486933;
    }
L_0x0048691e:
    // 0048691e  8a90041d5600           -mov dl, byte ptr [eax + 0x561d04]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5643524) /* 0x561d04 */);
    // 00486924  80fa5c                 +cmp dl, 0x5c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486927  740a                   -je 0x486933
    if (cpu.flags.zf)
    {
        goto L_0x00486933;
    }
    // 00486929  80fa3a                 +cmp dl, 0x3a
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048692c  7405                   -je 0x486933
    if (cpu.flags.zf)
    {
        goto L_0x00486933;
    }
    // 0048692e  48                     -dec eax
    (cpu.eax)--;
    // 0048692f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486931  7feb                   -jg 0x48691e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048691e;
    }
L_0x00486933:
    // 00486933  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486935  7536                   -jne 0x48696d
    if (!cpu.flags.zf)
    {
        goto L_0x0048696d;
    }
L_0x00486937:
    // 00486937  a3001d5600             -mov dword ptr [0x561d00], eax
    app->getMemory<x86::reg32>(x86::reg32(5643520) /* 0x561d00 */) = cpu.eax;
    // 0048693c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048693e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048693f  68041d5600             -push 0x561d04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5643524 /*0x561d04*/;
    cpu.esp -= 4;
    // 00486944  2eff1564444c00         -call dword ptr cs:[0x4c4464]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998244) /* 0x4c4464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048694b  a360944d00             -mov dword ptr [0x4d9460], eax
    app->getMemory<x86::reg32>(x86::reg32(5084256) /* 0x4d9460 */) = cpu.eax;
    // 00486950  83f8ff                 +cmp eax, -1
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
    // 00486953  751b                   -jne 0x486970
    if (!cpu.flags.zf)
    {
        goto L_0x00486970;
    }
    // 00486955  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486957  81c440010000           +add esp, 0x140
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048695d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048695e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048695f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486960  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486961  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486962  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486963:
    // 00486963  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486964  2eff1560444c00         -call dword ptr cs:[0x4c4460]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998240) /* 0x4c4460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048696b  eb8b                   -jmp 0x4868f8
    goto L_0x004868f8;
L_0x0048696d:
    // 0048696d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048696e  ebc7                   -jmp 0x486937
    goto L_0x00486937;
L_0x00486970:
    // 00486970  ba041d5600             -mov edx, 0x561d04
    cpu.edx = 5643524 /*0x561d04*/;
    // 00486975  8b1d001d5600           -mov ebx, dword ptr [0x561d00]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5643520) /* 0x561d00 */);
    // 0048697b  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0048697d  b8091e5600             -mov eax, 0x561e09
    cpu.eax = 5643785 /*0x561e09*/;
    // 00486982  888b091e5600           -mov byte ptr [ebx + 0x561e09], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5643785) /* 0x561e09 */) = cpu.cl;
    // 00486988  e8bfdfffff             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 0048698d  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 00486992  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00486996  b8091e5600             -mov eax, 0x561e09
    cpu.eax = 5643785 /*0x561e09*/;
    // 0048699b  e831c10100             -call 0x4a2ad1
    cpu.esp -= 4;
    sub_4a2ad1(app, cpu);
    if (cpu.terminate) return;
    // 004869a0  68091e5600             -push 0x561e09
    app->getMemory<x86::reg32>(cpu.esp-4) = 5643785 /*0x561e09*/;
    cpu.esp -= 4;
    // 004869a5  2eff15b4444c00         -call dword ptr cs:[0x4c44b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998324) /* 0x4c44b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004869ac  83f8ff                 +cmp eax, -1
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
    // 004869af  7415                   -je 0x4869c6
    if (cpu.flags.zf)
    {
        goto L_0x004869c6;
    }
    // 004869b1  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004869b3  7511                   -jne 0x4869c6
    if (!cpu.flags.zf)
    {
        goto L_0x004869c6;
    }
    // 004869b5  b8091e5600             -mov eax, 0x561e09
    cpu.eax = 5643785 /*0x561e09*/;
    // 004869ba  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004869c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004869c6:
    // 004869c6  e865feffff             -call 0x486830
    cpu.esp -= 4;
    sub_486830(app, cpu);
    if (cpu.terminate) return;
    // 004869cb  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004869d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4869e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004869e0);
    // 004869e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004869e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004869e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004869e3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004869e6  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004869ea  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004869ee  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004869f0  e837f2ffff             -call 0x485c2c
    cpu.esp -= 4;
    sub_485c2c(app, cpu);
    if (cpu.terminate) return;
    // 004869f5  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004869f8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004869fa  750a                   -jne 0x486a06
    if (!cpu.flags.zf)
    {
        goto L_0x00486a06;
    }
    // 004869fc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004869ff  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00486a02  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a05  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486a06:
    // 00486a06  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486a08  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00486a0d  e8aef3ffff             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
    // 00486a12  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00486a15  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00486a18  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00486a1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_486a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486a20);
    // 00486a20  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486a22  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00486a24  8b1d101f5600           -mov ebx, dword ptr [0x561f10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5644048) /* 0x561f10 */);
    // 00486a2a  d1fa                   +sar edx, 1
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
    // 00486a2c  e9701a0000             -jmp 0x4884a1
    return sub_4884a1(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486a34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486a34);
    // 00486a34  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486a36  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00486a38  8b1d101f5600           -mov ebx, dword ptr [0x561f10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5644048) /* 0x561f10 */);
    // 00486a3e  e95e1a0000             -jmp 0x4884a1
    return sub_4884a1(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_486a44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486a44);
    // 00486a44  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486a46  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00486a48  8b1d101f5600           -mov ebx, dword ptr [0x561f10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5644048) /* 0x561f10 */);
    // 00486a4e  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00486a50  e94c1a0000             -jmp 0x4884a1
    return sub_4884a1(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486a58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486a58);
    // 00486a58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486a59  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486a5a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00486a5c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x00486a5e:
    // 00486a5e  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00486a63  8b15101f5600           -mov edx, dword ptr [0x561f10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644048) /* 0x561f10 */);
    // 00486a69  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486a6b  e8cbba0100             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 00486a70  83c103                 +add ecx, 3
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
    // 00486a73  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00486a74  75e8                   -jne 0x486a5e
    if (!cpu.flags.zf)
    {
        goto L_0x00486a5e;
    }
    // 00486a76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486a7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486a7c);
    // 00486a7c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486a7e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00486a80  8b1d101f5600           -mov ebx, dword ptr [0x561f10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5644048) /* 0x561f10 */);
    // 00486a86  c1e202                 +shl edx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00486a89  e9131a0000             -jmp 0x4884a1
    return sub_4884a1(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486a90);
    // 00486a90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486a91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486a92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486a93  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00486a96  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00486a98  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00486a9a  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00486a9e  8a1578904d00           -mov dl, byte ptr [0x4d9078]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 00486aa4  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486aa7  735b                   -jae 0x486b04
    if (!cpu.flags.cf)
    {
        goto L_0x00486b04;
    }
    // 00486aa9  80fa04                 +cmp dl, 4
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486aac  750a                   -jne 0x486ab8
    if (!cpu.flags.zf)
    {
        goto L_0x00486ab8;
    }
    // 00486aae  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00486ab1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486ab3  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
L_0x00486ab6:
    // 00486ab6  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
L_0x00486ab8:
    // 00486ab8  a3101f5600             -mov dword ptr [0x561f10], eax
    app->getMemory<x86::reg32>(x86::reg32(5644048) /* 0x561f10 */) = cpu.eax;
    // 00486abd  66895c2404             -mov word ptr [esp + 4], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bx;
    // 00486ac2  66894c2406             -mov word ptr [esp + 6], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.cx;
    // 00486ac7  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00486ac9  b964944d00             -mov ecx, 0x4d9464
    cpu.ecx = 5084260 /*0x4d9464*/;
    // 00486ace  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486ad0  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
    // 00486ad3  a079904d00             -mov al, byte ptr [0x4d9079]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083257) /* 0x4d9079 */);
    // 00486ad8  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00486adb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00486ae0  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00486ae2  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00486ae4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00486ae6  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00486ae8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00486aeb  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00486af1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00486af3  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00486af6  e831610100             -call 0x49cc2c
    cpu.esp -= 4;
    sub_49cc2c(app, cpu);
    if (cpu.terminate) return;
    // 00486afb  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00486afe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486aff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b01  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00486b04:
    // 00486b04  7618                   -jbe 0x486b1e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486b1e;
    }
    // 00486b06  80fa0f                 +cmp dl, 0xf
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486b09  72ad                   -jb 0x486ab8
    if (cpu.flags.cf)
    {
        goto L_0x00486ab8;
    }
    // 00486b0b  7605                   -jbe 0x486b12
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486b12;
    }
    // 00486b0d  80fa10                 +cmp dl, 0x10
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486b10  75a6                   -jne 0x486ab8
    if (!cpu.flags.zf)
    {
        goto L_0x00486ab8;
    }
L_0x00486b12:
    // 00486b12  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00486b17  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486b19  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00486b1c  eb98                   -jmp 0x486ab6
    goto L_0x00486ab6;
L_0x00486b1e:
    // 00486b1e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00486b23  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486b25  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00486b28  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00486b2a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486b2c  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00486b2f  eb85                   -jmp 0x486ab6
    goto L_0x00486ab6;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_486b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486b40);
    // 00486b40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486b41  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486b43  a140a25900             -mov eax, dword ptr [0x59a240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874240) /* 0x59a240 */);
    // 00486b48  e86b180000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00486b4d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00486b4f  7423                   -je 0x486b74
    if (cpu.flags.zf)
    {
        goto L_0x00486b74;
    }
    // 00486b51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486b52  e8b94e0000             -call 0x48ba10
    cpu.esp -= 4;
    sub_48ba10(app, cpu);
    if (cpu.terminate) return;
    // 00486b57  8b0d24205600           -mov ecx, dword ptr [0x562024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5644324) /* 0x562024 */);
    // 00486b5d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486b5f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486b61  ff15b0944d00           -call dword ptr [0x4d94b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5084336) /* 0x4d94b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486b67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b68  a140a25900             -mov eax, dword ptr [0x59a240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874240) /* 0x59a240 */);
    // 00486b6d  e85e180000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00486b72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b73  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486b74:
    // 00486b74  ff15b4944d00           -call dword ptr [0x4d94b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5084340) /* 0x4d94b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486b7a  a140a25900             -mov eax, dword ptr [0x59a240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874240) /* 0x59a240 */);
    // 00486b7f  e84c180000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00486b84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486b88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486b88);
    // 00486b88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486b89  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486b8a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486b8b  833d98944d0000         +cmp dword ptr [0x4d9498], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084312) /* 0x4d9498 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486b92  7406                   -je 0x486b9a
    if (cpu.flags.zf)
    {
        goto L_0x00486b9a;
    }
    // 00486b94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486b96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b97  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486b9a:
    // 00486b9a  68e4db4c00             -push 0x4cdbe4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037028 /*0x4cdbe4*/;
    cpu.esp -= 4;
    // 00486b9f  2eff1518454c00         -call dword ptr cs:[0x4c4518]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998424) /* 0x4c4518 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486ba6  a398944d00             -mov dword ptr [0x4d9498], eax
    app->getMemory<x86::reg32>(x86::reg32(5084312) /* 0x4d9498 */) = cpu.eax;
    // 00486bab  83f820                 +cmp eax, 0x20
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
    // 00486bae  7d10                   -jge 0x486bc0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00486bc0;
    }
    // 00486bb0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486bb2  a398944d00             -mov dword ptr [0x4d9498], eax
    app->getMemory<x86::reg32>(x86::reg32(5084312) /* 0x4d9498 */) = cpu.eax;
    // 00486bb7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00486bbc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bbe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bbf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486bc0:
    // 00486bc0  68f0db4c00             -push 0x4cdbf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037040 /*0x4cdbf0*/;
    cpu.esp -= 4;
    // 00486bc5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486bc6  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486bcd  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486bcf  3d02000600             +cmp eax, 0x60002
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(393218 /*0x60002*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486bd4  7409                   -je 0x486bdf
    if (cpu.flags.zf)
    {
        goto L_0x00486bdf;
    }
    // 00486bd6  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 00486bdb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bdd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bde  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486bdf:
    // 00486bdf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486be0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486be1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486be2  6800dc4c00             -push 0x4cdc00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037056 /*0x4cdc00*/;
    cpu.esp -= 4;
    // 00486be7  8b0d98944d00           -mov ecx, dword ptr [0x4d9498]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5084312) /* 0x4d9498 */);
    // 00486bed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486bee  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00486bf0  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486bf7  68bc5c4900             -push 0x495cbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4807868 /*0x495cbc*/;
    cpu.esp -= 4;
    // 00486bfc  8b0d4cb84d00           -mov ecx, dword ptr [0x4db84c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093452) /* 0x4db84c */);
    // 00486c02  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00486c04  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00486c06  b87c384a00             -mov eax, 0x4a387c
    cpu.eax = 4864124 /*0x4a387c*/;
    // 00486c0b  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486c0d  6818dc4c00             -push 0x4cdc18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037080 /*0x4cdc18*/;
    cpu.esp -= 4;
    // 00486c12  8b1d98944d00           -mov ebx, dword ptr [0x4d9498]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5084312) /* 0x4d9498 */);
    // 00486c18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486c19  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486c20  6828dc4c00             -push 0x4cdc28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037096 /*0x4cdc28*/;
    cpu.esp -= 4;
    // 00486c25  8b3598944d00           -mov esi, dword ptr [0x4d9498]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5084312) /* 0x4d9498 */);
    // 00486c2b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486c2c  a3ac944d00             -mov dword ptr [0x4d94ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5084332) /* 0x4d94ac */) = cpu.eax;
    // 00486c31  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486c38  683cdc4c00             -push 0x4cdc3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037116 /*0x4cdc3c*/;
    cpu.esp -= 4;
    // 00486c3d  8b3d98944d00           -mov edi, dword ptr [0x4d9498]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5084312) /* 0x4d9498 */);
    // 00486c43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486c44  a3b0944d00             -mov dword ptr [0x4d94b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5084336) /* 0x4d94b0 */) = cpu.eax;
    // 00486c49  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486c50  684cdc4c00             -push 0x4cdc4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5037132 /*0x4cdc4c*/;
    cpu.esp -= 4;
    // 00486c55  8b2d98944d00           -mov ebp, dword ptr [0x4d9498]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5084312) /* 0x4d9498 */);
    // 00486c5b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486c5c  a3b4944d00             -mov dword ptr [0x4d94b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5084340) /* 0x4d94b4 */) = cpu.eax;
    // 00486c61  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486c68  a3b8944d00             -mov dword ptr [0x4d94b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5084344) /* 0x4d94b8 */) = cpu.eax;
    // 00486c6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c6f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c70  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486c72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c73  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c74  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486c78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486c78);
    // 00486c78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486c79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486c7a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486c7b  8b1598944d00           -mov edx, dword ptr [0x4d9498]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5084312) /* 0x4d9498 */);
    // 00486c81  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00486c83  750e                   -jne 0x486c93
    if (!cpu.flags.zf)
    {
        goto L_0x00486c93;
    }
    // 00486c85  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00486c87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486c89  891d98944d00           -mov dword ptr [0x4d9498], ebx
    app->getMemory<x86::reg32>(x86::reg32(5084312) /* 0x4d9498 */) = cpu.ebx;
    // 00486c8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486c93:
    // 00486c93  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486c94  2eff1570444c00         -call dword ptr cs:[0x4c4470]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998256) /* 0x4c4470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486c9b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00486c9d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486c9f  891d98944d00           -mov dword ptr [0x4d9498], ebx
    app->getMemory<x86::reg32>(x86::reg32(5084312) /* 0x4d9498 */) = cpu.ebx;
    // 00486ca5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ca6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ca7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ca8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486cac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486cac);
    // 00486cac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486cad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486cae  e8d5feffff             -call 0x486b88
    cpu.esp -= 4;
    sub_486b88(app, cpu);
    if (cpu.terminate) return;
    // 00486cb3  e8584d0000             -call 0x48ba10
    cpu.esp -= 4;
    sub_48ba10(app, cpu);
    if (cpu.terminate) return;
    // 00486cb8  ff15ac944d00           -call dword ptr [0x4d94ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5084332) /* 0x4d94ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486cbe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486cc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486cc2  7e06                   -jle 0x486cca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00486cca;
    }
    // 00486cc4  81ca00000100           -or edx, 0x10000
    cpu.edx |= x86::reg32(x86::sreg32(65536 /*0x10000*/));
L_0x00486cca:
    // 00486cca  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486ccc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ccd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486cce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486cd0);
    // 00486cd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486cd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486cd2  be9c944d00             -mov esi, 0x4d949c
    cpu.esi = 5084316 /*0x4d949c*/;
    // 00486cd7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00486cd9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486cdb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00486cdc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00486cdd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00486cde  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00486cdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ce0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ce1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486ce4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486ce4);
    // 00486ce4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486ce5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486ce6  bf9c944d00             -mov edi, 0x4d949c
    cpu.edi = 5084316 /*0x4d949c*/;
    // 00486ceb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00486ced  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00486cee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00486cef  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00486cf0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00486cf1  803da2944d0010         +cmp byte ptr [0x4d94a2], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5084322) /* 0x4d94a2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486cf8  7608                   -jbe 0x486d02
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486d02;
    }
    // 00486cfa  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00486cff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486d02:
    // 00486d02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486d04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486d08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486d08);
    // 00486d08  a394944d00             -mov dword ptr [0x4d9494], eax
    app->getMemory<x86::reg32>(x86::reg32(5084308) /* 0x4d9494 */) = cpu.eax;
    // 00486d0d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486d0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486d10);
    // 00486d10  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486d17  7506                   -jne 0x486d1f
    if (!cpu.flags.zf)
    {
        goto L_0x00486d1f;
    }
    // 00486d19  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00486d1e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486d1f:
    // 00486d1f  a140a25900             -mov eax, dword ptr [0x59a240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874240) /* 0x59a240 */);
    // 00486d24  e88f160000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00486d29  ff15b4944d00           -call dword ptr [0x4d94b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5084340) /* 0x4d94b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486d2f  a140a25900             -mov eax, dword ptr [0x59a240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874240) /* 0x59a240 */);
    // 00486d34  e897160000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00486d39  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486d3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486d3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486d3c);
    // 00486d3c  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486d43  7506                   -jne 0x486d4b
    if (!cpu.flags.zf)
    {
        goto L_0x00486d4b;
    }
    // 00486d45  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00486d4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486d4b:
    // 00486d4b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486d4c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486d4d  a140a25900             -mov eax, dword ptr [0x59a240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874240) /* 0x59a240 */);
    // 00486d52  e861160000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00486d57  e8b44c0000             -call 0x48ba10
    cpu.esp -= 4;
    sub_48ba10(app, cpu);
    if (cpu.terminate) return;
    // 00486d5c  8b0d24205600           -mov ecx, dword ptr [0x562024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5644324) /* 0x562024 */);
    // 00486d62  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486d64  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486d66  ff15b0944d00           -call dword ptr [0x4d94b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5084336) /* 0x4d94b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486d6c  a140a25900             -mov eax, dword ptr [0x59a240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874240) /* 0x59a240 */);
    // 00486d71  e85a160000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00486d76  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486d78  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486d7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486d7c);
    // 00486d7c  a140a25900             -mov eax, dword ptr [0x59a240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874240) /* 0x59a240 */);
    // 00486d81  e832160000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00486d86  ff15b8944d00           -call dword ptr [0x4d94b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5084344) /* 0x4d94b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486d8c  a140a25900             -mov eax, dword ptr [0x59a240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874240) /* 0x59a240 */);
    // 00486d91  e93a160000             -jmp 0x4883d0
    return sub_4883d0(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486d98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486d98);
    // 00486d98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486d99  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486d9c  837c241c00             +cmp dword ptr [esp + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486da1  7443                   -je 0x486de6
    if (cpu.flags.zf)
    {
        goto L_0x00486de6;
    }
    // 00486da3  803d88944d0000         +cmp byte ptr [0x4d9488], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5084296) /* 0x4d9488 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486daa  0f8588010000           -jne 0x486f38
    if (!cpu.flags.zf)
    {
        goto L_0x00486f38;
    }
L_0x00486db0:
    // 00486db0  803d89944d0000         +cmp byte ptr [0x4d9489], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5084297) /* 0x4d9489 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486db7  740f                   -je 0x486dc8
    if (cpu.flags.zf)
    {
        goto L_0x00486dc8;
    }
    // 00486db9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486dbb  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00486dbd  e87e98ffff             -call 0x480640
    cpu.esp -= 4;
    sub_480640(app, cpu);
    if (cpu.terminate) return;
    // 00486dc2  881d89944d00           -mov byte ptr [0x4d9489], bl
    app->getMemory<x86::reg8>(x86::reg32(5084297) /* 0x4d9489 */) = cpu.bl;
L_0x00486dc8:
    // 00486dc8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486dca  ff15b4944d00           -call dword ptr [0x4d94b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5084340) /* 0x4d94b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00486dd0:
    // 00486dd0  890d8c944d00           -mov dword ptr [0x4d948c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084300) /* 0x4d948c */) = cpu.ecx;
L_0x00486dd6:
    // 00486dd6  c6058b944d0001         -mov byte ptr [0x4d948b], 1
    app->getMemory<x86::reg8>(x86::reg32(5084299) /* 0x4d948b */) = 1 /*0x1*/;
    // 00486ddd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486ddf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486de2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486de3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00486de6:
    // 00486de6  a120205600             -mov eax, dword ptr [0x562020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644320) /* 0x562020 */);
    // 00486deb  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00486dee  e81d4c0000             -call 0x48ba10
    cpu.esp -= 4;
    sub_48ba10(app, cpu);
    if (cpu.terminate) return;
    // 00486df3  ff15ac944d00           -call dword ptr [0x4d94ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5084332) /* 0x4d94ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486df9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486dfb  0f8eb8000000           -jle 0x486eb9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00486eb9;
    }
    // 00486e01  8a7c2401               -mov bh, byte ptr [esp + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00486e05  f6c708                 +test bh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 8 /*0x8*/));
    // 00486e08  0f84c0000000           -je 0x486ece
    if (cpu.flags.zf)
    {
        goto L_0x00486ece;
    }
    // 00486e0e  c70590944d0022560000   -mov dword ptr [0x4d9490], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */) = 22050 /*0x5622*/;
L_0x00486e18:
    // 00486e18  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00486e1b  8a158a944d00           -mov dl, byte ptr [0x4d948a]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5084298) /* 0x4d948a */);
    // 00486e21  a324205600             -mov dword ptr [0x562024], eax
    app->getMemory<x86::reg32>(x86::reg32(5644324) /* 0x562024 */) = cpu.eax;
    // 00486e26  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00486e28  7512                   -jne 0x486e3c
    if (!cpu.flags.zf)
    {
        goto L_0x00486e3c;
    }
    // 00486e2a  b8c0ac4900             -mov eax, 0x49acc0
    cpu.eax = 4828352 /*0x49acc0*/;
    // 00486e2f  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
    // 00486e31  e8aaee0000             -call 0x495ce0
    cpu.esp -= 4;
    sub_495ce0(app, cpu);
    if (cpu.terminate) return;
    // 00486e36  88358a944d00           -mov byte ptr [0x4d948a], dh
    app->getMemory<x86::reg8>(x86::reg32(5084298) /* 0x4d948a */) = cpu.dh;
L_0x00486e3c:
    // 00486e3c  bae8114a00             -mov edx, 0x4a11e8
    cpu.edx = 4854248 /*0x4a11e8*/;
    // 00486e41  a124205600             -mov eax, dword ptr [0x562024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644324) /* 0x562024 */);
    // 00486e46  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00486e4b  e898bd0100             -call 0x4a2be8
    cpu.esp -= 4;
    sub_4a2be8(app, cpu);
    if (cpu.terminate) return;
    // 00486e50  8b15e09b5900           -mov edx, dword ptr [0x599be0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5872608) /* 0x599be0 */);
    // 00486e56  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00486e58  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486e5a  e8ed000000             -call 0x486f4c
    cpu.esp -= 4;
    sub_486f4c(app, cpu);
    if (cpu.terminate) return;
    // 00486e5f  e8ac4b0000             -call 0x48ba10
    cpu.esp -= 4;
    sub_48ba10(app, cpu);
    if (cpu.terminate) return;
    // 00486e64  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486e66  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00486e69  ff15b0944d00           -call dword ptr [0x4d94b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5084336) /* 0x4d94b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486e6f  a38c944d00             -mov dword ptr [0x4d948c], eax
    app->getMemory<x86::reg32>(x86::reg32(5084300) /* 0x4d948c */) = cpu.eax;
    // 00486e74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486e76  0f8c5affffff           -jl 0x486dd6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486dd6;
    }
    // 00486e7c  803d88944d0000         +cmp byte ptr [0x4d9488], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5084296) /* 0x4d9488 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486e83  7512                   -jne 0x486e97
    if (!cpu.flags.zf)
    {
        goto L_0x00486e97;
    }
    // 00486e85  b87c6d4800             -mov eax, 0x486d7c
    cpu.eax = 4746620 /*0x486d7c*/;
    // 00486e8a  b701                   -mov bh, 1
    cpu.bh = 1 /*0x1*/;
    // 00486e8c  e8abaeffff             -call 0x481d3c
    cpu.esp -= 4;
    sub_481d3c(app, cpu);
    if (cpu.terminate) return;
    // 00486e91  883d88944d00           -mov byte ptr [0x4d9488], bh
    app->getMemory<x86::reg8>(x86::reg32(5084296) /* 0x4d9488 */) = cpu.bh;
L_0x00486e97:
    // 00486e97  803d89944d0000         +cmp byte ptr [0x4d9489], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5084297) /* 0x4d9489 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486e9e  7512                   -jne 0x486eb2
    if (!cpu.flags.zf)
    {
        goto L_0x00486eb2;
    }
    // 00486ea0  b8406b4800             -mov eax, 0x486b40
    cpu.eax = 4746048 /*0x486b40*/;
    // 00486ea5  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 00486ea7  e89497ffff             -call 0x480640
    cpu.esp -= 4;
    sub_480640(app, cpu);
    if (cpu.terminate) return;
    // 00486eac  882d89944d00           -mov byte ptr [0x4d9489], ch
    app->getMemory<x86::reg8>(x86::reg32(5084297) /* 0x4d9489 */) = cpu.ch;
L_0x00486eb2:
    // 00486eb2  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00486eb4  e917ffffff             -jmp 0x486dd0
    goto L_0x00486dd0;
L_0x00486eb9:
    // 00486eb9  a38c944d00             -mov dword ptr [0x4d948c], eax
    app->getMemory<x86::reg32>(x86::reg32(5084300) /* 0x4d948c */) = cpu.eax;
    // 00486ebe  c6058b944d0001         -mov byte ptr [0x4d948b], 1
    app->getMemory<x86::reg8>(x86::reg32(5084299) /* 0x4d948b */) = 1 /*0x1*/;
    // 00486ec5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486ec7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486eca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ecb  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00486ece:
    // 00486ece  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 00486ed1  740f                   -je 0x486ee2
    if (cpu.flags.zf)
    {
        goto L_0x00486ee2;
    }
    // 00486ed3  c70590944d00803e0000   -mov dword ptr [0x4d9490], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */) = 16000 /*0x3e80*/;
    // 00486edd  e936ffffff             -jmp 0x486e18
    goto L_0x00486e18;
L_0x00486ee2:
    // 00486ee2  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 00486ee5  740f                   -je 0x486ef6
    if (cpu.flags.zf)
    {
        goto L_0x00486ef6;
    }
    // 00486ee7  c70590944d00007d0000   -mov dword ptr [0x4d9490], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */) = 32000 /*0x7d00*/;
    // 00486ef1  e922ffffff             -jmp 0x486e18
    goto L_0x00486e18;
L_0x00486ef6:
    // 00486ef6  f6c720                 +test bh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 32 /*0x20*/));
    // 00486ef9  740f                   -je 0x486f0a
    if (cpu.flags.zf)
    {
        goto L_0x00486f0a;
    }
    // 00486efb  c70590944d0044ac0000   -mov dword ptr [0x4d9490], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */) = 44100 /*0xac44*/;
    // 00486f05  e90effffff             -jmp 0x486e18
    goto L_0x00486e18;
L_0x00486f0a:
    // 00486f0a  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 00486f0d  740f                   -je 0x486f1e
    if (cpu.flags.zf)
    {
        goto L_0x00486f1e;
    }
    // 00486f0f  c70590944d00112b0000   -mov dword ptr [0x4d9490], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */) = 11025 /*0x2b11*/;
    // 00486f19  e9fafeffff             -jmp 0x486e18
    goto L_0x00486e18;
L_0x00486f1e:
    // 00486f1e  c7058c944d00f8ffffff   -mov dword ptr [0x4d948c], 0xfffffff8
    app->getMemory<x86::reg32>(x86::reg32(5084300) /* 0x4d948c */) = 4294967288 /*0xfffffff8*/;
    // 00486f28  c6058b944d0001         -mov byte ptr [0x4d948b], 1
    app->getMemory<x86::reg8>(x86::reg32(5084299) /* 0x4d948b */) = 1 /*0x1*/;
    // 00486f2f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486f31  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486f34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f35  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00486f38:
    // 00486f38  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00486f3a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00486f3c  881588944d00           -mov byte ptr [0x4d9488], dl
    app->getMemory<x86::reg8>(x86::reg32(5084296) /* 0x4d9488 */) = cpu.dl;
    // 00486f42  e8f5adffff             -call 0x481d3c
    cpu.esp -= 4;
    sub_481d3c(app, cpu);
    if (cpu.terminate) return;
    // 00486f47  e964feffff             -jmp 0x486db0
    goto L_0x00486db0;
}

/* align: skip  */
void Application::sub_486f4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486f4c);
    // 00486f4c  83fa28                 +cmp edx, 0x28
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486f4f  7316                   -jae 0x486f67
    if (!cpu.flags.cf)
    {
        goto L_0x00486f67;
    }
    // 00486f51  83fa0a                 +cmp edx, 0xa
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486f54  720e                   -jb 0x486f64
    if (cpu.flags.cf)
    {
        goto L_0x00486f64;
    }
    // 00486f56  761b                   -jbe 0x486f73
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486f73;
    }
    // 00486f58  83fa14                 +cmp edx, 0x14
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486f5b  7207                   -jb 0x486f64
    if (cpu.flags.cf)
    {
        goto L_0x00486f64;
    }
    // 00486f5d  7614                   -jbe 0x486f73
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486f73;
    }
    // 00486f5f  83fa1e                 +cmp edx, 0x1e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486f62  740f                   -je 0x486f73
    if (cpu.flags.zf)
    {
        goto L_0x00486f73;
    }
L_0x00486f64:
    // 00486f64  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00486f66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486f67:
    // 00486f67  760a                   -jbe 0x486f73
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486f73;
    }
    // 00486f69  83fa64                 +cmp edx, 0x64
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486f6c  7312                   -jae 0x486f80
    if (!cpu.flags.cf)
    {
        goto L_0x00486f80;
    }
    // 00486f6e  83fa32                 +cmp edx, 0x32
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486f71  75f1                   -jne 0x486f64
    if (!cpu.flags.zf)
    {
        goto L_0x00486f64;
    }
L_0x00486f73:
    // 00486f73  a190944d00             -mov eax, dword ptr [0x4d9490]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */);
    // 00486f78  e89fc90100             -call 0x4a391c
    cpu.esp -= 4;
    sub_4a391c(app, cpu);
    if (cpu.terminate) return;
    // 00486f7d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00486f7f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486f80:
    // 00486f80  76f1                   -jbe 0x486f73
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486f73;
    }
    // 00486f82  83fa6e                 +cmp edx, 0x6e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(110 /*0x6e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486f85  72dd                   -jb 0x486f64
    if (cpu.flags.cf)
    {
        goto L_0x00486f64;
    }
    // 00486f87  76ea                   -jbe 0x486f73
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486f73;
    }
    // 00486f89  83fa78                 +cmp edx, 0x78
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486f8c  74e5                   -je 0x486f73
    if (cpu.flags.zf)
    {
        goto L_0x00486f73;
    }
    // 00486f8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486f90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486f94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486f94);
    // 00486f94  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486f9b  75af                   -jne 0x486f4c
    if (!cpu.flags.zf)
    {
        return sub_486f4c(app, cpu);
    }
    // 00486f9d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00486fa0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486fa2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486fa0);
    goto L_entry_0x00486fa0;
    // 00486f94  803d38b84d0000         +cmp byte ptr [0x4db838], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486f9b  75af                   -jne 0x486f4c
    if (!cpu.flags.zf)
    {
        return sub_486f4c(app, cpu);
    }
    // 00486f9d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00486fa0:
    // 00486fa0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486fa2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486fa4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486fa4);
    // 00486fa4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486fa5  a320205600             -mov dword ptr [0x562020], eax
    app->getMemory<x86::reg32>(x86::reg32(5644320) /* 0x562020 */) = cpu.eax;
    // 00486faa  e8d9fbffff             -call 0x486b88
    cpu.esp -= 4;
    sub_486b88(app, cpu);
    if (cpu.terminate) return;
    // 00486faf  833de8894d0000         +cmp dword ptr [0x4d89e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486fb6  7507                   -jne 0x486fbf
    if (!cpu.flags.zf)
    {
        goto L_0x00486fbf;
    }
L_0x00486fb8:
    // 00486fb8  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 00486fbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fbe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486fbf:
    // 00486fbf  e84c4a0000             -call 0x48ba10
    cpu.esp -= 4;
    sub_48ba10(app, cpu);
    if (cpu.terminate) return;
    // 00486fc4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486fc6  74f0                   -je 0x486fb8
    if (cpu.flags.zf)
    {
        goto L_0x00486fb8;
    }
    // 00486fc8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486fc9  68986d4800             -push 0x486d98
    app->getMemory<x86::reg32>(cpu.esp-4) = 4746648 /*0x486d98*/;
    cpu.esp -= 4;
    // 00486fce  6800820000             -push 0x8200
    app->getMemory<x86::reg32>(cpu.esp-4) = 33280 /*0x8200*/;
    cpu.esp -= 4;
    // 00486fd3  e80897ffff             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 00486fd8  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00486fda  88258b944d00           -mov byte ptr [0x4d948b], ah
    app->getMemory<x86::reg8>(x86::reg32(5084299) /* 0x4d948b */) = cpu.ah;
    // 00486fe0  b800820000             -mov eax, 0x8200
    cpu.eax = 33280 /*0x8200*/;
    // 00486fe5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486fe7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00486fe9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00486feb  e86096ffff             -call 0x480650
    cpu.esp -= 4;
    sub_480650(app, cpu);
    if (cpu.terminate) return;
    // 00486ff0  803d8b944d0000         +cmp byte ptr [0x4d948b], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5084299) /* 0x4d948b */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486ff7  7513                   -jne 0x48700c
    if (!cpu.flags.zf)
    {
        goto L_0x0048700c;
    }
    // 00486ff9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00486ffb:
    // 00486ffb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486ffd  e80a100000             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 00487002  3a158b944d00           +cmp dl, byte ptr [0x4d948b]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5084299) /* 0x4d948b */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487008  74f1                   -je 0x486ffb
    if (cpu.flags.zf)
    {
        goto L_0x00486ffb;
    }
    // 0048700a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0048700c:
    // 0048700c  a18c944d00             -mov eax, dword ptr [0x4d948c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084300) /* 0x4d948c */);
    // 00487011  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487012  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487013  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_487014(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487014);
    // 00487014  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487015  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487016  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487017  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00487019  88258b944d00           -mov byte ptr [0x4d948b], ah
    app->getMemory<x86::reg8>(x86::reg32(5084299) /* 0x4d948b */) = cpu.ah;
    // 0048701f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00487024  b800820000             -mov eax, 0x8200
    cpu.eax = 33280 /*0x8200*/;
    // 00487029  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048702b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048702d  e81e96ffff             -call 0x480650
    cpu.esp -= 4;
    sub_480650(app, cpu);
    if (cpu.terminate) return;
    // 00487032  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487034  7420                   -je 0x487056
    if (cpu.flags.zf)
    {
        goto L_0x00487056;
    }
L_0x00487036:
    // 00487036  803d8b944d0000         +cmp byte ptr [0x4d948b], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5084299) /* 0x4d948b */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048703d  740e                   -je 0x48704d
    if (cpu.flags.zf)
    {
        goto L_0x0048704d;
    }
    // 0048703f  e834fcffff             -call 0x486c78
    cpu.esp -= 4;
    sub_486c78(app, cpu);
    if (cpu.terminate) return;
    // 00487044  a18c944d00             -mov eax, dword ptr [0x4d948c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084300) /* 0x4d948c */);
    // 00487049  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048704a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048704b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048704c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048704d:
    // 0048704d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048704f  e8b80f0000             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 00487054  ebe0                   -jmp 0x487036
    goto L_0x00487036;
L_0x00487056:
    // 00487056  803d88944d0000         +cmp byte ptr [0x4d9488], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5084296) /* 0x4d9488 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048705d  740d                   -je 0x48706c
    if (cpu.flags.zf)
    {
        goto L_0x0048706c;
    }
    // 0048705f  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00487061  883588944d00           -mov byte ptr [0x4d9488], dh
    app->getMemory<x86::reg8>(x86::reg32(5084296) /* 0x4d9488 */) = cpu.dh;
    // 00487067  e8d0acffff             -call 0x481d3c
    cpu.esp -= 4;
    sub_481d3c(app, cpu);
    if (cpu.terminate) return;
L_0x0048706c:
    // 0048706c  803d89944d0000         +cmp byte ptr [0x4d9489], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5084297) /* 0x4d9489 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487073  740f                   -je 0x487084
    if (cpu.flags.zf)
    {
        goto L_0x00487084;
    }
    // 00487075  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487077  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00487079  e8c295ffff             -call 0x480640
    cpu.esp -= 4;
    sub_480640(app, cpu);
    if (cpu.terminate) return;
    // 0048707e  883d89944d00           -mov byte ptr [0x4d9489], bh
    app->getMemory<x86::reg8>(x86::reg32(5084297) /* 0x4d9489 */) = cpu.bh;
L_0x00487084:
    // 00487084  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487086  89158c944d00           -mov dword ptr [0x4d948c], edx
    app->getMemory<x86::reg32>(x86::reg32(5084300) /* 0x4d948c */) = cpu.edx;
    // 0048708c  e8e7fbffff             -call 0x486c78
    cpu.esp -= 4;
    sub_486c78(app, cpu);
    if (cpu.terminate) return;
    // 00487091  a18c944d00             -mov eax, dword ptr [0x4d948c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084300) /* 0x4d948c */);
    // 00487096  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487097  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487098  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487099  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48709c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048709c);
    // 0048709c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048709d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048709f  e86cfcffff             -call 0x486d10
    cpu.esp -= 4;
    sub_486d10(app, cpu);
    if (cpu.terminate) return;
    // 004870a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004870a6  7c5b                   -jl 0x487103
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487103;
    }
    // 004870a8  890d24205600           -mov dword ptr [0x562024], ecx
    app->getMemory<x86::reg32>(x86::reg32(5644324) /* 0x562024 */) = cpu.ecx;
    // 004870ae  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 004870b1  7552                   -jne 0x487105
    if (!cpu.flags.zf)
    {
        goto L_0x00487105;
    }
    // 004870b3  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 004870b6  7459                   -je 0x487111
    if (cpu.flags.zf)
    {
        goto L_0x00487111;
    }
    // 004870b8  c70590944d00803e0000   -mov dword ptr [0x4d9490], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */) = 16000 /*0x3e80*/;
L_0x004870c2:
    // 004870c2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004870c4  e877bd0100             -call 0x4a2e40
    cpu.esp -= 4;
    sub_4a2e40(app, cpu);
    if (cpu.terminate) return;
    // 004870c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004870cb  7c36                   -jl 0x487103
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487103;
    }
    // 004870cd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004870ce  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004870d0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004870d2:
    // 004870d2  80b9fc9b590001         +cmp byte ptr [ecx + 0x599bfc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5872636) /* 0x599bfc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004870d9  7519                   -jne 0x4870f4
    if (!cpu.flags.zf)
    {
        goto L_0x004870f4;
    }
    // 004870db  83b9f09b590000         +cmp dword ptr [ecx + 0x599bf0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5872624) /* 0x599bf0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004870e2  7c10                   -jl 0x4870f4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004870f4;
    }
    // 004870e4  8b91009c5900           -mov edx, dword ptr [ecx + 0x599c00]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5872640) /* 0x599c00 */);
    // 004870ea  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004870ec  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004870ef  e80c0a0000             -call 0x487b00
    cpu.esp -= 4;
    sub_487b00(app, cpu);
    if (cpu.terminate) return;
L_0x004870f4:
    // 004870f4  43                     -inc ebx
    (cpu.ebx)++;
    // 004870f5  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004870f8  83fb10                 +cmp ebx, 0x10
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004870fb  7cd5                   -jl 0x4870d2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004870d2;
    }
    // 004870fd  e83afcffff             -call 0x486d3c
    cpu.esp -= 4;
    sub_486d3c(app, cpu);
    if (cpu.terminate) return;
    // 00487102  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00487103:
    // 00487103  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487104  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487105:
    // 00487105  c70590944d0022560000   -mov dword ptr [0x4d9490], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */) = 22050 /*0x5622*/;
    // 0048710f  ebb1                   -jmp 0x4870c2
    goto L_0x004870c2;
L_0x00487111:
    // 00487111  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00487114  740c                   -je 0x487122
    if (cpu.flags.zf)
    {
        goto L_0x00487122;
    }
    // 00487116  c70590944d00007d0000   -mov dword ptr [0x4d9490], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */) = 32000 /*0x7d00*/;
    // 00487120  eba0                   -jmp 0x4870c2
    goto L_0x004870c2;
L_0x00487122:
    // 00487122  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 00487125  740c                   -je 0x487133
    if (cpu.flags.zf)
    {
        goto L_0x00487133;
    }
    // 00487127  c70590944d0044ac0000   -mov dword ptr [0x4d9490], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */) = 44100 /*0xac44*/;
    // 00487131  eb8f                   -jmp 0x4870c2
    goto L_0x004870c2;
L_0x00487133:
    // 00487133  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 00487136  740f                   -je 0x487147
    if (cpu.flags.zf)
    {
        goto L_0x00487147;
    }
    // 00487138  c70590944d00112b0000   -mov dword ptr [0x4d9490], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */) = 11025 /*0x2b11*/;
    // 00487142  e97bffffff             -jmp 0x4870c2
    goto L_0x004870c2;
L_0x00487147:
    // 00487147  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048714c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048714d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_487150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487150);
    // 00487150  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00487152  7409                   -je 0x48715d
    if (cpu.flags.zf)
    {
        goto L_0x0048715d;
    }
    // 00487154  015018                 -add dword ptr [eax + 0x18], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00487157  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0048715c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048715d:
    // 0048715d  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00487160  015018                 -add dword ptr [eax + 0x18], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00487163  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 00487168  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48716c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048716c);
    // 0048716c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048716d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048716e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048716f  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00487172  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00487176  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00487178  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048717c  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00487180  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00487182  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00487185  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00487187  888a251f5600           -mov byte ptr [edx + 0x561f25], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5644069) /* 0x561f25 */) = cpu.cl;
    // 0048718d  c682261f560001         -mov byte ptr [edx + 0x561f26], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5644070) /* 0x561f26 */) = 1 /*0x1*/;
    // 00487194  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 00487196  66898a2a1f5600         -mov word ptr [edx + 0x561f2a], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5644074) /* 0x561f2a */) = cpu.cx;
    // 0048719d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048719f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004871a1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004871a3  81fa544d706c           +cmp edx, 0x6c704d54
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1819299156 /*0x6c704d54*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004871a9  0f85fa000000           -jne 0x4872a9
    if (!cpu.flags.zf)
    {
        goto L_0x004872a9;
    }
    // 004871af  80780400               +cmp byte ptr [eax + 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004871b3  0f85fe000000           -jne 0x4872b7
    if (!cpu.flags.zf)
    {
        goto L_0x004872b7;
    }
    // 004871b9  80780510               +cmp byte ptr [eax + 5], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004871bd  0f8502010000           -jne 0x4872c5
    if (!cpu.flags.zf)
    {
        goto L_0x004872c5;
    }
    // 004871c3  80780601               +cmp byte ptr [eax + 6], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004871c7  0f85f8000000           -jne 0x4872c5
    if (!cpu.flags.zf)
    {
        goto L_0x004872c5;
    }
    // 004871cd  c744241c04000000       -mov dword ptr [esp + 0x1c], 4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 4 /*0x4*/;
L_0x004871d5:
    // 004871d5  837c241002             +cmp dword ptr [esp + 0x10], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004871da  0f8530010000           -jne 0x487310
    if (!cpu.flags.zf)
    {
        goto L_0x00487310;
    }
    // 004871e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004871e2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004871e7  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004871eb  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004871ef  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x004871f3:
    // 004871f3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004871f5  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004871f8  668b560a               -mov dx, word ptr [esi + 0xa]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004871fc  668990201f5600         -mov word ptr [eax + 0x561f20], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5644064) /* 0x561f20 */) = cpu.dx;
    // 00487203  8a5605                 -mov dl, byte ptr [esi + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 00487206  8890221f5600           -mov byte ptr [eax + 0x561f22], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5644066) /* 0x561f22 */) = cpu.dl;
    // 0048720c  8a5606                 -mov dl, byte ptr [esi + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0048720f  8890231f5600           -mov byte ptr [eax + 0x561f23], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5644067) /* 0x561f23 */) = cpu.dl;
    // 00487215  8a5607                 -mov dl, byte ptr [esi + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */);
    // 00487218  8890241f5600           -mov byte ptr [eax + 0x561f24], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5644068) /* 0x561f24 */) = cpu.dl;
    // 0048721e  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00487222  89902c1f5600           -mov dword ptr [eax + 0x561f2c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5644076) /* 0x561f2c */) = cpu.edx;
    // 00487228  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048722a  8b1590944d00           -mov edx, dword ptr [0x4d9490]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */);
    // 00487230  668b460a               -mov ax, word ptr [esi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 00487234  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487238  e8a3c70100             -call 0x4a39e0
    cpu.esp -= 4;
    sub_4a39e0(app, cpu);
    if (cpu.terminate) return;
    // 0048723d  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048723f  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00487243  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00487247  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048724b  e8d0c70100             -call 0x4a3a20
    cpu.esp -= 4;
    sub_4a3a20(app, cpu);
    if (cpu.terminate) return;
    // 00487250  033d94944d00           -add edi, dword ptr [0x4d9494]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5084308) /* 0x4d9494 */)));
    // 00487256  83ff64                 +cmp edi, 0x64
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487259  0f8eef000000           -jle 0x48734e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048734e;
    }
    // 0048725f  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
L_0x00487264:
    // 00487264  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00487268  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487269  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048726a  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048726e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048726f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00487273  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487274  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00487278  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487279  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048727d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048727e  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00487282  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00487286  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487287  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048728a  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048728e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048728f  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00487293  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00487295  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487296  8a5e07                 -mov bl, byte ptr [esi + 7]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */);
    // 00487299  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048729b  e86cbc0100             -call 0x4a2f0c
    cpu.esp -= 4;
    sub_4a2f0c(app, cpu);
    if (cpu.terminate) return;
    // 004872a0  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004872a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872a6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004872a9:
    // 004872a9  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004872ae  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004872b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872b4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004872b7:
    // 004872b7  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 004872bc  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004872bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872c2  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004872c5:
    // 004872c5  807e0510               +cmp byte ptr [esi + 5], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004872c9  7513                   -jne 0x4872de
    if (!cpu.flags.zf)
    {
        goto L_0x004872de;
    }
    // 004872cb  807e0602               +cmp byte ptr [esi + 6], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004872cf  750d                   -jne 0x4872de
    if (!cpu.flags.zf)
    {
        goto L_0x004872de;
    }
    // 004872d1  c744241c08000000       -mov dword ptr [esp + 0x1c], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 8 /*0x8*/;
    // 004872d9  e9f7feffff             -jmp 0x4871d5
    goto L_0x004871d5;
L_0x004872de:
    // 004872de  807e0508               +cmp byte ptr [esi + 5], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004872e2  7513                   -jne 0x4872f7
    if (!cpu.flags.zf)
    {
        goto L_0x004872f7;
    }
    // 004872e4  807e0601               +cmp byte ptr [esi + 6], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004872e8  750d                   -jne 0x4872f7
    if (!cpu.flags.zf)
    {
        goto L_0x004872f7;
    }
    // 004872ea  c744241c01000000       -mov dword ptr [esp + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 004872f2  e9defeffff             -jmp 0x4871d5
    goto L_0x004871d5;
L_0x004872f7:
    // 004872f7  807e0508               +cmp byte ptr [esi + 5], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004872fb  75ac                   -jne 0x4872a9
    if (!cpu.flags.zf)
    {
        goto L_0x004872a9;
    }
    // 004872fd  807e0602               +cmp byte ptr [esi + 6], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487301  75a6                   -jne 0x4872a9
    if (!cpu.flags.zf)
    {
        goto L_0x004872a9;
    }
    // 00487303  c744241c02000000       -mov dword ptr [esp + 0x1c], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 2 /*0x2*/;
    // 0048730b  e9c5feffff             -jmp 0x4871d5
    goto L_0x004871d5;
L_0x00487310:
    // 00487310  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00487313  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00487317  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048731a  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048731e  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00487321  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00487325  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00487329  83faff                 +cmp edx, -1
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
    // 0048732c  7d08                   -jge 0x487336
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487336;
    }
    // 0048732e  c7442418ffffffff       -mov dword ptr [esp + 0x18], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 4294967295 /*0xffffffff*/;
L_0x00487336:
    // 00487336  837c2420ff             +cmp dword ptr [esp + 0x20], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048733b  0f8db2feffff           -jge 0x4871f3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004871f3;
    }
    // 00487341  c7442420ffffffff       -mov dword ptr [esp + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 00487349  e9a5feffff             -jmp 0x4871f3
    goto L_0x004871f3;
L_0x0048734e:
    // 0048734e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00487350  0f8d0effffff           -jge 0x487264
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487264;
    }
    // 00487356  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00487358  e907ffffff             -jmp 0x487264
    goto L_0x00487264;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4873a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004873a8);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004873a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004873a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004873aa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004873ab  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004873ae  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004873b0  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004873b4  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004873b8  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004873bd  bd22560000             -mov ebp, 0x5622
    cpu.ebp = 22050 /*0x5622*/;
    // 004873c2  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004873c7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004873c9  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004873cd  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004873d1  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004873d5  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004873d9  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004873dd  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004873e1  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 004873e5  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 004873e8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004873ed  81c7201f5600           -add edi, 0x561f20
    (cpu.edi) += x86::reg32(x86::sreg32(5644064 /*0x561f20*/));
    // 004873f3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004873f5  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004873f9  c6470500               -mov byte ptr [edi + 5], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */) = 0 /*0x0*/;
    // 004873fd  8a542458               -mov dl, byte ptr [esp + 0x58]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00487401  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00487403  885706                 -mov byte ptr [edi + 6], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00487406  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0048740a  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0048740e  6689570a               -mov word ptr [edi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 00487412  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487414  754f                   -jne 0x487465
    if (!cpu.flags.zf)
    {
        goto L_0x00487465;
    }
L_0x00487416:
    // 00487416  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 00487418  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048741b  0f840f010000           -je 0x487530
    if (cpu.flags.zf)
    {
        goto L_0x00487530;
    }
    // 00487421  80fcfe                 +cmp ah, 0xfe
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487424  0f8406010000           -je 0x487530
    if (cpu.flags.zf)
    {
        goto L_0x00487530;
    }
    // 0048742a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048742c  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 0048742e  46                     -inc esi
    (cpu.esi)++;
    // 0048742f  81fbfc000000           +cmp ebx, 0xfc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487435  74df                   -je 0x487416
    if (cpu.flags.zf)
    {
        goto L_0x00487416;
    }
    // 00487437  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00487439  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0048743b  81f9ff000000           +cmp ecx, 0xff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487441  7512                   -jne 0x487455
    if (!cpu.flags.zf)
    {
        goto L_0x00487455;
    }
    // 00487443  46                     -inc esi
    (cpu.esi)++;
    // 00487444  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00487449  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048744b  e800c60100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 00487450  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487452  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00487455:
    // 00487455  8d837fffffff           -lea eax, [ebx - 0x81]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-129) /* -0x81 */);
    // 0048745b  46                     -inc esi
    (cpu.esi)++;
    // 0048745c  83f811                 +cmp eax, 0x11
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048745f  7612                   -jbe 0x487473
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00487473;
    }
  [[fallthrough]];
  case 0x00487461:
    // 00487461  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487463  ebb1                   -jmp 0x487416
    goto L_0x00487416;
L_0x00487465:
    // 00487465  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0048746a  83c430                 +add esp, 0x30
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048746d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048746e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048746f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487470  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x00487473:
    // 00487473  ff248560734800         -jmp dword ptr [eax*4 + 0x487360]
    cpu.ip = app->getMemory<x86::reg32>(4748128 + cpu.eax * 4); goto dynamic_jump;
  case 0x0048747a:
    // 0048747a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048747c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048747e  e8cdc50100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 00487483  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00487487  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487489  eb8b                   -jmp 0x487416
    goto L_0x00487416;
  case 0x0048748b:
    // 0048748b  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0048748f  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487491  eb83                   -jmp 0x487416
    goto L_0x00487416;
  case 0x00487493:
    // 00487493  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00487495  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487497  e8b4c50100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 0048749c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004874a0  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004874a2  e96fffffff             -jmp 0x487416
    goto L_0x00487416;
  case 0x004874a7:
    // 004874a7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004874a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004874ab  e8a0c50100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004874b0  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004874b4  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004874b6  e95bffffff             -jmp 0x487416
    goto L_0x00487416;
  case 0x004874bb:
    // 004874bb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004874bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004874bf  e88cc50100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004874c4  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004874c8  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004874ca  e947ffffff             -jmp 0x487416
    goto L_0x00487416;
  case 0x004874cf:
    // 004874cf  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004874d1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004874d3  e878c50100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004874d8  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004874dc  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004874de  e933ffffff             -jmp 0x487416
    goto L_0x00487416;
  case 0x004874e3:
    // 004874e3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004874e5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004874e7  e864c50100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004874ec  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004874f0  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004874f2  e91fffffff             -jmp 0x487416
    goto L_0x00487416;
  case 0x004874f7:
    // 004874f7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004874f9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004874fb  e850c50100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 00487500  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00487504  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487506  e90bffffff             -jmp 0x487416
    goto L_0x00487416;
  case 0x0048750b:
    // 0048750b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048750d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048750f  e83cc50100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 00487514  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00487516  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487518  e9f9feffff             -jmp 0x487416
    goto L_0x00487416;
  case 0x0048751d:
    // 0048751d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048751f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487521  e82ac50100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 00487526  884705                 -mov byte ptr [edi + 5], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */) = cpu.al;
    // 00487529  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048752b  e9e6feffff             -jmp 0x487416
    goto L_0x00487416;
L_0x00487530:
    // 00487530  837c241402             +cmp dword ptr [esp + 0x14], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487535  0f85e4000000           -jne 0x48761f
    if (!cpu.flags.zf)
    {
        goto L_0x0048761f;
    }
    // 0048753b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048753d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00487542  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00487546  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0048754a  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x0048754e:
    // 0048754e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487552  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 00487555  8a44242c               -mov al, byte ptr [esp + 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00487559  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0048755c  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487560  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00487563  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00487567  884704                 -mov byte ptr [edi + 4], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0048756a  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048756e  8a7705                 -mov dh, byte ptr [edi + 5]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 00487571  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00487574  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00487576  0f85e2000000           -jne 0x48765e
    if (!cpu.flags.zf)
    {
        goto L_0x0048765e;
    }
    // 0048757c  837c245800             +cmp dword ptr [esp + 0x58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487581  0f84bf000000           -je 0x487646
    if (cpu.flags.zf)
    {
        goto L_0x00487646;
    }
    // 00487587  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048758b  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048758d  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00487591  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00487595  e886c40100             -call 0x4a3a20
    cpu.esp -= 4;
    sub_4a3a20(app, cpu);
    if (cpu.terminate) return;
L_0x0048759a:
    // 0048759a  837c242c10             +cmp dword ptr [esp + 0x2c], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048759f  0f851d010000           -jne 0x4876c2
    if (!cpu.flags.zf)
    {
        goto L_0x004876c2;
    }
    // 004875a5  837c240c01             +cmp dword ptr [esp + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004875aa  0f8512010000           -jne 0x4876c2
    if (!cpu.flags.zf)
    {
        goto L_0x004876c2;
    }
    // 004875b0  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
L_0x004875b5:
    // 004875b5  8b5c2448               -mov ebx, dword ptr [esp + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004875b9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004875bd  8b1590944d00           -mov edx, dword ptr [0x4d9490]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5084304) /* 0x4d9490 */);
    // 004875c3  e818c40100             -call 0x4a39e0
    cpu.esp -= 4;
    sub_4a39e0(app, cpu);
    if (cpu.terminate) return;
    // 004875c8  032d94944d00           -add ebp, dword ptr [0x4d9494]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5084308) /* 0x4d9494 */)));
    // 004875ce  83fd64                 +cmp ebp, 0x64
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004875d1  0f8e39010000           -jle 0x487710
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487710;
    }
    // 004875d7  bd64000000             -mov ebp, 0x64
    cpu.ebp = 100 /*0x64*/;
L_0x004875dc:
    // 004875dc  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004875e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004875e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004875e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004875e3  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004875e7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004875e8  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004875ec  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004875ed  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004875f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004875f2  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004875f6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004875f7  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004875fb  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004875ff  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487600  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00487602  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00487604  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00487608  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487609  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048760d  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00487611  e8f6b80100             -call 0x4a2f0c
    cpu.esp -= 4;
    sub_4a2f0c(app, cpu);
    if (cpu.terminate) return;
    // 00487616  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00487619  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048761a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048761b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048761c  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x0048761f:
    // 0048761f  837c2424ff             +cmp dword ptr [esp + 0x24], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487624  7d08                   -jge 0x48762e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048762e;
    }
    // 00487626  c7442424ffffffff       -mov dword ptr [esp + 0x24], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 4294967295 /*0xffffffff*/;
L_0x0048762e:
    // 0048762e  837c2428ff             +cmp dword ptr [esp + 0x28], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487633  0f8d15ffffff           -jge 0x48754e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048754e;
    }
    // 00487639  c7442428ffffffff       -mov dword ptr [esp + 0x28], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 4294967295 /*0xffffffff*/;
    // 00487641  e908ffffff             -jmp 0x48754e
    goto L_0x0048754e;
L_0x00487646:
    // 00487646  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048764a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048764c  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00487650  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00487654  e897cf0100             -call 0x4a45f0
    cpu.esp -= 4;
    sub_4a45f0(app, cpu);
    if (cpu.terminate) return;
    // 00487659  e93cffffff             -jmp 0x48759a
    goto L_0x0048759a;
L_0x0048765e:
    // 0048765e  80fe01                 +cmp dh, 1
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487661  0f85fefdffff           -jne 0x487465
    if (!cpu.flags.zf)
    {
        goto L_0x00487465;
    }
    // 00487667  837c240c01             +cmp dword ptr [esp + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048766c  0f85f3fdffff           -jne 0x487465
    if (!cpu.flags.zf)
    {
        goto L_0x00487465;
    }
    // 00487672  837c245800             +cmp dword ptr [esp + 0x58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487677  7414                   -je 0x48768d
    if (cpu.flags.zf)
    {
        goto L_0x0048768d;
    }
    // 00487679  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048767d  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00487680  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00487682  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00487686  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 00487689  89742450               -mov dword ptr [esp + 0x50], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.esi;
L_0x0048768d:
    // 0048768d  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 00487690  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00487693  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487694  8b4705                 -mov eax, dword ptr [edi + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 00487697  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048769b  c1f818                 +sar eax, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0048769e  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004876a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004876a3  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004876a7  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004876ab  e870cf0100             -call 0x4a4620
    cpu.esp -= 4;
    sub_4a4620(app, cpu);
    if (cpu.terminate) return;
    // 004876b0  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004876b3  884708                 -mov byte ptr [edi + 8], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 004876b6  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004876ba  884709                 -mov byte ptr [edi + 9], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 004876bd  e9d8feffff             -jmp 0x48759a
    goto L_0x0048759a;
L_0x004876c2:
    // 004876c2  837c242c10             +cmp dword ptr [esp + 0x2c], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004876c7  7511                   -jne 0x4876da
    if (!cpu.flags.zf)
    {
        goto L_0x004876da;
    }
    // 004876c9  837c240c02             +cmp dword ptr [esp + 0xc], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004876ce  750a                   -jne 0x4876da
    if (!cpu.flags.zf)
    {
        goto L_0x004876da;
    }
    // 004876d0  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 004876d5  e9dbfeffff             -jmp 0x4875b5
    goto L_0x004875b5;
L_0x004876da:
    // 004876da  837c242c08             +cmp dword ptr [esp + 0x2c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004876df  7510                   -jne 0x4876f1
    if (!cpu.flags.zf)
    {
        goto L_0x004876f1;
    }
    // 004876e1  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004876e5  83ff01                 +cmp edi, 1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004876e8  7507                   -jne 0x4876f1
    if (!cpu.flags.zf)
    {
        goto L_0x004876f1;
    }
    // 004876ea  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004876ec  e9c4feffff             -jmp 0x4875b5
    goto L_0x004875b5;
L_0x004876f1:
    // 004876f1  837c242c08             +cmp dword ptr [esp + 0x2c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004876f6  0f8569fdffff           -jne 0x487465
    if (!cpu.flags.zf)
    {
        goto L_0x00487465;
    }
    // 004876fc  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487700  83fa02                 +cmp edx, 2
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487703  0f855cfdffff           -jne 0x487465
    if (!cpu.flags.zf)
    {
        goto L_0x00487465;
    }
    // 00487709  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048770b  e9a5feffff             -jmp 0x4875b5
    goto L_0x004875b5;
L_0x00487710:
    // 00487710  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00487712  0f8dc4feffff           -jge 0x4875dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004875dc;
    }
    // 00487718  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0048771a  e9bdfeffff             -jmp 0x4875dc
    goto L_0x004875dc;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x90 */
void Application::sub_487720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487720);
    // 00487720  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487721  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487722  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487723  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487724  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00487727  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487729  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048772d  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00487732  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 00487734  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00487736  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00487738  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048773b  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048773e  7418                   -je 0x487758
    if (cpu.flags.zf)
    {
        goto L_0x00487758;
    }
L_0x00487740:
    // 00487740  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 00487742  80fefe                 +cmp dh, 0xfe
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487745  7411                   -je 0x487758
    if (cpu.flags.zf)
    {
        goto L_0x00487758;
    }
    // 00487747  0fb6f6                 -movzx esi, dh
    cpu.esi = x86::reg32(cpu.dh);
    // 0048774a  41                     -inc ecx
    (cpu.ecx)++;
    // 0048774b  81fefc000000           +cmp esi, 0xfc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487751  751a                   -jne 0x48776d
    if (!cpu.flags.zf)
    {
        goto L_0x0048776d;
    }
L_0x00487753:
    // 00487753  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487756  75e8                   -jne 0x487740
    if (!cpu.flags.zf)
    {
        goto L_0x00487740;
    }
L_0x00487758:
    // 00487758  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048775c  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048775e  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00487761  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487764  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00487767  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487768  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487769  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048776a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048776b  90                     -nop 
    ;
    // 0048776c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048776d:
    // 0048776d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048776f  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00487771  81fbff000000           +cmp ebx, 0xff
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487777  7512                   -jne 0x48778b
    if (!cpu.flags.zf)
    {
        goto L_0x0048778b;
    }
    // 00487779  41                     -inc ecx
    (cpu.ecx)++;
    // 0048777a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0048777f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487781  e8cac20100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 00487786  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00487788  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0048778b:
    // 0048778b  41                     -inc ecx
    (cpu.ecx)++;
    // 0048778c  81fe80000000           +cmp esi, 0x80
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487792  7c13                   -jl 0x4877a7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004877a7;
    }
    // 00487794  81fe88000000           +cmp esi, 0x88
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(136 /*0x88*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048779a  750f                   -jne 0x4877ab
    if (!cpu.flags.zf)
    {
        goto L_0x004877ab;
    }
    // 0048779c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048779e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004877a0  e8abc20100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004877a5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004877a7:
    // 004877a7  01d9                   +add ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004877a9  eba8                   -jmp 0x487753
    goto L_0x00487753;
L_0x004877ab:
    // 004877ab  81fe8a000000           +cmp esi, 0x8a
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(138 /*0x8a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004877b1  75f4                   -jne 0x4877a7
    if (!cpu.flags.zf)
    {
        goto L_0x004877a7;
    }
    // 004877b3  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004877b5  01d9                   +add ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004877b7  eb9a                   -jmp 0x487753
    goto L_0x00487753;
}

/* align: skip  */
void Application::sub_48776c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048776c);
    goto L_entry_0x0048776c;
    // 00487720  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487721  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487722  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487723  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487724  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00487727  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487729  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048772d  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00487732  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 00487734  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00487736  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00487738  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048773b  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048773e  7418                   -je 0x487758
    if (cpu.flags.zf)
    {
        goto L_0x00487758;
    }
L_0x00487740:
    // 00487740  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 00487742  80fefe                 +cmp dh, 0xfe
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487745  7411                   -je 0x487758
    if (cpu.flags.zf)
    {
        goto L_0x00487758;
    }
    // 00487747  0fb6f6                 -movzx esi, dh
    cpu.esi = x86::reg32(cpu.dh);
    // 0048774a  41                     -inc ecx
    (cpu.ecx)++;
    // 0048774b  81fefc000000           +cmp esi, 0xfc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487751  751a                   -jne 0x48776d
    if (!cpu.flags.zf)
    {
        goto L_0x0048776d;
    }
L_0x00487753:
    // 00487753  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487756  75e8                   -jne 0x487740
    if (!cpu.flags.zf)
    {
        goto L_0x00487740;
    }
L_0x00487758:
    // 00487758  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048775c  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048775e  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00487761  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487764  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00487767  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487768  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487769  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048776a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048776b  90                     -nop 
    ;
L_entry_0x0048776c:
    // 0048776c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048776d:
    // 0048776d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048776f  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00487771  81fbff000000           +cmp ebx, 0xff
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487777  7512                   -jne 0x48778b
    if (!cpu.flags.zf)
    {
        goto L_0x0048778b;
    }
    // 00487779  41                     -inc ecx
    (cpu.ecx)++;
    // 0048777a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0048777f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487781  e8cac20100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 00487786  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00487788  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0048778b:
    // 0048778b  41                     -inc ecx
    (cpu.ecx)++;
    // 0048778c  81fe80000000           +cmp esi, 0x80
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487792  7c13                   -jl 0x4877a7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004877a7;
    }
    // 00487794  81fe88000000           +cmp esi, 0x88
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(136 /*0x88*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048779a  750f                   -jne 0x4877ab
    if (!cpu.flags.zf)
    {
        goto L_0x004877ab;
    }
    // 0048779c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048779e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004877a0  e8abc20100             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004877a5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004877a7:
    // 004877a7  01d9                   +add ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004877a9  eba8                   -jmp 0x487753
    goto L_0x00487753;
L_0x004877ab:
    // 004877ab  81fe8a000000           +cmp esi, 0x8a
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(138 /*0x8a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004877b1  75f4                   -jne 0x4877a7
    if (!cpu.flags.zf)
    {
        goto L_0x004877a7;
    }
    // 004877b3  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004877b5  01d9                   +add ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004877b7  eb9a                   -jmp 0x487753
    goto L_0x00487753;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4877bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004877bc);
    // 004877bc  e9afbc0100             -jmp 0x4a3470
    return sub_4a3470(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4877c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004877c4);
    // 004877c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004877c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004877c6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004877c7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004877c8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004877cb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004877cd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004877cf  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004877d1  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 004877d3  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004877d6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004877d8  8896261f5600           -mov byte ptr [esi + 0x561f26], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5644070) /* 0x561f26 */) = cpu.dl;
    // 004877de  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 004877e5  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004877e7  8a9e251f5600           -mov bl, byte ptr [esi + 0x561f25]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5644069) /* 0x561f25 */);
    // 004877ed  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004877f0  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004877f2  745c                   -je 0x487850
    if (cpu.flags.zf)
    {
        goto L_0x00487850;
    }
    // 004877f4  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004877f7  756d                   -jne 0x487866
    if (!cpu.flags.zf)
    {
        goto L_0x00487866;
    }
    // 004877f9  8b8e261f5600           -mov ecx, dword ptr [esi + 0x561f26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5644070) /* 0x561f26 */);
    // 004877ff  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00487801  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00487804  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00487807  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487808  8b8e251f5600           -mov ecx, dword ptr [esi + 0x561f25]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5644069) /* 0x561f25 */);
    // 0048780e  8b921e9c5900           -mov edx, dword ptr [edx + 0x599c1e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5872670) /* 0x599c1e */);
    // 00487814  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00487817  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0048781a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048781b  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0048781e  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487822  e8f9cd0100             -call 0x4a4620
    cpu.esp -= 4;
    sub_4a4620(app, cpu);
    if (cpu.terminate) return;
    // 00487827  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0048782a  8886281f5600           -mov byte ptr [esi + 0x561f28], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5644072) /* 0x561f28 */) = cpu.al;
    // 00487830  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487834  8886291f5600           -mov byte ptr [esi + 0x561f29], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5644073) /* 0x561f29 */) = cpu.al;
L_0x0048783a:
    // 0048783a  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048783e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00487841  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00487843  e8c8bb0100             -call 0x4a3410
    cpu.esp -= 4;
    sub_4a3410(app, cpu);
    if (cpu.terminate) return;
    // 00487848  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048784b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048784c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048784d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048784e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048784f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487850:
    // 00487850  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487854  8b921e9c5900           -mov edx, dword ptr [edx + 0x599c1e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5872670) /* 0x599c1e */);
    // 0048785a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048785c  c1fa18                 +sar edx, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0048785f  e8bcc10100             -call 0x4a3a20
    cpu.esp -= 4;
    sub_4a3a20(app, cpu);
    if (cpu.terminate) return;
    // 00487864  ebd4                   -jmp 0x48783a
    goto L_0x0048783a;
L_0x00487866:
    // 00487866  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0048786b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048786e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048786f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487870  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487871  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487872  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
