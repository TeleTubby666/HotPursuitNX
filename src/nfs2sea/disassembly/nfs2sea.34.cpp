#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4b9bde(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b9bde);
    // 004b9bde  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b9bdf  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b9be1  83fb0a                 +cmp ebx, 0xa
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
    // 004b9be4  750a                   -jne 0x4b9bf0
    if (!cpu.flags.zf)
    {
        goto L_0x004b9bf0;
    }
    // 004b9be6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b9be8  7d06                   -jge 0x4b9bf0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b9bf0;
    }
    // 004b9bea  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004b9bec  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 004b9bef  42                     -inc edx
    (cpu.edx)++;
L_0x004b9bf0:
    // 004b9bf0  e8a0ffffff             -call 0x4b9b95
    cpu.esp -= 4;
    sub_4b9b95(app, cpu);
    if (cpu.terminate) return;
    // 004b9bf5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b9bf7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9bf8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9bf9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b9bf9);
    // 004b9bf9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b9bfa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b9bfb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b9bfc  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b9bfd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b9bfe  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004b9c01  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b9c03  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004b9c07  8d7c2434               -lea edi, [esp + 0x34]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b9c0b  8d6c2401               -lea ebp, [esp + 1]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 004b9c0f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b9c11  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 004b9c15  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b9c17  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b9c19  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004b9c1b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b9c1c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b9c1d  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004b9c21  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004b9c25  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x004b9c28:
    // 004b9c28  8d7c242c               -lea edi, [esp + 0x2c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b9c2c  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b9c30  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b9c34  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b9c38  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b9c3b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b9c3d  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b9c40  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b9c42  e81e5f0000             -call 0x4bfb65
    cpu.esp -= 4;
    sub_4bfb65(app, cpu);
    if (cpu.terminate) return;
    // 004b9c47  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b9c4a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b9c4c  894f04                 -mov dword ptr [edi + 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b9c4f  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 004b9c51  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b9c55  8a83a8e74d00           -mov al, byte ptr [ebx + 0x4de7a8]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5105576) /* 0x4de7a8 */);
    // 004b9c5b  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 004b9c5e  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b9c62  45                     -inc ebp
    (cpu.ebp)++;
    // 004b9c63  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b9c65  75c1                   -jne 0x4b9c28
    if (!cpu.flags.zf)
    {
        goto L_0x004b9c28;
    }
    // 004b9c67  837c243800             +cmp dword ptr [esp + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b9c6c  75ba                   -jne 0x4b9c28
    if (!cpu.flags.zf)
    {
        goto L_0x004b9c28;
    }
L_0x004b9c6e:
    // 004b9c6e  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004b9c72  4d                     -dec ebp
    (cpu.ebp)--;
    // 004b9c73  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b9c76  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004b9c79  89742440               -mov dword ptr [esp + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 004b9c7d  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004b9c7f  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004b9c81  75eb                   -jne 0x4b9c6e
    if (!cpu.flags.zf)
    {
        goto L_0x004b9c6e;
    }
    // 004b9c83  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004b9c87  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004b9c8a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9c8b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b9c8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9c8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9c8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9c8f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b9c90);
    // 004b9c90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b9c91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b9c92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b9c93  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b9c94  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b9c97  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b9c99  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b9c9b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b9c9d  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004b9c9f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b9ca1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b9ca2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b9ca3  83fb0a                 +cmp ebx, 0xa
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
    // 004b9ca6  752d                   -jne 0x4b9cd5
    if (!cpu.flags.zf)
    {
        goto L_0x004b9cd5;
    }
    // 004b9ca8  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 004b9cad  7426                   -je 0x4b9cd5
    if (cpu.flags.zf)
    {
        goto L_0x004b9cd5;
    }
    // 004b9caf  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 004b9cb2  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b9cb5  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b9cb9  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 004b9cbb  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 004b9cbd  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b9cc0  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004b9cc4  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b9cc7  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004b9cca  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b9ccb  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004b9cce  7501                   -jne 0x4b9cd1
    if (!cpu.flags.zf)
    {
        goto L_0x004b9cd1;
    }
    // 004b9cd0  46                     -inc esi
    (cpu.esi)++;
L_0x004b9cd1:
    // 004b9cd1  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x004b9cd5:
    // 004b9cd5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b9cd7  e81dffffff             -call 0x4b9bf9
    cpu.esp -= 4;
    sub_4b9bf9(app, cpu);
    if (cpu.terminate) return;
    // 004b9cdc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b9cde  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b9ce1  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b9ce2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9ce3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9ce4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9ce5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9ce6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b9ce6);
    // 004b9ce6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b9ce7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b9ce8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b9ce9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b9cea  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004b9ced  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b9cef  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004b9cf1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b9cf3  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004b9cf5  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 004b9cf9  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x004b9cfc:
    // 004b9cfc  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b9d00  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004b9d04  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b9d06  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004b9d08  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b9d0a  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b9d0e  8a92d0e74d00           -mov dl, byte ptr [edx + 0x4de7d0]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5105616) /* 0x4de7d0 */);
    // 004b9d14  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004b9d16  41                     -inc ecx
    (cpu.ecx)++;
    // 004b9d17  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b9d19  75e1                   -jne 0x4b9cfc
    if (!cpu.flags.zf)
    {
        goto L_0x004b9cfc;
    }
L_0x004b9d1b:
    // 004b9d1b  49                     -dec ecx
    (cpu.ecx)--;
    // 004b9d1c  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004b9d1e  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b9d20  46                     -inc esi
    (cpu.esi)++;
    // 004b9d21  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004b9d23  75f6                   -jne 0x4b9d1b
    if (!cpu.flags.zf)
    {
        goto L_0x004b9d1b;
    }
    // 004b9d25  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b9d27  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004b9d2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9d2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9d2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9d2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9d2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9d2f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b9d2f);
    // 004b9d2f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b9d30  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b9d32  83fb0a                 +cmp ebx, 0xa
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
    // 004b9d35  750a                   -jne 0x4b9d41
    if (!cpu.flags.zf)
    {
        goto L_0x004b9d41;
    }
    // 004b9d37  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b9d39  7d06                   -jge 0x4b9d41
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b9d41;
    }
    // 004b9d3b  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004b9d3d  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 004b9d40  42                     -inc edx
    (cpu.edx)++;
L_0x004b9d41:
    // 004b9d41  e8a0ffffff             -call 0x4b9ce6
    cpu.esp -= 4;
    sub_4b9ce6(app, cpu);
    if (cpu.terminate) return;
    // 004b9d46  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b9d48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9d49  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9d4a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b9d4a);
    // 004b9d4a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b9d4b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b9d4c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b9d4d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b9d4e  ff1538cb4d00           -call dword ptr [0x4dcb38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098296) /* 0x4dcb38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b9d54  a1fcb84d00             -mov eax, dword ptr [0x4db8fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093628) /* 0x4db8fc */);
    // 004b9d59  e9a2000000             -jmp 0x4b9e00
    return sub_4b9e00(app, cpu);
}

/* align: skip  */
void Application::sub_4b9d5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b9d5e);
    // 004b9d5e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b9d5f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b9d60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b9d61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b9d62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b9d63  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9d65  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 004b9d6a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b9d6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b9d6d  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b9d70  2eff159c454c00         -call dword ptr cs:[0x4c459c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998556) /* 0x4c459c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b9d77  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b9d79  7507                   -jne 0x4b9d82
    if (!cpu.flags.zf)
    {
        goto L_0x004b9d82;
    }
    // 004b9d7b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b9d80  eb36                   -jmp 0x4b9db8
    goto L_0x004b9db8;
L_0x004b9d82:
    // 004b9d82  3b1d00b94d00           +cmp ebx, dword ptr [0x4db900]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5093632) /* 0x4db900 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b9d88  751c                   -jne 0x4b9da6
    if (!cpu.flags.zf)
    {
        goto L_0x004b9da6;
    }
    // 004b9d8a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b9d8c  7408                   -je 0x4b9d96
    if (cpu.flags.zf)
    {
        goto L_0x004b9d96;
    }
    // 004b9d8e  893500b94d00           -mov dword ptr [0x4db900], esi
    app->getMemory<x86::reg32>(x86::reg32(5093632) /* 0x4db900 */) = cpu.esi;
    // 004b9d94  eb10                   -jmp 0x4b9da6
    goto L_0x004b9da6;
L_0x004b9d96:
    // 004b9d96  a1fcb84d00             -mov eax, dword ptr [0x4db8fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093628) /* 0x4db8fc */);
    // 004b9d9b  893504b94d00           -mov dword ptr [0x4db904], esi
    app->getMemory<x86::reg32>(x86::reg32(5093636) /* 0x4db904 */) = cpu.esi;
    // 004b9da1  a300b94d00             -mov dword ptr [0x4db900], eax
    app->getMemory<x86::reg32>(x86::reg32(5093632) /* 0x4db900 */) = cpu.eax;
L_0x004b9da6:
    // 004b9da6  3b1df4435b00           +cmp ebx, dword ptr [0x5b43f4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5981172) /* 0x5b43f4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b9dac  7508                   -jne 0x4b9db6
    if (!cpu.flags.zf)
    {
        goto L_0x004b9db6;
    }
    // 004b9dae  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b9db0  893df4435b00           -mov dword ptr [0x5b43f4], edi
    app->getMemory<x86::reg32>(x86::reg32(5981172) /* 0x5b43f4 */) = cpu.edi;
L_0x004b9db6:
    // 004b9db6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b9db8:
    // 004b9db8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9db9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9dba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9dbb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9dbc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9dbd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9dbe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b9dbe);
    // 004b9dbe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b9dbf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b9dc0  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b9dc3  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b9dc6  e893ffffff             -call 0x4b9d5e
    cpu.esp -= 4;
    sub_4b9d5e(app, cpu);
    if (cpu.terminate) return;
    // 004b9dcb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b9dcd  7516                   -jne 0x4b9de5
    if (!cpu.flags.zf)
    {
        goto L_0x004b9de5;
    }
    // 004b9dcf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b9dd1  7508                   -jne 0x4b9ddb
    if (!cpu.flags.zf)
    {
        goto L_0x004b9ddb;
    }
    // 004b9dd3  8915fcb84d00           -mov dword ptr [0x4db8fc], edx
    app->getMemory<x86::reg32>(x86::reg32(5093628) /* 0x4db8fc */) = cpu.edx;
    // 004b9dd9  eb03                   -jmp 0x4b9dde
    goto L_0x004b9dde;
L_0x004b9ddb:
    // 004b9ddb  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x004b9dde:
    // 004b9dde  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b9de0  7403                   -je 0x4b9de5
    if (cpu.flags.zf)
    {
        goto L_0x004b9de5;
    }
    // 004b9de2  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x004b9de5:
    // 004b9de5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9de6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9de7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9de8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b9de8);
L_0x004b9de8:
    // 004b9de8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b9dea  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004b9ded  83e92c                 -sub ecx, 0x2c
    (cpu.ecx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004b9df0  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004b9df2  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b9df5  39f1                   +cmp ecx, esi
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
    // 004b9df7  7505                   -jne 0x4b9dfe
    if (!cpu.flags.zf)
    {
        goto L_0x004b9dfe;
    }
    // 004b9df9  e8c0ffffff             -call 0x4b9dbe
    cpu.esp -= 4;
    sub_4b9dbe(app, cpu);
    if (cpu.terminate) return;
L_0x004b9dfe:
    // 004b9dfe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b9e00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b9e02  75e4                   -jne 0x4b9de8
    if (!cpu.flags.zf)
    {
        goto L_0x004b9de8;
    }
    // 004b9e04  ff1540cb4d00           -call dword ptr [0x4dcb40]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098304) /* 0x4dcb40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b9e0a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b9e0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9e0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9e0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9e0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9e10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b9e00);
    goto L_entry_0x004b9e00;
L_0x004b9de8:
    // 004b9de8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b9dea  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004b9ded  83e92c                 -sub ecx, 0x2c
    (cpu.ecx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004b9df0  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004b9df2  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b9df5  39f1                   +cmp ecx, esi
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
    // 004b9df7  7505                   -jne 0x4b9dfe
    if (!cpu.flags.zf)
    {
        goto L_0x004b9dfe;
    }
    // 004b9df9  e8c0ffffff             -call 0x4b9dbe
    cpu.esp -= 4;
    sub_4b9dbe(app, cpu);
    if (cpu.terminate) return;
L_0x004b9dfe:
    // 004b9dfe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_entry_0x004b9e00:
    // 004b9e00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b9e02  75e4                   -jne 0x4b9de8
    if (!cpu.flags.zf)
    {
        goto L_0x004b9de8;
    }
    // 004b9e04  ff1540cb4d00           -call dword ptr [0x4dcb40]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098304) /* 0x4dcb40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b9e0a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b9e0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9e0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9e0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9e0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9e10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4b9e14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b9e14);
    // 004b9e14  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b9e15  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b9e17  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b9e18  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b9e19  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b9e1c  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b9e1f  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b9e22  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004b9e25  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004b9e28  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004b9e2b  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b9e2d  891d08e84d00           -mov dword ptr [0x4de808], ebx
    app->getMemory<x86::reg32>(x86::reg32(5105672) /* 0x4de808 */) = cpu.ebx;
    // 004b9e33  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b9e36  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b9e39  83f901                 +cmp ecx, 1
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
    // 004b9e3c  7e7a                   -jle 0x4b9eb8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b9eb8;
    }
    // 004b9e3e  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b9e41:
    // 004b9e41  db050ae84d00           -fild dword ptr [0x4de80a]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5105674) /* 0x4de80a */))));
    // 004b9e47  d904ae                 -fld dword ptr [esi + ebp*4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.ebp * 4)));
    // 004b9e4a  d944ae04               -fld dword ptr [esi + ebp*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4)));
    // 004b9e4e  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b9e51  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b9e53  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004b9e55  891d08e84d00           -mov dword ptr [0x4de808], ebx
    app->getMemory<x86::reg32>(x86::reg32(5105672) /* 0x4de808 */) = cpu.ebx;
    // 004b9e5b  db050ae84d00           -fild dword ptr [0x4de80a]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5105674) /* 0x4de80a */))));
    // 004b9e61  d904ae                 -fld dword ptr [esi + ebp*4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.ebp * 4)));
    // 004b9e64  d944ae04               -fld dword ptr [esi + ebp*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4)));
    // 004b9e68  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004b9e6a  d80d04e84d00           -fmul dword ptr [0x4de804]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5105668) /* 0x4de804 */));
    // 004b9e70  d90500e84d00           -fld dword ptr [0x4de800]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5105664) /* 0x4de800 */)));
    // 004b9e76  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b9e78  d80d04e84d00           -fmul dword ptr [0x4de804]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5105668) /* 0x4de804 */));
    // 004b9e7e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b9e80  dceb                   -fsub st(3), st(0)
    cpu.fpu.st(3) -= x86::Float(cpu.fpu.st(0));
    // 004b9e82  d90500e84d00           -fld dword ptr [0x4de800]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5105664) /* 0x4de800 */)));
    // 004b9e88  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b9e8a  dcea                   -fsub st(2), st(0)
    cpu.fpu.st(2) -= x86::Float(cpu.fpu.st(0));
    // 004b9e8c  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004b9e8e  dece                   -fmulp st(6)
    cpu.fpu.st(6) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b9e90  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b9e92  decc                   +fmulp st(4)
    cpu.fpu.st(4) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b9e94  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b9e96  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b9e98  decc                   +fmulp st(4)
    cpu.fpu.st(4) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b9e9a  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b9e9c  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b9e9e  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b9ea0  dec2                   +faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b9ea2  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004b9ea4  891d08e84d00           -mov dword ptr [0x4de808], ebx
    app->getMemory<x86::reg32>(x86::reg32(5105672) /* 0x4de808 */) = cpu.ebx;
    // 004b9eaa  d95ff8                 -fstp dword ptr [edi - 8]
    app->getMemory<float>(cpu.edi + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b9ead  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b9eb0  83e902                 +sub ecx, 2
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
    // 004b9eb3  7f8c                   -jg 0x4b9e41
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b9e41;
    }
    // 004b9eb5  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b9eb8:
    // 004b9eb8  83f900                 +cmp ecx, 0
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
    // 004b9ebb  7e36                   -jle 0x4b9ef3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b9ef3;
    }
    // 004b9ebd  db050ae84d00           -fild dword ptr [0x4de80a]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5105674) /* 0x4de80a */))));
    // 004b9ec3  d90500e84d00           -fld dword ptr [0x4de800]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5105664) /* 0x4de800 */)));
    // 004b9ec9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b9ecb  d80d04e84d00           -fmul dword ptr [0x4de804]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5105668) /* 0x4de804 */));
    // 004b9ed1  dce9                   -fsub st(1), st(0)
    cpu.fpu.st(1) -= x86::Float(cpu.fpu.st(0));
    // 004b9ed3  d84cae04               -fmul dword ptr [esi + ebp*4 + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4));
    // 004b9ed7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b9ed9  d80cae                 -fmul dword ptr [esi + ebp*4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + cpu.ebp * 4));
    // 004b9edc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b9ede  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b9ee0  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004b9ee2  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b9ee5  891d08e84d00           -mov dword ptr [0x4de808], ebx
    app->getMemory<x86::reg32>(x86::reg32(5105672) /* 0x4de808 */) = cpu.ebx;
    // 004b9eeb  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b9eee  83e901                 +sub ecx, 1
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
    // 004b9ef1  7fc5                   -jg 0x4b9eb8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b9eb8;
    }
L_0x004b9ef3:
    // 004b9ef3  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004b9ef5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9ef6  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004b9ef9  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b9efb  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b9efe  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004b9f00  61                     -popal 
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
    // 004b9f01  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9f02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b9f04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b9f04);
    // 004b9f04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b9f05  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b9f07  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b9f08  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b9f09  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b9f0c  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b9f0f  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b9f12  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004b9f15  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004b9f18  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004b9f1b  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b9f1d  891d18e84d00           -mov dword ptr [0x4de818], ebx
    app->getMemory<x86::reg32>(x86::reg32(5105688) /* 0x4de818 */) = cpu.ebx;
    // 004b9f23  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b9f26  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b9f29  eb06                   -jmp 0x4b9f31
    goto L_0x004b9f31;
L_0x004b9f2b:
    // 004b9f2b  d95ff8                 -fstp dword ptr [edi - 8]
    app->getMemory<float>(cpu.edi + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b9f2e  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004b9f31:
    // 004b9f31  db051ae84d00           -fild dword ptr [0x4de81a]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5105690) /* 0x4de81a */))));
    // 004b9f37  d90510e84d00           -fld dword ptr [0x4de810]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5105680) /* 0x4de810 */)));
    // 004b9f3d  d904ee                 -fld dword ptr [esi + ebp*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.ebp * 8)));
    // 004b9f40  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b9f42  d80d14e84d00           -fmul dword ptr [0x4de814]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5105684) /* 0x4de814 */));
    // 004b9f48  d944ee04               -fld dword ptr [esi + ebp*8 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 8)));
    // 004b9f4c  d944ee08               -fld dword ptr [esi + ebp*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.ebp * 8)));
    // 004b9f50  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b9f52  dceb                   -fsub st(3), st(0)
    cpu.fpu.st(3) -= x86::Float(cpu.fpu.st(0));
    // 004b9f54  dcca                   -fmul st(2), st(0)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    // 004b9f56  d944ee0c               -fld dword ptr [esi + ebp*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ebp * 8)));
    // 004b9f5a  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004b9f5c  dccd                   -fmul st(5), st(0)
    cpu.fpu.st(5) *= cpu.fpu.st(0);
    // 004b9f5e  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b9f61  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b9f63  deca                   +fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b9f65  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004b9f67  891d18e84d00           -mov dword ptr [0x4de818], ebx
    app->getMemory<x86::reg32>(x86::reg32(5105688) /* 0x4de818 */) = cpu.ebx;
    // 004b9f6d  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b9f6f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b9f71  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b9f73  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b9f75  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b9f77  83e901                 +sub ecx, 1
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
    // 004b9f7a  7faf                   -jg 0x4b9f2b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b9f2b;
    }
    // 004b9f7c  d95ff8                 -fstp dword ptr [edi - 8]
    app->getMemory<float>(cpu.edi + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b9f7f  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b9f82  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004b9f84  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9f85  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004b9f88  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004b9f8a  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b9f8d  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004b9f8f  61                     -popal 
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
    // 004b9f90  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9f91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b9f94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b9f94);
    // 004b9f94  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b9f95  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b9f97  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b9f98  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b9f99  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 004b9f9e  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004b9fa1  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b9fa4  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b9fa7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b9faa  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004b9fad  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004b9fb0  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004b9fb3  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b9fb5  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b9fb8  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b9fbb  0f6ecb                 -movd mm1, ebx
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004b9fbe  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004b9fc1  0f72d110               -psrld mm1, 0x10
    cpu.mmx.mm1 = { _mm_srli_epi32(cpu.mmx.mm1, 16 /*0x10*/) };
    // 004b9fc5  0febca                 -por mm1, mm2
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004b9fc8  0fefcb                 -pxor mm1, mm3
    cpu.mmx.mm1 = { _mm_xor_si128(cpu.mmx.mm1, cpu.mmx.mm3) };
    // 004b9fcb  4a                     -dec edx
    (cpu.edx)--;
    // 004b9fcc  0f6ee2                 -movd mm4, edx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004b9fcf  42                     -inc edx
    (cpu.edx)++;
    // 004b9fd0  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004b9fd3  0f72d410               -psrld mm4, 0x10
    cpu.mmx.mm4 = { _mm_srli_epi32(cpu.mmx.mm4, 16 /*0x10*/) };
    // 004b9fd7  0febe5                 -por mm4, mm5
    cpu.mmx.mm4 = { _mm_or_si128(cpu.mmx.mm4, cpu.mmx.mm5) };
    // 004b9fda  0fefe3                 -pxor mm4, mm3
    cpu.mmx.mm4 = { _mm_xor_si128(cpu.mmx.mm4, cpu.mmx.mm3) };
L_0x004b9fdd:
    // 004b9fdd  0f60443500             -punpcklbw mm0, dword ptr [ebp + esi]
    cpu.mmx.mm0 = { _mm_unpacklo_epi8(cpu.mmx.mm0, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + cpu.esi * 1))) };
    // 004b9fe2  0f6fd1                 -movq mm2, mm1
    cpu.mmx.mm2 = cpu.mmx.mm1;
    // 004b9fe5  0f71d201               -psrlw mm2, 1
    cpu.mmx.mm2 = { _mm_srli_epi16(cpu.mmx.mm2, 1 /*0x1*/) };
    // 004b9fe9  0ff5c2                 -pmaddwd mm0, mm2
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm2) };
    // 004b9fec  0f73d017               -psrlq mm0, 0x17
    cpu.mmx.mm0 = { _mm_srli_epi64(cpu.mmx.mm0, 23 /*0x17*/) };
    // 004b9ff0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b9ff1  0f7ec1                 -movd ecx, mm0
    cpu.ecx = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004b9ff4  0ffdcc                 -paddw mm1, mm4
    cpu.mmx.mm1 = { _mm_add_epi16(cpu.mmx.mm1, cpu.mmx.mm4) };
    // 004b9ff7  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 004b9ff9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b9ffa  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b9ffc  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004b9ffe  83c701                 +add edi, 1
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ba001  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ba002  7fd9                   -jg 0x4b9fdd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b9fdd;
    }
    // 004ba004  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ba006  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba007  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ba00a  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004ba00c  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ba00f  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ba011  61                     -popal 
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
    // 004ba012  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba013  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba014(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba014);
    // 004ba014  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ba015  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ba017  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004ba018  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ba019  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 004ba01e  0f6ee3                 -movd mm4, ebx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ba021  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004ba024  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004ba027  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004ba02a  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004ba02d  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004ba030  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ba033  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ba035  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ba038  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004ba03b  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ba03e  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ba041  0f72d210               -psrld mm2, 0x10
    cpu.mmx.mm2 = { _mm_srli_epi32(cpu.mmx.mm2, 16 /*0x10*/) };
    // 004ba045  0febd3                 -por mm2, mm3
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm3) };
    // 004ba048  0fefd4                 -pxor mm2, mm4
    cpu.mmx.mm2 = { _mm_xor_si128(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004ba04b  0f6fea                 -movq mm5, mm2
    cpu.mmx.mm5 = cpu.mmx.mm2;
    // 004ba04e  0f73f220               -psllq mm2, 0x20
    cpu.mmx.mm2 = { _mm_slli_epi64(cpu.mmx.mm2, 32 /*0x20*/) };
    // 004ba052  0febd5                 -por mm2, mm5
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004ba055  4a                     -dec edx
    (cpu.edx)--;
    // 004ba056  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ba059  42                     -inc edx
    (cpu.edx)++;
    // 004ba05a  0f6ef2                 -movd mm6, edx
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ba05d  0f72d510               -psrld mm5, 0x10
    cpu.mmx.mm5 = { _mm_srli_epi32(cpu.mmx.mm5, 16 /*0x10*/) };
    // 004ba061  0febee                 -por mm5, mm6
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm6) };
    // 004ba064  0fefec                 -pxor mm5, mm4
    cpu.mmx.mm5 = { _mm_xor_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
    // 004ba067  0f6fe5                 -movq mm4, mm5
    cpu.mmx.mm4 = cpu.mmx.mm5;
    // 004ba06a  0f73f520               -psllq mm5, 0x20
    cpu.mmx.mm5 = { _mm_slli_epi64(cpu.mmx.mm5, 32 /*0x20*/) };
    // 004ba06e  0febec                 -por mm5, mm4
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
L_0x004ba071:
    // 004ba071  0f6e0c6e               -movd mm1, dword ptr [esi + ebp*2]
    cpu.mmx.mm1 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 2)) };
    // 004ba075  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004ba078  0f71d301               -psrlw mm3, 1
    cpu.mmx.mm3 = { _mm_srli_epi16(cpu.mmx.mm3, 1 /*0x1*/) };
    // 004ba07c  0f604c6e02             -punpcklbw mm1, dword ptr [esi + ebp*2 + 2]
    cpu.mmx.mm1 = { _mm_unpacklo_epi8(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.ebp * 2))) };
    // 004ba081  0f60c1                 -punpcklbw mm0, mm1
    cpu.mmx.mm0 = { _mm_unpacklo_epi8(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 004ba084  0ff5c3                 -pmaddwd mm0, mm3
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm3) };
    // 004ba087  0f72e017               -psrad mm0, 0x17
    cpu.mmx.mm0 = { _mm_srai_epi32(cpu.mmx.mm0, 23 /*0x17*/) };
    // 004ba08b  0ffdd5                 -paddw mm2, mm5
    cpu.mmx.mm2 = { _mm_add_epi16(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004ba08e  0f6bc1                 -packssdw mm0, mm1
    { __m128i _packed = _mm_packs_epi32(cpu.mmx.mm0, cpu.mmx.mm1); cpu.mmx.mm0 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004ba091  0f63c1                 -packsswb mm0, mm1
    { __m128i _packed = _mm_packs_epi16(cpu.mmx.mm0, cpu.mmx.mm1); cpu.mmx.mm0 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004ba094  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ba096  0f7e07                 -movd dword ptr [edi], mm0
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm0);
    // 004ba099  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ba09b  83c702                 +add edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ba09e  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ba09f  7fd0                   -jg 0x4ba071
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ba071;
    }
    // 004ba0a1  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ba0a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba0a4  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ba0a7  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004ba0a9  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ba0ac  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ba0ae  61                     -popal 
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
    // 004ba0af  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba0b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4ba0b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba0b4);
    // 004ba0b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ba0b5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ba0b7  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004ba0b8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ba0b9  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 004ba0be  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ba0c1  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004ba0c4  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004ba0c7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004ba0ca  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004ba0cd  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004ba0d0  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ba0d3  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ba0d5  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ba0d8  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004ba0db  0f6ecb                 -movd mm1, ebx
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ba0de  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ba0e1  0f72d110               -psrld mm1, 0x10
    cpu.mmx.mm1 = { _mm_srli_epi32(cpu.mmx.mm1, 16 /*0x10*/) };
    // 004ba0e5  0febca                 -por mm1, mm2
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004ba0e8  0fefcb                 -pxor mm1, mm3
    cpu.mmx.mm1 = { _mm_xor_si128(cpu.mmx.mm1, cpu.mmx.mm3) };
    // 004ba0eb  4a                     -dec edx
    (cpu.edx)--;
    // 004ba0ec  0f6ee2                 -movd mm4, edx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ba0ef  42                     -inc edx
    (cpu.edx)++;
    // 004ba0f0  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ba0f3  0f72d410               -psrld mm4, 0x10
    cpu.mmx.mm4 = { _mm_srli_epi32(cpu.mmx.mm4, 16 /*0x10*/) };
    // 004ba0f7  0febe5                 -por mm4, mm5
    cpu.mmx.mm4 = { _mm_or_si128(cpu.mmx.mm4, cpu.mmx.mm5) };
    // 004ba0fa  0fefe3                 -pxor mm4, mm3
    cpu.mmx.mm4 = { _mm_xor_si128(cpu.mmx.mm4, cpu.mmx.mm3) };
L_0x004ba0fd:
    // 004ba0fd  0f6e046e               -movd mm0, dword ptr [esi + ebp*2]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 2)) };
    // 004ba101  0f6fd1                 -movq mm2, mm1
    cpu.mmx.mm2 = cpu.mmx.mm1;
    // 004ba104  0f71d201               -psrlw mm2, 1
    cpu.mmx.mm2 = { _mm_srli_epi16(cpu.mmx.mm2, 1 /*0x1*/) };
    // 004ba108  0ff5c2                 -pmaddwd mm0, mm2
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm2) };
    // 004ba10b  0f73d00f               -psrlq mm0, 0xf
    cpu.mmx.mm0 = { _mm_srli_epi64(cpu.mmx.mm0, 15 /*0xf*/) };
    // 004ba10f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ba110  0f7ec1                 -movd ecx, mm0
    cpu.ecx = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004ba113  0ffdcc                 -paddw mm1, mm4
    cpu.mmx.mm1 = { _mm_add_epi16(cpu.mmx.mm1, cpu.mmx.mm4) };
    // 004ba116  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004ba119  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba11a  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ba11c  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ba11e  83c702                 +add edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ba121  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ba122  7fd9                   -jg 0x4ba0fd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ba0fd;
    }
    // 004ba124  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ba126  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba127  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ba12a  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004ba12c  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ba12f  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ba131  61                     -popal 
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
    // 004ba132  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba133  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba134(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba134);
    // 004ba134  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ba135  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ba137  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004ba138  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ba139  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 004ba13e  0f6ee3                 -movd mm4, ebx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ba141  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004ba144  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004ba147  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004ba14a  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004ba14d  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004ba150  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ba153  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ba155  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ba158  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004ba15b  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ba15e  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004ba161  0f72d210               -psrld mm2, 0x10
    cpu.mmx.mm2 = { _mm_srli_epi32(cpu.mmx.mm2, 16 /*0x10*/) };
    // 004ba165  0febd3                 -por mm2, mm3
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm3) };
    // 004ba168  0fefd4                 -pxor mm2, mm4
    cpu.mmx.mm2 = { _mm_xor_si128(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004ba16b  0f6fea                 -movq mm5, mm2
    cpu.mmx.mm5 = cpu.mmx.mm2;
    // 004ba16e  0f73f220               -psllq mm2, 0x20
    cpu.mmx.mm2 = { _mm_slli_epi64(cpu.mmx.mm2, 32 /*0x20*/) };
    // 004ba172  0febd5                 -por mm2, mm5
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004ba175  4a                     -dec edx
    (cpu.edx)--;
    // 004ba176  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ba179  42                     -inc edx
    (cpu.edx)++;
    // 004ba17a  0f6ef2                 -movd mm6, edx
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004ba17d  0f72d510               -psrld mm5, 0x10
    cpu.mmx.mm5 = { _mm_srli_epi32(cpu.mmx.mm5, 16 /*0x10*/) };
    // 004ba181  0febee                 -por mm5, mm6
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm6) };
    // 004ba184  0fefec                 -pxor mm5, mm4
    cpu.mmx.mm5 = { _mm_xor_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
    // 004ba187  0f6fe5                 -movq mm4, mm5
    cpu.mmx.mm4 = cpu.mmx.mm5;
    // 004ba18a  0f73f520               -psllq mm5, 0x20
    cpu.mmx.mm5 = { _mm_slli_epi64(cpu.mmx.mm5, 32 /*0x20*/) };
    // 004ba18e  0febec                 -por mm5, mm4
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
L_0x004ba191:
    // 004ba191  0f6e04ae               -movd mm0, dword ptr [esi + ebp*4]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 4)) };
    // 004ba195  0f6144ae04             -punpcklwd mm0, dword ptr [esi + ebp*4 + 4]
    cpu.mmx.mm0 = { _mm_unpacklo_epi16(cpu.mmx.mm0, x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4))) };
    // 004ba19a  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004ba19d  0f71d301               -psrlw mm3, 1
    cpu.mmx.mm3 = { _mm_srli_epi16(cpu.mmx.mm3, 1 /*0x1*/) };
    // 004ba1a1  0ff5c3                 -pmaddwd mm0, mm3
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm3) };
    // 004ba1a4  0f72e00f               -psrad mm0, 0xf
    cpu.mmx.mm0 = { _mm_srai_epi32(cpu.mmx.mm0, 15 /*0xf*/) };
    // 004ba1a8  0ffdd5                 -paddw mm2, mm5
    cpu.mmx.mm2 = { _mm_add_epi16(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004ba1ab  0f6bc1                 -packssdw mm0, mm1
    { __m128i _packed = _mm_packs_epi32(cpu.mmx.mm0, cpu.mmx.mm1); cpu.mmx.mm0 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004ba1ae  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ba1b0  0f7e07                 -movd dword ptr [edi], mm0
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm0);
    // 004ba1b3  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ba1b5  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ba1b8  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ba1b9  7fd6                   -jg 0x4ba191
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ba191;
    }
    // 004ba1bb  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ba1bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba1be  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ba1c1  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004ba1c3  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ba1c6  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ba1c8  61                     -popal 
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
    // 004ba1c9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba1ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba1d0);
    // 004ba1d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba1d1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba1d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ba1d6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba1da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba1db  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004ba1e0  e8b35a0000             -call 0x4bfc98
    cpu.esp -= 4;
    sub_4bfc98(app, cpu);
    if (cpu.terminate) return;
    // 004ba1e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba1e6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba1f0);
    // 004ba1f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba1f1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ba1f3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba1f7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba1fb  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ba201  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba205  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba206  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ba208  e8575b0000             -call 0x4bfd64
    cpu.esp -= 4;
    sub_4bfd64(app, cpu);
    if (cpu.terminate) return;
    // 004ba20d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba20e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba220);
    // 004ba220  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba224  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba228  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ba22e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004ba233  e8845c0000             -call 0x4bfebc
    cpu.esp -= 4;
    sub_4bfebc(app, cpu);
    if (cpu.terminate) return;
    // 004ba238  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba240);
    // 004ba240  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba241  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba245  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ba246  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba24a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba24b  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004ba250  e8435a0000             -call 0x4bfc98
    cpu.esp -= 4;
    sub_4bfc98(app, cpu);
    if (cpu.terminate) return;
    // 004ba255  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba256  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba260);
    // 004ba260  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba261  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ba263  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba267  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba26b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ba271  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba275  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba276  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004ba278  e8e75a0000             -call 0x4bfd64
    cpu.esp -= 4;
    sub_4bfd64(app, cpu);
    if (cpu.terminate) return;
    // 004ba27d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba27e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba290);
    // 004ba290  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba294  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba298  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ba29e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004ba2a3  e8145c0000             -call 0x4bfebc
    cpu.esp -= 4;
    sub_4bfebc(app, cpu);
    if (cpu.terminate) return;
    // 004ba2a8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba2b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba2b0);
    // 004ba2b0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ba2b3  b880ffffff             -mov eax, 0xffffff80
    cpu.eax = 4294967168 /*0xffffff80*/;
    // 004ba2b8  dd0578fc4c00           -fld qword ptr [0x4cfc78]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5045368) /* 0x4cfc78 */)));
L_0x004ba2be:
    // 004ba2be  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004ba2c1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ba2c3  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004ba2c6  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004ba2c8  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004ba2ca  40                     -inc eax
    (cpu.eax)++;
    // 004ba2cb  d91c95a4815b00         -fstp dword ptr [edx*4 + 0x5b81a4]
    app->getMemory<float>(x86::reg32(5996964) /* 0x5b81a4 */ + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ba2d2  83f87f                 +cmp eax, 0x7f
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
    // 004ba2d5  7ee7                   -jle 0x4ba2be
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ba2be;
    }
    // 004ba2d7  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ba2d9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ba2dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4ba2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba2e0);
    // 004ba2e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba2e1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba2e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ba2e6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba2ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba2eb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ba2ed  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ba2ef  e8d85c0000             -call 0x4bffcc
    cpu.esp -= 4;
    sub_4bffcc(app, cpu);
    if (cpu.terminate) return;
    // 004ba2f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba2f5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba300);
    // 004ba300  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba301  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ba303  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba307  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba30b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ba311  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba315  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba316  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ba318  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ba31a  e8815d0000             -call 0x4c00a0
    cpu.esp -= 4;
    sub_4c00a0(app, cpu);
    if (cpu.terminate) return;
    // 004ba31f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba320  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba330);
    // 004ba330  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba334  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba338  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba33a  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ba340  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ba342  e8e55e0000             -call 0x4c022c
    cpu.esp -= 4;
    sub_4c022c(app, cpu);
    if (cpu.terminate) return;
    // 004ba347  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba350);
    // 004ba350  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba351  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba355  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ba356  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba35a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba35b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ba35d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ba35f  e8685c0000             -call 0x4bffcc
    cpu.esp -= 4;
    sub_4bffcc(app, cpu);
    if (cpu.terminate) return;
    // 004ba364  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba365  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba370);
    // 004ba370  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba371  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ba373  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba377  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba37b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ba381  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba385  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba386  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ba388  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ba38a  e8115d0000             -call 0x4c00a0
    cpu.esp -= 4;
    sub_4c00a0(app, cpu);
    if (cpu.terminate) return;
    // 004ba38f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba390  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba3a0);
    // 004ba3a0  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba3a4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba3a8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004ba3ad  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ba3b3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ba3b5  e8725e0000             -call 0x4c022c
    cpu.esp -= 4;
    sub_4c022c(app, cpu);
    if (cpu.terminate) return;
    // 004ba3ba  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4ba3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba3c0);
    // 004ba3c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba3c1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba3c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ba3c6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba3ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba3cb  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004ba3d0  e8c3580000             -call 0x4bfc98
    cpu.esp -= 4;
    sub_4bfc98(app, cpu);
    if (cpu.terminate) return;
    // 004ba3d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba3d6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba3e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba3e0);
    // 004ba3e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba3e1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ba3e3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba3e7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba3eb  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ba3f1  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba3f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba3f6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004ba3f8  e867590000             -call 0x4bfd64
    cpu.esp -= 4;
    sub_4bfd64(app, cpu);
    if (cpu.terminate) return;
    // 004ba3fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba3fe  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba410);
    // 004ba410  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba414  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba418  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ba41e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004ba423  e8945a0000             -call 0x4bfebc
    cpu.esp -= 4;
    sub_4bfebc(app, cpu);
    if (cpu.terminate) return;
    // 004ba428  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba430);
    // 004ba430  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba431  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba435  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ba436  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba43a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba43b  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004ba440  e853580000             -call 0x4bfc98
    cpu.esp -= 4;
    sub_4bfc98(app, cpu);
    if (cpu.terminate) return;
    // 004ba445  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba446  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba450);
    // 004ba450  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba451  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ba453  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba457  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba45b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ba461  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba465  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba466  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004ba468  e8f7580000             -call 0x4bfd64
    cpu.esp -= 4;
    sub_4bfd64(app, cpu);
    if (cpu.terminate) return;
    // 004ba46d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba46e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba480);
    // 004ba480  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba484  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba488  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ba48e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004ba493  e8245a0000             -call 0x4bfebc
    cpu.esp -= 4;
    sub_4bfebc(app, cpu);
    if (cpu.terminate) return;
    // 004ba498  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba4a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba4a0);
    // 004ba4a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba4a1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba4a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ba4a6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba4aa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba4ab  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ba4ad  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004ba4b2  e8155b0000             -call 0x4bffcc
    cpu.esp -= 4;
    sub_4bffcc(app, cpu);
    if (cpu.terminate) return;
    // 004ba4b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba4b8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba4c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba4c0);
    // 004ba4c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba4c1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ba4c3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba4c7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba4cb  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ba4d1  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba4d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba4d6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ba4d8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ba4da  e8c15b0000             -call 0x4c00a0
    cpu.esp -= 4;
    sub_4c00a0(app, cpu);
    if (cpu.terminate) return;
    // 004ba4df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba4e0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba4f0);
    // 004ba4f0  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba4f4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba4f8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba4fa  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ba500  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004ba505  e8225d0000             -call 0x4c022c
    cpu.esp -= 4;
    sub_4c022c(app, cpu);
    if (cpu.terminate) return;
    // 004ba50a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4ba510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba510);
    // 004ba510  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba511  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba515  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ba516  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba51a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba51b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ba51d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004ba522  e8a55a0000             -call 0x4bffcc
    cpu.esp -= 4;
    sub_4bffcc(app, cpu);
    if (cpu.terminate) return;
    // 004ba527  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba528  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba530);
    // 004ba530  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba531  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ba533  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba537  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ba53b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ba541  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba545  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba546  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ba548  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ba54a  e8515b0000             -call 0x4c00a0
    cpu.esp -= 4;
    sub_4c00a0(app, cpu);
    if (cpu.terminate) return;
    // 004ba54f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba550  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba560);
    // 004ba560  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba564  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba568  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004ba56d  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004ba573  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba575  e8b25c0000             -call 0x4c022c
    cpu.esp -= 4;
    sub_4c022c(app, cpu);
    if (cpu.terminate) return;
    // 004ba57a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4ba580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba580);
    // 004ba580  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004ba583  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba584(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba584);
    // 004ba584  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ba585  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba586  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ba587  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ba588  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ba58a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ba58c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ba58e  8b5718                 -mov edx, dword ptr [edi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004ba591  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004ba594  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004ba596  39ca                   +cmp edx, ecx
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
    // 004ba598  7d3e                   -jge 0x4ba5d8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ba5d8;
    }
    // 004ba59a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ba59c  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004ba59f  8b471a                 -mov eax, dword ptr [edi + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(26) /* 0x1a */);
    // 004ba5a2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ba5a5  39c6                   +cmp esi, eax
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
    // 004ba5a7  7e39                   -jle 0x4ba5e2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ba5e2;
    }
    // 004ba5a9  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 004ba5ae  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ba5b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ba5b2:
    // 004ba5b2  8b7b1a                 -mov edi, dword ptr [ebx + 0x1a]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(26) /* 0x1a */);
    // 004ba5b5  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004ba5b8  39f8                   +cmp eax, edi
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
    // 004ba5ba  0f8d78000000           -jge 0x4ba638
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ba638;
    }
    // 004ba5c0  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004ba5c3  668b4a1e               -mov cx, word ptr [edx + 0x1e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004ba5c7  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004ba5ca  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004ba5cd  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba5d0  01ef                   +add edi, ebp
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
    // 004ba5d2  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ba5d3  897b0c                 -mov dword ptr [ebx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004ba5d6  ebda                   -jmp 0x4ba5b2
    goto L_0x004ba5b2;
L_0x004ba5d8:
    // 004ba5d8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ba5dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba5de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba5df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba5e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba5e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ba5e2:
    // 004ba5e2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba5e4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ba5e6  7e20                   -jle 0x4ba608
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ba608;
    }
    // 004ba5e8  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x004ba5ea:
    // 004ba5ea  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004ba5ed  668b4a1e               -mov cx, word ptr [edx + 0x1e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004ba5f1  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004ba5f4  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004ba5f7  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba5fa  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba5fd  40                     -inc eax
    (cpu.eax)++;
    // 004ba5fe  894b0c                 -mov dword ptr [ebx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004ba601  39f0                   +cmp eax, esi
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
    // 004ba603  7ce5                   -jl 0x4ba5ea
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ba5ea;
    }
    // 004ba605  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004ba608:
    // 004ba608  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004ba60a  8d1400                 -lea edx, [eax + eax]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004ba60d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ba60f  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004ba611:
    // 004ba611  8b4b1a                 -mov ecx, dword ptr [ebx + 0x1a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(26) /* 0x1a */);
    // 004ba614  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ba617  39c8                   +cmp eax, ecx
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
    // 004ba619  7d12                   -jge 0x4ba62d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ba62d;
    }
    // 004ba61b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba61e  47                     -inc edi
    (cpu.edi)++;
    // 004ba61f  668b4a1e               -mov cx, word ptr [edx + 0x1e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004ba623  83c202                 +add edx, 2
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ba626  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ba627  66894e1c               -mov word ptr [esi + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 004ba62b  ebe4                   -jmp 0x4ba611
    goto L_0x004ba611;
L_0x004ba62d:
    // 004ba62d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba62f  66897b1c               -mov word ptr [ebx + 0x1c], di
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.di;
    // 004ba633  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba634  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba635  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba636  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba637  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ba638:
    // 004ba638  8b6b14                 -mov ebp, dword ptr [ebx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004ba63b  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004ba63d  2b6b18                 -sub ebp, dword ptr [ebx + 0x18]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 004ba640  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ba642  0f8c7b000000           -jl 0x4ba6c3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ba6c3;
    }
L_0x004ba648:
    // 004ba648  39ee                   +cmp esi, ebp
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
    // 004ba64a  0f8d77000000           -jge 0x4ba6c7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ba6c7;
    }
    // 004ba650  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x004ba652:
    // 004ba652  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ba655  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004ba65c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba65e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ba660  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ba663  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ba665  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ba667  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ba66c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ba66f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ba671  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004ba674  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004ba676  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ba678  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ba679  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ba67c  e8df5b0000             -call 0x4c0260
    cpu.esp -= 4;
    sub_4c0260(app, cpu);
    if (cpu.terminate) return;
    // 004ba681  017b18                 -add dword ptr [ebx + 0x18], edi
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ba684  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ba686  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ba689  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba68b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ba68e  895318                 -mov dword ptr [ebx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004ba691  39fd                   +cmp ebp, edi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ba693  7536                   -jne 0x4ba6cb
    if (!cpu.flags.zf)
    {
        goto L_0x004ba6cb;
    }
    // 004ba695  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ba697  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004ba69a  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004ba69c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ba69e  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba6a0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ba6a2  7e18                   -jle 0x4ba6bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ba6bc;
    }
    // 004ba6a4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004ba6a6:
    // 004ba6a6  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004ba6a9  668910                 -mov word ptr [eax], dx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.dx;
    // 004ba6ac  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004ba6af  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba6b2  4e                     -dec esi
    (cpu.esi)--;
    // 004ba6b3  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004ba6b6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ba6b8  7fec                   -jg 0x4ba6a6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ba6a6;
    }
    // 004ba6ba  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004ba6bc:
    // 004ba6bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba6be  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba6bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba6c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba6c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba6c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ba6c3:
    // 004ba6c3  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004ba6c5  eb81                   -jmp 0x4ba648
    goto L_0x004ba648;
L_0x004ba6c7:
    // 004ba6c7  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004ba6c9  eb87                   -jmp 0x4ba652
    goto L_0x004ba652;
L_0x004ba6cb:
    // 004ba6cb  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ba6cd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba6cf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ba6d1  7c0b                   -jl 0x4ba6de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ba6de;
    }
    // 004ba6d3  6689431c               -mov word ptr [ebx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 004ba6d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba6d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba6da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba6db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba6dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba6dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ba6de:
    // 004ba6de  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba6e0  8d343f                 -lea esi, [edi + edi]
    cpu.esi = x86::reg32(cpu.edi + cpu.edi * 1);
L_0x004ba6e3:
    // 004ba6e3  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba6e6  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004ba6e9  47                     -inc edi
    (cpu.edi)++;
    // 004ba6ea  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba6ed  668b4c31fe             -mov cx, word ptr [ecx + esi - 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */ + cpu.esi * 1);
    // 004ba6f2  40                     -inc eax
    (cpu.eax)++;
    // 004ba6f3  66894a1c               -mov word ptr [edx + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 004ba6f7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ba6f9  7ce8                   -jl 0x4ba6e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ba6e3;
    }
    // 004ba6fb  6689431c               -mov word ptr [ebx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 004ba6ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba701  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba702  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba703  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba704  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba705  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ba708(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba708);
    // 004ba708  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004ba70f  66c7401c0000           -mov word ptr [eax + 0x1c], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004ba715  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004ba71b  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ba721  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004ba724  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004ba727  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ba72b  c70084a54b00           -mov dword ptr [eax], 0x4ba584
    app->getMemory<x86::reg32>(cpu.eax) = 4957572 /*0x4ba584*/;
    // 004ba731  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ba735  c70080a54b00           -mov dword ptr [eax], 0x4ba580
    app->getMemory<x86::reg32>(cpu.eax) = 4957568 /*0x4ba580*/;
    // 004ba73b  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 004ba740  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ba750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba750);
    // 004ba750  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba751  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ba752  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ba753  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ba756  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ba758  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ba75c  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004ba75f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ba761  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ba763  39d8                   +cmp eax, ebx
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
    // 004ba765  7d02                   -jge 0x4ba769
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ba769;
    }
    // 004ba767  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004ba769:
    // 004ba769  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba76b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ba76d  7e19                   -jle 0x4ba788
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ba788;
    }
    // 004ba76f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004ba773:
    // 004ba773  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba776  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx);
    // 004ba779  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba77c  40                     -inc eax
    (cpu.eax)++;
    // 004ba77d  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 004ba781  39f8                   +cmp eax, edi
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
    // 004ba783  7cee                   -jl 0x4ba773
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ba773;
    }
    // 004ba785  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004ba788:
    // 004ba788  39e8                   +cmp eax, ebp
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
    // 004ba78a  7d1c                   -jge 0x4ba7a8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ba7a8;
    }
    // 004ba78c  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ba790  8d1c00                 -lea ebx, [eax + eax]
    cpu.ebx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004ba793  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004ba795:
    // 004ba795  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba798  668b33                 -mov si, word ptr [ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx);
    // 004ba79b  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba79e  40                     -inc eax
    (cpu.eax)++;
    // 004ba79f  668971fe               -mov word ptr [ecx - 2], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.si;
    // 004ba7a3  39e8                   +cmp eax, ebp
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
    // 004ba7a5  7cee                   -jl 0x4ba795
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ba795;
    }
    // 004ba7a7  90                     -nop 
    ;
L_0x004ba7a8:
    // 004ba7a8  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ba7ab  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ba7ad  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ba7af  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ba7b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba7b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba7b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba7b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ba7b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba7b8);
    // 004ba7b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ba7b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba7ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ba7bb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ba7bc  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004ba7bf  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ba7c1  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ba7c3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ba7c5  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ba7c8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ba7ca  7e55                   -jle 0x4ba821
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ba821;
    }
    // 004ba7cc  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ba7cf  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004ba7d3  8d6826                 -lea ebp, [eax + 0x26]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(38) /* 0x26 */);
L_0x004ba7d6:
    // 004ba7d6  66837e2400             +cmp word ptr [esi + 0x24], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ba7db  755c                   -jne 0x4ba839
    if (!cpu.flags.zf)
    {
        goto L_0x004ba839;
    }
    // 004ba7dd  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ba7e0  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ba7e3  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004ba7e6  39c8                   +cmp eax, ecx
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
    // 004ba7e8  7d70                   -jge 0x4ba85a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ba85a;
    }
    // 004ba7ea  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004ba7ee  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ba7f3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ba7f5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ba7f8  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ba7fa  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ba7fd  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004ba803  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ba805  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba806  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ba809  e8525a0000             -call 0x4c0260
    cpu.esp -= 4;
    sub_4c0260(app, cpu);
    if (cpu.terminate) return;
    // 004ba80e  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ba811  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ba814  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ba817  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ba81a  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004ba81d:
    // 004ba81d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ba81f  7fb5                   -jg 0x4ba7d6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ba7d6;
    }
L_0x004ba821:
    // 004ba821  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004ba824  01460c                 -add dword ptr [esi + 0xc], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ba827  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ba829  0f8c3f010000           -jl 0x4ba96e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ba96e;
    }
    // 004ba82f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba831  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004ba834  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba835  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba836  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba837  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba838  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ba839:
    // 004ba839  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004ba83d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004ba83f  8b4622                 -mov eax, dword ptr [esi + 0x22]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004ba842  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ba844  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ba847  e804ffffff             -call 0x4ba750
    cpu.esp -= 4;
    sub_4ba750(app, cpu);
    if (cpu.terminate) return;
    // 004ba84c  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ba850  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba852  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ba854  66895e24               -mov word ptr [esi + 0x24], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 004ba858  ebc3                   -jmp 0x4ba81d
    goto L_0x004ba81d;
L_0x004ba85a:
    // 004ba85a  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004ba85e  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ba861  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ba866  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004ba86a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ba86c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ba86f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ba871  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004ba877  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ba87a  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004ba87d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ba87f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba880  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ba883  e8d8590000             -call 0x4c0260
    cpu.esp -= 4;
    sub_4c0260(app, cpu);
    if (cpu.terminate) return;
    // 004ba888  8346181c               -add dword ptr [esi + 0x18], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ba88c  668b5e20               -mov bx, word ptr [esi + 0x20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ba890  668b4618               -mov ax, word ptr [esi + 0x18]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ba894  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004ba899  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba89b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba89d  668b8694000000         -mov ax, word ptr [esi + 0x94]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 004ba8a4  66895624               -mov word ptr [esi + 0x24], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.dx;
    // 004ba8a8  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 004ba8ac  668b8696000000         -mov ax, word ptr [esi + 0x96]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(150) /* 0x96 */);
    // 004ba8b3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ba8b5  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004ba8b9  41                     -inc ecx
    (cpu.ecx)++;
    // 004ba8ba  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ba8bd  66894e24               -mov word ptr [esi + 0x24], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 004ba8c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ba8c3  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ba8c8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ba8cb  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ba8cd  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004ba8d0  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004ba8d3  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ba8d6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ba8d8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ba8db  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ba8dd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ba8e0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ba8e2  0f847a000000           -je 0x4ba962
    if (cpu.flags.zf)
    {
        goto L_0x004ba962;
    }
    // 004ba8e8  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004ba8ea  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004ba8ee  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ba8f3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ba8f5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ba8f8  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ba8fa  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ba8fd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ba8ff  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ba901  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ba904  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba905  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004ba908  e853590000             -call 0x4c0260
    cpu.esp -= 4;
    sub_4c0260(app, cpu);
    if (cpu.terminate) return;
    // 004ba90d  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ba910  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ba913  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ba916  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ba918  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ba91b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ba91d  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004ba921  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004ba926  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004ba92a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ba92c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004ba92e  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ba930  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004ba933  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ba935  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba937  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ba939  7e27                   -jle 0x4ba962
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ba962;
    }
L_0x004ba93b:
    // 004ba93b  8b4e22                 -mov ecx, dword ptr [esi + 0x22]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004ba93e  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ba941  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ba943  8d1c0e                 -lea ebx, [esi + ecx]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004ba946  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004ba949  66894b26               -mov word ptr [ebx + 0x26], cx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(38) /* 0x26 */) = cpu.cx;
    // 004ba94d  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ba951  43                     -inc ebx
    (cpu.ebx)++;
    // 004ba952  40                     -inc eax
    (cpu.eax)++;
    // 004ba953  66895e24               -mov word ptr [esi + 0x24], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 004ba957  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004ba95b  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba95e  39d8                   +cmp eax, ebx
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
    // 004ba960  7cd9                   -jl 0x4ba93b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ba93b;
    }
L_0x004ba962:
    // 004ba962  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004ba966  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004ba969  e9affeffff             -jmp 0x4ba81d
    goto L_0x004ba81d;
L_0x004ba96e:
    // 004ba96e  8b4622                 -mov eax, dword ptr [esi + 0x22]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004ba971  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ba974  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ba976  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ba979  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004ba97c  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 004ba97f  66894226               -mov word ptr [edx + 0x26], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(38) /* 0x26 */) = cpu.ax;
    // 004ba983  83460c02               -add dword ptr [esi + 0xc], 2
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba987  668b4e24               -mov cx, word ptr [esi + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ba98b  41                     -inc ecx
    (cpu.ecx)++;
    // 004ba98c  47                     -inc edi
    (cpu.edi)++;
    // 004ba98d  66894e24               -mov word ptr [esi + 0x24], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 004ba991  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ba993  7cd9                   -jl 0x4ba96e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ba96e;
    }
    // 004ba995  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba997  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004ba99a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba99b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba99c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba99d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ba99e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ba9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004ba9a0);
    // 004ba9a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ba9a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ba9a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ba9a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ba9a4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ba9a7  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ba9ab  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ba9ad  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ba9b0  8b5022                 -mov edx, dword ptr [eax + 0x22]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(34) /* 0x22 */);
    // 004ba9b3  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ba9b7  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004ba9ba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ba9bc  39ca                   +cmp edx, ecx
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
    // 004ba9be  7d2d                   -jge 0x4ba9ed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ba9ed;
    }
    // 004ba9c0  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004ba9c5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004ba9c7:
    // 004ba9c7  8b5622                 -mov edx, dword ptr [esi + 0x22]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004ba9ca  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004ba9cd  39d3                   +cmp ebx, edx
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
    // 004ba9cf  0f8d72000000           -jge 0x4baa47
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004baa47;
    }
    // 004ba9d5  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ba9d8  668b4826               -mov cx, word ptr [eax + 0x26]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 004ba9dc  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004ba9df  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ba9e2  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ba9e5  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ba9e7  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ba9e8  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004ba9eb  ebda                   -jmp 0x4ba9c7
    goto L_0x004ba9c7;
L_0x004ba9ed:
    // 004ba9ed  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba9ef  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ba9f1  7e21                   -jle 0x4baa14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004baa14;
    }
    // 004ba9f3  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004ba9f7:
    // 004ba9f7  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ba9fa  668b4826               -mov cx, word ptr [eax + 0x26]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 004ba9fe  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004baa01  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004baa04  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004baa07  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004baa0a  43                     -inc ebx
    (cpu.ebx)++;
    // 004baa0b  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004baa0e  39eb                   +cmp ebx, ebp
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
    // 004baa10  7ce5                   -jl 0x4ba9f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ba9f7;
    }
    // 004baa12  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004baa14:
    // 004baa14  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004baa16  8d141b                 -lea edx, [ebx + ebx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 004baa19  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004baa1b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004baa1d:
    // 004baa1d  8b4e22                 -mov ecx, dword ptr [esi + 0x22]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004baa20  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004baa23  39cb                   +cmp ebx, ecx
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
    // 004baa25  7d12                   -jge 0x4baa39
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004baa39;
    }
    // 004baa27  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004baa2a  47                     -inc edi
    (cpu.edi)++;
    // 004baa2b  668b4a26               -mov cx, word ptr [edx + 0x26]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(38) /* 0x26 */);
    // 004baa2f  83c202                 +add edx, 2
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004baa32  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004baa33  66894824               -mov word ptr [eax + 0x24], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 004baa37  ebe4                   -jmp 0x4baa1d
    goto L_0x004baa1d;
L_0x004baa39:
    // 004baa39  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004baa3b  66897e24               -mov word ptr [esi + 0x24], di
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.di;
    // 004baa3f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004baa42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baa43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baa44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baa45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baa46  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004baa47:
    // 004baa47  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004baa4a  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004baa4d  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004baa51  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004baa53  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004baa55  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004baa58  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004baa5c  39ef                   +cmp edi, ebp
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
    // 004baa5e  7e02                   -jle 0x4baa62
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004baa62;
    }
    // 004baa60  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x004baa62:
    // 004baa62  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004baa64  0f8cbb000000           -jl 0x4bab25
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bab25;
    }
L_0x004baa6a:
    // 004baa6a  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004baa6d  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004baa74  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004baa76  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004baa78  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004baa7b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004baa7d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004baa7f  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004baa84  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004baa87  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004baa89  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004baa8c  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004baa8e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004baa90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004baa91  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004baa94  e8c7570000             -call 0x4c0260
    cpu.esp -= 4;
    sub_4c0260(app, cpu);
    if (cpu.terminate) return;
    // 004baa99  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004baa9c  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004baa9f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004baaa1  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004baaa3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004baaa5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004baaa7  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004baaaa  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004baaac  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004baaae  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004baab1  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004baab5  8d0c00                 -lea ecx, [eax + eax]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004baab8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004baaba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004baabc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004baabe  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004baac0:
    // 004baac0  7c6a                   -jl 0x4bab2c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bab2c;
    }
    // 004baac2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004baac6  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004baac9  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004baacb  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004baacd  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004baad1  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004baad4  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004baad7  66895e24               -mov word ptr [esi + 0x24], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 004baadb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004baadd  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004baae0  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004baae3  7d36                   -jge 0x4bab1b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bab1b;
    }
    // 004baae5  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004baae9  66898694000000         -mov word ptr [esi + 0x94], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(148) /* 0x94 */) = cpu.ax;
    // 004baaf0  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004baaf4  66898696000000         -mov word ptr [esi + 0x96], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(150) /* 0x96 */) = cpu.ax;
    // 004baafb  8b8698000000           -mov eax, dword ptr [esi + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 004bab01  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bab05  c700b8a74b00           -mov dword ptr [eax], 0x4ba7b8
    app->getMemory<x86::reg32>(cpu.eax) = 4958136 /*0x4ba7b8*/;
    // 004bab0b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bab0d  7e0c                   -jle 0x4bab1b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bab1b;
    }
    // 004bab0f  8d5e0c                 -lea ebx, [esi + 0xc]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bab12  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bab14  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bab16  e89dfcffff             -call 0x4ba7b8
    cpu.esp -= 4;
    sub_4ba7b8(app, cpu);
    if (cpu.terminate) return;
L_0x004bab1b:
    // 004bab1b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bab1d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bab20  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bab21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bab22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bab23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bab24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bab25:
    // 004bab25  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004bab27  e93effffff             -jmp 0x4baa6a
    goto L_0x004baa6a;
L_0x004bab2c:
    // 004bab2c  8d0c16                 -lea ecx, [esi + edx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004bab2f  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bab32  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004bab35  668b0c28               -mov cx, word ptr [eax + ebp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1);
    // 004bab39  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004bab3c  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bab3f  66894d26               -mov word ptr [ebp + 0x26], cx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(38) /* 0x26 */) = cpu.cx;
    // 004bab43  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bab47  43                     -inc ebx
    (cpu.ebx)++;
    // 004bab48  41                     -inc ecx
    (cpu.ecx)++;
    // 004bab49  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bab4c  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004bab50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bab52  e969ffffff             -jmp 0x4baac0
    goto L_0x004baac0;
}

/* align: skip 0x90 */
void Application::sub_4bab58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bab58);
    // 004bab58  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004bab5f  66c740240000           -mov word ptr [eax + 0x24], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004bab65  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004bab6b  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bab71  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bab74  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004bab77  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004bab7a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bab7e  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004bab81  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bab85  899098000000           -mov dword ptr [eax + 0x98], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.edx;
    // 004bab8b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bab8f  c702a0a94b00           -mov dword ptr [edx], 0x4ba9a0
    app->getMemory<x86::reg32>(cpu.edx) = 4958624 /*0x4ba9a0*/;
    // 004bab95  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bab9b  b89c000000             -mov eax, 0x9c
    cpu.eax = 156 /*0x9c*/;
    // 004baba0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4babb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004babb0);
    // 004babb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004babb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004babb2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004babb3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004babb6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004babb8  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004babbb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004babbd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004babbf  0f84c8000000           -je 0x4bac8d
    if (cpu.flags.zf)
    {
        goto L_0x004bac8d;
    }
    // 004babc5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004babc6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004babc8  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004babcb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004babcd  0f8ea2000000           -jle 0x4bac75
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bac75;
    }
    // 004babd3  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004babd6  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004babda  8d501e                 -lea edx, [eax + 0x1e]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 004babdd  8d6814                 -lea ebp, [eax + 0x14]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004babe0  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004babe3  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004babe7  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004babeb:
    // 004babeb  66837e1c00             +cmp word ptr [esi + 0x1c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004babf0  0f85a3000000           -jne 0x4bac99
    if (!cpu.flags.zf)
    {
        goto L_0x004bac99;
    }
    // 004babf6  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004babf9  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004babfc  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004babff  39c8                   +cmp eax, ecx
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
    // 004bac01  0f8dbb000000           -jge 0x4bacc2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bacc2;
    }
    // 004bac07  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bac09  2b5618                 -sub edx, dword ptr [esi + 0x18]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)));
    // 004bac0c  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004bac11  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bac13  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bac16  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bac18  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bac1c  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004bac1f  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bac23  39c7                   +cmp edi, eax
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
    // 004bac25  7d11                   -jge 0x4bac38
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bac38;
    }
    // 004bac27  8d571b                 -lea edx, [edi + 0x1b]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(27) /* 0x1b */);
    // 004bac2a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bac2c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bac2f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bac31  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004bac34  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x004bac38:
    // 004bac38  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bac3c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bac40  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004bac42  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004bac47  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bac49  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bac4c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bac4e  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bac51  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bac53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bac54  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bac57  e804560000             -call 0x4c0260
    cpu.esp -= 4;
    sub_4c0260(app, cpu);
    if (cpu.terminate) return;
    // 004bac5c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bac5f  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bac62  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bac66  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bac68  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bac6a  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004bac6d:
    // 004bac6d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bac6f  0f8f76ffffff           -jg 0x4babeb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004babeb;
    }
L_0x004bac75:
    // 004bac75  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004bac78  01460c                 -add dword ptr [esi + 0xc], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bac7b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bac7d  0f8ce8000000           -jl 0x4bad6b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bad6b;
    }
    // 004bac83  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bac85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bac86  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004bac89  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bac8a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bac8b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bac8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bac8d:
    // 004bac8d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bac92  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004bac95  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bac96  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bac97  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bac98  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bac99:
    // 004bac99  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bac9d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004baca1  8b461a                 -mov eax, dword ptr [esi + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 004baca4  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004baca6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004baca9  e8a2faffff             -call 0x4ba750
    cpu.esp -= 4;
    sub_4ba750(app, cpu);
    if (cpu.terminate) return;
    // 004bacae  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bacb2  668b5e1c               -mov bx, word ptr [esi + 0x1c]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bacb6  2b5c2410               -sub ebx, dword ptr [esp + 0x10]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004bacba  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bacbc  66895e1c               -mov word ptr [esi + 0x1c], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.bx;
    // 004bacc0  ebab                   -jmp 0x4bac6d
    goto L_0x004bac6d;
L_0x004bacc2:
    // 004bacc2  837e1001               +cmp dword ptr [esi + 0x10], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bacc6  744f                   -je 0x4bad17
    if (cpu.flags.zf)
    {
        goto L_0x004bad17;
    }
    // 004bacc8  3b4e18                 +cmp ecx, dword ptr [esi + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004baccb  7e4a                   -jle 0x4bad17
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bad17;
    }
    // 004baccd  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bacd1  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004bacd6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bacd8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bacdb  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bacdd  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bace0  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bace6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bace8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bace9  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bacec  e86f550000             -call 0x4c0260
    cpu.esp -= 4;
    sub_4c0260(app, cpu);
    if (cpu.terminate) return;
    // 004bacf1  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bacf4  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bacf7  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bacfa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bacfc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bacff  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bad01  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004bad06  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bad09  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bad0b  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bad0d  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bad10  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bad12  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bad14  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x004bad17:
    // 004bad17  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bad1b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bad1d  ff1528ad4d00           -call dword ptr [0x4dad28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090600) /* 0x4dad28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bad23  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bad26  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bad28  7424                   -je 0x4bad4e
    if (cpu.flags.zf)
    {
        goto L_0x004bad4e;
    }
    // 004bad2a  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004bad2d  66895606               -mov word ptr [esi + 6], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 004bad31  668b4302               -mov ax, word ptr [ebx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004bad35  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004bad39  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bad3c  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004bad43  83c008                 +add eax, 8
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
    // 004bad46  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bad49  e91fffffff             -jmp 0x4bac6d
    goto L_0x004bac6d;
L_0x004bad4e:
    // 004bad4e  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bad51  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bad53  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bad55  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bad57  e81328fdff             -call 0x48d56f
    cpu.esp -= 4;
    sub_48d56f(app, cpu);
    if (cpu.terminate) return;
    // 004bad5c  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bad5f  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bad61  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004bad63  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bad66  e90affffff             -jmp 0x4bac75
    goto L_0x004bac75;
L_0x004bad6b:
    // 004bad6b  8b561a                 -mov edx, dword ptr [esi + 0x1a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 004bad6e  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bad71  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004bad74  668b00                 -mov ax, word ptr [eax]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax);
    // 004bad77  668944561e             -mov word ptr [esi + edx*2 + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(30) /* 0x1e */ + cpu.edx * 2) = cpu.ax;
    // 004bad7c  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bad7f  668b4e1c               -mov cx, word ptr [esi + 0x1c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bad83  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bad86  41                     -inc ecx
    (cpu.ecx)++;
    // 004bad87  895e0c                 -mov dword ptr [esi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004bad8a  47                     -inc edi
    (cpu.edi)++;
    // 004bad8b  66894e1c               -mov word ptr [esi + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 004bad8f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bad91  7cd8                   -jl 0x4bad6b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bad6b;
    }
    // 004bad93  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bad95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bad96  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004bad99  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bad9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bad9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bad9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bada0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bada0);
    // 004bada0  c7401001000000         -mov dword ptr [eax + 0x10], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004bada7  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004badae  66c7401c0000           -mov word ptr [eax + 0x1c], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004badb4  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004badba  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004badc0  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004badc3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004badc7  c700b0ab4b00           -mov dword ptr [eax], 0x4babb0
    app->getMemory<x86::reg32>(cpu.eax) = 4959152 /*0x4babb0*/;
    // 004badcd  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004badd1  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004badd7  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 004baddc  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_4bade0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bade0);
    // 004bade0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004bade3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bade4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bade4);
    // 004bade4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bade5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bade6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bade7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bade8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004badeb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004baded  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004badef  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004badf2  8b7818                 -mov edi, dword ptr [eax + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004badf5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004badf7  39f9                   +cmp ecx, edi
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
    // 004badf9  7d3f                   -jge 0x4bae3a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bae3a;
    }
    // 004badfb  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004badfd  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bae00  8b501e                 -mov edx, dword ptr [eax + 0x1e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 004bae03  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004bae06  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004bae08  39d6                   +cmp esi, edx
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
    // 004bae0a  7e3b                   -jle 0x4bae47
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bae47;
    }
    // 004bae0c  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004bae11  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004bae13:
    // 004bae13  8b4b1e                 -mov ecx, dword ptr [ebx + 0x1e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004bae16  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bae19  39ca                   +cmp edx, ecx
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
    // 004bae1b  0f8d8a000000           -jge 0x4baeab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004baeab;
    }
    // 004bae21  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bae24  668b4824               -mov cx, word ptr [eax + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004bae28  66894d00               -mov word ptr [ebp], cx
    app->getMemory<x86::reg16>(cpu.ebp) = cpu.cx;
    // 004bae2c  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bae2f  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bae32  01f9                   +add ecx, edi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bae34  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bae35  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004bae38  ebd9                   -jmp 0x4bae13
    goto L_0x004bae13;
L_0x004bae3a:
    // 004bae3a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bae3f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bae42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae46  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bae47:
    // 004bae47  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bae49  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bae4b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bae4d  7e1d                   -jle 0x4bae6c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bae6c;
    }
L_0x004bae4f:
    // 004bae4f  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bae52  668b7824               -mov di, word ptr [eax + 0x24]
    cpu.di = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004bae56  668939                 -mov word ptr [ecx], di
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.di;
    // 004bae59  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bae5c  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bae5f  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bae62  42                     -inc edx
    (cpu.edx)++;
    // 004bae63  896b10                 -mov dword ptr [ebx + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004bae66  39f2                   +cmp edx, esi
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
    // 004bae68  7ce5                   -jl 0x4bae4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bae4f;
    }
    // 004bae6a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004bae6c:
    // 004bae6c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bae6e  8d3412                 -lea esi, [edx + edx]
    cpu.esi = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004bae71  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004bae74  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bae76  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004bae78:
    // 004bae78  8b4b1e                 -mov ecx, dword ptr [ebx + 0x1e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004bae7b  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bae7e  39ca                   +cmp edx, ecx
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
    // 004bae80  7d18                   -jge 0x4bae9a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bae9a;
    }
    // 004bae82  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bae85  668b4e24               -mov cx, word ptr [esi + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bae89  66894822               -mov word ptr [eax + 0x22], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(34) /* 0x22 */) = cpu.cx;
    // 004bae8d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004bae90  83c602                 +add esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bae93  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bae94  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bae95  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004bae98  ebde                   -jmp 0x4bae78
    goto L_0x004bae78;
L_0x004bae9a:
    // 004bae9a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bae9d  66894320               -mov word ptr [ebx + 0x20], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ax;
    // 004baea1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004baea3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004baea6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baea7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baea8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baea9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baeaa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004baeab:
    // 004baeab  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004baeae  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004baeb1  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004baeb3  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004baeb5  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004baeb7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004baeb9  0f8c87000000           -jl 0x4baf46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004baf46;
    }
L_0x004baebf:
    // 004baebf  39ee                   +cmp esi, ebp
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
    // 004baec1  0f8d86000000           -jge 0x4baf4d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004baf4d;
    }
    // 004baec7  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
L_0x004baeca:
    // 004baeca  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004baecd  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004baecf  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004baed2  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004baed4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004baed6  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004baed9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004baedb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004baedd  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004baee2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004baee5  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004baee7  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004baeea  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004baeec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004baeed  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004baef0  e85b540000             -call 0x4c0350
    cpu.esp -= 4;
    sub_4c0350(app, cpu);
    if (cpu.terminate) return;
    // 004baef5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004baef8  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004baefb  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004baefe  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004baf00  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004baf02  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004baf04  89531c                 -mov dword ptr [ebx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004baf07  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004baf09  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004baf0c  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004baf0f  39fd                   +cmp ebp, edi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004baf11  7542                   -jne 0x4baf55
    if (!cpu.flags.zf)
    {
        goto L_0x004baf55;
    }
    // 004baf13  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004baf15  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004baf18  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004baf1a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004baf1c  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004baf1e  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004baf20  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004baf22  7e18                   -jle 0x4baf3c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004baf3c;
    }
    // 004baf24  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004baf26:
    // 004baf26  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004baf29  668910                 -mov word ptr [eax], dx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.dx;
    // 004baf2c  8b7b10                 -mov edi, dword ptr [ebx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004baf2f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004baf32  4e                     -dec esi
    (cpu.esi)--;
    // 004baf33  897b10                 -mov dword ptr [ebx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004baf36  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004baf38  7fec                   -jg 0x4baf26
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004baf26;
    }
    // 004baf3a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004baf3c:
    // 004baf3c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004baf3e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004baf41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baf42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baf43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baf44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baf45  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004baf46:
    // 004baf46  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004baf48  e972ffffff             -jmp 0x4baebf
    goto L_0x004baebf;
L_0x004baf4d:
    // 004baf4d  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004baf50  e975ffffff             -jmp 0x4baeca
    goto L_0x004baeca;
L_0x004baf55:
    // 004baf55  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004baf5a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004baf5c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004baf5e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004baf61  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004baf63  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004baf65  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004baf67  6bf6ff                 -imul esi, esi, -1
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004baf6a  83fee4                 +cmp esi, -0x1c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-28 /*-0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004baf6d  7502                   -jne 0x4baf71
    if (!cpu.flags.zf)
    {
        goto L_0x004baf71;
    }
    // 004baf6f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004baf71:
    // 004baf71  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004baf73  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004baf75  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004baf77  7c0e                   -jl 0x4baf87
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004baf87;
    }
    // 004baf79  66895320               -mov word ptr [ebx + 0x20], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.dx;
    // 004baf7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004baf7f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004baf82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baf83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baf84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baf85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baf86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004baf87:
    // 004baf87  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004baf89  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
L_0x004baf8c:
    // 004baf8c  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004baf8f  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004baf92  46                     -inc esi
    (cpu.esi)++;
    // 004baf93  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004baf96  668b7c28fe             -mov di, word ptr [eax + ebp - 2]
    cpu.di = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-2) /* -0x2 */ + cpu.ebp * 1);
    // 004baf9b  42                     -inc edx
    (cpu.edx)++;
    // 004baf9c  66897922               -mov word ptr [ecx + 0x22], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(34) /* 0x22 */) = cpu.di;
    // 004bafa0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bafa2  7ce8                   -jl 0x4baf8c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004baf8c;
    }
    // 004bafa4  66895320               -mov word ptr [ebx + 0x20], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.dx;
    // 004bafa8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bafaa  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bafad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bafae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bafaf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bafb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bafb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bafb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bafb4);
    // 004bafb4  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bafbb  66c740200000           -mov word ptr [eax + 0x20], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004bafc1  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004bafc7  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bafcd  66c7400a0000           -mov word ptr [eax + 0xa], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 004bafd3  66c740080000           -mov word ptr [eax + 8], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bafd9  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bafdc  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bafdf  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bafe3  c700e4ad4b00           -mov dword ptr [eax], 0x4bade4
    app->getMemory<x86::reg32>(cpu.eax) = 4959716 /*0x4bade4*/;
    // 004bafe9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bafed  c700e0ad4b00           -mov dword ptr [eax], 0x4bade0
    app->getMemory<x86::reg32>(cpu.eax) = 4959712 /*0x4bade0*/;
    // 004baff3  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 004baff8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bb000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb000);
    // 004bb000  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb001  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb002  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bb003  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bb006  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004bb008  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bb00c  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004bb00f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004bb011  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bb013  39d8                   +cmp eax, ebx
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
    // 004bb015  7d02                   -jge 0x4bb019
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb019;
    }
    // 004bb017  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004bb019:
    // 004bb019  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb01b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb01d  7e21                   -jle 0x4bb040
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb040;
    }
    // 004bb01f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004bb023:
    // 004bb023  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bb026  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx);
    // 004bb029  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb02c  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 004bb030  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bb033  668b59fe               -mov bx, word ptr [ecx - 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 004bb037  40                     -inc eax
    (cpu.eax)++;
    // 004bb038  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 004bb03c  39f8                   +cmp eax, edi
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
    // 004bb03e  7ce3                   -jl 0x4bb023
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb023;
    }
L_0x004bb040:
    // 004bb040  39e8                   +cmp eax, ebp
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
    // 004bb042  7d28                   -jge 0x4bb06c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb06c;
    }
    // 004bb044  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb048  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 004bb04f  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004bb051:
    // 004bb051  668b33                 -mov si, word ptr [ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx);
    // 004bb054  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb057  668931                 -mov word ptr [ecx], si
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.si;
    // 004bb05a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb05d  668b73fe               -mov si, word ptr [ebx - 2]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */);
    // 004bb061  40                     -inc eax
    (cpu.eax)++;
    // 004bb062  668971fe               -mov word ptr [ecx - 2], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.si;
    // 004bb066  39e8                   +cmp eax, ebp
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
    // 004bb068  7ce7                   -jl 0x4bb051
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb051;
    }
    // 004bb06a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004bb06c:
    // 004bb06c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bb06f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004bb071  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bb073  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bb076  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb077  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb078  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb079  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bb07c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb07c);
    // 004bb07c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb07d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb07e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb07f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bb080  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004bb083  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bb085  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bb087  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bb089  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bb08c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb08e  7e59                   -jle 0x4bb0e9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb0e9;
    }
    // 004bb090  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004bb093  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004bb097  8d682c                 -lea ebp, [eax + 0x2c]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
L_0x004bb09a:
    // 004bb09a  66837e2800             +cmp word ptr [esi + 0x28], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bb09f  7564                   -jne 0x4bb105
    if (!cpu.flags.zf)
    {
        goto L_0x004bb105;
    }
    // 004bb0a1  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bb0a4  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bb0a7  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004bb0aa  39c8                   +cmp eax, ecx
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
    // 004bb0ac  0f8d74000000           -jge 0x4bb126
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb126;
    }
    // 004bb0b2  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bb0b6  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bb0bb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bb0bd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb0c0  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bb0c2  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bb0c5  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bb0cb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb0cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb0ce  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bb0d1  e87a520000             -call 0x4c0350
    cpu.esp -= 4;
    sub_4c0350(app, cpu);
    if (cpu.terminate) return;
    // 004bb0d6  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bb0d9  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bb0dc  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bb0df  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb0e2  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x004bb0e5:
    // 004bb0e5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb0e7  7fb1                   -jg 0x4bb09a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bb09a;
    }
L_0x004bb0e9:
    // 004bb0e9  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004bb0f0  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb0f3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb0f5  0f8c63010000           -jl 0x4bb25e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb25e;
    }
    // 004bb0fb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb0fd  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004bb100  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb101  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb102  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb103  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb104  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bb105:
    // 004bb105  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004bb109  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bb10b  8b4626                 -mov eax, dword ptr [esi + 0x26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004bb10e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bb110  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004bb113  e8e8feffff             -call 0x4bb000
    cpu.esp -= 4;
    sub_4bb000(app, cpu);
    if (cpu.terminate) return;
    // 004bb118  668b5e28               -mov bx, word ptr [esi + 0x28]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bb11c  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb11e  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bb120  66895e28               -mov word ptr [esi + 0x28], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 004bb124  ebbf                   -jmp 0x4bb0e5
    goto L_0x004bb0e5;
L_0x004bb126:
    // 004bb126  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bb12a  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb12d  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bb132  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 004bb136  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bb138  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb13b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bb13d  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bb143  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bb146  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004bb149  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb14b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb14c  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bb14f  e8fc510000             -call 0x4c0350
    cpu.esp -= 4;
    sub_4c0350(app, cpu);
    if (cpu.terminate) return;
    // 004bb154  83461c1c               -add dword ptr [esi + 0x1c], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bb158  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bb15c  668b461c               -mov ax, word ptr [esi + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bb160  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004bb165  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bb167  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb169  668b8608010000         -mov ax, word ptr [esi + 0x108]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(264) /* 0x108 */);
    // 004bb170  66895628               -mov word ptr [esi + 0x28], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.dx;
    // 004bb174  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 004bb178  668b860a010000         -mov ax, word ptr [esi + 0x10a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(266) /* 0x10a */);
    // 004bb17f  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004bb183  668b860c010000         -mov ax, word ptr [esi + 0x10c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 004bb18a  6689460a               -mov word ptr [esi + 0xa], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 004bb18e  668b860e010000         -mov ax, word ptr [esi + 0x10e]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(270) /* 0x10e */);
    // 004bb195  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bb197  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004bb19b  41                     -inc ecx
    (cpu.ecx)++;
    // 004bb19c  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bb19f  66894e28               -mov word ptr [esi + 0x28], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 004bb1a3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bb1a5  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bb1aa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb1ad  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bb1af  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004bb1b2  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004bb1b5  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bb1b8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bb1ba  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb1bd  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bb1bf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb1c2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bb1c4  0f8488000000           -je 0x4bb252
    if (cpu.flags.zf)
    {
        goto L_0x004bb252;
    }
    // 004bb1ca  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004bb1cc  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bb1d0  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bb1d5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bb1d7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb1da  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bb1dc  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bb1df  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb1e1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bb1e3  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bb1e6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb1e7  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bb1ea  e861510000             -call 0x4c0350
    cpu.esp -= 4;
    sub_4c0350(app, cpu);
    if (cpu.terminate) return;
    // 004bb1ef  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bb1f2  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bb1f5  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bb1f8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bb1fa  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb1fd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb1ff  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 004bb204  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 004bb208  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb20a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb20c  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004bb20f  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004bb212  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004bb214  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004bb218  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bb21a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb21c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bb21e  7e32                   -jle 0x4bb252
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb252;
    }
L_0x004bb220:
    // 004bb220  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004bb223  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bb226  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 004bb229  66895c8e2c             -mov word ptr [esi + ecx*4 + 0x2c], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.ecx * 4) = cpu.bx;
    // 004bb22e  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004bb231  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bb234  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004bb238  66895c8e2e             -mov word ptr [esi + ecx*4 + 0x2e], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */ + cpu.ecx * 4) = cpu.bx;
    // 004bb23d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb240  668b5e28               -mov bx, word ptr [esi + 0x28]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bb244  42                     -inc edx
    (cpu.edx)++;
    // 004bb245  43                     -inc ebx
    (cpu.ebx)++;
    // 004bb246  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004bb24a  66895e28               -mov word ptr [esi + 0x28], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 004bb24e  39ca                   +cmp edx, ecx
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
    // 004bb250  7cce                   -jl 0x4bb220
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb220;
    }
L_0x004bb252:
    // 004bb252  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004bb256  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bb259  e987feffff             -jmp 0x4bb0e5
    goto L_0x004bb0e5;
L_0x004bb25e:
    // 004bb25e  8b4626                 -mov eax, dword ptr [esi + 0x26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004bb261  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004bb264  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bb267  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb26a  8d0c06                 -lea ecx, [esi + eax]
    cpu.ecx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004bb26d  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 004bb270  6689412c               -mov word ptr [ecx + 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.ax;
    // 004bb274  8b4626                 -mov eax, dword ptr [esi + 0x26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004bb277  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004bb27a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bb27d  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb280  8d0c06                 -lea ecx, [esi + eax]
    cpu.ecx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004bb283  668b4202               -mov ax, word ptr [edx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004bb287  6689412e               -mov word ptr [ecx + 0x2e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(46) /* 0x2e */) = cpu.ax;
    // 004bb28b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb28e  668b4e28               -mov cx, word ptr [esi + 0x28]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bb292  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb295  41                     -inc ecx
    (cpu.ecx)++;
    // 004bb296  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bb299  47                     -inc edi
    (cpu.edi)++;
    // 004bb29a  66894e28               -mov word ptr [esi + 0x28], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 004bb29e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb2a0  7cbc                   -jl 0x4bb25e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb25e;
    }
    // 004bb2a2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb2a4  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004bb2a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb2ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb2ac);
    // 004bb2ac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb2ad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb2ae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb2af  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bb2b0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bb2b3  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004bb2b5  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bb2b7  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bb2ba  8b5026                 -mov edx, dword ptr [eax + 0x26]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 004bb2bd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004bb2c0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bb2c2  39d5                   +cmp ebp, edx
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
    // 004bb2c4  7e38                   -jle 0x4bb2fe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb2fe;
    }
    // 004bb2c6  bf04000000             -mov edi, 4
    cpu.edi = 4 /*0x4*/;
    // 004bb2cb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bb2cd:
    // 004bb2cd  8b5626                 -mov edx, dword ptr [esi + 0x26]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004bb2d0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004bb2d3  39d3                   +cmp ebx, edx
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
    // 004bb2d5  0f8da2000000           -jge 0x4bb37d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb37d;
    }
    // 004bb2db  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb2de  668b482c               -mov cx, word ptr [eax + 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004bb2e2  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004bb2e5  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb2e8  668b482e               -mov cx, word ptr [eax + 0x2e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 004bb2ec  66894a02               -mov word ptr [edx + 2], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cx;
    // 004bb2f0  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb2f3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb2f6  01f9                   +add ecx, edi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bb2f8  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bb2f9  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004bb2fc  ebcf                   -jmp 0x4bb2cd
    goto L_0x004bb2cd;
L_0x004bb2fe:
    // 004bb2fe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bb300  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bb302  7e28                   -jle 0x4bb32c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb32c;
    }
L_0x004bb304:
    // 004bb304  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb307  668b482c               -mov cx, word ptr [eax + 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004bb30b  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004bb30e  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb311  668b502e               -mov dx, word ptr [eax + 0x2e]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 004bb315  66895102               -mov word ptr [ecx + 2], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 004bb319  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb31c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb31f  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb322  43                     -inc ebx
    (cpu.ebx)++;
    // 004bb323  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004bb326  39eb                   +cmp ebx, ebp
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
    // 004bb328  7cda                   -jl 0x4bb304
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb304;
    }
    // 004bb32a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004bb32c:
    // 004bb32c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bb32e  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004bb330  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 004bb337  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004bb33b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004bb33d:
    // 004bb33d  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004bb340  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bb343  39cb                   +cmp ebx, ecx
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
    // 004bb345  7d22                   -jge 0x4bb369
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb369;
    }
    // 004bb347  668b4a2c               -mov cx, word ptr [edx + 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 004bb34b  6689482c               -mov word ptr [eax + 0x2c], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.cx;
    // 004bb34f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb352  668b4a2e               -mov cx, word ptr [edx + 0x2e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(46) /* 0x2e */);
    // 004bb356  6689482a               -mov word ptr [eax + 0x2a], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(42) /* 0x2a */) = cpu.cx;
    // 004bb35a  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb35e  83c204                 +add edx, 4
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
    // 004bb361  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bb362  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bb363  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004bb367  ebd4                   -jmp 0x4bb33d
    goto L_0x004bb33d;
L_0x004bb369:
    // 004bb369  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb36d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb36f  66894628               -mov word ptr [esi + 0x28], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ax;
    // 004bb373  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bb375  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bb378  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb379  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb37a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb37b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb37c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bb37d:
    // 004bb37d  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bb380  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb382  2b461c                 -sub eax, dword ptr [esi + 0x1c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 004bb385  83e81c                 -sub eax, 0x1c
    (cpu.eax) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bb388  39c5                   +cmp ebp, eax
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
    // 004bb38a  0f8de1000000           -jge 0x4bb471
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb471;
    }
    // 004bb390  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
L_0x004bb394:
    // 004bb394  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004bb399  0f8cdb000000           -jl 0x4bb47a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb47a;
    }
L_0x004bb39f:
    // 004bb39f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb3a3  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004bb3a5  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bb3a8  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb3aa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bb3ac  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004bb3af  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb3b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bb3b3  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bb3b8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb3bb  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bb3bd  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bb3c0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb3c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb3c3  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bb3c6  e8854f0000             -call 0x4c0350
    cpu.esp -= 4;
    sub_4c0350(app, cpu);
    if (cpu.terminate) return;
    // 004bb3cb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb3ce  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bb3d1  037c2404               -add edi, dword ptr [esp + 4]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004bb3d5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bb3d7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004bb3d9  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bb3db  897e1c                 -mov dword ptr [esi + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 004bb3de  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb3e0  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bb3e2  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bb3e5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004bb3e8  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004bb3ef  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb3f1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bb3f3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bb3f5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bb3f8:
    // 004bb3f8  0f8c87000000           -jl 0x4bb485
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb485;
    }
    // 004bb3fe  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb401  66895e28               -mov word ptr [esi + 0x28], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 004bb405  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb407  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bb40a  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bb40d  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bb410  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb414  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bb416  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb418  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bb41b  7d48                   -jge 0x4bb465
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb465;
    }
    // 004bb41d  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004bb421  66898608010000         -mov word ptr [esi + 0x108], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(264) /* 0x108 */) = cpu.ax;
    // 004bb428  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004bb42c  6689860a010000         -mov word ptr [esi + 0x10a], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(266) /* 0x10a */) = cpu.ax;
    // 004bb433  668b460a               -mov ax, word ptr [esi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004bb437  6689860c010000         -mov word ptr [esi + 0x10c], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.ax;
    // 004bb43e  668b4608               -mov ax, word ptr [esi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004bb442  6689860e010000         -mov word ptr [esi + 0x10e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(270) /* 0x10e */) = cpu.ax;
    // 004bb449  8b8610010000           -mov eax, dword ptr [esi + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 004bb44f  c7007cb04b00           -mov dword ptr [eax], 0x4bb07c
    app->getMemory<x86::reg32>(cpu.eax) = 4960380 /*0x4bb07c*/;
    // 004bb455  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bb457  7e0c                   -jle 0x4bb465
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb465;
    }
    // 004bb459  8d5e10                 -lea ebx, [esi + 0x10]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb45c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bb45e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bb460  e817fcffff             -call 0x4bb07c
    cpu.esp -= 4;
    sub_4bb07c(app, cpu);
    if (cpu.terminate) return;
L_0x004bb465:
    // 004bb465  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb467  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bb469  83c408                 +add esp, 8
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
    // 004bb46c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb46d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb46e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb46f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb470  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bb471:
    // 004bb471  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004bb475  e91affffff             -jmp 0x4bb394
    goto L_0x004bb394;
L_0x004bb47a:
    // 004bb47a  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004bb47c  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004bb480  e91affffff             -jmp 0x4bb39f
    goto L_0x004bb39f;
L_0x004bb485:
    // 004bb485  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb488  8d3c01                 -lea edi, [ecx + eax]
    cpu.edi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004bb48b  8d0c16                 -lea ecx, [esi + edx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004bb48e  668b3f                 -mov di, word ptr [edi]
    cpu.di = app->getMemory<x86::reg16>(cpu.edi);
    // 004bb491  6689792c               -mov word ptr [ecx + 0x2c], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.di;
    // 004bb495  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb498  668b7c0702             -mov di, word ptr [edi + eax + 2]
    cpu.di = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(2) /* 0x2 */ + cpu.eax * 1);
    // 004bb49d  43                     -inc ebx
    (cpu.ebx)++;
    // 004bb49e  6689792e               -mov word ptr [ecx + 0x2e], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(46) /* 0x2e */) = cpu.di;
    // 004bb4a2  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004bb4a5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb4a8  47                     -inc edi
    (cpu.edi)++;
    // 004bb4a9  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb4ac  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004bb4af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bb4b1  e942ffffff             -jmp 0x4bb3f8
    goto L_0x004bb3f8;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bb4b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb4b8);
    // 004bb4b8  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bb4bf  66c740280000           -mov word ptr [eax + 0x28], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004bb4c5  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004bb4cb  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bb4d1  66c7400a0000           -mov word ptr [eax + 0xa], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 004bb4d7  66c740080000           -mov word ptr [eax + 8], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bb4dd  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bb4e0  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bb4e3  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004bb4e6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb4ea  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004bb4ed  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bb4f1  899010010000           -mov dword ptr [eax + 0x110], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(272) /* 0x110 */) = cpu.edx;
    // 004bb4f7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bb4fb  c702acb24b00           -mov dword ptr [edx], 0x4bb2ac
    app->getMemory<x86::reg32>(cpu.edx) = 4960940 /*0x4bb2ac*/;
    // 004bb501  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bb507  b814010000             -mov eax, 0x114
    cpu.eax = 276 /*0x114*/;
    // 004bb50c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_4bb510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb510);
    // 004bb510  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb511  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb512  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bb513  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bb516  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bb518  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004bb51b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bb51d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bb51f  0f848d000000           -je 0x4bb5b2
    if (cpu.flags.zf)
    {
        goto L_0x004bb5b2;
    }
    // 004bb525  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb526  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bb528  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bb52b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb52d  7e67                   -jle 0x4bb596
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb596;
    }
    // 004bb52f  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004bb532  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bb536  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004bb539  8d6818                 -lea ebp, [eax + 0x18]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004bb53c  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bb53f  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bb543  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004bb547:
    // 004bb547  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bb54a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bb54c  756b                   -jne 0x4bb5b9
    if (!cpu.flags.zf)
    {
        goto L_0x004bb5b9;
    }
    // 004bb54e  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bb551  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bb554  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004bb557  39d0                   +cmp eax, edx
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
    // 004bb559  0f8d77000000           -jge 0x4bb5d6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb5d6;
    }
    // 004bb55f  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bb563  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004bb568  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bb56a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb56d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bb56f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bb572  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bb578  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb57a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb57b  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bb57e  e8cd4d0000             -call 0x4c0350
    cpu.esp -= 4;
    sub_4c0350(app, cpu);
    if (cpu.terminate) return;
    // 004bb583  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bb586  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bb589  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bb58c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb58f  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
L_0x004bb592:
    // 004bb592  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb594  7fb1                   -jg 0x4bb547
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bb547;
    }
L_0x004bb596:
    // 004bb596  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004bb59d  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb5a0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb5a2  0f8ce5000000           -jl 0x4bb68d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb68d;
    }
    // 004bb5a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb5aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004bb5ab:
    // 004bb5ab  83c40c                 +add esp, 0xc
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
    // 004bb5ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb5af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb5b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb5b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bb5b2:
    // 004bb5b2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bb5b7  ebf2                   -jmp 0x4bb5ab
    goto L_0x004bb5ab;
L_0x004bb5b9:
    // 004bb5b9  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb5bd  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bb5c1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bb5c3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bb5c5  e836faffff             -call 0x4bb000
    cpu.esp -= 4;
    sub_4bb000(app, cpu);
    if (cpu.terminate) return;
    // 004bb5ca  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bb5cd  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb5cf  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bb5d1  895620                 -mov dword ptr [esi + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004bb5d4  ebbc                   -jmp 0x4bb592
    goto L_0x004bb592;
L_0x004bb5d6:
    // 004bb5d6  837e1401               +cmp dword ptr [esi + 0x14], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bb5da  7445                   -je 0x4bb621
    if (cpu.flags.zf)
    {
        goto L_0x004bb621;
    }
    // 004bb5dc  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bb5e0  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004bb5e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bb5e7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb5ea  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bb5ec  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bb5ef  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bb5f5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb5f7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb5f8  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bb5fb  e8504d0000             -call 0x4c0350
    cpu.esp -= 4;
    sub_4c0350(app, cpu);
    if (cpu.terminate) return;
    // 004bb600  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bb603  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bb605  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bb608  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004bb60b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb60d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bb60f  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb612  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb614  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bb617  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb61a  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb61c  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb61e  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x004bb621:
    // 004bb621  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bb625  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bb627  ff1528ad4d00           -call dword ptr [0x4dad28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090600) /* 0x4dad28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb62d  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bb630  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bb632  7434                   -je 0x4bb668
    if (cpu.flags.zf)
    {
        goto L_0x004bb668;
    }
    // 004bb634  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004bb637  66895606               -mov word ptr [esi + 6], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 004bb63b  668b5302               -mov dx, word ptr [ebx + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004bb63f  66895604               -mov word ptr [esi + 4], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 004bb643  668b5304               -mov dx, word ptr [ebx + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004bb647  6689560a               -mov word ptr [esi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 004bb64b  668b4306               -mov ax, word ptr [ebx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004bb64f  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004bb653  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bb656  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bb65d  83c008                 +add eax, 8
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
    // 004bb660  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004bb663  e92affffff             -jmp 0x4bb592
    goto L_0x004bb592;
L_0x004bb668:
    // 004bb668  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bb66a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb66c  0f8e20ffffff           -jle 0x4bb592
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb592;
    }
L_0x004bb672:
    // 004bb672  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb675  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 004bb67a  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb67d  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bb680  4f                     -dec edi
    (cpu.edi)--;
    // 004bb681  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bb684  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb686  7fea                   -jg 0x4bb672
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bb672;
    }
    // 004bb688  e905ffffff             -jmp 0x4bb592
    goto L_0x004bb592;
L_0x004bb68d:
    // 004bb68d  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb690  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bb693  668b12                 -mov dx, word ptr [edx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx);
    // 004bb696  6689548624             -mov word ptr [esi + eax*4 + 0x24], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.eax * 4) = cpu.dx;
    // 004bb69b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb69e  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bb6a1  668b5202               -mov dx, word ptr [edx + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004bb6a5  6689548626             -mov word ptr [esi + eax*4 + 0x26], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(38) /* 0x26 */ + cpu.eax * 4) = cpu.dx;
    // 004bb6aa  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb6ad  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bb6b0  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb6b3  43                     -inc ebx
    (cpu.ebx)++;
    // 004bb6b4  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004bb6b7  47                     -inc edi
    (cpu.edi)++;
    // 004bb6b8  895e20                 -mov dword ptr [esi + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004bb6bb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb6bd  7cce                   -jl 0x4bb68d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb68d;
    }
    // 004bb6bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb6c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb6c2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bb6c5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb6c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb6c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb6c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bb6cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb6cc);
    // 004bb6cc  c7401401000000         -mov dword ptr [eax + 0x14], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004bb6d3  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bb6da  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004bb6e1  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004bb6e7  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bb6ed  66c7400a0000           -mov word ptr [eax + 0xa], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 004bb6f3  66c740080000           -mov word ptr [eax + 8], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bb6f9  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bb6fc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bb700  c70010b54b00           -mov dword ptr [eax], 0x4bb510
    app->getMemory<x86::reg32>(cpu.eax) = 4961552 /*0x4bb510*/;
    // 004bb706  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bb70a  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bb710  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 004bb715  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bb720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb720);
    // 004bb720  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004bb723  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb724(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb724);
    // 004bb724  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb725  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb726  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb727  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bb728  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bb72a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bb72c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bb72e  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004bb731  8b7918                 -mov edi, dword ptr [ecx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004bb734  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bb736  39fa                   +cmp edx, edi
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
    // 004bb738  7d64                   -jge 0x4bb79e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb79e;
    }
    // 004bb73a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004bb73c  8b6920                 -mov ebp, dword ptr [ecx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004bb73f  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bb742  39ee                   +cmp esi, ebp
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
    // 004bb744  7f62                   -jg 0x4bb7a8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bb7a8;
    }
    // 004bb746  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb748  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bb74a  7e1c                   -jle 0x4bb768
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb768;
    }
    // 004bb74c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004bb74e:
    // 004bb74e  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bb751  8b7a24                 -mov edi, dword ptr [edx + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 004bb754  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 004bb756  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bb759  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb75c  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb75f  40                     -inc eax
    (cpu.eax)++;
    // 004bb760  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004bb763  39f0                   +cmp eax, esi
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
    // 004bb765  7ce7                   -jl 0x4bb74e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb74e;
    }
    // 004bb767  90                     -nop 
    ;
L_0x004bb768:
    // 004bb768  8b7320                 -mov esi, dword ptr [ebx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004bb76b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bb76d  39f0                   +cmp eax, esi
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
    // 004bb76f  7d23                   -jge 0x4bb794
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb794;
    }
    // 004bb771  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004bb778  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004bb77a  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bb77c:
    // 004bb77c  d94224                 -fld dword ptr [edx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */)));
    // 004bb77f  41                     -inc ecx
    (cpu.ecx)++;
    // 004bb780  40                     -inc eax
    (cpu.eax)++;
    // 004bb781  d95e24                 -fstp dword ptr [esi + 0x24]
    app->getMemory<float>(cpu.esi + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bb784  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb787  8b7b20                 -mov edi, dword ptr [ebx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004bb78a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb78d  39f8                   +cmp eax, edi
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
    // 004bb78f  7ceb                   -jl 0x4bb77c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb77c;
    }
    // 004bb791  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bb794:
    // 004bb794  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb796  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004bb799  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb79a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb79b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb79c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb79d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bb79e:
    // 004bb79e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bb7a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb7a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb7a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb7a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb7a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bb7a8:
    // 004bb7a8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb7aa  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bb7ac  7e1e                   -jle 0x4bb7cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb7cc;
    }
    // 004bb7ae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004bb7b0:
    // 004bb7b0  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bb7b3  d94024                 -fld dword ptr [eax + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */)));
    // 004bb7b6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb7b9  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bb7bb  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bb7be  42                     -inc edx
    (cpu.edx)++;
    // 004bb7bf  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb7c2  8b7b20                 -mov edi, dword ptr [ebx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004bb7c5  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004bb7c8  39fa                   +cmp edx, edi
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
    // 004bb7ca  7ce4                   -jl 0x4bb7b0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb7b0;
    }
L_0x004bb7cc:
    // 004bb7cc  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bb7cf  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004bb7d2  8b6b20                 -mov ebp, dword ptr [ebx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004bb7d5  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb7d7  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004bb7d9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb7db  0f8c7e000000           -jl 0x4bb85f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb85f;
    }
L_0x004bb7e1:
    // 004bb7e1  39fe                   +cmp esi, edi
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
    // 004bb7e3  0f8d7d000000           -jge 0x4bb866
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb866;
    }
    // 004bb7e9  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004bb7eb:
    // 004bb7eb  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004bb7ee  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004bb7f5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bb7f7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bb7f9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bb7fc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb7fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bb800  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bb805  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb808  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bb80a  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004bb80d  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 004bb80f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb811  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bb812  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bb815  e8c64d0000             -call 0x4c05e0
    cpu.esp -= 4;
    sub_4c05e0(app, cpu);
    if (cpu.terminate) return;
    // 004bb81a  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004bb81d  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004bb81f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bb821  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bb823  89531c                 -mov dword ptr [ebx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bb826  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb828  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb82b  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004bb82e  39ef                   +cmp edi, ebp
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
    // 004bb830  7538                   -jne 0x4bb86a
    if (!cpu.flags.zf)
    {
        goto L_0x004bb86a;
    }
    // 004bb832  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bb834  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bb837  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004bb839  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bb83b  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb83d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bb83f  7e17                   -jle 0x4bb858
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb858;
    }
L_0x004bb841:
    // 004bb841  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bb844  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bb84a  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bb84d  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb850  4e                     -dec esi
    (cpu.esi)--;
    // 004bb851  896b10                 -mov dword ptr [ebx + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004bb854  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bb856  7fe9                   -jg 0x4bb841
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bb841;
    }
L_0x004bb858:
    // 004bb858  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb85a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb85b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb85c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb85d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb85e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bb85f:
    // 004bb85f  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004bb861  e97bffffff             -jmp 0x4bb7e1
    goto L_0x004bb7e1;
L_0x004bb866:
    // 004bb866  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004bb868  eb81                   -jmp 0x4bb7eb
    goto L_0x004bb7eb;
L_0x004bb86a:
    // 004bb86a  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bb86c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bb86e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bb870  7c0a                   -jl 0x4bb87c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb87c;
    }
    // 004bb872  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004bb875  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb877  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb878  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb879  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb87a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb87b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bb87c:
    // 004bb87c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bb87e  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
L_0x004bb885:
    // 004bb885  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb888  46                     -inc esi
    (cpu.esi)++;
    // 004bb889  8b7b10                 -mov edi, dword ptr [ebx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bb88c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb88f  41                     -inc ecx
    (cpu.ecx)++;
    // 004bb890  8b6c07fc               -mov ebp, dword ptr [edi + eax - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004bb894  896a20                 -mov dword ptr [edx + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004bb897  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bb899  7cea                   -jl 0x4bb885
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb885;
    }
    // 004bb89b  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004bb89e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb8a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb8a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb8a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb8a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb8a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bb8a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb8a8);
    // 004bb8a8  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bb8af  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004bb8b6  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bb8bd  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bb8c4  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bb8c7  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bb8ca  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bb8ce  c70024b74b00           -mov dword ptr [eax], 0x4bb724
    app->getMemory<x86::reg32>(cpu.eax) = 4962084 /*0x4bb724*/;
    // 004bb8d4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bb8d8  c70020b74b00           -mov dword ptr [eax], 0x4bb720
    app->getMemory<x86::reg32>(cpu.eax) = 4962080 /*0x4bb720*/;
    // 004bb8de  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 004bb8e3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bb8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb8f0);
    // 004bb8f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb8f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb8f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bb8f3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb8f6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bb8f8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004bb8fb  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004bb8fd  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004bb8ff  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bb901  39d8                   +cmp eax, ebx
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
    // 004bb903  7d02                   -jge 0x4bb907
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb907;
    }
    // 004bb905  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004bb907:
    // 004bb907  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb909  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bb90b  7e13                   -jle 0x4bb920
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb920;
    }
    // 004bb90d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004bb910:
    // 004bb910  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004bb912  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb915  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb918  40                     -inc eax
    (cpu.eax)++;
    // 004bb919  d95afc                 -fstp dword ptr [edx - 4]
    app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bb91c  39f0                   +cmp eax, esi
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
    // 004bb91e  7cf0                   -jl 0x4bb910
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb910;
    }
L_0x004bb920:
    // 004bb920  39f8                   +cmp eax, edi
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
    // 004bb922  7d1c                   -jge 0x4bb940
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb940;
    }
    // 004bb924  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004bb927  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004bb92e  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bb930:
    // 004bb930  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004bb932  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb935  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb938  40                     -inc eax
    (cpu.eax)++;
    // 004bb939  d95bfc                 -fstp dword ptr [ebx - 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bb93c  39f8                   +cmp eax, edi
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
    // 004bb93e  7cf0                   -jl 0x4bb930
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bb930;
    }
L_0x004bb940:
    // 004bb940  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bb942  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
    // 004bb945  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb948  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb949  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb94a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb94b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb94c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb94c);
    // 004bb94c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb94d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb94e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb94f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bb950  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004bb953  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bb955  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bb957  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bb959  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bb95c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb95e  7e55                   -jle 0x4bb9b5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb9b5;
    }
    // 004bb960  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004bb963  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004bb967  8d682c                 -lea ebp, [eax + 0x2c]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
L_0x004bb96a:
    // 004bb96a  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bb96d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bb96f  7560                   -jne 0x4bb9d1
    if (!cpu.flags.zf)
    {
        goto L_0x004bb9d1;
    }
    // 004bb971  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bb974  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bb977  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004bb97a  39d8                   +cmp eax, ebx
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
    // 004bb97c  7d6e                   -jge 0x4bb9ec
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bb9ec;
    }
    // 004bb97e  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bb982  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bb987  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bb989  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb98c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bb98e  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bb991  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bb997  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb999  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb99a  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bb99d  e83e4c0000             -call 0x4c05e0
    cpu.esp -= 4;
    sub_4c05e0(app, cpu);
    if (cpu.terminate) return;
    // 004bb9a2  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bb9a5  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bb9a8  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bb9ab  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb9ae  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x004bb9b1:
    // 004bb9b1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb9b3  7fb5                   -jg 0x4bb96a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bb96a;
    }
L_0x004bb9b5:
    // 004bb9b5  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004bb9bc  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb9bf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bb9c1  0f8c24010000           -jl 0x4bbaeb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bbaeb;
    }
    // 004bb9c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb9c9  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004bb9cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb9cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb9ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb9cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb9d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bb9d1:
    // 004bb9d1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bb9d3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bb9d5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bb9d7  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004bb9db  e810ffffff             -call 0x4bb8f0
    cpu.esp -= 4;
    sub_4bb8f0(app, cpu);
    if (cpu.terminate) return;
    // 004bb9e0  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bb9e3  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb9e5  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bb9e7  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004bb9ea  ebc5                   -jmp 0x4bb9b1
    goto L_0x004bb9b1;
L_0x004bb9ec:
    // 004bb9ec  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bb9ef  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 004bb9f3  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bb9f7  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bb9fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bb9fe  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bba01  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bba03  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bba09  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bba0c  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004bba0f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bba11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bba12  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bba15  e8c64b0000             -call 0x4c05e0
    cpu.esp -= 4;
    sub_4c05e0(app, cpu);
    if (cpu.terminate) return;
    // 004bba1a  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bba1d  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bba20  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bba23  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bba25  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bba28  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004bba2d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bba2f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bba31  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bba34  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004bba37  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004bba3a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bba3c  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bba41  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bba44  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bba46  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004bba49  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004bba4c  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bba4f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bba51  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bba54  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bba56  d98608010000           -fld dword ptr [esi + 0x108]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(264) /* 0x108 */)));
    // 004bba5c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bba5f  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bba62  8b860c010000           -mov eax, dword ptr [esi + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 004bba68  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004bba6b  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004bba6e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bba70  746d                   -je 0x4bbadf
    if (cpu.flags.zf)
    {
        goto L_0x004bbadf;
    }
    // 004bba72  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bba75  6bd00f                 -imul edx, eax, 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bba78  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bba7a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bba7d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bba7f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bba82  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004bba84  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bba86  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bba88  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bba8b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bba8c  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bba8f  e84c4b0000             -call 0x4c05e0
    cpu.esp -= 4;
    sub_4c05e0(app, cpu);
    if (cpu.terminate) return;
    // 004bba94  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bba97  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bba9a  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bba9d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bba9f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbaa2  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bbaa4  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 004bbaa8  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004bbaad  8b5c2478               -mov ebx, dword ptr [esp + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004bbab1  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bbab4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bbab6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004bbab8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bbabb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bbabd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbabf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bbac1  7e1c                   -jle 0x4bbadf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbadf;
    }
    // 004bbac3  8b5c2478               -mov ebx, dword ptr [esp + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
L_0x004bbac7:
    // 004bbac7  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bbaca  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004bbacc  d95c8e2c               -fstp dword ptr [esi + ecx*4 + 0x2c]
    app->getMemory<float>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbad0  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bbad3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbad6  41                     -inc ecx
    (cpu.ecx)++;
    // 004bbad7  42                     -inc edx
    (cpu.edx)++;
    // 004bbad8  894e28                 -mov dword ptr [esi + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004bbadb  39da                   +cmp edx, ebx
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
    // 004bbadd  7ce8                   -jl 0x4bbac7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bbac7;
    }
L_0x004bbadf:
    // 004bbadf  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004bbae3  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bbae6  e9c6feffff             -jmp 0x4bb9b1
    goto L_0x004bb9b1;
L_0x004bbaeb:
    // 004bbaeb  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbaee  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bbaf1  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004bbaf3  894c862c               -mov dword ptr [esi + eax*4 + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.eax * 4) = cpu.ecx;
    // 004bbaf7  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbafa  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bbafd  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbb00  43                     -inc ebx
    (cpu.ebx)++;
    // 004bbb01  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004bbb04  47                     -inc edi
    (cpu.edi)++;
    // 004bbb05  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004bbb08  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bbb0a  7cdf                   -jl 0x4bbaeb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bbaeb;
    }
    // 004bbb0c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbb0e  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004bbb11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bbb18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbb18);
    // 004bbb18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbb19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbb1a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbb1b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbb1c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bbb1f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bbb21  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bbb25  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bbb27  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bbb29  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bbb2c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bbb2e  3b4128                 +cmp eax, dword ptr [ecx + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bbb31  7f62                   -jg 0x4bbb95
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bbb95;
    }
    // 004bbb33  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bbb37  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbb39  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bbb3b  7e1f                   -jle 0x4bbb5c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbb5c;
    }
    // 004bbb3d  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bbb41  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004bbb43:
    // 004bbb43  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbb46  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 004bbb49  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 004bbb4b  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbb4e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbb51  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbb54  40                     -inc eax
    (cpu.eax)++;
    // 004bbb55  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004bbb58  39f8                   +cmp eax, edi
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
    // 004bbb5a  7ce7                   -jl 0x4bbb43
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bbb43;
    }
L_0x004bbb5c:
    // 004bbb5c  8b6e28                 -mov ebp, dword ptr [esi + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bbb5f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bbb61  39e8                   +cmp eax, ebp
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
    // 004bbb63  7d23                   -jge 0x4bbb88
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bbb88;
    }
    // 004bbb65  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004bbb6c  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004bbb6e  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004bbb70:
    // 004bbb70  d9422c                 -fld dword ptr [edx + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(44) /* 0x2c */)));
    // 004bbb73  43                     -inc ebx
    (cpu.ebx)++;
    // 004bbb74  40                     -inc eax
    (cpu.eax)++;
    // 004bbb75  d9592c                 -fstp dword ptr [ecx + 0x2c]
    app->getMemory<float>(cpu.ecx + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbb78  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbb7b  8b7e28                 -mov edi, dword ptr [esi + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bbb7e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbb81  39f8                   +cmp eax, edi
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
    // 004bbb83  7ceb                   -jl 0x4bbb70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bbb70;
    }
    // 004bbb85  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bbb88:
    // 004bbb88  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbb8a  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004bbb8d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bbb90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb93  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bbb95:
    // 004bbb95  8b5928                 -mov ebx, dword ptr [ecx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004bbb98  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbb9a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bbb9c  7e1e                   -jle 0x4bbbbc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbbbc;
    }
    // 004bbb9e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004bbba0:
    // 004bbba0  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbba3  d9402c                 -fld dword ptr [eax + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */)));
    // 004bbba6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbba9  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbbab  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbbae  42                     -inc edx
    (cpu.edx)++;
    // 004bbbaf  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbbb2  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bbbb5  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004bbbb8  39ca                   +cmp edx, ecx
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
    // 004bbbba  7ce4                   -jl 0x4bbba0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bbba0;
    }
L_0x004bbbbc:
    // 004bbbbc  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bbbc0  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bbbc3  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bbbc6  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbbc8  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bbbcb  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bbbcd  83e81c                 -sub eax, 0x1c
    (cpu.eax) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bbbd0  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004bbbd4  39d8                   +cmp eax, ebx
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
    // 004bbbd6  0f8ec7000000           -jle 0x4bbca3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbca3;
    }
    // 004bbbdc  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
L_0x004bbbdf:
    // 004bbbdf  833c2400               +cmp dword ptr [esp], 0
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
    // 004bbbe3  0f8cc2000000           -jl 0x4bbcab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bbcab;
    }
L_0x004bbbe9:
    // 004bbbe9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bbbec  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bbbef  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004bbbf1  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004bbbf8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bbbfa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bbbfc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bbbff  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbc01  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bbc03  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bbc08  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bbc0b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bbc0d  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bbc10  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bbc12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbc13  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bbc16  e8c5490000             -call 0x4c05e0
    cpu.esp -= 4;
    sub_4c05e0(app, cpu);
    if (cpu.terminate) return;
    // 004bbc1b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbc1e  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bbc21  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bbc24  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bbc26  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bbc28  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bbc2a  894e1c                 -mov dword ptr [esi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004bbc2d  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbc2f  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004bbc32  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004bbc34  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbc36  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 004bbc3d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bbc3f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bbc41  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bbc43  90                     -nop 
    ;
L_0x004bbc44:
    // 004bbc44  7c6f                   -jl 0x4bbcb5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bbcb5;
    }
    // 004bbc46  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bbc49  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bbc4d  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbc50  894e28                 -mov dword ptr [esi + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004bbc53  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbc55  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbc57  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bbc5a  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bbc5d  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004bbc61  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbc63  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004bbc66  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bbc69  7d2e                   -jge 0x4bbc99
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bbc99;
    }
    // 004bbc6b  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004bbc6e  8b8610010000           -mov eax, dword ptr [esi + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 004bbc74  d99e08010000           -fstp dword ptr [esi + 0x108]
    app->getMemory<float>(cpu.esi + x86::reg32(264) /* 0x108 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbc7a  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004bbc7d  89960c010000           -mov dword ptr [esi + 0x10c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.edx;
    // 004bbc83  c7004cb94b00           -mov dword ptr [eax], 0x4bb94c
    app->getMemory<x86::reg32>(cpu.eax) = 4962636 /*0x4bb94c*/;
    // 004bbc89  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bbc8b  7e0c                   -jle 0x4bbc99
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbc99;
    }
    // 004bbc8d  8d5e10                 -lea ebx, [esi + 0x10]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbc90  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bbc92  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bbc94  e8b3fcffff             -call 0x4bb94c
    cpu.esp -= 4;
    sub_4bb94c(app, cpu);
    if (cpu.terminate) return;
L_0x004bbc99:
    // 004bbc99  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbc9b  83c40c                 +add esp, 0xc
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
    // 004bbc9e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbc9f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbca0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbca1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbca2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bbca3:
    // 004bbca3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004bbca6  e934ffffff             -jmp 0x4bbbdf
    goto L_0x004bbbdf;
L_0x004bbcab:
    // 004bbcab  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004bbcad  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004bbcb0  e934ffffff             -jmp 0x4bbbe9
    goto L_0x004bbbe9;
L_0x004bbcb5:
    // 004bbcb5  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbcb8  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bbcba  43                     -inc ebx
    (cpu.ebx)++;
    // 004bbcbb  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004bbcbf  41                     -inc ecx
    (cpu.ecx)++;
    // 004bbcc0  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bbcc4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbcc7  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004bbcca  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004bbccd  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbcd0  d95f2c                 -fstp dword ptr [edi + 0x2c]
    app->getMemory<float>(cpu.edi + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbcd3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbcd5  e96affffff             -jmp 0x4bbc44
    goto L_0x004bbc44;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bbcdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbcdc);
    // 004bbcdc  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bbce3  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004bbcea  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bbcf1  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bbcf8  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bbcfb  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bbcfe  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004bbd01  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bbd05  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004bbd08  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bbd0c  899010010000           -mov dword ptr [eax + 0x110], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(272) /* 0x110 */) = cpu.edx;
    // 004bbd12  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bbd16  c70218bb4b00           -mov dword ptr [edx], 0x4bbb18
    app->getMemory<x86::reg32>(cpu.edx) = 4963096 /*0x4bbb18*/;
    // 004bbd1c  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bbd22  b814010000             -mov eax, 0x114
    cpu.eax = 276 /*0x114*/;
    // 004bbd27  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bbd30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbd30);
    // 004bbd30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbd31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbd32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbd33  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bbd36  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bbd38  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004bbd3b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bbd3d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bbd3f  0f84b4000000           -je 0x4bbdf9
    if (cpu.flags.zf)
    {
        goto L_0x004bbdf9;
    }
    // 004bbd45  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbd46  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bbd48  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bbd4b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bbd4d  0f8e8a000000           -jle 0x4bbddd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbddd;
    }
    // 004bbd53  8d6810                 -lea ebp, [eax + 0x10]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004bbd56  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004bbd59  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bbd5d  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004bbd60  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bbd63  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bbd67  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004bbd6b:
    // 004bbd6b  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bbd6e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bbd70  0f858f000000           -jne 0x4bbe05
    if (!cpu.flags.zf)
    {
        goto L_0x004bbe05;
    }
    // 004bbd76  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bbd79  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bbd7c  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004bbd7f  39d0                   +cmp eax, edx
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
    // 004bbd81  0f8d99000000           -jge 0x4bbe20
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bbe20;
    }
    // 004bbd87  2b561c                 -sub edx, dword ptr [esi + 0x1c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 004bbd8a  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bbd8f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bbd91  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bbd94  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bbd96  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bbd98  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004bbd9b  39df                   +cmp edi, ebx
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
    // 004bbd9d  7d0d                   -jge 0x4bbdac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bbdac;
    }
    // 004bbd9f  8d571b                 -lea edx, [edi + 0x1b]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(27) /* 0x1b */);
    // 004bbda2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bbda4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bbda7  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bbda9  6bd81c                 -imul ebx, eax, 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
L_0x004bbdac:
    // 004bbdac  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bbdb0  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bbdb5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bbdb7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bbdba  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bbdbc  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bbdbf  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 004bbdc1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bbdc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbdc4  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bbdc7  e814480000             -call 0x4c05e0
    cpu.esp -= 4;
    sub_4c05e0(app, cpu);
    if (cpu.terminate) return;
    // 004bbdcc  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bbdcf  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bbdd1  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bbdd3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbdd6  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
L_0x004bbdd9:
    // 004bbdd9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bbddb  7f8e                   -jg 0x4bbd6b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bbd6b;
    }
L_0x004bbddd:
    // 004bbddd  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004bbde4  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bbde7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bbde9  0f8cd7000000           -jl 0x4bbec6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bbec6;
    }
    // 004bbdef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbdf1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbdf2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bbdf5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbdf6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbdf7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbdf8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bbdf9:
    // 004bbdf9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bbdfe  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bbe01  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe02  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe03  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bbe05:
    // 004bbe05  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bbe09  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bbe0b  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004bbe0d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bbe0f  e8dcfaffff             -call 0x4bb8f0
    cpu.esp -= 4;
    sub_4bb8f0(app, cpu);
    if (cpu.terminate) return;
    // 004bbe14  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bbe17  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbe19  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bbe1b  894e20                 -mov dword ptr [esi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004bbe1e  ebb9                   -jmp 0x4bbdd9
    goto L_0x004bbdd9;
L_0x004bbe20:
    // 004bbe20  837e1401               +cmp dword ptr [esi + 0x14], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bbe24  744e                   -je 0x4bbe74
    if (cpu.flags.zf)
    {
        goto L_0x004bbe74;
    }
    // 004bbe26  3b561c                 +cmp edx, dword ptr [esi + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bbe29  7e49                   -jle 0x4bbe74
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbe74;
    }
    // 004bbe2b  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bbe2f  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bbe34  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bbe36  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bbe39  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bbe3b  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bbe3e  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bbe44  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bbe46  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbe47  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bbe4a  e891470000             -call 0x4c05e0
    cpu.esp -= 4;
    sub_4c05e0(app, cpu);
    if (cpu.terminate) return;
    // 004bbe4f  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bbe52  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004bbe57  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bbe5a  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bbe5d  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bbe60  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bbe62  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbe65  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbe67  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004bbe6a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbe6d  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbe6f  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbe71  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
L_0x004bbe74:
    // 004bbe74  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bbe78  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bbe7c  ff1528ad4d00           -call dword ptr [0x4dad28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090600) /* 0x4dad28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bbe82  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bbe85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbe87  751d                   -jne 0x4bbea6
    if (!cpu.flags.zf)
    {
        goto L_0x004bbea6;
    }
L_0x004bbe89:
    // 004bbe89  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bbe8b  0f8e48ffffff           -jle 0x4bbdd9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbdd9;
    }
    // 004bbe91  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbe94  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bbe9a  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbe9d  83c004                 +add eax, 4
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
    // 004bbea0  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bbea1  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bbea4  ebe3                   -jmp 0x4bbe89
    goto L_0x004bbe89;
L_0x004bbea6:
    // 004bbea6  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax))));
    // 004bbea8  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bbeab  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbeae  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 004bbeb1  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bbeb8  83c208                 +add edx, 8
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
    // 004bbebb  d95e08                 +fstp dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbebe  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bbec1  e913ffffff             -jmp 0x4bbdd9
    goto L_0x004bbdd9;
L_0x004bbec6:
    // 004bbec6  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbec9  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bbecc  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004bbece  894c8624               -mov dword ptr [esi + eax*4 + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.eax * 4) = cpu.ecx;
    // 004bbed2  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bbed5  8b6e20                 -mov ebp, dword ptr [esi + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bbed8  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbedb  45                     -inc ebp
    (cpu.ebp)++;
    // 004bbedc  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004bbedf  47                     -inc edi
    (cpu.edi)++;
    // 004bbee0  896e20                 -mov dword ptr [esi + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004bbee3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bbee5  7cdf                   -jl 0x4bbec6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bbec6;
    }
    // 004bbee7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbee9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbeea  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bbeed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbeee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbeef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbef0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bbef4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbef4);
    // 004bbef4  c7401401000000         -mov dword ptr [eax + 0x14], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004bbefb  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bbf02  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004bbf09  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bbf10  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bbf17  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bbf1a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bbf1e  c70030bd4b00           -mov dword ptr [eax], 0x4bbd30
    app->getMemory<x86::reg32>(cpu.eax) = 4963632 /*0x4bbd30*/;
    // 004bbf24  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bbf28  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bbf2e  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 004bbf33  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bbf40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbf40);
    // 004bbf40  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004bbf43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbf44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbf44);
    // 004bbf44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbf45  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbf46  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbf47  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbf48  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bbf4a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bbf4c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bbf4e  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004bbf51  8b7920                 -mov edi, dword ptr [ecx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004bbf54  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bbf56  39fa                   +cmp edx, edi
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
    // 004bbf58  0f8d68000000           -jge 0x4bbfc6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bbfc6;
    }
    // 004bbf5e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004bbf60  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004bbf63  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004bbf66  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004bbf68  39c6                   +cmp esi, eax
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
    // 004bbf6a  7f64                   -jg 0x4bbfd0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bbfd0;
    }
    // 004bbf6c  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bbf6e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbf70  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bbf72  7e1c                   -jle 0x4bbf90
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbf90;
    }
    // 004bbf74  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004bbf76:
    // 004bbf76  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bbf79  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004bbf7c  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 004bbf7e  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bbf81  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbf84  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbf87  42                     -inc edx
    (cpu.edx)++;
    // 004bbf88  894b18                 -mov dword ptr [ebx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004bbf8b  39f2                   +cmp edx, esi
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
    // 004bbf8d  7ce7                   -jl 0x4bbf76
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bbf76;
    }
    // 004bbf8f  90                     -nop 
    ;
L_0x004bbf90:
    // 004bbf90  8b7328                 -mov esi, dword ptr [ebx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004bbf93  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bbf95  39f2                   +cmp edx, esi
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
    // 004bbf97  7d23                   -jge 0x4bbfbc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bbfbc;
    }
    // 004bbf99  8d349500000000         -lea esi, [edx*4]
    cpu.esi = x86::reg32(cpu.edx * 4);
    // 004bbfa0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bbfa2  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bbfa4:
    // 004bbfa4  d9462c                 -fld dword ptr [esi + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(44) /* 0x2c */)));
    // 004bbfa7  41                     -inc ecx
    (cpu.ecx)++;
    // 004bbfa8  42                     -inc edx
    (cpu.edx)++;
    // 004bbfa9  d9582c                 -fstp dword ptr [eax + 0x2c]
    app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbfac  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbfaf  8b7b28                 -mov edi, dword ptr [ebx + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004bbfb2  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbfb5  39fa                   +cmp edx, edi
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
    // 004bbfb7  7ceb                   -jl 0x4bbfa4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bbfa4;
    }
    // 004bbfb9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bbfbc:
    // 004bbfbc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbfbe  894b28                 -mov dword ptr [ebx + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004bbfc1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbfc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbfc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbfc4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbfc5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bbfc6:
    // 004bbfc6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bbfcb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbfcc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbfcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbfce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbfcf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bbfd0:
    // 004bbfd0  8b6928                 -mov ebp, dword ptr [ecx + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004bbfd3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbfd5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bbfd7  7e1f                   -jle 0x4bbff8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbff8;
    }
    // 004bbfd9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004bbfdb:
    // 004bbfdb  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bbfde  d9422c                 -fld dword ptr [edx + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(44) /* 0x2c */)));
    // 004bbfe1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbfe4  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbfe6  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bbfe9  40                     -inc eax
    (cpu.eax)++;
    // 004bbfea  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbfed  8b7b28                 -mov edi, dword ptr [ebx + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004bbff0  894b18                 -mov dword ptr [ebx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004bbff3  39f8                   +cmp eax, edi
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
    // 004bbff5  7ce4                   -jl 0x4bbfdb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bbfdb;
    }
    // 004bbff7  90                     -nop 
    ;
L_0x004bbff8:
    // 004bbff8  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004bbffb  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004bbffd  8b6b20                 -mov ebp, dword ptr [ebx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004bc000  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc002  2b6b24                 -sub ebp, dword ptr [ebx + 0x24]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */)));
    // 004bc005  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bc007  0f8c7a000000           -jl 0x4bc087
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc087;
    }
L_0x004bc00d:
    // 004bc00d  39ee                   +cmp esi, ebp
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
    // 004bc00f  0f8d76000000           -jge 0x4bc08b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc08b;
    }
    // 004bc015  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x004bc017:
    // 004bc017  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004bc01a  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc01c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bc01e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004bc021  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc023  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bc025  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bc02a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc02d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc02f  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004bc032  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004bc034  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc036  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc037  895314                 -mov dword ptr [ebx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bc03a  e889460000             -call 0x4c06c8
    cpu.esp -= 4;
    sub_4c06c8(app, cpu);
    if (cpu.terminate) return;
    // 004bc03f  8b5324                 -mov edx, dword ptr [ebx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004bc042  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bc044  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bc046  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bc048  895324                 -mov dword ptr [ebx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004bc04b  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc04d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc050  894b24                 -mov dword ptr [ebx + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004bc053  39fd                   +cmp ebp, edi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc055  7538                   -jne 0x4bc08f
    if (!cpu.flags.zf)
    {
        goto L_0x004bc08f;
    }
    // 004bc057  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bc059  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bc05b  2b4320                 -sub eax, dword ptr [ebx + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
    // 004bc05e  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc060  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bc062  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bc064  7e1a                   -jle 0x4bc080
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc080;
    }
L_0x004bc066:
    // 004bc066  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bc069  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bc06f  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bc072  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc075  4e                     -dec esi
    (cpu.esi)--;
    // 004bc076  896b18                 -mov dword ptr [ebx + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004bc079  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bc07b  7fe9                   -jg 0x4bc066
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc066;
    }
    // 004bc07d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bc080:
    // 004bc080  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc082  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc083  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc084  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc085  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc086  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc087:
    // 004bc087  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004bc089  eb82                   -jmp 0x4bc00d
    goto L_0x004bc00d;
L_0x004bc08b:
    // 004bc08b  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004bc08d  eb88                   -jmp 0x4bc017
    goto L_0x004bc017;
L_0x004bc08f:
    // 004bc08f  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bc094  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004bc096  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bc098  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc09b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc09d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004bc09f  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc0a1  6bf6ff                 -imul esi, esi, -1
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004bc0a4  83fee4                 +cmp esi, -0x1c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-28 /*-0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc0a7  7502                   -jne 0x4bc0ab
    if (!cpu.flags.zf)
    {
        goto L_0x004bc0ab;
    }
    // 004bc0a9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004bc0ab:
    // 004bc0ab  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bc0ad  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc0af  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bc0b1  7c0a                   -jl 0x4bc0bd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc0bd;
    }
    // 004bc0b3  894b28                 -mov dword ptr [ebx + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004bc0b6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc0b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc0bd:
    // 004bc0bd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bc0bf  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
L_0x004bc0c6:
    // 004bc0c6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc0c9  46                     -inc esi
    (cpu.esi)++;
    // 004bc0ca  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bc0cd  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc0d0  41                     -inc ecx
    (cpu.ecx)++;
    // 004bc0d1  8b6c3afc               -mov ebp, dword ptr [edx + edi - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 004bc0d5  896828                 -mov dword ptr [eax + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 004bc0d8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bc0da  7cea                   -jl 0x4bc0c6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc0c6;
    }
    // 004bc0dc  894b28                 -mov dword ptr [ebx + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004bc0df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc0e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bc0e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc0e8);
    // 004bc0e8  c7402400000000         -mov dword ptr [eax + 0x24], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004bc0ef  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004bc0f6  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bc0fd  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bc104  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004bc10b  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004bc112  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bc115  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004bc118  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc11c  c70044bf4b00           -mov dword ptr [eax], 0x4bbf44
    app->getMemory<x86::reg32>(cpu.eax) = 4964164 /*0x4bbf44*/;
    // 004bc122  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc126  c70040bf4b00           -mov dword ptr [eax], 0x4bbf40
    app->getMemory<x86::reg32>(cpu.eax) = 4964160 /*0x4bbf40*/;
    // 004bc12c  b804010000             -mov eax, 0x104
    cpu.eax = 260 /*0x104*/;
    // 004bc131  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc140);
    // 004bc140  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc141  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc142  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc143  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc146  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bc148  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004bc14b  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004bc14d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004bc14f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bc151  39d8                   +cmp eax, ebx
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
    // 004bc153  7d02                   -jge 0x4bc157
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc157;
    }
    // 004bc155  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004bc157:
    // 004bc157  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc159  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc15b  7e1f                   -jle 0x4bc17c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc17c;
    }
    // 004bc15d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004bc160:
    // 004bc160  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004bc162  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc165  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc168  40                     -inc eax
    (cpu.eax)++;
    // 004bc169  d95afc                 -fstp dword ptr [edx - 4]
    app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc16c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc16f  8b59fc                 -mov ebx, dword ptr [ecx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004bc172  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004bc175  39f8                   +cmp eax, edi
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
    // 004bc177  7ce7                   -jl 0x4bc160
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc160;
    }
    // 004bc179  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bc17c:
    // 004bc17c  39f0                   +cmp eax, esi
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
    // 004bc17e  7d24                   -jge 0x4bc1a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc1a4;
    }
    // 004bc180  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004bc183  8d1cc500000000         -lea ebx, [eax*8]
    cpu.ebx = x86::reg32(cpu.eax * 8);
    // 004bc18a  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004bc18c:
    // 004bc18c  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004bc18e  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc191  40                     -inc eax
    (cpu.eax)++;
    // 004bc192  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc194  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc197  d943fc                 -fld dword ptr [ebx - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */)));
    // 004bc19a  d959fc                 -fstp dword ptr [ecx - 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc19d  39f0                   +cmp eax, esi
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
    // 004bc19f  7ceb                   -jl 0x4bc18c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc18c;
    }
    // 004bc1a1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bc1a4:
    // 004bc1a4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bc1a6  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
    // 004bc1a9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc1ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc1ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc1ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc1af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bc1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc1b0);
    // 004bc1b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc1b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc1b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc1b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc1b4  81ecec000000           -sub esp, 0xec
    (cpu.esp) -= x86::reg32(x86::sreg32(236 /*0xec*/));
    // 004bc1ba  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bc1bc  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bc1be  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bc1c0  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004bc1c3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc1c5  7e5c                   -jle 0x4bc223
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc223;
    }
    // 004bc1c7  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004bc1ca  899424e4000000         -mov dword ptr [esp + 0xe4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */) = cpu.edx;
    // 004bc1d1  8d6834                 -lea ebp, [eax + 0x34]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(52) /* 0x34 */);
L_0x004bc1d4:
    // 004bc1d4  66837e3000             +cmp word ptr [esi + 0x30], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bc1d9  756a                   -jne 0x4bc245
    if (!cpu.flags.zf)
    {
        goto L_0x004bc245;
    }
    // 004bc1db  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc1de  8b4e2c                 -mov ecx, dword ptr [esi + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004bc1e1  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004bc1e4  39c8                   +cmp eax, ecx
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
    // 004bc1e6  0f8d7d000000           -jge 0x4bc269
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc269;
    }
    // 004bc1ec  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bc1f0  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bc1f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc1f7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc1fa  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc1fc  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bc1ff  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bc205  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc207  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc208  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bc20b  e8b8440000             -call 0x4c06c8
    cpu.esp -= 4;
    sub_4c06c8(app, cpu);
    if (cpu.terminate) return;
    // 004bc210  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc213  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bc216  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bc219  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc21c  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004bc21f:
    // 004bc21f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc221  7fb1                   -jg 0x4bc1d4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc1d4;
    }
L_0x004bc223:
    // 004bc223  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004bc22a  014618                 -add dword ptr [esi + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc22d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bc230:
    // 004bc230  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc232  0f8c6c010000           -jl 0x4bc3a4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc3a4;
    }
    // 004bc238  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc23a  81c4ec000000           -add esp, 0xec
    (cpu.esp) += x86::reg32(x86::sreg32(236 /*0xec*/));
    // 004bc240  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc241  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc242  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc243  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc244  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc245:
    // 004bc245  8b8c24e4000000         -mov ecx, dword ptr [esp + 0xe4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 004bc24c  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bc24e  8b462e                 -mov eax, dword ptr [esi + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004bc251  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bc253  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004bc256  e8e5feffff             -call 0x4bc140
    cpu.esp -= 4;
    sub_4bc140(app, cpu);
    if (cpu.terminate) return;
    // 004bc25b  668b5e30               -mov bx, word ptr [esi + 0x30]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004bc25f  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc261  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc263  66895e30               -mov word ptr [esi + 0x30], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 004bc267  ebb6                   -jmp 0x4bc21f
    goto L_0x004bc21f;
L_0x004bc269:
    // 004bc269  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bc26d  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc270  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bc275  898424e0000000         -mov dword ptr [esp + 0xe0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */) = cpu.eax;
    // 004bc27c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc27e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc281  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc283  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bc289  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bc28c  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004bc28f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc291  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc292  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bc295  e82e440000             -call 0x4c06c8
    cpu.esp -= 4;
    sub_4c06c8(app, cpu);
    if (cpu.terminate) return;
    // 004bc29a  8346241c               -add dword ptr [esi + 0x24], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bc29e  668b5e2c               -mov bx, word ptr [esi + 0x2c]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004bc2a2  668b4624               -mov ax, word ptr [esi + 0x24]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc2a6  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004bc2ab  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc2ad  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc2af  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bc2b1  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bc2b4  66895630               -mov word ptr [esi + 0x30], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.dx;
    // 004bc2b8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bc2ba  41                     -inc ecx
    (cpu.ecx)++;
    // 004bc2bb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc2be  66894e30               -mov word ptr [esi + 0x30], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.cx;
    // 004bc2c2  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bc2c7  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc2c9  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004bc2cc  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004bc2cf  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bc2d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bc2d4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc2d7  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc2d9  d986ec010000           -fld dword ptr [esi + 0x1ec]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(492) /* 0x1ec */)));
    // 004bc2df  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc2e2  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc2e5  8b86f0010000           -mov eax, dword ptr [esi + 0x1f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(496) /* 0x1f0 */);
    // 004bc2eb  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004bc2ee  8b86f4010000           -mov eax, dword ptr [esi + 0x1f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(500) /* 0x1f4 */);
    // 004bc2f4  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004bc2f7  8b86f8010000           -mov eax, dword ptr [esi + 0x1f8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(504) /* 0x1f8 */);
    // 004bc2fd  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bc300  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bc302  0f848d000000           -je 0x4bc395
    if (cpu.flags.zf)
    {
        goto L_0x004bc395;
    }
    // 004bc308  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004bc30a  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bc30e  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bc313  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc315  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc318  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc31a  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bc31d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc31f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bc321  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bc324  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc325  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004bc328  e89b430000             -call 0x4c06c8
    cpu.esp -= 4;
    sub_4c06c8(app, cpu);
    if (cpu.terminate) return;
    // 004bc32d  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc330  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bc333  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bc336  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bc338  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc33b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc33d  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 004bc342  898424e8000000         -mov dword ptr [esp + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 004bc349  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc34b  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004bc34e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc350  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bc352  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004bc355  8b8c24e8000000         -mov ecx, dword ptr [esp + 0xe8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 004bc35c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bc35e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc360  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bc362  7e31                   -jle 0x4bc395
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc395;
    }
L_0x004bc364:
    // 004bc364  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004bc367  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bc36a  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004bc36c  895cce34               -mov dword ptr [esi + ecx*8 + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */ + cpu.ecx * 8) = cpu.ebx;
    // 004bc370  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004bc373  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc376  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bc379  8b58fc                 -mov ebx, dword ptr [eax - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004bc37c  895cce38               -mov dword ptr [esi + ecx*8 + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */ + cpu.ecx * 8) = cpu.ebx;
    // 004bc380  668b5e30               -mov bx, word ptr [esi + 0x30]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004bc384  42                     -inc edx
    (cpu.edx)++;
    // 004bc385  43                     -inc ebx
    (cpu.ebx)++;
    // 004bc386  8b8c24e8000000         -mov ecx, dword ptr [esp + 0xe8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 004bc38d  66895e30               -mov word ptr [esi + 0x30], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 004bc391  39ca                   +cmp edx, ecx
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
    // 004bc393  7ccf                   -jl 0x4bc364
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc364;
    }
L_0x004bc395:
    // 004bc395  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 004bc39c  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004bc39f  e97bfeffff             -jmp 0x4bc21f
    goto L_0x004bc21f;
L_0x004bc3a4:
    // 004bc3a4  8b562e                 -mov edx, dword ptr [esi + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004bc3a7  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc3aa  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004bc3ad  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004bc3af  894cd634               -mov dword ptr [esi + edx*8 + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */ + cpu.edx * 8) = cpu.ecx;
    // 004bc3b3  8b462e                 -mov eax, dword ptr [esi + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004bc3b6  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc3b9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004bc3bc  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004bc3bf  894cc638               -mov dword ptr [esi + eax*8 + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */ + cpu.eax * 8) = cpu.ecx;
    // 004bc3c3  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc3c6  668b4e30               -mov cx, word ptr [esi + 0x30]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004bc3ca  83c208                 +add edx, 8
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
    // 004bc3cd  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bc3ce  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004bc3d1  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bc3d2  66894e30               -mov word ptr [esi + 0x30], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.cx;
    // 004bc3d6  e955feffff             -jmp 0x4bc230
    goto L_0x004bc230;
}

/* align: skip 0x90 */
void Application::sub_4bc3dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc3dc);
    // 004bc3dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc3dd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc3de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc3df  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc3e0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bc3e3  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004bc3e6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bc3e8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004bc3eb  8b502e                 -mov edx, dword ptr [eax + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 004bc3ee  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004bc3f1  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004bc3f4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bc3f6  39ca                   +cmp edx, ecx
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
    // 004bc3f8  7d34                   -jge 0x4bc42e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc42e;
    }
    // 004bc3fa  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 004bc3ff  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bc401:
    // 004bc401  8b562e                 -mov edx, dword ptr [esi + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004bc404  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004bc407  39d3                   +cmp ebx, edx
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
    // 004bc409  0f8d8a000000           -jge 0x4bc499
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc499;
    }
    // 004bc40f  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc412  8b4834                 -mov ecx, dword ptr [eax + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004bc415  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004bc417  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc41a  8b4838                 -mov ecx, dword ptr [eax + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004bc41d  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004bc420  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc423  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc426  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc428  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bc429  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004bc42c  ebd3                   -jmp 0x4bc401
    goto L_0x004bc401;
L_0x004bc42e:
    // 004bc42e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc430  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bc432  7e28                   -jle 0x4bc45c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc45c;
    }
    // 004bc434  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
L_0x004bc437:
    // 004bc437  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc43a  8b4834                 -mov ecx, dword ptr [eax + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004bc43d  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004bc43f  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc442  8b4838                 -mov ecx, dword ptr [eax + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004bc445  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004bc448  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc44b  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc44e  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc451  43                     -inc ebx
    (cpu.ebx)++;
    // 004bc452  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004bc455  39eb                   +cmp ebx, ebp
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
    // 004bc457  7cde                   -jl 0x4bc437
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc437;
    }
    // 004bc459  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bc45c:
    // 004bc45c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bc45e  8d14dd00000000         -lea edx, [ebx*8]
    cpu.edx = x86::reg32(cpu.ebx * 8);
    // 004bc465  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004bc467  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004bc469:
    // 004bc469  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004bc46c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bc46f  39cb                   +cmp ebx, ecx
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
    // 004bc471  7d16                   -jge 0x4bc489
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc489;
    }
    // 004bc473  d94234                 -fld dword ptr [edx + 0x34]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(52) /* 0x34 */)));
    // 004bc476  47                     -inc edi
    (cpu.edi)++;
    // 004bc477  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc47a  43                     -inc ebx
    (cpu.ebx)++;
    // 004bc47b  d95834                 -fstp dword ptr [eax + 0x34]
    app->getMemory<float>(cpu.eax + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc47e  83c008                 +add eax, 8
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
    // 004bc481  8b4a30                 -mov ecx, dword ptr [edx + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 004bc484  894830                 -mov dword ptr [eax + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 004bc487  ebe0                   -jmp 0x4bc469
    goto L_0x004bc469;
L_0x004bc489:
    // 004bc489  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc48b  66897e30               -mov word ptr [esi + 0x30], di
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.di;
    // 004bc48f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc491  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bc494  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc495  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc496  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc497  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc498  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc499:
    // 004bc499  8b7e28                 -mov edi, dword ptr [esi + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bc49c  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc49f  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004bc4a2  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc4a4  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc4a6  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bc4a9  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004bc4ac  39ef                   +cmp edi, ebp
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
    // 004bc4ae  7e02                   -jle 0x4bc4b2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc4b2;
    }
    // 004bc4b0  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x004bc4b2:
    // 004bc4b2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc4b4  0f8cc8000000           -jl 0x4bc582
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc582;
    }
L_0x004bc4ba:
    // 004bc4ba  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc4bd  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc4bf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bc4c1  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004bc4c4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc4c6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bc4c8  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bc4cd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc4d0  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc4d2  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bc4d5  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004bc4d7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc4d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc4da  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bc4dd  e8e6410000             -call 0x4c06c8
    cpu.esp -= 4;
    sub_4c06c8(app, cpu);
    if (cpu.terminate) return;
    // 004bc4e2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc4e5  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc4e8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bc4ea  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bc4ec  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc4ee  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bc4f0  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004bc4f3  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc4f5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bc4f7  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004bc4fa  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004bc4fe  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 004bc505  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc507  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bc509  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bc50b  90                     -nop 
    ;
L_0x004bc50c:
    // 004bc50c  0f8c77000000           -jl 0x4bc589
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc589;
    }
    // 004bc512  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bc515  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc518  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bc51a  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc51c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004bc51f  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc522  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bc525  66895e30               -mov word ptr [esi + 0x30], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 004bc529  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc52b  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004bc52e  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc531  7d43                   -jge 0x4bc576
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc576;
    }
    // 004bc533  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004bc536  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004bc539  8b86fc010000           -mov eax, dword ptr [esi + 0x1fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(508) /* 0x1fc */);
    // 004bc53f  d99eec010000           -fstp dword ptr [esi + 0x1ec]
    app->getMemory<float>(cpu.esi + x86::reg32(492) /* 0x1ec */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc545  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004bc548  8996f0010000           -mov dword ptr [esi + 0x1f0], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(496) /* 0x1f0 */) = cpu.edx;
    // 004bc54e  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bc551  8996f4010000           -mov dword ptr [esi + 0x1f4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(500) /* 0x1f4 */) = cpu.edx;
    // 004bc557  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bc55a  8996f8010000           -mov dword ptr [esi + 0x1f8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(504) /* 0x1f8 */) = cpu.edx;
    // 004bc560  c700b0c14b00           -mov dword ptr [eax], 0x4bc1b0
    app->getMemory<x86::reg32>(cpu.eax) = 4964784 /*0x4bc1b0*/;
    // 004bc566  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bc568  7e0c                   -jle 0x4bc576
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc576;
    }
    // 004bc56a  8d5e18                 -lea ebx, [esi + 0x18]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc56d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bc56f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bc571  e83afcffff             -call 0x4bc1b0
    cpu.esp -= 4;
    sub_4bc1b0(app, cpu);
    if (cpu.terminate) return;
L_0x004bc576:
    // 004bc576  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc578  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc57a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bc57d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc57e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc57f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc580  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc581  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc582:
    // 004bc582  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004bc584  e931ffffff             -jmp 0x4bc4ba
    goto L_0x004bc4ba;
L_0x004bc589:
    // 004bc589  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc58c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc58e  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004bc592  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc596  8d0c16                 -lea ecx, [esi + edx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004bc599  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004bc59c  d95934                 -fstp dword ptr [ecx + 0x34]
    app->getMemory<float>(cpu.ecx + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc59f  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc5a2  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc5a4  43                     -inc ebx
    (cpu.ebx)++;
    // 004bc5a5  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc5a8  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004bc5ab  d95938                 -fstp dword ptr [ecx + 0x38]
    app->getMemory<float>(cpu.ecx + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc5ae  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bc5b2  41                     -inc ecx
    (cpu.ecx)++;
    // 004bc5b3  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc5b6  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004bc5ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bc5bc  e94bffffff             -jmp 0x4bc50c
    goto L_0x004bc50c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bc5c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc5c4);
    // 004bc5c4  c7402400000000         -mov dword ptr [eax + 0x24], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004bc5cb  66c740300000           -mov word ptr [eax + 0x30], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 004bc5d1  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bc5d8  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bc5df  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004bc5e6  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004bc5ed  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bc5f0  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004bc5f3  894828                 -mov dword ptr [eax + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004bc5f6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bc5fa  89502c                 -mov dword ptr [eax + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 004bc5fd  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc601  8990fc010000           -mov dword ptr [eax + 0x1fc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(508) /* 0x1fc */) = cpu.edx;
    // 004bc607  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc60b  c702dcc34b00           -mov dword ptr [edx], 0x4bc3dc
    app->getMemory<x86::reg32>(cpu.edx) = 4965340 /*0x4bc3dc*/;
    // 004bc611  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bc617  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 004bc61c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_4bc620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc620);
    // 004bc620  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc621  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc622  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc623  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bc626  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bc628  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004bc62b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bc62d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bc62f  0f848d000000           -je 0x4bc6c2
    if (cpu.flags.zf)
    {
        goto L_0x004bc6c2;
    }
    // 004bc635  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc636  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bc638  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004bc63b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc63d  7e67                   -jle 0x4bc6a6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc6a6;
    }
    // 004bc63f  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004bc642  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bc646  8d502c                 -lea edx, [eax + 0x2c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004bc649  8d6820                 -lea ebp, [eax + 0x20]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004bc64c  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bc64f  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bc653  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004bc657:
    // 004bc657  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bc65a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bc65c  756b                   -jne 0x4bc6c9
    if (!cpu.flags.zf)
    {
        goto L_0x004bc6c9;
    }
    // 004bc65e  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc661  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bc664  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004bc667  39d0                   +cmp eax, edx
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
    // 004bc669  0f8d77000000           -jge 0x4bc6e6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc6e6;
    }
    // 004bc66f  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bc673  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004bc678  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc67a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc67d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc67f  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bc682  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bc688  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc68a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc68b  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bc68e  e835400000             -call 0x4c06c8
    cpu.esp -= 4;
    sub_4c06c8(app, cpu);
    if (cpu.terminate) return;
    // 004bc693  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc696  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bc699  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bc69c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc69f  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
L_0x004bc6a2:
    // 004bc6a2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc6a4  7fb1                   -jg 0x4bc657
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc657;
    }
L_0x004bc6a6:
    // 004bc6a6  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004bc6ad  014618                 -add dword ptr [esi + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc6b0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc6b2  0f8ce0000000           -jl 0x4bc798
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc798;
    }
    // 004bc6b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc6ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004bc6bb:
    // 004bc6bb  83c40c                 +add esp, 0xc
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
    // 004bc6be  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc6bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc6c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc6c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc6c2:
    // 004bc6c2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bc6c7  ebf2                   -jmp 0x4bc6bb
    goto L_0x004bc6bb;
L_0x004bc6c9:
    // 004bc6c9  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bc6cd  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc6d1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bc6d3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bc6d5  e866faffff             -call 0x4bc140
    cpu.esp -= 4;
    sub_4bc140(app, cpu);
    if (cpu.terminate) return;
    // 004bc6da  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bc6dd  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc6df  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc6e1  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004bc6e4  ebbc                   -jmp 0x4bc6a2
    goto L_0x004bc6a2;
L_0x004bc6e6:
    // 004bc6e6  837e1c01               +cmp dword ptr [esi + 0x1c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc6ea  7445                   -je 0x4bc731
    if (cpu.flags.zf)
    {
        goto L_0x004bc731;
    }
    // 004bc6ec  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bc6f0  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004bc6f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc6f7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc6fa  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc6fc  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bc6ff  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bc705  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc707  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc708  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bc70b  e8b83f0000             -call 0x4c06c8
    cpu.esp -= 4;
    sub_4c06c8(app, cpu);
    if (cpu.terminate) return;
    // 004bc710  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc713  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc715  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bc718  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004bc71b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc71d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bc71f  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc722  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc724  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004bc727  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc72a  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc72c  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc72e  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x004bc731:
    // 004bc731  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc735  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bc737  ff1528ad4d00           -call dword ptr [0x4dad28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090600) /* 0x4dad28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bc73d  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bc740  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bc742  742e                   -je 0x4bc772
    if (cpu.flags.zf)
    {
        goto L_0x004bc772;
    }
    // 004bc744  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bc746  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax))));
    // 004bc748  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc74b  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 004bc74e  d95e08                 -fstp dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc751  df4004                 -fild word ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 004bc754  d95e0c                 -fstp dword ptr [esi + 0xc]
    app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc757  df4006                 -fild word ptr [eax + 6]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */))));
    // 004bc75a  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bc75d  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004bc764  83c008                 +add eax, 8
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
    // 004bc767  d95e10                 +fstp dword ptr [esi + 0x10]
    app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc76a  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004bc76d  e930ffffff             -jmp 0x4bc6a2
    goto L_0x004bc6a2;
L_0x004bc772:
    // 004bc772  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bc774  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc776  0f8e26ffffff           -jle 0x4bc6a2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc6a2;
    }
L_0x004bc77c:
    // 004bc77c  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc77f  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bc785  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc788  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc78b  4f                     -dec edi
    (cpu.edi)--;
    // 004bc78c  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004bc78f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc791  7fe9                   -jg 0x4bc77c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc77c;
    }
    // 004bc793  e90affffff             -jmp 0x4bc6a2
    goto L_0x004bc6a2;
L_0x004bc798:
    // 004bc798  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc79b  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bc79e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004bc7a0  894cc62c               -mov dword ptr [esi + eax*8 + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.eax * 8) = cpu.ecx;
    // 004bc7a4  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc7a7  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bc7aa  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004bc7ad  894cd630               -mov dword ptr [esi + edx*8 + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */ + cpu.edx * 8) = cpu.ecx;
    // 004bc7b1  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc7b4  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bc7b7  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc7ba  43                     -inc ebx
    (cpu.ebx)++;
    // 004bc7bb  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004bc7be  47                     -inc edi
    (cpu.edi)++;
    // 004bc7bf  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004bc7c2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc7c4  7cd2                   -jl 0x4bc798
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc798;
    }
    // 004bc7c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc7c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7c9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bc7cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bc7d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc7d0);
    // 004bc7d0  c7401c01000000         -mov dword ptr [eax + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 004bc7d7  c7402400000000         -mov dword ptr [eax + 0x24], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004bc7de  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004bc7e5  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bc7ec  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bc7f3  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004bc7fa  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004bc801  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004bc804  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc808  c70020c64b00           -mov dword ptr [eax], 0x4bc620
    app->getMemory<x86::reg32>(cpu.eax) = 4965920 /*0x4bc620*/;
    // 004bc80e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc812  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bc818  b804010000             -mov eax, 0x104
    cpu.eax = 260 /*0x104*/;
    // 004bc81d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4bc820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc820);
    // 004bc820  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004bc826  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4bc828(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc828);
    // 004bc828  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc829  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc82a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc82b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bc82d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004bc82f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc831  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc833  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bc835  7e34                   -jle 0x4bc86b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc86b;
    }
    // 004bc837  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004bc839  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004bc83b:
    // 004bc83b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004bc83d  25ffff0100             -and eax, 0x1ffff
    cpu.eax &= x86::reg32(x86::sreg32(131071 /*0x1ffff*/));
    // 004bc842  3dff7f0000             +cmp eax, 0x7fff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc847  7613                   -jbe 0x4bc85c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004bc85c;
    }
    // 004bc849  3d00800100             +cmp eax, 0x18000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(98304 /*0x18000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bc84e  730c                   -jae 0x4bc85c
    if (!cpu.flags.cf)
    {
        goto L_0x004bc85c;
    }
    // 004bc850  3d00000100             +cmp eax, 0x10000
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
    // 004bc855  7318                   -jae 0x4bc86f
    if (!cpu.flags.cf)
    {
        goto L_0x004bc86f;
    }
    // 004bc857  b8ff7f0000             -mov eax, 0x7fff
    cpu.eax = 32767 /*0x7fff*/;
L_0x004bc85c:
    // 004bc85c  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc85f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc862  41                     -inc ecx
    (cpu.ecx)++;
    // 004bc863  668943fe               -mov word ptr [ebx - 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004bc867  39f1                   +cmp ecx, esi
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
    // 004bc869  7cd0                   -jl 0x4bc83b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc83b;
    }
L_0x004bc86b:
    // 004bc86b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc86c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc86d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc86e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc86f:
    // 004bc86f  b800800000             -mov eax, 0x8000
    cpu.eax = 32768 /*0x8000*/;
    // 004bc874  ebe6                   -jmp 0x4bc85c
    goto L_0x004bc85c;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bc878(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc878);
    // 004bc878  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc879  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc87a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc87b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bc87e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004bc880  8b884c0d0000           -mov ecx, dword ptr [eax + 0xd4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004bc886  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004bc88c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bc88e  39d1                   +cmp ecx, edx
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
    // 004bc890  0f83eb000000           -jae 0x4bc981
    if (!cpu.flags.cf)
    {
        goto L_0x004bc981;
    }
    // 004bc896  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc897  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bc899  8b984c0d0000           -mov ebx, dword ptr [eax + 0xd4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004bc89f  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004bc8a1  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004bc8a7  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004bc8a9  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc8ab  89984c0d0000           -mov dword ptr [eax + 0xd4c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 004bc8b1  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004bc8b5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bc8b7  0f8ed0000000           -jle 0x4bc98d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc98d;
    }
    // 004bc8bd  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004bc8bf:
    // 004bc8bf  8bb7480d0000           -mov esi, dword ptr [edi + 0xd48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004bc8c5  39f5                   +cmp ebp, esi
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
    // 004bc8c7  7d02                   -jge 0x4bc8cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc8cb;
    }
    // 004bc8c9  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004bc8cb:
    // 004bc8cb  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004bc8d0  8b97480d0000           -mov edx, dword ptr [edi + 0xd48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004bc8d6  8d9f84060000           -lea ebx, [edi + 0x684]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1668) /* 0x684 */);
    // 004bc8dc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc8de  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004bc8e2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bc8e5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bc8e7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc8e9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004bc8eb  e838ffffff             -call 0x4bc828
    cpu.esp -= 4;
    sub_4bc828(app, cpu);
    if (cpu.terminate) return;
    // 004bc8f0  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004bc8f3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc8f5  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004bc8fb  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bc8fd  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bc8ff  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 004bc905  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bc907  7e5f                   -jle 0x4bc968
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc968;
    }
    // 004bc909  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc90d  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004bc911:
    // 004bc911  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bc916  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bc918  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 004bc91d  e83e4b0000             -call 0x4c1460
    cpu.esp -= 4;
    sub_4c1460(app, cpu);
    if (cpu.terminate) return;
    // 004bc922  c787480d0000b0010000   -mov dword ptr [edi + 0xd48], 0x1b0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = 432 /*0x1b0*/;
    // 004bc92c  39f5                   +cmp ebp, esi
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
    // 004bc92e  7d02                   -jge 0x4bc932
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc932;
    }
    // 004bc930  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004bc932:
    // 004bc932  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004bc937  2b87480d0000           -sub eax, dword ptr [edi + 0xd48]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */)));
    // 004bc93d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc941  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bc944  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bc946  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc948  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004bc94a  e8d9feffff             -call 0x4bc828
    cpu.esp -= 4;
    sub_4bc828(app, cpu);
    if (cpu.terminate) return;
    // 004bc94f  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004bc952  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc954  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004bc95a  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bc95c  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bc95e  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 004bc964  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bc966  7fa9                   -jg 0x4bc911
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc911;
    }
L_0x004bc968:
    // 004bc968  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc96a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004bc96b:
    // 004bc96b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004bc96e  39d0                   +cmp eax, edx
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
    // 004bc970  7d26                   -jge 0x4bc998
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc998;
    }
    // 004bc972  83c102                 +add ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc975  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004bc978  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004bc97c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004bc97f  ebea                   -jmp 0x4bc96b
    goto L_0x004bc96b;
L_0x004bc981:
    // 004bc981  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bc986  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bc989  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc98a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc98b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc98c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc98d:
    // 004bc98d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bc98f  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004bc993  e927ffffff             -jmp 0x4bc8bf
    goto L_0x004bc8bf;
L_0x004bc998:
    // 004bc998  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc99a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bc99d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc99e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc99f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc9a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bc9a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc9a4);
    // 004bc9a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc9a5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bc9a7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc9a9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004bc9ab  e8c4490000             -call 0x4c1374
    cpu.esp -= 4;
    sub_4c1374(app, cpu);
    if (cpu.terminate) return;
    // 004bc9b0  c786480d000000000000   -mov dword ptr [esi + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004bc9ba  c7864c0d000000000000   -mov dword ptr [esi + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004bc9c4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc9c8  899e440d0000           -mov dword ptr [esi + 0xd44], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3396) /* 0xd44 */) = cpu.ebx;
    // 004bc9ce  c70078c84b00           -mov dword ptr [eax], 0x4bc878
    app->getMemory<x86::reg32>(cpu.eax) = 4966520 /*0x4bc878*/;
    // 004bc9d4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc9d8  c70020c84b00           -mov dword ptr [eax], 0x4bc820
    app->getMemory<x86::reg32>(cpu.eax) = 4966432 /*0x4bc820*/;
    // 004bc9de  b8500d0000             -mov eax, 0xd50
    cpu.eax = 3408 /*0xd50*/;
    // 004bc9e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc9e4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc9f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc9f0);
    // 004bc9f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc9f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc9f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc9f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc9f4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bc9f7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bc9f9  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004bc9ff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bca01  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bca03  0f84b5000000           -je 0x4bcabe
    if (cpu.flags.zf)
    {
        goto L_0x004bcabe;
    }
    // 004bca09  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bca0b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bca0d  0f8ea1000000           -jle 0x4bcab4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcab4;
    }
    // 004bca13  8d9884060000           -lea ebx, [eax + 0x684]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1668) /* 0x684 */);
    // 004bca19  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004bca1d  8d98480d0000           -lea ebx, [eax + 0xd48]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(3400) /* 0xd48 */);
    // 004bca23  05440d0000             -add eax, 0xd44
    (cpu.eax) += x86::reg32(x86::sreg32(3396 /*0xd44*/));
    // 004bca28  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004bca2c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004bca2f:
    // 004bca2f  8b814c0d0000           -mov eax, dword ptr [ecx + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */);
    // 004bca35  3b81480d0000           +cmp eax, dword ptr [ecx + 0xd48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bca3b  0f8d8a000000           -jge 0x4bcacb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcacb;
    }
L_0x004bca41:
    // 004bca41  83b9500d000000         +cmp dword ptr [ecx + 0xd50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bca48  0f8e0f010000           -jle 0x4bcb5d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcb5d;
    }
L_0x004bca4e:
    // 004bca4e  8bb1480d0000           -mov esi, dword ptr [ecx + 0xd48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */);
    // 004bca54  2bb14c0d0000           -sub esi, dword ptr [ecx + 0xd4c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */)));
    // 004bca5a  39f7                   +cmp edi, esi
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
    // 004bca5c  7d02                   -jge 0x4bca60
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bca60;
    }
    // 004bca5e  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004bca60:
    // 004bca60  8b91500d0000           -mov edx, dword ptr [ecx + 0xd50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 004bca66  39d6                   +cmp esi, edx
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
    // 004bca68  7e02                   -jle 0x4bca6c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bca6c;
    }
    // 004bca6a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x004bca6c:
    // 004bca6c  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004bca71  2b81500d0000           -sub eax, dword ptr [ecx + 0xd50]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */)));
    // 004bca77  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bca7b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bca7e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004bca80  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bca82  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bca84  e89ffdffff             -call 0x4bc828
    cpu.esp -= 4;
    sub_4bc828(app, cpu);
    if (cpu.terminate) return;
    // 004bca89  8b994c0d0000           -mov ebx, dword ptr [ecx + 0xd4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */);
    // 004bca8f  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bca91  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004bca94  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bca96  8b81500d0000           -mov eax, dword ptr [ecx + 0xd50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 004bca9c  89994c0d0000           -mov dword ptr [ecx + 0xd4c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 004bcaa2  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bcaa4  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bcaa6  8981500d0000           -mov dword ptr [ecx + 0xd50], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */) = cpu.eax;
    // 004bcaac  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bcaae  0f8f7bffffff           -jg 0x4bca2f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bca2f;
    }
L_0x004bcab4:
    // 004bcab4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcab6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bcab9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcaba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcabb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcabc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcabd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bcabe:
    // 004bcabe  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bcac3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bcac6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcac7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcac8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcac9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcaca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bcacb:
    // 004bcacb  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bcacf  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bcad2  ff1528ad4d00           -call dword ptr [0x4dad28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090600) /* 0x4dad28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bcad8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bcada  752b                   -jne 0x4bcb07
    if (!cpu.flags.zf)
    {
        goto L_0x004bcb07;
    }
    // 004bcadc  8b99440d0000           -mov ebx, dword ptr [ecx + 0xd44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */);
    // 004bcae2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bcae4  7421                   -je 0x4bcb07
    if (cpu.flags.zf)
    {
        goto L_0x004bcb07;
    }
    // 004bcae6  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004bcae8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bcaea  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004bcaec  7443                   -je 0x4bcb31
    if (cpu.flags.zf)
    {
        goto L_0x004bcb31;
    }
    // 004bcaee  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004bcaf1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bcaf3  e87c480000             -call 0x4c1374
    cpu.esp -= 4;
    sub_4c1374(app, cpu);
    if (cpu.terminate) return;
    // 004bcaf8  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004bcb02  e93affffff             -jmp 0x4bca41
    goto L_0x004bca41;
L_0x004bcb07:
    // 004bcb07  8d1c3f                 -lea ebx, [edi + edi]
    cpu.ebx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004bcb0a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004bcb0c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bcb0e  e85c0afdff             -call 0x48d56f
    cpu.esp -= 4;
    sub_48d56f(app, cpu);
    if (cpu.terminate) return;
    // 004bcb13  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004bcb1d  c781480d000000000000   -mov dword ptr [ecx + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004bcb27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcb29  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bcb2c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcb2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcb2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcb2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcb30  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bcb31:
    // 004bcb31  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004bcb34  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004bcb39  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004bcb3c  8b81440d0000           -mov eax, dword ptr [ecx + 0xd44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */);
    // 004bcb42  c7410808000000         -mov dword ptr [ecx + 8], 8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 004bcb49  83c002                 +add eax, 2
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
    // 004bcb4c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004bcb4e  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004bcb58  e9e4feffff             -jmp 0x4bca41
    goto L_0x004bca41;
L_0x004bcb5d:
    // 004bcb5d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bcb62  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bcb64  e8f7480000             -call 0x4c1460
    cpu.esp -= 4;
    sub_4c1460(app, cpu);
    if (cpu.terminate) return;
    // 004bcb69  c781500d0000b0010000   -mov dword ptr [ecx + 0xd50], 0x1b0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */) = 432 /*0x1b0*/;
    // 004bcb73  e9d6feffff             -jmp 0x4bca4e
    goto L_0x004bca4e;
}

/* align: skip  */
void Application::sub_4bcb78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcb78);
    // 004bcb78  c780440d000001000000   -mov dword ptr [eax + 0xd44], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */) = 1 /*0x1*/;
    // 004bcb82  c780480d000000000000   -mov dword ptr [eax + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004bcb8c  c7804c0d000000000000   -mov dword ptr [eax + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004bcb96  c780500d000000000000   -mov dword ptr [eax + 0xd50], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 004bcba0  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bcba4  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bcbaa  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bcbae  c700f0c94b00           -mov dword ptr [eax], 0x4bc9f0
    app->getMemory<x86::reg32>(cpu.eax) = 4966896 /*0x4bc9f0*/;
    // 004bcbb4  b8540d0000             -mov eax, 0xd54
    cpu.eax = 3412 /*0xd54*/;
    // 004bcbb9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4bcbc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcbc0);
    // 004bcbc0  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004bcbc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4bcbc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcbc8);
    // 004bcbc8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bcbc9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bcbcb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcbcd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bcbcf  7e13                   -jle 0x4bcbe4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcbe4;
    }
L_0x004bcbd1:
    // 004bcbd1  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004bcbd3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bcbd6  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bcbd9  40                     -inc eax
    (cpu.eax)++;
    // 004bcbda  d95afc                 -fstp dword ptr [edx - 4]
    app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bcbdd  39d8                   +cmp eax, ebx
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
    // 004bcbdf  7cf0                   -jl 0x4bcbd1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bcbd1;
    }
    // 004bcbe1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bcbe4:
    // 004bcbe4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcbe5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bcbe8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcbe8);
    // 004bcbe8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bcbe9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcbea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bcbeb  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bcbee  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004bcbf0  8b884c0d0000           -mov ecx, dword ptr [eax + 0xd4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004bcbf6  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004bcbfc  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bcbfe  39d1                   +cmp ecx, edx
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
    // 004bcc00  0f83f2000000           -jae 0x4bccf8
    if (!cpu.flags.cf)
    {
        goto L_0x004bccf8;
    }
    // 004bcc06  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bcc07  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bcc09  8b984c0d0000           -mov ebx, dword ptr [eax + 0xd4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004bcc0f  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004bcc11  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004bcc17  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004bcc19  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bcc1b  89984c0d0000           -mov dword ptr [eax + 0xd4c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 004bcc21  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004bcc25  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bcc27  0f8ed7000000           -jle 0x4bcd04
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcd04;
    }
    // 004bcc2d  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004bcc2f:
    // 004bcc2f  8bb7480d0000           -mov esi, dword ptr [edi + 0xd48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004bcc35  39f5                   +cmp ebp, esi
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
    // 004bcc37  7d02                   -jge 0x4bcc3b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcc3b;
    }
    // 004bcc39  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004bcc3b:
    // 004bcc3b  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004bcc40  8b97480d0000           -mov edx, dword ptr [edi + 0xd48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004bcc46  8d9f84060000           -lea ebx, [edi + 0x684]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1668) /* 0x684 */);
    // 004bcc4c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bcc4e  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004bcc52  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bcc55  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bcc57  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bcc59  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004bcc5b  e868ffffff             -call 0x4bcbc8
    cpu.esp -= 4;
    sub_4bcbc8(app, cpu);
    if (cpu.terminate) return;
    // 004bcc60  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004bcc67  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bcc69  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004bcc6f  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bcc71  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bcc73  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 004bcc79  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bcc7b  7e60                   -jle 0x4bccdd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bccdd;
    }
    // 004bcc7d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bcc81  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004bcc85:
    // 004bcc85  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bcc87  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bcc89  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 004bcc8e  e8cd470000             -call 0x4c1460
    cpu.esp -= 4;
    sub_4c1460(app, cpu);
    if (cpu.terminate) return;
    // 004bcc93  c787480d0000b0010000   -mov dword ptr [edi + 0xd48], 0x1b0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = 432 /*0x1b0*/;
    // 004bcc9d  39f5                   +cmp ebp, esi
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
    // 004bcc9f  7d02                   -jge 0x4bcca3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcca3;
    }
    // 004bcca1  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004bcca3:
    // 004bcca3  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004bcca8  2b87480d0000           -sub eax, dword ptr [edi + 0xd48]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */)));
    // 004bccae  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bccb2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bccb5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bccb7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bccb9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004bccbb  e808ffffff             -call 0x4bcbc8
    cpu.esp -= 4;
    sub_4bcbc8(app, cpu);
    if (cpu.terminate) return;
    // 004bccc0  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004bccc7  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bccc9  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004bcccf  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bccd1  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004bccd3  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 004bccd9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bccdb  7fa8                   -jg 0x4bcc85
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bcc85;
    }
L_0x004bccdd:
    // 004bccdd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004bccde:
    // 004bccde  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bcce2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bcce4  7e29                   -jle 0x4bcd0f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcd0f;
    }
    // 004bcce6  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004bcce9  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 004bccef  83c104                 +add ecx, 4
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
    // 004bccf2  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004bccf6  ebe6                   -jmp 0x4bccde
    goto L_0x004bccde;
L_0x004bccf8:
    // 004bccf8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bccfd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bcd00  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bcd04:
    // 004bcd04  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004bcd06  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004bcd0a  e920ffffff             -jmp 0x4bcc2f
    goto L_0x004bcc2f;
L_0x004bcd0f:
    // 004bcd0f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcd11  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bcd14  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd15  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bcd18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcd18);
    // 004bcd18  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bcd19  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bcd1b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bcd1d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004bcd1f  e850460000             -call 0x4c1374
    cpu.esp -= 4;
    sub_4c1374(app, cpu);
    if (cpu.terminate) return;
    // 004bcd24  c786480d000000000000   -mov dword ptr [esi + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004bcd2e  c7864c0d000000000000   -mov dword ptr [esi + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004bcd38  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bcd3c  899e440d0000           -mov dword ptr [esi + 0xd44], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3396) /* 0xd44 */) = cpu.ebx;
    // 004bcd42  c700e8cb4b00           -mov dword ptr [eax], 0x4bcbe8
    app->getMemory<x86::reg32>(cpu.eax) = 4967400 /*0x4bcbe8*/;
    // 004bcd48  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bcd4c  c700c0cb4b00           -mov dword ptr [eax], 0x4bcbc0
    app->getMemory<x86::reg32>(cpu.eax) = 4967360 /*0x4bcbc0*/;
    // 004bcd52  b8500d0000             -mov eax, 0xd50
    cpu.eax = 3408 /*0xd50*/;
    // 004bcd57  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd58  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bcd60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcd60);
    // 004bcd60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bcd61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bcd62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcd63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bcd64  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bcd67  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bcd69  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bcd6d  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004bcd73  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004bcd75  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bcd77  0f84e2000000           -je 0x4bce5f
    if (cpu.flags.zf)
    {
        goto L_0x004bce5f;
    }
    // 004bcd7d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bcd7f  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bcd83  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004bcd86  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bcd88  0f8ec7000000           -jle 0x4bce55
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bce55;
    }
    // 004bcd8e  8d8684060000           -lea eax, [esi + 0x684]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1668) /* 0x684 */);
    // 004bcd94  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004bcd98  8d86480d0000           -lea eax, [esi + 0xd48]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3400) /* 0xd48 */);
    // 004bcd9e  81c6440d0000           -add esi, 0xd44
    (cpu.esi) += x86::reg32(x86::sreg32(3396 /*0xd44*/));
    // 004bcda4  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004bcda8  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004bcdac:
    // 004bcdac  8b854c0d0000           -mov eax, dword ptr [ebp + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 004bcdb2  3b85480d0000           +cmp eax, dword ptr [ebp + 0xd48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcdb8  0f8dae000000           -jge 0x4bce6c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bce6c;
    }
L_0x004bcdbe:
    // 004bcdbe  83bd500d000000         +cmp dword ptr [ebp + 0xd50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcdc5  0f8e3a010000           -jle 0x4bcf05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcf05;
    }
L_0x004bcdcb:
    // 004bcdcb  8b95480d0000           -mov edx, dword ptr [ebp + 0xd48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */);
    // 004bcdd1  8bbd4c0d0000           -mov edi, dword ptr [ebp + 0xd4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 004bcdd7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bcddb  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bcddd  39c2                   +cmp edx, eax
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
    // 004bcddf  7e02                   -jle 0x4bcde3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcde3;
    }
    // 004bcde1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004bcde3:
    // 004bcde3  8b8d500d0000           -mov ecx, dword ptr [ebp + 0xd50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 004bcde9  39ca                   +cmp edx, ecx
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
    // 004bcdeb  7e02                   -jle 0x4bcdef
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcdef;
    }
    // 004bcded  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004bcdef:
    // 004bcdef  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 004bcdf4  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bcdf8  8bbd500d0000           -mov edi, dword ptr [ebp + 0xd50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 004bcdfe  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 004bce05  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bce07  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004bce09  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004bce0c  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004bce0f  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bce11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bce12  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bce14  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bce17  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bce19  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bce1b  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bce1e  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bce20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce21  8b8d4c0d0000           -mov ecx, dword ptr [ebp + 0xd4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 004bce27  8d341f                 -lea esi, [edi + ebx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 004bce2a  8b85500d0000           -mov eax, dword ptr [ebp + 0xd50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 004bce30  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bce34  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004bce37  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bce39  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bce3b  898d4c0d0000           -mov dword ptr [ebp + 0xd4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = cpu.ecx;
    // 004bce41  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bce43  8985500d0000           -mov dword ptr [ebp + 0xd50], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */) = cpu.eax;
    // 004bce49  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004bce4d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bce4f  0f8f57ffffff           -jg 0x4bcdac
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bcdac;
    }
L_0x004bce55:
    // 004bce55  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bce57  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bce5a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce5d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce5e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bce5f:
    // 004bce5f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bce64  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bce67  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bce6c:
    // 004bce6c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bce70  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bce74  ff1528ad4d00           -call dword ptr [0x4dad28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090600) /* 0x4dad28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bce7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bce7c  752b                   -jne 0x4bcea9
    if (!cpu.flags.zf)
    {
        goto L_0x004bcea9;
    }
    // 004bce7e  8b9d440d0000           -mov ebx, dword ptr [ebp + 0xd44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */);
    // 004bce84  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bce86  7421                   -je 0x4bcea9
    if (cpu.flags.zf)
    {
        goto L_0x004bcea9;
    }
    // 004bce88  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004bce8a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bce8c  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004bce8e  7448                   -je 0x4bced8
    if (cpu.flags.zf)
    {
        goto L_0x004bced8;
    }
    // 004bce90  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004bce93  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bce95  e8da440000             -call 0x4c1374
    cpu.esp -= 4;
    sub_4c1374(app, cpu);
    if (cpu.terminate) return;
    // 004bce9a  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004bcea4  e915ffffff             -jmp 0x4bcdbe
    goto L_0x004bcdbe;
L_0x004bcea9:
    // 004bcea9  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bcead  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bceb0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bceb2  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004bceb5  e8b506fdff             -call 0x48d56f
    cpu.esp -= 4;
    sub_48d56f(app, cpu);
    if (cpu.terminate) return;
    // 004bceba  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004bcec4  c785480d000000000000   -mov dword ptr [ebp + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004bcece  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bced0  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004bced3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bced4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bced5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bced6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bced7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bced8:
    // 004bced8  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004bcedb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004bcee0  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004bcee3  8b85440d0000           -mov eax, dword ptr [ebp + 0xd44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */);
    // 004bcee9  c7450808000000         -mov dword ptr [ebp + 8], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 004bcef0  83c002                 +add eax, 2
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
    // 004bcef3  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004bcef6  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004bcf00  e9b9feffff             -jmp 0x4bcdbe
    goto L_0x004bcdbe;
L_0x004bcf05:
    // 004bcf05  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004bcf07  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004bcf09  e852450000             -call 0x4c1460
    cpu.esp -= 4;
    sub_4c1460(app, cpu);
    if (cpu.terminate) return;
    // 004bcf0e  c785500d0000b0010000   -mov dword ptr [ebp + 0xd50], 0x1b0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */) = 432 /*0x1b0*/;
    // 004bcf18  e9aefeffff             -jmp 0x4bcdcb
    goto L_0x004bcdcb;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bcf20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcf20);
    // 004bcf20  c780440d000001000000   -mov dword ptr [eax + 0xd44], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */) = 1 /*0x1*/;
    // 004bcf2a  c780480d000000000000   -mov dword ptr [eax + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004bcf34  c7804c0d000000000000   -mov dword ptr [eax + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004bcf3e  c780500d000000000000   -mov dword ptr [eax + 0xd50], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 004bcf48  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bcf4c  c70060cd4b00           -mov dword ptr [eax], 0x4bcd60
    app->getMemory<x86::reg32>(cpu.eax) = 4967776 /*0x4bcd60*/;
    // 004bcf52  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bcf56  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bcf5c  b8540d0000             -mov eax, 0xd54
    cpu.eax = 3412 /*0xd54*/;
    // 004bcf61  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4bcf64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcf64);
    // 004bcf64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bcf65  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004bcf68  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bcf6a  e8c451feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004bcf6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bcf71  7407                   -je 0x4bcf7a
    if (cpu.flags.zf)
    {
        goto L_0x004bcf7a;
    }
    // 004bcf73  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bcf75  e8f505fdff             -call 0x48d56f
    cpu.esp -= 4;
    sub_48d56f(app, cpu);
    if (cpu.terminate) return;
L_0x004bcf7a:
    // 004bcf7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcf7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bcf7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcf7c);
    // 004bcf7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bcf7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bcf7e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bcf7f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcf81  e8e395ffff             -call 0x4b6569
    cpu.esp -= 4;
    sub_4b6569(app, cpu);
    if (cpu.terminate) return;
    // 004bcf86  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bcf88  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bcf8a  7410                   -je 0x4bcf9c
    if (cpu.flags.zf)
    {
        goto L_0x004bcf9c;
    }
    // 004bcf8c  8b1518cb4d00           -mov edx, dword ptr [0x4dcb18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */);
    // 004bcf92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bcf93  2eff1588454c00         -call dword ptr cs:[0x4c4588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998536) /* 0x4c4588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bcf9a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004bcf9c:
    // 004bcf9c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bcf9e  750f                   -jne 0x4bcfaf
    if (!cpu.flags.zf)
    {
        goto L_0x004bcfaf;
    }
    // 004bcfa0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bcfa5  b880fc4c00             -mov eax, 0x4cfc80
    cpu.eax = 5045376 /*0x4cfc80*/;
    // 004bcfaa  e8b2c8ffff             -call 0x4b9861
    cpu.esp -= 4;
    sub_4b9861(app, cpu);
    if (cpu.terminate) return;
L_0x004bcfaf:
    // 004bcfaf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bcfb1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcfb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcfb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcfb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bcfb5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcfb5);
    // 004bcfb5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bcfb6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bcfb7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bcfb8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bcfb9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcfba  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bcfbb  ff1548cb4d00           -call dword ptr [0x4dcb48]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098312) /* 0x4dcb48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bcfc1  2eff15a0444c00         -call dword ptr cs:[0x4c44a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998304) /* 0x4c44a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bcfc8  8b1da4855b00           -mov ebx, dword ptr [0x5b85a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5997988) /* 0x5b85a4 */);
    // 004bcfce  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004bcfd0  eb07                   -jmp 0x4bcfd9
    goto L_0x004bcfd9;
L_0x004bcfd2:
    // 004bcfd2  3b6b04                 +cmp ebp, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcfd5  7406                   -je 0x4bcfdd
    if (cpu.flags.zf)
    {
        goto L_0x004bcfdd;
    }
    // 004bcfd7  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
L_0x004bcfd9:
    // 004bcfd9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bcfdb  75f5                   -jne 0x4bcfd2
    if (!cpu.flags.zf)
    {
        goto L_0x004bcfd2;
    }
L_0x004bcfdd:
    // 004bcfdd  837b0c00               +cmp dword ptr [ebx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcfe1  7425                   -je 0x4bd008
    if (cpu.flags.zf)
    {
        goto L_0x004bd008;
    }
    // 004bcfe3  8b157ce74d00           -mov edx, dword ptr [0x4de77c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5105532) /* 0x4de77c */);
    // 004bcfe9  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004bcfec  e8baf4feff             -call 0x4ac4ab
    cpu.esp -= 4;
    sub_4ac4ab(app, cpu);
    if (cpu.terminate) return;
    // 004bcff1  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004bcff3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bcff5  755e                   -jne 0x4bd055
    if (!cpu.flags.zf)
    {
        goto L_0x004bd055;
    }
    // 004bcff7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bcffc  b8a5fc4c00             -mov eax, 0x4cfca5
    cpu.eax = 5045413 /*0x4cfca5*/;
    // 004bd001  e85bc8ffff             -call 0x4b9861
    cpu.esp -= 4;
    sub_4b9861(app, cpu);
    if (cpu.terminate) return;
    // 004bd006  eb4d                   -jmp 0x4bd055
    goto L_0x004bd055;
L_0x004bd008:
    // 004bd008  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bd00d  8b157ce74d00           -mov edx, dword ptr [0x4de77c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5105532) /* 0x4de77c */);
    // 004bd013  e84cffffff             -call 0x4bcf64
    cpu.esp -= 4;
    sub_4bcf64(app, cpu);
    if (cpu.terminate) return;
    // 004bd018  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004bd01a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd01c  750f                   -jne 0x4bd02d
    if (!cpu.flags.zf)
    {
        goto L_0x004bd02d;
    }
    // 004bd01e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bd023  b8cdfc4c00             -mov eax, 0x4cfccd
    cpu.eax = 5045453 /*0x4cfccd*/;
    // 004bd028  e834c8ffff             -call 0x4b9861
    cpu.esp -= 4;
    sub_4b9861(app, cpu);
    if (cpu.terminate) return;
L_0x004bd02d:
    // 004bd02d  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004bd030  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004bd032  8b8ef0000000           -mov ecx, dword ptr [esi + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 004bd038  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004bd039  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004bd03b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004bd03d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bd03e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bd040  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bd043  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bd045  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bd047  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bd04a  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bd04c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd04d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004bd04e  c7430c01000000         -mov dword ptr [ebx + 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004bd055:
    // 004bd055  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004bd058  a17ce74d00             -mov eax, dword ptr [0x4de77c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5105532) /* 0x4de77c */);
    // 004bd05d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd05e  c6455201               -mov byte ptr [ebp + 0x52], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 004bd062  8b3518cb4d00           -mov esi, dword ptr [0x4dcb18]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */);
    // 004bd068  c6455300               -mov byte ptr [ebp + 0x53], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(83) /* 0x53 */) = 0 /*0x0*/;
    // 004bd06c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd06d  8985f0000000           -mov dword ptr [ebp + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 004bd073  2eff158c454c00         -call dword ptr cs:[0x4c458c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998540) /* 0x4c458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bd07a  ff154ccb4d00           -call dword ptr [0x4dcb4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098316) /* 0x4dcb4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bd080  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004bd082  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd083  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd084  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd085  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd086  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd087  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd088  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bd089(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bd089);
    // 004bd089  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bd08a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd08b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd08c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bd08e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bd090  ff1548cb4d00           -call dword ptr [0x4dcb48]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098312) /* 0x4dcb48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bd096  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004bd09b  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004bd0a0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bd0a2  e8bdfeffff             -call 0x4bcf64
    cpu.esp -= 4;
    sub_4bcf64(app, cpu);
    if (cpu.terminate) return;
    // 004bd0a7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bd0a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd0ab  742f                   -je 0x4bd0dc
    if (cpu.flags.zf)
    {
        goto L_0x004bd0dc;
    }
    // 004bd0ad  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bd0af  e84d470000             -call 0x4c1801
    cpu.esp -= 4;
    sub_4c1801(app, cpu);
    if (cpu.terminate) return;
    // 004bd0b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd0b6  7409                   -je 0x4bd0c1
    if (cpu.flags.zf)
    {
        goto L_0x004bd0c1;
    }
    // 004bd0b8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd0ba  e8f99ffeff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004bd0bf  eb1b                   -jmp 0x4bd0dc
    goto L_0x004bd0dc;
L_0x004bd0c1:
    // 004bd0c1  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004bd0c4  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004bd0c7  8a4352                 -mov al, byte ptr [ebx + 0x52]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(82) /* 0x52 */);
    // 004bd0ca  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004bd0cd  a1a4855b00             -mov eax, dword ptr [0x5b85a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5997988) /* 0x5b85a4 */);
    // 004bd0d2  8915a4855b00           -mov dword ptr [0x5b85a4], edx
    app->getMemory<x86::reg32>(x86::reg32(5997988) /* 0x5b85a4 */) = cpu.edx;
    // 004bd0d8  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004bd0da  eb02                   -jmp 0x4bd0de
    goto L_0x004bd0de;
L_0x004bd0dc:
    // 004bd0dc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004bd0de:
    // 004bd0de  ff154ccb4d00           -call dword ptr [0x4dcb4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098316) /* 0x4dcb4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bd0e4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bd0e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd0e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd0e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd0e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bd0ea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bd0ea);
    // 004bd0ea  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bd0eb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd0ec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bd0ed  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bd0ef  ff1548cb4d00           -call dword ptr [0x4dcb48]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098312) /* 0x4dcb48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bd0f5  bba4855b00             -mov ebx, 0x5b85a4
    cpu.ebx = 5997988 /*0x5b85a4*/;
    // 004bd0fa  8b15a4855b00           -mov edx, dword ptr [0x5b85a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5997988) /* 0x5b85a4 */);
    // 004bd100  eb24                   -jmp 0x4bd126
    goto L_0x004bd126;
L_0x004bd102:
    // 004bd102  3b4a04                 +cmp ecx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd105  751b                   -jne 0x4bd122
    if (!cpu.flags.zf)
    {
        goto L_0x004bd122;
    }
    // 004bd107  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 004bd10b  7408                   -je 0x4bd115
    if (cpu.flags.zf)
    {
        goto L_0x004bd115;
    }
    // 004bd10d  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004bd110  e8a39ffeff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
L_0x004bd115:
    // 004bd115  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004bd117  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004bd119  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd11b  e8989ffeff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004bd120  eb08                   -jmp 0x4bd12a
    goto L_0x004bd12a;
L_0x004bd122:
    // 004bd122  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bd124  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004bd126:
    // 004bd126  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bd128  75d8                   -jne 0x4bd102
    if (!cpu.flags.zf)
    {
        goto L_0x004bd102;
    }
L_0x004bd12a:
    // 004bd12a  ff154ccb4d00           -call dword ptr [0x4dcb4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098316) /* 0x4dcb4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bd130  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd131  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd132  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd133  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bd130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bd130);
    goto L_entry_0x004bd130;
    // 004bd0ea  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bd0eb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd0ec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bd0ed  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bd0ef  ff1548cb4d00           -call dword ptr [0x4dcb48]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098312) /* 0x4dcb48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bd0f5  bba4855b00             -mov ebx, 0x5b85a4
    cpu.ebx = 5997988 /*0x5b85a4*/;
    // 004bd0fa  8b15a4855b00           -mov edx, dword ptr [0x5b85a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5997988) /* 0x5b85a4 */);
    // 004bd100  eb24                   -jmp 0x4bd126
    goto L_0x004bd126;
L_0x004bd102:
    // 004bd102  3b4a04                 +cmp ecx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bd105  751b                   -jne 0x4bd122
    if (!cpu.flags.zf)
    {
        goto L_0x004bd122;
    }
    // 004bd107  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 004bd10b  7408                   -je 0x4bd115
    if (cpu.flags.zf)
    {
        goto L_0x004bd115;
    }
    // 004bd10d  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004bd110  e8a39ffeff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
L_0x004bd115:
    // 004bd115  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004bd117  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004bd119  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd11b  e8989ffeff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004bd120  eb08                   -jmp 0x4bd12a
    goto L_0x004bd12a;
L_0x004bd122:
    // 004bd122  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bd124  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004bd126:
    // 004bd126  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bd128  75d8                   -jne 0x4bd102
    if (!cpu.flags.zf)
    {
        goto L_0x004bd102;
    }
L_0x004bd12a:
    // 004bd12a  ff154ccb4d00           -call dword ptr [0x4dcb4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098316) /* 0x4dcb4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x004bd130:
    // 004bd130  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd131  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd132  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd133  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bd134(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bd134);
    // 004bd134  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bd135  ff1548cb4d00           -call dword ptr [0x4dcb48]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098312) /* 0x4dcb48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bd13b  a1a4855b00             -mov eax, dword ptr [0x5b85a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5997988) /* 0x5b85a4 */);
L_0x004bd140:
    // 004bd140  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd142  740b                   -je 0x4bd14f
    if (cpu.flags.zf)
    {
        goto L_0x004bd14f;
    }
    // 004bd144  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004bd147  c6425301               -mov byte ptr [edx + 0x53], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(83) /* 0x53 */) = 1 /*0x1*/;
    // 004bd14b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004bd14d  ebf1                   -jmp 0x4bd140
    goto L_0x004bd140;
L_0x004bd14f:
    // 004bd14f  ff154ccb4d00           -call dword ptr [0x4dcb4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098316) /* 0x4dcb4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bd155  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd156  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bd157(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bd157);
    // 004bd157  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bd158  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd159  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bd15a  8b15a4855b00           -mov edx, dword ptr [0x5b85a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5997988) /* 0x5b85a4 */);
L_0x004bd160:
    // 004bd160  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bd162  74cc                   -je 0x4bd130
    if (cpu.flags.zf)
    {
        return sub_4bd130(app, cpu);
    }
    // 004bd164  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004bd167  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004bd169  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bd16b  7408                   -je 0x4bd175
    if (cpu.flags.zf)
    {
        goto L_0x004bd175;
    }
    // 004bd16d  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004bd170  e8439ffeff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
L_0x004bd175:
    // 004bd175  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd177  e83c9ffeff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004bd17c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bd17e  ebe0                   -jmp 0x4bd160
    goto L_0x004bd160;
}

/* align: skip  */
void Application::sub_4bd180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bd180);
    // 004bd180  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bd181  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd182  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bd183  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bd185  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bd187  741b                   -je 0x4bd1a4
    if (cpu.flags.zf)
    {
        goto L_0x004bd1a4;
    }
    // 004bd189  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bd18b  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 004bd192  e82597ffff             -call 0x4b68bc
    cpu.esp -= 4;
    sub_4b68bc(app, cpu);
    if (cpu.terminate) return;
    // 004bd197  2eff15a0444c00         -call dword ptr cs:[0x4c44a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998304) /* 0x4c44a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bd19e  8983da000000           -mov dword ptr [ebx + 0xda], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(218) /* 0xda */) = cpu.eax;
L_0x004bd1a4:
    // 004bd1a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd1a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd1a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd1a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bd1a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bd1a8);
    // 004bd1a8  e9aaffffff             -jmp 0x4bd157
    return sub_4bd157(app, cpu);
}

/* align: skip  */
void Application::sub_4bd1ad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bd1ad);
    // 004bd1ad  66833801               +cmp word ptr [eax], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bd1b1  751c                   -jne 0x4bd1cf
    if (!cpu.flags.zf)
    {
        goto L_0x004bd1cf;
    }
    // 004bd1b3  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004bd1b7  7416                   -je 0x4bd1cf
    if (cpu.flags.zf)
    {
        goto L_0x004bd1cf;
    }
    // 004bd1b9  668b400a               -mov ax, word ptr [eax + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 004bd1bd  663d1000               +cmp ax, 0x10
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bd1c1  7206                   -jb 0x4bd1c9
    if (cpu.flags.cf)
    {
        goto L_0x004bd1c9;
    }
    // 004bd1c3  663d1200               +cmp ax, 0x12
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18 /*0x12*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bd1c7  7606                   -jbe 0x4bd1cf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004bd1cf;
    }
L_0x004bd1c9:
    // 004bd1c9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004bd1ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bd1cf:
    // 004bd1cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd1d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
