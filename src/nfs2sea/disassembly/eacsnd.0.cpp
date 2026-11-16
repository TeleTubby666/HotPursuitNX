#include "eacsnd.h"
#include <lib/thread.h>

namespace eacsnd
{

/* align: skip  */
void sub_5bba00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bba00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bba01  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 005bba06  b802000600             -mov eax, 0x60002
    cpu.eax = 393218 /*0x60002*/;
    // 005bba0b  891560ec5b00           -mov dword ptr [0x5bec60], edx
    app->getMemory<x86::reg32>(x86::reg32(6024288) /* 0x5bec60 */) = cpu.edx;
    // 005bba11  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bba12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_5bba14(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bba14  a368ec5b00             -mov dword ptr [0x5bec68], eax
    app->getMemory<x86::reg32>(x86::reg32(6024296) /* 0x5bec68 */) = cpu.eax;
    // 005bba19  89156cec5b00           -mov dword ptr [0x5bec6c], edx
    app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */) = cpu.edx;
    // 005bba1f  891d70ec5b00           -mov dword ptr [0x5bec70], ebx
    app->getMemory<x86::reg32>(x86::reg32(6024304) /* 0x5bec70 */) = cpu.ebx;
    // 005bba25  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005bba29  890d74ec5b00           -mov dword ptr [0x5bec74], ecx
    app->getMemory<x86::reg32>(x86::reg32(6024308) /* 0x5bec74 */) = cpu.ecx;
    // 005bba2f  a378ec5b00             -mov dword ptr [0x5bec78], eax
    app->getMemory<x86::reg32>(x86::reg32(6024312) /* 0x5bec78 */) = cpu.eax;
    // 005bba34  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005bba36  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_5bba3c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bba3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bba3d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bba3e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005bba3f  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 005bba45  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005bba47  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005bba49  89942488000000         -mov dword ptr [esp + 0x88], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.edx;
    // 005bba50  833d60ec5b0000         +cmp dword ptr [0x5bec60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024288) /* 0x5bec60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bba57  7c0f                   -jl 0x5bba68
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005bba68;
    }
    // 005bba59  a160ec5b00             -mov eax, dword ptr [0x5bec60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024288) /* 0x5bec60 */);
    // 005bba5e  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 005bba64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bba65  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bba66  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bba67  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005bba68:
    // 005bba68  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005bba69  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bba6a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bba6b  803d10ec5b0000         +cmp byte ptr [0x5bec10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024208) /* 0x5bec10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bba72  7475                   -je 0x5bbae9
    if (cpu.flags.zf)
    {
        goto L_0x005bbae9;
    }
L_0x005bba74:
    // 005bba74  c744240c60000000       -mov dword ptr [esp + 0xc], 0x60
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 96 /*0x60*/;
    // 005bba7c  a100ec5b00             -mov eax, dword ptr [0x5bec00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bba81  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005bba83  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005bba87  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bba88  8b3d00ec5b00           -mov edi, dword ptr [0x5bec00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bba8e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005bba8f  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bba92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bba94  0f848b000000           -je 0x5bbb25
    if (cpu.flags.zf)
    {
        goto L_0x005bbb25;
    }
L_0x005bba9a:
    // 005bba9a  c7842494000000ffffffff -mov dword ptr [esp + 0x94], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967295 /*0xffffffff*/;
L_0x005bbaa5:
    // 005bbaa5  803d10ec5b0000         +cmp byte ptr [0x5bec10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024208) /* 0x5bec10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bbaac  7522                   -jne 0x5bbad0
    if (!cpu.flags.zf)
    {
        goto L_0x005bbad0;
    }
    // 005bbaae  833d00ec5b0000         +cmp dword ptr [0x5bec00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bbab5  7411                   -je 0x5bbac8
    if (cpu.flags.zf)
    {
        goto L_0x005bbac8;
    }
    // 005bbab7  a100ec5b00             -mov eax, dword ptr [0x5bec00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bbabc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bbabe  8b1500ec5b00           -mov edx, dword ptr [0x5bec00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bbac4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bbac5  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005bbac8:
    // 005bbac8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005bbaca  890d00ec5b00           -mov dword ptr [0x5bec00], ecx
    app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */) = cpu.ecx;
L_0x005bbad0:
    // 005bbad0  8b842494000000         -mov eax, dword ptr [esp + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 005bbad7  a360ec5b00             -mov dword ptr [0x5bec60], eax
    app->getMemory<x86::reg32>(x86::reg32(6024288) /* 0x5bec60 */) = cpu.eax;
    // 005bbadc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bbadd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bbade  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bbadf  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 005bbae5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bbae6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bbae7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bbae8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005bbae9:
    // 005bbae9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bbaea  6800ec5b00             -push 0x5bec00
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024192 /*0x5bec00*/;
    cpu.esp -= 4;
    // 005bbaef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bbaf0  e83f110000             -call 0x5bcc34
    cpu.esp -= 4;
    sub_5bcc34(app, cpu);
    if (cpu.terminate) return;
    // 005bbaf5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bbaf7  0f8477ffffff           -je 0x5bba74
    if (cpu.flags.zf)
    {
        goto L_0x005bba74;
    }
    // 005bbafd  3d0a007888             +cmp eax, 0x8878000a
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
    // 005bbb02  7414                   -je 0x5bbb18
    if (cpu.flags.zf)
    {
        goto L_0x005bbb18;
    }
    // 005bbb04  3d78007888             +cmp eax, 0x88780078
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
    // 005bbb09  758f                   -jne 0x5bba9a
    if (!cpu.flags.zf)
    {
        goto L_0x005bba9a;
    }
    // 005bbb0b  c7842494000000f6ffffff -mov dword ptr [esp + 0x94], 0xfffffff6
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967286 /*0xfffffff6*/;
    // 005bbb16  eb8d                   -jmp 0x5bbaa5
    goto L_0x005bbaa5;
L_0x005bbb18:
    // 005bbb18  c7842494000000eeffffff -mov dword ptr [esp + 0x94], 0xffffffee
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967278 /*0xffffffee*/;
    // 005bbb23  eb80                   -jmp 0x5bbaa5
    goto L_0x005bbaa5;
L_0x005bbb25:
    // 005bbb25  f644241020             +test byte ptr [esp + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 32 /*0x20*/));
    // 005bbb2a  0f84c2000000           -je 0x5bbbf2
    if (cpu.flags.zf)
    {
        goto L_0x005bbbf2;
    }
    // 005bbb30  c60515ec5b0001         -mov byte ptr [0x5bec15], 1
    app->getMemory<x86::reg8>(x86::reg32(6024213) /* 0x5bec15 */) = 1 /*0x1*/;
L_0x005bbb37:
    // 005bbb37  8aac2496000000         -mov ch, byte ptr [esp + 0x96]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(150) /* 0x96 */);
    // 005bbb3e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 005bbb43  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005bbb47  80cd02                 -or ch, 2
    cpu.ch |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 005bbb4a  6689942482000000       -mov word ptr [esp + 0x82], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */) = cpu.dx;
    // 005bbb52  88ac2496000000         -mov byte ptr [esp + 0x96], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(150) /* 0x96 */) = cpu.ch;
    // 005bbb59  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 005bbb5e  83e005                 -and eax, 5
    cpu.eax &= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 005bbb61  66898c248e000000       -mov word ptr [esp + 0x8e], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */) = cpu.cx;
    // 005bbb69  83f805                 +cmp eax, 5
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
    // 005bbb6c  7508                   -jne 0x5bbb76
    if (!cpu.flags.zf)
    {
        goto L_0x005bbb76;
    }
    // 005bbb6e  808c249400000001       -or byte ptr [esp + 0x94], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x005bbb76:
    // 005bbb76  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005bbb7a  83e006                 -and eax, 6
    cpu.eax &= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 005bbb7d  83f806                 +cmp eax, 6
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
    // 005bbb80  7508                   -jne 0x5bbb8a
    if (!cpu.flags.zf)
    {
        goto L_0x005bbb8a;
    }
    // 005bbb82  808c249400000002       -or byte ptr [esp + 0x94], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x005bbb8a:
    // 005bbb8a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005bbb8e  83e009                 -and eax, 9
    cpu.eax &= x86::reg32(x86::sreg32(9 /*0x9*/));
    // 005bbb91  83f809                 +cmp eax, 9
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
    // 005bbb94  7508                   -jne 0x5bbb9e
    if (!cpu.flags.zf)
    {
        goto L_0x005bbb9e;
    }
    // 005bbb96  808c249400000004       -or byte ptr [esp + 0x94], 4
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x005bbb9e:
    // 005bbb9e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005bbba2  83e00a                 -and eax, 0xa
    cpu.eax &= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 005bbba5  83f80a                 +cmp eax, 0xa
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
    // 005bbba8  752b                   -jne 0x5bbbd5
    if (!cpu.flags.zf)
    {
        goto L_0x005bbbd5;
    }
    // 005bbbaa  8ab42494000000         -mov dh, byte ptr [esp + 0x94]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 005bbbb1  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 005bbbb6  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
    // 005bbbbb  80ce08                 -or dh, 8
    cpu.dh |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 005bbbbe  6689b42482000000       -mov word ptr [esp + 0x82], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */) = cpu.si;
    // 005bbbc6  6689bc248e000000       -mov word ptr [esp + 0x8e], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */) = cpu.di;
    // 005bbbce  88b42494000000         -mov byte ptr [esp + 0x94], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.dh;
L_0x005bbbd5:
    // 005bbbd5  a100ec5b00             -mov eax, dword ptr [0x5bec00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bbbda  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 005bbbdc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bbbde  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bbbdf  8b2d00ec5b00           -mov ebp, dword ptr [0x5bec00]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bbbe5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005bbbe6  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bbbe9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bbbeb  7412                   -je 0x5bbbff
    if (cpu.flags.zf)
    {
        goto L_0x005bbbff;
    }
    // 005bbbed  e9a8feffff             -jmp 0x5bba9a
    goto L_0x005bba9a;
L_0x005bbbf2:
    // 005bbbf2  30f6                   +xor dh, dh
    cpu.clear_co();
    cpu.set_szp((cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh))));
    // 005bbbf4  883515ec5b00           -mov byte ptr [0x5bec15], dh
    app->getMemory<x86::reg8>(x86::reg32(6024213) /* 0x5bec15 */) = cpu.dh;
    // 005bbbfa  e938ffffff             -jmp 0x5bbb37
    goto L_0x005bbb37;
L_0x005bbbff:
    // 005bbbff  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 005bbc04  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 005bbc08  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005bbc0a  e8680f0000             -call 0x5bcb77
    cpu.esp -= 4;
    sub_5bcb77(app, cpu);
    if (cpu.terminate) return;
    // 005bbc0f  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 005bbc14  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 005bbc19  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 005bbc1d  89542470               -mov dword ptr [esp + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 005bbc21  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bbc23  8b1500ec5b00           -mov edx, dword ptr [0x5bec00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bbc29  6804ec5b00             -push 0x5bec04
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024196 /*0x5bec04*/;
    cpu.esp -= 4;
    // 005bbc2e  8d442474               -lea eax, [esp + 0x74]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 005bbc32  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 005bbc34  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bbc35  8b0d00ec5b00           -mov ecx, dword ptr [0x5bec00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bbc3b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bbc3c  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bbc3f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bbc41  0f8553feffff           -jne 0x5bba9a
    if (!cpu.flags.zf)
    {
        goto L_0x005bba9a;
    }
    // 005bbc47  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005bbc4c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005bbc4e  6689842480000000       -mov word ptr [esp + 0x80], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.ax;
    // 005bbc56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005bbc58  668b942482000000       -mov dx, word ptr [esp + 0x82]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
    // 005bbc60  668b84248e000000       -mov ax, word ptr [esp + 0x8e]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
    // 005bbc68  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 005bbc6b  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 005bbc6e  668984248c000000       -mov word ptr [esp + 0x8c], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.ax;
    // 005bbc76  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005bbc78  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 005bbc80  69c0112b0000           -imul eax, eax, 0x2b11
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(11025 /*0x2b11*/)));
    // 005bbc86  bb112b0000             -mov ebx, 0x2b11
    cpu.ebx = 11025 /*0x2b11*/;
    // 005bbc8b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005bbc8d  899c2484000000         -mov dword ptr [esp + 0x84], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 005bbc94  6689942490000000       -mov word ptr [esp + 0x90], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.dx;
    // 005bbc9c  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 005bbca3  a104ec5b00             -mov eax, dword ptr [0x5bec04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bbca8  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005bbcaa  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005bbcb1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bbcb2  8b3504ec5b00           -mov esi, dword ptr [0x5bec04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bbcb8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bbcb9  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bbcbc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bbcbe  7508                   -jne 0x5bbcc8
    if (!cpu.flags.zf)
    {
        goto L_0x005bbcc8;
    }
    // 005bbcc0  808c249500000002       -or byte ptr [esp + 0x95], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x005bbcc8:
    // 005bbcc8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005bbcca  668b94248c000000       -mov dx, word ptr [esp + 0x8c]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 005bbcd2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 005bbcd9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005bbcdb  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 005bbcde  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005bbce0  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 005bbce3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005bbce5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 005bbce8  bf803e0000             -mov edi, 0x3e80
    cpu.edi = 16000 /*0x3e80*/;
    // 005bbced  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005bbcef  89bc2484000000         -mov dword ptr [esp + 0x84], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 005bbcf6  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 005bbcfd  a104ec5b00             -mov eax, dword ptr [0x5bec04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bbd02  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005bbd04  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005bbd0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bbd0c  8b2d04ec5b00           -mov ebp, dword ptr [0x5bec04]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bbd12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005bbd13  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bbd16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bbd18  7508                   -jne 0x5bbd22
    if (!cpu.flags.zf)
    {
        goto L_0x005bbd22;
    }
    // 005bbd1a  808c249500000004       -or byte ptr [esp + 0x95], 4
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x005bbd22:
    // 005bbd22  c784248400000022560000 -mov dword ptr [esp + 0x84], 0x5622
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = 22050 /*0x5622*/;
    // 005bbd2d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005bbd2f  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 005bbd37  69c022560000           -imul eax, eax, 0x5622
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(22050 /*0x5622*/)));
    // 005bbd3d  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 005bbd44  8b1504ec5b00           -mov edx, dword ptr [0x5bec04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bbd4a  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005bbd51  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 005bbd53  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bbd54  8b0d04ec5b00           -mov ecx, dword ptr [0x5bec04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bbd5a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bbd5b  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bbd5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bbd60  7508                   -jne 0x5bbd6a
    if (!cpu.flags.zf)
    {
        goto L_0x005bbd6a;
    }
    // 005bbd62  808c249500000008       -or byte ptr [esp + 0x95], 8
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x005bbd6a:
    // 005bbd6a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005bbd6c  668b94248c000000       -mov dx, word ptr [esp + 0x8c]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 005bbd74  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 005bbd7b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005bbd7d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 005bbd80  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005bbd82  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 005bbd85  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005bbd87  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 005bbd8a  bb007d0000             -mov ebx, 0x7d00
    cpu.ebx = 32000 /*0x7d00*/;
    // 005bbd8f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005bbd91  899c2484000000         -mov dword ptr [esp + 0x84], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 005bbd98  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 005bbd9f  8b1504ec5b00           -mov edx, dword ptr [0x5bec04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bbda5  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005bbdac  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 005bbdae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bbdaf  8b3504ec5b00           -mov esi, dword ptr [0x5bec04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bbdb5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bbdb6  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bbdb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bbdbb  7508                   -jne 0x5bbdc5
    if (!cpu.flags.zf)
    {
        goto L_0x005bbdc5;
    }
    // 005bbdbd  808c249500000010       -or byte ptr [esp + 0x95], 0x10
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x005bbdc5:
    // 005bbdc5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005bbdc7  bf44ac0000             -mov edi, 0xac44
    cpu.edi = 44100 /*0xac44*/;
    // 005bbdcc  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 005bbdd4  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 005bbdd7  89bc2484000000         -mov dword ptr [esp + 0x84], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 005bbdde  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 005bbde5  a104ec5b00             -mov eax, dword ptr [0x5bec04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bbdea  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005bbdec  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005bbdf3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bbdf4  8b2d04ec5b00           -mov ebp, dword ptr [0x5bec04]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bbdfa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005bbdfb  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bbdfe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bbe00  7508                   -jne 0x5bbe0a
    if (!cpu.flags.zf)
    {
        goto L_0x005bbe0a;
    }
    // 005bbe02  808c249500000020       -or byte ptr [esp + 0x95], 0x20
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x005bbe0a:
    // 005bbe0a  f68424940000000f       +test byte ptr [esp + 0x94], 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) & 15 /*0xf*/));
    // 005bbe12  7571                   -jne 0x5bbe85
    if (!cpu.flags.zf)
    {
        goto L_0x005bbe85;
    }
L_0x005bbe14:
    // 005bbe14  c7842494000000ffffffff -mov dword ptr [esp + 0x94], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967295 /*0xffffffff*/;
L_0x005bbe1f:
    // 005bbe1f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bbe21  a104ec5b00             -mov eax, dword ptr [0x5bec04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bbe26  6a12                   -push 0x12
    app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 005bbe28  8d942488000000         -lea edx, [esp + 0x88]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 005bbe2f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bbe31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bbe32  8b1d04ec5b00           -mov ebx, dword ptr [0x5bec04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bbe38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bbe39  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bbe3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bbe3e  0f8561fcffff           -jne 0x5bbaa5
    if (!cpu.flags.zf)
    {
        goto L_0x005bbaa5;
    }
    // 005bbe44  6683bc248200000001     +cmp word ptr [esp + 0x82], 1
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
    // 005bbe4d  754f                   -jne 0x5bbe9e
    if (!cpu.flags.zf)
    {
        goto L_0x005bbe9e;
    }
    // 005bbe4f  6683bc248e00000008     +cmp word ptr [esp + 0x8e], 8
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
    // 005bbe58  7544                   -jne 0x5bbe9e
    if (!cpu.flags.zf)
    {
        goto L_0x005bbe9e;
    }
    // 005bbe5a  c784249400000001000000 -mov dword ptr [esp + 0x94], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 1 /*0x1*/;
L_0x005bbe65:
    // 005bbe65  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 005bbe6c  81f9112b0000           +cmp ecx, 0x2b11
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
    // 005bbe72  0f859a000000           -jne 0x5bbf12
    if (!cpu.flags.zf)
    {
        goto L_0x005bbf12;
    }
    // 005bbe78  808c249500000002       +or byte ptr [esp + 0x95], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 005bbe80  e920fcffff             -jmp 0x5bbaa5
    goto L_0x005bbaa5;
L_0x005bbe85:
    // 005bbe85  f68424950000003e       +test byte ptr [esp + 0x95], 0x3e
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) & 62 /*0x3e*/));
    // 005bbe8d  7485                   -je 0x5bbe14
    if (cpu.flags.zf)
    {
        goto L_0x005bbe14;
    }
    // 005bbe8f  83bc249400000000       +cmp dword ptr [esp + 0x94], 0
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
    // 005bbe97  7e86                   -jle 0x5bbe1f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005bbe1f;
    }
    // 005bbe99  e907fcffff             -jmp 0x5bbaa5
    goto L_0x005bbaa5;
L_0x005bbe9e:
    // 005bbe9e  6683bc248200000002     +cmp word ptr [esp + 0x82], 2
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
    // 005bbea7  7518                   -jne 0x5bbec1
    if (!cpu.flags.zf)
    {
        goto L_0x005bbec1;
    }
    // 005bbea9  6683bc248e00000008     +cmp word ptr [esp + 0x8e], 8
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
    // 005bbeb2  750d                   -jne 0x5bbec1
    if (!cpu.flags.zf)
    {
        goto L_0x005bbec1;
    }
    // 005bbeb4  c784249400000002000000 -mov dword ptr [esp + 0x94], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 2 /*0x2*/;
    // 005bbebf  eba4                   -jmp 0x5bbe65
    goto L_0x005bbe65;
L_0x005bbec1:
    // 005bbec1  6683bc248200000001     +cmp word ptr [esp + 0x82], 1
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
    // 005bbeca  7518                   -jne 0x5bbee4
    if (!cpu.flags.zf)
    {
        goto L_0x005bbee4;
    }
    // 005bbecc  6683bc248e00000010     +cmp word ptr [esp + 0x8e], 0x10
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
    // 005bbed5  750d                   -jne 0x5bbee4
    if (!cpu.flags.zf)
    {
        goto L_0x005bbee4;
    }
    // 005bbed7  c784249400000004000000 -mov dword ptr [esp + 0x94], 4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4 /*0x4*/;
    // 005bbee2  eb81                   -jmp 0x5bbe65
    goto L_0x005bbe65;
L_0x005bbee4:
    // 005bbee4  6683bc248200000002     +cmp word ptr [esp + 0x82], 2
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
    // 005bbeed  0f85a7fbffff           -jne 0x5bba9a
    if (!cpu.flags.zf)
    {
        goto L_0x005bba9a;
    }
    // 005bbef3  6683bc248e00000010     +cmp word ptr [esp + 0x8e], 0x10
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
    // 005bbefc  0f8598fbffff           -jne 0x5bba9a
    if (!cpu.flags.zf)
    {
        goto L_0x005bba9a;
    }
    // 005bbf02  c784249400000008000000 -mov dword ptr [esp + 0x94], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 8 /*0x8*/;
    // 005bbf0d  e953ffffff             -jmp 0x5bbe65
    goto L_0x005bbe65;
L_0x005bbf12:
    // 005bbf12  81f9803e0000           +cmp ecx, 0x3e80
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
    // 005bbf18  750d                   -jne 0x5bbf27
    if (!cpu.flags.zf)
    {
        goto L_0x005bbf27;
    }
    // 005bbf1a  808c249500000004       +or byte ptr [esp + 0x95], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 005bbf22  e97efbffff             -jmp 0x5bbaa5
    goto L_0x005bbaa5;
L_0x005bbf27:
    // 005bbf27  81f922560000           +cmp ecx, 0x5622
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
    // 005bbf2d  750d                   -jne 0x5bbf3c
    if (!cpu.flags.zf)
    {
        goto L_0x005bbf3c;
    }
    // 005bbf2f  808c249500000008       +or byte ptr [esp + 0x95], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 005bbf37  e969fbffff             -jmp 0x5bbaa5
    goto L_0x005bbaa5;
L_0x005bbf3c:
    // 005bbf3c  81f9007d0000           +cmp ecx, 0x7d00
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
    // 005bbf42  750d                   -jne 0x5bbf51
    if (!cpu.flags.zf)
    {
        goto L_0x005bbf51;
    }
    // 005bbf44  808c249500000010       +or byte ptr [esp + 0x95], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 005bbf4c  e954fbffff             -jmp 0x5bbaa5
    goto L_0x005bbaa5;
L_0x005bbf51:
    // 005bbf51  81f944ac0000           +cmp ecx, 0xac44
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
    // 005bbf57  0f853dfbffff           -jne 0x5bba9a
    if (!cpu.flags.zf)
    {
        goto L_0x005bba9a;
    }
    // 005bbf5d  808c249500000020       +or byte ptr [esp + 0x95], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 005bbf65  e93bfbffff             -jmp 0x5bbaa5
    goto L_0x005bbaa5;
}

/* align: skip 0x8b 0xc0 */
void sub_5bbf6c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bbf6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bbf6d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bbf6e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005bbf6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005bbf70  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 005bbf73  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 005bbf77  895c243c               -mov dword ptr [esp + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 005bbf7b  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 005bbf80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bbf82  0f8499010000           -je 0x5bc121
    if (cpu.flags.zf)
    {
        goto L_0x005bc121;
    }
    // 005bbf88  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
L_0x005bbf8d:
    // 005bbf8d  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 005bbf90  0f8495010000           -je 0x5bc12b
    if (cpu.flags.zf)
    {
        goto L_0x005bc12b;
    }
    // 005bbf96  c70564ec5b0022560000   -mov dword ptr [0x5bec64], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(6024292) /* 0x5bec64 */) = 22050 /*0x5622*/;
L_0x005bbfa0:
    // 005bbfa0  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 005bbfa3  0f84e9010000           -je 0x5bc192
    if (cpu.flags.zf)
    {
        goto L_0x005bc192;
    }
    // 005bbfa9  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x005bbfae:
    // 005bbfae  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
L_0x005bbfb3:
    // 005bbfb3  803d15ec5b0000         +cmp byte ptr [0x5bec15], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024213) /* 0x5bec15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bbfba  0f8420020000           -je 0x5bc1e0
    if (cpu.flags.zf)
    {
        goto L_0x005bc1e0;
    }
    // 005bbfc0  c70530ec5b0000200000   -mov dword ptr [0x5bec30], 0x2000
    app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */) = 8192 /*0x2000*/;
    // 005bbfca  83ff08                 +cmp edi, 8
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
    // 005bbfcd  750c                   -jne 0x5bbfdb
    if (!cpu.flags.zf)
    {
        goto L_0x005bbfdb;
    }
    // 005bbfcf  a130ec5b00             -mov eax, dword ptr [0x5bec30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */);
    // 005bbfd4  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005bbfd6  a330ec5b00             -mov dword ptr [0x5bec30], eax
    app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */) = cpu.eax;
L_0x005bbfdb:
    // 005bbfdb  83fe01                 +cmp esi, 1
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
    // 005bbfde  750e                   -jne 0x5bbfee
    if (!cpu.flags.zf)
    {
        goto L_0x005bbfee;
    }
    // 005bbfe0  8b1530ec5b00           -mov edx, dword ptr [0x5bec30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */);
    // 005bbfe6  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 005bbfe8  891530ec5b00           -mov dword ptr [0x5bec30], edx
    app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */) = cpu.edx;
L_0x005bbfee:
    // 005bbfee  812530ec5b00f0ff0f00   -and dword ptr [0x5bec30], 0xffff0
    app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */) &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005bbff8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005bbffa  a338ec5b00             -mov dword ptr [0x5bec38], eax
    app->getMemory<x86::reg32>(x86::reg32(6024248) /* 0x5bec38 */) = cpu.eax;
    // 005bbfff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005bc001  a32cec5b00             -mov dword ptr [0x5bec2c], eax
    app->getMemory<x86::reg32>(x86::reg32(6024236) /* 0x5bec2c */) = cpu.eax;
    // 005bc006  a324ec5b00             -mov dword ptr [0x5bec24], eax
    app->getMemory<x86::reg32>(x86::reg32(6024228) /* 0x5bec24 */) = cpu.eax;
    // 005bc00b  a328ec5b00             -mov dword ptr [0x5bec28], eax
    app->getMemory<x86::reg32>(x86::reg32(6024232) /* 0x5bec28 */) = cpu.eax;
    // 005bc010  a338ec5b00             -mov dword ptr [0x5bec38], eax
    app->getMemory<x86::reg32>(x86::reg32(6024248) /* 0x5bec38 */) = cpu.eax;
    // 005bc015  a318ec5b00             -mov dword ptr [0x5bec18], eax
    app->getMemory<x86::reg32>(x86::reg32(6024216) /* 0x5bec18 */) = cpu.eax;
    // 005bc01a  a344ec5b00             -mov dword ptr [0x5bec44], eax
    app->getMemory<x86::reg32>(x86::reg32(6024260) /* 0x5bec44 */) = cpu.eax;
    // 005bc01f  b932000000             -mov ecx, 0x32
    cpu.ecx = 50 /*0x32*/;
    // 005bc024  a164ec5b00             -mov eax, dword ptr [0x5bec64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024292) /* 0x5bec64 */);
    // 005bc029  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 005bc02b  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005bc030  a31cec5b00             -mov dword ptr [0x5bec1c], eax
    app->getMemory<x86::reg32>(x86::reg32(6024220) /* 0x5bec1c */) = cpu.eax;
    // 005bc035  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005bc037  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 005bc03a  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 005bc03d  a213ec5b00             -mov byte ptr [0x5bec13], al
    app->getMemory<x86::reg8>(x86::reg32(6024211) /* 0x5bec13 */) = cpu.al;
    // 005bc042  0fbe0513ec5b00         -movsx eax, byte ptr [0x5bec13]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024211) /* 0x5bec13 */)));
    // 005bc049  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 005bc04b  a214ec5b00             -mov byte ptr [0x5bec14], al
    app->getMemory<x86::reg8>(x86::reg32(6024212) /* 0x5bec14 */) = cpu.al;
    // 005bc050  803d10ec5b0000         +cmp byte ptr [0x5bec10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024208) /* 0x5bec10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bc057  751d                   -jne 0x5bc076
    if (!cpu.flags.zf)
    {
        goto L_0x005bc076;
    }
    // 005bc059  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bc05b  6800ec5b00             -push 0x5bec00
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024192 /*0x5bec00*/;
    cpu.esp -= 4;
    // 005bc060  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bc062  e8cd0b0000             -call 0x5bcc34
    cpu.esp -= 4;
    sub_5bcc34(app, cpu);
    if (cpu.terminate) return;
    // 005bc067  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc069  0f859a010000           -jne 0x5bc209
    if (!cpu.flags.zf)
    {
        goto L_0x005bc209;
    }
    // 005bc06f  c60510ec5b0001         -mov byte ptr [0x5bec10], 1
    app->getMemory<x86::reg8>(x86::reg32(6024208) /* 0x5bec10 */) = 1 /*0x1*/;
L_0x005bc076:
    // 005bc076  a100ec5b00             -mov eax, dword ptr [0x5bec00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bc07b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bc07c  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 005bc080  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc082  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bc083  8b0d00ec5b00           -mov ecx, dword ptr [0x5bec00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bc089  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bc08a  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc08d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc08f  0f84a0010000           -je 0x5bc235
    if (cpu.flags.zf)
    {
        goto L_0x005bc235;
    }
    // 005bc095  833d6cec5b0000         +cmp dword ptr [0x5bec6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc09c  740e                   -je 0x5bc0ac
    if (cpu.flags.zf)
    {
        goto L_0x005bc0ac;
    }
    // 005bc09e  685cea5b00             -push 0x5bea5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 6023772 /*0x5bea5c*/;
    cpu.esp -= 4;
L_0x005bc0a3:
    // 005bc0a3  ff156cec5b00           -call dword ptr [0x5bec6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc0a9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005bc0ac:
    // 005bc0ac  803d12ec5b0000         +cmp byte ptr [0x5bec12], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024210) /* 0x5bec12 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bc0b3  7434                   -je 0x5bc0e9
    if (cpu.flags.zf)
    {
        goto L_0x005bc0e9;
    }
    // 005bc0b5  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 005bc0b7  881512ec5b00           -mov byte ptr [0x5bec12], dl
    app->getMemory<x86::reg8>(x86::reg32(6024210) /* 0x5bec12 */) = cpu.dl;
    // 005bc0bd  a104ec5b00             -mov eax, dword ptr [0x5bec04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bc0c2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc0c4  8b3504ec5b00           -mov esi, dword ptr [0x5bec04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bc0ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bc0cb  ff5048                 -call dword ptr [eax + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc0ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc0d0  7417                   -je 0x5bc0e9
    if (cpu.flags.zf)
    {
        goto L_0x005bc0e9;
    }
    // 005bc0d2  833d6cec5b0000         +cmp dword ptr [0x5bec6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc0d9  740e                   -je 0x5bc0e9
    if (cpu.flags.zf)
    {
        goto L_0x005bc0e9;
    }
    // 005bc0db  68a0eb5b00             -push 0x5beba0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024096 /*0x5beba0*/;
    cpu.esp -= 4;
    // 005bc0e0  ff156cec5b00           -call dword ptr [0x5bec6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc0e6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005bc0e9:
    // 005bc0e9  803d10ec5b0000         +cmp byte ptr [0x5bec10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024208) /* 0x5bec10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bc0f0  7425                   -je 0x5bc117
    if (cpu.flags.zf)
    {
        goto L_0x005bc117;
    }
    // 005bc0f2  833d00ec5b0000         +cmp dword ptr [0x5bec00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc0f9  0f859e040000           -jne 0x5bc59d
    if (!cpu.flags.zf)
    {
        goto L_0x005bc59d;
    }
L_0x005bc0ff:
    // 005bc0ff  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005bc101  890d00ec5b00           -mov dword ptr [0x5bec00], ecx
    app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */) = cpu.ecx;
    // 005bc107  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 005bc109  881d11ec5b00           -mov byte ptr [0x5bec11], bl
    app->getMemory<x86::reg8>(x86::reg32(6024209) /* 0x5bec11 */) = cpu.bl;
    // 005bc10f  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 005bc111  883d10ec5b00           -mov byte ptr [0x5bec10], bh
    app->getMemory<x86::reg8>(x86::reg32(6024208) /* 0x5bec10 */) = cpu.bh;
L_0x005bc117:
    // 005bc117  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005bc119  83c444                 +add esp, 0x44
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
    // 005bc11c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc11d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc11e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc11f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc120  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005bc121:
    // 005bc121  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 005bc126  e962feffff             -jmp 0x5bbf8d
    goto L_0x005bbf8d;
L_0x005bc12b:
    // 005bc12b  f6c604                 +test dh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 4 /*0x4*/));
    // 005bc12e  740f                   -je 0x5bc13f
    if (cpu.flags.zf)
    {
        goto L_0x005bc13f;
    }
    // 005bc130  c70564ec5b00803e0000   -mov dword ptr [0x5bec64], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(6024292) /* 0x5bec64 */) = 16000 /*0x3e80*/;
    // 005bc13a  e961feffff             -jmp 0x5bbfa0
    goto L_0x005bbfa0;
L_0x005bc13f:
    // 005bc13f  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 005bc142  740f                   -je 0x5bc153
    if (cpu.flags.zf)
    {
        goto L_0x005bc153;
    }
    // 005bc144  c70564ec5b00007d0000   -mov dword ptr [0x5bec64], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(6024292) /* 0x5bec64 */) = 32000 /*0x7d00*/;
    // 005bc14e  e94dfeffff             -jmp 0x5bbfa0
    goto L_0x005bbfa0;
L_0x005bc153:
    // 005bc153  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 005bc156  740f                   -je 0x5bc167
    if (cpu.flags.zf)
    {
        goto L_0x005bc167;
    }
    // 005bc158  c70564ec5b0044ac0000   -mov dword ptr [0x5bec64], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(6024292) /* 0x5bec64 */) = 44100 /*0xac44*/;
    // 005bc162  e939feffff             -jmp 0x5bbfa0
    goto L_0x005bbfa0;
L_0x005bc167:
    // 005bc167  f6c602                 +test dh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 2 /*0x2*/));
    // 005bc16a  740f                   -je 0x5bc17b
    if (cpu.flags.zf)
    {
        goto L_0x005bc17b;
    }
    // 005bc16c  c70564ec5b00112b0000   -mov dword ptr [0x5bec64], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(6024292) /* 0x5bec64 */) = 11025 /*0x2b11*/;
    // 005bc176  e925feffff             -jmp 0x5bbfa0
    goto L_0x005bbfa0;
L_0x005bc17b:
    // 005bc17b  833d6cec5b0000         +cmp dword ptr [0x5bec6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc182  0f8424ffffff           -je 0x5bc0ac
    if (cpu.flags.zf)
    {
        goto L_0x005bc0ac;
    }
    // 005bc188  6800ea5b00             -push 0x5bea00
    app->getMemory<x86::reg32>(cpu.esp-4) = 6023680 /*0x5bea00*/;
    cpu.esp -= 4;
    // 005bc18d  e911ffffff             -jmp 0x5bc0a3
    goto L_0x005bc0a3;
L_0x005bc192:
    // 005bc192  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 005bc195  740f                   -je 0x5bc1a6
    if (cpu.flags.zf)
    {
        goto L_0x005bc1a6;
    }
    // 005bc197  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 005bc19c  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 005bc1a1  e90dfeffff             -jmp 0x5bbfb3
    goto L_0x005bbfb3;
L_0x005bc1a6:
    // 005bc1a6  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 005bc1a9  740a                   -je 0x5bc1b5
    if (cpu.flags.zf)
    {
        goto L_0x005bc1b5;
    }
    // 005bc1ab  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 005bc1b0  e9f9fdffff             -jmp 0x5bbfae
    goto L_0x005bbfae;
L_0x005bc1b5:
    // 005bc1b5  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 005bc1b8  740f                   -je 0x5bc1c9
    if (cpu.flags.zf)
    {
        goto L_0x005bc1c9;
    }
    // 005bc1ba  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 005bc1bf  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 005bc1c4  e9eafdffff             -jmp 0x5bbfb3
    goto L_0x005bbfb3;
L_0x005bc1c9:
    // 005bc1c9  833d6cec5b0000         +cmp dword ptr [0x5bec6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc1d0  0f84d6feffff           -je 0x5bc0ac
    if (cpu.flags.zf)
    {
        goto L_0x005bc0ac;
    }
    // 005bc1d6  682cea5b00             -push 0x5bea2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 6023724 /*0x5bea2c*/;
    cpu.esp -= 4;
    // 005bc1db  e9c3feffff             -jmp 0x5bc0a3
    goto L_0x005bc0a3;
L_0x005bc1e0:
    // 005bc1e0  c70530ec5b0014000000   -mov dword ptr [0x5bec30], 0x14
    app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */) = 20 /*0x14*/;
    // 005bc1ea  a164ec5b00             -mov eax, dword ptr [0x5bec64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024292) /* 0x5bec64 */);
    // 005bc1ef  0faf0530ec5b00         -imul eax, dword ptr [0x5bec30]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */))));
    // 005bc1f6  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 005bc1fb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005bc1fd  f7f1                   +div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 005bc1ff  a330ec5b00             -mov dword ptr [0x5bec30], eax
    app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */) = cpu.eax;
    // 005bc204  e9e5fdffff             -jmp 0x5bbfee
    goto L_0x005bbfee;
L_0x005bc209:
    // 005bc209  3d0a007888             +cmp eax, 0x8878000a
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
    // 005bc20e  750a                   -jne 0x5bc21a
    if (!cpu.flags.zf)
    {
        goto L_0x005bc21a;
    }
    // 005bc210  bdeeffffff             -mov ebp, 0xffffffee
    cpu.ebp = 4294967278 /*0xffffffee*/;
    // 005bc215  e992feffff             -jmp 0x5bc0ac
    goto L_0x005bc0ac;
L_0x005bc21a:
    // 005bc21a  3d78007888             +cmp eax, 0x88780078
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
    // 005bc21f  750a                   -jne 0x5bc22b
    if (!cpu.flags.zf)
    {
        goto L_0x005bc22b;
    }
    // 005bc221  bdf6ffffff             -mov ebp, 0xfffffff6
    cpu.ebp = 4294967286 /*0xfffffff6*/;
    // 005bc226  e981feffff             -jmp 0x5bc0ac
    goto L_0x005bc0ac;
L_0x005bc22b:
    // 005bc22b  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 005bc230  e977feffff             -jmp 0x5bc0ac
    goto L_0x005bc0ac;
L_0x005bc235:
    // 005bc235  803d11ec5b0000         +cmp byte ptr [0x5bec11], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024209) /* 0x5bec11 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bc23c  755f                   -jne 0x5bc29d
    if (!cpu.flags.zf)
    {
        goto L_0x005bc29d;
    }
    // 005bc23e  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 005bc243  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005bc245  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005bc247  e82b090000             -call 0x5bcb77
    cpu.esp -= 4;
    sub_5bcb77(app, cpu);
    if (cpu.terminate) return;
    // 005bc24c  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 005bc251  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005bc256  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 005bc259  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005bc25d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bc25f  8b1500ec5b00           -mov edx, dword ptr [0x5bec00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bc265  6804ec5b00             -push 0x5bec04
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024196 /*0x5bec04*/;
    cpu.esp -= 4;
    // 005bc26a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005bc26e  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 005bc270  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bc271  8b0d00ec5b00           -mov ecx, dword ptr [0x5bec00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bc277  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bc278  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc27b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc27d  7417                   -je 0x5bc296
    if (cpu.flags.zf)
    {
        goto L_0x005bc296;
    }
    // 005bc27f  833d6cec5b0000         +cmp dword ptr [0x5bec6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc286  0f8420feffff           -je 0x5bc0ac
    if (cpu.flags.zf)
    {
        goto L_0x005bc0ac;
    }
    // 005bc28c  6890ea5b00             -push 0x5bea90
    app->getMemory<x86::reg32>(cpu.esp-4) = 6023824 /*0x5bea90*/;
    cpu.esp -= 4;
    // 005bc291  e90dfeffff             -jmp 0x5bc0a3
    goto L_0x005bc0a3;
L_0x005bc296:
    // 005bc296  c60511ec5b0001         -mov byte ptr [0x5bec11], 1
    app->getMemory<x86::reg8>(x86::reg32(6024209) /* 0x5bec11 */) = 1 /*0x1*/;
L_0x005bc29d:
    // 005bc29d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 005bc2a2  668974242a             -mov word ptr [esp + 0x2a], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(42) /* 0x2a */) = cpu.si;
    // 005bc2a7  6689542428             -mov word ptr [esp + 0x28], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.dx;
    // 005bc2ac  a164ec5b00             -mov eax, dword ptr [0x5bec64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024292) /* 0x5bec64 */);
    // 005bc2b1  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 005bc2b5  0fbe0d14ec5b00         -movsx ecx, byte ptr [0x5bec14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024212) /* 0x5bec14 */)));
    // 005bc2bc  a164ec5b00             -mov eax, dword ptr [0x5bec64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024292) /* 0x5bec64 */);
    // 005bc2c1  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 005bc2c3  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 005bc2c7  660fbe0513ec5b00       -movsx ax, byte ptr [0x5bec13]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024211) /* 0x5bec13 */)));
    // 005bc2cf  6689442434             -mov word ptr [esp + 0x34], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ax;
    // 005bc2d4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005bc2d6  66897c2436             -mov word ptr [esp + 0x36], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(54) /* 0x36 */) = cpu.di;
    // 005bc2db  66895c2438             -mov word ptr [esp + 0x38], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.bx;
    // 005bc2e0  a104ec5b00             -mov eax, dword ptr [0x5bec04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bc2e5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc2e7  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 005bc2eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bc2ec  8b1d04ec5b00           -mov ebx, dword ptr [0x5bec04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bc2f2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bc2f3  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc2f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc2f8  7417                   -je 0x5bc311
    if (cpu.flags.zf)
    {
        goto L_0x005bc311;
    }
    // 005bc2fa  833d6cec5b0000         +cmp dword ptr [0x5bec6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc301  0f84a5fdffff           -je 0x5bc0ac
    if (cpu.flags.zf)
    {
        goto L_0x005bc0ac;
    }
    // 005bc307  68c4ea5b00             -push 0x5beac4
    app->getMemory<x86::reg32>(cpu.esp-4) = 6023876 /*0x5beac4*/;
    cpu.esp -= 4;
    // 005bc30c  e992fdffff             -jmp 0x5bc0a3
    goto L_0x005bc0a3;
L_0x005bc311:
    // 005bc311  c744241414000000       -mov dword ptr [esp + 0x14], 0x14
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 20 /*0x14*/;
    // 005bc319  a104ec5b00             -mov eax, dword ptr [0x5bec04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bc31e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc320  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005bc324  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bc325  8b0d04ec5b00           -mov ecx, dword ptr [0x5bec04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bc32b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bc32c  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc32f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc331  7417                   -je 0x5bc34a
    if (cpu.flags.zf)
    {
        goto L_0x005bc34a;
    }
    // 005bc333  833d6cec5b0000         +cmp dword ptr [0x5bec6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc33a  0f846cfdffff           -je 0x5bc0ac
    if (cpu.flags.zf)
    {
        goto L_0x005bc0ac;
    }
    // 005bc340  68fcea5b00             -push 0x5beafc
    app->getMemory<x86::reg32>(cpu.esp-4) = 6023932 /*0x5beafc*/;
    cpu.esp -= 4;
    // 005bc345  e959fdffff             -jmp 0x5bc0a3
    goto L_0x005bc0a3;
L_0x005bc34a:
    // 005bc34a  837c244000             +cmp dword ptr [esp + 0x40], 0
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
    // 005bc34f  0f8429010000           -je 0x5bc47e
    if (cpu.flags.zf)
    {
        goto L_0x005bc47e;
    }
    // 005bc355  f644241804             +test byte ptr [esp + 0x18], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */) & 4 /*0x4*/));
    // 005bc35a  0f844cfdffff           -je 0x5bc0ac
    if (cpu.flags.zf)
    {
        goto L_0x005bc0ac;
    }
    // 005bc360  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 005bc364  a33cec5b00             -mov dword ptr [0x5bec3c], eax
    app->getMemory<x86::reg32>(x86::reg32(6024252) /* 0x5bec3c */) = cpu.eax;
    // 005bc369  0fbe0d14ec5b00         -movsx ecx, byte ptr [0x5bec14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024212) /* 0x5bec14 */)));
    // 005bc370  a13cec5b00             -mov eax, dword ptr [0x5bec3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024252) /* 0x5bec3c */);
    // 005bc375  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 005bc377  a80f                   +test al, 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 15 /*0xf*/));
    // 005bc379  0f852dfdffff           -jne 0x5bc0ac
    if (!cpu.flags.zf)
    {
        goto L_0x005bc0ac;
    }
L_0x005bc37f:
    // 005bc37f  0fbe0d14ec5b00         -movsx ecx, byte ptr [0x5bec14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024212) /* 0x5bec14 */)));
    // 005bc386  a13cec5b00             -mov eax, dword ptr [0x5bec3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024252) /* 0x5bec3c */);
    // 005bc38b  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 005bc38d  a35cec5b00             -mov dword ptr [0x5bec5c], eax
    app->getMemory<x86::reg32>(x86::reg32(6024284) /* 0x5bec5c */) = cpu.eax;
    // 005bc392  8b155cec5b00           -mov edx, dword ptr [0x5bec5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024284) /* 0x5bec5c */);
    // 005bc398  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 005bc39b  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 005bc3a0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005bc3a2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005bc3a5  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005bc3a7  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005bc3ac  a334ec5b00             -mov dword ptr [0x5bec34], eax
    app->getMemory<x86::reg32>(x86::reg32(6024244) /* 0x5bec34 */) = cpu.eax;
    // 005bc3b1  a15cec5b00             -mov eax, dword ptr [0x5bec5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024284) /* 0x5bec5c */);
    // 005bc3b6  a340ec5b00             -mov dword ptr [0x5bec40], eax
    app->getMemory<x86::reg32>(x86::reg32(6024256) /* 0x5bec40 */) = cpu.eax;
    // 005bc3bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005bc3bd  a34cec5b00             -mov dword ptr [0x5bec4c], eax
    app->getMemory<x86::reg32>(x86::reg32(6024268) /* 0x5bec4c */) = cpu.eax;
    // 005bc3c2  a350ec5b00             -mov dword ptr [0x5bec50], eax
    app->getMemory<x86::reg32>(x86::reg32(6024272) /* 0x5bec50 */) = cpu.eax;
    // 005bc3c7  a348ec5b00             -mov dword ptr [0x5bec48], eax
    app->getMemory<x86::reg32>(x86::reg32(6024264) /* 0x5bec48 */) = cpu.eax;
    // 005bc3cc  837c244000             +cmp dword ptr [esp + 0x40], 0
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
    // 005bc3d1  0f8400010000           -je 0x5bc4d7
    if (cpu.flags.zf)
    {
        goto L_0x005bc4d7;
    }
    // 005bc3d7  a104ec5b00             -mov eax, dword ptr [0x5bec04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
L_0x005bc3dc:
    // 005bc3dc  a30cec5b00             -mov dword ptr [0x5bec0c], eax
    app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */) = cpu.eax;
    // 005bc3e1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bc3e3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bc3e5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bc3e7  a10cec5b00             -mov eax, dword ptr [0x5bec0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bc3ec  6858ec5b00             -push 0x5bec58
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024280 /*0x5bec58*/;
    cpu.esp -= 4;
    // 005bc3f1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc3f3  6854ec5b00             -push 0x5bec54
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024276 /*0x5bec54*/;
    cpu.esp -= 4;
    // 005bc3f8  8b1d3cec5b00           -mov ebx, dword ptr [0x5bec3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6024252) /* 0x5bec3c */);
    // 005bc3fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bc3ff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bc401  8b350cec5b00           -mov esi, dword ptr [0x5bec0c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bc407  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bc408  ff502c                 -call dword ptr [eax + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc40b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc40d  0f8599fcffff           -jne 0x5bc0ac
    if (!cpu.flags.zf)
    {
        goto L_0x005bc0ac;
    }
    // 005bc413  8b1d3cec5b00           -mov ebx, dword ptr [0x5bec3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6024252) /* 0x5bec3c */);
    // 005bc419  a154ec5b00             -mov eax, dword ptr [0x5bec54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024276) /* 0x5bec54 */);
    // 005bc41e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005bc420  e852070000             -call 0x5bcb77
    cpu.esp -= 4;
    sub_5bcb77(app, cpu);
    if (cpu.terminate) return;
    // 005bc425  a10cec5b00             -mov eax, dword ptr [0x5bec0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bc42a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bc42c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc42e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bc430  8b3d3cec5b00           -mov edi, dword ptr [0x5bec3c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6024252) /* 0x5bec3c */);
    // 005bc436  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005bc437  8b1554ec5b00           -mov edx, dword ptr [0x5bec54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024276) /* 0x5bec54 */);
    // 005bc43d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bc43e  8b0d0cec5b00           -mov ecx, dword ptr [0x5bec0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bc444  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bc445  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc448  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005bc44a  a10cec5b00             -mov eax, dword ptr [0x5bec0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bc44f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bc451  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc453  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bc455  8b1d0cec5b00           -mov ebx, dword ptr [0x5bec0c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bc45b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bc45c  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc45f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc461  0f8425010000           -je 0x5bc58c
    if (cpu.flags.zf)
    {
        goto L_0x005bc58c;
    }
    // 005bc467  833d6cec5b0000         +cmp dword ptr [0x5bec6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc46e  0f8438fcffff           -je 0x5bc0ac
    if (cpu.flags.zf)
    {
        goto L_0x005bc0ac;
    }
    // 005bc474  686ceb5b00             -push 0x5beb6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024044 /*0x5beb6c*/;
    cpu.esp -= 4;
    // 005bc479  e925fcffff             -jmp 0x5bc0a3
    goto L_0x005bc0a3;
L_0x005bc47e:
    // 005bc47e  803d15ec5b0000         +cmp byte ptr [0x5bec15], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024213) /* 0x5bec15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bc485  7418                   -je 0x5bc49f
    if (cpu.flags.zf)
    {
        goto L_0x005bc49f;
    }
    // 005bc487  0fbe0d14ec5b00         -movsx ecx, byte ptr [0x5bec14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024212) /* 0x5bec14 */)));
    // 005bc48e  b800a00000             -mov eax, 0xa000
    cpu.eax = 40960 /*0xa000*/;
    // 005bc493  d3e0                   +shl eax, cl
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
    // 005bc495  a33cec5b00             -mov dword ptr [0x5bec3c], eax
    app->getMemory<x86::reg32>(x86::reg32(6024252) /* 0x5bec3c */) = cpu.eax;
    // 005bc49a  e9e0feffff             -jmp 0x5bc37f
    goto L_0x005bc37f;
L_0x005bc49f:
    // 005bc49f  8b1564ec5b00           -mov edx, dword ptr [0x5bec64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024292) /* 0x5bec64 */);
    // 005bc4a5  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 005bc4ac  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005bc4ae  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 005bc4b1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005bc4b3  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 005bc4b8  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 005bc4bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005bc4bd  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 005bc4bf  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005bc4c4  0fbe0d14ec5b00         -movsx ecx, byte ptr [0x5bec14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024212) /* 0x5bec14 */)));
    // 005bc4cb  d3e0                   +shl eax, cl
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
    // 005bc4cd  a33cec5b00             -mov dword ptr [0x5bec3c], eax
    app->getMemory<x86::reg32>(x86::reg32(6024252) /* 0x5bec3c */) = cpu.eax;
    // 005bc4d2  e9a8feffff             -jmp 0x5bc37f
    goto L_0x005bc37f;
L_0x005bc4d7:
    // 005bc4d7  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 005bc4dc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005bc4de  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005bc4e0  e892060000             -call 0x5bcb77
    cpu.esp -= 4;
    sub_5bcb77(app, cpu);
    if (cpu.terminate) return;
    // 005bc4e5  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 005bc4ea  ba08000100             -mov edx, 0x10008
    cpu.edx = 65544 /*0x10008*/;
    // 005bc4ef  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005bc4f2  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005bc4f6  a13cec5b00             -mov eax, dword ptr [0x5bec3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024252) /* 0x5bec3c */);
    // 005bc4fb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 005bc500  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005bc504  668974242a             -mov word ptr [esp + 0x2a], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(42) /* 0x2a */) = cpu.si;
    // 005bc509  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 005bc50d  66894c2428             -mov word ptr [esp + 0x28], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 005bc512  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005bc516  a164ec5b00             -mov eax, dword ptr [0x5bec64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024292) /* 0x5bec64 */);
    // 005bc51b  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 005bc51f  0fbe0d14ec5b00         -movsx ecx, byte ptr [0x5bec14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024212) /* 0x5bec14 */)));
    // 005bc526  a164ec5b00             -mov eax, dword ptr [0x5bec64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024292) /* 0x5bec64 */);
    // 005bc52b  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 005bc52d  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 005bc531  660fbe0513ec5b00       -movsx ax, byte ptr [0x5bec13]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024211) /* 0x5bec13 */)));
    // 005bc539  6689442434             -mov word ptr [esp + 0x34], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ax;
    // 005bc53e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 005bc540  66897c2436             -mov word ptr [esp + 0x36], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(54) /* 0x36 */) = cpu.di;
    // 005bc545  6689742438             -mov word ptr [esp + 0x38], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.si;
    // 005bc54a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bc54c  a100ec5b00             -mov eax, dword ptr [0x5bec00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bc551  6808ec5b00             -push 0x5bec08
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024200 /*0x5bec08*/;
    cpu.esp -= 4;
    // 005bc556  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc558  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005bc55c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bc55d  8b0d00ec5b00           -mov ecx, dword ptr [0x5bec00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bc563  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bc564  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc567  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc569  7417                   -je 0x5bc582
    if (cpu.flags.zf)
    {
        goto L_0x005bc582;
    }
    // 005bc56b  833d6cec5b0000         +cmp dword ptr [0x5bec6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc572  0f8434fbffff           -je 0x5bc0ac
    if (cpu.flags.zf)
    {
        goto L_0x005bc0ac;
    }
    // 005bc578  6834eb5b00             -push 0x5beb34
    app->getMemory<x86::reg32>(cpu.esp-4) = 6023988 /*0x5beb34*/;
    cpu.esp -= 4;
    // 005bc57d  e921fbffff             -jmp 0x5bc0a3
    goto L_0x005bc0a3;
L_0x005bc582:
    // 005bc582  a108ec5b00             -mov eax, dword ptr [0x5bec08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024200) /* 0x5bec08 */);
    // 005bc587  e950feffff             -jmp 0x5bc3dc
    goto L_0x005bc3dc;
L_0x005bc58c:
    // 005bc58c  c60512ec5b0001         -mov byte ptr [0x5bec12], 1
    app->getMemory<x86::reg8>(x86::reg32(6024210) /* 0x5bec12 */) = 1 /*0x1*/;
    // 005bc593  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005bc595  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 005bc598  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc599  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc59a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc59b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc59c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005bc59d:
    // 005bc59d  a100ec5b00             -mov eax, dword ptr [0x5bec00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bc5a2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc5a4  8b1500ec5b00           -mov edx, dword ptr [0x5bec00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bc5aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bc5ab  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc5ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc5b0  0f8449fbffff           -je 0x5bc0ff
    if (cpu.flags.zf)
    {
        goto L_0x005bc0ff;
    }
    // 005bc5b6  833d6cec5b0000         +cmp dword ptr [0x5bec6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc5bd  740e                   -je 0x5bc5cd
    if (cpu.flags.zf)
    {
        goto L_0x005bc5cd;
    }
    // 005bc5bf  68d0eb5b00             -push 0x5bebd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024144 /*0x5bebd0*/;
    cpu.esp -= 4;
    // 005bc5c4  ff156cec5b00           -call dword ptr [0x5bec6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc5ca  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005bc5cd:
    // 005bc5cd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005bc5d2  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 005bc5d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc5d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc5d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc5d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc5d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_5bc5dc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bc5dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bc5dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bc5de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bc5df  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005bc5e1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005bc5e3  803d12ec5b0000         +cmp byte ptr [0x5bec12], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024210) /* 0x5bec12 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bc5ea  751f                   -jne 0x5bc60b
    if (!cpu.flags.zf)
    {
        goto L_0x005bc60b;
    }
L_0x005bc5ec:
    // 005bc5ec  803d15ec5b0000         +cmp byte ptr [0x5bec15], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024213) /* 0x5bec15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bc5f3  751d                   -jne 0x5bc612
    if (!cpu.flags.zf)
    {
        goto L_0x005bc612;
    }
    // 005bc5f5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005bc5fa  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005bc5fc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005bc5fe  e869f9ffff             -call 0x5bbf6c
    cpu.esp -= 4;
    sub_5bbf6c(app, cpu);
    if (cpu.terminate) return;
    // 005bc603  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc605  750b                   -jne 0x5bc612
    if (!cpu.flags.zf)
    {
        goto L_0x005bc612;
    }
    // 005bc607  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc608  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc609  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc60a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005bc60b:
    // 005bc60b  e814000000             -call 0x5bc624
    cpu.esp -= 4;
    sub_5bc624(app, cpu);
    if (cpu.terminate) return;
    // 005bc610  ebda                   -jmp 0x5bc5ec
    goto L_0x005bc5ec;
L_0x005bc612:
    // 005bc612  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005bc614  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005bc616  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005bc618  e84ff9ffff             -call 0x5bbf6c
    cpu.esp -= 4;
    sub_5bbf6c(app, cpu);
    if (cpu.terminate) return;
    // 005bc61d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc61e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc61f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc620  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_5bc624(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bc624  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bc625  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bc626  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bc627  803d12ec5b0000         +cmp byte ptr [0x5bec12], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024210) /* 0x5bec12 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bc62e  7534                   -jne 0x5bc664
    if (!cpu.flags.zf)
    {
        goto L_0x005bc664;
    }
L_0x005bc630:
    // 005bc630  803d10ec5b0000         +cmp byte ptr [0x5bec10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024208) /* 0x5bec10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bc637  7425                   -je 0x5bc65e
    if (cpu.flags.zf)
    {
        goto L_0x005bc65e;
    }
    // 005bc639  833d00ec5b0000         +cmp dword ptr [0x5bec00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc640  7558                   -jne 0x5bc69a
    if (!cpu.flags.zf)
    {
        goto L_0x005bc69a;
    }
L_0x005bc642:
    // 005bc642  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005bc643  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bc644  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 005bc646  893d00ec5b00           -mov dword ptr [0x5bec00], edi
    app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */) = cpu.edi;
    // 005bc64c  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 005bc64e  881d11ec5b00           -mov byte ptr [0x5bec11], bl
    app->getMemory<x86::reg8>(x86::reg32(6024209) /* 0x5bec11 */) = cpu.bl;
    // 005bc654  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 005bc656  883d10ec5b00           -mov byte ptr [0x5bec10], bh
    app->getMemory<x86::reg8>(x86::reg32(6024208) /* 0x5bec10 */) = cpu.bh;
    // 005bc65c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc65d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x005bc65e:
    // 005bc65e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005bc660  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc661  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc662  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc663  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005bc664:
    // 005bc664  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 005bc666  881512ec5b00           -mov byte ptr [0x5bec12], dl
    app->getMemory<x86::reg8>(x86::reg32(6024210) /* 0x5bec12 */) = cpu.dl;
    // 005bc66c  a104ec5b00             -mov eax, dword ptr [0x5bec04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bc671  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc673  8b1504ec5b00           -mov edx, dword ptr [0x5bec04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024196) /* 0x5bec04 */);
    // 005bc679  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bc67a  ff5048                 -call dword ptr [eax + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc67d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc67f  74af                   -je 0x5bc630
    if (cpu.flags.zf)
    {
        goto L_0x005bc630;
    }
    // 005bc681  833d6cec5b0000         +cmp dword ptr [0x5bec6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc688  74a6                   -je 0x5bc630
    if (cpu.flags.zf)
    {
        goto L_0x005bc630;
    }
    // 005bc68a  68a0eb5b00             -push 0x5beba0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024096 /*0x5beba0*/;
    cpu.esp -= 4;
    // 005bc68f  ff156cec5b00           -call dword ptr [0x5bec6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc695  83c404                 +add esp, 4
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
    // 005bc698  eb96                   -jmp 0x5bc630
    goto L_0x005bc630;
L_0x005bc69a:
    // 005bc69a  a100ec5b00             -mov eax, dword ptr [0x5bec00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bc69f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc6a1  8b3500ec5b00           -mov esi, dword ptr [0x5bec00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6024192) /* 0x5bec00 */);
    // 005bc6a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bc6a8  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc6ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc6ad  7493                   -je 0x5bc642
    if (cpu.flags.zf)
    {
        goto L_0x005bc642;
    }
    // 005bc6af  833d6cec5b0000         +cmp dword ptr [0x5bec6c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc6b6  740e                   -je 0x5bc6c6
    if (cpu.flags.zf)
    {
        goto L_0x005bc6c6;
    }
    // 005bc6b8  68d0eb5b00             -push 0x5bebd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024144 /*0x5bebd0*/;
    cpu.esp -= 4;
    // 005bc6bd  ff156cec5b00           -call dword ptr [0x5bec6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6024300) /* 0x5bec6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc6c3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005bc6c6:
    // 005bc6c6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005bc6cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc6cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc6cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc6ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_5bc6d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bc6d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bc6d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bc6d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bc6d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005bc6d4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 005bc6d6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005bc6d8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005bc6da  7e43                   -jle 0x5bc71f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005bc71f;
    }
L_0x005bc6dc:
    // 005bc6dc  833d48ec5b0000         +cmp dword ptr [0x5bec48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024264) /* 0x5bec48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc6e3  7e3f                   -jle 0x5bc724
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005bc724;
    }
L_0x005bc6e5:
    // 005bc6e5  a148ec5b00             -mov eax, dword ptr [0x5bec48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024264) /* 0x5bec48 */);
    // 005bc6ea  39c6                   +cmp esi, eax
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
    // 005bc6ec  0f8e98000000           -jle 0x5bc78a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005bc78a;
    }
    // 005bc6f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x005bc6f4:
    // 005bc6f4  8b1548ec5b00           -mov edx, dword ptr [0x5bec48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024264) /* 0x5bec48 */);
    // 005bc6fa  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 005bc6fc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005bc6fe  891548ec5b00           -mov dword ptr [0x5bec48], edx
    app->getMemory<x86::reg32>(x86::reg32(6024264) /* 0x5bec48 */) = cpu.edx;
    // 005bc704  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005bc706  ff1568ec5b00           -call dword ptr [0x5bec68]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6024296) /* 0x5bec68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc70c  8b0d11ec5b00           -mov ecx, dword ptr [0x5bec11]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024209) /* 0x5bec11 */);
    // 005bc712  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 005bc715  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 005bc717  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 005bc719  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 005bc71b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005bc71d  7fbd                   -jg 0x5bc6dc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005bc6dc;
    }
L_0x005bc71f:
    // 005bc71f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc720  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc721  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc722  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc723  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005bc724:
    // 005bc724  ff054cec5b00           -inc dword ptr [0x5bec4c]
    (app->getMemory<x86::reg32>(x86::reg32(6024268) /* 0x5bec4c */))++;
    // 005bc72a  ff1574ec5b00           -call dword ptr [0x5bec74]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(6024308) /* 0x5bec74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc730  a14cec5b00             -mov eax, dword ptr [0x5bec4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024268) /* 0x5bec4c */);
    // 005bc735  0faf0564ec5b00         -imul eax, dword ptr [0x5bec64]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6024292) /* 0x5bec64 */))));
    // 005bc73c  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 005bc741  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005bc743  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 005bc745  8b0d50ec5b00           -mov ecx, dword ptr [0x5bec50]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024272) /* 0x5bec50 */);
    // 005bc74b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 005bc74d  a348ec5b00             -mov dword ptr [0x5bec48], eax
    app->getMemory<x86::reg32>(x86::reg32(6024264) /* 0x5bec48 */) = cpu.eax;
    // 005bc752  25f0ffff0f             -and eax, 0xffffff0
    cpu.eax &= x86::reg32(x86::sreg32(268435440 /*0xffffff0*/));
    // 005bc757  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 005bc75a  a348ec5b00             -mov dword ptr [0x5bec48], eax
    app->getMemory<x86::reg32>(x86::reg32(6024264) /* 0x5bec48 */) = cpu.eax;
    // 005bc75f  8b0d4cec5b00           -mov ecx, dword ptr [0x5bec4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024268) /* 0x5bec4c */);
    // 005bc765  891550ec5b00           -mov dword ptr [0x5bec50], edx
    app->getMemory<x86::reg32>(x86::reg32(6024272) /* 0x5bec50 */) = cpu.edx;
    // 005bc76b  81f930750000           +cmp ecx, 0x7530
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
    // 005bc771  0f8e6effffff           -jle 0x5bc6e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005bc6e5;
    }
    // 005bc777  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 005bc779  891d4cec5b00           -mov dword ptr [0x5bec4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(6024268) /* 0x5bec4c */) = cpu.ebx;
    // 005bc77f  891d50ec5b00           -mov dword ptr [0x5bec50], ebx
    app->getMemory<x86::reg32>(x86::reg32(6024272) /* 0x5bec50 */) = cpu.ebx;
    // 005bc785  e95bffffff             -jmp 0x5bc6e5
    goto L_0x005bc6e5;
L_0x005bc78a:
    // 005bc78a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005bc78c  e963ffffff             -jmp 0x5bc6f4
    goto L_0x005bc6f4;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_5bc794(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bc794  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bc795  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bc796  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bc797  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bc798  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005bc799  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005bc79a  8b1518ec5b00           -mov edx, dword ptr [0x5bec18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024216) /* 0x5bec18 */);
    // 005bc7a0  81fa00000011           +cmp edx, 0x11000000
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
    // 005bc7a6  0f879f000000           -ja 0x5bc84b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x005bc84b;
    }
L_0x005bc7ac:
    // 005bc7ac  a118ec5b00             -mov eax, dword ptr [0x5bec18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024216) /* 0x5bec18 */);
    // 005bc7b1  8b351cec5b00           -mov esi, dword ptr [0x5bec1c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6024220) /* 0x5bec1c */);
    // 005bc7b7  8b3d5cec5b00           -mov edi, dword ptr [0x5bec5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6024284) /* 0x5bec5c */);
    // 005bc7bd  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 005bc7bf  39f8                   +cmp eax, edi
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
    // 005bc7c1  7c10                   -jl 0x5bc7d3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005bc7d3;
    }
    // 005bc7c3  8b2d18ec5b00           -mov ebp, dword ptr [0x5bec18]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6024216) /* 0x5bec18 */);
    // 005bc7c9  29fd                   -sub ebp, edi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edi));
    // 005bc7cb  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 005bc7cd  892d18ec5b00           -mov dword ptr [0x5bec18], ebp
    app->getMemory<x86::reg32>(x86::reg32(6024216) /* 0x5bec18 */) = cpu.ebp;
L_0x005bc7d3:
    // 005bc7d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc7d5  0f8cab000000           -jl 0x5bc886
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005bc886;
    }
    // 005bc7db  8b1544ec5b00           -mov edx, dword ptr [0x5bec44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024260) /* 0x5bec44 */);
    // 005bc7e1  42                     -inc edx
    (cpu.edx)++;
    // 005bc7e2  8b0d40ec5b00           -mov ecx, dword ptr [0x5bec40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024256) /* 0x5bec40 */);
    // 005bc7e8  891544ec5b00           -mov dword ptr [0x5bec44], edx
    app->getMemory<x86::reg32>(x86::reg32(6024260) /* 0x5bec44 */) = cpu.edx;
    // 005bc7ee  39c8                   +cmp eax, ecx
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
    // 005bc7f0  0f8c78000000           -jl 0x5bc86e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005bc86e;
    }
L_0x005bc7f6:
    // 005bc7f6  8b1d44ec5b00           -mov ebx, dword ptr [0x5bec44]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6024260) /* 0x5bec44 */);
    // 005bc7fc  81fbb80b0000           +cmp ebx, 0xbb8
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
    // 005bc802  7c40                   -jl 0x5bc844
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005bc844;
    }
    // 005bc804  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 005bc809  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005bc80b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005bc80d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005bc810  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005bc812  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005bc814  752e                   -jne 0x5bc844
    if (!cpu.flags.zf)
    {
        goto L_0x005bc844;
    }
    // 005bc816  833d40ec5b0010         +cmp dword ptr [0x5bec40], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024256) /* 0x5bec40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc81d  7e56                   -jle 0x5bc875
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005bc875;
    }
    // 005bc81f  8b3d30ec5b00           -mov edi, dword ptr [0x5bec30]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */);
    // 005bc825  4f                     -dec edi
    (cpu.edi)--;
    // 005bc826  a15cec5b00             -mov eax, dword ptr [0x5bec5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024284) /* 0x5bec5c */);
    // 005bc82b  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 005bc82d  893d30ec5b00           -mov dword ptr [0x5bec30], edi
    app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */) = cpu.edi;
    // 005bc833  81e5f0ff0f00           -and ebp, 0xffff0
    cpu.ebp &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005bc839  a340ec5b00             -mov dword ptr [0x5bec40], eax
    app->getMemory<x86::reg32>(x86::reg32(6024256) /* 0x5bec40 */) = cpu.eax;
    // 005bc83e  892d30ec5b00           -mov dword ptr [0x5bec30], ebp
    app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */) = cpu.ebp;
L_0x005bc844:
    // 005bc844  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc845  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc846  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc847  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc848  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc849  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc84a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005bc84b:
    // 005bc84b  8b1d1cec5b00           -mov ebx, dword ptr [0x5bec1c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6024220) /* 0x5bec1c */);
    // 005bc851  8d8a000000f0           -lea ecx, [edx - 0x10000000]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-268435456) /* -0x10000000 */);
    // 005bc857  81eb00000010           +sub ebx, 0x10000000
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
    // 005bc85d  890d18ec5b00           -mov dword ptr [0x5bec18], ecx
    app->getMemory<x86::reg32>(x86::reg32(6024216) /* 0x5bec18 */) = cpu.ecx;
    // 005bc863  891d1cec5b00           -mov dword ptr [0x5bec1c], ebx
    app->getMemory<x86::reg32>(x86::reg32(6024220) /* 0x5bec1c */) = cpu.ebx;
    // 005bc869  e93effffff             -jmp 0x5bc7ac
    goto L_0x005bc7ac;
L_0x005bc86e:
    // 005bc86e  a340ec5b00             -mov dword ptr [0x5bec40], eax
    app->getMemory<x86::reg32>(x86::reg32(6024256) /* 0x5bec40 */) = cpu.eax;
    // 005bc873  eb81                   -jmp 0x5bc7f6
    goto L_0x005bc7f6;
L_0x005bc875:
    // 005bc875  a15cec5b00             -mov eax, dword ptr [0x5bec5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024284) /* 0x5bec5c */);
    // 005bc87a  a340ec5b00             -mov dword ptr [0x5bec40], eax
    app->getMemory<x86::reg32>(x86::reg32(6024256) /* 0x5bec40 */) = cpu.eax;
    // 005bc87f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc880  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc881  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc882  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc883  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc884  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc885  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005bc886:
    // 005bc886  833d18ec5b0000         +cmp dword ptr [0x5bec18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024216) /* 0x5bec18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc88d  74b5                   -je 0x5bc844
    if (cpu.flags.zf)
    {
        goto L_0x005bc844;
    }
    // 005bc88f  8b1d30ec5b00           -mov ebx, dword ptr [0x5bec30]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */);
    // 005bc895  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005bc897  891d30ec5b00           -mov dword ptr [0x5bec30], ebx
    app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */) = cpu.ebx;
    // 005bc89d  8d730f                 -lea esi, [ebx + 0xf]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 005bc8a0  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 005bc8a2  893530ec5b00           -mov dword ptr [0x5bec30], esi
    app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */) = cpu.esi;
    // 005bc8a8  81e7f0ff0f00           -and edi, 0xffff0
    cpu.edi &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005bc8ae  8b2d34ec5b00           -mov ebp, dword ptr [0x5bec34]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6024244) /* 0x5bec34 */);
    // 005bc8b4  893d30ec5b00           -mov dword ptr [0x5bec30], edi
    app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */) = cpu.edi;
    // 005bc8ba  39ef                   +cmp edi, ebp
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
    // 005bc8bc  7e06                   -jle 0x5bc8c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005bc8c4;
    }
    // 005bc8be  892d30ec5b00           -mov dword ptr [0x5bec30], ebp
    app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */) = cpu.ebp;
L_0x005bc8c4:
    // 005bc8c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005bc8c6  a344ec5b00             -mov dword ptr [0x5bec44], eax
    app->getMemory<x86::reg32>(x86::reg32(6024260) /* 0x5bec44 */) = cpu.eax;
    // 005bc8cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc8cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc8cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc8ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc8cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc8d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc8d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_5bc8d4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bc8d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bc8d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bc8d6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bc8d7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bc8d8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005bc8d9  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005bc8dc  803d12ec5b0000         +cmp byte ptr [0x5bec12], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024210) /* 0x5bec12 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bc8e3  7509                   -jne 0x5bc8ee
    if (!cpu.flags.zf)
    {
        goto L_0x005bc8ee;
    }
L_0x005bc8e5:
    // 005bc8e5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005bc8e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc8e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc8ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc8eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc8ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bc8ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005bc8ee:
    // 005bc8ee  a10cec5b00             -mov eax, dword ptr [0x5bec0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bc8f3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc8f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005bc8f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bc8f8  8b0d0cec5b00           -mov ecx, dword ptr [0x5bec0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bc8fe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bc8ff  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc902  f6042402               +test byte ptr [esp], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp) & 2 /*0x2*/));
    // 005bc906  0f85e4000000           -jne 0x5bc9f0
    if (!cpu.flags.zf)
    {
        goto L_0x005bc9f0;
    }
    // 005bc90c  a10cec5b00             -mov eax, dword ptr [0x5bec0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bc911  6820ec5b00             -push 0x5bec20
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024224 /*0x5bec20*/;
    cpu.esp -= 4;
    // 005bc916  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc918  6824ec5b00             -push 0x5bec24
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024228 /*0x5bec24*/;
    cpu.esp -= 4;
    // 005bc91d  8b1d0cec5b00           -mov ebx, dword ptr [0x5bec0c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bc923  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bc924  ff5010                 -call dword ptr [eax + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bc927  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bc929  75ba                   -jne 0x5bc8e5
    if (!cpu.flags.zf)
    {
        goto L_0x005bc8e5;
    }
    // 005bc92b  803d15ec5b0000         +cmp byte ptr [0x5bec15], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024213) /* 0x5bec15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bc932  740a                   -je 0x5bc93e
    if (cpu.flags.zf)
    {
        goto L_0x005bc93e;
    }
    // 005bc934  a120ec5b00             -mov eax, dword ptr [0x5bec20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024224) /* 0x5bec20 */);
    // 005bc939  a324ec5b00             -mov dword ptr [0x5bec24], eax
    app->getMemory<x86::reg32>(x86::reg32(6024228) /* 0x5bec24 */) = cpu.eax;
L_0x005bc93e:
    // 005bc93e  0fbe0d14ec5b00         -movsx ecx, byte ptr [0x5bec14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024212) /* 0x5bec14 */)));
    // 005bc945  d32d24ec5b00           -shr dword ptr [0x5bec24], cl
    app->getMemory<x86::reg32>(x86::reg32(6024228) /* 0x5bec24 */) >>= cpu.cl % 32;
    // 005bc94b  812524ec5b00f0ff0f00   -and dword ptr [0x5bec24], 0xffff0
    app->getMemory<x86::reg32>(x86::reg32(6024228) /* 0x5bec24 */) &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005bc955  a124ec5b00             -mov eax, dword ptr [0x5bec24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024228) /* 0x5bec24 */);
    // 005bc95a  3b0528ec5b00           +cmp eax, dword ptr [0x5bec28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6024232) /* 0x5bec28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc960  0f82a4000000           -jb 0x5bca0a
    if (cpu.flags.cf)
    {
        goto L_0x005bca0a;
    }
    // 005bc966  a124ec5b00             -mov eax, dword ptr [0x5bec24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024228) /* 0x5bec24 */);
L_0x005bc96b:
    // 005bc96b  2b0528ec5b00           -sub eax, dword ptr [0x5bec28]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6024232) /* 0x5bec28 */)));
    // 005bc971  01051cec5b00           -add dword ptr [0x5bec1c], eax
    (app->getMemory<x86::reg32>(x86::reg32(6024220) /* 0x5bec1c */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 005bc977  a124ec5b00             -mov eax, dword ptr [0x5bec24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024228) /* 0x5bec24 */);
    // 005bc97c  3b0528ec5b00           +cmp eax, dword ptr [0x5bec28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6024232) /* 0x5bec28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc982  0f8592000000           -jne 0x5bca1a
    if (!cpu.flags.zf)
    {
        goto L_0x005bca1a;
    }
    // 005bc988  8b157cec5b00           -mov edx, dword ptr [0x5bec7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024316) /* 0x5bec7c */);
    // 005bc98e  42                     -inc edx
    (cpu.edx)++;
    // 005bc98f  89157cec5b00           -mov dword ptr [0x5bec7c], edx
    app->getMemory<x86::reg32>(x86::reg32(6024316) /* 0x5bec7c */) = cpu.edx;
    // 005bc995  81faf4010000           +cmp edx, 0x1f4
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
    // 005bc99b  0f8f85000000           -jg 0x5bca26
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005bca26;
    }
L_0x005bc9a1:
    // 005bc9a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x005bc9a2:
    // 005bc9a2  8b1d24ec5b00           -mov ebx, dword ptr [0x5bec24]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6024228) /* 0x5bec24 */);
    // 005bc9a8  031d30ec5b00           -add ebx, dword ptr [0x5bec30]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */)));
    // 005bc9ae  81e3f0ff0f00           -and ebx, 0xffff0
    cpu.ebx &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005bc9b4  3b1d5cec5b00           +cmp ebx, dword ptr [0x5bec5c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6024284) /* 0x5bec5c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc9ba  7c06                   -jl 0x5bc9c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005bc9c2;
    }
    // 005bc9bc  2b1d5cec5b00           -sub ebx, dword ptr [0x5bec5c]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6024284) /* 0x5bec5c */)));
L_0x005bc9c2:
    // 005bc9c2  3b1d2cec5b00           +cmp ebx, dword ptr [0x5bec2c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6024236) /* 0x5bec2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005bc9c8  0f8c78000000           -jl 0x5bca46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005bca46;
    }
    // 005bc9ce  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 005bc9d0  2b352cec5b00           -sub esi, dword ptr [0x5bec2c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6024236) /* 0x5bec2c */)));
    // 005bc9d6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x005bc9d8:
    // 005bc9d8  a15cec5b00             -mov eax, dword ptr [0x5bec5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024284) /* 0x5bec5c */);
    // 005bc9dd  83e810                 -sub eax, 0x10
    (cpu.eax) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005bc9e0  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 005bc9e3  39c2                   +cmp edx, eax
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
    // 005bc9e5  7c71                   -jl 0x5bca58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005bca58;
    }
    // 005bc9e7  830530ec5b0010         +add dword ptr [0x5bec30], 0x10
    {
        auto tmp1 = app->getMemory<x86::reg32>(x86::reg32(6024240) /* 0x5bec30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005bc9ee  ebb2                   -jmp 0x5bc9a2
    goto L_0x005bc9a2;
L_0x005bc9f0:
    // 005bc9f0  a10cec5b00             -mov eax, dword ptr [0x5bec0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bc9f5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bc9f7  8b350cec5b00           -mov esi, dword ptr [0x5bec0c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bc9fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bc9fe  ff5050                 -call dword ptr [eax + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bca01  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005bca04  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bca05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bca06  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bca07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bca08  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bca09  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005bca0a:
    // 005bca0a  a124ec5b00             -mov eax, dword ptr [0x5bec24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024228) /* 0x5bec24 */);
    // 005bca0f  03055cec5b00           +add eax, dword ptr [0x5bec5c]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6024284) /* 0x5bec5c */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005bca15  e951ffffff             -jmp 0x5bc96b
    goto L_0x005bc96b;
L_0x005bca1a:
    // 005bca1a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005bca1c  a37cec5b00             -mov dword ptr [0x5bec7c], eax
    app->getMemory<x86::reg32>(x86::reg32(6024316) /* 0x5bec7c */) = cpu.eax;
    // 005bca21  e97bffffff             -jmp 0x5bc9a1
    goto L_0x005bc9a1;
L_0x005bca26:
    // 005bca26  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005bca28  a10cec5b00             -mov eax, dword ptr [0x5bec0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bca2d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bca2f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bca31  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bca33  8b1d0cec5b00           -mov ebx, dword ptr [0x5bec0c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bca39  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005bca3a  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bca3d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005bca40  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bca41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bca42  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bca43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bca44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bca45  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005bca46:
    // 005bca46  8b355cec5b00           -mov esi, dword ptr [0x5bec5c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6024284) /* 0x5bec5c */);
    // 005bca4c  8b0d2cec5b00           -mov ecx, dword ptr [0x5bec2c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024236) /* 0x5bec2c */);
    // 005bca52  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 005bca54  29ce                   +sub esi, ecx
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
    // 005bca56  eb80                   -jmp 0x5bc9d8
    goto L_0x005bc9d8;
L_0x005bca58:
    // 005bca58  803d15ec5b0000         +cmp byte ptr [0x5bec15], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(6024213) /* 0x5bec15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005bca5f  7505                   -jne 0x5bca66
    if (!cpu.flags.zf)
    {
        goto L_0x005bca66;
    }
    // 005bca61  e82efdffff             -call 0x5bc794
    cpu.esp -= 4;
    sub_5bc794(app, cpu);
    if (cpu.terminate) return;
L_0x005bca66:
    // 005bca66  a124ec5b00             -mov eax, dword ptr [0x5bec24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024228) /* 0x5bec24 */);
    // 005bca6b  a328ec5b00             -mov dword ptr [0x5bec28], eax
    app->getMemory<x86::reg32>(x86::reg32(6024232) /* 0x5bec28 */) = cpu.eax;
    // 005bca70  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005bca72  0f84ef000000           -je 0x5bcb67
    if (cpu.flags.zf)
    {
        goto L_0x005bcb67;
    }
    // 005bca78  013518ec5b00           -add dword ptr [0x5bec18], esi
    (app->getMemory<x86::reg32>(x86::reg32(6024216) /* 0x5bec18 */)) += x86::reg32(x86::sreg32(cpu.esi));
    // 005bca7e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bca80  8b150cec5b00           -mov edx, dword ptr [0x5bec0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bca86  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bca88  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 005bca8a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bca8c  0fbe0d14ec5b00         -movsx ecx, byte ptr [0x5bec14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024212) /* 0x5bec14 */)));
    // 005bca93  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005bca95  6858ec5b00             -push 0x5bec58
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024280 /*0x5bec58*/;
    cpu.esp -= 4;
    // 005bca9a  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 005bca9c  6854ec5b00             -push 0x5bec54
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024276 /*0x5bec54*/;
    cpu.esp -= 4;
    // 005bcaa1  0fbe0d14ec5b00         -movsx ecx, byte ptr [0x5bec14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024212) /* 0x5bec14 */)));
    // 005bcaa8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bcaa9  a12cec5b00             -mov eax, dword ptr [0x5bec2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024236) /* 0x5bec2c */);
    // 005bcaae  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 005bcab0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bcab1  a10cec5b00             -mov eax, dword ptr [0x5bec0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bcab6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bcab7  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bcaba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bcabc  7532                   -jne 0x5bcaf0
    if (!cpu.flags.zf)
    {
        goto L_0x005bcaf0;
    }
    // 005bcabe  a154ec5b00             -mov eax, dword ptr [0x5bec54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024276) /* 0x5bec54 */);
    // 005bcac3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005bcac5  e806fcffff             -call 0x5bc6d0
    cpu.esp -= 4;
    sub_5bc6d0(app, cpu);
    if (cpu.terminate) return;
    // 005bcaca  a10cec5b00             -mov eax, dword ptr [0x5bec0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bcacf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bcad1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bcad3  0fbe0d14ec5b00         -movsx ecx, byte ptr [0x5bec14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024212) /* 0x5bec14 */)));
    // 005bcada  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bcadc  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 005bcade  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005bcadf  8b1554ec5b00           -mov edx, dword ptr [0x5bec54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024276) /* 0x5bec54 */);
    // 005bcae5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bcae6  8b0d0cec5b00           -mov ecx, dword ptr [0x5bec0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bcaec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bcaed  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005bcaf0:
    // 005bcaf0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005bcaf2  7473                   -je 0x5bcb67
    if (cpu.flags.zf)
    {
        goto L_0x005bcb67;
    }
    // 005bcaf4  8b3518ec5b00           -mov esi, dword ptr [0x5bec18]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6024216) /* 0x5bec18 */);
    // 005bcafa  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 005bcafc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bcafe  893518ec5b00           -mov dword ptr [0x5bec18], esi
    app->getMemory<x86::reg32>(x86::reg32(6024216) /* 0x5bec18 */) = cpu.esi;
    // 005bcb04  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bcb06  a10cec5b00             -mov eax, dword ptr [0x5bec0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bcb0b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bcb0d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bcb0f  6858ec5b00             -push 0x5bec58
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024280 /*0x5bec58*/;
    cpu.esp -= 4;
    // 005bcb14  0fbe0d14ec5b00         -movsx ecx, byte ptr [0x5bec14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024212) /* 0x5bec14 */)));
    // 005bcb1b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 005bcb1d  6854ec5b00             -push 0x5bec54
    app->getMemory<x86::reg32>(cpu.esp-4) = 6024276 /*0x5bec54*/;
    cpu.esp -= 4;
    // 005bcb22  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 005bcb24  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bcb25  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bcb27  8b2d0cec5b00           -mov ebp, dword ptr [0x5bec0c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bcb2d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005bcb2e  ff502c                 -call dword ptr [eax + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005bcb31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005bcb33  750c                   -jne 0x5bcb41
    if (!cpu.flags.zf)
    {
        goto L_0x005bcb41;
    }
    // 005bcb35  a154ec5b00             -mov eax, dword ptr [0x5bec54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024276) /* 0x5bec54 */);
    // 005bcb3a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 005bcb3c  e88ffbffff             -call 0x5bc6d0
    cpu.esp -= 4;
    sub_5bc6d0(app, cpu);
    if (cpu.terminate) return;
L_0x005bcb41:
    // 005bcb41  a10cec5b00             -mov eax, dword ptr [0x5bec0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bcb46  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005bcb48  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bcb4a  0fbe0d14ec5b00         -movsx ecx, byte ptr [0x5bec14]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(6024212) /* 0x5bec14 */)));
    // 005bcb51  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005bcb53  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 005bcb55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005bcb56  8b1554ec5b00           -mov edx, dword ptr [0x5bec54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6024276) /* 0x5bec54 */);
    // 005bcb5c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005bcb5d  8b0d0cec5b00           -mov ecx, dword ptr [0x5bec0c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6024204) /* 0x5bec0c */);
    // 005bcb63  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bcb64  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005bcb67:
    // 005bcb67  891d2cec5b00           -mov dword ptr [0x5bec2c], ebx
    app->getMemory<x86::reg32>(x86::reg32(6024236) /* 0x5bec2c */) = cpu.ebx;
    // 005bcb6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bcb6e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005bcb71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bcb72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bcb73  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bcb74  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bcb75  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bcb76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_5bcb77(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bcb77  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bcb78  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 005bcb7a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005bcb7b  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 005bcb7d  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 005bcb80  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 005bcb82  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 005bcb85  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 005bcb87  e804000000             -call 0x5bcb90
    cpu.esp -= 4;
    sub_5bcb90(app, cpu);
    if (cpu.terminate) return;
    // 005bcb8c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bcb8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bcb8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_5bcb90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bcb90  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 005bcb92  742c                   -je 0x5bcbc0
    if (cpu.flags.zf)
    {
        goto L_0x005bcbc0;
    }
    // 005bcb94  3810                   -cmp byte ptr [eax], dl
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
L_0x005bcb96:
    // 005bcb96  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 005bcb98  7409                   -je 0x5bcba3
    if (cpu.flags.zf)
    {
        goto L_0x005bcba3;
    }
    // 005bcb9a  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 005bcb9c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005bcb9d  c1ca08                 +ror edx, 8
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
    // 005bcba0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcba1  75f3                   -jne 0x5bcb96
    if (!cpu.flags.zf)
    {
        goto L_0x005bcb96;
    }
L_0x005bcba3:
    // 005bcba3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bcba4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 005bcba7  e81b000000             -call 0x5bcbc7
    cpu.esp -= 4;
    sub_5bcbc7(app, cpu);
    if (cpu.terminate) return;
    // 005bcbac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bcbad  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 005bcbb0  740e                   -je 0x5bcbc0
    if (cpu.flags.zf)
    {
        goto L_0x005bcbc0;
    }
    // 005bcbb2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 005bcbb4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcbb5  7409                   -je 0x5bcbc0
    if (cpu.flags.zf)
    {
        goto L_0x005bcbc0;
    }
    // 005bcbb7  887001                 -mov byte ptr [eax + 1], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 005bcbba  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcbbb  7403                   -je 0x5bcbc0
    if (cpu.flags.zf)
    {
        goto L_0x005bcbc0;
    }
    // 005bcbbd  885002                 -mov byte ptr [eax + 2], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x005bcbc0:
    // 005bcbc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_5bcbc2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bcbc2  90                     -nop 
    ;
    // 005bcbc3  90                     -nop 
    ;
    // 005bcbc4  90                     -nop 
    ;
    // 005bcbc5  90                     -nop 
    ;
    // 005bcbc6  90                     -nop 
    ;
    // 005bcbc7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 005bcbc9  7467                   -je 0x5bcc32
    if (cpu.flags.zf)
    {
        goto L_0x005bcc32;
    }
L_0x005bcbcb:
    // 005bcbcb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 005bcbcd  7408                   -je 0x5bcbd7
    if (cpu.flags.zf)
    {
        goto L_0x005bcbd7;
    }
    // 005bcbcf  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005bcbd1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005bcbd4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcbd5  75f4                   -jne 0x5bcbcb
    if (!cpu.flags.zf)
    {
        goto L_0x005bcbcb;
    }
L_0x005bcbd7:
    // 005bcbd7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bcbd8  c1e902                 +shr ecx, 2
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
    // 005bcbdb  743a                   -je 0x5bcc17
    if (cpu.flags.zf)
    {
        goto L_0x005bcc17;
    }
    // 005bcbdd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcbde  7429                   -je 0x5bcc09
    if (cpu.flags.zf)
    {
        goto L_0x005bcc09;
    }
L_0x005bcbe0:
    // 005bcbe0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005bcbe2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005bcbe5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcbe6  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005bcbe9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 005bcbec  7418                   -je 0x5bcc06
    if (cpu.flags.zf)
    {
        goto L_0x005bcc06;
    }
    // 005bcbee  385020                 +cmp byte ptr [eax + 0x20], dl
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
    // 005bcbf1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 005bcbf4  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005bcbf7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcbf8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005bcbfb  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 005bcbfe  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 005bcc01  75dd                   -jne 0x5bcbe0
    if (!cpu.flags.zf)
    {
        goto L_0x005bcbe0;
    }
    // 005bcc03  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x005bcc06:
    // 005bcc06  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x005bcc09:
    // 005bcc09  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005bcc0b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005bcc0e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005bcc11  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 005bcc14  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x005bcc17:
    // 005bcc17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bcc18  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 005bcc1b  7415                   -je 0x5bcc32
    if (cpu.flags.zf)
    {
        goto L_0x005bcc32;
    }
    // 005bcc1d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005bcc1f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005bcc22  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcc23  740d                   -je 0x5bcc32
    if (cpu.flags.zf)
    {
        goto L_0x005bcc32;
    }
    // 005bcc25  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005bcc27  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005bcc2a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcc2b  7405                   -je 0x5bcc32
    if (cpu.flags.zf)
    {
        goto L_0x005bcc32;
    }
    // 005bcc2d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005bcc2f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x005bcc32:
    // 005bcc32  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_5bcbc7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x005bcbc7;
    // 005bcbc2  90                     -nop 
    ;
    // 005bcbc3  90                     -nop 
    ;
    // 005bcbc4  90                     -nop 
    ;
    // 005bcbc5  90                     -nop 
    ;
    // 005bcbc6  90                     -nop 
    ;
L_entry_0x005bcbc7:
    // 005bcbc7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 005bcbc9  7467                   -je 0x5bcc32
    if (cpu.flags.zf)
    {
        goto L_0x005bcc32;
    }
L_0x005bcbcb:
    // 005bcbcb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 005bcbcd  7408                   -je 0x5bcbd7
    if (cpu.flags.zf)
    {
        goto L_0x005bcbd7;
    }
    // 005bcbcf  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005bcbd1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005bcbd4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcbd5  75f4                   -jne 0x5bcbcb
    if (!cpu.flags.zf)
    {
        goto L_0x005bcbcb;
    }
L_0x005bcbd7:
    // 005bcbd7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005bcbd8  c1e902                 +shr ecx, 2
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
    // 005bcbdb  743a                   -je 0x5bcc17
    if (cpu.flags.zf)
    {
        goto L_0x005bcc17;
    }
    // 005bcbdd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcbde  7429                   -je 0x5bcc09
    if (cpu.flags.zf)
    {
        goto L_0x005bcc09;
    }
L_0x005bcbe0:
    // 005bcbe0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005bcbe2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005bcbe5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcbe6  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005bcbe9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 005bcbec  7418                   -je 0x5bcc06
    if (cpu.flags.zf)
    {
        goto L_0x005bcc06;
    }
    // 005bcbee  385020                 +cmp byte ptr [eax + 0x20], dl
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
    // 005bcbf1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 005bcbf4  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005bcbf7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcbf8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005bcbfb  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 005bcbfe  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 005bcc01  75dd                   -jne 0x5bcbe0
    if (!cpu.flags.zf)
    {
        goto L_0x005bcbe0;
    }
    // 005bcc03  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x005bcc06:
    // 005bcc06  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x005bcc09:
    // 005bcc09  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005bcc0b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005bcc0e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005bcc11  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 005bcc14  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x005bcc17:
    // 005bcc17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005bcc18  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 005bcc1b  7415                   -je 0x5bcc32
    if (cpu.flags.zf)
    {
        goto L_0x005bcc32;
    }
    // 005bcc1d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005bcc1f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005bcc22  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcc23  740d                   -je 0x5bcc32
    if (cpu.flags.zf)
    {
        goto L_0x005bcc32;
    }
    // 005bcc25  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005bcc27  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005bcc2a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005bcc2b  7405                   -je 0x5bcc32
    if (cpu.flags.zf)
    {
        goto L_0x005bcc32;
    }
    // 005bcc2d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005bcc2f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x005bcc32:
    // 005bcc32  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_5bcc34(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bcc34  ff2530da5b00           -jmp dword ptr [0x5bda30]
    return app->dynamic_call(app->getMemory<x86::reg32>(6019632), cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_5bcc40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005bcc40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc60  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc62  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc64  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc66  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc68  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc6a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc6c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc6e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc70  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc72  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc78  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc7c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc7e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc80  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc82  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc90  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc92  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc94  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc96  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc98  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc9a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc9c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcc9e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcca0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcca2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcca4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcca6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcca8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccaa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccb0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccb2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccb4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccb6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccb8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccbc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccbe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccc0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccc2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccc4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccc6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccc8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcccc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccd0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccd2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccd4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccd6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccd8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccdc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccde  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcce0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcce2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcce4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcce6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcce8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccf0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccf2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccf4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccf6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccf8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccfa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccfc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bccfe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd00  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd02  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd04  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd06  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd08  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd0a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd0c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd0e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd10  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd12  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd14  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd16  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd18  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd1a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd1c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd1e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd20  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd22  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd24  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd26  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd28  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd2a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd2c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd2e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd60  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd62  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd64  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd66  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd68  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd6a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd6c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd6e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd70  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd72  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd78  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd7c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd7e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd80  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd82  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd90  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd92  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd94  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd96  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd98  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd9a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd9c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcd9e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcda0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcda2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcda4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcda6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcda8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdaa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdb0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdb2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdb4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdb6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdb8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdbc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdbe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdc0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdc2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdc4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdc6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdc8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdcc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdd0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdd2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdd4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdd6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdd8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcddc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdde  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcde0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcde2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcde4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcde6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcde8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdf0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdf2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdf4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdf6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdf8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdfa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdfc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005bcdfe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
}

}
