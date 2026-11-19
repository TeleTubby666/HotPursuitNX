#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_41fc30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fc30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fc31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fc32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041fc33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fc34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fc35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041fc36  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041fc39  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041fc3b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fc3d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0041fc40  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0041fc42  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041fc46  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0041fc49  8a501f                 -mov dl, byte ptr [eax + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
    // 0041fc4c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041fc50  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0041fc52  0f858f000000           -jne 0x41fce7
    if (!cpu.flags.zf)
    {
        goto L_0x0041fce7;
    }
L_0x0041fc58:
    // 0041fc58  8b4f24                 -mov ecx, dword ptr [edi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0041fc5b  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0041fc5e  39c8                   +cmp eax, ecx
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
    // 0041fc60  7617                   -jbe 0x41fc79
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041fc79;
    }
    // 0041fc62  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041fc66  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0041fc68  8b571c                 -mov edx, dword ptr [edi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0041fc6b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041fc6f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fc71  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fc73  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0041fc76  014724                 -add dword ptr [edi + 0x24], eax
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0041fc79:
    // 0041fc79  8b4724                 -mov eax, dword ptr [edi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0041fc7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fc7e  7452                   -je 0x41fcd2
    if (cpu.flags.zf)
    {
        goto L_0x0041fcd2;
    }
    // 0041fc80  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041fc82  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0041fc84:
    // 0041fc84  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0041fc86  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041fc88  8b5f1c                 -mov ebx, dword ptr [edi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0041fc8b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041fc8d  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0041fc8f  e86c000000             -call 0x41fd00
    cpu.esp -= 4;
    sub_41fd00(app, cpu);
    if (cpu.terminate) return;
    // 0041fc94  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041fc98  807a1f00               +cmp byte ptr [edx + 0x1f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(31) /* 0x1f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041fc9c  7516                   -jne 0x41fcb4
    if (!cpu.flags.zf)
    {
        goto L_0x0041fcb4;
    }
    // 0041fc9e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fca0  7412                   -je 0x41fcb4
    if (cpu.flags.zf)
    {
        goto L_0x0041fcb4;
    }
    // 0041fca2  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fca4  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041fca6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fca8  740a                   -je 0x41fcb4
    if (cpu.flags.zf)
    {
        goto L_0x0041fcb4;
    }
    // 0041fcaa  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041fcae  83780400               +cmp dword ptr [eax + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fcb2  75d0                   -jne 0x41fc84
    if (!cpu.flags.zf)
    {
        goto L_0x0041fc84;
    }
L_0x0041fcb4:
    // 0041fcb4  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041fcb8  80781f00               +cmp byte ptr [eax + 0x1f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041fcbc  7514                   -jne 0x41fcd2
    if (!cpu.flags.zf)
    {
        goto L_0x0041fcd2;
    }
    // 0041fcbe  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0041fcc0  7410                   -je 0x41fcd2
    if (cpu.flags.zf)
    {
        goto L_0x0041fcd2;
    }
    // 0041fcc2  8b571c                 -mov edx, dword ptr [edi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0041fcc5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0041fcc7  8d042a                 -lea eax, [edx + ebp]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0041fcca  e831190600             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0041fccf  897724                 -mov dword ptr [edi + 0x24], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.esi;
L_0x0041fcd2:
    // 0041fcd2  833c2400               +cmp dword ptr [esp], 0
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
    // 0041fcd6  741b                   -je 0x41fcf3
    if (cpu.flags.zf)
    {
        goto L_0x0041fcf3;
    }
    // 0041fcd8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041fcdd  83c40c                 +add esp, 0xc
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
    // 0041fce0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fce1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fce2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fce3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fce4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fce5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fce6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fce7:
    // 0041fce7  c7472400000000         -mov dword ptr [edi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0041fcee  e965ffffff             -jmp 0x41fc58
    goto L_0x0041fc58;
L_0x0041fcf3:
    // 0041fcf3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fcf5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041fcf8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fcf9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fcfa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fcfb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fcfc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fcfd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fcfe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_41fd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fd00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fd01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fd02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041fd03  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041fd06  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041fd08  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041fd0c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0041fd0e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0041fd10  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0041fd12  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041fd16  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0041fd19  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041fd1b  8a501f                 -mov dl, byte ptr [eax + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
    // 0041fd1e  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0041fd21  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0041fd23  7512                   -jne 0x41fd37
    if (!cpu.flags.zf)
    {
        goto L_0x0041fd37;
    }
    // 0041fd25  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0041fd27  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x0041fd2a:
    // 0041fd2a  39d0                   +cmp eax, edx
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
    // 0041fd2c  7309                   -jae 0x41fd37
    if (!cpu.flags.cf)
    {
        goto L_0x0041fd37;
    }
    // 0041fd2e  8038fe                 +cmp byte ptr [eax], 0xfe
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041fd31  7404                   -je 0x41fd37
    if (cpu.flags.zf)
    {
        goto L_0x0041fd37;
    }
    // 0041fd33  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0041fd34  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0041fd35  ebf3                   -jmp 0x41fd2a
    goto L_0x0041fd2a;
L_0x0041fd37:
    // 0041fd37  8d042e                 -lea eax, [esi + ebp]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0041fd3a  8038fe                 +cmp byte ptr [eax], 0xfe
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041fd3d  7529                   -jne 0x41fd68
    if (!cpu.flags.zf)
    {
        goto L_0x0041fd68;
    }
    // 0041fd3f  8d4e06                 -lea ecx, [esi + 6]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0041fd42  39d9                   +cmp ecx, ebx
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
    // 0041fd44  7626                   -jbe 0x41fd6c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041fd6c;
    }
L_0x0041fd46:
    // 0041fd46  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0041fd49  83c728                 -add edi, 0x28
    (cpu.edi) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0041fd4c  39d6                   +cmp esi, edx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd4e  0f8677010000           -jbe 0x41fecb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041fecb;
    }
    // 0041fd54  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041fd59  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0041fd5b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041fd5d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041fd5f  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
L_0x0041fd61:
    // 0041fd61  83c410                 +add esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041fd64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fd65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fd66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fd67  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fd68:
    // 0041fd68  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0041fd6a  ebf5                   -jmp 0x41fd61
    goto L_0x0041fd61;
L_0x0041fd6c:
    // 0041fd6c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fd6e  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0041fd71  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0041fd73  3b5708                 +cmp edx, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd76  0f8733010000           -ja 0x41feaf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041feaf;
    }
    // 0041fd7c  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041fd7e  39d9                   +cmp ecx, ebx
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
    // 0041fd80  77c4                   -ja 0x41fd46
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041fd46;
    }
    // 0041fd82  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0041fd84  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0041fd86  e885060000             -call 0x420410
    cpu.esp -= 4;
    sub_420410(app, cpu);
    if (cpu.terminate) return;
    // 0041fd8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fd8d  0f8414010000           -je 0x41fea7
    if (cpu.flags.zf)
    {
        goto L_0x0041fea7;
    }
    // 0041fd93  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041fd97  83780400               +cmp dword ptr [eax + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd9b  740c                   -je 0x41fda9
    if (cpu.flags.zf)
    {
        goto L_0x0041fda9;
    }
    // 0041fd9d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041fda1  a150af4c00             -mov eax, dword ptr [0x4caf50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025616) /* 0x4caf50 */);
    // 0041fda6  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0041fda9:
    // 0041fda9  ff4710                 -inc dword ptr [edi + 0x10]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */))++;
    // 0041fdac  8a7503                 -mov dh, byte ptr [ebp + 3]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(3) /* 0x3 */);
    // 0041fdaf  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fdb1  80fe7f                 +cmp dh, 0x7f
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041fdb4  770c                   -ja 0x41fdc2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041fdc2;
    }
    // 0041fdb6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fdb8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041fdba  8a5503                 -mov dl, byte ptr [ebp + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(3) /* 0x3 */);
    // 0041fdbd  e86e020000             -call 0x420030
    cpu.esp -= 4;
    sub_420030(app, cpu);
    if (cpu.terminate) return;
L_0x0041fdc2:
    // 0041fdc2  8a5d01                 -mov bl, byte ptr [ebp + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0041fdc5  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0041fdc8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0041fdca  7408                   -je 0x41fdd4
    if (cpu.flags.zf)
    {
        goto L_0x0041fdd4;
    }
    // 0041fdcc  8a7d02                 -mov bh, byte ptr [ebp + 2]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0041fdcf  80ff7f                 +cmp bh, 0x7f
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041fdd2  7642                   -jbe 0x41fe16
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041fe16;
    }
L_0x0041fdd4:
    // 0041fdd4  8a4d02                 -mov cl, byte ptr [ebp + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0041fdd7  80f97f                 +cmp cl, 0x7f
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041fdda  0f86b7000000           -jbe 0x41fe97
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041fe97;
    }
    // 0041fde0  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041fde3  0f855dffffff           -jne 0x41fd46
    if (!cpu.flags.zf)
    {
        goto L_0x0041fd46;
    }
    // 0041fde9  833d4caf4c0002         +cmp dword ptr [0x4caf4c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fdf0  7c18                   -jl 0x41fe0a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fe0a;
    }
    // 0041fdf2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fdf4  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0041fdf7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fdf8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fdfa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041fdfc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041fdfe  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0041fe00  b8a8a24b00             -mov eax, 0x4ba2a8
    cpu.eax = 4956840 /*0x4ba2a8*/;
    // 0041fe05  e89a250600             -call 0x4823a4
    cpu.esp -= 4;
    sub_4823a4(app, cpu);
    if (cpu.terminate) return;
L_0x0041fe0a:
    // 0041fe0a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041fe0c  e8cf000000             -call 0x41fee0
    cpu.esp -= 4;
    sub_41fee0(app, cpu);
    if (cpu.terminate) return;
    // 0041fe11  e930ffffff             -jmp 0x41fd46
    goto L_0x0041fd46;
L_0x0041fe16:
    // 0041fe16  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fe18  8b4770                 -mov eax, dword ptr [edi + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(112) /* 0x70 */);
    // 0041fe1b  88fa                   -mov dl, bh
    cpu.dl = cpu.bh;
    // 0041fe1d  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 0041fe22  e849060000             -call 0x420470
    cpu.esp -= 4;
    sub_420470(app, cpu);
    if (cpu.terminate) return;
    // 0041fe27  8d5f78                 -lea ebx, [edi + 0x78]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(120) /* 0x78 */);
    // 0041fe2a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041fe2c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0041fe2e  e8592d0600             -call 0x482b8c
    cpu.esp -= 4;
    sub_482b8c(app, cpu);
    if (cpu.terminate) return;
    // 0041fe33  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041fe37  c6470e00               -mov byte ptr [edi + 0xe], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 0041fe3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fe3d  0f8403ffffff           -je 0x41fd46
    if (cpu.flags.zf)
    {
        goto L_0x0041fd46;
    }
    // 0041fe43  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041fe46  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0041fe48  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0041fe4a  e8b1170600             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0041fe4f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041fe53  8d8794000000           -lea eax, [edi + 0x94]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(148) /* 0x94 */);
    // 0041fe59  e8c6290600             -call 0x482824
    cpu.esp -= 4;
    sub_482824(app, cpu);
    if (cpu.terminate) return;
    // 0041fe5e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041fe62  ff00                   -inc dword ptr [eax]
    (app->getMemory<x86::reg32>(cpu.eax))++;
    // 0041fe64  833d4caf4c0003         +cmp dword ptr [0x4caf4c], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fe6b  0f8cd5feffff           -jl 0x41fd46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fd46;
    }
    // 0041fe71  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fe73  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0041fe76  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fe77  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041fe7b  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0041fe7d  8d5812                 -lea ebx, [eax + 0x12]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0041fe80  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041fe82  8d5004                 -lea edx, [eax + 4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041fe85  8a480d                 -mov cl, byte ptr [eax + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0041fe88  b8a0a24b00             -mov eax, 0x4ba2a0
    cpu.eax = 4956832 /*0x4ba2a0*/;
    // 0041fe8d  e812250600             -call 0x4823a4
    cpu.esp -= 4;
    sub_4823a4(app, cpu);
    if (cpu.terminate) return;
    // 0041fe92  e9affeffff             -jmp 0x41fd46
    goto L_0x0041fd46;
L_0x0041fe97:
    // 0041fe97  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0041fe99  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041fe9b  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0041fe9d  e80e010000             -call 0x41ffb0
    cpu.esp -= 4;
    sub_41ffb0(app, cpu);
    if (cpu.terminate) return;
    // 0041fea2  e99ffeffff             -jmp 0x41fd46
    goto L_0x0041fd46;
L_0x0041fea7:
    // 0041fea7  83c603                 +add esi, 3
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041feaa  e997feffff             -jmp 0x41fd46
    goto L_0x0041fd46;
L_0x0041feaf:
    // 0041feaf  80fafe                 +cmp dl, 0xfe
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041feb2  740d                   -je 0x41fec1
    if (cpu.flags.zf)
    {
        goto L_0x0041fec1;
    }
    // 0041feb4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041feb9  40                     -inc eax
    (cpu.eax)++;
    // 0041feba  01c6                   +add esi, eax
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
    // 0041febc  e985feffff             -jmp 0x41fd46
    goto L_0x0041fd46;
L_0x0041fec1:
    // 0041fec1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fec3  40                     -inc eax
    (cpu.eax)++;
    // 0041fec4  01c6                   +add esi, eax
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
    // 0041fec6  e97bfeffff             -jmp 0x41fd46
    goto L_0x0041fd46;
L_0x0041fecb:
    // 0041fecb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fecd  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0041fecf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041fed1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041fed3  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0041fed5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041fed8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fed9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041feda  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fedb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_41fee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fee2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041fee3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fee4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fee5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041fee7  833d4caf4c0002         +cmp dword ptr [0x4caf4c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041feee  7c18                   -jl 0x41ff08
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ff08;
    }
    // 0041fef0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fef2  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0041fef5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fef6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fef8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041fefa  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041fefc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fefe  b868a24b00             -mov eax, 0x4ba268
    cpu.eax = 4956776 /*0x4ba268*/;
    // 0041ff03  e89c240600             -call 0x4823a4
    cpu.esp -= 4;
    sub_4823a4(app, cpu);
    if (cpu.terminate) return;
L_0x0041ff08:
    // 0041ff08  b8fcdc5100             -mov eax, 0x51dcfc
    cpu.eax = 5364988 /*0x51dcfc*/;
    // 0041ff0d  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0041ff0f  e884290600             -call 0x482898
    cpu.esp -= 4;
    sub_482898(app, cpu);
    if (cpu.terminate) return;
    // 0041ff14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ff16  746e                   -je 0x41ff86
    if (cpu.flags.zf)
    {
        goto L_0x0041ff86;
    }
    // 0041ff18  8b1d4caf4c00           -mov ebx, dword ptr [0x4caf4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
    // 0041ff1e  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 0041ff20  83fb01                 +cmp ebx, 1
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
    // 0041ff23  7c18                   -jl 0x41ff3d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ff3d;
    }
    // 0041ff25  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ff27  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0041ff2a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ff2b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041ff2d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041ff2f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ff31  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041ff33  b878a24b00             -mov eax, 0x4ba278
    cpu.eax = 4956792 /*0x4ba278*/;
    // 0041ff38  e867240600             -call 0x4823a4
    cpu.esp -= 4;
    sub_4823a4(app, cpu);
    if (cpu.terminate) return;
L_0x0041ff3d:
    // 0041ff3d  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0041ff44  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0041ff47  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041ff49  ff5204                 -call dword ptr [edx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0041ff4c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041ff4e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041ff50  ff5618                 -call dword ptr [esi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0041ff53  b8e0dc5100             -mov eax, 0x51dce0
    cpu.eax = 5364960 /*0x51dce0*/;
    // 0041ff58  e8a3270600             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0041ff5d  833d4caf4c0002         +cmp dword ptr [0x4caf4c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ff64  7d06                   -jge 0x41ff6c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041ff6c;
    }
L_0x0041ff66:
    // 0041ff66  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff68  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff6a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ff6c:
    // 0041ff6c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ff6e  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0041ff71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ff72  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041ff74  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041ff76  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ff78  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0041ff7a  b884a24b00             -mov eax, 0x4ba284
    cpu.eax = 4956804 /*0x4ba284*/;
    // 0041ff7f  e820240600             -call 0x4823a4
    cpu.esp -= 4;
    sub_4823a4(app, cpu);
    if (cpu.terminate) return;
    // 0041ff84  ebe0                   -jmp 0x41ff66
    goto L_0x0041ff66;
L_0x0041ff86:
    // 0041ff86  833d4caf4c0001         +cmp dword ptr [0x4caf4c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ff8d  7cd7                   -jl 0x41ff66
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ff66;
    }
    // 0041ff8f  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0041ff92  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ff93  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041ff95  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041ff97  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041ff99  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041ff9b  b890a24b00             -mov eax, 0x4ba290
    cpu.eax = 4956816 /*0x4ba290*/;
    // 0041ffa0  e8ff230600             -call 0x4823a4
    cpu.esp -= 4;
    sub_4823a4(app, cpu);
    if (cpu.terminate) return;
    // 0041ffa5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffa6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffa7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffa8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffa9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffaa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_41ffb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ffb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ffb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ffb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ffb3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041ffb4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ffb7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041ffb9  8d4854                 -lea ecx, [eax + 0x54]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 0041ffbc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041ffbe  e87d290600             -call 0x482940
    cpu.esp -= 4;
    sub_482940(app, cpu);
    if (cpu.terminate) return;
    // 0041ffc3  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 0041ffc8  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0041ffce  e89d040000             -call 0x420470
    cpu.esp -= 4;
    sub_420470(app, cpu);
    if (cpu.terminate) return;
    // 0041ffd3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0041ffd6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041ffd8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041ffda  e8592a0600             -call 0x482a38
    cpu.esp -= 4;
    sub_482a38(app, cpu);
    if (cpu.terminate) return;
    // 0041ffdf  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041ffe1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ffe3  7410                   -je 0x41fff5
    if (cpu.flags.zf)
    {
        goto L_0x0041fff5;
    }
    // 0041ffe5  833d4caf4c0003         +cmp dword ptr [0x4caf4c], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ffec  7d0f                   -jge 0x41fffd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041fffd;
    }
    // 0041ffee  c7470800000000         -mov dword ptr [edi + 8], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x0041fff5:
    // 0041fff5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fff8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fff9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fffa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fffb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fffc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fffd:
    // 0041fffd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ffff  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 00420002  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420003  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00420007  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00420009  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042000b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042000d  b860a24b00             -mov eax, 0x4ba260
    cpu.eax = 4956768 /*0x4ba260*/;
    // 00420012  e88d230600             -call 0x4823a4
    cpu.esp -= 4;
    sub_4823a4(app, cpu);
    if (cpu.terminate) return;
    // 00420017  c7470800000000         -mov dword ptr [edi + 8], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0042001e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420021  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420022  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420023  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420024  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420025  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420032  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420033  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420034  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420037  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00420039  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 0042003e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00420044  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00420047  e824040000             -call 0x420470
    cpu.esp -= 4;
    sub_420470(app, cpu);
    if (cpu.terminate) return;
    // 0042004c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0042004f  3b4630                 +cmp eax, dword ptr [esi + 0x30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420052  7349                   -jae 0x42009d
    if (!cpu.flags.cf)
    {
        goto L_0x0042009d;
    }
    // 00420054  3b4634                 +cmp eax, dword ptr [esi + 0x34]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420057  7644                   -jbe 0x42009d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042009d;
    }
    // 00420059  8b3d4caf4c00           -mov edi, dword ptr [0x4caf4c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
    // 0042005f  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00420062  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420065  7d1a                   -jge 0x420081
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00420081;
    }
L_0x00420067:
    // 00420067  8d5e38                 -lea ebx, [esi + 0x38]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0042006a  8d4e54                 -lea ecx, [esi + 0x54]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(84) /* 0x54 */);
L_0x0042006d:
    // 0042006d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042006f  e8cc280600             -call 0x482940
    cpu.esp -= 4;
    sub_482940(app, cpu);
    if (cpu.terminate) return;
    // 00420074  3b4634                 +cmp eax, dword ptr [esi + 0x34]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420077  7649                   -jbe 0x4200c2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004200c2;
    }
L_0x00420079:
    // 00420079  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042007c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042007d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042007e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042007f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420080  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420081:
    // 00420081  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420083  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 00420086  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420087  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042008b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042008d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042008f  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00420091  b850a24b00             -mov eax, 0x4ba250
    cpu.eax = 4956752 /*0x4ba250*/;
    // 00420096  e809230600             -call 0x4823a4
    cpu.esp -= 4;
    sub_4823a4(app, cpu);
    if (cpu.terminate) return;
    // 0042009b  ebca                   -jmp 0x420067
    goto L_0x00420067;
L_0x0042009d:
    // 0042009d  833d4caf4c0003         +cmp dword ptr [0x4caf4c], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004200a4  7cc1                   -jl 0x420067
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420067;
    }
    // 004200a6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004200a8  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 004200ab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004200ac  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004200b0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004200b2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004200b4  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004200b6  b858a24b00             -mov eax, 0x4ba258
    cpu.eax = 4956760 /*0x4ba258*/;
    // 004200bb  e8e4220600             -call 0x4823a4
    cpu.esp -= 4;
    sub_4823a4(app, cpu);
    if (cpu.terminate) return;
    // 004200c0  eba5                   -jmp 0x420067
    goto L_0x00420067;
L_0x004200c2:
    // 004200c2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004200c4  e8b3260600             -call 0x48277c
    cpu.esp -= 4;
    sub_48277c(app, cpu);
    if (cpu.terminate) return;
    // 004200c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004200cb  74ac                   -je 0x420079
    if (cpu.flags.zf)
    {
        goto L_0x00420079;
    }
    // 004200cd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004200cf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004200d1  e82a260600             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 004200d6  eb95                   -jmp 0x42006d
    goto L_0x0042006d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4200e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004200e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004200e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004200e2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004200e4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004200e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004200e8  740d                   -je 0x4200f7
    if (cpu.flags.zf)
    {
        goto L_0x004200f7;
    }
    // 004200ea  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004200ed  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004200f0  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004200f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004200f5  7e08                   -jle 0x4200ff
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004200ff;
    }
L_0x004200f7:
    // 004200f7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004200fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004200fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004200fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004200ff:
    // 004200ff  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420100  833d4caf4c0003         +cmp dword ptr [0x4caf4c], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420107  7c1b                   -jl 0x420124
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420124;
    }
    // 00420109  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042010a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042010c  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0042010f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420110  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00420113  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00420115  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00420117  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00420119  b848a24b00             -mov eax, 0x4ba248
    cpu.eax = 4956744 /*0x4ba248*/;
    // 0042011e  e881220600             -call 0x4823a4
    cpu.esp -= 4;
    sub_4823a4(app, cpu);
    if (cpu.terminate) return;
    // 00420123  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00420124:
    // 00420124  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00420126  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00420129  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0042012c  83e37f                 -and ebx, 0x7f
    cpu.ebx &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0042012f  e80c000000             -call 0x420140
    cpu.esp -= 4;
    sub_420140(app, cpu);
    if (cpu.terminate) return;
    // 00420134  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420135  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420136  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420137  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420140  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420141  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420142  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420143  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420144  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420147  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420149  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042014b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0042014e  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00420150  c7400801000000         -mov dword ptr [eax + 8], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 00420157  8b6e04                 -mov ebp, dword ptr [esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042015a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042015c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042015e  ff550c                 -call dword ptr [ebp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420161  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420164  730a                   -jae 0x420170
    if (!cpu.flags.cf)
    {
        goto L_0x00420170;
    }
L_0x00420166:
    // 00420166  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420168  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042016b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042016c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042016d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042016e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042016f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420170:
    // 00420170  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00420172  e829020000             -call 0x4203a0
    cpu.esp -= 4;
    sub_4203a0(app, cpu);
    if (cpu.terminate) return;
    // 00420177  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0042017c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00420181  c6410cfe               -mov byte ptr [ecx + 0xc], 0xfe
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = 254 /*0xfe*/;
    // 00420185  8a2424                 -mov ah, byte ptr [esp]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp);
    // 00420188  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0042018d  88610e                 -mov byte ptr [ecx + 0xe], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.ah;
    // 00420190  8d690c                 -lea ebp, [ecx + 0xc]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00420193  88410f                 -mov byte ptr [ecx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 00420196  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00420198  c6410d00               -mov byte ptr [ecx + 0xd], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = 0 /*0x0*/;
    // 0042019c  e89f020000             -call 0x420440
    cpu.esp -= 4;
    sub_420440(app, cpu);
    if (cpu.terminate) return;
    // 004201a1  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004201a4  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004201a6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004201a8  ff5618                 -call dword ptr [esi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004201ab  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004201ae  7521                   -jne 0x4201d1
    if (!cpu.flags.zf)
    {
        goto L_0x004201d1;
    }
    // 004201b0  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004201b5:
    // 004201b5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004201b7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004201b9  74ab                   -je 0x420166
    if (cpu.flags.zf)
    {
        goto L_0x00420166;
    }
    // 004201bb  833c247f               +cmp dword ptr [esp], 0x7f
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004201bf  77a5                   -ja 0x420166
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00420166;
    }
    // 004201c1  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 004201c4  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004201c7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004201c9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004201cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004201cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004201ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004201cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004201d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004201d1:
    // 004201d1  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004201d3  ebe0                   -jmp 0x4201b5
    goto L_0x004201b5;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4201e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004201e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004201e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004201e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004201e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004201e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004201e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004201e7  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004201ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004201ec  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004201ee  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004201f0  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004201f2  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004201f5  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004201f8  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004201fb  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004201fe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420200  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00420202  8a560d                 -mov dl, byte ptr [esi + 0xd]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 00420205  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420208  83c206                 -add edx, 6
    (cpu.edx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0042020b  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0042020e  39d0                   +cmp eax, edx
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
    // 00420210  734a                   -jae 0x42025c
    if (!cpu.flags.cf)
    {
        goto L_0x0042025c;
    }
    // 00420212  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00420216  0f8cf8000000           -jl 0x420314
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420314;
    }
    // 0042021c  833d4caf4c0003         +cmp dword ptr [0x4caf4c], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420223  7c19                   -jl 0x42023e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042023e;
    }
    // 00420225  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420227  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0042022a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042022b  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042022e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00420230  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00420232  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00420234  b840a24b00             -mov eax, 0x4ba240
    cpu.eax = 4956736 /*0x4ba240*/;
L_0x00420239:
    // 00420239  e866210600             -call 0x4823a4
    cpu.esp -= 4;
    sub_4823a4(app, cpu);
    if (cpu.terminate) return;
L_0x0042023e:
    // 0042023e  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420242  0f84f2000000           -je 0x42033a
    if (cpu.flags.zf)
    {
        goto L_0x0042033a;
    }
    // 00420248  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0042024b  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0042024e  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00420251  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00420254  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00420256  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420257  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420258  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420259  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042025a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042025b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042025c:
    // 0042025c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042025e  e83d010000             -call 0x4203a0
    cpu.esp -= 4;
    sub_4203a0(app, cpu);
    if (cpu.terminate) return;
    // 00420263  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00420265  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420267  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0042026a  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0042026d  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00420270  88560f                 -mov byte ptr [esi + 0xf], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 00420273  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420275  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00420277  8a560d                 -mov dl, byte ptr [esi + 0xd]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0042027a  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042027d  83c206                 -add edx, 6
    (cpu.edx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00420280  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00420283  e8b8010000             -call 0x420440
    cpu.esp -= 4;
    sub_420440(app, cpu);
    if (cpu.terminate) return;
    // 00420288  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0042028b  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0042028e  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00420291  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00420294  ff5718                 -call dword ptr [edi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420297  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0042029a  39d0                   +cmp eax, edx
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
    // 0042029c  754f                   -jne 0x4202ed
    if (!cpu.flags.zf)
    {
        goto L_0x004202ed;
    }
    // 0042029e  833d4caf4c0003         +cmp dword ptr [0x4caf4c], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004202a5  7c24                   -jl 0x4202cb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004202cb;
    }
    // 004202a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004202a9  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004202ac  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004202af  8d5e12                 -lea ebx, [esi + 0x12]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 004202b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004202b3  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004202b6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004202b8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004202ba  8a4e0d                 -mov cl, byte ptr [esi + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 004202bd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004202bf  7c25                   -jl 0x4202e6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004202e6;
    }
    // 004202c1  b820a24b00             -mov eax, 0x4ba220
    cpu.eax = 4956704 /*0x4ba220*/;
L_0x004202c6:
    // 004202c6  e8d9200600             -call 0x4823a4
    cpu.esp -= 4;
    sub_4823a4(app, cpu);
    if (cpu.terminate) return;
L_0x004202cb:
    // 004202cb  c745f001000000         -mov dword ptr [ebp - 0x10], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 1 /*0x1*/;
    // 004202d2  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004202d5  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004202d8  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004202db  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004202de  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004202e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004202e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004202e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004202e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004202e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004202e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004202e6:
    // 004202e6  b818a24b00             -mov eax, 0x4ba218
    cpu.eax = 4956696 /*0x4ba218*/;
    // 004202eb  ebd9                   -jmp 0x4202c6
    goto L_0x004202c6;
L_0x004202ed:
    // 004202ed  833d4caf4c0001         +cmp dword ptr [0x4caf4c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004202f4  0f8c44ffffff           -jl 0x42023e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042023e;
    }
    // 004202fa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004202fc  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004202ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420300  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00420303  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00420305  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00420307  8d55ec                 -lea edx, [ebp - 0x14]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0042030a  b828a24b00             -mov eax, 0x4ba228
    cpu.eax = 4956712 /*0x4ba228*/;
    // 0042030f  e925ffffff             -jmp 0x420239
    goto L_0x00420239;
L_0x00420314:
    // 00420314  833d4caf4c0003         +cmp dword ptr [0x4caf4c], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042031b  0f8c1dffffff           -jl 0x42023e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042023e;
    }
    // 00420321  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420323  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 00420326  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420327  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0042032a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042032c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042032e  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00420330  b838a24b00             -mov eax, 0x4ba238
    cpu.eax = 4956728 /*0x4ba238*/;
    // 00420335  e9fffeffff             -jmp 0x420239
    goto L_0x00420239;
L_0x0042033a:
    // 0042033a  c7460801000000         -mov dword ptr [esi + 8], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 00420341  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00420344  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00420346  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420347  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420348  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420349  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042034a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042034b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_420350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420350  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420351  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420352  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420353  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00420355  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00420357  8d6812                 -lea ebp, [eax + 0x12]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0042035a  8b426c                 -mov eax, dword ptr [edx + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    // 0042035d  e866080600             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00420362  8b4230                 -mov eax, dword ptr [edx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 00420365  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00420368  895a30                 -mov dword ptr [edx + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0042036b  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0042036e  8b426c                 -mov eax, dword ptr [edx + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    // 00420371  e86a080600             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00420376  c74608ffffffff         -mov dword ptr [esi + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 0042037d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042037f  8a5604                 -mov dl, byte ptr [esi + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00420382  c6460cfe               -mov byte ptr [esi + 0xc], 0xfe
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = 254 /*0xfe*/;
    // 00420386  80e27f                 -and dl, 0x7f
    cpu.dl &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00420389  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042038b  88560e                 -mov byte ptr [esi + 0xe], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */) = cpu.dl;
    // 0042038e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00420390  884e0d                 -mov byte ptr [esi + 0xd], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.cl;
    // 00420393  e868120600             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00420398  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420399  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042039a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042039b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4203a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004203a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004203a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004203a2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004203a5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004203a7  83c078                 -add eax, 0x78
    (cpu.eax) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 004203aa  e891250600             -call 0x482940
    cpu.esp -= 4;
    sub_482940(app, cpu);
    if (cpu.terminate) return;
    // 004203af  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004203b2  83f8ff                 +cmp eax, -1
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
    // 004203b5  7422                   -je 0x4203d9
    if (cpu.flags.zf)
    {
        goto L_0x004203d9;
    }
L_0x004203b7:
    // 004203b7  48                     -dec eax
    (cpu.eax)--;
    // 004203b8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004203bb  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004203bd  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004203c0  8b0d4caf4c00           -mov ecx, dword ptr [0x4caf4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5025612) /* 0x4caf4c */);
    // 004203c6  89422c                 -mov dword ptr [edx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004203c9  83f903                 +cmp ecx, 3
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
    // 004203cc  7d10                   -jge 0x4203de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004203de;
    }
    // 004203ce  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004203d1  247f                   -and al, 0x7f
    cpu.al &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004203d3  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004203d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004203d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004203d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004203d9:
    // 004203d9  8b4274                 -mov eax, dword ptr [edx + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */);
    // 004203dc  ebd9                   -jmp 0x4203b7
    goto L_0x004203b7;
L_0x004203de:
    // 004203de  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004203df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004203e1  8a420d                 -mov al, byte ptr [edx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 004203e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004203e5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004203e7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004203e9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004203eb  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004203ef  b810a24b00             -mov eax, 0x4ba210
    cpu.eax = 4956688 /*0x4ba210*/;
    // 004203f4  e8ab1f0600             -call 0x4823a4
    cpu.esp -= 4;
    sub_4823a4(app, cpu);
    if (cpu.terminate) return;
    // 004203f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004203fa  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004203fd  247f                   -and al, 0x7f
    cpu.al &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004203ff  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420402  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420403  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420404  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420410  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420411  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420412  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420414  8a5804                 -mov bl, byte ptr [eax + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00420417  8a7805                 -mov bh, byte ptr [eax + 5]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0042041a  e821000000             -call 0x420440
    cpu.esp -= 4;
    sub_420440(app, cpu);
    if (cpu.terminate) return;
    // 0042041f  8b4102                 -mov eax, dword ptr [ecx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00420422  0fbfd3                 -movsx edx, bx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00420425  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00420428  39c2                   +cmp edx, eax
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
    // 0042042a  7508                   -jne 0x420434
    if (!cpu.flags.zf)
    {
        goto L_0x00420434;
    }
    // 0042042c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420431  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420432  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420433  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420434:
    // 00420434  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420436  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420437  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420438  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420440  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420441  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420443  c6400500               -mov byte ptr [eax + 5], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = 0 /*0x0*/;
    // 00420447  8a4005                 -mov al, byte ptr [eax + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0042044a  884104                 -mov byte ptr [ecx + 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0042044d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042044f  e80c540600             -call 0x485860
    cpu.esp -= 4;
    sub_485860(app, cpu);
    if (cpu.terminate) return;
    // 00420454  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00420456  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00420459  885105                 -mov byte ptr [ecx + 5], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 0042045c  884104                 -mov byte ptr [ecx + 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0042045f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420460  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420470  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420471  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420473  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00420475  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00420477  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00420479  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0042047b  39c8                   +cmp eax, ecx
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
    // 0042047d  7303                   -jae 0x420482
    if (!cpu.flags.cf)
    {
        goto L_0x00420482;
    }
    // 0042047f  43                     -inc ebx
    (cpu.ebx)++;
    // 00420480  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00420482:
    // 00420482  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420483  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420490  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420491  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00420493  833d24624d0000         +cmp dword ptr [0x4d6224], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042049a  7417                   -je 0x4204b3
    if (cpu.flags.zf)
    {
        goto L_0x004204b3;
    }
L_0x0042049c:
    // 0042049c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042049e  7c1a                   -jl 0x4204ba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004204ba;
    }
    // 004204a0  3b1510624d00           +cmp edx, dword ptr [0x4d6210]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5071376) /* 0x4d6210 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004204a6  7312                   -jae 0x4204ba
    if (!cpu.flags.cf)
    {
        goto L_0x004204ba;
    }
    // 004204a8  a124624d00             -mov eax, dword ptr [0x4d6224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */);
    // 004204ad  8b44d004               -mov eax, dword ptr [eax + edx*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edx * 8);
    // 004204b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004204b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004204b3:
    // 004204b3  e848080000             -call 0x420d00
    cpu.esp -= 4;
    sub_420d00(app, cpu);
    if (cpu.terminate) return;
    // 004204b8  ebe2                   -jmp 0x42049c
    goto L_0x0042049c;
L_0x004204ba:
    // 004204ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004204bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004204bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4204c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004204c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004204c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004204c2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004204c4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004204c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004204c8  745b                   -je 0x420525
    if (cpu.flags.zf)
    {
        goto L_0x00420525;
    }
    // 004204ca  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 004204ce  7516                   -jne 0x4204e6
    if (!cpu.flags.zf)
    {
        goto L_0x004204e6;
    }
    // 004204d0  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 004204d6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004204d8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004204db  c1e204                 +shl edx, 4
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
    // 004204de  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004204e0  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004204e3  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004204e6:
    // 004204e6  837e2800               +cmp dword ptr [esi + 0x28], 0
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
    // 004204ea  7516                   -jne 0x420502
    if (!cpu.flags.zf)
    {
        goto L_0x00420502;
    }
    // 004204ec  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 004204f2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004204f4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004204f7  c1e202                 +shl edx, 2
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
    // 004204fa  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004204fc  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004204ff  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x00420502:
    // 00420502  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 00420506  7516                   -jne 0x42051e
    if (!cpu.flags.zf)
    {
        goto L_0x0042051e;
    }
    // 00420508  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 0042050e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420510  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00420513  c1e202                 +shl edx, 2
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
    // 00420516  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00420518  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0042051b  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0042051e:
    // 0042051e  c7460806000000         -mov dword ptr [esi + 8], 6
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 6 /*0x6*/;
L_0x00420525:
    // 00420525  ba80494c00             -mov edx, 0x4c4980
    cpu.edx = 4999552 /*0x4c4980*/;
    // 0042052a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042052b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042052d  bb9c494c00             -mov ebx, 0x4c499c
    cpu.ebx = 4999580 /*0x4c499c*/;
    // 00420532  e8d1080600             -call 0x480e08
    cpu.esp -= 4;
    sub_480e08(app, cpu);
    if (cpu.terminate) return;
    // 00420537  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420538  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420539  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420540  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420541  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420543  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420545  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00420547  8b4934                 -mov ecx, dword ptr [ecx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0042054a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042054c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042054e  e835670600             -call 0x486c88
    cpu.esp -= 4;
    sub_486c88(app, cpu);
    if (cpu.terminate) return;
    // 00420553  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420554  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420560  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420561  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420563  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00420565  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00420567  8b4934                 -mov ecx, dword ptr [ecx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0042056a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042056c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042056e  e8856b0600             -call 0x4870f8
    cpu.esp -= 4;
    sub_4870f8(app, cpu);
    if (cpu.terminate) return;
    // 00420573  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00420575  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420577  7c04                   -jl 0x42057d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042057d;
    }
    // 00420579  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042057b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042057c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042057d:
    // 0042057d  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0042057f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420581  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420582  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420590  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00420593  e9f0690600             -jmp 0x486f88
    return sub_486f88(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4205a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004205a0  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004205a3  e9346a0600             -jmp 0x486fdc
    return sub_486fdc(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4205b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004205b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004205b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004205b2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004205b4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004205b6  833d2c624d0009         +cmp dword ptr [0x4d622c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004205bd  750f                   -jne 0x4205ce
    if (!cpu.flags.zf)
    {
        goto L_0x004205ce;
    }
    // 004205bf  833d98494c0000         +cmp dword ptr [0x4c4998], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999576) /* 0x4c4998 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004205c6  752a                   -jne 0x4205f2
    if (!cpu.flags.zf)
    {
        goto L_0x004205f2;
    }
L_0x004205c8:
    // 004205c8  8b4330                 -mov eax, dword ptr [ebx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 004205cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004205cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004205cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004205ce:
    // 004205ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004205cf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004205d0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004205d2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004205d4  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 004205d9  c7403000000000         -mov dword ptr [eax + 0x30], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 004205e0  8b3d00624d00           -mov edi, dword ptr [0x4d6200]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5071360) /* 0x4d6200 */);
    // 004205e6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004205e7  2eff150c744b00         -call dword ptr cs:[0x4b740c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944908) /* 0x4b740c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004205ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004205ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004205f0  ebd6                   -jmp 0x4205c8
    goto L_0x004205c8;
L_0x004205f2:
    // 004205f2  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004205f5  e88e690600             -call 0x486f88
    cpu.esp -= 4;
    sub_486f88(app, cpu);
    if (cpu.terminate) return;
    // 004205fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004205fc  74ca                   -je 0x4205c8
    if (cpu.flags.zf)
    {
        goto L_0x004205c8;
    }
    // 004205fe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420600  ff1598494c00           -call dword ptr [0x4c4998]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4999576) /* 0x4c4998 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420606  8b4330                 -mov eax, dword ptr [ebx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 00420609  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042060a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042060b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_420610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420610  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420611  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420612  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420614  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420616  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 0042061b  c7403000000000         -mov dword ptr [eax + 0x30], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00420622  8b1500624d00           -mov edx, dword ptr [0x4d6200]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5071360) /* 0x4d6200 */);
    // 00420628  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420629  2eff150c744b00         -call dword ptr cs:[0x4b740c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944908) /* 0x4b740c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420630  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420635  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420636  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420637  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420640  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420641  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420642  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420643  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420644  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420645  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00420647  a314624d00             -mov dword ptr [0x4d6214], eax
    app->getMemory<x86::reg32>(x86::reg32(5071380) /* 0x4d6214 */) = cpu.eax;
    // 0042064c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042064e  891598494c00           -mov dword ptr [0x4c4998], edx
    app->getMemory<x86::reg32>(x86::reg32(4999576) /* 0x4c4998 */) = cpu.edx;
    // 00420654  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420656  89152c624d00           -mov dword ptr [0x4d622c], edx
    app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */) = cpu.edx;
    // 0042065c  c74034ffffffff         -mov dword ptr [eax + 0x34], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 4294967295 /*0xffffffff*/;
    // 00420663  68f0614d00             -push 0x4d61f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5071344 /*0x4d61f0*/;
    cpu.esp -= 4;
    // 00420668  895030                 -mov dword ptr [eax + 0x30], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0042066b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00420670  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00420675  b870074200             -mov eax, 0x420770
    cpu.eax = 4327280 /*0x420770*/;
    // 0042067a  890d28624d00           -mov dword ptr [0x4d6228], ecx
    app->getMemory<x86::reg32>(x86::reg32(5071400) /* 0x4d6228 */) = cpu.ecx;
    // 00420680  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00420685  e8d6000600             -call 0x480760
    cpu.esp -= 4;
    sub_480760(app, cpu);
    if (cpu.terminate) return;
    // 0042068a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042068c  0f84b3000000           -je 0x420745
    if (cpu.flags.zf)
    {
        goto L_0x00420745;
    }
    // 00420692  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
L_0x00420697:
    // 00420697  833d28624d0000         +cmp dword ptr [0x4d6228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071400) /* 0x4d6228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042069e  7416                   -je 0x4206b6
    if (cpu.flags.zf)
    {
        goto L_0x004206b6;
    }
    // 004206a0  8b1d20a44c00           -mov ebx, dword ptr [0x4ca420]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 004206a6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004206a8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004206aa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004206ad  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004206af  e868010600             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 004206b4  ebe1                   -jmp 0x420697
    goto L_0x00420697;
L_0x004206b6:
    // 004206b6  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004206bb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004206bd:
    // 004206bd  8b2d28624d00           -mov ebp, dword ptr [0x4d6228]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5071400) /* 0x4d6228 */);
    // 004206c3  39e9                   +cmp ecx, ebp
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
    // 004206c5  752a                   -jne 0x4206f1
    if (!cpu.flags.zf)
    {
        goto L_0x004206f1;
    }
    // 004206c7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004206c9  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004206cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004206ce  7521                   -jne 0x4206f1
    if (!cpu.flags.zf)
    {
        goto L_0x004206f1;
    }
    // 004206d0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004206d2  e869950500             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 004206d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004206d9  7c16                   -jl 0x4206f1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004206f1;
    }
    // 004206db  8b2d20a44c00           -mov ebp, dword ptr [0x4ca420]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 004206e1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004206e3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004206e5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004206e8  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004206ea  e82d010600             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 004206ef  ebcc                   -jmp 0x4206bd
    goto L_0x004206bd;
L_0x004206f1:
    // 004206f1  833d28624d0000         +cmp dword ptr [0x4d6228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071400) /* 0x4d6228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004206f8  7540                   -jne 0x42073a
    if (!cpu.flags.zf)
    {
        goto L_0x0042073a;
    }
L_0x004206fa:
    // 004206fa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004206fc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004206fe  c7473000000000         -mov dword ptr [edi + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00420705  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 0042070a  8b0d00624d00           -mov ecx, dword ptr [0x4d6200]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5071360) /* 0x4d6200 */);
    // 00420710  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420711  2eff150c744b00         -call dword ptr cs:[0x4b740c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944908) /* 0x4b740c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00420718:
    // 00420718  837f3000               +cmp dword ptr [edi + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042071c  7413                   -je 0x420731
    if (cpu.flags.zf)
    {
        goto L_0x00420731;
    }
    // 0042071e  833d2c624d0009         +cmp dword ptr [0x4d622c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420725  750a                   -jne 0x420731
    if (!cpu.flags.zf)
    {
        goto L_0x00420731;
    }
    // 00420727  8b0d38624d00           -mov ecx, dword ptr [0x4d6238]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5071416) /* 0x4d6238 */);
    // 0042072d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042072f  7520                   -jne 0x420751
    if (!cpu.flags.zf)
    {
        goto L_0x00420751;
    }
L_0x00420731:
    // 00420731  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 00420734  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420735  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420736  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420737  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420738  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420739  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042073a:
    // 0042073a  833d2c624d0009         +cmp dword ptr [0x4d622c], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420741  75b7                   -jne 0x4206fa
    if (!cpu.flags.zf)
    {
        goto L_0x004206fa;
    }
    // 00420743  ebd3                   -jmp 0x420718
    goto L_0x00420718;
L_0x00420745:
    // 00420745  c7052c624d0001000000   -mov dword ptr [0x4d622c], 1
    app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */) = 1 /*0x1*/;
    // 0042074f  ebc7                   -jmp 0x420718
    goto L_0x00420718;
L_0x00420751:
    // 00420751  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00420756  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00420758  e837630600             -call 0x486a94
    cpu.esp -= 4;
    sub_486a94(app, cpu);
    if (cpu.terminate) return;
    // 0042075d  894734                 -mov dword ptr [edi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00420760  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 00420763  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420764  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420765  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420766  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420767  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420768  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420770  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420771  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00420774  a114624d00             -mov eax, dword ptr [0x4d6214]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071380) /* 0x4d6214 */);
    // 00420779  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 0042077c  e88f070000             -call 0x420f10
    cpu.esp -= 4;
    sub_420f10(app, cpu);
    if (cpu.terminate) return;
    // 00420781  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420783  0f84c4000000           -je 0x42084d
    if (cpu.flags.zf)
    {
        goto L_0x0042084d;
    }
    // 00420789  a114624d00             -mov eax, dword ptr [0x4d6214]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071380) /* 0x4d6214 */);
    // 0042078e  83786400               +cmp dword ptr [eax + 0x64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420792  0f8583000000           -jne 0x42081b
    if (!cpu.flags.zf)
    {
        goto L_0x0042081b;
    }
    // 00420798  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0042079d:
    // 0042079d  e82e080000             -call 0x420fd0
    cpu.esp -= 4;
    sub_420fd0(app, cpu);
    if (cpu.terminate) return;
    // 004207a2  a32c624d00             -mov dword ptr [0x4d622c], eax
    app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */) = cpu.eax;
    // 004207a7  833d2c624d0000         +cmp dword ptr [0x4d622c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004207ae  0f858f000000           -jne 0x420843
    if (!cpu.flags.zf)
    {
        goto L_0x00420843;
    }
    // 004207b4  c7052c624d0002000000   -mov dword ptr [0x4d622c], 2
    app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */) = 2 /*0x2*/;
    // 004207be  a114624d00             -mov eax, dword ptr [0x4d6214]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071380) /* 0x4d6214 */);
    // 004207c3  8b6864                 -mov ebp, dword ptr [eax + 0x64]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    // 004207c6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004207c8  7558                   -jne 0x420822
    if (!cpu.flags.zf)
    {
        goto L_0x00420822;
    }
L_0x004207ca:
    // 004207ca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004207cf:
    // 004207cf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004207d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004207d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004207d2  8b1514624d00           -mov edx, dword ptr [0x4d6214]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5071380) /* 0x4d6214 */);
    // 004207d8  894230                 -mov dword ptr [edx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004207db  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004207dd  a328624d00             -mov dword ptr [0x4d6228], eax
    app->getMemory<x86::reg32>(x86::reg32(5071400) /* 0x4d6228 */) = cpu.eax;
    // 004207e2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004207e4:
    // 004207e4  a114624d00             -mov eax, dword ptr [0x4d6214]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071380) /* 0x4d6214 */);
    // 004207e9  3b5830                 +cmp ebx, dword ptr [eax + 0x30]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004207ec  744d                   -je 0x42083b
    if (cpu.flags.zf)
    {
        goto L_0x0042083b;
    }
    // 004207ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004207ef  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004207f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004207f1  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004207f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004207f6  2eff15f0734b00         -call dword ptr cs:[0x4b73f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944880) /* 0x4b73f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004207fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004207ff  742e                   -je 0x42082f
    if (cpu.flags.zf)
    {
        goto L_0x0042082f;
    }
    // 00420801  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00420805  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420806  2eff153c744b00         -call dword ptr cs:[0x4b743c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944956) /* 0x4b743c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042080d  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00420811  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420812  2eff15d4734b00         -call dword ptr cs:[0x4b73d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944852) /* 0x4b73d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420819  ebc9                   -jmp 0x4207e4
    goto L_0x004207e4;
L_0x0042081b:
    // 0042081b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042081d  e97bffffff             -jmp 0x42079d
    goto L_0x0042079d;
L_0x00420822:
    // 00420822  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00420824  e837010000             -call 0x420960
    cpu.esp -= 4;
    sub_420960(app, cpu);
    if (cpu.terminate) return;
    // 00420829  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042082b  759d                   -jne 0x4207ca
    if (!cpu.flags.zf)
    {
        goto L_0x004207ca;
    }
    // 0042082d  eba0                   -jmp 0x4207cf
    goto L_0x004207cf;
L_0x0042082f:
    // 0042082f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420834  e8e3ff0500             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 00420839  eba9                   -jmp 0x4207e4
    goto L_0x004207e4;
L_0x0042083b:
    // 0042083b  e830000000             -call 0x420870
    cpu.esp -= 4;
    sub_420870(app, cpu);
    if (cpu.terminate) return;
    // 00420840  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420841  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420842  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00420843:
    // 00420843  e848080000             -call 0x421090
    cpu.esp -= 4;
    sub_421090(app, cpu);
    if (cpu.terminate) return;
    // 00420848  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042084b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042084c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042084d:
    // 0042084d  c7052c624d0002000080   -mov dword ptr [0x4d622c], 0x80000002
    app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */) = 2147483650 /*0x80000002*/;
    // 00420857  a314624d00             -mov dword ptr [0x4d6214], eax
    app->getMemory<x86::reg32>(x86::reg32(5071380) /* 0x4d6214 */) = cpu.eax;
    // 0042085c  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042085f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420860  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420870  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420871  8b1534624d00           -mov edx, dword ptr [0x4d6234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5071412) /* 0x4d6234 */);
    // 00420877  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00420879  7502                   -jne 0x42087d
    if (!cpu.flags.zf)
    {
        goto L_0x0042087d;
    }
    // 0042087b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042087c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042087d:
    // 0042087d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042087e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042087f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420881  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420883  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420884  bbb0a84b00             -mov ebx, 0x4ba8b0
    cpu.ebx = 4958384 /*0x4ba8b0*/;
    // 00420889  e8db590900             -call 0x4b6269
    cpu.esp -= 4;
    sub_4b6269(app, cpu);
    if (cpu.terminate) return;
    // 0042088e  891d58b34c00           -mov dword ptr [0x4cb358], ebx
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = cpu.ebx;
    // 00420894  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420895  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420896  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420897  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4208a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004208a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004208a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004208a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004208a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004208a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004208a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004208a6  bad4a74b00             -mov edx, 0x4ba7d4
    cpu.edx = 4958164 /*0x4ba7d4*/;
    // 004208ab  b9ba020000             -mov ecx, 0x2ba
    cpu.ecx = 698 /*0x2ba*/;
    // 004208b0  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 004208b5  b8a0a84b00             -mov eax, 0x4ba8a0
    cpu.eax = 4958368 /*0x4ba8a0*/;
    // 004208ba  bdd4a74b00             -mov ebp, 0x4ba7d4
    cpu.ebp = 4958164 /*0x4ba7d4*/;
    // 004208bf  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 004208c5  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 004208ca  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 004208d0  e853990500             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 004208d5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004208d7  c70018000000           -mov dword ptr [eax], 0x18
    app->getMemory<x86::reg32>(cpu.eax) = 24 /*0x18*/;
L_0x004208dd:
    // 004208dd  686ca84b00             -push 0x4ba86c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4958316 /*0x4ba86c*/;
    cpu.esp -= 4;
    // 004208e2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004208e3  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004208e5  8b3534624d00           -mov esi, dword ptr [0x4d6234]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5071412) /* 0x4d6234 */);
    // 004208eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004208ec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004208ee  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004208f0  e85c5a0900             -call 0x4b6351
    cpu.esp -= 4;
    sub_4b6351(app, cpu);
    if (cpu.terminate) return;
    // 004208f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004208f7  7535                   -jne 0x42092e
    if (!cpu.flags.zf)
    {
        goto L_0x0042092e;
    }
    // 004208f9  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004208fc  3b3b                   +cmp edi, dword ptr [ebx]
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
    // 004208fe  7641                   -jbe 0x420941
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420941;
    }
    // 00420900  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00420902  e8859d0500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00420907  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00420909  b8cd020000             -mov eax, 0x2cd
    cpu.eax = 717 /*0x2cd*/;
    // 0042090e  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 00420913  a37ca64c00             -mov dword ptr [0x4ca67c], eax
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.eax;
    // 00420918  b8a0a84b00             -mov eax, 0x4ba8a0
    cpu.eax = 4958368 /*0x4ba8a0*/;
    // 0042091d  892d78a64c00           -mov dword ptr [0x4ca678], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebp;
    // 00420923  e800990500             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00420928  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042092a  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0042092c  ebaf                   -jmp 0x4208dd
    goto L_0x004208dd;
L_0x0042092e:
    // 0042092e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00420930  e8579d0500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00420935  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0042093a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042093b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042093c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042093d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042093e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042093f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420940  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420941:
    // 00420941  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00420944  8b0403                 -mov eax, dword ptr [ebx + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00420947  a338624d00             -mov dword ptr [0x4d6238], eax
    app->getMemory<x86::reg32>(x86::reg32(5071416) /* 0x4d6238 */) = cpu.eax;
    // 0042094c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042094e  e8399d0500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00420953  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420955  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420956  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420957  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420958  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420959  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042095a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042095b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_420960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420961  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420962  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420963  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420964  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420965  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420967  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420969  740b                   -je 0x420976
    if (cpu.flags.zf)
    {
        goto L_0x00420976;
    }
    // 0042096b  833d30624d0000         +cmp dword ptr [0x4d6230], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071408) /* 0x4d6230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420972  7508                   -jne 0x42097c
    if (!cpu.flags.zf)
    {
        goto L_0x0042097c;
    }
    // 00420974  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00420976:
    // 00420976  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420977  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420978  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420979  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042097a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042097b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042097c:
    // 0042097c  bbd4a74b00             -mov ebx, 0x4ba7d4
    cpu.ebx = 4958164 /*0x4ba7d4*/;
    // 00420981  be97020000             -mov esi, 0x297
    cpu.esi = 663 /*0x297*/;
    // 00420986  ba70000000             -mov edx, 0x70
    cpu.edx = 112 /*0x70*/;
    // 0042098b  b88ca84b00             -mov eax, 0x4ba88c
    cpu.eax = 4958348 /*0x4ba88c*/;
    // 00420990  891d78a64c00           -mov dword ptr [0x4ca678], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebx;
    // 00420996  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 0042099b  89357ca64c00           -mov dword ptr [0x4ca67c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.esi;
    // 004209a1  e882980500             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 004209a6  bb70000000             -mov ebx, 0x70
    cpu.ebx = 112 /*0x70*/;
    // 004209ab  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004209ad  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004209af  e8fb880600             -call 0x4892af
    cpu.esp -= 4;
    sub_4892af(app, cpu);
    if (cpu.terminate) return;
    // 004209b4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004209b5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004209b7  c70670000000           -mov dword ptr [esi], 0x70
    app->getMemory<x86::reg32>(cpu.esi) = 112 /*0x70*/;
    // 004209bd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004209be  c7460401000000         -mov dword ptr [esi + 4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004209c5  6834624d00             -push 0x4d6234
    app->getMemory<x86::reg32>(cpu.esp-4) = 5071412 /*0x4d6234*/;
    cpu.esp -= 4;
    // 004209ca  8b3d30624d00           -mov edi, dword ptr [0x4d6230]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5071408) /* 0x4d6230 */);
    // 004209d0  c7461010000000         -mov dword ptr [esi + 0x10], 0x10
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 16 /*0x10*/;
    // 004209d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004209d8  c7462cb80b0000         -mov dword ptr [esi + 0x2c], 0xbb8
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 3000 /*0xbb8*/;
    // 004209df  e85b5a0900             -call 0x4b643f
    cpu.esp -= 4;
    sub_4b643f(app, cpu);
    if (cpu.terminate) return;
    // 004209e4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004209e6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004209e8  e89f9c0500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 004209ed  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004209ef  7c0b                   -jl 0x4209fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004209fc;
    }
    // 004209f1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004209f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004209f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004209f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004209f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004209fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004209fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004209fc:
    // 004209fc  c7052c624d000f000000   -mov dword ptr [0x4d622c], 0xf
    app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */) = 15 /*0xf*/;
    // 00420a06  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420a08  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420a09  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420a0a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420a0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420a0c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420a0d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_420a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420a10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420a11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420a12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420a13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420a14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420a15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420a16  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00420a18  8b1518624d00           -mov edx, dword ptr [0x4d6218]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */);
    // 00420a1e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00420a20  0f8598000000           -jne 0x420abe
    if (!cpu.flags.zf)
    {
        goto L_0x00420abe;
    }
L_0x00420a26:
    // 00420a26  bbd4a74b00             -mov ebx, 0x4ba7d4
    cpu.ebx = 4958164 /*0x4ba7d4*/;
    // 00420a2b  bf6a020000             -mov edi, 0x26a
    cpu.edi = 618 /*0x26a*/;
    // 00420a30  baf0000000             -mov edx, 0xf0
    cpu.edx = 240 /*0xf0*/;
    // 00420a35  b87ca84b00             -mov eax, 0x4ba87c
    cpu.eax = 4958332 /*0x4ba87c*/;
    // 00420a3a  891d78a64c00           -mov dword ptr [0x4ca678], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebx;
    // 00420a40  893d7ca64c00           -mov dword ptr [0x4ca67c], edi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.edi;
    // 00420a46  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 00420a4b  bfd4a74b00             -mov edi, 0x4ba7d4
    cpu.edi = 4958164 /*0x4ba7d4*/;
    // 00420a50  e8d3970500             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00420a55  a318624d00             -mov dword ptr [0x4d6218], eax
    app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */) = cpu.eax;
    // 00420a5a  c700f0000000           -mov dword ptr [eax], 0xf0
    app->getMemory<x86::reg32>(cpu.eax) = 240 /*0xf0*/;
L_0x00420a60:
    // 00420a60  8b2d18624d00           -mov ebp, dword ptr [0x4d6218]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */);
    // 00420a66  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420a67  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420a69  a11c624d00             -mov eax, dword ptr [0x4d621c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071388) /* 0x4d621c */);
    // 00420a6e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420a6f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420a70  8b1504624d00           -mov edx, dword ptr [0x4d6204]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5071364) /* 0x4d6204 */);
    // 00420a76  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420a77  e838580900             -call 0x4b62b4
    cpu.esp -= 4;
    sub_4b62b4(app, cpu);
    if (cpu.terminate) return;
    // 00420a7c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00420a7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420a80  7550                   -jne 0x420ad2
    if (!cpu.flags.zf)
    {
        goto L_0x00420ad2;
    }
    // 00420a82  a118624d00             -mov eax, dword ptr [0x4d6218]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */);
    // 00420a87  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00420a8a  3b08                   +cmp ecx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420a8c  7655                   -jbe 0x420ae3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420ae3;
    }
    // 00420a8e  e8f99b0500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00420a93  bd7f020000             -mov ebp, 0x27f
    cpu.ebp = 639 /*0x27f*/;
    // 00420a98  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 00420a9d  b87ca84b00             -mov eax, 0x4ba87c
    cpu.eax = 4958332 /*0x4ba87c*/;
    // 00420aa2  893d78a64c00           -mov dword ptr [0x4ca678], edi
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edi;
    // 00420aa8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00420aaa  892d7ca64c00           -mov dword ptr [0x4ca67c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebp;
    // 00420ab0  e873970500             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00420ab5  a318624d00             -mov dword ptr [0x4d6218], eax
    app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */) = cpu.eax;
    // 00420aba  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00420abc  eba2                   -jmp 0x420a60
    goto L_0x00420a60;
L_0x00420abe:
    // 00420abe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420ac0  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00420ac2  e8c59b0500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00420ac7  890d18624d00           -mov dword ptr [0x4d6218], ecx
    app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */) = cpu.ecx;
    // 00420acd  e954ffffff             -jmp 0x420a26
    goto L_0x00420a26;
L_0x00420ad2:
    // 00420ad2  a118624d00             -mov eax, dword ptr [0x4d6218]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */);
    // 00420ad7  e8b09b0500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00420adc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420ade  a318624d00             -mov dword ptr [0x4d6218], eax
    app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */) = cpu.eax;
L_0x00420ae3:
    // 00420ae3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420ae5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ae6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ae7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ae8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ae9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420aea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420aeb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_420af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420af0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420af1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420af2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420af3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420af4  81ec401f0000           -sub esp, 0x1f40
    (cpu.esp) -= x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 00420afa  bb401f0000             -mov ebx, 0x1f40
    cpu.ebx = 8000 /*0x1f40*/;
    // 00420aff  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00420b01  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420b03  e8a7870600             -call 0x4892af
    cpu.esp -= 4;
    sub_4892af(app, cpu);
    if (cpu.terminate) return;
    // 00420b08  686ca84b00             -push 0x4ba86c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4958316 /*0x4ba86c*/;
    cpu.esp -= 4;
    // 00420b0d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00420b11  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420b12  8b0d94494c00           -mov ecx, dword ptr [0x4c4994]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4999572) /* 0x4c4994 */);
    // 00420b18  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 00420b1d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420b1e  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00420b22  e8df570900             -call 0x4b6306
    cpu.esp -= 4;
    sub_4b6306(app, cpu);
    if (cpu.terminate) return;
    // 00420b27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420b29  7509                   -jne 0x420b34
    if (!cpu.flags.zf)
    {
        goto L_0x00420b34;
    }
    // 00420b2b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00420b2f  3b0424                 +cmp eax, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420b32  760d                   -jbe 0x420b41
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420b41;
    }
L_0x00420b34:
    // 00420b34  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420b36  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 00420b3c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b3d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b3e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420b41:
    // 00420b41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420b42  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00420b46  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00420b4a  8d503c                 -lea edx, [eax + 0x3c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 00420b4d  806220f8               -and byte ptr [edx + 0x20], 0xf8
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(32) /* 0x20 */) &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00420b51  686ca84b00             -push 0x4ba86c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4958316 /*0x4ba86c*/;
    cpu.esp -= 4;
    // 00420b56  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00420b5a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420b5b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420b5c  8b2d94494c00           -mov ebp, dword ptr [0x4c4994]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4999572) /* 0x4c4994 */);
    // 00420b62  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420b63  e8dc590900             -call 0x4b6544
    cpu.esp -= 4;
    sub_4b6544(app, cpu);
    if (cpu.terminate) return;
    // 00420b68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420b6a  7405                   -je 0x420b71
    if (cpu.flags.zf)
    {
        goto L_0x00420b71;
    }
    // 00420b6c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00420b71:
    // 00420b71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b72  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 00420b78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_420b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420b80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420b81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420b82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420b83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420b84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420b85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420b86  81ec401f0000           -sub esp, 0x1f40
    (cpu.esp) -= x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 00420b8c  bb401f0000             -mov ebx, 0x1f40
    cpu.ebx = 8000 /*0x1f40*/;
    // 00420b91  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00420b93  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420b95  e815870600             -call 0x4892af
    cpu.esp -= 4;
    sub_4892af(app, cpu);
    if (cpu.terminate) return;
    // 00420b9a  686ca84b00             -push 0x4ba86c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4958316 /*0x4ba86c*/;
    cpu.esp -= 4;
    // 00420b9f  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00420ba3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420ba4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00420ba6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420ba8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420baa  8b0d30624d00           -mov ecx, dword ptr [0x4d6230]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5071408) /* 0x4d6230 */);
    // 00420bb0  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 00420bb5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420bb6  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00420bba  e892570900             -call 0x4b6351
    cpu.esp -= 4;
    sub_4b6351(app, cpu);
    if (cpu.terminate) return;
    // 00420bbf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420bc1  740f                   -je 0x420bd2
    if (cpu.flags.zf)
    {
        goto L_0x00420bd2;
    }
L_0x00420bc3:
    // 00420bc3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420bc5  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 00420bcb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420bcc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420bcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420bce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420bcf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420bd0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420bd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420bd2:
    // 00420bd2  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00420bd4  035c2414               -add ebx, dword ptr [esp + 0x14]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00420bd8  ba00100000             -mov edx, 0x1000
    cpu.edx = 4096 /*0x1000*/;
    // 00420bdd  68f0514d00             -push 0x4d51f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5067248 /*0x4d51f0*/;
    cpu.esp -= 4;
    // 00420be2  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 00420be4  bf2ef53ce7             -mov edi, 0xe73cf52e
    cpu.edi = 3879531822 /*0xe73cf52e*/;
    // 00420be9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420bea  668915f0514d00         -mov word ptr [0x4d51f0], dx
    app->getMemory<x86::reg16>(x86::reg32(5067248) /* 0x4d51f0 */) = cpu.dx;
    // 00420bf1  893d24524d00           -mov dword ptr [0x4d5224], edi
    app->getMemory<x86::reg32>(x86::reg32(5067300) /* 0x4d5224 */) = cpu.edi;
    // 00420bf7  2eff15a8744b00         -call dword ptr cs:[0x4b74a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945064) /* 0x4b74a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420bfe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00420c00  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00420c02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420c03  2eff1550744b00         -call dword ptr cs:[0x4b7450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944976) /* 0x4b7450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420c0a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00420c0c  74b5                   -je 0x420bc3
    if (cpu.flags.zf)
    {
        goto L_0x00420bc3;
    }
    // 00420c0e  b8f0514d00             -mov eax, 0x4d51f0
    cpu.eax = 5067248 /*0x4d51f0*/;
    // 00420c13  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00420c16  a308624d00             -mov dword ptr [0x4d6208], eax
    app->getMemory<x86::reg32>(x86::reg32(5071368) /* 0x4d6208 */) = cpu.eax;
    // 00420c1b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420c20  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 00420c26  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_420c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420c30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420c31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420c32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420c33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420c34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420c35  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00420c38  8b1594494c00           -mov edx, dword ptr [0x4c4994]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999572) /* 0x4c4994 */);
    // 00420c3e  83faff                 +cmp edx, -1
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
    // 00420c41  750b                   -jne 0x420c4e
    if (!cpu.flags.zf)
    {
        goto L_0x00420c4e;
    }
L_0x00420c43:
    // 00420c43  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420c45  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00420c48  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c4a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420c4e:
    // 00420c4e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00420c50  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420c51  681c624d00             -push 0x4d621c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5071388 /*0x4d621c*/;
    cpu.esp -= 4;
    // 00420c56  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 00420c5b  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 00420c60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420c61  8b1d04624d00           -mov ebx, dword ptr [0x4d6204]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5071364) /* 0x4d6204 */);
    // 00420c67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420c68  e824580900             -call 0x4b6491
    cpu.esp -= 4;
    sub_4b6491(app, cpu);
    if (cpu.terminate) return;
    // 00420c6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420c6f  75d2                   -jne 0x420c43
    if (!cpu.flags.zf)
    {
        goto L_0x00420c43;
    }
    // 00420c71  a194494c00             -mov eax, dword ptr [0x4c4994]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999572) /* 0x4c4994 */);
    // 00420c76  e895fdffff             -call 0x420a10
    cpu.esp -= 4;
    sub_420a10(app, cpu);
    if (cpu.terminate) return;
    // 00420c7b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420c7d  75c4                   -jne 0x420c43
    if (!cpu.flags.zf)
    {
        goto L_0x00420c43;
    }
    // 00420c7f  833d0c624d0000         +cmp dword ptr [0x4d620c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071372) /* 0x4d620c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420c86  746b                   -je 0x420cf3
    if (cpu.flags.zf)
    {
        goto L_0x00420cf3;
    }
    // 00420c88  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x00420c8d:
    // 00420c8d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420c8f  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00420c91  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420c92  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420c94  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420c96  8b3d1c624d00           -mov edi, dword ptr [0x4d621c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5071388) /* 0x4d621c */);
    // 00420c9c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420c9d  6830624d00             -push 0x4d6230
    app->getMemory<x86::reg32>(cpu.esp-4) = 5071408 /*0x4d6230*/;
    cpu.esp -= 4;
    // 00420ca2  8b2d94494c00           -mov ebp, dword ptr [0x4c4994]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4999572) /* 0x4c4994 */);
    // 00420ca8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420ca9  a104624d00             -mov eax, dword ptr [0x4d6204]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071364) /* 0x4d6204 */);
    // 00420cae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420caf  e832580900             -call 0x4b64e6
    cpu.esp -= 4;
    sub_4b64e6(app, cpu);
    if (cpu.terminate) return;
    // 00420cb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420cb6  758b                   -jne 0x420c43
    if (!cpu.flags.zf)
    {
        goto L_0x00420c43;
    }
    // 00420cb8  833d08624d0000         +cmp dword ptr [0x4d6208], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071368) /* 0x4d6208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420cbf  7424                   -je 0x420ce5
    if (cpu.flags.zf)
    {
        goto L_0x00420ce5;
    }
    // 00420cc1  a130624d00             -mov eax, dword ptr [0x4d6230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071408) /* 0x4d6230 */);
    // 00420cc6  e825feffff             -call 0x420af0
    cpu.esp -= 4;
    sub_420af0(app, cpu);
    if (cpu.terminate) return;
    // 00420ccb  a118624d00             -mov eax, dword ptr [0x4d6218]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */);
    // 00420cd0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420cd2  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 00420cd8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420cd9  8b1d30624d00           -mov ebx, dword ptr [0x4d6230]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5071408) /* 0x4d6230 */);
    // 00420cdf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420ce0  e8ae580900             -call 0x4b6593
    cpu.esp -= 4;
    sub_4b6593(app, cpu);
    if (cpu.terminate) return;
L_0x00420ce5:
    // 00420ce5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420cea  83c410                 +add esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00420ced  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420cee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420cef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420cf0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420cf1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420cf2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420cf3:
    // 00420cf3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420cf8  eb93                   -jmp 0x420c8d
    goto L_0x00420c8d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420d00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420d01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420d02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420d03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420d04  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00420d07  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420d09  6afa                   -push -6
    app->getMemory<x86::reg32>(cpu.esp-4) = -6 /*-0x6*/;
    cpu.esp -= 4;
    // 00420d0b  891510624d00           -mov dword ptr [0x4d6210], edx
    app->getMemory<x86::reg32>(x86::reg32(5071376) /* 0x4d6210 */) = cpu.edx;
    // 00420d11  e83a6a0600             -call 0x487750
    cpu.esp -= 4;
    sub_487750(app, cpu);
    if (cpu.terminate) return;
    // 00420d16  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420d17  2eff15f8734b00         -call dword ptr cs:[0x4b73f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944888) /* 0x4b73f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420d1e  6820624d00             -push 0x4d6220
    app->getMemory<x86::reg32>(cpu.esp-4) = 5071392 /*0x4d6220*/;
    cpu.esp -= 4;
    // 00420d23  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420d25  68f0114200             -push 0x4211f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4329968 /*0x4211f0*/;
    cpu.esp -= 4;
    // 00420d2a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420d2b  6804624d00             -push 0x4d6204
    app->getMemory<x86::reg32>(cpu.esp-4) = 5071364 /*0x4d6204*/;
    cpu.esp -= 4;
    // 00420d30  e8b8560900             -call 0x4b63ed
    cpu.esp -= 4;
    sub_4b63ed(app, cpu);
    if (cpu.terminate) return;
    // 00420d35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420d37  0f8505010000           -jne 0x420e42
    if (!cpu.flags.zf)
    {
        goto L_0x00420e42;
    }
    // 00420d3d  833d20624d0000         +cmp dword ptr [0x4d6220], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071392) /* 0x4d6220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420d44  0f84fc000000           -je 0x420e46
    if (cpu.flags.zf)
    {
        goto L_0x00420e46;
    }
    // 00420d4a  833d24624d0000         +cmp dword ptr [0x4d6224], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420d51  7433                   -je 0x420d86
    if (cpu.flags.zf)
    {
        goto L_0x00420d86;
    }
    // 00420d53  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00420d55:
    // 00420d55  a124624d00             -mov eax, dword ptr [0x4d6224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */);
    // 00420d5a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00420d5c  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00420d5f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00420d61  7407                   -je 0x420d6a
    if (cpu.flags.zf)
    {
        goto L_0x00420d6a;
    }
    // 00420d63  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00420d65  e822990500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x00420d6a:
    // 00420d6a  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00420d6d  81fea0000000           +cmp esi, 0xa0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420d73  75e0                   -jne 0x420d55
    if (!cpu.flags.zf)
    {
        goto L_0x00420d55;
    }
    // 00420d75  a124624d00             -mov eax, dword ptr [0x4d6224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */);
    // 00420d7a  e80d990500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00420d7f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420d81  a324624d00             -mov dword ptr [0x4d6224], eax
    app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */) = cpu.eax;
L_0x00420d86:
    // 00420d86  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420d87  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420d88  bad4a74b00             -mov edx, 0x4ba7d4
    cpu.edx = 4958164 /*0x4ba7d4*/;
    // 00420d8d  b9b7010000             -mov ecx, 0x1b7
    cpu.ecx = 439 /*0x1b7*/;
    // 00420d92  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 00420d97  b854a84b00             -mov eax, 0x4ba854
    cpu.eax = 4958292 /*0x4ba854*/;
    // 00420d9c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00420d9e  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 00420da4  baa0000000             -mov edx, 0xa0
    cpu.edx = 160 /*0xa0*/;
    // 00420da9  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 00420daf  e874940500             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00420db4  a324624d00             -mov dword ptr [0x4d6224], eax
    app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */) = cpu.eax;
    // 00420db9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00420dbb:
    // 00420dbb  a124624d00             -mov eax, dword ptr [0x4d6224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */);
    // 00420dc0  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00420dc3  895406fc               -mov dword ptr [esi + eax - 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.edx;
    // 00420dc7  895406f8               -mov dword ptr [esi + eax - 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1) = cpu.edx;
    // 00420dcb  81fea0000000           +cmp esi, 0xa0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420dd1  75e8                   -jne 0x420dbb
    if (!cpu.flags.zf)
    {
        goto L_0x00420dbb;
    }
    // 00420dd3  8b1d20624d00           -mov ebx, dword ptr [0x4d6220]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5071392) /* 0x4d6220 */);
    // 00420dd9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00420ddb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00420ddd  7630                   -jbe 0x420e0f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420e0f;
    }
L_0x00420ddf:
    // 00420ddf  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00420de3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420de4  681c624d00             -push 0x4d621c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5071388 /*0x4d621c*/;
    cpu.esp -= 4;
    // 00420de9  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 00420dee  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 00420df3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420df4  8b1504624d00           -mov edx, dword ptr [0x4d6204]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5071364) /* 0x4d6204 */);
    // 00420dfa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420dfb  e891560900             -call 0x4b6491
    cpu.esp -= 4;
    sub_4b6491(app, cpu);
    if (cpu.terminate) return;
    // 00420e00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420e02  746a                   -je 0x420e6e
    if (cpu.flags.zf)
    {
        goto L_0x00420e6e;
    }
L_0x00420e04:
    // 00420e04  8b3d20624d00           -mov edi, dword ptr [0x4d6220]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5071392) /* 0x4d6220 */);
    // 00420e0a  46                     -inc esi
    (cpu.esi)++;
    // 00420e0b  39fe                   +cmp esi, edi
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
    // 00420e0d  72d0                   -jb 0x420ddf
    if (cpu.flags.cf)
    {
        goto L_0x00420ddf;
    }
L_0x00420e0f:
    // 00420e0f  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 00420e14  e803fa0500             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 00420e19  8b2d04624d00           -mov ebp, dword ptr [0x4d6204]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5071364) /* 0x4d6204 */);
    // 00420e1f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420e20  e8b9570900             -call 0x4b65de
    cpu.esp -= 4;
    sub_4b65de(app, cpu);
    if (cpu.terminate) return;
    // 00420e25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420e27  740a                   -je 0x420e33
    if (cpu.flags.zf)
    {
        goto L_0x00420e33;
    }
    // 00420e29  c70558b34c00bca74b00   -mov dword ptr [0x4cb358], 0x4ba7bc
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = 4958140 /*0x4ba7bc*/;
L_0x00420e33:
    // 00420e33  a110624d00             -mov eax, dword ptr [0x4d6210]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071376) /* 0x4d6210 */);
    // 00420e38  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00420e3a:
    // 00420e3a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00420e3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e3e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420e42:
    // 00420e42  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00420e44  ebf4                   -jmp 0x420e3a
    goto L_0x00420e3a;
L_0x00420e46:
    // 00420e46  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 00420e4b  e8ccf90500             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 00420e50  8b3504624d00           -mov esi, dword ptr [0x4d6204]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5071364) /* 0x4d6204 */);
    // 00420e56  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420e57  e882570900             -call 0x4b65de
    cpu.esp -= 4;
    sub_4b65de(app, cpu);
    if (cpu.terminate) return;
    // 00420e5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420e5e  740a                   -je 0x420e6a
    if (cpu.flags.zf)
    {
        goto L_0x00420e6a;
    }
    // 00420e60  c70558b34c00bca74b00   -mov dword ptr [0x4cb358], 0x4ba7bc
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = 4958140 /*0x4ba7bc*/;
L_0x00420e6a:
    // 00420e6a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00420e6c  ebcc                   -jmp 0x420e3a
    goto L_0x00420e3a;
L_0x00420e6e:
    // 00420e6e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00420e70  e89bfbffff             -call 0x420a10
    cpu.esp -= 4;
    sub_420a10(app, cpu);
    if (cpu.terminate) return;
    // 00420e75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420e77  758b                   -jne 0x420e04
    if (!cpu.flags.zf)
    {
        goto L_0x00420e04;
    }
    // 00420e79  a118624d00             -mov eax, dword ptr [0x4d6218]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */);
    // 00420e7e  f6403c10               +test byte ptr [eax + 0x3c], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */) & 16 /*0x10*/));
    // 00420e82  7480                   -je 0x420e04
    if (cpu.flags.zf)
    {
        goto L_0x00420e04;
    }
    // 00420e84  b9d4a74b00             -mov ecx, 0x4ba7d4
    cpu.ecx = 4958164 /*0x4ba7d4*/;
    // 00420e89  bbcf010000             -mov ebx, 0x1cf
    cpu.ebx = 463 /*0x1cf*/;
    // 00420e8e  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00420e91  b860a84b00             -mov eax, 0x4ba860
    cpu.eax = 4958304 /*0x4ba860*/;
    // 00420e96  891d7ca64c00           -mov dword ptr [0x4ca67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebx;
    // 00420e9c  42                     -inc edx
    (cpu.edx)++;
    // 00420e9d  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 00420ea2  890d78a64c00           -mov dword ptr [0x4ca678], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ecx;
    // 00420ea8  e893930500             -call 0x47a240
    cpu.esp -= 4;
    sub_47a240(app, cpu);
    if (cpu.terminate) return;
    // 00420ead  8b0d10624d00           -mov ecx, dword ptr [0x4d6210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5071376) /* 0x4d6210 */);
    // 00420eb3  8b1524624d00           -mov edx, dword ptr [0x4d6224]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */);
    // 00420eb9  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 00420ebc  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00420ebe  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00420ec1  a118624d00             -mov eax, dword ptr [0x4d6218]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */);
    // 00420ec6  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00420ec9  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00420ecc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00420ece  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00420ed1  e8e6b00500             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 00420ed6  8b1510624d00           -mov edx, dword ptr [0x4d6210]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5071376) /* 0x4d6210 */);
    // 00420edc  a124624d00             -mov eax, dword ptr [0x4d6224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */);
    // 00420ee1  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00420ee4  8b0d18624d00           -mov ecx, dword ptr [0x4d6218]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */);
    // 00420eea  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00420eec  8b7920                 -mov edi, dword ptr [ecx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00420eef  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00420ef2  8b2d10624d00           -mov ebp, dword ptr [0x4d6210]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5071376) /* 0x4d6210 */);
    // 00420ef8  01fa                   +add edx, edi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00420efa  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00420efb  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00420efe  892d10624d00           -mov dword ptr [0x4d6210], ebp
    app->getMemory<x86::reg32>(x86::reg32(5071376) /* 0x4d6210 */) = cpu.ebp;
    // 00420f04  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 00420f06  e9f9feffff             -jmp 0x420e04
    goto L_0x00420e04;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420f10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420f11  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00420f13  833d24624d0000         +cmp dword ptr [0x4d6224], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420f1a  741c                   -je 0x420f38
    if (cpu.flags.zf)
    {
        goto L_0x00420f38;
    }
L_0x00420f1c:
    // 00420f1c  3b1510624d00           +cmp edx, dword ptr [0x4d6210]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5071376) /* 0x4d6210 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420f22  7d1b                   -jge 0x420f3f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00420f3f;
    }
    // 00420f24  a124624d00             -mov eax, dword ptr [0x4d6224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */);
    // 00420f29  8b04d0                 -mov eax, dword ptr [eax + edx*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 8);
    // 00420f2c  a394494c00             -mov dword ptr [0x4c4994], eax
    app->getMemory<x86::reg32>(x86::reg32(4999572) /* 0x4c4994 */) = cpu.eax;
    // 00420f31  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420f36  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420f38:
    // 00420f38  e8c3fdffff             -call 0x420d00
    cpu.esp -= 4;
    sub_420d00(app, cpu);
    if (cpu.terminate) return;
    // 00420f3d  ebdd                   -jmp 0x420f1c
    goto L_0x00420f1c;
L_0x00420f3f:
    // 00420f3f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420f40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420f41  bed4a74b00             -mov esi, 0x4ba7d4
    cpu.esi = 4958164 /*0x4ba7d4*/;
    // 00420f46  bf82010000             -mov edi, 0x182
    cpu.edi = 386 /*0x182*/;
    // 00420f4b  683ca84b00             -push 0x4ba83c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4958268 /*0x4ba83c*/;
    cpu.esp -= 4;
    // 00420f50  893578a64c00           -mov dword ptr [0x4ca678], esi
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.esi;
    // 00420f56  893d7ca64c00           -mov dword ptr [0x4ca67c], edi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.edi;
    // 00420f5c  e81f8f0500             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00420f61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420f64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420f66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f68  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420f70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420f71  6820624d00             -push 0x4d6220
    app->getMemory<x86::reg32>(cpu.esp-4) = 5071392 /*0x4d6220*/;
    cpu.esp -= 4;
    // 00420f76  89150c624d00           -mov dword ptr [0x4d620c], edx
    app->getMemory<x86::reg32>(x86::reg32(5071372) /* 0x4d620c */) = cpu.edx;
    // 00420f7c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420f7e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420f7f  68f0114200             -push 0x4211f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4329968 /*0x4211f0*/;
    cpu.esp -= 4;
    // 00420f84  891518624d00           -mov dword ptr [0x4d6218], edx
    app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */) = cpu.edx;
    // 00420f8a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420f8b  891538624d00           -mov dword ptr [0x4d6238], edx
    app->getMemory<x86::reg32>(x86::reg32(5071416) /* 0x4d6238 */) = cpu.edx;
    // 00420f91  891534624d00           -mov dword ptr [0x4d6234], edx
    app->getMemory<x86::reg32>(x86::reg32(5071412) /* 0x4d6234 */) = cpu.edx;
    // 00420f97  6804624d00             -push 0x4d6204
    app->getMemory<x86::reg32>(cpu.esp-4) = 5071364 /*0x4d6204*/;
    cpu.esp -= 4;
    // 00420f9c  891530624d00           -mov dword ptr [0x4d6230], edx
    app->getMemory<x86::reg32>(x86::reg32(5071408) /* 0x4d6230 */) = cpu.edx;
    // 00420fa2  891524624d00           -mov dword ptr [0x4d6224], edx
    app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */) = cpu.edx;
    // 00420fa8  e840540900             -call 0x4b63ed
    cpu.esp -= 4;
    sub_4b63ed(app, cpu);
    if (cpu.terminate) return;
    // 00420fad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420faf  7510                   -jne 0x420fc1
    if (!cpu.flags.zf)
    {
        goto L_0x00420fc1;
    }
    // 00420fb1  833d20624d0000         +cmp dword ptr [0x4d6220], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071392) /* 0x4d6220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420fb8  7505                   -jne 0x420fbf
    if (!cpu.flags.zf)
    {
        goto L_0x00420fbf;
    }
    // 00420fba  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
L_0x00420fbf:
    // 00420fbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420fc0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420fc1:
    // 00420fc1  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00420fc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420fc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420fd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420fd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420fd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420fd3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00420fd5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420fd7  89152c624d00           -mov dword ptr [0x4d622c], edx
    app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */) = cpu.edx;
    // 00420fdd  833d94494c00ff         +cmp dword ptr [0x4c4994], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999572) /* 0x4c4994 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420fe4  745b                   -je 0x421041
    if (cpu.flags.zf)
    {
        goto L_0x00421041;
    }
    // 00420fe6  6afa                   -push -6
    app->getMemory<x86::reg32>(cpu.esp-4) = -6 /*-0x6*/;
    cpu.esp -= 4;
    // 00420fe8  e863670600             -call 0x487750
    cpu.esp -= 4;
    sub_487750(app, cpu);
    if (cpu.terminate) return;
    // 00420fed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420fee  2eff15f8734b00         -call dword ptr cs:[0x4b73f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944888) /* 0x4b73f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420ff5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00420ffa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420ffc  e86fffffff             -call 0x420f70
    cpu.esp -= 4;
    sub_420f70(app, cpu);
    if (cpu.terminate) return;
    // 00421001  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00421003  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421005  7568                   -jne 0x42106f
    if (!cpu.flags.zf)
    {
        goto L_0x0042106f;
    }
    // 00421007  e824fcffff             -call 0x420c30
    cpu.esp -= 4;
    sub_420c30(app, cpu);
    if (cpu.terminate) return;
    // 0042100c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042100e  746a                   -je 0x42107a
    if (cpu.flags.zf)
    {
        goto L_0x0042107a;
    }
    // 00421010  e86bfbffff             -call 0x420b80
    cpu.esp -= 4;
    sub_420b80(app, cpu);
    if (cpu.terminate) return;
    // 00421015  e876000000             -call 0x421090
    cpu.esp -= 4;
    sub_421090(app, cpu);
    if (cpu.terminate) return;
    // 0042101a  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 0042101f  e8f8f70500             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 00421024  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00421026  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00421028  e843ffffff             -call 0x420f70
    cpu.esp -= 4;
    sub_420f70(app, cpu);
    if (cpu.terminate) return;
    // 0042102d  83f80a                 +cmp eax, 0xa
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
    // 00421030  7448                   -je 0x42107a
    if (cpu.flags.zf)
    {
        goto L_0x0042107a;
    }
    // 00421032  e8f9fbffff             -call 0x420c30
    cpu.esp -= 4;
    sub_420c30(app, cpu);
    if (cpu.terminate) return;
    // 00421037  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421039  7444                   -je 0x42107f
    if (cpu.flags.zf)
    {
        goto L_0x0042107f;
    }
    // 0042103b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042103d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042103e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042103f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421040  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421041:
    // 00421041  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421042  bbd4a74b00             -mov ebx, 0x4ba7d4
    cpu.ebx = 4958164 /*0x4ba7d4*/;
    // 00421047  be2f010000             -mov esi, 0x12f
    cpu.esi = 303 /*0x12f*/;
    // 0042104c  68f4a74b00             -push 0x4ba7f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4958196 /*0x4ba7f4*/;
    cpu.esp -= 4;
    // 00421051  891d78a64c00           -mov dword ptr [0x4ca678], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebx;
    // 00421057  89357ca64c00           -mov dword ptr [0x4ca67c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.esi;
    // 0042105d  e81e8e0500             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00421062  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00421067  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042106a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042106b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042106c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042106d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042106e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042106f:
    // 0042106f  e81c000000             -call 0x421090
    cpu.esp -= 4;
    sub_421090(app, cpu);
    if (cpu.terminate) return;
    // 00421074  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00421076  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421077  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421078  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421079  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042107a:
    // 0042107a  e811000000             -call 0x421090
    cpu.esp -= 4;
    sub_421090(app, cpu);
    if (cpu.terminate) return;
L_0x0042107f:
    // 0042107f  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00421084  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421085  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421086  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421087  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421090  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421091  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421092  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421093  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421094  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421095  b8e8030000             -mov eax, 0x3e8
    cpu.eax = 1000 /*0x3e8*/;
    // 0042109a  e87df70500             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 0042109f  8b1534624d00           -mov edx, dword ptr [0x4d6234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5071412) /* 0x4d6234 */);
    // 004210a5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004210a7  0f85c5000000           -jne 0x421172
    if (!cpu.flags.zf)
    {
        goto L_0x00421172;
    }
L_0x004210ad:
    // 004210ad  8b1d30624d00           -mov ebx, dword ptr [0x4d6230]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5071408) /* 0x4d6230 */);
    // 004210b3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004210b5  7414                   -je 0x4210cb
    if (cpu.flags.zf)
    {
        goto L_0x004210cb;
    }
    // 004210b7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004210b8  e826510900             -call 0x4b61e3
    cpu.esp -= 4;
    sub_4b61e3(app, cpu);
    if (cpu.terminate) return;
    // 004210bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004210bf  740a                   -je 0x4210cb
    if (cpu.flags.zf)
    {
        goto L_0x004210cb;
    }
    // 004210c1  c70558b34c0088a74b00   -mov dword ptr [0x4cb358], 0x4ba788
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = 4958088 /*0x4ba788*/;
L_0x004210cb:
    // 004210cb  8b2d14624d00           -mov ebp, dword ptr [0x4d6214]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5071380) /* 0x4d6214 */);
    // 004210d1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004210d3  0f84a4000000           -je 0x42117d
    if (cpu.flags.zf)
    {
        goto L_0x0042117d;
    }
    // 004210d9  8b5534                 -mov edx, dword ptr [ebp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 004210dc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004210de  83faff                 +cmp edx, -1
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
    // 004210e1  0f8496000000           -je 0x42117d
    if (cpu.flags.zf)
    {
        goto L_0x0042117d;
    }
    // 004210e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004210e9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004210eb  e8d0580600             -call 0x4869c0
    cpu.esp -= 4;
    sub_4869c0(app, cpu);
    if (cpu.terminate) return;
    // 004210f0  893d14624d00           -mov dword ptr [0x4d6214], edi
    app->getMemory<x86::reg32>(x86::reg32(5071380) /* 0x4d6214 */) = cpu.edi;
L_0x004210f6:
    // 004210f6  8b2d18624d00           -mov ebp, dword ptr [0x4d6218]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */);
    // 004210fc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004210fe  740e                   -je 0x42110e
    if (cpu.flags.zf)
    {
        goto L_0x0042110e;
    }
    // 00421100  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00421102  e885950500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00421107  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421109  a318624d00             -mov dword ptr [0x4d6218], eax
    app->getMemory<x86::reg32>(x86::reg32(5071384) /* 0x4d6218 */) = cpu.eax;
L_0x0042110e:
    // 0042110e  833d24624d0000         +cmp dword ptr [0x4d6224], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421115  7445                   -je 0x42115c
    if (cpu.flags.zf)
    {
        goto L_0x0042115c;
    }
    // 00421117  8b0d10624d00           -mov ecx, dword ptr [0x4d6210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5071376) /* 0x4d6210 */);
    // 0042111d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042111f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00421121  7e25                   -jle 0x421148
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00421148;
    }
    // 00421123  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00421125:
    // 00421125  a124624d00             -mov eax, dword ptr [0x4d6224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */);
    // 0042112a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042112c  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042112f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00421131  7407                   -je 0x42113a
    if (cpu.flags.zf)
    {
        goto L_0x0042113a;
    }
    // 00421133  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00421135  e852950500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x0042113a:
    // 0042113a  8b1d10624d00           -mov ebx, dword ptr [0x4d6210]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5071376) /* 0x4d6210 */);
    // 00421140  42                     -inc edx
    (cpu.edx)++;
    // 00421141  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421144  39da                   +cmp edx, ebx
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
    // 00421146  7cdd                   -jl 0x421125
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421125;
    }
L_0x00421148:
    // 00421148  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421149  a124624d00             -mov eax, dword ptr [0x4d6224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */);
    // 0042114e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00421150  e837950500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00421155  893524624d00           -mov dword ptr [0x4d6224], esi
    app->getMemory<x86::reg32>(x86::reg32(5071396) /* 0x4d6224 */) = cpu.esi;
    // 0042115b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042115c:
    // 0042115c  8b2d04624d00           -mov ebp, dword ptr [0x4d6204]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5071364) /* 0x4d6204 */);
    // 00421162  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421163  e876540900             -call 0x4b65de
    cpu.esp -= 4;
    sub_4b65de(app, cpu);
    if (cpu.terminate) return;
    // 00421168  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042116a  753e                   -jne 0x4211aa
    if (!cpu.flags.zf)
    {
        goto L_0x004211aa;
    }
    // 0042116c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042116d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042116e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042116f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421170  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421171  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421172:
    // 00421172  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421173  e8ae500900             -call 0x4b6226
    cpu.esp -= 4;
    sub_4b6226(app, cpu);
    if (cpu.terminate) return;
    // 00421178  e930ffffff             -jmp 0x4210ad
    goto L_0x004210ad;
L_0x0042117d:
    // 0042117d  8b0d38624d00           -mov ecx, dword ptr [0x4d6238]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5071416) /* 0x4d6238 */);
    // 00421183  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00421185  0f846bffffff           -je 0x4210f6
    if (cpu.flags.zf)
    {
        goto L_0x004210f6;
    }
    // 0042118b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042118c  2eff1550744b00         -call dword ptr cs:[0x4b7450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944976) /* 0x4b7450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421193  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421195  0f855bffffff           -jne 0x4210f6
    if (!cpu.flags.zf)
    {
        goto L_0x004210f6;
    }
    // 0042119b  c70558b34c009ca74b00   -mov dword ptr [0x4cb358], 0x4ba79c
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = 4958108 /*0x4ba79c*/;
    // 004211a5  e94cffffff             -jmp 0x4210f6
    goto L_0x004210f6;
L_0x004211aa:
    // 004211aa  c70558b34c00bca74b00   -mov dword ptr [0x4cb358], 0x4ba7bc
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = 4958140 /*0x4ba7bc*/;
    // 004211b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004211b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004211b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004211b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004211b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004211b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4211f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004211f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004211f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004211f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004211f3  83ec4c                 -sub esp, 0x4c
    (cpu.esp) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004211f6  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004211fa  8b5c2468               -mov ebx, dword ptr [esp + 0x68]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004211fe  8b74246c               -mov esi, dword ptr [esp + 0x6c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00421202  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 00421206  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00421209  83fa0b                 +cmp edx, 0xb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042120c  0f871d020000           -ja 0x42142f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042142f;
    }
    // 00421212  ff2495c0114200         -jmp dword ptr [edx*4 + 0x4211c0]
    cpu.ip = app->getMemory<x86::reg32>(4329920 + cpu.edx * 4); goto dynamic_jump;
  case 0x00421219:
    // 00421219  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042121a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042121b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042121c  b8e4a64b00             -mov eax, 0x4ba6e4
    cpu.eax = 4957924 /*0x4ba6e4*/;
    // 00421221  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421222  b83c624d00             -mov eax, 0x4d623c
    cpu.eax = 5071420 /*0x4d623c*/;
    // 00421227  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421228  be3c624d00             -mov esi, 0x4d623c
    cpu.esi = 5071420 /*0x4d623c*/;
    // 0042122d  2eff1548744b00         -call dword ptr cs:[0x4b7448]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944968) /* 0x4b7448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421234  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00421237  893558b34c00           -mov dword ptr [0x4cb358], esi
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = cpu.esi;
L_0x0042123d:
    // 0042123d  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00421240  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421241  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421242  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421243  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x00421246:
    // 00421246  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421247  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421248  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421249  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042124a  6880a64b00             -push 0x4ba680
    app->getMemory<x86::reg32>(cpu.esp-4) = 4957824 /*0x4ba680*/;
    cpu.esp -= 4;
    // 0042124f  683c624d00             -push 0x4d623c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5071420 /*0x4d623c*/;
    cpu.esp -= 4;
    // 00421254  2eff1548744b00         -call dword ptr cs:[0x4b7448]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944968) /* 0x4b7448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042125b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0042125e  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00421262  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421263  8b2d30624d00           -mov ebp, dword ptr [0x4d6230]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5071408) /* 0x4d6230 */);
    // 00421269  bf3c624d00             -mov edi, 0x4d623c
    cpu.edi = 5071420 /*0x4d623c*/;
    // 0042126e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042126f  893d58b34c00           -mov dword ptr [0x4cb358], edi
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = cpu.edi;
    // 00421275  e82c510900             -call 0x4b63a6
    cpu.esp -= 4;
    sub_4b63a6(app, cpu);
    if (cpu.terminate) return;
    // 0042127a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042127b  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0042127e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042127f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421280  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421281  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x00421284:
    // 00421284  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421285  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421286  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421287  68b4a64b00             -push 0x4ba6b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4957876 /*0x4ba6b4*/;
    cpu.esp -= 4;
    // 0042128c  683c624d00             -push 0x4d623c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5071420 /*0x4d623c*/;
    cpu.esp -= 4;
    // 00421291  2eff1548744b00         -call dword ptr cs:[0x4b7448]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944968) /* 0x4b7448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421298  b93c624d00             -mov ecx, 0x4d623c
    cpu.ecx = 5071420 /*0x4d623c*/;
    // 0042129d  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004212a0  890d58b34c00           -mov dword ptr [0x4cb358], ecx
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = cpu.ecx;
    // 004212a6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004212a8  7493                   -je 0x42123d
    if (cpu.flags.zf)
    {
        goto L_0x0042123d;
    }
    // 004212aa  c7052c624d000f000000   -mov dword ptr [0x4d622c], 0xf
    app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */) = 15 /*0xf*/;
    // 004212b4  c70528624d0001000000   -mov dword ptr [0x4d6228], 1
    app->getMemory<x86::reg32>(x86::reg32(5071400) /* 0x4d6228 */) = 1 /*0x1*/;
    // 004212be  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004212c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004212c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004212c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004212c4  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x004212c7:
    // 004212c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004212c8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004212c9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004212ca  6818a74b00             -push 0x4ba718
    app->getMemory<x86::reg32>(cpu.esp-4) = 4957976 /*0x4ba718*/;
    cpu.esp -= 4;
    // 004212cf  683c624d00             -push 0x4d623c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5071420 /*0x4d623c*/;
    cpu.esp -= 4;
    // 004212d4  2eff1548744b00         -call dword ptr cs:[0x4b7448]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944968) /* 0x4b7448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004212db  b83c624d00             -mov eax, 0x4d623c
    cpu.eax = 5071420 /*0x4d623c*/;
    // 004212e0  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004212e3  a358b34c00             -mov dword ptr [0x4cb358], eax
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = cpu.eax;
    // 004212e8  83fb10                 +cmp ebx, 0x10
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
    // 004212eb  732d                   -jae 0x42131a
    if (!cpu.flags.cf)
    {
        goto L_0x0042131a;
    }
    // 004212ed  83fb02                 +cmp ebx, 2
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
    // 004212f0  0f83a4000000           -jae 0x42139a
    if (!cpu.flags.cf)
    {
        goto L_0x0042139a;
    }
    // 004212f6  83fb01                 +cmp ebx, 1
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
    // 004212f9  0f853effffff           -jne 0x42123d
    if (!cpu.flags.zf)
    {
        goto L_0x0042123d;
    }
    // 004212ff  8b0d34624d00           -mov ecx, dword ptr [0x4d6234]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5071412) /* 0x4d6234 */);
    // 00421305  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421306  e81b4f0900             -call 0x4b6226
    cpu.esp -= 4;
    sub_4b6226(app, cpu);
    if (cpu.terminate) return;
    // 0042130b  891d28624d00           -mov dword ptr [0x4d6228], ebx
    app->getMemory<x86::reg32>(x86::reg32(5071400) /* 0x4d6228 */) = cpu.ebx;
    // 00421311  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421314  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421315  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421316  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421317  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0042131a:
    // 0042131a  0f861dffffff           -jbe 0x42123d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042123d;
    }
    // 00421320  81fb80000000           +cmp ebx, 0x80
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421326  7326                   -jae 0x42134e
    if (!cpu.flags.cf)
    {
        goto L_0x0042134e;
    }
    // 00421328  83fb40                 +cmp ebx, 0x40
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042132b  0f850cffffff           -jne 0x42123d
    if (!cpu.flags.zf)
    {
        goto L_0x0042123d;
    }
L_0x00421331:
    // 00421331  c7052c624d000c000000   -mov dword ptr [0x4d622c], 0xc
    app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */) = 12 /*0xc*/;
    // 0042133b  c70528624d0001000000   -mov dword ptr [0x4d6228], 1
    app->getMemory<x86::reg32>(x86::reg32(5071400) /* 0x4d6228 */) = 1 /*0x1*/;
    // 00421345  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421348  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421349  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042134a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042134b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0042134e:
    // 0042134e  0f86e9feffff           -jbe 0x42123d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042123d;
    }
    // 00421354  81fb00010000           +cmp ebx, 0x100
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042135a  0f82ddfeffff           -jb 0x42123d
    if (cpu.flags.cf)
    {
        goto L_0x0042123d;
    }
    // 00421360  765e                   -jbe 0x4213c0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004213c0;
    }
    // 00421362  81fb00400000           +cmp ebx, 0x4000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421368  0f85cffeffff           -jne 0x42123d
    if (!cpu.flags.zf)
    {
        goto L_0x0042123d;
    }
    // 0042136e  83fe08                 +cmp esi, 8
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
    // 00421371  7370                   -jae 0x4213e3
    if (!cpu.flags.cf)
    {
        goto L_0x004213e3;
    }
    // 00421373  83fe01                 +cmp esi, 1
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
    // 00421376  7205                   -jb 0x42137d
    if (cpu.flags.cf)
    {
        goto L_0x0042137d;
    }
    // 00421378  7603                   -jbe 0x42137d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042137d;
    }
    // 0042137a  83fe02                 -cmp esi, 2
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
L_0x0042137d:
    // 0042137d  c7052c624d000b000000   -mov dword ptr [0x4d622c], 0xb
    app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */) = 11 /*0xb*/;
    // 00421387  c70528624d0001000000   -mov dword ptr [0x4d6228], 1
    app->getMemory<x86::reg32>(x86::reg32(5071400) /* 0x4d6228 */) = 1 /*0x1*/;
    // 00421391  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421394  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421395  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421396  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421397  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0042139a:
    // 0042139a  0f879dfeffff           -ja 0x42123d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042123d;
    }
    // 004213a0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004213a2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004213a4  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004213a8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004213a9  e8ea4d0900             -call 0x4b6198
    cpu.esp -= 4;
    sub_4b6198(app, cpu);
    if (cpu.terminate) return;
    // 004213ae  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004213b2  a334624d00             -mov dword ptr [0x4d6234], eax
    app->getMemory<x86::reg32>(x86::reg32(5071412) /* 0x4d6234 */) = cpu.eax;
    // 004213b7  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004213ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004213bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004213bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004213bd  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004213c0:
    // 004213c0  be09000000             -mov esi, 9
    cpu.esi = 9 /*0x9*/;
    // 004213c5  e8d6f4ffff             -call 0x4208a0
    cpu.esp -= 4;
    sub_4208a0(app, cpu);
    if (cpu.terminate) return;
    // 004213ca  89352c624d00           -mov dword ptr [0x4d622c], esi
    app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */) = cpu.esi;
    // 004213d0  c70528624d0001000000   -mov dword ptr [0x4d6228], 1
    app->getMemory<x86::reg32>(x86::reg32(5071400) /* 0x4d6228 */) = 1 /*0x1*/;
    // 004213da  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004213dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004213de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004213df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004213e0  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004213e3:
    // 004213e3  762d                   -jbe 0x421412
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00421412;
    }
    // 004213e5  83fe20                 +cmp esi, 0x20
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
    // 004213e8  7293                   -jb 0x42137d
    if (cpu.flags.cf)
    {
        goto L_0x0042137d;
    }
    // 004213ea  0f8641ffffff           -jbe 0x421331
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00421331;
    }
    // 004213f0  83fe40                 +cmp esi, 0x40
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
    // 004213f3  7588                   -jne 0x42137d
    if (!cpu.flags.zf)
    {
        goto L_0x0042137d;
    }
    // 004213f5  c7052c624d000d000000   -mov dword ptr [0x4d622c], 0xd
    app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */) = 13 /*0xd*/;
    // 004213ff  c70528624d0001000000   -mov dword ptr [0x4d6228], 1
    app->getMemory<x86::reg32>(x86::reg32(5071400) /* 0x4d6228 */) = 1 /*0x1*/;
    // 00421409  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0042140c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042140d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042140e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042140f  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00421412:
    // 00421412  c7052c624d000e000000   -mov dword ptr [0x4d622c], 0xe
    app->getMemory<x86::reg32>(x86::reg32(5071404) /* 0x4d622c */) = 14 /*0xe*/;
    // 0042141c  c70528624d0001000000   -mov dword ptr [0x4d6228], 1
    app->getMemory<x86::reg32>(x86::reg32(5071400) /* 0x4d6228 */) = 1 /*0x1*/;
    // 00421426  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00421429  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042142a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042142b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042142c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x0042142f:
L_0x0042142f:
    // 0042142f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421430  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421431  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421432  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421433  684ca74b00             -push 0x4ba74c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4958028 /*0x4ba74c*/;
    cpu.esp -= 4;
    // 00421438  683c624d00             -push 0x4d623c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5071420 /*0x4d623c*/;
    cpu.esp -= 4;
    // 0042143d  2eff1548744b00         -call dword ptr cs:[0x4b7448]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944968) /* 0x4b7448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421444  ba3c624d00             -mov edx, 0x4d623c
    cpu.edx = 5071420 /*0x4d623c*/;
    // 00421449  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0042144c  891558b34c00           -mov dword ptr [0x4cb358], edx
    app->getMemory<x86::reg32>(x86::reg32(5026648) /* 0x4cb358 */) = cpu.edx;
    // 00421452  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00421455  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421456  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421457  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421458  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421460  81fa00470000           +cmp edx, 0x4700
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18176 /*0x4700*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421466  741d                   -je 0x421485
    if (cpu.flags.zf)
    {
        goto L_0x00421485;
    }
    // 00421468  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042146b  0f843f220000           -je 0x4236b0
    if (cpu.flags.zf)
    {
        return sub_4236b0(app, cpu);
    }
    // 00421471  81fa00530000           +cmp edx, 0x5300
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21248 /*0x5300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421477  0f8433220000           -je 0x4236b0
    if (cpu.flags.zf)
    {
        return sub_4236b0(app, cpu);
    }
    // 0042147d  f6c2ff                 +test dl, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 255 /*0xff*/));
    // 00421480  750e                   -jne 0x421490
    if (!cpu.flags.zf)
    {
        goto L_0x00421490;
    }
    // 00421482  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421484  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421485:
    // 00421485  e886240000             -call 0x423910
    cpu.esp -= 4;
    sub_423910(app, cpu);
    if (cpu.terminate) return;
    // 0042148a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042148f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421490:
    // 00421490  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00421496  e9d5220000             -jmp 0x423770
    return sub_423770(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4214a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004214a0  e9cb240000             -jmp 0x423970
    return sub_423970(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4214b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004214b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004214b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004214b2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004214b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004214b7  a12a074e00             -mov eax, dword ptr [0x4e072a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113642) /* 0x4e072a */);
    // 004214bc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004214bf  e85c000300             -call 0x451520
    cpu.esp -= 4;
    sub_451520(app, cpu);
    if (cpu.terminate) return;
    // 004214c4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004214c6  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004214c7  83f8ff                 +cmp eax, -1
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
    // 004214ca  7448                   -je 0x421514
    if (cpu.flags.zf)
    {
        goto L_0x00421514;
    }
    // 004214cc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004214ce  743c                   -je 0x42150c
    if (cpu.flags.zf)
    {
        goto L_0x0042150c;
    }
    // 004214d0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004214d2  0f84aa010000           -je 0x421682
    if (cpu.flags.zf)
    {
        goto L_0x00421682;
    }
    // 004214d8  83f908                 +cmp ecx, 8
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
    // 004214db  753b                   -jne 0x421518
    if (!cpu.flags.zf)
    {
        goto L_0x00421518;
    }
L_0x004214dd:
    // 004214dd  0fbfc3                 -movsx eax, bx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 004214e0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004214e2  e879ffffff             -call 0x421460
    cpu.esp -= 4;
    sub_421460(app, cpu);
    if (cpu.terminate) return;
    // 004214e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004214e9  741c                   -je 0x421507
    if (cpu.flags.zf)
    {
        goto L_0x00421507;
    }
    // 004214eb  b408                   -mov ah, 8
    cpu.ah = 8 /*0x8*/;
    // 004214ed  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004214ef  885c2401               -mov byte ptr [esp + 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004214f3  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004214f8  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 004214fb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004214fd  66894c2402             -mov word ptr [esp + 2], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.cx;
    // 00421502  e8c9020300             -call 0x4517d0
    cpu.esp -= 4;
    sub_4517d0(app, cpu);
    if (cpu.terminate) return;
L_0x00421507:
    // 00421507  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0042150c:
    // 0042150c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042150e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421511  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421512  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421513  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421514:
    // 00421514  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00421516  ebf4                   -jmp 0x42150c
    goto L_0x0042150c;
L_0x00421518:
    // 00421518  81f900530000           +cmp ecx, 0x5300
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21248 /*0x5300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042151e  74bd                   -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421520  81f900470000           +cmp ecx, 0x4700
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18176 /*0x4700*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421526  74b5                   -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421528  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042152b  7c05                   -jl 0x421532
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421532;
    }
    // 0042152d  83f922                 +cmp ecx, 0x22
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421530  7eab                   -jle 0x4214dd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004214dd;
    }
L_0x00421532:
    // 00421532  83f926                 +cmp ecx, 0x26
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421535  7c05                   -jl 0x42153c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042153c;
    }
    // 00421537  83f93b                 +cmp ecx, 0x3b
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(59 /*0x3b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042153a  7ea1                   -jle 0x4214dd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004214dd;
    }
L_0x0042153c:
    // 0042153c  83f93d                 +cmp ecx, 0x3d
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61 /*0x3d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042153f  749c                   -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421541  83f93f                 +cmp ecx, 0x3f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421544  7497                   -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421546  83f941                 +cmp ecx, 0x41
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65 /*0x41*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421549  7c05                   -jl 0x421550
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421550;
    }
    // 0042154b  83f97d                 +cmp ecx, 0x7d
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(125 /*0x7d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042154e  7e8d                   -jle 0x4214dd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004214dd;
    }
L_0x00421550:
    // 00421550  81f991000000           +cmp ecx, 0x91
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(145 /*0x91*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421556  7485                   -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421558  81f992000000           +cmp ecx, 0x92
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(146 /*0x92*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042155e  0f8479ffffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421564  81f9a1000000           +cmp ecx, 0xa1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(161 /*0xa1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042156a  0f846dffffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421570  81f9b0000000           +cmp ecx, 0xb0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(176 /*0xb0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421576  0f8461ffffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 0042157c  81f9bf000000           +cmp ecx, 0xbf
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(191 /*0xbf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421582  0f8455ffffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421588  81f9c1000000           +cmp ecx, 0xc1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(193 /*0xc1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042158e  0f8449ffffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421594  81f9e1000000           +cmp ecx, 0xe1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(225 /*0xe1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042159a  0f843dffffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 004215a0  81f9c4000000           +cmp ecx, 0xc4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(196 /*0xc4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004215a6  0f8431ffffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 004215ac  81f9e4000000           +cmp ecx, 0xe4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(228 /*0xe4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004215b2  0f8425ffffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 004215b8  81f9c7000000           +cmp ecx, 0xc7
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(199 /*0xc7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004215be  0f8419ffffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 004215c4  81f9e7000000           +cmp ecx, 0xe7
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(231 /*0xe7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004215ca  0f840dffffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 004215d0  81f9c9000000           +cmp ecx, 0xc9
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(201 /*0xc9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004215d6  0f8401ffffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 004215dc  81f9e9000000           +cmp ecx, 0xe9
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(233 /*0xe9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004215e2  0f84f5feffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 004215e8  81f9cd000000           +cmp ecx, 0xcd
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(205 /*0xcd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004215ee  0f84e9feffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 004215f4  81f9ed000000           +cmp ecx, 0xed
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(237 /*0xed*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004215fa  0f84ddfeffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421600  81f9d1000000           +cmp ecx, 0xd1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(209 /*0xd1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421606  0f84d1feffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 0042160c  81f9f1000000           +cmp ecx, 0xf1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(241 /*0xf1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421612  0f84c5feffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421618  81f9d3000000           +cmp ecx, 0xd3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(211 /*0xd3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042161e  0f84b9feffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421624  81f9f3000000           +cmp ecx, 0xf3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(243 /*0xf3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042162a  0f84adfeffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421630  81f9d6000000           +cmp ecx, 0xd6
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(214 /*0xd6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421636  0f84a1feffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 0042163c  81f9f6000000           +cmp ecx, 0xf6
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(246 /*0xf6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421642  0f8495feffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421648  81f9da000000           +cmp ecx, 0xda
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(218 /*0xda*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042164e  0f8489feffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421654  81f9fa000000           +cmp ecx, 0xfa
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(250 /*0xfa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042165a  0f847dfeffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421660  81f9dc000000           +cmp ecx, 0xdc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(220 /*0xdc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421666  0f8471feffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 0042166c  81f9fc000000           +cmp ecx, 0xfc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421672  0f8465feffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421678  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042167a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042167c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042167f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421680  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421681  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421682:
    // 00421682  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421685  0f8d52feffff           -jge 0x4214dd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004214dd;
    }
    // 0042168b  83f908                 +cmp ecx, 8
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
    // 0042168e  0f8449feffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 00421694  81f900530000           +cmp ecx, 0x5300
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21248 /*0x5300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042169a  0f843dfeffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 004216a0  81f900470000           +cmp ecx, 0x4700
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18176 /*0x4700*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004216a6  0f8431feffff           -je 0x4214dd
    if (cpu.flags.zf)
    {
        goto L_0x004214dd;
    }
    // 004216ac  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004216ae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004216b0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004216b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4216c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004216c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004216c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004216c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004216c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004216c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004216c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004216c6  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004216c9  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004216cd  803d7f074e0001         +cmp byte ptr [0x4e077f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004216d4  0f84b4000000           -je 0x42178e
    if (cpu.flags.zf)
    {
        goto L_0x0042178e;
    }
    // 004216da  c744242002000000       -mov dword ptr [esp + 0x20], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 2 /*0x2*/;
L_0x004216e2:
    // 004216e2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004216e4  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004216e8  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004216ec  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004216ee  0f8e90000000           -jle 0x421784
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00421784;
    }
    // 004216f4  bfa4014e00             -mov edi, 0x4e01a4
    cpu.edi = 5112228 /*0x4e01a4*/;
    // 004216f9  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004216fd  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00421701  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00421705  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
L_0x00421709:
    // 00421709  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042170d  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00421711  e86a1e0000             -call 0x423580
    cpu.esp -= 4;
    sub_423580(app, cpu);
    if (cpu.terminate) return;
    // 00421716  8bbf2c074e00           -mov edi, dword ptr [edi + 0x4e072c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5113644) /* 0x4e072c */);
    // 0042171c  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0042171f  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00421723  83ffff                 +cmp edi, -1
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
    // 00421726  7416                   -je 0x42173e
    if (cpu.flags.zf)
    {
        goto L_0x0042173e;
    }
    // 00421728  837c241800             +cmp dword ptr [esp + 0x18], 0
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
    // 0042172d  0f84bc000000           -je 0x4217ef
    if (cpu.flags.zf)
    {
        goto L_0x004217ef;
    }
    // 00421733  66833c7d68074e0000     +cmp word ptr [edi*2 + 0x4e0768], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113704) /* 0x4e0768 */ + cpu.edi * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042173c  745d                   -je 0x42179b
    if (cpu.flags.zf)
    {
        goto L_0x0042179b;
    }
L_0x0042173e:
    // 0042173e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00421742  e8c9210000             -call 0x423910
    cpu.esp -= 4;
    sub_423910(app, cpu);
    if (cpu.terminate) return;
L_0x00421747:
    // 00421747  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042174b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042174f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00421753  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00421757  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042175b  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042175f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00421762  83c509                 -add ebp, 9
    (cpu.ebp) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00421765  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421768  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042176b  41                     -inc ecx
    (cpu.ecx)++;
    // 0042176c  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00421770  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00421774  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00421778  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042177c  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00421780  39d9                   +cmp ecx, ebx
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
    // 00421782  7c85                   -jl 0x421709
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421709;
    }
L_0x00421784:
    // 00421784  83c42c                 +add esp, 0x2c
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
    // 00421787  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421788  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421789  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042178a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042178b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042178c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042178d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042178e:
    // 0042178e  c744242008000000       -mov dword ptr [esp + 0x20], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 8 /*0x8*/;
    // 00421796  e947ffffff             -jmp 0x4216e2
    goto L_0x004216e2;
L_0x0042179b:
    // 0042179b  837c242002             +cmp dword ptr [esp + 0x20], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004217a0  0f85be000000           -jne 0x421864
    if (!cpu.flags.zf)
    {
        goto L_0x00421864;
    }
    // 004217a6  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004217aa  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 004217af  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x004217b3:
    // 004217b3  8b9bbc494c00           -mov ebx, dword ptr [ebx + 0x4c49bc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4999612) /* 0x4c49bc */);
    // 004217b9  e8e27f0400             -call 0x4697a0
    cpu.esp -= 4;
    sub_4697a0(app, cpu);
    if (cpu.terminate) return;
    // 004217be  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004217c2  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 004217c7  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004217c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004217cb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004217cd  7e17                   -jle 0x4217e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004217e6;
    }
    // 004217cf  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004217d1  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
L_0x004217d5:
    // 004217d5  807e0400               +cmp byte ptr [esi + 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004217d9  7401                   -je 0x4217dc
    if (cpu.flags.zf)
    {
        goto L_0x004217dc;
    }
    // 004217db  47                     -inc edi
    (cpu.edi)++;
L_0x004217dc:
    // 004217dc  40                     -inc eax
    (cpu.eax)++;
    // 004217dd  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004217df  83c626                 -add esi, 0x26
    (cpu.esi) += x86::reg32(x86::sreg32(38 /*0x26*/));
    // 004217e2  39e8                   +cmp eax, ebp
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
    // 004217e4  7cef                   -jl 0x4217d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004217d5;
    }
L_0x004217e6:
    // 004217e6  83ff06                 +cmp edi, 6
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004217e9  0f8d8b000000           -jge 0x42187a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042187a;
    }
L_0x004217ef:
    // 004217ef  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004217f1:
    // 004217f1  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004217f5  3b38                   +cmp edi, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004217f7  0f8d4affffff           -jge 0x421747
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00421747;
    }
    // 004217fd  6bf726                 -imul esi, edi, 0x26
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(38 /*0x26*/)));
    // 00421800  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421803  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00421805  6bc714                 -imul eax, edi, 0x14
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(20 /*0x14*/)));
    // 00421808  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042180c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0042180f  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00421813  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00421815  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00421819  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x0042181d:
    // 0042181d  837c241800             +cmp dword ptr [esp + 0x18], 0
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
    // 00421822  7471                   -je 0x421895
    if (cpu.flags.zf)
    {
        goto L_0x00421895;
    }
    // 00421824  837c242002             +cmp dword ptr [esp + 0x20], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421829  7557                   -jne 0x421882
    if (!cpu.flags.zf)
    {
        goto L_0x00421882;
    }
    // 0042182b  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0042182e  ba8b000000             -mov edx, 0x8b
    cpu.edx = 139 /*0x8b*/;
    // 00421833  8b9bbc494c00           -mov ebx, dword ptr [ebx + 0x4c49bc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4999612) /* 0x4c49bc */);
    // 00421839  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042183b  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
L_0x0042183d:
    // 0042183d  e85e7f0400             -call 0x4697a0
    cpu.esp -= 4;
    sub_4697a0(app, cpu);
    if (cpu.terminate) return;
L_0x00421842:
    // 00421842  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00421846  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042184a  83c626                 -add esi, 0x26
    (cpu.esi) += x86::reg32(x86::sreg32(38 /*0x26*/));
    // 0042184d  47                     -inc edi
    (cpu.edi)++;
    // 0042184e  83c50f                 -add ebp, 0xf
    (cpu.ebp) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00421851  83c314                 -add ebx, 0x14
    (cpu.ebx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00421854  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421856  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0042185a  39cf                   +cmp edi, ecx
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
    // 0042185c  0f8de5feffff           -jge 0x421747
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00421747;
    }
    // 00421862  ebb9                   -jmp 0x42181d
    goto L_0x0042181d;
L_0x00421864:
    // 00421864  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00421868  8d04ff                 -lea eax, [edi + edi*8]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 8);
    // 0042186b  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 00421870  05a4014e00             +add eax, 0x4e01a4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5112228 /*0x4e01a4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421875  e939ffffff             -jmp 0x4217b3
    goto L_0x004217b3;
L_0x0042187a:
    // 0042187a  83ef05                 +sub edi, 5
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042187d  e96fffffff             -jmp 0x4217f1
    goto L_0x004217f1;
L_0x00421882:
    // 00421882  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00421886  ba8b000000             -mov edx, 0x8b
    cpu.edx = 139 /*0x8b*/;
    // 0042188b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042188d  8b9bbc494c00           -mov ebx, dword ptr [ebx + 0x4c49bc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4999612) /* 0x4c49bc */);
    // 00421893  eba8                   -jmp 0x42183d
    goto L_0x0042183d;
L_0x00421895:
    // 00421895  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00421899  83f802                 +cmp eax, 2
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
    // 0042189c  752d                   -jne 0x4218cb
    if (!cpu.flags.zf)
    {
        goto L_0x004218cb;
    }
    // 0042189e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042189f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004218a3  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004218a7  bafd000000             -mov edx, 0xfd
    cpu.edx = 253 /*0xfd*/;
    // 004218ac  668b80dc494c00         -mov ax, word ptr [eax + 0x4c49dc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4999644) /* 0x4c49dc */);
    // 004218b3  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004218b5  01c8                   +add eax, ecx
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
    // 004218b7  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004218bc  0fbfd8                 -movsx ebx, ax
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004218bf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004218c1  e8ca3bfeff             -call 0x405490
    cpu.esp -= 4;
    sub_405490(app, cpu);
    if (cpu.terminate) return;
    // 004218c6  e977ffffff             -jmp 0x421842
    goto L_0x00421842;
L_0x004218cb:
    // 004218cb  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004218cd  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004218d1  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004218d6  bafd000000             -mov edx, 0xfd
    cpu.edx = 253 /*0xfd*/;
    // 004218db  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004218dd  8b9bda494c00           -mov ebx, dword ptr [ebx + 0x4c49da]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4999642) /* 0x4c49da */);
    // 004218e3  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004218e5  c1fb10                 +sar ebx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004218e8  e8a33bfeff             -call 0x405490
    cpu.esp -= 4;
    sub_405490(app, cpu);
    if (cpu.terminate) return;
    // 004218ed  e950ffffff             -jmp 0x421842
    goto L_0x00421842;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421900  e99b200000             -jmp 0x4239a0
    return sub_4239a0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421910  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421911  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421912  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421913  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421914  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00421917  803d7f074e0001         +cmp byte ptr [0x4e077f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042191e  753f                   -jne 0x42195f
    if (!cpu.flags.zf)
    {
        goto L_0x0042195f;
    }
    // 00421920  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00421925  be25000000             -mov esi, 0x25
    cpu.esi = 37 /*0x25*/;
    // 0042192a  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0042192f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00421931  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00421935  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00421939  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0042193d  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00421941  897c2414               -mov dword ptr [esp + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 00421945  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00421949  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0042194d  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00421950  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00421952  e8a9200000             -call 0x423a00
    cpu.esp -= 4;
    sub_423a00(app, cpu);
    if (cpu.terminate) return;
    // 00421957  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0042195a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042195b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042195c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042195d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042195e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042195f:
    // 0042195f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421960  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00421965  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0042196a  bb25000000             -mov ebx, 0x25
    cpu.ebx = 37 /*0x25*/;
    // 0042196f  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00421974  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00421976  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042197a  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042197e  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00421982  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00421986  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0042198a  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0042198e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00421993  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00421997  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0042199b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042199c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0042199e  e85d200000             -call 0x423a00
    cpu.esp -= 4;
    sub_423a00(app, cpu);
    if (cpu.terminate) return;
    // 004219a3  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004219a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004219a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004219a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004219a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004219aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4219b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004219b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004219b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004219b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004219b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004219b4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004219b7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004219b9  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004219bb  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004219be  66833d78074e0000       +cmp word ptr [0x4e0778], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004219c6  744c                   -je 0x421a14
    if (cpu.flags.zf)
    {
        goto L_0x00421a14;
    }
    // 004219c8  803d7f074e0001         +cmp byte ptr [0x4e077f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004219cf  7543                   -jne 0x421a14
    if (!cpu.flags.zf)
    {
        goto L_0x00421a14;
    }
    // 004219d1  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 004219d6  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004219db:
    // 004219db  a128074e00             -mov eax, dword ptr [0x4e0728]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113640) /* 0x4e0728 */);
    // 004219e0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004219e3  39c1                   +cmp ecx, eax
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
    // 004219e5  7d2d                   -jge 0x421a14
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00421a14;
    }
    // 004219e7  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004219ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004219ec  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004219ef  8b04452c074e00         -mov eax, dword ptr [eax*2 + 0x4e072c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113644) /* 0x4e072c */ + cpu.eax * 2);
    // 004219f6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004219f9  39c1                   +cmp ecx, eax
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
    // 004219fb  7506                   -jne 0x421a03
    if (!cpu.flags.zf)
    {
        goto L_0x00421a03;
    }
L_0x004219fd:
    // 004219fd  41                     -inc ecx
    (cpu.ecx)++;
    // 004219fe  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a01  ebd8                   -jmp 0x4219db
    goto L_0x004219db;
L_0x00421a03:
    // 00421a03  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00421a05  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00421a07  8b86a0034e00           -mov eax, dword ptr [esi + 0x4e03a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5112736) /* 0x4e03a0 */);
    // 00421a0d  e8befd0200             -call 0x4517d0
    cpu.esp -= 4;
    sub_4517d0(app, cpu);
    if (cpu.terminate) return;
    // 00421a12  ebe9                   -jmp 0x4219fd
    goto L_0x004219fd;
L_0x00421a14:
    // 00421a14  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00421a17  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00421a1a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421a1c  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00421a1e  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00421a21  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00421a24  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00421a29  e832faffff             -call 0x421460
    cpu.esp -= 4;
    sub_421460(app, cpu);
    if (cpu.terminate) return;
    // 00421a2e  66891d54074e00         -mov word ptr [0x4e0754], bx
    app->getMemory<x86::reg16>(x86::reg32(5113684) /* 0x4e0754 */) = cpu.bx;
    // 00421a35  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421a38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421a39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421a3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421a3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421a3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_421a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421a40  b017                   -mov al, 0x17
    cpu.al = 23 /*0x17*/;
    // 00421a42  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a43  00c0                   -add al, al
    (cpu.al) += x86::reg8(x86::sreg8(cpu.al));
    // 00421a45  17                     -pop ss
    cpu.ss = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00421a46  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a47  00d0                   -add al, dl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.dl));
    // 00421a49  17                     -pop ss
    cpu.ss = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00421a4a  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a4b  00e0                   -add al, ah
    (cpu.al) += x86::reg8(x86::sreg8(cpu.ah));
    // 00421a4d  17                     -pop ss
    cpu.ss = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00421a4e  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a4f  00f0                   -add al, dh
    (cpu.al) += x86::reg8(x86::sreg8(cpu.dh));
    // 00421a51  17                     -pop ss
    cpu.ss = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00421a52  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a53  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a55  184d00                 +sbb byte ptr [ebp], cl
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl)) + cpu.flags.cf;
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a58  1018                   -adc byte ptr [eax], bl
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.bl) + cpu.flags.cf);
    // 00421a5a  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a5b  0020                   +add byte ptr [eax], ah
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a5d  184d00                 -sbb byte ptr [ebp], cl
    (app->getMemory<x86::reg8>(cpu.ebp)) -= x86::reg8(x86::sreg8(cpu.cl) + cpu.flags.cf);
    // 00421a60  3018                   -xor byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00421a62  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a63  0030                   +add byte ptr [eax], dh
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dh));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a65  184d00                 +sbb byte ptr [ebp], cl
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl)) + cpu.flags.cf;
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a68  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00421a69  184d00                 +sbb byte ptr [ebp], cl
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl)) + cpu.flags.cf;
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421a6d  184d00                 +sbb byte ptr [ebp], cl
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl)) + cpu.flags.cf;
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a70  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00421a71  184d00                 -sbb byte ptr [ebp], cl
    (app->getMemory<x86::reg8>(cpu.ebp)) -= x86::reg8(x86::sreg8(cpu.cl) + cpu.flags.cf);
    // 00421a74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421a76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421a78  0400                   -add al, 0
    (cpu.al) += x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00421a7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421a7c  0800                   -or byte ptr [eax], al
    app->getMemory<x86::reg8>(cpu.eax) |= x86::reg8(x86::sreg8(cpu.al));
    // 00421a7e  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a80  1400                   -adc al, 0
    (cpu.al) += x86::reg8(x86::sreg8(0 /*0x0*/) + cpu.flags.cf);
    // 00421a82  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a84  1800                   -sbb byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) -= x86::reg8(x86::sreg8(cpu.al) + cpu.flags.cf);
    // 00421a86  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a88  1c00                   -sbb al, 0
    (cpu.al) -= x86::reg8(x86::sreg8(0 /*0x0*/) + cpu.flags.cf);
    // 00421a8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421a8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421a8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421a90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421a92  7416                   -je 0x421aaa
    if (cpu.flags.zf)
    {
        goto L_0x00421aaa;
    }
    // 00421a94  83f801                 +cmp eax, 1
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
    // 00421a97  7410                   -je 0x421aa9
    if (cpu.flags.zf)
    {
        goto L_0x00421aa9;
    }
    // 00421a99  3d57000780             +cmp eax, 0x80070057
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942487 /*0x80070057*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421a9e  7407                   -je 0x421aa7
    if (cpu.flags.zf)
    {
        goto L_0x00421aa7;
    }
    // 00421aa0  3d05000780             +cmp eax, 0x80070005
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942405 /*0x80070005*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421aa5  7509                   -jne 0x421ab0
    if (!cpu.flags.zf)
    {
        goto L_0x00421ab0;
    }
L_0x00421aa7:
    // 00421aa7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00421aa9:
    // 00421aa9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421aaa:
    // 00421aaa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421aaf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421ab0:
    // 00421ab0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421ab1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421ab2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421ab3  b9a4aa4b00             -mov ecx, 0x4baaa4
    cpu.ecx = 4958884 /*0x4baaa4*/;
    // 00421ab8  bb74070000             -mov ebx, 0x774
    cpu.ebx = 1908 /*0x774*/;
    // 00421abd  68c4aa4b00             -push 0x4baac4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4958916 /*0x4baac4*/;
    cpu.esp -= 4;
    // 00421ac2  890d78a64c00           -mov dword ptr [0x4ca678], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ecx;
    // 00421ac8  891d7ca64c00           -mov dword ptr [0x4ca67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebx;
    // 00421ace  e8ad830500             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00421ad3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421ad6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421ad8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ad9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ada  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_421a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00421a90;
    // 00421a40  b017                   -mov al, 0x17
    cpu.al = 23 /*0x17*/;
    // 00421a42  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a43  00c0                   -add al, al
    (cpu.al) += x86::reg8(x86::sreg8(cpu.al));
    // 00421a45  17                     -pop ss
    cpu.ss = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00421a46  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a47  00d0                   -add al, dl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.dl));
    // 00421a49  17                     -pop ss
    cpu.ss = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00421a4a  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a4b  00e0                   -add al, ah
    (cpu.al) += x86::reg8(x86::sreg8(cpu.ah));
    // 00421a4d  17                     -pop ss
    cpu.ss = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00421a4e  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a4f  00f0                   -add al, dh
    (cpu.al) += x86::reg8(x86::sreg8(cpu.dh));
    // 00421a51  17                     -pop ss
    cpu.ss = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00421a52  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a53  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a55  184d00                 +sbb byte ptr [ebp], cl
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl)) + cpu.flags.cf;
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a58  1018                   -adc byte ptr [eax], bl
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.bl) + cpu.flags.cf);
    // 00421a5a  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a5b  0020                   +add byte ptr [eax], ah
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a5d  184d00                 -sbb byte ptr [ebp], cl
    (app->getMemory<x86::reg8>(cpu.ebp)) -= x86::reg8(x86::sreg8(cpu.cl) + cpu.flags.cf);
    // 00421a60  3018                   -xor byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00421a62  4d                     -dec ebp
    (cpu.ebp)--;
    // 00421a63  0030                   +add byte ptr [eax], dh
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dh));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a65  184d00                 +sbb byte ptr [ebp], cl
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl)) + cpu.flags.cf;
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a68  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00421a69  184d00                 +sbb byte ptr [ebp], cl
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl)) + cpu.flags.cf;
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421a6d  184d00                 +sbb byte ptr [ebp], cl
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.ebp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl)) + cpu.flags.cf;
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a70  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00421a71  184d00                 -sbb byte ptr [ebp], cl
    (app->getMemory<x86::reg8>(cpu.ebp)) -= x86::reg8(x86::sreg8(cpu.cl) + cpu.flags.cf);
    // 00421a74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421a76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421a78  0400                   -add al, 0
    (cpu.al) += x86::reg8(x86::sreg8(0 /*0x0*/));
    // 00421a7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421a7c  0800                   -or byte ptr [eax], al
    app->getMemory<x86::reg8>(cpu.eax) |= x86::reg8(x86::sreg8(cpu.al));
    // 00421a7e  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a80  1400                   -adc al, 0
    (cpu.al) += x86::reg8(x86::sreg8(0 /*0x0*/) + cpu.flags.cf);
    // 00421a82  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a84  1800                   -sbb byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) -= x86::reg8(x86::sreg8(cpu.al) + cpu.flags.cf);
    // 00421a86  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a88  1c00                   -sbb al, 0
    (cpu.al) -= x86::reg8(x86::sreg8(0 /*0x0*/) + cpu.flags.cf);
    // 00421a8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421a8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421a8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x00421a90:
    // 00421a90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421a92  7416                   -je 0x421aaa
    if (cpu.flags.zf)
    {
        goto L_0x00421aaa;
    }
    // 00421a94  83f801                 +cmp eax, 1
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
    // 00421a97  7410                   -je 0x421aa9
    if (cpu.flags.zf)
    {
        goto L_0x00421aa9;
    }
    // 00421a99  3d57000780             +cmp eax, 0x80070057
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942487 /*0x80070057*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421a9e  7407                   -je 0x421aa7
    if (cpu.flags.zf)
    {
        goto L_0x00421aa7;
    }
    // 00421aa0  3d05000780             +cmp eax, 0x80070005
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942405 /*0x80070005*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421aa5  7509                   -jne 0x421ab0
    if (!cpu.flags.zf)
    {
        goto L_0x00421ab0;
    }
L_0x00421aa7:
    // 00421aa7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00421aa9:
    // 00421aa9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421aaa:
    // 00421aaa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421aaf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421ab0:
    // 00421ab0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421ab1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421ab2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421ab3  b9a4aa4b00             -mov ecx, 0x4baaa4
    cpu.ecx = 4958884 /*0x4baaa4*/;
    // 00421ab8  bb74070000             -mov ebx, 0x774
    cpu.ebx = 1908 /*0x774*/;
    // 00421abd  68c4aa4b00             -push 0x4baac4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4958916 /*0x4baac4*/;
    cpu.esp -= 4;
    // 00421ac2  890d78a64c00           -mov dword ptr [0x4ca678], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ecx;
    // 00421ac8  891d7ca64c00           -mov dword ptr [0x4ca67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebx;
    // 00421ace  e8ad830500             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00421ad3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421ad6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421ad8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ad9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ada  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421ae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421ae0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421ae1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421ae2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421ae3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421ae4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421ae5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421ae6  8b15fc494c00           -mov edx, dword ptr [0x4c49fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */);
    // 00421aec  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00421aee  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00421af0  743a                   -je 0x421b2c
    if (cpu.flags.zf)
    {
        goto L_0x00421b2c;
    }
    // 00421af2  3c13                   +cmp al, 0x13
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(19 /*0x13*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421af4  743f                   -je 0x421b35
    if (cpu.flags.zf)
    {
        goto L_0x00421b35;
    }
    // 00421af6  3c11                   +cmp al, 0x11
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(17 /*0x11*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421af8  7361                   -jae 0x421b5b
    if (!cpu.flags.cf)
    {
        goto L_0x00421b5b;
    }
    // 00421afa  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421afc  0f85ae000000           -jne 0x421bb0
    if (!cpu.flags.zf)
    {
        goto L_0x00421bb0;
    }
    // 00421b02  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00421b04  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00421b06:
    // 00421b06  8bae48634d00           -mov ebp, dword ptr [esi + 0x4d6348]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5071688) /* 0x4d6348 */);
    // 00421b0c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00421b0e  7413                   -je 0x421b23
    if (cpu.flags.zf)
    {
        goto L_0x00421b23;
    }
    // 00421b10  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421b11  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00421b14  ff521c                 -call dword ptr [edx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421b17  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00421b19  e872ffffff             -call 0x421a90
    cpu.esp -= 4;
    sub_421a90(app, cpu);
    if (cpu.terminate) return;
    // 00421b1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421b20  7401                   -je 0x421b23
    if (cpu.flags.zf)
    {
        goto L_0x00421b23;
    }
    // 00421b22  47                     -inc edi
    (cpu.edi)++;
L_0x00421b23:
    // 00421b23  43                     -inc ebx
    (cpu.ebx)++;
    // 00421b24  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421b27  83fb10                 +cmp ebx, 0x10
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
    // 00421b2a  7cda                   -jl 0x421b06
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421b06;
    }
L_0x00421b2c:
    // 00421b2c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00421b2e:
    // 00421b2e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421b35:
    // 00421b35  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00421b3a  e8a1ffffff             -call 0x421ae0
    cpu.esp -= 4;
    sub_421ae0(app, cpu);
    if (cpu.terminate) return;
    // 00421b3f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00421b41  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00421b46  e895ffffff             -call 0x421ae0
    cpu.esp -= 4;
    sub_421ae0(app, cpu);
    if (cpu.terminate) return;
    // 00421b4b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00421b4d  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00421b52  e889ffffff             -call 0x421ae0
    cpu.esp -= 4;
    sub_421ae0(app, cpu);
    if (cpu.terminate) return;
    // 00421b57  01d0                   +add eax, edx
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
    // 00421b59  ebd3                   -jmp 0x421b2e
    goto L_0x00421b2e;
L_0x00421b5b:
    // 00421b5b  7712                   -ja 0x421b6f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00421b6f;
    }
    // 00421b5d  833d004a4c0000         +cmp dword ptr [0x4c4a00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421b64  752e                   -jne 0x421b94
    if (!cpu.flags.zf)
    {
        goto L_0x00421b94;
    }
    // 00421b66  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00421b68  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b6a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b6c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421b6f:
    // 00421b6f  3c12                   +cmp al, 0x12
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(18 /*0x12*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421b71  753d                   -jne 0x421bb0
    if (!cpu.flags.zf)
    {
        goto L_0x00421bb0;
    }
    // 00421b73  8b0d044a4c00           -mov ecx, dword ptr [0x4c4a04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4999684) /* 0x4c4a04 */);
    // 00421b79  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00421b7b  74af                   -je 0x421b2c
    if (cpu.flags.zf)
    {
        goto L_0x00421b2c;
    }
    // 00421b7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421b7e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00421b80  0fbed8                 -movsx ebx, al
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00421b83  ff521c                 -call dword ptr [edx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421b86  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00421b88  e803ffffff             -call 0x421a90
    cpu.esp -= 4;
    sub_421a90(app, cpu);
    if (cpu.terminate) return;
    // 00421b8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b90  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b92  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b93  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421b94:
    // 00421b94  0fbed8                 -movsx ebx, al
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00421b97  a1004a4c00             -mov eax, dword ptr [0x4c4a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
    // 00421b9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421b9d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421b9f  ff521c                 -call dword ptr [edx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421ba2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00421ba4  e8e7feffff             -call 0x421a90
    cpu.esp -= 4;
    sub_421a90(app, cpu);
    if (cpu.terminate) return;
    // 00421ba9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421baa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421bab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421bac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421bad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421bae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421baf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421bb0:
    // 00421bb0  3c13                   +cmp al, 0x13
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(19 /*0x13*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421bb2  7f2c                   -jg 0x421be0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00421be0;
    }
    // 00421bb4  0fbed8                 -movsx ebx, al
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00421bb7  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00421bbe  8bb048634d00           -mov esi, dword ptr [eax + 0x4d6348]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5071688) /* 0x4d6348 */);
    // 00421bc4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00421bc6  0f8460ffffff           -je 0x421b2c
    if (cpu.flags.zf)
    {
        goto L_0x00421b2c;
    }
    // 00421bcc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421bcd  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421bcf  ff521c                 -call dword ptr [edx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421bd2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00421bd4  e8b7feffff             -call 0x421a90
    cpu.esp -= 4;
    sub_421a90(app, cpu);
    if (cpu.terminate) return;
    // 00421bd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421bda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421bdb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421bdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421bdd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421bde  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421bdf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421be0:
    // 00421be0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421be2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421be3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421be4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421be5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421be6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421be7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421be8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421bf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421bf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421bf2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421bf3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421bf4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421bf5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421bf8  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 00421bfb  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00421bfd  e84e5b0600             -call 0x487750
    cpu.esp -= 4;
    sub_487750(app, cpu);
    if (cpu.terminate) return;
    // 00421c02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421c04  7435                   -je 0x421c3b
    if (cpu.flags.zf)
    {
        goto L_0x00421c3b;
    }
    // 00421c06  8a2424                 -mov ah, byte ptr [esp]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp);
    // 00421c09  80fc10                 +cmp ah, 0x10
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
    // 00421c0c  7d36                   -jge 0x421c44
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00421c44;
    }
    // 00421c0e  8b7424fd               -mov esi, dword ptr [esp - 3]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-3) /* -0x3 */);
    // 00421c12  c1fe18                 -sar esi, 0x18
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (24 /*0x18*/ % 32));
    // 00421c15  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00421c18  8bbe48634d00           -mov edi, dword ptr [esi + 0x4d6348]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5071688) /* 0x4d6348 */);
    // 00421c1e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00421c20  7446                   -je 0x421c68
    if (cpu.flags.zf)
    {
        goto L_0x00421c68;
    }
    // 00421c22  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421c23  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 00421c25  e8265b0600             -call 0x487750
    cpu.esp -= 4;
    sub_487750(app, cpu);
    if (cpu.terminate) return;
    // 00421c2a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421c2b  8bae48634d00           -mov ebp, dword ptr [esi + 0x4d6348]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5071688) /* 0x4d6348 */);
    // 00421c31  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421c32  ff5734                 -call dword ptr [edi + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421c35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421c37  742f                   -je 0x421c68
    if (cpu.flags.zf)
    {
        goto L_0x00421c68;
    }
    // 00421c39  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00421c3b:
    // 00421c3b  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421c3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c43  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421c44:
    // 00421c44  7530                   -jne 0x421c76
    if (!cpu.flags.zf)
    {
        goto L_0x00421c76;
    }
    // 00421c46  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 00421c48  886c2404               -mov byte ptr [esp + 4], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ch;
L_0x00421c4c:
    // 00421c4c  8b442401               -mov eax, dword ptr [esp + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00421c50  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00421c52  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00421c55  e896ffffff             -call 0x421bf0
    cpu.esp -= 4;
    sub_421bf0(app, cpu);
    if (cpu.terminate) return;
    // 00421c5a  ff442404               -inc dword ptr [esp + 4]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))++;
    // 00421c5e  807c240410             +cmp byte ptr [esp + 4], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421c63  7ce7                   -jl 0x421c4c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421c4c;
    }
    // 00421c65  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00421c68:
    // 00421c68  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421c6d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421c70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c75  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421c76:
    // 00421c76  80fc11                 +cmp ah, 0x11
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(17 /*0x11*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421c79  742c                   -je 0x421ca7
    if (cpu.flags.zf)
    {
        goto L_0x00421ca7;
    }
    // 00421c7b  80fc12                 +cmp ah, 0x12
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(18 /*0x12*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421c7e  75e8                   -jne 0x421c68
    if (!cpu.flags.zf)
    {
        goto L_0x00421c68;
    }
    // 00421c80  a1044a4c00             -mov eax, dword ptr [0x4c4a04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999684) /* 0x4c4a04 */);
    // 00421c85  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421c86  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00421c88  e8c35a0600             -call 0x487750
    cpu.esp -= 4;
    sub_487750(app, cpu);
    if (cpu.terminate) return;
    // 00421c8d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421c8e  8b15044a4c00           -mov edx, dword ptr [0x4c4a04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999684) /* 0x4c4a04 */);
    // 00421c94  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421c95  ff5634                 -call dword ptr [esi + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421c98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421c9a  74cc                   -je 0x421c68
    if (cpu.flags.zf)
    {
        goto L_0x00421c68;
    }
    // 00421c9c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421c9e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421ca1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ca2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ca3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ca4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ca5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ca6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421ca7:
    // 00421ca7  a1004a4c00             -mov eax, dword ptr [0x4c4a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
    // 00421cac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421cad  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00421caf  e89c5a0600             -call 0x487750
    cpu.esp -= 4;
    sub_487750(app, cpu);
    if (cpu.terminate) return;
    // 00421cb4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421cb5  8b0d004a4c00           -mov ecx, dword ptr [0x4c4a00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
    // 00421cbb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421cbc  ff5634                 -call dword ptr [esi + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421cbf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421cc1  74a5                   -je 0x421c68
    if (cpu.flags.zf)
    {
        goto L_0x00421c68;
    }
    // 00421cc3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421cc5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421cc8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cc9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ccb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ccc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ccd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_421cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421cd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421cd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421cd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421cd3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421cd6  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00421cda  8b15144a4c00           -mov edx, dword ptr [0x4c4a14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999700) /* 0x4c4a14 */);
    // 00421ce0  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00421ce7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421ce9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00421cec  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421cee  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00421cf1  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00421cf3  bb50000000             -mov ebx, 0x50
    cpu.ebx = 80 /*0x50*/;
    // 00421cf8  889091634d00           -mov byte ptr [eax + 0x4d6391], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5071761) /* 0x4d6391 */) = cpu.dl;
    // 00421cfe  0588634d00             -add eax, 0x4d6388
    (cpu.eax) += x86::reg32(x86::sreg32(5071752 /*0x4d6388*/));
    // 00421d03  8d962c010000           -lea edx, [esi + 0x12c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(300) /* 0x12c */);
    // 00421d09  83c009                 -add eax, 9
    (cpu.eax) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00421d0c  e8aba20500             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 00421d11  8b15144a4c00           -mov edx, dword ptr [0x4c4a14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999700) /* 0x4c4a14 */);
    // 00421d17  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00421d1e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421d20  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00421d23  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421d25  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00421d2c  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00421d2e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421d30  889ae0634d00           -mov byte ptr [edx + 0x4d63e0], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5071840) /* 0x4d63e0 */) = cpu.bl;
    // 00421d36  668b4624               -mov ax, word ptr [esi + 0x24]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00421d3a  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00421d3d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00421d42  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00421d46  3c04                   +cmp al, 4
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421d48  7239                   -jb 0x421d83
    if (cpu.flags.cf)
    {
        goto L_0x00421d83;
    }
    // 00421d4a  772a                   -ja 0x421d76
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00421d76;
    }
    // 00421d4c  c68290634d0004         -mov byte ptr [edx + 0x4d6390], 4
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5071760) /* 0x4d6390 */) = 4 /*0x4*/;
L_0x00421d53:
    // 00421d53  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00421d55  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00421d59  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421d5a  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421d5d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421d5e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00421d60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421d61  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421d64  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421d66  7439                   -je 0x421da1
    if (cpu.flags.zf)
    {
        goto L_0x00421da1;
    }
    // 00421d68  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421d6d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421d70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421d71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421d72  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421d73  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00421d76:
    // 00421d76  3c06                   +cmp al, 6
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(6 /*0x6*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421d78  7509                   -jne 0x421d83
    if (!cpu.flags.zf)
    {
        goto L_0x00421d83;
    }
    // 00421d7a  c68290634d0002         -mov byte ptr [edx + 0x4d6390], 2
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5071760) /* 0x4d6390 */) = 2 /*0x2*/;
    // 00421d81  ebd0                   -jmp 0x421d53
    goto L_0x00421d53;
L_0x00421d83:
    // 00421d83  8b15144a4c00           -mov edx, dword ptr [0x4c4a14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999700) /* 0x4c4a14 */);
    // 00421d89  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00421d90  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421d92  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00421d95  29d0                   +sub eax, edx
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
    // 00421d97  c6048590634d0001       -mov byte ptr [eax*4 + 0x4d6390], 1
    app->getMemory<x86::reg8>(x86::reg32(5071760) /* 0x4d6390 */ + cpu.eax * 4) = 1 /*0x1*/;
    // 00421d9f  ebb2                   -jmp 0x421d53
    goto L_0x00421d53;
L_0x00421da1:
    // 00421da1  6880694b00             -push 0x4b6980
    app->getMemory<x86::reg32>(cpu.esp-4) = 4942208 /*0x4b6980*/;
    cpu.esp -= 4;
    // 00421da6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00421daa  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00421dae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421daf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00421db1  ff502c                 -call dword ptr [eax + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421db4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421db6  7543                   -jne 0x421dfb
    if (!cpu.flags.zf)
    {
        goto L_0x00421dfb;
    }
    // 00421db8  a1144a4c00             -mov eax, dword ptr [0x4c4a14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999700) /* 0x4c4a14 */);
    // 00421dbd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00421dc0  0548634d00             -add eax, 0x4d6348
    (cpu.eax) += x86::reg32(x86::sreg32(5071688 /*0x4d6348*/));
    // 00421dc5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421dc6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00421dca  6880184d00             -push 0x4d1880
    app->getMemory<x86::reg32>(cpu.esp-4) = 5052544 /*0x4d1880*/;
    cpu.esp -= 4;
    // 00421dcf  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00421dd3  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00421dd5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421dd6  ff12                   -call dword ptr [edx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421dd8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421dda  7539                   -jne 0x421e15
    if (!cpu.flags.zf)
    {
        goto L_0x00421e15;
    }
    // 00421ddc  a1114a4c00             -mov eax, dword ptr [0x4c4a11]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999697) /* 0x4c4a11 */);
    // 00421de1  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 00421de6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00421de9  e802feffff             -call 0x421bf0
    cpu.esp -= 4;
    sub_421bf0(app, cpu);
    if (cpu.terminate) return;
    // 00421dee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421df0  7541                   -jne 0x421e33
    if (!cpu.flags.zf)
    {
        goto L_0x00421e33;
    }
    // 00421df2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421df5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421df6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421df7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421df8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00421dfb:
    // 00421dfb  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00421dfe  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00421e01  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421e02  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00421e04  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421e07  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421e0c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421e0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421e10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421e11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421e12  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00421e15:
    // 00421e15  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421e16  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00421e1a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00421e1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421e1f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00421e21  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421e24  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421e29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421e2a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421e2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421e2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421e2f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421e30  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00421e33:
    // 00421e33  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00421e36  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00421e39  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421e3a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00421e3c  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421e3f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421e44  0105144a4c00           -add dword ptr [0x4c4a14], eax
    (app->getMemory<x86::reg32>(x86::reg32(4999700) /* 0x4c4a14 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00421e4a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421e4d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421e4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421e4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421e50  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421e60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421e61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421e62  833dfc494c0000         +cmp dword ptr [0x4c49fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421e69  0f848e000000           -je 0x421efd
    if (cpu.flags.zf)
    {
        goto L_0x00421efd;
    }
    // 00421e6f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421e70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421e71  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421e72  833d004a4c0000         +cmp dword ptr [0x4c4a00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421e79  7432                   -je 0x421ead
    if (cpu.flags.zf)
    {
        goto L_0x00421ead;
    }
    // 00421e7b  8b1d084a4c00           -mov ebx, dword ptr [0x4c4a08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999688) /* 0x4c4a08 */);
    // 00421e81  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00421e83  7408                   -je 0x421e8d
    if (cpu.flags.zf)
    {
        goto L_0x00421e8d;
    }
    // 00421e85  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421e86  2eff1550744b00         -call dword ptr cs:[0x4b7450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944976) /* 0x4b7450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00421e8d:
    // 00421e8d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421e8e  a1004a4c00             -mov eax, dword ptr [0x4c4a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
    // 00421e93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421e94  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421e96  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421e99  a1004a4c00             -mov eax, dword ptr [0x4c4a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
    // 00421e9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421e9f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421ea1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00421ea3  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421ea6  893d004a4c00           -mov dword ptr [0x4c4a00], edi
    app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */) = cpu.edi;
    // 00421eac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00421ead:
    // 00421ead  8b2d044a4c00           -mov ebp, dword ptr [0x4c4a04]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4999684) /* 0x4c4a04 */);
    // 00421eb3  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00421eb5  7557                   -jne 0x421f0e
    if (!cpu.flags.zf)
    {
        goto L_0x00421f0e;
    }
L_0x00421eb7:
    // 00421eb7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00421eb9:
    // 00421eb9  8b9348634d00           -mov edx, dword ptr [ebx + 0x4d6348]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5071688) /* 0x4d6348 */);
    // 00421ebf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00421ec1  741c                   -je 0x421edf
    if (cpu.flags.zf)
    {
        goto L_0x00421edf;
    }
    // 00421ec3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00421ec5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421ec6  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00421ec8  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421ecb  8b8348634d00           -mov eax, dword ptr [ebx + 0x4d6348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5071688) /* 0x4d6348 */);
    // 00421ed1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421ed2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421ed4  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421ed7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00421ed9  898b48634d00           -mov dword ptr [ebx + 0x4d6348], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5071688) /* 0x4d6348 */) = cpu.ecx;
L_0x00421edf:
    // 00421edf  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421ee2  83fb40                 +cmp ebx, 0x40
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421ee5  75d2                   -jne 0x421eb9
    if (!cpu.flags.zf)
    {
        goto L_0x00421eb9;
    }
    // 00421ee7  a1fc494c00             -mov eax, dword ptr [0x4c49fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */);
    // 00421eec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421eed  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421eef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00421ef1  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421ef4  891dfc494c00           -mov dword ptr [0x4c49fc], ebx
    app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */) = cpu.ebx;
    // 00421efa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421efb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421efc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00421efd:
    // 00421efd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00421eff  8935144a4c00           -mov dword ptr [0x4c4a14], esi
    app->getMemory<x86::reg32>(x86::reg32(4999700) /* 0x4c4a14 */) = cpu.esi;
    // 00421f05  8935104a4c00           -mov dword ptr [0x4c4a10], esi
    app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */) = cpu.esi;
    // 00421f0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f0d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421f0e:
    // 00421f0e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421f0f  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00421f12  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421f15  a1044a4c00             -mov eax, dword ptr [0x4c4a04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999684) /* 0x4c4a04 */);
    // 00421f1a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421f1b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421f1d  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421f20  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00421f22  a3044a4c00             -mov dword ptr [0x4c4a04], eax
    app->getMemory<x86::reg32>(x86::reg32(4999684) /* 0x4c4a04 */) = cpu.eax;
    // 00421f27  eb8e                   -jmp 0x421eb7
    goto L_0x00421eb7;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421f30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421f31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421f32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421f33  83ec54                 -sub esp, 0x54
    (cpu.esp) -= x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00421f36  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00421f38  895c2450               -mov dword ptr [esp + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 00421f3c  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00421f3e  0fbed8                 -movsx ebx, al
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00421f41  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 00421f48  8b9748634d00           -mov edx, dword ptr [edi + 0x4d6348]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5071688) /* 0x4d6348 */);
    // 00421f4e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00421f50  7521                   -jne 0x421f73
    if (!cpu.flags.zf)
    {
        goto L_0x00421f73;
    }
    // 00421f52  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00421f56  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00421f58  7515                   -jne 0x421f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00421f6f;
    }
L_0x00421f5a:
    // 00421f5a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00421f5c  7406                   -je 0x421f64
    if (cpu.flags.zf)
    {
        goto L_0x00421f64;
    }
    // 00421f5e  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x00421f64:
    // 00421f64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421f66  83c454                 +add esp, 0x54
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(84 /*0x54*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421f69  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f6c  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00421f6f:
    // 00421f6f  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00421f71  ebe7                   -jmp 0x421f5a
    goto L_0x00421f5a;
L_0x00421f73:
    // 00421f73  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00421f75  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421f76  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00421f78  ff5264                 -call dword ptr [edx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421f7b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421f7d  7420                   -je 0x421f9f
    if (cpu.flags.zf)
    {
        goto L_0x00421f9f;
    }
    // 00421f7f  3d1e000780             +cmp eax, 0x8007001e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942430 /*0x8007001e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421f84  7407                   -je 0x421f8d
    if (cpu.flags.zf)
    {
        goto L_0x00421f8d;
    }
    // 00421f86  3d0c000780             +cmp eax, 0x8007000c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942412 /*0x8007000c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421f8b  75d7                   -jne 0x421f64
    if (!cpu.flags.zf)
    {
        goto L_0x00421f64;
    }
L_0x00421f8d:
    // 00421f8d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00421f8f  e84cfbffff             -call 0x421ae0
    cpu.esp -= 4;
    sub_421ae0(app, cpu);
    if (cpu.terminate) return;
    // 00421f94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421f96  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00421f99  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f9c  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00421f9f:
    // 00421f9f  8b8748634d00           -mov eax, dword ptr [edi + 0x4d6348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5071688) /* 0x4d6348 */);
    // 00421fa5  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00421fa7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421fa8  6a50                   -push 0x50
    app->getMemory<x86::reg32>(cpu.esp-4) = 80 /*0x50*/;
    cpu.esp -= 4;
    // 00421faa  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421fac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421fad  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421fb0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421fb2  7419                   -je 0x421fcd
    if (cpu.flags.zf)
    {
        goto L_0x00421fcd;
    }
    // 00421fb4  3d1e000780             +cmp eax, 0x8007001e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942430 /*0x8007001e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421fb9  75a9                   -jne 0x421f64
    if (!cpu.flags.zf)
    {
        goto L_0x00421f64;
    }
    // 00421fbb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00421fbd  e81efbffff             -call 0x421ae0
    cpu.esp -= 4;
    sub_421ae0(app, cpu);
    if (cpu.terminate) return;
    // 00421fc2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421fc4  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00421fc7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421fc8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421fc9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421fca  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00421fcd:
    // 00421fcd  8b4c2450               -mov ecx, dword ptr [esp + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00421fd1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00421fd3  7405                   -je 0x421fda
    if (cpu.flags.zf)
    {
        goto L_0x00421fda;
    }
    // 00421fd5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00421fd8  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x00421fda:
    // 00421fda  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00421fdc  7407                   -je 0x421fe5
    if (cpu.flags.zf)
    {
        goto L_0x00421fe5;
    }
    // 00421fde  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00421fe2  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x00421fe5:
    // 00421fe5  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00421fe9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00421feb  7406                   -je 0x421ff3
    if (cpu.flags.zf)
    {
        goto L_0x00421ff3;
    }
    // 00421fed  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00421ff1  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00421ff3:
    // 00421ff3  8b7c2468               -mov edi, dword ptr [esp + 0x68]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00421ff7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00421ff9  7406                   -je 0x422001
    if (cpu.flags.zf)
    {
        goto L_0x00422001;
    }
    // 00421ffb  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00421fff  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x00422001:
    // 00422001  8b6c246c               -mov ebp, dword ptr [esp + 0x6c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00422005  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00422007  7407                   -je 0x422010
    if (cpu.flags.zf)
    {
        goto L_0x00422010;
    }
    // 00422009  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042200d  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x00422010:
    // 00422010  837c247000             +cmp dword ptr [esp + 0x70], 0
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
    // 00422015  740a                   -je 0x422021
    if (cpu.flags.zf)
    {
        goto L_0x00422021;
    }
    // 00422017  8b542470               -mov edx, dword ptr [esp + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0042201b  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042201f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00422021:
    // 00422021  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00422025  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00422027  7406                   -je 0x42202f
    if (cpu.flags.zf)
    {
        goto L_0x0042202f;
    }
    // 00422029  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042202d  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0042202f:
    // 0042202f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422031  7424                   -je 0x422057
    if (cpu.flags.zf)
    {
        goto L_0x00422057;
    }
    // 00422033  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00422039  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042203b:
    // 0042203b  f644043080             +test byte ptr [esp + eax + 0x30], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(48) /* 0x30 */ + cpu.eax * 1) & 128 /*0x80*/));
    // 00422040  740f                   -je 0x422051
    if (cpu.flags.zf)
    {
        goto L_0x00422051;
    }
    // 00422042  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00422047  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00422049  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0042204b  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0042204d  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0042204f  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
L_0x00422051:
    // 00422051  40                     -inc eax
    (cpu.eax)++;
    // 00422052  83f820                 +cmp eax, 0x20
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
    // 00422055  7ce4                   -jl 0x42203b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042203b;
    }
L_0x00422057:
    // 00422057  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042205c  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0042205f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422060  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422061  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422062  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422070  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422071  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422072  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422073  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00422077  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422078  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042207c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042207d  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00422081  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422082  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00422086  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422087  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042208b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042208c  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0042208f  e89cfeffff             -call 0x421f30
    cpu.esp -= 4;
    sub_421f30(app, cpu);
    if (cpu.terminate) return;
    // 00422094  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422096  7405                   -je 0x42209d
    if (cpu.flags.zf)
    {
        goto L_0x0042209d;
    }
    // 00422098  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0042209d:
    // 0042209d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042209e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042209f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004220a0  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4220b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004220b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004220b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004220b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004220b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004220b4  81ec8c010000           -sub esp, 0x18c
    (cpu.esp) -= x86::reg32(x86::sreg32(396 /*0x18c*/));
    // 004220ba  88842488010000         -mov byte ptr [esp + 0x188], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(392) /* 0x188 */) = cpu.al;
    // 004220c1  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004220c3  899c2480010000         -mov dword ptr [esp + 0x180], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */) = cpu.ebx;
    // 004220ca  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 004220cf  8dbc2468010000         -lea edi, [esp + 0x168]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(360) /* 0x168 */);
    // 004220d6  be741a4200             -mov esi, 0x421a74
    cpu.esi = 4332148 /*0x421a74*/;
    // 004220db  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004220dd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004220df  756c                   -jne 0x42214d
    if (!cpu.flags.zf)
    {
        goto L_0x0042214d;
    }
L_0x004220e1:
    // 004220e1  8b942480010000         -mov edx, dword ptr [esp + 0x180]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 004220e8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004220ea  7406                   -je 0x4220f2
    if (cpu.flags.zf)
    {
        goto L_0x004220f2;
    }
    // 004220ec  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
L_0x004220f2:
    // 004220f2  80bc248801000010       +cmp byte ptr [esp + 0x188], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(392) /* 0x188 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004220fa  7559                   -jne 0x422155
    if (!cpu.flags.zf)
    {
        goto L_0x00422155;
    }
    // 004220fc  c78424840100000f000000 -mov dword ptr [esp + 0x184], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */) = 15 /*0xf*/;
L_0x00422107:
    // 00422107  8b842481010000         -mov eax, dword ptr [esp + 0x181]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(385) /* 0x181 */);
    // 0042210e  8b9c2480010000         -mov ebx, dword ptr [esp + 0x180]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 00422115  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00422117  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0042211a  e891ffffff             -call 0x4220b0
    cpu.esp -= 4;
    sub_4220b0(app, cpu);
    if (cpu.terminate) return;
    // 0042211f  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 00422126  48                     -dec eax
    (cpu.eax)--;
    // 00422127  89842484010000         -mov dword ptr [esp + 0x184], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */) = cpu.eax;
    // 0042212e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422130  7fd5                   -jg 0x422107
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00422107;
    }
    // 00422132  8b9c2480010000         -mov ebx, dword ptr [esp + 0x180]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 00422139  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0042213b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042213d  e86effffff             -call 0x4220b0
    cpu.esp -= 4;
    sub_4220b0(app, cpu);
    if (cpu.terminate) return;
    // 00422142  81c48c010000           +add esp, 0x18c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(396 /*0x18c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00422148  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422149  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042214a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042214b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042214c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042214d:
    // 0042214d  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00422153  eb8c                   -jmp 0x4220e1
    goto L_0x004220e1;
L_0x00422155:
    // 00422155  833dfc494c0000         +cmp dword ptr [0x4c49fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042215c  7427                   -je 0x422185
    if (cpu.flags.zf)
    {
        goto L_0x00422185;
    }
L_0x0042215e:
    // 0042215e  8b942485010000         -mov edx, dword ptr [esp + 0x185]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 00422165  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00422168  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 0042216f  83b948634d0000         +cmp dword ptr [ecx + 0x4d6348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5071688) /* 0x4d6348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422176  7528                   -jne 0x4221a0
    if (!cpu.flags.zf)
    {
        goto L_0x004221a0;
    }
    // 00422178  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042217a  81c48c010000           -add esp, 0x18c
    (cpu.esp) += x86::reg32(x86::sreg32(396 /*0x18c*/));
    // 00422180  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422181  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422182  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422183  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422184  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422185:
    // 00422185  e886080000             -call 0x422a10
    cpu.esp -= 4;
    sub_422a10(app, cpu);
    if (cpu.terminate) return;
    // 0042218a  833dfc494c0000         +cmp dword ptr [0x4c49fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422191  75cb                   -jne 0x42215e
    if (!cpu.flags.zf)
    {
        goto L_0x0042215e;
    }
L_0x00422193:
    // 00422193  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00422195  81c48c010000           -add esp, 0x18c
    (cpu.esp) += x86::reg32(x86::sreg32(396 /*0x18c*/));
    // 0042219b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042219c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042219d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042219e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042219f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004221a0:
    // 004221a0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004221a2  e839f9ffff             -call 0x421ae0
    cpu.esp -= 4;
    sub_421ae0(app, cpu);
    if (cpu.terminate) return;
    // 004221a7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004221ae  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004221b0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004221b3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004221b5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004221b8  83b888634d0000         +cmp dword ptr [eax + 0x4d6388], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5071752) /* 0x4d6388 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004221bf  0f847d000000           -je 0x422242
    if (cpu.flags.zf)
    {
        goto L_0x00422242;
    }
L_0x004221c5:
    // 004221c5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004221c7  7422                   -je 0x4221eb
    if (cpu.flags.zf)
    {
        goto L_0x004221eb;
    }
    // 004221c9  8b942485010000         -mov edx, dword ptr [esp + 0x185]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 004221d0  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004221d3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004221da  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004221dc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004221df  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004221e1  8b048588634d00         -mov eax, dword ptr [eax*4 + 0x4d6388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071752) /* 0x4d6388 */ + cpu.eax * 4);
    // 004221e8  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x004221eb:
    // 004221eb  8b8c2480010000         -mov ecx, dword ptr [esp + 0x180]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 004221f2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004221f4  7421                   -je 0x422217
    if (cpu.flags.zf)
    {
        goto L_0x00422217;
    }
    // 004221f6  8b942485010000         -mov edx, dword ptr [esp + 0x185]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 004221fd  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00422200  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00422207  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00422209  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0042220c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042220e  8b04858c634d00         -mov eax, dword ptr [eax*4 + 0x4d638c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071756) /* 0x4d638c */ + cpu.eax * 4);
    // 00422215  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x00422217:
    // 00422217  8b942485010000         -mov edx, dword ptr [esp + 0x185]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 0042221e  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00422221  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00422228  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042222a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0042222d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042222f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422232  0588634d00             -add eax, 0x4d6388
    (cpu.eax) += x86::reg32(x86::sreg32(5071752 /*0x4d6388*/));
    // 00422237  81c48c010000           -add esp, 0x18c
    (cpu.esp) += x86::reg32(x86::sreg32(396 /*0x18c*/));
    // 0042223d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042223e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042223f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422240  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422241  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422242:
    // 00422242  83b88c634d0000         +cmp dword ptr [eax + 0x4d638c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5071756) /* 0x4d638c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422249  0f8576ffffff           -jne 0x4221c5
    if (!cpu.flags.zf)
    {
        goto L_0x004221c5;
    }
    // 0042224f  bb2c000000             -mov ebx, 0x2c
    cpu.ebx = 44 /*0x2c*/;
    // 00422254  8b8148634d00           -mov eax, dword ptr [ecx + 0x4d6348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5071688) /* 0x4d6348 */);
    // 0042225a  8d8c243c010000         -lea ecx, [esp + 0x13c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 00422261  899c243c010000         -mov dword ptr [esp + 0x13c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */) = cpu.ebx;
    // 00422268  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422269  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042226b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042226c  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042226f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422271  0f851cffffff           -jne 0x422193
    if (!cpu.flags.zf)
    {
        goto L_0x00422193;
    }
    // 00422277  f684244101000001       +test byte ptr [esp + 0x141], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(321) /* 0x141 */) & 1 /*0x1*/));
    // 0042227f  741f                   -je 0x4222a0
    if (cpu.flags.zf)
    {
        goto L_0x004222a0;
    }
    // 00422281  8b8c2485010000         -mov ecx, dword ptr [esp + 0x185]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 00422288  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042228d  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00422290  8b35104a4c00           -mov esi, dword ptr [0x4c4a10]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */);
    // 00422296  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00422298  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0042229a  8935104a4c00           -mov dword ptr [0x4c4a10], esi
    app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */) = cpu.esi;
L_0x004222a0:
    // 004222a0  bf3c010000             -mov edi, 0x13c
    cpu.edi = 316 /*0x13c*/;
    // 004222a5  8b94244c010000         -mov edx, dword ptr [esp + 0x14c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */);
    // 004222ac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004222ae  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004222b0  89842484010000         -mov dword ptr [esp + 0x184], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */) = cpu.eax;
    // 004222b7  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004222ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004222bc  7669                   -jbe 0x422327
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00422327;
    }
    // 004222be  be30000000             -mov esi, 0x30
    cpu.esi = 48 /*0x30*/;
L_0x004222c3:
    // 004222c3  83fb20                 +cmp ebx, 0x20
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004222c6  7d5f                   -jge 0x422327
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00422327;
    }
    // 004222c8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004222ca  8bbc2489010000         -mov edi, dword ptr [esp + 0x189]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(393) /* 0x189 */);
    // 004222d1  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004222d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004222d6  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 004222d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004222da  8b04bd48634d00         -mov eax, dword ptr [edi*4 + 0x4d6348]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071688) /* 0x4d6348 */ + cpu.edi * 4);
    // 004222e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004222e2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004222e4  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004222e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004222e9  7528                   -jne 0x422313
    if (!cpu.flags.zf)
    {
        goto L_0x00422313;
    }
    // 004222eb  6bc75c                 -imul eax, edi, 0x5c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(92 /*0x5c*/)));
    // 004222ee  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004222f0  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004222f5  8b9088634d00           -mov edx, dword ptr [eax + 0x4d6388]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5071752) /* 0x4d6388 */);
    // 004222fb  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 004222fd  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 004222ff  899088634d00           -mov dword ptr [eax + 0x4d6388], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5071752) /* 0x4d6388 */) = cpu.edx;
    // 00422305  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00422307  7403                   -je 0x42230c
    if (cpu.flags.zf)
    {
        goto L_0x0042230c;
    }
    // 00422309  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
L_0x0042230c:
    // 0042230c  ff842484010000         -inc dword ptr [esp + 0x184]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */))++;
L_0x00422313:
    // 00422313  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 0042231a  8bbc244c010000         -mov edi, dword ptr [esp + 0x14c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */);
    // 00422321  46                     -inc esi
    (cpu.esi)++;
    // 00422322  43                     -inc ebx
    (cpu.ebx)++;
    // 00422323  39f8                   +cmp eax, edi
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
    // 00422325  729c                   -jb 0x4222c3
    if (cpu.flags.cf)
    {
        goto L_0x004222c3;
    }
L_0x00422327:
    // 00422327  8b842448010000         -mov eax, dword ptr [esp + 0x148]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 0042232e  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00422330  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00422332  89ac2484010000         -mov dword ptr [esp + 0x184], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */) = cpu.ebp;
    // 00422339  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042233b  0f8675000000           -jbe 0x4223b6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004223b6;
    }
    // 00422341  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00422343:
    // 00422343  83fb06                 +cmp ebx, 6
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422346  7d6e                   -jge 0x4223b6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004223b6;
    }
    // 00422348  8bac2485010000         -mov ebp, dword ptr [esp + 0x185]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 0042234f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00422351  8b94346c010000         -mov edx, dword ptr [esp + esi + 0x16c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */ + cpu.esi * 1);
    // 00422358  c1fd18                 -sar ebp, 0x18
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (24 /*0x18*/ % 32));
    // 0042235b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042235c  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00422360  8b04ad48634d00         -mov eax, dword ptr [ebp*4 + 0x4d6348]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071688) /* 0x4d6348 */ + cpu.ebp * 4);
    // 00422367  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422368  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042236a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042236b  ff5138                 -call dword ptr [ecx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042236e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422370  752e                   -jne 0x4223a0
    if (!cpu.flags.zf)
    {
        goto L_0x004223a0;
    }
    // 00422372  6bed5c                 -imul ebp, ebp, 0x5c
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(92 /*0x5c*/)));
    // 00422375  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042237a  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0042237c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0042237e  8b8d8c634d00           -mov ecx, dword ptr [ebp + 0x4d638c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5071756) /* 0x4d638c */);
    // 00422384  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00422386  8bbc2480010000         -mov edi, dword ptr [esp + 0x180]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 0042238d  898d8c634d00           -mov dword ptr [ebp + 0x4d638c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5071756) /* 0x4d638c */) = cpu.ecx;
    // 00422393  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00422395  7402                   -je 0x422399
    if (cpu.flags.zf)
    {
        goto L_0x00422399;
    }
    // 00422397  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
L_0x00422399:
    // 00422399  ff842484010000         -inc dword ptr [esp + 0x184]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */))++;
L_0x004223a0:
    // 004223a0  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 004223a7  8bbc2448010000         -mov edi, dword ptr [esp + 0x148]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004223ae  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004223b1  43                     -inc ebx
    (cpu.ebx)++;
    // 004223b2  39f8                   +cmp eax, edi
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
    // 004223b4  728d                   -jb 0x422343
    if (cpu.flags.cf)
    {
        goto L_0x00422343;
    }
L_0x004223b6:
    // 004223b6  8b942485010000         -mov edx, dword ptr [esp + 0x185]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 004223bd  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004223c0  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004223c7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004223c9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004223cc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004223ce  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004223d1  0588634d00             -add eax, 0x4d6388
    (cpu.eax) += x86::reg32(x86::sreg32(5071752 /*0x4d6388*/));
    // 004223d6  81c48c010000           -add esp, 0x18c
    (cpu.esp) += x86::reg32(x86::sreg32(396 /*0x18c*/));
    // 004223dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004223dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004223de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004223df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004223e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4223f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004223f0  833dfc494c0000         +cmp dword ptr [0x4c49fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004223f7  7463                   -je 0x42245c
    if (cpu.flags.zf)
    {
        goto L_0x0042245c;
    }
    // 004223f9  833d1c4a4c0000         +cmp dword ptr [0x4c4a1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999708) /* 0x4c4a1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422400  756b                   -jne 0x42246d
    if (!cpu.flags.zf)
    {
        goto L_0x0042246d;
    }
L_0x00422402:
    // 00422402  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422403  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422404  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00422409  8b3d144a4c00           -mov edi, dword ptr [0x4c4a14]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4999700) /* 0x4c4a14 */);
    // 0042240f  89351c4a4c00           -mov dword ptr [0x4c4a1c], esi
    app->getMemory<x86::reg32>(x86::reg32(4999708) /* 0x4c4a1c */) = cpu.esi;
    // 00422415  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00422417  7528                   -jne 0x422441
    if (!cpu.flags.zf)
    {
        goto L_0x00422441;
    }
    // 00422419  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042241a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042241b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042241c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042241d  a1fc494c00             -mov eax, dword ptr [0x4c49fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */);
    // 00422422  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422423  68d01c4200             -push 0x421cd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4332752 /*0x421cd0*/;
    cpu.esp -= 4;
    // 00422428  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0042242a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042242c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042242d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042242f  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422432  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00422437  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00422439  e872fcffff             -call 0x4220b0
    cpu.esp -= 4;
    sub_4220b0(app, cpu);
    if (cpu.terminate) return;
    // 0042243e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042243f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422440  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00422441:
    // 00422441  833d144a4c0000         +cmp dword ptr [0x4c4a14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999700) /* 0x4c4a14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422448  740a                   -je 0x422454
    if (cpu.flags.zf)
    {
        goto L_0x00422454;
    }
    // 0042244a  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0042244f  e88cf6ffff             -call 0x421ae0
    cpu.esp -= 4;
    sub_421ae0(app, cpu);
    if (cpu.terminate) return;
L_0x00422454:
    // 00422454  a1144a4c00             -mov eax, dword ptr [0x4c4a14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999700) /* 0x4c4a14 */);
    // 00422459  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042245a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042245b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042245c:
    // 0042245c  e8af050000             -call 0x422a10
    cpu.esp -= 4;
    sub_422a10(app, cpu);
    if (cpu.terminate) return;
    // 00422461  833dfc494c0000         +cmp dword ptr [0x4c49fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422468  7598                   -jne 0x422402
    if (!cpu.flags.zf)
    {
        goto L_0x00422402;
    }
    // 0042246a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042246c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042246d:
    // 0042246d  a1144a4c00             -mov eax, dword ptr [0x4c4a14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999700) /* 0x4c4a14 */);
    // 00422472  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422481  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422482  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422483  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422484  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00422486  3c13                   +cmp al, 0x13
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(19 /*0x13*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422488  741b                   -je 0x4224a5
    if (cpu.flags.zf)
    {
        goto L_0x004224a5;
    }
L_0x0042248a:
    // 0042248a  80fa10                 +cmp dl, 0x10
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
    // 0042248d  7536                   -jne 0x4224c5
    if (!cpu.flags.zf)
    {
        goto L_0x004224c5;
    }
    // 0042248f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00422491:
    // 00422491  0fbec2                 -movsx eax, dl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 00422494  42                     -inc edx
    (cpu.edx)++;
    // 00422495  e8e6ffffff             -call 0x422480
    cpu.esp -= 4;
    sub_422480(app, cpu);
    if (cpu.terminate) return;
    // 0042249a  83fa10                 +cmp edx, 0x10
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
    // 0042249d  7cf2                   -jl 0x422491
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422491;
    }
    // 0042249f  90                     -nop 
    ;
L_0x004224a0:
    // 004224a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004224a5:
    // 004224a5  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 004224aa  e8d1ffffff             -call 0x422480
    cpu.esp -= 4;
    sub_422480(app, cpu);
    if (cpu.terminate) return;
    // 004224af  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 004224b4  e8c7ffffff             -call 0x422480
    cpu.esp -= 4;
    sub_422480(app, cpu);
    if (cpu.terminate) return;
    // 004224b9  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004224be  e8bdffffff             -call 0x422480
    cpu.esp -= 4;
    sub_422480(app, cpu);
    if (cpu.terminate) return;
    // 004224c3  ebc5                   -jmp 0x42248a
    goto L_0x0042248a;
L_0x004224c5:
    // 004224c5  80fa11                 +cmp dl, 0x11
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(17 /*0x11*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004224c8  7515                   -jne 0x4224df
    if (!cpu.flags.zf)
    {
        goto L_0x004224df;
    }
    // 004224ca  8b35004a4c00           -mov esi, dword ptr [0x4c4a00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
    // 004224d0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004224d2  74cc                   -je 0x4224a0
    if (cpu.flags.zf)
    {
        goto L_0x004224a0;
    }
    // 004224d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004224d5  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004224d7  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004224da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004224df:
    // 004224df  80fa12                 +cmp dl, 0x12
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(18 /*0x12*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004224e2  7515                   -jne 0x4224f9
    if (!cpu.flags.zf)
    {
        goto L_0x004224f9;
    }
    // 004224e4  8b1d044a4c00           -mov ebx, dword ptr [0x4c4a04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999684) /* 0x4c4a04 */);
    // 004224ea  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004224ec  74b2                   -je 0x4224a0
    if (cpu.flags.zf)
    {
        goto L_0x004224a0;
    }
    // 004224ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004224ef  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004224f1  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004224f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004224f9:
    // 004224f9  7515                   -jne 0x422510
    if (!cpu.flags.zf)
    {
        goto L_0x00422510;
    }
    // 004224fb  8b0d044a4c00           -mov ecx, dword ptr [0x4c4a04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4999684) /* 0x4c4a04 */);
    // 00422501  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00422503  749b                   -je 0x4224a0
    if (cpu.flags.zf)
    {
        goto L_0x004224a0;
    }
    // 00422505  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422506  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00422508  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042250b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042250c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042250d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042250e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042250f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422510:
    // 00422510  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00422512  7c8c                   -jl 0x4224a0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004224a0;
    }
    // 00422514  80fa10                 +cmp dl, 0x10
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
    // 00422517  7d87                   -jge 0x4224a0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004224a0;
    }
    // 00422519  0fbec2                 -movsx eax, dl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 0042251c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0042251f  8b9048634d00           -mov edx, dword ptr [eax + 0x4d6348]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5071688) /* 0x4d6348 */);
    // 00422525  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00422527  0f8473ffffff           -je 0x4224a0
    if (cpu.flags.zf)
    {
        goto L_0x004224a0;
    }
    // 0042252d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042252f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422530  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00422532  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422535  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422536  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422537  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422538  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422539  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422540  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422541  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422542  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422543  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422544  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 0042254a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0042254c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042254e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00422550  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00422552  8d8c2404020000         -lea ecx, [esp + 0x204]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(516) /* 0x204 */);
    // 00422559  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042255a  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042255e  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00422563  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422564  a1004a4c00             -mov eax, dword ptr [0x4c4a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
    // 00422569  8994240c020000         -mov dword ptr [esp + 0x20c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.edx;
    // 00422570  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00422572  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422574  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422575  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422578  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042257a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042257c  0f8580000000           -jne 0x422602
    if (!cpu.flags.zf)
    {
        goto L_0x00422602;
    }
    // 00422582  8b8c2400020000         -mov ecx, dword ptr [esp + 0x200]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 00422589  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042258b  7635                   -jbe 0x4225c2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004225c2;
    }
    // 0042258d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042258f  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
L_0x00422592:
    // 00422592  8b0c04                 -mov ecx, dword ptr [esp + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 1);
    // 00422595  83f90c                 +cmp ecx, 0xc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422598  0f85c9000000           -jne 0x422667
    if (!cpu.flags.zf)
    {
        goto L_0x00422667;
    }
    // 0042259e  f644040480             +test byte ptr [esp + eax + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) & 128 /*0x80*/));
    // 004225a3  0f84af000000           -je 0x422658
    if (cpu.flags.zf)
    {
        goto L_0x00422658;
    }
    // 004225a9  8a2d50794d00           -mov ch, byte ptr [0x4d7950]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5077328) /* 0x4d7950 */);
    // 004225af  80cd01                 -or ch, 1
    cpu.ch |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004225b2  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004225b5:
    // 004225b5  882d50794d00           -mov byte ptr [0x4d7950], ch
    app->getMemory<x86::reg8>(x86::reg32(5077328) /* 0x4d7950 */) = cpu.ch;
L_0x004225bb:
    // 004225bb  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004225be  39d8                   +cmp eax, ebx
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
    // 004225c0  7cd0                   -jl 0x422592
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422592;
    }
L_0x004225c2:
    // 004225c2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004225c4  740a                   -je 0x4225d0
    if (cpu.flags.zf)
    {
        goto L_0x004225d0;
    }
    // 004225c6  a150794d00             -mov eax, dword ptr [0x4d7950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077328) /* 0x4d7950 */);
    // 004225cb  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004225cd  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x004225d0:
    // 004225d0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004225d2  7407                   -je 0x4225db
    if (cpu.flags.zf)
    {
        goto L_0x004225db;
    }
    // 004225d4  a148794d00             -mov eax, dword ptr [0x4d7948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077320) /* 0x4d7948 */);
    // 004225d9  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x004225db:
    // 004225db  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004225dd  7407                   -je 0x4225e6
    if (cpu.flags.zf)
    {
        goto L_0x004225e6;
    }
    // 004225df  a14c794d00             -mov eax, dword ptr [0x4d794c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077324) /* 0x4d794c */);
    // 004225e4  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x004225e6:
    // 004225e6  833da0a44c0000         +cmp dword ptr [0x4ca4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004225ed  7408                   -je 0x4225f7
    if (cpu.flags.zf)
    {
        goto L_0x004225f7;
    }
    // 004225ef  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004225f1  0f858d010000           -jne 0x422784
    if (!cpu.flags.zf)
    {
        goto L_0x00422784;
    }
L_0x004225f7:
    // 004225f7  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 004225fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004225fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004225ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422600  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422601  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422602:
    // 00422602  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00422604  891d50794d00           -mov dword ptr [0x4d7950], ebx
    app->getMemory<x86::reg32>(x86::reg32(5077328) /* 0x4d7950 */) = cpu.ebx;
    // 0042260a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042260c  7403                   -je 0x422611
    if (cpu.flags.zf)
    {
        goto L_0x00422611;
    }
    // 0042260e  895d00                 -mov dword ptr [ebp], ebx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ebx;
L_0x00422611:
    // 00422611  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00422613  7407                   -je 0x42261c
    if (cpu.flags.zf)
    {
        goto L_0x0042261c;
    }
    // 00422615  a148794d00             -mov eax, dword ptr [0x4d7948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077320) /* 0x4d7948 */);
    // 0042261a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x0042261c:
    // 0042261c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042261e  7407                   -je 0x422627
    if (cpu.flags.zf)
    {
        goto L_0x00422627;
    }
    // 00422620  a14c794d00             -mov eax, dword ptr [0x4d794c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077324) /* 0x4d794c */);
    // 00422625  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00422627:
    // 00422627  81fa07020480           +cmp edx, 0x80040207
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147746311 /*0x80040207*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042262d  72c8                   -jb 0x4225f7
    if (cpu.flags.cf)
    {
        goto L_0x004225f7;
    }
    // 0042262f  76c6                   -jbe 0x4225f7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004225f7;
    }
    // 00422631  81fa0c000780           +cmp edx, 0x8007000c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942412 /*0x8007000c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422637  72be                   -jb 0x4225f7
    if (cpu.flags.cf)
    {
        goto L_0x004225f7;
    }
    // 00422639  7608                   -jbe 0x422643
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00422643;
    }
    // 0042263b  81fa1e000780           +cmp edx, 0x8007001e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942430 /*0x8007001e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422641  75b4                   -jne 0x4225f7
    if (!cpu.flags.zf)
    {
        goto L_0x004225f7;
    }
L_0x00422643:
    // 00422643  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00422648  e893f4ffff             -call 0x421ae0
    cpu.esp -= 4;
    sub_421ae0(app, cpu);
    if (cpu.terminate) return;
    // 0042264d  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00422653  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422654  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422655  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422656  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422657  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422658:
    // 00422658  812550794d00fe000000   +and dword ptr [0x4d7950], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(x86::reg32(5077328) /* 0x4d7950 */) &= x86::reg32(x86::sreg32(254 /*0xfe*/))));
    // 00422662  e954ffffff             -jmp 0x4225bb
    goto L_0x004225bb;
L_0x00422667:
    // 00422667  83f90d                 +cmp ecx, 0xd
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042266a  7527                   -jne 0x422693
    if (!cpu.flags.zf)
    {
        goto L_0x00422693;
    }
    // 0042266c  f644040480             +test byte ptr [esp + eax + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) & 128 /*0x80*/));
    // 00422671  7411                   -je 0x422684
    if (cpu.flags.zf)
    {
        goto L_0x00422684;
    }
    // 00422673  8a2d50794d00           -mov ch, byte ptr [0x4d7950]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5077328) /* 0x4d7950 */);
    // 00422679  80cd02                 -or ch, 2
    cpu.ch |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0042267c  80ca02                 +or dl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0042267f  e931ffffff             -jmp 0x4225b5
    goto L_0x004225b5;
L_0x00422684:
    // 00422684  812550794d00fd000000   +and dword ptr [0x4d7950], 0xfd
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(x86::reg32(5077328) /* 0x4d7950 */) &= x86::reg32(x86::sreg32(253 /*0xfd*/))));
    // 0042268e  e928ffffff             -jmp 0x4225bb
    goto L_0x004225bb;
L_0x00422693:
    // 00422693  83f90e                 +cmp ecx, 0xe
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422696  7527                   -jne 0x4226bf
    if (!cpu.flags.zf)
    {
        goto L_0x004226bf;
    }
    // 00422698  f644040480             +test byte ptr [esp + eax + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) & 128 /*0x80*/));
    // 0042269d  7411                   -je 0x4226b0
    if (cpu.flags.zf)
    {
        goto L_0x004226b0;
    }
    // 0042269f  8a2d50794d00           -mov ch, byte ptr [0x4d7950]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5077328) /* 0x4d7950 */);
    // 004226a5  80cd04                 -or ch, 4
    cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004226a8  80ca04                 +or dl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004226ab  e905ffffff             -jmp 0x4225b5
    goto L_0x004225b5;
L_0x004226b0:
    // 004226b0  812550794d00fb000000   +and dword ptr [0x4d7950], 0xfb
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(x86::reg32(5077328) /* 0x4d7950 */) &= x86::reg32(x86::sreg32(251 /*0xfb*/))));
    // 004226ba  e9fcfeffff             -jmp 0x4225bb
    goto L_0x004225bb;
L_0x004226bf:
    // 004226bf  83f90f                 +cmp ecx, 0xf
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004226c2  7527                   -jne 0x4226eb
    if (!cpu.flags.zf)
    {
        goto L_0x004226eb;
    }
    // 004226c4  f644040480             +test byte ptr [esp + eax + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) & 128 /*0x80*/));
    // 004226c9  7411                   -je 0x4226dc
    if (cpu.flags.zf)
    {
        goto L_0x004226dc;
    }
    // 004226cb  8a2d50794d00           -mov ch, byte ptr [0x4d7950]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5077328) /* 0x4d7950 */);
    // 004226d1  80cd08                 -or ch, 8
    cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004226d4  80ca08                 +or dl, 8
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004226d7  e9d9feffff             -jmp 0x4225b5
    goto L_0x004225b5;
L_0x004226dc:
    // 004226dc  812550794d00f7000000   +and dword ptr [0x4d7950], 0xf7
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(x86::reg32(5077328) /* 0x4d7950 */) &= x86::reg32(x86::sreg32(247 /*0xf7*/))));
    // 004226e6  e9d0feffff             -jmp 0x4225bb
    goto L_0x004225bb;
L_0x004226eb:
    // 004226eb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004226ed  7546                   -jne 0x422735
    if (!cpu.flags.zf)
    {
        goto L_0x00422735;
    }
    // 004226ef  8b4c0404               -mov ecx, dword ptr [esp + eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 004226f3  010d48794d00           -add dword ptr [0x4d7948], ecx
    (app->getMemory<x86::reg32>(x86::reg32(5077320) /* 0x4d7948 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004226f9  8b0d48794d00           -mov ecx, dword ptr [0x4d7948]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5077320) /* 0x4d7948 */);
    // 004226ff  3b0d38794d00           +cmp ecx, dword ptr [0x4d7938]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5077304) /* 0x4d7938 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422705  7d11                   -jge 0x422718
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00422718;
    }
    // 00422707  8b0d38794d00           -mov ecx, dword ptr [0x4d7938]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5077304) /* 0x4d7938 */);
    // 0042270d  890d48794d00           -mov dword ptr [0x4d7948], ecx
    app->getMemory<x86::reg32>(x86::reg32(5077320) /* 0x4d7948 */) = cpu.ecx;
    // 00422713  e9a3feffff             -jmp 0x4225bb
    goto L_0x004225bb;
L_0x00422718:
    // 00422718  3b0d40794d00           +cmp ecx, dword ptr [0x4d7940]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5077312) /* 0x4d7940 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042271e  0f8e97feffff           -jle 0x4225bb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004225bb;
    }
    // 00422724  8b0d40794d00           -mov ecx, dword ptr [0x4d7940]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5077312) /* 0x4d7940 */);
    // 0042272a  890d48794d00           -mov dword ptr [0x4d7948], ecx
    app->getMemory<x86::reg32>(x86::reg32(5077320) /* 0x4d7948 */) = cpu.ecx;
    // 00422730  e986feffff             -jmp 0x4225bb
    goto L_0x004225bb;
L_0x00422735:
    // 00422735  83f904                 +cmp ecx, 4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422738  0f857dfeffff           -jne 0x4225bb
    if (!cpu.flags.zf)
    {
        goto L_0x004225bb;
    }
    // 0042273e  8b4c0404               -mov ecx, dword ptr [esp + eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00422742  010d4c794d00           -add dword ptr [0x4d794c], ecx
    (app->getMemory<x86::reg32>(x86::reg32(5077324) /* 0x4d794c */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422748  8b0d4c794d00           -mov ecx, dword ptr [0x4d794c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5077324) /* 0x4d794c */);
    // 0042274e  3b0d3c794d00           +cmp ecx, dword ptr [0x4d793c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5077308) /* 0x4d793c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422754  7d11                   -jge 0x422767
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00422767;
    }
    // 00422756  8b0d3c794d00           -mov ecx, dword ptr [0x4d793c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5077308) /* 0x4d793c */);
    // 0042275c  890d4c794d00           -mov dword ptr [0x4d794c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5077324) /* 0x4d794c */) = cpu.ecx;
    // 00422762  e954feffff             -jmp 0x4225bb
    goto L_0x004225bb;
L_0x00422767:
    // 00422767  3b0d44794d00           +cmp ecx, dword ptr [0x4d7944]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5077316) /* 0x4d7944 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042276d  0f8e48feffff           -jle 0x4225bb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004225bb;
    }
    // 00422773  8b0d44794d00           -mov ecx, dword ptr [0x4d7944]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5077316) /* 0x4d7944 */);
    // 00422779  890d4c794d00           -mov dword ptr [0x4d794c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5077324) /* 0x4d794c */) = cpu.ecx;
    // 0042277f  e937feffff             -jmp 0x4225bb
    goto L_0x004225bb;
L_0x00422784:
    // 00422784  a150794d00             -mov eax, dword ptr [0x4d7950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077328) /* 0x4d7950 */);
    // 00422789  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0042278b  ff15a0a44c00           -call dword ptr [0x4ca4a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422791  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00422797  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422798  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422799  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042279a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042279b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4227a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004227a0  a338794d00             -mov dword ptr [0x4d7938], eax
    app->getMemory<x86::reg32>(x86::reg32(5077304) /* 0x4d7938 */) = cpu.eax;
    // 004227a5  89153c794d00           -mov dword ptr [0x4d793c], edx
    app->getMemory<x86::reg32>(x86::reg32(5077308) /* 0x4d793c */) = cpu.edx;
    // 004227ab  891d40794d00           -mov dword ptr [0x4d7940], ebx
    app->getMemory<x86::reg32>(x86::reg32(5077312) /* 0x4d7940 */) = cpu.ebx;
    // 004227b1  8b154c794d00           -mov edx, dword ptr [0x4d794c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5077324) /* 0x4d794c */);
    // 004227b7  a148794d00             -mov eax, dword ptr [0x4d7948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077320) /* 0x4d7948 */);
    // 004227bc  890d44794d00           -mov dword ptr [0x4d7944], ecx
    app->getMemory<x86::reg32>(x86::reg32(5077316) /* 0x4d7944 */) = cpu.ecx;
    // 004227c2  e909000000             -jmp 0x4227d0
    return sub_4227d0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4227d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004227d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004227d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004227d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004227d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004227d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004227d5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004227d8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004227da  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004227dc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004227de  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004227e2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004227e3  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004227e8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004227ea  a1004a4c00             -mov eax, dword ptr [0x4c4a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
    // 004227ef  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004227f3  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004227f5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004227f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004227f8  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004227fb  8b0d38794d00           -mov ecx, dword ptr [0x4d7938]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5077304) /* 0x4d7938 */);
    // 00422801  39ce                   +cmp esi, ecx
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
    // 00422803  7c31                   -jl 0x422836
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422836;
    }
    // 00422805  8b3d40794d00           -mov edi, dword ptr [0x4d7940]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5077312) /* 0x4d7940 */);
    // 0042280b  39fe                   +cmp esi, edi
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
    // 0042280d  7e2f                   -jle 0x42283e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042283e;
    }
    // 0042280f  893d48794d00           -mov dword ptr [0x4d7948], edi
    app->getMemory<x86::reg32>(x86::reg32(5077320) /* 0x4d7948 */) = cpu.edi;
L_0x00422815:
    // 00422815  8b2d3c794d00           -mov ebp, dword ptr [0x4d793c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5077308) /* 0x4d793c */);
    // 0042281b  39eb                   +cmp ebx, ebp
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
    // 0042281d  7c27                   -jl 0x422846
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422846;
    }
    // 0042281f  a144794d00             -mov eax, dword ptr [0x4d7944]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077316) /* 0x4d7944 */);
    // 00422824  39c3                   +cmp ebx, eax
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
    // 00422826  7e26                   -jle 0x42284e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042284e;
    }
    // 00422828  a34c794d00             -mov dword ptr [0x4d794c], eax
    app->getMemory<x86::reg32>(x86::reg32(5077324) /* 0x4d794c */) = cpu.eax;
L_0x0042282d:
    // 0042282d  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00422830  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422831  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422832  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422833  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422834  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422835  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422836:
    // 00422836  890d48794d00           -mov dword ptr [0x4d7948], ecx
    app->getMemory<x86::reg32>(x86::reg32(5077320) /* 0x4d7948 */) = cpu.ecx;
    // 0042283c  ebd7                   -jmp 0x422815
    goto L_0x00422815;
L_0x0042283e:
    // 0042283e  893548794d00           -mov dword ptr [0x4d7948], esi
    app->getMemory<x86::reg32>(x86::reg32(5077320) /* 0x4d7948 */) = cpu.esi;
    // 00422844  ebcf                   -jmp 0x422815
    goto L_0x00422815;
L_0x00422846:
    // 00422846  892d4c794d00           -mov dword ptr [0x4d794c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5077324) /* 0x4d794c */) = cpu.ebp;
    // 0042284c  ebdf                   -jmp 0x42282d
    goto L_0x0042282d;
L_0x0042284e:
    // 0042284e  891d4c794d00           -mov dword ptr [0x4d794c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5077324) /* 0x4d794c */) = cpu.ebx;
    // 00422854  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00422857  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422858  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422859  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042285a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042285b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042285c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_422860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422861  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422862  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422863  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422864  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422865  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00422868  833dfc494c0000         +cmp dword ptr [0x4c49fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042286f  7446                   -je 0x4228b7
    if (cpu.flags.zf)
    {
        goto L_0x004228b7;
    }
L_0x00422871:
    // 00422871  8b1d004a4c00           -mov ebx, dword ptr [0x4c4a00]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
    // 00422877  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00422879  744e                   -je 0x4228c9
    if (cpu.flags.zf)
    {
        goto L_0x004228c9;
    }
L_0x0042287b:
    // 0042287b  833d004a4c0000         +cmp dword ptr [0x4c4a00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422882  740a                   -je 0x42288e
    if (cpu.flags.zf)
    {
        goto L_0x0042288e;
    }
    // 00422884  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00422889  e852f2ffff             -call 0x421ae0
    cpu.esp -= 4;
    sub_421ae0(app, cpu);
    if (cpu.terminate) return;
L_0x0042288e:
    // 0042288e  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00422893  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00422895  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00422897  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00422899  891d50794d00           -mov dword ptr [0x4d7950], ebx
    app->getMemory<x86::reg32>(x86::reg32(5077328) /* 0x4d7950 */) = cpu.ebx;
    // 0042289f  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 004228a4  e8f7feffff             -call 0x4227a0
    cpu.esp -= 4;
    sub_4227a0(app, cpu);
    if (cpu.terminate) return;
    // 004228a9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004228ae:
    // 004228ae  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004228b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004228b7:
    // 004228b7  e854010000             -call 0x422a10
    cpu.esp -= 4;
    sub_422a10(app, cpu);
    if (cpu.terminate) return;
    // 004228bc  833dfc494c0000         +cmp dword ptr [0x4c49fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004228c3  75ac                   -jne 0x422871
    if (!cpu.flags.zf)
    {
        goto L_0x00422871;
    }
    // 004228c5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004228c7  ebe5                   -jmp 0x4228ae
    goto L_0x004228ae;
L_0x004228c9:
    // 004228c9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004228ca  68004a4c00             -push 0x4c4a00
    app->getMemory<x86::reg32>(cpu.esp-4) = 4999680 /*0x4c4a00*/;
    cpu.esp -= 4;
    // 004228cf  a1fc494c00             -mov eax, dword ptr [0x4c49fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */);
    // 004228d4  6870184d00             -push 0x4d1870
    app->getMemory<x86::reg32>(cpu.esp-4) = 5052528 /*0x4d1870*/;
    cpu.esp -= 4;
    // 004228d9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004228db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004228dc  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004228df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004228e1  740b                   -je 0x4228ee
    if (cpu.flags.zf)
    {
        goto L_0x004228ee;
    }
    // 004228e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004228e5  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004228e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004228ee:
    // 004228ee  68a0664b00             -push 0x4b66a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4941472 /*0x4b66a0*/;
    cpu.esp -= 4;
    // 004228f3  a1004a4c00             -mov eax, dword ptr [0x4c4a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
    // 004228f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004228f9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004228fb  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004228fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422900  740b                   -je 0x42290d
    if (cpu.flags.zf)
    {
        goto L_0x0042290d;
    }
    // 00422902  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00422904  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00422907  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422908  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422909  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042290a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042290b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042290c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042290d:
    // 0042290d  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00422912  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00422917  e8d4f2ffff             -call 0x421bf0
    cpu.esp -= 4;
    sub_421bf0(app, cpu);
    if (cpu.terminate) return;
    // 0042291c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042291e  748e                   -je 0x4228ae
    if (cpu.flags.zf)
    {
        goto L_0x004228ae;
    }
    // 00422920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422921  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422922  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422923  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422924  2eff1554744b00         -call dword ptr cs:[0x4b7454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944980) /* 0x4b7454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042292b  a3084a4c00             -mov dword ptr [0x4c4a08], eax
    app->getMemory<x86::reg32>(x86::reg32(4999688) /* 0x4c4a08 */) = cpu.eax;
    // 00422930  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422932  0f8476ffffff           -je 0x4228ae
    if (cpu.flags.zf)
    {
        goto L_0x004228ae;
    }
    // 00422938  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422939  8b15004a4c00           -mov edx, dword ptr [0x4c4a00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
    // 0042293f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422940  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00422942  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422945  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422947  7536                   -jne 0x42297f
    if (!cpu.flags.zf)
    {
        goto L_0x0042297f;
    }
    // 00422949  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
    // 0042294e  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
    // 00422953  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00422958  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0042295a  a1004a4c00             -mov eax, dword ptr [0x4c4a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999680) /* 0x4c4a00 */);
    // 0042295f  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00422963  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00422967  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0042296a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042296b  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0042296f  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00422973  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00422975  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422977  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422978  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042297b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042297d  740b                   -je 0x42298a
    if (cpu.flags.zf)
    {
        goto L_0x0042298a;
    }
L_0x0042297f:
    // 0042297f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00422981  83c414                 +add esp, 0x14
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
    // 00422984  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422985  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422986  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422987  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422988  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422989  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042298a:
    // 0042298a  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0042298c  e87f540500             -call 0x477e10
    cpu.esp -= 4;
    sub_477e10(app, cpu);
    if (cpu.terminate) return;
    // 00422991  68b0294200             -push 0x4229b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4336048 /*0x4229b0*/;
    cpu.esp -= 4;
    // 00422996  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00422998  a30c4a4c00             -mov dword ptr [0x4c4a0c], eax
    app->getMemory<x86::reg32>(x86::reg32(4999692) /* 0x4c4a0c */) = cpu.eax;
    // 0042299d  e87e530500             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 004229a2  e9d4feffff             -jmp 0x42287b
    goto L_0x0042287b;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4229b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004229b0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004229b1  833d0c4a4c0000         +cmp dword ptr [0x4c4a0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999692) /* 0x4c4a0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004229b8  751b                   -jne 0x4229d5
    if (!cpu.flags.zf)
    {
        goto L_0x004229d5;
    }
L_0x004229ba:
    // 004229ba  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004229bc  2eff151c744b00         -call dword ptr cs:[0x4b741c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944924) /* 0x4b741c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004229c3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004229c5  2eff1530744b00         -call dword ptr cs:[0x4b7430]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944944) /* 0x4b7430 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004229cc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004229d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229d2  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004229d5:
    // 004229d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004229d6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004229d7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004229d8  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004229dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004229dd  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004229e1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004229e2  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004229e6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004229e7  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004229eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004229ec  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004229f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004229f1  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004229f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004229f6  ff150c4a4c00           -call dword ptr [0x4c4a0c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4999692) /* 0x4c4a0c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004229fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229ff  ebb9                   -jmp 0x4229ba
    goto L_0x004229ba;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422a10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422a11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422a12  8b15fc494c00           -mov edx, dword ptr [0x4c49fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */);
    // 00422a18  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00422a1a  7568                   -jne 0x422a84
    if (!cpu.flags.zf)
    {
        goto L_0x00422a84;
    }
    // 00422a1c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00422a1e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00422a20:
    // 00422a20  83c05c                 -add eax, 0x5c
    (cpu.eax) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 00422a23  89882c634d00           -mov dword ptr [eax + 0x4d632c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5071660) /* 0x4d632c */) = cpu.ecx;
    // 00422a29  898830634d00           -mov dword ptr [eax + 0x4d6330], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5071664) /* 0x4d6330 */) = cpu.ecx;
    // 00422a2f  888834634d00           -mov byte ptr [eax + 0x4d6334], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5071668) /* 0x4d6334 */) = cpu.cl;
    // 00422a35  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00422a38  888835634d00           -mov byte ptr [eax + 0x4d6335], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5071669) /* 0x4d6335 */) = cpu.cl;
    // 00422a3e  898a44634d00           -mov dword ptr [edx + 0x4d6344], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5071684) /* 0x4d6344 */) = cpu.ecx;
    // 00422a44  83fa40                 +cmp edx, 0x40
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
    // 00422a47  75d7                   -jne 0x422a20
    if (!cpu.flags.zf)
    {
        goto L_0x00422a20;
    }
    // 00422a49  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00422a4b:
    // 00422a4b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00422a4e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00422a50  898844694d00           -mov dword ptr [eax + 0x4d6944], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073220) /* 0x4d6944 */) = cpu.ecx;
    // 00422a56  83f878                 +cmp eax, 0x78
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422a59  75f0                   -jne 0x422a4b
    if (!cpu.flags.zf)
    {
        goto L_0x00422a4b;
    }
    // 00422a5b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422a5c  68fc494c00             -push 0x4c49fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4999676 /*0x4c49fc*/;
    cpu.esp -= 4;
    // 00422a61  6800050000             -push 0x500
    app->getMemory<x86::reg32>(cpu.esp-4) = 1280 /*0x500*/;
    cpu.esp -= 4;
    // 00422a66  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422a67  890d104a4c00           -mov dword ptr [0x4c4a10], ecx
    app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */) = cpu.ecx;
    // 00422a6d  890d144a4c00           -mov dword ptr [0x4c4a14], ecx
    app->getMemory<x86::reg32>(x86::reg32(4999700) /* 0x4c4a14 */) = cpu.ecx;
    // 00422a73  2eff1504754b00         -call dword ptr cs:[0x4b7504]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945156) /* 0x4b7504 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422a7a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422a7b  e8a8420900             -call 0x4b6d28
    cpu.esp -= 4;
    sub_4b6d28(app, cpu);
    if (cpu.terminate) return;
    // 00422a80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422a82  7503                   -jne 0x422a87
    if (!cpu.flags.zf)
    {
        goto L_0x00422a87;
    }
L_0x00422a84:
    // 00422a84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422a85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422a86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422a87:
    // 00422a87  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422a88  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00422a8a  893dfc494c00           -mov dword ptr [0x4c49fc], edi
    app->getMemory<x86::reg32>(x86::reg32(4999676) /* 0x4c49fc */) = cpu.edi;
    // 00422a90  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422a91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422a92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422a93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422aa0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422aa1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422aa2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422aa3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00422aa6  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00422aaa  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00422aae  6689442408             -mov word ptr [esp + 8], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00422ab3  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00422ab7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00422ab9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00422abb  7455                   -je 0x422b12
    if (cpu.flags.zf)
    {
        goto L_0x00422b12;
    }
    // 00422abd  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00422abf  81ff68010000           +cmp edi, 0x168
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(360 /*0x168*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422ac5  0f8e02020000           -jle 0x422ccd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00422ccd;
    }
    // 00422acb  c70368010000           -mov dword ptr [ebx], 0x168
    app->getMemory<x86::reg32>(cpu.ebx) = 360 /*0x168*/;
L_0x00422ad1:
    // 00422ad1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00422ad3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00422ad6  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00422ad9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422adc  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00422ade  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00422ae1  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00422ae3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422ae6  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00422ae8  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422aec  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00422aef  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00422af2  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00422af5  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422af8  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00422afa  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422afd  8bb8386a4d00           -mov edi, dword ptr [eax + 0x4d6a38]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073464) /* 0x4d6a38 */);
    // 00422b03  3b3b                   +cmp edi, dword ptr [ebx]
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
    // 00422b05  740b                   -je 0x422b12
    if (cpu.flags.zf)
    {
        goto L_0x00422b12;
    }
    // 00422b07  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00422b09  80ca40                 -or dl, 0x40
    cpu.dl |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00422b0c  8998386a4d00           -mov dword ptr [eax + 0x4d6a38], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073464) /* 0x4d6a38 */) = cpu.ebx;
L_0x00422b12:
    // 00422b12  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00422b14  7437                   -je 0x422b4d
    if (cpu.flags.zf)
    {
        goto L_0x00422b4d;
    }
    // 00422b16  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00422b18  3dffffff00             +cmp eax, 0xffffff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422b1d  0f85b9010000           -jne 0x422cdc
    if (!cpu.flags.zf)
    {
        goto L_0x00422cdc;
    }
    // 00422b23  c701ffffffff           -mov dword ptr [ecx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx) = 4294967295 /*0xffffffff*/;
L_0x00422b29:
    // 00422b29  8b5c2406               -mov ebx, dword ptr [esp + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422b2d  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00422b30  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00422b32  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422b35  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00422b37  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422b3a  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00422b3c  3bb8c8694d00           +cmp edi, dword ptr [eax + 0x4d69c8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073352) /* 0x4d69c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422b42  7409                   -je 0x422b4d
    if (cpu.flags.zf)
    {
        goto L_0x00422b4d;
    }
    // 00422b44  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00422b47  89b8c8694d00           -mov dword ptr [eax + 0x4d69c8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073352) /* 0x4d69c8 */) = cpu.edi;
L_0x00422b4d:
    // 00422b4d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422b4f  7432                   -je 0x422b83
    if (cpu.flags.zf)
    {
        goto L_0x00422b83;
    }
    // 00422b51  813e10270000           +cmp dword ptr [esi], 0x2710
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10000 /*0x2710*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422b57  7606                   -jbe 0x422b5f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00422b5f;
    }
    // 00422b59  c70610270000           -mov dword ptr [esi], 0x2710
    app->getMemory<x86::reg32>(cpu.esi) = 10000 /*0x2710*/;
L_0x00422b5f:
    // 00422b5f  8b4c2406               -mov ecx, dword ptr [esp + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422b63  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00422b66  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422b68  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422b6b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422b6d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422b70  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00422b72  3b98d0694d00           +cmp ebx, dword ptr [eax + 0x4d69d0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073360) /* 0x4d69d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422b78  7409                   -je 0x422b83
    if (cpu.flags.zf)
    {
        goto L_0x00422b83;
    }
    // 00422b7a  80ca04                 -or dl, 4
    cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00422b7d  8998d0694d00           -mov dword ptr [eax + 0x4d69d0], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073360) /* 0x4d69d0 */) = cpu.ebx;
L_0x00422b83:
    // 00422b83  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00422b87  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422b89  745b                   -je 0x422be6
    if (cpu.flags.zf)
    {
        goto L_0x00422be6;
    }
    // 00422b8b  8b4c2406               -mov ecx, dword ptr [esp + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422b8f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00422b92  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422b94  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422b97  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422b99  bbc0694d00             -mov ebx, 0x4d69c0
    cpu.ebx = 5073344 /*0x4d69c0*/;
    // 00422b9e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422ba1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00422ba3  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00422ba5  83c334                 -add ebx, 0x34
    (cpu.ebx) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00422ba8  8b88ec694d00           -mov ecx, dword ptr [eax + 0x4d69ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073388) /* 0x4d69ec */);
    // 00422bae  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00422bb0  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00422bb4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00422bb6  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 00422bb8  7405                   -je 0x422bbf
    if (cpu.flags.zf)
    {
        goto L_0x00422bbf;
    }
    // 00422bba  19c0                   +sbb eax, eax
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
    // 00422bbc  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x00422bbf:
    // 00422bbf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422bc1  7423                   -je 0x422be6
    if (cpu.flags.zf)
    {
        goto L_0x00422be6;
    }
    // 00422bc3  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00422bc7  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00422bcb  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00422bcd  8b89ec694d00           -mov ecx, dword ptr [ecx + 0x4d69ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5073388) /* 0x4d69ec */);
    // 00422bd3  80ce01                 -or dh, 1
    cpu.dh |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00422bd6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422bd7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422bd9  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00422bdc  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00422bde  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00422be0  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00422be3  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00422be5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00422be6:
    // 00422be6  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00422bea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422bec  742d                   -je 0x422c1b
    if (cpu.flags.zf)
    {
        goto L_0x00422c1b;
    }
    // 00422bee  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00422bf0  80fb20                 +cmp bl, 0x20
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
    // 00422bf3  7d26                   -jge 0x422c1b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00422c1b;
    }
    // 00422bf5  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00422bf8  83f8ff                 +cmp eax, -1
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
    // 00422bfb  0f8509010000           -jne 0x422d0a
    if (!cpu.flags.zf)
    {
        goto L_0x00422d0a;
    }
    // 00422c01  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00422c03:
    // 00422c03  8b4c2406               -mov ecx, dword ptr [esp + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422c07  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00422c0a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422c0c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422c0f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422c11  80ca08                 -or dl, 8
    cpu.dl |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00422c14  891c85d4694d00         -mov dword ptr [eax*4 + 0x4d69d4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5073364) /* 0x4d69d4 */ + cpu.eax * 4) = cpu.ebx;
L_0x00422c1b:
    // 00422c1b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00422c1d  7459                   -je 0x422c78
    if (cpu.flags.zf)
    {
        goto L_0x00422c78;
    }
    // 00422c1f  8b4c2406               -mov ecx, dword ptr [esp + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422c23  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00422c26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422c28  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422c2b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422c2d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422c30  8b5d00                 -mov ebx, dword ptr [ebp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00422c33  3b98286a4d00           +cmp ebx, dword ptr [eax + 0x4d6a28]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073448) /* 0x4d6a28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422c39  0f84da000000           -je 0x422d19
    if (cpu.flags.zf)
    {
        goto L_0x00422d19;
    }
L_0x00422c3f:
    // 00422c3f  8b4c2406               -mov ecx, dword ptr [esp + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422c43  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00422c46  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422c48  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422c4b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422c4d  8b4d00                 -mov ecx, dword ptr [ebp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00422c50  890c85286a4d00         -mov dword ptr [eax*4 + 0x4d6a28], ecx
    app->getMemory<x86::reg32>(x86::reg32(5073448) /* 0x4d6a28 */ + cpu.eax * 4) = cpu.ecx;
    // 00422c57  8b4d04                 -mov ecx, dword ptr [ebp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00422c5a  890c852c6a4d00         -mov dword ptr [eax*4 + 0x4d6a2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5073452) /* 0x4d6a2c */ + cpu.eax * 4) = cpu.ecx;
    // 00422c61  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00422c64  890c85306a4d00         -mov dword ptr [eax*4 + 0x4d6a30], ecx
    app->getMemory<x86::reg32>(x86::reg32(5073456) /* 0x4d6a30 */ + cpu.eax * 4) = cpu.ecx;
    // 00422c6b  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00422c6e  80ca80                 -or dl, 0x80
    cpu.dl |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00422c71  890c85346a4d00         -mov dword ptr [eax*4 + 0x4d6a34], ecx
    app->getMemory<x86::reg32>(x86::reg32(5073460) /* 0x4d6a34 */ + cpu.eax * 4) = cpu.ecx;
L_0x00422c78:
    // 00422c78  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00422c7a  0f85cb000000           -jne 0x422d4b
    if (!cpu.flags.zf)
    {
        goto L_0x00422d4b;
    }
    // 00422c80  807c240c01             +cmp byte ptr [esp + 0xc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422c85  7520                   -jne 0x422ca7
    if (!cpu.flags.zf)
    {
        goto L_0x00422ca7;
    }
    // 00422c87  8b542406               -mov edx, dword ptr [esp + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422c8b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00422c8e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00422c90  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422c93  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00422c95  8b0485406a4d00         -mov eax, dword ptr [eax*4 + 0x4d6a40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5073472) /* 0x4d6a40 */ + cpu.eax * 4);
    // 00422c9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422c9e  7507                   -jne 0x422ca7
    if (!cpu.flags.zf)
    {
        goto L_0x00422ca7;
    }
    // 00422ca0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00422ca2  e8e9010000             -call 0x422e90
    cpu.esp -= 4;
    sub_422e90(app, cpu);
    if (cpu.terminate) return;
L_0x00422ca7:
    // 00422ca7  807c240c03             +cmp byte ptr [esp + 0xc], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422cac  7514                   -jne 0x422cc2
    if (!cpu.flags.zf)
    {
        goto L_0x00422cc2;
    }
    // 00422cae  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422cb2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00422cb5  8b048548694d00         -mov eax, dword ptr [eax*4 + 0x4d6948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5073224) /* 0x4d6948 */ + cpu.eax * 4);
    // 00422cbc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422cbd  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422cbf  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00422cc2:
    // 00422cc2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00422cc4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00422cc7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422cc8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422cc9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422cca  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00422ccd:
    // 00422ccd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00422ccf  0f8dfcfdffff           -jge 0x422ad1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00422ad1;
    }
    // 00422cd5  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00422cd7  e9f5fdffff             -jmp 0x422ad1
    goto L_0x00422ad1;
L_0x00422cdc:
    // 00422cdc  3ddc050000             +cmp eax, 0x5dc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1500 /*0x5dc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422ce1  7606                   -jbe 0x422ce9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00422ce9;
    }
    // 00422ce3  c701dc050000           -mov dword ptr [ecx], 0x5dc
    app->getMemory<x86::reg32>(cpu.ecx) = 1500 /*0x5dc*/;
L_0x00422ce9:
    // 00422ce9  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00422ceb  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00422cf2  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00422cf4  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00422cf7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00422cf9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00422cfc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00422cfe  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422d01  01d8                   +add eax, ebx
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
    // 00422d03  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00422d05  e91ffeffff             -jmp 0x422b29
    goto L_0x00422b29;
L_0x00422d0a:
    // 00422d0a  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00422d0e  0fbe1b                 -movsx ebx, byte ptr [ebx]
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebx)));
    // 00422d11  83c330                 +add ebx, 0x30
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00422d14  e9eafeffff             -jmp 0x422c03
    goto L_0x00422c03;
L_0x00422d19:
    // 00422d19  8b7504                 -mov esi, dword ptr [ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00422d1c  3bb02c6a4d00           +cmp esi, dword ptr [eax + 0x4d6a2c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073452) /* 0x4d6a2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422d22  0f8517ffffff           -jne 0x422c3f
    if (!cpu.flags.zf)
    {
        goto L_0x00422c3f;
    }
    // 00422d28  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00422d2b  3bb8306a4d00           +cmp edi, dword ptr [eax + 0x4d6a30]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073456) /* 0x4d6a30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422d31  0f8508ffffff           -jne 0x422c3f
    if (!cpu.flags.zf)
    {
        goto L_0x00422c3f;
    }
    // 00422d37  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00422d3a  3b88346a4d00           +cmp ecx, dword ptr [eax + 0x4d6a34]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073460) /* 0x4d6a34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422d40  0f85f9feffff           -jne 0x422c3f
    if (!cpu.flags.zf)
    {
        goto L_0x00422c3f;
    }
    // 00422d46  e92dffffff             -jmp 0x422c78
    goto L_0x00422c78;
L_0x00422d4b:
    // 00422d4b  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422d4f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00422d52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422d53  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00422d55  8b0c8548694d00         -mov ecx, dword ptr [eax*4 + 0x4d6948]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5073224) /* 0x4d6948 */ + cpu.eax * 4);
    // 00422d5c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422d5f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00422d61  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422d64  05c0694d00             -add eax, 0x4d69c0
    (cpu.eax) += x86::reg32(x86::sreg32(5073344 /*0x4d69c0*/));
    // 00422d69  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422d6a  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00422d6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422d6d  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422d70  8a7c240c               -mov bh, byte ptr [esp + 0xc]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00422d74  80ff01                 +cmp bh, 1
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422d77  752e                   -jne 0x422da7
    if (!cpu.flags.zf)
    {
        goto L_0x00422da7;
    }
L_0x00422d79:
    // 00422d79  8b542406               -mov edx, dword ptr [esp + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422d7d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00422d80  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00422d82  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422d85  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00422d87  8b0485406a4d00         -mov eax, dword ptr [eax*4 + 0x4d6a40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5073472) /* 0x4d6a40 */ + cpu.eax * 4);
    // 00422d8e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422d90  751c                   -jne 0x422dae
    if (!cpu.flags.zf)
    {
        goto L_0x00422dae;
    }
    // 00422d92  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00422d94  e8f7000000             -call 0x422e90
    cpu.esp -= 4;
    sub_422e90(app, cpu);
    if (cpu.terminate) return;
L_0x00422d99:
    // 00422d99  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00422d9e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00422da1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422da2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422da3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422da4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00422da7:
    // 00422da7  80ff02                 +cmp bh, 2
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422daa  74cd                   -je 0x422d79
    if (cpu.flags.zf)
    {
        goto L_0x00422d79;
    }
    // 00422dac  ebeb                   -jmp 0x422d99
    goto L_0x00422d99;
L_0x00422dae:
    // 00422dae  807c240c03             +cmp byte ptr [esp + 0xc], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422db3  75e4                   -jne 0x422d99
    if (!cpu.flags.zf)
    {
        goto L_0x00422d99;
    }
    // 00422db5  8b049548694d00         -mov eax, dword ptr [edx*4 + 0x4d6948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5073224) /* 0x4d6948 */ + cpu.edx * 4);
    // 00422dbc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422dbd  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422dbf  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422dc2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00422dc7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00422dca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422dcb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422dcc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422dcd  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_422dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422dd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422dd1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422dd2  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00422dd3  8b048548694d00         -mov eax, dword ptr [eax*4 + 0x4d6948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5073224) /* 0x4d6948 */ + cpu.eax * 4);
    // 00422dda  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422ddb  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422ddd  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422de0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422de1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422de2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422df0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422df1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422df2  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422df4  7513                   -jne 0x422e09
    if (!cpu.flags.zf)
    {
        goto L_0x00422e09;
    }
    // 00422df6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00422df8:
    // 00422df8  0fbec2                 -movsx eax, dl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 00422dfb  42                     -inc edx
    (cpu.edx)++;
    // 00422dfc  e8efffffff             -call 0x422df0
    cpu.esp -= 4;
    sub_422df0(app, cpu);
    if (cpu.terminate) return;
    // 00422e01  83fa10                 +cmp edx, 0x10
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
    // 00422e04  7cf2                   -jl 0x422df8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422df8;
    }
    // 00422e06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e07  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422e09:
    // 00422e09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422e0a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422e0b  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00422e0e  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00422e11  83ba48634d0000         +cmp dword ptr [edx + 0x4d6348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5071688) /* 0x4d6348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422e18  751d                   -jne 0x422e37
    if (!cpu.flags.zf)
    {
        goto L_0x00422e37;
    }
L_0x00422e1a:
    // 00422e1a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00422e1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00422e1e:
    // 00422e1e  81c284000000           -add edx, 0x84
    (cpu.edx) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 00422e24  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00422e26  89b2bc694d00           -mov dword ptr [edx + 0x4d69bc], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5073340) /* 0x4d69bc */) = cpu.esi;
    // 00422e2c  81fa780f0000           +cmp edx, 0xf78
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3960 /*0xf78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422e32  75ea                   -jne 0x422e1e
    if (!cpu.flags.zf)
    {
        goto L_0x00422e1e;
    }
    // 00422e34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e35  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e36  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422e37:
    // 00422e37  0fbec8                 -movsx ecx, al
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00422e3a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00422e3f  8b1d104a4c00           -mov ebx, dword ptr [0x4c4a10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */);
    // 00422e45  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00422e47  85d8                   +test eax, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebx));
    // 00422e49  74cf                   -je 0x422e1a
    if (cpu.flags.zf)
    {
        goto L_0x00422e1a;
    }
    // 00422e4b  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00422e4d  8b8248634d00           -mov eax, dword ptr [edx + 0x4d6348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5071688) /* 0x4d6348 */);
    // 00422e53  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422e54  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422e56  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422e59  ebbf                   -jmp 0x422e1a
    goto L_0x00422e1a;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422e60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422e61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422e62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422e63  0fbfd8                 -movsx ebx, ax
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00422e66  8b049d48694d00         -mov eax, dword ptr [ebx*4 + 0x4d6948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5073224) /* 0x4d6948 */ + cpu.ebx * 4);
    // 00422e6d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422e6e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422e70  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422e73  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00422e75  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422e78  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00422e7a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00422e7c  31da                   -xor edx, ebx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00422e7e  891485406a4d00         -mov dword ptr [eax*4 + 0x4d6a40], edx
    app->getMemory<x86::reg32>(x86::reg32(5073472) /* 0x4d6a40 */ + cpu.eax * 4) = cpu.edx;
    // 00422e85  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e87  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422e90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422e91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422e92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422e93  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00422e95  0fbfd8                 -movsx ebx, ax
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00422e98  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00422e9a  8b049d48694d00         -mov eax, dword ptr [ebx*4 + 0x4d6948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5073224) /* 0x4d6948 */ + cpu.ebx * 4);
    // 00422ea1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422ea2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422ea4  ff521c                 -call dword ptr [edx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422ea7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00422ea9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00422eab  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422eae  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00422eb0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422eb3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00422eb5  750e                   -jne 0x422ec5
    if (!cpu.flags.zf)
    {
        goto L_0x00422ec5;
    }
    // 00422eb7  c780406a4d0001000000   -mov dword ptr [eax + 0x4d6a40], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073472) /* 0x4d6a40 */) = 1 /*0x1*/;
    // 00422ec1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422ec2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422ec3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422ec4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422ec5:
    // 00422ec5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00422ec7  8990406a4d00           -mov dword ptr [eax + 0x4d6a40], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073472) /* 0x4d6a40 */) = cpu.edx;
    // 00422ecd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422ece  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422ecf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422ed0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422f14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00422f14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422f15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422f16  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422f17  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422f18  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422f19  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 00422f1b  833d184a4c001e         +cmp dword ptr [0x4c4a18], 0x1e
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422f22  0f8dd5010000           -jge 0x4230fd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004230fd;
    }
    // 00422f28  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00422f2b  833c8548634d0000       +cmp dword ptr [eax*4 + 0x4d6348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071688) /* 0x4d6348 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422f33  0f84c4010000           -je 0x4230fd
    if (cpu.flags.zf)
    {
        goto L_0x004230fd;
    }
    // 00422f39  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00422f3e  0fbecb                 -movsx ecx, bl
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00422f41  8b3d104a4c00           -mov edi, dword ptr [0x4c4a10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */);
    // 00422f47  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00422f49  85f8                   +test eax, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edi));
    // 00422f4b  0f84ac010000           -je 0x4230fd
    if (cpu.flags.zf)
    {
        goto L_0x004230fd;
    }
    // 00422f51  8b6a34                 -mov ebp, dword ptr [edx + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    // 00422f54  81fdffffff00           +cmp ebp, 0xffffff
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422f5a  0f85a8010000           -jne 0x423108
    if (!cpu.flags.zf)
    {
        goto L_0x00423108;
    }
    // 00422f60  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
L_0x00422f65:
    // 00422f65  8b35184a4c00           -mov esi, dword ptr [0x4c4a18]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */);
    // 00422f6b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00422f6d  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422f70  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00422f72  890c85c8694d00         -mov dword ptr [eax*4 + 0x4d69c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5073352) /* 0x4d69c8 */ + cpu.eax * 4) = cpu.ecx;
    // 00422f79  8b4a38                 -mov ecx, dword ptr [edx + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    // 00422f7c  890c85d0694d00         -mov dword ptr [eax*4 + 0x4d69d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5073360) /* 0x4d69d0 */ + cpu.eax * 4) = cpu.ecx;
    // 00422f83  8b423a                 -mov eax, dword ptr [edx + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(58) /* 0x3a */);
    // 00422f86  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00422f89  83f8ff                 +cmp eax, -1
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
    // 00422f8c  0f8593010000           -jne 0x423125
    if (!cpu.flags.zf)
    {
        goto L_0x00423125;
    }
    // 00422f92  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00422f94:
    // 00422f94  a1184a4c00             -mov eax, dword ptr [0x4c4a18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */);
    // 00422f99  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00422f9b  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 00422f9e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00422fa0  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00422fa3  89b1d4694d00           -mov dword ptr [ecx + 0x4d69d4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5073364) /* 0x4d69d4 */) = cpu.esi;
    // 00422fa9  8b4240                 -mov eax, dword ptr [edx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 00422fac  8981d8694d00           -mov dword ptr [ecx + 0x4d69d8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5073368) /* 0x4d69d8 */) = cpu.eax;
    // 00422fb2  8b7244                 -mov esi, dword ptr [edx + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */);
    // 00422fb5  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00422fbc  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00422fbe  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00422fc1  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00422fc3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422fc6  8981386a4d00           -mov dword ptr [ecx + 0x4d6a38], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5073464) /* 0x4d6a38 */) = cpu.eax;
    // 00422fcc  807a3c00               +cmp byte ptr [edx + 0x3c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(60) /* 0x3c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422fd0  0f855d010000           -jne 0x423133
    if (!cpu.flags.zf)
    {
        goto L_0x00423133;
    }
L_0x00422fd6:
    // 00422fd6  8b0d184a4c00           -mov ecx, dword ptr [0x4c4a18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */);
    // 00422fdc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422fde  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422fe1  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00422fe6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422fe8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00422fea  b940634d00             -mov ecx, 0x4d6340
    cpu.ecx = 5071680 /*0x4d6340*/;
    // 00422fef  892c85dc694d00         -mov dword ptr [eax*4 + 0x4d69dc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5073372) /* 0x4d69dc */ + cpu.eax * 4) = cpu.ebp;
    // 00422ff6  893540634d00           -mov dword ptr [0x4d6340], esi
    app->getMemory<x86::reg32>(x86::reg32(5071680) /* 0x4d6340 */) = cpu.esi;
    // 00422ffc  890c85e0694d00         -mov dword ptr [eax*4 + 0x4d69e0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5073376) /* 0x4d69e0 */ + cpu.eax * 4) = cpu.ecx;
L_0x00423003:
    // 00423003  8b0d184a4c00           -mov ecx, dword ptr [0x4c4a18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */);
    // 00423009  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042300b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0042300e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00423010  bfc0694d00             -mov edi, 0x4d69c0
    cpu.edi = 5073344 /*0x4d69c0*/;
    // 00423015  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00423018  8d7204                 -lea esi, [edx + 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0042301b  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042301d  b930000000             -mov ecx, 0x30
    cpu.ecx = 48 /*0x30*/;
    // 00423022  83c734                 -add edi, 0x34
    (cpu.edi) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00423025  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423026  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00423028  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0042302b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0042302d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0042302f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00423032  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00423034  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423035  8b0d184a4c00           -mov ecx, dword ptr [0x4c4a18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */);
    // 0042303b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042303d  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00423040  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00423042  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00423045  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00423047  bd22000000             -mov ebp, 0x22
    cpu.ebp = 34 /*0x22*/;
    // 0042304c  8988cc694d00           -mov dword ptr [eax + 0x4d69cc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073356) /* 0x4d69cc */) = cpu.ecx;
    // 00423052  b9c0694d00             -mov ecx, 0x4d69c0
    cpu.ecx = 5073344 /*0x4d69c0*/;
    // 00423057  bf34000000             -mov edi, 0x34
    cpu.edi = 52 /*0x34*/;
    // 0042305c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042305e  89b8c0694d00           -mov dword ptr [eax + 0x4d69c0], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073344) /* 0x4d69c0 */) = cpu.edi;
    // 00423064  8d3439                 -lea esi, [ecx + edi]
    cpu.esi = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 00423067  89a8c4694d00           -mov dword ptr [eax + 0x4d69c4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073348) /* 0x4d69c4 */) = cpu.ebp;
    // 0042306d  83c178                 -add ecx, 0x78
    (cpu.ecx) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00423070  89b0f0694d00           -mov dword ptr [eax + 0x4d69f0], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073392) /* 0x4d69f0 */) = cpu.esi;
    // 00423076  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00423078  8988e4694d00           -mov dword ptr [eax + 0x4d69e4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073380) /* 0x4d69e4 */) = cpu.ecx;
    // 0042307e  89b83c6a4d00           -mov dword ptr [eax + 0x4d6a3c], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073468) /* 0x4d6a3c */) = cpu.edi;
    // 00423084  89b8e8694d00           -mov dword ptr [eax + 0x4d69e8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073384) /* 0x4d69e8 */) = cpu.edi;
    // 0042308a  89b0f0694d00           -mov dword ptr [eax + 0x4d69f0], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073392) /* 0x4d69f0 */) = cpu.esi;
    // 00423090  89b8406a4d00           -mov dword ptr [eax + 0x4d6a40], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073472) /* 0x4d6a40 */) = cpu.edi;
    // 00423096  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00423098  80f90c                 +cmp cl, 0xc
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(12 /*0xc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042309b  7760                   -ja 0x4230fd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004230fd;
    }
    // 0042309d  81e1ff000000           +and ecx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004230a3  ff248de02e4200         -jmp dword ptr [ecx*4 + 0x422ee0]
    cpu.ip = app->getMemory<x86::reg32>(4337376 + cpu.ecx * 4); goto dynamic_jump;
  case 0x004230aa:
    // 004230aa  c780ec694d0004000000   -mov dword ptr [eax + 0x4d69ec], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073388) /* 0x4d69ec */) = 4 /*0x4*/;
L_0x004230b4:
    // 004230b4  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 004230b7  8b348548634d00         -mov esi, dword ptr [eax*4 + 0x4d6348]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5071688) /* 0x4d6348 */ + cpu.eax * 4);
    // 004230be  a1184a4c00             -mov eax, dword ptr [0x4c4a18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */);
    // 004230c3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004230c6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004230c8  0548694d00             -add eax, 0x4d6948
    (cpu.eax) += x86::reg32(x86::sreg32(5073224 /*0x4d6948*/));
    // 004230cd  8b0d184a4c00           -mov ecx, dword ptr [0x4c4a18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */);
    // 004230d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004230d4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004230d6  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004230d9  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004230db  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004230de  05c0694d00             -add eax, 0x4d69c0
    (cpu.eax) += x86::reg32(x86::sreg32(5073344 /*0x4d69c0*/));
    // 004230e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004230e4  0fbe02                 -movsx eax, byte ptr [edx]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx)));
    // 004230e7  8b2c85401a4200         -mov ebp, dword ptr [eax*4 + 0x421a40]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4332096) /* 0x421a40 */ + cpu.eax * 4);
    // 004230ee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004230ef  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004230f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004230f2  ff5748                 -call dword ptr [edi + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004230f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004230f7  0f8416010000           -je 0x423213
    if (cpu.flags.zf)
    {
        goto L_0x00423213;
    }
L_0x004230fd:
    // 004230fd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00423102  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423103  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423104  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423105  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423106  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423107  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423108:
    // 00423108  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 0042310f  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00423111  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00423114  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00423116  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00423119  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0042311b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0042311e  01c1                   +add ecx, eax
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
    // 00423120  e940feffff             -jmp 0x422f65
    goto L_0x00422f65;
L_0x00423125:
    // 00423125  8b723a                 -mov esi, dword ptr [edx + 0x3a]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(58) /* 0x3a */);
    // 00423128  c1fe18                 -sar esi, 0x18
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (24 /*0x18*/ % 32));
    // 0042312b  83c630                 +add esi, 0x30
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042312e  e961feffff             -jmp 0x422f94
    goto L_0x00422f94;
L_0x00423133:
    // 00423133  0fbef3                 -movsx esi, bl
    cpu.esi = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00423136  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0042313d  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0042313f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00423142  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00423144  f6048590634d0002       +test byte ptr [eax*4 + 0x4d6390], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5071760) /* 0x4d6390 */ + cpu.eax * 4) & 2 /*0x2*/));
    // 0042314c  0f8584feffff           -jne 0x422fd6
    if (!cpu.flags.zf)
    {
        goto L_0x00422fd6;
    }
    // 00423152  807a3c01               +cmp byte ptr [edx + 0x3c], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(60) /* 0x3c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423156  7526                   -jne 0x42317e
    if (!cpu.flags.zf)
    {
        goto L_0x0042317e;
    }
    // 00423158  be40634d00             -mov esi, 0x4d6340
    cpu.esi = 5071680 /*0x4d6340*/;
    // 0042315d  bf04000000             -mov edi, 4
    cpu.edi = 4 /*0x4*/;
    // 00423162  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00423167  89b1e0694d00           -mov dword ptr [ecx + 0x4d69e0], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5073376) /* 0x4d69e0 */) = cpu.esi;
    // 0042316d  893d40634d00           -mov dword ptr [0x4d6340], edi
    app->getMemory<x86::reg32>(x86::reg32(5071680) /* 0x4d6340 */) = cpu.edi;
    // 00423173  8981dc694d00           -mov dword ptr [ecx + 0x4d69dc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5073372) /* 0x4d69dc */) = cpu.eax;
    // 00423179  e985feffff             -jmp 0x423003
    goto L_0x00423003;
L_0x0042317e:
    // 0042317e  be40634d00             -mov esi, 0x4d6340
    cpu.esi = 5071680 /*0x4d6340*/;
    // 00423183  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 00423188  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0042318a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0042318f  893d40634d00           -mov dword ptr [0x4d6340], edi
    app->getMemory<x86::reg32>(x86::reg32(5071680) /* 0x4d6340 */) = cpu.edi;
    // 00423195  89b1e0694d00           -mov dword ptr [ecx + 0x4d69e0], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5073376) /* 0x4d69e0 */) = cpu.esi;
    // 0042319b  892d44634d00           -mov dword ptr [0x4d6344], ebp
    app->getMemory<x86::reg32>(x86::reg32(5071684) /* 0x4d6344 */) = cpu.ebp;
    // 004231a1  8981dc694d00           -mov dword ptr [ecx + 0x4d69dc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5073372) /* 0x4d69dc */) = cpu.eax;
    // 004231a7  e957feffff             -jmp 0x423003
    goto L_0x00423003;
  case 0x004231ac:
    // 004231ac  c780ec694d0008000000   -mov dword ptr [eax + 0x4d69ec], 8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073388) /* 0x4d69ec */) = 8 /*0x8*/;
    // 004231b6  e9f9feffff             -jmp 0x4230b4
    goto L_0x004230b4;
  case 0x004231bb:
    // 004231bb  c780ec694d0010000000   -mov dword ptr [eax + 0x4d69ec], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073388) /* 0x4d69ec */) = 16 /*0x10*/;
    // 004231c5  e9eafeffff             -jmp 0x4230b4
    goto L_0x004230b4;
  case 0x004231ca:
    // 004231ca  8b0d184a4c00           -mov ecx, dword ptr [0x4c4a18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */);
    // 004231d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004231d2  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004231d5  01c8                   +add eax, ecx
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
    // 004231d7  c70485ec694d0010000000 -mov dword ptr [eax*4 + 0x4d69ec], 0x10
    app->getMemory<x86::reg32>(x86::reg32(5073388) /* 0x4d69ec */ + cpu.eax * 4) = 16 /*0x10*/;
    // 004231e2  e9cdfeffff             -jmp 0x4230b4
    goto L_0x004230b4;
  case 0x004231e7:
    // 004231e7  8b0d184a4c00           -mov ecx, dword ptr [0x4c4a18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */);
    // 004231ed  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004231ef  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004231f2  01c8                   +add eax, ecx
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
    // 004231f4  c70485ec694d0018000000 -mov dword ptr [eax*4 + 0x4d69ec], 0x18
    app->getMemory<x86::reg32>(x86::reg32(5073388) /* 0x4d69ec */ + cpu.eax * 4) = 24 /*0x18*/;
    // 004231ff  e9b0feffff             -jmp 0x4230b4
    goto L_0x004230b4;
  case 0x00423204:
    // 00423204  c780ec694d0030000000   -mov dword ptr [eax + 0x4d69ec], 0x30
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5073388) /* 0x4d69ec */) = 48 /*0x30*/;
    // 0042320e  e9a1feffff             -jmp 0x4230b4
    goto L_0x004230b4;
L_0x00423213:
    // 00423213  66a1184a4c00           -mov ax, word ptr [0x4c4a18]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(4999704) /* 0x4c4a18 */);
    // 00423219  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0042321a  8b048548694d00         -mov eax, dword ptr [eax*4 + 0x4d6948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5073224) /* 0x4d6948 */ + cpu.eax * 4);
    // 00423221  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423222  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00423224  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00423227  a1184a4c00             -mov eax, dword ptr [0x4c4a18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */);
    // 0042322c  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0042322f  8915184a4c00           -mov dword ptr [0x4c4a18], edx
    app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */) = cpu.edx;
    // 00423235  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423236  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423237  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423238  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423239  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042323a  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423240  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423241  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423242  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423243  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423244  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423245  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00423248  88442414               -mov byte ptr [esp + 0x14], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.al;
    // 0042324c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0042324e  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423250  751b                   -jne 0x42326d
    if (!cpu.flags.zf)
    {
        goto L_0x0042326d;
    }
    // 00423252  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00423254:
    // 00423254  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00423257  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00423259  43                     -inc ebx
    (cpu.ebx)++;
    // 0042325a  e8e1ffffff             -call 0x423240
    cpu.esp -= 4;
    sub_423240(app, cpu);
    if (cpu.terminate) return;
    // 0042325f  83fb10                 +cmp ebx, 0x10
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
    // 00423262  7cf0                   -jl 0x423254
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00423254;
    }
L_0x00423264:
    // 00423264  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00423267  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423268  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423269  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042326a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042326b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042326c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042326d:
    // 0042326d  8b4c2411               -mov ecx, dword ptr [esp + 0x11]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(17) /* 0x11 */);
    // 00423271  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00423276  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00423279  8b15104a4c00           -mov edx, dword ptr [0x4c4a10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */);
    // 0042327f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00423281  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 00423283  0f849e000000           -je 0x423327
    if (cpu.flags.zf)
    {
        goto L_0x00423327;
    }
L_0x00423289:
    // 00423289  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
    // 0042328e  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00423293  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00423295  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00423299  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0042329d  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004232a1  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004232a4  83fe64                 +cmp esi, 0x64
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004232a7  0f8e98000000           -jle 0x423345
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00423345;
    }
    // 004232ad  c744241010270000       -mov dword ptr [esp + 0x10], 0x2710
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 10000 /*0x2710*/;
L_0x004232b5:
    // 004232b5  8b35184a4c00           -mov esi, dword ptr [0x4c4a18]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */);
    // 004232bb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004232bd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004232bf  7e1b                   -jle 0x4232dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004232dc;
    }
L_0x004232c1:
    // 004232c1  0fbfc3                 -movsx eax, bx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 004232c4  8b048548694d00         -mov eax, dword ptr [eax*4 + 0x4d6948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5073224) /* 0x4d6948 */ + cpu.eax * 4);
    // 004232cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004232cc  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004232ce  43                     -inc ebx
    (cpu.ebx)++;
    // 004232cf  ff562c                 -call dword ptr [esi + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004232d2  3b1d184a4c00           +cmp ebx, dword ptr [0x4c4a18]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004232d8  7ce7                   -jl 0x4232c1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004232c1;
    }
    // 004232da  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004232dc:
    // 004232dc  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004232de  8b442411               -mov eax, dword ptr [esp + 0x11]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(17) /* 0x11 */);
    // 004232e2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004232e3  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004232e6  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 004232e8  8b048548634d00         -mov eax, dword ptr [eax*4 + 0x4d6348]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5071688) /* 0x4d6348 */ + cpu.eax * 4);
    // 004232ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004232f0  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004232f2  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004232f5  8b2d184a4c00           -mov ebp, dword ptr [0x4c4a18]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */);
    // 004232fb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004232fd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004232ff  0f8e5fffffff           -jle 0x423264
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00423264;
    }
L_0x00423305:
    // 00423305  0fbfc3                 -movsx eax, bx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00423308  8b048548694d00         -mov eax, dword ptr [eax*4 + 0x4d6948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5073224) /* 0x4d6948 */ + cpu.eax * 4);
    // 0042330f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423310  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00423312  43                     -inc ebx
    (cpu.ebx)++;
    // 00423313  ff5628                 -call dword ptr [esi + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00423316  3b1d184a4c00           +cmp ebx, dword ptr [0x4c4a18]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4999704) /* 0x4c4a18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042331c  7ce7                   -jl 0x423305
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00423305;
    }
    // 0042331e  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00423321  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423322  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423323  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423324  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423325  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423326  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423327:
    // 00423327  8b442411               -mov eax, dword ptr [esp + 0x11]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(17) /* 0x11 */);
    // 0042332b  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0042332e  833c8548634d0000       +cmp dword ptr [eax*4 + 0x4d6348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5071688) /* 0x4d6348 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423336  0f854dffffff           -jne 0x423289
    if (!cpu.flags.zf)
    {
        goto L_0x00423289;
    }
    // 0042333c  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0042333f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423340  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423341  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423342  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423343  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423344  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423345:
    // 00423345  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00423347  7c1a                   -jl 0x423363
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00423363;
    }
    // 00423349  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00423350  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00423352  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00423355  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00423357  c1e002                 +shl eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0042335a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0042335e  e952ffffff             -jmp 0x4232b5
    goto L_0x004232b5;
L_0x00423363:
    // 00423363  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00423367  e949ffffff             -jmp 0x4232b5
    goto L_0x004232b5;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_423370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423370  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423371  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423372  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423373  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423375  7515                   -jne 0x42338c
    if (!cpu.flags.zf)
    {
        goto L_0x0042338c;
    }
    // 00423377  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00423379:
    // 00423379  0fbec2                 -movsx eax, dl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 0042337c  42                     -inc edx
    (cpu.edx)++;
    // 0042337d  e8eeffffff             -call 0x423370
    cpu.esp -= 4;
    sub_423370(app, cpu);
    if (cpu.terminate) return;
    // 00423382  83fa10                 +cmp edx, 0x10
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
    // 00423385  7cf2                   -jl 0x423379
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00423379;
    }
    // 00423387  90                     -nop 
    ;
L_0x00423388:
    // 00423388  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423389  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042338a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042338b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042338c:
    // 0042338c  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0042338f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00423392  83ba48634d0000         +cmp dword ptr [edx + 0x4d6348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5071688) /* 0x4d6348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423399  74ed                   -je 0x423388
    if (cpu.flags.zf)
    {
        goto L_0x00423388;
    }
    // 0042339b  0fbec8                 -movsx ecx, al
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0042339e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004233a3  8b1d104a4c00           -mov ebx, dword ptr [0x4c4a10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */);
    // 004233a9  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004233ab  85d8                   +test eax, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebx));
    // 004233ad  74d9                   -je 0x423388
    if (cpu.flags.zf)
    {
        goto L_0x00423388;
    }
    // 004233af  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004233b1  8b8248634d00           -mov eax, dword ptr [edx + 0x4d6348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5071688) /* 0x4d6348 */);
    // 004233b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004233b8  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004233ba  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004233bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004233be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004233bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004233c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4233d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004233d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004233d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004233d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004233d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004233d4  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004233d6  7521                   -jne 0x4233f9
    if (!cpu.flags.zf)
    {
        goto L_0x004233f9;
    }
    // 004233d8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004233da:
    // 004233da  0fbed1                 -movsx edx, cl
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.cl));
    // 004233dd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004233df  e80cfaffff             -call 0x422df0
    cpu.esp -= 4;
    sub_422df0(app, cpu);
    if (cpu.terminate) return;
    // 004233e4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004233e6  41                     -inc ecx
    (cpu.ecx)++;
    // 004233e7  e8e4ffffff             -call 0x4233d0
    cpu.esp -= 4;
    sub_4233d0(app, cpu);
    if (cpu.terminate) return;
    // 004233ec  83f910                 +cmp ecx, 0x10
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
    // 004233ef  7ce9                   -jl 0x4233da
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004233da;
    }
    // 004233f1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004233f4:
    // 004233f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004233f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004233f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004233f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004233f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004233f9:
    // 004233f9  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 004233fc  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 00423403  83bb48634d0000         +cmp dword ptr [ebx + 0x4d6348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5071688) /* 0x4d6348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042340a  74e8                   -je 0x4233f4
    if (cpu.flags.zf)
    {
        goto L_0x004233f4;
    }
    // 0042340c  0fbec8                 -movsx ecx, al
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0042340f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00423414  8b35104a4c00           -mov esi, dword ptr [0x4c4a10]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */);
    // 0042341a  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0042341c  85f0                   +test eax, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.esi));
    // 0042341e  74d4                   -je 0x4233f4
    if (cpu.flags.zf)
    {
        goto L_0x004233f4;
    }
    // 00423420  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00423422  e8c9f9ffff             -call 0x422df0
    cpu.esp -= 4;
    sub_422df0(app, cpu);
    if (cpu.terminate) return;
    // 00423427  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00423429  8b9348634d00           -mov edx, dword ptr [ebx + 0x4d6348]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5071688) /* 0x4d6348 */);
    // 0042342f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423430  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00423432  ff5058                 -call dword ptr [eax + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00423435  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423436  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423437  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423438  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423439  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423441  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423442  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423443  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423445  7515                   -jne 0x42345c
    if (!cpu.flags.zf)
    {
        goto L_0x0042345c;
    }
    // 00423447  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00423449:
    // 00423449  0fbec2                 -movsx eax, dl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 0042344c  42                     -inc edx
    (cpu.edx)++;
    // 0042344d  e8eeffffff             -call 0x423440
    cpu.esp -= 4;
    sub_423440(app, cpu);
    if (cpu.terminate) return;
    // 00423452  83fa10                 +cmp edx, 0x10
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
    // 00423455  7cf2                   -jl 0x423449
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00423449;
    }
    // 00423457  90                     -nop 
    ;
L_0x00423458:
    // 00423458  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423459  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042345a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042345b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042345c:
    // 0042345c  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0042345f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00423462  83ba48634d0000         +cmp dword ptr [edx + 0x4d6348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5071688) /* 0x4d6348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423469  74ed                   -je 0x423458
    if (cpu.flags.zf)
    {
        goto L_0x00423458;
    }
    // 0042346b  0fbec8                 -movsx ecx, al
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0042346e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00423473  8b1d104a4c00           -mov ebx, dword ptr [0x4c4a10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */);
    // 00423479  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0042347b  85d8                   +test eax, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebx));
    // 0042347d  74d9                   -je 0x423458
    if (cpu.flags.zf)
    {
        goto L_0x00423458;
    }
    // 0042347f  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00423481  8b8248634d00           -mov eax, dword ptr [edx + 0x4d6348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5071688) /* 0x4d6348 */);
    // 00423487  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423488  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042348a  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042348d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042348e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042348f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423490  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4234a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004234a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004234a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004234a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004234a3  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004234a5  7515                   -jne 0x4234bc
    if (!cpu.flags.zf)
    {
        goto L_0x004234bc;
    }
    // 004234a7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004234a9:
    // 004234a9  0fbec2                 -movsx eax, dl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 004234ac  42                     -inc edx
    (cpu.edx)++;
    // 004234ad  e8eeffffff             -call 0x4234a0
    cpu.esp -= 4;
    sub_4234a0(app, cpu);
    if (cpu.terminate) return;
    // 004234b2  83fa10                 +cmp edx, 0x10
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
    // 004234b5  7cf2                   -jl 0x4234a9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004234a9;
    }
    // 004234b7  90                     -nop 
    ;
L_0x004234b8:
    // 004234b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004234b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004234ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004234bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004234bc:
    // 004234bc  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 004234bf  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004234c2  83ba48634d0000         +cmp dword ptr [edx + 0x4d6348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5071688) /* 0x4d6348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004234c9  74ed                   -je 0x4234b8
    if (cpu.flags.zf)
    {
        goto L_0x004234b8;
    }
    // 004234cb  0fbec8                 -movsx ecx, al
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 004234ce  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004234d3  8b1d104a4c00           -mov ebx, dword ptr [0x4c4a10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */);
    // 004234d9  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004234db  85d8                   +test eax, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebx));
    // 004234dd  74d9                   -je 0x4234b8
    if (cpu.flags.zf)
    {
        goto L_0x004234b8;
    }
    // 004234df  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004234e1  8b8248634d00           -mov eax, dword ptr [edx + 0x4d6348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5071688) /* 0x4d6348 */);
    // 004234e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004234e8  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004234ea  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004234ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004234ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004234ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004234f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423500  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423501  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423502  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423503  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423504  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423505  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423506  833d144a4c0000         +cmp dword ptr [0x4c4a14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999700) /* 0x4c4a14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042350d  7447                   -je 0x423556
    if (cpu.flags.zf)
    {
        goto L_0x00423556;
    }
L_0x0042350f:
    // 0042350f  833d104a4c0000         +cmp dword ptr [0x4c4a10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423516  7432                   -je 0x42354a
    if (cpu.flags.zf)
    {
        goto L_0x0042354a;
    }
    // 00423518  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042351a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0042351c:
    // 0042351c  8bbe48634d00           -mov edi, dword ptr [esi + 0x4d6348]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5071688) /* 0x4d6348 */);
    // 00423522  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00423524  741b                   -je 0x423541
    if (cpu.flags.zf)
    {
        goto L_0x00423541;
    }
    // 00423526  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042352b  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0042352d  8b2d104a4c00           -mov ebp, dword ptr [0x4c4a10]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */);
    // 00423533  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00423535  85e8                   +test eax, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebp));
    // 00423537  7408                   -je 0x423541
    if (cpu.flags.zf)
    {
        goto L_0x00423541;
    }
    // 00423539  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042353b  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0042353d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042353e  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00423541:
    // 00423541  43                     -inc ebx
    (cpu.ebx)++;
    // 00423542  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423545  83fb10                 +cmp ebx, 0x10
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
    // 00423548  7cd2                   -jl 0x42351c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042351c;
    }
L_0x0042354a:
    // 0042354a  a1104a4c00             -mov eax, dword ptr [0x4c4a10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999696) /* 0x4c4a10 */);
    // 0042354f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423550  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423551  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423552  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423553  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423554  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423555  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423556:
    // 00423556  e895eeffff             -call 0x4223f0
    cpu.esp -= 4;
    sub_4223f0(app, cpu);
    if (cpu.terminate) return;
    // 0042355b  ebb2                   -jmp 0x42350f
    goto L_0x0042350f;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_423560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423560  e9fbf2ffff             -jmp 0x422860
    return sub_422860(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423570  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423580  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423581  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423582  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423583  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423584  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423585  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423586  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423589  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042358b  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0042358e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00423590  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00423593  8b1d244a4c00           -mov ebx, dword ptr [0x4c4a24]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */);
    // 00423599  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042359b  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0042359d  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004235a0  83f901                 +cmp ecx, 1
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
    // 004235a3  0f8599000000           -jne 0x423642
    if (!cpu.flags.zf)
    {
        goto L_0x00423642;
    }
    // 004235a9  8b1d204a4c00           -mov ebx, dword ptr [0x4c4a20]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 004235af  8b7310                 -mov esi, dword ptr [ebx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004235b2  8b7c1a34               -mov edi, dword ptr [edx + ebx + 0x34]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */ + cpu.ebx * 1);
    // 004235b6  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004235b8  8d1437                 -lea edx, [edi + esi]
    cpu.edx = x86::reg32(cpu.edi + cpu.esi * 1);
    // 004235bb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004235bd  39f2                   +cmp edx, esi
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
    // 004235bf  7e05                   -jle 0x4235c6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004235c6;
    }
    // 004235c1  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004235c3  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004235c5  41                     -inc ecx
    (cpu.ecx)++;
L_0x004235c6:
    // 004235c6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004235c8  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004235cb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004235cd  8b2d244a4c00           -mov ebp, dword ptr [0x4c4a24]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */);
    // 004235d3  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004235d6  8b1d204a4c00           -mov ebx, dword ptr [0x4c4a20]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 004235dc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004235de  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004235e1  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004235e4  8d4328                 -lea eax, [ebx + 0x28]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004235e7  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004235eb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004235ed  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004235ef  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004235f2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004235f4  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004235f6  e805e00500             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 004235fb  39f1                   +cmp ecx, esi
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
    // 004235fd  7c0f                   -jl 0x42360e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042360e;
    }
L_0x004235ff:
    // 004235ff  a1244a4c00             -mov eax, dword ptr [0x4c4a24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */);
    // 00423604  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423607  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423608  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423609  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042360a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042360b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042360c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042360d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042360e:
    // 0042360e  a1244a4c00             -mov eax, dword ptr [0x4c4a24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */);
    // 00423613  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423616  8d1408                 -lea edx, [eax + ecx]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 00423619  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0042361b  a1204a4c00             -mov eax, dword ptr [0x4c4a20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 00423620  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00423624  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00423627  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00423629  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042362b  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0042362e  e8cddf0500             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00423633  a1244a4c00             -mov eax, dword ptr [0x4c4a24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */);
    // 00423638  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042363b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042363c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042363d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042363e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042363f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423640  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423641  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423642:
    // 00423642  a1204a4c00             -mov eax, dword ptr [0x4c4a20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 00423647  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0042364b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042364d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042364f  8b5c0228               -mov ebx, dword ptr [edx + eax + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */ + cpu.eax * 1);
L_0x00423653:
    // 00423653  8b35244a4c00           -mov esi, dword ptr [0x4c4a24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */);
    // 00423659  3b2e                   +cmp ebp, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042365b  7da2                   -jge 0x4235ff
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004235ff;
    }
    // 0042365d  8b3d204a4c00           -mov edi, dword ptr [0x4c4a20]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 00423663  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00423665  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00423667  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0042366a  f77f04                 -idiv dword ptr [edi + 4]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042366d  6bd234                 -imul edx, edx, 0x34
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(52 /*0x34*/)));
    // 00423670  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00423674  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00423677  8d5728                 -lea edx, [edi + 0x28]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0042367a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042367c  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0042367f  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423682  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00423684  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423687  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042368a  8d3c0e                 -lea edi, [esi + ecx]
    cpu.edi = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0042368d  45                     -inc ebp
    (cpu.ebp)++;
    // 0042368e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00423690  43                     -inc ebx
    (cpu.ebx)++;
    // 00423691  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423692:
    // 00423692  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423694  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423696  3c00                   +cmp al, 0
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
    // 00423698  7410                   -je 0x4236aa
    if (cpu.flags.zf)
    {
        goto L_0x004236aa;
    }
    // 0042369a  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0042369d  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004236a0  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004236a3  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004236a6  3c00                   +cmp al, 0
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
    // 004236a8  75e8                   -jne 0x423692
    if (!cpu.flags.zf)
    {
        goto L_0x00423692;
    }
L_0x004236aa:
    // 004236aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004236ab  83c126                 +add ecx, 0x26
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004236ae  eba3                   -jmp 0x423653
    goto L_0x00423653;
}

/* align: skip  */
void Application::sub_4236b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004236b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004236b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004236b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004236b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004236b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004236b5  8b35204a4c00           -mov esi, dword ptr [0x4c4a20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 004236bb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004236bd  833d284a4c0000         +cmp dword ptr [0x4c4a28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999720) /* 0x4c4a28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004236c4  0f8482000000           -je 0x42374c
    if (cpu.flags.zf)
    {
        goto L_0x0042374c;
    }
    // 004236ca  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004236cd  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004236cf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004236d2  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004236d4  8d4e28                 -lea ecx, [esi + 0x28]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004236d7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004236da  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004236dc  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004236df  3b4104                 +cmp eax, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004236e2  740d                   -je 0x4236f1
    if (cpu.flags.zf)
    {
        goto L_0x004236f1;
    }
L_0x004236e4:
    // 004236e4  6bd034                 -imul edx, eax, 0x34
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(52 /*0x34*/)));
    // 004236e7  8b5c1114               -mov ebx, dword ptr [ecx + edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */ + cpu.edx * 1);
    // 004236eb  3b5c1110               +cmp ebx, dword ptr [ecx + edx + 0x10]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.edx * 1)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004236ef  745f                   -je 0x423750
    if (cpu.flags.zf)
    {
        goto L_0x00423750;
    }
L_0x004236f1:
    // 004236f1  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004236f8  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004236fa  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004236fd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004236ff  8d590c                 -lea ebx, [ecx + 0xc]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00423702  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00423705  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00423707  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0042370a  3b5a04                 +cmp ebx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042370d  743d                   -je 0x42374c
    if (cpu.flags.zf)
    {
        goto L_0x0042374c;
    }
    // 0042370f  4b                     -dec ebx
    (cpu.ebx)--;
    // 00423710  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00423713  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00423715  7c4b                   -jl 0x423762
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00423762;
    }
L_0x00423717:
    // 00423717  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042371a  035208                 -add edx, dword ptr [edx + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0042371d  c6420c00               -mov byte ptr [edx + 0xc], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00423721  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00423724  8935204a4c00           -mov dword ptr [0x4c4a20], esi
    app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */) = cpu.esi;
    // 0042372a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042372c  7407                   -je 0x423735
    if (cpu.flags.zf)
    {
        goto L_0x00423735;
    }
    // 0042372e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00423730  e83bfeffff             -call 0x423570
    cpu.esp -= 4;
    sub_423570(app, cpu);
    if (cpu.terminate) return;
L_0x00423735:
    // 00423735  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042373a  8b35204a4c00           -mov esi, dword ptr [0x4c4a20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
L_0x00423740:
    // 00423740  8935204a4c00           -mov dword ptr [0x4c4a20], esi
    app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */) = cpu.esi;
    // 00423746  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423747  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423748  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423749  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042374a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042374b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042374c:
    // 0042374c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042374e  ebf0                   -jmp 0x423740
    goto L_0x00423740;
L_0x00423750:
    // 00423750  48                     -dec eax
    (cpu.eax)--;
    // 00423751  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423753  7c07                   -jl 0x42375c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042375c;
    }
L_0x00423755:
    // 00423755  3b4104                 +cmp eax, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423758  758a                   -jne 0x4236e4
    if (!cpu.flags.zf)
    {
        goto L_0x004236e4;
    }
    // 0042375a  eb95                   -jmp 0x4236f1
    goto L_0x004236f1;
L_0x0042375c:
    // 0042375c  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042375f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00423760  ebf3                   -jmp 0x423755
    goto L_0x00423755;
L_0x00423762:
    // 00423762  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00423764  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00423767  ebae                   -jmp 0x423717
    goto L_0x00423717;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423770  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423771  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423772  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423775  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00423777  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
    // 0042377a  833d284a4c0000         +cmp dword ptr [0x4c4a28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999720) /* 0x4c4a28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423781  0f849a000000           -je 0x423821
    if (cpu.flags.zf)
    {
        goto L_0x00423821;
    }
    // 00423787  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423788  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423789  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042378a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0042378c  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 0042378f  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00423791  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 00423794  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00423796  8b35204a4c00           -mov esi, dword ptr [0x4c4a20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 0042379c  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0042379f  8d3c2e                 -lea edi, [esi + ebp]
    cpu.edi = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 004237a2  8b5730                 -mov edx, dword ptr [edi + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 004237a5  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 004237ac  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004237ae  8d4628                 -lea eax, [esi + 0x28]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004237b1  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004237b4  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004237b6  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004237b8  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004237bb  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004237be  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004237c0  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004237c3  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004237c6  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004237c9  8a54240c               -mov dl, byte ptr [esp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004237cd  8854010c               -mov byte ptr [ecx + eax + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.dl;
    // 004237d1  837e0c01               +cmp dword ptr [esi + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004237d5  754e                   -jne 0x423825
    if (!cpu.flags.zf)
    {
        goto L_0x00423825;
    }
    // 004237d7  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004237d9  3b5908                 +cmp ebx, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004237dc  7d07                   -jge 0x4237e5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004237e5;
    }
    // 004237de  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x004237e5:
    // 004237e5  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004237e8  3b7108                 +cmp esi, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004237eb  751a                   -jne 0x423807
    if (!cpu.flags.zf)
    {
        goto L_0x00423807;
    }
    // 004237ed  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004237f0  a1204a4c00             -mov eax, dword ptr [0x4c4a20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 004237f5  897904                 -mov dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004237f8  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004237fa  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004237fc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004237ff  43                     -inc ebx
    (cpu.ebx)++;
    // 00423800  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00423802  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00423804  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00423807:
    // 00423807  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0042380a  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0042380c:
    // 0042380c  034908                 -add ecx, dword ptr [ecx + 8]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 0042380f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00423814  c6410c00               -mov byte ptr [ecx + 0xc], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00423818  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423819  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042381a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042381b:
    // 0042381b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042381e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042381f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423820  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423821:
    // 00423821  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00423823  ebf6                   -jmp 0x42381b
    goto L_0x0042381b;
L_0x00423825:
    // 00423825  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00423827  3b5108                 +cmp edx, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042382a  7541                   -jne 0x42386d
    if (!cpu.flags.zf)
    {
        goto L_0x0042386d;
    }
    // 0042382c  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 0042382f  40                     -inc eax
    (cpu.eax)++;
    // 00423830  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00423832  894730                 -mov dword ptr [edi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00423835  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00423838  f77e04                 -idiv dword ptr [esi + 4]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042383b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042383d  895730                 -mov dword ptr [edi + 0x30], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00423840  e86b000000             -call 0x4238b0
    cpu.esp -= 4;
    sub_4238b0(app, cpu);
    if (cpu.terminate) return;
    // 00423845  8b3d204a4c00           -mov edi, dword ptr [0x4c4a20]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 0042384b  8d342f                 -lea esi, [edi + ebp]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebp * 1);
    // 0042384e  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00423851  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00423854  39d0                   +cmp eax, edx
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
    // 00423856  7515                   -jne 0x42386d
    if (!cpu.flags.zf)
    {
        goto L_0x0042386d;
    }
    // 00423858  8d6a01                 -lea ebp, [edx + 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0042385b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0042385d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0042385f  896e2c                 -mov dword ptr [esi + 0x2c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ebp;
    // 00423862  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00423865  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00423868  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042386a  89562c                 -mov dword ptr [esi + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.edx;
L_0x0042386d:
    // 0042386d  a1204a4c00             -mov eax, dword ptr [0x4c4a20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 00423872  83782000               +cmp dword ptr [eax + 0x20], 0
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
    // 00423876  7407                   -je 0x42387f
    if (cpu.flags.zf)
    {
        goto L_0x0042387f;
    }
    // 00423878  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042387a  e8f1fcffff             -call 0x423570
    cpu.esp -= 4;
    sub_423570(app, cpu);
    if (cpu.terminate) return;
L_0x0042387f:
    // 0042387f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00423881  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00423884  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00423886  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00423889  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0042388b  8b15204a4c00           -mov edx, dword ptr [0x4c4a20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 00423891  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00423894  01d0                   +add eax, edx
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
    // 00423896  8b502c                 -mov edx, dword ptr [eax + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00423899  895028                 -mov dword ptr [eax + 0x28], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0042389c  e96bffffff             -jmp 0x42380c
    goto L_0x0042380c;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4238b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004238b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004238b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004238b2  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004238b4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004238b6  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004238b9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004238bb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004238be  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004238c0  8b1d204a4c00           -mov ebx, dword ptr [0x4c4a20]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 004238c6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004238c9  8d5328                 -lea edx, [ebx + 0x28]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004238cc  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004238cf  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004238d1  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004238d8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004238da  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004238dd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004238df  8d530c                 -lea edx, [ebx + 0xc]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004238e2  c7048200000000         -mov dword ptr [edx + eax*4], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = 0 /*0x0*/;
    // 004238e9  c744820400000000       -mov dword ptr [edx + eax*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) = 0 /*0x0*/;
    // 004238f1  c744820800000000       -mov dword ptr [edx + eax*4 + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */ + cpu.eax * 4) = 0 /*0x0*/;
    // 004238f9  c644820c00             -mov byte ptr [edx + eax*4 + 0xc], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) = 0 /*0x0*/;
    // 004238fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004238ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423900  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423910  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423911  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423912  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00423914  8b35284a4c00           -mov esi, dword ptr [0x4c4a28]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4999720) /* 0x4c4a28 */);
    // 0042391a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042391c  7442                   -je 0x423960
    if (cpu.flags.zf)
    {
        goto L_0x00423960;
    }
    // 0042391e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042391f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423920  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423922  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00423924  8915284a4c00           -mov dword ptr [0x4c4a28], edx
    app->getMemory<x86::reg32>(x86::reg32(4999720) /* 0x4c4a28 */) = cpu.edx;
L_0x0042392a:
    // 0042392a  a1204a4c00             -mov eax, dword ptr [0x4c4a20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 0042392f  3b4804                 +cmp ecx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423932  7c2f                   -jl 0x423963
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00423963;
    }
    // 00423934  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00423936  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 00423939  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0042393b  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0042393e  01d9                   +add ecx, ebx
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
    // 00423940  c744882800000000       -mov dword ptr [eax + ecx*4 + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */ + cpu.ecx * 4) = 0 /*0x0*/;
    // 00423948  c744882c00000000       -mov dword ptr [eax + ecx*4 + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */ + cpu.ecx * 4) = 0 /*0x0*/;
    // 00423950  c744883000000000       -mov dword ptr [eax + ecx*4 + 0x30], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */ + cpu.ecx * 4) = 0 /*0x0*/;
    // 00423958  8935284a4c00           -mov dword ptr [0x4c4a28], esi
    app->getMemory<x86::reg32>(x86::reg32(4999720) /* 0x4c4a28 */) = cpu.esi;
    // 0042395e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042395f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00423960:
    // 00423960  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423961  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423962  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423963:
    // 00423963  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00423965  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00423967  e844ffffff             -call 0x4238b0
    cpu.esp -= 4;
    sub_4238b0(app, cpu);
    if (cpu.terminate) return;
    // 0042396c  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042396d  ebbb                   -jmp 0x42392a
    goto L_0x0042392a;
}

/* align: skip 0x00 */
void Application::sub_423970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423970  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423971  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423973  a1204a4c00             -mov eax, dword ptr [0x4c4a20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 00423978  3b5008                 +cmp edx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042397b  7c02                   -jl 0x42397f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042397f;
    }
    // 0042397d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042397e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042397f:
    // 0042397f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00423981  e88affffff             -call 0x423910
    cpu.esp -= 4;
    sub_423910(app, cpu);
    if (cpu.terminate) return;
    // 00423986  42                     -inc edx
    (cpu.edx)++;
    // 00423987  a1204a4c00             -mov eax, dword ptr [0x4c4a20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 0042398c  3b5008                 +cmp edx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042398f  7cee                   -jl 0x42397f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042397f;
    }
    // 00423991  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423992  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4239a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004239a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004239a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004239a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004239a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004239a4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004239a6  8b0d204a4c00           -mov ecx, dword ptr [0x4c4a20]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 004239ac  8915284a4c00           -mov dword ptr [0x4c4a28], edx
    app->getMemory<x86::reg32>(x86::reg32(4999720) /* 0x4c4a28 */) = cpu.edx;
    // 004239b2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004239b4  751d                   -jne 0x4239d3
    if (!cpu.flags.zf)
    {
        goto L_0x004239d3;
    }
L_0x004239b6:
    // 004239b6  8b1d244a4c00           -mov ebx, dword ptr [0x4c4a24]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */);
    // 004239bc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004239be  751c                   -jne 0x4239dc
    if (!cpu.flags.zf)
    {
        goto L_0x004239dc;
    }
    // 004239c0  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004239c2  8935204a4c00           -mov dword ptr [0x4c4a20], esi
    app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */) = cpu.esi;
    // 004239c8  8935244a4c00           -mov dword ptr [0x4c4a24], esi
    app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */) = cpu.esi;
    // 004239ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004239d3:
    // 004239d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004239d5  e8b26c0500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 004239da  ebda                   -jmp 0x4239b6
    goto L_0x004239b6;
L_0x004239dc:
    // 004239dc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004239de  e8a96c0500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 004239e3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004239e5  8935204a4c00           -mov dword ptr [0x4c4a20], esi
    app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */) = cpu.esi;
    // 004239eb  8935244a4c00           -mov dword ptr [0x4c4a24], esi
    app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */) = cpu.esi;
    // 004239f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239f2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423a00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423a00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423a01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423a02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423a03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423a04  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423a05  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423a06  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00423a08  833d204a4c0000         +cmp dword ptr [0x4c4a20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423a0f  0f85fd000000           -jne 0x423b12
    if (!cpu.flags.zf)
    {
        goto L_0x00423b12;
    }
L_0x00423a15:
    // 00423a15  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00423a18  8b690c                 -mov ebp, dword ptr [ecx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00423a1b  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00423a1e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00423a20  740b                   -je 0x423a2d
    if (cpu.flags.zf)
    {
        goto L_0x00423a2d;
    }
    // 00423a22  83fe01                 +cmp esi, 1
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
    // 00423a25  0f8e0f010000           -jle 0x423b3a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00423b3a;
    }
    // 00423a2b  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
L_0x00423a2d:
    // 00423a2d  bbe8aa4b00             -mov ebx, 0x4baae8
    cpu.ebx = 4958952 /*0x4baae8*/;
    // 00423a32  bd74000000             -mov ebp, 0x74
    cpu.ebp = 116 /*0x74*/;
    // 00423a37  bac8100000             -mov edx, 0x10c8
    cpu.edx = 4296 /*0x10c8*/;
    // 00423a3c  b820ab4b00             -mov eax, 0x4bab20
    cpu.eax = 4959008 /*0x4bab20*/;
    // 00423a41  891d78a64c00           -mov dword ptr [0x4ca678], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebx;
    // 00423a47  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00423a4c  892d7ca64c00           -mov dword ptr [0x4ca67c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebp;
    // 00423a52  e8d1670500             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00423a57  a3204a4c00             -mov dword ptr [0x4c4a20], eax
    app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */) = cpu.eax;
    // 00423a5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423a5e  7527                   -jne 0x423a87
    if (!cpu.flags.zf)
    {
        goto L_0x00423a87;
    }
    // 00423a60  68c8100000             -push 0x10c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4296 /*0x10c8*/;
    cpu.esp -= 4;
    // 00423a65  b8e8aa4b00             -mov eax, 0x4baae8
    cpu.eax = 4958952 /*0x4baae8*/;
    // 00423a6a  ba76000000             -mov edx, 0x76
    cpu.edx = 118 /*0x76*/;
    // 00423a6f  6828ab4b00             -push 0x4bab28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4959016 /*0x4bab28*/;
    cpu.esp -= 4;
    // 00423a74  a378a64c00             -mov dword ptr [0x4ca678], eax
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.eax;
    // 00423a79  89157ca64c00           -mov dword ptr [0x4ca67c], edx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.edx;
    // 00423a7f  e8fc630500             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00423a84  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00423a87:
    // 00423a87  bac8100000             -mov edx, 0x10c8
    cpu.edx = 4296 /*0x10c8*/;
    // 00423a8c  a1204a4c00             -mov eax, dword ptr [0x4c4a20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 00423a91  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00423a96  e801d20500             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00423a9b  8b15204a4c00           -mov edx, dword ptr [0x4c4a20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 00423aa1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00423aa3  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00423aa6  e855db0500             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 00423aab  a1204a4c00             -mov eax, dword ptr [0x4c4a20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999712) /* 0x4c4a20 */);
    // 00423ab0  bbe8aa4b00             -mov ebx, 0x4baae8
    cpu.ebx = 4958952 /*0x4baae8*/;
    // 00423ab5  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 00423aba  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00423abd  891d78a64c00           -mov dword ptr [0x4ca678], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebx;
    // 00423ac3  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 00423ac5  be80000000             -mov esi, 0x80
    cpu.esi = 128 /*0x80*/;
    // 00423aca  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00423acf  b848ab4b00             -mov eax, 0x4bab48
    cpu.eax = 4959048 /*0x4bab48*/;
    // 00423ad4  89357ca64c00           -mov dword ptr [0x4ca67c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.esi;
    // 00423ada  e849670500             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00423adf  a3244a4c00             -mov dword ptr [0x4c4a24], eax
    app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */) = cpu.eax;
    // 00423ae4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423ae6  7459                   -je 0x423b41
    if (cpu.flags.zf)
    {
        goto L_0x00423b41;
    }
L_0x00423ae8:
    // 00423ae8  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 00423aed  a1244a4c00             -mov eax, dword ptr [0x4c4a24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */);
    // 00423af2  e8a5d10500             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00423af7  a1244a4c00             -mov eax, dword ptr [0x4c4a24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999716) /* 0x4c4a24 */);
    // 00423afc  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00423aff  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00423b01  c705284a4c0001000000   -mov dword ptr [0x4c4a28], 1
    app->getMemory<x86::reg32>(x86::reg32(4999720) /* 0x4c4a28 */) = 1 /*0x1*/;
    // 00423b0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b0e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423b12:
    // 00423b12  bbe8aa4b00             -mov ebx, 0x4baae8
    cpu.ebx = 4958952 /*0x4baae8*/;
    // 00423b17  be5f000000             -mov esi, 0x5f
    cpu.esi = 95 /*0x5f*/;
    // 00423b1c  6808ab4b00             -push 0x4bab08
    app->getMemory<x86::reg32>(cpu.esp-4) = 4958984 /*0x4bab08*/;
    cpu.esp -= 4;
    // 00423b21  891d78a64c00           -mov dword ptr [0x4ca678], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebx;
    // 00423b27  89357ca64c00           -mov dword ptr [0x4ca67c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.esi;
    // 00423b2d  e84e630500             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00423b32  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00423b35  e9dbfeffff             -jmp 0x423a15
    goto L_0x00423a15;
L_0x00423b3a:
    // 00423b3a  01ef                   +add edi, ebp
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00423b3c  e9ecfeffff             -jmp 0x423a2d
    goto L_0x00423a2d;
L_0x00423b41:
    // 00423b41  6880010000             -push 0x180
    app->getMemory<x86::reg32>(cpu.esp-4) = 384 /*0x180*/;
    cpu.esp -= 4;
    // 00423b46  bfe8aa4b00             -mov edi, 0x4baae8
    cpu.edi = 4958952 /*0x4baae8*/;
    // 00423b4b  bd82000000             -mov ebp, 0x82
    cpu.ebp = 130 /*0x82*/;
    // 00423b50  6828ab4b00             -push 0x4bab28
    app->getMemory<x86::reg32>(cpu.esp-4) = 4959016 /*0x4bab28*/;
    cpu.esp -= 4;
    // 00423b55  893d78a64c00           -mov dword ptr [0x4ca678], edi
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edi;
    // 00423b5b  892d7ca64c00           -mov dword ptr [0x4ca67c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebp;
    // 00423b61  e81a630500             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00423b66  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00423b69  e97affffff             -jmp 0x423ae8
    goto L_0x00423ae8;
}

/* align: skip 0x00 0x00 */
void Application::sub_423b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423b70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423b71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423b72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423b73  81ec00090000           -sub esp, 0x900
    (cpu.esp) -= x86::reg32(x86::sreg32(2304 /*0x900*/));
    // 00423b79  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00423b7b  b854ab4b00             -mov eax, 0x4bab54
    cpu.eax = 4959060 /*0x4bab54*/;
    // 00423b80  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00423b82  e86961feff             -call 0x409cf0
    cpu.esp -= 4;
    sub_409cf0(app, cpu);
    if (cpu.terminate) return;
    // 00423b87  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423b89  e802d5fdff             -call 0x401090
    cpu.esp -= 4;
    sub_401090(app, cpu);
    if (cpu.terminate) return;
    // 00423b8e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00423b90  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00423b93  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00423b95  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00423b97  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00423b99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423b9a  8b1de0074e00           -mov ebx, dword ptr [0x4e07e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5113824) /* 0x4e07e0 */);
    // 00423ba0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423ba1  685cab4b00             -push 0x4bab5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4959068 /*0x4bab5c*/;
    cpu.esp -= 4;
    // 00423ba6  8d8424d8080000         -lea eax, [esp + 0x8d8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2264) /* 0x8d8 */);
    // 00423bad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423bae  e82e840500             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00423bb3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00423bb6  83faff                 +cmp edx, -1
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
    // 00423bb9  750a                   -jne 0x423bc5
    if (!cpu.flags.zf)
    {
        goto L_0x00423bc5;
    }
L_0x00423bbb:
    // 00423bbb  81c400090000           -add esp, 0x900
    (cpu.esp) += x86::reg32(x86::sreg32(2304 /*0x900*/));
    // 00423bc1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423bc2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423bc3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423bc4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423bc5:
    // 00423bc5  68f7020000             -push 0x2f7
    app->getMemory<x86::reg32>(cpu.esp-4) = 759 /*0x2f7*/;
    cpu.esp -= 4;
    // 00423bca  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00423bcc  e8ffdefdff             -call 0x401ad0
    cpu.esp -= 4;
    sub_401ad0(app, cpu);
    if (cpu.terminate) return;
    // 00423bd1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00423bd4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423bd6  74e3                   -je 0x423bbb
    if (cpu.flags.zf)
    {
        goto L_0x00423bbb;
    }
    // 00423bd8  8d8424cc080000         -lea eax, [esp + 0x8cc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2252) /* 0x8cc */);
    // 00423bdf  e8ea960500             -call 0x47d2ce
    cpu.esp -= 4;
    sub_47d2ce(app, cpu);
    if (cpu.terminate) return;
    // 00423be4  b8f8020000             -mov eax, 0x2f8
    cpu.eax = 760 /*0x2f8*/;
    // 00423be9  baa6024e00             -mov edx, 0x4e02a6
    cpu.edx = 5112486 /*0x4e02a6*/;
    // 00423bee  e8adf0fdff             -call 0x402ca0
    cpu.esp -= 4;
    sub_402ca0(app, cpu);
    if (cpu.terminate) return;
    // 00423bf3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00423bf5  e8b6580500             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 00423bfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423bfc  75bd                   -jne 0x423bbb
    if (!cpu.flags.zf)
    {
        goto L_0x00423bbb;
    }
    // 00423bfe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423bff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423c00  be68ab4b00             -mov esi, 0x4bab68
    cpu.esi = 4959080 /*0x4bab68*/;
    // 00423c05  bf7e024e00             -mov edi, 0x4e027e
    cpu.edi = 5112446 /*0x4e027e*/;
    // 00423c0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423c0b:
    // 00423c0b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423c0d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423c0f  3c00                   +cmp al, 0
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
    // 00423c11  7410                   -je 0x423c23
    if (cpu.flags.zf)
    {
        goto L_0x00423c23;
    }
    // 00423c13  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00423c16  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423c19  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423c1c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423c1f  3c00                   +cmp al, 0
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
    // 00423c21  75e8                   -jne 0x423c0b
    if (!cpu.flags.zf)
    {
        goto L_0x00423c0b;
    }
L_0x00423c23:
    // 00423c23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c25  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c26  81c400090000           -add esp, 0x900
    (cpu.esp) += x86::reg32(x86::sreg32(2304 /*0x900*/));
    // 00423c2c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_423c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423c30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423c31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423c32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423c33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423c34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423c35  81ec740a0000           -sub esp, 0xa74
    (cpu.esp) -= x86::reg32(x86::sreg32(2676 /*0xa74*/));
    // 00423c3b  b8ea020000             -mov eax, 0x2ea
    cpu.eax = 746 /*0x2ea*/;
    // 00423c40  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00423c42  e8297effff             -call 0x41ba70
    cpu.esp -= 4;
    sub_41ba70(app, cpu);
    if (cpu.terminate) return;
    // 00423c47  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00423c49  b854ab4b00             -mov eax, 0x4bab54
    cpu.eax = 4959060 /*0x4bab54*/;
    // 00423c4e  e89d60feff             -call 0x409cf0
    cpu.esp -= 4;
    sub_409cf0(app, cpu);
    if (cpu.terminate) return;
    // 00423c53  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423c55  e836d4fdff             -call 0x401090
    cpu.esp -= 4;
    sub_401090(app, cpu);
    if (cpu.terminate) return;
    // 00423c5a  83f8ff                 +cmp eax, -1
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
    // 00423c5d  7437                   -je 0x423c96
    if (cpu.flags.zf)
    {
        goto L_0x00423c96;
    }
    // 00423c5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423c61  0f8590010000           -jne 0x423df7
    if (!cpu.flags.zf)
    {
        goto L_0x00423df7;
    }
    // 00423c67  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00423c6c  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00423c71  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00423c73  baeb020000             -mov edx, 0x2eb
    cpu.edx = 747 /*0x2eb*/;
    // 00423c78  88a424d4090000         -mov byte ptr [esp + 0x9d4], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2516) /* 0x9d4 */) = cpu.ah;
    // 00423c7f  88a424240a0000         -mov byte ptr [esp + 0xa24], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2596) /* 0xa24 */) = cpu.ah;
    // 00423c86  8d8424240a0000         -lea eax, [esp + 0xa24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 00423c8d  e8bee7fdff             -call 0x402450
    cpu.esp -= 4;
    sub_402450(app, cpu);
    if (cpu.terminate) return;
    // 00423c92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423c94  750c                   -jne 0x423ca2
    if (!cpu.flags.zf)
    {
        goto L_0x00423ca2;
    }
L_0x00423c96:
    // 00423c96  81c4740a0000           -add esp, 0xa74
    (cpu.esp) += x86::reg32(x86::sreg32(2676 /*0xa74*/));
    // 00423c9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c9e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ca0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ca1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423ca2:
    // 00423ca2  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00423ca7  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00423cac  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00423cae  8d8424d4090000         -lea eax, [esp + 0x9d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2516) /* 0x9d4 */);
    // 00423cb5  88b424d4090000         -mov byte ptr [esp + 0x9d4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2516) /* 0x9d4 */) = cpu.dh;
    // 00423cbc  bae7020000             -mov edx, 0x2e7
    cpu.edx = 743 /*0x2e7*/;
    // 00423cc1  e88ae7fdff             -call 0x402450
    cpu.esp -= 4;
    sub_402450(app, cpu);
    if (cpu.terminate) return;
    // 00423cc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423cc8  74cc                   -je 0x423c96
    if (cpu.flags.zf)
    {
        goto L_0x00423c96;
    }
    // 00423cca  8d8424d4090000         -lea eax, [esp + 0x9d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2516) /* 0x9d4 */);
    // 00423cd1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423cd2  8b0de0074e00           -mov ecx, dword ptr [0x4e07e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113824) /* 0x4e07e0 */);
    // 00423cd8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423cd9  685cab4b00             -push 0x4bab5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4959068 /*0x4bab5c*/;
    cpu.esp -= 4;
    // 00423cde  8d8424e0080000         -lea eax, [esp + 0x8e0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2272) /* 0x8e0 */);
    // 00423ce5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423ce6  e8f6820500             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00423ceb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00423cee  8d8424d4080000         -lea eax, [esp + 0x8d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2260) /* 0x8d4 */);
    // 00423cf5  e836b00500             -call 0x47ed30
    cpu.esp -= 4;
    sub_47ed30(app, cpu);
    if (cpu.terminate) return;
    // 00423cfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423cfc  0f848a000000           -je 0x423d8c
    if (cpu.flags.zf)
    {
        goto L_0x00423d8c;
    }
    // 00423d02  68f9020000             -push 0x2f9
    app->getMemory<x86::reg32>(cpu.esp-4) = 761 /*0x2f9*/;
    cpu.esp -= 4;
    // 00423d07  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00423d09  e8c2ddfdff             -call 0x401ad0
    cpu.esp -= 4;
    sub_401ad0(app, cpu);
    if (cpu.terminate) return;
    // 00423d0e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00423d11  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423d13  7481                   -je 0x423c96
    if (cpu.flags.zf)
    {
        goto L_0x00423c96;
    }
    // 00423d15  8d8424d4080000         -lea eax, [esp + 0x8d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2260) /* 0x8d4 */);
    // 00423d1c  8d9424240a0000         -lea edx, [esp + 0xa24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 00423d23  8db424240a0000         -lea esi, [esp + 0xa24]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 00423d2a  e89f950500             -call 0x47d2ce
    cpu.esp -= 4;
    sub_47d2ce(app, cpu);
    if (cpu.terminate) return;
    // 00423d2f  8d8424d4080000         -lea eax, [esp + 0x8d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2260) /* 0x8d4 */);
    // 00423d36  bf7e024e00             -mov edi, 0x4e027e
    cpu.edi = 5112446 /*0x4e027e*/;
    // 00423d3b  e890010000             -call 0x423ed0
    cpu.esp -= 4;
    sub_423ed0(app, cpu);
    if (cpu.terminate) return;
    // 00423d40  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423d41:
    // 00423d41  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423d43  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423d45  3c00                   +cmp al, 0
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
    // 00423d47  7410                   -je 0x423d59
    if (cpu.flags.zf)
    {
        goto L_0x00423d59;
    }
    // 00423d49  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00423d4c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423d4f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423d52  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423d55  3c00                   +cmp al, 0
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
    // 00423d57  75e8                   -jne 0x423d41
    if (!cpu.flags.zf)
    {
        goto L_0x00423d41;
    }
L_0x00423d59:
    // 00423d59  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d5a  8db424d4090000         -lea esi, [esp + 0x9d4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(2516) /* 0x9d4 */);
    // 00423d61  bfa6024e00             -mov edi, 0x4e02a6
    cpu.edi = 5112486 /*0x4e02a6*/;
    // 00423d66  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423d67:
    // 00423d67  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423d69  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423d6b  3c00                   +cmp al, 0
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
    // 00423d6d  7410                   -je 0x423d7f
    if (cpu.flags.zf)
    {
        goto L_0x00423d7f;
    }
    // 00423d6f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00423d72  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423d75  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423d78  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423d7b  3c00                   +cmp al, 0
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
    // 00423d7d  75e8                   -jne 0x423d67
    if (!cpu.flags.zf)
    {
        goto L_0x00423d67;
    }
L_0x00423d7f:
    // 00423d7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d80  81c4740a0000           -add esp, 0xa74
    (cpu.esp) += x86::reg32(x86::sreg32(2676 /*0xa74*/));
    // 00423d86  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d88  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d8b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423d8c:
    // 00423d8c  8d9424240a0000         -lea edx, [esp + 0xa24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 00423d93  8d8424d4080000         -lea eax, [esp + 0x8d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2260) /* 0x8d4 */);
    // 00423d9a  8db424240a0000         -lea esi, [esp + 0xa24]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 00423da1  bf7e024e00             -mov edi, 0x4e027e
    cpu.edi = 5112446 /*0x4e027e*/;
    // 00423da6  e825010000             -call 0x423ed0
    cpu.esp -= 4;
    sub_423ed0(app, cpu);
    if (cpu.terminate) return;
    // 00423dab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423dac:
    // 00423dac  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423dae  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423db0  3c00                   +cmp al, 0
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
    // 00423db2  7410                   -je 0x423dc4
    if (cpu.flags.zf)
    {
        goto L_0x00423dc4;
    }
    // 00423db4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00423db7  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423dba  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423dbd  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423dc0  3c00                   +cmp al, 0
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
    // 00423dc2  75e8                   -jne 0x423dac
    if (!cpu.flags.zf)
    {
        goto L_0x00423dac;
    }
L_0x00423dc4:
    // 00423dc4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423dc5  8db424d4090000         -lea esi, [esp + 0x9d4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(2516) /* 0x9d4 */);
    // 00423dcc  bfa6024e00             -mov edi, 0x4e02a6
    cpu.edi = 5112486 /*0x4e02a6*/;
    // 00423dd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423dd2:
    // 00423dd2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423dd4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423dd6  3c00                   +cmp al, 0
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
    // 00423dd8  7410                   -je 0x423dea
    if (cpu.flags.zf)
    {
        goto L_0x00423dea;
    }
    // 00423dda  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00423ddd  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423de0  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423de3  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423de6  3c00                   +cmp al, 0
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
    // 00423de8  75e8                   -jne 0x423dd2
    if (!cpu.flags.zf)
    {
        goto L_0x00423dd2;
    }
L_0x00423dea:
    // 00423dea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423deb  81c4740a0000           -add esp, 0xa74
    (cpu.esp) += x86::reg32(x86::sreg32(2676 /*0xa74*/));
    // 00423df1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423df2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423df3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423df4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423df5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423df6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423df7:
    // 00423df7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00423df9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00423dfc  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00423dfe  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00423e00  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00423e02  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423e03  8b15e0074e00           -mov edx, dword ptr [0x4e07e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113824) /* 0x4e07e0 */);
    // 00423e09  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423e0a  685cab4b00             -push 0x4bab5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4959068 /*0x4bab5c*/;
    cpu.esp -= 4;
    // 00423e0f  8d8424e0080000         -lea eax, [esp + 0x8e0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2272) /* 0x8e0 */);
    // 00423e16  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423e17  8db424340a0000         -lea esi, [esp + 0xa34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(2612) /* 0xa34 */);
    // 00423e1e  8d9424340a0000         -lea edx, [esp + 0xa34]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(2612) /* 0xa34 */);
    // 00423e25  e8b7810500             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00423e2a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00423e2d  8d8424d4080000         -lea eax, [esp + 0x8d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2260) /* 0x8d4 */);
    // 00423e34  bf7e024e00             -mov edi, 0x4e027e
    cpu.edi = 5112446 /*0x4e027e*/;
    // 00423e39  e852000000             -call 0x423e90
    cpu.esp -= 4;
    sub_423e90(app, cpu);
    if (cpu.terminate) return;
    // 00423e3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423e3f:
    // 00423e3f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423e41  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423e43  3c00                   +cmp al, 0
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
    // 00423e45  7410                   -je 0x423e57
    if (cpu.flags.zf)
    {
        goto L_0x00423e57;
    }
    // 00423e47  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00423e4a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423e4d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423e50  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423e53  3c00                   +cmp al, 0
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
    // 00423e55  75e8                   -jne 0x423e3f
    if (!cpu.flags.zf)
    {
        goto L_0x00423e3f;
    }
L_0x00423e57:
    // 00423e57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423e58  bfa6024e00             -mov edi, 0x4e02a6
    cpu.edi = 5112486 /*0x4e02a6*/;
    // 00423e5d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00423e5f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423e60:
    // 00423e60  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423e62  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423e64  3c00                   +cmp al, 0
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
    // 00423e66  7410                   -je 0x423e78
    if (cpu.flags.zf)
    {
        goto L_0x00423e78;
    }
    // 00423e68  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00423e6b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423e6e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423e71  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423e74  3c00                   +cmp al, 0
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
    // 00423e76  75e8                   -jne 0x423e60
    if (!cpu.flags.zf)
    {
        goto L_0x00423e60;
    }
L_0x00423e78:
    // 00423e78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423e79  81c4740a0000           -add esp, 0xa74
    (cpu.esp) += x86::reg32(x86::sreg32(2676 /*0xa74*/));
    // 00423e7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423e80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423e81  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423e82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423e83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423e84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423e90  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423e91  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00423e93  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423e95  e8c6890500             -call 0x47c860
    cpu.esp -= 4;
    sub_47c860(app, cpu);
    if (cpu.terminate) return;
    // 00423e9a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00423e9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423e9e  7502                   -jne 0x423ea2
    if (!cpu.flags.zf)
    {
        goto L_0x00423ea2;
    }
    // 00423ea0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ea1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423ea2:
    // 00423ea2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423ea3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00423ea5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423ea6:
    // 00423ea6  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423ea8  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423eaa  3c00                   +cmp al, 0
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
    // 00423eac  7410                   -je 0x423ebe
    if (cpu.flags.zf)
    {
        goto L_0x00423ebe;
    }
    // 00423eae  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00423eb1  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423eb4  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423eb7  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423eba  3c00                   +cmp al, 0
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
    // 00423ebc  75e8                   -jne 0x423ea6
    if (!cpu.flags.zf)
    {
        goto L_0x00423ea6;
    }
L_0x00423ebe:
    // 00423ebe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ebf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00423ec1  e8c6670500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00423ec6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ec7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ec8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423ed0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423ed1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423ed2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423ed3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423ed4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00423ed6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00423ed8  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00423eda  49                     -dec ecx
    (cpu.ecx)--;
    // 00423edb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00423edd  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00423edf  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00423ee1  49                     -dec ecx
    (cpu.ecx)--;
    // 00423ee2  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00423ee5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00423ee7  e8e48f0500             -call 0x47ced0
    cpu.esp -= 4;
    sub_47ced0(app, cpu);
    if (cpu.terminate) return;
    // 00423eec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423eee  7405                   -je 0x423ef5
    if (cpu.flags.zf)
    {
        goto L_0x00423ef5;
    }
    // 00423ef0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ef1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ef2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ef3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ef4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423ef5:
    // 00423ef5  b8f3020000             -mov eax, 0x2f3
    cpu.eax = 755 /*0x2f3*/;
    // 00423efa  e8a1edfdff             -call 0x402ca0
    cpu.esp -= 4;
    sub_402ca0(app, cpu);
    if (cpu.terminate) return;
    // 00423eff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423f00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423f01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423f02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423f03  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423f10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423f11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423f12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423f13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423f14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423f15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423f16  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423f19  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00423f1b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00423f1d  890d64794d00           -mov dword ptr [0x4d7964], ecx
    app->getMemory<x86::reg32>(x86::reg32(5077348) /* 0x4d7964 */) = cpu.ecx;
    // 00423f23  e868c5ffff             -call 0x420490
    cpu.esp -= 4;
    sub_420490(app, cpu);
    if (cpu.terminate) return;
    // 00423f28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423f2a  0f84ba000000           -je 0x423fea
    if (cpu.flags.zf)
    {
        goto L_0x00423fea;
    }
    // 00423f30  8b1d2c4a4c00           -mov ebx, dword ptr [0x4c4a2c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999724) /* 0x4c4a2c */);
    // 00423f36  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00423f38  7407                   -je 0x423f41
    if (cpu.flags.zf)
    {
        goto L_0x00423f41;
    }
    // 00423f3a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00423f3c  e84b670500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x00423f41:
    // 00423f41  be6cab4b00             -mov esi, 0x4bab6c
    cpu.esi = 4959084 /*0x4bab6c*/;
    // 00423f46  bf8f000000             -mov edi, 0x8f
    cpu.edi = 143 /*0x8f*/;
    // 00423f4b  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00423f50  ba6c0c0000             -mov edx, 0xc6c
    cpu.edx = 3180 /*0xc6c*/;
    // 00423f55  b890ab4b00             -mov eax, 0x4bab90
    cpu.eax = 4959120 /*0x4bab90*/;
    // 00423f5a  893578a64c00           -mov dword ptr [0x4ca678], esi
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.esi;
    // 00423f60  893d7ca64c00           -mov dword ptr [0x4ca67c], edi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.edi;
    // 00423f66  e8bd620500             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00423f6b  a32c4a4c00             -mov dword ptr [0x4c4a2c], eax
    app->getMemory<x86::reg32>(x86::reg32(4999724) /* 0x4c4a2c */) = cpu.eax;
    // 00423f70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423f72  0f8472000000           -je 0x423fea
    if (cpu.flags.zf)
    {
        goto L_0x00423fea;
    }
    // 00423f78  69e9d4000000           -imul ebp, ecx, 0xd4
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(212 /*0xd4*/)));
L_0x00423f7e:
    // 00423f7e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00423f80  bbd4000000             -mov ebx, 0xd4
    cpu.ebx = 212 /*0xd4*/;
    // 00423f85  e806c5ffff             -call 0x420490
    cpu.esp -= 4;
    sub_420490(app, cpu);
    if (cpu.terminate) return;
    // 00423f8a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00423f8c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00423f8f  a12c4a4c00             -mov eax, dword ptr [0x4c4a2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999724) /* 0x4c4a2c */);
    // 00423f94  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423f96  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00423f98  e812530600             -call 0x4892af
    cpu.esp -= 4;
    sub_4892af(app, cpu);
    if (cpu.terminate) return;
    // 00423f9d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00423f9f  7422                   -je 0x423fc3
    if (cpu.flags.zf)
    {
        goto L_0x00423fc3;
    }
    // 00423fa1  8b3d2c4a4c00           -mov edi, dword ptr [0x4c4a2c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4999724) /* 0x4c4a2c */);
    // 00423fa7  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00423fa9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423faa:
    // 00423faa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423fac  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423fae  3c00                   +cmp al, 0
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
    // 00423fb0  7410                   -je 0x423fc2
    if (cpu.flags.zf)
    {
        goto L_0x00423fc2;
    }
    // 00423fb2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00423fb5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423fb8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423fbb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423fbe  3c00                   +cmp al, 0
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
    // 00423fc0  75e8                   -jne 0x423faa
    if (!cpu.flags.zf)
    {
        goto L_0x00423faa;
    }
L_0x00423fc2:
    // 00423fc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00423fc3:
    // 00423fc3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00423fc6  41                     -inc ecx
    (cpu.ecx)++;
    // 00423fc7  81c5d4000000           -add ebp, 0xd4
    (cpu.ebp) += x86::reg32(x86::sreg32(212 /*0xd4*/));
    // 00423fcd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423fcf  7405                   -je 0x423fd6
    if (cpu.flags.zf)
    {
        goto L_0x00423fd6;
    }
    // 00423fd1  83f90e                 +cmp ecx, 0xe
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423fd4  7ca8                   -jl 0x423f7e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00423f7e;
    }
L_0x00423fd6:
    // 00423fd6  a12c4a4c00             -mov eax, dword ptr [0x4c4a2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999724) /* 0x4c4a2c */);
    // 00423fdb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423fdd  49                     -dec ecx
    (cpu.ecx)--;
    // 00423fde  891560794d00           -mov dword ptr [0x4d7960], edx
    app->getMemory<x86::reg32>(x86::reg32(5077344) /* 0x4d7960 */) = cpu.edx;
    // 00423fe4  890d64794d00           -mov dword ptr [0x4d7964], ecx
    app->getMemory<x86::reg32>(x86::reg32(5077348) /* 0x4d7964 */) = cpu.ecx;
L_0x00423fea:
    // 00423fea  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423fed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423fee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423fef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ff0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ff1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ff2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ff3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_424000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424000  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424001  833d2c4a4c0000         +cmp dword ptr [0x4c4a2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999724) /* 0x4c4a2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00424008  743d                   -je 0x424047
    if (cpu.flags.zf)
    {
        goto L_0x00424047;
    }
    // 0042400a  8b0d64794d00           -mov ecx, dword ptr [0x4d7964]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5077348) /* 0x4d7964 */);
    // 00424010  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00424012  7433                   -je 0x424047
    if (cpu.flags.zf)
    {
        goto L_0x00424047;
    }
    // 00424014  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424015  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424016  8b1d60794d00           -mov ebx, dword ptr [0x4d7960]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5077344) /* 0x4d7960 */);
    // 0042401c  43                     -inc ebx
    (cpu.ebx)++;
    // 0042401d  891d60794d00           -mov dword ptr [0x4d7960], ebx
    app->getMemory<x86::reg32>(x86::reg32(5077344) /* 0x4d7960 */) = cpu.ebx;
    // 00424023  39cb                   +cmp ebx, ecx
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
    // 00424025  7c0a                   -jl 0x424031
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00424031;
    }
    // 00424027  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00424028  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042402a  893d60794d00           -mov dword ptr [0x4d7960], edi
    app->getMemory<x86::reg32>(x86::reg32(5077344) /* 0x4d7960 */) = cpu.edi;
    // 00424030  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00424031:
    // 00424031  690560794d00d4000000   -imul eax, dword ptr [0x4d7960], 0xd4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5077344) /* 0x4d7960 */))) * x86::sreg64(x86::sreg32(212 /*0xd4*/)));
    // 0042403b  8b152c4a4c00           -mov edx, dword ptr [0x4c4a2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999724) /* 0x4c4a2c */);
    // 00424041  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00424043  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424044  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424045  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424046  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00424047:
    // 00424047  e8c4feffff             -call 0x423f10
    cpu.esp -= 4;
    sub_423f10(app, cpu);
    if (cpu.terminate) return;
    // 0042404c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042404d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_424050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424050  a160794d00             -mov eax, dword ptr [0x4d7960]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077344) /* 0x4d7960 */);
    // 00424055  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_424060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424061  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424062  e88d3e0500             -call 0x477ef4
    cpu.esp -= 4;
    sub_477ef4(app, cpu);
    if (cpu.terminate) return;
    // 00424067  8b1d047b4d00           -mov ebx, dword ptr [0x4d7b04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5077764) /* 0x4d7b04 */);
    // 0042406d  8b15007b4d00           -mov edx, dword ptr [0x4d7b00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5077760) /* 0x4d7b00 */);
    // 00424073  a1f87a4d00             -mov eax, dword ptr [0x4d7af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077752) /* 0x4d7af8 */);
    // 00424078  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0042407b  83ea0a                 -sub edx, 0xa
    (cpu.edx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0042407e  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00424081  e8ce530500             -call 0x479454
    cpu.esp -= 4;
    sub_479454(app, cpu);
    if (cpu.terminate) return;
    // 00424086  e87d3e0500             -call 0x477f08
    cpu.esp -= 4;
    sub_477f08(app, cpu);
    if (cpu.terminate) return;
    // 0042408b  8b1d047b4d00           -mov ebx, dword ptr [0x4d7b04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5077764) /* 0x4d7b04 */);
    // 00424091  8b15007b4d00           -mov edx, dword ptr [0x4d7b00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5077760) /* 0x4d7b00 */);
    // 00424097  a1f87a4d00             -mov eax, dword ptr [0x4d7af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077752) /* 0x4d7af8 */);
    // 0042409c  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0042409f  83ea0a                 -sub edx, 0xa
    (cpu.edx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004240a2  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004240a5  e8aa530500             -call 0x479454
    cpu.esp -= 4;
    sub_479454(app, cpu);
    if (cpu.terminate) return;
    // 004240aa  e86d3e0500             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 004240af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004240b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004240b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4240c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004240c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004240c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004240c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004240c3  bb384a4c00             -mov ebx, 0x4c4a38
    cpu.ebx = 4999736 /*0x4c4a38*/;
    // 004240c8  ba344a4c00             -mov edx, 0x4c4a34
    cpu.edx = 4999732 /*0x4c4a34*/;
    // 004240cd  b83c4a4c00             -mov eax, 0x4c4a3c
    cpu.eax = 4999740 /*0x4c4a3c*/;
    // 004240d2  e869e4ffff             -call 0x422540
    cpu.esp -= 4;
    sub_422540(app, cpu);
    if (cpu.terminate) return;
    // 004240d7  833df87a4d0000         +cmp dword ptr [0x4d7af8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5077752) /* 0x4d7af8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004240de  741c                   -je 0x4240fc
    if (cpu.flags.zf)
    {
        goto L_0x004240fc;
    }
    // 004240e0  8b0d344a4c00           -mov ecx, dword ptr [0x4c4a34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 004240e6  3b0d007b4d00           +cmp ecx, dword ptr [0x4d7b00]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5077760) /* 0x4d7b00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004240ec  7526                   -jne 0x424114
    if (!cpu.flags.zf)
    {
        goto L_0x00424114;
    }
    // 004240ee  8b1d384a4c00           -mov ebx, dword ptr [0x4c4a38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */);
    // 004240f4  3b1d047b4d00           +cmp ebx, dword ptr [0x4d7b04]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5077764) /* 0x4d7b04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004240fa  7518                   -jne 0x424114
    if (!cpu.flags.zf)
    {
        goto L_0x00424114;
    }
L_0x004240fc:
    // 004240fc  a1344a4c00             -mov eax, dword ptr [0x4c4a34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 00424101  a3007b4d00             -mov dword ptr [0x4d7b00], eax
    app->getMemory<x86::reg32>(x86::reg32(5077760) /* 0x4d7b00 */) = cpu.eax;
    // 00424106  a1384a4c00             -mov eax, dword ptr [0x4c4a38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */);
    // 0042410b  a3047b4d00             -mov dword ptr [0x4d7b04], eax
    app->getMemory<x86::reg32>(x86::reg32(5077764) /* 0x4d7b04 */) = cpu.eax;
    // 00424110  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424111  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424112  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424113  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00424114:
    // 00424114  baa8ab4b00             -mov edx, 0x4baba8
    cpu.edx = 4959144 /*0x4baba8*/;
    // 00424119  a1304a4c00             -mov eax, dword ptr [0x4c4a30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999728) /* 0x4c4a30 */);
    // 0042411e  e841480500             -call 0x478964
    cpu.esp -= 4;
    sub_478964(app, cpu);
    if (cpu.terminate) return;
    // 00424123  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00424125  e8ca3d0500             -call 0x477ef4
    cpu.esp -= 4;
    sub_477ef4(app, cpu);
    if (cpu.terminate) return;
    // 0042412a  8b1d047b4d00           -mov ebx, dword ptr [0x4d7b04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5077764) /* 0x4d7b04 */);
    // 00424130  8b15007b4d00           -mov edx, dword ptr [0x4d7b00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5077760) /* 0x4d7b00 */);
    // 00424136  a1f87a4d00             -mov eax, dword ptr [0x4d7af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077752) /* 0x4d7af8 */);
    // 0042413b  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0042413e  83ea0a                 -sub edx, 0xa
    (cpu.edx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00424141  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00424144  e80b530500             -call 0x479454
    cpu.esp -= 4;
    sub_479454(app, cpu);
    if (cpu.terminate) return;
    // 00424149  8b1d384a4c00           -mov ebx, dword ptr [0x4c4a38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */);
    // 0042414f  8b15344a4c00           -mov edx, dword ptr [0x4c4a34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 00424155  a1f87a4d00             -mov eax, dword ptr [0x4d7af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077752) /* 0x4d7af8 */);
    // 0042415a  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0042415d  83ea0a                 -sub edx, 0xa
    (cpu.edx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00424160  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00424163  e8b8510500             -call 0x479320
    cpu.esp -= 4;
    sub_479320(app, cpu);
    if (cpu.terminate) return;
    // 00424168  8b1d384a4c00           -mov ebx, dword ptr [0x4c4a38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */);
    // 0042416e  8b15344a4c00           -mov edx, dword ptr [0x4c4a34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 00424174  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00424176  83ea07                 +sub edx, 7
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00424179  e83e4c0500             -call 0x478dbc
    cpu.esp -= 4;
    sub_478dbc(app, cpu);
    if (cpu.terminate) return;
    // 0042417e  e8993d0500             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 00424183  e974ffffff             -jmp 0x4240fc
    goto L_0x004240fc;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_424190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424190  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424191  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424192  bb384a4c00             -mov ebx, 0x4c4a38
    cpu.ebx = 4999736 /*0x4c4a38*/;
    // 00424197  ba344a4c00             -mov edx, 0x4c4a34
    cpu.edx = 4999732 /*0x4c4a34*/;
    // 0042419c  b83c4a4c00             -mov eax, 0x4c4a3c
    cpu.eax = 4999740 /*0x4c4a3c*/;
    // 004241a1  e89ae3ffff             -call 0x422540
    cpu.esp -= 4;
    sub_422540(app, cpu);
    if (cpu.terminate) return;
    // 004241a6  833df87a4d0000         +cmp dword ptr [0x4d7af8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5077752) /* 0x4d7af8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004241ad  7517                   -jne 0x4241c6
    if (!cpu.flags.zf)
    {
        goto L_0x004241c6;
    }
L_0x004241af:
    // 004241af  a1344a4c00             -mov eax, dword ptr [0x4c4a34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 004241b4  a3007b4d00             -mov dword ptr [0x4d7b00], eax
    app->getMemory<x86::reg32>(x86::reg32(5077760) /* 0x4d7b00 */) = cpu.eax;
    // 004241b9  a1384a4c00             -mov eax, dword ptr [0x4c4a38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */);
    // 004241be  a3047b4d00             -mov dword ptr [0x4d7b04], eax
    app->getMemory<x86::reg32>(x86::reg32(5077764) /* 0x4d7b04 */) = cpu.eax;
    // 004241c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004241c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004241c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004241c6:
    // 004241c6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004241c7  baa8ab4b00             -mov edx, 0x4baba8
    cpu.edx = 4959144 /*0x4baba8*/;
    // 004241cc  a1304a4c00             -mov eax, dword ptr [0x4c4a30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999728) /* 0x4c4a30 */);
    // 004241d1  e88e470500             -call 0x478964
    cpu.esp -= 4;
    sub_478964(app, cpu);
    if (cpu.terminate) return;
    // 004241d6  8b1d384a4c00           -mov ebx, dword ptr [0x4c4a38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */);
    // 004241dc  8b15344a4c00           -mov edx, dword ptr [0x4c4a34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 004241e2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004241e4  a1f87a4d00             -mov eax, dword ptr [0x4d7af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077752) /* 0x4d7af8 */);
    // 004241e9  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004241ec  83ea0a                 -sub edx, 0xa
    (cpu.edx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004241ef  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004241f2  e829510500             -call 0x479320
    cpu.esp -= 4;
    sub_479320(app, cpu);
    if (cpu.terminate) return;
    // 004241f7  8b1d384a4c00           -mov ebx, dword ptr [0x4c4a38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */);
    // 004241fd  8b15344a4c00           -mov edx, dword ptr [0x4c4a34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 00424203  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00424205  83ea07                 +sub edx, 7
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00424208  e8af4b0500             -call 0x478dbc
    cpu.esp -= 4;
    sub_478dbc(app, cpu);
    if (cpu.terminate) return;
    // 0042420d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042420e  eb9f                   -jmp 0x4241af
    goto L_0x004241af;
}

/* align: skip  */
void Application::sub_424210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424210  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424211  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424212  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424213  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00424214  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00424215  8b15304a4c00           -mov edx, dword ptr [0x4c4a30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999728) /* 0x4c4a30 */);
    // 0042421b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042421d  752b                   -jne 0x42424a
    if (!cpu.flags.zf)
    {
        goto L_0x0042424a;
    }
L_0x0042421f:
    // 0042421f  8b1df87a4d00           -mov ebx, dword ptr [0x4d7af8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5077752) /* 0x4d7af8 */);
    // 00424225  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00424227  7411                   -je 0x42423a
    if (cpu.flags.zf)
    {
        goto L_0x0042423a;
    }
    // 00424229  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042422a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042422c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042422e  e81d460500             -call 0x478850
    cpu.esp -= 4;
    sub_478850(app, cpu);
    if (cpu.terminate) return;
    // 00424233  8935f87a4d00           -mov dword ptr [0x4d7af8], esi
    app->getMemory<x86::reg32>(x86::reg32(5077752) /* 0x4d7af8 */) = cpu.esi;
    // 00424239  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042423a:
    // 0042423a  8b3dfc7a4d00           -mov edi, dword ptr [0x4d7afc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5077756) /* 0x4d7afc */);
    // 00424240  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00424242  7517                   -jne 0x42425b
    if (!cpu.flags.zf)
    {
        goto L_0x0042425b;
    }
    // 00424244  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424245  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424246  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424247  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424248  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424249  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042424a:
    // 0042424a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042424c  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0042424e  e839640500             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00424253  890d304a4c00           -mov dword ptr [0x4c4a30], ecx
    app->getMemory<x86::reg32>(x86::reg32(4999728) /* 0x4c4a30 */) = cpu.ecx;
    // 00424259  ebc4                   -jmp 0x42421f
    goto L_0x0042421f;
L_0x0042425b:
    // 0042425b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042425d  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042425f  e8ec450500             -call 0x478850
    cpu.esp -= 4;
    sub_478850(app, cpu);
    if (cpu.terminate) return;
    // 00424264  892dfc7a4d00           -mov dword ptr [0x4d7afc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5077756) /* 0x4d7afc */) = cpu.ebp;
    // 0042426a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042426b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042426c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042426d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042426e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042426f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_424270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424271  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424272  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424273  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00424274  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00424275  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00424276  8b1d344a4c00           -mov ebx, dword ptr [0x4c4a34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 0042427c  8b35384a4c00           -mov esi, dword ptr [0x4c4a38]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */);
    // 00424282  668b3d067c4d00         -mov di, word ptr [0x4d7c06]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(5078022) /* 0x4d7c06 */);
    // 00424289  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0042428b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042428d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0042428f:
    // 0042428f  0fbfd7                 -movsx edx, di
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.di));
    // 00424292  39d1                   +cmp ecx, edx
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
    // 00424294  0f8daf000000           -jge 0x424349
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00424349;
    }
    // 0042429a  8b90567a4d00           -mov edx, dword ptr [eax + 0x4d7a56]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5077590) /* 0x4d7a56 */);
    // 004242a0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004242a3  39d6                   +cmp esi, edx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004242a5  7f06                   -jg 0x4242ad
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004242ad;
    }
L_0x004242a7:
    // 004242a7  41                     -inc ecx
    (cpu.ecx)++;
    // 004242a8  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004242ab  ebe2                   -jmp 0x42428f
    goto L_0x0042428f;
L_0x004242ad:
    // 004242ad  8b90067a4d00           -mov edx, dword ptr [eax + 0x4d7a06]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5077510) /* 0x4d7a06 */);
    // 004242b3  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004242b6  39d6                   +cmp esi, edx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004242b8  7ded                   -jge 0x4242a7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004242a7;
    }
    // 004242ba  8b90b6794d00           -mov edx, dword ptr [eax + 0x4d79b6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5077430) /* 0x4d79b6 */);
    // 004242c0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004242c3  39d3                   +cmp ebx, edx
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
    // 004242c5  7ee0                   -jle 0x4242a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004242a7;
    }
    // 004242c7  8b9066794d00           -mov edx, dword ptr [eax + 0x4d7966]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5077350) /* 0x4d7966 */);
    // 004242cd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004242d0  39d3                   +cmp ebx, edx
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
    // 004242d2  7dd3                   -jge 0x4242a7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004242a7;
    }
    // 004242d4  891d344a4c00           -mov dword ptr [0x4c4a34], ebx
    app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */) = cpu.ebx;
    // 004242da  8935384a4c00           -mov dword ptr [0x4c4a38], esi
    app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */) = cpu.esi;
    // 004242e0  66893d067c4d00         -mov word ptr [0x4d7c06], di
    app->getMemory<x86::reg16>(x86::reg32(5078022) /* 0x4d7c06 */) = cpu.di;
    // 004242e7  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004242ea  8b80a67a4d00           -mov eax, dword ptr [eax + 0x4d7aa6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5077670) /* 0x4d7aa6 */);
    // 004242f0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004242f3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004242f6  39d0                   +cmp eax, edx
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
    // 004242f8  740f                   -je 0x424309
    if (cpu.flags.zf)
    {
        goto L_0x00424309;
    }
    // 004242fa  8b44850c               -mov eax, dword ptr [ebp + eax*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */ + cpu.eax * 4);
    // 004242fe  803802                 +cmp byte ptr [eax], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00424301  7517                   -jne 0x42431a
    if (!cpu.flags.zf)
    {
        goto L_0x0042431a;
    }
    // 00424303  f6400801               +test byte ptr [eax + 8], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) & 1 /*0x1*/));
    // 00424307  7411                   -je 0x42431a
    if (cpu.flags.zf)
    {
        goto L_0x0042431a;
    }
L_0x00424309:
    // 00424309  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042430b  8b1d344a4c00           -mov ebx, dword ptr [0x4c4a34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 00424311  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00424313  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424314  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424315  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424316  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424317  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424318  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424319  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042431a:
    // 0042431a  ba2d000000             -mov edx, 0x2d
    cpu.edx = 45 /*0x2d*/;
    // 0042431f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00424324  e817cd0000             -call 0x431040
    cpu.esp -= 4;
    sub_431040(app, cpu);
    if (cpu.terminate) return;
    // 00424329  668b044da87a4d00       -mov ax, word ptr [ecx*2 + 0x4d7aa8]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5077672) /* 0x4d7aa8 */ + cpu.ecx * 2);
    // 00424331  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00424336  6689450a               -mov word ptr [ebp + 0xa], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 0042433a  8b1d344a4c00           -mov ebx, dword ptr [0x4c4a34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 00424340  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00424342  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424343  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424344  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424345  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424346  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424347  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424348  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00424349:
    // 00424349  66837d0a64             +cmp word ptr [ebp + 0xa], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(10) /* 0xa */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042434e  7411                   -je 0x424361
    if (cpu.flags.zf)
    {
        goto L_0x00424361;
    }
    // 00424350  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00424353  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424356  66c7450a6400           -mov word ptr [ebp + 0xa], 0x64
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(10) /* 0xa */) = 100 /*0x64*/;
    // 0042435c  a3087b4d00             -mov dword ptr [0x4d7b08], eax
    app->getMemory<x86::reg32>(x86::reg32(5077768) /* 0x4d7b08 */) = cpu.eax;
L_0x00424361:
    // 00424361  891d344a4c00           -mov dword ptr [0x4c4a34], ebx
    app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */) = cpu.ebx;
    // 00424367  8935384a4c00           -mov dword ptr [0x4c4a38], esi
    app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */) = cpu.esi;
    // 0042436d  66893d067c4d00         -mov word ptr [0x4d7c06], di
    app->getMemory<x86::reg16>(x86::reg32(5078022) /* 0x4d7c06 */) = cpu.di;
    // 00424374  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00424376  8b1d344a4c00           -mov ebx, dword ptr [0x4c4a34]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 0042437c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042437e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042437f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424380  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424381  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424382  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424383  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424384  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_424390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424390  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00424391  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00424392  8b35384a4c00           -mov esi, dword ptr [0x4c4a38]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */);
    // 00424398  39f2                   +cmp edx, esi
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
    // 0042439a  7d1e                   -jge 0x4243ba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004243ba;
    }
    // 0042439c  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042439e  39f2                   +cmp edx, esi
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
    // 004243a0  7e18                   -jle 0x4243ba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004243ba;
    }
    // 004243a2  8b2d344a4c00           -mov ebp, dword ptr [0x4c4a34]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 004243a8  39e8                   +cmp eax, ebp
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
    // 004243aa  7d0e                   -jge 0x4243ba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004243ba;
    }
    // 004243ac  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004243ae  39e8                   +cmp eax, ebp
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
    // 004243b0  7e08                   -jle 0x4243ba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004243ba;
    }
    // 004243b2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004243b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004243b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004243b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004243ba:
    // 004243ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004243bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004243bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004243be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4243c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004243c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004243c1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004243c3  8b15384a4c00           -mov edx, dword ptr [0x4c4a38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */);
    // 004243c9  39d0                   +cmp eax, edx
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
    // 004243cb  7e07                   -jle 0x4243d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004243d4;
    }
    // 004243cd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004243d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004243d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004243d4:
    // 004243d4  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004243d6  4a                     -dec edx
    (cpu.edx)--;
    // 004243d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004243d9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004243dc  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004243de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004243df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4243e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004243e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004243e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004243e2  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004243e5  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004243e8  8b54900c               -mov edx, dword ptr [eax + edx*4 + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.edx * 4);
    // 004243ec  803a02                 +cmp byte ptr [edx], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004243ef  7413                   -je 0x424404
    if (cpu.flags.zf)
    {
        goto L_0x00424404;
    }
L_0x004243f1:
    // 004243f1  8b15384a4c00           -mov edx, dword ptr [0x4c4a38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */);
    // 004243f7  a1344a4c00             -mov eax, dword ptr [0x4c4a34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 004243fc  e8cfe3ffff             -call 0x4227d0
    cpu.esp -= 4;
    sub_4227d0(app, cpu);
    if (cpu.terminate) return;
    // 00424401  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424402  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424403  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00424404:
    // 00424404  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00424406  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424409  e8c275ffff             -call 0x41b9d0
    cpu.esp -= 4;
    sub_41b9d0(app, cpu);
    if (cpu.terminate) return;
    // 0042440e  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00424411  a3344a4c00             -mov dword ptr [0x4c4a34], eax
    app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */) = cpu.eax;
    // 00424416  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00424418  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0042441b  e89075ffff             -call 0x41b9b0
    cpu.esp -= 4;
    sub_41b9b0(app, cpu);
    if (cpu.terminate) return;
    // 00424420  83c00d                 -add eax, 0xd
    (cpu.eax) += x86::reg32(x86::sreg32(13 /*0xd*/));
    // 00424423  8a5a09                 -mov bl, byte ptr [edx + 9]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
    // 00424426  a3384a4c00             -mov dword ptr [0x4c4a38], eax
    app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */) = cpu.eax;
    // 0042442b  80fb0d                 +cmp bl, 0xd
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042442e  7513                   -jne 0x424443
    if (!cpu.flags.zf)
    {
        goto L_0x00424443;
    }
    // 00424430  803dc8004e0000         +cmp byte ptr [0x4e00c8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112008) /* 0x4e00c8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00424437  740a                   -je 0x424443
    if (cpu.flags.zf)
    {
        goto L_0x00424443;
    }
    // 00424439  8105344a4c009f000000   -add dword ptr [0x4c4a34], 0x9f
    (app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */)) += x86::reg32(x86::sreg32(159 /*0x9f*/));
L_0x00424443:
    // 00424443  f6420810               +test byte ptr [edx + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00424447  74a8                   -je 0x4243f1
    if (cpu.flags.zf)
    {
        goto L_0x004243f1;
    }
    // 00424449  8305344a4c002e         -add dword ptr [0x4c4a34], 0x2e
    (app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */)) += x86::reg32(x86::sreg32(46 /*0x2e*/));
    // 00424450  8b15384a4c00           -mov edx, dword ptr [0x4c4a38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(4999736) /* 0x4c4a38 */);
    // 00424456  a1344a4c00             -mov eax, dword ptr [0x4c4a34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999732) /* 0x4c4a34 */);
    // 0042445b  e870e3ffff             -call 0x4227d0
    cpu.esp -= 4;
    sub_4227d0(app, cpu);
    if (cpu.terminate) return;
    // 00424460  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424461  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424462  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_424470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424472  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424473  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00424474  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00424475  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00424476  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0042447c  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0042447e  833d304a4c0000         +cmp dword ptr [0x4c4a30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999728) /* 0x4c4a30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00424485  0f84ce000000           -je 0x424559
    if (cpu.flags.zf)
    {
        goto L_0x00424559;
    }
L_0x0042448b:
    // 0042448b  baa8ab4b00             -mov edx, 0x4baba8
    cpu.edx = 4959144 /*0x4baba8*/;
    // 00424490  a1304a4c00             -mov eax, dword ptr [0x4c4a30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4999728) /* 0x4c4a30 */);
    // 00424495  e8ca440500             -call 0x478964
    cpu.esp -= 4;
    sub_478964(app, cpu);
    if (cpu.terminate) return;
    // 0042449a  8b1df87a4d00           -mov ebx, dword ptr [0x4d7af8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5077752) /* 0x4d7af8 */);
    // 004244a0  8b7802                 -mov edi, dword ptr [eax + 2]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004244a3  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004244a6  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004244a9  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004244ac  47                     -inc edi
    (cpu.edi)++;
    // 004244ad  41                     -inc ecx
    (cpu.ecx)++;
    // 004244ae  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004244b0  7407                   -je 0x4244b9
    if (cpu.flags.zf)
    {
        goto L_0x004244b9;
    }
    // 004244b2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004244b4  e897430500             -call 0x478850
    cpu.esp -= 4;
    sub_478850(app, cpu);
    if (cpu.terminate) return;
L_0x004244b9:
    // 004244b9  8d510a                 -lea edx, [ecx + 0xa]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(10) /* 0xa */);
    // 004244bc  8d470a                 -lea eax, [edi + 0xa]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(10) /* 0xa */);
    // 004244bf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004244c1  e89e3b0500             -call 0x478064
    cpu.esp -= 4;
    sub_478064(app, cpu);
    if (cpu.terminate) return;
    // 004244c6  8b35fc7a4d00           -mov esi, dword ptr [0x4d7afc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5077756) /* 0x4d7afc */);
    // 004244cc  a3f87a4d00             -mov dword ptr [0x4d7af8], eax
    app->getMemory<x86::reg32>(x86::reg32(5077752) /* 0x4d7af8 */) = cpu.eax;
    // 004244d1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004244d3  7407                   -je 0x4244dc
    if (cpu.flags.zf)
    {
        goto L_0x004244dc;
    }
    // 004244d5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004244d7  e874430500             -call 0x478850
    cpu.esp -= 4;
    sub_478850(app, cpu);
    if (cpu.terminate) return;
L_0x004244dc:
    // 004244dc  8d510a                 -lea edx, [ecx + 0xa]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(10) /* 0xa */);
    // 004244df  8d470a                 -lea eax, [edi + 0xa]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(10) /* 0xa */);
    // 004244e2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004244e4  e87b3b0500             -call 0x478064
    cpu.esp -= 4;
    sub_478064(app, cpu);
    if (cpu.terminate) return;
    // 004244e9  a3fc7a4d00             -mov dword ptr [0x4d7afc], eax
    app->getMemory<x86::reg32>(x86::reg32(5077756) /* 0x4d7afc */) = cpu.eax;
    // 004244ee  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004244f0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004244f2  a1f87a4d00             -mov eax, dword ptr [0x4d7af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5077752) /* 0x4d7af8 */);
    // 004244f7  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004244f9  e80a3b0500             -call 0x478008
    cpu.esp -= 4;
    sub_478008(app, cpu);
    if (cpu.terminate) return;
    // 004244fe  89bc2400010000         -mov dword ptr [esp + 0x100], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edi;
    // 00424505  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00424508  668915067c4d00         -mov word ptr [0x4d7c06], dx
    app->getMemory<x86::reg16>(x86::reg32(5078022) /* 0x4d7c06 */) = cpu.dx;
    // 0042450f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00424511  7422                   -je 0x424535
    if (cpu.flags.zf)
    {
        goto L_0x00424535;
    }
L_0x00424513:
    // 00424513  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00424516  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00424518  3c01                   +cmp al, 1
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
    // 0042451a  736f                   -jae 0x42458b
    if (!cpu.flags.cf)
    {
        goto L_0x0042458b;
    }
L_0x0042451c:
    // 0042451c  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00424523  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00424526  42                     -inc edx
    (cpu.edx)++;
    // 00424527  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042452a  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 00424531  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00424533  75de                   -jne 0x424513
    if (!cpu.flags.zf)
    {
        goto L_0x00424513;
    }
L_0x00424535:
    // 00424535  e8e2390500             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0042453a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0042453c  bfa0484200             -mov edi, 0x4248a0
    cpu.edi = 4343968 /*0x4248a0*/;
    // 00424541  e89afeffff             -call 0x4243e0
    cpu.esp -= 4;
    sub_4243e0(app, cpu);
    if (cpu.terminate) return;
    // 00424546  893da0a44c00           -mov dword ptr [0x4ca4a0], edi
    app->getMemory<x86::reg32>(x86::reg32(5022880) /* 0x4ca4a0 */) = cpu.edi;
    // 0042454c  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00424552  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424553  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424554  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424555  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424556  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424557  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00424559:
    // 00424559  8b0dd4074e00           -mov ecx, dword ptr [0x4e07d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113812) /* 0x4e07d4 */);
    // 0042455f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424560  689cab4b00             -push 0x4bab9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4959132 /*0x4bab9c*/;
    cpu.esp -= 4;
    // 00424565  680c7b4d00             -push 0x4d7b0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5077772 /*0x4d7b0c*/;
    cpu.esp -= 4;
    // 0042456a  e8727a0500             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0042456f  83c40c                 +add esp, 0xc
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
    // 00424572  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00424577  b80c7b4d00             -mov eax, 0x4d7b0c
    cpu.eax = 5077772 /*0x4d7b0c*/;
    // 0042457c  e8df820500             -call 0x47c860
    cpu.esp -= 4;
    sub_47c860(app, cpu);
    if (cpu.terminate) return;
    // 00424581  a3304a4c00             -mov dword ptr [0x4c4a30], eax
    app->getMemory<x86::reg32>(x86::reg32(4999728) /* 0x4c4a30 */) = cpu.eax;
    // 00424586  e900ffffff             -jmp 0x42448b
    goto L_0x0042448b;
L_0x0042458b:
    // 0042458b  0f87a8000000           -ja 0x424639
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00424639;
    }
    // 00424591  f6420201               +test byte ptr [edx + 2], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) & 1 /*0x1*/));
    // 00424595  7585                   -jne 0x42451c
    if (!cpu.flags.zf)
    {
        goto L_0x0042451c;
    }
    // 00424597  a1047c4d00             -mov eax, dword ptr [0x4d7c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5078020) /* 0x4d7c04 */);
    // 0042459c  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004245a3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004245a6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004245a9  66890c45a87a4d00       -mov word ptr [eax*2 + 0x4d7aa8], cx
    app->getMemory<x86::reg16>(x86::reg32(5077672) /* 0x4d7aa8 */ + cpu.eax * 2) = cpu.cx;
    // 004245b1  a1703e4c00             -mov eax, dword ptr [0x4c3e70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4996720) /* 0x4c3e70 */);
    // 004245b6  e8a9430500             -call 0x478964
    cpu.esp -= 4;
    sub_478964(app, cpu);
    if (cpu.terminate) return;
    // 004245bb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004245bd  81fdb43a4c00           +cmp ebp, 0x4c3ab4
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4995764 /*0x4c3ab4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004245c3  0f852e020000           -jne 0x4247f7
    if (!cpu.flags.zf)
    {
        goto L_0x004247f7;
    }
    // 004245c9  e8a25fffff             -call 0x41a570
    cpu.esp -= 4;
    sub_41a570(app, cpu);
    if (cpu.terminate) return;
L_0x004245ce:
    // 004245ce  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004245d1  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004245d4  0fbff8                 -movsx edi, ax
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004245d7  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004245da  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004245dc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004245de  8b15047c4d00           -mov edx, dword ptr [0x4d7c04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5078020) /* 0x4d7c04 */);
    // 004245e4  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004245e7  66893455587a4d00       -mov word ptr [edx*2 + 0x4d7a58], si
    app->getMemory<x86::reg16>(x86::reg32(5077592) /* 0x4d7a58 */ + cpu.edx * 2) = cpu.si;
    // 004245ef  66037106               -add si, word ptr [ecx + 6]
    (cpu.si) += x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */)));
    // 004245f3  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004245f5  66890455087a4d00       -mov word ptr [edx*2 + 0x4d7a08], ax
    app->getMemory<x86::reg16>(x86::reg32(5077512) /* 0x4d7a08 */ + cpu.edx * 2) = cpu.ax;
    // 004245fd  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00424600  c1e014                 -shl eax, 0x14
    cpu.eax <<= 20 /*0x14*/ % 32;
    // 00424603  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 00424606  66890455b8794d00       -mov word ptr [edx*2 + 0x4d79b8], ax
    app->getMemory<x86::reg16>(x86::reg32(5077432) /* 0x4d79b8 */ + cpu.edx * 2) = cpu.ax;
    // 0042460e  66034104               -add ax, word ptr [ecx + 4]
    (cpu.ax) += x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 00424612  668b3d067c4d00         -mov di, word ptr [0x4d7c06]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(5078022) /* 0x4d7c06 */);
    // 00424619  6689045568794d00       -mov word ptr [edx*2 + 0x4d7968], ax
    app->getMemory<x86::reg16>(x86::reg32(5077352) /* 0x4d7968 */ + cpu.edx * 2) = cpu.ax;
    // 00424621  6683ff28               +cmp di, 0x28
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(40 /*0x28*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00424625  0f8df1feffff           -jge 0x42451c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042451c;
    }
    // 0042462b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0042462d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042462e  66a3067c4d00           -mov word ptr [0x4d7c06], ax
    app->getMemory<x86::reg16>(x86::reg32(5078022) /* 0x4d7c06 */) = cpu.ax;
    // 00424634  e9e3feffff             -jmp 0x42451c
    goto L_0x0042451c;
L_0x00424639:
    // 00424639  3c02                   +cmp al, 2
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042463b  0f85dbfeffff           -jne 0x42451c
    if (!cpu.flags.zf)
    {
        goto L_0x0042451c;
    }
    // 00424641  a1047c4d00             -mov eax, dword ptr [0x4d7c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5078020) /* 0x4d7c04 */);
    // 00424646  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424649  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00424650  66890c45a87a4d00       -mov word ptr [eax*2 + 0x4d7aa8], cx
    app->getMemory<x86::reg16>(x86::reg32(5077672) /* 0x4d7aa8 */ + cpu.eax * 2) = cpu.cx;
    // 00424658  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042465a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0042465d  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0042465f  e80c74ffff             -call 0x41ba70
    cpu.esp -= 4;
    sub_41ba70(app, cpu);
    if (cpu.terminate) return;
    // 00424664  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00424666  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00424667:
    // 00424667  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00424669  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0042466b  3c00                   +cmp al, 0
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
    // 0042466d  7410                   -je 0x42467f
    if (cpu.flags.zf)
    {
        goto L_0x0042467f;
    }
    // 0042466f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00424672  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00424675  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00424678  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042467b  3c00                   +cmp al, 0
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
    // 0042467d  75e8                   -jne 0x424667
    if (!cpu.flags.zf)
    {
        goto L_0x00424667;
    }
L_0x0042467f:
    // 0042467f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424680  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00424682  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424685  e82673ffff             -call 0x41b9b0
    cpu.esp -= 4;
    sub_41b9b0(app, cpu);
    if (cpu.terminate) return;
    // 0042468a  8b0d047c4d00           -mov ecx, dword ptr [0x4d7c04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5078020) /* 0x4d7c04 */);
    // 00424690  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00424693  6689044d587a4d00       -mov word ptr [ecx*2 + 0x4d7a58], ax
    app->getMemory<x86::reg16>(x86::reg32(5077592) /* 0x4d7a58 */ + cpu.ecx * 2) = cpu.ax;
    // 0042469b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042469d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004246a0  e8ab73ffff             -call 0x41ba50
    cpu.esp -= 4;
    sub_41ba50(app, cpu);
    if (cpu.terminate) return;
    // 004246a5  668b344d587a4d00       -mov si, word ptr [ecx*2 + 0x4d7a58]
    cpu.si = app->getMemory<x86::reg16>(x86::reg32(5077592) /* 0x4d7a58 */ + cpu.ecx * 2);
    // 004246ad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004246af  a1047c4d00             -mov eax, dword ptr [0x4d7c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5078020) /* 0x4d7c04 */);
    // 004246b4  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004246b6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004246b9  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004246bc  66890c45087a4d00       -mov word ptr [eax*2 + 0x4d7a08], cx
    app->getMemory<x86::reg16>(x86::reg32(5077512) /* 0x4d7a08 */ + cpu.eax * 2) = cpu.cx;
    // 004246c4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004246c6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004246c9  e88273ffff             -call 0x41ba50
    cpu.esp -= 4;
    sub_41ba50(app, cpu);
    if (cpu.terminate) return;
    // 004246ce  e81d10feff             -call 0x4056f0
    cpu.esp -= 4;
    sub_4056f0(app, cpu);
    if (cpu.terminate) return;
    // 004246d3  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004246d5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004246d8  e81373ffff             -call 0x41b9f0
    cpu.esp -= 4;
    sub_41b9f0(app, cpu);
    if (cpu.terminate) return;
    // 004246dd  83f801                 +cmp eax, 1
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
    // 004246e0  0f85c7000000           -jne 0x4247ad
    if (!cpu.flags.zf)
    {
        goto L_0x004247ad;
    }
L_0x004246e6:
    // 004246e6  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004246e8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004246eb  e8e072ffff             -call 0x41b9d0
    cpu.esp -= 4;
    sub_41b9d0(app, cpu);
    if (cpu.terminate) return;
    // 004246f0  8b0d047c4d00           -mov ecx, dword ptr [0x4d7c04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5078020) /* 0x4d7c04 */);
    // 004246f6  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004246f9  050c000000             -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004246fe  6689044d68794d00       -mov word ptr [ecx*2 + 0x4d7968], ax
    app->getMemory<x86::reg16>(x86::reg32(5077352) /* 0x4d7968 */ + cpu.ecx * 2) = cpu.ax;
    // 00424706  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00424708  e8c7370500             -call 0x477ed4
    cpu.esp -= 4;
    sub_477ed4(app, cpu);
    if (cpu.terminate) return;
    // 0042470d  668b0c4d68794d00       -mov cx, word ptr [ecx*2 + 0x4d7968]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5077352) /* 0x4d7968 */ + cpu.ecx * 2);
    // 00424715  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00424717  a1047c4d00             -mov eax, dword ptr [0x4d7c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5078020) /* 0x4d7c04 */);
    // 0042471c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0042471f  83e90c                 -sub ecx, 0xc
    (cpu.ecx) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424722  66890c45b8794d00       -mov word ptr [eax*2 + 0x4d79b8], cx
    app->getMemory<x86::reg16>(x86::reg32(5077432) /* 0x4d79b8 */ + cpu.eax * 2) = cpu.cx;
L_0x0042472a:
    // 0042472a  807a0912               +cmp byte ptr [edx + 9], 0x12
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(18 /*0x12*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042472e  7512                   -jne 0x424742
    if (!cpu.flags.zf)
    {
        goto L_0x00424742;
    }
    // 00424730  a1047c4d00             -mov eax, dword ptr [0x4d7c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5078020) /* 0x4d7c04 */);
    // 00424735  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424738  6681044568794d002c01   -add word ptr [eax*2 + 0x4d7968], 0x12c
    (app->getMemory<x86::reg16>(x86::reg32(5077352) /* 0x4d7968 */ + cpu.eax * 2)) += x86::reg16(x86::sreg16(300 /*0x12c*/));
L_0x00424742:
    // 00424742  807a090d               +cmp byte ptr [edx + 9], 0xd
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00424746  7512                   -jne 0x42475a
    if (!cpu.flags.zf)
    {
        goto L_0x0042475a;
    }
    // 00424748  a1047c4d00             -mov eax, dword ptr [0x4d7c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5078020) /* 0x4d7c04 */);
    // 0042474d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424750  6681044568794d00f000   -add word ptr [eax*2 + 0x4d7968], 0xf0
    (app->getMemory<x86::reg16>(x86::reg32(5077352) /* 0x4d7968 */ + cpu.eax * 2)) += x86::reg16(x86::sreg16(240 /*0xf0*/));
L_0x0042475a:
    // 0042475a  837a0c00               +cmp dword ptr [edx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042475e  7417                   -je 0x424777
    if (cpu.flags.zf)
    {
        goto L_0x00424777;
    }
    // 00424760  f6420808               +test byte ptr [edx + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00424764  7511                   -jne 0x424777
    if (!cpu.flags.zf)
    {
        goto L_0x00424777;
    }
    // 00424766  a1047c4d00             -mov eax, dword ptr [0x4d7c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5078020) /* 0x4d7c04 */);
    // 0042476b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0042476e  6683044568794d0078     -add word ptr [eax*2 + 0x4d7968], 0x78
    (app->getMemory<x86::reg16>(x86::reg32(5077352) /* 0x4d7968 */ + cpu.eax * 2)) += x86::reg16(x86::sreg16(120 /*0x78*/));
L_0x00424777:
    // 00424777  807a0905               +cmp byte ptr [edx + 9], 5
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(5 /*0x5*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042477b  7511                   -jne 0x42478e
    if (!cpu.flags.zf)
    {
        goto L_0x0042478e;
    }
    // 0042477d  a1047c4d00             -mov eax, dword ptr [0x4d7c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5078020) /* 0x4d7c04 */);
    // 00424782  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424785  6683044568794d006e     -add word ptr [eax*2 + 0x4d7968], 0x6e
    (app->getMemory<x86::reg16>(x86::reg32(5077352) /* 0x4d7968 */ + cpu.eax * 2)) += x86::reg16(x86::sreg16(110 /*0x6e*/));
L_0x0042478e:
    // 0042478e  66a1067c4d00           -mov ax, word ptr [0x4d7c06]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5078022) /* 0x4d7c06 */);
    // 00424794  663d2800               +cmp ax, 0x28
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(40 /*0x28*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00424798  0f8d7efdffff           -jge 0x42451c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042451c;
    }
    // 0042479e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004247a0  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004247a1  668915067c4d00         -mov word ptr [0x4d7c06], dx
    app->getMemory<x86::reg16>(x86::reg32(5078022) /* 0x4d7c06 */) = cpu.dx;
    // 004247a8  e96ffdffff             -jmp 0x42451c
    goto L_0x0042451c;
L_0x004247ad:
    // 004247ad  83f804                 +cmp eax, 4
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
    // 004247b0  0f8430ffffff           -je 0x4246e6
    if (cpu.flags.zf)
    {
        goto L_0x004246e6;
    }
    // 004247b6  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004247b8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004247bb  e81072ffff             -call 0x41b9d0
    cpu.esp -= 4;
    sub_41b9d0(app, cpu);
    if (cpu.terminate) return;
    // 004247c0  8b0d047c4d00           -mov ecx, dword ptr [0x4d7c04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5078020) /* 0x4d7c04 */);
    // 004247c6  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004247c9  6689044db8794d00       -mov word ptr [ecx*2 + 0x4d79b8], ax
    app->getMemory<x86::reg16>(x86::reg32(5077432) /* 0x4d79b8 */ + cpu.ecx * 2) = cpu.ax;
    // 004247d1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004247d3  e8fc360500             -call 0x477ed4
    cpu.esp -= 4;
    sub_477ed4(app, cpu);
    if (cpu.terminate) return;
    // 004247d8  668b0c4db8794d00       -mov cx, word ptr [ecx*2 + 0x4d79b8]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5077432) /* 0x4d79b8 */ + cpu.ecx * 2);
    // 004247e0  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004247e2  a1047c4d00             -mov eax, dword ptr [0x4d7c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5078020) /* 0x4d7c04 */);
    // 004247e7  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004247ea  66890c4568794d00       -mov word ptr [eax*2 + 0x4d7968], cx
    app->getMemory<x86::reg16>(x86::reg32(5077352) /* 0x4d7968 */ + cpu.eax * 2) = cpu.cx;
    // 004247f2  e933ffffff             -jmp 0x42472a
    goto L_0x0042472a;
L_0x004247f7:
    // 004247f7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004247f9  e9d0fdffff             -jmp 0x4245ce
    goto L_0x004245ce;
}

/* align: skip 0x00 0x00 */
void Application::sub_424800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424801  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424802  bb384a4c00             -mov ebx, 0x4c4a38
    cpu.ebx = 4999736 /*0x4c4a38*/;
    // 00424807  ba344a4c00             -mov edx, 0x4c4a34
    cpu.edx = 4999732 /*0x4c4a34*/;
    // 0042480c  b83c4a4c00             -mov eax, 0x4c4a3c
    cpu.eax = 4999740 /*0x4c4a3c*/;
    // 00424811  e82addffff             -call 0x422540
    cpu.esp -= 4;
    sub_422540(app, cpu);
    if (cpu.terminate) return;
    // 00424816  833d404a4c0000         +cmp dword ptr [0x4c4a40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999744) /* 0x4c4a40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042481d  7505                   -jne 0x424824
    if (!cpu.flags.zf)
    {
        goto L_0x00424824;
    }
    // 0042481f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00424821  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424822  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424823  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00424824:
    // 00424824  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424825  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00424827  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042482c  890d404a4c00           -mov dword ptr [0x4c4a40], ecx
    app->getMemory<x86::reg32>(x86::reg32(4999744) /* 0x4c4a40 */) = cpu.ecx;
    // 00424832  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424833  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424834  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424835  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_424840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00424840  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00424841  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00424842  bb384a4c00             -mov ebx, 0x4c4a38
    cpu.ebx = 4999736 /*0x4c4a38*/;
    // 00424847  ba344a4c00             -mov edx, 0x4c4a34
    cpu.edx = 4999732 /*0x4c4a34*/;
    // 0042484c  b83c4a4c00             -mov eax, 0x4c4a3c
    cpu.eax = 4999740 /*0x4c4a3c*/;
    // 00424851  e8eadcffff             -call 0x422540
    cpu.esp -= 4;
    sub_422540(app, cpu);
    if (cpu.terminate) return;
    // 00424856  833d404a4c0000         +cmp dword ptr [0x4c4a40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4999744) /* 0x4c4a40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042485d  7505                   -jne 0x424864
    if (!cpu.flags.zf)
    {
        goto L_0x00424864;
    }
    // 0042485f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00424861  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424862  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424863  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00424864:
    // 00424864  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00424865  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00424867  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042486c  890d404a4c00           -mov dword ptr [0x4c4a40], ecx
    app->getMemory<x86::reg32>(x86::reg32(4999744) /* 0x4c4a40 */) = cpu.ecx;
    // 00424872  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424873  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424874  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00424875  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
