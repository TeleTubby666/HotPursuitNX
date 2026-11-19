#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484a44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484a44  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484a45  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00484a48  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00484a4b  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00484a4e  ff5248                 -call dword ptr [edx + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484a51  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484a53  7408                   -je 0x484a5d
    if (cpu.flags.zf)
    {
        goto L_0x00484a5d;
    }
    // 00484a55  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484a57  66a1ecaf4c00           -mov ax, word ptr [0x4cafec]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5025772) /* 0x4cafec */);
L_0x00484a5d:
    // 00484a5d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484a60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484a61  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00484a64  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00484a67  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00484a6a  ff524c                 -call dword ptr [edx + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484a6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484a70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484a70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484a71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484a72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484a73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484a74  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00484a77  8954246c               -mov dword ptr [esp + 0x6c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 00484a7b  895c2468               -mov dword ptr [esp + 0x68], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebx;
    // 00484a7f  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00484a84  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00484a86  bea02e4800             -mov esi, 0x482ea0
    cpu.esi = 4730528 /*0x482ea0*/;
    // 00484a8b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484a8d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00484a8f  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00484a92  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00484a94  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00484a98  83c730                 -add edi, 0x30
    (cpu.edi) += x86::reg32(x86::sreg32(48 /*0x30*/));
L_0x00484a9b:
    // 00484a9b  ba746164ea             -mov edx, 0xea646174
    cpu.edx = 3932447092 /*0xea646174*/;
    // 00484aa0  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00484aa5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00484aa7  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 00484aab  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00484aaf  8b4c2468               -mov ecx, dword ptr [esp + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00484ab3  e848cbffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00484ab8  8d5c2464               -lea ebx, [esp + 0x64]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00484abc  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 00484abf  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00484ac3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484ac4  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00484ac7  8b4c2470               -mov ecx, dword ptr [esp + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 00484acb  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00484ace  ff5654                 -call dword ptr [esi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484ad1  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00484ad5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484ad7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00484ad9  746c                   -je 0x484b47
    if (cpu.flags.zf)
    {
        goto L_0x00484b47;
    }
    // 00484adb  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 00484ade  83781800               +cmp dword ptr [eax + 0x18], 0
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
    // 00484ae2  7505                   -jne 0x484ae9
    if (!cpu.flags.zf)
    {
        goto L_0x00484ae9;
    }
    // 00484ae4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00484ae6  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x00484ae9:
    // 00484ae9  8b4c246c               -mov ecx, dword ptr [esp + 0x6c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00484aed  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00484af1  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 00484af4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484af5  8d542454               -lea edx, [esp + 0x54]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00484af9  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00484afc  e83be8ffff             -call 0x48333c
    cpu.esp -= 4;
    sub_48333c(app, cpu);
    if (cpu.terminate) return;
    // 00484b01  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 00484b04  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00484b06  3b5018                 +cmp edx, dword ptr [eax + 0x18]
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
    // 00484b09  7507                   -jne 0x484b12
    if (!cpu.flags.zf)
    {
        goto L_0x00484b12;
    }
    // 00484b0b  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x00484b12:
    // 00484b12  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00484b16  81fb746164ea           +cmp ebx, 0xea646174
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
    // 00484b1c  7418                   -je 0x484b36
    if (cpu.flags.zf)
    {
        goto L_0x00484b36;
    }
    // 00484b1e  81fb216f6eea           +cmp ebx, 0xea6e6f21
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
    // 00484b24  0f8571ffffff           -jne 0x484a9b
    if (!cpu.flags.zf)
    {
        goto L_0x00484a9b;
    }
    // 00484b2a  c7450400000000         -mov dword ptr [ebp + 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00484b31  e965ffffff             -jmp 0x484a9b
    goto L_0x00484a9b;
L_0x00484b36:
    // 00484b36  c7454401000000         -mov dword ptr [ebp + 0x44], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(68) /* 0x44 */) = 1 /*0x1*/;
    // 00484b3d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00484b3f  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00484b42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b46  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484b47:
    // 00484b47  8b4548                 -mov eax, dword ptr [ebp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */);
    // 00484b4a  83b8a800000000         +cmp dword ptr [eax + 0xa8], 0
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
    // 00484b51  7512                   -jne 0x484b65
    if (!cpu.flags.zf)
    {
        goto L_0x00484b65;
    }
    // 00484b53  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 00484b58  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00484b5b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484b5d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00484b5f  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00484b62  ff5658                 -call dword ptr [esi + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00484b65:
    // 00484b65  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00484b67  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00484b69  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00484b6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484b74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484b74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484b75  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484b76  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484b77  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484b78  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00484b7b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484b7d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00484b80  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00484b82  ba746164ea             -mov edx, 0xea646174
    cpu.edx = 3932447092 /*0xea646174*/;
    // 00484b87  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00484b8b  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00484b8f  83784400               +cmp dword ptr [eax + 0x44], 0
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
    // 00484b93  7d35                   -jge 0x484bca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00484bca;
    }
    // 00484b95  ff4844                 -dec dword ptr [eax + 0x44]
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */))--;
    // 00484b98  837844fc               +cmp dword ptr [eax + 0x44], -4
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
    // 00484b9c  7d2c                   -jge 0x484bca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00484bca;
    }
    // 00484b9e  b86e706fea             -mov eax, 0xea6f706e
    cpu.eax = 3933171822 /*0xea6f706e*/;
    // 00484ba3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484ba5  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00484ba9  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00484bac  bb6e706fea             -mov ebx, 0xea6f706e
    cpu.ebx = 3933171822 /*0xea6f706e*/;
    // 00484bb1  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00484bb4  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00484bb7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484bb9  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00484bbc  ff5550                 -call dword ptr [ebp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484bbf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484bc1  7407                   -je 0x484bca
    if (cpu.flags.zf)
    {
        goto L_0x00484bca;
    }
    // 00484bc3  c74644ffffffff         -mov dword ptr [esi + 0x44], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */) = 4294967295 /*0xffffffff*/;
L_0x00484bca:
    // 00484bca  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00484bce  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00484bd2  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00484bd5  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00484bd8  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00484bdc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484bdd  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00484be0  83c230                 -add edx, 0x30
    (cpu.edx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00484be3  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00484be6  ff5650                 -call dword ptr [esi + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484be9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484beb  7402                   -je 0x484bef
    if (cpu.flags.zf)
    {
        goto L_0x00484bef;
    }
    // 00484bed  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00484bef:
    // 00484bef  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00484bf2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bf3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bf4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bf5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bf6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_484c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484c00  6d                     -insd dword ptr es:[edi], dx
    NFS2_ASSERT(false);
    // 00484c01  61                     -popal 
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
    // 00484c02  67eaffffffff5152       -ljmp 0x5251:0xffffffff
    NFS2_ASSERT(false);
    // 00484c0a  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484c11  3b0554de5100           +cmp eax, dword ptr [0x51de54]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5365332) /* 0x51de54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484c17  7208                   -jb 0x484c21
    if (cpu.flags.cf)
    {
        goto L_0x00484c21;
    }
    // 00484c19  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484c1e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484c21:
    // 00484c21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484c23  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484c28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484c28  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484c29  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484c2b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00484c2d  833d60de510000         +cmp dword ptr [0x51de60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365344) /* 0x51de60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484c34  7404                   -je 0x484c3a
    if (cpu.flags.zf)
    {
        goto L_0x00484c3a;
    }
    // 00484c36  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484c38  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c39  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484c3a:
    // 00484c3a  ba64de5100             -mov edx, 0x51de64
    cpu.edx = 5365348 /*0x51de64*/;
    // 00484c3f  e8bcc9ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00484c44  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484c49  890d60de5100           -mov dword ptr [0x51de60], ecx
    app->getMemory<x86::reg32>(x86::reg32(5365344) /* 0x51de60 */) = cpu.ecx;
    // 00484c4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484c54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484c54  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484c55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484c56  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484c57  81ec04200000           -sub esp, 0x2004
    (cpu.esp) -= x86::reg32(x86::sreg32(8196 /*0x2004*/));
    // 00484c5d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00484c5f  89942400200000         -mov dword ptr [esp + 0x2000], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8192) /* 0x2000 */) = cpu.edx;
    // 00484c66  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00484c68  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00484c6a  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00484c6f  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00484c71  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00484c76  e885c9ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00484c7b  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00484c7f  8b842400200000         -mov eax, dword ptr [esp + 0x2000]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8192) /* 0x2000 */);
    // 00484c86  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00484c88  e873c9ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00484c8d  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00484c90  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484c97  a358de5100             -mov dword ptr [0x51de58], eax
    app->getMemory<x86::reg32>(x86::reg32(5365336) /* 0x51de58 */) = cpu.eax;
    // 00484c9c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00484c9e:
    // 00484c9e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00484ca0  b800de5100             -mov eax, 0x51de00
    cpu.eax = 5365248 /*0x51de00*/;
    // 00484ca5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00484ca7  e8c4c2ffff             -call 0x480f70
    cpu.esp -= 4;
    sub_480f70(app, cpu);
    if (cpu.terminate) return;
    // 00484cac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484cae  751a                   -jne 0x484cca
    if (!cpu.flags.zf)
    {
        goto L_0x00484cca;
    }
    // 00484cb0  3b0d04de5100           +cmp ecx, dword ptr [0x51de04]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5365252) /* 0x51de04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484cb6  7412                   -je 0x484cca
    if (cpu.flags.zf)
    {
        goto L_0x00484cca;
    }
    // 00484cb8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00484cba  74e2                   -je 0x484c9e
    if (cpu.flags.zf)
    {
        goto L_0x00484c9e;
    }
    // 00484cbc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484cc1  e80e50ffff             -call 0x479cd4
    cpu.esp -= 4;
    sub_479cd4(app, cpu);
    if (cpu.terminate) return;
    // 00484cc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484cc8  7cd4                   -jl 0x484c9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484c9e;
    }
L_0x00484cca:
    // 00484cca  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00484ccc  0f847c000000           -je 0x484d4e
    if (cpu.flags.zf)
    {
        goto L_0x00484d4e;
    }
    // 00484cd2  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00484cd7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00484cd9:
    // 00484cd9  8b1d60de5100           -mov ebx, dword ptr [0x51de60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5365344) /* 0x51de60 */);
    // 00484cdf  39da                   +cmp edx, ebx
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
    // 00484ce1  7513                   -jne 0x484cf6
    if (!cpu.flags.zf)
    {
        goto L_0x00484cf6;
    }
    // 00484ce3  3b1d04de5100           +cmp ebx, dword ptr [0x51de04]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5365252) /* 0x51de04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484ce9  740b                   -je 0x484cf6
    if (cpu.flags.zf)
    {
        goto L_0x00484cf6;
    }
    // 00484ceb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484ced  e8e24fffff             -call 0x479cd4
    cpu.esp -= 4;
    sub_479cd4(app, cpu);
    if (cpu.terminate) return;
    // 00484cf2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484cf4  7de3                   -jge 0x484cd9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00484cd9;
    }
L_0x00484cf6:
    // 00484cf6  833d60de510000         +cmp dword ptr [0x51de60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365344) /* 0x51de60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484cfd  7420                   -je 0x484d1f
    if (cpu.flags.zf)
    {
        goto L_0x00484d1f;
    }
    // 00484cff  813d64de5100687568ea   +cmp dword ptr [0x51de64], 0xea687568
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365348) /* 0x51de64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932714344 /*0xea687568*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484d09  7520                   -jne 0x484d2b
    if (!cpu.flags.zf)
    {
        goto L_0x00484d2b;
    }
    // 00484d0b  c785a000000000000000   -mov dword ptr [ebp + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 00484d15  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
L_0x00484d1f:
    // 00484d1f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484d21  81c404200000           -add esp, 0x2004
    (cpu.esp) += x86::reg32(x86::sreg32(8196 /*0x2004*/));
    // 00484d27  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d28  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d29  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484d2b:
    // 00484d2b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00484d2d  891560de5100           -mov dword ptr [0x51de60], edx
    app->getMemory<x86::reg32>(x86::reg32(5365344) /* 0x51de60 */) = cpu.edx;
    // 00484d33  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484d3a  a358de5100             -mov dword ptr [0x51de58], eax
    app->getMemory<x86::reg32>(x86::reg32(5365336) /* 0x51de58 */) = cpu.eax;
    // 00484d3f  a164de5100             -mov eax, dword ptr [0x51de64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365348) /* 0x51de64 */);
    // 00484d44  81c404200000           -add esp, 0x2004
    (cpu.esp) += x86::reg32(x86::sreg32(8196 /*0x2004*/));
    // 00484d4a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d4b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d4c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484d4e:
    // 00484d4e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484d53  81c404200000           -add esp, 0x2004
    (cpu.esp) += x86::reg32(x86::sreg32(8196 /*0x2004*/));
    // 00484d59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484d60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484d61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484d62  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484d64  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00484d66  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484d68  740e                   -je 0x484d78
    if (cpu.flags.zf)
    {
        goto L_0x00484d78;
    }
L_0x00484d6a:
    // 00484d6a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484d6c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00484d6e  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00484d70  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484d72  42                     -inc edx
    (cpu.edx)++;
    // 00484d73  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484d75  75f3                   -jne 0x484d6a
    if (!cpu.flags.zf)
    {
        goto L_0x00484d6a;
    }
    // 00484d77  90                     -nop 
    ;
L_0x00484d78:
    // 00484d78  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484d7a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484d80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484d81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484d82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484d83  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00484d86  833d60de510000         +cmp dword ptr [0x51de60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365344) /* 0x51de60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484d8d  0f847e000000           -je 0x484e11
    if (cpu.flags.zf)
    {
        goto L_0x00484e11;
    }
    // 00484d93  833d04de510000         +cmp dword ptr [0x51de04], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365252) /* 0x51de04 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484d9a  7475                   -je 0x484e11
    if (cpu.flags.zf)
    {
        goto L_0x00484e11;
    }
    // 00484d9c  813d64de5100706e61ea   +cmp dword ptr [0x51de64], 0xea616e70
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365348) /* 0x51de64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932253808 /*0xea616e70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484da6  7569                   -jne 0x484e11
    if (!cpu.flags.zf)
    {
        goto L_0x00484e11;
    }
    // 00484da8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484da9  8b2d48de5100           -mov ebp, dword ptr [0x51de48]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5365320) /* 0x51de48 */);
    // 00484daf  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00484db2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00484db4  7452                   -je 0x484e08
    if (cpu.flags.zf)
    {
        goto L_0x00484e08;
    }
    // 00484db6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484db7  be736572ea             -mov esi, 0xea726573
    cpu.esi = 3933365619 /*0xea726573*/;
    // 00484dbc  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00484dc0  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00484dc4  be68de5100             -mov esi, 0x51de68
    cpu.esi = 5365352 /*0x51de68*/;
    // 00484dc9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484dca  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484dcb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484dcc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484dcd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484dce  8b1de8de5100           -mov ebx, dword ptr [0x51dee8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5365480) /* 0x51dee8 */);
    // 00484dd4  ba64de5100             -mov edx, 0x51de64
    cpu.edx = 5365348 /*0x51de64*/;
    // 00484dd9  83c228                 -add edx, 0x28
    (cpu.edx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00484ddc  a148de5100             -mov eax, dword ptr [0x51de48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365320) /* 0x51de48 */);
    // 00484de1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484de3  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484de5  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00484de9  a1e8de5100             -mov eax, dword ptr [0x51dee8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365480) /* 0x51dee8 */);
    // 00484dee  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00484df2  a148de5100             -mov eax, dword ptr [0x51de48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365320) /* 0x51de48 */);
    // 00484df7  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00484dfc  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00484e00  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484e02  e84dfeffff             -call 0x484c54
    cpu.esp -= 4;
    sub_484c54(app, cpu);
    if (cpu.terminate) return;
    // 00484e07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484e08:
    // 00484e08  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484e0a  893d60de5100           -mov dword ptr [0x51de60], edi
    app->getMemory<x86::reg32>(x86::reg32(5365344) /* 0x51de60 */) = cpu.edi;
    // 00484e10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484e11:
    // 00484e11  a148de5100             -mov eax, dword ptr [0x51de48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365320) /* 0x51de48 */);
    // 00484e16  83781400               +cmp dword ptr [eax + 0x14], 0
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
    // 00484e1a  7520                   -jne 0x484e3c
    if (!cpu.flags.zf)
    {
        goto L_0x00484e3c;
    }
    // 00484e1c  833d04de510000         +cmp dword ptr [0x51de04], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365252) /* 0x51de04 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484e23  7420                   -je 0x484e45
    if (cpu.flags.zf)
    {
        goto L_0x00484e45;
    }
    // 00484e25  8b1d58de5100           -mov ebx, dword ptr [0x51de58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5365336) /* 0x51de58 */);
    // 00484e2b  81c310270000           -add ebx, 0x2710
    (cpu.ebx) += x86::reg32(x86::sreg32(10000 /*0x2710*/));
    // 00484e31  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484e38  39d8                   +cmp eax, ebx
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
    // 00484e3a  7709                   -ja 0x484e45
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00484e45;
    }
L_0x00484e3c:
    // 00484e3c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484e3e  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00484e41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484e45:
    // 00484e45  b800de5100             -mov eax, 0x51de00
    cpu.eax = 5365248 /*0x51de00*/;
    // 00484e4a  e839c1ffff             -call 0x480f88
    cpu.esp -= 4;
    sub_480f88(app, cpu);
    if (cpu.terminate) return;
    // 00484e4f  b8804d4800             -mov eax, 0x484d80
    cpu.eax = 4738432 /*0x484d80*/;
    // 00484e54  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00484e56  e8994dffff             -call 0x479bf4
    cpu.esp -= 4;
    sub_479bf4(app, cpu);
    if (cpu.terminate) return;
    // 00484e5b  891550de5100           -mov dword ptr [0x51de50], edx
    app->getMemory<x86::reg32>(x86::reg32(5365328) /* 0x51de50 */) = cpu.edx;
    // 00484e61  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484e63  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00484e66  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484e6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484e6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484e6d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484e6e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484e6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484e70  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484e72  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00484e74  833d04de510000         +cmp dword ptr [0x51de04], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365252) /* 0x51de04 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484e7b  7426                   -je 0x484ea3
    if (cpu.flags.zf)
    {
        goto L_0x00484ea3;
    }
    // 00484e7d  3b0548de5100           +cmp eax, dword ptr [0x51de48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5365320) /* 0x51de48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484e83  7473                   -je 0x484ef8
    if (cpu.flags.zf)
    {
        goto L_0x00484ef8;
    }
    // 00484e85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e86  b800de5100             -mov eax, 0x51de00
    cpu.eax = 5365248 /*0x51de00*/;
    // 00484e8b  e8f8c0ffff             -call 0x480f88
    cpu.esp -= 4;
    sub_480f88(app, cpu);
    if (cpu.terminate) return;
    // 00484e90  b8804d4800             -mov eax, 0x484d80
    cpu.eax = 4738432 /*0x484d80*/;
    // 00484e95  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484e97  e8584dffff             -call 0x479bf4
    cpu.esp -= 4;
    sub_479bf4(app, cpu);
    if (cpu.terminate) return;
    // 00484e9c  893d50de5100           -mov dword ptr [0x51de50], edi
    app->getMemory<x86::reg32>(x86::reg32(5365328) /* 0x51de50 */) = cpu.edi;
    // 00484ea2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484ea3:
    // 00484ea3  ba50000000             -mov edx, 0x50
    cpu.edx = 80 /*0x50*/;
    // 00484ea8  b800de5100             -mov eax, 0x51de00
    cpu.eax = 5365248 /*0x51de00*/;
    // 00484ead  bd084c4800             -mov ebp, 0x484c08
    cpu.ebp = 4738056 /*0x484c08*/;
    // 00484eb2  e8e5bdffff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00484eb7  892d14de5100           -mov dword ptr [0x51de14], ebp
    app->getMemory<x86::reg32>(x86::reg32(5365268) /* 0x51de14 */) = cpu.ebp;
    // 00484ebd  c70520de5100284c4800   -mov dword ptr [0x51de20], 0x484c28
    app->getMemory<x86::reg32>(x86::reg32(5365280) /* 0x51de20 */) = 4738088 /*0x484c28*/;
    // 00484ec7  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484ece  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00484ed0  a354de5100             -mov dword ptr [0x51de54], eax
    app->getMemory<x86::reg32>(x86::reg32(5365332) /* 0x51de54 */) = cpu.eax;
    // 00484ed5  b930de5100             -mov ecx, 0x51de30
    cpu.ecx = 5365296 /*0x51de30*/;
    // 00484eda  8b1df4af4c00           -mov ebx, dword ptr [0x4caff4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5025780) /* 0x4caff4 */);
    // 00484ee0  8b15f0af4c00           -mov edx, dword ptr [0x4caff0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5025776) /* 0x4caff0 */);
    // 00484ee6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00484ee8  e88fd0ffff             -call 0x481f7c
    cpu.esp -= 4;
    sub_481f7c(app, cpu);
    if (cpu.terminate) return;
    // 00484eed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484eef  7511                   -jne 0x484f02
    if (!cpu.flags.zf)
    {
        goto L_0x00484f02;
    }
L_0x00484ef1:
    // 00484ef1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484ef3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ef4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ef5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ef6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ef7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484ef8:
    // 00484ef8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484efd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484efe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484eff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484f02:
    // 00484f02  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00484f07  bafa000000             -mov edx, 0xfa
    cpu.edx = 250 /*0xfa*/;
    // 00484f0c  b800de5100             -mov eax, 0x51de00
    cpu.eax = 5365248 /*0x51de00*/;
    // 00484f11  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00484f13  e834d0ffff             -call 0x481f4c
    cpu.esp -= 4;
    sub_481f4c(app, cpu);
    if (cpu.terminate) return;
    // 00484f18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484f1a  74d5                   -je 0x484ef1
    if (cpu.flags.zf)
    {
        goto L_0x00484ef1;
    }
    // 00484f1c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00484f21  b8804d4800             -mov eax, 0x484d80
    cpu.eax = 4738432 /*0x484d80*/;
    // 00484f26  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00484f28  e8334cffff             -call 0x479b60
    cpu.esp -= 4;
    sub_479b60(app, cpu);
    if (cpu.terminate) return;
    // 00484f2d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00484f32  891550de5100           -mov dword ptr [0x51de50], edx
    app->getMemory<x86::reg32>(x86::reg32(5365328) /* 0x51de50 */) = cpu.edx;
    // 00484f38  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484f3a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f3c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f3d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484f40  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484f45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484f48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484f48  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484f49  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f4a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484f4c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00484f4e  e89dbfffff             -call 0x480ef0
    cpu.esp -= 4;
    sub_480ef0(app, cpu);
    if (cpu.terminate) return;
    // 00484f53  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00484f56  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484f59  a33cb04c00             -mov dword ptr [0x4cb03c], eax
    app->getMemory<x86::reg32>(x86::reg32(5025852) /* 0x4cb03c */) = cpu.eax;
    // 00484f5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484f60  7505                   -jne 0x484f67
    if (!cpu.flags.zf)
    {
        goto L_0x00484f67;
    }
L_0x00484f62:
    // 00484f62  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f63  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f64  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00484f67:
    // 00484f67  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00484f6a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00484f6c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484f6e  ff531c                 -call dword ptr [ebx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484f71  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00484f74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484f76  74ea                   -je 0x484f62
    if (cpu.flags.zf)
    {
        goto L_0x00484f62;
    }
    // 00484f78  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00484f7b  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00484f7e  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00484f83  ff5140                 -call dword ptr [ecx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484f86  8d968c000000           -lea edx, [esi + 0x8c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00484f8c  c7869c00000001000000   -mov dword ptr [esi + 0x9c], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */) = 1 /*0x1*/;
    // 00484f96  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00484f98  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00484f9f  e85cc6ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00484fa4  bb33000000             -mov ebx, 0x33
    cpu.ebx = 51 /*0x33*/;
    // 00484fa9  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00484fad  8d4644                 -lea eax, [esi + 0x44]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00484fb0  e80770ffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 00484fb5  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 00484fba  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00484fbe  8d4678                 -lea eax, [esi + 0x78]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00484fc1  e8f66fffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 00484fc6  a13cb04c00             -mov eax, dword ptr [0x4cb03c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025852) /* 0x4cb03c */);
    // 00484fcb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484fcc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484fcd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_484fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484fd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484fd1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484fd2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484fd4  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00484fd7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484fdc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00484fde  7431                   -je 0x485011
    if (cpu.flags.zf)
    {
        goto L_0x00485011;
    }
    // 00484fe0  83baa000000000         +cmp dword ptr [edx + 0xa0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(160) /* 0xa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484fe7  7407                   -je 0x484ff0
    if (cpu.flags.zf)
    {
        goto L_0x00484ff0;
    }
    // 00484fe9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484feb  e81ccfffff             -call 0x481f0c
    cpu.esp -= 4;
    sub_481f0c(app, cpu);
    if (cpu.terminate) return;
L_0x00484ff0:
    // 00484ff0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484ff1  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00484ff4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484ff6  ff5320                 -call dword ptr [ebx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484ff9  c7829c00000000000000   -mov dword ptr [edx + 0x9c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */) = 0 /*0x0*/;
    // 00485003  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00485006  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048500d  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00485010  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00485011:
    // 00485011  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485012  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485013  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485014(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485014  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485015  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485016  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00485019  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048501b  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048501f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00485021  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00485028  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048502a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048502d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048502f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00485032  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485034  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00485037  8b0d20a44c00           -mov ecx, dword ptr [0x4ca420]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 0048503d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048503f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00485041  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00485043  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485045  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00485047  e820feffff             -call 0x484e6c
    cpu.esp -= 4;
    sub_484e6c(app, cpu);
    if (cpu.terminate) return;
    // 0048504c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048504e  745f                   -je 0x4850af
    if (cpu.flags.zf)
    {
        goto L_0x004850af;
    }
    // 00485050  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485051  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00485055  be004c4800             -mov esi, 0x484c00
    cpu.esi = 4738048 /*0x484c00*/;
    // 0048505a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048505b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048505c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048505d:
    // 0048505d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00485062  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00485067  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00485069  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048506b  e8e4fbffff             -call 0x484c54
    cpu.esp -= 4;
    sub_484c54(app, cpu);
    if (cpu.terminate) return;
    // 00485070  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00485072  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485074  7435                   -je 0x4850ab
    if (cpu.flags.zf)
    {
        goto L_0x004850ab;
    }
    // 00485076  813d64de5100636564ea   +cmp dword ptr [0x51de64], 0xea646563
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365348) /* 0x51de64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932448099 /*0xea646563*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485080  7529                   -jne 0x4850ab
    if (!cpu.flags.zf)
    {
        goto L_0x004850ab;
    }
    // 00485082  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00485084:
    // 00485084  8b82d0de5100           -mov eax, dword ptr [edx + 0x51ded0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5365456) /* 0x51ded0 */);
    // 0048508a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048508d  e8cefcffff             -call 0x484d60
    cpu.esp -= 4;
    sub_484d60(app, cpu);
    if (cpu.terminate) return;
    // 00485092  83fa40                 +cmp edx, 0x40
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485095  75ed                   -jne 0x485084
    if (!cpu.flags.zf)
    {
        goto L_0x00485084;
    }
    // 00485097  b968de5100             -mov ecx, 0x51de68
    cpu.ecx = 5365352 /*0x51de68*/;
    // 0048509c  ba8cde5100             -mov edx, 0x51de8c
    cpu.edx = 5365388 /*0x51de8c*/;
    // 004850a1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004850a3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004850a5  ff542408               -call dword ptr [esp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004850a9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004850ab:
    // 004850ab  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004850ad  75ae                   -jne 0x48505d
    if (!cpu.flags.zf)
    {
        goto L_0x0048505d;
    }
L_0x004850af:
    // 004850af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004850b1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004850b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4850b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004850b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004850b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004850ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004850bb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004850bc  81ec88000000           -sub esp, 0x88
    (cpu.esp) -= x86::reg32(x86::sreg32(136 /*0x88*/));
    // 004850c2  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004850c4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004850c6  83b8a000000000         +cmp dword ptr [eax + 0xa0], 0
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
    // 004850cd  7405                   -je 0x4850d4
    if (cpu.flags.zf)
    {
        goto L_0x004850d4;
    }
    // 004850cf  e8f0030000             -call 0x4854c4
    cpu.esp -= 4;
    sub_4854c4(app, cpu);
    if (cpu.terminate) return;
L_0x004850d4:
    // 004850d4  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 004850d9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004850db  e88cfdffff             -call 0x484e6c
    cpu.esp -= 4;
    sub_484e6c(app, cpu);
    if (cpu.terminate) return;
    // 004850e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004850e2  0f8497000000           -je 0x48517f
    if (cpu.flags.zf)
    {
        goto L_0x0048517f;
    }
    // 004850e8  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 004850ed  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004850f1  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004850f5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004850f7  b9646461ea             -mov ecx, 0xea616464
    cpu.ecx = 3932251236 /*0xea616464*/;
    // 004850fc  e8bb6effff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 00485101  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00485104  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 00485109  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0048510c  bb88000000             -mov ebx, 0x88
    cpu.ebx = 136 /*0x88*/;
    // 00485111  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00485113  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485115  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00485117  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048511c  e833fbffff             -call 0x484c54
    cpu.esp -= 4;
    sub_484c54(app, cpu);
    if (cpu.terminate) return;
    // 00485121  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485123  745a                   -je 0x48517f
    if (cpu.flags.zf)
    {
        goto L_0x0048517f;
    }
    // 00485125  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048512a  b87cde5100             -mov eax, 0x51de7c
    cpu.eax = 5365372 /*0x51de7c*/;
    // 0048512f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00485131  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00485133  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00485135  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048513c  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048513e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485140  7e3d                   -jle 0x48517f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048517f;
    }
    // 00485142  be68de5100             -mov esi, 0x51de68
    cpu.esi = 5365352 /*0x51de68*/;
    // 00485147  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048514a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048514b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048514c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048514d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048514e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048514f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485151  7e28                   -jle 0x48517b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048517b;
    }
    // 00485153  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00485158:
    // 00485158  c7451400000000         -mov dword ptr [ebp + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0048515f  8985a0000000           -mov dword ptr [ebp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00485165  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 0048516b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00485170  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 00485176  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485177  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485178  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485179  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048517a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048517b:
    // 0048517b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048517d  ebd9                   -jmp 0x485158
    goto L_0x00485158;
L_0x0048517f:
    // 0048517f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485181  81c488000000           -add esp, 0x88
    (cpu.esp) += x86::reg32(x86::sreg32(136 /*0x88*/));
    // 00485187  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485188  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485189  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048518a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048518b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48518c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048518c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048518d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048518e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048518f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485190  81ecb0000000           -sub esp, 0xb0
    (cpu.esp) -= x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 00485196  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00485198  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048519a  899c24ac000000         -mov dword ptr [esp + 0xac], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.ebx;
    // 004851a1  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 004851a6  e8c1fcffff             -call 0x484e6c
    cpu.esp -= 4;
    sub_484e6c(app, cpu);
    if (cpu.terminate) return;
    // 004851ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004851ad  7461                   -je 0x485210
    if (cpu.flags.zf)
    {
        goto L_0x00485210;
    }
    // 004851af  c70424716572ea         -mov dword ptr [esp], 0xea726571
    app->getMemory<x86::reg32>(cpu.esp) = 3933365617 /*0xea726571*/;
    // 004851b6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004851b8  7451                   -je 0x48520b
    if (cpu.flags.zf)
    {
        goto L_0x0048520b;
    }
L_0x004851ba:
    // 004851ba  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004851be  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004851c3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004851c4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004851c5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004851c6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004851c7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004851c8  bbac000000             -mov ebx, 0xac
    cpu.ebx = 172 /*0xac*/;
    // 004851cd  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004851d1  8db58c000000           -lea esi, [ebp + 0x8c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 004851d7  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004851d9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004851db  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004851dc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004851dd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004851de  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004851df  e870faffff             -call 0x484c54
    cpu.esp -= 4;
    sub_484c54(app, cpu);
    if (cpu.terminate) return;
    // 004851e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004851e6  7428                   -je 0x485210
    if (cpu.flags.zf)
    {
        goto L_0x00485210;
    }
    // 004851e8  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 004851ed  8bbc24ac000000         -mov edi, dword ptr [esp + 0xac]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 004851f4  be8cde5100             -mov esi, 0x51de8c
    cpu.esi = 5365388 /*0x51de8c*/;
    // 004851f9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004851fe  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485200  81c4b0000000           +add esp, 0xb0
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
    // 00485206  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485207  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485208  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485209  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048520a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048520b:
    // 0048520b  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048520e  ebaa                   -jmp 0x4851ba
    goto L_0x004851ba;
L_0x00485210:
    // 00485210  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485212  81c4b0000000           -add esp, 0xb0
    (cpu.esp) += x86::reg32(x86::sreg32(176 /*0xb0*/));
    // 00485218  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485219  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048521a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048521b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048521c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485220  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485221  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485222  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485223  81ecb4000000           -sub esp, 0xb4
    (cpu.esp) -= x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 00485229  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048522b  899424ac000000         -mov dword ptr [esp + 0xac], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.edx;
    // 00485232  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00485234  898c24b0000000         -mov dword ptr [esp + 0xb0], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.ecx;
    // 0048523b  83b8a000000000         +cmp dword ptr [eax + 0xa0], 0
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
    // 00485242  7405                   -je 0x485249
    if (cpu.flags.zf)
    {
        goto L_0x00485249;
    }
    // 00485244  e87b020000             -call 0x4854c4
    cpu.esp -= 4;
    sub_4854c4(app, cpu);
    if (cpu.terminate) return;
L_0x00485249:
    // 00485249  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 0048524e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00485250  e817fcffff             -call 0x484e6c
    cpu.esp -= 4;
    sub_484e6c(app, cpu);
    if (cpu.terminate) return;
    // 00485255  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485257  0f84e6000000           -je 0x485343
    if (cpu.flags.zf)
    {
        goto L_0x00485343;
    }
    // 0048525d  ba40000000             -mov edx, 0x40
    cpu.edx = 64 /*0x40*/;
    // 00485262  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00485266  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0048526b  e82cbaffff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00485270  8d44245c               -lea eax, [esp + 0x5c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00485274  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00485276  e8416dffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 0048527b  833dfcaf4c0000         +cmp dword ptr [0x4caffc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025788) /* 0x4caffc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485282  0f849e000000           -je 0x485326
    if (cpu.flags.zf)
    {
        goto L_0x00485326;
    }
    // 00485288  833df8af4c0000         +cmp dword ptr [0x4caff8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025784) /* 0x4caff8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048528f  0f8487000000           -je 0x48531c
    if (cpu.flags.zf)
    {
        goto L_0x0048531c;
    }
    // 00485295  b8617472ea             -mov eax, 0xea727461
    cpu.eax = 3933369441 /*0xea727461*/;
L_0x0048529a:
    // 0048529a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048529d  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 004852a2  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004852a6  8bb424ac000000         -mov esi, dword ptr [esp + 0xac]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 004852ad  bbac000000             -mov ebx, 0xac
    cpu.ebx = 172 /*0xac*/;
    // 004852b2  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004852b4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004852b6  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004852ba  8db58c000000           -lea esi, [ebp + 0x8c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 004852c0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004852c2  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004852c7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004852c8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004852c9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004852ca  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004852cb  e884f9ffff             -call 0x484c54
    cpu.esp -= 4;
    sub_484c54(app, cpu);
    if (cpu.terminate) return;
    // 004852d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004852d2  746f                   -je 0x485343
    if (cpu.flags.zf)
    {
        goto L_0x00485343;
    }
    // 004852d4  813d64de5100636564ea   +cmp dword ptr [0x51de64], 0xea646563
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365348) /* 0x51de64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932448099 /*0xea646563*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004852de  7563                   -jne 0x485343
    if (!cpu.flags.zf)
    {
        goto L_0x00485343;
    }
    // 004852e0  be68de5100             -mov esi, 0x51de68
    cpu.esi = 5365352 /*0x51de68*/;
    // 004852e5  8d7d1c                 -lea edi, [ebp + 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004852e8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004852e9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004852ea  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004852eb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004852ec  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004852ed  c785a000000001000000   -mov dword ptr [ebp + 0xa0], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = 1 /*0x1*/;
    // 004852f7  8b85a0000000           -mov eax, dword ptr [ebp + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */);
    // 004852fd  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 00485303  8b8424b0000000         -mov eax, dword ptr [esp + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0048530a  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048530d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00485312  81c4b4000000           +add esp, 0xb4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(180 /*0xb4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00485318  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485319  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048531a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048531b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048531c:
    // 0048531c  b861776eea             -mov eax, 0xea6e7761
    cpu.eax = 3933108065 /*0xea6e7761*/;
    // 00485321  e974ffffff             -jmp 0x48529a
    goto L_0x0048529a;
L_0x00485326:
    // 00485326  833df8af4c0000         +cmp dword ptr [0x4caff8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025784) /* 0x4caff8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048532d  740a                   -je 0x485339
    if (cpu.flags.zf)
    {
        goto L_0x00485339;
    }
    // 0048532f  b8647472ea             -mov eax, 0xea727464
    cpu.eax = 3933369444 /*0xea727464*/;
    // 00485334  e961ffffff             -jmp 0x48529a
    goto L_0x0048529a;
L_0x00485339:
    // 00485339  b877656eea             -mov eax, 0xea6e6577
    cpu.eax = 3933103479 /*0xea6e6577*/;
    // 0048533e  e957ffffff             -jmp 0x48529a
    goto L_0x0048529a;
L_0x00485343:
    // 00485343  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485345  81c4b4000000           -add esp, 0xb4
    (cpu.esp) += x86::reg32(x86::sreg32(180 /*0xb4*/));
    // 0048534b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048534c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048534d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048534e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_485350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485350  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485351  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485352  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485353  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485354  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485355  81ecac000000           -sub esp, 0xac
    (cpu.esp) -= x86::reg32(x86::sreg32(172 /*0xac*/));
    // 0048535b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048535d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048535f  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 00485364  e803fbffff             -call 0x484e6c
    cpu.esp -= 4;
    sub_484e6c(app, cpu);
    if (cpu.terminate) return;
    // 00485369  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048536b  750e                   -jne 0x48537b
    if (!cpu.flags.zf)
    {
        goto L_0x0048537b;
    }
L_0x0048536d:
    // 0048536d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048536f  81c4ac000000           -add esp, 0xac
    (cpu.esp) += x86::reg32(x86::sreg32(172 /*0xac*/));
    // 00485375  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485376  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485377  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485378  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485379  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048537a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048537b:
    // 0048537b  baac000000             -mov edx, 0xac
    cpu.edx = 172 /*0xac*/;
    // 00485380  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00485382  b90d000000             -mov ecx, 0xd
    cpu.ecx = 13 /*0xd*/;
    // 00485387  e810b9ffff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0048538c  ba647075ea             -mov edx, 0xea757064
    cpu.edx = 3933565028 /*0xea757064*/;
    // 00485391  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00485395  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00485398  bbac000000             -mov ebx, 0xac
    cpu.ebx = 172 /*0xac*/;
    // 0048539d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048539f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004853a1  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004853a5  8db58c000000           -lea esi, [ebp + 0x8c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(140) /* 0x8c */);
    // 004853ab  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004853ad  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004853b2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004853b3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004853b4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004853b5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004853b6  e899f8ffff             -call 0x484c54
    cpu.esp -= 4;
    sub_484c54(app, cpu);
    if (cpu.terminate) return;
    // 004853bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004853bd  74ae                   -je 0x48536d
    if (cpu.flags.zf)
    {
        goto L_0x0048536d;
    }
    // 004853bf  813d64de5100636564ea   +cmp dword ptr [0x51de64], 0xea646563
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365348) /* 0x51de64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932448099 /*0xea646563*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004853c9  75a2                   -jne 0x48536d
    if (!cpu.flags.zf)
    {
        goto L_0x0048536d;
    }
    // 004853cb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004853d0  81c4ac000000           -add esp, 0xac
    (cpu.esp) += x86::reg32(x86::sreg32(172 /*0xac*/));
    // 004853d6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4853dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004853dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004853dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004853de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004853df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004853e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004853e1  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004853e4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004853e6  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004853ea  83781400               +cmp dword ptr [eax + 0x14], 0
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
    // 004853ee  750b                   -jne 0x4853fb
    if (!cpu.flags.zf)
    {
        goto L_0x004853fb;
    }
L_0x004853f0:
    // 004853f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004853f2  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004853f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004853fb:
    // 004853fb  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 00485400  e867faffff             -call 0x484e6c
    cpu.esp -= 4;
    sub_484e6c(app, cpu);
    if (cpu.terminate) return;
    // 00485405  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485407  74e7                   -je 0x4853f0
    if (cpu.flags.zf)
    {
        goto L_0x004853f0;
    }
    // 00485409  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048540d  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00485410  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00485414  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485415  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485416  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485417  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485418  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485419  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048541b  7549                   -jne 0x485466
    if (!cpu.flags.zf)
    {
        goto L_0x00485466;
    }
    // 0048541d  c70424746873ea         -mov dword ptr [esp], 0xea736874
    app->getMemory<x86::reg32>(cpu.esp) = 3933431924 /*0xea736874*/;
L_0x00485424:
    // 00485424  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00485429  bb18000000             -mov ebx, 0x18
    cpu.ebx = 24 /*0x18*/;
    // 0048542e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00485430  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00485432  e81df8ffff             -call 0x484c54
    cpu.esp -= 4;
    sub_484c54(app, cpu);
    if (cpu.terminate) return;
    // 00485437  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485439  74b5                   -je 0x4853f0
    if (cpu.flags.zf)
    {
        goto L_0x004853f0;
    }
    // 0048543b  837c241800             +cmp dword ptr [esp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485440  7416                   -je 0x485458
    if (cpu.flags.zf)
    {
        goto L_0x00485458;
    }
    // 00485442  c785a000000000000000   -mov dword ptr [ebp + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 0048544c  8b85a0000000           -mov eax, dword ptr [ebp + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */);
    // 00485452  8985a4000000           -mov dword ptr [ebp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
L_0x00485458:
    // 00485458  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048545d  83c41c                 +add esp, 0x1c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00485460  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485461  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485462  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485463  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485464  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485465  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485466:
    // 00485466  c70424656964ea         -mov dword ptr [esp], 0xea646965
    app->getMemory<x86::reg32>(cpu.esp) = 3932449125 /*0xea646965*/;
    // 0048546d  ebb5                   -jmp 0x485424
    goto L_0x00485424;
}

/* align: skip 0x90 */
void Application::sub_485470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485470  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485471  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485472  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00485475  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00485477  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 0048547c  e8ebf9ffff             -call 0x484e6c
    cpu.esp -= 4;
    sub_484e6c(app, cpu);
    if (cpu.terminate) return;
    // 00485481  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485483  7506                   -jne 0x48548b
    if (!cpu.flags.zf)
    {
        goto L_0x0048548b;
    }
    // 00485485  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00485488  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485489  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048548a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048548b:
    // 0048548b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048548c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048548d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048548e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048548f  ba776c61ea             -mov edx, 0xea616c77
    cpu.edx = 3932253303 /*0xea616c77*/;
    // 00485494  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00485498  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048549d  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004854a1  bb18000000             -mov ebx, 0x18
    cpu.ebx = 24 /*0x18*/;
    // 004854a6  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004854a9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004854ab  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004854af  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004854b0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004854b1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004854b2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004854b3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004854b4  e89bf7ffff             -call 0x484c54
    cpu.esp -= 4;
    sub_484c54(app, cpu);
    if (cpu.terminate) return;
    // 004854b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854bd  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004854c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4854c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004854c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004854c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004854c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004854c7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004854c8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004854c9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004854ca  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004854cd  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004854cf  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 004854d4  e893f9ffff             -call 0x484e6c
    cpu.esp -= 4;
    sub_484e6c(app, cpu);
    if (cpu.terminate) return;
    // 004854d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004854db  750c                   -jne 0x4854e9
    if (!cpu.flags.zf)
    {
        goto L_0x004854e9;
    }
L_0x004854dd:
    // 004854dd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004854df  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004854e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004854e9:
    // 004854e9  ba657962ea             -mov edx, 0xea627965
    cpu.edx = 3932322149 /*0xea627965*/;
    // 004854ee  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004854f2  bb18000000             -mov ebx, 0x18
    cpu.ebx = 24 /*0x18*/;
    // 004854f7  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004854fa  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004854fc  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004854ff  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485501  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00485503  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485504  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485505  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485506  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485507  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485508  e847f7ffff             -call 0x484c54
    cpu.esp -= 4;
    sub_484c54(app, cpu);
    if (cpu.terminate) return;
    // 0048550d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048550f  74cc                   -je 0x4854dd
    if (cpu.flags.zf)
    {
        goto L_0x004854dd;
    }
    // 00485511  c785a000000000000000   -mov dword ptr [ebp + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 0048551b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00485520  c785a400000000000000   -mov dword ptr [ebp + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 0048552a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048552d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048552e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048552f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485530  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485531  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485532  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485533  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485534(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485534  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485535  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485536  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485537  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485538  81ec08010000           -sub esp, 0x108
    (cpu.esp) -= x86::reg32(x86::sreg32(264 /*0x108*/));
    // 0048553e  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 00485545  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 0048554c  899c24f8000000         -mov dword ptr [esp + 0xf8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */) = cpu.ebx;
    // 00485553  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 00485558  e80ff9ffff             -call 0x484e6c
    cpu.esp -= 4;
    sub_484e6c(app, cpu);
    if (cpu.terminate) return;
    // 0048555d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048555f  744f                   -je 0x4855b0
    if (cpu.flags.zf)
    {
        goto L_0x004855b0;
    }
    // 00485561  ba716572ea             -mov edx, 0xea726571
    cpu.edx = 3933365617 /*0xea726571*/;
    // 00485566  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048556d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00485570  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485572  7449                   -je 0x4855bd
    if (cpu.flags.zf)
    {
        goto L_0x004855bd;
    }
    // 00485574  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x00485576:
    // 00485576  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048557a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048557b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048557c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048557d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048557e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048557f  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00485584  8bb42404010000         -mov esi, dword ptr [esp + 0x104]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048558b  bbac000000             -mov ebx, 0xac
    cpu.ebx = 172 /*0xac*/;
    // 00485590  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00485594  8db68c000000           -lea esi, [esi + 0x8c]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0048559a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048559c  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004855a3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004855a4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004855a5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004855a6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004855a7  e8a8f6ffff             -call 0x484c54
    cpu.esp -= 4;
    sub_484c54(app, cpu);
    if (cpu.terminate) return;
    // 004855ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004855ae  7519                   -jne 0x4855c9
    if (!cpu.flags.zf)
    {
        goto L_0x004855c9;
    }
L_0x004855b0:
    // 004855b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004855b2:
    // 004855b2  81c408010000           -add esp, 0x108
    (cpu.esp) += x86::reg32(x86::sreg32(264 /*0x108*/));
    // 004855b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004855bd:
    // 004855bd  8bb42404010000         -mov esi, dword ptr [esp + 0x104]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004855c4  83c61c                 +add esi, 0x1c
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004855c7  ebad                   -jmp 0x485576
    goto L_0x00485576;
L_0x004855c9:
    // 004855c9  8d9424ac000000         -lea edx, [esp + 0xac]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 004855d0  b8d0de5100             -mov eax, 0x51ded0
    cpu.eax = 5365456 /*0x51ded0*/;
    // 004855d5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004855d7  be746567ea             -mov esi, 0xea676574
    cpu.esi = 3932644724 /*0xea676574*/;
    // 004855dc  899c24ec000000         -mov dword ptr [esp + 0xec], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(236) /* 0xec */) = cpu.ebx;
    // 004855e3  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 004855e8  8bbc2400010000         -mov edi, dword ptr [esp + 0x100]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004855ef  e80cc0ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 004855f4  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004855f7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004855f9  0f8464010000           -je 0x485763
    if (cpu.flags.zf)
    {
        goto L_0x00485763;
    }
    // 004855ff  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x00485601:
    // 00485601  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00485605  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048560a  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0048560f  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00485613  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00485618  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485619  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048561a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048561b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048561c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048561d  e8b2d6ffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 00485622  bb78000000             -mov ebx, 0x78
    cpu.ebx = 120 /*0x78*/;
    // 00485627  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00485629  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485630  e81ff6ffff             -call 0x484c54
    cpu.esp -= 4;
    sub_484c54(app, cpu);
    if (cpu.terminate) return;
    // 00485635  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485637  7410                   -je 0x485649
    if (cpu.flags.zf)
    {
        goto L_0x00485649;
    }
    // 00485639  813d64de5100796c70ea   +cmp dword ptr [0x51de64], 0xea706c79
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365348) /* 0x51de64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933236345 /*0xea706c79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485643  0f8429010000           -je 0x485772
    if (cpu.flags.zf)
    {
        goto L_0x00485772;
    }
L_0x00485649:
    // 00485649  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485650  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00485653  898424f4000000         -mov dword ptr [esp + 0xf4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(244) /* 0xf4 */) = cpu.eax;
    // 0048565a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048565c  898424f0000000         -mov dword ptr [esp + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */) = cpu.eax;
L_0x00485663:
    // 00485663  8b8424f0000000         -mov eax, dword ptr [esp + 0xf0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */);
    // 0048566a  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0048566f  898424fc000000         -mov dword ptr [esp + 0xfc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */) = cpu.eax;
L_0x00485676:
    // 00485676  8b8424fc000000         -mov eax, dword ptr [esp + 0xfc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 0048567d  85ac04ac000000         -test dword ptr [esp + eax + 0xac], ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */ + cpu.eax * 1) & cpu.ebp));
    // 00485684  0f8499000000           -je 0x485723
    if (cpu.flags.zf)
    {
        goto L_0x00485723;
    }
    // 0048568a  b9746567ea             -mov ecx, 0xea676574
    cpu.ecx = 3932644724 /*0xea676574*/;
    // 0048568f  8b9c2400010000         -mov ebx, dword ptr [esp + 0x100]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00485696  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00485699  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048569b  0f8416010000           -je 0x4857b7
    if (cpu.flags.zf)
    {
        goto L_0x004857b7;
    }
    // 004856a1  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x004856a3:
    // 004856a3  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004856a7  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004856ac  8b9424ec000000         -mov edx, dword ptr [esp + 0xec]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(236) /* 0xec */);
    // 004856b3  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004856b7  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004856bc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004856bd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004856be  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004856bf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004856c0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004856c1  e80ed6ffff             -call 0x482cd4
    cpu.esp -= 4;
    sub_482cd4(app, cpu);
    if (cpu.terminate) return;
    // 004856c6  bb78000000             -mov ebx, 0x78
    cpu.ebx = 120 /*0x78*/;
    // 004856cb  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004856cd  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004856d4  e87bf5ffff             -call 0x484c54
    cpu.esp -= 4;
    sub_484c54(app, cpu);
    if (cpu.terminate) return;
    // 004856d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004856db  7446                   -je 0x485723
    if (cpu.flags.zf)
    {
        goto L_0x00485723;
    }
    // 004856dd  813d64de5100796c70ea   +cmp dword ptr [0x51de64], 0xea706c79
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365348) /* 0x51de64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3933236345 /*0xea706c79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004856e7  753a                   -jne 0x485723
    if (!cpu.flags.zf)
    {
        goto L_0x00485723;
    }
    // 004856e9  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004856ee  8d8424ec000000         -lea eax, [esp + 0xec]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(236) /* 0xec */);
    // 004856f5  ba80de5100             -mov edx, 0x51de80
    cpu.edx = 5365376 /*0x51de80*/;
    // 004856fa  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004856fc  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004856fe  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00485700  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00485707  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00485709  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048570b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048570d  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485714  ff9424f8000000         -call dword ptr [esp + 0xf8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048571b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048571d  0f848ffeffff           -je 0x4855b2
    if (cpu.flags.zf)
    {
        goto L_0x004855b2;
    }
L_0x00485723:
    // 00485723  8bbc24ec000000         -mov edi, dword ptr [esp + 0xec]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(236) /* 0xec */);
    // 0048572a  47                     -inc edi
    (cpu.edi)++;
    // 0048572b  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048572d  89bc24ec000000         -mov dword ptr [esp + 0xec], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(236) /* 0xec */) = cpu.edi;
    // 00485734  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00485736  0f853affffff           -jne 0x485676
    if (!cpu.flags.zf)
    {
        goto L_0x00485676;
    }
    // 0048573c  8bac24f0000000         -mov ebp, dword ptr [esp + 0xf0]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */);
    // 00485743  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00485746  89ac24f0000000         -mov dword ptr [esp + 0xf0], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(240) /* 0xf0 */) = cpu.ebp;
    // 0048574d  83fd40                 +cmp ebp, 0x40
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485750  0f8c0dffffff           -jl 0x485663
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485663;
    }
    // 00485756  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485758  81c408010000           -add esp, 0x108
    (cpu.esp) += x86::reg32(x86::sreg32(264 /*0x108*/));
    // 0048575e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048575f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485760  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485761  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485762  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485763:
    // 00485763  8bb42404010000         -mov esi, dword ptr [esp + 0x104]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048576a  83c61c                 +add esi, 0x1c
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048576d  e98ffeffff             -jmp 0x485601
    goto L_0x00485601;
L_0x00485772:
    // 00485772  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00485777  8d8424ec000000         -lea eax, [esp + 0xec]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(236) /* 0xec */);
    // 0048577e  ba80de5100             -mov edx, 0x51de80
    cpu.edx = 5365376 /*0x51de80*/;
    // 00485783  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00485785  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00485787  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00485789  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00485790  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00485792  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00485794  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485796  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048579d  ff9424f8000000         -call dword ptr [esp + 0xf8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(248) /* 0xf8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004857a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004857a6  0f859dfeffff           -jne 0x485649
    if (!cpu.flags.zf)
    {
        goto L_0x00485649;
    }
    // 004857ac  81c408010000           +add esp, 0x108
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(264 /*0x108*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004857b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004857b7:
    // 004857b7  8bb424f4000000         -mov esi, dword ptr [esp + 0xf4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(244) /* 0xf4 */);
    // 004857be  e9e0feffff             -jmp 0x4856a3
    goto L_0x004856a3;
}

/* align: skip 0x90 */
void Application::sub_4857c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004857c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004857c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004857c6  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004857c9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004857cb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004857cd  bac4090000             -mov edx, 0x9c4
    cpu.edx = 2500 /*0x9c4*/;
    // 004857d2  e895f6ffff             -call 0x484e6c
    cpu.esp -= 4;
    sub_484e6c(app, cpu);
    if (cpu.terminate) return;
    // 004857d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004857d9  7506                   -jne 0x4857e1
    if (!cpu.flags.zf)
    {
        goto L_0x004857e1;
    }
    // 004857db  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004857de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004857e1:
    // 004857e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004857e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004857e3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004857e4  c744240c766d72ea       -mov dword ptr [esp + 0xc], 0xea726d76
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 3933367670 /*0xea726d76*/;
    // 004857ec  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004857f0  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004857f3  bb2c000000             -mov ebx, 0x2c
    cpu.ebx = 44 /*0x2c*/;
    // 004857f8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004857f9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004857fa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004857fb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004857fc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004857fd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004857ff  8d7c2424               -lea edi, [esp + 0x24]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00485803  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00485805  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00485809  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048580e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048580f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485810  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485811  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485812  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00485813  e83cf4ffff             -call 0x484c54
    cpu.esp -= 4;
    sub_484c54(app, cpu);
    if (cpu.terminate) return;
    // 00485818  3d6b6361ea             +cmp eax, 0xea61636b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3932250987 /*0xea61636b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048581d  750e                   -jne 0x48582d
    if (!cpu.flags.zf)
    {
        goto L_0x0048582d;
    }
    // 0048581f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00485824  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485825  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485826  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485827  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0048582a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048582b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048582c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048582d:
    // 0048582d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048582f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485830  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485831  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485832  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00485835  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485836  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485837  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485838(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485838  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048583a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048583c  7407                   -je 0x485845
    if (cpu.flags.zf)
    {
        goto L_0x00485845;
    }
    // 0048583e  c7420801000000         -mov dword ptr [edx + 8], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x00485845:
    // 00485845  ba08494c00             -mov edx, 0x4c4908
    cpu.edx = 4999432 /*0x4c4908*/;
    // 0048584a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048584b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048584d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048584f  e8b4b5ffff             -call 0x480e08
    cpu.esp -= 4;
    sub_480e08(app, cpu);
    if (cpu.terminate) return;
    // 00485854  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_485860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485861  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485862  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485863  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485865  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00485868  baeafb0000             -mov edx, 0xfbea
    cpu.edx = 64490 /*0xfbea*/;
    // 0048586d  39f0                   +cmp eax, esi
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
    // 0048586f  7323                   -jae 0x485894
    if (!cpu.flags.cf)
    {
        goto L_0x00485894;
    }
L_0x00485871:
    // 00485871  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485873  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485875  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 00485877  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00485879  31d9                   -xor ecx, ebx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048587b  668b0c4d40b04c00       -mov cx, word ptr [ecx*2 + 0x4cb040]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5025856) /* 0x4cb040 */ + cpu.ecx * 2);
    // 00485883  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00485889  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0048588c  40                     -inc eax
    (cpu.eax)++;
    // 0048588d  31ca                   -xor edx, ecx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048588f  39f0                   +cmp eax, esi
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
    // 00485891  72de                   -jb 0x485871
    if (cpu.flags.cf)
    {
        goto L_0x00485871;
    }
    // 00485893  90                     -nop 
    ;
L_0x00485894:
    // 00485894  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485896  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485897  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485898  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485899  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4858a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004858a0  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004858a6  833d44b24c0002         +cmp dword ptr [0x4cb244], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026372) /* 0x4cb244 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004858ad  7c21                   -jl 0x4858d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004858d0;
    }
    // 004858af  833d40b24c0000         +cmp dword ptr [0x4cb240], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004858b6  750a                   -jne 0x4858c2
    if (!cpu.flags.zf)
    {
        goto L_0x004858c2;
    }
    // 004858b8  e8bbb2ffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 004858bd  a340b24c00             -mov dword ptr [0x4cb240], eax
    app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */) = cpu.eax;
L_0x004858c2:
    // 004858c2  a140b24c00             -mov eax, dword ptr [0x4cb240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */);
    // 004858c7  e8fcb2ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004858cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004858ce  7507                   -jne 0x4858d7
    if (!cpu.flags.zf)
    {
        goto L_0x004858d7;
    }
L_0x004858d0:
    // 004858d0  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004858d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004858d7:
    // 004858d7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004858d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004858d9  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004858e0  8d9c2408010000         -lea ebx, [esp + 0x108]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004858e7  8b942410010000         -mov edx, dword ptr [esp + 0x110]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004858ee  89842408010000         -mov dword ptr [esp + 0x108], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.eax;
    // 004858f5  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004858f9  e8d8210100             -call 0x497ad6
    cpu.esp -= 4;
    sub_497ad6(app, cpu);
    if (cpu.terminate) return;
    // 004858fe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485900  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00485904  899c2408010000         -mov dword ptr [esp + 0x108], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.ebx;
    // 0048590b  e8e0000000             -call 0x4859f0
    cpu.esp -= 4;
    sub_4859f0(app, cpu);
    if (cpu.terminate) return;
    // 00485910  a140b24c00             -mov eax, dword ptr [0x4cb240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */);
    // 00485915  e8c6b2ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048591a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048591b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048591c  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00485922  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_485924(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485924  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485925  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485926  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0048592c  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00485933  8b942414010000         -mov edx, dword ptr [esp + 0x114]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0048593a  833d44b24c0002         +cmp dword ptr [0x4cb244], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026372) /* 0x4cb244 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485941  0f8c8b000000           -jl 0x4859d2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004859d2;
    }
    // 00485947  833d40b24c0000         +cmp dword ptr [0x4cb240], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048594e  750a                   -jne 0x48595a
    if (!cpu.flags.zf)
    {
        goto L_0x0048595a;
    }
    // 00485950  e823b2ffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00485955  a340b24c00             -mov dword ptr [0x4cb240], eax
    app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */) = cpu.eax;
L_0x0048595a:
    // 0048595a  a140b24c00             -mov eax, dword ptr [0x4cb240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */);
    // 0048595f  e864b2ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00485964  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485966  746a                   -je 0x4859d2
    if (cpu.flags.zf)
    {
        goto L_0x004859d2;
    }
    // 00485968  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048596a  7c23                   -jl 0x48598f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048598f;
    }
    // 0048596c  83fb50                 +cmp ebx, 0x50
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048596f  7d1e                   -jge 0x48598f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048598f;
    }
    // 00485971  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00485973  7c1a                   -jl 0x48598f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048598f;
    }
    // 00485975  83fa19                 +cmp edx, 0x19
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485978  7d15                   -jge 0x48598f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048598f;
    }
    // 0048597a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00485981  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00485983  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00485986  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00485988  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048598a  a350b24c00             -mov dword ptr [0x4cb250], eax
    app->getMemory<x86::reg32>(x86::reg32(5026384) /* 0x4cb250 */) = cpu.eax;
L_0x0048598f:
    // 0048598f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485990  8d842420010000         -lea eax, [esp + 0x120]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 00485997  8d9c2404010000         -lea ebx, [esp + 0x104]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048599e  8b94241c010000         -mov edx, dword ptr [esp + 0x11c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004859a5  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 004859ac  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004859b0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004859b2  e81f210100             -call 0x497ad6
    cpu.esp -= 4;
    sub_497ad6(app, cpu);
    if (cpu.terminate) return;
    // 004859b7  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004859bb  89bc2404010000         -mov dword ptr [esp + 0x104], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.edi;
    // 004859c2  e829000000             -call 0x4859f0
    cpu.esp -= 4;
    sub_4859f0(app, cpu);
    if (cpu.terminate) return;
    // 004859c7  a140b24c00             -mov eax, dword ptr [0x4cb240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */);
    // 004859cc  e80fb2ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004859d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004859d2:
    // 004859d2  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004859d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4859f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004859f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004859f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004859f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004859f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004859f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004859f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004859f6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004859f9  8b1d50b24c00           -mov ebx, dword ptr [0x4cb250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026384) /* 0x4cb250 */);
    // 004859ff  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00485a01  833d44b24c0002         +cmp dword ptr [0x4cb244], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026372) /* 0x4cb244 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485a08  7d10                   -jge 0x485a1a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00485a1a;
    }
L_0x00485a0a:
    // 00485a0a  8b1d50b24c00           -mov ebx, dword ptr [0x4cb250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026384) /* 0x4cb250 */);
    // 00485a10  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00485a13  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a14  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485a1a:
    // 00485a1a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00485a1c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485a1e  49                     -dec ecx
    (cpu.ecx)--;
    // 00485a1f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00485a21  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00485a23  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00485a25  49                     -dec ecx
    (cpu.ecx)--;
    // 00485a26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485a28  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00485a2b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00485a2d  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00485a2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485a31  7ed7                   -jle 0x485a0a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00485a0a;
    }
L_0x00485a33:
    // 00485a33  8b1d50b24c00           -mov ebx, dword ptr [0x4cb250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026384) /* 0x4cb250 */);
    // 00485a39  80f90e                 +cmp cl, 0xe
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(14 /*0xe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485a3c  7441                   -je 0x485a7f
    if (cpu.flags.zf)
    {
        goto L_0x00485a7f;
    }
    // 00485a3e  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 00485a40  80f920                 +cmp cl, 0x20
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485a43  7245                   -jb 0x485a8a
    if (cpu.flags.cf)
    {
        goto L_0x00485a8a;
    }
    // 00485a45  e8fa000000             -call 0x485b44
    cpu.esp -= 4;
    sub_485b44(app, cpu);
    if (cpu.terminate) return;
    // 00485a4a  8b1d50b24c00           -mov ebx, dword ptr [0x4cb250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026384) /* 0x4cb250 */);
    // 00485a50  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00485a52  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00485a54  a055b24c00             -mov al, byte ptr [0x4cb255]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5026389) /* 0x4cb255 */);
    // 00485a59  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00485a5b  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485a5e  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00485a61  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00485a63  8b154cb24c00           -mov edx, dword ptr [0x4cb24c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5026380) /* 0x4cb24c */);
    // 00485a69  6689441afe             -mov word ptr [edx + ebx - 2], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */ + cpu.ebx * 1) = cpu.ax;
L_0x00485a6e:
    // 00485a6e  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00485a71  46                     -inc esi
    (cpu.esi)++;
    // 00485a72  47                     -inc edi
    (cpu.edi)++;
    // 00485a73  891d50b24c00           -mov dword ptr [0x4cb250], ebx
    app->getMemory<x86::reg32>(x86::reg32(5026384) /* 0x4cb250 */) = cpu.ebx;
    // 00485a79  39ef                   +cmp edi, ebp
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
    // 00485a7b  7d8d                   -jge 0x485a0a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00485a0a;
    }
    // 00485a7d  ebb4                   -jmp 0x485a33
    goto L_0x00485a33;
L_0x00485a7f:
    // 00485a7f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00485a81  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00485a83  a255b24c00             -mov byte ptr [0x4cb255], al
    app->getMemory<x86::reg8>(x86::reg32(5026389) /* 0x4cb255 */) = cpu.al;
    // 00485a88  ebe4                   -jmp 0x485a6e
    goto L_0x00485a6e;
L_0x00485a8a:
    // 00485a8a  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00485a8c  80ea08                 -sub dl, 8
    (cpu.dl) -= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00485a8f  80fa04                 +cmp dl, 4
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
    // 00485a92  77da                   -ja 0x485a6e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00485a6e;
    }
    // 00485a94  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00485a96  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00485a98  ff2485dc594800         -jmp dword ptr [eax*4 + 0x4859dc]
    cpu.ip = app->getMemory<x86::reg32>(4741596 + cpu.eax * 4); goto dynamic_jump;
  case 0x00485a9f:
    // 00485a9f  83fb02                 +cmp ebx, 2
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
    // 00485aa2  7cca                   -jl 0x485a6e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485a6e;
    }
    // 00485aa4  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00485aa7  ebc5                   -jmp 0x485a6e
    goto L_0x00485a6e;
  case 0x00485aa9:
    // 00485aa9  803d56b24c0001         +cmp byte ptr [0x4cb256], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5026390) /* 0x4cb256 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485ab0  76bc                   -jbe 0x485a6e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00485a6e;
    }
    // 00485ab2  bda0000000             -mov ebp, 0xa0
    cpu.ebp = 160 /*0xa0*/;
    // 00485ab7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00485ab9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00485abb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00485abe  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00485ac0  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00485ac3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00485ac5  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00485ac7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485ac9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00485acc  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00485ace  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00485ad0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485ad2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485ad4  8a1d56b24c00           -mov bl, byte ptr [0x4cb256]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5026390) /* 0x4cb256 */);
    // 00485ada  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00485add  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00485adf  40                     -inc eax
    (cpu.eax)++;
    // 00485ae0  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00485ae3  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00485ae5  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00485ae8  eb84                   -jmp 0x485a6e
    goto L_0x00485a6e;
  case 0x00485aea:
    // 00485aea  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00485aec  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00485aee  bba0000000             -mov ebx, 0xa0
    cpu.ebx = 160 /*0xa0*/;
    // 00485af3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00485af6  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00485af8  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00485afb  69dba0000000           +imul ebx, ebx, 0xa0
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(160 /*0xa0*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 00485b01  891d50b24c00           -mov dword ptr [0x4cb250], ebx
    app->getMemory<x86::reg32>(x86::reg32(5026384) /* 0x4cb250 */) = cpu.ebx;
    // 00485b07  e838000000             -call 0x485b44
    cpu.esp -= 4;
    sub_485b44(app, cpu);
    if (cpu.terminate) return;
    // 00485b0c  8b1d50b24c00           -mov ebx, dword ptr [0x4cb250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026384) /* 0x4cb250 */);
    // 00485b12  e957ffffff             -jmp 0x485a6e
    goto L_0x00485a6e;
  case 0x00485b17:
    // 00485b17  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485b19  8a1d54b24c00           -mov bl, byte ptr [0x4cb254]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5026388) /* 0x4cb254 */);
    // 00485b1f  69dba0000000           +imul ebx, ebx, 0xa0
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(160 /*0xa0*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 00485b25  e944ffffff             -jmp 0x485a6e
    goto L_0x00485a6e;
  case 0x00485b2a:
    // 00485b2a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485b2c  e897000000             -call 0x485bc8
    cpu.esp -= 4;
    sub_485bc8(app, cpu);
    if (cpu.terminate) return;
    // 00485b31  8a1d54b24c00           -mov bl, byte ptr [0x4cb254]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5026388) /* 0x4cb254 */);
    // 00485b37  69dba0000000           +imul ebx, ebx, 0xa0
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(160 /*0xa0*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 00485b3d  e92cffffff             -jmp 0x485a6e
    goto L_0x00485a6e;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485b44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485b44  813d50b24c00a00f0000   +cmp dword ptr [0x4cb250], 0xfa0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026384) /* 0x4cb250 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000 /*0xfa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485b4e  7d01                   -jge 0x485b51
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00485b51;
    }
    // 00485b50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485b51:
    // 00485b51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485b52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485b53  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485b54  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485b55  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485b56  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00485b58  b919000000             -mov ecx, 0x19
    cpu.ecx = 25 /*0x19*/;
    // 00485b5d  8a1554b24c00           -mov dl, byte ptr [0x4cb254]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5026388) /* 0x4cb254 */);
    // 00485b63  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00485b65  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00485b6c  49                     -dec ecx
    (cpu.ecx)--;
    // 00485b6d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00485b6f  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 00485b76  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00485b79  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00485b7b  8b0d4cb24c00           -mov ecx, dword ptr [0x4cb24c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5026380) /* 0x4cb24c */);
    // 00485b81  42                     -inc edx
    (cpu.edx)++;
    // 00485b82  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00485b84  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00485b8b  8b354cb24c00           -mov esi, dword ptr [0x4cb24c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5026380) /* 0x4cb24c */);
    // 00485b91  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00485b93  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 00485b96  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00485b99  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00485b9b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00485b9d  e85ebaffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00485ba2  a14cb24c00             -mov eax, dword ptr [0x4cb24c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026380) /* 0x4cb24c */);
    // 00485ba7  baa0000000             -mov edx, 0xa0
    cpu.edx = 160 /*0xa0*/;
    // 00485bac  05000f0000             -add eax, 0xf00
    (cpu.eax) += x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00485bb1  bf000f0000             -mov edi, 0xf00
    cpu.edi = 3840 /*0xf00*/;
    // 00485bb6  e8e1b0ffff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00485bbb  893d50b24c00           -mov dword ptr [0x4cb250], edi
    app->getMemory<x86::reg32>(x86::reg32(5026384) /* 0x4cb250 */) = cpu.edi;
    // 00485bc1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bc2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bc3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bc5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_485bc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485bc8  833d44b24c0002         +cmp dword ptr [0x4cb244], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026372) /* 0x4cb244 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485bcf  7c46                   -jl 0x485c17
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485c17;
    }
    // 00485bd1  833d40b24c0000         +cmp dword ptr [0x4cb240], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485bd8  750a                   -jne 0x485be4
    if (!cpu.flags.zf)
    {
        goto L_0x00485be4;
    }
    // 00485bda  e899afffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00485bdf  a340b24c00             -mov dword ptr [0x4cb240], eax
    app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */) = cpu.eax;
L_0x00485be4:
    // 00485be4  a140b24c00             -mov eax, dword ptr [0x4cb240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */);
    // 00485be9  e8daafffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00485bee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485bf0  7425                   -je 0x485c17
    if (cpu.flags.zf)
    {
        goto L_0x00485c17;
    }
    // 00485bf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485bf3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00485bf5:
    // 00485bf5  8b154cb24c00           -mov edx, dword ptr [0x4cb24c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5026380) /* 0x4cb24c */);
    // 00485bfb  c7040200000000         -mov dword ptr [edx + eax], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 00485c02  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00485c05  3da00f0000             +cmp eax, 0xfa0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000 /*0xfa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485c0a  7ce9                   -jl 0x485bf5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485bf5;
    }
    // 00485c0c  a140b24c00             -mov eax, dword ptr [0x4cb240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */);
    // 00485c11  e8caafffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00485c16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00485c17:
    // 00485c17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485c18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485c18  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485c19  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485c1b  833d40b24c0000         +cmp dword ptr [0x4cb240], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485c22  750a                   -jne 0x485c2e
    if (!cpu.flags.zf)
    {
        goto L_0x00485c2e;
    }
    // 00485c24  e84fafffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00485c29  a340b24c00             -mov dword ptr [0x4cb240], eax
    app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */) = cpu.eax;
L_0x00485c2e:
    // 00485c2e  a140b24c00             -mov eax, dword ptr [0x4cb240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */);
    // 00485c33  e890afffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00485c38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485c3a  7419                   -je 0x485c55
    if (cpu.flags.zf)
    {
        goto L_0x00485c55;
    }
    // 00485c3c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00485c3e  7c0b                   -jl 0x485c4b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485c4b;
    }
    // 00485c40  83fa18                 +cmp edx, 0x18
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485c43  7f06                   -jg 0x485c4b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00485c4b;
    }
    // 00485c45  881554b24c00           -mov byte ptr [0x4cb254], dl
    app->getMemory<x86::reg8>(x86::reg32(5026388) /* 0x4cb254 */) = cpu.dl;
L_0x00485c4b:
    // 00485c4b  a140b24c00             -mov eax, dword ptr [0x4cb240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026368) /* 0x4cb240 */);
    // 00485c50  e88bafffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x00485c55:
    // 00485c55  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_485c58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485c58  a255b24c00             -mov byte ptr [0x4cb255], al
    app->getMemory<x86::reg8>(x86::reg32(5026389) /* 0x4cb255 */) = cpu.al;
    // 00485c5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485c60  83f801                 +cmp eax, 1
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
    // 00485c63  7d01                   -jge 0x485c66
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00485c66;
    }
    // 00485c65  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485c66:
    // 00485c66  a256b24c00             -mov byte ptr [0x4cb256], al
    app->getMemory<x86::reg8>(x86::reg32(5026390) /* 0x4cb256 */) = cpu.al;
    // 00485c6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485c6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485c6c  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 00485c6f  0500000b00             -add eax, 0xb0000
    (cpu.eax) += x86::reg32(x86::sreg32(720896 /*0xb0000*/));
    // 00485c74  a34cb24c00             -mov dword ptr [0x4cb24c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026380) /* 0x4cb24c */) = cpu.eax;
    // 00485c79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485c7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485c7c  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00485c7f  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00485c82  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_485c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485c90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485c91  ba34074c00             -mov edx, 0x4c0734
    cpu.edx = 4982580 /*0x4c0734*/;
    // 00485c96  e805000000             -call 0x485ca0
    cpu.esp -= 4;
    sub_485ca0(app, cpu);
    if (cpu.terminate) return;
    // 00485c9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485ca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485ca1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485ca2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485ca4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485ca6  e865040000             -call 0x486110
    cpu.esp -= 4;
    sub_486110(app, cpu);
    if (cpu.terminate) return;
    // 00485cab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485cad  7508                   -jne 0x485cb7
    if (!cpu.flags.zf)
    {
        goto L_0x00485cb7;
    }
L_0x00485caf:
    // 00485caf  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 00485cb4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485cb5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485cb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485cb7:
    // 00485cb7  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00485cbd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485cbf  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00485cc1  e826020000             -call 0x485eec
    cpu.esp -= 4;
    sub_485eec(app, cpu);
    if (cpu.terminate) return;
    // 00485cc6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485cc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485cca  7405                   -je 0x485cd1
    if (cpu.flags.zf)
    {
        goto L_0x00485cd1;
    }
    // 00485ccc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485cce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ccf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485cd0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485cd1:
    // 00485cd1  ba44074c00             -mov edx, 0x4c0744
    cpu.edx = 4982596 /*0x4c0744*/;
    // 00485cd6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485cd8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485cda  e831040000             -call 0x486110
    cpu.esp -= 4;
    sub_486110(app, cpu);
    if (cpu.terminate) return;
    // 00485cdf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485ce1  74cc                   -je 0x485caf
    if (cpu.flags.zf)
    {
        goto L_0x00485caf;
    }
    // 00485ce3  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00485ce9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485ceb  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00485ced  e8fa010000             -call 0x485eec
    cpu.esp -= 4;
    sub_485eec(app, cpu);
    if (cpu.terminate) return;
    // 00485cf2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485cf4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485cf6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485cf7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485cf8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485cfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485cfc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485cfd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485cfe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485cff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485d01  ba50074c00             -mov edx, 0x4c0750
    cpu.edx = 4982608 /*0x4c0750*/;
    // 00485d06  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485d08  e803040000             -call 0x486110
    cpu.esp -= 4;
    sub_486110(app, cpu);
    if (cpu.terminate) return;
    // 00485d0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485d0f  7509                   -jne 0x485d1a
    if (!cpu.flags.zf)
    {
        goto L_0x00485d1a;
    }
    // 00485d11  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 00485d16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485d1a:
    // 00485d1a  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00485d20  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485d22  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00485d24  e8c3010000             -call 0x485eec
    cpu.esp -= 4;
    sub_485eec(app, cpu);
    if (cpu.terminate) return;
    // 00485d29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485d30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485d31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485d32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485d33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485d34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485d35  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00485d38  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00485d3a  be58074c00             -mov esi, 0x4c0758
    cpu.esi = 4982616 /*0x4c0758*/;
    // 00485d3f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00485d41  e8b6ffffff             -call 0x485cfc
    cpu.esp -= 4;
    sub_485cfc(app, cpu);
    if (cpu.terminate) return;
    // 00485d46  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00485d47:
    // 00485d47  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00485d49  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00485d4b  3c00                   +cmp al, 0
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
    // 00485d4d  7410                   -je 0x485d5f
    if (cpu.flags.zf)
    {
        goto L_0x00485d5f;
    }
    // 00485d4f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00485d52  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485d55  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00485d58  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485d5b  3c00                   +cmp al, 0
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
    // 00485d5d  75e8                   -jne 0x485d47
    if (!cpu.flags.zf)
    {
        goto L_0x00485d47;
    }
L_0x00485d5f:
    // 00485d5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d60  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00485d62  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00485d64  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00485d69  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485d6a  2bc9                   +sub ecx, ecx
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
    // 00485d6c  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00485d6d  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00485d6f  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00485d71  4f                     -dec edi
    (cpu.edi)--;
L_0x00485d72:
    // 00485d72  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00485d74  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00485d76  3c00                   +cmp al, 0
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
    // 00485d78  7410                   -je 0x485d8a
    if (cpu.flags.zf)
    {
        goto L_0x00485d8a;
    }
    // 00485d7a  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00485d7d  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485d80  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00485d83  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485d86  3c00                   +cmp al, 0
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
    // 00485d88  75e8                   -jne 0x485d72
    if (!cpu.flags.zf)
    {
        goto L_0x00485d72;
    }
L_0x00485d8a:
    // 00485d8a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d8b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00485d8d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00485d8f  e87c030000             -call 0x486110
    cpu.esp -= 4;
    sub_486110(app, cpu);
    if (cpu.terminate) return;
    // 00485d94  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00485d97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485da0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485da1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485da2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485da3  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00485da6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00485da8  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00485daa  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00485dac  e84bffffff             -call 0x485cfc
    cpu.esp -= 4;
    sub_485cfc(app, cpu);
    if (cpu.terminate) return;
    // 00485db1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00485db2:
    // 00485db2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00485db4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00485db6  3c00                   +cmp al, 0
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
    // 00485db8  7410                   -je 0x485dca
    if (cpu.flags.zf)
    {
        goto L_0x00485dca;
    }
    // 00485dba  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00485dbd  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485dc0  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00485dc3  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485dc6  3c00                   +cmp al, 0
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
    // 00485dc8  75e8                   -jne 0x485db2
    if (!cpu.flags.zf)
    {
        goto L_0x00485db2;
    }
L_0x00485dca:
    // 00485dca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485dcb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485dcd  7464                   -je 0x485e33
    if (cpu.flags.zf)
    {
        goto L_0x00485e33;
    }
    // 00485dcf  be5c074c00             -mov esi, 0x4c075c
    cpu.esi = 4982620 /*0x4c075c*/;
L_0x00485dd4:
    // 00485dd4  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00485dd6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485dd7  2bc9                   +sub ecx, ecx
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
    // 00485dd9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00485dda  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00485ddc  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00485dde  4f                     -dec edi
    (cpu.edi)--;
L_0x00485ddf:
    // 00485ddf  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00485de1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00485de3  3c00                   +cmp al, 0
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
    // 00485de5  7410                   -je 0x485df7
    if (cpu.flags.zf)
    {
        goto L_0x00485df7;
    }
    // 00485de7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00485dea  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485ded  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00485df0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485df3  3c00                   +cmp al, 0
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
    // 00485df5  75e8                   -jne 0x485ddf
    if (!cpu.flags.zf)
    {
        goto L_0x00485ddf;
    }
L_0x00485df7:
    // 00485df7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485df8  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00485dfa  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00485dfc  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00485e01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485e02  2bc9                   +sub ecx, ecx
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
    // 00485e04  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00485e05  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00485e07  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00485e09  4f                     -dec edi
    (cpu.edi)--;
L_0x00485e0a:
    // 00485e0a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00485e0c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00485e0e  3c00                   +cmp al, 0
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
    // 00485e10  7410                   -je 0x485e22
    if (cpu.flags.zf)
    {
        goto L_0x00485e22;
    }
    // 00485e12  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00485e15  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485e18  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00485e1b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485e1e  3c00                   +cmp al, 0
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
    // 00485e20  75e8                   -jne 0x485e0a
    if (!cpu.flags.zf)
    {
        goto L_0x00485e0a;
    }
L_0x00485e22:
    // 00485e22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e23  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00485e25  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00485e27  e8e4020000             -call 0x486110
    cpu.esp -= 4;
    sub_486110(app, cpu);
    if (cpu.terminate) return;
    // 00485e2c  83c450                 +add esp, 0x50
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00485e2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485e33:
    // 00485e33  be60074c00             -mov esi, 0x4c0760
    cpu.esi = 4982624 /*0x4c0760*/;
    // 00485e38  eb9a                   -jmp 0x485dd4
    goto L_0x00485dd4;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485e3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485e3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485e3d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485e3e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485e3f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485e41  e8b6feffff             -call 0x485cfc
    cpu.esp -= 4;
    sub_485cfc(app, cpu);
    if (cpu.terminate) return;
    // 00485e46  ba58074c00             -mov edx, 0x4c0758
    cpu.edx = 4982616 /*0x4c0758*/;
    // 00485e4b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485e4d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485e4f  e8bc020000             -call 0x486110
    cpu.esp -= 4;
    sub_486110(app, cpu);
    if (cpu.terminate) return;
    // 00485e54  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00485e5a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485e5c  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00485e5e  e889000000             -call 0x485eec
    cpu.esp -= 4;
    sub_485eec(app, cpu);
    if (cpu.terminate) return;
    // 00485e63  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_485e68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485e68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485e69  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485e6a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485e6b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485e6d  e88afeffff             -call 0x485cfc
    cpu.esp -= 4;
    sub_485cfc(app, cpu);
    if (cpu.terminate) return;
    // 00485e72  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00485e77  ba64074c00             -mov edx, 0x4c0764
    cpu.edx = 4982628 /*0x4c0764*/;
    // 00485e7c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485e7e  e88d020000             -call 0x486110
    cpu.esp -= 4;
    sub_486110(app, cpu);
    if (cpu.terminate) return;
    // 00485e83  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_485e88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485e88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485e89  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485e8a  bb6c074c00             -mov ebx, 0x4c076c
    cpu.ebx = 4982636 /*0x4c076c*/;
    // 00485e8f  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00485e94  e8a70e0000             -call 0x486d40
    cpu.esp -= 4;
    sub_486d40(app, cpu);
    if (cpu.terminate) return;
    // 00485e99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e9a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485e9b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485e9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485e9c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485e9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485e9e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485ea0  a120a44c00             -mov eax, dword ptr [0x4ca420]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00485ea5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485ea7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00485eaa  c1e202                 +shl edx, 2
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
    // 00485ead  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00485eaf  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00485eb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485eb4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485eb6  e831000000             -call 0x485eec
    cpu.esp -= 4;
    sub_485eec(app, cpu);
    if (cpu.terminate) return;
    // 00485ebb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485ebd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485ebf  741e                   -je 0x485edf
    if (cpu.flags.zf)
    {
        goto L_0x00485edf;
    }
    // 00485ec1  83f802                 +cmp eax, 2
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
    // 00485ec4  7419                   -je 0x485edf
    if (cpu.flags.zf)
    {
        goto L_0x00485edf;
    }
    // 00485ec6  83f8ff                 +cmp eax, -1
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
    // 00485ec9  7414                   -je 0x485edf
    if (cpu.flags.zf)
    {
        goto L_0x00485edf;
    }
    // 00485ecb  83f801                 +cmp eax, 1
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
    // 00485ece  740a                   -je 0x485eda
    if (cpu.flags.zf)
    {
        goto L_0x00485eda;
    }
    // 00485ed0  83f805                 +cmp eax, 5
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
    // 00485ed3  7405                   -je 0x485eda
    if (cpu.flags.zf)
    {
        goto L_0x00485eda;
    }
    // 00485ed5  83f80a                 +cmp eax, 0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485ed8  7c0a                   -jl 0x485ee4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485ee4;
    }
L_0x00485eda:
    // 00485eda  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485edc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485edd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ede  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485edf:
    // 00485edf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485ee1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ee2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ee3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485ee4:
    // 00485ee4  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00485ee9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485eea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485eeb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485eec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485eec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485eed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485eee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485eef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485ef0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485ef1  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00485ef4  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00485ef8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00485efa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00485efc  8b1d5cb24c00           -mov ebx, dword ptr [0x4cb25c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026396) /* 0x4cb25c */);
    // 00485f02  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00485f06  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00485f08  7518                   -jne 0x485f22
    if (!cpu.flags.zf)
    {
        goto L_0x00485f22;
    }
    // 00485f0a  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00485f10  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485f12  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00485f15  c1e202                 +shl edx, 2
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
    // 00485f18  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00485f1a  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00485f1d  a35cb24c00             -mov dword ptr [0x4cb25c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026396) /* 0x4cb25c */) = cpu.eax;
L_0x00485f22:
    // 00485f22  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00485f24  893558b34c00           -mov dword ptr [0x4cb358], esi
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = cpu.esi;
    // 00485f2a  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00485f2f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00485f31  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00485f35  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00485f37  48                     -dec eax
    (cpu.eax)--;
    // 00485f38  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00485f3a  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
L_0x00485f3e:
    // 00485f3e  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00485f42  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 00485f47  39f8                   +cmp eax, edi
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
    // 00485f49  7c0e                   -jl 0x485f59
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485f59;
    }
    // 00485f4b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00485f50  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00485f53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485f54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485f55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485f56  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485f57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485f58  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485f59:
    // 00485f59  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00485f5b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485f5d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00485f62  e8d93cffff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 00485f67  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00485f6b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00485f6d  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00485f6f  e8cc120000             -call 0x487240
    cpu.esp -= 4;
    sub_487240(app, cpu);
    if (cpu.terminate) return;
    // 00485f74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485f76  0f846b010000           -je 0x4860e7
    if (cpu.flags.zf)
    {
        goto L_0x004860e7;
    }
    // 00485f7c  ff442434               -inc dword ptr [esp + 0x34]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */))++;
    // 00485f80  8a242c                 -mov ah, byte ptr [esp + ebp]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + cpu.ebp * 1);
    // 00485f83  45                     -inc ebp
    (cpu.ebp)++;
    // 00485f84  80fc20                 +cmp ah, 0x20
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485f87  0f8384000000           -jae 0x486011
    if (!cpu.flags.cf)
    {
        goto L_0x00486011;
    }
    // 00485f8d  c6442cff5f             -mov byte ptr [esp + ebp - 1], 0x5f
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.ebp * 1) = 95 /*0x5f*/;
L_0x00485f92:
    // 00485f92  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00485f94:
    // 00485f94  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00485f98  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00485f9c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00485f9e  0f8489000000           -je 0x48602d
    if (cpu.flags.zf)
    {
        goto L_0x0048602d;
    }
L_0x00485fa4:
    // 00485fa4  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00485fa6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00485fa8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00485faa  883c2c                 -mov byte ptr [esp + ebp], bh
    app->getMemory<x86::reg8>(cpu.esp + cpu.ebp * 1) = cpu.bh;
L_0x00485fad:
    // 00485fad  8b0d5cb34c00           -mov ecx, dword ptr [0x4cb35c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5026652) /* 0x4cb35c */);
    // 00485fb3  49                     -dec ecx
    (cpu.ecx)--;
    // 00485fb4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485fb6  0f8cc1000000           -jl 0x48607d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048607d;
    }
    // 00485fbc  6bd90c                 -imul ebx, ecx, 0xc
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 00485fbf  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00485fc1:
    // 00485fc1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00485fc3  8b9364b24c00           -mov edx, dword ptr [ebx + 0x4cb264]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5026404) /* 0x4cb264 */);
    // 00485fc9  e8f9b00000             -call 0x4910c7
    cpu.esp -= 4;
    sub_4910c7(app, cpu);
    if (cpu.terminate) return;
    // 00485fce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485fd0  0f849b000000           -je 0x486071
    if (cpu.flags.zf)
    {
        goto L_0x00486071;
    }
    // 00485fd6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00485fd8  0f8e64000000           -jle 0x486042
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00486042;
    }
    // 00485fde  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00485fe3:
    // 00485fe3  8b1d60b34c00           -mov ebx, dword ptr [0x4cb360]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026656) /* 0x4cb360 */);
    // 00485fe9  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00485feb  a15cb24c00             -mov eax, dword ptr [0x4cb25c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026396) /* 0x4cb25c */);
    // 00485ff0  891d60b34c00           -mov dword ptr [0x4cb360], ebx
    app->getMemory<x86::reg32>(x86::reg32(5026656) /* 0x4cb360 */) = cpu.ebx;
    // 00485ff6  e8d93cffff             -call 0x479cd4
    cpu.esp -= 4;
    sub_479cd4(app, cpu);
    if (cpu.terminate) return;
    // 00485ffb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485ffd  0f8d43000000           -jge 0x486046
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00486046;
    }
L_0x00486003:
    // 00486003  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00486008  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048600b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048600c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048600d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048600e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048600f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486010  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486011:
    // 00486011  80fc30                 +cmp ah, 0x30
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486014  0f8278ffffff           -jb 0x485f92
    if (cpu.flags.cf)
    {
        goto L_0x00485f92;
    }
    // 0048601a  80fc39                 +cmp ah, 0x39
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048601d  0f876fffffff           -ja 0x485f92
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00485f92;
    }
    // 00486023  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00486028  e967ffffff             -jmp 0x485f94
    goto L_0x00485f94;
L_0x0048602d:
    // 0048602d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048602f  0f846fffffff           -je 0x485fa4
    if (cpu.flags.zf)
    {
        goto L_0x00485fa4;
    }
    // 00486035  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00486039  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0048603d  e962ffffff             -jmp 0x485fa4
    goto L_0x00485fa4;
L_0x00486042:
    // 00486042  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00486044  eb9d                   -jmp 0x485fe3
    goto L_0x00485fe3;
L_0x00486046:
    // 00486046  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0048604d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048604f  8b148564b24c00         -mov edx, dword ptr [eax*4 + 0x4cb264]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5026404) /* 0x4cb264 */ + cpu.eax * 4);
    // 00486056  8b04856cb24c00         -mov eax, dword ptr [eax*4 + 0x4cb26c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026412) /* 0x4cb26c */ + cpu.eax * 4);
    // 0048605d  891558b34c00           -mov dword ptr [0x4cb358], edx
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = cpu.edx;
    // 00486063  e88ea40000             -call 0x4904f6
    cpu.esp -= 4;
    sub_4904f6(app, cpu);
    if (cpu.terminate) return;
    // 00486068  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048606b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048606c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048606d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048606e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048606f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486070  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486071:
    // 00486071  49                     -dec ecx
    (cpu.ecx)--;
    // 00486072  83eb0c                 -sub ebx, 0xc
    (cpu.ebx) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00486075  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00486077  0f8d44ffffff           -jge 0x485fc1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00485fc1;
    }
L_0x0048607d:
    // 0048607d  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486080  47                     -inc edi
    (cpu.edi)++;
    // 00486081  83fe08                 +cmp esi, 8
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
    // 00486084  0f8c23ffffff           -jl 0x485fad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485fad;
    }
    // 0048608a  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048608e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00486090  7455                   -je 0x4860e7
    if (cpu.flags.zf)
    {
        goto L_0x004860e7;
    }
    // 00486092  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 00486097  754e                   -jne 0x4860e7
    if (!cpu.flags.zf)
    {
        goto L_0x004860e7;
    }
    // 00486099  833d60b34c0000         +cmp dword ptr [0x4cb360], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026656) /* 0x4cb360 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004860a0  7445                   -je 0x4860e7
    if (cpu.flags.zf)
    {
        goto L_0x004860e7;
    }
    // 004860a2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004860a4  e84da40000             -call 0x4904f6
    cpu.esp -= 4;
    sub_4904f6(app, cpu);
    if (cpu.terminate) return;
    // 004860a9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004860ab  83f80a                 +cmp eax, 0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004860ae  7c4e                   -jl 0x4860fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004860fe;
    }
    // 004860b0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004860b5:
    // 004860b5  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004860bc  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004860be  8b048564b24c00         -mov eax, dword ptr [eax*4 + 0x4cb264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026404) /* 0x4cb264 */ + cpu.eax * 4);
    // 004860c5  a358b34c00             -mov dword ptr [0x4cb358], eax
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = cpu.eax;
L_0x004860ca:
    // 004860ca  a15cb24c00             -mov eax, dword ptr [0x4cb25c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026396) /* 0x4cb25c */);
    // 004860cf  e8003cffff             -call 0x479cd4
    cpu.esp -= 4;
    sub_479cd4(app, cpu);
    if (cpu.terminate) return;
    // 004860d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004860d6  0f8c27ffffff           -jl 0x486003
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486003;
    }
    // 004860dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004860de  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004860e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004860e7:
    // 004860e7  83fd29                 +cmp ebp, 0x29
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004860ea  0f8c4efeffff           -jl 0x485f3e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485f3e;
    }
    // 004860f0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004860f5  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004860f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004860fe:
    // 004860fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486100  7c04                   -jl 0x486106
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486106;
    }
    // 00486102  7db1                   -jge 0x4860b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004860b5;
    }
    // 00486104  ebc4                   -jmp 0x4860ca
    goto L_0x004860ca;
L_0x00486106:
    // 00486106  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0048610b  ebbd                   -jmp 0x4860ca
    goto L_0x004860ca;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486110  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486111  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486112  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486113  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486114  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486117  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00486119  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048611c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048611e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486120  49                     -dec ecx
    (cpu.ecx)--;
    // 00486121  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00486123  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00486125  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00486127  49                     -dec ecx
    (cpu.ecx)--;
    // 00486128  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048612a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048612c  891554b34c00           -mov dword ptr [0x4cb354], edx
    app->getMemory<x86::reg32>(x86::reg32(5026644) /* 0x4cb354 */) = cpu.edx;
    // 00486132  83f931                 +cmp ecx, 0x31
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49 /*0x31*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486135  0f8fb5000000           -jg 0x4861f0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004861f0;
    }
    // 0048613b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048613d  7407                   -je 0x486146
    if (cpu.flags.zf)
    {
        goto L_0x00486146;
    }
    // 0048613f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00486141  e85a080000             -call 0x4869a0
    cpu.esp -= 4;
    sub_4869a0(app, cpu);
    if (cpu.terminate) return;
L_0x00486146:
    // 00486146  a120a44c00             -mov eax, dword ptr [0x4ca420]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 0048614b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048614d  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00486152  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00486155  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00486157  e8783bffff             -call 0x479cd4
    cpu.esp -= 4;
    sub_479cd4(app, cpu);
    if (cpu.terminate) return;
    // 0048615c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048615e  0f8c8c000000           -jl 0x4861f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004861f0;
    }
    // 00486164  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00486166  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00486169  e812080000             -call 0x486980
    cpu.esp -= 4;
    sub_486980(app, cpu);
    if (cpu.terminate) return;
    // 0048616e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00486170  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00486172  e8c90b0000             -call 0x486d40
    cpu.esp -= 4;
    sub_486d40(app, cpu);
    if (cpu.terminate) return;
    // 00486177  bb74074c00             -mov ebx, 0x4c0774
    cpu.ebx = 4982644 /*0x4c0774*/;
    // 0048617c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00486181  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00486183  e8b80b0000             -call 0x486d40
    cpu.esp -= 4;
    sub_486d40(app, cpu);
    if (cpu.terminate) return;
    // 00486188  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 0048618d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048618f  a120a44c00             -mov eax, dword ptr [0x4ca420]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00486194  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486196  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 0048619b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048619e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004861a0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004861a2  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004861a4:
    // 004861a4  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 004861a9  39f8                   +cmp eax, edi
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
    // 004861ab  7d4d                   -jge 0x4861fa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004861fa;
    }
    // 004861ad  833d54b34c0000         +cmp dword ptr [0x4cb354], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026644) /* 0x4cb354 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004861b4  7544                   -jne 0x4861fa
    if (!cpu.flags.zf)
    {
        goto L_0x004861fa;
    }
    // 004861b6  bb10df5100             -mov ebx, 0x51df10
    cpu.ebx = 5365520 /*0x51df10*/;
    // 004861bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004861bd  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004861c2  e8793affff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 004861c7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004861c9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004861cb  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004861cd  e86e100000             -call 0x487240
    cpu.esp -= 4;
    sub_487240(app, cpu);
    if (cpu.terminate) return;
    // 004861d2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004861d4  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 004861d6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004861d9  88a610df5100           -mov byte ptr [esi + 0x51df10], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5365520) /* 0x51df10 */) = cpu.ah;
    // 004861df  b810df5100             -mov eax, 0x51df10
    cpu.eax = 5365520 /*0x51df10*/;
    // 004861e4  e8deae0000             -call 0x4910c7
    cpu.esp -= 4;
    sub_4910c7(app, cpu);
    if (cpu.terminate) return;
    // 004861e9  a354b34c00             -mov dword ptr [0x4cb354], eax
    app->getMemory<x86::reg32>(x86::reg32(5026644) /* 0x4cb354 */) = cpu.eax;
    // 004861ee  ebb4                   -jmp 0x4861a4
    goto L_0x004861a4;
L_0x004861f0:
    // 004861f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004861f2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004861f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004861f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004861f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004861f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004861f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004861fa:
    // 004861fa  833d54b34c0000         +cmp dword ptr [0x4cb354], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026644) /* 0x4cb354 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486201  74ed                   -je 0x4861f0
    if (cpu.flags.zf)
    {
        goto L_0x004861f0;
    }
    // 00486203  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00486208  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048620b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048620c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048620d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048620e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048620f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486210  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486211  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486212  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486213  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486214  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486215  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00486217  833d5cb24c0000         +cmp dword ptr [0x4cb25c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026396) /* 0x4cb25c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048621e  7518                   -jne 0x486238
    if (!cpu.flags.zf)
    {
        goto L_0x00486238;
    }
    // 00486220  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00486226  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486228  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048622b  c1e202                 +shl edx, 2
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
    // 0048622e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00486230  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00486233  a35cb24c00             -mov dword ptr [0x4cb25c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026396) /* 0x4cb25c */) = cpu.eax;
L_0x00486238:
    // 00486238  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 0048623e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00486245  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00486247  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486249  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048624c  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048624e  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00486250  e87f3affff             -call 0x479cd4
    cpu.esp -= 4;
    sub_479cd4(app, cpu);
    if (cpu.terminate) return;
    // 00486255  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486257  7d08                   -jge 0x486261
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00486261;
    }
L_0x00486259:
    // 00486259  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048625b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048625c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048625d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048625e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048625f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486260  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486261:
    // 00486261  bb78074c00             -mov ebx, 0x4c0778
    cpu.ebx = 4982648 /*0x4c0778*/;
    // 00486266  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0048626b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048626d  e8ce0a0000             -call 0x486d40
    cpu.esp -= 4;
    sub_486d40(app, cpu);
    if (cpu.terminate) return;
    // 00486272  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00486278  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048627f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00486281  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486283  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00486286  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00486288  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048628a  e8453affff             -call 0x479cd4
    cpu.esp -= 4;
    sub_479cd4(app, cpu);
    if (cpu.terminate) return;
    // 0048628f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486291  7cc6                   -jl 0x486259
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486259;
    }
    // 00486293  8b1d60b24c00           -mov ebx, dword ptr [0x4cb260]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026400) /* 0x4cb260 */);
    // 00486299  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048629b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048629d  49                     -dec ecx
    (cpu.ecx)--;
    // 0048629e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004862a0  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004862a2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004862a4  49                     -dec ecx
    (cpu.ecx)--;
    // 004862a5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004862a7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004862a9  e8920a0000             -call 0x486d40
    cpu.esp -= 4;
    sub_486d40(app, cpu);
    if (cpu.terminate) return;
    // 004862ae  a15cb24c00             -mov eax, dword ptr [0x4cb25c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026396) /* 0x4cb25c */);
    // 004862b3  e81c3affff             -call 0x479cd4
    cpu.esp -= 4;
    sub_479cd4(app, cpu);
    if (cpu.terminate) return;
    // 004862b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004862ba  7c9d                   -jl 0x486259
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486259;
    }
    // 004862bc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004862be  ba7c074c00             -mov edx, 0x4c077c
    cpu.edx = 4982652 /*0x4c077c*/;
    // 004862c3  e8b8060000             -call 0x486980
    cpu.esp -= 4;
    sub_486980(app, cpu);
    if (cpu.terminate) return;
    // 004862c8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004862ca  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004862cc  e83ffeffff             -call 0x486110
    cpu.esp -= 4;
    sub_486110(app, cpu);
    if (cpu.terminate) return;
    // 004862d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004862d3  7484                   -je 0x486259
    if (cpu.flags.zf)
    {
        goto L_0x00486259;
    }
    // 004862d5  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 004862db  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004862dd  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004862df  e808fcffff             -call 0x485eec
    cpu.esp -= 4;
    sub_485eec(app, cpu);
    if (cpu.terminate) return;
    // 004862e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004862e6  0f856dffffff           -jne 0x486259
    if (!cpu.flags.zf)
    {
        goto L_0x00486259;
    }
    // 004862ec  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004862f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004862f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004862f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004862f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004862f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004862f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4862f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004862f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004862f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004862fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004862fb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004862fd  ba80074c00             -mov edx, 0x4c0780
    cpu.edx = 4982656 /*0x4c0780*/;
    // 00486302  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00486304  e807feffff             -call 0x486110
    cpu.esp -= 4;
    sub_486110(app, cpu);
    if (cpu.terminate) return;
    // 00486309  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 0048630f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486311  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00486313  e8d4fbffff             -call 0x485eec
    cpu.esp -= 4;
    sub_485eec(app, cpu);
    if (cpu.terminate) return;
    // 00486318  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486319  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048631a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048631b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_486320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486320  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486321  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00486323  833d64b34c0000         +cmp dword ptr [0x4cb364], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026660) /* 0x4cb364 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048632a  7416                   -je 0x486342
    if (cpu.flags.zf)
    {
        goto L_0x00486342;
    }
L_0x0048632c:
    // 0048632c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048632e  42                     -inc edx
    (cpu.edx)++;
    // 0048632f  e88c060000             -call 0x4869c0
    cpu.esp -= 4;
    sub_4869c0(app, cpu);
    if (cpu.terminate) return;
    // 00486334  83fa10                 +cmp edx, 0x10
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
    // 00486337  7d09                   -jge 0x486342
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00486342;
    }
    // 00486339  833d64b34c0000         +cmp dword ptr [0x4cb364], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026660) /* 0x4cb364 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486340  75ea                   -jne 0x48632c
    if (!cpu.flags.zf)
    {
        goto L_0x0048632c;
    }
L_0x00486342:
    // 00486342  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486343  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486344(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486344  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486345  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486347  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 0048634c  e877a8ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00486351  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00486358  8b8850df5100           -mov ecx, dword ptr [eax + 0x51df50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5365584) /* 0x51df50 */);
    // 0048635e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00486360  750c                   -jne 0x48636e
    if (!cpu.flags.zf)
    {
        goto L_0x0048636e;
    }
    // 00486362  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486367  e874a8ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048636c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048636d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048636e:
    // 0048636e  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00486370  8b1568b34c00           -mov edx, dword ptr [0x4cb368]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5026664) /* 0x4cb368 */);
    // 00486376  b890df5100             -mov eax, 0x51df90
    cpu.eax = 5365648 /*0x51df90*/;
    // 0048637b  e820a7ffff             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 00486380  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486385  e856a8ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048638a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048638b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48638c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048638c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048638d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048638e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048638f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486390  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486391  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486392  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00486394  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486399  e82aa8ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048639e  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004863a2  7518                   -jne 0x4863bc
    if (!cpu.flags.zf)
    {
        goto L_0x004863bc;
    }
    // 004863a4  8d7318                 -lea esi, [ebx + 0x18]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004863a7  8d6b14                 -lea ebp, [ebx + 0x14]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004863aa  8d7b2c                 -lea edi, [ebx + 0x2c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(44) /* 0x2c */);
L_0x004863ad:
    // 004863ad  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004863b0  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004863b6  0f8cbb000000           -jl 0x486477
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486477;
    }
L_0x004863bc:
    // 004863bc  8dbb3c020000           -lea edi, [ebx + 0x23c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(572) /* 0x23c */);
    // 004863c2  8dab38020000           -lea ebp, [ebx + 0x238]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 004863c8  8db350020000           -lea esi, [ebx + 0x250]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(592) /* 0x250 */);
L_0x004863ce:
    // 004863ce  83bb2c02000000         +cmp dword ptr [ebx + 0x22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004863d5  0f854c010000           -jne 0x486527
    if (!cpu.flags.zf)
    {
        goto L_0x00486527;
    }
    // 004863db  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 004863e1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004863e3  0f8e3e010000           -jle 0x486527
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00486527;
    }
    // 004863e9  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 004863ef  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004863f1  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004863f7  0f8e03010000           -jle 0x486500
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00486500;
    }
    // 004863fd  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 00486402  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00486404:
    // 00486404  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486405  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486406  c7833c02000000000000   -mov dword ptr [ebx + 0x23c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(572) /* 0x23c */) = 0 /*0x0*/;
    // 00486410  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486411  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00486413  c7834002000000000000   -mov dword ptr [ebx + 0x240], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(576) /* 0x240 */) = 0 /*0x0*/;
    // 0048641d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048641e  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00486421  c7834402000000000000   -mov dword ptr [ebx + 0x244], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(580) /* 0x244 */) = 0 /*0x0*/;
    // 0048642b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048642c  c7834802000000000000   -mov dword ptr [ebx + 0x248], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(584) /* 0x248 */) = 0 /*0x0*/;
    // 00486436  2eff15dc754b00         -call dword ptr cs:[0x4b75dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945372) /* 0x4b75dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048643d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048643f  0f84c6000000           -je 0x48650b
    if (cpu.flags.zf)
    {
        goto L_0x0048650b;
    }
    // 00486445  8b8338020000           -mov eax, dword ptr [ebx + 0x238]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 0048644b  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 00486451  8b8b38020000           -mov ecx, dword ptr [ebx + 0x238]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 00486457  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00486459  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 0048645f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00486461  899334020000           -mov dword ptr [ebx + 0x234], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = cpu.edx;
    // 00486467  25ff010000             +and eax, 0x1ff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/))));
    // 0048646c  898330020000           -mov dword ptr [ebx + 0x230], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.eax;
    // 00486472  e957ffffff             -jmp 0x4863ce
    goto L_0x004863ce;
L_0x00486477:
    // 00486477  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0048647a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048647c  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00486481  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00486484  39d0                   +cmp eax, edx
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
    // 00486486  7d4e                   -jge 0x4864d6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004864d6;
    }
L_0x00486488:
    // 00486488  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048648a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048648b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048648c  c7431800000000         -mov dword ptr [ebx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00486493  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486494  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00486496  c7431c00000000         -mov dword ptr [ebx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0048649d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048649e  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004864a1  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004864a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004864a9  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004864b0  2eff155c754b00         -call dword ptr cs:[0x4b755c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945244) /* 0x4b755c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004864b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004864b9  7422                   -je 0x4864dd
    if (cpu.flags.zf)
    {
        goto L_0x004864dd;
    }
    // 004864bb  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004864be  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004864c1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004864c3  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004864c6  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004864c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004864cb  0f84dcfeffff           -je 0x4863ad
    if (cpu.flags.zf)
    {
        goto L_0x004863ad;
    }
    // 004864d1  e9e6feffff             -jmp 0x4863bc
    goto L_0x004863bc;
L_0x004864d6:
    // 004864d6  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 004864db  ebab                   -jmp 0x486488
    goto L_0x00486488;
L_0x004864dd:
    // 004864dd  2eff15ec744b00         -call dword ptr cs:[0x4b74ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945132) /* 0x4b74ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004864e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004864e6  750c                   -jne 0x4864f4
    if (!cpu.flags.zf)
    {
        goto L_0x004864f4;
    }
L_0x004864e8:
    // 004864e8  c7430801000000         -mov dword ptr [ebx + 8], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 004864ef  e9c8feffff             -jmp 0x4863bc
    goto L_0x004863bc;
L_0x004864f4:
    // 004864f4  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004864f9  74ed                   -je 0x4864e8
    if (cpu.flags.zf)
    {
        goto L_0x004864e8;
    }
    // 004864fb  e9bcfeffff             -jmp 0x4863bc
    goto L_0x004863bc;
L_0x00486500:
    // 00486500  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 00486506  e9f9feffff             -jmp 0x486404
    goto L_0x00486404;
L_0x0048650b:
    // 0048650b  2eff15ec744b00         -call dword ptr cs:[0x4b74ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945132) /* 0x4b74ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486512  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486514  7407                   -je 0x48651d
    if (cpu.flags.zf)
    {
        goto L_0x0048651d;
    }
    // 00486516  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048651b  750a                   -jne 0x486527
    if (!cpu.flags.zf)
    {
        goto L_0x00486527;
    }
L_0x0048651d:
    // 0048651d  c7832c02000001000000   -mov dword ptr [ebx + 0x22c], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 1 /*0x1*/;
L_0x00486527:
    // 00486527  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 0048652c  e8afa6ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486531  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486532  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486533  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486534  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486535  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486536  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486537  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486538(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486538  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486539  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048653a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048653b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048653e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00486540  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486545  e87ea6ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048654a  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048654e  751e                   -jne 0x48656e
    if (!cpu.flags.zf)
    {
        goto L_0x0048656e;
    }
L_0x00486550:
    // 00486550  83bb2c02000000         +cmp dword ptr [ebx + 0x22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486557  0f856e000000           -jne 0x4865cb
    if (!cpu.flags.zf)
    {
        goto L_0x004865cb;
    }
L_0x0048655d:
    // 0048655d  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486562  e879a6ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486567  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048656a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048656b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048656c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048656d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048656e:
    // 0048656e  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00486571  e836a5ffff             -call 0x480aac
    cpu.esp -= 4;
    sub_480aac(app, cpu);
    if (cpu.terminate) return;
    // 00486576  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486578  74d6                   -je 0x486550
    if (cpu.flags.zf)
    {
        goto L_0x00486550;
    }
    // 0048657a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048657c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00486580  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486581  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00486584  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486585  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00486588  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486589  2eff150c754b00         -call dword ptr cs:[0x4b750c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945164) /* 0x4b750c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486590  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486592  7418                   -je 0x4865ac
    if (cpu.flags.zf)
    {
        goto L_0x004865ac;
    }
    // 00486594  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486595  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00486599  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048659b  750a                   -jne 0x4865a7
    if (!cpu.flags.zf)
    {
        goto L_0x004865a7;
    }
L_0x0048659d:
    // 0048659d  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004865a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004865a5  eba9                   -jmp 0x486550
    goto L_0x00486550;
L_0x004865a7:
    // 004865a7  017310                 +add dword ptr [ebx + 0x10], esi
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004865aa  ebf1                   -jmp 0x48659d
    goto L_0x0048659d;
L_0x004865ac:
    // 004865ac  2eff15ec744b00         -call dword ptr cs:[0x4b74ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945132) /* 0x4b74ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004865b3  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004865b8  750a                   -jne 0x4865c4
    if (!cpu.flags.zf)
    {
        goto L_0x004865c4;
    }
    // 004865ba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004865bf  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004865c2  eb8c                   -jmp 0x486550
    goto L_0x00486550;
L_0x004865c4:
    // 004865c4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004865c6  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004865c9  eb85                   -jmp 0x486550
    goto L_0x00486550;
L_0x004865cb:
    // 004865cb  8b834c020000           -mov eax, dword ptr [ebx + 0x24c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */);
    // 004865d1  e8d6a4ffff             -call 0x480aac
    cpu.esp -= 4;
    sub_480aac(app, cpu);
    if (cpu.terminate) return;
    // 004865d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004865d8  7483                   -je 0x48655d
    if (cpu.flags.zf)
    {
        goto L_0x0048655d;
    }
    // 004865da  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004865dc  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004865e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004865e1  8d833c020000           -lea eax, [ebx + 0x23c]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(572) /* 0x23c */);
    // 004865e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004865e8  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004865eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004865ec  2eff150c754b00         -call dword ptr cs:[0x4b750c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945164) /* 0x4b750c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004865f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004865f5  743c                   -je 0x486633
    if (cpu.flags.zf)
    {
        goto L_0x00486633;
    }
    // 004865f7  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004865fa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004865fc  741a                   -je 0x486618
    if (cpu.flags.zf)
    {
        goto L_0x00486618;
    }
    // 004865fe  299334020000           -sub dword ptr [ebx + 0x234], edx
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00486604  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 0048660a  030424                 -add eax, dword ptr [esp]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0048660d  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00486612  898330020000           -mov dword ptr [ebx + 0x230], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.eax;
L_0x00486618:
    // 00486618  c7832c02000000000000   -mov dword ptr [ebx + 0x22c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 0 /*0x0*/;
    // 00486622  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486627  e8b4a5ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048662c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048662f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486630  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486631  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486632  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486633:
    // 00486633  2eff15ec744b00         -call dword ptr cs:[0x4b74ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945132) /* 0x4b74ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048663a  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048663f  751c                   -jne 0x48665d
    if (!cpu.flags.zf)
    {
        goto L_0x0048665d;
    }
    // 00486641  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00486646:
    // 00486646  89832c020000           -mov dword ptr [ebx + 0x22c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = cpu.eax;
    // 0048664c  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486651  e88aa5ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486656  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486659  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048665a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048665b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048665c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048665d:
    // 0048665d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048665f  ebe5                   -jmp 0x486646
    goto L_0x00486646;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486664(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486664  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486665  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486666  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486667  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0048666d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00486672  a168b34c00             -mov eax, dword ptr [0x4cb368]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026664) /* 0x4cb368 */);
    // 00486677  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048667a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048667c:
    // 0048667c  8b9050df5100           -mov edx, dword ptr [eax + 0x51df50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5365584) /* 0x51df50 */);
    // 00486682  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00486684  7422                   -je 0x4866a8
    if (cpu.flags.zf)
    {
        goto L_0x004866a8;
    }
    // 00486686  837a0800               +cmp dword ptr [edx + 8], 0
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
    // 0048668a  7408                   -je 0x486694
    if (cpu.flags.zf)
    {
        goto L_0x00486694;
    }
    // 0048668c  41                     -inc ecx
    (cpu.ecx)++;
    // 0048668d  8b5a28                 -mov ebx, dword ptr [edx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 00486690  895c8cfc               -mov dword ptr [esp + ecx*4 - 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.ebx;
L_0x00486694:
    // 00486694  83ba2c02000000         +cmp dword ptr [edx + 0x22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048669b  740b                   -je 0x4866a8
    if (cpu.flags.zf)
    {
        goto L_0x004866a8;
    }
    // 0048669d  41                     -inc ecx
    (cpu.ecx)++;
    // 0048669e  8b924c020000           -mov edx, dword ptr [edx + 0x24c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(588) /* 0x24c */);
    // 004866a4  89548cfc               -mov dword ptr [esp + ecx*4 - 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.edx;
L_0x004866a8:
    // 004866a8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004866ab  83f840                 +cmp eax, 0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004866ae  75cc                   -jne 0x48667c
    if (!cpu.flags.zf)
    {
        goto L_0x0048667c;
    }
    // 004866b0  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004866b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004866b4  e89fa4ffff             -call 0x480b58
    cpu.esp -= 4;
    sub_480b58(app, cpu);
    if (cpu.terminate) return;
    // 004866b9  81c484000000           -add esp, 0x84
    (cpu.esp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 004866bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4866c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004866c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004866c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004866c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004866c7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004866c8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004866c9  e8bea3ffff             -call 0x480a8c
    cpu.esp -= 4;
    sub_480a8c(app, cpu);
    if (cpu.terminate) return;
    // 004866ce  a368b34c00             -mov dword ptr [0x4cb368], eax
    app->getMemory<x86::reg32>(x86::reg32(5026664) /* 0x4cb368 */) = cpu.eax;
    // 004866d3  833d64b34c0000         +cmp dword ptr [0x4cb364], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026660) /* 0x4cb364 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004866da  0f8479000000           -je 0x486759
    if (cpu.flags.zf)
    {
        goto L_0x00486759;
    }
    // 004866e0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004866e2:
    // 004866e2  e87dffffff             -call 0x486664
    cpu.esp -= 4;
    sub_486664(app, cpu);
    if (cpu.terminate) return;
    // 004866e7  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004866e9:
    // 004866e9  8b9e50df5100           -mov ebx, dword ptr [esi + 0x51df50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5365584) /* 0x51df50 */);
    // 004866ef  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004866f1  7456                   -je 0x486749
    if (cpu.flags.zf)
    {
        goto L_0x00486749;
    }
    // 004866f3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004866f5  e83efeffff             -call 0x486538
    cpu.esp -= 4;
    sub_486538(app, cpu);
    if (cpu.terminate) return;
    // 004866fa  3b3b                   +cmp edi, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004866fc  743c                   -je 0x48673a
    if (cpu.flags.zf)
    {
        goto L_0x0048673a;
    }
    // 004866fe  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486703  e8c0a4ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00486708  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048670a  83f803                 +cmp eax, 3
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
    // 0048670d  7362                   -jae 0x486771
    if (!cpu.flags.cf)
    {
        goto L_0x00486771;
    }
    // 0048670f  83f802                 +cmp eax, 2
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
    // 00486712  751a                   -jne 0x48672e
    if (!cpu.flags.zf)
    {
        goto L_0x0048672e;
    }
    // 00486714  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00486716  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00486719  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048671a  2eff1554754b00         -call dword ptr cs:[0x4b7554]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945236) /* 0x4b7554 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486721  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486723  e810feffff             -call 0x486538
    cpu.esp -= 4;
    sub_486538(app, cpu);
    if (cpu.terminate) return;
    // 00486728  897b0c                 -mov dword ptr [ebx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0048672b  897b10                 -mov dword ptr [ebx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x0048672e:
    // 0048672e  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 00486730  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486735  e8a6a4ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x0048673a:
    // 0048673a  3bbe50df5100           +cmp edi, dword ptr [esi + 0x51df50]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5365584) /* 0x51df50 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486740  7407                   -je 0x486749
    if (cpu.flags.zf)
    {
        goto L_0x00486749;
    }
    // 00486742  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486744  e843fcffff             -call 0x48638c
    cpu.esp -= 4;
    sub_48638c(app, cpu);
    if (cpu.terminate) return;
L_0x00486749:
    // 00486749  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048674c  83fe40                 +cmp esi, 0x40
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048674f  7598                   -jne 0x4866e9
    if (!cpu.flags.zf)
    {
        goto L_0x004866e9;
    }
    // 00486751  3b3d64b34c00           +cmp edi, dword ptr [0x4cb364]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5026660) /* 0x4cb364 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486757  7589                   -jne 0x4866e2
    if (!cpu.flags.zf)
    {
        goto L_0x004866e2;
    }
L_0x00486759:
    // 00486759  a168b34c00             -mov eax, dword ptr [0x4cb368]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026664) /* 0x4cb368 */);
    // 0048675e  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00486760  e803a4ffff             -call 0x480b68
    cpu.esp -= 4;
    sub_480b68(app, cpu);
    if (cpu.terminate) return;
    // 00486765  891d68b34c00           -mov dword ptr [0x4cb368], ebx
    app->getMemory<x86::reg32>(x86::reg32(5026664) /* 0x4cb368 */) = cpu.ebx;
    // 0048676b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048676c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048676d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048676e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048676f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486770  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486771:
    // 00486771  7642                   -jbe 0x4867b5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004867b5;
    }
    // 00486773  83f804                 +cmp eax, 4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486776  75b6                   -jne 0x48672e
    if (!cpu.flags.zf)
    {
        goto L_0x0048672e;
    }
    // 00486778  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0048677a  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048677d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048677e  2eff1554754b00         -call dword ptr cs:[0x4b7554]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945236) /* 0x4b7554 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486785  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486787  e8acfdffff             -call 0x486538
    cpu.esp -= 4;
    sub_486538(app, cpu);
    if (cpu.terminate) return;
    // 0048678c  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048678f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486790  2eff1550744b00         -call dword ptr cs:[0x4b7450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944976) /* 0x4b7450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486797  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 0048679a  e8c9a3ffff             -call 0x480b68
    cpu.esp -= 4;
    sub_480b68(app, cpu);
    if (cpu.terminate) return;
    // 0048679f  8b834c020000           -mov eax, dword ptr [ebx + 0x24c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */);
    // 004867a5  e8bea3ffff             -call 0x480b68
    cpu.esp -= 4;
    sub_480b68(app, cpu);
    if (cpu.terminate) return;
    // 004867aa  89be50df5100           -mov dword ptr [esi + 0x51df50], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5365584) /* 0x51df50 */) = cpu.edi;
    // 004867b0  e979ffffff             -jmp 0x48672e
    goto L_0x0048672e;
L_0x004867b5:
    // 004867b5  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 004867b7  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004867ba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004867bb  2eff1554754b00         -call dword ptr cs:[0x4b7554]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945236) /* 0x4b7554 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004867c2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004867c4  e86ffdffff             -call 0x486538
    cpu.esp -= 4;
    sub_486538(app, cpu);
    if (cpu.terminate) return;
    // 004867c9  89bb30020000           -mov dword ptr [ebx + 0x230], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.edi;
    // 004867cf  89bb34020000           -mov dword ptr [ebx + 0x234], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = cpu.edi;
    // 004867d5  e954ffffff             -jmp 0x48672e
    goto L_0x0048672e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4867dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004867dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004867de  7c10                   -jl 0x4867f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004867f0;
    }
    // 004867e0  83f810                 +cmp eax, 0x10
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
    // 004867e3  7d0b                   -jge 0x4867f0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004867f0;
    }
    // 004867e5  833c8550df510000       +cmp dword ptr [eax*4 + 0x51df50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004867ed  7504                   -jne 0x4867f3
    if (!cpu.flags.zf)
    {
        goto L_0x004867f3;
    }
    // 004867ef  90                     -nop 
    ;
L_0x004867f0:
    // 004867f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004867f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004867f3:
    // 004867f3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004867f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4867fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004867fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004867fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004867fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004867ff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486801  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486808  750a                   -jne 0x486814
    if (!cpu.flags.zf)
    {
        goto L_0x00486814;
    }
    // 0048680a  e869a3ffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 0048680f  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x00486814:
    // 00486814  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486819  e8aaa3ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048681e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486820  e8b7ffffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 00486825  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486827  750e                   -jne 0x486837
    if (!cpu.flags.zf)
    {
        goto L_0x00486837;
    }
L_0x00486829:
    // 00486829  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 0048682e  e8ada3ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486833  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486834  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486835  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486836  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486837:
    // 00486837  8b049550df5100         -mov eax, dword ptr [edx*4 + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.edx * 4);
    // 0048683e  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00486840  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00486843  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486844  2eff157c744b00         -call dword ptr cs:[0x4b747c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945020) /* 0x4b747c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048684b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048684d  75da                   -jne 0x486829
    if (!cpu.flags.zf)
    {
        goto L_0x00486829;
    }
    // 0048684f  e804a4ffff             -call 0x480c58
    cpu.esp -= 4;
    sub_480c58(app, cpu);
    if (cpu.terminate) return;
    // 00486854  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486859  e882a3ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048685e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048685f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486860  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486861  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486864(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486864  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486865  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486866  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486867  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486869  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486870  750a                   -jne 0x48687c
    if (!cpu.flags.zf)
    {
        goto L_0x0048687c;
    }
    // 00486872  e801a3ffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00486877  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x0048687c:
    // 0048687c  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486881  e842a3ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00486886  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486888  e84fffffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 0048688d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048688f  750e                   -jne 0x48689f
    if (!cpu.flags.zf)
    {
        goto L_0x0048689f;
    }
L_0x00486891:
    // 00486891  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486896  e845a3ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048689b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048689c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048689d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048689e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048689f:
    // 0048689f  8b049550df5100         -mov eax, dword ptr [edx*4 + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.edx * 4);
    // 004868a6  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 004868a8  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004868ab  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004868ac  2eff157c744b00         -call dword ptr cs:[0x4b747c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945020) /* 0x4b747c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004868b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004868b5  75da                   -jne 0x486891
    if (!cpu.flags.zf)
    {
        goto L_0x00486891;
    }
    // 004868b7  e89ca3ffff             -call 0x480c58
    cpu.esp -= 4;
    sub_480c58(app, cpu);
    if (cpu.terminate) return;
    // 004868bc  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 004868c1  e81aa3ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004868c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004868c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004868c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004868c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4868cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004868cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004868cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004868ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004868cf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004868d0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004868d3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004868d5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004868da  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004868e1  750a                   -jne 0x4868ed
    if (!cpu.flags.zf)
    {
        goto L_0x004868ed;
    }
    // 004868e3  e890a2ffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 004868e8  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x004868ed:
    // 004868ed  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 004868f2  e8d1a2ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004868f7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004868f9  e8defeffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 004868fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486900  7514                   -jne 0x486916
    if (!cpu.flags.zf)
    {
        goto L_0x00486916;
    }
    // 00486902  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486907  e8d4a2ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048690c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048690e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486911  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486912  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486913  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486914  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486915  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486916:
    // 00486916  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00486918  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486919  8b049550df5100         -mov eax, dword ptr [edx*4 + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.edx * 4);
    // 00486920  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00486923  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486924  2eff15a4744b00         -call dword ptr cs:[0x4b74a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945060) /* 0x4b74a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048692b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048692d  751f                   -jne 0x48694e
    if (!cpu.flags.zf)
    {
        goto L_0x0048694e;
    }
    // 0048692f  f6042480               +test byte ptr [esp], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp) & 128 /*0x80*/));
    // 00486933  7432                   -je 0x486967
    if (cpu.flags.zf)
    {
        goto L_0x00486967;
    }
    // 00486935  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048693a  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 0048693f  e89ca2ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486944  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486946  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486949  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048694a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048694b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048694c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048694d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048694e:
    // 0048694e  e805a3ffff             -call 0x480c58
    cpu.esp -= 4;
    sub_480c58(app, cpu);
    if (cpu.terminate) return;
    // 00486953  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486958  e883a2ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048695d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048695f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486962  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486963  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486964  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486965  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486966  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486967:
    // 00486967  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00486969  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 0048696e  e86da2ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486973  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486975  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486978  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486979  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048697a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048697b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048697c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486980  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486981  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486983  e854feffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 00486988  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048698a  7502                   -jne 0x48698e
    if (!cpu.flags.zf)
    {
        goto L_0x0048698e;
    }
    // 0048698c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048698d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048698e:
    // 0048698e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048698f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00486994  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486996  e8a9f9ffff             -call 0x486344
    cpu.esp -= 4;
    sub_486344(app, cpu);
    if (cpu.terminate) return;
    // 0048699b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048699c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048699d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4869a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004869a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004869a1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004869a3  e834feffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 004869a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004869aa  7502                   -jne 0x4869ae
    if (!cpu.flags.zf)
    {
        goto L_0x004869ae;
    }
    // 004869ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004869ae:
    // 004869ae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004869af  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004869b4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004869b6  e889f9ffff             -call 0x486344
    cpu.esp -= 4;
    sub_486344(app, cpu);
    if (cpu.terminate) return;
    // 004869bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4869c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004869c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004869c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004869c2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004869c4  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004869cb  0f8480000000           -je 0x486a51
    if (cpu.flags.zf)
    {
        goto L_0x00486a51;
    }
L_0x004869d1:
    // 004869d1  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 004869d6  e8eda1ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004869db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004869dd  e8fafdffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 004869e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004869e4  0f8476000000           -je 0x486a60
    if (cpu.flags.zf)
    {
        goto L_0x00486a60;
    }
    // 004869ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004869eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004869ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004869ed  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 004869f4  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004869f9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004869fb  8bb350df5100           -mov esi, dword ptr [ebx + 0x51df50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5365584) /* 0x51df50 */);
    // 00486a01  e83ef9ffff             -call 0x486344
    cpu.esp -= 4;
    sub_486344(app, cpu);
    if (cpu.terminate) return;
    // 00486a06  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486a0b  e8d0a1ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486a10  8bbb50df5100           -mov edi, dword ptr [ebx + 0x51df50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5365584) /* 0x51df50 */);
    // 00486a16  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00486a18  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00486a1a  7418                   -je 0x486a34
    if (cpu.flags.zf)
    {
        goto L_0x00486a34;
    }
    // 00486a1c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00486a21:
    // 00486a21  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486a23  e8f49dffff             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 00486a28  83ba50df510000         +cmp dword ptr [edx + 0x51df50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5365584) /* 0x51df50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486a2f  75f0                   -jne 0x486a21
    if (!cpu.flags.zf)
    {
        goto L_0x00486a21;
    }
    // 00486a31  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00486a34:
    // 00486a34  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486a36  e8513cffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00486a3b  ff0d64b34c00           -dec dword ptr [0x4cb364]
    (app->getMemory<x86::reg32>(x86::reg32(5026660) /* 0x4cb364 */))--;
    // 00486a41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a44  8b1564b34c00           -mov edx, dword ptr [0x4cb364]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5026660) /* 0x4cb364 */);
    // 00486a4a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00486a4c  7429                   -je 0x486a77
    if (cpu.flags.zf)
    {
        goto L_0x00486a77;
    }
    // 00486a4e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486a51:
    // 00486a51  e822a1ffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00486a56  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
    // 00486a5b  e971ffffff             -jmp 0x4869d1
    goto L_0x004869d1;
L_0x00486a60:
    // 00486a60  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486a65  e876a1ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486a6a  8b1564b34c00           -mov edx, dword ptr [0x4cb364]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5026660) /* 0x4cb364 */);
    // 00486a70  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00486a72  7403                   -je 0x486a77
    if (cpu.flags.zf)
    {
        goto L_0x00486a77;
    }
    // 00486a74  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486a77:
    // 00486a77  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486a79  e8c6f8ffff             -call 0x486344
    cpu.esp -= 4;
    sub_486344(app, cpu);
    if (cpu.terminate) return;
    // 00486a7e  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486a83  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486a85  e86aa1ffff             -call 0x480bf4
    cpu.esp -= 4;
    sub_480bf4(app, cpu);
    if (cpu.terminate) return;
    // 00486a8a  890d6cb34c00           -mov dword ptr [0x4cb36c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.ecx;
    // 00486a90  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486a94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486a94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486a95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486a96  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486a97  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486a98  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486a99  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00486a9c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00486a9e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00486aa0  83f8ff                 +cmp eax, -1
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
    // 00486aa3  752e                   -jne 0x486ad3
    if (!cpu.flags.zf)
    {
        goto L_0x00486ad3;
    }
    // 00486aa5  be0f000000             -mov esi, 0xf
    cpu.esi = 15 /*0xf*/;
    // 00486aaa  8b158cdf5100           -mov edx, dword ptr [0x51df8c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5365644) /* 0x51df8c */);
    // 00486ab0  b83c000000             -mov eax, 0x3c
    cpu.eax = 60 /*0x3c*/;
    // 00486ab5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00486ab7  7412                   -je 0x486acb
    if (cpu.flags.zf)
    {
        goto L_0x00486acb;
    }
L_0x00486ab9:
    // 00486ab9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486abb  7c0e                   -jl 0x486acb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486acb;
    }
    // 00486abd  8b884cdf5100           -mov ecx, dword ptr [eax + 0x51df4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5365580) /* 0x51df4c */);
    // 00486ac3  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486ac6  4e                     -dec esi
    (cpu.esi)--;
    // 00486ac7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00486ac9  75ee                   -jne 0x486ab9
    if (!cpu.flags.zf)
    {
        goto L_0x00486ab9;
    }
L_0x00486acb:
    // 00486acb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00486acd  0f8ccf000000           -jl 0x486ba2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486ba2;
    }
L_0x00486ad3:
    // 00486ad3  ff0564b34c00           -inc dword ptr [0x4cb364]
    (app->getMemory<x86::reg32>(x86::reg32(5026660) /* 0x4cb364 */))++;
    // 00486ad9  833d64b34c0001         +cmp dword ptr [0x4cb364], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026660) /* 0x4cb364 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486ae0  0f84ca000000           -je 0x486bb0
    if (cpu.flags.zf)
    {
        goto L_0x00486bb0;
    }
L_0x00486ae6:
    // 00486ae6  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 00486aeb  ba50040000             -mov edx, 0x450
    cpu.edx = 1104 /*0x450*/;
    // 00486af0  b888074c00             -mov eax, 0x4c0788
    cpu.eax = 4982664 /*0x4c0788*/;
    // 00486af5  e82e37ffff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00486afa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00486afc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00486afe  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00486b00  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00486b02  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00486b09  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00486b0b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00486b0d  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00486b10  2eff1554744b00         -call dword ptr cs:[0x4b7454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944980) /* 0x4b7454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486b17  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00486b19  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00486b20  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00486b22  c7431000000000         -mov dword ptr [ebx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00486b29  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00486b2b  c7832c02000000000000   -mov dword ptr [ebx + 0x22c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 0 /*0x0*/;
    // 00486b35  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00486b37  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00486b3a  2eff1554744b00         -call dword ptr cs:[0x4b7454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944980) /* 0x4b7454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486b41  c7833002000000000000   -mov dword ptr [ebx + 0x230], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = 0 /*0x0*/;
    // 00486b4b  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 00486b50  89834c020000           -mov dword ptr [ebx + 0x24c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */) = cpu.eax;
    // 00486b56  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00486b58  c7833402000000000000   -mov dword ptr [ebx + 0x234], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = 0 /*0x0*/;
    // 00486b62  e835a1ffff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00486b67  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00486b69  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486b6a  ba19000000             -mov edx, 0x19
    cpu.edx = 25 /*0x19*/;
    // 00486b6f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486b70  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00486b74  2eff1568754b00         -call dword ptr cs:[0x4b7568]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945256) /* 0x4b7568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486b7b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486b7d  7505                   -jne 0x486b84
    if (!cpu.flags.zf)
    {
        goto L_0x00486b84;
    }
    // 00486b7f  e8d4a0ffff             -call 0x480c58
    cpu.esp -= 4;
    sub_480c58(app, cpu);
    if (cpu.terminate) return;
L_0x00486b84:
    // 00486b84  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00486b89  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486b8b  892cb550df5100         -mov dword ptr [esi*4 + 0x51df50], ebp
    app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.esi * 4) = cpu.ebp;
    // 00486b92  e8adf7ffff             -call 0x486344
    cpu.esp -= 4;
    sub_486344(app, cpu);
    if (cpu.terminate) return;
    // 00486b97  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486b99  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00486b9c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b9d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b9e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ba0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ba1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486ba2:
    // 00486ba2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00486ba7  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00486baa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486baf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486bb0:
    // 00486bb0  b820634800             -mov eax, 0x486320
    cpu.eax = 4743968 /*0x486320*/;
    // 00486bb5  e8229b0000             -call 0x4906dc
    cpu.esp -= 4;
    sub_4906dc(app, cpu);
    if (cpu.terminate) return;
    // 00486bba  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486bc1  750a                   -jne 0x486bcd
    if (!cpu.flags.zf)
    {
        goto L_0x00486bcd;
    }
    // 00486bc3  e8b09fffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00486bc8  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x00486bcd:
    // 00486bcd  6890df5100             -push 0x51df90
    app->getMemory<x86::reg32>(cpu.esp-4) = 5365648 /*0x51df90*/;
    cpu.esp -= 4;
    // 00486bd2  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00486bd7  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00486bdc  b8c4664800             -mov eax, 0x4866c4
    cpu.eax = 4744900 /*0x4866c4*/;
    // 00486be1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00486be3  e8789bffff             -call 0x480760
    cpu.esp -= 4;
    sub_480760(app, cpu);
    if (cpu.terminate) return;
    // 00486be8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486bea  0f85f6feffff           -jne 0x486ae6
    if (!cpu.flags.zf)
    {
        goto L_0x00486ae6;
    }
    // 00486bf0  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486bf5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486bf7  e8f89fffff             -call 0x480bf4
    cpu.esp -= 4;
    sub_480bf4(app, cpu);
    if (cpu.terminate) return;
    // 00486bfc  890d6cb34c00           -mov dword ptr [0x4cb36c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.ecx;
    // 00486c02  a164b34c00             -mov eax, dword ptr [0x4cb364]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026660) /* 0x4cb364 */);
    // 00486c07  ff0d64b34c00           -dec dword ptr [0x4cb364]
    (app->getMemory<x86::reg32>(x86::reg32(5026660) /* 0x4cb364 */))--;
    // 00486c0d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00486c12  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00486c15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486c1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486c1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486c1d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486c1e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486c1f  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00486c22  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00486c24  8b148550df5100         -mov edx, dword ptr [eax*4 + 0x51df50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.eax * 4);
    // 00486c2b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00486c2d  7407                   -je 0x486c36
    if (cpu.flags.zf)
    {
        goto L_0x00486c36;
    }
    // 00486c2f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00486c32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c35  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486c36:
    // 00486c36  40                     -inc eax
    (cpu.eax)++;
    // 00486c37  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486c38  6894074c00             -push 0x4c0794
    app->getMemory<x86::reg32>(cpu.esp-4) = 4982676 /*0x4c0794*/;
    cpu.esp -= 4;
    // 00486c3d  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00486c41  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486c42  e89a53ffff             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00486c47  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00486c4a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486c4b  6880000040             -push 0x40000080
    app->getMemory<x86::reg32>(cpu.esp-4) = 1073741952 /*0x40000080*/;
    cpu.esp -= 4;
    // 00486c50  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00486c52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486c53  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486c54  68000000c0             -push 0xc0000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 3221225472 /*0xc0000000*/;
    cpu.esp -= 4;
    // 00486c59  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00486c5d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486c5e  2eff1558744b00         -call dword ptr cs:[0x4b7458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944984) /* 0x4b7458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486c65  83f8ff                 +cmp eax, -1
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
    // 00486c68  7410                   -je 0x486c7a
    if (cpu.flags.zf)
    {
        goto L_0x00486c7a;
    }
    // 00486c6a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486c6c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486c6e  e821feffff             -call 0x486a94
    cpu.esp -= 4;
    sub_486a94(app, cpu);
    if (cpu.terminate) return;
    // 00486c73  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00486c76  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c78  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486c7a:
    // 00486c7a  e8d99fffff             -call 0x480c58
    cpu.esp -= 4;
    sub_480c58(app, cpu);
    if (cpu.terminate) return;
    // 00486c7f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00486c82  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486c88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486c88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486c89  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486c8b  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486c92  750a                   -jne 0x486c9e
    if (!cpu.flags.zf)
    {
        goto L_0x00486c9e;
    }
    // 00486c94  e8df9effff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00486c99  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x00486c9e:
    // 00486c9e  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486ca3  e8209fffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00486ca8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486caa  e82dfbffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 00486caf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486cb1  740b                   -je 0x486cbe
    if (cpu.flags.zf)
    {
        goto L_0x00486cbe;
    }
    // 00486cb3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486cb5  e822030000             -call 0x486fdc
    cpu.esp -= 4;
    sub_486fdc(app, cpu);
    if (cpu.terminate) return;
    // 00486cba  39d0                   +cmp eax, edx
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
    // 00486cbc  7d10                   -jge 0x486cce
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00486cce;
    }
L_0x00486cbe:
    // 00486cbe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00486cc0  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486cc5  e8169fffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486cca  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486ccc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ccd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486cce:
    // 00486cce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486cd0  e86b000000             -call 0x486d40
    cpu.esp -= 4;
    sub_486d40(app, cpu);
    if (cpu.terminate) return;
    // 00486cd5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486cd7  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486cdc  e8ff9effff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486ce1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486ce3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ce4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486ce8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486ce8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486ce9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486cea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00486cec  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00486cee  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00486cf0  e8e7faffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 00486cf5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486cf7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486cf9  742d                   -je 0x486d28
    if (cpu.flags.zf)
    {
        goto L_0x00486d28;
    }
    // 00486cfb  031d60d25100           -add ebx, dword ptr [0x51d260]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */)));
L_0x00486d01:
    // 00486d01  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486d03  e8d4020000             -call 0x486fdc
    cpu.esp -= 4;
    sub_486fdc(app, cpu);
    if (cpu.terminate) return;
    // 00486d08  39d0                   +cmp eax, edx
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
    // 00486d0a  7d11                   -jge 0x486d1d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00486d1d;
    }
    // 00486d0c  3b1d60d25100           +cmp ebx, dword ptr [0x51d260]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486d12  7e09                   -jle 0x486d1d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00486d1d;
    }
    // 00486d14  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00486d16  e8252fffff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 00486d1b  ebe4                   -jmp 0x486d01
    goto L_0x00486d01;
L_0x00486d1d:
    // 00486d1d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486d1f  e8b8020000             -call 0x486fdc
    cpu.esp -= 4;
    sub_486fdc(app, cpu);
    if (cpu.terminate) return;
    // 00486d24  39d0                   +cmp eax, edx
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
    // 00486d26  7d05                   -jge 0x486d2d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00486d2d;
    }
L_0x00486d28:
    // 00486d28  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486d2a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d2c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486d2d:
    // 00486d2d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00486d2f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486d31  e80a000000             -call 0x486d40
    cpu.esp -= 4;
    sub_486d40(app, cpu);
    if (cpu.terminate) return;
    // 00486d36  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486d38  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486d3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486d40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486d41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486d42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486d43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486d44  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486d46  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00486d48  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00486d4a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00486d4c  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486d53  750a                   -jne 0x486d5f
    if (!cpu.flags.zf)
    {
        goto L_0x00486d5f;
    }
    // 00486d55  e81e9effff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00486d5a  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x00486d5f:
    // 00486d5f  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486d64  e85f9effff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00486d69  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486d6b  e86cfaffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 00486d70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486d72  0f84b1000000           -je 0x486e29
    if (cpu.flags.zf)
    {
        goto L_0x00486e29;
    }
    // 00486d78  8b048d50df5100         -mov eax, dword ptr [ecx*4 + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.ecx * 4);
    // 00486d7f  8bb034020000           -mov esi, dword ptr [eax + 0x234]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 00486d85  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00486d87  81fe00020000           +cmp esi, 0x200
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486d8d  7e0b                   -jle 0x486d9a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00486d9a;
    }
    // 00486d8f  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 00486d94  2b9034020000           -sub edx, dword ptr [eax + 0x234]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */)));
L_0x00486d9a:
    // 00486d9a  8b048d50df5100         -mov eax, dword ptr [ecx*4 + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.ecx * 4);
    // 00486da1  8b9830020000           -mov ebx, dword ptr [eax + 0x230]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(560) /* 0x230 */);
    // 00486da7  8b8034020000           -mov eax, dword ptr [eax + 0x234]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 00486dad  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00486daf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486db1  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00486db6  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00486db9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00486dbb  81fb00020000           +cmp ebx, 0x200
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486dc1  7e0b                   -jle 0x486dce
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00486dce;
    }
    // 00486dc3  be00020000             -mov esi, 0x200
    cpu.esi = 512 /*0x200*/;
    // 00486dc8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00486dca  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00486dcc  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00486dce:
    // 00486dce  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00486dd0  7418                   -je 0x486dea
    if (cpu.flags.zf)
    {
        goto L_0x00486dea;
    }
    // 00486dd2  8b148d50df5100         -mov edx, dword ptr [ecx*4 + 0x51df50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.ecx * 4);
    // 00486dd9  81c250020000           -add edx, 0x250
    (cpu.edx) += x86::reg32(x86::sreg32(592 /*0x250*/));
    // 00486ddf  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00486de1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00486de3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00486de5  e816a8ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
L_0x00486dea:
    // 00486dea  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00486dec  7417                   -je 0x486e05
    if (cpu.flags.zf)
    {
        goto L_0x00486e05;
    }
    // 00486dee  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00486df0  8b148d50df5100         -mov edx, dword ptr [ecx*4 + 0x51df50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.ecx * 4);
    // 00486df7  8d042e                 -lea eax, [esi + ebp]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 00486dfa  81c250020000           -add edx, 0x250
    (cpu.edx) += x86::reg32(x86::sreg32(592 /*0x250*/));
    // 00486e00  e8fba7ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
L_0x00486e05:
    // 00486e05  8b048d50df5100         -mov eax, dword ptr [ecx*4 + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.ecx * 4);
    // 00486e0c  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 00486e0f  8ba834020000           -mov ebp, dword ptr [eax + 0x234]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 00486e15  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00486e17  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00486e1c  89a834020000           -mov dword ptr [eax + 0x234], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */) = cpu.ebp;
    // 00486e22  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486e24  e81bf5ffff             -call 0x486344
    cpu.esp -= 4;
    sub_486344(app, cpu);
    if (cpu.terminate) return;
L_0x00486e29:
    // 00486e29  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486e2e  e8ad9dffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486e33  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 00486e36  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e37  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e3a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486e3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486e3c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486e3d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486e3e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486e3f  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00486e42  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00486e44  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00486e46  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00486e48  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00486e4a  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486e51  750a                   -jne 0x486e5d
    if (!cpu.flags.zf)
    {
        goto L_0x00486e5d;
    }
    // 00486e53  e8209dffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00486e58  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x00486e5d:
    // 00486e5d  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486e62  e8619dffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00486e67  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486e69  e86ef9ffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 00486e6e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486e70  7513                   -jne 0x486e85
    if (!cpu.flags.zf)
    {
        goto L_0x00486e85;
    }
L_0x00486e72:
    // 00486e72  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486e77  e8649dffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486e7c  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00486e7f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e82  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00486e85:
    // 00486e85  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00486e87  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486e88  8b04b550df5100         -mov eax, dword ptr [esi*4 + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.esi * 4);
    // 00486e8f  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00486e92  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486e93  2eff15ac744b00         -call dword ptr cs:[0x4b74ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945068) /* 0x4b74ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486e9a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486e9c  745c                   -je 0x486efa
    if (cpu.flags.zf)
    {
        goto L_0x00486efa;
    }
    // 00486e9e  804c240801             -or byte ptr [esp + 8], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00486ea3  6681642408fdb0         -and word ptr [esp + 8], 0xb0fd
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */) &= x86::reg16(x86::sreg16(45309 /*0xb0fd*/));
    // 00486eaa  83ff10                 +cmp edi, 0x10
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486ead  7f07                   -jg 0x486eb6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00486eb6;
    }
    // 00486eaf  8b3cbd70b34c00         -mov edi, dword ptr [edi*4 + 0x4cb370]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026672) /* 0x4cb370 */ + cpu.edi * 4);
L_0x00486eb6:
    // 00486eb6  8a44242c               -mov al, byte ptr [esp + 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00486eba  0405                   -add al, 5
    (cpu.al) += x86::reg8(x86::sreg8(5 /*0x5*/));
    // 00486ebc  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00486ec0  88442412               -mov byte ptr [esp + 0x12], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(18) /* 0x12 */) = cpu.al;
    // 00486ec4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00486ec6  764a                   -jbe 0x486f12
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486f12;
    }
    // 00486ec8  83fb01                 +cmp ebx, 1
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
    // 00486ecb  7545                   -jne 0x486f12
    if (!cpu.flags.zf)
    {
        goto L_0x00486f12;
    }
    // 00486ecd  c644241402             -mov byte ptr [esp + 0x14], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = 2 /*0x2*/;
L_0x00486ed2:
    // 00486ed2  83fd01                 +cmp ebp, 1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486ed5  7343                   -jae 0x486f1a
    if (!cpu.flags.cf)
    {
        goto L_0x00486f1a;
    }
L_0x00486ed7:
    // 00486ed7  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00486ed9  884c2413               -mov byte ptr [esp + 0x13], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = cpu.cl;
L_0x00486edd:
    // 00486edd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00486edf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486ee0  8b04b550df5100         -mov eax, dword ptr [esi*4 + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.esi * 4);
    // 00486ee7  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00486eea  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486eeb  2eff1564754b00         -call dword ptr cs:[0x4b7564]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945252) /* 0x4b7564 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486ef2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486ef4  0f8578ffffff           -jne 0x486e72
    if (!cpu.flags.zf)
    {
        goto L_0x00486e72;
    }
L_0x00486efa:
    // 00486efa  e8599dffff             -call 0x480c58
    cpu.esp -= 4;
    sub_480c58(app, cpu);
    if (cpu.terminate) return;
    // 00486eff  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486f04  e8d79cffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486f09  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00486f0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f0f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00486f12:
    // 00486f12  30f6                   +xor dh, dh
    cpu.clear_co();
    cpu.set_szp((cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh))));
    // 00486f14  88742414               -mov byte ptr [esp + 0x14], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dh;
    // 00486f18  ebb8                   -jmp 0x486ed2
    goto L_0x00486ed2;
L_0x00486f1a:
    // 00486f1a  7707                   -ja 0x486f23
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00486f23;
    }
    // 00486f1c  c644241301             -mov byte ptr [esp + 0x13], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = 1 /*0x1*/;
    // 00486f21  ebba                   -jmp 0x486edd
    goto L_0x00486edd;
L_0x00486f23:
    // 00486f23  83fd03                 +cmp ebp, 3
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486f26  75af                   -jne 0x486ed7
    if (!cpu.flags.zf)
    {
        goto L_0x00486ed7;
    }
    // 00486f28  c644241302             -mov byte ptr [esp + 0x13], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = 2 /*0x2*/;
    // 00486f2d  ebae                   -jmp 0x486edd
    goto L_0x00486edd;
}

/* align: skip 0x90 */
void Application::sub_486f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486f30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486f31  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486f33  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486f3a  750a                   -jne 0x486f46
    if (!cpu.flags.zf)
    {
        goto L_0x00486f46;
    }
    // 00486f3c  e8379cffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00486f41  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x00486f46:
    // 00486f46  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486f4b  e8789cffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00486f50  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486f52  e885f8ffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 00486f57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486f59  741b                   -je 0x486f76
    if (cpu.flags.zf)
    {
        goto L_0x00486f76;
    }
    // 00486f5b  8b149550df5100         -mov edx, dword ptr [edx*4 + 0x51df50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.edx * 4);
    // 00486f62  8b9234020000           -mov edx, dword ptr [edx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 00486f68  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486f6d  e86e9cffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486f72  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486f74  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f75  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486f76:
    // 00486f76  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00486f78  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486f7d  e85e9cffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486f82  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486f84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486f88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486f88  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486f89  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486f8b  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486f92  750a                   -jne 0x486f9e
    if (!cpu.flags.zf)
    {
        goto L_0x00486f9e;
    }
    // 00486f94  e8df9bffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00486f99  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x00486f9e:
    // 00486f9e  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486fa3  e8209cffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00486fa8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486faa  e82df8ffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 00486faf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486fb1  7418                   -je 0x486fcb
    if (cpu.flags.zf)
    {
        goto L_0x00486fcb;
    }
    // 00486fb3  8b149550df5100         -mov edx, dword ptr [edx*4 + 0x51df50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.edx * 4);
    // 00486fba  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00486fbd  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486fc2  e8199cffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486fc7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486fc9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486fcb:
    // 00486fcb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00486fcd  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486fd2  e8099cffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00486fd7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486fd9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486fdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00486fdc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486fdd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486fdf  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486fe6  750a                   -jne 0x486ff2
    if (!cpu.flags.zf)
    {
        goto L_0x00486ff2;
    }
    // 00486fe8  e88b9bffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00486fed  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x00486ff2:
    // 00486ff2  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00486ff7  e8cc9bffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00486ffc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486ffe  e8d9f7ffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 00487003  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487005  7426                   -je 0x48702d
    if (cpu.flags.zf)
    {
        goto L_0x0048702d;
    }
    // 00487007  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487008  8b149550df5100         -mov edx, dword ptr [edx*4 + 0x51df50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.edx * 4);
    // 0048700f  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 00487014  8b9a34020000           -mov ebx, dword ptr [edx + 0x234]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 0048701a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048701c  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048701e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048701f  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00487024  e8b79bffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00487029  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048702b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048702c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048702d:
    // 0048702d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048702f  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00487034  e8a79bffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00487039  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048703b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048703c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487040  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487041  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487042  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487043  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487044  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487046  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00487048  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048704a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048704c  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487053  750a                   -jne 0x48705f
    if (!cpu.flags.zf)
    {
        goto L_0x0048705f;
    }
    // 00487055  e81e9bffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 0048705a  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x0048705f:
    // 0048705f  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00487064  e85f9bffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00487069  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048706b  e86cf7ffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 00487070  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487072  0f846e000000           -je 0x4870e6
    if (cpu.flags.zf)
    {
        goto L_0x004870e6;
    }
    // 00487078  8b048d50df5100         -mov eax, dword ptr [ecx*4 + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.ecx * 4);
    // 0048707f  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00487082  39f2                   +cmp edx, esi
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
    // 00487084  7e02                   -jle 0x487088
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487088;
    }
    // 00487086  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x00487088:
    // 00487088  8b048d50df5100         -mov eax, dword ptr [ecx*4 + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.ecx * 4);
    // 0048708f  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00487092  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00487094  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00487096  81fb00020000           +cmp ebx, 0x200
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048709c  7e14                   -jle 0x4870b2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004870b2;
    }
    // 0048709e  bf00020000             -mov edi, 0x200
    cpu.edi = 512 /*0x200*/;
    // 004870a3  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004870a6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004870a8  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004870aa  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004870ac  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004870ae  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004870b0  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004870b2:
    // 004870b2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004870b4  7418                   -je 0x4870ce
    if (cpu.flags.zf)
    {
        goto L_0x004870ce;
    }
    // 004870b6  8b048d50df5100         -mov eax, dword ptr [ecx*4 + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.ecx * 4);
    // 004870bd  8d502c                 -lea edx, [eax + 0x2c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004870c0  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004870c3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004870c5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004870c7  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004870c9  e832a5ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
L_0x004870ce:
    // 004870ce  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004870d0  7414                   -je 0x4870e6
    if (cpu.flags.zf)
    {
        goto L_0x004870e6;
    }
    // 004870d2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004870d4  8b048d50df5100         -mov eax, dword ptr [ecx*4 + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.ecx * 4);
    // 004870db  8d142e                 -lea edx, [esi + ebp]
    cpu.edx = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 004870de  83c02c                 -add eax, 0x2c
    (cpu.eax) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004870e1  e81aa5ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
L_0x004870e6:
    // 004870e6  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 004870eb  e8f09affff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004870f0  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 004870f3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004870f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004870f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004870f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004870f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4870f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004870f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004870f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004870fb  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487102  750a                   -jne 0x48710e
    if (!cpu.flags.zf)
    {
        goto L_0x0048710e;
    }
    // 00487104  e86f9affff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00487109  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x0048710e:
    // 0048710e  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00487113  e8b09affff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00487118  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048711a  e821ffffff             -call 0x487040
    cpu.esp -= 4;
    sub_487040(app, cpu);
    if (cpu.terminate) return;
    // 0048711f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00487121  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487123  750e                   -jne 0x487133
    if (!cpu.flags.zf)
    {
        goto L_0x00487133;
    }
    // 00487125  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 0048712a  e8b19affff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048712f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487131  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487132  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487133:
    // 00487133  8b148d50df5100         -mov edx, dword ptr [ecx*4 + 0x51df50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.ecx * 4);
    // 0048713a  294210                 -sub dword ptr [edx + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048713d  8b148d50df5100         -mov edx, dword ptr [ecx*4 + 0x51df50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.ecx * 4);
    // 00487144  03420c                 -add eax, dword ptr [edx + 0xc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00487147  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048714c  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048714f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00487154  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487156  e8e9f1ffff             -call 0x486344
    cpu.esp -= 4;
    sub_486344(app, cpu);
    if (cpu.terminate) return;
    // 0048715b  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00487160  e87b9affff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00487165  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487167  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487168  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48716c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048716c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048716d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048716e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487170  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00487172  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487179  750a                   -jne 0x487185
    if (!cpu.flags.zf)
    {
        goto L_0x00487185;
    }
    // 0048717b  e8f899ffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00487180  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x00487185:
    // 00487185  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 0048718a  e8399affff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048718f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487191  e846f6ffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 00487196  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487198  7435                   -je 0x4871cf
    if (cpu.flags.zf)
    {
        goto L_0x004871cf;
    }
    // 0048719a  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
L_0x004871a1:
    // 004871a1  8b8350df5100           -mov eax, dword ptr [ebx + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5365584) /* 0x51df50 */);
    // 004871a7  3b5010                 +cmp edx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004871aa  7e09                   -jle 0x4871b5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004871b5;
    }
    // 004871ac  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004871ae  e88d2affff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 004871b3  ebec                   -jmp 0x4871a1
    goto L_0x004871a1;
L_0x004871b5:
    // 004871b5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004871b7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004871b9  e83affffff             -call 0x4870f8
    cpu.esp -= 4;
    sub_4870f8(app, cpu);
    if (cpu.terminate) return;
    // 004871be  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004871c0  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 004871c5  e8169affff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004871ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004871cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004871cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004871ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004871cf:
    // 004871cf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004871d1  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 004871d6  e8059affff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 004871db  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004871dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004871de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004871df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4871e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004871e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004871e1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004871e3  833d6cb34c0000         +cmp dword ptr [0x4cb36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004871ea  750a                   -jne 0x4871f6
    if (!cpu.flags.zf)
    {
        goto L_0x004871f6;
    }
    // 004871ec  e88799ffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 004871f1  a36cb34c00             -mov dword ptr [0x4cb36c], eax
    app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */) = cpu.eax;
L_0x004871f6:
    // 004871f6  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 004871fb  e8c899ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00487200  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487202  e8d5f5ffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 00487207  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487209  740c                   -je 0x487217
    if (cpu.flags.zf)
    {
        goto L_0x00487217;
    }
    // 0048720b  8b048d50df5100         -mov eax, dword ptr [ecx*4 + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365584) /* 0x51df50 */ + cpu.ecx * 4);
    // 00487212  3b5010                 +cmp edx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487215  7e10                   -jle 0x487227
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00487227;
    }
L_0x00487217:
    // 00487217  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487219  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 0048721e  e8bd99ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00487223  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487225  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487226  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487227:
    // 00487227  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487229  e8cafeffff             -call 0x4870f8
    cpu.esp -= 4;
    sub_4870f8(app, cpu);
    if (cpu.terminate) return;
    // 0048722e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487230  a16cb34c00             -mov eax, dword ptr [0x4cb36c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026668) /* 0x4cb36c */);
    // 00487235  e8a699ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048723a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048723c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048723d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_487240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487240  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487241  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487242  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00487244  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00487246  e891f5ffff             -call 0x4867dc
    cpu.esp -= 4;
    sub_4867dc(app, cpu);
    if (cpu.terminate) return;
    // 0048724b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048724d  7434                   -je 0x487283
    if (cpu.flags.zf)
    {
        goto L_0x00487283;
    }
    // 0048724f  8b1d60d25100           -mov ebx, dword ptr [0x51d260]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */);
    // 00487255  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00487257  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
L_0x0048725e:
    // 0048725e  8b8150df5100           -mov eax, dword ptr [ecx + 0x51df50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5365584) /* 0x51df50 */);
    // 00487264  3b5010                 +cmp edx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487267  7e11                   -jle 0x48727a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048727a;
    }
    // 00487269  3b1d60d25100           +cmp ebx, dword ptr [0x51d260]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5362272) /* 0x51d260 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048726f  7e09                   -jle 0x48727a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048727a;
    }
    // 00487271  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00487273  e8c829ffff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 00487278  ebe4                   -jmp 0x48725e
    goto L_0x0048725e;
L_0x0048727a:
    // 0048727a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048727c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048727e  e875feffff             -call 0x4870f8
    cpu.esp -= 4;
    sub_4870f8(app, cpu);
    if (cpu.terminate) return;
L_0x00487283:
    // 00487283  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487284  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487285  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_487290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487290  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00487292  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00487294  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00487296  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00487298  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048729a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048729c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048729e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004872a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004872a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004872a2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004872a5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004872a7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004872a8  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004872ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004872ad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004872ae  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004872b2  e86bfa0200             -call 0x4b6d22
    cpu.esp -= 4;
    sub_4b6d22(app, cpu);
    if (cpu.terminate) return;
    // 004872b7  8b1ddcd75100           -mov ebx, dword ptr [0x51d7dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5363676) /* 0x51d7dc */);
    // 004872bd  43                     -inc ebx
    (cpu.ebx)++;
    // 004872be  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004872c1  891ddcd75100           -mov dword ptr [0x51d7dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5363676) /* 0x51d7dc */) = cpu.ebx;
    // 004872c7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004872ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4872a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004872a0;
    // 00487290  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00487292  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00487294  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00487296  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00487298  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048729a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048729c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048729e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x004872a0:
    // 004872a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004872a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004872a2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004872a5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004872a7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004872a8  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004872ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004872ad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004872ae  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004872b2  e86bfa0200             -call 0x4b6d22
    cpu.esp -= 4;
    sub_4b6d22(app, cpu);
    if (cpu.terminate) return;
    // 004872b7  8b1ddcd75100           -mov ebx, dword ptr [0x51d7dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5363676) /* 0x51d7dc */);
    // 004872bd  43                     -inc ebx
    (cpu.ebx)++;
    // 004872be  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004872c1  891ddcd75100           -mov dword ptr [0x51d7dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5363676) /* 0x51d7dc */) = cpu.ebx;
    // 004872c7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004872ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4872d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004872d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004872d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004872d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004872d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004872d4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004872d7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004872d9  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004872dc  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004872df  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004872e0  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004872e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004872e6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004872e7  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004872ea  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 004872f0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004872f2  48                     -dec eax
    (cpu.eax)--;
    // 004872f3  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004872f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004872f7  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004872fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004872fc  e883180000             -call 0x488b84
    cpu.esp -= 4;
    sub_488b84(app, cpu);
    if (cpu.terminate) return;
    // 00487301  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487303  7408                   -je 0x48730d
    if (cpu.flags.zf)
    {
        goto L_0x0048730d;
    }
L_0x00487305:
    // 00487305  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00487308  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487309  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048730a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048730b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048730c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048730d:
    // 0048730d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487310  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00487313  80e4b7                 -and ah, 0xb7
    cpu.ah &= x86::reg8(x86::sreg8(183 /*0xb7*/));
    // 00487316  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487317  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048731b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048731c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048731e  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00487321  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 00487327  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487329  48                     -dec eax
    (cpu.eax)--;
    // 0048732a  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048732d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048732e  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00487331  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487333  e84c180000             -call 0x488b84
    cpu.esp -= 4;
    sub_488b84(app, cpu);
    if (cpu.terminate) return;
    // 00487338  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048733a  7531                   -jne 0x48736d
    if (!cpu.flags.zf)
    {
        goto L_0x0048736d;
    }
    // 0048733c  f644240140             +test byte ptr [esp + 1], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 64 /*0x40*/));
    // 00487341  746c                   -je 0x4873af
    if (cpu.flags.zf)
    {
        goto L_0x004873af;
    }
    // 00487343  804c240508             -or byte ptr [esp + 5], 8
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00487348:
    // 00487348  8b6e24                 -mov ebp, dword ptr [esi + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048734b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048734c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487350  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487351  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487353  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00487356  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 0048735c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048735e  48                     -dec eax
    (cpu.eax)--;
    // 0048735f  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00487362  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487363  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00487366  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487368  e817180000             -call 0x488b84
    cpu.esp -= 4;
    sub_488b84(app, cpu);
    if (cpu.terminate) return;
L_0x0048736d:
    // 0048736d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048736f  7594                   -jne 0x487305
    if (!cpu.flags.zf)
    {
        goto L_0x00487305;
    }
    // 00487371  80be6304000001         +cmp byte ptr [esi + 0x463], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487378  768b                   -jbe 0x487305
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00487305;
    }
    // 0048737a  8a7c2405               -mov bh, byte ptr [esp + 5]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */);
    // 0048737e  80e7b7                 -and bh, 0xb7
    cpu.bh &= x86::reg8(x86::sreg8(183 /*0xb7*/));
    // 00487381  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00487384  887c2405               -mov byte ptr [esp + 5], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.bh;
    // 00487388  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487389  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048738d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048738e  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00487391  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487392  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00487395  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00487398  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487399  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048739b  c6866304000001         -mov byte ptr [esi + 0x463], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */) = 1 /*0x1*/;
    // 004873a2  e8dd170000             -call 0x488b84
    cpu.esp -= 4;
    sub_488b84(app, cpu);
    if (cpu.terminate) return;
    // 004873a7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004873aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004873ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004873ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004873ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004873ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004873af:
    // 004873af  804c240540             +or byte ptr [esp + 5], 0x40
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 004873b4  eb92                   -jmp 0x487348
    goto L_0x00487348;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4873b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004873b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004873b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004873ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004873bb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004873bd  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004873bf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004873c1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004873c3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004873c4  c7036c000000           -mov dword ptr [ebx], 0x6c
    app->getMemory<x86::reg32>(cpu.ebx) = 108 /*0x6c*/;
    // 004873ca  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004873cc  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004873ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004873cf  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004873d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004873d4  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004873da  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004873dc  7408                   -je 0x4873e6
    if (cpu.flags.zf)
    {
        goto L_0x004873e6;
    }
    // 004873de  81fac2010000           +cmp edx, 0x1c2
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(450 /*0x1c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004873e4  7406                   -je 0x4873ec
    if (cpu.flags.zf)
    {
        goto L_0x004873ec;
    }
L_0x004873e6:
    // 004873e6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004873e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004873e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004873ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004873eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004873ec:
    // 004873ec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004873ed  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004873ef  ff506c                 -call dword ptr [eax + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004873f2  8b9644040000           -mov edx, dword ptr [esi + 0x444]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 004873f8  39d7                   +cmp edi, edx
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
    // 004873fa  7418                   -je 0x487414
    if (cpu.flags.zf)
    {
        goto L_0x00487414;
    }
    // 004873fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004873fe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004873ff  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00487401  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487404  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487406  740c                   -je 0x487414
    if (cpu.flags.zf)
    {
        goto L_0x00487414;
    }
    // 00487408  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 0048740e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048740f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00487411  ff526c                 -call dword ptr [edx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00487414:
    // 00487414  8b8e48040000           -mov ecx, dword ptr [esi + 0x448]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 0048741a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048741c  741a                   -je 0x487438
    if (cpu.flags.zf)
    {
        goto L_0x00487438;
    }
    // 0048741e  39cf                   +cmp edi, ecx
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
    // 00487420  7416                   -je 0x487438
    if (cpu.flags.zf)
    {
        goto L_0x00487438;
    }
    // 00487422  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487423  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00487425  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487428  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048742a  740c                   -je 0x487438
    if (cpu.flags.zf)
    {
        goto L_0x00487438;
    }
    // 0048742c  8b8648040000           -mov eax, dword ptr [esi + 0x448]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 00487432  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487433  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00487435  ff526c                 -call dword ptr [edx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00487438:
    // 00487438  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487439  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048743b  ff5060                 -call dword ptr [eax + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048743e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487440  0f85b2000000           -jne 0x4874f8
    if (!cpu.flags.zf)
    {
        goto L_0x004874f8;
    }
    // 00487446  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487448  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048744a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048744b  c7036c000000           -mov dword ptr [ebx], 0x6c
    app->getMemory<x86::reg32>(cpu.ebx) = 108 /*0x6c*/;
    // 00487451  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487453  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00487455  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487456  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487459  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048745b  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00487461  7434                   -je 0x487497
    if (cpu.flags.zf)
    {
        goto L_0x00487497;
    }
    // 00487463  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00487468  e87397ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048746d  e8be6dffff             -call 0x47e230
    cpu.esp -= 4;
    sub_47e230(app, cpu);
    if (cpu.terminate) return;
    // 00487472  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00487477  e84c97ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048747c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048747e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00487480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487481  c7036c000000           -mov dword ptr [ebx], 0x6c
    app->getMemory<x86::reg32>(cpu.ebx) = 108 /*0x6c*/;
    // 00487487  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487489  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048748b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048748c  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048748f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487491  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
L_0x00487497:
    // 00487497  0f8549ffffff           -jne 0x4873e6
    if (!cpu.flags.zf)
    {
        goto L_0x004873e6;
    }
    // 0048749d  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 004874a1  7519                   -jne 0x4874bc
    if (!cpu.flags.zf)
    {
        goto L_0x004874bc;
    }
L_0x004874a3:
    // 004874a3  833d70a64c0000         +cmp dword ptr [0x4ca670], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023344) /* 0x4ca670 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004874aa  0f8436ffffff           -je 0x4873e6
    if (cpu.flags.zf)
    {
        goto L_0x004873e6;
    }
    // 004874b0  ff1570a64c00           -call dword ptr [0x4ca670]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023344) /* 0x4ca670 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004874b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004874b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004874bc:
    // 004874bc  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004874bf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004874c0  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004874c5  66c78632040000ffff     -mov word ptr [esi + 0x432], 0xffff
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1074) /* 0x432 */) = 65535 /*0xffff*/;
    // 004874ce  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004874d0  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004874d3  66c786300400000001     -mov word ptr [esi + 0x430], 0x100
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1072) /* 0x430 */) = 256 /*0x100*/;
    // 004874dc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004874de  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004874e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004874e1  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004874e4  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004874e7  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 004874ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004874ee  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004874f0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004874f1  ff527c                 -call dword ptr [edx + 0x7c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004874f4  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004874f6  ebab                   -jmp 0x4874a3
    goto L_0x004874a3;
L_0x004874f8:
    // 004874f8  bac2010000             -mov edx, 0x1c2
    cpu.edx = 450 /*0x1c2*/;
    // 004874fd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004874ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487500  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487501  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487502  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_487504(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487504  3b05b4d75100           +cmp eax, dword ptr [0x51d7b4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5363636) /* 0x51d7b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048750a  7401                   -je 0x48750d
    if (cpu.flags.zf)
    {
        goto L_0x0048750d;
    }
    // 0048750c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048750d:
    // 0048750d  a1d4d75100             -mov eax, dword ptr [0x51d7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363668) /* 0x51d7d4 */);
    // 00487512  0102                   -add dword ptr [edx], eax
    (app->getMemory<x86::reg32>(cpu.edx)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487514  a1d8d75100             -mov eax, dword ptr [0x51d7d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363672) /* 0x51d7d8 */);
    // 00487519  0103                   -add dword ptr [ebx], eax
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048751b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48751c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048751c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048751d  3b05b4d75100           +cmp eax, dword ptr [0x51d7b4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5363636) /* 0x51d7b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487523  7402                   -je 0x487527
    if (cpu.flags.zf)
    {
        goto L_0x00487527;
    }
    // 00487525  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487526  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487527:
    // 00487527  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487528  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487529  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048752a  a1d4d75100             -mov eax, dword ptr [0x51d7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363668) /* 0x51d7d4 */);
    // 0048752f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00487531  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00487534  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00487537  8b6a0c                 -mov ebp, dword ptr [edx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048753a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048753c  a1d8d75100             -mov eax, dword ptr [0x51d7d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363672) /* 0x51d7d8 */);
    // 00487541  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00487543  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487545  a1d4d75100             -mov eax, dword ptr [0x51d7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363668) /* 0x51d7d4 */);
    // 0048754a  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0048754d  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048754f  a1d8d75100             -mov eax, dword ptr [0x51d7d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363672) /* 0x51d7d8 */);
    // 00487554  897a08                 -mov dword ptr [edx + 8], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00487557  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487559  896a0c                 -mov dword ptr [edx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0048755c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048755d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048755e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048755f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487560  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487564(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487564  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487565  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487566  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487568  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048756a  7410                   -je 0x48757c
    if (cpu.flags.zf)
    {
        goto L_0x0048757c;
    }
L_0x0048756c:
    // 0048756c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048756e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00487570  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00487572  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00487574  42                     -inc edx
    (cpu.edx)++;
    // 00487575  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487577  75f3                   -jne 0x48756c
    if (!cpu.flags.zf)
    {
        goto L_0x0048756c;
    }
    // 00487579  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0048757c:
    // 0048757c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048757e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048757f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487580  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487584(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487584  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487585  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487586  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487587  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048758a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048758c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048758e  f6430510               +test byte ptr [ebx + 5], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) & 16 /*0x10*/));
    // 00487592  0f844a010000           -je 0x4876e2
    if (cpu.flags.zf)
    {
        goto L_0x004876e2;
    }
    // 00487598  837b5410               +cmp dword ptr [ebx + 0x54], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048759c  0f8440010000           -je 0x4876e2
    if (cpu.flags.zf)
    {
        goto L_0x004876e2;
    }
    // 004875a2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004875a4  8a4354                 -mov al, byte ptr [ebx + 0x54]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004875a7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004875ab:
    // 004875ab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004875ad  0f8cdd000000           -jl 0x487690
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487690;
    }
    // 004875b3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004875ba  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004875bc  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004875bf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004875c2  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004875c5  890c28                 -mov dword ptr [eax + ebp], ecx
    app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1) = cpu.ecx;
    // 004875c8  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004875cb  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004875cd  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004875d0  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004875d3  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004875d6  894d04                 -mov dword ptr [ebp + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004875d9  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004875dc  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004875de  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004875e1  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004875e4  8a4b54                 -mov cl, byte ptr [ebx + 0x54]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004875e7  884d12                 -mov byte ptr [ebp + 0x12], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.cl;
    // 004875ea  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004875ed  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004875f1  884c2813               -mov byte ptr [eax + ebp + 0x13], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */ + cpu.ebp * 1) = cpu.cl;
    // 004875f5  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004875f8  66c74401100100         -mov word ptr [ecx + eax + 0x10], 1
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.eax * 1) = 1 /*0x1*/;
    // 004875ff  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00487602  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487604  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00487607  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0048760a  8b0db4b34c00           -mov ecx, dword ptr [0x4cb3b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5026740) /* 0x4cb3b4 */);
    // 00487610  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00487613  f6430604               +test byte ptr [ebx + 6], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) & 4 /*0x4*/));
    // 00487617  740b                   -je 0x487624
    if (cpu.flags.zf)
    {
        goto L_0x00487624;
    }
    // 00487619  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048761c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048761e  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00487621  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00487624:
    // 00487624  f6430420               +test byte ptr [ebx + 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 32 /*0x20*/));
    // 00487628  741b                   -je 0x487645
    if (cpu.flags.zf)
    {
        goto L_0x00487645;
    }
    // 0048762a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00487631  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00487634  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00487637  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048763a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048763c  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 0048763e  8a4b14                 -mov cl, byte ptr [ebx + 0x14]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00487641  66014810               -add word ptr [eax + 0x10], cx
    (app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg16(x86::sreg16(cpu.cx));
L_0x00487645:
    // 00487645  f6430480               +test byte ptr [ebx + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 128 /*0x80*/));
    // 00487649  7411                   -je 0x48765c
    if (cpu.flags.zf)
    {
        goto L_0x0048765c;
    }
    // 0048764b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00487652  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00487655  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00487657  804c810c01             -or byte ptr [ecx + eax*4 + 0xc], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0048765c:
    // 0048765c  f6430440               +test byte ptr [ebx + 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 64 /*0x40*/));
    // 00487660  7411                   -je 0x487673
    if (cpu.flags.zf)
    {
        goto L_0x00487673;
    }
    // 00487662  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00487669  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048766c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048766e  804c810c02             -or byte ptr [ecx + eax*4 + 0xc], 2
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00487673:
    // 00487673  f6430401               +test byte ptr [ebx + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 00487677  7417                   -je 0x487690
    if (cpu.flags.zf)
    {
        goto L_0x00487690;
    }
    // 00487679  f6436a20               +test byte ptr [ebx + 0x6a], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(106) /* 0x6a */) & 32 /*0x20*/));
    // 0048767d  7411                   -je 0x487690
    if (cpu.flags.zf)
    {
        goto L_0x00487690;
    }
    // 0048767f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00487686  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00487689  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048768b  804c810c04             -or byte ptr [ecx + eax*4 + 0xc], 4
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00487690:
    // 00487690  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00487692  7447                   -je 0x4876db
    if (cpu.flags.zf)
    {
        goto L_0x004876db;
    }
    // 00487694  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00487696  7c1e                   -jl 0x4876b6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004876b6;
    }
    // 00487698  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048769f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004876a1  8a9660040000           -mov dl, byte ptr [esi + 0x460]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1120) /* 0x460 */);
    // 004876a7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004876aa  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004876ac  755b                   -jne 0x487709
    if (!cpu.flags.zf)
    {
        goto L_0x00487709;
    }
    // 004876ae  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004876b1  8064020cef             -and byte ptr [edx + eax + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x004876b6:
    // 004876b6  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004876bd  740c                   -je 0x4876cb
    if (cpu.flags.zf)
    {
        goto L_0x004876cb;
    }
    // 004876bf  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004876c2  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004876c5  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004876c8  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004876cb:
    // 004876cb  8b4354                 -mov eax, dword ptr [ebx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004876ce  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004876d1  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004876d5  88865c040000           -mov byte ptr [esi + 0x45c], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */) = cpu.al;
L_0x004876db:
    // 004876db  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004876de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004876df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004876e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004876e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004876e2:
    // 004876e2  8b4358                 -mov eax, dword ptr [ebx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 004876e5  e87afeffff             -call 0x487564
    cpu.esp -= 4;
    sub_487564(app, cpu);
    if (cpu.terminate) return;
    // 004876ea  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004876ec  8b435c                 -mov eax, dword ptr [ebx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(92) /* 0x5c */);
    // 004876ef  e870feffff             -call 0x487564
    cpu.esp -= 4;
    sub_487564(app, cpu);
    if (cpu.terminate) return;
    // 004876f4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004876f6  8b4360                 -mov eax, dword ptr [ebx + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
    // 004876f9  e866feffff             -call 0x487564
    cpu.esp -= 4;
    sub_487564(app, cpu);
    if (cpu.terminate) return;
    // 004876fe  01c1                   +add ecx, eax
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
    // 00487700  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00487704  e9a2feffff             -jmp 0x4875ab
    goto L_0x004875ab;
L_0x00487709:
    // 00487709  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048770c  804c020c10             +or byte ptr [edx + eax + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00487711  eba3                   -jmp 0x4876b6
    goto L_0x004876b6;
}

/* align: skip 0x90 */
void Application::sub_487714(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487714  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487715  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487716  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487717  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048771a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048771c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048771e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00487720  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487721  8b15c4d75100           -mov edx, dword ptr [0x51d7c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 00487727  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487728  2eff15e4734b00         -call dword ptr cs:[0x4b73e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944868) /* 0x4b73e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048772f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487733  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00487736  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00487738  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0048773a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048773e  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487742  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00487744  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00487746  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00487749  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048774a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048774b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048774c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487750  a1c4d75100             -mov eax, dword ptr [0x51d7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 00487755  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_487758(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487758  a1dcd75100             -mov eax, dword ptr [0x51d7dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5363676) /* 0x51d7dc */);
    // 0048775d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_487760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487760  a170d35100             -mov eax, dword ptr [0x51d370]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362544) /* 0x51d370 */);
    // 00487765  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_487768(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487768  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487769  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048776a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048776c  7414                   -je 0x487782
    if (cpu.flags.zf)
    {
        goto L_0x00487782;
    }
    // 0048776e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487770  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487771  8b15c4d75100           -mov edx, dword ptr [0x51d7c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 00487777  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487778  2eff1534744b00         -call dword ptr cs:[0x4b7434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944948) /* 0x4b7434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048777f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487780  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487781  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487782:
    // 00487782  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00487787  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487788  8b15c4d75100           -mov edx, dword ptr [0x51d7c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5363652) /* 0x51d7c4 */);
    // 0048778e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048778f  2eff1534744b00         -call dword ptr cs:[0x4b7434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944948) /* 0x4b7434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487796  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487797  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487798  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48779c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048779c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048779d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048779e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048779f  6890914800             -push 0x489190
    app->getMemory<x86::reg32>(cpu.esp-4) = 4755856 /*0x489190*/;
    cpu.esp -= 4;
    // 004877a4  e873f50200             -call 0x4b6d1c
    cpu.esp -= 4;
    sub_4b6d1c(app, cpu);
    if (cpu.terminate) return;
    // 004877a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004877aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004877ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4877ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004877ac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004877ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004877ae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004877af  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004877b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004877b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004877b2  81ecd8020000           -sub esp, 0x2d8
    (cpu.esp) -= x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 004877b8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004877ba  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004877bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004877be  7505                   -jne 0x4877c5
    if (!cpu.flags.zf)
    {
        goto L_0x004877c5;
    }
    // 004877c0  bb70d35100             -mov ebx, 0x51d370
    cpu.ebx = 5362544 /*0x51d370*/;
L_0x004877c5:
    // 004877c5  833d38af4c0000         +cmp dword ptr [0x4caf38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004877cc  750a                   -jne 0x4877d8
    if (!cpu.flags.zf)
    {
        goto L_0x004877d8;
    }
    // 004877ce  e8a593ffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 004877d3  a338af4c00             -mov dword ptr [0x4caf38], eax
    app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */) = cpu.eax;
L_0x004877d8:
    // 004877d8  bab0df5100             -mov edx, 0x51dfb0
    cpu.edx = 5365680 /*0x51dfb0*/;
    // 004877dd  a1b0df5100             -mov eax, dword ptr [0x51dfb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365680) /* 0x51dfb0 */);
    // 004877e2  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004877e5  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004877e8  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004877ea  8b6a0c                 -mov ebp, dword ptr [edx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004877ed  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 004877ef  8a15dca34c00           -mov dl, byte ptr [0x4ca3dc]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5022684) /* 0x4ca3dc */);
    // 004877f5  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004877f7  f6c280                 +test dl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 128 /*0x80*/));
    // 004877fa  7521                   -jne 0x48781d
    if (!cpu.flags.zf)
    {
        goto L_0x0048781d;
    }
    // 004877fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004877fe  740e                   -je 0x48780e
    if (cpu.flags.zf)
    {
        goto L_0x0048780e;
    }
    // 00487800  bab0df5100             -mov edx, 0x51dfb0
    cpu.edx = 5365680 /*0x51dfb0*/;
    // 00487805  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487807  e894faffff             -call 0x4872a0
    cpu.esp -= 4;
    sub_4872a0(app, cpu);
    if (cpu.terminate) return;
    // 0048780c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0048780e:
    // 0048780e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00487810  750b                   -jne 0x48781d
    if (!cpu.flags.zf)
    {
        goto L_0x0048781d;
    }
    // 00487812  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487814  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487816  e885faffff             -call 0x4872a0
    cpu.esp -= 4;
    sub_4872a0(app, cpu);
    if (cpu.terminate) return;
    // 0048781b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0048781d:
    // 0048781d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048781f  0f8420010000           -je 0x487945
    if (cpu.flags.zf)
    {
        goto L_0x00487945;
    }
L_0x00487825:
    // 00487825  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487826  6890184d00             -push 0x4d1890
    app->getMemory<x86::reg32>(cpu.esp-4) = 5052560 /*0x4d1890*/;
    cpu.esp -= 4;
    // 0048782b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048782d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048782e  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487830  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487832  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487833  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00487835  81e7ffff0000           -and edi, 0xffff
    cpu.edi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048783b  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048783e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00487840  0f853e010000           -jne 0x487984
    if (!cpu.flags.zf)
    {
        goto L_0x00487984;
    }
    // 00487846  b86c010000             -mov eax, 0x16c
    cpu.eax = 364 /*0x16c*/;
    // 0048784b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048784d  8984246c010000         -mov dword ptr [esp + 0x16c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.eax;
    // 00487854  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00487857  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487858  8d942470010000         -lea edx, [esp + 0x170]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 0048785f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00487861  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487862  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00487864  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487865  ff562c                 -call dword ptr [esi + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487868  8ab42473010000         -mov dh, byte ptr [esp + 0x173]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */);
    // 0048786f  893db4b34c00           -mov dword ptr [0x4cb3b4], edi
    app->getMemory<x86::reg32>(x86::reg32(5026740) /* 0x4cb3b4 */) = cpu.edi;
    // 00487875  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 00487878  740a                   -je 0x487884
    if (cpu.flags.zf)
    {
        goto L_0x00487884;
    }
    // 0048787a  c705b4b34c0008000000   -mov dword ptr [0x4cb3b4], 8
    app->getMemory<x86::reg32>(x86::reg32(5026740) /* 0x4cb3b4 */) = 8 /*0x8*/;
L_0x00487884:
    // 00487884  f684247201000008       +test byte ptr [esp + 0x172], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(370) /* 0x172 */) & 8 /*0x8*/));
    // 0048788c  7407                   -je 0x487895
    if (cpu.flags.zf)
    {
        goto L_0x00487895;
    }
    // 0048788e  800db5b34c0008         -or byte ptr [0x4cb3b5], 8
    app->getMemory<x86::reg8>(x86::reg32(5026741) /* 0x4cb3b5 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00487895:
    // 00487895  f684247001000001       +test byte ptr [esp + 0x170], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */) & 1 /*0x1*/));
    // 0048789d  7407                   -je 0x4878a6
    if (cpu.flags.zf)
    {
        goto L_0x004878a6;
    }
    // 0048789f  800db4b34c0020         -or byte ptr [0x4cb3b4], 0x20
    app->getMemory<x86::reg8>(x86::reg32(5026740) /* 0x4cb3b4 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x004878a6:
    // 004878a6  8a942470010000         -mov dl, byte ptr [esp + 0x170]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 004878ad  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004878b0  0f85c0000000           -jne 0x487976
    if (!cpu.flags.zf)
    {
        goto L_0x00487976;
    }
L_0x004878b6:
    // 004878b6  f684247001000040       +test byte ptr [esp + 0x170], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */) & 64 /*0x40*/));
    // 004878be  7407                   -je 0x4878c7
    if (cpu.flags.zf)
    {
        goto L_0x004878c7;
    }
    // 004878c0  800db4b34c0040         -or byte ptr [0x4cb3b4], 0x40
    app->getMemory<x86::reg8>(x86::reg32(5026740) /* 0x4cb3b4 */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x004878c7:
    // 004878c7  f684247301000004       +test byte ptr [esp + 0x173], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 4 /*0x4*/));
    // 004878cf  7407                   -je 0x4878d8
    if (cpu.flags.zf)
    {
        goto L_0x004878d8;
    }
    // 004878d1  800db4b34c0080         -or byte ptr [0x4cb3b4], 0x80
    app->getMemory<x86::reg8>(x86::reg32(5026740) /* 0x4cb3b4 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004878d8:
    // 004878d8  f684247101000002       +test byte ptr [esp + 0x171], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(369) /* 0x171 */) & 2 /*0x2*/));
    // 004878e0  7407                   -je 0x4878e9
    if (cpu.flags.zf)
    {
        goto L_0x004878e9;
    }
    // 004878e2  800db5b34c0001         -or byte ptr [0x4cb3b5], 1
    app->getMemory<x86::reg8>(x86::reg32(5026741) /* 0x4cb3b5 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004878e9:
    // 004878e9  f684247301000080       +test byte ptr [esp + 0x173], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 128 /*0x80*/));
    // 004878f1  7407                   -je 0x4878fa
    if (cpu.flags.zf)
    {
        goto L_0x004878fa;
    }
    // 004878f3  800db5b34c0004         -or byte ptr [0x4cb3b5], 4
    app->getMemory<x86::reg8>(x86::reg32(5026741) /* 0x4cb3b5 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004878fa:
    // 004878fa  f684247301000001       +test byte ptr [esp + 0x173], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 1 /*0x1*/));
    // 00487902  7411                   -je 0x487915
    if (cpu.flags.zf)
    {
        goto L_0x00487915;
    }
    // 00487904  f684247901000002       +test byte ptr [esp + 0x179], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(377) /* 0x179 */) & 2 /*0x2*/));
    // 0048790c  7407                   -je 0x487915
    if (cpu.flags.zf)
    {
        goto L_0x00487915;
    }
    // 0048790e  800db5b34c0002         -or byte ptr [0x4cb3b5], 2
    app->getMemory<x86::reg8>(x86::reg32(5026741) /* 0x4cb3b5 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00487915:
    // 00487915  f68424f001000010       +test byte ptr [esp + 0x1f0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(496) /* 0x1f0 */) & 16 /*0x10*/));
    // 0048791d  7407                   -je 0x487926
    if (cpu.flags.zf)
    {
        goto L_0x00487926;
    }
    // 0048791f  800db4b34c0010         -or byte ptr [0x4cb3b4], 0x10
    app->getMemory<x86::reg8>(x86::reg32(5026740) /* 0x4cb3b4 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00487926:
    // 00487926  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00487928  893dbcaa4c00           -mov dword ptr [0x4caabc], edi
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.edi;
L_0x0048792e:
    // 0048792e  833b00                 +cmp dword ptr [ebx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487931  7463                   -je 0x487996
    if (cpu.flags.zf)
    {
        goto L_0x00487996;
    }
    // 00487933  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00487938:
    // 00487938  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 0048793e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048793f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487940  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487941  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487942  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487943  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487944  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487945:
    // 00487945  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0048794a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048794c  e84ff9ffff             -call 0x4872a0
    cpu.esp -= 4;
    sub_4872a0(app, cpu);
    if (cpu.terminate) return;
    // 00487951  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00487953  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487955  0f85cafeffff           -jne 0x487825
    if (!cpu.flags.zf)
    {
        goto L_0x00487825;
    }
    // 0048795b  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048795d  b8a0074c00             -mov eax, 0x4c07a0
    cpu.eax = 4982688 /*0x4c07a0*/;
    // 00487962  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487964  7509                   -jne 0x48796f
    if (!cpu.flags.zf)
    {
        goto L_0x0048796f;
    }
L_0x00487966:
    // 00487966  a3bcaa4c00             -mov dword ptr [0x4caabc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.eax;
    // 0048796b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048796d  ebc9                   -jmp 0x487938
    goto L_0x00487938;
L_0x0048796f:
    // 0048796f  b8b8074c00             -mov eax, 0x4c07b8
    cpu.eax = 4982712 /*0x4c07b8*/;
    // 00487974  ebf0                   -jmp 0x487966
    goto L_0x00487966;
L_0x00487976:
    // 00487976  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00487979  0f8437ffffff           -je 0x4878b6
    if (cpu.flags.zf)
    {
        goto L_0x004878b6;
    }
    // 0048797f  e976ffffff             -jmp 0x4878fa
    goto L_0x004878fa;
L_0x00487984:
    // 00487984  b8bc074c00             -mov eax, 0x4c07bc
    cpu.eax = 4982716 /*0x4c07bc*/;
    // 00487989  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048798b  7518                   -jne 0x4879a5
    if (!cpu.flags.zf)
    {
        goto L_0x004879a5;
    }
L_0x0048798d:
    // 0048798d  a3bcaa4c00             -mov dword ptr [0x4caabc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.eax;
    // 00487992  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00487994  7498                   -je 0x48792e
    if (cpu.flags.zf)
    {
        goto L_0x0048792e;
    }
L_0x00487996:
    // 00487996  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487998  81c4d8020000           +add esp, 0x2d8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(728 /*0x2d8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048799e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048799f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004879a5:
    // 004879a5  b8b8074c00             -mov eax, 0x4c07b8
    cpu.eax = 4982712 /*0x4c07b8*/;
    // 004879aa  ebe1                   -jmp 0x48798d
    goto L_0x0048798d;
}

/* align: skip  */
void Application::sub_4879ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004879ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004879ad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004879ae  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004879af  81ecd8020000           -sub esp, 0x2d8
    (cpu.esp) -= x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 004879b5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004879b7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004879b9  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004879bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004879bd  7505                   -jne 0x4879c4
    if (!cpu.flags.zf)
    {
        goto L_0x004879c4;
    }
    // 004879bf  be70d35100             -mov esi, 0x51d370
    cpu.esi = 5362544 /*0x51d370*/;
L_0x004879c4:
    // 004879c4  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004879c7  750e                   -jne 0x4879d7
    if (!cpu.flags.zf)
    {
        goto L_0x004879d7;
    }
L_0x004879c9:
    // 004879c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004879cb  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 004879d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879d4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004879d7:
    // 004879d7  b96c010000             -mov ecx, 0x16c
    cpu.ecx = 364 /*0x16c*/;
    // 004879dc  898c246c010000         -mov dword ptr [esp + 0x16c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.ecx;
    // 004879e3  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004879e6  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004879e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004879e9  8d8c2470010000         -lea ecx, [esp + 0x170]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 004879f0  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004879f2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004879f3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004879f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004879f6  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004879f9  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 004879fd  75ca                   -jne 0x4879c9
    if (!cpu.flags.zf)
    {
        goto L_0x004879c9;
    }
    // 004879ff  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00487a01  740a                   -je 0x487a0d
    if (cpu.flags.zf)
    {
        goto L_0x00487a0d;
    }
    // 00487a03  8b8424a8010000         -mov eax, dword ptr [esp + 0x1a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(424) /* 0x1a8 */);
    // 00487a0a  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x00487a0d:
    // 00487a0d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00487a0f  7409                   -je 0x487a1a
    if (cpu.flags.zf)
    {
        goto L_0x00487a1a;
    }
    // 00487a11  8b8424ac010000         -mov eax, dword ptr [esp + 0x1ac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(428) /* 0x1ac */);
    // 00487a18  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00487a1a:
    // 00487a1a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00487a1c  7411                   -je 0x487a2f
    if (cpu.flags.zf)
    {
        goto L_0x00487a2f;
    }
    // 00487a1e  f684247301000008       +test byte ptr [esp + 0x173], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 8 /*0x8*/));
    // 00487a26  745c                   -je 0x487a84
    if (cpu.flags.zf)
    {
        goto L_0x00487a84;
    }
    // 00487a28  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00487a2d:
    // 00487a2d  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x00487a2f:
    // 00487a2f  83bc24e802000000       +cmp dword ptr [esp + 0x2e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487a37  742d                   -je 0x487a66
    if (cpu.flags.zf)
    {
        goto L_0x00487a66;
    }
    // 00487a39  68c8914800             -push 0x4891c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4755912 /*0x4891c8*/;
    cpu.esp -= 4;
    // 00487a3e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00487a40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487a41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487a42  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00487a44  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00487a46  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00487a48  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487a49  890dc8df5100           -mov dword ptr [0x51dfc8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5365704) /* 0x51dfc8 */) = cpu.ecx;
    // 00487a4f  890dc0df5100           -mov dword ptr [0x51dfc0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5365696) /* 0x51dfc0 */) = cpu.ecx;
    // 00487a55  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487a58  8b9424e8020000         -mov edx, dword ptr [esp + 0x2e8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */);
    // 00487a5f  a1c0df5100             -mov eax, dword ptr [0x51dfc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365696) /* 0x51dfc0 */);
    // 00487a64  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00487a66:
    // 00487a66  833dc8df510000         +cmp dword ptr [0x51dfc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5365704) /* 0x51dfc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487a6d  0f8e56ffffff           -jle 0x4879c9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004879c9;
    }
    // 00487a73  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00487a78  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 00487a7e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a81  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00487a84:
    // 00487a84  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00487a86  eba5                   -jmp 0x487a2d
    goto L_0x00487a2d;
}

/* align: skip  */
void Application::sub_487a88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487a88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487a89  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487a8a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487a8b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487a8c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487a8d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487a8e  8b3dbcaa4c00           -mov edi, dword ptr [0x4caabc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */);
    // 00487a94  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00487a96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487a98  7505                   -jne 0x487a9f
    if (!cpu.flags.zf)
    {
        goto L_0x00487a9f;
    }
    // 00487a9a  be70d35100             -mov esi, 0x51d370
    cpu.esi = 5362544 /*0x51d370*/;
L_0x00487a9f:
    // 00487a9f  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487aa2  7521                   -jne 0x487ac5
    if (!cpu.flags.zf)
    {
        goto L_0x00487ac5;
    }
    // 00487aa4  b8e0074c00             -mov eax, 0x4c07e0
    cpu.eax = 4982752 /*0x4c07e0*/;
    // 00487aa9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487aab  7511                   -jne 0x487abe
    if (!cpu.flags.zf)
    {
        goto L_0x00487abe;
    }
L_0x00487aad:
    // 00487aad  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487aaf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00487ab1  893dbcaa4c00           -mov dword ptr [0x4caabc], edi
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.edi;
    // 00487ab7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ab8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ab9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487aba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487abb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487abc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487abd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487abe:
    // 00487abe  b8b8074c00             -mov eax, 0x4c07b8
    cpu.eax = 4982712 /*0x4c07b8*/;
    // 00487ac3  ebe8                   -jmp 0x487aad
    goto L_0x00487aad;
L_0x00487ac5:
    // 00487ac5  83be5404000000         +cmp dword ptr [esi + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487acc  751f                   -jne 0x487aed
    if (!cpu.flags.zf)
    {
        goto L_0x00487aed;
    }
    // 00487ace  b800084c00             -mov eax, 0x4c0800
    cpu.eax = 4982784 /*0x4c0800*/;
    // 00487ad3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487ad5  74d6                   -je 0x487aad
    if (cpu.flags.zf)
    {
        goto L_0x00487aad;
    }
    // 00487ad7  b8b8074c00             -mov eax, 0x4c07b8
    cpu.eax = 4982712 /*0x4c07b8*/;
    // 00487adc  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487ade  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487ae0  893dbcaa4c00           -mov dword ptr [0x4caabc], edi
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.edi;
    // 00487ae6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ae7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ae8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ae9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487aea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487aeb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487aec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487aed:
    // 00487aed  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487af4  744f                   -je 0x487b45
    if (cpu.flags.zf)
    {
        goto L_0x00487b45;
    }
    // 00487af6  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00487afb  8b1db8b34c00           -mov ebx, dword ptr [0x4cb3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026744) /* 0x4cb3b8 */);
    // 00487b01  893dbcaa4c00           -mov dword ptr [0x4caabc], edi
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.edi;
    // 00487b07  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00487b09  7405                   -je 0x487b10
    if (cpu.flags.zf)
    {
        goto L_0x00487b10;
    }
    // 00487b0b  b851000000             -mov eax, 0x51
    cpu.eax = 81 /*0x51*/;
L_0x00487b10:
    // 00487b10  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487b11  8bae54040000           -mov ebp, dword ptr [esi + 0x454]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
    // 00487b17  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00487b19  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487b1a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00487b1c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487b1d  ff5150                 -call dword ptr [ecx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487b20  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00487b25  742b                   -je 0x487b52
    if (cpu.flags.zf)
    {
        goto L_0x00487b52;
    }
    // 00487b27  b874084c00             -mov eax, 0x4c0874
    cpu.eax = 4982900 /*0x4c0874*/;
    // 00487b2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487b2e  0f85ba000000           -jne 0x487bee
    if (!cpu.flags.zf)
    {
        goto L_0x00487bee;
    }
    // 00487b34  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487b36  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00487b38  893dbcaa4c00           -mov dword ptr [0x4caabc], edi
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.edi;
    // 00487b3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487b45:
    // 00487b45  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 00487b4a  893dbcaa4c00           -mov dword ptr [0x4caabc], edi
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.edi;
    // 00487b50  ebbe                   -jmp 0x487b10
    goto L_0x00487b10;
L_0x00487b52:
    // 00487b52  68c8914800             -push 0x4891c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4755912 /*0x4891c8*/;
    cpu.esp -= 4;
    // 00487b57  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487b58  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487b5a  a3c8df5100             -mov dword ptr [0x51dfc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5365704) /* 0x51dfc8 */) = cpu.eax;
    // 00487b5f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00487b61  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00487b63  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00487b65  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487b66  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487b69  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00487b6e  7423                   -je 0x487b93
    if (cpu.flags.zf)
    {
        goto L_0x00487b93;
    }
    // 00487b70  b81c084c00             -mov eax, 0x4c081c
    cpu.eax = 4982812 /*0x4c081c*/;
    // 00487b75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487b77  0f8430ffffff           -je 0x487aad
    if (cpu.flags.zf)
    {
        goto L_0x00487aad;
    }
    // 00487b7d  b8b8074c00             -mov eax, 0x4c07b8
    cpu.eax = 4982712 /*0x4c07b8*/;
    // 00487b82  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487b84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487b86  893dbcaa4c00           -mov dword ptr [0x4caabc], edi
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.edi;
    // 00487b8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487b93:
    // 00487b93  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00487b96  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00487b98  740e                   -je 0x487ba8
    if (cpu.flags.zf)
    {
        goto L_0x00487ba8;
    }
    // 00487b9a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487b9c  e8eb2affff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00487ba1  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x00487ba8:
    // 00487ba8  a1c8df5100             -mov eax, dword ptr [0x51dfc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365704) /* 0x51dfc8 */);
    // 00487bad  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00487bb0  83f810                 +cmp eax, 0x10
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
    // 00487bb3  7d07                   -jge 0x487bbc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487bbc;
    }
    // 00487bb5  c7460810000000         -mov dword ptr [esi + 8], 0x10
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 16 /*0x10*/;
L_0x00487bbc:
    // 00487bbc  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00487bbf  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00487bc6  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 00487bcb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00487bcd  b840084c00             -mov eax, 0x4c0840
    cpu.eax = 4982848 /*0x4c0840*/;
    // 00487bd2  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00487bd5  e84e26ffff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00487bda  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00487bdd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487bdf  7523                   -jne 0x487c04
    if (!cpu.flags.zf)
    {
        goto L_0x00487c04;
    }
    // 00487be1  b84c084c00             -mov eax, 0x4c084c
    cpu.eax = 4982860 /*0x4c084c*/;
    // 00487be6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487be8  0f84bffeffff           -je 0x487aad
    if (cpu.flags.zf)
    {
        goto L_0x00487aad;
    }
L_0x00487bee:
    // 00487bee  b8b8074c00             -mov eax, 0x4c07b8
    cpu.eax = 4982712 /*0x4c07b8*/;
    // 00487bf3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487bf5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487bf7  893dbcaa4c00           -mov dword ptr [0x4caabc], edi
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.edi;
    // 00487bfd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487bfe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487bff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c00  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487c04:
    // 00487c04  68c8914800             -push 0x4891c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4755912 /*0x4891c8*/;
    cpu.esp -= 4;
    // 00487c09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487c0a  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00487c0c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487c0d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00487c0f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00487c11  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00487c13  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487c14  892dc4df5100           -mov dword ptr [0x51dfc4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5365700) /* 0x51dfc4 */) = cpu.ebp;
    // 00487c1a  892dc8df5100           -mov dword ptr [0x51dfc8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5365704) /* 0x51dfc8 */) = cpu.ebp;
    // 00487c20  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487c23  c7462800030000         -mov dword ptr [esi + 0x28], 0x300
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 768 /*0x300*/;
    // 00487c2a  c7462c00010000         -mov dword ptr [esi + 0x2c], 0x100
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 256 /*0x100*/;
    // 00487c31  a1c8df5100             -mov eax, dword ptr [0x51dfc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365704) /* 0x51dfc8 */);
    // 00487c36  8a965d040000           -mov dl, byte ptr [esi + 0x45d]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
    // 00487c3c  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00487c3f  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00487c41  7539                   -jne 0x487c7c
    if (!cpu.flags.zf)
    {
        goto L_0x00487c7c;
    }
    // 00487c43  837e0400               +cmp dword ptr [esi + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487c47  7533                   -jne 0x487c7c
    if (!cpu.flags.zf)
    {
        goto L_0x00487c7c;
    }
    // 00487c49  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487c4a  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00487c4d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487c4e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00487c50  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487c51  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00487c53  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487c54  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487c57  8b8e54040000           -mov ecx, dword ptr [esi + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
    // 00487c5d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487c5e  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00487c61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487c62  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00487c64  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487c65  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487c68  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00487c6d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00487c6f  893dbcaa4c00           -mov dword ptr [0x4caabc], edi
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.edi;
    // 00487c75  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c76  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487c7c:
    // 00487c7c  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00487c83  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00487c88  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00487c8a  893dbcaa4c00           -mov dword ptr [0x4caabc], edi
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.edi;
    // 00487c90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487c96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_487c98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487c98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487c99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487c9a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487c9b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487c9c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487c9d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487c9e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00487ca0  83b84404000000         +cmp dword ptr [eax + 0x444], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1092) /* 0x444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487ca7  740c                   -je 0x487cb5
    if (cpu.flags.zf)
    {
        goto L_0x00487cb5;
    }
    // 00487ca9  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00487cab  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00487cad  7406                   -je 0x487cb5
    if (cpu.flags.zf)
    {
        goto L_0x00487cb5;
    }
    // 00487caf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487cb0  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00487cb2  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00487cb5:
    // 00487cb5  8bb350040000           -mov esi, dword ptr [ebx + 0x450]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1104) /* 0x450 */);
    // 00487cbb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00487cbd  7407                   -je 0x487cc6
    if (cpu.flags.zf)
    {
        goto L_0x00487cc6;
    }
    // 00487cbf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487cc1  e8e27b0100             -call 0x49f8a8
    cpu.esp -= 4;
    sub_49f8a8(app, cpu);
    if (cpu.terminate) return;
L_0x00487cc6:
    // 00487cc6  8bbb4c040000           -mov edi, dword ptr [ebx + 0x44c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1100) /* 0x44c */);
    // 00487ccc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00487cce  7407                   -je 0x487cd7
    if (cpu.flags.zf)
    {
        goto L_0x00487cd7;
    }
    // 00487cd0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00487cd2  e8d17b0100             -call 0x49f8a8
    cpu.esp -= 4;
    sub_49f8a8(app, cpu);
    if (cpu.terminate) return;
L_0x00487cd7:
    // 00487cd7  c7835004000000000000   -mov dword ptr [ebx + 0x450], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1104) /* 0x450 */) = 0 /*0x0*/;
    // 00487ce1  8bab48040000           -mov ebp, dword ptr [ebx + 0x448]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1096) /* 0x448 */);
    // 00487ce7  c7834c04000000000000   -mov dword ptr [ebx + 0x44c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1100) /* 0x44c */) = 0 /*0x0*/;
    // 00487cf1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00487cf3  7409                   -je 0x487cfe
    if (cpu.flags.zf)
    {
        goto L_0x00487cfe;
    }
    // 00487cf5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00487cf7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487cf9  e87a100000             -call 0x488d78
    cpu.esp -= 4;
    sub_488d78(app, cpu);
    if (cpu.terminate) return;
L_0x00487cfe:
    // 00487cfe  8b8344040000           -mov eax, dword ptr [ebx + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1092) /* 0x444 */);
    // 00487d04  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487d06  7520                   -jne 0x487d28
    if (!cpu.flags.zf)
    {
        goto L_0x00487d28;
    }
L_0x00487d08:
    // 00487d08  c7834804000000000000   -mov dword ptr [ebx + 0x448], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1096) /* 0x448 */) = 0 /*0x0*/;
    // 00487d12  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00487d17  c7834404000000000000   -mov dword ptr [ebx + 0x444], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1092) /* 0x444 */) = 0 /*0x0*/;
    // 00487d21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d27  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487d28:
    // 00487d28  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487d2a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487d2c  e847100000             -call 0x488d78
    cpu.esp -= 4;
    sub_488d78(app, cpu);
    if (cpu.terminate) return;
    // 00487d31  ebd5                   -jmp 0x487d08
    goto L_0x00487d08;
}

/* align: skip 0x90 */
void Application::sub_487d34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00487d34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487d35  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487d36  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487d37  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487d38  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487d39  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487d3a  81ec44030000           -sub esp, 0x344
    (cpu.esp) -= x86::reg32(x86::sreg32(836 /*0x344*/));
    // 00487d40  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00487d42  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00487d44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487d46  7505                   -jne 0x487d4d
    if (!cpu.flags.zf)
    {
        goto L_0x00487d4d;
    }
    // 00487d48  be70d35100             -mov esi, 0x51d370
    cpu.esi = 5362544 /*0x51d370*/;
L_0x00487d4d:
    // 00487d4d  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00487d52  e8718effff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00487d57  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487d59  ba6c010000             -mov edx, 0x16c
    cpu.edx = 364 /*0x16c*/;
    // 00487d5e  e835ffffff             -call 0x487c98
    cpu.esp -= 4;
    sub_487c98(app, cpu);
    if (cpu.terminate) return;
    // 00487d63  8994246c010000         -mov dword ptr [esp + 0x16c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.edx;
    // 00487d6a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00487d6d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00487d6f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487d70  8d942470010000         -lea edx, [esp + 0x170]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 00487d77  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00487d79  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487d7a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00487d7c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487d7d  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487d80  8aa637040000           -mov ah, byte ptr [esi + 0x437]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
    // 00487d86  80fc01                 +cmp ah, 1
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487d89  0f8340010000           -jae 0x487ecf
    if (!cpu.flags.cf)
    {
        goto L_0x00487ecf;
    }
    // 00487d8f  c6863704000001         -mov byte ptr [esi + 0x437], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */) = 1 /*0x1*/;
L_0x00487d96:
    // 00487d96  f68424f001000010       +test byte ptr [esp + 0x1f0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(496) /* 0x1f0 */) & 16 /*0x10*/));
    // 00487d9e  0f8462010000           -je 0x487f06
    if (cpu.flags.zf)
    {
        goto L_0x00487f06;
    }
    // 00487da4  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x00487da6:
    // 00487da6  888660040000           -mov byte ptr [esi + 0x460], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1120) /* 0x460 */) = cpu.al;
    // 00487dac  f684247301000008       +test byte ptr [esp + 0x173], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 8 /*0x8*/));
    // 00487db4  0f8453010000           -je 0x487f0d
    if (cpu.flags.zf)
    {
        goto L_0x00487f0d;
    }
    // 00487dba  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x00487dbc:
    // 00487dbc  8aae5e040000           -mov ch, byte ptr [esi + 0x45e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1118) /* 0x45e */);
    // 00487dc2  888662040000           -mov byte ptr [esi + 0x462], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1122) /* 0x462 */) = cpu.al;
    // 00487dc8  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 00487dca  0f8544010000           -jne 0x487f14
    if (!cpu.flags.zf)
    {
        goto L_0x00487f14;
    }
    // 00487dd0  80be3604000000         +cmp byte ptr [esi + 0x436], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1078) /* 0x436 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487dd7  740e                   -je 0x487de7
    if (cpu.flags.zf)
    {
        goto L_0x00487de7;
    }
    // 00487dd9  c6863504000001         -mov byte ptr [esi + 0x435], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */) = 1 /*0x1*/;
    // 00487de0  c6863404000001         -mov byte ptr [esi + 0x434], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1076) /* 0x434 */) = 1 /*0x1*/;
L_0x00487de7:
    // 00487de7  81fe70d35100           +cmp esi, 0x51d370
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5362544 /*0x51d370*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487ded  7503                   -jne 0x487df2
    if (!cpu.flags.zf)
    {
        goto L_0x00487df2;
    }
    // 00487def  80cf02                 -or bh, 2
    cpu.bh |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00487df2:
    // 00487df2  80be6304000001         +cmp byte ptr [esi + 0x463], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487df9  762f                   -jbe 0x487e2a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00487e2a;
    }
    // 00487dfb  80be3504000000         +cmp byte ptr [esi + 0x435], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487e02  0f8430010000           -je 0x487f38
    if (cpu.flags.zf)
    {
        goto L_0x00487f38;
    }
L_0x00487e08:
    // 00487e08  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00487e0d:
    // 00487e0d  80be6004000000         +cmp byte ptr [esi + 0x460], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1120) /* 0x460 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487e14  0f8532010000           -jne 0x487f4c
    if (!cpu.flags.zf)
    {
        goto L_0x00487f4c;
    }
    // 00487e1a  80be6204000000         +cmp byte ptr [esi + 0x462], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1122) /* 0x462 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487e21  0f8425010000           -je 0x487f4c
    if (cpu.flags.zf)
    {
        goto L_0x00487f4c;
    }
L_0x00487e27:
    // 00487e27  80cf08                 -or bh, 8
    cpu.bh |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00487e2a:
    // 00487e2a  8b7e24                 -mov edi, dword ptr [esi + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00487e2d  8d4630                 -lea eax, [esi + 0x30]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00487e30  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00487e32  0f852e010000           -jne 0x487f66
    if (!cpu.flags.zf)
    {
        goto L_0x00487f66;
    }
    // 00487e38  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487e39  8d7e24                 -lea edi, [esi + 0x24]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00487e3c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487e3d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487e3e  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00487e40  6a44                   -push 0x44
    app->getMemory<x86::reg32>(cpu.esp-4) = 68 /*0x44*/;
    cpu.esp -= 4;
    // 00487e42  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00487e44  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487e45  ff5114                 -call dword ptr [ecx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00487e48:
    // 00487e48  66c786300400000000     -mov word ptr [esi + 0x430], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1072) /* 0x430 */) = 0 /*0x0*/;
    // 00487e51  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00487e53  66c78632040000ff00     -mov word ptr [esi + 0x432], 0xff
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1074) /* 0x432 */) = 255 /*0xff*/;
    // 00487e5c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487e5e  c6865f04000000         -mov byte ptr [esi + 0x45f], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = 0 /*0x0*/;
    // 00487e65  e866f4ffff             -call 0x4872d0
    cpu.esp -= 4;
    sub_4872d0(app, cpu);
    if (cpu.terminate) return;
    // 00487e6a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487e6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487e6e  0f8507010000           -jne 0x487f7b
    if (!cpu.flags.zf)
    {
        goto L_0x00487f7b;
    }
    // 00487e74  c6865f04000001         -mov byte ptr [esi + 0x45f], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = 1 /*0x1*/;
L_0x00487e7b:
    // 00487e7b  c6863704000002         -mov byte ptr [esi + 0x437], 2
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */) = 2 /*0x2*/;
    // 00487e82  8a8637040000           -mov al, byte ptr [esi + 0x437]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
    // 00487e88  888663040000           -mov byte ptr [esi + 0x463], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */) = cpu.al;
    // 00487e8e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00487e90  7409                   -je 0x487e9b
    if (cpu.flags.zf)
    {
        goto L_0x00487e9b;
    }
    // 00487e92  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00487e94  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487e96  e8dd0e0000             -call 0x488d78
    cpu.esp -= 4;
    sub_488d78(app, cpu);
    if (cpu.terminate) return;
L_0x00487e9b:
    // 00487e9b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00487e9d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487e9f  e82cf4ffff             -call 0x4872d0
    cpu.esp -= 4;
    sub_4872d0(app, cpu);
    if (cpu.terminate) return;
    // 00487ea4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00487ea6:
    // 00487ea6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00487ea8  0f8534010000           -jne 0x487fe2
    if (!cpu.flags.zf)
    {
        goto L_0x00487fe2;
    }
    // 00487eae  b8fc084c00             -mov eax, 0x4c08fc
    cpu.eax = 4983036 /*0x4c08fc*/;
    // 00487eb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487eb5  0f850e010000           -jne 0x487fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00487fc9;
    }
    // 00487ebb  a3bcaa4c00             -mov dword ptr [0x4caabc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.eax;
    // 00487ec0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487ec2  81c444030000           -add esp, 0x344
    (cpu.esp) += x86::reg32(x86::sreg32(836 /*0x344*/));
    // 00487ec8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ec9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487eca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ecb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ecc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ecd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ece  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487ecf:
    // 00487ecf  80fc02                 +cmp ah, 2
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487ed2  0f86befeffff           -jbe 0x487d96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00487d96;
    }
    // 00487ed8  b8d8084c00             -mov eax, 0x4c08d8
    cpu.eax = 4983000 /*0x4c08d8*/;
    // 00487edd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487edf  751e                   -jne 0x487eff
    if (!cpu.flags.zf)
    {
        goto L_0x00487eff;
    }
L_0x00487ee1:
    // 00487ee1  a3bcaa4c00             -mov dword ptr [0x4caabc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.eax;
    // 00487ee6  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00487eeb  e8f08cffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00487ef0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487ef2  81c444030000           +add esp, 0x344
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(836 /*0x344*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487ef8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ef9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487efa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487efb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487efc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487efd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487efe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487eff:
    // 00487eff  b8b8074c00             -mov eax, 0x4c07b8
    cpu.eax = 4982712 /*0x4c07b8*/;
    // 00487f04  ebdb                   -jmp 0x487ee1
    goto L_0x00487ee1;
L_0x00487f06:
    // 00487f06  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00487f08  e999feffff             -jmp 0x487da6
    goto L_0x00487da6;
L_0x00487f0d:
    // 00487f0d  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00487f0f  e9a8feffff             -jmp 0x487dbc
    goto L_0x00487dbc;
L_0x00487f14:
    // 00487f14  c6863604000000         -mov byte ptr [esi + 0x436], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1078) /* 0x436 */) = 0 /*0x0*/;
    // 00487f1b  c6863504000001         -mov byte ptr [esi + 0x435], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */) = 1 /*0x1*/;
    // 00487f22  c6863704000002         -mov byte ptr [esi + 0x437], 2
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */) = 2 /*0x2*/;
    // 00487f29  80cf2a                 +or bh, 0x2a
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(42 /*0x2a*/))));
    // 00487f2c  c6866304000001         -mov byte ptr [esi + 0x463], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */) = 1 /*0x1*/;
    // 00487f33  e9affeffff             -jmp 0x487de7
    goto L_0x00487de7;
L_0x00487f38:
    // 00487f38  80be3404000000         +cmp byte ptr [esi + 0x434], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1076) /* 0x434 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487f3f  0f85c3feffff           -jne 0x487e08
    if (!cpu.flags.zf)
    {
        goto L_0x00487e08;
    }
    // 00487f45  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00487f47  e9c1feffff             -jmp 0x487e0d
    goto L_0x00487e0d;
L_0x00487f4c:
    // 00487f4c  80be5e04000000         +cmp byte ptr [esi + 0x45e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1118) /* 0x45e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487f53  7408                   -je 0x487f5d
    if (cpu.flags.zf)
    {
        goto L_0x00487f5d;
    }
L_0x00487f55:
    // 00487f55  80cf40                 +or bh, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 00487f58  e9cdfeffff             -jmp 0x487e2a
    goto L_0x00487e2a;
L_0x00487f5d:
    // 00487f5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487f5f  74f4                   -je 0x487f55
    if (cpu.flags.zf)
    {
        goto L_0x00487f55;
    }
    // 00487f61  e9c1feffff             -jmp 0x487e27
    goto L_0x00487e27;
L_0x00487f66:
    // 00487f66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487f67  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00487f6c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487f6e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487f70  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00487f72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487f73  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487f76  e9cdfeffff             -jmp 0x487e48
    goto L_0x00487e48;
L_0x00487f7b:
    // 00487f7b  8d8c24d8020000         -lea ecx, [esp + 0x2d8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 00487f82  bd6c000000             -mov ebp, 0x6c
    cpu.ebp = 108 /*0x6c*/;
    // 00487f87  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487f88  89ac24dc020000         -mov dword ptr [esp + 0x2dc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(732) /* 0x2dc */) = cpu.ebp;
    // 00487f8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00487f90  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00487f92  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487f95  f684244203000020       +test byte ptr [esp + 0x342], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(834) /* 0x342 */) & 32 /*0x20*/));
    // 00487f9d  7415                   -je 0x487fb4
    if (cpu.flags.zf)
    {
        goto L_0x00487fb4;
    }
    // 00487f9f  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00487fa1  88865f040000           -mov byte ptr [esi + 0x45f], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = cpu.al;
    // 00487fa7  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00487fa9  0f85ccfeffff           -jne 0x487e7b
    if (!cpu.flags.zf)
    {
        goto L_0x00487e7b;
    }
    // 00487faf  e9f2feffff             -jmp 0x487ea6
    goto L_0x00487ea6;
L_0x00487fb4:
    // 00487fb4  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00487fb6  88865f040000           -mov byte ptr [esi + 0x45f], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = cpu.al;
    // 00487fbc  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00487fbe  0f85b7feffff           -jne 0x487e7b
    if (!cpu.flags.zf)
    {
        goto L_0x00487e7b;
    }
    // 00487fc4  e9ddfeffff             -jmp 0x487ea6
    goto L_0x00487ea6;
L_0x00487fc9:
    // 00487fc9  b8b8074c00             -mov eax, 0x4c07b8
    cpu.eax = 4982712 /*0x4c07b8*/;
    // 00487fce  a3bcaa4c00             -mov dword ptr [0x4caabc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024444) /* 0x4caabc */) = cpu.eax;
    // 00487fd3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487fd5  81c444030000           -add esp, 0x344
    (cpu.esp) += x86::reg32(x86::sreg32(836 /*0x344*/));
    // 00487fdb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487fdc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487fdd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487fde  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487fdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487fe0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487fe1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487fe2:
    // 00487fe2  837e0400               +cmp dword ptr [esi + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487fe6  7413                   -je 0x487ffb
    if (cpu.flags.zf)
    {
        goto L_0x00487ffb;
    }
    // 00487fe8  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487fef  750a                   -jne 0x487ffb
    if (!cpu.flags.zf)
    {
        goto L_0x00487ffb;
    }
    // 00487ff1  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00487ff4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487ff5  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00487ff7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487ff8  ff5070                 -call dword ptr [eax + 0x70]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00487ffb:
    // 00487ffb  8d8424d8020000         -lea eax, [esp + 0x2d8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 00488002  b96c000000             -mov ecx, 0x6c
    cpu.ecx = 108 /*0x6c*/;
    // 00488007  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488008  898c24dc020000         -mov dword ptr [esp + 0x2dc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(732) /* 0x2dc */) = cpu.ecx;
    // 0048800f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488010  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 00488012  8d9c24e0020000         -lea ebx, [esp + 0x2e0]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(736) /* 0x2e0 */);
    // 00488019  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048801c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00488021  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488023  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00488026  e859f5ffff             -call 0x487584
    cpu.esp -= 4;
    sub_487584(app, cpu);
    if (cpu.terminate) return;
    // 0048802b  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 00488031  89be44040000           -mov dword ptr [esi + 0x444], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */) = cpu.edi;
    // 00488037  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488039  0f8602010000           -jbe 0x488141
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488141;
    }
    // 0048803f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00488041  e8660d0000             -call 0x488dac
    cpu.esp -= 4;
    sub_488dac(app, cpu);
    if (cpu.terminate) return;
L_0x00488046:
    // 00488046  898648040000           -mov dword ptr [esi + 0x448], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */) = cpu.eax;
L_0x0048804c:
    // 0048804c  83be4404000000         +cmp dword ptr [esi + 0x444], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488053  745a                   -je 0x4880af
    if (cpu.flags.zf)
    {
        goto L_0x004880af;
    }
    // 00488055  c78424d80200006c000000 -mov dword ptr [esp + 0x2d8], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */) = 108 /*0x6c*/;
    // 00488060  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00488063  8d8c24d8020000         -lea ecx, [esp + 0x2d8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 0048806a  898424e8020000         -mov dword ptr [esp + 0x2e8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */) = cpu.eax;
    // 00488071  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488072  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 00488078  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488079  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048807b  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048807e  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 00488084  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488085  8b942400030000         -mov edx, dword ptr [esp + 0x300]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0048808c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048808e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048808f  8b9c24f0020000         -mov ebx, dword ptr [esp + 0x2f0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(752) /* 0x2f0 */);
    // 00488096  8a8e5c040000           -mov cl, byte ptr [esi + 0x45c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */);
    // 0048809c  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0048809e  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004880a1  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004880a4  e8df760100             -call 0x49f788
    cpu.esp -= 4;
    sub_49f788(app, cpu);
    if (cpu.terminate) return;
    // 004880a9  89864c040000           -mov dword ptr [esi + 0x44c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1100) /* 0x44c */) = cpu.eax;
L_0x004880af:
    // 004880af  83be4804000000         +cmp dword ptr [esi + 0x448], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004880b6  0f84f6000000           -je 0x4881b2
    if (cpu.flags.zf)
    {
        goto L_0x004881b2;
    }
    // 004880bc  c78424d80200006c000000 -mov dword ptr [esp + 0x2d8], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */) = 108 /*0x6c*/;
    // 004880c7  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004880ca  8d9424d8020000         -lea edx, [esp + 0x2d8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 004880d1  898424e8020000         -mov dword ptr [esp + 0x2e8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */) = cpu.eax;
    // 004880d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004880d9  8b8648040000           -mov eax, dword ptr [esi + 0x448]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 004880df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004880e0  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004880e2  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004880e5  8bbe48040000           -mov edi, dword ptr [esi + 0x448]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 004880eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004880ec  8bac2400030000         -mov ebp, dword ptr [esp + 0x300]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004880f3  8b9c24ec020000         -mov ebx, dword ptr [esp + 0x2ec]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(748) /* 0x2ec */);
    // 004880fa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004880fb  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004880fe  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488100  6afe                   -push -2
    app->getMemory<x86::reg32>(cpu.esp-4) = -2 /*-0x2*/;
    cpu.esp -= 4;
    // 00488102  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00488105  8a8e5c040000           -mov cl, byte ptr [esi + 0x45c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */);
    // 0048810b  e878760100             -call 0x49f788
    cpu.esp -= 4;
    sub_49f788(app, cpu);
    if (cpu.terminate) return;
    // 00488110  898650040000           -mov dword ptr [esi + 0x450], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1104) /* 0x450 */) = cpu.eax;
L_0x00488116:
    // 00488116  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 0048811b  e8c08affff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00488120  833d70a64c0000         +cmp dword ptr [0x4ca670], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023344) /* 0x4ca670 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488127  7406                   -je 0x48812f
    if (cpu.flags.zf)
    {
        goto L_0x0048812f;
    }
    // 00488129  ff1570a64c00           -call dword ptr [0x4ca670]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023344) /* 0x4ca670 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048812f:
    // 0048812f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00488134  81c444030000           -add esp, 0x344
    (cpu.esp) += x86::reg32(x86::sreg32(836 /*0x344*/));
    // 0048813a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048813b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048813c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048813d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048813e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048813f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488140  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488141:
    // 00488141  80be3604000000         +cmp byte ptr [esi + 0x436], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1078) /* 0x436 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488148  0f85fefeffff           -jne 0x48804c
    if (!cpu.flags.zf)
    {
        goto L_0x0048804c;
    }
    // 0048814e  80be3704000001         +cmp byte ptr [esi + 0x437], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488155  0f86f1feffff           -jbe 0x48804c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048804c;
    }
    // 0048815b  80be3504000000         +cmp byte ptr [esi + 0x435], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488162  742b                   -je 0x48818f
    if (cpu.flags.zf)
    {
        goto L_0x0048818f;
    }
L_0x00488164:
    // 00488164  8b9e48040000           -mov ebx, dword ptr [esi + 0x448]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 0048816a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048816c  0f85dafeffff           -jne 0x48804c
    if (!cpu.flags.zf)
    {
        goto L_0x0048804c;
    }
    // 00488172  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488173  6840080000             -push 0x840
    app->getMemory<x86::reg32>(cpu.esp-4) = 2112 /*0x840*/;
    cpu.esp -= 4;
    // 00488178  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488179  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048817b  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0048817e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048817f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00488182  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00488185  e8fa090000             -call 0x488b84
    cpu.esp -= 4;
    sub_488b84(app, cpu);
    if (cpu.terminate) return;
    // 0048818a  e9b7feffff             -jmp 0x488046
    goto L_0x00488046;
L_0x0048818f:
    // 0048818f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488191  6840400000             -push 0x4040
    app->getMemory<x86::reg32>(cpu.esp-4) = 16448 /*0x4040*/;
    cpu.esp -= 4;
    // 00488196  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488198  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048819a  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0048819d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048819f  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004881a2  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004881a5  e8da090000             -call 0x488b84
    cpu.esp -= 4;
    sub_488b84(app, cpu);
    if (cpu.terminate) return;
    // 004881aa  898648040000           -mov dword ptr [esi + 0x448], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */) = cpu.eax;
    // 004881b0  ebb2                   -jmp 0x488164
    goto L_0x00488164;
L_0x004881b2:
    // 004881b2  80be3704000001         +cmp byte ptr [esi + 0x437], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004881b9  0f8657ffffff           -jbe 0x488116
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488116;
    }
    // 004881bf  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004881c2  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004881c5  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004881c7  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004881ca  8a9e5c040000           -mov bl, byte ptr [esi + 0x45c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */);
    // 004881d0  bf2ca74c00             -mov edi, 0x4ca72c
    cpu.edi = 5023532 /*0x4ca72c*/;
    // 004881d5  e836ce0000             -call 0x495010
    cpu.esp -= 4;
    sub_495010(app, cpu);
    if (cpu.terminate) return;
    // 004881da  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004881df  898650040000           -mov dword ptr [esi + 0x450], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1104) /* 0x450 */) = cpu.eax;
    // 004881e5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004881e7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004881e9  e928ffffff             -jmp 0x488116
    goto L_0x00488116;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4881f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004881f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004881f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004881f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004881f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004881f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004881f5  81ec8c040000           -sub esp, 0x48c
    (cpu.esp) -= x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 004881fb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004881fd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004881ff  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00488201  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488203  7505                   -jne 0x48820a
    if (!cpu.flags.zf)
    {
        goto L_0x0048820a;
    }
    // 00488205  bb70d35100             -mov ebx, 0x51d370
    cpu.ebx = 5362544 /*0x51d370*/;
L_0x0048820a:
    // 0048820a  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0048820f  8d8c2400040000         -lea ecx, [esp + 0x400]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 00488216  89942400040000         -mov dword ptr [esp + 0x400], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.edx;
    // 0048821d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048821e  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00488220  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488221  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488223  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488226  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00488228  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048822f  0f84f0010000           -je 0x488425
    if (cpu.flags.zf)
    {
        goto L_0x00488425;
    }
    // 00488235  837b1000               +cmp dword ptr [ebx + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488239  0f843f010000           -je 0x48837e
    if (cpu.flags.zf)
    {
        goto L_0x0048837e;
    }
    // 0048823f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00488241  0f8c45010000           -jl 0x48838c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048838c;
    }
    // 00488247  3b7308                 +cmp esi, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048824a  7c02                   -jl 0x48824e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048824e;
    }
    // 0048824c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048824e:
    // 0048824e  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00488255  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00488257  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048825a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048825d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048825f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00488262  89942488040000         -mov dword ptr [esp + 0x488], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */) = cpu.edx;
    // 00488269  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048826b  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 0048826d  8a5012                 -mov dl, byte ptr [eax + 0x12]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 00488270  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00488273  89942484040000         -mov dword ptr [esp + 0x484], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */) = cpu.edx;
    // 0048827a  8984247c040000         -mov dword ptr [esp + 0x47c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.eax;
L_0x00488281:
    // 00488281  837b2400               +cmp dword ptr [ebx + 0x24], 0
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
    // 00488285  7433                   -je 0x4882ba
    if (cpu.flags.zf)
    {
        goto L_0x004882ba;
    }
    // 00488287  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0048828c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048828e  e8098affff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00488293  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00488295  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488296  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0048829b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048829d  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004882a0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004882a2  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004882a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004882a5  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004882a8  66c783300400000000     -mov word ptr [ebx + 0x430], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1072) /* 0x430 */) = 0 /*0x0*/;
    // 004882b1  66c78332040000ff00     -mov word ptr [ebx + 0x432], 0xff
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1074) /* 0x432 */) = 255 /*0xff*/;
L_0x004882ba:
    // 004882ba  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004882bc  8b8c2480040000         -mov ecx, dword ptr [esp + 0x480]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
    // 004882c3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004882c4  8b8c248c040000         -mov ecx, dword ptr [esp + 0x48c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1164) /* 0x48c */);
    // 004882cb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004882cc  8b8c2494040000         -mov ecx, dword ptr [esp + 0x494]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1172) /* 0x494 */);
    // 004882d3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004882d4  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004882d6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004882d7  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004882d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004882da  ff5254                 -call dword ptr [edx + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004882dd  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004882e2  89842480040000         -mov dword ptr [esp + 0x480], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */) = cpu.eax;
    // 004882e9  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 004882ee  8d8c2400040000         -lea ecx, [esp + 0x400]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 004882f5  89842400040000         -mov dword ptr [esp + 0x400], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.eax;
    // 004882fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004882fd  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004882ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488300  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488302  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488305  8b94240c040000         -mov edx, dword ptr [esp + 0x40c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 0048830c  39d5                   +cmp ebp, edx
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
    // 0048830e  0f82a3000000           -jb 0x4883b7
    if (cpu.flags.cf)
    {
        goto L_0x004883b7;
    }
    // 00488314  895314                 -mov dword ptr [ebx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x00488317:
    // 00488317  8b842488040000         -mov eax, dword ptr [esp + 0x488]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */);
    // 0048831e  8b8c2408040000         -mov ecx, dword ptr [esp + 0x408]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1032) /* 0x408 */);
    // 00488325  39c8                   +cmp eax, ecx
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
    // 00488327  0f82a3000000           -jb 0x4883d0
    if (cpu.flags.cf)
    {
        goto L_0x004883d0;
    }
    // 0048832d  894b18                 -mov dword ptr [ebx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x00488330:
    // 00488330  83bc248004000000       +cmp dword ptr [esp + 0x480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488338  0f85b2000000           -jne 0x4883f0
    if (!cpu.flags.zf)
    {
        goto L_0x004883f0;
    }
    // 0048833e  8b842484040000         -mov eax, dword ptr [esp + 0x484]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */);
    // 00488345  3b842454040000         +cmp eax, dword ptr [esp + 0x454]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048834c  0f859e000000           -jne 0x4883f0
    if (!cpu.flags.zf)
    {
        goto L_0x004883f0;
    }
    // 00488352  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x00488357:
    // 00488357  8b842454040000         -mov eax, dword ptr [esp + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */);
    // 0048835e  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00488361  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 00488366  89730c                 -mov dword ptr [ebx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00488369  2eff1598734b00         -call dword ptr cs:[0x4b7398]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944792) /* 0x4b7398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488370  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00488372  81c48c040000           -add esp, 0x48c
    (cpu.esp) += x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 00488378  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488379  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048837a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048837b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048837c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048837d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048837e:
    // 0048837e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488380  81c48c040000           -add esp, 0x48c
    (cpu.esp) += x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 00488386  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488387  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488388  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488389  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048838a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048838b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048838c:
    // 0048838c  bd80020000             -mov ebp, 0x280
    cpu.ebp = 640 /*0x280*/;
    // 00488391  b8e0010000             -mov eax, 0x1e0
    cpu.eax = 480 /*0x1e0*/;
    // 00488396  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048839b  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0048839d  89842488040000         -mov dword ptr [esp + 0x488], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */) = cpu.eax;
    // 004883a4  89942484040000         -mov dword ptr [esp + 0x484], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */) = cpu.edx;
    // 004883ab  898c247c040000         -mov dword ptr [esp + 0x47c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.ecx;
    // 004883b2  e9cafeffff             -jmp 0x488281
    goto L_0x00488281;
L_0x004883b7:
    // 004883b7  896b14                 -mov dword ptr [ebx + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 004883ba  8b84240c040000         -mov eax, dword ptr [esp + 0x40c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 004883c1  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004883c3  d1e8                   +shr eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004883c5  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 004883cb  e947ffffff             -jmp 0x488317
    goto L_0x00488317;
L_0x004883d0:
    // 004883d0  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004883d3  8bac2488040000         -mov ebp, dword ptr [esp + 0x488]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */);
    // 004883da  8b842408040000         -mov eax, dword ptr [esp + 0x408]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1032) /* 0x408 */);
    // 004883e1  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004883e3  d1e8                   +shr eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004883e5  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 004883eb  e940ffffff             -jmp 0x488330
    goto L_0x00488330;
L_0x004883f0:
    // 004883f0  81bc2480040000e1000000 +cmp dword ptr [esp + 0x480], 0xe1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(225 /*0xe1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004883fb  750a                   -jne 0x488407
    if (!cpu.flags.zf)
    {
        goto L_0x00488407;
    }
    // 004883fd  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 00488402  e950ffffff             -jmp 0x488357
    goto L_0x00488357;
L_0x00488407:
    // 00488407  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00488409  0f8548ffffff           -jne 0x488357
    if (!cpu.flags.zf)
    {
        goto L_0x00488357;
    }
    // 0048840f  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00488416  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00488419  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048841b  804c820f80             +or byte ptr [edx + eax*4 + 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 00488420  e932ffffff             -jmp 0x488357
    goto L_0x00488357;
L_0x00488425:
    // 00488425  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 0048842c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048842d  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 00488433  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488434  2eff15e4734b00         -call dword ptr cs:[0x4b73e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944868) /* 0x4b73e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048843b  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 00488442  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488443  8bbb54040000           -mov edi, dword ptr [ebx + 0x454]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 00488449  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048844a  2eff15c4734b00         -call dword ptr cs:[0x4b73c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944836) /* 0x4b73c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488451  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 00488458  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488459  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048845f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488460  2eff15c4734b00         -call dword ptr cs:[0x4b73c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944836) /* 0x4b73c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488467  81bb6404000078ecffff   +cmp dword ptr [ebx + 0x464], 0xffffec78
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294962296 /*0xffffec78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488471  7d1e                   -jge 0x488491
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00488491;
    }
    // 00488473  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488475  2eff15f4734b00         -call dword ptr cs:[0x4b73f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944884) /* 0x4b73f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048847c  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048847f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488481  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488483  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00488486  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00488488  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048848a  8984246c040000         -mov dword ptr [esp + 0x46c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */) = cpu.eax;
L_0x00488491:
    // 00488491  81bb6804000078ecffff   +cmp dword ptr [ebx + 0x468], 0xffffec78
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294962296 /*0xffffec78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048849b  7d1e                   -jge 0x4884bb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004884bb;
    }
    // 0048849d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048849f  2eff15f4734b00         -call dword ptr cs:[0x4b73f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944884) /* 0x4b73f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004884a6  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004884a9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004884ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004884ad  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004884b0  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004884b2  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004884b4  89842470040000         -mov dword ptr [esp + 0x470], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */) = cpu.eax;
L_0x004884bb:
    // 004884bb  8b84246c040000         -mov eax, dword ptr [esp + 0x46c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004884c2  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004884c5  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004884c7  89842474040000         -mov dword ptr [esp + 0x474], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1140) /* 0x474 */) = cpu.eax;
    // 004884ce  8b842470040000         -mov eax, dword ptr [esp + 0x470]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 004884d5  034318                 -add eax, dword ptr [ebx + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 004884d8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004884da  8984247c040000         -mov dword ptr [esp + 0x47c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.eax;
    // 004884e1  6af0                   -push -0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = -16 /*-0x10*/;
    cpu.esp -= 4;
    // 004884e3  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004884e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004884ea  2eff15f8734b00         -call dword ptr cs:[0x4b73f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944888) /* 0x4b73f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004884f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004884f2  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 004884f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004884fa  2eff15b0734b00         -call dword ptr cs:[0x4b73b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944816) /* 0x4b73b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488501  8b842478040000         -mov eax, dword ptr [esp + 0x478]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1144) /* 0x478 */);
    // 00488508  8b942470040000         -mov edx, dword ptr [esp + 0x470]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 0048850f  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 00488511  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00488513  8b8c2470040000         -mov ecx, dword ptr [esp + 0x470]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 0048851a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048851b  8b84247c040000         -mov eax, dword ptr [esp + 0x47c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */);
    // 00488522  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488524  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488525  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488526  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488527  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488529  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048852f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488530  2eff1528744b00         -call dword ptr cs:[0x4b7428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944936) /* 0x4b7428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488537  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 0048853e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048853f  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 00488545  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488546  2eff15e4734b00         -call dword ptr cs:[0x4b73e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944868) /* 0x4b73e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048854d  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 00488554  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488555  8bbb54040000           -mov edi, dword ptr [ebx + 0x454]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048855b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048855c  2eff15c4734b00         -call dword ptr cs:[0x4b73c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944836) /* 0x4b73c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488563  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 0048856a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048856b  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 00488571  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488572  2eff15c4734b00         -call dword ptr cs:[0x4b73c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944836) /* 0x4b73c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488579  8b842474040000         -mov eax, dword ptr [esp + 0x474]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 00488580  8b94246c040000         -mov edx, dword ptr [esp + 0x46c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 00488587  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00488589  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048858c  8b842478040000         -mov eax, dword ptr [esp + 0x478]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1144) /* 0x478 */);
    // 00488593  8b8c2470040000         -mov ecx, dword ptr [esp + 0x470]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 0048859a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048859c  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048859f  8b84246c040000         -mov eax, dword ptr [esp + 0x46c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004885a6  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 004885ac  8b842470040000         -mov eax, dword ptr [esp + 0x470]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 004885b3  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 004885b9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004885bb  7520                   -jne 0x4885dd
    if (!cpu.flags.zf)
    {
        goto L_0x004885dd;
    }
    // 004885bd  8b842454040000         -mov eax, dword ptr [esp + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */);
L_0x004885c4:
    // 004885c4  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004885c7  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004885cc  89730c                 -mov dword ptr [ebx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004885cf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004885d1  81c48c040000           +add esp, 0x48c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1164 /*0x48c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004885d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885db  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004885dd:
    // 004885dd  a1d8a34c00             -mov eax, dword ptr [0x4ca3d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022680) /* 0x4ca3d8 */);
    // 004885e2  ebe0                   -jmp 0x4885c4
    goto L_0x004885c4;
}

/* align: skip  */
void Application::sub_4885e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004885e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004885e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004885e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004885e9  7505                   -jne 0x4885f0
    if (!cpu.flags.zf)
    {
        goto L_0x004885f0;
    }
    // 004885eb  bb70d35100             -mov ebx, 0x51d370
    cpu.ebx = 5362544 /*0x51d370*/;
L_0x004885f0:
    // 004885f0  833b00                 +cmp dword ptr [ebx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004885f3  7450                   -je 0x488645
    if (cpu.flags.zf)
    {
        goto L_0x00488645;
    }
    // 004885f5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004885f6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004885f7  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 004885fc  e8c785ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00488601  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488603  e890f6ffff             -call 0x487c98
    cpu.esp -= 4;
    sub_487c98(app, cpu);
    if (cpu.terminate) return;
    // 00488608  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048860a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048860b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048860d  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488610  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00488613  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00488615  7407                   -je 0x48861e
    if (cpu.flags.zf)
    {
        goto L_0x0048861e;
    }
    // 00488617  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00488619  e86e20ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x0048861e:
    // 0048861e  c7431000000000         -mov dword ptr [ebx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00488625  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048862c  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00488633  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00488638  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 0048863e  e89d85ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00488643  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488644  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00488645:
    // 00488645  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488646  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488648(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488648  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488649  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048864a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048864c  7505                   -jne 0x488653
    if (!cpu.flags.zf)
    {
        goto L_0x00488653;
    }
    // 0048864e  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
L_0x00488653:
    // 00488653  8b9054040000           -mov edx, dword ptr [eax + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */);
    // 00488659  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048865a  2eff1524744b00         -call dword ptr cs:[0x4b7424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944932) /* 0x4b7424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488661  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488662  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488663  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488664(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488664  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488665  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488666  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488669  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048866b  7505                   -jne 0x488672
    if (!cpu.flags.zf)
    {
        goto L_0x00488672;
    }
    // 0048866d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
L_0x00488672:
    // 00488672  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00488674  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488676  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488677  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488679  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048867a  ff5140                 -call dword ptr [ecx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048867d  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 00488681  7509                   -jne 0x48868c
    if (!cpu.flags.zf)
    {
        goto L_0x0048868c;
    }
    // 00488683  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00488686  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488689  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048868a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048868b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048868c:
    // 0048868c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00488691  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488694  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488695  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488696  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488698(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488698  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488699  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048869a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048869c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048869e  7505                   -jne 0x4886a5
    if (!cpu.flags.zf)
    {
        goto L_0x004886a5;
    }
    // 004886a0  b970d35100             -mov ecx, 0x51d370
    cpu.ecx = 5362544 /*0x51d370*/;
L_0x004886a5:
    // 004886a5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004886a7  e830030000             -call 0x4889dc
    cpu.esp -= 4;
    sub_4889dc(app, cpu);
    if (cpu.terminate) return;
    // 004886ac  8b9944040000           -mov ebx, dword ptr [ecx + 0x444]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1092) /* 0x444 */);
    // 004886b2  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004886b4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004886b6  7420                   -je 0x4886d8
    if (cpu.flags.zf)
    {
        goto L_0x004886d8;
    }
    // 004886b8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004886bd:
    // 004886bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004886be  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004886c0  8b9144040000           -mov edx, dword ptr [ecx + 0x444]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1092) /* 0x444 */);
    // 004886c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004886c7  ff532c                 -call dword ptr [ebx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004886ca  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 004886ce  750c                   -jne 0x4886dc
    if (!cpu.flags.zf)
    {
        goto L_0x004886dc;
    }
    // 004886d0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004886d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004886d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004886d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004886d8:
    // 004886d8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004886da  ebe1                   -jmp 0x4886bd
    goto L_0x004886bd;
L_0x004886dc:
    // 004886dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004886de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004886df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004886e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4886e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004886e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004886e5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004886e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004886e8  7505                   -jne 0x4886ef
    if (!cpu.flags.zf)
    {
        goto L_0x004886ef;
    }
    // 004886ea  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
L_0x004886ef:
    // 004886ef  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004886f1  8b8044040000           -mov eax, dword ptr [eax + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1092) /* 0x444 */);
    // 004886f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004886f8  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004886fa  ff5248                 -call dword ptr [edx + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004886fd  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00488702  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488707  7408                   -je 0x488711
    if (cpu.flags.zf)
    {
        goto L_0x00488711;
    }
    // 00488709  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048870e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048870f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488710  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488711:
    // 00488711  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488713  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488714  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488715  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
