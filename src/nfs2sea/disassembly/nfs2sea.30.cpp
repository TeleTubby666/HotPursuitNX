#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b0468(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b0468);
    // 004b0468  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0469  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b046a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b046c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b046e  8b1570df4d00           -mov edx, dword ptr [0x4ddf70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5103472) /* 0x4ddf70 */);
    // 004b0474  42                     -inc edx
    (cpu.edx)++;
    // 004b0475  891570df4d00           -mov dword ptr [0x4ddf70], edx
    app->getMemory<x86::reg32>(x86::reg32(5103472) /* 0x4ddf70 */) = cpu.edx;
    // 004b047b  83fa01                 +cmp edx, 1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b047e  7514                   -jne 0x4b0494
    if (!cpu.flags.zf)
    {
        goto L_0x004b0494;
    }
    // 004b0480  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b0483  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0486  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0488  741b                   -je 0x4b04a5
    if (cpu.flags.zf)
    {
        goto L_0x004b04a5;
    }
    // 004b048a  b84c044b00             -mov eax, 0x4b044c
    cpu.eax = 4916300 /*0x4b044c*/;
    // 004b048f  e8e0f5feff             -call 0x49fa74
    cpu.esp -= 4;
    sub_49fa74(app, cpu);
    if (cpu.terminate) return;
L_0x004b0494:
    // 004b0494  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b0497  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0499  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b049b  ff531c                 -call dword ptr [ebx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b049e  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b04a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b04a3  7505                   -jne 0x4b04aa
    if (!cpu.flags.zf)
    {
        goto L_0x004b04aa;
    }
L_0x004b04a5:
    // 004b04a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b04a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b04a7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004b04aa:
    // 004b04aa  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b04ad  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004b04b0  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004b04b5  ff5140                 -call dword ptr [ecx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b04b8  8d968c000000           -lea edx, [esi + 0x8c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 004b04be  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b04c0  c7869c00000001000000   -mov dword ptr [esi + 0x9c], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */) = 1 /*0x1*/;
    // 004b04ca  e83196fdff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004b04cf  bb33000000             -mov ebx, 0x33
    cpu.ebx = 51 /*0x33*/;
    // 004b04d4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b04d8  8d4644                 -lea eax, [esi + 0x44]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 004b04db  e86c44fdff             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 004b04e0  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 004b04e5  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b04e9  8d4678                 -lea eax, [esi + 0x78]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 004b04ec  e85b44fdff             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 004b04f1  b8fa000000             -mov eax, 0xfa
    cpu.eax = 250 /*0xfa*/;
    // 004b04f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b04f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b04f8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b04fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b04fc);
    // 004b04fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b04fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b04fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b04ff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0500  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0501  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0503  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b0506  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b050b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b050d  745b                   -je 0x4b056a
    if (cpu.flags.zf)
    {
        goto L_0x004b056a;
    }
    // 004b050f  83781400               +cmp dword ptr [eax + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0513  7509                   -jne 0x4b051e
    if (!cpu.flags.zf)
    {
        goto L_0x004b051e;
    }
    // 004b0515  83b8a000000000         +cmp dword ptr [eax + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b051c  7409                   -je 0x4b0527
    if (cpu.flags.zf)
    {
        goto L_0x004b0527;
    }
L_0x004b051e:
    // 004b051e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0520  e8b7aefeff             -call 0x49b3dc
    cpu.esp -= 4;
    sub_49b3dc(app, cpu);
    if (cpu.terminate) return;
    // 004b0525  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004b0527:
    // 004b0527  8baaa8000000           -mov ebp, dword ptr [edx + 0xa8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 004b052d  c7829c00000000000000   -mov dword ptr [edx + 0x9c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */) = 0 /*0x0*/;
    // 004b0537  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b0539  7411                   -je 0x4b054c
    if (cpu.flags.zf)
    {
        goto L_0x004b054c;
    }
    // 004b053b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004b053d:
    // 004b053d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b053f  e8dc1dfdff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 004b0544  3bb2a8000000           +cmp esi, dword ptr [edx + 0xa8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b054a  75f1                   -jne 0x4b053d
    if (!cpu.flags.zf)
    {
        goto L_0x004b053d;
    }
L_0x004b054c:
    // 004b054c  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b054f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b0551  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004b0558  ff5620                 -call dword ptr [esi + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b055b  8b1d70df4d00           -mov ebx, dword ptr [0x4ddf70]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5103472) /* 0x4ddf70 */);
    // 004b0561  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b0562  891d70df4d00           -mov dword ptr [0x4ddf70], ebx
    app->getMemory<x86::reg32>(x86::reg32(5103472) /* 0x4ddf70 */) = cpu.ebx;
    // 004b0568  7408                   -je 0x4b0572
    if (cpu.flags.zf)
    {
        goto L_0x004b0572;
    }
L_0x004b056a:
    // 004b056a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b056c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b056d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b056e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b056f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0570  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0571  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0572:
    // 004b0572  b84c044b00             -mov eax, 0x4b044c
    cpu.eax = 4916300 /*0x4b044c*/;
    // 004b0577  e860f5feff             -call 0x49fadc
    cpu.esp -= 4;
    sub_49fadc(app, cpu);
    if (cpu.terminate) return;
    // 004b057c  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b057f  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0582  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b0584  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0586  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0587  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0588  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0589  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b058a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b058b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b058c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b058c);
    // 004b058c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b058d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b058e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b058f  81ec88000000           -sub esp, 0x88
    (cpu.esp) -= x86::reg32(x86::sreg32(136 /*0x88*/));
    // 004b0595  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b0597  89942480000000         -mov dword ptr [esp + 0x80], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 004b059e  899c2484000000         -mov dword ptr [esp + 0x84], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 004b05a5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b05a7  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004b05ac  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004b05ae  bec0f34a00             -mov esi, 0x4af3c0
    cpu.esi = 4912064 /*0x4af3c0*/;
    // 004b05b3  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004b05b7  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004b05bc  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b05be  e88defffff             -call 0x4af550
    cpu.esp -= 4;
    sub_4af550(app, cpu);
    if (cpu.terminate) return;
    // 004b05c3  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004b05ca  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004b05ce  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b05d2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b05d4  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b05d8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b05db  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b05dd  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b05e0  a1c0155600             -mov eax, dword ptr [0x5615c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */);
    // 004b05e5  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 004b05ec  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004b05f1  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b05f3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b05f5  a36cdf4d00             -mov dword ptr [0x4ddf6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5103468) /* 0x4ddf6c */) = cpu.eax;
L_0x004b05fa:
    // 004b05fa  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b05fd  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004b0601  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b0604  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0607  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004b0609:
    // 004b0609  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b060b  e8a41dfdff             -call 0x4823b4
    cpu.esp -= 4;
    sub_4823b4(app, cpu);
    if (cpu.terminate) return;
    // 004b0610  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0612  7d1d                   -jge 0x4b0631
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0631;
    }
L_0x004b0614:
    // 004b0614  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b0616  752a                   -jne 0x4b0642
    if (!cpu.flags.zf)
    {
        goto L_0x004b0642;
    }
    // 004b0618  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b061a  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004b0621  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 004b0627  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0628  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0629  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b062a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b062b:
    // 004b062b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b062d  74cb                   -je 0x4b05fa
    if (cpu.flags.zf)
    {
        goto L_0x004b05fa;
    }
    // 004b062f  ebd8                   -jmp 0x4b0609
    goto L_0x004b0609;
L_0x004b0631:
    // 004b0631  e87eefffff             -call 0x4af5b4
    cpu.esp -= 4;
    sub_4af5b4(app, cpu);
    if (cpu.terminate) return;
    // 004b0636  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0638  75da                   -jne 0x4b0614
    if (!cpu.flags.zf)
    {
        goto L_0x004b0614;
    }
    // 004b063a  3b5c2414               +cmp ebx, dword ptr [esp + 0x14]
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
    // 004b063e  75eb                   -jne 0x4b062b
    if (!cpu.flags.zf)
    {
        goto L_0x004b062b;
    }
    // 004b0640  ebd2                   -jmp 0x4b0614
    goto L_0x004b0614;
L_0x004b0642:
    // 004b0642  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0645  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b0648  ff5134                 -call dword ptr [ecx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b064b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b064d  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004b0654  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 004b065a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b065b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b065c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b065d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b0660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b0660);
    // 004b0660  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0661  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0662  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0663  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0664  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004b066a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b066c  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 004b0673  899c24fc000000         -mov dword ptr [esp + 0xfc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */) = cpu.ebx;
    // 004b067a  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004b067f  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 004b0686  be10f44a00             -mov esi, 0x4af410
    cpu.esi = 4912144 /*0x4af410*/;
    // 004b068b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b068d  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0694  0f857e000000           -jne 0x4b0718
    if (!cpu.flags.zf)
    {
        goto L_0x004b0718;
    }
L_0x004b069a:
    // 004b069a  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 004b069f  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b06a3  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 004b06a6  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b06a8  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b06ac  8bb42400010000         -mov esi, dword ptr [esp + 0x100]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004b06b3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b06b4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b06b5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b06b6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b06b7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b06b8  8bb42400010000         -mov esi, dword ptr [esp + 0x100]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004b06bf  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004b06c2  8b8c24fc000000         -mov ecx, dword ptr [esp + 0xfc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 004b06c9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b06ca  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b06cb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b06cc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b06cd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b06ce  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b06d0  7476                   -je 0x4b0748
    if (cpu.flags.zf)
    {
        goto L_0x004b0748;
    }
    // 004b06d2  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004b06d7  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b06db  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b06dd  e86a42fdff             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
L_0x004b06e2:
    // 004b06e2  a1e8894d00             -mov eax, dword ptr [0x4d89e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 004b06e7  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b06e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b06ea  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b06ee  bb646461ea             -mov ebx, 0xea616464
    cpu.ebx = 3932251236 /*0xea616464*/;
    // 004b06f3  6888000000             -push 0x88
    app->getMemory<x86::reg32>(cpu.esp-4) = 136 /*0x88*/;
    cpu.esp -= 4;
    // 004b06f8  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004b06ff  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b0701  e832f0ffff             -call 0x4af738
    cpu.esp -= 4;
    sub_4af738(app, cpu);
    if (cpu.terminate) return;
    // 004b0706  8b8424b0000000         -mov eax, dword ptr [esp + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
L_0x004b070d:
    // 004b070d  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004b0713  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0714  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0715  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0716  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0717  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0718:
    // 004b0718  8b9c2400010000         -mov ebx, dword ptr [esp + 0x100]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004b071f  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b0722  e819adfeff             -call 0x49b440
    cpu.esp -= 4;
    sub_49b440(app, cpu);
    if (cpu.terminate) return;
    // 004b0727  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0729  7407                   -je 0x4b0732
    if (cpu.flags.zf)
    {
        goto L_0x004b0732;
    }
    // 004b072b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b0730  ebdb                   -jmp 0x4b070d
    goto L_0x004b070d;
L_0x004b0732:
    // 004b0732  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b0734  e8a3acfeff             -call 0x49b3dc
    cpu.esp -= 4;
    sub_49b3dc(app, cpu);
    if (cpu.terminate) return;
    // 004b0739  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 004b0743  e952ffffff             -jmp 0x4b069a
    goto L_0x004b069a;
L_0x004b0748:
    // 004b0748  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b074b  c6403c00               -mov byte ptr [eax + 0x3c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 004b074f  eb91                   -jmp 0x4b06e2
    goto L_0x004b06e2;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b0754(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b0754);
    // 004b0754  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0755  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0756  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0757  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0758  81ecfc000000           -sub esp, 0xfc
    (cpu.esp) -= x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 004b075e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004b0760  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004b0765  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 004b076c  be60f44a00             -mov esi, 0x4af460
    cpu.esi = 4912224 /*0x4af460*/;
    // 004b0771  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0773  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b0775  7554                   -jne 0x4b07cb
    if (!cpu.flags.zf)
    {
        goto L_0x004b07cb;
    }
    // 004b0777  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b077e  744b                   -je 0x4b07cb
    if (cpu.flags.zf)
    {
        goto L_0x004b07cb;
    }
L_0x004b0780:
    // 004b0780  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 004b0786  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b0788  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004b078a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b078b  bb716572ea             -mov ebx, 0xea726571
    cpu.ebx = 3933365617 /*0xea726571*/;
    // 004b0790  8db424cc000000         -lea esi, [esp + 0xcc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(204) /* 0xcc */);
    // 004b0797  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 004b079c  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004b07a3  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004b07a5  e88eefffff             -call 0x4af738
    cpu.esp -= 4;
    sub_4af738(app, cpu);
    if (cpu.terminate) return;
    // 004b07aa  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 004b07af  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b07b1  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b07b9  7429                   -je 0x4b07e4
    if (cpu.flags.zf)
    {
        goto L_0x004b07e4;
    }
    // 004b07bb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b07c0  81c4fc000000           -add esp, 0xfc
    (cpu.esp) += x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 004b07c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b07c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b07c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b07c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b07ca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b07cb:
    // 004b07cb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b07cd  7415                   -je 0x4b07e4
    if (cpu.flags.zf)
    {
        goto L_0x004b07e4;
    }
    // 004b07cf  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b07d6  750c                   -jne 0x4b07e4
    if (!cpu.flags.zf)
    {
        goto L_0x004b07e4;
    }
    // 004b07d8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b07da  8d781c                 -lea edi, [eax + 0x1c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b07dd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b07de  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b07df  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b07e0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b07e1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b07e2  eb9c                   -jmp 0x4b0780
    goto L_0x004b0780;
L_0x004b07e4:
    // 004b07e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b07e6  81c4fc000000           -add esp, 0xfc
    (cpu.esp) += x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 004b07ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b07ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b07ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b07ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b07f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b07f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b07f4);
    // 004b07f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b07f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b07f6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b07f7  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b07fa  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b07fc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b07fe  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b0802  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004b0805  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0807  8b4e30                 -mov ecx, dword ptr [esi + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004b080a  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b080e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b0810  0f84e6000000           -je 0x4b08fc
    if (cpu.flags.zf)
    {
        goto L_0x004b08fc;
    }
L_0x004b0816:
    // 004b0816  83bda400000000         +cmp dword ptr [ebp + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b081d  7411                   -je 0x4b0830
    if (cpu.flags.zf)
    {
        goto L_0x004b0830;
    }
    // 004b081f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b0821  e8b6abfeff             -call 0x49b3dc
    cpu.esp -= 4;
    sub_49b3dc(app, cpu);
    if (cpu.terminate) return;
    // 004b0826  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
L_0x004b0830:
    // 004b0830  8b5630                 -mov edx, dword ptr [esi + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004b0833  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b0836  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004b083d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b083f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b0842  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b0844  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b0847  8d90ec000000           -lea edx, [eax + 0xec]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(236) /* 0xec */);
    // 004b084d  8b1d048a4d00           -mov ebx, dword ptr [0x4d8a04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */);
    // 004b0853  b8d8f64c00             -mov eax, 0x4cf6d8
    cpu.eax = 5043928 /*0x4cf6d8*/;
    // 004b0858  e8ab20fdff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 004b085d  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b0860  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0862  0f8489000000           -je 0x4b08f1
    if (cpu.flags.zf)
    {
        goto L_0x004b08f1;
    }
    // 004b0868  896804                 -mov dword ptr [eax + 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b086b  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b086e  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 004b0873  8d7f54                 -lea edi, [edi + 0x54]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(84) /* 0x54 */);
    // 004b0876  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0878  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b087b  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b0882  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b0885  c7405000000000         -mov dword ptr [eax + 0x50], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = 0 /*0x0*/;
    // 004b088c  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b088f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b0892  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 004b0895  a134b34d00             -mov eax, dword ptr [0x4db334]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092148) /* 0x4db334 */);
    // 004b089a  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004b089d  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 004b08a3  a138b34d00             -mov eax, dword ptr [0x4db338]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092152) /* 0x4db338 */);
    // 004b08a8  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 004b08ab  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 004b08b1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b08b5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b08b6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b08b7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b08b8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b08b9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b08ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b08bc  754a                   -jne 0x4b0908
    if (!cpu.flags.zf)
    {
        goto L_0x004b0908;
    }
    // 004b08be  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b08c1  c6403c00               -mov byte ptr [eax + 0x3c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
L_0x004b08c5:
    // 004b08c5  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b08c8  8d858c000000           -lea eax, [ebp + 0x8c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 004b08ce  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b08d1  e87aecffff             -call 0x4af550
    cpu.esp -= 4;
    sub_4af550(app, cpu);
    if (cpu.terminate) return;
    // 004b08d6  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b08d9  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b08dc  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b08df  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b08e2  ff5328                 -call dword ptr [ebx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b08e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b08e7  7435                   -je 0x4b091e
    if (cpu.flags.zf)
    {
        goto L_0x004b091e;
    }
    // 004b08e9  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x004b08f1:
    // 004b08f1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b08f5  83c40c                 +add esp, 0xc
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
    // 004b08f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b08f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b08fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b08fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b08fc:
    // 004b08fc  c7463020000000         -mov dword ptr [esi + 0x30], 0x20
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 32 /*0x20*/;
    // 004b0903  e90effffff             -jmp 0x4b0816
    goto L_0x004b0816;
L_0x004b0908:
    // 004b0908  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004b090d  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b0910  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0914  83c03c                 +add eax, 0x3c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0917  e83040fdff             -call 0x48494c
    cpu.esp -= 4;
    sub_48494c(app, cpu);
    if (cpu.terminate) return;
    // 004b091c  eba7                   -jmp 0x4b08c5
    goto L_0x004b08c5;
L_0x004b091e:
    // 004b091e  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b0921  e84624fdff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 004b0926  c7451400000000         -mov dword ptr [ebp + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b092d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0931  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b0934  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0935  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0936  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0937  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b0938(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b0938);
    // 004b0938  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0939  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b093c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b093e  7504                   -jne 0x4b0944
    if (!cpu.flags.zf)
    {
        goto L_0x004b0944;
    }
    // 004b0940  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0942  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0943  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0944:
    // 004b0944  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0945  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0946  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004b0948  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 004b094d  8d7e54                 -lea edi, [esi + 0x54]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 004b0950  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b0952  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b0957  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0959  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b095a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b095b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b095c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b0960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b0960);
    // 004b0960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0961  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0962  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b0964  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b0966  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b0969  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b096b  7442                   -je 0x4b09af
    if (cpu.flags.zf)
    {
        goto L_0x004b09af;
    }
    // 004b096d  837a0800               +cmp dword ptr [edx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0971  741b                   -je 0x4b098e
    if (cpu.flags.zf)
    {
        goto L_0x004b098e;
    }
L_0x004b0973:
    // 004b0973  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0975  740f                   -je 0x4b0986
    if (cpu.flags.zf)
    {
        goto L_0x004b0986;
    }
    // 004b0977  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004b097a  e8ed23fdff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 004b097f  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x004b0986:
    // 004b0986  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b098b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b098c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b098d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b098e:
    // 004b098e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b098f  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b0992  83c20c                 +add edx, 0xc
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0995  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b0998  ff562c                 -call dword ptr [esi + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b099b  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004b099e  c6400c00               -mov byte ptr [eax + 0xc], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004b09a2  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004b09a5  c7400801000000         -mov dword ptr [eax + 8], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 004b09ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b09ad  ebc4                   -jmp 0x4b0973
    goto L_0x004b0973;
L_0x004b09af:
    // 004b09af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b09b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b09b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b09b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b09b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b09b4);
    // 004b09b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b09b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b09b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b09b7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b09b8  8b3d34b34d00           -mov edi, dword ptr [0x4db334]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5092148) /* 0x4db334 */);
    // 004b09be  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b09c0  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b09c3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b09c5  7409                   -je 0x4b09d0
    if (cpu.flags.zf)
    {
        goto L_0x004b09d0;
    }
    // 004b09c7  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b09ca  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b09cc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b09ce  7513                   -jne 0x4b09e3
    if (!cpu.flags.zf)
    {
        goto L_0x004b09e3;
    }
L_0x004b09d0:
    // 004b09d0  8b3d34b34d00           -mov edi, dword ptr [0x4db334]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5092148) /* 0x4db334 */);
    // 004b09d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b09d8  893d34b34d00           -mov dword ptr [0x4db334], edi
    app->getMemory<x86::reg32>(x86::reg32(5092148) /* 0x4db334 */) = cpu.edi;
    // 004b09de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b09df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b09e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b09e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b09e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b09e3:
    // 004b09e3  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b09ea  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004b09ed  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 004b09f3  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b09f6  e855ebffff             -call 0x4af550
    cpu.esp -= 4;
    sub_4af550(app, cpu);
    if (cpu.terminate) return;
    // 004b09fb  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b09fe  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004b0a01  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b0a04  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b0a07  ff5128                 -call dword ptr [ecx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0a0a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0a0c  7441                   -je 0x4b0a4f
    if (cpu.flags.zf)
    {
        goto L_0x004b0a4f;
    }
    // 004b0a0e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0a0f  8b3d34b34d00           -mov edi, dword ptr [0x4db334]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5092148) /* 0x4db334 */);
    // 004b0a15  c786a000000001000000   -mov dword ptr [esi + 0xa0], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */) = 1 /*0x1*/;
    // 004b0a1f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b0a21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b0a23:
    // 004b0a23  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004b0a26  8b9984000000           -mov ebx, dword ptr [ecx + 0x84]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 004b0a2c  4b                     -dec ebx
    (cpu.ebx)--;
    // 004b0a2d  39da                   +cmp edx, ebx
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
    // 004b0a2f  730d                   -jae 0x4b0a3e
    if (!cpu.flags.cf)
    {
        goto L_0x004b0a3e;
    }
    // 004b0a31  83c064                 +add eax, 0x64
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0a34  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b0a35  89bc0180000000         -mov dword ptr [ecx + eax + 0x80], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */ + cpu.eax * 1) = cpu.edi;
    // 004b0a3c  ebe5                   -jmp 0x4b0a23
    goto L_0x004b0a23;
L_0x004b0a3e:
    // 004b0a3e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b0a43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a44  893d34b34d00           -mov dword ptr [0x4db334], edi
    app->getMemory<x86::reg32>(x86::reg32(5092148) /* 0x4db334 */) = cpu.edi;
    // 004b0a4a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a4c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a4e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0a4f:
    // 004b0a4f  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004b0a52  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b0a59  8b3d34b34d00           -mov edi, dword ptr [0x4db334]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5092148) /* 0x4db334 */);
    // 004b0a5f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0a61  893d34b34d00           -mov dword ptr [0x4db334], edi
    app->getMemory<x86::reg32>(x86::reg32(5092148) /* 0x4db334 */) = cpu.edi;
    // 004b0a67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0a6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b0a6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b0a6c);
    // 004b0a6c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0a6d  81ecb0000000           -sub esp, 0xb0
    (cpu.esp) -= x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 004b0a73  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b0a75  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0a7c  0f84e8000000           -je 0x4b0b6a
    if (cpu.flags.zf)
    {
        goto L_0x004b0b6a;
    }
    // 004b0a82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0a83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0a84  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0a85  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0a86  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0a87  a168df4d00             -mov eax, dword ptr [0x4ddf68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5103464) /* 0x4ddf68 */);
    // 004b0a8c  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b0a90  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0a94  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004b0a97  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0a98  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0a99  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0a9a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0a9b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0a9c  40                     -inc eax
    (cpu.eax)++;
    // 004b0a9d  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b0aa0  a368df4d00             -mov dword ptr [0x4ddf68], eax
    app->getMemory<x86::reg32>(x86::reg32(5103464) /* 0x4ddf68 */) = cpu.eax;
    // 004b0aa5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b0aa7  0f84ca000000           -je 0x4b0b77
    if (cpu.flags.zf)
    {
        goto L_0x004b0b77;
    }
    // 004b0aad  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b0ab0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b0ab2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0ab4  0f8588000000           -jne 0x4b0b42
    if (!cpu.flags.zf)
    {
        goto L_0x004b0b42;
    }
    // 004b0aba  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0abd  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b0ac0  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b0ac3  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0ac6  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b0ac9  899c24c0000000         -mov dword ptr [esp + 0xc0], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.ebx;
    // 004b0ad0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b0ad2  c6400c00               -mov byte ptr [eax + 0xc], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
L_0x004b0ad6:
    // 004b0ad6  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b0ad9  8b7850                 -mov edi, dword ptr [eax + 0x50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004b0adc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b0ade  7462                   -je 0x4b0b42
    if (cpu.flags.zf)
    {
        goto L_0x004b0b42;
    }
    // 004b0ae0  8b9084000000           -mov edx, dword ptr [eax + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 004b0ae6  8b8c24c0000000         -mov ecx, dword ptr [esp + 0xc0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 004b0aed  4a                     -dec edx
    (cpu.edx)--;
    // 004b0aee  39ca                   +cmp edx, ecx
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
    // 004b0af0  7650                   -jbe 0x4b0b42
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b0b42;
    }
    // 004b0af2  8a8c24c0000000         -mov cl, byte ptr [esp + 0xc0]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 004b0af9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b0afe  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004b0b00  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b0b02  85fa                   +test edx, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edi));
    // 004b0b04  7514                   -jne 0x4b0b1a
    if (!cpu.flags.zf)
    {
        goto L_0x004b0b1a;
    }
L_0x004b0b06:
    // 004b0b06  8b8424c0000000         -mov eax, dword ptr [esp + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
    // 004b0b0d  40                     -inc eax
    (cpu.eax)++;
    // 004b0b0e  83c664                 +add esi, 0x64
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0b11  898424c0000000         -mov dword ptr [esp + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 004b0b18  ebbc                   -jmp 0x4b0ad6
    goto L_0x004b0ad6;
L_0x004b0b1a:
    // 004b0b1a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004b0b1c  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 004b0b1e  21cf                   -and edi, ecx
    cpu.edi &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0b20  bb657962ea             -mov ebx, 0xea627965
    cpu.ebx = 3932322149 /*0xea627965*/;
    // 004b0b25  897850                 -mov dword ptr [eax + 0x50], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 004b0b28  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0b2c  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b0b2f  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0b32  81c288000000           -add edx, 0x88
    (cpu.edx) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 004b0b38  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b0b3b  01f2                   +add edx, esi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0b3d  ff5750                 -call dword ptr [edi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0b40  ebc4                   -jmp 0x4b0b06
    goto L_0x004b0b06;
L_0x004b0b42:
    // 004b0b42  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b0b45  e82222fdff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 004b0b4a  c7451400000000         -mov dword ptr [ebp + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x004b0b51:
    // 004b0b51  c785a000000000000000   -mov dword ptr [ebp + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 004b0b5b  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 004b0b65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004b0b6a:
    // 004b0b6a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b0b6f  81c4b0000000           +add esp, 0xb0
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(176 /*0xb0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0b75  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0b76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0b77:
    // 004b0b77  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 004b0b79  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0b7d  bb657962ea             -mov ebx, 0xea627965
    cpu.ebx = 3932322149 /*0xea627965*/;
    // 004b0b82  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b0b85  8d551c                 -lea edx, [ebp + 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004b0b88  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b0b8b  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0b8e  ebc1                   -jmp 0x4b0b51
    goto L_0x004b0b51;
}

/* align: skip  */
void Application::sub_4b0b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b0b90);
    // 004b0b90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0b91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0b92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0b93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0b94  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 004b0b9a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b0b9c  899c24fc000000         -mov dword ptr [esp + 0xfc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */) = cpu.ebx;
    // 004b0ba3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0ba5  898c2404010000         -mov dword ptr [esp + 0x104], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.ecx;
    // 004b0bac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b0bae  0f85a2000000           -jne 0x4b0c56
    if (!cpu.flags.zf)
    {
        goto L_0x004b0c56;
    }
    // 004b0bb4  83b8a400000000         +cmp dword ptr [eax + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0bbb  0f8495000000           -je 0x4b0c56
    if (cpu.flags.zf)
    {
        goto L_0x004b0c56;
    }
    // 004b0bc1  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
L_0x004b0bc4:
    // 004b0bc4  837d1400               +cmp dword ptr [ebp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0bc8  0f84d8000000           -je 0x4b0ca6
    if (cpu.flags.zf)
    {
        goto L_0x004b0ca6;
    }
    // 004b0bce  8d451c                 -lea eax, [ebp + 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004b0bd1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b0bd3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0bd5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b0bd7  e864a8feff             -call 0x49b440
    cpu.esp -= 4;
    sub_49b440(app, cpu);
    if (cpu.terminate) return;
    // 004b0bdc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0bde  0f84c2000000           -je 0x4b0ca6
    if (cpu.flags.zf)
    {
        goto L_0x004b0ca6;
    }
    // 004b0be4  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b0be9  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 004b0bec  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0bee  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b0bf0  ff9424fc000000         -call dword ptr [esp + 0xfc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0bf7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0bf9  0f8451020000           -je 0x4b0e50
    if (cpu.flags.zf)
    {
        goto L_0x004b0e50;
    }
    // 004b0bff  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b0c04  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0c06  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b0c08  89bc2404010000         -mov dword ptr [esp + 0x104], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.edi;
    // 004b0c0f  89842408010000         -mov dword ptr [esp + 0x108], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.eax;
L_0x004b0c16:
    // 004b0c16  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b0c19  8b9084000000           -mov edx, dword ptr [eax + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 004b0c1f  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004b0c26  4a                     -dec edx
    (cpu.edx)--;
    // 004b0c27  39fa                   +cmp edx, edi
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
    // 004b0c29  0f8621020000           -jbe 0x4b0e50
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b0e50;
    }
    // 004b0c2f  8a8c2408010000         -mov cl, byte ptr [esp + 0x108]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004b0c36  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b0c3b  d3e2                   +shl edx, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b0c3d  855050                 -test dword ptr [eax + 0x50], edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) & cpu.edx));
    // 004b0c40  753d                   -jne 0x4b0c7f
    if (!cpu.flags.zf)
    {
        goto L_0x004b0c7f;
    }
L_0x004b0c42:
    // 004b0c42  8bbc2408010000         -mov edi, dword ptr [esp + 0x108]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004b0c49  47                     -inc edi
    (cpu.edi)++;
    // 004b0c4a  83c664                 +add esi, 0x64
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b0c4d  89bc2408010000         -mov dword ptr [esp + 0x108], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.edi;
    // 004b0c54  ebc0                   -jmp 0x4b0c16
    goto L_0x004b0c16;
L_0x004b0c56:
    // 004b0c56  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b0c58  7418                   -je 0x4b0c72
    if (cpu.flags.zf)
    {
        goto L_0x004b0c72;
    }
    // 004b0c5a  83bda400000000         +cmp dword ptr [ebp + 0xa4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0c61  750f                   -jne 0x4b0c72
    if (!cpu.flags.zf)
    {
        goto L_0x004b0c72;
    }
    // 004b0c63  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b0c65  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004b0c68  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0c69  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0c6a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0c6b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0c6c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0c6d  e952ffffff             -jmp 0x4b0bc4
    goto L_0x004b0bc4;
L_0x004b0c72:
    // 004b0c72  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0c74  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 004b0c7a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0c7b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0c7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0c7d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0c7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0c7f:
    // 004b0c7f  0588000000             -add eax, 0x88
    (cpu.eax) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 004b0c84  8d5f01                 -lea ebx, [edi + 1]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b0c87  8d1430                 -lea edx, [eax + esi]
    cpu.edx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 004b0c8a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0c8c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b0c8e  ff9424fc000000         -call dword ptr [esp + 0xfc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0c95  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0c97  0f84b3010000           -je 0x4b0e50
    if (cpu.flags.zf)
    {
        goto L_0x004b0e50;
    }
    // 004b0c9d  ff842404010000         +inc dword ptr [esp + 0x104]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b0ca4  eb9c                   -jmp 0x4b0c42
    goto L_0x004b0c42;
L_0x004b0ca6:
    // 004b0ca6  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004b0cab  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 004b0cb2  bb716572ea             -mov ebx, 0xea726571
    cpu.ebx = 3933365617 /*0xea726571*/;
    // 004b0cb7  a1e8894d00             -mov eax, dword ptr [0x4d89e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 004b0cbc  beb0f44a00             -mov esi, 0x4af4b0
    cpu.esi = 4912304 /*0x4af4b0*/;
    // 004b0cc1  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b0cc3  8d9424ac000000         -lea edx, [esp + 0xac]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 004b0cca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0ccb  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0ccd  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 004b0cd2  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b0cd6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b0cd8  e85beaffff             -call 0x4af738
    cpu.esp -= 4;
    sub_4af738(app, cpu);
    if (cpu.terminate) return;
    // 004b0cdd  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0ce5  0f8465010000           -je 0x4b0e50
    if (cpu.flags.zf)
    {
        goto L_0x004b0e50;
    }
    // 004b0ceb  8b8424b4000000         -mov eax, dword ptr [esp + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004b0cf2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b0cf7  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004b0cfc  89842400010000         -mov dword ptr [esp + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 004b0d03  899424b0000000         -mov dword ptr [esp + 0xb0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.edx;
    // 004b0d0a  8b8424fc000000         -mov eax, dword ptr [esp + 0xfc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 004b0d11  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004b0d16  898424c4000000         -mov dword ptr [esp + 0xc4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 004b0d1d  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0d21  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0d25  e8f617ffff             -call 0x4a2520
    cpu.esp -= 4;
    sub_4a2520(app, cpu);
    if (cpu.terminate) return;
    // 004b0d2a  a1e8894d00             -mov eax, dword ptr [0x4d89e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 004b0d2f  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004b0d31  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b0d33  bb746567ea             -mov ebx, 0xea676574
    cpu.ebx = 3932644724 /*0xea676574*/;
    // 004b0d38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0d39  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004b0d40  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004b0d43  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 004b0d45  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b0d47  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0d48  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0d49  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0d4a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0d4b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0d4c  e8e7e9ffff             -call 0x4af738
    cpu.esp -= 4;
    sub_4af738(app, cpu);
    if (cpu.terminate) return;
    // 004b0d51  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0d59  0f8403010000           -je 0x4b0e62
    if (cpu.flags.zf)
    {
        goto L_0x004b0e62;
    }
    // 004b0d5f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004b0d64:
    // 004b0d64  8bb42400010000         -mov esi, dword ptr [esp + 0x100]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004b0d6b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b0d6d  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 004b0d74  899c240c010000         -mov dword ptr [esp + 0x10c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.ebx;
    // 004b0d7b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b0d7d  0f84cd000000           -je 0x4b0e50
    if (cpu.flags.zf)
    {
        goto L_0x004b0e50;
    }
L_0x004b0d83:
    // 004b0d83  83bc240c0100001f       +cmp dword ptr [esp + 0x10c], 0x1f
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0d8b  0f8dbf000000           -jge 0x4b0e50
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b0e50;
    }
    // 004b0d91  83bc24c400000000       +cmp dword ptr [esp + 0xc4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0d99  0f84b1000000           -je 0x4b0e50
    if (cpu.flags.zf)
    {
        goto L_0x004b0e50;
    }
    // 004b0d9f  83bc240401000000       +cmp dword ptr [esp + 0x104], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0da7  0f84a3000000           -je 0x4b0e50
    if (cpu.flags.zf)
    {
        goto L_0x004b0e50;
    }
    // 004b0dad  8a8c240c010000         -mov cl, byte ptr [esp + 0x10c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004b0db4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b0db9  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004b0dc0  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b0dc2  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 004b0dc4  746c                   -je 0x4b0e32
    if (cpu.flags.zf)
    {
        goto L_0x004b0e32;
    }
    // 004b0dc6  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004b0dcb  8b94240c010000         -mov edx, dword ptr [esp + 0x10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004b0dd2  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0dd6  e84517ffff             -call 0x4a2520
    cpu.esp -= 4;
    sub_4a2520(app, cpu);
    if (cpu.terminate) return;
    // 004b0ddb  a1e8894d00             -mov eax, dword ptr [0x4d89e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 004b0de0  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b0de2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0de3  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0de7  bb746567ea             -mov ebx, 0xea676574
    cpu.ebx = 3932644724 /*0xea676574*/;
    // 004b0dec  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 004b0dee  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004b0df5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b0df7  e83ce9ffff             -call 0x4af738
    cpu.esp -= 4;
    sub_4af738(app, cpu);
    if (cpu.terminate) return;
    // 004b0dfc  83bc24b000000000       +cmp dword ptr [esp + 0xb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0e04  7463                   -je 0x4b0e69
    if (cpu.flags.zf)
    {
        goto L_0x004b0e69;
    }
    // 004b0e06  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004b0e0b:
    // 004b0e0b  8a8c240c010000         -mov cl, byte ptr [esp + 0x10c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004b0e12  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 004b0e19  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b0e1e  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b0e20  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004b0e27  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004b0e29  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0e2b  899c240c010000         -mov dword ptr [esp + 0x10c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.ebx;
L_0x004b0e32:
    // 004b0e32  8b94240c010000         -mov edx, dword ptr [esp + 0x10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004b0e39  42                     -inc edx
    (cpu.edx)++;
    // 004b0e3a  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004b0e41  8994240c010000         -mov dword ptr [esp + 0x10c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.edx;
    // 004b0e48  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b0e4a  0f8533ffffff           -jne 0x4b0d83
    if (!cpu.flags.zf)
    {
        goto L_0x004b0d83;
    }
L_0x004b0e50:
    // 004b0e50  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004b0e57  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 004b0e5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0e62:
    // 004b0e62  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b0e64  e9fbfeffff             -jmp 0x4b0d64
    goto L_0x004b0d64;
L_0x004b0e69:
    // 004b0e69  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b0e6b  eb9e                   -jmp 0x4b0e0b
    goto L_0x004b0e0b;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b0e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b0e70);
    // 004b0e70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0e71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0e72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0e73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0e74  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b0e77  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b0e79  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b0e7c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b0e7e  750a                   -jne 0x4b0e8a
    if (!cpu.flags.zf)
    {
        goto L_0x004b0e8a;
    }
L_0x004b0e80:
    // 004b0e80  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0e82  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b0e85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e86  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0e89  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0e8a:
    // 004b0e8a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0e8c  e887e9ffff             -call 0x4af818
    cpu.esp -= 4;
    sub_4af818(app, cpu);
    if (cpu.terminate) return;
    // 004b0e91  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0e93  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0e95  74e9                   -je 0x4b0e80
    if (cpu.flags.zf)
    {
        goto L_0x004b0e80;
    }
    // 004b0e97  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0e98  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004b0e9b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b0e9d  0588000000             -add eax, 0x88
    (cpu.eax) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 004b0ea2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0ea4  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004b0ea9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0eab  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b0eae  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b0eb0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b0eb2  bb74756fea             -mov ebx, 0xea6f7574
    cpu.ebx = 3933173108 /*0xea6f7574*/;
    // 004b0eb7  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b0eba  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b0ebe  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b0ec0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0ec2  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b0ec5  ff5550                 -call dword ptr [ebp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0ec8  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b0ecc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b0ed1  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004b0ed4  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004b0ed6  8b5a50                 -mov ebx, dword ptr [edx + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    // 004b0ed9  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004b0edb  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0edd  895a50                 -mov dword ptr [edx + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 004b0ee0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ee1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0ee3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b0ee6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ee7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ee8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0ee9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0eea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b0eec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b0eec);
    // 004b0eec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0eed  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b0eef  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b0ef1  745a                   -je 0x4b0f4d
    if (cpu.flags.zf)
    {
        goto L_0x004b0f4d;
    }
    // 004b0ef3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0ef4  837a2400               +cmp dword ptr [edx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0ef8  7515                   -jne 0x4b0f0f
    if (!cpu.flags.zf)
    {
        goto L_0x004b0f0f;
    }
    // 004b0efa  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 004b0f00  bf1e000000             -mov edi, 0x1e
    cpu.edi = 30 /*0x1e*/;
    // 004b0f05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0f07  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b0f0a  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b0f0c  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004b0f0f:
    // 004b0f0f  837e2800               +cmp dword ptr [esi + 0x28], 0
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
    // 004b0f13  7515                   -jne 0x4b0f2a
    if (!cpu.flags.zf)
    {
        goto L_0x004b0f2a;
    }
    // 004b0f15  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 004b0f1b  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
    // 004b0f20  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0f22  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b0f25  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b0f27  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x004b0f2a:
    // 004b0f2a  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 004b0f2e  7515                   -jne 0x4b0f45
    if (!cpu.flags.zf)
    {
        goto L_0x004b0f45;
    }
    // 004b0f30  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 004b0f36  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
    // 004b0f3b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b0f3d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b0f40  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b0f42  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x004b0f45:
    // 004b0f45  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b0f4c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004b0f4d:
    // 004b0f4d  badc294d00             -mov edx, 0x4d29dc
    cpu.edx = 5056988 /*0x4d29dc*/;
    // 004b0f52  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0f53  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0f55  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b0f57  bbb0df4d00             -mov ebx, 0x4ddfb0
    cpu.ebx = 5103536 /*0x4ddfb0*/;
    // 004b0f5c  e89776fdff             -call 0x4885f8
    cpu.esp -= 4;
    sub_4885f8(app, cpu);
    if (cpu.terminate) return;
    // 004b0f61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0f62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b0f64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b0f64);
    // 004b0f64  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0f65  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0f66  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0f67  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0f68  8b7048                 -mov esi, dword ptr [eax + 0x48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004b0f6b  891514715b00           -mov dword ptr [0x5b7114], edx
    app->getMemory<x86::reg32>(x86::reg32(5992724) /* 0x5b7114 */) = cpu.edx;
    // 004b0f71  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b0f74  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0f76  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b0f78  7459                   -je 0x4b0fd3
    if (cpu.flags.zf)
    {
        goto L_0x004b0fd3;
    }
    // 004b0f7a  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b0f7d  837a4400               +cmp dword ptr [edx + 0x44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0f81  740b                   -je 0x4b0f8e
    if (cpu.flags.zf)
    {
        goto L_0x004b0f8e;
    }
    // 004b0f83  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b0f85  8d5030                 -lea edx, [eax + 0x30]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004b0f88  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b0f8b  ff5144                 -call dword ptr [ecx + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b0f8e:
    // 004b0f8e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0f8f  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 004b0f94  8d5730                 -lea edx, [edi + 0x30]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 004b0f97  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b0f9a  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b0f9d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b0f9f  ff5558                 -call dword ptr [ebp + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0fa2  a178ea5600             -mov eax, dword ptr [0x56ea78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696120) /* 0x56ea78 */);
    // 004b0fa7  e80c74fdff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004b0fac  8b9ea8000000           -mov ebx, dword ptr [esi + 0xa8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 004b0fb2  43                     -inc ebx
    (cpu.ebx)++;
    // 004b0fb3  a178ea5600             -mov eax, dword ptr [0x56ea78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696120) /* 0x56ea78 */);
    // 004b0fb8  899ea8000000           -mov dword ptr [esi + 0xa8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */) = cpu.ebx;
    // 004b0fbe  e80d74fdff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004b0fc3  c74744ffffffff         -mov dword ptr [edi + 0x44], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */) = 4294967295 /*0xffffffff*/;
    // 004b0fca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fcb  8b4744                 -mov eax, dword ptr [edi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */);
    // 004b0fce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fcf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fd0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fd2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b0fd3:
    // 004b0fd3  895044                 -mov dword ptr [eax + 0x44], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 004b0fd6  8b4744                 -mov eax, dword ptr [edi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */);
    // 004b0fd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fdb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fdc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0fdd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b0fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b0fe0);
    // 004b0fe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0fe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0fe2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0fe3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0fe4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0fe5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b0fe7  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004b0fea  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004b0fed  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0fef  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0ff1  7409                   -je 0x4b0ffc
    if (cpu.flags.zf)
    {
        goto L_0x004b0ffc;
    }
    // 004b0ff3  83baa800000000         +cmp dword ptr [edx + 0xa8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0ffa  7512                   -jne 0x4b100e
    if (!cpu.flags.zf)
    {
        goto L_0x004b100e;
    }
L_0x004b0ffc:
    // 004b0ffc  c7474400000000         -mov dword ptr [edi + 0x44], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 004b1003  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b1008  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1009  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b100a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b100b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b100c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b100d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b100e:
    // 004b100e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b100f  a178ea5600             -mov eax, dword ptr [0x56ea78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696120) /* 0x56ea78 */);
    // 004b1014  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 004b1019  e89a73fdff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004b101e  8d7130                 -lea esi, [ecx + 0x30]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 004b1021  8baaa8000000           -mov ebp, dword ptr [edx + 0xa8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 004b1027  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b102c  4d                     -dec ebp
    (cpu.ebp)--;
    // 004b102d  a178ea5600             -mov eax, dword ptr [0x56ea78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696120) /* 0x56ea78 */);
    // 004b1032  89aaa8000000           -mov dword ptr [edx + 0xa8], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */) = cpu.ebp;
    // 004b1038  e89373fdff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004b103d  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b1040  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004b1043  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b1045  ff5558                 -call dword ptr [ebp + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b1048  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1049  c7474400000000         -mov dword ptr [edi + 0x44], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 004b1050  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b1055  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1056  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1057  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1058  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1059  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b105a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b105c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b105c);
    // 004b105c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b105d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b105e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b105f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b1061  8b1d14715b00           -mov ebx, dword ptr [0x5b7114]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5992724) /* 0x5b7114 */);
    // 004b1067  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b1069  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b106b  751b                   -jne 0x4b1088
    if (!cpu.flags.zf)
    {
        goto L_0x004b1088;
    }
L_0x004b106d:
    // 004b106d  83794400               +cmp dword ptr [ecx + 0x44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1071  7428                   -je 0x4b109b
    if (cpu.flags.zf)
    {
        goto L_0x004b109b;
    }
    // 004b1073  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004b1076  83b89c00000000         +cmp dword ptr [eax + 0x9c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b107d  741c                   -je 0x4b109b
    if (cpu.flags.zf)
    {
        goto L_0x004b109b;
    }
    // 004b107f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b1084  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1085  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1086  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1087  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1088:
    // 004b1088  e833000000             -call 0x4b10c0
    cpu.esp -= 4;
    sub_4b10c0(app, cpu);
    if (cpu.terminate) return;
    // 004b108d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b108f  74dc                   -je 0x4b106d
    if (cpu.flags.zf)
    {
        goto L_0x004b106d;
    }
    // 004b1091  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b1093  ff1514715b00           -call dword ptr [0x5b7114]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5992724) /* 0x5b7114 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b1099  ebd2                   -jmp 0x4b106d
    goto L_0x004b106d;
L_0x004b109b:
    // 004b109b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b109d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b109e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b109f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b10a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b10a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b10a4);
    // 004b10a4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b10a5  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004b10a8  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b10ab  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b10ae  ff5248                 -call dword ptr [edx + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b10b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b10b3  7408                   -je 0x4b10bd
    if (cpu.flags.zf)
    {
        goto L_0x004b10bd;
    }
    // 004b10b5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b10b7  66a1ccdf4d00           -mov ax, word ptr [0x4ddfcc]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5103564) /* 0x4ddfcc */);
L_0x004b10bd:
    // 004b10bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b10be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b10c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b10c0);
    // 004b10c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b10c1  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004b10c4  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b10c7  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b10ca  ff524c                 -call dword ptr [edx + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b10cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b10ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b10d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b10d0);
    // 004b10d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b10d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b10d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b10d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b10d4  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004b10d7  8954246c               -mov dword ptr [esp + 0x6c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 004b10db  895c2468               -mov dword ptr [esp + 0x68], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebx;
    // 004b10df  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004b10e4  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004b10e6  be00f54a00             -mov esi, 0x4af500
    cpu.esi = 4912384 /*0x4af500*/;
    // 004b10eb  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b10ed  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b10ef  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004b10f2  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004b10f4  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b10f8  83c730                 -add edi, 0x30
    (cpu.edi) += x86::reg32(x86::sreg32(48 /*0x30*/));
L_0x004b10fb:
    // 004b10fb  ba746164ea             -mov edx, 0xea646174
    cpu.edx = 3932447092 /*0xea646174*/;
    // 004b1100  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 004b1105  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b1107  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 004b110b  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004b110f  8b4c2468               -mov ecx, dword ptr [esp + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004b1113  e8e889fdff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004b1118  8d5c2464               -lea ebx, [esp + 0x64]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004b111c  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 004b111f  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004b1123  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1124  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b1127  8b4c2470               -mov ecx, dword ptr [esp + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004b112b  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b112e  ff5654                 -call dword ptr [esi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b1131  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004b1135  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b1137  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b1139  746c                   -je 0x4b11a7
    if (cpu.flags.zf)
    {
        goto L_0x004b11a7;
    }
    // 004b113b  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 004b113e  83781800               +cmp dword ptr [eax + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1142  7505                   -jne 0x4b1149
    if (!cpu.flags.zf)
    {
        goto L_0x004b1149;
    }
    // 004b1144  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b1146  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004b1149:
    // 004b1149  8b4c246c               -mov ecx, dword ptr [esp + 0x6c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004b114d  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004b1151  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 004b1154  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1155  8d542454               -lea edx, [esp + 0x54]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004b1159  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b115c  e83be8ffff             -call 0x4af99c
    cpu.esp -= 4;
    sub_4af99c(app, cpu);
    if (cpu.terminate) return;
    // 004b1161  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 004b1164  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b1166  3b5018                 +cmp edx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1169  7507                   -jne 0x4b1172
    if (!cpu.flags.zf)
    {
        goto L_0x004b1172;
    }
    // 004b116b  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x004b1172:
    // 004b1172  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004b1176  81fb746164ea           +cmp ebx, 0xea646174
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932447092 /*0xea646174*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b117c  7418                   -je 0x4b1196
    if (cpu.flags.zf)
    {
        goto L_0x004b1196;
    }
    // 004b117e  81fb216f6eea           +cmp ebx, 0xea6e6f21
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933105953 /*0xea6e6f21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1184  0f8571ffffff           -jne 0x4b10fb
    if (!cpu.flags.zf)
    {
        goto L_0x004b10fb;
    }
    // 004b118a  c7450400000000         -mov dword ptr [ebp + 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b1191  e965ffffff             -jmp 0x4b10fb
    goto L_0x004b10fb;
L_0x004b1196:
    // 004b1196  c7454401000000         -mov dword ptr [ebp + 0x44], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(68) /* 0x44 */) = 1 /*0x1*/;
    // 004b119d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b119f  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004b11a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b11a7:
    // 004b11a7  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 004b11aa  83b8a800000000         +cmp dword ptr [eax + 0xa8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b11b1  7512                   -jne 0x4b11c5
    if (!cpu.flags.zf)
    {
        goto L_0x004b11c5;
    }
    // 004b11b3  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 004b11b8  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b11bb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b11bd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b11bf  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b11c2  ff5658                 -call dword ptr [esi + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b11c5:
    // 004b11c5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b11c7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b11c9  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004b11cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b11d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b11d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b11d4);
    // 004b11d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b11d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b11d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b11d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b11d8  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b11db  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b11dd  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b11e0  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004b11e2  ba746164ea             -mov edx, 0xea646174
    cpu.edx = 3932447092 /*0xea646174*/;
    // 004b11e7  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b11eb  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b11ef  83784400               +cmp dword ptr [eax + 0x44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b11f3  7d35                   -jge 0x4b122a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b122a;
    }
    // 004b11f5  ff4844                 -dec dword ptr [eax + 0x44]
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */))--;
    // 004b11f8  837844fc               +cmp dword ptr [eax + 0x44], -4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b11fc  7d2c                   -jge 0x4b122a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b122a;
    }
    // 004b11fe  b86e706fea             -mov eax, 0xea6f706e
    cpu.eax = 3933171822 /*0xea6f706e*/;
    // 004b1203  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b1205  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b1209  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004b120c  bb6e706fea             -mov ebx, 0xea6f706e
    cpu.ebx = 3933171822 /*0xea6f706e*/;
    // 004b1211  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004b1214  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b1217  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b1219  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b121c  ff5550                 -call dword ptr [ebp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b121f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b1221  7407                   -je 0x4b122a
    if (cpu.flags.zf)
    {
        goto L_0x004b122a;
    }
    // 004b1223  c74644ffffffff         -mov dword ptr [esi + 0x44], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = 4294967295 /*0xffffffff*/;
L_0x004b122a:
    // 004b122a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b122e  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b1232  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b1235  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004b1238  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b123c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b123d  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b1240  83c230                 -add edx, 0x30
    (cpu.edx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004b1243  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b1246  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b1249  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b124b  7402                   -je 0x4b124f
    if (cpu.flags.zf)
    {
        goto L_0x004b124f;
    }
    // 004b124d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004b124f:
    // 004b124f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b1252  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1253  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1254  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1255  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1256  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b1257(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b1257);
    // 004b1257  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1258  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1259  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b125a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b125b  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004b125e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b1260  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004b1262  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004b1267  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004b1269  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b126c  885c246c               -mov byte ptr [esp + 0x6c], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.bl;
    // 004b1270  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004b1272  89542468               -mov dword ptr [esp + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 004b1276  66895c241e             -mov word ptr [esp + 0x1e], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(30) /* 0x1e */) = cpu.bx;
    // 004b127b  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004b127d  66894c241c             -mov word ptr [esp + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 004b1282  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004b1286  e978000000             -jmp 0x4b1303
    goto L_0x004b1303;
L_0x004b128b:
    // 004b128b  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004b128d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b128f  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004b1293  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 004b1297  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b1299  e87a020000             -call 0x4b1518
    cpu.esp -= 4;
    sub_4b1518(app, cpu);
    if (cpu.terminate) return;
    // 004b129e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b12a0  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004b12a4  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b12a6  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004b12a8  47                     -inc edi
    (cpu.edi)++;
    // 004b12a9  88442415               -mov byte ptr [esp + 0x15], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 004b12ad  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
    // 004b12b1  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004b12b3  0f8453020000           -je 0x4b150c
    if (cpu.flags.zf)
    {
        goto L_0x004b150c;
    }
    // 004b12b9  3c6e                   +cmp al, 0x6e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(110 /*0x6e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b12bb  0f85d8000000           -jne 0x4b1399
    if (!cpu.flags.zf)
    {
        goto L_0x004b1399;
    }
    // 004b12c1  8a74241e               -mov dh, byte ptr [esp + 0x1e]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 004b12c5  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 004b12c8  7461                   -je 0x4b132b
    if (cpu.flags.zf)
    {
        goto L_0x004b132b;
    }
    // 004b12ca  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 004b12cd  7413                   -je 0x4b12e2
    if (cpu.flags.zf)
    {
        goto L_0x004b12e2;
    }
    // 004b12cf  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b12d1  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b12d4  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b12d6  c452f8                 -les edx, ptr [edx - 8]
    NFS2_ASSERT(false);
L_0x004b12d9:
    // 004b12d9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b12dd  268902                 -mov dword ptr es:[edx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 004b12e0  eb21                   -jmp 0x4b1303
    goto L_0x004b1303;
L_0x004b12e2:
    // 004b12e2  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 004b12e5  740c                   -je 0x4b12f3
    if (cpu.flags.zf)
    {
        goto L_0x004b12f3;
    }
    // 004b12e7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b12e9  83c004                 +add eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b12ec  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b12ee  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b12f1  eb0a                   -jmp 0x4b12fd
    goto L_0x004b12fd;
L_0x004b12f3:
    // 004b12f3  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004b12f5  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b12f8  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004b12fa  8b57fc                 -mov edx, dword ptr [edi - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
L_0x004b12fd:
    // 004b12fd  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b1301  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004b1303:
    // 004b1303  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004b1307  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 004b1309  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004b130b  0f84fb010000           -je 0x4b150c
    if (cpu.flags.zf)
    {
        goto L_0x004b150c;
    }
    // 004b1311  8d7801                 -lea edi, [eax + 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b1314  80ff25                 +cmp bh, 0x25
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1317  0f846effffff           -je 0x4b128b
    if (cpu.flags.zf)
    {
        goto L_0x004b128b;
    }
    // 004b131d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b131f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b1321  88fa                   -mov dl, bh
    cpu.dl = cpu.bh;
    // 004b1323  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
    // 004b1327  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b1329  ebd8                   -jmp 0x4b1303
    goto L_0x004b1303;
L_0x004b132b:
    // 004b132b  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 004b132e  743d                   -je 0x4b136d
    if (cpu.flags.zf)
    {
        goto L_0x004b136d;
    }
    // 004b1330  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 004b1333  7414                   -je 0x4b1349
    if (cpu.flags.zf)
    {
        goto L_0x004b1349;
    }
    // 004b1335  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b1337  83c108                 +add ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b133a  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004b133c  c451f8                 -les edx, ptr [ecx - 8]
    NFS2_ASSERT(false);
    // 004b133f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b1343  66268902               -mov word ptr es:[edx], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.ax;
    // 004b1347  ebba                   -jmp 0x4b1303
    goto L_0x004b1303;
L_0x004b1349:
    // 004b1349  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 004b134c  7413                   -je 0x4b1361
    if (cpu.flags.zf)
    {
        goto L_0x004b1361;
    }
    // 004b134e  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b1350  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b1353  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 004b1355  8b53fc                 -mov edx, dword ptr [ebx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x004b1358:
    // 004b1358  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b135c  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 004b135f  eba2                   -jmp 0x4b1303
    goto L_0x004b1303;
L_0x004b1361:
    // 004b1361  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b1363  83c204                 +add edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b1366  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b1368  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b136b  ebeb                   -jmp 0x4b1358
    goto L_0x004b1358;
L_0x004b136d:
    // 004b136d  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 004b1370  740f                   -je 0x4b1381
    if (cpu.flags.zf)
    {
        goto L_0x004b1381;
    }
    // 004b1372  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b1374  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b1377  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b1379  c450f8                 -les edx, ptr [eax - 8]
    NFS2_ASSERT(false);
    // 004b137c  e958ffffff             -jmp 0x4b12d9
    goto L_0x004b12d9;
L_0x004b1381:
    // 004b1381  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 004b1384  0f8569ffffff           -jne 0x4b12f3
    if (!cpu.flags.zf)
    {
        goto L_0x004b12f3;
    }
    // 004b138a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b138c  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b138f  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004b1391  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004b1394  e964ffffff             -jmp 0x4b12fd
    goto L_0x004b12fd;
L_0x004b1399:
    // 004b1399  8d4c246c               -lea ecx, [esp + 0x6c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004b139d  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004b139f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b13a1  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004b13a5  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 004b13a9  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004b13ad  e878050000             -call 0x4b192a
    cpu.esp -= 4;
    sub_4b192a(app, cpu);
    if (cpu.terminate) return;
    // 004b13b2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b13b4  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004b13b8  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b13ba  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b13bc  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b13c0  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b13c4  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b13c8  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b13ca  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b13ce  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b13d0  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b13d4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b13d6  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b13da  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b13dc  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b13e0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b13e2  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b13e4  8a64241e               -mov ah, byte ptr [esp + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 004b13e8  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b13ec  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 004b13ef  751d                   -jne 0x4b140e
    if (!cpu.flags.zf)
    {
        goto L_0x004b140e;
    }
    // 004b13f1  807c241620             +cmp byte ptr [esp + 0x16], 0x20
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b13f6  7516                   -jne 0x4b140e
    if (!cpu.flags.zf)
    {
        goto L_0x004b140e;
    }
L_0x004b13f8:
    // 004b13f8  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b13fd  7e0f                   -jle 0x4b140e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b140e;
    }
    // 004b13ff  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004b1404  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b1406  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b1408  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b140c  ebea                   -jmp 0x4b13f8
    goto L_0x004b13f8;
L_0x004b140e:
    // 004b140e  8d5c2438               -lea ebx, [esp + 0x38]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
L_0x004b1412:
    // 004b1412  837c242000             +cmp dword ptr [esp + 0x20], 0
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
    // 004b1417  7e14                   -jle 0x4b142d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b142d;
    }
    // 004b1419  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b141b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b141d  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004b141f  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b1421  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b1425  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b1426  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b1427  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b142b  ebe5                   -jmp 0x4b1412
    goto L_0x004b1412;
L_0x004b142d:
    // 004b142d  837c242400             +cmp dword ptr [esp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1432  7e0f                   -jle 0x4b1443
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1443;
    }
    // 004b1434  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004b1439  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b143b  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b143d  ff4c2424               +dec dword ptr [esp + 0x24]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b1441  ebea                   -jmp 0x4b142d
    goto L_0x004b142d;
L_0x004b1443:
    // 004b1443  8a742415               -mov dh, byte ptr [esp + 0x15]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */);
    // 004b1447  80fe73                 +cmp dh, 0x73
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(115 /*0x73*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b144a  7532                   -jne 0x4b147e
    if (!cpu.flags.zf)
    {
        goto L_0x004b147e;
    }
    // 004b144c  f644241e20             +test byte ptr [esp + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004b1451  740f                   -je 0x4b1462
    if (cpu.flags.zf)
    {
        goto L_0x004b1462;
    }
L_0x004b1453:
    // 004b1453  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004b1455  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004b1457  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004b1459  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b145b  e872040000             -call 0x4b18d2
    cpu.esp -= 4;
    sub_4b18d2(app, cpu);
    if (cpu.terminate) return;
    // 004b1460  eb3d                   -jmp 0x4b149f
    goto L_0x004b149f;
L_0x004b1462:
    // 004b1462  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1467  7e36                   -jle 0x4b149f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b149f;
    }
    // 004b1469  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b146b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b146d  268a17                 -mov dl, byte ptr es:[edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.edi);
    // 004b1470  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b1472  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b1476  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b1477  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b1478  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004b147c  ebe4                   -jmp 0x4b1462
    goto L_0x004b1462;
L_0x004b147e:
    // 004b147e  80fe53                 +cmp dh, 0x53
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1481  74d0                   -je 0x4b1453
    if (cpu.flags.zf)
    {
        goto L_0x004b1453;
    }
L_0x004b1483:
    // 004b1483  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1488  7e15                   -jle 0x4b149f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b149f;
    }
    // 004b148a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b148c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b148e  268a17                 -mov dl, byte ptr es:[edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.edi);
    // 004b1491  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b1493  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b1497  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b1498  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b1499  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004b149d  ebe4                   -jmp 0x4b1483
    goto L_0x004b1483;
L_0x004b149f:
    // 004b149f  837c242c00             +cmp dword ptr [esp + 0x2c], 0
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
    // 004b14a4  7e0f                   -jle 0x4b14b5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b14b5;
    }
    // 004b14a6  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004b14ab  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b14ad  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b14af  ff4c242c               +dec dword ptr [esp + 0x2c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b14b3  ebea                   -jmp 0x4b149f
    goto L_0x004b149f;
L_0x004b14b5:
    // 004b14b5  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 004b14ba  7e15                   -jle 0x4b14d1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b14d1;
    }
    // 004b14bc  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b14be  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b14c0  268a17                 -mov dl, byte ptr es:[edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.edi);
    // 004b14c3  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b14c5  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b14c9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b14ca  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b14cb  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 004b14cf  ebe4                   -jmp 0x4b14b5
    goto L_0x004b14b5;
L_0x004b14d1:
    // 004b14d1  837c243400             +cmp dword ptr [esp + 0x34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b14d6  7e0f                   -jle 0x4b14e7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b14e7;
    }
    // 004b14d8  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004b14dd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b14df  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b14e1  ff4c2434               +dec dword ptr [esp + 0x34]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b14e5  ebea                   -jmp 0x4b14d1
    goto L_0x004b14d1;
L_0x004b14e7:
    // 004b14e7  f644241e08             +test byte ptr [esp + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 004b14ec  0f8411feffff           -je 0x4b1303
    if (cpu.flags.zf)
    {
        goto L_0x004b1303;
    }
L_0x004b14f2:
    // 004b14f2  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b14f7  0f8e06feffff           -jle 0x4b1303
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1303;
    }
    // 004b14fd  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004b1502  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b1504  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b1506  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b150a  ebe6                   -jmp 0x4b14f2
    goto L_0x004b14f2;
L_0x004b150c:
    // 004b150c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b1510  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004b1513  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1514  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b1515  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1516  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1517  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b1518(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b1518);
    // 004b1518  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1519  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b151a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b151b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b151d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b151f  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
    // 004b1523  e83d010000             -call 0x4b1665
    cpu.esp -= 4;
    sub_4b1665(app, cpu);
    if (cpu.terminate) return;
    // 004b1528  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b152f  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1532  7524                   -jne 0x4b1558
    if (!cpu.flags.zf)
    {
        goto L_0x004b1558;
    }
    // 004b1534  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b1536  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1539  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b153b  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b153e  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b1541  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b1543  7d10                   -jge 0x4b1555
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1555;
    }
    // 004b1545  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b1547  8a6b1e                 -mov ch, byte ptr [ebx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004b154a  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 004b154c  80cd08                 +or ch, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004b154f  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004b1552  886b1e                 -mov byte ptr [ebx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.ch;
L_0x004b1555:
    // 004b1555  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b1556  eb1f                   -jmp 0x4b1577
    goto L_0x004b1577;
L_0x004b1558:
    // 004b1558  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b155a  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b155d  7218                   -jb 0x4b1577
    if (cpu.flags.cf)
    {
        goto L_0x004b1577;
    }
    // 004b155f  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1562  7713                   -ja 0x4b1577
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b1577;
    }
    // 004b1564  6b4b040a               -imul ecx, dword ptr [ebx + 4], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004b1568  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b156a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b156c  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004b156f  01d1                   +add ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b1571  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b1572  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b1575  ebe1                   -jmp 0x4b1558
    goto L_0x004b1558;
L_0x004b1577:
    // 004b1577  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 004b157e  80382e                 +cmp byte ptr [eax], 0x2e
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
    // 004b1581  7551                   -jne 0x4b15d4
    if (!cpu.flags.zf)
    {
        goto L_0x004b15d4;
    }
    // 004b1583  40                     -inc eax
    (cpu.eax)++;
    // 004b1584  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b158b  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b158e  751b                   -jne 0x4b15ab
    if (!cpu.flags.zf)
    {
        goto L_0x004b15ab;
    }
    // 004b1590  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b1592  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1595  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b1597  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b159a  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b159d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b159f  7d07                   -jge 0x4b15a8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b15a8;
    }
    // 004b15a1  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
L_0x004b15a8:
    // 004b15a8  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b15a9  eb1f                   -jmp 0x4b15ca
    goto L_0x004b15ca;
L_0x004b15ab:
    // 004b15ab  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b15ad  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b15b0  7218                   -jb 0x4b15ca
    if (cpu.flags.cf)
    {
        goto L_0x004b15ca;
    }
    // 004b15b2  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b15b5  7713                   -ja 0x4b15ca
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b15ca;
    }
    // 004b15b7  6b4b080a               -imul ecx, dword ptr [ebx + 8], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004b15bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b15bd  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b15bf  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004b15c2  01d1                   +add ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b15c4  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b15c5  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004b15c8  ebe1                   -jmp 0x4b15ab
    goto L_0x004b15ab;
L_0x004b15ca:
    // 004b15ca  837b08ff               +cmp dword ptr [ebx + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b15ce  7404                   -je 0x4b15d4
    if (cpu.flags.zf)
    {
        goto L_0x004b15d4;
    }
    // 004b15d0  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
L_0x004b15d4:
    // 004b15d4  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b15d6  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b15d9  80fa4e                 +cmp dl, 0x4e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b15dc  721f                   -jb 0x4b15fd
    if (cpu.flags.cf)
    {
        goto L_0x004b15fd;
    }
    // 004b15de  0f8677000000           -jbe 0x4b165b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b165b;
    }
    // 004b15e4  80fa6c                 +cmp dl, 0x6c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(108 /*0x6c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b15e7  720b                   -jb 0x4b15f4
    if (cpu.flags.cf)
    {
        goto L_0x004b15f4;
    }
    // 004b15e9  762b                   -jbe 0x4b1616
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1616;
    }
    // 004b15eb  80fa77                 +cmp dl, 0x77
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b15ee  7426                   -je 0x4b1616
    if (cpu.flags.zf)
    {
        goto L_0x004b1616;
    }
    // 004b15f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b15f4:
    // 004b15f4  80fa68                 +cmp dl, 0x68
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(104 /*0x68*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b15f7  742b                   -je 0x4b1624
    if (cpu.flags.zf)
    {
        goto L_0x004b1624;
    }
    // 004b15f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b15fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b15fd:
    // 004b15fd  80fa49                 +cmp dl, 0x49
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(73 /*0x49*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1600  720b                   -jb 0x4b160d
    if (cpu.flags.cf)
    {
        goto L_0x004b160d;
    }
    // 004b1602  7626                   -jbe 0x4b162a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b162a;
    }
    // 004b1604  80fa4c                 +cmp dl, 0x4c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(76 /*0x4c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1607  743d                   -je 0x4b1646
    if (cpu.flags.zf)
    {
        goto L_0x004b1646;
    }
    // 004b1609  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b160a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b160b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b160c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b160d:
    // 004b160d  80fa46                 +cmp dl, 0x46
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1610  7443                   -je 0x4b1655
    if (cpu.flags.zf)
    {
        goto L_0x004b1655;
    }
    // 004b1612  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1613  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1614  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1615  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1616:
    // 004b1616  8a4b1e                 -mov cl, byte ptr [ebx + 0x1e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004b1619  80c920                 -or cl, 0x20
    cpu.cl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004b161c  40                     -inc eax
    (cpu.eax)++;
    // 004b161d  884b1e                 -mov byte ptr [ebx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 004b1620  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1621  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1622  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1623  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1624:
    // 004b1624  804b1e10               +or byte ptr [ebx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004b1628  eb35                   -jmp 0x4b165f
    goto L_0x004b165f;
L_0x004b162a:
    // 004b162a  80780136               +cmp byte ptr [eax + 1], 0x36
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(54 /*0x36*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b162e  7531                   -jne 0x4b1661
    if (!cpu.flags.zf)
    {
        goto L_0x004b1661;
    }
    // 004b1630  80780234               +cmp byte ptr [eax + 2], 0x34
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1634  752b                   -jne 0x4b1661
    if (!cpu.flags.zf)
    {
        goto L_0x004b1661;
    }
    // 004b1636  8a6b1f                 -mov ch, byte ptr [ebx + 0x1f]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 004b1639  80cd01                 -or ch, 1
    cpu.ch |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b163c  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b163f  886b1f                 -mov byte ptr [ebx + 0x1f], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.ch;
    // 004b1642  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1643  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1644  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1645  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1646:
    // 004b1646  8a531f                 -mov dl, byte ptr [ebx + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 004b1649  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b164c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b164e  88531f                 -mov byte ptr [ebx + 0x1f], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.dl;
    // 004b1651  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1652  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1653  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1654  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1655:
    // 004b1655  804b1e80               +or byte ptr [ebx + 0x1e], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 004b1659  eb04                   -jmp 0x4b165f
    goto L_0x004b165f;
L_0x004b165b:
    // 004b165b  804b1e40               -or byte ptr [ebx + 0x1e], 0x40
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x004b165f:
    // 004b165f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004b1661:
    // 004b1661  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1662  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1663  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1664  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b1665(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b1665);
    // 004b1665  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b1666  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1667  66c7421e0000           -mov word ptr [edx + 0x1e], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
L_0x004b166d:
    // 004b166d  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b166f  80fb2d                 +cmp bl, 0x2d
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1672  7506                   -jne 0x4b167a
    if (!cpu.flags.zf)
    {
        goto L_0x004b167a;
    }
    // 004b1674  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004b1678  eb42                   -jmp 0x4b16bc
    goto L_0x004b16bc;
L_0x004b167a:
    // 004b167a  80fb23                 +cmp bl, 0x23
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(35 /*0x23*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b167d  7506                   -jne 0x4b1685
    if (!cpu.flags.zf)
    {
        goto L_0x004b1685;
    }
    // 004b167f  804a1e01               +or byte ptr [edx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004b1683  eb37                   -jmp 0x4b16bc
    goto L_0x004b16bc;
L_0x004b1685:
    // 004b1685  80fb2b                 +cmp bl, 0x2b
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1688  7513                   -jne 0x4b169d
    if (!cpu.flags.zf)
    {
        goto L_0x004b169d;
    }
    // 004b168a  8a6a1e                 -mov ch, byte ptr [edx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004b168d  80cd04                 -or ch, 4
    cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004b1690  88eb                   -mov bl, ch
    cpu.bl = cpu.ch;
    // 004b1692  886a1e                 -mov byte ptr [edx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.ch;
    // 004b1695  80e3fd                 +and bl, 0xfd
    cpu.clear_co();
    cpu.set_szp((cpu.bl &= x86::reg8(x86::sreg8(253 /*0xfd*/))));
    // 004b1698  885a1e                 -mov byte ptr [edx + 0x1e], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.bl;
    // 004b169b  eb1f                   -jmp 0x4b16bc
    goto L_0x004b16bc;
L_0x004b169d:
    // 004b169d  80fb20                 +cmp bl, 0x20
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
    // 004b16a0  7512                   -jne 0x4b16b4
    if (!cpu.flags.zf)
    {
        goto L_0x004b16b4;
    }
    // 004b16a2  8a7a1e                 -mov bh, byte ptr [edx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004b16a5  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 004b16a8  7512                   -jne 0x4b16bc
    if (!cpu.flags.zf)
    {
        goto L_0x004b16bc;
    }
    // 004b16aa  88f9                   -mov cl, bh
    cpu.cl = cpu.bh;
    // 004b16ac  80c902                 +or cl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004b16af  884a1e                 -mov byte ptr [edx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 004b16b2  eb08                   -jmp 0x4b16bc
    goto L_0x004b16bc;
L_0x004b16b4:
    // 004b16b4  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b16b7  7506                   -jne 0x4b16bf
    if (!cpu.flags.zf)
    {
        goto L_0x004b16bf;
    }
    // 004b16b9  885a16                 -mov byte ptr [edx + 0x16], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */) = cpu.bl;
L_0x004b16bc:
    // 004b16bc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b16bd  ebae                   -jmp 0x4b166d
    goto L_0x004b166d;
L_0x004b16bf:
    // 004b16bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b16c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b16c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b16c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b16c2);
    // 004b16c2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b16c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b16c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b16c5  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b16c6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b16c8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004b16ca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b16cc  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 004b16ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b16d0:
    // 004b16d0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b16d2  268a1e                 -mov bl, byte ptr es:[esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ees + cpu.esi);
    // 004b16d5  42                     -inc edx
    (cpu.edx)++;
    // 004b16d6  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b16d8  7407                   -je 0x4b16e1
    if (cpu.flags.zf)
    {
        goto L_0x004b16e1;
    }
    // 004b16da  39f8                   +cmp eax, edi
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
    // 004b16dc  7403                   -je 0x4b16e1
    if (cpu.flags.zf)
    {
        goto L_0x004b16e1;
    }
    // 004b16de  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b16df  ebef                   -jmp 0x4b16d0
    goto L_0x004b16d0;
L_0x004b16e1:
    // 004b16e1  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b16e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b16e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b16e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b16e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b16e6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b16e6);
    // 004b16e6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b16e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b16e8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b16e9  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b16ec  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b16ee  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b16f0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b16f2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b16f4  83feff                 +cmp esi, -1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b16f7  7525                   -jne 0x4b171e
    if (!cpu.flags.zf)
    {
        goto L_0x004b171e;
    }
L_0x004b16f9:
    // 004b16f9  66268b33               -mov si, word ptr es:[ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 004b16fd  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 004b1700  7418                   -je 0x4b171a
    if (cpu.flags.zf)
    {
        goto L_0x004b171a;
    }
    // 004b1702  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1704  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b1706  6689f2                 -mov dx, si
    cpu.dx = cpu.si;
    // 004b1709  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b170c  e84f840000             -call 0x4b9b60
    cpu.esp -= 4;
    sub_4b9b60(app, cpu);
    if (cpu.terminate) return;
    // 004b1711  83f8ff                 +cmp eax, -1
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
    // 004b1714  74e3                   -je 0x4b16f9
    if (cpu.flags.zf)
    {
        goto L_0x004b16f9;
    }
    // 004b1716  01c1                   +add ecx, eax
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
    // 004b1718  ebdf                   -jmp 0x4b16f9
    goto L_0x004b16f9;
L_0x004b171a:
    // 004b171a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b171c  eb2a                   -jmp 0x4b1748
    goto L_0x004b1748;
L_0x004b171e:
    // 004b171e  6626833b00             +cmp word ptr es:[ebx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b1723  741d                   -je 0x4b1742
    if (cpu.flags.zf)
    {
        goto L_0x004b1742;
    }
    // 004b1725  39f1                   +cmp ecx, esi
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
    // 004b1727  7f19                   -jg 0x4b1742
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b1742;
    }
    // 004b1729  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b172b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b172d  66268b13               -mov dx, word ptr es:[ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 004b1731  e82a840000             -call 0x4b9b60
    cpu.esp -= 4;
    sub_4b9b60(app, cpu);
    if (cpu.terminate) return;
    // 004b1736  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b1739  83f8ff                 +cmp eax, -1
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
    // 004b173c  74e0                   -je 0x4b171e
    if (cpu.flags.zf)
    {
        goto L_0x004b171e;
    }
    // 004b173e  01c1                   +add ecx, eax
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
    // 004b1740  ebdc                   -jmp 0x4b171e
    goto L_0x004b171e;
L_0x004b1742:
    // 004b1742  39f1                   +cmp ecx, esi
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
    // 004b1744  7ed4                   -jle 0x4b171a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b171a;
    }
    // 004b1746  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004b1748:
    // 004b1748  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b174b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b174c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b174d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b174e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b174f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b174f);
    // 004b174f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1750  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1751  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1752  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1753  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1756  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b1758  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004b175b  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004b1760  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004b1762  e877840000             -call 0x4b9bde
    cpu.esp -= 4;
    sub_4b9bde(app, cpu);
    if (cpu.terminate) return;
    // 004b1767  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b1768  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b176a  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b176c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b176e  49                     -dec ecx
    (cpu.ecx)--;
    // 004b176f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b1771  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004b1773  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004b1775  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b1776  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b1777  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b177a  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004b177c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b177d  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004b1780  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004b1783  eb07                   -jmp 0x4b178c
    goto L_0x004b178c;
L_0x004b1785:
    // 004b1785  4a                     -dec edx
    (cpu.edx)--;
    // 004b1786  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b1788  48                     -dec eax
    (cpu.eax)--;
    // 004b1789  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004b178b  4b                     -dec ebx
    (cpu.ebx)--;
L_0x004b178c:
    // 004b178c  39f2                   +cmp edx, esi
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
    // 004b178e  75f5                   -jne 0x4b1785
    if (!cpu.flags.zf)
    {
        goto L_0x004b1785;
    }
    // 004b1790  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x004b1793:
    // 004b1793  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b1795  7c07                   -jl 0x4b179e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b179e;
    }
    // 004b1797  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b1798  c60230                 -mov byte ptr [edx], 0x30
    app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 004b179b  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b179c  ebf5                   -jmp 0x4b1793
    goto L_0x004b1793;
L_0x004b179e:
    // 004b179e  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004b17a1  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 004b17a5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b17a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b17a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b17aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b17ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b17ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b17ad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b17ad);
    // 004b17ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b17ae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b17af  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b17b0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b17b3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b17b5  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b17b7  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b17ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b17bc  7d0b                   -jge 0x4b17c9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b17c9;
    }
    // 004b17be  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004b17c0  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b17c3  c6002d                 -mov byte ptr [eax], 0x2d
    app->getMemory<x86::reg8>(cpu.eax) = 45 /*0x2d*/;
    // 004b17c6  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x004b17c9:
    // 004b17c9  837e08ff               +cmp dword ptr [esi + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b17cd  7507                   -jne 0x4b17d6
    if (!cpu.flags.zf)
    {
        goto L_0x004b17d6;
    }
    // 004b17cf  c7460804000000         -mov dword ptr [esi + 8], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4 /*0x4*/;
L_0x004b17d6:
    // 004b17d6  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004b17db  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b17dd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b17df  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004b17e4  e8f5830000             -call 0x4b9bde
    cpu.esp -= 4;
    sub_4b9bde(app, cpu);
    if (cpu.terminate) return;
    // 004b17e9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x004b17eb:
    // 004b17eb  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b17ed  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b17f0  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004b17f2  7404                   -je 0x4b17f8
    if (cpu.flags.zf)
    {
        goto L_0x004b17f8;
    }
    // 004b17f4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b17f6  ebf3                   -jmp 0x4b17eb
    goto L_0x004b17eb;
L_0x004b17f8:
    // 004b17f8  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004b17fc  742c                   -je 0x4b182a
    if (cpu.flags.zf)
    {
        goto L_0x004b182a;
    }
    // 004b17fe  c6012e                 -mov byte ptr [ecx], 0x2e
    app->getMemory<x86::reg8>(cpu.ecx) = 46 /*0x2e*/;
    // 004b1801  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b1803  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b1805  eb1b                   -jmp 0x4b1822
    goto L_0x004b1822;
L_0x004b1807:
    // 004b1807  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1809  6689542402             -mov word ptr [esp + 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 004b180e  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b1811  6bd70a                 -imul edx, edi, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004b1814  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b1817  8a542402               -mov dl, byte ptr [esp + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004b181b  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b181e  40                     -inc eax
    (cpu.eax)++;
    // 004b181f  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004b1821  41                     -inc ecx
    (cpu.ecx)++;
L_0x004b1822:
    // 004b1822  3b4608                 +cmp eax, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1825  7ce0                   -jl 0x4b1807
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1807;
    }
    // 004b1827  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x004b182a:
    // 004b182a  f644240180             +test byte ptr [esp + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 128 /*0x80*/));
    // 004b182f  7450                   -je 0x4b1881
    if (cpu.flags.zf)
    {
        goto L_0x004b1881;
    }
L_0x004b1831:
    // 004b1831  39d9                   +cmp ecx, ebx
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
    // 004b1833  7532                   -jne 0x4b1867
    if (!cpu.flags.zf)
    {
        goto L_0x004b1867;
    }
    // 004b1835  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b1838  c60331                 -mov byte ptr [ebx], 0x31
    app->getMemory<x86::reg8>(cpu.ebx) = 49 /*0x31*/;
L_0x004b183b:
    // 004b183b  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b183d  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b1840  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1843  7504                   -jne 0x4b1849
    if (!cpu.flags.zf)
    {
        goto L_0x004b1849;
    }
    // 004b1845  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b1847  ebf2                   -jmp 0x4b183b
    goto L_0x004b183b;
L_0x004b1849:
    // 004b1849  80fa2e                 +cmp dl, 0x2e
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
    // 004b184c  7510                   -jne 0x4b185e
    if (!cpu.flags.zf)
    {
        goto L_0x004b185e;
    }
    // 004b184e  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 004b1851  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b1854  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004b1856:
    // 004b1856  803930                 +cmp byte ptr [ecx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1859  7503                   -jne 0x4b185e
    if (!cpu.flags.zf)
    {
        goto L_0x004b185e;
    }
    // 004b185b  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b185c  ebf8                   -jmp 0x4b1856
    goto L_0x004b1856;
L_0x004b185e:
    // 004b185e  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 004b1861  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b1862  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 004b1865  eb1a                   -jmp 0x4b1881
    goto L_0x004b1881;
L_0x004b1867:
    // 004b1867  49                     -dec ecx
    (cpu.ecx)--;
    // 004b1868  80392e                 +cmp byte ptr [ecx], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b186b  7501                   -jne 0x4b186e
    if (!cpu.flags.zf)
    {
        goto L_0x004b186e;
    }
    // 004b186d  49                     -dec ecx
    (cpu.ecx)--;
L_0x004b186e:
    // 004b186e  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b1870  3c39                   +cmp al, 0x39
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1872  7408                   -je 0x4b187c
    if (cpu.flags.zf)
    {
        goto L_0x004b187c;
    }
    // 004b1874  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004b1876  fec4                   +inc ah
    {
        x86::reg8& tmp = cpu.ah;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 004b1878  8821                   -mov byte ptr [ecx], ah
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.ah;
    // 004b187a  eb05                   -jmp 0x4b1881
    goto L_0x004b1881;
L_0x004b187c:
    // 004b187c  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 004b187f  ebb0                   -jmp 0x4b1831
    goto L_0x004b1831;
L_0x004b1881:
    // 004b1881  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1884  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1885  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1886  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1887  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b1888(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b1888);
    // 004b1888  ff1568e54d00           -call dword ptr [0x4de568]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5105000) /* 0x4de568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b188e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b188f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b188f);
    // 004b188f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b1890  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1891  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b1892  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1893  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1894  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1895  f6401e08               +test byte ptr [eax + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 004b1899  7530                   -jne 0x4b18cb
    if (!cpu.flags.zf)
    {
        goto L_0x004b18cb;
    }
    // 004b189b  80781630               +cmp byte ptr [eax + 0x16], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b189f  752a                   -jne 0x4b18cb
    if (!cpu.flags.zf)
    {
        goto L_0x004b18cb;
    }
    // 004b18a1  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b18a4  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b18a7  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004b18aa  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b18ac  8b7028                 -mov esi, dword ptr [eax + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004b18af  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b18b1  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004b18b4  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b18b6  8b6830                 -mov ebp, dword ptr [eax + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004b18b9  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004b18bb  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004b18be  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b18c0  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b18c2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b18c4  7e05                   -jle 0x4b18cb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b18cb;
    }
    // 004b18c6  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b18c8  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
L_0x004b18cb:
    // 004b18cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b18cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b18cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b18ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b18cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b18d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b18d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b18d2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b18d2);
    // 004b18d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b18d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b18d4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b18d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b18d6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b18d9  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b18db  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b18dd  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
L_0x004b18df:
    // 004b18df  837b2800               +cmp dword ptr [ebx + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b18e3  7e3d                   -jle 0x4b1922
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1922;
    }
    // 004b18e5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b18e7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b18e9  66268b16               -mov dx, word ptr es:[esi]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.esi);
    // 004b18ed  e86e820000             -call 0x4b9b60
    cpu.esp -= 4;
    sub_4b9b60(app, cpu);
    if (cpu.terminate) return;
    // 004b18f2  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b18f5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b18f7  83f8ff                 +cmp eax, -1
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
    // 004b18fa  74e3                   -je 0x4b18df
    if (cpu.flags.zf)
    {
        goto L_0x004b18df;
    }
    // 004b18fc  3b4328                 +cmp eax, dword ptr [ebx + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b18ff  7f1a                   -jg 0x4b191b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b191b;
    }
    // 004b1901  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
L_0x004b1903:
    // 004b1903  4f                     -dec edi
    (cpu.edi)--;
    // 004b1904  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1907  74d6                   -je 0x4b18df
    if (cpu.flags.zf)
    {
        goto L_0x004b18df;
    }
    // 004b1909  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b190b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b190d  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b190f  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b1911  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004b1914  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b1915  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b1916  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b1919  ebe8                   -jmp 0x4b1903
    goto L_0x004b1903;
L_0x004b191b:
    // 004b191b  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
L_0x004b1922:
    // 004b1922  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1925  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1926  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b1927  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1928  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1929  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b192a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b192a);
    // 004b192a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b192b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b192c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b192d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b192e  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1931  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b1933  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b1935  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b1937  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b1939  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004b1940  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004b1947  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004b194e  c7432c00000000         -mov dword ptr [ebx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 004b1955  c7433000000000         -mov dword ptr [ebx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 004b195c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004b195e  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 004b1961  c7433400000000         -mov dword ptr [ebx + 0x34], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004b1968  3c69                   +cmp al, 0x69
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(105 /*0x69*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b196a  7219                   -jb 0x4b1985
    if (cpu.flags.cf)
    {
        goto L_0x004b1985;
    }
    // 004b196c  0f8686000000           -jbe 0x4b19f8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b19f8;
    }
    // 004b1972  3c75                   +cmp al, 0x75
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(117 /*0x75*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1974  720b                   -jb 0x4b1981
    if (cpu.flags.cf)
    {
        goto L_0x004b1981;
    }
    // 004b1976  7620                   -jbe 0x4b1998
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1998;
    }
    // 004b1978  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x004b197a:
    // 004b197a  741c                   -je 0x4b1998
    if (cpu.flags.zf)
    {
        goto L_0x004b1998;
    }
    // 004b197c  e956010000             -jmp 0x4b1ad7
    goto L_0x004b1ad7;
L_0x004b1981:
    // 004b1981  3c6f                   +cmp al, 0x6f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1983  ebf5                   -jmp 0x4b197a
    goto L_0x004b197a;
L_0x004b1985:
    // 004b1985  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1987  0f824a010000           -jb 0x4b1ad7
    if (cpu.flags.cf)
    {
        goto L_0x004b1ad7;
    }
    // 004b198d  7609                   -jbe 0x4b1998
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1998;
    }
    // 004b198f  3c64                   +cmp al, 0x64
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1991  7465                   -je 0x4b19f8
    if (cpu.flags.zf)
    {
        goto L_0x004b19f8;
    }
    // 004b1993  e93f010000             -jmp 0x4b1ad7
    goto L_0x004b1ad7;
L_0x004b1998:
    // 004b1998  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004b199c  7420                   -je 0x4b19be
    if (cpu.flags.zf)
    {
        goto L_0x004b19be;
    }
    // 004b199e  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b19a0  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b19a3  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b19a5  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004b19a8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b19ab  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004b19ad  83c504                 +add ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b19b0  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004b19b2  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x004b19b5:
    // 004b19b5  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b19b9  e919010000             -jmp 0x4b1ad7
    goto L_0x004b1ad7;
L_0x004b19be:
    // 004b19be  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004b19c2  7413                   -je 0x4b19d7
    if (cpu.flags.zf)
    {
        goto L_0x004b19d7;
    }
    // 004b19c4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b19c6  83c004                 +add eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b19c9  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b19cb  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
L_0x004b19ce:
    // 004b19ce  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b19d2  e900010000             -jmp 0x4b1ad7
    goto L_0x004b1ad7;
L_0x004b19d7:
    // 004b19d7  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004b19d9  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b19dc  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004b19de  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b19e1  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b19e5  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 004b19e9  0f84e8000000           -je 0x4b1ad7
    if (cpu.flags.zf)
    {
        goto L_0x004b1ad7;
    }
    // 004b19ef  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b19f1  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b19f6  ebd6                   -jmp 0x4b19ce
    goto L_0x004b19ce;
L_0x004b19f8:
    // 004b19f8  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004b19fc  741d                   -je 0x4b1a1b
    if (cpu.flags.zf)
    {
        goto L_0x004b1a1b;
    }
    // 004b19fe  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b1a00  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1a03  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b1a05  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b1a08  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b1a0b  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b1a0d  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b1a10  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b1a12  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004b1a15  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b1a19  eb33                   -jmp 0x4b1a4e
    goto L_0x004b1a4e;
L_0x004b1a1b:
    // 004b1a1b  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004b1a1f  740c                   -je 0x4b1a2d
    if (cpu.flags.zf)
    {
        goto L_0x004b1a2d;
    }
    // 004b1a21  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004b1a23  83c504                 +add ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b1a26  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004b1a28  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b1a2b  eb1d                   -jmp 0x4b1a4a
    goto L_0x004b1a4a;
L_0x004b1a2d:
    // 004b1a2d  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b1a2f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1a32  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b1a34  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004b1a37  8a791e                 -mov bh, byte ptr [ecx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b1a3a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b1a3e  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 004b1a41  740b                   -je 0x4b1a4e
    if (cpu.flags.zf)
    {
        goto L_0x004b1a4e;
    }
    // 004b1a43  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 004b1a47  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
L_0x004b1a4a:
    // 004b1a4a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004b1a4e:
    // 004b1a4e  8a591f                 -mov bl, byte ptr [ecx + 0x1f]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 004b1a51  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1a53  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004b1a56  7409                   -je 0x4b1a61
    if (cpu.flags.zf)
    {
        goto L_0x004b1a61;
    }
    // 004b1a58  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 004b1a5d  7409                   -je 0x4b1a68
    if (cpu.flags.zf)
    {
        goto L_0x004b1a68;
    }
    // 004b1a5f  eb0b                   -jmp 0x4b1a6c
    goto L_0x004b1a6c;
L_0x004b1a61:
    // 004b1a61  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004b1a66  7c04                   -jl 0x4b1a6c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1a6c;
    }
L_0x004b1a68:
    // 004b1a68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b1a6a  7444                   -je 0x4b1ab0
    if (cpu.flags.zf)
    {
        goto L_0x004b1ab0;
    }
L_0x004b1a6c:
    // 004b1a6c  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b1a6f  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b1a72  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004b1a75  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 004b1a79  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004b1a7d  742b                   -je 0x4b1aaa
    if (cpu.flags.zf)
    {
        goto L_0x004b1aaa;
    }
    // 004b1a7f  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b1a82  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b1a86  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 004b1a88  f7d5                   -not ebp
    cpu.ebp = ~cpu.ebp;
    // 004b1a8a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004b1a8d  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b1a90  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b1a94  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b1a97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b1a99  7508                   -jne 0x4b1aa3
    if (!cpu.flags.zf)
    {
        goto L_0x004b1aa3;
    }
    // 004b1a9b  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004b1a9e  e912ffffff             -jmp 0x4b19b5
    goto L_0x004b19b5;
L_0x004b1aa3:
    // 004b1aa3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b1aa5  e90bffffff             -jmp 0x4b19b5
    goto L_0x004b19b5;
L_0x004b1aaa:
    // 004b1aaa  f75c2408               +neg dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = 0;
        auto tmp2 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004b1aae  eb27                   -jmp 0x4b1ad7
    goto L_0x004b1ad7;
L_0x004b1ab0:
    // 004b1ab0  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b1ab3  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004b1ab5  740f                   -je 0x4b1ac6
    if (cpu.flags.zf)
    {
        goto L_0x004b1ac6;
    }
    // 004b1ab7  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b1aba  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b1abd  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004b1ac0  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 004b1ac4  eb11                   -jmp 0x4b1ad7
    goto L_0x004b1ad7;
L_0x004b1ac6:
    // 004b1ac6  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004b1ac8  740d                   -je 0x4b1ad7
    if (cpu.flags.zf)
    {
        goto L_0x004b1ad7;
    }
    // 004b1aca  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b1acd  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b1ad0  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004b1ad3  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x004b1ad7:
    // 004b1ad7  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004b1ada  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004b1adf  3c64                   +cmp al, 0x64
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1ae1  7261                   -jb 0x4b1b44
    if (cpu.flags.cf)
    {
        goto L_0x004b1b44;
    }
    // 004b1ae3  0f86f0010000           -jbe 0x4b1cd9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1cd9;
    }
    // 004b1ae9  3c6f                   +cmp al, 0x6f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1aeb  7238                   -jb 0x4b1b25
    if (cpu.flags.cf)
    {
        goto L_0x004b1b25;
    }
    // 004b1aed  0f86c6010000           -jbe 0x4b1cb9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1cb9;
    }
    // 004b1af3  3c73                   +cmp al, 0x73
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(115 /*0x73*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1af5  7221                   -jb 0x4b1b18
    if (cpu.flags.cf)
    {
        goto L_0x004b1b18;
    }
    // 004b1af7  0f86e0000000           -jbe 0x4b1bdd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1bdd;
    }
    // 004b1afd  3c75                   +cmp al, 0x75
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(117 /*0x75*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1aff  0f82a2030000           -jb 0x4b1ea7
    if (cpu.flags.cf)
    {
        goto L_0x004b1ea7;
    }
    // 004b1b05  0f86ce010000           -jbe 0x4b1cd9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1cd9;
    }
    // 004b1b0b  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1b0d  0f8463010000           -je 0x4b1c76
    if (cpu.flags.zf)
    {
        goto L_0x004b1c76;
    }
    // 004b1b13  e98f030000             -jmp 0x4b1ea7
    goto L_0x004b1ea7;
L_0x004b1b18:
    // 004b1b18  3c70                   +cmp al, 0x70
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(112 /*0x70*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x004b1b1a:
    // 004b1b1a  0f845f020000           -je 0x4b1d7f
    if (cpu.flags.zf)
    {
        goto L_0x004b1d7f;
    }
    // 004b1b20  e982030000             -jmp 0x4b1ea7
    goto L_0x004b1ea7;
L_0x004b1b25:
    // 004b1b25  3c66                   +cmp al, 0x66
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(102 /*0x66*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1b27  0f8294000000           -jb 0x4b1bc1
    if (cpu.flags.cf)
    {
        goto L_0x004b1bc1;
    }
    // 004b1b2d  765d                   -jbe 0x4b1b8c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1b8c;
    }
    // 004b1b2f  3c67                   +cmp al, 0x67
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(103 /*0x67*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1b31  0f868a000000           -jbe 0x4b1bc1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1bc1;
    }
    // 004b1b37  3c69                   +cmp al, 0x69
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(105 /*0x69*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1b39  0f849a010000           -je 0x4b1cd9
    if (cpu.flags.zf)
    {
        goto L_0x004b1cd9;
    }
    // 004b1b3f  e963030000             -jmp 0x4b1ea7
    goto L_0x004b1ea7;
L_0x004b1b44:
    // 004b1b44  3c47                   +cmp al, 0x47
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(71 /*0x47*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1b46  722f                   -jb 0x4b1b77
    if (cpu.flags.cf)
    {
        goto L_0x004b1b77;
    }
    // 004b1b48  0f8673000000           -jbe 0x4b1bc1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1bc1;
    }
    // 004b1b4e  3c53                   +cmp al, 0x53
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1b50  7221                   -jb 0x4b1b73
    if (cpu.flags.cf)
    {
        goto L_0x004b1b73;
    }
    // 004b1b52  0f8685000000           -jbe 0x4b1bdd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1bdd;
    }
    // 004b1b58  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1b5a  0f8247030000           -jb 0x4b1ea7
    if (cpu.flags.cf)
    {
        goto L_0x004b1ea7;
    }
    // 004b1b60  0f8610010000           -jbe 0x4b1c76
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1c76;
    }
    // 004b1b66  3c63                   +cmp al, 0x63
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(99 /*0x63*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1b68  0f849d020000           -je 0x4b1e0b
    if (cpu.flags.zf)
    {
        goto L_0x004b1e0b;
    }
    // 004b1b6e  e934030000             -jmp 0x4b1ea7
    goto L_0x004b1ea7;
L_0x004b1b73:
    // 004b1b73  3c50                   +cmp al, 0x50
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1b75  eba3                   -jmp 0x4b1b1a
    goto L_0x004b1b1a;
L_0x004b1b77:
    // 004b1b77  3c45                   +cmp al, 0x45
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(69 /*0x45*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1b79  7204                   -jb 0x4b1b7f
    if (cpu.flags.cf)
    {
        goto L_0x004b1b7f;
    }
    // 004b1b7b  7644                   -jbe 0x4b1bc1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b1bc1;
    }
    // 004b1b7d  eb0d                   -jmp 0x4b1b8c
    goto L_0x004b1b8c;
L_0x004b1b7f:
    // 004b1b7f  3c43                   +cmp al, 0x43
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(67 /*0x43*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1b81  0f84f4020000           -je 0x4b1e7b
    if (cpu.flags.zf)
    {
        goto L_0x004b1e7b;
    }
    // 004b1b87  e91b030000             -jmp 0x4b1ea7
    goto L_0x004b1ea7;
L_0x004b1b8c:
    // 004b1b8c  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 004b1b90  742f                   -je 0x4b1bc1
    if (cpu.flags.zf)
    {
        goto L_0x004b1bc1;
    }
    // 004b1b92  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b1b94  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b1b97  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b1b99  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004b1b9c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b1ba0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b1ba2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b1ba4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1ba6  e802fcffff             -call 0x4b17ad
    cpu.esp -= 4;
    sub_4b17ad(app, cpu);
    if (cpu.terminate) return;
    // 004b1bab  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004b1bb0  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b1bb2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1bb4  e809fbffff             -call 0x4b16c2
    cpu.esp -= 4;
    sub_4b16c2(app, cpu);
    if (cpu.terminate) return;
    // 004b1bb9  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b1bbc  e9f9020000             -jmp 0x4b1eba
    goto L_0x004b1eba;
L_0x004b1bc1:
    // 004b1bc1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b1bc3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1bc5  e8befcffff             -call 0x4b1888
    cpu.esp -= 4;
    sub_4b1888(app, cpu);
    if (cpu.terminate) return;
    // 004b1bca  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b1bcc  e8befcffff             -call 0x4b188f
    cpu.esp -= 4;
    sub_4b188f(app, cpu);
    if (cpu.terminate) return;
    // 004b1bd1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b1bd3  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b1bd6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b1bd8  e9dd020000             -jmp 0x4b1eba
    goto L_0x004b1eba;
L_0x004b1bdd:
    // 004b1bdd  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 004b1be0  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b1be3  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004b1be5  741d                   -je 0x4b1c04
    if (cpu.flags.zf)
    {
        goto L_0x004b1c04;
    }
    // 004b1be7  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004b1be9  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b1bec  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004b1bee  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004b1bf1  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b1bf5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b1bf7  7505                   -jne 0x4b1bfe
    if (!cpu.flags.zf)
    {
        goto L_0x004b1bfe;
    }
    // 004b1bf9  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004b1bfc  742e                   -je 0x4b1c2c
    if (cpu.flags.zf)
    {
        goto L_0x004b1c2c;
    }
L_0x004b1bfe:
    // 004b1bfe  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b1c00  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b1c02  eb28                   -jmp 0x4b1c2c
    goto L_0x004b1c2c;
L_0x004b1c04:
    // 004b1c04  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004b1c06  7410                   -je 0x4b1c18
    if (cpu.flags.zf)
    {
        goto L_0x004b1c18;
    }
    // 004b1c08  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004b1c0a  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1c0d  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004b1c0f  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 004b1c12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b1c14  7416                   -je 0x4b1c2c
    if (cpu.flags.zf)
    {
        goto L_0x004b1c2c;
    }
    // 004b1c16  eb0e                   -jmp 0x4b1c26
    goto L_0x004b1c26;
L_0x004b1c18:
    // 004b1c18  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b1c1a  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1c1d  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b1c1f  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004b1c22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b1c24  7406                   -je 0x4b1c2c
    if (cpu.flags.zf)
    {
        goto L_0x004b1c2c;
    }
L_0x004b1c26:
    // 004b1c26  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b1c28  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b1c2a  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
L_0x004b1c2c:
    // 004b1c2c  80791553               +cmp byte ptr [ecx + 0x15], 0x53
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1c30  7514                   -jne 0x4b1c46
    if (!cpu.flags.zf)
    {
        goto L_0x004b1c46;
    }
    // 004b1c32  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 004b1c36  7514                   -jne 0x4b1c4c
    if (!cpu.flags.zf)
    {
        goto L_0x004b1c4c;
    }
L_0x004b1c38:
    // 004b1c38  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004b1c3a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b1c3c  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b1c3f  e8a2faffff             -call 0x4b16e6
    cpu.esp -= 4;
    sub_4b16e6(app, cpu);
    if (cpu.terminate) return;
    // 004b1c44  eb12                   -jmp 0x4b1c58
    goto L_0x004b1c58;
L_0x004b1c46:
    // 004b1c46  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 004b1c4a  75ec                   -jne 0x4b1c38
    if (!cpu.flags.zf)
    {
        goto L_0x004b1c38;
    }
L_0x004b1c4c:
    // 004b1c4c  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004b1c4e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b1c50  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b1c53  e86afaffff             -call 0x4b16c2
    cpu.esp -= 4;
    sub_4b16c2(app, cpu);
    if (cpu.terminate) return;
L_0x004b1c58:
    // 004b1c58  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b1c5b  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b1c5e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b1c60  0f8c54020000           -jl 0x4b1eba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1eba;
    }
    // 004b1c66  39d0                   +cmp eax, edx
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
    // 004b1c68  0f8e4c020000           -jle 0x4b1eba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b1eba;
    }
    // 004b1c6e  895128                 -mov dword ptr [ecx + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004b1c71  e944020000             -jmp 0x4b1eba
    goto L_0x004b1eba;
L_0x004b1c76:
    // 004b1c76  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 004b1c7a  7438                   -je 0x4b1cb4
    if (cpu.flags.zf)
    {
        goto L_0x004b1cb4;
    }
    // 004b1c7c  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 004b1c80  740f                   -je 0x4b1c91
    if (cpu.flags.zf)
    {
        goto L_0x004b1c91;
    }
    // 004b1c82  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1c86  7510                   -jne 0x4b1c98
    if (!cpu.flags.zf)
    {
        goto L_0x004b1c98;
    }
    // 004b1c88  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1c8d  7425                   -je 0x4b1cb4
    if (cpu.flags.zf)
    {
        goto L_0x004b1cb4;
    }
    // 004b1c8f  eb07                   -jmp 0x4b1c98
    goto L_0x004b1c98;
L_0x004b1c91:
    // 004b1c91  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004b1c96  741c                   -je 0x4b1cb4
    if (cpu.flags.zf)
    {
        goto L_0x004b1cb4;
    }
L_0x004b1c98:
    // 004b1c98  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b1c9b  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b1c9e  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b1ca1  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
    // 004b1ca5  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b1ca8  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b1cab  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b1cae  8a5115                 -mov dl, byte ptr [ecx + 0x15]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004b1cb1  881406                 -mov byte ptr [esi + eax], dl
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = cpu.dl;
L_0x004b1cb4:
    // 004b1cb4  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004b1cb9:
    // 004b1cb9  8079156f               +cmp byte ptr [ecx + 0x15], 0x6f
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1cbd  751a                   -jne 0x4b1cd9
    if (!cpu.flags.zf)
    {
        goto L_0x004b1cd9;
    }
    // 004b1cbf  8a511e                 -mov dl, byte ptr [ecx + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b1cc2  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004b1cc7  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004b1cca  740d                   -je 0x4b1cd9
    if (cpu.flags.zf)
    {
        goto L_0x004b1cd9;
    }
    // 004b1ccc  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b1ccf  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b1cd2  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b1cd5  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
L_0x004b1cd9:
    // 004b1cd9  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b1cdb  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b1cde  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b1ce0  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b1ce2  8a711f                 -mov dh, byte ptr [ecx + 0x1f]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 004b1ce5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b1ce7  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 004b1cea  7436                   -je 0x4b1d22
    if (cpu.flags.zf)
    {
        goto L_0x004b1d22;
    }
    // 004b1cec  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1cf0  7515                   -jne 0x4b1d07
    if (!cpu.flags.zf)
    {
        goto L_0x004b1d07;
    }
    // 004b1cf2  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1cf6  750f                   -jne 0x4b1d07
    if (!cpu.flags.zf)
    {
        goto L_0x004b1d07;
    }
    // 004b1cf8  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1cfd  7508                   -jne 0x4b1d07
    if (!cpu.flags.zf)
    {
        goto L_0x004b1d07;
    }
L_0x004b1cff:
    // 004b1cff  26c60000               -mov byte ptr es:[eax], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 004b1d03  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b1d05  eb51                   -jmp 0x4b1d58
    goto L_0x004b1d58;
L_0x004b1d07:
    // 004b1d07  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b1d0a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b1d0c  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b1d0e  e8e67e0000             -call 0x4b9bf9
    cpu.esp -= 4;
    sub_4b9bf9(app, cpu);
    if (cpu.terminate) return;
    // 004b1d13  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1d17  7531                   -jne 0x4b1d4a
    if (!cpu.flags.zf)
    {
        goto L_0x004b1d4a;
    }
    // 004b1d19  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1d1b  e8a6010000             -call 0x4b1ec6
    cpu.esp -= 4;
    sub_4b1ec6(app, cpu);
    if (cpu.terminate) return;
    // 004b1d20  eb28                   -jmp 0x4b1d4a
    goto L_0x004b1d4a;
L_0x004b1d22:
    // 004b1d22  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1d26  7507                   -jne 0x4b1d2f
    if (!cpu.flags.zf)
    {
        goto L_0x004b1d2f;
    }
    // 004b1d28  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004b1d2d  74d0                   -je 0x4b1cff
    if (cpu.flags.zf)
    {
        goto L_0x004b1cff;
    }
L_0x004b1d2f:
    // 004b1d2f  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b1d32  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b1d36  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b1d38  e8a97f0000             -call 0x4b9ce6
    cpu.esp -= 4;
    sub_4b9ce6(app, cpu);
    if (cpu.terminate) return;
    // 004b1d3d  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1d41  7507                   -jne 0x4b1d4a
    if (!cpu.flags.zf)
    {
        goto L_0x004b1d4a;
    }
    // 004b1d43  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1d45  e87c010000             -call 0x4b1ec6
    cpu.esp -= 4;
    sub_4b1ec6(app, cpu);
    if (cpu.terminate) return;
L_0x004b1d4a:
    // 004b1d4a  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004b1d4f  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004b1d51  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b1d53  e86af9ffff             -call 0x4b16c2
    cpu.esp -= 4;
    sub_4b16c2(app, cpu);
    if (cpu.terminate) return;
L_0x004b1d58:
    // 004b1d58  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b1d5b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b1d5d  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b1d60  39c2                   +cmp edx, eax
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
    // 004b1d62  7d05                   -jge 0x4b1d69
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1d69;
    }
    // 004b1d64  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1d66  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004b1d69:
    // 004b1d69  837908ff               +cmp dword ptr [ecx + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1d6d  0f8547010000           -jne 0x4b1eba
    if (!cpu.flags.zf)
    {
        goto L_0x004b1eba;
    }
    // 004b1d73  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b1d75  e815fbffff             -call 0x4b188f
    cpu.esp -= 4;
    sub_4b188f(app, cpu);
    if (cpu.terminate) return;
    // 004b1d7a  e93b010000             -jmp 0x4b1eba
    goto L_0x004b1eba;
L_0x004b1d7f:
    // 004b1d7f  83790400               +cmp dword ptr [ecx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1d83  7516                   -jne 0x4b1d9b
    if (!cpu.flags.zf)
    {
        goto L_0x004b1d9b;
    }
    // 004b1d85  f6411e80               +test byte ptr [ecx + 0x1e], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 128 /*0x80*/));
    // 004b1d89  7409                   -je 0x4b1d94
    if (cpu.flags.zf)
    {
        goto L_0x004b1d94;
    }
    // 004b1d8b  c741040d000000         -mov dword ptr [ecx + 4], 0xd
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 13 /*0xd*/;
    // 004b1d92  eb07                   -jmp 0x4b1d9b
    goto L_0x004b1d9b;
L_0x004b1d94:
    // 004b1d94  c7410408000000         -mov dword ptr [ecx + 4], 8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
L_0x004b1d9b:
    // 004b1d9b  80611ef9               -and byte ptr [ecx + 0x1e], 0xf9
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 004b1d9f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b1da1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1da4  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b1da6  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b1da9  8b68fc                 -mov ebp, dword ptr [eax - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b1dac  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 004b1daf  7429                   -je 0x4b1dda
    if (cpu.flags.zf)
    {
        goto L_0x004b1dda;
    }
    // 004b1db1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1db4  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b1db6  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004b1dbb  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b1dbe  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b1dc0  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 004b1dc5  e885f9ffff             -call 0x4b174f
    cpu.esp -= 4;
    sub_4b174f(app, cpu);
    if (cpu.terminate) return;
    // 004b1dca  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004b1dcf  8d5605                 -lea edx, [esi + 5]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 004b1dd2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b1dd4  c646043a               -mov byte ptr [esi + 4], 0x3a
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 58 /*0x3a*/;
    // 004b1dd8  eb09                   -jmp 0x4b1de3
    goto L_0x004b1de3;
L_0x004b1dda:
    // 004b1dda  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004b1ddf  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b1de1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004b1de3:
    // 004b1de3  e867f9ffff             -call 0x4b174f
    cpu.esp -= 4;
    sub_4b174f(app, cpu);
    if (cpu.terminate) return;
    // 004b1de8  80791550               +cmp byte ptr [ecx + 0x15], 0x50
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1dec  7507                   -jne 0x4b1df5
    if (!cpu.flags.zf)
    {
        goto L_0x004b1df5;
    }
    // 004b1dee  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1df0  e8d1000000             -call 0x4b1ec6
    cpu.esp -= 4;
    sub_4b1ec6(app, cpu);
    if (cpu.terminate) return;
L_0x004b1df5:
    // 004b1df5  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004b1dfa  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004b1dfc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b1dfe  e8bff8ffff             -call 0x4b16c2
    cpu.esp -= 4;
    sub_4b16c2(app, cpu);
    if (cpu.terminate) return;
L_0x004b1e03:
    // 004b1e03  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004b1e06  e9af000000             -jmp 0x4b1eba
    goto L_0x004b1eba;
L_0x004b1e0b:
    // 004b1e0b  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b1e0e  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 004b1e15  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004b1e18  7453                   -je 0x4b1e6d
    if (cpu.flags.zf)
    {
        goto L_0x004b1e6d;
    }
    // 004b1e1a  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004b1e1c  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1e1f  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b1e21  668b43fc               -mov ax, word ptr [ebx - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 004b1e25  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b1e27  6689c2                 -mov dx, ax
    cpu.dx = cpu.ax;
    // 004b1e2a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b1e2e  e82d7d0000             -call 0x4b9b60
    cpu.esp -= 4;
    sub_4b9b60(app, cpu);
    if (cpu.terminate) return;
    // 004b1e33  83f8ff                 +cmp eax, -1
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
    // 004b1e36  0f847e000000           -je 0x4b1eba
    if (cpu.flags.zf)
    {
        goto L_0x004b1eba;
    }
    // 004b1e3c  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b1e40  8b2d90805b00           -mov ebp, dword ptr [0x5b8090]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5996688) /* 0x5b8090 */);
    // 004b1e46  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b1e48  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b1e4a  746e                   -je 0x4b1eba
    if (cpu.flags.zf)
    {
        goto L_0x004b1eba;
    }
    // 004b1e4c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b1e4e  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b1e52  8a8095805b00           -mov al, byte ptr [eax + 0x5b8095]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5996693) /* 0x5b8095 */);
    // 004b1e58  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b1e5a  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b1e5f  7459                   -je 0x4b1eba
    if (cpu.flags.zf)
    {
        goto L_0x004b1eba;
    }
    // 004b1e61  8a44240d               -mov al, byte ptr [esp + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */);
    // 004b1e65  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004b1e68  ff4120                 +inc dword ptr [ecx + 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b1e6b  eb4d                   -jmp 0x4b1eba
    goto L_0x004b1eba;
L_0x004b1e6d:
    // 004b1e6d  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b1e6f  83c004                 +add eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b1e72  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b1e74  8a40fc                 -mov al, byte ptr [eax - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b1e77  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b1e79  eb3f                   -jmp 0x4b1eba
    goto L_0x004b1eba;
L_0x004b1e7b:
    // 004b1e7b  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004b1e7d  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b1e80  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 004b1e82  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b1e86  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b1e8c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b1e8e  e8cd7c0000             -call 0x4b9b60
    cpu.esp -= 4;
    sub_4b9b60(app, cpu);
    if (cpu.terminate) return;
    // 004b1e93  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b1e95  83f8ff                 +cmp eax, -1
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
    // 004b1e98  0f8565ffffff           -jne 0x4b1e03
    if (!cpu.flags.zf)
    {
        goto L_0x004b1e03;
    }
    // 004b1e9e  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004b1ea5  eb13                   -jmp 0x4b1eba
    goto L_0x004b1eba;
L_0x004b1ea7:
    // 004b1ea7  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b1eae  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004b1eb1  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b1eb3  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
L_0x004b1eba:
    // 004b1eba  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 004b1ebc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b1ebe  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b1ec1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1ec2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b1ec3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1ec4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1ec5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b1ec6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b1ec6);
    // 004b1ec6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b1ec7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004b1ec9:
    // 004b1ec9  803a00                 +cmp byte ptr [edx], 0
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
    // 004b1ecc  740e                   -je 0x4b1edc
    if (cpu.flags.zf)
    {
        goto L_0x004b1edc;
    }
    // 004b1ece  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b1ed0  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b1ed2  e8bb2afdff             -call 0x484992
    cpu.esp -= 4;
    sub_484992(app, cpu);
    if (cpu.terminate) return;
    // 004b1ed7  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004b1ed9  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b1eda  ebed                   -jmp 0x4b1ec9
    goto L_0x004b1ec9;
L_0x004b1edc:
    // 004b1edc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1edd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b1ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b1ee0);
    // 004b1ee0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b1ee1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b1ee3  3d00000100             +cmp eax, 0x10000
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
    // 004b1ee8  7f1b                   -jg 0x4b1f05
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b1f05;
    }
    // 004b1eea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b1eec  7c1e                   -jl 0x4b1f0c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1f0c;
    }
L_0x004b1eee:
    // 004b1eee  e8f145fdff             -call 0x4864e4
    cpu.esp -= 4;
    sub_4864e4(app, cpu);
    if (cpu.terminate) return;
    // 004b1ef3  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
    // 004b1ef8  2d00400000             -sub eax, 0x4000
    (cpu.eax) -= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 004b1efd  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b1f00  c1f80e                 +sar eax, 0xe
    {
        x86::reg8 tmp = 14 /*0xe*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004b1f03  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1f04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1f05:
    // 004b1f05  ba00000100             -mov edx, 0x10000
    cpu.edx = 65536 /*0x10000*/;
    // 004b1f0a  ebe2                   -jmp 0x4b1eee
    goto L_0x004b1eee;
L_0x004b1f0c:
    // 004b1f0c  31c2                   +xor edx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b1f0e  ebde                   -jmp 0x4b1eee
    goto L_0x004b1eee;
}

/* align: skip  */
void Application::sub_4b1f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b1f10);
    // 004b1f10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b1f12(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b1f12);
    // 004b1f12  6650                   -push ax
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ax;
    cpu.esp -= 4;
    // 004b1f14  9b                     -wait 
    /*nothing*/;
    // 004b1f15  dbe3                   +fninit 
    cpu.fpu.init();
    // 004b1f17  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 004b1f19  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004b1f1b  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b1f1d  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b1f1f  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004b1f21  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004b1f23  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004b1f25  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 004b1f27  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004b1f28  7402                   -je 0x4b1f2c
    if (cpu.flags.zf)
    {
        goto L_0x004b1f2c;
    }
    // 004b1f2a  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
L_0x004b1f2c:
    // 004b1f2c  9b                     -wait 
    /*nothing*/;
    // 004b1f2d  dbe3                   -fninit 
    cpu.fpu.init();
    // 004b1f2f  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b1f32  66870424               -xchg word ptr [esp], ax
    {
        x86::reg16 tmp = app->getMemory<x86::reg16>(cpu.esp);
        app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
        cpu.ax = tmp;
    }
    // 004b1f36  6658                   -pop ax
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b1f38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b1f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b1f40);
    // 004b1f40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b1f41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b1f42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b1f43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b1f44  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b1f47  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b1f49  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b1f4b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b1f4d  3b0568904d00           +cmp eax, dword ptr [0x4d9068]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1f53  7c49                   -jl 0x4b1f9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1f9e;
    }
    // 004b1f55  3b0570904d00           +cmp eax, dword ptr [0x4d9070]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1f5b  7d41                   -jge 0x4b1f9e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1f9e;
    }
    // 004b1f5d  3b356c904d00           +cmp esi, dword ptr [0x4d906c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1f63  7c39                   -jl 0x4b1f9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b1f9e;
    }
    // 004b1f65  3b3574904d00           +cmp esi, dword ptr [0x4d9074]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1f6b  7d31                   -jge 0x4b1f9e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b1f9e;
    }
    // 004b1f6d  803d78904d0010         +cmp byte ptr [0x4d9078], 0x10
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
    // 004b1f74  7509                   -jne 0x4b1f7f
    if (!cpu.flags.zf)
    {
        goto L_0x004b1f7f;
    }
    // 004b1f76  803d7a904d0000         +cmp byte ptr [0x4d907a], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083258) /* 0x4d907a */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b1f7d  7427                   -je 0x4b1fa6
    if (cpu.flags.zf)
    {
        goto L_0x004b1fa6;
    }
L_0x004b1f7f:
    // 004b1f7f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b1f81  c1eb18                 -shr ebx, 0x18
    cpu.ebx >>= 24 /*0x18*/ % 32;
    // 004b1f84  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b1f8a  81fbff000000           +cmp ebx, 0xff
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
    // 004b1f90  0f84ae000000           -je 0x4b2044
    if (cpu.flags.zf)
    {
        goto L_0x004b2044;
    }
    // 004b1f96  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b1f98  0f85c0000000           -jne 0x4b205e
    if (!cpu.flags.zf)
    {
        goto L_0x004b205e;
    }
L_0x004b1f9e:
    // 004b1f9e  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b1fa1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1fa2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1fa3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1fa4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b1fa5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b1fa6:
    // 004b1fa6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b1fa8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b1faa  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 004b1fb0  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004b1fb3  8b1588904d00           -mov edx, dword ptr [0x4d9088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 004b1fb9  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004b1fbc  03057c904d00           -add eax, dword ptr [0x4d907c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004b1fc2  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b1fc4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b1fc6  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1fcc  726b                   -jb 0x4b2039
    if (cpu.flags.cf)
    {
        goto L_0x004b2039;
    }
    // 004b1fce  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b1fd4  7340                   -jae 0x4b2016
    if (!cpu.flags.cf)
    {
        goto L_0x004b2016;
    }
    // 004b1fd6  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004b1fd9  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b1fdb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b1fdd  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004b1fe0  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b1fe3  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004b1fe5  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004b1feb  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b1fee  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004b1ff3  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004b1ff6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b1ff8  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004b1ffa  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b1ffd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b1fff  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004b2002  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b2004  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004b2007  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b200d  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004b2012  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2014  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004b2016:
    // 004b2016  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2018  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004b201e  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004b2021  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2023  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b2026  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004b202c  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004b202f  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004b2032  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b2034  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b2036  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004b2039:
    // 004b2039  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004b203c  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b203f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2040  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2041  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2042  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2043  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2044:
    // 004b2044  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b2046  e891eafcff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 004b204b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b204d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b204f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b2051  e8da73ffff             -call 0x4a9430
    cpu.esp -= 4;
    sub_4a9430(app, cpu);
    if (cpu.terminate) return;
    // 004b2056  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b2059  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b205a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b205b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b205c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b205d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b205e:
    // 004b205e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b2060  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b2063  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b2068  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b206b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b206d  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004b2070  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b2076  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b207b  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b207f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b2083  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b2085  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 004b208a  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b208d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b208f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b2091  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b2093  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b2095  e8a603ffff             -call 0x4a2440
    cpu.esp -= 4;
    sub_4a2440(app, cpu);
    if (cpu.terminate) return;
    // 004b209a  e88141feff             -call 0x496220
    cpu.esp -= 4;
    sub_496220(app, cpu);
    if (cpu.terminate) return;
    // 004b209f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b20a1  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b20a4  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b20aa  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b20ae  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b20b0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b20b2  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004b20b5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b20ba  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b20c0  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b20c4  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004b20c8  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004b20cd  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004b20d2  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b20d4  2b442414               -sub eax, dword ptr [esp + 0x14]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004b20d8  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004b20db  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 004b20e0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b20e2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b20e5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b20e7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b20e9  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 004b20ec  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b20ee  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b20f4  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b20f8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b20fa  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b20fc  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b20fe  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b2101  c1e810                 +shr eax, 0x10
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
    // 004b2104  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b2106  030424                 -add eax, dword ptr [esp]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004b2109  39d8                   +cmp eax, ebx
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
    // 004b210b  0f8e77000000           -jle 0x4b2188
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2188;
    }
    // 004b2111  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004b2113:
    // 004b2113  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2115  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b2117  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b211b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b211f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b2121  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b2124  c1e810                 +shr eax, 0x10
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
    // 004b2127  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b2129  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b212b  3dff000000             +cmp eax, 0xff
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
    // 004b2130  7e6e                   -jle 0x4b21a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b21a0;
    }
    // 004b2132  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004b2137:
    // 004b2137  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b2139  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b213b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b213f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b2141  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b2144  c1e810                 +shr eax, 0x10
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
    // 004b2147  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b2149  03442404               -add eax, dword ptr [esp + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b214d  3dff000000             +cmp eax, 0xff
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
    // 004b2152  7e60                   -jle 0x4b21b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b21b4;
    }
    // 004b2154  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004b2159:
    // 004b2159  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b215d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b215f  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 004b2162  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004b2165  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2167  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004b2169  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004b216c  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b216e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2170  e867e9fcff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 004b2175  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2177  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b2179  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b217b  e8b072ffff             -call 0x4a9430
    cpu.esp -= 4;
    sub_4a9430(app, cpu);
    if (cpu.terminate) return;
    // 004b2180  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b2183  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2184  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2185  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2186  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2187  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2188:
    // 004b2188  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b218a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b218c  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b218f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b2191  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b2194  c1e810                 +shr eax, 0x10
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
    // 004b2197  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b2199  01d8                   +add eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b219b  e973ffffff             -jmp 0x4b2113
    goto L_0x004b2113;
L_0x004b21a0:
    // 004b21a0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b21a4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b21a6  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b21a8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b21ab  c1e810                 +shr eax, 0x10
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
    // 004b21ae  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b21b0  01e8                   +add eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b21b2  eb83                   -jmp 0x4b2137
    goto L_0x004b2137;
L_0x004b21b4:
    // 004b21b4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b21b8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b21ba  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b21be  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b21c0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b21c3  c1e810                 +shr eax, 0x10
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
    // 004b21c6  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b21c8  01c8                   +add eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b21ca  eb8d                   -jmp 0x4b2159
    goto L_0x004b2159;
}

/* align: skip  */
void Application::sub_4b21cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b21cc);
    // 004b21cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b21cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b21ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b21cf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b21d0  837c242400             +cmp dword ptr [esp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b21d5  0f8efb000000           -jle 0x4b22d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b22d6;
    }
    // 004b21db  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b21dd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b21df  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b21e3  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b21e7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b21eb  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b21ef  83f901                 +cmp ecx, 1
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
    // 004b21f2  0f8cde000000           -jl 0x4b22d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b22d6;
    }
    // 004b21f8  d1e9                   +shr ecx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004b21fa  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004b21fe  7259                   -jb 0x4b2259
    if (cpu.flags.cf)
    {
        goto L_0x004b2259;
    }
L_0x004b2200:
    // 004b2200  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x004b2204:
    // 004b2204  8a7e01                 -mov bh, byte ptr [esi + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b2207  8a7601                 -mov dh, byte ptr [esi + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b220a  8a5f02                 -mov bl, byte ptr [edi + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004b220d  8a5703                 -mov dl, byte ptr [edi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 004b2210  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004b2213  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b2216  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004b221a  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004b221e  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b2221  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 004b2223  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 004b2225  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004b2227  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b222a  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004b222d  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b2230  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004b2234  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004b2238  83e901                 +sub ecx, 1
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
    // 004b223b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b223d  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004b2240  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004b2243  7fbf                   -jg 0x4b2204
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b2204;
    }
    // 004b2245  03742428               -add esi, dword ptr [esp + 0x28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b2249  037c242c               -add edi, dword ptr [esp + 0x2c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b224d  836c242401             +sub dword ptr [esp + 0x24], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b2252  75ac                   -jne 0x4b2200
    if (!cpu.flags.zf)
    {
        goto L_0x004b2200;
    }
    // 004b2254  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2255  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2256  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2257  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2258  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2259:
    // 004b2259  8344242801             -add dword ptr [esp + 0x28], 1
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004b225e  8344242c02             -add dword ptr [esp + 0x2c], 2
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004b2263:
    // 004b2263  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b2267  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b226a  7441                   -je 0x4b22ad
    if (cpu.flags.zf)
    {
        goto L_0x004b22ad;
    }
L_0x004b226c:
    // 004b226c  8a7e01                 -mov bh, byte ptr [esi + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b226f  8a7601                 -mov dh, byte ptr [esi + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b2272  8a5f02                 -mov bl, byte ptr [edi + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004b2275  8a5703                 -mov dl, byte ptr [edi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 004b2278  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004b227b  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b227e  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004b2282  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004b2286  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b2289  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 004b228b  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 004b228d  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004b228f  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b2292  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004b2295  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b2298  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004b229c  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004b22a0  83e901                 +sub ecx, 1
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
    // 004b22a3  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b22a5  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004b22a8  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004b22ab  7fbf                   -jg 0x4b226c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b226c;
    }
L_0x004b22ad:
    // 004b22ad  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 004b22af  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004b22b1  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b22b4  88fe                   -mov dh, bh
    cpu.dh = cpu.bh;
    // 004b22b6  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 004b22b9  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b22bc  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 004b22c0  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 004b22c4  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004b22c7  03742428               -add esi, dword ptr [esp + 0x28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004b22cb  037c242c               -add edi, dword ptr [esp + 0x2c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 004b22cf  836c242401             +sub dword ptr [esp + 0x24], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b22d4  758d                   -jne 0x4b2263
    if (!cpu.flags.zf)
    {
        goto L_0x004b2263;
    }
L_0x004b22d6:
    // 004b22d6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b22d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b22d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b22d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b22da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b22e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b22e0);
    // 004b22e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b22e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b22e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b22e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b22e4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b22e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b22e8  0f849a000000           -je 0x4b2388
    if (cpu.flags.zf)
    {
        goto L_0x004b2388;
    }
    // 004b22ee  8d480b                 -lea ecx, [eax + 0xb]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 004b22f1  39c1                   +cmp ecx, eax
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b22f3  0f828f000000           -jb 0x4b2388
    if (cpu.flags.cf)
    {
        goto L_0x004b2388;
    }
    // 004b22f9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004b22fb  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004b22fe  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004b2301  83f910                 +cmp ecx, 0x10
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2304  7305                   -jae 0x4b230b
    if (!cpu.flags.cf)
    {
        goto L_0x004b230b;
    }
    // 004b2306  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x004b230b:
    // 004b230b  39c1                   +cmp ecx, eax
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b230d  0f8775000000           -ja 0x4b2388
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b2388;
    }
    // 004b2313  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004b2316  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004b2319  39d9                   +cmp ecx, ebx
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
    // 004b231b  7705                   -ja 0x4b2322
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b2322;
    }
    // 004b231d  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 004b2320  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b2322:
    // 004b2322  8d7720                 -lea esi, [edi + 0x20]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x004b2325:
    // 004b2325  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b2327  39d1                   +cmp ecx, edx
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
    // 004b2329  7612                   -jbe 0x4b233d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b233d;
    }
    // 004b232b  39da                   +cmp edx, ebx
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
    // 004b232d  7602                   -jbe 0x4b2331
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b2331;
    }
    // 004b232f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x004b2331:
    // 004b2331  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b2334  39f0                   +cmp eax, esi
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
    // 004b2336  75ed                   -jne 0x4b2325
    if (!cpu.flags.zf)
    {
        goto L_0x004b2325;
    }
    // 004b2338  895f14                 -mov dword ptr [edi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004b233b  eb4b                   -jmp 0x4b2388
    goto L_0x004b2388;
L_0x004b233d:
    // 004b233d  895f10                 -mov dword ptr [edi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004b2340  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004b2343  43                     -inc ebx
    (cpu.ebx)++;
    // 004b2344  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2346  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004b2349  83fa10                 +cmp edx, 0x10
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b234c  721e                   -jb 0x4b236c
    if (cpu.flags.cf)
    {
        goto L_0x004b236c;
    }
    // 004b234e  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 004b2351  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b2354  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b2356  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004b2358  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b235b  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b235e  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b2361  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b2364  895908                 -mov dword ptr [ecx + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b2367  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b236a  eb12                   -jmp 0x4b237e
    goto L_0x004b237e;
L_0x004b236c:
    // 004b236c  ff4f1c                 -dec dword ptr [edi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))--;
    // 004b236f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b2372  89570c                 -mov dword ptr [edi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004b2375  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b2378  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b237b  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004b237e:
    // 004b237e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2380  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b2383  8d6804                 -lea ebp, [eax + 4]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b2386  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x004b2388:
    // 004b2388  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b238a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b238b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b238c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b238d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b238e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b2390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2390);
    // 004b2390  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2391  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2392  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2393  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2394  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b2396  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2398  0f841d010000           -je 0x4b24bb
    if (cpu.flags.zf)
    {
        goto L_0x004b24bb;
    }
    // 004b239e  8d58fc                 -lea ebx, [eax - 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b23a1  f60301                 +test byte ptr [ebx], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx) & 1 /*0x1*/));
    // 004b23a4  0f8411010000           -je 0x4b24bb
    if (cpu.flags.zf)
    {
        goto L_0x004b24bb;
    }
    // 004b23aa  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b23ac  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004b23af  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 004b23b2  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004b23b4  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 004b23b7  7522                   -jne 0x4b23db
    if (!cpu.flags.zf)
    {
        goto L_0x004b23db;
    }
    // 004b23b9  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004b23bb  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b23bd  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b23bf  3b410c                 +cmp eax, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b23c2  7503                   -jne 0x4b23c7
    if (!cpu.flags.zf)
    {
        goto L_0x004b23c7;
    }
    // 004b23c4  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004b23c7:
    // 004b23c7  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b23ca  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b23cd  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b23d0  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b23d3  ff4e1c                 +dec dword ptr [esi + 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b23d6  e994000000             -jmp 0x4b246f
    goto L_0x004b246f;
L_0x004b23db:
    // 004b23db  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b23dd  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b23e0  39c3                   +cmp ebx, eax
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
    // 004b23e2  7316                   -jae 0x4b23fa
    if (!cpu.flags.cf)
    {
        goto L_0x004b23fa;
    }
    // 004b23e4  3b5804                 +cmp ebx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b23e7  0f8782000000           -ja 0x4b246f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b246f;
    }
    // 004b23ed  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004b23f0  39c3                   +cmp ebx, eax
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
    // 004b23f2  0f8277000000           -jb 0x4b246f
    if (cpu.flags.cf)
    {
        goto L_0x004b246f;
    }
    // 004b23f8  eb19                   -jmp 0x4b2413
    goto L_0x004b2413;
L_0x004b23fa:
    // 004b23fa  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b23fd  39c3                   +cmp ebx, eax
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
    // 004b23ff  0f826a000000           -jb 0x4b246f
    if (cpu.flags.cf)
    {
        goto L_0x004b246f;
    }
    // 004b2405  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b2408  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b240b  39d3                   +cmp ebx, edx
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
    // 004b240d  0f875c000000           -ja 0x4b246f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b246f;
    }
L_0x004b2413:
    // 004b2413  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004b2416  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004b2419  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b241b  8d4f01                 -lea ecx, [edi + 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b241e  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b2420  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b2422  39f8                   +cmp eax, edi
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
    // 004b2424  7328                   -jae 0x4b244e
    if (!cpu.flags.cf)
    {
        goto L_0x004b244e;
    }
    // 004b2426  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004b2429  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004b242b  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b242d  39f8                   +cmp eax, edi
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
    // 004b242f  7705                   -ja 0x4b2436
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b2436;
    }
    // 004b2431  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
L_0x004b2436:
    // 004b2436  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b2438  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b243a:
    // 004b243a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b243c  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004b243f  742e                   -je 0x4b246f
    if (cpu.flags.zf)
    {
        goto L_0x004b246f;
    }
    // 004b2441  83faff                 +cmp edx, -1
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
    // 004b2444  7408                   -je 0x4b244e
    if (cpu.flags.zf)
    {
        goto L_0x004b244e;
    }
    // 004b2446  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004b2449  01d0                   +add eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b244b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b244c  75ec                   -jne 0x4b243a
    if (!cpu.flags.zf)
    {
        goto L_0x004b243a;
    }
L_0x004b244e:
    // 004b244e  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b2451  39c3                   +cmp ebx, eax
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
    // 004b2453  7303                   -jae 0x4b2458
    if (!cpu.flags.cf)
    {
        goto L_0x004b2458;
    }
    // 004b2455  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
L_0x004b2458:
    // 004b2458  39c3                   +cmp ebx, eax
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
    // 004b245a  7213                   -jb 0x4b246f
    if (cpu.flags.cf)
    {
        goto L_0x004b246f;
    }
    // 004b245c  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b245f  39c3                   +cmp ebx, eax
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
    // 004b2461  720c                   -jb 0x4b246f
    if (cpu.flags.cf)
    {
        goto L_0x004b246f;
    }
    // 004b2463  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b2466  39c3                   +cmp ebx, eax
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
    // 004b2468  7205                   -jb 0x4b246f
    if (cpu.flags.cf)
    {
        goto L_0x004b246f;
    }
    // 004b246a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b246d  ebe9                   -jmp 0x4b2458
    goto L_0x004b2458;
L_0x004b246f:
    // 004b246f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b2472  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004b2474  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b2476  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b2478  39df                   +cmp edi, ebx
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
    // 004b247a  7512                   -jne 0x4b248e
    if (!cpu.flags.zf)
    {
        goto L_0x004b248e;
    }
    // 004b247c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004b247e  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b2480  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004b2482  3b5e0c                 +cmp ebx, dword ptr [esi + 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2485  7503                   -jne 0x4b248a
    if (!cpu.flags.zf)
    {
        goto L_0x004b248a;
    }
    // 004b2487  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x004b248a:
    // 004b248a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b248c  eb0f                   -jmp 0x4b249d
    goto L_0x004b249d;
L_0x004b248e:
    // 004b248e  ff461c                 -inc dword ptr [esi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))++;
    // 004b2491  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b2494  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b2497  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b249a  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x004b249d:
    // 004b249d  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004b24a0  4a                     -dec edx
    (cpu.edx)--;
    // 004b24a1  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b24a4  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b24a7  39fb                   +cmp ebx, edi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b24a9  7308                   -jae 0x4b24b3
    if (!cpu.flags.cf)
    {
        goto L_0x004b24b3;
    }
    // 004b24ab  3b4e10                 +cmp ecx, dword ptr [esi + 0x10]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b24ae  7603                   -jbe 0x4b24b3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b24b3;
    }
    // 004b24b0  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x004b24b3:
    // 004b24b3  3b4e14                 +cmp ecx, dword ptr [esi + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b24b6  7603                   -jbe 0x4b24bb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b24bb;
    }
    // 004b24b8  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x004b24bb:
    // 004b24bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b24bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b24bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b24be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b24bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b24c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b24c0);
    // 004b24c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b24c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b24c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b24c4  a1fcb84d00             -mov eax, dword ptr [0x4db8fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093628) /* 0x4db8fc */);
    // 004b24c9  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004b24cb  eb09                   -jmp 0x4b24d6
    goto L_0x004b24d6;
L_0x004b24cd:
    // 004b24cd  39c2                   +cmp edx, eax
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
    // 004b24cf  7209                   -jb 0x4b24da
    if (cpu.flags.cf)
    {
        goto L_0x004b24da;
    }
    // 004b24d1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b24d3  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x004b24d6:
    // 004b24d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b24d8  75f3                   -jne 0x4b24cd
    if (!cpu.flags.zf)
    {
        goto L_0x004b24cd;
    }
L_0x004b24da:
    // 004b24da  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b24dd  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b24e0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b24e2  7405                   -je 0x4b24e9
    if (cpu.flags.zf)
    {
        goto L_0x004b24e9;
    }
    // 004b24e4  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b24e7  eb06                   -jmp 0x4b24ef
    goto L_0x004b24ef;
L_0x004b24e9:
    // 004b24e9  8915fcb84d00           -mov dword ptr [0x4db8fc], edx
    app->getMemory<x86::reg32>(x86::reg32(5093628) /* 0x4db8fc */) = cpu.edx;
L_0x004b24ef:
    // 004b24ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b24f1  7403                   -je 0x4b24f6
    if (cpu.flags.zf)
    {
        goto L_0x004b24f6;
    }
    // 004b24f3  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004b24f6:
    // 004b24f6  8d5a20                 -lea ebx, [edx + 0x20]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004b24f9  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b24fb  83c22c                 -add edx, 0x2c
    (cpu.edx) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004b24fe  c742f400000000         -mov dword ptr [edx - 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = 0 /*0x0*/;
    // 004b2505  c742e400000000         -mov dword ptr [edx - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 004b250c  c742ec00000000         -mov dword ptr [edx - 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 004b2513  c742f000000000         -mov dword ptr [edx - 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = 0 /*0x0*/;
    // 004b251a  895af8                 -mov dword ptr [edx - 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004b251d  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004b2520  83e82c                 -sub eax, 0x2c
    (cpu.eax) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004b2523  895ae0                 -mov dword ptr [edx - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 004b2526  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b2528  c70402ffffffff         -mov dword ptr [edx + eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 4294967295 /*0xffffffff*/;
    // 004b252f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2531  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2532  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2533  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2534(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2534);
    // 004b2534  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2535  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2536  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2537  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2538  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2539  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b253a  833df8e74d0000         +cmp dword ptr [0x4de7f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5105656) /* 0x4de7f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2541  7507                   -jne 0x4b254a
    if (!cpu.flags.zf)
    {
        goto L_0x004b254a;
    }
L_0x004b2543:
    // 004b2543  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b2545  e973000000             -jmp 0x4b25bd
    goto L_0x004b25bd;
L_0x004b254a:
    // 004b254a  833d88b84d00fe         +cmp dword ptr [0x4db888], -2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093512) /* 0x4db888 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2551  74f0                   -je 0x4b2543
    if (cpu.flags.zf)
    {
        goto L_0x004b2543;
    }
    // 004b2553  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b2555  e87d000000             -call 0x4b25d7
    cpu.esp -= 4;
    sub_4b25d7(app, cpu);
    if (cpu.terminate) return;
    // 004b255a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b255c  745f                   -je 0x4b25bd
    if (cpu.flags.zf)
    {
        goto L_0x004b25bd;
    }
    // 004b255e  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 004b2560  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 004b2565  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b2569  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b256a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b256c  2eff1598454c00         -call dword ptr cs:[0x4c4598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998552) /* 0x4c4598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2573  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2575  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2577  7444                   -je 0x4b25bd
    if (cpu.flags.zf)
    {
        goto L_0x004b25bd;
    }
    // 004b2579  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b257c  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b257f  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2582  39f0                   +cmp eax, esi
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
    // 004b2584  77bd                   -ja 0x4b2543
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b2543;
    }
    // 004b2586  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b2589  83f838                 +cmp eax, 0x38
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b258c  72b5                   -jb 0x4b2543
    if (cpu.flags.cf)
    {
        goto L_0x004b2543;
    }
    // 004b258e  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b2590  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2592  e829ffffff             -call 0x4b24c0
    cpu.esp -= 4;
    sub_4b24c0(app, cpu);
    if (cpu.terminate) return;
    // 004b2597  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2599  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b259b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b259e  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b25a0  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b25a2  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004b25a5  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b25ac  47                     -inc edi
    (cpu.edi)++;
    // 004b25ad  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b25b0  897a18                 -mov dword ptr [edx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004b25b3  e8004bffff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004b25b8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004b25bd:
    // 004b25bd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b25c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b25c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b25c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b25c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b25c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b25c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b25c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b25c6);
    // 004b25c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b25c7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b25c9  e87c770000             -call 0x4b9d4a
    cpu.esp -= 4;
    sub_4b9d4a(app, cpu);
    if (cpu.terminate) return;
    // 004b25ce  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b25d0  e85fffffff             -call 0x4b2534
    cpu.esp -= 4;
    sub_4b2534(app, cpu);
    if (cpu.terminate) return;
    // 004b25d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b25d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b25d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b25d7);
    // 004b25d7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b25d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b25d9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b25db  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b25dd  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b25e0  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004b25e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b25e4  7438                   -je 0x4b261e
    if (cpu.flags.zf)
    {
        goto L_0x004b261e;
    }
    // 004b25e6  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b25e8  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004b25eb  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b25ed  7305                   -jae 0x4b25f4
    if (!cpu.flags.cf)
    {
        goto L_0x004b25f4;
    }
L_0x004b25ef:
    // 004b25ef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b25f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b25f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b25f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b25f4:
    // 004b25f4  8b0dfce74d00           -mov ecx, dword ptr [0x4de7fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5105660) /* 0x4de7fc */);
    // 004b25fa  39c8                   +cmp eax, ecx
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
    // 004b25fc  7304                   -jae 0x4b2602
    if (!cpu.flags.cf)
    {
        goto L_0x004b2602;
    }
    // 004b25fe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b2600  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x004b2602:
    // 004b2602  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b2604  05ff0f0000             -add eax, 0xfff
    (cpu.eax) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 004b2609  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b260b  72e2                   -jb 0x4b25ef
    if (cpu.flags.cf)
    {
        goto L_0x004b25ef;
    }
    // 004b260d  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004b260f  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004b2612  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b2614  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2616  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004b2619  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x004b261e:
    // 004b261e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b261f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2620  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2621(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2621);
    // 004b2621  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2623  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2624(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2624);
    // 004b2624  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2625  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2626  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2627  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2629  f6c303                 +test bl, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 3 /*0x3*/));
    // 004b262c  7523                   -jne 0x4b2651
    if (!cpu.flags.zf)
    {
        goto L_0x004b2651;
    }
    // 004b262e  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004b2633  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2635  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b2637  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b2639  7409                   -je 0x4b2644
    if (cpu.flags.zf)
    {
        goto L_0x004b2644;
    }
L_0x004b263b:
    // 004b263b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b2640  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2641  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2642  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2643  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2644:
    // 004b2644  b990010000             -mov ecx, 0x190
    cpu.ecx = 400 /*0x190*/;
    // 004b2649  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b264b  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b264d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b264f  74ea                   -je 0x4b263b
    if (cpu.flags.zf)
    {
        goto L_0x004b263b;
    }
L_0x004b2651:
    // 004b2651  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2653  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2654  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2655  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2656  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2657(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2657);
    // 004b2657  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2658  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2659  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b265a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b265b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b265c  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004b265f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2661  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b2664  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b2666  0f85b8000000           -jne 0x4b2724
    if (!cpu.flags.zf)
    {
        goto L_0x004b2724;
    }
    // 004b266c  8d826c070000           -lea eax, [edx + 0x76c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1900) /* 0x76c */);
    // 004b2672  e8adffffff             -call 0x4b2624
    cpu.esp -= 4;
    sub_4b2624(app, cpu);
    if (cpu.terminate) return;
    // 004b2677  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2679  7413                   -je 0x4b268e
    if (cpu.flags.zf)
    {
        goto L_0x004b268e;
    }
    // 004b267b  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b267e  8b3445d2fe4c00         -mov esi, dword ptr [eax*2 + 0x4cfed2]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5045970) /* 0x4cfed2 */ + cpu.eax * 2);
    // 004b2685  8b0445d0fe4c00         -mov eax, dword ptr [eax*2 + 0x4cfed0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5045968) /* 0x4cfed0 */ + cpu.eax * 2);
    // 004b268c  eb11                   -jmp 0x4b269f
    goto L_0x004b269f;
L_0x004b268e:
    // 004b268e  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b2691  8b3445b8fe4c00         -mov esi, dword ptr [eax*2 + 0x4cfeb8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5045944) /* 0x4cfeb8 */ + cpu.eax * 2);
    // 004b2698  8b0445b6fe4c00         -mov eax, dword ptr [eax*2 + 0x4cfeb6]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5045942) /* 0x4cfeb6 */ + cpu.eax * 2);
L_0x004b269f:
    // 004b269f  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004b26a2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004b26a5  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b26a7  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b26a9  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b26ae  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004b26b1  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004b26b5  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004b26b9  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004b26bd  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b26c0  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b26c4  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b26c8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b26ca  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 004b26ce  e81202ffff             -call 0x4a28e5
    cpu.esp -= 4;
    sub_4a28e5(app, cpu);
    if (cpu.terminate) return;
    // 004b26d3  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b26d7  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004b26da  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b26dc  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b26df  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 004b26e4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b26e6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b26e9  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b26eb  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b26ee  83f805                 +cmp eax, 5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b26f1  751f                   -jne 0x4b2712
    if (!cpu.flags.zf)
    {
        goto L_0x004b2712;
    }
    // 004b26f3  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004b26f6  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004b26f8  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 004b26fb  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b26fe  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2700  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b2702  39f0                   +cmp eax, esi
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
    // 004b2704  7e08                   -jle 0x4b270e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b270e;
    }
    // 004b2706  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b2709  83e802                 +sub eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b270c  eb05                   -jmp 0x4b2713
    goto L_0x004b2713;
L_0x004b270e:
    // 004b270e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b2710  eb01                   -jmp 0x4b2713
    goto L_0x004b2713;
L_0x004b2712:
    // 004b2712  48                     -dec eax
    (cpu.eax)--;
L_0x004b2713:
    // 004b2713  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b2717  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b2719  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b271b  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b271e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2720  01d8                   +add eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b2722  eb0f                   -jmp 0x4b2733
    goto L_0x004b2733;
L_0x004b2724:
    // 004b2724  83f901                 +cmp ecx, 1
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
    // 004b2727  7507                   -jne 0x4b2730
    if (!cpu.flags.zf)
    {
        goto L_0x004b2730;
    }
    // 004b2729  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b272c  29c8                   +sub eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b272e  eb03                   -jmp 0x4b2733
    goto L_0x004b2733;
L_0x004b2730:
    // 004b2730  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
L_0x004b2733:
    // 004b2733  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004b2736  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2737  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2738  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2739  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b273a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b273b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b273c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b273c);
    // 004b273c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b273d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b273e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b273f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2741  83782000               +cmp dword ptr [eax + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2745  751b                   -jne 0x4b2762
    if (!cpu.flags.zf)
    {
        goto L_0x004b2762;
    }
    // 004b2747  83792000               +cmp dword ptr [ecx + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b274b  7515                   -jne 0x4b2762
    if (!cpu.flags.zf)
    {
        goto L_0x004b2762;
    }
    // 004b274d  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004b2750  8b7910                 -mov edi, dword ptr [ecx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004b2753  39fe                   +cmp esi, edi
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
    // 004b2755  7e09                   -jle 0x4b2760
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2760;
    }
L_0x004b2757:
    // 004b2757  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b275c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b275d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b275e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b275f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b2760:
    // 004b2760  7c16                   -jl 0x4b2778
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2778;
    }
L_0x004b2762:
    // 004b2762  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b2764  e8eefeffff             -call 0x4b2657
    cpu.esp -= 4;
    sub_4b2657(app, cpu);
    if (cpu.terminate) return;
    // 004b2769  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b276b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b276d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b276f  e8e3feffff             -call 0x4b2657
    cpu.esp -= 4;
    sub_4b2657(app, cpu);
    if (cpu.terminate) return;
    // 004b2774  39c6                   +cmp esi, eax
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
    // 004b2776  7fdf                   -jg 0x4b2757
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b2757;
    }
L_0x004b2778:
    // 004b2778  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b277a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b277b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b277c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b277d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b277e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b277e);
    // 004b277e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b277f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2780  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2781  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2782  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2783  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2784  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b2787  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b2789  a12ee34d00             -mov eax, dword ptr [0x4de32e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104430) /* 0x4de32e */);
    // 004b278e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2790  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b2792  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004b2794  0f8484020000           -je 0x4b2a1e
    if (cpu.flags.zf)
    {
        goto L_0x004b2a1e;
    }
    // 004b279a  ba04e24d00             -mov edx, 0x4de204
    cpu.edx = 5104132 /*0x4de204*/;
    // 004b279f  b8e0e14d00             -mov eax, 0x4de1e0
    cpu.eax = 5104096 /*0x4de1e0*/;
    // 004b27a4  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004b27a7  e890ffffff             -call 0x4b273c
    cpu.esp -= 4;
    sub_4b273c(app, cpu);
    if (cpu.terminate) return;
    // 004b27ac  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b27b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b27b2  740c                   -je 0x4b27c0
    if (cpu.flags.zf)
    {
        goto L_0x004b27c0;
    }
    // 004b27b4  be04e24d00             -mov esi, 0x4de204
    cpu.esi = 5104132 /*0x4de204*/;
    // 004b27b9  bbe0e14d00             -mov ebx, 0x4de1e0
    cpu.ebx = 5104096 /*0x4de1e0*/;
    // 004b27be  eb0a                   -jmp 0x4b27ca
    goto L_0x004b27ca;
L_0x004b27c0:
    // 004b27c0  bee0e14d00             -mov esi, 0x4de1e0
    cpu.esi = 5104096 /*0x4de1e0*/;
    // 004b27c5  bb04e24d00             -mov ebx, 0x4de204
    cpu.ebx = 5104132 /*0x4de204*/;
L_0x004b27ca:
    // 004b27ca  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004b27cd  056c070000             -add eax, 0x76c
    (cpu.eax) += x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 004b27d2  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004b27d5  e84afeffff             -call 0x4b2624
    cpu.esp -= 4;
    sub_4b2624(app, cpu);
    if (cpu.terminate) return;
    // 004b27da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b27dc  8d442d00               -lea eax, [ebp + ebp]
    cpu.eax = x86::reg32(cpu.ebp + cpu.ebp * 1);
    // 004b27e0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b27e2  740e                   -je 0x4b27f2
    if (cpu.flags.zf)
    {
        goto L_0x004b27f2;
    }
    // 004b27e4  8b90d2fe4c00           -mov edx, dword ptr [eax + 0x4cfed2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5045970) /* 0x4cfed2 */);
    // 004b27ea  8b80d0fe4c00           -mov eax, dword ptr [eax + 0x4cfed0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5045968) /* 0x4cfed0 */);
    // 004b27f0  eb0c                   -jmp 0x4b27fe
    goto L_0x004b27fe;
L_0x004b27f2:
    // 004b27f2  8b90b8fe4c00           -mov edx, dword ptr [eax + 0x4cfeb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5045944) /* 0x4cfeb8 */);
    // 004b27f8  8b80b6fe4c00           -mov eax, dword ptr [eax + 0x4cfeb6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5045942) /* 0x4cfeb6 */);
L_0x004b27fe:
    // 004b27fe  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b2801  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004b2804  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2806  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004b280a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b280c  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004b280f  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b2813  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2815  0f85b9000000           -jne 0x4b28d4
    if (!cpu.flags.zf)
    {
        goto L_0x004b28d4;
    }
    // 004b281b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004b281e  39d5                   +cmp ebp, edx
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
    // 004b2820  7e0a                   -jle 0x4b282c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b282c;
    }
    // 004b2822  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b2827  e9dd000000             -jmp 0x4b2909
    goto L_0x004b2909;
L_0x004b282c:
    // 004b282c  0f85d7000000           -jne 0x4b2909
    if (!cpu.flags.zf)
    {
        goto L_0x004b2909;
    }
    // 004b2832  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004b2835  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004b2838  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b283b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b283d  c744241807000000       -mov dword ptr [esp + 0x18], 7
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 7 /*0x7*/;
    // 004b2845  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2847  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b284a  f77c2418               -idiv dword ptr [esp + 0x18]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b284e  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b2851  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2853  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004b2856  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b285a  83c206                 -add edx, 6
    (cpu.edx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 004b285d  2b5618                 -sub edx, dword ptr [esi + 0x18]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)));
    // 004b2860  c744241807000000       -mov dword ptr [esp + 0x18], 7
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 7 /*0x7*/;
    // 004b2868  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b286a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b286d  f77c2418               -idiv dword ptr [esp + 0x18]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b2871  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b2874  48                     -dec eax
    (cpu.eax)--;
    // 004b2875  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2877  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b287a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b287e  83fa05                 +cmp edx, 5
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
    // 004b2881  7529                   -jne 0x4b28ac
    if (!cpu.flags.zf)
    {
        goto L_0x004b28ac;
    }
    // 004b2883  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b2887  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b288b  83e807                 -sub eax, 7
    (cpu.eax) -= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b288e  39d0                   +cmp eax, edx
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
    // 004b2890  0f8d73000000           -jge 0x4b2909
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b2909;
    }
    // 004b2896  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b289a  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b289f  39d0                   +cmp eax, edx
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
    // 004b28a1  0f8c62000000           -jl 0x4b2909
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2909;
    }
    // 004b28a7  e964000000             -jmp 0x4b2910
    goto L_0x004b2910;
L_0x004b28ac:
    // 004b28ac  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b28af  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b28b3  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b28b7  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b28ba  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b28bc  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b28c0  40                     -inc eax
    (cpu.eax)++;
    // 004b28c1  39d0                   +cmp eax, edx
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
    // 004b28c3  7f44                   -jg 0x4b2909
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b2909;
    }
    // 004b28c5  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b28c9  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b28ce  39d0                   +cmp eax, edx
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
    // 004b28d0  7e37                   -jle 0x4b2909
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2909;
    }
    // 004b28d2  eb3c                   -jmp 0x4b2910
    goto L_0x004b2910;
L_0x004b28d4:
    // 004b28d4  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004b28d7  83f801                 +cmp eax, 1
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
    // 004b28da  751f                   -jne 0x4b28fb
    if (!cpu.flags.zf)
    {
        goto L_0x004b28fb;
    }
    // 004b28dc  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004b28df  056c070000             -add eax, 0x76c
    (cpu.eax) += x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 004b28e4  e83bfdffff             -call 0x4b2624
    cpu.esp -= 4;
    sub_4b2624(app, cpu);
    if (cpu.terminate) return;
    // 004b28e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b28eb  740d                   -je 0x4b28fa
    if (cpu.flags.zf)
    {
        goto L_0x004b28fa;
    }
    // 004b28ed  a1bafe4c00             -mov eax, dword ptr [0x4cfeba]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5045946) /* 0x4cfeba */);
    // 004b28f2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004b28f5  39c2                   +cmp edx, eax
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
    // 004b28f7  7e01                   -jle 0x4b28fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b28fa;
    }
    // 004b28f9  42                     -inc edx
    (cpu.edx)++;
L_0x004b28fa:
    // 004b28fa  4a                     -dec edx
    (cpu.edx)--;
L_0x004b28fb:
    // 004b28fb  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004b28fe  39c2                   +cmp edx, eax
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
    // 004b2900  7f07                   -jg 0x4b2909
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b2909;
    }
    // 004b2902  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b2907  7407                   -je 0x4b2910
    if (cpu.flags.zf)
    {
        goto L_0x004b2910;
    }
L_0x004b2909:
    // 004b2909  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b290e  7416                   -je 0x4b2926
    if (cpu.flags.zf)
    {
        goto L_0x004b2926;
    }
L_0x004b2910:
    // 004b2910  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b2912  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b2914  e814010000             -call 0x4b2a2d
    cpu.esp -= 4;
    sub_4b2a2d(app, cpu);
    if (cpu.terminate) return;
    // 004b2919  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b291b  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004b291e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b2920  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x004b2926:
    // 004b2926  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b2928  7513                   -jne 0x4b293d
    if (!cpu.flags.zf)
    {
        goto L_0x004b293d;
    }
    // 004b292a  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b292e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b2930  0f84e8000000           -je 0x4b2a1e
    if (cpu.flags.zf)
    {
        goto L_0x004b2a1e;
    }
    // 004b2936  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b2938  e9e1000000             -jmp 0x4b2a1e
    goto L_0x004b2a1e;
L_0x004b293d:
    // 004b293d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b293f  8b7320                 -mov esi, dword ptr [ebx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004b2942  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b2945  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b2947  0f857f000000           -jne 0x4b29cc
    if (!cpu.flags.zf)
    {
        goto L_0x004b29cc;
    }
    // 004b294d  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b2950  39c5                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2952  7e07                   -jle 0x4b295b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b295b;
    }
    // 004b2954  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004b2956  e9a6000000             -jmp 0x4b2a01
    goto L_0x004b2a01;
L_0x004b295b:
    // 004b295b  0f85a0000000           -jne 0x4b2a01
    if (!cpu.flags.zf)
    {
        goto L_0x004b2a01;
    }
    // 004b2961  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004b2964  8b7318                 -mov esi, dword ptr [ebx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004b2967  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b296a  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b296c  be07000000             -mov esi, 7
    cpu.esi = 7 /*0x7*/;
    // 004b2971  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2973  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b2976  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b2978  8b690c                 -mov ebp, dword ptr [ecx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b297b  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b297d  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004b2980  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004b2983  83c206                 -add edx, 6
    (cpu.edx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 004b2986  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2988  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b298a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b298d  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b298f  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b2992  48                     -dec eax
    (cpu.eax)--;
    // 004b2993  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b2995  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2997  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b299a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b299c  83fe05                 +cmp esi, 5
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
    // 004b299f  7518                   -jne 0x4b29b9
    if (!cpu.flags.zf)
    {
        goto L_0x004b29b9;
    }
    // 004b29a1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b29a5  83e807                 -sub eax, 7
    (cpu.eax) -= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b29a8  39c5                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b29aa  7f07                   -jg 0x4b29b3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b29b3;
    }
L_0x004b29ac:
    // 004b29ac  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b29b1  eb4e                   -jmp 0x4b2a01
    goto L_0x004b2a01;
L_0x004b29b3:
    // 004b29b3  39c2                   +cmp edx, eax
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
    // 004b29b5  7f4a                   -jg 0x4b2a01
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b2a01;
    }
    // 004b29b7  eb4e                   -jmp 0x4b2a07
    goto L_0x004b2a07;
L_0x004b29b9:
    // 004b29b9  4e                     -dec esi
    (cpu.esi)--;
    // 004b29ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b29bc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b29bf  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b29c1  40                     -inc eax
    (cpu.eax)++;
    // 004b29c2  39c5                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b29c4  7ce6                   -jl 0x4b29ac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b29ac;
    }
    // 004b29c6  39c2                   +cmp edx, eax
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
    // 004b29c8  7d37                   -jge 0x4b2a01
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b2a01;
    }
    // 004b29ca  eb3b                   -jmp 0x4b2a07
    goto L_0x004b2a07;
L_0x004b29cc:
    // 004b29cc  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004b29cf  83fe01                 +cmp esi, 1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b29d2  7520                   -jne 0x4b29f4
    if (!cpu.flags.zf)
    {
        goto L_0x004b29f4;
    }
    // 004b29d4  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004b29d7  056c070000             -add eax, 0x76c
    (cpu.eax) += x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 004b29dc  e843fcffff             -call 0x4b2624
    cpu.esp -= 4;
    sub_4b2624(app, cpu);
    if (cpu.terminate) return;
    // 004b29e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b29e3  740e                   -je 0x4b29f3
    if (cpu.flags.zf)
    {
        goto L_0x004b29f3;
    }
    // 004b29e5  a1bafe4c00             -mov eax, dword ptr [0x4cfeba]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5045946) /* 0x4cfeba */);
    // 004b29ea  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004b29ed  39c2                   +cmp edx, eax
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
    // 004b29ef  7e02                   -jle 0x4b29f3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b29f3;
    }
    // 004b29f1  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004b29f3:
    // 004b29f3  4a                     -dec edx
    (cpu.edx)--;
L_0x004b29f4:
    // 004b29f4  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004b29f7  39c2                   +cmp edx, eax
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
    // 004b29f9  7f06                   -jg 0x4b2a01
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b2a01;
    }
    // 004b29fb  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b29fd  39c2                   +cmp edx, eax
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
    // 004b29ff  7406                   -je 0x4b2a07
    if (cpu.flags.zf)
    {
        goto L_0x004b2a07;
    }
L_0x004b2a01:
    // 004b2a01  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2a05  740b                   -je 0x4b2a12
    if (cpu.flags.zf)
    {
        goto L_0x004b2a12;
    }
L_0x004b2a07:
    // 004b2a07  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b2a09  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b2a0b  e81d000000             -call 0x4b2a2d
    cpu.esp -= 4;
    sub_4b2a2d(app, cpu);
    if (cpu.terminate) return;
    // 004b2a10  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004b2a12:
    // 004b2a12  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b2a16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2a18  7404                   -je 0x4b2a1e
    if (cpu.flags.zf)
    {
        goto L_0x004b2a1e;
    }
    // 004b2a1a  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004b2a1c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004b2a1e:
    // 004b2a1e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b2a20  897920                 -mov dword ptr [ecx + 0x20], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 004b2a23  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b2a26  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2a27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2a28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2a29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2a2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2a2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2a2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2a2d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2a2d);
    // 004b2a2d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2a2e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2a2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2a30  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2a31  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b2a34  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b2a37  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b2a39  39f1                   +cmp ecx, esi
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
    // 004b2a3b  7c14                   -jl 0x4b2a51
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2a51;
    }
    // 004b2a3d  7517                   -jne 0x4b2a56
    if (!cpu.flags.zf)
    {
        goto L_0x004b2a56;
    }
    // 004b2a3f  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b2a42  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b2a45  39e9                   +cmp ecx, ebp
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
    // 004b2a47  7c08                   -jl 0x4b2a51
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b2a51;
    }
    // 004b2a49  750b                   -jne 0x4b2a56
    if (!cpu.flags.zf)
    {
        goto L_0x004b2a56;
    }
    // 004b2a4b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b2a4d  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2a4f  7d05                   -jge 0x4b2a56
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b2a56;
    }
L_0x004b2a51:
    // 004b2a51  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004b2a56:
    // 004b2a56  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2a58  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2a59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2a5a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2a5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2a5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2a5d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2a5d);
    // 004b2a5d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2a5e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2a5f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2a60  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b2a62  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b2a64  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2a66  81fac0a80000           +cmp edx, 0xa8c0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43200 /*0xa8c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2a6c  731c                   -jae 0x4b2a8a
    if (!cpu.flags.cf)
    {
        goto L_0x004b2a8a;
    }
    // 004b2a6e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b2a70  7e18                   -jle 0x4b2a8a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2a8a;
    }
    // 004b2a72  8db280510100           -lea esi, [edx + 0x15180]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(86400) /* 0x15180 */);
    // 004b2a78  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b2a7a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2a7c  bb80510100             -mov ebx, 0x15180
    cpu.ebx = 86400 /*0x15180*/;
    // 004b2a81  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2a83  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b2a85  01c7                   +add edi, eax
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
    // 004b2a87  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b2a88  eb0f                   -jmp 0x4b2a99
    goto L_0x004b2a99;
L_0x004b2a8a:
    // 004b2a8a  bb80510100             -mov ebx, 0x15180
    cpu.ebx = 86400 /*0x15180*/;
    // 004b2a8f  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2a91  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2a93  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2a95  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b2a97  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004b2a99:
    // 004b2a99  bb80510100             -mov ebx, 0x15180
    cpu.ebx = 86400 /*0x15180*/;
    // 004b2a9e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2aa0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2aa2  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b2aa4  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b2aa6  be100e0000             -mov esi, 0xe10
    cpu.esi = 3600 /*0xe10*/;
    // 004b2aab  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2aad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2aaf  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b2ab1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2ab3  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b2ab6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2ab8  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b2aba  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b2abc  be3c000000             -mov esi, 0x3c
    cpu.esi = 60 /*0x3c*/;
    // 004b2ac1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2ac3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2ac5  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b2ac7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2ac9  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b2acc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2ace  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b2ad0  bb6e010000             -mov ebx, 0x16e
    cpu.ebx = 366 /*0x16e*/;
    // 004b2ad5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b2ad7  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004b2ad9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2adb  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b2add  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2adf  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b2ae2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b2ae4  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b2ae7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b2ae9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2aeb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b2aee  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b2af0  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b2af2  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2af4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b2af6  7608                   -jbe 0x4b2b00
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b2b00;
    }
    // 004b2af8  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b2afb  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b2afe  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b2b00:
    // 004b2b00  8d826c070000           -lea eax, [edx + 0x76c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1900) /* 0x76c */);
    // 004b2b06  e819fbffff             -call 0x4b2624
    cpu.esp -= 4;
    sub_4b2624(app, cpu);
    if (cpu.terminate) return;
    // 004b2b0b  056d010000             -add eax, 0x16d
    (cpu.eax) += x86::reg32(x86::sreg32(365 /*0x16d*/));
L_0x004b2b10:
    // 004b2b10  39c3                   +cmp ebx, eax
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
    // 004b2b12  7205                   -jb 0x4b2b19
    if (cpu.flags.cf)
    {
        goto L_0x004b2b19;
    }
    // 004b2b14  42                     -inc edx
    (cpu.edx)++;
    // 004b2b15  29c3                   +sub ebx, eax
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b2b17  ebf7                   -jmp 0x4b2b10
    goto L_0x004b2b10;
L_0x004b2b19:
    // 004b2b19  beb8fe4c00             -mov esi, 0x4cfeb8
    cpu.esi = 5045944 /*0x4cfeb8*/;
    // 004b2b1e  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b2b21  8d826c070000           -lea eax, [edx + 0x76c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1900) /* 0x76c */);
    // 004b2b27  89591c                 -mov dword ptr [ecx + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004b2b2a  e8f5faffff             -call 0x4b2624
    cpu.esp -= 4;
    sub_4b2624(app, cpu);
    if (cpu.terminate) return;
    // 004b2b2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2b31  7405                   -je 0x4b2b38
    if (cpu.flags.zf)
    {
        goto L_0x004b2b38;
    }
    // 004b2b33  bed2fe4c00             -mov esi, 0x4cfed2
    cpu.esi = 5045970 /*0x4cfed2*/;
L_0x004b2b38:
    // 004b2b38  bd1f000000             -mov ebp, 0x1f
    cpu.ebp = 31 /*0x1f*/;
    // 004b2b3d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2b3f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2b41  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b2b43  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2b45  8b1456                 -mov edx, dword ptr [esi + edx*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 2);
    // 004b2b48  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b2b4b  39d3                   +cmp ebx, edx
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
    // 004b2b4d  7201                   -jb 0x4b2b50
    if (cpu.flags.cf)
    {
        goto L_0x004b2b50;
    }
    // 004b2b4f  40                     -inc eax
    (cpu.eax)++;
L_0x004b2b50:
    // 004b2b50  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b2b53  0fbf0446               -movsx eax, word ptr [esi + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 004b2b57  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2b59  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2b5b  43                     -inc ebx
    (cpu.ebx)++;
    // 004b2b5c  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b2b5f  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b2b62  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 004b2b67  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b2b69  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b2b6b  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b2b6e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2b6f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2b70  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2b71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2b72(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2b72);
    // 004b2b72  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2b73  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2b74  c7422000000000         -mov dword ptr [edx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004b2b7b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2b7d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b2b7f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b2b81  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2b83  b8df630000             -mov eax, 0x63df
    cpu.eax = 25567 /*0x63df*/;
    // 004b2b88  e8d0feffff             -call 0x4b2a5d
    cpu.esp -= 4;
    sub_4b2a5d(app, cpu);
    if (cpu.terminate) return;
    // 004b2b8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2b8e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2b8f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2b90);
    // 004b2b90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2b91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2b92  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2b94  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2b9a  8d5014                 -lea edx, [eax + 0x14]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b2b9d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2b9f  e8ceffffff             -call 0x4b2b72
    cpu.esp -= 4;
    sub_4b2b72(app, cpu);
    if (cpu.terminate) return;
    // 004b2ba4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2ba5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2ba6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2ba7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2ba7);
    // 004b2ba7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2ba8  8a153ee34d00           -mov dl, byte ptr [0x4de33e]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5104446) /* 0x4de33e */);
    // 004b2bae  a13ee34d00             -mov eax, dword ptr [0x4de33e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104446) /* 0x4de33e */);
    // 004b2bb3  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004b2bb6  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004b2bb9  88153ee34d00           -mov byte ptr [0x4de33e], dl
    app->getMemory<x86::reg8>(x86::reg32(5104446) /* 0x4de33e */) = cpu.dl;
    // 004b2bbf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2bc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2bc1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2bc1);
    // 004b2bc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2bc2  8a153ee34d00           -mov dl, byte ptr [0x4de33e]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5104446) /* 0x4de33e */);
    // 004b2bc8  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b2bcb  a13ee34d00             -mov eax, dword ptr [0x4de33e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104446) /* 0x4de33e */);
    // 004b2bd0  88153ee34d00           -mov byte ptr [0x4de33e], dl
    app->getMemory<x86::reg8>(x86::reg32(5104446) /* 0x4de33e */) = cpu.dl;
    // 004b2bd6  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004b2bd8  80e6fd                 -and dh, 0xfd
    cpu.dh &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004b2bdb  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004b2bde  88353ee34d00           -mov byte ptr [0x4de33e], dh
    app->getMemory<x86::reg8>(x86::reg32(5104446) /* 0x4de33e */) = cpu.dh;
    // 004b2be4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2be5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2be6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2be6);
    // 004b2be6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2be7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2be8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2be9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2bea  81ecac000000           -sub esp, 0xac
    (cpu.esp) -= x86::reg32(x86::sreg32(172 /*0xac*/));
    // 004b2bf0  8a253ee34d00           -mov ah, byte ptr [0x4de33e]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5104446) /* 0x4de33e */);
    // 004b2bf6  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004b2bf9  7409                   -je 0x4b2c04
    if (cpu.flags.zf)
    {
        goto L_0x004b2c04;
    }
    // 004b2bfb  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004b2bfe  0f85cd000000           -jne 0x4b2cd1
    if (!cpu.flags.zf)
    {
        goto L_0x004b2cd1;
    }
L_0x004b2c04:
    // 004b2c04  8a353ee34d00           -mov dh, byte ptr [0x4de33e]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(5104446) /* 0x4de33e */);
    // 004b2c0a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b2c0c  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004b2c0f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b2c10  88353ee34d00           -mov byte ptr [0x4de33e], dh
    app->getMemory<x86::reg8>(x86::reg32(5104446) /* 0x4de33e */) = cpu.dh;
    // 004b2c16  2eff15fc444c00         -call dword ptr cs:[0x4c44fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998396) /* 0x4c44fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b2c1d  83f801                 +cmp eax, 1
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
    // 004b2c20  0f82ab000000           -jb 0x4b2cd1
    if (cpu.flags.cf)
    {
        goto L_0x004b2cd1;
    }
    // 004b2c26  7635                   -jbe 0x4b2c5d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b2c5d;
    }
    // 004b2c28  83f802                 +cmp eax, 2
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
    // 004b2c2b  0f85a0000000           -jne 0x4b2cd1
    if (!cpu.flags.zf)
    {
        goto L_0x004b2cd1;
    }
    // 004b2c31  c70536e34d0001000000   -mov dword ptr [0x4de336], 1
    app->getMemory<x86::reg32>(x86::reg32(5104438) /* 0x4de336 */) = 1 /*0x1*/;
    // 004b2c3b  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 004b2c42  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2c44  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b2c47  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2c49  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b2c4c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2c4e  a33ae34d00             -mov dword ptr [0x4de33a], eax
    app->getMemory<x86::reg32>(x86::reg32(5104442) /* 0x4de33a */) = cpu.eax;
    // 004b2c53  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004b2c55  891d3ae34d00           -mov dword ptr [0x4de33a], ebx
    app->getMemory<x86::reg32>(x86::reg32(5104442) /* 0x4de33a */) = cpu.ebx;
    // 004b2c5b  eb08                   -jmp 0x4b2c65
    goto L_0x004b2c65;
L_0x004b2c5d:
    // 004b2c5d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2c5f  890d36e34d00           -mov dword ptr [0x4de336], ecx
    app->getMemory<x86::reg32>(x86::reg32(5104438) /* 0x4de336 */) = cpu.ecx;
L_0x004b2c65:
    // 004b2c65  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004b2c69  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b2c6c  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004b2c6e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2c70  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b2c73  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2c75  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004b2c7a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b2c7d  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2c81  a332e34d00             -mov dword ptr [0x4de332], eax
    app->getMemory<x86::reg32>(x86::reg32(5104434) /* 0x4de332 */) = cpu.eax;
    // 004b2c86  b828e24d00             -mov eax, 0x4de228
    cpu.eax = 5104168 /*0x4de228*/;
    // 004b2c8b  e897630000             -call 0x4b9027
    cpu.esp -= 4;
    sub_4b9027(app, cpu);
    if (cpu.terminate) return;
    // 004b2c90  83f8ff                 +cmp eax, -1
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
    // 004b2c93  750a                   -jne 0x4b2c9f
    if (!cpu.flags.zf)
    {
        goto L_0x004b2c9f;
    }
    // 004b2c95  30ff                   +xor bh, bh
    cpu.clear_co();
    cpu.set_szp((cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh))));
    // 004b2c97  883d28e24d00           -mov byte ptr [0x4de228], bh
    app->getMemory<x86::reg8>(x86::reg32(5104168) /* 0x4de228 */) = cpu.bh;
    // 004b2c9d  eb08                   -jmp 0x4b2ca7
    goto L_0x004b2ca7;
L_0x004b2c9f:
    // 004b2c9f  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004b2ca1  881da8e24d00           -mov byte ptr [0x4de2a8], bl
    app->getMemory<x86::reg8>(x86::reg32(5104296) /* 0x4de2a8 */) = cpu.bl;
L_0x004b2ca7:
    // 004b2ca7  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004b2cac  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004b2cb0  b8a9e24d00             -mov eax, 0x4de2a9
    cpu.eax = 5104297 /*0x4de2a9*/;
    // 004b2cb5  e86d630000             -call 0x4b9027
    cpu.esp -= 4;
    sub_4b9027(app, cpu);
    if (cpu.terminate) return;
    // 004b2cba  83f8ff                 +cmp eax, -1
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
    // 004b2cbd  750a                   -jne 0x4b2cc9
    if (!cpu.flags.zf)
    {
        goto L_0x004b2cc9;
    }
    // 004b2cbf  30ed                   +xor ch, ch
    cpu.clear_co();
    cpu.set_szp((cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch))));
    // 004b2cc1  882da9e24d00           -mov byte ptr [0x4de2a9], ch
    app->getMemory<x86::reg8>(x86::reg32(5104297) /* 0x4de2a9 */) = cpu.ch;
    // 004b2cc7  eb08                   -jmp 0x4b2cd1
    goto L_0x004b2cd1;
L_0x004b2cc9:
    // 004b2cc9  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004b2ccb  880d29e34d00           -mov byte ptr [0x4de329], cl
    app->getMemory<x86::reg8>(x86::reg32(5104425) /* 0x4de329 */) = cpu.cl;
L_0x004b2cd1:
    // 004b2cd1  81c4ac000000           -add esp, 0xac
    (cpu.esp) += x86::reg32(x86::sreg32(172 /*0xac*/));
    // 004b2cd7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2cd8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2cd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2cda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2cdb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2cdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2cdc);
    // 004b2cdc  b820f74c00             -mov eax, 0x4cf720
    cpu.eax = 5044000 /*0x4cf720*/;
    // 004b2ce1  e8a792ffff             -call 0x4abf8d
    cpu.esp -= 4;
    sub_4abf8d(app, cpu);
    if (cpu.terminate) return;
    // 004b2ce6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b2ce8  0f84f8feffff           -je 0x4b2be6
    if (cpu.flags.zf)
    {
        return sub_4b2be6(app, cpu);
    }
    // 004b2cee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2cef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2cf0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b2cf1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2cf2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2cf3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2cf4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b2cf7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2cf9  bb32e34d00             -mov ebx, 0x4de332
    cpu.ebx = 5104434 /*0x4de332*/;
    // 004b2cfe  891536e34d00           -mov dword ptr [0x4de336], edx
    app->getMemory<x86::reg32>(x86::reg32(5104438) /* 0x4de336 */) = cpu.edx;
    // 004b2d04  ba28e24d00             -mov edx, 0x4de228
    cpu.edx = 5104168 /*0x4de228*/;
    // 004b2d09  e83d000000             -call 0x4b2d4b
    cpu.esp -= 4;
    sub_4b2d4b(app, cpu);
    if (cpu.terminate) return;
    // 004b2d0e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b2d10  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2d12  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004b2d14  0f8534020000           -jne 0x4b2f4e
    if (!cpu.flags.zf)
    {
        return sub_4b2f4e(app, cpu);
    }
    // 004b2d1a  8825a9e24d00           -mov byte ptr [0x4de2a9], ah
    app->getMemory<x86::reg8>(x86::reg32(5104297) /* 0x4de2a9 */) = cpu.ah;
    // 004b2d20  e9e7020000             -jmp 0x4b300c
    return sub_4b300c(app, cpu);
}

/* align: skip  */
void Application::sub_4b2d25(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2d25);
    // 004b2d25  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2d26  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2d27  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2d29  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004b2d2b:
    // 004b2d2b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2d2d  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2d30  7214                   -jb 0x4b2d46
    if (cpu.flags.cf)
    {
        goto L_0x004b2d46;
    }
    // 004b2d32  80fb39                 +cmp bl, 0x39
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2d35  770f                   -ja 0x4b2d46
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b2d46;
    }
    // 004b2d37  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004b2d3a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b2d3c  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2d3e  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b2d40  40                     -inc eax
    (cpu.eax)++;
    // 004b2d41  83ea30                 +sub edx, 0x30
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b2d44  ebe5                   -jmp 0x4b2d2b
    goto L_0x004b2d2b;
L_0x004b2d46:
    // 004b2d46  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004b2d48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2d4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2d4b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2d4b);
    // 004b2d4b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2d4c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2d4d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2d4e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b2d4f  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b2d52  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b2d54  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b2d57  80383a                 +cmp byte ptr [eax], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2d5a  7501                   -jne 0x4b2d5d
    if (!cpu.flags.zf)
    {
        goto L_0x004b2d5d;
    }
    // 004b2d5c  45                     -inc ebp
    (cpu.ebp)++;
L_0x004b2d5d:
    // 004b2d5d  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004b2d5f:
    // 004b2d5f  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 004b2d62  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004b2d64  741c                   -je 0x4b2d82
    if (cpu.flags.zf)
    {
        goto L_0x004b2d82;
    }
    // 004b2d66  80fa2c                 +cmp dl, 0x2c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2d69  7417                   -je 0x4b2d82
    if (cpu.flags.zf)
    {
        goto L_0x004b2d82;
    }
    // 004b2d6b  80fa2d                 +cmp dl, 0x2d
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2d6e  7412                   -je 0x4b2d82
    if (cpu.flags.zf)
    {
        goto L_0x004b2d82;
    }
    // 004b2d70  80fa2b                 +cmp dl, 0x2b
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2d73  740d                   -je 0x4b2d82
    if (cpu.flags.zf)
    {
        goto L_0x004b2d82;
    }
    // 004b2d75  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2d78  7205                   -jb 0x4b2d7f
    if (cpu.flags.cf)
    {
        goto L_0x004b2d7f;
    }
    // 004b2d7a  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2d7d  7603                   -jbe 0x4b2d82
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b2d82;
    }
L_0x004b2d7f:
    // 004b2d7f  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b2d80  ebdd                   -jmp 0x4b2d5f
    goto L_0x004b2d5f;
L_0x004b2d82:
    // 004b2d82  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b2d84  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b2d86  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b2d8a  3d80000000             +cmp eax, 0x80
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b2d8f  7e08                   -jle 0x4b2d99
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b2d99;
    }
    // 004b2d91  c744241080000000       -mov dword ptr [esp + 0x10], 0x80
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 128 /*0x80*/;
L_0x004b2d99:
    // 004b2d99  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b2d9d  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b2da0  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b2da1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b2da3  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b2da5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b2da6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b2da8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b2dab  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b2dad  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b2daf  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b2db2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b2db4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2db5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b2db6  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b2dba  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004b2dbd  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004b2dc0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2dc2  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004b2dc5  80fa2d                 +cmp dl, 0x2d
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2dc8  7507                   -jne 0x4b2dd1
    if (!cpu.flags.zf)
    {
        goto L_0x004b2dd1;
    }
    // 004b2dca  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b2dcf  eb05                   -jmp 0x4b2dd6
    goto L_0x004b2dd6;
L_0x004b2dd1:
    // 004b2dd1  80fa2b                 +cmp dl, 0x2b
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2dd4  7502                   -jne 0x4b2dd8
    if (!cpu.flags.zf)
    {
        goto L_0x004b2dd8;
    }
L_0x004b2dd6:
    // 004b2dd6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004b2dd8:
    // 004b2dd8  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004b2ddb  3c30                   +cmp al, 0x30
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2ddd  0f8273000000           -jb 0x4b2e56
    if (cpu.flags.cf)
    {
        goto L_0x004b2e56;
    }
    // 004b2de3  3c39                   +cmp al, 0x39
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2de5  776f                   -ja 0x4b2e56
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b2e56;
    }
    // 004b2de7  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2deb  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b2ded  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b2def  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004b2df3  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004b2df7  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004b2dfb  e825ffffff             -call 0x4b2d25
    cpu.esp -= 4;
    sub_4b2d25(app, cpu);
    if (cpu.terminate) return;
    // 004b2e00  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2e02  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b2e04  80fa3a                 +cmp dl, 0x3a
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
    // 004b2e07  751f                   -jne 0x4b2e28
    if (!cpu.flags.zf)
    {
        goto L_0x004b2e28;
    }
    // 004b2e09  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b2e0d  40                     -inc eax
    (cpu.eax)++;
    // 004b2e0e  e812ffffff             -call 0x4b2d25
    cpu.esp -= 4;
    sub_4b2d25(app, cpu);
    if (cpu.terminate) return;
    // 004b2e13  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2e15  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b2e17  80fe3a                 +cmp dh, 0x3a
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2e1a  750c                   -jne 0x4b2e28
    if (!cpu.flags.zf)
    {
        goto L_0x004b2e28;
    }
    // 004b2e1c  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2e20  40                     -inc eax
    (cpu.eax)++;
    // 004b2e21  e8fffeffff             -call 0x4b2d25
    cpu.esp -= 4;
    sub_4b2d25(app, cpu);
    if (cpu.terminate) return;
    // 004b2e26  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004b2e28:
    // 004b2e28  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2e2c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b2e2e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b2e31  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b2e33  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b2e37  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b2e3a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b2e3c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b2e3e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b2e41  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2e43  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2e47  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b2e4a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b2e4c  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b2e4e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b2e50  7404                   -je 0x4b2e56
    if (cpu.flags.zf)
    {
        goto L_0x004b2e56;
    }
    // 004b2e52  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004b2e54  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x004b2e56:
    // 004b2e56  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b2e58  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b2e5b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2e5c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2e5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2e5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2e5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2e60);
    // 004b2e60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b2e61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b2e62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b2e63  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2e66  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2e68  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b2e6a  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2e6c  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 004b2e71  80fc4a                 +cmp ah, 0x4a
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(74 /*0x4a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2e74  7507                   -jne 0x4b2e7d
    if (!cpu.flags.zf)
    {
        goto L_0x004b2e7d;
    }
    // 004b2e76  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004b2e7b  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004b2e7d:
    // 004b2e7d  803b4d                 +cmp byte ptr [ebx], 0x4d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(77 /*0x4d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2e80  7503                   -jne 0x4b2e85
    if (!cpu.flags.zf)
    {
        goto L_0x004b2e85;
    }
    // 004b2e82  43                     -inc ebx
    (cpu.ebx)++;
    // 004b2e83  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004b2e85:
    // 004b2e85  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2e89  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2e8b  897120                 -mov dword ptr [ecx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004b2e8e  e892feffff             -call 0x4b2d25
    cpu.esp -= 4;
    sub_4b2d25(app, cpu);
    if (cpu.terminate) return;
    // 004b2e93  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2e95  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2e97  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b2e99  7409                   -je 0x4b2ea4
    if (cpu.flags.zf)
    {
        goto L_0x004b2ea4;
    }
    // 004b2e9b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2e9f  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004b2ea2  eb45                   -jmp 0x4b2ee9
    goto L_0x004b2ee9;
L_0x004b2ea4:
    // 004b2ea4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2ea8  48                     -dec eax
    (cpu.eax)--;
    // 004b2ea9  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b2eac  803a2e                 +cmp byte ptr [edx], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2eaf  7531                   -jne 0x4b2ee2
    if (!cpu.flags.zf)
    {
        goto L_0x004b2ee2;
    }
    // 004b2eb1  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b2eb4  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2eb8  e868feffff             -call 0x4b2d25
    cpu.esp -= 4;
    sub_4b2d25(app, cpu);
    if (cpu.terminate) return;
    // 004b2ebd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2ebf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2ec1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2ec5  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b2ec8  803a2e                 +cmp byte ptr [edx], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2ecb  7515                   -jne 0x4b2ee2
    if (!cpu.flags.zf)
    {
        goto L_0x004b2ee2;
    }
    // 004b2ecd  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b2ed0  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2ed4  e84cfeffff             -call 0x4b2d25
    cpu.esp -= 4;
    sub_4b2d25(app, cpu);
    if (cpu.terminate) return;
    // 004b2ed9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2edb  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b2edf  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004b2ee2:
    // 004b2ee2  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x004b2ee9:
    // 004b2ee9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004b2eee  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b2ef0  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b2ef4  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004b2ef7  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004b2efb  803b2f                 +cmp byte ptr [ebx], 0x2f
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2efe  7532                   -jne 0x4b2f32
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f32;
    }
    // 004b2f00  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b2f04  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b2f07  e819feffff             -call 0x4b2d25
    cpu.esp -= 4;
    sub_4b2d25(app, cpu);
    if (cpu.terminate) return;
    // 004b2f0c  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2f0e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2f10  80fe3a                 +cmp dh, 0x3a
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f13  751d                   -jne 0x4b2f32
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f32;
    }
    // 004b2f15  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2f19  40                     -inc eax
    (cpu.eax)++;
    // 004b2f1a  e806feffff             -call 0x4b2d25
    cpu.esp -= 4;
    sub_4b2d25(app, cpu);
    if (cpu.terminate) return;
    // 004b2f1f  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2f21  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b2f23  80fa3a                 +cmp dl, 0x3a
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
    // 004b2f26  750a                   -jne 0x4b2f32
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f32;
    }
    // 004b2f28  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b2f2a  40                     -inc eax
    (cpu.eax)++;
    // 004b2f2b  e8f5fdffff             -call 0x4b2d25
    cpu.esp -= 4;
    sub_4b2d25(app, cpu);
    if (cpu.terminate) return;
    // 004b2f30  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004b2f32:
    // 004b2f32  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b2f35  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004b2f37  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b2f3b  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b2f3e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b2f42  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b2f45  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b2f47  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b2f4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2f4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2f4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b2f4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b2f4e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b2f4e);
    // 004b2f4e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b2f53  baa9e24d00             -mov edx, 0x4de2a9
    cpu.edx = 5104297 /*0x4de2a9*/;
    // 004b2f58  a132e34d00             -mov eax, dword ptr [0x4de332]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104434) /* 0x4de332 */);
    // 004b2f5d  891d36e34d00           -mov dword ptr [0x4de336], ebx
    app->getMemory<x86::reg32>(x86::reg32(5104438) /* 0x4de336 */) = cpu.ebx;
    // 004b2f63  2d100e0000             -sub eax, 0xe10
    (cpu.eax) -= x86::reg32(x86::sreg32(3600 /*0xe10*/));
    // 004b2f68  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004b2f6a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b2f6d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b2f6f  e8d7fdffff             -call 0x4b2d4b
    cpu.esp -= 4;
    sub_4b2d4b(app, cpu);
    if (cpu.terminate) return;
    // 004b2f74  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b2f77  8b1d32e34d00           -mov ebx, dword ptr [0x4de332]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5104434) /* 0x4de332 */);
    // 004b2f7d  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2f7f  891d3ae34d00           -mov dword ptr [0x4de33a], ebx
    app->getMemory<x86::reg32>(x86::reg32(5104442) /* 0x4de33a */) = cpu.ebx;
    // 004b2f85  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2f87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2f89  80fb2c                 +cmp bl, 0x2c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f8c  750d                   -jne 0x4b2f9b
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f9b;
    }
    // 004b2f8e  bae0e14d00             -mov edx, 0x4de1e0
    cpu.edx = 5104096 /*0x4de1e0*/;
    // 004b2f93  40                     -inc eax
    (cpu.eax)++;
    // 004b2f94  e8c7feffff             -call 0x4b2e60
    cpu.esp -= 4;
    sub_4b2e60(app, cpu);
    if (cpu.terminate) return;
    // 004b2f99  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004b2f9b:
    // 004b2f9b  803a2c                 +cmp byte ptr [edx], 0x2c
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f9e  756c                   -jne 0x4b300c
    if (!cpu.flags.zf)
    {
        goto L_0x004b300c;
    }
    // 004b2fa0  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b2fa3  ba04e24d00             -mov edx, 0x4de204
    cpu.edx = 5104132 /*0x4de204*/;
    // 004b2fa8  e8b3feffff             -call 0x4b2e60
    cpu.esp -= 4;
    sub_4b2e60(app, cpu);
    if (cpu.terminate) return;
    // 004b2fad  a13ae34d00             -mov eax, dword ptr [0x4de33a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104442) /* 0x4de33a */);
    // 004b2fb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2fb4  bb100e0000             -mov ebx, 0xe10
    cpu.ebx = 3600 /*0xe10*/;
    // 004b2fb9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b2fbc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b2fbe  8b350ce24d00           -mov esi, dword ptr [0x4de20c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5104140) /* 0x4de20c */);
    // 004b2fc4  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2fc6  a13ae34d00             -mov eax, dword ptr [0x4de33a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104442) /* 0x4de33a */);
    // 004b2fcb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2fcd  bb3c000000             -mov ebx, 0x3c
    cpu.ebx = 60 /*0x3c*/;
    // 004b2fd2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b2fd5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b2fd7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2fd9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b2fdc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b2fde  8b3d08e24d00           -mov edi, dword ptr [0x4de208]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5104136) /* 0x4de208 */);
    // 004b2fe4  a13ae34d00             -mov eax, dword ptr [0x4de33a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104442) /* 0x4de33a */);
    // 004b2fe9  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2feb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2fed  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b2ff0  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b2ff2  8b2d04e24d00           -mov ebp, dword ptr [0x4de204]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5104132) /* 0x4de204 */);
    // 004b2ff8  89350ce24d00           -mov dword ptr [0x4de20c], esi
    app->getMemory<x86::reg32>(x86::reg32(5104140) /* 0x4de20c */) = cpu.esi;
    // 004b2ffe  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3000  893d08e24d00           -mov dword ptr [0x4de208], edi
    app->getMemory<x86::reg32>(x86::reg32(5104136) /* 0x4de208 */) = cpu.edi;
    // 004b3006  892d04e24d00           -mov dword ptr [0x4de204], ebp
    app->getMemory<x86::reg32>(x86::reg32(5104132) /* 0x4de204 */) = cpu.ebp;
L_0x004b300c:
    // 004b300c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b300f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3010  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3011  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3012  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3013  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3014  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3015  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b300c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b300c);
    goto L_entry_0x004b300c;
    // 004b2f4e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b2f53  baa9e24d00             -mov edx, 0x4de2a9
    cpu.edx = 5104297 /*0x4de2a9*/;
    // 004b2f58  a132e34d00             -mov eax, dword ptr [0x4de332]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104434) /* 0x4de332 */);
    // 004b2f5d  891d36e34d00           -mov dword ptr [0x4de336], ebx
    app->getMemory<x86::reg32>(x86::reg32(5104438) /* 0x4de336 */) = cpu.ebx;
    // 004b2f63  2d100e0000             -sub eax, 0xe10
    (cpu.eax) -= x86::reg32(x86::sreg32(3600 /*0xe10*/));
    // 004b2f68  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004b2f6a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b2f6d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b2f6f  e8d7fdffff             -call 0x4b2d4b
    cpu.esp -= 4;
    sub_4b2d4b(app, cpu);
    if (cpu.terminate) return;
    // 004b2f74  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b2f77  8b1d32e34d00           -mov ebx, dword ptr [0x4de332]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5104434) /* 0x4de332 */);
    // 004b2f7d  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b2f7f  891d3ae34d00           -mov dword ptr [0x4de33a], ebx
    app->getMemory<x86::reg32>(x86::reg32(5104442) /* 0x4de33a */) = cpu.ebx;
    // 004b2f85  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b2f87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2f89  80fb2c                 +cmp bl, 0x2c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f8c  750d                   -jne 0x4b2f9b
    if (!cpu.flags.zf)
    {
        goto L_0x004b2f9b;
    }
    // 004b2f8e  bae0e14d00             -mov edx, 0x4de1e0
    cpu.edx = 5104096 /*0x4de1e0*/;
    // 004b2f93  40                     -inc eax
    (cpu.eax)++;
    // 004b2f94  e8c7feffff             -call 0x4b2e60
    cpu.esp -= 4;
    sub_4b2e60(app, cpu);
    if (cpu.terminate) return;
    // 004b2f99  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004b2f9b:
    // 004b2f9b  803a2c                 +cmp byte ptr [edx], 0x2c
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b2f9e  756c                   -jne 0x4b300c
    if (!cpu.flags.zf)
    {
        goto L_0x004b300c;
    }
    // 004b2fa0  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b2fa3  ba04e24d00             -mov edx, 0x4de204
    cpu.edx = 5104132 /*0x4de204*/;
    // 004b2fa8  e8b3feffff             -call 0x4b2e60
    cpu.esp -= 4;
    sub_4b2e60(app, cpu);
    if (cpu.terminate) return;
    // 004b2fad  a13ae34d00             -mov eax, dword ptr [0x4de33a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104442) /* 0x4de33a */);
    // 004b2fb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2fb4  bb100e0000             -mov ebx, 0xe10
    cpu.ebx = 3600 /*0xe10*/;
    // 004b2fb9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b2fbc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b2fbe  8b350ce24d00           -mov esi, dword ptr [0x4de20c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5104140) /* 0x4de20c */);
    // 004b2fc4  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b2fc6  a13ae34d00             -mov eax, dword ptr [0x4de33a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104442) /* 0x4de33a */);
    // 004b2fcb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2fcd  bb3c000000             -mov ebx, 0x3c
    cpu.ebx = 60 /*0x3c*/;
    // 004b2fd2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b2fd5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b2fd7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2fd9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b2fdc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b2fde  8b3d08e24d00           -mov edi, dword ptr [0x4de208]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5104136) /* 0x4de208 */);
    // 004b2fe4  a13ae34d00             -mov eax, dword ptr [0x4de33a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104442) /* 0x4de33a */);
    // 004b2fe9  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b2feb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b2fed  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b2ff0  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b2ff2  8b2d04e24d00           -mov ebp, dword ptr [0x4de204]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5104132) /* 0x4de204 */);
    // 004b2ff8  89350ce24d00           -mov dword ptr [0x4de20c], esi
    app->getMemory<x86::reg32>(x86::reg32(5104140) /* 0x4de20c */) = cpu.esi;
    // 004b2ffe  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3000  893d08e24d00           -mov dword ptr [0x4de208], edi
    app->getMemory<x86::reg32>(x86::reg32(5104136) /* 0x4de208 */) = cpu.edi;
    // 004b3006  892d04e24d00           -mov dword ptr [0x4de204], ebp
    app->getMemory<x86::reg32>(x86::reg32(5104132) /* 0x4de204 */) = cpu.ebp;
L_0x004b300c:
L_entry_0x004b300c:
    // 004b300c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b300f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3010  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3011  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3012  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3013  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3014  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3015  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b3018(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3018);
    // 004b3018  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3019  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b301b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b301c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b301d  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b3020  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b3023  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b3026  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b3029  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b302c  c70036304b00           -mov dword ptr [eax], 0x4b3036
    app->getMemory<x86::reg32>(cpu.eax) = 4927542 /*0x4b3036*/;
    // 004b3032  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3033  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3034  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3035  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3036(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3036);
    // 004b3036  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3037  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b3039  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b303a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b303b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b303c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b303d  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b3040  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b3043  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b3046  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b3049  db450c                 -fild dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))));
    // 004b304c  db4510                 -fild dword ptr [ebp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))));
    // 004b304f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3051  d80d44e34d00           -fmul dword ptr [0x4de344]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5104452) /* 0x4de344 */));
    // 004b3057  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3059  d80d44e34d00           -fmul dword ptr [0x4de344]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5104452) /* 0x4de344 */));
    // 004b305f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3061  d91e                   -fstp dword ptr [esi]
    app->getMemory<float>(cpu.esi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3063  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3066  83f800                 +cmp eax, 0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3069  7417                   -je 0x4b3082
    if (cpu.flags.zf)
    {
        goto L_0x004b3082;
    }
    // 004b306b  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b306e  7448                   -je 0x4b30b8
    if (cpu.flags.zf)
    {
        goto L_0x004b30b8;
    }
    // 004b3070  83f87f                 +cmp eax, 0x7f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3073  7414                   -je 0x4b3089
    if (cpu.flags.zf)
    {
        goto L_0x004b3089;
    }
    // 004b3075  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3078  742e                   -je 0x4b30a8
    if (cpu.flags.zf)
    {
        goto L_0x004b30a8;
    }
    // 004b307a  c701c6304b00           -mov dword ptr [ecx], 0x4b30c6
    app->getMemory<x86::reg32>(cpu.ecx) = 4927686 /*0x4b30c6*/;
    // 004b3080  eb3e                   -jmp 0x4b30c0
    goto L_0x004b30c0;
L_0x004b3082:
    // 004b3082  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3085  7409                   -je 0x4b3090
    if (cpu.flags.zf)
    {
        goto L_0x004b3090;
    }
    // 004b3087  eb27                   -jmp 0x4b30b0
    goto L_0x004b30b0;
L_0x004b3089:
    // 004b3089  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b308c  740a                   -je 0x4b3098
    if (cpu.flags.zf)
    {
        goto L_0x004b3098;
    }
    // 004b308e  eb10                   -jmp 0x4b30a0
    goto L_0x004b30a0;
L_0x004b3090:
    // 004b3090  c701c9334b00           -mov dword ptr [ecx], 0x4b33c9
    app->getMemory<x86::reg32>(cpu.ecx) = 4928457 /*0x4b33c9*/;
    // 004b3096  eb28                   -jmp 0x4b30c0
    goto L_0x004b30c0;
L_0x004b3098:
    // 004b3098  c70156314b00           -mov dword ptr [ecx], 0x4b3156
    app->getMemory<x86::reg32>(cpu.ecx) = 4927830 /*0x4b3156*/;
    // 004b309e  eb20                   -jmp 0x4b30c0
    goto L_0x004b30c0;
L_0x004b30a0:
    // 004b30a0  c70143334b00           -mov dword ptr [ecx], 0x4b3343
    app->getMemory<x86::reg32>(cpu.ecx) = 4928323 /*0x4b3343*/;
    // 004b30a6  eb18                   -jmp 0x4b30c0
    goto L_0x004b30c0;
L_0x004b30a8:
    // 004b30a8  c701be324b00           -mov dword ptr [ecx], 0x4b32be
    app->getMemory<x86::reg32>(cpu.ecx) = 4928190 /*0x4b32be*/;
    // 004b30ae  eb10                   -jmp 0x4b30c0
    goto L_0x004b30c0;
L_0x004b30b0:
    // 004b30b0  c70141324b00           -mov dword ptr [ecx], 0x4b3241
    app->getMemory<x86::reg32>(cpu.ecx) = 4928065 /*0x4b3241*/;
    // 004b30b6  eb08                   -jmp 0x4b30c0
    goto L_0x004b30c0;
L_0x004b30b8:
    // 004b30b8  c701c5314b00           -mov dword ptr [ecx], 0x4b31c5
    app->getMemory<x86::reg32>(cpu.ecx) = 4927941 /*0x4b31c5*/;
    // 004b30be  eb00                   -jmp 0x4b30c0
    goto L_0x004b30c0;
L_0x004b30c0:
    // 004b30c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b30c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b30c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b30c3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b30c4  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b30c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b30c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b30c6);
    // 004b30c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b30c7  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b30c9  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b30ca  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b30cd  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b30d0  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b30d3  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b30d6  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004b30d8  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b30db  83f901                 +cmp ecx, 1
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
    // 004b30de  7e45                   -jle 0x4b3125
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b3125;
    }
    // 004b30e0  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b30e3:
    // 004b30e3  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b30e5  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b30e7  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b30e9  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b30eb  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b30ee  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b30f0  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b30f3  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 004b30f5  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b30f7  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b30fa  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b30fc  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b30ff  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3101  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b3104  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b3106  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b3109  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b310b  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b310e  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3111  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3114  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3117  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b311a  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b311d  83e902                 +sub ecx, 2
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
    // 004b3120  7fc1                   -jg 0x4b30e3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b30e3;
    }
    // 004b3122  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b3125:
    // 004b3125  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3128  7e25                   -jle 0x4b314f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b314f;
    }
    // 004b312a  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b312c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b312e  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b3130  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b3132  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3134  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b3137  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3139  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b313c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b313e  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3141  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3144  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3147  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b314a  83e901                 +sub ecx, 1
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
    // 004b314d  7fd6                   -jg 0x4b3125
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b3125;
    }
L_0x004b314f:
    // 004b314f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3151  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3153  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b3154  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3155  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3156(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3156);
    // 004b3156  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3157  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b3159  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b315a  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b315d  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b3160  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b3163  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b3166  83f901                 +cmp ecx, 1
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
    // 004b3169  7e35                   -jle 0x4b31a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b31a0;
    }
    // 004b316b  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b316e:
    // 004b316e  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004b3171  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004b3173  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004b3176  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004b3178  d94508                 -fld dword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004b317b  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004b317e  d9450c                 -fld dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 004b3181  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004b3184  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b3186  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3189  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b318c  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b318f  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3192  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3195  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b3198  83e902                 +sub ecx, 2
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
    // 004b319b  7fd1                   -jg 0x4b316e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b316e;
    }
    // 004b319d  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b31a0:
    // 004b31a0  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b31a3  7e1d                   -jle 0x4b31c2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b31c2;
    }
    // 004b31a5  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004b31a8  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004b31aa  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004b31ad  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004b31af  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b31b1  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b31b4  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b31b7  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b31ba  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b31bd  83e901                 +sub ecx, 1
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
    // 004b31c0  7fde                   -jg 0x4b31a0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b31a0;
    }
L_0x004b31c2:
    // 004b31c2  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b31c3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b31c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b31c5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b31c5);
    // 004b31c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b31c6  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b31c8  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b31c9  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b31cc  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b31cf  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b31d2  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004b31d4  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b31d7  83f903                 +cmp ecx, 3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b31da  7e46                   -jle 0x4b3222
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b3222;
    }
    // 004b31dc  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b31df:
    // 004b31df  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b31e1  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b31e3  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b31e6  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b31e8  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004b31eb  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b31ed  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004b31f0  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b31f2  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b31f4  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b31f7  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b31f9  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b31fc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b31fe  d84510                 -fadd dword ptr [ebp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    // 004b3201  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b3203  d84518                 -fadd dword ptr [ebp + 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */));
    // 004b3206  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b3208  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b320b  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b320e  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3211  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3214  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b3217  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b321a  83e904                 +sub ecx, 4
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
    // 004b321d  7fc0                   -jg 0x4b31df
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b31df;
    }
    // 004b321f  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b3222:
    // 004b3222  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3225  7e15                   -jle 0x4b323c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b323c;
    }
    // 004b3227  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b3229  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b322b  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b322e  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3231  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3234  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3237  83e901                 +sub ecx, 1
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
    // 004b323a  7fe6                   -jg 0x4b3222
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b3222;
    }
L_0x004b323c:
    // 004b323c  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b323e  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b323f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3240  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3241(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3241);
    // 004b3241  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3242  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b3244  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b3245  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b3248  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b324b  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b324e  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b3251  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b3254  83f903                 +cmp ecx, 3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3257  7e46                   -jle 0x4b329f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b329f;
    }
    // 004b3259  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b325c:
    // 004b325c  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b325e  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b3260  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b3263  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b3265  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004b3268  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b326a  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004b326d  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b326f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b3271  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b3274  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b3276  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b3279  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b327b  d84514                 -fadd dword ptr [ebp + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */));
    // 004b327e  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b3280  d8451c                 -fadd dword ptr [ebp + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */));
    // 004b3283  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b3285  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3288  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b328b  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b328e  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3291  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b3294  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b3297  83e904                 +sub ecx, 4
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
    // 004b329a  7fc0                   -jg 0x4b325c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b325c;
    }
    // 004b329c  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b329f:
    // 004b329f  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b32a2  7e15                   -jle 0x4b32b9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b32b9;
    }
    // 004b32a4  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b32a6  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b32a8  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b32ab  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b32ae  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b32b1  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b32b4  83e901                 +sub ecx, 1
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
    // 004b32b7  7fe6                   -jg 0x4b329f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b329f;
    }
L_0x004b32b9:
    // 004b32b9  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b32bb  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b32bc  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b32bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b32be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b32be);
    // 004b32be  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b32bf  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b32c1  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b32c2  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b32c5  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b32c8  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b32cb  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004b32cd  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b32d0  83f901                 +cmp ecx, 1
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
    // 004b32d3  7e41                   -jle 0x4b3316
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b3316;
    }
    // 004b32d5  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b32d8:
    // 004b32d8  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b32da  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b32dc  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b32de  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b32e1  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b32e3  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b32e6  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b32e8  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b32eb  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b32ed  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b32f0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b32f2  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b32f5  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b32f7  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b32fa  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b32fc  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b32ff  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3302  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3305  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3308  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b330b  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b330e  83e902                 +sub ecx, 2
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
    // 004b3311  7fc5                   -jg 0x4b32d8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b32d8;
    }
    // 004b3313  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b3316:
    // 004b3316  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3319  7e23                   -jle 0x4b333e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b333e;
    }
    // 004b331b  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b331d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b331f  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b3321  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3323  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b3326  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3328  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b332b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b332d  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3330  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3333  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3336  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3339  83e901                 +sub ecx, 1
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
    // 004b333c  7fd8                   -jg 0x4b3316
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b3316;
    }
L_0x004b333e:
    // 004b333e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3340  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b3341  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3342  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3343(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3343);
    // 004b3343  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3344  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b3346  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b3347  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b334a  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b334d  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b3350  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b3353  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b3356  83f901                 +cmp ecx, 1
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
    // 004b3359  7e41                   -jle 0x4b339c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b339c;
    }
    // 004b335b  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b335e:
    // 004b335e  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b3360  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b3362  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b3364  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b3367  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b336a  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b336c  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b336e  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b3371  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b3373  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b3376  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3378  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b337b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b337d  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b3380  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b3382  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3385  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3388  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b338b  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b338e  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3391  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b3394  83e902                 +sub ecx, 2
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
    // 004b3397  7fc5                   -jg 0x4b335e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b335e;
    }
    // 004b3399  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b339c:
    // 004b339c  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b339f  7e23                   -jle 0x4b33c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b33c4;
    }
    // 004b33a1  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b33a3  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b33a5  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b33a7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b33a9  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b33ac  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b33ae  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b33b1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b33b3  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b33b6  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b33b9  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b33bc  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b33bf  83e901                 +sub ecx, 1
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
    // 004b33c2  7fd8                   -jg 0x4b339c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b339c;
    }
L_0x004b33c4:
    // 004b33c4  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b33c6  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b33c7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b33c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b33c9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b33c9);
    // 004b33c9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b33ca  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b33cc  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b33cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b33d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b33d0);
    // 004b33d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b33d1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b33d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b33d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b33d5  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b33d8  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b33db  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b33de  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b33e1  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b33e4  c700ee334b00           -mov dword ptr [eax], 0x4b33ee
    app->getMemory<x86::reg32>(cpu.eax) = 4928494 /*0x4b33ee*/;
    // 004b33ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b33eb  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b33ec  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b33ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b33ee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b33ee);
    // 004b33ee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b33ef  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b33f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b33f2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b33f3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b33f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b33f5  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b33f8  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b33fb  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b33fe  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b3401  db450c                 -fild dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))));
    // 004b3404  db4510                 -fild dword ptr [ebp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))));
    // 004b3407  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3409  d80d48e34d00           -fmul dword ptr [0x4de348]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5104456) /* 0x4de348 */));
    // 004b340f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3411  d80d48e34d00           -fmul dword ptr [0x4de348]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5104456) /* 0x4de348 */));
    // 004b3417  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3419  d91e                   -fstp dword ptr [esi]
    app->getMemory<float>(cpu.esi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b341b  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b341e  83f800                 +cmp eax, 0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3421  7417                   -je 0x4b343a
    if (cpu.flags.zf)
    {
        goto L_0x004b343a;
    }
    // 004b3423  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3426  7448                   -je 0x4b3470
    if (cpu.flags.zf)
    {
        goto L_0x004b3470;
    }
    // 004b3428  83f87f                 +cmp eax, 0x7f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b342b  7414                   -je 0x4b3441
    if (cpu.flags.zf)
    {
        goto L_0x004b3441;
    }
    // 004b342d  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3430  742e                   -je 0x4b3460
    if (cpu.flags.zf)
    {
        goto L_0x004b3460;
    }
    // 004b3432  c7017e344b00           -mov dword ptr [ecx], 0x4b347e
    app->getMemory<x86::reg32>(cpu.ecx) = 4928638 /*0x4b347e*/;
    // 004b3438  eb3e                   -jmp 0x4b3478
    goto L_0x004b3478;
L_0x004b343a:
    // 004b343a  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b343d  7409                   -je 0x4b3448
    if (cpu.flags.zf)
    {
        goto L_0x004b3448;
    }
    // 004b343f  eb27                   -jmp 0x4b3468
    goto L_0x004b3468;
L_0x004b3441:
    // 004b3441  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3444  740a                   -je 0x4b3450
    if (cpu.flags.zf)
    {
        goto L_0x004b3450;
    }
    // 004b3446  eb10                   -jmp 0x4b3458
    goto L_0x004b3458;
L_0x004b3448:
    // 004b3448  c7018b374b00           -mov dword ptr [ecx], 0x4b378b
    app->getMemory<x86::reg32>(cpu.ecx) = 4929419 /*0x4b378b*/;
    // 004b344e  eb28                   -jmp 0x4b3478
    goto L_0x004b3478;
L_0x004b3450:
    // 004b3450  c70110354b00           -mov dword ptr [ecx], 0x4b3510
    app->getMemory<x86::reg32>(cpu.ecx) = 4928784 /*0x4b3510*/;
    // 004b3456  eb20                   -jmp 0x4b3478
    goto L_0x004b3478;
L_0x004b3458:
    // 004b3458  c70103374b00           -mov dword ptr [ecx], 0x4b3703
    app->getMemory<x86::reg32>(cpu.ecx) = 4929283 /*0x4b3703*/;
    // 004b345e  eb18                   -jmp 0x4b3478
    goto L_0x004b3478;
L_0x004b3460:
    // 004b3460  c7017c364b00           -mov dword ptr [ecx], 0x4b367c
    app->getMemory<x86::reg32>(cpu.ecx) = 4929148 /*0x4b367c*/;
    // 004b3466  eb10                   -jmp 0x4b3478
    goto L_0x004b3478;
L_0x004b3468:
    // 004b3468  c701fd354b00           -mov dword ptr [ecx], 0x4b35fd
    app->getMemory<x86::reg32>(cpu.ecx) = 4929021 /*0x4b35fd*/;
    // 004b346e  eb08                   -jmp 0x4b3478
    goto L_0x004b3478;
L_0x004b3470:
    // 004b3470  c70181354b00           -mov dword ptr [ecx], 0x4b3581
    app->getMemory<x86::reg32>(cpu.ecx) = 4928897 /*0x4b3581*/;
    // 004b3476  eb00                   -jmp 0x4b3478
    goto L_0x004b3478;
L_0x004b3478:
    // 004b3478  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3479  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b347a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b347b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b347c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b347d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b347e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b347e);
    // 004b347e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b347f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b3481  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b3482  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b3485  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b3488  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b348b  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b348e  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004b3490  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b3493  83f901                 +cmp ecx, 1
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
    // 004b3496  7e46                   -jle 0x4b34de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b34de;
    }
    // 004b3498  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b349b:
    // 004b349b  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b349d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b349f  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b34a2  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b34a4  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004b34a7  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b34a9  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004b34ac  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 004b34ae  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b34b0  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b34b3  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b34b5  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b34b8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b34ba  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b34bd  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b34bf  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b34c2  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b34c4  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b34c7  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b34ca  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b34cd  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b34d0  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b34d3  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b34d6  83e902                 +sub ecx, 2
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
    // 004b34d9  7fc0                   -jg 0x4b349b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b349b;
    }
    // 004b34db  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b34de:
    // 004b34de  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b34e1  7e26                   -jle 0x4b3509
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b3509;
    }
    // 004b34e3  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b34e5  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b34e7  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b34ea  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b34ec  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b34ee  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b34f1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b34f3  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b34f6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b34f8  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b34fb  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b34fe  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3501  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3504  83e901                 +sub ecx, 1
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
    // 004b3507  7fd5                   -jg 0x4b34de
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b34de;
    }
L_0x004b3509:
    // 004b3509  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b350b  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b350d  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b350e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b350f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3510);
    // 004b3510  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3511  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b3513  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b3514  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b3517  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b351a  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b351d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b3520  83f901                 +cmp ecx, 1
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
    // 004b3523  7e36                   -jle 0x4b355b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b355b;
    }
    // 004b3525  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b3528:
    // 004b3528  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004b352b  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004b352d  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004b3530  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004b3533  d94508                 -fld dword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004b3536  d84708                 -fadd dword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 004b3539  d9450c                 -fld dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 004b353c  d8470c                 -fadd dword ptr [edi + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */));
    // 004b353f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b3541  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3544  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3547  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b354a  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b354d  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b3550  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b3553  83e902                 +sub ecx, 2
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
    // 004b3556  7fd0                   -jg 0x4b3528
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b3528;
    }
    // 004b3558  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b355b:
    // 004b355b  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b355e  7e1e                   -jle 0x4b357e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b357e;
    }
    // 004b3560  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004b3563  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004b3565  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004b3568  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004b356b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b356d  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3570  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3573  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3576  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3579  83e901                 +sub ecx, 1
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
    // 004b357c  7fdd                   -jg 0x4b355b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b355b;
    }
L_0x004b357e:
    // 004b357e  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b357f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3580  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3581(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3581);
    // 004b3581  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3582  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b3584  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b3585  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b3588  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b358b  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b358e  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004b3590  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b3593  83f903                 +cmp ecx, 3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3596  7e46                   -jle 0x4b35de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b35de;
    }
    // 004b3598  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b359b:
    // 004b359b  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b359d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b359f  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004b35a2  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b35a4  d94710                 -fld dword ptr [edi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 004b35a7  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b35a9  d94718                 -fld dword ptr [edi + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(24) /* 0x18 */)));
    // 004b35ac  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b35ae  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b35b0  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b35b3  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b35b5  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b35b8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b35ba  d84510                 -fadd dword ptr [ebp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    // 004b35bd  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b35bf  d84518                 -fadd dword ptr [ebp + 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */));
    // 004b35c2  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b35c4  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b35c7  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b35ca  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b35cd  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b35d0  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b35d3  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b35d6  83e904                 +sub ecx, 4
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
    // 004b35d9  7fc0                   -jg 0x4b359b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b359b;
    }
    // 004b35db  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b35de:
    // 004b35de  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b35e1  7e15                   -jle 0x4b35f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b35f8;
    }
    // 004b35e3  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b35e5  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b35e7  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b35ea  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b35ed  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b35f0  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b35f3  83e901                 +sub ecx, 1
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
    // 004b35f6  7fe6                   -jg 0x4b35de
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b35de;
    }
L_0x004b35f8:
    // 004b35f8  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b35fa  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b35fb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b35fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b35fd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b35fd);
    // 004b35fd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b35fe  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b3600  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b3601  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b3604  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b3607  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b360a  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b360d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b3610  83f903                 +cmp ecx, 3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3613  7e47                   -jle 0x4b365c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b365c;
    }
    // 004b3615  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b3618:
    // 004b3618  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b361b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b361d  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004b3620  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b3622  d94714                 -fld dword ptr [edi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */)));
    // 004b3625  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b3627  d9471c                 -fld dword ptr [edi + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(28) /* 0x1c */)));
    // 004b362a  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b362c  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b362e  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b3631  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b3633  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b3636  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3638  d84514                 -fadd dword ptr [ebp + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */));
    // 004b363b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b363d  d8451c                 -fadd dword ptr [ebp + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */));
    // 004b3640  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b3642  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3645  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3648  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b364b  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b364e  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b3651  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b3654  83e904                 +sub ecx, 4
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
    // 004b3657  7fbf                   -jg 0x4b3618
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b3618;
    }
    // 004b3659  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b365c:
    // 004b365c  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b365f  7e16                   -jle 0x4b3677
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b3677;
    }
    // 004b3661  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b3664  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b3666  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b3669  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b366c  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b366f  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3672  83e901                 +sub ecx, 1
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
    // 004b3675  7fe5                   -jg 0x4b365c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b365c;
    }
L_0x004b3677:
    // 004b3677  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3679  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b367a  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b367b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b367c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b367c);
    // 004b367c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b367d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b367f  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b3680  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b3683  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b3686  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b3689  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004b368b  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b368e  83f901                 +cmp ecx, 1
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
    // 004b3691  7e42                   -jle 0x4b36d5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b36d5;
    }
    // 004b3693  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b3696:
    // 004b3696  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b3698  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b369a  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b369d  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004b36a0  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b36a2  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004b36a5  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b36a7  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b36aa  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b36ac  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b36af  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b36b1  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b36b4  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b36b6  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b36b9  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b36bb  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b36be  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b36c1  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b36c4  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b36c7  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b36ca  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b36cd  83e902                 +sub ecx, 2
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
    // 004b36d0  7fc4                   -jg 0x4b3696
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b3696;
    }
    // 004b36d2  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b36d5:
    // 004b36d5  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b36d8  7e24                   -jle 0x4b36fe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b36fe;
    }
    // 004b36da  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b36dc  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b36de  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b36e1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b36e3  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b36e6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b36e8  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b36eb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b36ed  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b36f0  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b36f3  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b36f6  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b36f9  83e901                 +sub ecx, 1
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
    // 004b36fc  7fd7                   -jg 0x4b36d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b36d5;
    }
L_0x004b36fe:
    // 004b36fe  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3700  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b3701  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3702  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3703(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3703);
    // 004b3703  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3704  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b3706  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b3707  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b370a  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b370d  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b3710  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b3713  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b3716  83f901                 +cmp ecx, 1
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
    // 004b3719  7e42                   -jle 0x4b375d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b375d;
    }
    // 004b371b  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b371e:
    // 004b371e  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b3720  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b3723  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b3725  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004b3728  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004b372b  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b372d  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b372f  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b3732  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b3734  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b3737  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3739  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b373c  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b373e  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b3741  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b3743  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3746  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3749  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b374c  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b374f  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b3752  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b3755  83e902                 +sub ecx, 2
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
    // 004b3758  7fc4                   -jg 0x4b371e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b371e;
    }
    // 004b375a  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b375d:
    // 004b375d  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3760  7e24                   -jle 0x4b3786
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b3786;
    }
    // 004b3762  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b3764  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b3767  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b3769  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b376b  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b376e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3770  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b3773  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b3775  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3778  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b377b  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b377e  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3781  83e901                 +sub ecx, 1
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
    // 004b3784  7fd7                   -jg 0x4b375d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b375d;
    }
L_0x004b3786:
    // 004b3786  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3788  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b3789  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b378a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b378b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b378b);
    // 004b378b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b378c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b378e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b378f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3790);
    // 004b3790  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3791  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b3793  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3794  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b3797  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004b379d  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004b37a4  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b37a7  c700d0374b00           -mov dword ptr [eax], 0x4b37d0
    app->getMemory<x86::reg32>(cpu.eax) = 4929488 /*0x4b37d0*/;
    // 004b37ad  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b37b0  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b37b3  c700e5374b00           -mov dword ptr [eax], 0x4b37e5
    app->getMemory<x86::reg32>(cpu.eax) = 4929509 /*0x4b37e5*/;
    // 004b37b9  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b37bc  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b37bf  c7002b384b00           -mov dword ptr [eax], 0x4b382b
    app->getMemory<x86::reg32>(cpu.eax) = 4929579 /*0x4b382b*/;
    // 004b37c5  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b37c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b37c9  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004b37ce  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b37cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b37d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b37d0);
    // 004b37d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b37d1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b37d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b37d4  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b37d7  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b37da  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b37dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b37de  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004b37e3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b37e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b37e5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b37e5);
    // 004b37e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b37e6  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b37e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b37e9  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b37ec  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b37f3  7c08                   -jl 0x4b37fd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b37fd;
    }
    // 004b37f5  7f1e                   -jg 0x4b3815
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b3815;
    }
    // 004b37f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b37f8  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b37fb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b37fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b37fd:
    // 004b37fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b37fe  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b3801  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b3804  4a                     -dec edx
    (cpu.edx)--;
    // 004b3805  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b3808  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004b380a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b380b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b380e  40                     -inc eax
    (cpu.eax)++;
    // 004b380f  2b460c                 -sub eax, dword ptr [esi + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 004b3812  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3813  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3814  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3815:
    // 004b3815  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3816  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b3819  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b381c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b381f  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004b3821  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3822  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b3825  2b460c                 -sub eax, dword ptr [esi + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 004b3828  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3829  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b382a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b382b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b382b);
    // 004b382b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b382c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b382e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b382f  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b3832  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3839  750f                   -jne 0x4b384a
    if (!cpu.flags.zf)
    {
        goto L_0x004b384a;
    }
    // 004b383b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b383c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b383d  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b3840  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b3843  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004b3845  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3846  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3847  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3848  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3849  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b384a:
    // 004b384a  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b384b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b384d  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b3850  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b3853  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b3856  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b3859  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004b385b  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004b385e  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b3861  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b3863  a34ce34d00             -mov dword ptr [0x4de34c], eax
    app->getMemory<x86::reg32>(x86::reg32(5104460) /* 0x4de34c */) = cpu.eax;
    // 004b3868  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b386b  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b386e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b386f  c1ee02                 -shr esi, 2
    cpu.esi >>= 2 /*0x2*/ % 32;
    // 004b3872  8beb                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004b3874  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004b3877  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004b387a  83f801                 +cmp eax, 1
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
    // 004b387d  751c                   -jne 0x4b389b
    if (!cpu.flags.zf)
    {
        goto L_0x004b389b;
    }
    // 004b387f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3880  be00000000             -mov esi, 0
    cpu.esi = 0 /*0x0*/;
L_0x004b3885:
    // 004b3885  a14ce34d00             -mov eax, dword ptr [0x4de34c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104460) /* 0x4de34c */);
    // 004b388a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b388c  03d5                   +add edx, ebp
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b388e  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004b3890  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3893  83fe00                 +cmp esi, 0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3896  74ed                   -je 0x4b3885
    if (cpu.flags.zf)
    {
        goto L_0x004b3885;
    }
    // 004b3898  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3899  90                     -nop 
    ;
    // 004b389a  90                     -nop 
    ;
L_0x004b389b:
    // 004b389b  8b04b500000000         -mov eax, dword ptr [esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi * 4);
    // 004b38a2  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b38a4  03d5                   +add edx, ebp
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b38a6  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004b38a8  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b38ab  3bf9                   +cmp edi, ecx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b38ad  7cec                   -jl 0x4b389b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b389b;
    }
    // 004b38af  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b38b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b38b3  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b38b6  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b38b8  3b5e04                 +cmp ebx, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b38bb  7c11                   -jl 0x4b38ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b38ce;
    }
    // 004b38bd  8b47fc                 -mov eax, dword ptr [edi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 004b38c0  c7460c01000000         -mov dword ptr [esi + 0xc], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 004b38c7  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b38ca  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b38cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b38cc  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b38cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b38ce:
    // 004b38ce  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004b38d5  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b38d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b38d7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b38d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4b38dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b38dc);
    // 004b38dc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b38dd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b38df  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b38e0  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b38e3  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004b38e9  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b38f0  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b38f3  c7001c394b00           -mov dword ptr [eax], 0x4b391c
    app->getMemory<x86::reg32>(cpu.eax) = 4929820 /*0x4b391c*/;
    // 004b38f9  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b38fc  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b38ff  c70031394b00           -mov dword ptr [eax], 0x4b3931
    app->getMemory<x86::reg32>(cpu.eax) = 4929841 /*0x4b3931*/;
    // 004b3905  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b3908  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b390b  c70077394b00           -mov dword ptr [eax], 0x4b3977
    app->getMemory<x86::reg32>(cpu.eax) = 4929911 /*0x4b3977*/;
    // 004b3911  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004b3914  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3915  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004b391a  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b391b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b391c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b391c);
    // 004b391c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b391d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b391f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3920  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b3923  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b3926  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b3929  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b392a  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004b392f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3930  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3931(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3931);
    // 004b3931  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3932  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b3934  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3935  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b3938  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b393f  7c08                   -jl 0x4b3949
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b3949;
    }
    // 004b3941  7f1e                   -jg 0x4b3961
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b3961;
    }
    // 004b3943  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3944  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b3947  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3948  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3949:
    // 004b3949  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b394a  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b394d  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b3950  4a                     -dec edx
    (cpu.edx)--;
    // 004b3951  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b3954  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004b3956  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3957  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b395a  40                     -inc eax
    (cpu.eax)++;
    // 004b395b  2b4610                 -sub eax, dword ptr [esi + 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 004b395e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b395f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3960  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3961:
    // 004b3961  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3962  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b3965  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b3968  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b396b  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004b396d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b396e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b3971  2b4610                 -sub eax, dword ptr [esi + 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 004b3974  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3975  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3976  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3977(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3977);
    // 004b3977  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3978  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b397a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b397b  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b397e  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3985  750f                   -jne 0x4b3996
    if (!cpu.flags.zf)
    {
        goto L_0x004b3996;
    }
    // 004b3987  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3988  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3989  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b398c  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b398f  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004b3991  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3992  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3993  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3994  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3995  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3996:
    // 004b3996  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b3997  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b3999  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b399c  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b399f  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b39a2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b39a5  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004b39a7  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 004b39aa  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b39ad  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b39af  a354e34d00             -mov dword ptr [0x4de354], eax
    app->getMemory<x86::reg32>(x86::reg32(5104468) /* 0x4de354 */) = cpu.eax;
    // 004b39b4  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b39b7  a358e34d00             -mov dword ptr [0x4de358], eax
    app->getMemory<x86::reg32>(x86::reg32(5104472) /* 0x4de358 */) = cpu.eax;
    // 004b39bc  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004b39bf  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b39c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b39c3  c1ee03                 -shr esi, 3
    cpu.esi >>= 3 /*0x3*/ % 32;
    // 004b39c6  8beb                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004b39c8  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004b39cb  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004b39ce  83f801                 +cmp eax, 1
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
    // 004b39d1  7522                   -jne 0x4b39f5
    if (!cpu.flags.zf)
    {
        goto L_0x004b39f5;
    }
    // 004b39d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b39d4  be00000000             -mov esi, 0
    cpu.esi = 0 /*0x0*/;
L_0x004b39d9:
    // 004b39d9  a154e34d00             -mov eax, dword ptr [0x4de354]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104468) /* 0x4de354 */);
    // 004b39de  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b39e0  a158e34d00             -mov eax, dword ptr [0x4de358]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104472) /* 0x4de358 */);
    // 004b39e5  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b39e8  03d5                   +add edx, ebp
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b39ea  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004b39ec  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b39ef  83fe00                 +cmp esi, 0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b39f2  74e5                   -je 0x4b39d9
    if (cpu.flags.zf)
    {
        goto L_0x004b39d9;
    }
    // 004b39f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004b39f5:
    // 004b39f5  892550e34d00           -mov dword ptr [0x4de350], esp
    app->getMemory<x86::reg32>(x86::reg32(5104464) /* 0x4de350 */) = cpu.esp;
    // 004b39fb  90                     -nop 
    ;
L_0x004b39fc:
    // 004b39fc  8b04f500000000         -mov eax, dword ptr [esi*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi * 8);
    // 004b3a03  8b24f504000000         -mov esp, dword ptr [esi*8 + 4]
    cpu.esp = app->getMemory<x86::reg32>(x86::reg32(4) /* 0x4 */ + cpu.esi * 8);
    // 004b3a0a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b3a0c  896704                 -mov dword ptr [edi + 4], esp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.esp;
    // 004b3a0f  03d5                   +add edx, ebp
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3a11  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004b3a13  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b3a16  3bf9                   +cmp edi, ecx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3a18  7ce2                   -jl 0x4b39fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b39fc;
    }
    // 004b3a1a  8b2550e34d00           -mov esp, dword ptr [0x4de350]
    cpu.esp = app->getMemory<x86::reg32>(x86::reg32(5104464) /* 0x4de350 */);
    // 004b3a20  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b3a23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a24  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b3a27  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b3a29  3b5e04                 +cmp ebx, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3a2c  7c17                   -jl 0x4b3a45
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b3a45;
    }
    // 004b3a2e  8b47f8                 -mov eax, dword ptr [edi - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */);
    // 004b3a31  c7461001000000         -mov dword ptr [esi + 0x10], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004b3a38  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b3a3b  8b47fc                 -mov eax, dword ptr [edi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 004b3a3e  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b3a41  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b3a42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a43  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3a45:
    // 004b3a45  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b3a4c  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004b3a4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a4e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3a50);
    // 004b3a50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3a51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3a52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3a53  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b3a57  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b3a5b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b3a5e  48                     -dec eax
    (cpu.eax)--;
    // 004b3a5f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b3a62  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b3a65  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b3a68  8b5a13                 -mov ebx, dword ptr [edx + 0x13]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004b3a6b  40                     -inc eax
    (cpu.eax)++;
    // 004b3a6c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004b3a6f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b3a71  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b3a73  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004b3a76  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b3a78  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b3a7a  7501                   -jne 0x4b3a7d
    if (!cpu.flags.zf)
    {
        goto L_0x004b3a7d;
    }
    // 004b3a7c  40                     -inc eax
    (cpu.eax)++;
L_0x004b3a7d:
    // 004b3a7d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b3a81  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b3a84  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b3a87  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004b3a8a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b3a8d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b3a8f  885116                 -mov byte ptr [ecx + 0x16], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(22) /* 0x16 */) = cpu.dl;
    // 004b3a92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a94  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3a95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b3a98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3a98);
    // 004b3a98  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b3a9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b3aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3aa0);
    // 004b3aa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3aa1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b3aa5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3aa9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b3aac  48                     -dec eax
    (cpu.eax)--;
    // 004b3aad  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b3ab0  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b3ab3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b3ab5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b3ab8  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004b3abb  40                     -inc eax
    (cpu.eax)++;
    // 004b3abc  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b3abe  7501                   -jne 0x4b3ac1
    if (!cpu.flags.zf)
    {
        goto L_0x004b3ac1;
    }
    // 004b3ac0  40                     -inc eax
    (cpu.eax)++;
L_0x004b3ac1:
    // 004b3ac1  8b5111                 -mov edx, dword ptr [ecx + 0x11]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 004b3ac4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b3ac7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3ac9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3aca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b3acc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3acc);
    // 004b3acc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3acd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3ace  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3acf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3ad0  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b3ad3  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b3ad7  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b3adb  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b3adf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b3ae1  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004b3ae4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b3ae6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b3ae8  7571                   -jne 0x4b3b5b
    if (!cpu.flags.zf)
    {
        goto L_0x004b3b5b;
    }
L_0x004b3aea:
    // 004b3aea  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b3aee  4f                     -dec edi
    (cpu.edi)--;
    // 004b3aef  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b3af2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b3af4  7f6f                   -jg 0x4b3b65
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b3b65;
    }
L_0x004b3af6:
    // 004b3af6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3af8  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b3afb  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b3aff  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b3b02  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004b3b05  dc0d24f74c00           -fmul qword ptr [0x4cf724]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5044004) /* 0x4cf724 */));
    // 004b3b0b  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b3b0d  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004b3b0f  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004b3b11  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3b13  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004b3b17  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b3b19  d80c86                 -fmul dword ptr [esi + eax*4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 4));
    // 004b3b1c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b3b1e  d95cbd00               -fstp dword ptr [ebp + edi*4]
    app->getMemory<float>(cpu.ebp + cpu.edi * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3b22  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3b24  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b3b27  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004b3b2b  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3b2e  d95b10                 -fstp dword ptr [ebx + 0x10]
    app->getMemory<float>(cpu.ebx + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3b31  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b3b33  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3b35  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3b37  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b3b3a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b3b3d  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b3b43  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b3b45  8b4313                 -mov eax, dword ptr [ebx + 0x13]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(19) /* 0x13 */);
    // 004b3b48  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 004b3b4a  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b3b4d  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004b3b51  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b3b53  83c414                 +add esp, 0x14
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
    // 004b3b56  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3b57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3b58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3b59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3b5a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3b5b:
    // 004b3b5b  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b3b5e  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004b3b61  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b3b63  eb85                   -jmp 0x4b3aea
    goto L_0x004b3aea;
L_0x004b3b65:
    // 004b3b65  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3b68  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3b6b  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b3b6e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b3b71  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b3b74  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3b75  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b3b78  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3b79  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b3b7d  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b3b81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3b82  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3b83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3b84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3b85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3b86  e889620000             -call 0x4b9e14
    cpu.esp -= 4;
    sub_4b9e14(app, cpu);
    if (cpu.terminate) return;
    // 004b3b8b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b3b8e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b3b92  c1e810                 +shr eax, 0x10
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
    // 004b3b95  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b3b98  e959ffffff             -jmp 0x4b3af6
    goto L_0x004b3af6;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b3ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3ba0);
    // 004b3ba0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b3ba4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3ba8  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b3baa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b3bac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3bac);
    // 004b3bac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3bad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3bae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3baf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3bb0  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b3bb3  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b3bb7  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b3bbb  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b3bbf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b3bc1  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004b3bc4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b3bc6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b3bc8  0f85c5000000           -jne 0x4b3c93
    if (!cpu.flags.zf)
    {
        goto L_0x004b3c93;
    }
L_0x004b3bce:
    // 004b3bce  807b1400               +cmp byte ptr [ebx + 0x14], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b3bd2  7409                   -je 0x4b3bdd
    if (cpu.flags.zf)
    {
        goto L_0x004b3bdd;
    }
    // 004b3bd4  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b3bd7  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004b3bda  83ee04                 +sub esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004b3bdd:
    // 004b3bdd  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b3be1  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004b3be7  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b3bea  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b3beb  7433                   -je 0x4b3c20
    if (cpu.flags.zf)
    {
        goto L_0x004b3c20;
    }
    // 004b3bed  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3bf0  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3bf3  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b3bf6  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b3bf9  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b3bfc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3bfd  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b3c00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3c01  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b3c05  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b3c09  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3c0a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3c0b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3c0c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3c0d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3c0e  e801620000             -call 0x4b9e14
    cpu.esp -= 4;
    sub_4b9e14(app, cpu);
    if (cpu.terminate) return;
    // 004b3c13  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b3c16  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b3c1a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b3c1d  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004b3c20:
    // 004b3c20  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3c22  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b3c25  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b3c29  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b3c2c  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004b3c2f  dc0d2cf74c00           -fmul qword ptr [0x4cf72c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5044012) /* 0x4cf72c */));
    // 004b3c35  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b3c37  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004b3c39  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004b3c3b  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3c3d  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004b3c41  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b3c43  d80c86                 -fmul dword ptr [esi + eax*4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 4));
    // 004b3c46  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b3c48  d95cbd00               -fstp dword ptr [ebp + edi*4]
    app->getMemory<float>(cpu.ebp + cpu.edi * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3c4c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3c4e  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b3c51  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3c53  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004b3c57  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3c5a  8b6b08                 -mov ebp, dword ptr [ebx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3c5d  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b3c5f  d95b10                 -fstp dword ptr [ebx + 0x10]
    app->getMemory<float>(cpu.ebx + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3c62  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3c64  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b3c67  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b3c6a  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b3c70  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b3c72  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b3c75  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004b3c77  39e8                   +cmp eax, ebp
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
    // 004b3c79  7225                   -jb 0x4b3ca0
    if (cpu.flags.cf)
    {
        goto L_0x004b3ca0;
    }
    // 004b3c7b  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3c7d  c6431401               -mov byte ptr [ebx + 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004b3c81  8b1486                 -mov edx, dword ptr [esi + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004b3c84  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004b3c87  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004b3c8b  83c414                 +add esp, 0x14
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
    // 004b3c8e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c8f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3c92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3c93:
    // 004b3c93  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b3c96  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004b3c99  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b3c9b  e92effffff             -jmp 0x4b3bce
    goto L_0x004b3bce;
L_0x004b3ca0:
    // 004b3ca0  c6431400               -mov byte ptr [ebx + 0x14], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b3ca4  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004b3ca8  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b3cab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3cac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3cad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3cae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3caf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b3cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3cb0);
    // 004b3cb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3cb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3cb2  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3cb6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b3cba  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b3cbd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3cbf  81fb00000100           +cmp ebx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3cc5  732c                   -jae 0x4b3cf3
    if (!cpu.flags.cf)
    {
        goto L_0x004b3cf3;
    }
    // 004b3cc7  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3ccd  7324                   -jae 0x4b3cf3
    if (!cpu.flags.cf)
    {
        goto L_0x004b3cf3;
    }
L_0x004b3ccf:
    // 004b3ccf  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b3cd2  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3cd8  724b                   -jb 0x4b3d25
    if (cpu.flags.cf)
    {
        goto L_0x004b3d25;
    }
    // 004b3cda  7660                   -jbe 0x4b3d3c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3d3c;
    }
    // 004b3cdc  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b3cdf  c702503a4b00           -mov dword ptr [edx], 0x4b3a50
    app->getMemory<x86::reg32>(cpu.edx) = 4930128 /*0x4b3a50*/;
    // 004b3ce5  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b3ce8  c700cc3a4b00           -mov dword ptr [eax], 0x4b3acc
    app->getMemory<x86::reg32>(cpu.eax) = 4930252 /*0x4b3acc*/;
    // 004b3cee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3cf0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3cf1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3cf2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3cf3:
    // 004b3cf3  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b3cf6  39f2                   +cmp edx, esi
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
    // 004b3cf8  74d5                   -je 0x4b3ccf
    if (cpu.flags.zf)
    {
        goto L_0x004b3ccf;
    }
    // 004b3cfa  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3d00  7608                   -jbe 0x4b3d0a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b3d0a;
    }
    // 004b3d02  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b3d08  77c5                   -ja 0x4b3ccf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b3ccf;
    }
L_0x004b3d0a:
    // 004b3d0a  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b3d0e  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004b3d12  c6401600               -mov byte ptr [eax + 0x16], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 004b3d16  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b3d1d  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b3d23  ebaa                   -jmp 0x4b3ccf
    goto L_0x004b3ccf;
L_0x004b3d25:
    // 004b3d25  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b3d28  c702a03a4b00           -mov dword ptr [edx], 0x4b3aa0
    app->getMemory<x86::reg32>(cpu.edx) = 4930208 /*0x4b3aa0*/;
    // 004b3d2e  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b3d31  c700ac3b4b00           -mov dword ptr [eax], 0x4b3bac
    app->getMemory<x86::reg32>(cpu.eax) = 4930476 /*0x4b3bac*/;
    // 004b3d37  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3d39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3d3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3d3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3d3c:
    // 004b3d3c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b3d3f  c702983a4b00           -mov dword ptr [edx], 0x4b3a98
    app->getMemory<x86::reg32>(cpu.edx) = 4930200 /*0x4b3a98*/;
    // 004b3d45  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b3d48  c700a03b4b00           -mov dword ptr [eax], 0x4b3ba0
    app->getMemory<x86::reg32>(cpu.eax) = 4930464 /*0x4b3ba0*/;
    // 004b3d4e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3d50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3d51  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3d52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b3d54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3d54);
    // 004b3d54  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b3d58  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b3d5e  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b3d65  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b3d69  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b3d70  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004b3d74  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b3d78  c6401601               -mov byte ptr [eax + 0x16], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 1 /*0x1*/;
    // 004b3d7c  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b3d7f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3d83  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b3d86  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b3d8a  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b3d8d  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b3d90  c700b03c4b00           -mov dword ptr [eax], 0x4b3cb0
    app->getMemory<x86::reg32>(cpu.eax) = 4930736 /*0x4b3cb0*/;
    // 004b3d96  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b3d98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b3da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3da0);
    // 004b3da0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3da1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3da2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3da3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b3da7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b3dab  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b3dae  48                     -dec eax
    (cpu.eax)--;
    // 004b3daf  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b3db2  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b3db5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b3db8  8b5a1b                 -mov ebx, dword ptr [edx + 0x1b]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(27) /* 0x1b */);
    // 004b3dbb  40                     -inc eax
    (cpu.eax)++;
    // 004b3dbc  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004b3dbf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b3dc1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b3dc3  8a5a1d                 -mov bl, byte ptr [edx + 0x1d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(29) /* 0x1d */);
    // 004b3dc6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b3dc8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b3dca  7501                   -jne 0x4b3dcd
    if (!cpu.flags.zf)
    {
        goto L_0x004b3dcd;
    }
    // 004b3dcc  40                     -inc eax
    (cpu.eax)++;
L_0x004b3dcd:
    // 004b3dcd  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b3dd1  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b3dd4  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b3dd7  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004b3dda  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b3ddd  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b3ddf  88511e                 -mov byte ptr [ecx + 0x1e], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.dl;
    // 004b3de2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3de3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3de4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3de5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b3de8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3de8);
    // 004b3de8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b3dec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b3df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3df0);
    // 004b3df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3df1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b3df5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3df9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b3dfc  48                     -dec eax
    (cpu.eax)--;
    // 004b3dfd  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b3e00  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b3e03  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b3e05  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b3e08  8a5a1d                 -mov bl, byte ptr [edx + 0x1d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(29) /* 0x1d */);
    // 004b3e0b  40                     -inc eax
    (cpu.eax)++;
    // 004b3e0c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b3e0e  7501                   -jne 0x4b3e11
    if (!cpu.flags.zf)
    {
        goto L_0x004b3e11;
    }
    // 004b3e10  40                     -inc eax
    (cpu.eax)++;
L_0x004b3e11:
    // 004b3e11  8b5119                 -mov edx, dword ptr [ecx + 0x19]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(25) /* 0x19 */);
    // 004b3e14  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b3e17  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3e19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3e1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b3e1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3e1c);
    // 004b3e1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3e1d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3e1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3e1f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3e20  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b3e23  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b3e27  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b3e2b  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b3e2f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b3e31  8a481d                 -mov cl, byte ptr [eax + 0x1d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */);
    // 004b3e34  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b3e36  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b3e38  0f8598000000           -jne 0x4b3ed6
    if (!cpu.flags.zf)
    {
        goto L_0x004b3ed6;
    }
L_0x004b3e3e:
    // 004b3e3e  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b3e42  4f                     -dec edi
    (cpu.edi)--;
    // 004b3e43  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b3e46  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b3e48  0f8f9d000000           -jg 0x4b3eeb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b3eeb;
    }
L_0x004b3e4e:
    // 004b3e4e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3e50  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b3e53  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b3e57  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b3e5a  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004b3e5d  dc0d34f74c00           -fmul qword ptr [0x4cf734]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5044020) /* 0x4cf734 */));
    // 004b3e63  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b3e65  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004b3e67  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004b3e69  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3e6b  d944c608               -fld dword ptr [esi + eax*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8)));
    // 004b3e6f  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b3e71  d904c6                 -fld dword ptr [esi + eax*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 8)));
    // 004b3e74  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b3e76  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b3e78  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004b3e7f  d91c28                 -fstp dword ptr [eax + ebp]
    app->getMemory<float>(cpu.eax + cpu.ebp * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3e82  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3e84  d84cfe04               -fmul dword ptr [esi + edi*8 + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edi * 8));
    // 004b3e88  d944fe0c               -fld dword ptr [esi + edi*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edi * 8)));
    // 004b3e8c  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b3e8e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b3e90  d95c2804               -fstp dword ptr [eax + ebp + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3e94  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3e96  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b3e99  d944c608               -fld dword ptr [esi + eax*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8)));
    // 004b3e9d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3e9f  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3ea2  d944c60c               -fld dword ptr [esi + eax*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.eax * 8)));
    // 004b3ea6  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3ea9  d95b18                 -fstp dword ptr [ebx + 0x18]
    app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3eac  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b3eae  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3eb0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b3eb2  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b3eb5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b3eb8  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b3ebe  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b3ec0  8b431b                 -mov eax, dword ptr [ebx + 0x1b]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(27) /* 0x1b */);
    // 004b3ec3  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 004b3ec5  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b3ec8  c6431d01               -mov byte ptr [ebx + 0x1d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = 1 /*0x1*/;
    // 004b3ecc  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b3ece  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b3ed1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ed2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ed3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ed4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b3ed5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b3ed6:
    // 004b3ed6  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b3ed9  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b3edc  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b3ede  83ee04                 +sub esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b3ee1  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b3ee4  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b3ee6  e953ffffff             -jmp 0x4b3e3e
    goto L_0x004b3e3e;
L_0x004b3eeb:
    // 004b3eeb  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3eee  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3ef1  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b3ef4  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004b3ef7  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b3efa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3efb  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b3efe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3eff  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b3f03  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b3f07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3f08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3f09  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3f0a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3f0b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3f0c  e8f35f0000             -call 0x4b9f04
    cpu.esp -= 4;
    sub_4b9f04(app, cpu);
    if (cpu.terminate) return;
    // 004b3f11  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b3f14  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b3f18  c1e810                 +shr eax, 0x10
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
    // 004b3f1b  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b3f1e  e92bffffff             -jmp 0x4b3e4e
    goto L_0x004b3e4e;
}

/* align: skip 0x90 */
void Application::sub_4b3f24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3f24);
    // 004b3f24  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b3f28  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b3f2c  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b3f2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
