#include "eacsnd.h"
#include <lib/thread.h>

namespace eacsnd
{

/* align: skip  */
void sub_54aa00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054aa00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054aa01  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0054aa06  b802000600             -mov eax, 0x60002
    cpu.eax = 393218 /*0x60002*/;
    // 0054aa0b  891560dc5400           -mov dword ptr [0x54dc60], edx
    app->getMemory<x86::reg32>(x86::reg32(5561440) /* 0x54dc60 */) = cpu.edx;
    // 0054aa11  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054aa12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_54aa14(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054aa14  a368dc5400             -mov dword ptr [0x54dc68], eax
    app->getMemory<x86::reg32>(x86::reg32(5561448) /* 0x54dc68 */) = cpu.eax;
    // 0054aa19  89156cdc5400           -mov dword ptr [0x54dc6c], edx
    app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */) = cpu.edx;
    // 0054aa1f  891d70dc5400           -mov dword ptr [0x54dc70], ebx
    app->getMemory<x86::reg32>(x86::reg32(5561456) /* 0x54dc70 */) = cpu.ebx;
    // 0054aa25  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0054aa29  890d74dc5400           -mov dword ptr [0x54dc74], ecx
    app->getMemory<x86::reg32>(x86::reg32(5561460) /* 0x54dc74 */) = cpu.ecx;
    // 0054aa2f  a378dc5400             -mov dword ptr [0x54dc78], eax
    app->getMemory<x86::reg32>(x86::reg32(5561464) /* 0x54dc78 */) = cpu.eax;
    // 0054aa34  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0054aa36  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_54aa3c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054aa3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054aa3d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054aa3e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0054aa3f  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0054aa45  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0054aa47  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054aa49  89942488000000         -mov dword ptr [esp + 0x88], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.edx;
    // 0054aa50  833d60dc540000         +cmp dword ptr [0x54dc60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561440) /* 0x54dc60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054aa57  7c0f                   -jl 0x54aa68
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0054aa68;
    }
    // 0054aa59  a160dc5400             -mov eax, dword ptr [0x54dc60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561440) /* 0x54dc60 */);
    // 0054aa5e  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0054aa64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054aa65  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054aa66  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054aa67  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054aa68:
    // 0054aa68  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0054aa69  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054aa6a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054aa6b  803d10dc540000         +cmp byte ptr [0x54dc10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561360) /* 0x54dc10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054aa72  7475                   -je 0x54aae9
    if (cpu.flags.zf)
    {
        goto L_0x0054aae9;
    }
L_0x0054aa74:
    // 0054aa74  c744240c60000000       -mov dword ptr [esp + 0xc], 0x60
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 96 /*0x60*/;
    // 0054aa7c  a100dc5400             -mov eax, dword ptr [0x54dc00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054aa81  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0054aa83  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0054aa87  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054aa88  8b3d00dc5400           -mov edi, dword ptr [0x54dc00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054aa8e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0054aa8f  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054aa92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054aa94  0f848b000000           -je 0x54ab25
    if (cpu.flags.zf)
    {
        goto L_0x0054ab25;
    }
L_0x0054aa9a:
    // 0054aa9a  c7842494000000ffffffff -mov dword ptr [esp + 0x94], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967295 /*0xffffffff*/;
L_0x0054aaa5:
    // 0054aaa5  803d10dc540000         +cmp byte ptr [0x54dc10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561360) /* 0x54dc10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054aaac  7522                   -jne 0x54aad0
    if (!cpu.flags.zf)
    {
        goto L_0x0054aad0;
    }
    // 0054aaae  833d00dc540000         +cmp dword ptr [0x54dc00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054aab5  7411                   -je 0x54aac8
    if (cpu.flags.zf)
    {
        goto L_0x0054aac8;
    }
    // 0054aab7  a100dc5400             -mov eax, dword ptr [0x54dc00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054aabc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054aabe  8b1500dc5400           -mov edx, dword ptr [0x54dc00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054aac4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054aac5  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0054aac8:
    // 0054aac8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0054aaca  890d00dc5400           -mov dword ptr [0x54dc00], ecx
    app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */) = cpu.ecx;
L_0x0054aad0:
    // 0054aad0  8b842494000000         -mov eax, dword ptr [esp + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 0054aad7  a360dc5400             -mov dword ptr [0x54dc60], eax
    app->getMemory<x86::reg32>(x86::reg32(5561440) /* 0x54dc60 */) = cpu.eax;
    // 0054aadc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054aadd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054aade  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054aadf  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0054aae5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054aae6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054aae7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054aae8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054aae9:
    // 0054aae9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054aaea  6800dc5400             -push 0x54dc00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561344 /*0x54dc00*/;
    cpu.esp -= 4;
    // 0054aaef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054aaf0  e83f110000             -call 0x54bc34
    cpu.esp -= 4;
    sub_54bc34(app, cpu);
    if (cpu.terminate) return;
    // 0054aaf5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054aaf7  0f8477ffffff           -je 0x54aa74
    if (cpu.flags.zf)
    {
        goto L_0x0054aa74;
    }
    // 0054aafd  3d0a007888             +cmp eax, 0x8878000a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565706 /*0x8878000a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054ab02  7414                   -je 0x54ab18
    if (cpu.flags.zf)
    {
        goto L_0x0054ab18;
    }
    // 0054ab04  3d78007888             +cmp eax, 0x88780078
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565816 /*0x88780078*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054ab09  758f                   -jne 0x54aa9a
    if (!cpu.flags.zf)
    {
        goto L_0x0054aa9a;
    }
    // 0054ab0b  c7842494000000f6ffffff -mov dword ptr [esp + 0x94], 0xfffffff6
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967286 /*0xfffffff6*/;
    // 0054ab16  eb8d                   -jmp 0x54aaa5
    goto L_0x0054aaa5;
L_0x0054ab18:
    // 0054ab18  c7842494000000eeffffff -mov dword ptr [esp + 0x94], 0xffffffee
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967278 /*0xffffffee*/;
    // 0054ab23  eb80                   -jmp 0x54aaa5
    goto L_0x0054aaa5;
L_0x0054ab25:
    // 0054ab25  f644241020             +test byte ptr [esp + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 32 /*0x20*/));
    // 0054ab2a  0f84c2000000           -je 0x54abf2
    if (cpu.flags.zf)
    {
        goto L_0x0054abf2;
    }
    // 0054ab30  c60515dc540001         -mov byte ptr [0x54dc15], 1
    app->getMemory<x86::reg8>(x86::reg32(5561365) /* 0x54dc15 */) = 1 /*0x1*/;
L_0x0054ab37:
    // 0054ab37  8aac2496000000         -mov ch, byte ptr [esp + 0x96]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(150) /* 0x96 */);
    // 0054ab3e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0054ab43  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0054ab47  80cd02                 -or ch, 2
    cpu.ch |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0054ab4a  6689942482000000       -mov word ptr [esp + 0x82], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */) = cpu.dx;
    // 0054ab52  88ac2496000000         -mov byte ptr [esp + 0x96], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(150) /* 0x96 */) = cpu.ch;
    // 0054ab59  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0054ab5e  83e005                 -and eax, 5
    cpu.eax &= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0054ab61  66898c248e000000       -mov word ptr [esp + 0x8e], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */) = cpu.cx;
    // 0054ab69  83f805                 +cmp eax, 5
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
    // 0054ab6c  7508                   -jne 0x54ab76
    if (!cpu.flags.zf)
    {
        goto L_0x0054ab76;
    }
    // 0054ab6e  808c249400000001       -or byte ptr [esp + 0x94], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0054ab76:
    // 0054ab76  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0054ab7a  83e006                 -and eax, 6
    cpu.eax &= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0054ab7d  83f806                 +cmp eax, 6
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
    // 0054ab80  7508                   -jne 0x54ab8a
    if (!cpu.flags.zf)
    {
        goto L_0x0054ab8a;
    }
    // 0054ab82  808c249400000002       -or byte ptr [esp + 0x94], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0054ab8a:
    // 0054ab8a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0054ab8e  83e009                 -and eax, 9
    cpu.eax &= x86::reg32(x86::sreg32(9 /*0x9*/));
    // 0054ab91  83f809                 +cmp eax, 9
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054ab94  7508                   -jne 0x54ab9e
    if (!cpu.flags.zf)
    {
        goto L_0x0054ab9e;
    }
    // 0054ab96  808c249400000004       -or byte ptr [esp + 0x94], 4
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0054ab9e:
    // 0054ab9e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0054aba2  83e00a                 -and eax, 0xa
    cpu.eax &= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0054aba5  83f80a                 +cmp eax, 0xa
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
    // 0054aba8  752b                   -jne 0x54abd5
    if (!cpu.flags.zf)
    {
        goto L_0x0054abd5;
    }
    // 0054abaa  8ab42494000000         -mov dh, byte ptr [esp + 0x94]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 0054abb1  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 0054abb6  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
    // 0054abbb  80ce08                 -or dh, 8
    cpu.dh |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0054abbe  6689b42482000000       -mov word ptr [esp + 0x82], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */) = cpu.si;
    // 0054abc6  6689bc248e000000       -mov word ptr [esp + 0x8e], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */) = cpu.di;
    // 0054abce  88b42494000000         -mov byte ptr [esp + 0x94], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.dh;
L_0x0054abd5:
    // 0054abd5  a100dc5400             -mov eax, dword ptr [0x54dc00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054abda  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0054abdc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054abde  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054abdf  8b2d00dc5400           -mov ebp, dword ptr [0x54dc00]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054abe5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0054abe6  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054abe9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054abeb  7412                   -je 0x54abff
    if (cpu.flags.zf)
    {
        goto L_0x0054abff;
    }
    // 0054abed  e9a8feffff             -jmp 0x54aa9a
    goto L_0x0054aa9a;
L_0x0054abf2:
    // 0054abf2  30f6                   +xor dh, dh
    cpu.clear_co();
    cpu.set_szp((cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh))));
    // 0054abf4  883515dc5400           -mov byte ptr [0x54dc15], dh
    app->getMemory<x86::reg8>(x86::reg32(5561365) /* 0x54dc15 */) = cpu.dh;
    // 0054abfa  e938ffffff             -jmp 0x54ab37
    goto L_0x0054ab37;
L_0x0054abff:
    // 0054abff  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0054ac04  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0054ac08  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054ac0a  e8680f0000             -call 0x54bb77
    cpu.esp -= 4;
    sub_54bb77(app, cpu);
    if (cpu.terminate) return;
    // 0054ac0f  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0054ac14  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0054ac19  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0054ac1d  89542470               -mov dword ptr [esp + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 0054ac21  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054ac23  8b1500dc5400           -mov edx, dword ptr [0x54dc00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054ac29  6804dc5400             -push 0x54dc04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561348 /*0x54dc04*/;
    cpu.esp -= 4;
    // 0054ac2e  8d442474               -lea eax, [esp + 0x74]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0054ac32  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0054ac34  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054ac35  8b0d00dc5400           -mov ecx, dword ptr [0x54dc00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054ac3b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054ac3c  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054ac3f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054ac41  0f8553feffff           -jne 0x54aa9a
    if (!cpu.flags.zf)
    {
        goto L_0x0054aa9a;
    }
    // 0054ac47  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0054ac4c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054ac4e  6689842480000000       -mov word ptr [esp + 0x80], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.ax;
    // 0054ac56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0054ac58  668b942482000000       -mov dx, word ptr [esp + 0x82]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
    // 0054ac60  668b84248e000000       -mov ax, word ptr [esp + 0x8e]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
    // 0054ac68  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0054ac6b  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0054ac6e  668984248c000000       -mov word ptr [esp + 0x8c], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.ax;
    // 0054ac76  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0054ac78  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0054ac80  69c0112b0000           -imul eax, eax, 0x2b11
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(11025 /*0x2b11*/)));
    // 0054ac86  bb112b0000             -mov ebx, 0x2b11
    cpu.ebx = 11025 /*0x2b11*/;
    // 0054ac8b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054ac8d  899c2484000000         -mov dword ptr [esp + 0x84], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 0054ac94  6689942490000000       -mov word ptr [esp + 0x90], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.dx;
    // 0054ac9c  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0054aca3  a104dc5400             -mov eax, dword ptr [0x54dc04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054aca8  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0054acaa  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0054acb1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054acb2  8b3504dc5400           -mov esi, dword ptr [0x54dc04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054acb8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054acb9  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054acbc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054acbe  7508                   -jne 0x54acc8
    if (!cpu.flags.zf)
    {
        goto L_0x0054acc8;
    }
    // 0054acc0  808c249500000002       -or byte ptr [esp + 0x95], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0054acc8:
    // 0054acc8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054acca  668b94248c000000       -mov dx, word ptr [esp + 0x8c]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0054acd2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0054acd9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0054acdb  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0054acde  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0054ace0  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0054ace3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0054ace5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0054ace8  bf803e0000             -mov edi, 0x3e80
    cpu.edi = 16000 /*0x3e80*/;
    // 0054aced  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0054acef  89bc2484000000         -mov dword ptr [esp + 0x84], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 0054acf6  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0054acfd  a104dc5400             -mov eax, dword ptr [0x54dc04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054ad02  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0054ad04  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0054ad0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054ad0c  8b2d04dc5400           -mov ebp, dword ptr [0x54dc04]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054ad12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0054ad13  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054ad16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054ad18  7508                   -jne 0x54ad22
    if (!cpu.flags.zf)
    {
        goto L_0x0054ad22;
    }
    // 0054ad1a  808c249500000004       -or byte ptr [esp + 0x95], 4
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0054ad22:
    // 0054ad22  c784248400000022560000 -mov dword ptr [esp + 0x84], 0x5622
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = 22050 /*0x5622*/;
    // 0054ad2d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0054ad2f  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0054ad37  69c022560000           -imul eax, eax, 0x5622
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(22050 /*0x5622*/)));
    // 0054ad3d  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0054ad44  8b1504dc5400           -mov edx, dword ptr [0x54dc04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054ad4a  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0054ad51  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0054ad53  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054ad54  8b0d04dc5400           -mov ecx, dword ptr [0x54dc04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054ad5a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054ad5b  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054ad5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054ad60  7508                   -jne 0x54ad6a
    if (!cpu.flags.zf)
    {
        goto L_0x0054ad6a;
    }
    // 0054ad62  808c249500000008       -or byte ptr [esp + 0x95], 8
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0054ad6a:
    // 0054ad6a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054ad6c  668b94248c000000       -mov dx, word ptr [esp + 0x8c]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0054ad74  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0054ad7b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0054ad7d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0054ad80  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0054ad82  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0054ad85  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0054ad87  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0054ad8a  bb007d0000             -mov ebx, 0x7d00
    cpu.ebx = 32000 /*0x7d00*/;
    // 0054ad8f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0054ad91  899c2484000000         -mov dword ptr [esp + 0x84], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 0054ad98  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0054ad9f  8b1504dc5400           -mov edx, dword ptr [0x54dc04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054ada5  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0054adac  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0054adae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054adaf  8b3504dc5400           -mov esi, dword ptr [0x54dc04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054adb5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054adb6  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054adb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054adbb  7508                   -jne 0x54adc5
    if (!cpu.flags.zf)
    {
        goto L_0x0054adc5;
    }
    // 0054adbd  808c249500000010       -or byte ptr [esp + 0x95], 0x10
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0054adc5:
    // 0054adc5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0054adc7  bf44ac0000             -mov edi, 0xac44
    cpu.edi = 44100 /*0xac44*/;
    // 0054adcc  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0054add4  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0054add7  89bc2484000000         -mov dword ptr [esp + 0x84], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 0054adde  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0054ade5  a104dc5400             -mov eax, dword ptr [0x54dc04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054adea  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0054adec  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0054adf3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054adf4  8b2d04dc5400           -mov ebp, dword ptr [0x54dc04]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054adfa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0054adfb  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054adfe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054ae00  7508                   -jne 0x54ae0a
    if (!cpu.flags.zf)
    {
        goto L_0x0054ae0a;
    }
    // 0054ae02  808c249500000020       -or byte ptr [esp + 0x95], 0x20
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0054ae0a:
    // 0054ae0a  f68424940000000f       +test byte ptr [esp + 0x94], 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) & 15 /*0xf*/));
    // 0054ae12  7571                   -jne 0x54ae85
    if (!cpu.flags.zf)
    {
        goto L_0x0054ae85;
    }
L_0x0054ae14:
    // 0054ae14  c7842494000000ffffffff -mov dword ptr [esp + 0x94], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967295 /*0xffffffff*/;
L_0x0054ae1f:
    // 0054ae1f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054ae21  a104dc5400             -mov eax, dword ptr [0x54dc04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054ae26  6a12                   -push 0x12
    app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 0054ae28  8d942488000000         -lea edx, [esp + 0x88]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0054ae2f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054ae31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054ae32  8b1d04dc5400           -mov ebx, dword ptr [0x54dc04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054ae38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054ae39  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054ae3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054ae3e  0f8561fcffff           -jne 0x54aaa5
    if (!cpu.flags.zf)
    {
        goto L_0x0054aaa5;
    }
    // 0054ae44  6683bc248200000001     +cmp word ptr [esp + 0x82], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0054ae4d  754f                   -jne 0x54ae9e
    if (!cpu.flags.zf)
    {
        goto L_0x0054ae9e;
    }
    // 0054ae4f  6683bc248e00000008     +cmp word ptr [esp + 0x8e], 8
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0054ae58  7544                   -jne 0x54ae9e
    if (!cpu.flags.zf)
    {
        goto L_0x0054ae9e;
    }
    // 0054ae5a  c784249400000001000000 -mov dword ptr [esp + 0x94], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 1 /*0x1*/;
L_0x0054ae65:
    // 0054ae65  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0054ae6c  81f9112b0000           +cmp ecx, 0x2b11
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11025 /*0x2b11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054ae72  0f859a000000           -jne 0x54af12
    if (!cpu.flags.zf)
    {
        goto L_0x0054af12;
    }
    // 0054ae78  808c249500000002       +or byte ptr [esp + 0x95], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0054ae80  e920fcffff             -jmp 0x54aaa5
    goto L_0x0054aaa5;
L_0x0054ae85:
    // 0054ae85  f68424950000003e       +test byte ptr [esp + 0x95], 0x3e
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) & 62 /*0x3e*/));
    // 0054ae8d  7485                   -je 0x54ae14
    if (cpu.flags.zf)
    {
        goto L_0x0054ae14;
    }
    // 0054ae8f  83bc249400000000       +cmp dword ptr [esp + 0x94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054ae97  7e86                   -jle 0x54ae1f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0054ae1f;
    }
    // 0054ae99  e907fcffff             -jmp 0x54aaa5
    goto L_0x0054aaa5;
L_0x0054ae9e:
    // 0054ae9e  6683bc248200000002     +cmp word ptr [esp + 0x82], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0054aea7  7518                   -jne 0x54aec1
    if (!cpu.flags.zf)
    {
        goto L_0x0054aec1;
    }
    // 0054aea9  6683bc248e00000008     +cmp word ptr [esp + 0x8e], 8
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0054aeb2  750d                   -jne 0x54aec1
    if (!cpu.flags.zf)
    {
        goto L_0x0054aec1;
    }
    // 0054aeb4  c784249400000002000000 -mov dword ptr [esp + 0x94], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 2 /*0x2*/;
    // 0054aebf  eba4                   -jmp 0x54ae65
    goto L_0x0054ae65;
L_0x0054aec1:
    // 0054aec1  6683bc248200000001     +cmp word ptr [esp + 0x82], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0054aeca  7518                   -jne 0x54aee4
    if (!cpu.flags.zf)
    {
        goto L_0x0054aee4;
    }
    // 0054aecc  6683bc248e00000010     +cmp word ptr [esp + 0x8e], 0x10
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0054aed5  750d                   -jne 0x54aee4
    if (!cpu.flags.zf)
    {
        goto L_0x0054aee4;
    }
    // 0054aed7  c784249400000004000000 -mov dword ptr [esp + 0x94], 4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4 /*0x4*/;
    // 0054aee2  eb81                   -jmp 0x54ae65
    goto L_0x0054ae65;
L_0x0054aee4:
    // 0054aee4  6683bc248200000002     +cmp word ptr [esp + 0x82], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0054aeed  0f85a7fbffff           -jne 0x54aa9a
    if (!cpu.flags.zf)
    {
        goto L_0x0054aa9a;
    }
    // 0054aef3  6683bc248e00000010     +cmp word ptr [esp + 0x8e], 0x10
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0054aefc  0f8598fbffff           -jne 0x54aa9a
    if (!cpu.flags.zf)
    {
        goto L_0x0054aa9a;
    }
    // 0054af02  c784249400000008000000 -mov dword ptr [esp + 0x94], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 8 /*0x8*/;
    // 0054af0d  e953ffffff             -jmp 0x54ae65
    goto L_0x0054ae65;
L_0x0054af12:
    // 0054af12  81f9803e0000           +cmp ecx, 0x3e80
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16000 /*0x3e80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054af18  750d                   -jne 0x54af27
    if (!cpu.flags.zf)
    {
        goto L_0x0054af27;
    }
    // 0054af1a  808c249500000004       +or byte ptr [esp + 0x95], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 0054af22  e97efbffff             -jmp 0x54aaa5
    goto L_0x0054aaa5;
L_0x0054af27:
    // 0054af27  81f922560000           +cmp ecx, 0x5622
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22050 /*0x5622*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054af2d  750d                   -jne 0x54af3c
    if (!cpu.flags.zf)
    {
        goto L_0x0054af3c;
    }
    // 0054af2f  808c249500000008       +or byte ptr [esp + 0x95], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0054af37  e969fbffff             -jmp 0x54aaa5
    goto L_0x0054aaa5;
L_0x0054af3c:
    // 0054af3c  81f9007d0000           +cmp ecx, 0x7d00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32000 /*0x7d00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054af42  750d                   -jne 0x54af51
    if (!cpu.flags.zf)
    {
        goto L_0x0054af51;
    }
    // 0054af44  808c249500000010       +or byte ptr [esp + 0x95], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0054af4c  e954fbffff             -jmp 0x54aaa5
    goto L_0x0054aaa5;
L_0x0054af51:
    // 0054af51  81f944ac0000           +cmp ecx, 0xac44
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44100 /*0xac44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054af57  0f853dfbffff           -jne 0x54aa9a
    if (!cpu.flags.zf)
    {
        goto L_0x0054aa9a;
    }
    // 0054af5d  808c249500000020       +or byte ptr [esp + 0x95], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0054af65  e93bfbffff             -jmp 0x54aaa5
    goto L_0x0054aaa5;
}

/* align: skip 0x8b 0xc0 */
void sub_54af6c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054af6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054af6d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054af6e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0054af6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0054af70  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0054af73  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0054af77  895c243c               -mov dword ptr [esp + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 0054af7b  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0054af80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054af82  0f8499010000           -je 0x54b121
    if (cpu.flags.zf)
    {
        goto L_0x0054b121;
    }
    // 0054af88  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
L_0x0054af8d:
    // 0054af8d  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 0054af90  0f8495010000           -je 0x54b12b
    if (cpu.flags.zf)
    {
        goto L_0x0054b12b;
    }
    // 0054af96  c70564dc540022560000   -mov dword ptr [0x54dc64], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(5561444) /* 0x54dc64 */) = 22050 /*0x5622*/;
L_0x0054afa0:
    // 0054afa0  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 0054afa3  0f84e9010000           -je 0x54b192
    if (cpu.flags.zf)
    {
        goto L_0x0054b192;
    }
    // 0054afa9  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x0054afae:
    // 0054afae  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
L_0x0054afb3:
    // 0054afb3  803d15dc540000         +cmp byte ptr [0x54dc15], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561365) /* 0x54dc15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054afba  0f8420020000           -je 0x54b1e0
    if (cpu.flags.zf)
    {
        goto L_0x0054b1e0;
    }
    // 0054afc0  c70530dc540000200000   -mov dword ptr [0x54dc30], 0x2000
    app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */) = 8192 /*0x2000*/;
    // 0054afca  83ff08                 +cmp edi, 8
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
    // 0054afcd  750c                   -jne 0x54afdb
    if (!cpu.flags.zf)
    {
        goto L_0x0054afdb;
    }
    // 0054afcf  a130dc5400             -mov eax, dword ptr [0x54dc30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */);
    // 0054afd4  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0054afd6  a330dc5400             -mov dword ptr [0x54dc30], eax
    app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */) = cpu.eax;
L_0x0054afdb:
    // 0054afdb  83fe01                 +cmp esi, 1
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
    // 0054afde  750e                   -jne 0x54afee
    if (!cpu.flags.zf)
    {
        goto L_0x0054afee;
    }
    // 0054afe0  8b1530dc5400           -mov edx, dword ptr [0x54dc30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */);
    // 0054afe6  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0054afe8  891530dc5400           -mov dword ptr [0x54dc30], edx
    app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */) = cpu.edx;
L_0x0054afee:
    // 0054afee  812530dc5400f0ff0f00   -and dword ptr [0x54dc30], 0xffff0
    app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */) &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 0054aff8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0054affa  a338dc5400             -mov dword ptr [0x54dc38], eax
    app->getMemory<x86::reg32>(x86::reg32(5561400) /* 0x54dc38 */) = cpu.eax;
    // 0054afff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054b001  a32cdc5400             -mov dword ptr [0x54dc2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5561388) /* 0x54dc2c */) = cpu.eax;
    // 0054b006  a324dc5400             -mov dword ptr [0x54dc24], eax
    app->getMemory<x86::reg32>(x86::reg32(5561380) /* 0x54dc24 */) = cpu.eax;
    // 0054b00b  a328dc5400             -mov dword ptr [0x54dc28], eax
    app->getMemory<x86::reg32>(x86::reg32(5561384) /* 0x54dc28 */) = cpu.eax;
    // 0054b010  a338dc5400             -mov dword ptr [0x54dc38], eax
    app->getMemory<x86::reg32>(x86::reg32(5561400) /* 0x54dc38 */) = cpu.eax;
    // 0054b015  a318dc5400             -mov dword ptr [0x54dc18], eax
    app->getMemory<x86::reg32>(x86::reg32(5561368) /* 0x54dc18 */) = cpu.eax;
    // 0054b01a  a344dc5400             -mov dword ptr [0x54dc44], eax
    app->getMemory<x86::reg32>(x86::reg32(5561412) /* 0x54dc44 */) = cpu.eax;
    // 0054b01f  b932000000             -mov ecx, 0x32
    cpu.ecx = 50 /*0x32*/;
    // 0054b024  a164dc5400             -mov eax, dword ptr [0x54dc64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561444) /* 0x54dc64 */);
    // 0054b029  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0054b02b  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 0054b030  a31cdc5400             -mov dword ptr [0x54dc1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5561372) /* 0x54dc1c */) = cpu.eax;
    // 0054b035  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0054b037  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0054b03a  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0054b03d  a213dc5400             -mov byte ptr [0x54dc13], al
    app->getMemory<x86::reg8>(x86::reg32(5561363) /* 0x54dc13 */) = cpu.al;
    // 0054b042  0fbe0513dc5400         -movsx eax, byte ptr [0x54dc13]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561363) /* 0x54dc13 */)));
    // 0054b049  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0054b04b  a214dc5400             -mov byte ptr [0x54dc14], al
    app->getMemory<x86::reg8>(x86::reg32(5561364) /* 0x54dc14 */) = cpu.al;
    // 0054b050  803d10dc540000         +cmp byte ptr [0x54dc10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561360) /* 0x54dc10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054b057  751d                   -jne 0x54b076
    if (!cpu.flags.zf)
    {
        goto L_0x0054b076;
    }
    // 0054b059  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054b05b  6800dc5400             -push 0x54dc00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561344 /*0x54dc00*/;
    cpu.esp -= 4;
    // 0054b060  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054b062  e8cd0b0000             -call 0x54bc34
    cpu.esp -= 4;
    sub_54bc34(app, cpu);
    if (cpu.terminate) return;
    // 0054b067  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b069  0f859a010000           -jne 0x54b209
    if (!cpu.flags.zf)
    {
        goto L_0x0054b209;
    }
    // 0054b06f  c60510dc540001         -mov byte ptr [0x54dc10], 1
    app->getMemory<x86::reg8>(x86::reg32(5561360) /* 0x54dc10 */) = 1 /*0x1*/;
L_0x0054b076:
    // 0054b076  a100dc5400             -mov eax, dword ptr [0x54dc00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054b07b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054b07c  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0054b080  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b082  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054b083  8b0d00dc5400           -mov ecx, dword ptr [0x54dc00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054b089  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054b08a  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b08d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b08f  0f84a0010000           -je 0x54b235
    if (cpu.flags.zf)
    {
        goto L_0x0054b235;
    }
    // 0054b095  833d6cdc540000         +cmp dword ptr [0x54dc6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b09c  740e                   -je 0x54b0ac
    if (cpu.flags.zf)
    {
        goto L_0x0054b0ac;
    }
    // 0054b09e  685cda5400             -push 0x54da5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560924 /*0x54da5c*/;
    cpu.esp -= 4;
L_0x0054b0a3:
    // 0054b0a3  ff156cdc5400           -call dword ptr [0x54dc6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b0a9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0054b0ac:
    // 0054b0ac  803d12dc540000         +cmp byte ptr [0x54dc12], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561362) /* 0x54dc12 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054b0b3  7434                   -je 0x54b0e9
    if (cpu.flags.zf)
    {
        goto L_0x0054b0e9;
    }
    // 0054b0b5  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0054b0b7  881512dc5400           -mov byte ptr [0x54dc12], dl
    app->getMemory<x86::reg8>(x86::reg32(5561362) /* 0x54dc12 */) = cpu.dl;
    // 0054b0bd  a104dc5400             -mov eax, dword ptr [0x54dc04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054b0c2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b0c4  8b3504dc5400           -mov esi, dword ptr [0x54dc04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054b0ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054b0cb  ff5048                 -call dword ptr [eax + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b0ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b0d0  7417                   -je 0x54b0e9
    if (cpu.flags.zf)
    {
        goto L_0x0054b0e9;
    }
    // 0054b0d2  833d6cdc540000         +cmp dword ptr [0x54dc6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b0d9  740e                   -je 0x54b0e9
    if (cpu.flags.zf)
    {
        goto L_0x0054b0e9;
    }
    // 0054b0db  68a0db5400             -push 0x54dba0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561248 /*0x54dba0*/;
    cpu.esp -= 4;
    // 0054b0e0  ff156cdc5400           -call dword ptr [0x54dc6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b0e6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0054b0e9:
    // 0054b0e9  803d10dc540000         +cmp byte ptr [0x54dc10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561360) /* 0x54dc10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054b0f0  7425                   -je 0x54b117
    if (cpu.flags.zf)
    {
        goto L_0x0054b117;
    }
    // 0054b0f2  833d00dc540000         +cmp dword ptr [0x54dc00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b0f9  0f859e040000           -jne 0x54b59d
    if (!cpu.flags.zf)
    {
        goto L_0x0054b59d;
    }
L_0x0054b0ff:
    // 0054b0ff  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0054b101  890d00dc5400           -mov dword ptr [0x54dc00], ecx
    app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */) = cpu.ecx;
    // 0054b107  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0054b109  881d11dc5400           -mov byte ptr [0x54dc11], bl
    app->getMemory<x86::reg8>(x86::reg32(5561361) /* 0x54dc11 */) = cpu.bl;
    // 0054b10f  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0054b111  883d10dc5400           -mov byte ptr [0x54dc10], bh
    app->getMemory<x86::reg8>(x86::reg32(5561360) /* 0x54dc10 */) = cpu.bh;
L_0x0054b117:
    // 0054b117  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0054b119  83c444                 +add esp, 0x44
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0054b11c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b11d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b11e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b11f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b120  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054b121:
    // 0054b121  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0054b126  e962feffff             -jmp 0x54af8d
    goto L_0x0054af8d;
L_0x0054b12b:
    // 0054b12b  f6c604                 +test dh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 4 /*0x4*/));
    // 0054b12e  740f                   -je 0x54b13f
    if (cpu.flags.zf)
    {
        goto L_0x0054b13f;
    }
    // 0054b130  c70564dc5400803e0000   -mov dword ptr [0x54dc64], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(5561444) /* 0x54dc64 */) = 16000 /*0x3e80*/;
    // 0054b13a  e961feffff             -jmp 0x54afa0
    goto L_0x0054afa0;
L_0x0054b13f:
    // 0054b13f  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 0054b142  740f                   -je 0x54b153
    if (cpu.flags.zf)
    {
        goto L_0x0054b153;
    }
    // 0054b144  c70564dc5400007d0000   -mov dword ptr [0x54dc64], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(5561444) /* 0x54dc64 */) = 32000 /*0x7d00*/;
    // 0054b14e  e94dfeffff             -jmp 0x54afa0
    goto L_0x0054afa0;
L_0x0054b153:
    // 0054b153  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 0054b156  740f                   -je 0x54b167
    if (cpu.flags.zf)
    {
        goto L_0x0054b167;
    }
    // 0054b158  c70564dc540044ac0000   -mov dword ptr [0x54dc64], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(5561444) /* 0x54dc64 */) = 44100 /*0xac44*/;
    // 0054b162  e939feffff             -jmp 0x54afa0
    goto L_0x0054afa0;
L_0x0054b167:
    // 0054b167  f6c602                 +test dh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 2 /*0x2*/));
    // 0054b16a  740f                   -je 0x54b17b
    if (cpu.flags.zf)
    {
        goto L_0x0054b17b;
    }
    // 0054b16c  c70564dc5400112b0000   -mov dword ptr [0x54dc64], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(5561444) /* 0x54dc64 */) = 11025 /*0x2b11*/;
    // 0054b176  e925feffff             -jmp 0x54afa0
    goto L_0x0054afa0;
L_0x0054b17b:
    // 0054b17b  833d6cdc540000         +cmp dword ptr [0x54dc6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b182  0f8424ffffff           -je 0x54b0ac
    if (cpu.flags.zf)
    {
        goto L_0x0054b0ac;
    }
    // 0054b188  6800da5400             -push 0x54da00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560832 /*0x54da00*/;
    cpu.esp -= 4;
    // 0054b18d  e911ffffff             -jmp 0x54b0a3
    goto L_0x0054b0a3;
L_0x0054b192:
    // 0054b192  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0054b195  740f                   -je 0x54b1a6
    if (cpu.flags.zf)
    {
        goto L_0x0054b1a6;
    }
    // 0054b197  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 0054b19c  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 0054b1a1  e90dfeffff             -jmp 0x54afb3
    goto L_0x0054afb3;
L_0x0054b1a6:
    // 0054b1a6  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 0054b1a9  740a                   -je 0x54b1b5
    if (cpu.flags.zf)
    {
        goto L_0x0054b1b5;
    }
    // 0054b1ab  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0054b1b0  e9f9fdffff             -jmp 0x54afae
    goto L_0x0054afae;
L_0x0054b1b5:
    // 0054b1b5  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0054b1b8  740f                   -je 0x54b1c9
    if (cpu.flags.zf)
    {
        goto L_0x0054b1c9;
    }
    // 0054b1ba  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0054b1bf  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 0054b1c4  e9eafdffff             -jmp 0x54afb3
    goto L_0x0054afb3;
L_0x0054b1c9:
    // 0054b1c9  833d6cdc540000         +cmp dword ptr [0x54dc6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b1d0  0f84d6feffff           -je 0x54b0ac
    if (cpu.flags.zf)
    {
        goto L_0x0054b0ac;
    }
    // 0054b1d6  682cda5400             -push 0x54da2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560876 /*0x54da2c*/;
    cpu.esp -= 4;
    // 0054b1db  e9c3feffff             -jmp 0x54b0a3
    goto L_0x0054b0a3;
L_0x0054b1e0:
    // 0054b1e0  c70530dc540014000000   -mov dword ptr [0x54dc30], 0x14
    app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */) = 20 /*0x14*/;
    // 0054b1ea  a164dc5400             -mov eax, dword ptr [0x54dc64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561444) /* 0x54dc64 */);
    // 0054b1ef  0faf0530dc5400         -imul eax, dword ptr [0x54dc30]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */))));
    // 0054b1f6  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 0054b1fb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054b1fd  f7f1                   +div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0054b1ff  a330dc5400             -mov dword ptr [0x54dc30], eax
    app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */) = cpu.eax;
    // 0054b204  e9e5fdffff             -jmp 0x54afee
    goto L_0x0054afee;
L_0x0054b209:
    // 0054b209  3d0a007888             +cmp eax, 0x8878000a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565706 /*0x8878000a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b20e  750a                   -jne 0x54b21a
    if (!cpu.flags.zf)
    {
        goto L_0x0054b21a;
    }
    // 0054b210  bdeeffffff             -mov ebp, 0xffffffee
    cpu.ebp = 4294967278 /*0xffffffee*/;
    // 0054b215  e992feffff             -jmp 0x54b0ac
    goto L_0x0054b0ac;
L_0x0054b21a:
    // 0054b21a  3d78007888             +cmp eax, 0x88780078
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565816 /*0x88780078*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b21f  750a                   -jne 0x54b22b
    if (!cpu.flags.zf)
    {
        goto L_0x0054b22b;
    }
    // 0054b221  bdf6ffffff             -mov ebp, 0xfffffff6
    cpu.ebp = 4294967286 /*0xfffffff6*/;
    // 0054b226  e981feffff             -jmp 0x54b0ac
    goto L_0x0054b0ac;
L_0x0054b22b:
    // 0054b22b  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0054b230  e977feffff             -jmp 0x54b0ac
    goto L_0x0054b0ac;
L_0x0054b235:
    // 0054b235  803d11dc540000         +cmp byte ptr [0x54dc11], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561361) /* 0x54dc11 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054b23c  755f                   -jne 0x54b29d
    if (!cpu.flags.zf)
    {
        goto L_0x0054b29d;
    }
    // 0054b23e  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0054b243  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0054b245  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054b247  e82b090000             -call 0x54bb77
    cpu.esp -= 4;
    sub_54bb77(app, cpu);
    if (cpu.terminate) return;
    // 0054b24c  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0054b251  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0054b256  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0054b259  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0054b25d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054b25f  8b1500dc5400           -mov edx, dword ptr [0x54dc00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054b265  6804dc5400             -push 0x54dc04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561348 /*0x54dc04*/;
    cpu.esp -= 4;
    // 0054b26a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0054b26e  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0054b270  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054b271  8b0d00dc5400           -mov ecx, dword ptr [0x54dc00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054b277  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054b278  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b27b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b27d  7417                   -je 0x54b296
    if (cpu.flags.zf)
    {
        goto L_0x0054b296;
    }
    // 0054b27f  833d6cdc540000         +cmp dword ptr [0x54dc6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b286  0f8420feffff           -je 0x54b0ac
    if (cpu.flags.zf)
    {
        goto L_0x0054b0ac;
    }
    // 0054b28c  6890da5400             -push 0x54da90
    app->getMemory<x86::reg32>(cpu.esp-4) = 5560976 /*0x54da90*/;
    cpu.esp -= 4;
    // 0054b291  e90dfeffff             -jmp 0x54b0a3
    goto L_0x0054b0a3;
L_0x0054b296:
    // 0054b296  c60511dc540001         -mov byte ptr [0x54dc11], 1
    app->getMemory<x86::reg8>(x86::reg32(5561361) /* 0x54dc11 */) = 1 /*0x1*/;
L_0x0054b29d:
    // 0054b29d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0054b2a2  668974242a             -mov word ptr [esp + 0x2a], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(42) /* 0x2a */) = cpu.si;
    // 0054b2a7  6689542428             -mov word ptr [esp + 0x28], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.dx;
    // 0054b2ac  a164dc5400             -mov eax, dword ptr [0x54dc64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561444) /* 0x54dc64 */);
    // 0054b2b1  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0054b2b5  0fbe0d14dc5400         -movsx ecx, byte ptr [0x54dc14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561364) /* 0x54dc14 */)));
    // 0054b2bc  a164dc5400             -mov eax, dword ptr [0x54dc64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561444) /* 0x54dc64 */);
    // 0054b2c1  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0054b2c3  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0054b2c7  660fbe0513dc5400       -movsx ax, byte ptr [0x54dc13]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561363) /* 0x54dc13 */)));
    // 0054b2cf  6689442434             -mov word ptr [esp + 0x34], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ax;
    // 0054b2d4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0054b2d6  66897c2436             -mov word ptr [esp + 0x36], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(54) /* 0x36 */) = cpu.di;
    // 0054b2db  66895c2438             -mov word ptr [esp + 0x38], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.bx;
    // 0054b2e0  a104dc5400             -mov eax, dword ptr [0x54dc04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054b2e5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b2e7  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0054b2eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054b2ec  8b1d04dc5400           -mov ebx, dword ptr [0x54dc04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054b2f2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054b2f3  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b2f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b2f8  7417                   -je 0x54b311
    if (cpu.flags.zf)
    {
        goto L_0x0054b311;
    }
    // 0054b2fa  833d6cdc540000         +cmp dword ptr [0x54dc6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b301  0f84a5fdffff           -je 0x54b0ac
    if (cpu.flags.zf)
    {
        goto L_0x0054b0ac;
    }
    // 0054b307  68c4da5400             -push 0x54dac4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561028 /*0x54dac4*/;
    cpu.esp -= 4;
    // 0054b30c  e992fdffff             -jmp 0x54b0a3
    goto L_0x0054b0a3;
L_0x0054b311:
    // 0054b311  c744241414000000       -mov dword ptr [esp + 0x14], 0x14
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 20 /*0x14*/;
    // 0054b319  a104dc5400             -mov eax, dword ptr [0x54dc04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054b31e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b320  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0054b324  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054b325  8b0d04dc5400           -mov ecx, dword ptr [0x54dc04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054b32b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054b32c  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b32f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b331  7417                   -je 0x54b34a
    if (cpu.flags.zf)
    {
        goto L_0x0054b34a;
    }
    // 0054b333  833d6cdc540000         +cmp dword ptr [0x54dc6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b33a  0f846cfdffff           -je 0x54b0ac
    if (cpu.flags.zf)
    {
        goto L_0x0054b0ac;
    }
    // 0054b340  68fcda5400             -push 0x54dafc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561084 /*0x54dafc*/;
    cpu.esp -= 4;
    // 0054b345  e959fdffff             -jmp 0x54b0a3
    goto L_0x0054b0a3;
L_0x0054b34a:
    // 0054b34a  837c244000             +cmp dword ptr [esp + 0x40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b34f  0f8429010000           -je 0x54b47e
    if (cpu.flags.zf)
    {
        goto L_0x0054b47e;
    }
    // 0054b355  f644241804             +test byte ptr [esp + 0x18], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */) & 4 /*0x4*/));
    // 0054b35a  0f844cfdffff           -je 0x54b0ac
    if (cpu.flags.zf)
    {
        goto L_0x0054b0ac;
    }
    // 0054b360  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0054b364  a33cdc5400             -mov dword ptr [0x54dc3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5561404) /* 0x54dc3c */) = cpu.eax;
    // 0054b369  0fbe0d14dc5400         -movsx ecx, byte ptr [0x54dc14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561364) /* 0x54dc14 */)));
    // 0054b370  a13cdc5400             -mov eax, dword ptr [0x54dc3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561404) /* 0x54dc3c */);
    // 0054b375  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0054b377  a80f                   +test al, 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 15 /*0xf*/));
    // 0054b379  0f852dfdffff           -jne 0x54b0ac
    if (!cpu.flags.zf)
    {
        goto L_0x0054b0ac;
    }
L_0x0054b37f:
    // 0054b37f  0fbe0d14dc5400         -movsx ecx, byte ptr [0x54dc14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561364) /* 0x54dc14 */)));
    // 0054b386  a13cdc5400             -mov eax, dword ptr [0x54dc3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561404) /* 0x54dc3c */);
    // 0054b38b  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0054b38d  a35cdc5400             -mov dword ptr [0x54dc5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5561436) /* 0x54dc5c */) = cpu.eax;
    // 0054b392  8b155cdc5400           -mov edx, dword ptr [0x54dc5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561436) /* 0x54dc5c */);
    // 0054b398  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0054b39b  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0054b3a0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0054b3a2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0054b3a5  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0054b3a7  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 0054b3ac  a334dc5400             -mov dword ptr [0x54dc34], eax
    app->getMemory<x86::reg32>(x86::reg32(5561396) /* 0x54dc34 */) = cpu.eax;
    // 0054b3b1  a15cdc5400             -mov eax, dword ptr [0x54dc5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561436) /* 0x54dc5c */);
    // 0054b3b6  a340dc5400             -mov dword ptr [0x54dc40], eax
    app->getMemory<x86::reg32>(x86::reg32(5561408) /* 0x54dc40 */) = cpu.eax;
    // 0054b3bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0054b3bd  a34cdc5400             -mov dword ptr [0x54dc4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5561420) /* 0x54dc4c */) = cpu.eax;
    // 0054b3c2  a350dc5400             -mov dword ptr [0x54dc50], eax
    app->getMemory<x86::reg32>(x86::reg32(5561424) /* 0x54dc50 */) = cpu.eax;
    // 0054b3c7  a348dc5400             -mov dword ptr [0x54dc48], eax
    app->getMemory<x86::reg32>(x86::reg32(5561416) /* 0x54dc48 */) = cpu.eax;
    // 0054b3cc  837c244000             +cmp dword ptr [esp + 0x40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b3d1  0f8400010000           -je 0x54b4d7
    if (cpu.flags.zf)
    {
        goto L_0x0054b4d7;
    }
    // 0054b3d7  a104dc5400             -mov eax, dword ptr [0x54dc04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
L_0x0054b3dc:
    // 0054b3dc  a30cdc5400             -mov dword ptr [0x54dc0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */) = cpu.eax;
    // 0054b3e1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054b3e3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054b3e5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054b3e7  a10cdc5400             -mov eax, dword ptr [0x54dc0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054b3ec  6858dc5400             -push 0x54dc58
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561432 /*0x54dc58*/;
    cpu.esp -= 4;
    // 0054b3f1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b3f3  6854dc5400             -push 0x54dc54
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561428 /*0x54dc54*/;
    cpu.esp -= 4;
    // 0054b3f8  8b1d3cdc5400           -mov ebx, dword ptr [0x54dc3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5561404) /* 0x54dc3c */);
    // 0054b3fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054b3ff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054b401  8b350cdc5400           -mov esi, dword ptr [0x54dc0c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054b407  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054b408  ff502c                 -call dword ptr [eax + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b40b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b40d  0f8599fcffff           -jne 0x54b0ac
    if (!cpu.flags.zf)
    {
        goto L_0x0054b0ac;
    }
    // 0054b413  8b1d3cdc5400           -mov ebx, dword ptr [0x54dc3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5561404) /* 0x54dc3c */);
    // 0054b419  a154dc5400             -mov eax, dword ptr [0x54dc54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561428) /* 0x54dc54 */);
    // 0054b41e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054b420  e852070000             -call 0x54bb77
    cpu.esp -= 4;
    sub_54bb77(app, cpu);
    if (cpu.terminate) return;
    // 0054b425  a10cdc5400             -mov eax, dword ptr [0x54dc0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054b42a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054b42c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b42e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054b430  8b3d3cdc5400           -mov edi, dword ptr [0x54dc3c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5561404) /* 0x54dc3c */);
    // 0054b436  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0054b437  8b1554dc5400           -mov edx, dword ptr [0x54dc54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561428) /* 0x54dc54 */);
    // 0054b43d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054b43e  8b0d0cdc5400           -mov ecx, dword ptr [0x54dc0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054b444  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054b445  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b448  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0054b44a  a10cdc5400             -mov eax, dword ptr [0x54dc0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054b44f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054b451  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b453  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054b455  8b1d0cdc5400           -mov ebx, dword ptr [0x54dc0c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054b45b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054b45c  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b45f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b461  0f8425010000           -je 0x54b58c
    if (cpu.flags.zf)
    {
        goto L_0x0054b58c;
    }
    // 0054b467  833d6cdc540000         +cmp dword ptr [0x54dc6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b46e  0f8438fcffff           -je 0x54b0ac
    if (cpu.flags.zf)
    {
        goto L_0x0054b0ac;
    }
    // 0054b474  686cdb5400             -push 0x54db6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561196 /*0x54db6c*/;
    cpu.esp -= 4;
    // 0054b479  e925fcffff             -jmp 0x54b0a3
    goto L_0x0054b0a3;
L_0x0054b47e:
    // 0054b47e  803d15dc540000         +cmp byte ptr [0x54dc15], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561365) /* 0x54dc15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054b485  7418                   -je 0x54b49f
    if (cpu.flags.zf)
    {
        goto L_0x0054b49f;
    }
    // 0054b487  0fbe0d14dc5400         -movsx ecx, byte ptr [0x54dc14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561364) /* 0x54dc14 */)));
    // 0054b48e  b800a00000             -mov eax, 0xa000
    cpu.eax = 40960 /*0xa000*/;
    // 0054b493  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0054b495  a33cdc5400             -mov dword ptr [0x54dc3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5561404) /* 0x54dc3c */) = cpu.eax;
    // 0054b49a  e9e0feffff             -jmp 0x54b37f
    goto L_0x0054b37f;
L_0x0054b49f:
    // 0054b49f  8b1564dc5400           -mov edx, dword ptr [0x54dc64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561444) /* 0x54dc64 */);
    // 0054b4a5  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0054b4ac  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0054b4ae  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0054b4b1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0054b4b3  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 0054b4b8  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0054b4bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054b4bd  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0054b4bf  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 0054b4c4  0fbe0d14dc5400         -movsx ecx, byte ptr [0x54dc14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561364) /* 0x54dc14 */)));
    // 0054b4cb  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0054b4cd  a33cdc5400             -mov dword ptr [0x54dc3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5561404) /* 0x54dc3c */) = cpu.eax;
    // 0054b4d2  e9a8feffff             -jmp 0x54b37f
    goto L_0x0054b37f;
L_0x0054b4d7:
    // 0054b4d7  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0054b4dc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0054b4de  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054b4e0  e892060000             -call 0x54bb77
    cpu.esp -= 4;
    sub_54bb77(app, cpu);
    if (cpu.terminate) return;
    // 0054b4e5  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0054b4ea  ba08000100             -mov edx, 0x10008
    cpu.edx = 65544 /*0x10008*/;
    // 0054b4ef  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0054b4f2  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0054b4f6  a13cdc5400             -mov eax, dword ptr [0x54dc3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561404) /* 0x54dc3c */);
    // 0054b4fb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0054b500  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0054b504  668974242a             -mov word ptr [esp + 0x2a], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(42) /* 0x2a */) = cpu.si;
    // 0054b509  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0054b50d  66894c2428             -mov word ptr [esp + 0x28], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 0054b512  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0054b516  a164dc5400             -mov eax, dword ptr [0x54dc64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561444) /* 0x54dc64 */);
    // 0054b51b  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0054b51f  0fbe0d14dc5400         -movsx ecx, byte ptr [0x54dc14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561364) /* 0x54dc14 */)));
    // 0054b526  a164dc5400             -mov eax, dword ptr [0x54dc64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561444) /* 0x54dc64 */);
    // 0054b52b  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0054b52d  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0054b531  660fbe0513dc5400       -movsx ax, byte ptr [0x54dc13]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561363) /* 0x54dc13 */)));
    // 0054b539  6689442434             -mov word ptr [esp + 0x34], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ax;
    // 0054b53e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0054b540  66897c2436             -mov word ptr [esp + 0x36], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(54) /* 0x36 */) = cpu.di;
    // 0054b545  6689742438             -mov word ptr [esp + 0x38], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.si;
    // 0054b54a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054b54c  a100dc5400             -mov eax, dword ptr [0x54dc00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054b551  6808dc5400             -push 0x54dc08
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561352 /*0x54dc08*/;
    cpu.esp -= 4;
    // 0054b556  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b558  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0054b55c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054b55d  8b0d00dc5400           -mov ecx, dword ptr [0x54dc00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054b563  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054b564  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b567  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b569  7417                   -je 0x54b582
    if (cpu.flags.zf)
    {
        goto L_0x0054b582;
    }
    // 0054b56b  833d6cdc540000         +cmp dword ptr [0x54dc6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b572  0f8434fbffff           -je 0x54b0ac
    if (cpu.flags.zf)
    {
        goto L_0x0054b0ac;
    }
    // 0054b578  6834db5400             -push 0x54db34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561140 /*0x54db34*/;
    cpu.esp -= 4;
    // 0054b57d  e921fbffff             -jmp 0x54b0a3
    goto L_0x0054b0a3;
L_0x0054b582:
    // 0054b582  a108dc5400             -mov eax, dword ptr [0x54dc08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561352) /* 0x54dc08 */);
    // 0054b587  e950feffff             -jmp 0x54b3dc
    goto L_0x0054b3dc;
L_0x0054b58c:
    // 0054b58c  c60512dc540001         -mov byte ptr [0x54dc12], 1
    app->getMemory<x86::reg8>(x86::reg32(5561362) /* 0x54dc12 */) = 1 /*0x1*/;
    // 0054b593  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0054b595  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0054b598  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b599  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b59a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b59b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b59c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054b59d:
    // 0054b59d  a100dc5400             -mov eax, dword ptr [0x54dc00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054b5a2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b5a4  8b1500dc5400           -mov edx, dword ptr [0x54dc00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054b5aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054b5ab  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b5ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b5b0  0f8449fbffff           -je 0x54b0ff
    if (cpu.flags.zf)
    {
        goto L_0x0054b0ff;
    }
    // 0054b5b6  833d6cdc540000         +cmp dword ptr [0x54dc6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b5bd  740e                   -je 0x54b5cd
    if (cpu.flags.zf)
    {
        goto L_0x0054b5cd;
    }
    // 0054b5bf  68d0db5400             -push 0x54dbd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561296 /*0x54dbd0*/;
    cpu.esp -= 4;
    // 0054b5c4  ff156cdc5400           -call dword ptr [0x54dc6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b5ca  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0054b5cd:
    // 0054b5cd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0054b5d2  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0054b5d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b5d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b5d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b5d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b5d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_54b5dc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054b5dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054b5dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054b5de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054b5df  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0054b5e1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0054b5e3  803d12dc540000         +cmp byte ptr [0x54dc12], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561362) /* 0x54dc12 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054b5ea  751f                   -jne 0x54b60b
    if (!cpu.flags.zf)
    {
        goto L_0x0054b60b;
    }
L_0x0054b5ec:
    // 0054b5ec  803d15dc540000         +cmp byte ptr [0x54dc15], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561365) /* 0x54dc15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054b5f3  751d                   -jne 0x54b612
    if (!cpu.flags.zf)
    {
        goto L_0x0054b612;
    }
    // 0054b5f5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0054b5fa  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0054b5fc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0054b5fe  e869f9ffff             -call 0x54af6c
    cpu.esp -= 4;
    sub_54af6c(app, cpu);
    if (cpu.terminate) return;
    // 0054b603  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b605  750b                   -jne 0x54b612
    if (!cpu.flags.zf)
    {
        goto L_0x0054b612;
    }
    // 0054b607  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b608  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b609  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b60a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054b60b:
    // 0054b60b  e814000000             -call 0x54b624
    cpu.esp -= 4;
    sub_54b624(app, cpu);
    if (cpu.terminate) return;
    // 0054b610  ebda                   -jmp 0x54b5ec
    goto L_0x0054b5ec;
L_0x0054b612:
    // 0054b612  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0054b614  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0054b616  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0054b618  e84ff9ffff             -call 0x54af6c
    cpu.esp -= 4;
    sub_54af6c(app, cpu);
    if (cpu.terminate) return;
    // 0054b61d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b61e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b61f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b620  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_54b624(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054b624  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054b625  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054b626  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054b627  803d12dc540000         +cmp byte ptr [0x54dc12], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561362) /* 0x54dc12 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054b62e  7534                   -jne 0x54b664
    if (!cpu.flags.zf)
    {
        goto L_0x0054b664;
    }
L_0x0054b630:
    // 0054b630  803d10dc540000         +cmp byte ptr [0x54dc10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561360) /* 0x54dc10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054b637  7425                   -je 0x54b65e
    if (cpu.flags.zf)
    {
        goto L_0x0054b65e;
    }
    // 0054b639  833d00dc540000         +cmp dword ptr [0x54dc00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b640  7558                   -jne 0x54b69a
    if (!cpu.flags.zf)
    {
        goto L_0x0054b69a;
    }
L_0x0054b642:
    // 0054b642  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0054b643  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054b644  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0054b646  893d00dc5400           -mov dword ptr [0x54dc00], edi
    app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */) = cpu.edi;
    // 0054b64c  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0054b64e  881d11dc5400           -mov byte ptr [0x54dc11], bl
    app->getMemory<x86::reg8>(x86::reg32(5561361) /* 0x54dc11 */) = cpu.bl;
    // 0054b654  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0054b656  883d10dc5400           -mov byte ptr [0x54dc10], bh
    app->getMemory<x86::reg8>(x86::reg32(5561360) /* 0x54dc10 */) = cpu.bh;
    // 0054b65c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b65d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0054b65e:
    // 0054b65e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0054b660  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b661  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b662  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b663  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054b664:
    // 0054b664  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0054b666  881512dc5400           -mov byte ptr [0x54dc12], dl
    app->getMemory<x86::reg8>(x86::reg32(5561362) /* 0x54dc12 */) = cpu.dl;
    // 0054b66c  a104dc5400             -mov eax, dword ptr [0x54dc04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054b671  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b673  8b1504dc5400           -mov edx, dword ptr [0x54dc04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561348) /* 0x54dc04 */);
    // 0054b679  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054b67a  ff5048                 -call dword ptr [eax + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b67d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b67f  74af                   -je 0x54b630
    if (cpu.flags.zf)
    {
        goto L_0x0054b630;
    }
    // 0054b681  833d6cdc540000         +cmp dword ptr [0x54dc6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b688  74a6                   -je 0x54b630
    if (cpu.flags.zf)
    {
        goto L_0x0054b630;
    }
    // 0054b68a  68a0db5400             -push 0x54dba0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561248 /*0x54dba0*/;
    cpu.esp -= 4;
    // 0054b68f  ff156cdc5400           -call dword ptr [0x54dc6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b695  83c404                 +add esp, 4
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
    // 0054b698  eb96                   -jmp 0x54b630
    goto L_0x0054b630;
L_0x0054b69a:
    // 0054b69a  a100dc5400             -mov eax, dword ptr [0x54dc00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054b69f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b6a1  8b3500dc5400           -mov esi, dword ptr [0x54dc00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5561344) /* 0x54dc00 */);
    // 0054b6a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054b6a8  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b6ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b6ad  7493                   -je 0x54b642
    if (cpu.flags.zf)
    {
        goto L_0x0054b642;
    }
    // 0054b6af  833d6cdc540000         +cmp dword ptr [0x54dc6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b6b6  740e                   -je 0x54b6c6
    if (cpu.flags.zf)
    {
        goto L_0x0054b6c6;
    }
    // 0054b6b8  68d0db5400             -push 0x54dbd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561296 /*0x54dbd0*/;
    cpu.esp -= 4;
    // 0054b6bd  ff156cdc5400           -call dword ptr [0x54dc6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5561452) /* 0x54dc6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b6c3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0054b6c6:
    // 0054b6c6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0054b6cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b6cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b6cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b6ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_54b6d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054b6d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054b6d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054b6d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054b6d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0054b6d4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0054b6d6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0054b6d8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0054b6da  7e43                   -jle 0x54b71f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0054b71f;
    }
L_0x0054b6dc:
    // 0054b6dc  833d48dc540000         +cmp dword ptr [0x54dc48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561416) /* 0x54dc48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b6e3  7e3f                   -jle 0x54b724
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0054b724;
    }
L_0x0054b6e5:
    // 0054b6e5  a148dc5400             -mov eax, dword ptr [0x54dc48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561416) /* 0x54dc48 */);
    // 0054b6ea  39c6                   +cmp esi, eax
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
    // 0054b6ec  0f8e98000000           -jle 0x54b78a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0054b78a;
    }
    // 0054b6f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0054b6f4:
    // 0054b6f4  8b1548dc5400           -mov edx, dword ptr [0x54dc48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561416) /* 0x54dc48 */);
    // 0054b6fa  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0054b6fc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0054b6fe  891548dc5400           -mov dword ptr [0x54dc48], edx
    app->getMemory<x86::reg32>(x86::reg32(5561416) /* 0x54dc48 */) = cpu.edx;
    // 0054b704  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0054b706  ff1568dc5400           -call dword ptr [0x54dc68]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5561448) /* 0x54dc68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b70c  8b0d11dc5400           -mov ecx, dword ptr [0x54dc11]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561361) /* 0x54dc11 */);
    // 0054b712  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0054b715  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0054b717  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0054b719  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0054b71b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0054b71d  7fbd                   -jg 0x54b6dc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0054b6dc;
    }
L_0x0054b71f:
    // 0054b71f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b720  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b721  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b722  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b723  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054b724:
    // 0054b724  ff054cdc5400           -inc dword ptr [0x54dc4c]
    (app->getMemory<x86::reg32>(x86::reg32(5561420) /* 0x54dc4c */))++;
    // 0054b72a  ff1574dc5400           -call dword ptr [0x54dc74]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5561460) /* 0x54dc74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b730  a14cdc5400             -mov eax, dword ptr [0x54dc4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561420) /* 0x54dc4c */);
    // 0054b735  0faf0564dc5400         -imul eax, dword ptr [0x54dc64]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5561444) /* 0x54dc64 */))));
    // 0054b73c  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 0054b741  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054b743  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0054b745  8b0d50dc5400           -mov ecx, dword ptr [0x54dc50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561424) /* 0x54dc50 */);
    // 0054b74b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0054b74d  a348dc5400             -mov dword ptr [0x54dc48], eax
    app->getMemory<x86::reg32>(x86::reg32(5561416) /* 0x54dc48 */) = cpu.eax;
    // 0054b752  25f0ffff0f             -and eax, 0xffffff0
    cpu.eax &= x86::reg32(x86::sreg32(268435440 /*0xffffff0*/));
    // 0054b757  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0054b75a  a348dc5400             -mov dword ptr [0x54dc48], eax
    app->getMemory<x86::reg32>(x86::reg32(5561416) /* 0x54dc48 */) = cpu.eax;
    // 0054b75f  8b0d4cdc5400           -mov ecx, dword ptr [0x54dc4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561420) /* 0x54dc4c */);
    // 0054b765  891550dc5400           -mov dword ptr [0x54dc50], edx
    app->getMemory<x86::reg32>(x86::reg32(5561424) /* 0x54dc50 */) = cpu.edx;
    // 0054b76b  81f930750000           +cmp ecx, 0x7530
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30000 /*0x7530*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b771  0f8e6effffff           -jle 0x54b6e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0054b6e5;
    }
    // 0054b777  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0054b779  891d4cdc5400           -mov dword ptr [0x54dc4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5561420) /* 0x54dc4c */) = cpu.ebx;
    // 0054b77f  891d50dc5400           -mov dword ptr [0x54dc50], ebx
    app->getMemory<x86::reg32>(x86::reg32(5561424) /* 0x54dc50 */) = cpu.ebx;
    // 0054b785  e95bffffff             -jmp 0x54b6e5
    goto L_0x0054b6e5;
L_0x0054b78a:
    // 0054b78a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0054b78c  e963ffffff             -jmp 0x54b6f4
    goto L_0x0054b6f4;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_54b794(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054b794  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054b795  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054b796  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054b797  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054b798  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0054b799  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0054b79a  8b1518dc5400           -mov edx, dword ptr [0x54dc18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561368) /* 0x54dc18 */);
    // 0054b7a0  81fa00000011           +cmp edx, 0x11000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(285212672 /*0x11000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b7a6  0f879f000000           -ja 0x54b84b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0054b84b;
    }
L_0x0054b7ac:
    // 0054b7ac  a118dc5400             -mov eax, dword ptr [0x54dc18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561368) /* 0x54dc18 */);
    // 0054b7b1  8b351cdc5400           -mov esi, dword ptr [0x54dc1c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5561372) /* 0x54dc1c */);
    // 0054b7b7  8b3d5cdc5400           -mov edi, dword ptr [0x54dc5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5561436) /* 0x54dc5c */);
    // 0054b7bd  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0054b7bf  39f8                   +cmp eax, edi
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
    // 0054b7c1  7c10                   -jl 0x54b7d3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0054b7d3;
    }
    // 0054b7c3  8b2d18dc5400           -mov ebp, dword ptr [0x54dc18]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5561368) /* 0x54dc18 */);
    // 0054b7c9  29fd                   -sub ebp, edi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0054b7cb  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0054b7cd  892d18dc5400           -mov dword ptr [0x54dc18], ebp
    app->getMemory<x86::reg32>(x86::reg32(5561368) /* 0x54dc18 */) = cpu.ebp;
L_0x0054b7d3:
    // 0054b7d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b7d5  0f8cab000000           -jl 0x54b886
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0054b886;
    }
    // 0054b7db  8b1544dc5400           -mov edx, dword ptr [0x54dc44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561412) /* 0x54dc44 */);
    // 0054b7e1  42                     -inc edx
    (cpu.edx)++;
    // 0054b7e2  8b0d40dc5400           -mov ecx, dword ptr [0x54dc40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561408) /* 0x54dc40 */);
    // 0054b7e8  891544dc5400           -mov dword ptr [0x54dc44], edx
    app->getMemory<x86::reg32>(x86::reg32(5561412) /* 0x54dc44 */) = cpu.edx;
    // 0054b7ee  39c8                   +cmp eax, ecx
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
    // 0054b7f0  0f8c78000000           -jl 0x54b86e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0054b86e;
    }
L_0x0054b7f6:
    // 0054b7f6  8b1d44dc5400           -mov ebx, dword ptr [0x54dc44]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5561412) /* 0x54dc44 */);
    // 0054b7fc  81fbb80b0000           +cmp ebx, 0xbb8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3000 /*0xbb8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b802  7c40                   -jl 0x54b844
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0054b844;
    }
    // 0054b804  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0054b809  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0054b80b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0054b80d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0054b810  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0054b812  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0054b814  752e                   -jne 0x54b844
    if (!cpu.flags.zf)
    {
        goto L_0x0054b844;
    }
    // 0054b816  833d40dc540010         +cmp dword ptr [0x54dc40], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561408) /* 0x54dc40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b81d  7e56                   -jle 0x54b875
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0054b875;
    }
    // 0054b81f  8b3d30dc5400           -mov edi, dword ptr [0x54dc30]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */);
    // 0054b825  4f                     -dec edi
    (cpu.edi)--;
    // 0054b826  a15cdc5400             -mov eax, dword ptr [0x54dc5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561436) /* 0x54dc5c */);
    // 0054b82b  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0054b82d  893d30dc5400           -mov dword ptr [0x54dc30], edi
    app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */) = cpu.edi;
    // 0054b833  81e5f0ff0f00           -and ebp, 0xffff0
    cpu.ebp &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 0054b839  a340dc5400             -mov dword ptr [0x54dc40], eax
    app->getMemory<x86::reg32>(x86::reg32(5561408) /* 0x54dc40 */) = cpu.eax;
    // 0054b83e  892d30dc5400           -mov dword ptr [0x54dc30], ebp
    app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */) = cpu.ebp;
L_0x0054b844:
    // 0054b844  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b845  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b846  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b847  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b848  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b849  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b84a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054b84b:
    // 0054b84b  8b1d1cdc5400           -mov ebx, dword ptr [0x54dc1c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5561372) /* 0x54dc1c */);
    // 0054b851  8d8a000000f0           -lea ecx, [edx - 0x10000000]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-268435456) /* -0x10000000 */);
    // 0054b857  81eb00000010           +sub ebx, 0x10000000
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0054b85d  890d18dc5400           -mov dword ptr [0x54dc18], ecx
    app->getMemory<x86::reg32>(x86::reg32(5561368) /* 0x54dc18 */) = cpu.ecx;
    // 0054b863  891d1cdc5400           -mov dword ptr [0x54dc1c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5561372) /* 0x54dc1c */) = cpu.ebx;
    // 0054b869  e93effffff             -jmp 0x54b7ac
    goto L_0x0054b7ac;
L_0x0054b86e:
    // 0054b86e  a340dc5400             -mov dword ptr [0x54dc40], eax
    app->getMemory<x86::reg32>(x86::reg32(5561408) /* 0x54dc40 */) = cpu.eax;
    // 0054b873  eb81                   -jmp 0x54b7f6
    goto L_0x0054b7f6;
L_0x0054b875:
    // 0054b875  a15cdc5400             -mov eax, dword ptr [0x54dc5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561436) /* 0x54dc5c */);
    // 0054b87a  a340dc5400             -mov dword ptr [0x54dc40], eax
    app->getMemory<x86::reg32>(x86::reg32(5561408) /* 0x54dc40 */) = cpu.eax;
    // 0054b87f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b880  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b881  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b882  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b883  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b884  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b885  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054b886:
    // 0054b886  833d18dc540000         +cmp dword ptr [0x54dc18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561368) /* 0x54dc18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b88d  74b5                   -je 0x54b844
    if (cpu.flags.zf)
    {
        goto L_0x0054b844;
    }
    // 0054b88f  8b1d30dc5400           -mov ebx, dword ptr [0x54dc30]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */);
    // 0054b895  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0054b897  891d30dc5400           -mov dword ptr [0x54dc30], ebx
    app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */) = cpu.ebx;
    // 0054b89d  8d730f                 -lea esi, [ebx + 0xf]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 0054b8a0  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0054b8a2  893530dc5400           -mov dword ptr [0x54dc30], esi
    app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */) = cpu.esi;
    // 0054b8a8  81e7f0ff0f00           -and edi, 0xffff0
    cpu.edi &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 0054b8ae  8b2d34dc5400           -mov ebp, dword ptr [0x54dc34]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5561396) /* 0x54dc34 */);
    // 0054b8b4  893d30dc5400           -mov dword ptr [0x54dc30], edi
    app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */) = cpu.edi;
    // 0054b8ba  39ef                   +cmp edi, ebp
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
    // 0054b8bc  7e06                   -jle 0x54b8c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0054b8c4;
    }
    // 0054b8be  892d30dc5400           -mov dword ptr [0x54dc30], ebp
    app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */) = cpu.ebp;
L_0x0054b8c4:
    // 0054b8c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0054b8c6  a344dc5400             -mov dword ptr [0x54dc44], eax
    app->getMemory<x86::reg32>(x86::reg32(5561412) /* 0x54dc44 */) = cpu.eax;
    // 0054b8cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b8cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b8cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b8ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b8cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b8d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b8d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_54b8d4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054b8d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054b8d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054b8d6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054b8d7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054b8d8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0054b8d9  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0054b8dc  803d12dc540000         +cmp byte ptr [0x54dc12], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561362) /* 0x54dc12 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054b8e3  7509                   -jne 0x54b8ee
    if (!cpu.flags.zf)
    {
        goto L_0x0054b8ee;
    }
L_0x0054b8e5:
    // 0054b8e5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0054b8e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b8e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b8ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b8eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b8ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054b8ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054b8ee:
    // 0054b8ee  a10cdc5400             -mov eax, dword ptr [0x54dc0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054b8f3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b8f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0054b8f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054b8f8  8b0d0cdc5400           -mov ecx, dword ptr [0x54dc0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054b8fe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054b8ff  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b902  f6042402               +test byte ptr [esp], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp) & 2 /*0x2*/));
    // 0054b906  0f85e4000000           -jne 0x54b9f0
    if (!cpu.flags.zf)
    {
        goto L_0x0054b9f0;
    }
    // 0054b90c  a10cdc5400             -mov eax, dword ptr [0x54dc0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054b911  6820dc5400             -push 0x54dc20
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561376 /*0x54dc20*/;
    cpu.esp -= 4;
    // 0054b916  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b918  6824dc5400             -push 0x54dc24
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561380 /*0x54dc24*/;
    cpu.esp -= 4;
    // 0054b91d  8b1d0cdc5400           -mov ebx, dword ptr [0x54dc0c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054b923  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054b924  ff5010                 -call dword ptr [eax + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054b927  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054b929  75ba                   -jne 0x54b8e5
    if (!cpu.flags.zf)
    {
        goto L_0x0054b8e5;
    }
    // 0054b92b  803d15dc540000         +cmp byte ptr [0x54dc15], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561365) /* 0x54dc15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054b932  740a                   -je 0x54b93e
    if (cpu.flags.zf)
    {
        goto L_0x0054b93e;
    }
    // 0054b934  a120dc5400             -mov eax, dword ptr [0x54dc20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561376) /* 0x54dc20 */);
    // 0054b939  a324dc5400             -mov dword ptr [0x54dc24], eax
    app->getMemory<x86::reg32>(x86::reg32(5561380) /* 0x54dc24 */) = cpu.eax;
L_0x0054b93e:
    // 0054b93e  0fbe0d14dc5400         -movsx ecx, byte ptr [0x54dc14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561364) /* 0x54dc14 */)));
    // 0054b945  d32d24dc5400           -shr dword ptr [0x54dc24], cl
    app->getMemory<x86::reg32>(x86::reg32(5561380) /* 0x54dc24 */) >>= cpu.cl % 32;
    // 0054b94b  812524dc5400f0ff0f00   -and dword ptr [0x54dc24], 0xffff0
    app->getMemory<x86::reg32>(x86::reg32(5561380) /* 0x54dc24 */) &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 0054b955  a124dc5400             -mov eax, dword ptr [0x54dc24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561380) /* 0x54dc24 */);
    // 0054b95a  3b0528dc5400           +cmp eax, dword ptr [0x54dc28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5561384) /* 0x54dc28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b960  0f82a4000000           -jb 0x54ba0a
    if (cpu.flags.cf)
    {
        goto L_0x0054ba0a;
    }
    // 0054b966  a124dc5400             -mov eax, dword ptr [0x54dc24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561380) /* 0x54dc24 */);
L_0x0054b96b:
    // 0054b96b  2b0528dc5400           -sub eax, dword ptr [0x54dc28]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5561384) /* 0x54dc28 */)));
    // 0054b971  01051cdc5400           -add dword ptr [0x54dc1c], eax
    (app->getMemory<x86::reg32>(x86::reg32(5561372) /* 0x54dc1c */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0054b977  a124dc5400             -mov eax, dword ptr [0x54dc24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561380) /* 0x54dc24 */);
    // 0054b97c  3b0528dc5400           +cmp eax, dword ptr [0x54dc28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5561384) /* 0x54dc28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b982  0f8592000000           -jne 0x54ba1a
    if (!cpu.flags.zf)
    {
        goto L_0x0054ba1a;
    }
    // 0054b988  8b157cdc5400           -mov edx, dword ptr [0x54dc7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561468) /* 0x54dc7c */);
    // 0054b98e  42                     -inc edx
    (cpu.edx)++;
    // 0054b98f  89157cdc5400           -mov dword ptr [0x54dc7c], edx
    app->getMemory<x86::reg32>(x86::reg32(5561468) /* 0x54dc7c */) = cpu.edx;
    // 0054b995  81faf4010000           +cmp edx, 0x1f4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b99b  0f8f85000000           -jg 0x54ba26
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0054ba26;
    }
L_0x0054b9a1:
    // 0054b9a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0054b9a2:
    // 0054b9a2  8b1d24dc5400           -mov ebx, dword ptr [0x54dc24]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5561380) /* 0x54dc24 */);
    // 0054b9a8  031d30dc5400           -add ebx, dword ptr [0x54dc30]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */)));
    // 0054b9ae  81e3f0ff0f00           -and ebx, 0xffff0
    cpu.ebx &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 0054b9b4  3b1d5cdc5400           +cmp ebx, dword ptr [0x54dc5c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5561436) /* 0x54dc5c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b9ba  7c06                   -jl 0x54b9c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0054b9c2;
    }
    // 0054b9bc  2b1d5cdc5400           -sub ebx, dword ptr [0x54dc5c]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5561436) /* 0x54dc5c */)));
L_0x0054b9c2:
    // 0054b9c2  3b1d2cdc5400           +cmp ebx, dword ptr [0x54dc2c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5561388) /* 0x54dc2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054b9c8  0f8c78000000           -jl 0x54ba46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0054ba46;
    }
    // 0054b9ce  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0054b9d0  2b352cdc5400           -sub esi, dword ptr [0x54dc2c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5561388) /* 0x54dc2c */)));
    // 0054b9d6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0054b9d8:
    // 0054b9d8  a15cdc5400             -mov eax, dword ptr [0x54dc5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561436) /* 0x54dc5c */);
    // 0054b9dd  83e810                 -sub eax, 0x10
    (cpu.eax) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0054b9e0  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0054b9e3  39c2                   +cmp edx, eax
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
    // 0054b9e5  7c71                   -jl 0x54ba58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0054ba58;
    }
    // 0054b9e7  830530dc540010         +add dword ptr [0x54dc30], 0x10
    {
        auto tmp1 = app->getMemory<x86::reg32>(x86::reg32(5561392) /* 0x54dc30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0054b9ee  ebb2                   -jmp 0x54b9a2
    goto L_0x0054b9a2;
L_0x0054b9f0:
    // 0054b9f0  a10cdc5400             -mov eax, dword ptr [0x54dc0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054b9f5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054b9f7  8b350cdc5400           -mov esi, dword ptr [0x54dc0c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054b9fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054b9fe  ff5050                 -call dword ptr [eax + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054ba01  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0054ba04  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054ba05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054ba06  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054ba07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054ba08  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054ba09  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054ba0a:
    // 0054ba0a  a124dc5400             -mov eax, dword ptr [0x54dc24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561380) /* 0x54dc24 */);
    // 0054ba0f  03055cdc5400           +add eax, dword ptr [0x54dc5c]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5561436) /* 0x54dc5c */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0054ba15  e951ffffff             -jmp 0x54b96b
    goto L_0x0054b96b;
L_0x0054ba1a:
    // 0054ba1a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0054ba1c  a37cdc5400             -mov dword ptr [0x54dc7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5561468) /* 0x54dc7c */) = cpu.eax;
    // 0054ba21  e97bffffff             -jmp 0x54b9a1
    goto L_0x0054b9a1;
L_0x0054ba26:
    // 0054ba26  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0054ba28  a10cdc5400             -mov eax, dword ptr [0x54dc0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054ba2d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054ba2f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054ba31  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054ba33  8b1d0cdc5400           -mov ebx, dword ptr [0x54dc0c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054ba39  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054ba3a  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054ba3d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0054ba40  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054ba41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054ba42  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054ba43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054ba44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054ba45  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054ba46:
    // 0054ba46  8b355cdc5400           -mov esi, dword ptr [0x54dc5c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5561436) /* 0x54dc5c */);
    // 0054ba4c  8b0d2cdc5400           -mov ecx, dword ptr [0x54dc2c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561388) /* 0x54dc2c */);
    // 0054ba52  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0054ba54  29ce                   +sub esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0054ba56  eb80                   -jmp 0x54b9d8
    goto L_0x0054b9d8;
L_0x0054ba58:
    // 0054ba58  803d15dc540000         +cmp byte ptr [0x54dc15], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5561365) /* 0x54dc15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054ba5f  7505                   -jne 0x54ba66
    if (!cpu.flags.zf)
    {
        goto L_0x0054ba66;
    }
    // 0054ba61  e82efdffff             -call 0x54b794
    cpu.esp -= 4;
    sub_54b794(app, cpu);
    if (cpu.terminate) return;
L_0x0054ba66:
    // 0054ba66  a124dc5400             -mov eax, dword ptr [0x54dc24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561380) /* 0x54dc24 */);
    // 0054ba6b  a328dc5400             -mov dword ptr [0x54dc28], eax
    app->getMemory<x86::reg32>(x86::reg32(5561384) /* 0x54dc28 */) = cpu.eax;
    // 0054ba70  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0054ba72  0f84ef000000           -je 0x54bb67
    if (cpu.flags.zf)
    {
        goto L_0x0054bb67;
    }
    // 0054ba78  013518dc5400           -add dword ptr [0x54dc18], esi
    (app->getMemory<x86::reg32>(x86::reg32(5561368) /* 0x54dc18 */)) += x86::reg32(x86::sreg32(cpu.esi));
    // 0054ba7e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054ba80  8b150cdc5400           -mov edx, dword ptr [0x54dc0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054ba86  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054ba88  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0054ba8a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054ba8c  0fbe0d14dc5400         -movsx ecx, byte ptr [0x54dc14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561364) /* 0x54dc14 */)));
    // 0054ba93  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0054ba95  6858dc5400             -push 0x54dc58
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561432 /*0x54dc58*/;
    cpu.esp -= 4;
    // 0054ba9a  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0054ba9c  6854dc5400             -push 0x54dc54
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561428 /*0x54dc54*/;
    cpu.esp -= 4;
    // 0054baa1  0fbe0d14dc5400         -movsx ecx, byte ptr [0x54dc14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561364) /* 0x54dc14 */)));
    // 0054baa8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054baa9  a12cdc5400             -mov eax, dword ptr [0x54dc2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561388) /* 0x54dc2c */);
    // 0054baae  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0054bab0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054bab1  a10cdc5400             -mov eax, dword ptr [0x54dc0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054bab6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054bab7  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054baba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054babc  7532                   -jne 0x54baf0
    if (!cpu.flags.zf)
    {
        goto L_0x0054baf0;
    }
    // 0054babe  a154dc5400             -mov eax, dword ptr [0x54dc54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561428) /* 0x54dc54 */);
    // 0054bac3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0054bac5  e806fcffff             -call 0x54b6d0
    cpu.esp -= 4;
    sub_54b6d0(app, cpu);
    if (cpu.terminate) return;
    // 0054baca  a10cdc5400             -mov eax, dword ptr [0x54dc0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054bacf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054bad1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054bad3  0fbe0d14dc5400         -movsx ecx, byte ptr [0x54dc14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561364) /* 0x54dc14 */)));
    // 0054bada  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054badc  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0054bade  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054badf  8b1554dc5400           -mov edx, dword ptr [0x54dc54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561428) /* 0x54dc54 */);
    // 0054bae5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054bae6  8b0d0cdc5400           -mov ecx, dword ptr [0x54dc0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054baec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054baed  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0054baf0:
    // 0054baf0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0054baf2  7473                   -je 0x54bb67
    if (cpu.flags.zf)
    {
        goto L_0x0054bb67;
    }
    // 0054baf4  8b3518dc5400           -mov esi, dword ptr [0x54dc18]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5561368) /* 0x54dc18 */);
    // 0054bafa  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0054bafc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054bafe  893518dc5400           -mov dword ptr [0x54dc18], esi
    app->getMemory<x86::reg32>(x86::reg32(5561368) /* 0x54dc18 */) = cpu.esi;
    // 0054bb04  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054bb06  a10cdc5400             -mov eax, dword ptr [0x54dc0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054bb0b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054bb0d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054bb0f  6858dc5400             -push 0x54dc58
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561432 /*0x54dc58*/;
    cpu.esp -= 4;
    // 0054bb14  0fbe0d14dc5400         -movsx ecx, byte ptr [0x54dc14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561364) /* 0x54dc14 */)));
    // 0054bb1b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0054bb1d  6854dc5400             -push 0x54dc54
    app->getMemory<x86::reg32>(cpu.esp-4) = 5561428 /*0x54dc54*/;
    cpu.esp -= 4;
    // 0054bb22  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0054bb24  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054bb25  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054bb27  8b2d0cdc5400           -mov ebp, dword ptr [0x54dc0c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054bb2d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0054bb2e  ff502c                 -call dword ptr [eax + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054bb31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054bb33  750c                   -jne 0x54bb41
    if (!cpu.flags.zf)
    {
        goto L_0x0054bb41;
    }
    // 0054bb35  a154dc5400             -mov eax, dword ptr [0x54dc54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561428) /* 0x54dc54 */);
    // 0054bb3a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0054bb3c  e88ffbffff             -call 0x54b6d0
    cpu.esp -= 4;
    sub_54b6d0(app, cpu);
    if (cpu.terminate) return;
L_0x0054bb41:
    // 0054bb41  a10cdc5400             -mov eax, dword ptr [0x54dc0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054bb46  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0054bb48  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054bb4a  0fbe0d14dc5400         -movsx ecx, byte ptr [0x54dc14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5561364) /* 0x54dc14 */)));
    // 0054bb51  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054bb53  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 0054bb55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0054bb56  8b1554dc5400           -mov edx, dword ptr [0x54dc54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5561428) /* 0x54dc54 */);
    // 0054bb5c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054bb5d  8b0d0cdc5400           -mov ecx, dword ptr [0x54dc0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5561356) /* 0x54dc0c */);
    // 0054bb63  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054bb64  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0054bb67:
    // 0054bb67  891d2cdc5400           -mov dword ptr [0x54dc2c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5561388) /* 0x54dc2c */) = cpu.ebx;
    // 0054bb6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054bb6e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0054bb71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054bb72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054bb73  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054bb74  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054bb75  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054bb76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_54bb77(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054bb77  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054bb78  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0054bb7a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054bb7b  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 0054bb7d  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0054bb80  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 0054bb82  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0054bb85  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 0054bb87  e804000000             -call 0x54bb90
    cpu.esp -= 4;
    sub_54bb90(app, cpu);
    if (cpu.terminate) return;
    // 0054bb8c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054bb8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054bb8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_54bb90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054bb90  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0054bb92  742c                   -je 0x54bbc0
    if (cpu.flags.zf)
    {
        goto L_0x0054bbc0;
    }
    // 0054bb94  3810                   -cmp byte ptr [eax], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x0054bb96:
    // 0054bb96  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 0054bb98  7409                   -je 0x54bba3
    if (cpu.flags.zf)
    {
        goto L_0x0054bba3;
    }
    // 0054bb9a  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0054bb9c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0054bb9d  c1ca08                 +ror edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 count = 8 /*0x8*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 0054bba0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bba1  75f3                   -jne 0x54bb96
    if (!cpu.flags.zf)
    {
        goto L_0x0054bb96;
    }
L_0x0054bba3:
    // 0054bba3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054bba4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0054bba7  e81b000000             -call 0x54bbc7
    cpu.esp -= 4;
    sub_54bbc7(app, cpu);
    if (cpu.terminate) return;
    // 0054bbac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054bbad  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0054bbb0  740e                   -je 0x54bbc0
    if (cpu.flags.zf)
    {
        goto L_0x0054bbc0;
    }
    // 0054bbb2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0054bbb4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bbb5  7409                   -je 0x54bbc0
    if (cpu.flags.zf)
    {
        goto L_0x0054bbc0;
    }
    // 0054bbb7  887001                 -mov byte ptr [eax + 1], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 0054bbba  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bbbb  7403                   -je 0x54bbc0
    if (cpu.flags.zf)
    {
        goto L_0x0054bbc0;
    }
    // 0054bbbd  885002                 -mov byte ptr [eax + 2], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x0054bbc0:
    // 0054bbc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_54bbc2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054bbc2  90                     -nop 
    ;
    // 0054bbc3  90                     -nop 
    ;
    // 0054bbc4  90                     -nop 
    ;
    // 0054bbc5  90                     -nop 
    ;
    // 0054bbc6  90                     -nop 
    ;
    // 0054bbc7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0054bbc9  7467                   -je 0x54bc32
    if (cpu.flags.zf)
    {
        goto L_0x0054bc32;
    }
L_0x0054bbcb:
    // 0054bbcb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 0054bbcd  7408                   -je 0x54bbd7
    if (cpu.flags.zf)
    {
        goto L_0x0054bbd7;
    }
    // 0054bbcf  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054bbd1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0054bbd4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bbd5  75f4                   -jne 0x54bbcb
    if (!cpu.flags.zf)
    {
        goto L_0x0054bbcb;
    }
L_0x0054bbd7:
    // 0054bbd7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054bbd8  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0054bbdb  743a                   -je 0x54bc17
    if (cpu.flags.zf)
    {
        goto L_0x0054bc17;
    }
    // 0054bbdd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bbde  7429                   -je 0x54bc09
    if (cpu.flags.zf)
    {
        goto L_0x0054bc09;
    }
L_0x0054bbe0:
    // 0054bbe0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054bbe2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0054bbe5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bbe6  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0054bbe9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0054bbec  7418                   -je 0x54bc06
    if (cpu.flags.zf)
    {
        goto L_0x0054bc06;
    }
    // 0054bbee  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054bbf1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0054bbf4  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0054bbf7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bbf8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0054bbfb  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0054bbfe  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0054bc01  75dd                   -jne 0x54bbe0
    if (!cpu.flags.zf)
    {
        goto L_0x0054bbe0;
    }
    // 0054bc03  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x0054bc06:
    // 0054bc06  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x0054bc09:
    // 0054bc09  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054bc0b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0054bc0e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0054bc11  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0054bc14  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x0054bc17:
    // 0054bc17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054bc18  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0054bc1b  7415                   -je 0x54bc32
    if (cpu.flags.zf)
    {
        goto L_0x0054bc32;
    }
    // 0054bc1d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054bc1f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0054bc22  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bc23  740d                   -je 0x54bc32
    if (cpu.flags.zf)
    {
        goto L_0x0054bc32;
    }
    // 0054bc25  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054bc27  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0054bc2a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bc2b  7405                   -je 0x54bc32
    if (cpu.flags.zf)
    {
        goto L_0x0054bc32;
    }
    // 0054bc2d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054bc2f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0054bc32:
    // 0054bc32  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_54bbc7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0054bbc7;
    // 0054bbc2  90                     -nop 
    ;
    // 0054bbc3  90                     -nop 
    ;
    // 0054bbc4  90                     -nop 
    ;
    // 0054bbc5  90                     -nop 
    ;
    // 0054bbc6  90                     -nop 
    ;
L_entry_0x0054bbc7:
    // 0054bbc7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0054bbc9  7467                   -je 0x54bc32
    if (cpu.flags.zf)
    {
        goto L_0x0054bc32;
    }
L_0x0054bbcb:
    // 0054bbcb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 0054bbcd  7408                   -je 0x54bbd7
    if (cpu.flags.zf)
    {
        goto L_0x0054bbd7;
    }
    // 0054bbcf  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054bbd1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0054bbd4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bbd5  75f4                   -jne 0x54bbcb
    if (!cpu.flags.zf)
    {
        goto L_0x0054bbcb;
    }
L_0x0054bbd7:
    // 0054bbd7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054bbd8  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0054bbdb  743a                   -je 0x54bc17
    if (cpu.flags.zf)
    {
        goto L_0x0054bc17;
    }
    // 0054bbdd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bbde  7429                   -je 0x54bc09
    if (cpu.flags.zf)
    {
        goto L_0x0054bc09;
    }
L_0x0054bbe0:
    // 0054bbe0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054bbe2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0054bbe5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bbe6  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0054bbe9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0054bbec  7418                   -je 0x54bc06
    if (cpu.flags.zf)
    {
        goto L_0x0054bc06;
    }
    // 0054bbee  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054bbf1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0054bbf4  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0054bbf7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bbf8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0054bbfb  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0054bbfe  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0054bc01  75dd                   -jne 0x54bbe0
    if (!cpu.flags.zf)
    {
        goto L_0x0054bbe0;
    }
    // 0054bc03  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x0054bc06:
    // 0054bc06  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x0054bc09:
    // 0054bc09  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054bc0b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0054bc0e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0054bc11  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0054bc14  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x0054bc17:
    // 0054bc17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054bc18  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0054bc1b  7415                   -je 0x54bc32
    if (cpu.flags.zf)
    {
        goto L_0x0054bc32;
    }
    // 0054bc1d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054bc1f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0054bc22  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bc23  740d                   -je 0x54bc32
    if (cpu.flags.zf)
    {
        goto L_0x0054bc32;
    }
    // 0054bc25  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054bc27  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0054bc2a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054bc2b  7405                   -je 0x54bc32
    if (cpu.flags.zf)
    {
        goto L_0x0054bc32;
    }
    // 0054bc2d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054bc2f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0054bc32:
    // 0054bc32  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_54bc34(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054bc34  ff2530ca5400           -jmp dword ptr [0x54ca30]
    return app->dynamic_call(app->getMemory<x86::reg32>(5556784), cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_54bc40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054bc40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc60  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc62  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc64  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc66  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc68  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc6a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc6c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc6e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc70  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc72  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc78  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc7c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc7e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc80  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc82  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc90  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc92  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc94  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc96  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc98  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc9a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc9c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bc9e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bca0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bca2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bca4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bca6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bca8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcaa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcb0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcb2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcb4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcb6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcb8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcbc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcbe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcc0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcc2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcc4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcc6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcc8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bccc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcd0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcd2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcd4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcd6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcd8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcdc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcde  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bce0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bce2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bce4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bce6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bce8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcf0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcf2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcf4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcf6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcf8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcfa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcfc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bcfe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd00  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd02  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd04  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd06  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd08  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd0a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd0c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd0e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd10  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd12  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd14  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd16  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd18  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd1a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd1c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd1e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd20  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd22  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd24  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd26  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd28  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd2a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd2c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd2e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd60  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd62  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd64  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd66  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd68  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd6a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd6c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd6e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd70  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd72  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd78  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd7c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd7e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd80  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd82  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd90  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd92  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd94  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd96  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd98  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd9a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd9c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bd9e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bda0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bda2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bda4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bda6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bda8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdaa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdb0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdb2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdb4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdb6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdb8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdbc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdbe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdc0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdc2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdc4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdc6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdc8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdcc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdd0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdd2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdd4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdd6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdd8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bddc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdde  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bde0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bde2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bde4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bde6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bde8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdf0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdf2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdf4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdf6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdf8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdfa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdfc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054bdfe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
}

}
