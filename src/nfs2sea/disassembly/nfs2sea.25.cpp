#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x90 */
void Application::sub_49bfb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049bfb4);
    // 0049bfb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bfb5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bfb6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bfb9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049bfbb  b9a0ea5600             -mov ecx, 0x56eaa0
    cpu.ecx = 5696160 /*0x56eaa0*/;
    // 0049bfc0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049bfc3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bfc5  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049bfc7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049bfc9  7e41                   -jle 0x49c00c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c00c;
    }
    // 0049bfcb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0049bfcd:
    // 0049bfcd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bfcf  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049bfd2  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0049bfd5  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049bfd8  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0049bfdb  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049bfdd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bfdf  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049bfe2  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0049bfe5  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049bfe8  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0049bfeb  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0049bfee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bff0  43                     -inc ebx
    (cpu.ebx)++;
    // 0049bff1  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049bff3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bff6  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0049bff9  43                     -inc ebx
    (cpu.ebx)++;
    // 0049bffa  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049bffd  43                     -inc ebx
    (cpu.ebx)++;
    // 0049bffe  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0049c001  42                     -inc edx
    (cpu.edx)++;
    // 0049c002  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0049c005  39f2                   +cmp edx, esi
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
    // 0049c007  7cc4                   -jl 0x49bfcd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bfcd;
    }
    // 0049c009  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049c00c:
    // 0049c00c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c00f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c010  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c011  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c020);
    // 0049c020  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c021  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049c023  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0049c025  39d0                   +cmp eax, edx
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
    // 0049c027  7e0b                   -jle 0x49c034
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c034;
    }
    // 0049c029  39c8                   +cmp eax, ecx
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
    // 0049c02b  7c0e                   -jl 0x49c03b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c03b;
    }
    // 0049c02d  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0049c032  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c033  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c034:
    // 0049c034  b800ffffff             -mov eax, 0xffffff00
    cpu.eax = 4294967040 /*0xffffff00*/;
    // 0049c039  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c03a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c03b:
    // 0049c03b  c1e00e                 -shl eax, 0xe
    cpu.eax <<= 14 /*0xe*/ % 32;
    // 0049c03e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049c040  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c043  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c045  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049c048  e803000000             -call 0x49c050
    cpu.esp -= 4;
    sub_49c050(app, cpu);
    if (cpu.terminate) return;
    // 0049c04d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c04e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c050);
    // 0049c050  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c051  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c052  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c053  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c055  7c25                   -jl 0x49c07c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c07c;
    }
    // 0049c057  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0049c059:
    // 0049c059  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049c05b  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 0049c05e  3d00fa0000             +cmp eax, 0xfa00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64000 /*0xfa00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c063  7f20                   -jg 0x49c085
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c085;
    }
    // 0049c065  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 0049c067  7401                   -je 0x49c06a
    if (cpu.flags.zf)
    {
        goto L_0x0049c06a;
    }
    // 0049c069  42                     -inc edx
    (cpu.edx)++;
L_0x0049c06a:
    // 0049c06a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c06c  8a82d0df4d00           -mov al, byte ptr [edx + 0x4ddfd0]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5103568) /* 0x4ddfd0 */);
    // 0049c072  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c074  7402                   -je 0x49c078
    if (cpu.flags.zf)
    {
        goto L_0x0049c078;
    }
    // 0049c076  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0049c078:
    // 0049c078  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c079  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c07a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c07b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c07c:
    // 0049c07c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049c081  f7d8                   +neg eax
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.eax;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0049c083  ebd4                   -jmp 0x49c059
    goto L_0x0049c059;
L_0x0049c085:
    // 0049c085  3d00000100             +cmp eax, 0x10000
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
    // 0049c08a  7c0f                   -jl 0x49c09b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c09b;
    }
    // 0049c08c  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0049c091  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c093  74e3                   -je 0x49c078
    if (cpu.flags.zf)
    {
        goto L_0x0049c078;
    }
    // 0049c095  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049c097  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c098  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c099  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c09a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c09b:
    // 0049c09b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c09d  83e17f                 -and ecx, 0x7f
    cpu.ecx &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049c0a0  81faff010000           +cmp edx, 0x1ff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(511 /*0x1ff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c0a6  7520                   -jne 0x49c0c8
    if (!cpu.flags.zf)
    {
        goto L_0x0049c0c8;
    }
    // 0049c0a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c0aa  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0049c0af  a0cfe14d00             -mov al, byte ptr [0x4de1cf]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5104079) /* 0x4de1cf */);
    // 0049c0b4  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c0b6  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049c0b9  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 0049c0bc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049c0be  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c0c0  74b6                   -je 0x49c078
    if (cpu.flags.zf)
    {
        goto L_0x0049c078;
    }
    // 0049c0c2  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049c0c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c0c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c0c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c0c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c0c8:
    // 0049c0c8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c0c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c0cb  0fb6b2d1df4d00         -movzx esi, byte ptr [edx + 0x4ddfd1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5103569) /* 0x4ddfd1 */));
    // 0049c0d2  8a82d0df4d00           -mov al, byte ptr [edx + 0x4ddfd0]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5103568) /* 0x4ddfd0 */);
    // 0049c0d8  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c0da  0fafce                 -imul ecx, esi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0049c0dd  c1f907                 -sar ecx, 7
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (7 /*0x7*/ % 32));
    // 0049c0e0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c0e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c0e3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c0e5  7491                   -je 0x49c078
    if (cpu.flags.zf)
    {
        goto L_0x0049c078;
    }
    // 0049c0e7  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0049c0e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c0ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c0eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c0ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c0f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c0f0);
    // 0049c0f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c0f1  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0049c0f6  e855ffffff             -call 0x49c050
    cpu.esp -= 4;
    sub_49c050(app, cpu);
    if (cpu.terminate) return;
    // 0049c0fb  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c0fd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c0ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c100  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c110);
    // 0049c110  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c111  8b0d288a4d00           -mov ecx, dword ptr [0x4d8a28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081640) /* 0x4d8a28 */);
    // 0049c117  a3308a4d00             -mov dword ptr [0x4d8a30], eax
    app->getMemory<x86::reg32>(x86::reg32(5081648) /* 0x4d8a30 */) = cpu.eax;
    // 0049c11c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c11e  a3388a4d00             -mov dword ptr [0x4d8a38], eax
    app->getMemory<x86::reg32>(x86::reg32(5081656) /* 0x4d8a38 */) = cpu.eax;
    // 0049c123  a12c8a4d00             -mov eax, dword ptr [0x4d8a2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081644) /* 0x4d8a2c */);
    // 0049c128  8915348a4d00           -mov dword ptr [0x4d8a34], edx
    app->getMemory<x86::reg32>(x86::reg32(5081652) /* 0x4d8a34 */) = cpu.edx;
    // 0049c12e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c130  89153c8a4d00           -mov dword ptr [0x4d8a3c], edx
    app->getMemory<x86::reg32>(x86::reg32(5081660) /* 0x4d8a3c */) = cpu.edx;
    // 0049c136  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c137  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c138(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c138);
    // 0049c138  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c139  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c13a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049c13c  8915508a4d00           -mov dword ptr [0x4d8a50], edx
    app->getMemory<x86::reg32>(x86::reg32(5081680) /* 0x4d8a50 */) = cpu.edx;
    // 0049c142  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 0049c144  8b15308a4d00           -mov edx, dword ptr [0x4d8a30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081648) /* 0x4d8a30 */);
    // 0049c14a  a34c8a4d00             -mov dword ptr [0x4d8a4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5081676) /* 0x4d8a4c */) = cpu.eax;
    // 0049c14f  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c151  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0049c153  8915388a4d00           -mov dword ptr [0x4d8a38], edx
    app->getMemory<x86::reg32>(x86::reg32(5081656) /* 0x4d8a38 */) = cpu.edx;
    // 0049c159  8b15348a4d00           -mov edx, dword ptr [0x4d8a34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081652) /* 0x4d8a34 */);
    // 0049c15f  891d288a4d00           -mov dword ptr [0x4d8a28], ebx
    app->getMemory<x86::reg32>(x86::reg32(5081640) /* 0x4d8a28 */) = cpu.ebx;
    // 0049c165  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c167  890d2c8a4d00           -mov dword ptr [0x4d8a2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5081644) /* 0x4d8a2c */) = cpu.ecx;
    // 0049c16d  89153c8a4d00           -mov dword ptr [0x4d8a3c], edx
    app->getMemory<x86::reg32>(x86::reg32(5081660) /* 0x4d8a3c */) = cpu.edx;
    // 0049c173  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0049c179  c0e507                 +shl ch, 7
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
    // 0049c17c  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049c17e  00ed                   +add ch, ch
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
    // 0049c180  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049c182  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c184  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049c189  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c18b  8b0485d0944d00         -mov eax, dword ptr [eax*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 0049c192  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c194  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c196  8b1d288a4d00           -mov ebx, dword ptr [0x4d8a28]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081640) /* 0x4d8a28 */);
    // 0049c19c  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049c19f  a14c8a4d00             -mov eax, dword ptr [0x4d8a4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081676) /* 0x4d8a4c */);
    // 0049c1a4  c0e407                 +shl ah, 7
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
    // 0049c1a7  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049c1a9  00e4                   +add ah, ah
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
    // 0049c1ab  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049c1ad  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c1af  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049c1b4  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c1b6  8b0485d0944d00         -mov eax, dword ptr [eax*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 0049c1bd  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c1bf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c1c1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c1c3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c1c5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c1c7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c1ca  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c1cc  a3408a4d00             -mov dword ptr [0x4d8a40], eax
    app->getMemory<x86::reg32>(x86::reg32(5081664) /* 0x4d8a40 */) = cpu.eax;
    // 0049c1d1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c1d3  746a                   -je 0x49c23f
    if (cpu.flags.zf)
    {
        goto L_0x0049c23f;
    }
    // 0049c1d5  a1508a4d00             -mov eax, dword ptr [0x4d8a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081680) /* 0x4d8a50 */);
    // 0049c1da  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0049c1e0  c0e507                 +shl ch, 7
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
    // 0049c1e3  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049c1e5  00ed                   +add ch, ch
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
    // 0049c1e7  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049c1e9  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c1eb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049c1f0  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c1f2  8b0485d0944d00         -mov eax, dword ptr [eax*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 0049c1f9  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c1fb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c1fd  8b152c8a4d00           -mov edx, dword ptr [0x4d8a2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081644) /* 0x4d8a2c */);
    // 0049c203  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c205  0fafda                 -imul ebx, edx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049c208  a1508a4d00             -mov eax, dword ptr [0x4d8a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081680) /* 0x4d8a50 */);
    // 0049c20d  c0e407                 +shl ah, 7
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
    // 0049c210  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049c212  00e4                   +add ah, ah
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
    // 0049c214  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049c216  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c218  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049c21d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c21f  8b0485d0944d00         -mov eax, dword ptr [eax*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 0049c226  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c228  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c22a  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0049c22c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c22e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c230  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c232  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c235  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c237  a3448a4d00             -mov dword ptr [0x4d8a44], eax
    app->getMemory<x86::reg32>(x86::reg32(5081668) /* 0x4d8a44 */) = cpu.eax;
    // 0049c23c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c23d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c23e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c23f:
    // 0049c23f  8b15548a4d00           -mov edx, dword ptr [0x4d8a54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081684) /* 0x4d8a54 */);
    // 0049c245  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049c247  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049c24a  c1e810                 +shr eax, 0x10
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
    // 0049c24d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049c24f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049c251  8b152c8a4d00           -mov edx, dword ptr [0x4d8a2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081644) /* 0x4d8a2c */);
    // 0049c257  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 0049c259  a3448a4d00             -mov dword ptr [0x4d8a44], eax
    app->getMemory<x86::reg32>(x86::reg32(5081668) /* 0x4d8a44 */) = cpu.eax;
    // 0049c25e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049c260  892d448a4d00           -mov dword ptr [0x4d8a44], ebp
    app->getMemory<x86::reg32>(x86::reg32(5081668) /* 0x4d8a44 */) = cpu.ebp;
    // 0049c266  e8e5c4ffff             -call 0x498750
    cpu.esp -= 4;
    sub_498750(app, cpu);
    if (cpu.terminate) return;
    // 0049c26b  a3508a4d00             -mov dword ptr [0x4d8a50], eax
    app->getMemory<x86::reg32>(x86::reg32(5081680) /* 0x4d8a50 */) = cpu.eax;
    // 0049c270  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c271  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c272  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c274(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c274);
    // 0049c274  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c275  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c276  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c278  c1e20a                 -shl edx, 0xa
    cpu.edx <<= 10 /*0xa*/ % 32;
    // 0049c27b  be68010000             -mov esi, 0x168
    cpu.esi = 360 /*0x168*/;
    // 0049c280  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c282  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c285  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c287  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049c289  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c28b  c1e20a                 -shl edx, 0xa
    cpu.edx <<= 10 /*0xa*/ % 32;
    // 0049c28e  bf68010000             -mov edi, 0x168
    cpu.edi = 360 /*0x168*/;
    // 0049c293  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c295  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c298  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c29a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049c29c  e897feffff             -call 0x49c138
    cpu.esp -= 4;
    sub_49c138(app, cpu);
    if (cpu.terminate) return;
    // 0049c2a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c2a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c2a4);
    // 0049c2a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c2a5  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 0049c2a9  7e46                   -jle 0x49c2f1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c2f1;
    }
    // 0049c2ab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c2ac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c2ad  8b0d408a4d00           -mov ecx, dword ptr [0x4d8a40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081664) /* 0x4d8a40 */);
    // 0049c2b3  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049c2b5  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049c2b8  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049c2bb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c2bd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c2c0  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c2c2  8b15388a4d00           -mov edx, dword ptr [0x4d8a38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081656) /* 0x4d8a38 */);
    // 0049c2c8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049c2ca  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0049c2cc  8b2d448a4d00           -mov ebp, dword ptr [0x4d8a44]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5081668) /* 0x4d8a44 */);
    // 0049c2d2  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049c2d5  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0049c2d8  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049c2db  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c2dd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c2e0  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c2e2  8b153c8a4d00           -mov edx, dword ptr [0x4d8a3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081660) /* 0x4d8a3c */);
    // 0049c2e8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049c2ea  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049c2ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c2f1:
    // 0049c2f1  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 0049c2f8  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049c2fb  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0049c2fd  800d488a4d0001         -or byte ptr [0x4d8a48], 1
    app->getMemory<x86::reg8>(x86::reg32(5081672) /* 0x4d8a48 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0049c304  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c305  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c306(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c306);
    // 0049c306  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c307  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c308  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049c309  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 0049c30b  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 0049c30d  c8080000               -enter 8, 0
    {
        cpu.esp -= 4;
        app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
        cpu.ebp = cpu.esp;
        cpu.esp -= 8;
    }
    // 0049c311  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c313  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049c315  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c317  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0049c31a  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0049c31d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c31f  744f                   -je 0x49c370
    if (cpu.flags.zf)
    {
        goto L_0x0049c370;
    }
    // 0049c321  48                     -dec eax
    (cpu.eax)--;
    // 0049c322  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049c325  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049c327  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c329  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
L_0x0049c32c:
    // 0049c32c  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c32f  732c                   -jae 0x49c35d
    if (!cpu.flags.cf)
    {
        goto L_0x0049c35d;
    }
    // 0049c331  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c334  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c336  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c338  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049c33a  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 0049c33c  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0049c33f  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0049c342  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c344  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c346  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c349  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c34b  7504                   -jne 0x49c351
    if (!cpu.flags.zf)
    {
        goto L_0x0049c351;
    }
    // 0049c34d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c34f  eb1f                   -jmp 0x49c370
    goto L_0x0049c370;
L_0x0049c351:
    // 0049c351  7d05                   -jge 0x49c358
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c358;
    }
    // 0049c353  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0049c356  ebd4                   -jmp 0x49c32c
    goto L_0x0049c32c;
L_0x0049c358:
    // 0049c358  8d1c31                 -lea ebx, [ecx + esi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 0049c35b  ebcf                   -jmp 0x49c32c
    goto L_0x0049c32c;
L_0x0049c35d:
    // 0049c35d  750f                   -jne 0x49c36e
    if (!cpu.flags.zf)
    {
        goto L_0x0049c36e;
    }
    // 0049c35f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c361  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c363  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c366  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c368  7504                   -jne 0x49c36e
    if (!cpu.flags.zf)
    {
        goto L_0x0049c36e;
    }
    // 0049c36a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c36c  eb02                   -jmp 0x49c370
    goto L_0x0049c370;
L_0x0049c36e:
    // 0049c36e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049c370:
    // 0049c370  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c371  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c373  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c375  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c376  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c377  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c378  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_49c37b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c37b);
    // 0049c37b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c37c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c37d  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049c37e  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 0049c380  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 0049c382  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c384  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049c386  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c388  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c38a  7e1c                   -jle 0x49c3a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c3a8;
    }
    // 0049c38c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c38e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c390  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c392  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c394  7e0e                   -jle 0x49c3a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c3a4;
    }
    // 0049c396  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c398  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c39a  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c39c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c39e  7f1c                   -jg 0x49c3bc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c3bc;
    }
L_0x0049c3a0:
    // 0049c3a0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c3a2  eb1a                   -jmp 0x49c3be
    goto L_0x0049c3be;
L_0x0049c3a4:
    // 0049c3a4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c3a6  eb16                   -jmp 0x49c3be
    goto L_0x0049c3be;
L_0x0049c3a8:
    // 0049c3a8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c3aa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c3ac  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c3ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c3b0  7df2                   -jge 0x49c3a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c3a4;
    }
    // 0049c3b2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c3b4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c3b6  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c3b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c3ba  7fe4                   -jg 0x49c3a0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c3a0;
    }
L_0x0049c3bc:
    // 0049c3bc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049c3be:
    // 0049c3be  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c3c0  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c3c2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c3c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c3be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c3be);
    goto L_entry_0x0049c3be;
    // 0049c37b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c37c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c37d  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049c37e  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 0049c380  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 0049c382  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c384  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049c386  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c388  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c38a  7e1c                   -jle 0x49c3a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c3a8;
    }
    // 0049c38c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c38e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c390  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c392  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c394  7e0e                   -jle 0x49c3a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c3a4;
    }
    // 0049c396  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c398  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c39a  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c39c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c39e  7f1c                   -jg 0x49c3bc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c3bc;
    }
L_0x0049c3a0:
    // 0049c3a0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c3a2  eb1a                   -jmp 0x49c3be
    goto L_0x0049c3be;
L_0x0049c3a4:
    // 0049c3a4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c3a6  eb16                   -jmp 0x49c3be
    goto L_0x0049c3be;
L_0x0049c3a8:
    // 0049c3a8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c3aa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c3ac  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c3ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c3b0  7df2                   -jge 0x49c3a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c3a4;
    }
    // 0049c3b2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c3b4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c3b6  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c3b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c3ba  7fe4                   -jg 0x49c3a0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c3a0;
    }
L_0x0049c3bc:
    // 0049c3bc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049c3be:
L_entry_0x0049c3be:
    // 0049c3be  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c3c0  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c3c2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c3c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c3c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c3c6);
    // 0049c3c6  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049c3c7  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 0049c3c8  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c3c9  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 0049c3cc  c1e902                 +shr ecx, 2
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
    // 0049c3cf  740b                   -je 0x49c3dc
    if (cpu.flags.zf)
    {
        goto L_0x0049c3dc;
    }
L_0x0049c3d1:
    // 0049c3d1  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049c3d3  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esi);
        app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 0049c3d5  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0049c3d6  83c604                 +add esi, 4
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
    // 0049c3d9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049c3da  75f5                   -jne 0x49c3d1
    if (!cpu.flags.zf)
    {
        goto L_0x0049c3d1;
    }
L_0x0049c3dc:
    // 0049c3dc  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049c3df  7409                   -je 0x49c3ea
    if (cpu.flags.zf)
    {
        goto L_0x0049c3ea;
    }
L_0x0049c3e1:
    // 0049c3e1  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0049c3e3  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = app->getMemory<x86::reg8>(cpu.esi);
        app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 0049c3e5  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 0049c3e6  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049c3e7  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049c3e8  75f7                   -jne 0x49c3e1
    if (!cpu.flags.zf)
    {
        goto L_0x0049c3e1;
    }
L_0x0049c3ea:
    // 0049c3ea  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c3eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c3ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c3ec);
    // 0049c3ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c3ed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c3ee  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049c3ef  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 0049c3f1  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 0049c3f3  c84c0100               -enter 0x14c, 0
    {
        cpu.esp -= 4;
        app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
        cpu.ebp = cpu.esp;
        cpu.esp -= 332;
    }
    // 0049c3f7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c3f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c3f9  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049c3fc  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c3fe  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 0049c401  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 0049c403  7407                   -je 0x49c40c
    if (cpu.flags.zf)
    {
        goto L_0x0049c40c;
    }
    // 0049c405  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049c40a  eb09                   -jmp 0x49c415
    goto L_0x0049c415;
L_0x0049c40c:
    // 0049c40c  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c40f  0f97c0                 -seta al
    cpu.al = (!cpu.flags.cf && !cpu.flags.zf);
    // 0049c412  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
L_0x0049c415:
    // 0049c415  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 0049c418  6b85acfeffff03         -imul eax, dword ptr [ebp - 0x154], 3
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))) * x86::sreg64(x86::sreg32(3 /*0x3*/)));
    // 0049c41f  8945c4                 -mov dword ptr [ebp - 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.eax;
    // 0049c422  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049c428  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c42a  c745e400000000         -mov dword ptr [ebp - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 0049c431  8945bc                 -mov dword ptr [ebp - 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.eax;
L_0x0049c434:
    // 0049c434  83bdb0feffff01         +cmp dword ptr [ebp - 0x150], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c43b  0f8688000000           -jbe 0x49c4c9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c4c9;
    }
    // 0049c441  83bdb0feffff10         +cmp dword ptr [ebp - 0x150], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c448  0f83a7000000           -jae 0x49c4f5
    if (!cpu.flags.cf)
    {
        goto L_0x0049c4f5;
    }
    // 0049c44e  8b45c4                 -mov eax, dword ptr [ebp - 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 0049c451  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0049c454  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 0049c45a  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 0049c461  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c464  01c2                   +add edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c466  8955c0                 -mov dword ptr [ebp - 0x40], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edx;
    // 0049c469  eb58                   -jmp 0x49c4c3
    goto L_0x0049c4c3;
L_0x0049c46b:
    // 0049c46b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c46e  0345e0                 +add eax, dword ptr [ebp - 0x20]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c471  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 0049c474  eb3f                   -jmp 0x49c4b5
    goto L_0x0049c4b5;
L_0x0049c476:
    // 0049c476  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c478  eb20                   -jmp 0x49c49a
    goto L_0x0049c49a;
L_0x0049c47a:
    // 0049c47a  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c47e  740f                   -je 0x49c48f
    if (cpu.flags.zf)
    {
        goto L_0x0049c48f;
    }
    // 0049c480  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049c486  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049c488  e839ffffff             -call 0x49c3c6
    cpu.esp -= 4;
    sub_49c3c6(app, cpu);
    if (cpu.terminate) return;
    // 0049c48d  eb08                   -jmp 0x49c497
    goto L_0x0049c497;
L_0x0049c48f:
    // 0049c48f  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049c491  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049c493  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0049c495  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x0049c497:
    // 0049c497  2b5de0                 -sub ebx, dword ptr [ebp - 0x20]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
L_0x0049c49a:
    // 0049c49a  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c49d  7610                   -jbe 0x49c4af
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c4af;
    }
    // 0049c49f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c4a1  2b7de0                 -sub edi, dword ptr [ebp - 0x20]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    // 0049c4a4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c4a6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c4a8  ff55e8                 -call dword ptr [ebp - 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c4ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c4ad  7fcb                   -jg 0x49c47a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c47a;
    }
L_0x0049c4af:
    // 0049c4af  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0049c4b2  0145d4                 -add dword ptr [ebp - 0x2c], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049c4b5:
    // 0049c4b5  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0049c4b8  3b45c0                 +cmp eax, dword ptr [ebp - 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c4bb  72b9                   -jb 0x49c476
    if (cpu.flags.cf)
    {
        goto L_0x0049c476;
    }
    // 0049c4bd  8b45bc                 -mov eax, dword ptr [ebp - 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 0049c4c0  2945e0                 -sub dword ptr [ebp - 0x20], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049c4c3:
    // 0049c4c3  837de000               +cmp dword ptr [ebp - 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c4c7  7fa2                   -jg 0x49c46b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c46b;
    }
L_0x0049c4c9:
    // 0049c4c9  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c4cd  0f843e030000           -je 0x49c811
    if (cpu.flags.zf)
    {
        goto L_0x0049c811;
    }
    // 0049c4d3  ff4de4                 +dec dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049c4d6  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049c4d9  8b9485b4feffff         -mov edx, dword ptr [ebp + eax*4 - 0x14c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-332) /* -0x14c */ + cpu.eax * 4);
    // 0049c4e0  8b848534ffffff         -mov eax, dword ptr [ebp + eax*4 - 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-204) /* -0xcc */ + cpu.eax * 4);
    // 0049c4e7  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0049c4ea  8985b0feffff           -mov dword ptr [ebp - 0x150], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */) = cpu.eax;
    // 0049c4f0  e93fffffff             -jmp 0x49c434
    goto L_0x0049c434;
L_0x0049c4f5:
    // 0049c4f5  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 0049c4fb  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 0049c4fd  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 0049c504  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c507  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c509  83bdb0feffff1d         +cmp dword ptr [ebp - 0x150], 0x1d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(29 /*0x1d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c510  0f8693000000           -jbe 0x49c5a9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c5a9;
    }
    // 0049c516  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c519  8945c8                 -mov dword ptr [ebp - 0x38], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.eax;
    // 0049c51c  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 0049c522  48                     -dec eax
    (cpu.eax)--;
    // 0049c523  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 0049c52a  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c52d  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c52f  83bdb0feffff2a         +cmp dword ptr [ebp - 0x150], 0x2a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c536  7660                   -jbe 0x49c598
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c598;
    }
    // 0049c538  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 0049c53e  8b95acfeffff           -mov edx, dword ptr [ebp - 0x154]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049c544  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0049c547  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049c54a  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c54d  8955d8                 -mov dword ptr [ebp - 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.edx;
    // 0049c550  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0049c553  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049c556  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c559  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 0049c55c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c55e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c561  0355d8                 -add edx, dword ptr [ebp - 0x28]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 0049c564  e812feffff             -call 0x49c37b
    cpu.esp -= 4;
    sub_49c37b(app, cpu);
    if (cpu.terminate) return;
    // 0049c569  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0049c56c  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049c56f  8945c8                 -mov dword ptr [ebp - 0x38], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.eax;
    // 0049c572  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049c574  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c576  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049c578  2b45d8                 -sub eax, dword ptr [ebp - 0x28]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 0049c57b  e8fbfdffff             -call 0x49c37b
    cpu.esp -= 4;
    sub_49c37b(app, cpu);
    if (cpu.terminate) return;
    // 0049c580  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049c583  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c585  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049c587  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049c589  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c58b  2b55d8                 -sub edx, dword ptr [ebp - 0x28]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 0049c58e  2b45b8                 -sub eax, dword ptr [ebp - 0x48]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */)));
    // 0049c591  e8e5fdffff             -call 0x49c37b
    cpu.esp -= 4;
    sub_49c37b(app, cpu);
    if (cpu.terminate) return;
    // 0049c596  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0049c598:
    // 0049c598  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049c59b  8b45c8                 -mov eax, dword ptr [ebp - 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0049c59e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049c5a0  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049c5a2  e8d4fdffff             -call 0x49c37b
    cpu.esp -= 4;
    sub_49c37b(app, cpu);
    if (cpu.terminate) return;
    // 0049c5a7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0049c5a9:
    // 0049c5a9  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c5ad  7424                   -je 0x49c5d3
    if (cpu.flags.zf)
    {
        goto L_0x0049c5d3;
    }
    // 0049c5af  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c5b2  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 0049c5b5  740f                   -je 0x49c5c6
    if (cpu.flags.zf)
    {
        goto L_0x0049c5c6;
    }
    // 0049c5b7  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049c5bd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c5bf  e802feffff             -call 0x49c3c6
    cpu.esp -= 4;
    sub_49c3c6(app, cpu);
    if (cpu.terminate) return;
    // 0049c5c4  eb18                   -jmp 0x49c5de
    goto L_0x0049c5de;
L_0x0049c5c6:
    // 0049c5c6  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c5c9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049c5cb  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049c5cd  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049c5cf  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0049c5d1  eb0b                   -jmp 0x49c5de
    goto L_0x0049c5de;
L_0x0049c5d3:
    // 0049c5d3  8d45b4                 -lea eax, [ebp - 0x4c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0049c5d6  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 0049c5d9  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049c5db  8945b4                 -mov dword ptr [ebp - 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.eax;
L_0x0049c5de:
    // 0049c5de  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 0049c5e4  48                     -dec eax
    (cpu.eax)--;
    // 0049c5e5  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 0049c5ec  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c5ef  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0049c5f2  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0049c5f5  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 0049c5fb  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0049c5fe  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0049c601  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x0049c604:
    // 0049c604  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c608  7448                   -je 0x49c652
    if (cpu.flags.zf)
    {
        goto L_0x0049c652;
    }
    // 0049c60a  8b55d0                 -mov edx, dword ptr [ebp - 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0049c60d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c60f  ff55e8                 -call dword ptr [ebp - 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c612  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c614  7f3c                   -jg 0x49c652
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c652;
    }
    // 0049c616  752f                   -jne 0x49c647
    if (!cpu.flags.zf)
    {
        goto L_0x0049c647;
    }
    // 0049c618  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c61c  7412                   -je 0x49c630
    if (cpu.flags.zf)
    {
        goto L_0x0049c630;
    }
    // 0049c61e  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049c624  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c627  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c629  e898fdffff             -call 0x49c3c6
    cpu.esp -= 4;
    sub_49c3c6(app, cpu);
    if (cpu.terminate) return;
    // 0049c62e  eb0e                   -jmp 0x49c63e
    goto L_0x0049c63e;
L_0x0049c630:
    // 0049c630  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c633  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c636  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049c638  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049c63a  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0049c63c  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x0049c63e:
    // 0049c63e  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049c644  0145ec                 -add dword ptr [ebp - 0x14], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049c647:
    // 0049c647  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0049c64a  039dacfeffff           +add ebx, dword ptr [ebp - 0x154]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c650  ebb2                   -jmp 0x49c604
    goto L_0x0049c604;
L_0x0049c652:
    // 0049c652  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c656  7453                   -je 0x49c6ab
    if (cpu.flags.zf)
    {
        goto L_0x0049c6ab;
    }
    // 0049c658  8b55d0                 -mov edx, dword ptr [ebp - 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0049c65b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c65e  ff55e8                 -call dword ptr [ebp - 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c661  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c663  7c46                   -jl 0x49c6ab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c6ab;
    }
    // 0049c665  7536                   -jne 0x49c69d
    if (!cpu.flags.zf)
    {
        goto L_0x0049c69d;
    }
    // 0049c667  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c66b  7413                   -je 0x49c680
    if (cpu.flags.zf)
    {
        goto L_0x0049c680;
    }
    // 0049c66d  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049c673  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c676  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c679  e848fdffff             -call 0x49c3c6
    cpu.esp -= 4;
    sub_49c3c6(app, cpu);
    if (cpu.terminate) return;
    // 0049c67e  eb14                   -jmp 0x49c694
    goto L_0x0049c694;
L_0x0049c680:
    // 0049c680  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c683  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c686  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c689  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049c68b  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049c68d  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0049c68f  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c692  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x0049c694:
    // 0049c694  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049c69a  2945f0                 -sub dword ptr [ebp - 0x10], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049c69d:
    // 0049c69d  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049c6a3  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0049c6a6  2945f8                 +sub dword ptr [ebp - 8], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c6a9  eba7                   -jmp 0x49c652
    goto L_0x0049c652;
L_0x0049c6ab:
    // 0049c6ab  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c6af  7442                   -je 0x49c6f3
    if (cpu.flags.zf)
    {
        goto L_0x0049c6f3;
    }
    // 0049c6b1  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c6b5  7412                   -je 0x49c6c9
    if (cpu.flags.zf)
    {
        goto L_0x0049c6c9;
    }
    // 0049c6b7  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049c6bd  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c6c0  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049c6c2  e8fffcffff             -call 0x49c3c6
    cpu.esp -= 4;
    sub_49c3c6(app, cpu);
    if (cpu.terminate) return;
    // 0049c6c7  eb0e                   -jmp 0x49c6d7
    goto L_0x0049c6d7;
L_0x0049c6c9:
    // 0049c6c9  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c6cc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049c6ce  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049c6d0  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049c6d2  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c6d5  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x0049c6d7:
    // 0049c6d7  039dacfeffff           +add ebx, dword ptr [ebp - 0x154]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c6dd  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049c6e0  7411                   -je 0x49c6f3
    if (cpu.flags.zf)
    {
        goto L_0x0049c6f3;
    }
    // 0049c6e2  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049c6e8  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 0049c6eb  2945f8                 +sub dword ptr [ebp - 8], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c6ee  e911ffffff             -jmp 0x49c604
    goto L_0x0049c604;
L_0x0049c6f3:
    // 0049c6f3  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 0049c6f9  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 0049c700  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c703  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049c705  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c707  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c70a  2b4dec                 -sub ecx, dword ptr [ebp - 0x14]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 0049c70d  2b45fc                 -sub eax, dword ptr [ebp - 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0049c710  8955cc                 -mov dword ptr [ebp - 0x34], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.edx;
    // 0049c713  39c8                   +cmp eax, ecx
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
    // 0049c715  7d02                   -jge 0x49c719
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c719;
    }
    // 0049c717  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0049c719:
    // 0049c719  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049c71b  762c                   -jbe 0x49c749
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c749;
    }
    // 0049c71d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c71f  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c722  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c724  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049c725  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 0049c726  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c727  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 0049c72a  c1e902                 +shr ecx, 2
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
    // 0049c72d  740b                   -je 0x49c73a
    if (cpu.flags.zf)
    {
        goto L_0x0049c73a;
    }
L_0x0049c72f:
    // 0049c72f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049c731  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esi);
        app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 0049c733  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0049c734  83c604                 +add esi, 4
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
    // 0049c737  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049c738  75f5                   -jne 0x49c72f
    if (!cpu.flags.zf)
    {
        goto L_0x0049c72f;
    }
L_0x0049c73a:
    // 0049c73a  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049c73d  7409                   -je 0x49c748
    if (cpu.flags.zf)
    {
        goto L_0x0049c748;
    }
L_0x0049c73f:
    // 0049c73f  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0049c741  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = app->getMemory<x86::reg8>(cpu.esi);
        app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 0049c743  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 0049c744  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049c745  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049c746  75f7                   -jne 0x49c73f
    if (!cpu.flags.zf)
    {
        goto L_0x0049c73f;
    }
L_0x0049c748:
    // 0049c748  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x0049c749:
    // 0049c749  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0049c74c  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c74f  2b45f0                 -sub eax, dword ptr [ebp - 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 0049c752  2b4df8                 -sub ecx, dword ptr [ebp - 8]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0049c755  2b85acfeffff           -sub eax, dword ptr [ebp - 0x154]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
    // 0049c75b  39c1                   +cmp ecx, eax
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
    // 0049c75d  7202                   -jb 0x49c761
    if (cpu.flags.cf)
    {
        goto L_0x0049c761;
    }
    // 0049c75f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0049c761:
    // 0049c761  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049c763  762c                   -jbe 0x49c791
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c791;
    }
    // 0049c765  8b7dcc                 -mov edi, dword ptr [ebp - 0x34]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0049c768  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049c76a  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c76c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049c76d  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 0049c76e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049c76f  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 0049c772  c1e902                 +shr ecx, 2
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
    // 0049c775  740b                   -je 0x49c782
    if (cpu.flags.zf)
    {
        goto L_0x0049c782;
    }
L_0x0049c777:
    // 0049c777  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049c779  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esi);
        app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 0049c77b  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0049c77c  83c604                 +add esi, 4
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
    // 0049c77f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049c780  75f5                   -jne 0x49c777
    if (!cpu.flags.zf)
    {
        goto L_0x0049c777;
    }
L_0x0049c782:
    // 0049c782  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049c785  7409                   -je 0x49c790
    if (cpu.flags.zf)
    {
        goto L_0x0049c790;
    }
L_0x0049c787:
    // 0049c787  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0049c789  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = app->getMemory<x86::reg8>(cpu.esi);
        app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 0049c78b  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 0049c78c  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049c78d  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049c78e  75f7                   -jne 0x49c787
    if (!cpu.flags.zf)
    {
        goto L_0x0049c787;
    }
L_0x0049c790:
    // 0049c790  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x0049c791:
    // 0049c791  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c794  8b4dcc                 -mov ecx, dword ptr [ebp - 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0049c797  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049c799  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049c79c  2b75ec                 -sub esi, dword ptr [ebp - 0x14]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 0049c79f  2b7df8                 -sub edi, dword ptr [ebp - 8]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0049c7a2  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0049c7a5  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049c7a7  39f7                   +cmp edi, esi
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
    // 0049c7a9  7224                   -jb 0x49c7cf
    if (cpu.flags.cf)
    {
        goto L_0x0049c7cf;
    }
    // 0049c7ab  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c7ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c7af  f7b5acfeffff           -div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049c7b5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c7b7  89842b34ffffff         -mov dword ptr [ebx + ebp - 0xcc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-204) /* -0xcc */ + cpu.ebp * 1) = cpu.eax;
    // 0049c7be  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c7c0  f7b5acfeffff           +div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049c7c6  898c2bb4feffff         -mov dword ptr [ebx + ebp - 0x14c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-332) /* -0x14c */ + cpu.ebp * 1) = cpu.ecx;
    // 0049c7cd  eb34                   -jmp 0x49c803
    goto L_0x0049c803;
L_0x0049c7cf:
    // 0049c7cf  3bb5acfeffff           +cmp esi, dword ptr [ebp - 0x154]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c7d5  0f86eefcffff           -jbe 0x49c4c9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c4c9;
    }
    // 0049c7db  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c7de  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c7e0  89842bb4feffff         -mov dword ptr [ebx + ebp - 0x14c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-332) /* -0x14c */ + cpu.ebp * 1) = cpu.eax;
    // 0049c7e7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c7e9  f7b5acfeffff           -div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049c7ef  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c7f1  89842b34ffffff         -mov dword ptr [ebx + ebp - 0xcc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-204) /* -0xcc */ + cpu.ebp * 1) = cpu.eax;
    // 0049c7f8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c7fa  f7b5acfeffff           +div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049c800  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x0049c803:
    // 0049c803  8985b0feffff           -mov dword ptr [ebp - 0x150], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */) = cpu.eax;
    // 0049c809  ff45e4                 +inc dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049c80c  e923fcffff             -jmp 0x49c434
    goto L_0x0049c434;
L_0x0049c811:
    // 0049c811  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c812  e9a7fbffff             -jmp 0x49c3be
    return sub_49c3be(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c820);
    // 0049c820  a184ea5600             -mov eax, dword ptr [0x56ea84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */);
    // 0049c825  a380894d00             -mov dword ptr [0x4d8980], eax
    app->getMemory<x86::reg32>(x86::reg32(5081472) /* 0x4d8980 */) = cpu.eax;
    // 0049c82a  a180ea5600             -mov eax, dword ptr [0x56ea80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */);
    // 0049c82f  a384894d00             -mov dword ptr [0x4d8984], eax
    app->getMemory<x86::reg32>(x86::reg32(5081476) /* 0x4d8984 */) = cpu.eax;
    // 0049c834  a19cea5600             -mov eax, dword ptr [0x56ea9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */);
    // 0049c839  a388894d00             -mov dword ptr [0x4d8988], eax
    app->getMemory<x86::reg32>(x86::reg32(5081480) /* 0x4d8988 */) = cpu.eax;
    // 0049c83e  a188894d00             -mov eax, dword ptr [0x4d8988]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081480) /* 0x4d8988 */);
    // 0049c843  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c844(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c844);
    // 0049c844  ff0590ea5600           -inc dword ptr [0x56ea90]
    (app->getMemory<x86::reg32>(x86::reg32(5696144) /* 0x56ea90 */))++;
    // 0049c84a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c84c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c84c);
    // 0049c84c  ff0d90ea5600           -dec dword ptr [0x56ea90]
    (app->getMemory<x86::reg32>(x86::reg32(5696144) /* 0x56ea90 */))--;
    // 0049c852  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c854(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c854);
    // 0049c854  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c855  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c856  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c857  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049c85c  bf4cc84900             -mov edi, 0x49c84c
    cpu.edi = 4835404 /*0x49c84c*/;
    // 0049c861  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c863  a198894d00             -mov eax, dword ptr [0x4d8998]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081496) /* 0x4d8998 */);
    // 0049c868  891594ea5600           -mov dword ptr [0x56ea94], edx
    app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */) = cpu.edx;
    // 0049c86e  a38cea5600             -mov dword ptr [0x56ea8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */) = cpu.eax;
    // 0049c873  891598ea5600           -mov dword ptr [0x56ea98], edx
    app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */) = cpu.edx;
    // 0049c879  891590ea5600           -mov dword ptr [0x56ea90], edx
    app->getMemory<x86::reg32>(x86::reg32(5696144) /* 0x56ea90 */) = cpu.edx;
    // 0049c87f  89357c894d00           -mov dword ptr [0x4d897c], esi
    app->getMemory<x86::reg32>(x86::reg32(5081468) /* 0x4d897c */) = cpu.esi;
    // 0049c885  893d588a4d00           -mov dword ptr [0x4d8a58], edi
    app->getMemory<x86::reg32>(x86::reg32(5081688) /* 0x4d8a58 */) = cpu.edi;
    // 0049c88b  893d5c8a4d00           -mov dword ptr [0x4d8a5c], edi
    app->getMemory<x86::reg32>(x86::reg32(5081692) /* 0x4d8a5c */) = cpu.edi;
    // 0049c891  a19c894d00             -mov eax, dword ptr [0x4d899c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081500) /* 0x4d899c */);
    // 0049c896  ba20c84900             -mov edx, 0x49c820
    cpu.edx = 4835360 /*0x49c820*/;
    // 0049c89b  a388ea5600             -mov dword ptr [0x56ea88], eax
    app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */) = cpu.eax;
    // 0049c8a0  b844c84900             -mov eax, 0x49c844
    cpu.eax = 4835396 /*0x49c844*/;
    // 0049c8a5  8915648a4d00           -mov dword ptr [0x4d8a64], edx
    app->getMemory<x86::reg32>(x86::reg32(5081700) /* 0x4d8a64 */) = cpu.edx;
    // 0049c8ab  a3608a4d00             -mov dword ptr [0x4d8a60], eax
    app->getMemory<x86::reg32>(x86::reg32(5081696) /* 0x4d8a60 */) = cpu.eax;
    // 0049c8b0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c8b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c8b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c8b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c8b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49c8b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c8b8);
    // 0049c8b8  a394ea5600             -mov dword ptr [0x56ea94], eax
    app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */) = cpu.eax;
    // 0049c8bd  891598ea5600           -mov dword ptr [0x56ea98], edx
    app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */) = cpu.edx;
    // 0049c8c3  891d8cea5600           -mov dword ptr [0x56ea8c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */) = cpu.ebx;
    // 0049c8c9  890d88ea5600           -mov dword ptr [0x56ea88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */) = cpu.ecx;
    // 0049c8cf  8b1d9cea5600           -mov ebx, dword ptr [0x56ea9c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */);
    // 0049c8d5  8b1580ea5600           -mov edx, dword ptr [0x56ea80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */);
    // 0049c8db  a184ea5600             -mov eax, dword ptr [0x56ea84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */);
    // 0049c8e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c8e2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0049c8e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c8e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c8e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c8e7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c8ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c8ec  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049c8ee  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049c8f1  833d7c894d0000         +cmp dword ptr [0x4d897c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081468) /* 0x4d897c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c8f8  0f84c3000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c8fe  833d54894d0000         +cmp dword ptr [0x4d8954], 0
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
    // 0049c905  0f84b6000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c90b  8b3d94ea5600           -mov edi, dword ptr [0x56ea94]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c911  39f8                   +cmp eax, edi
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
    // 0049c913  0f8ede010000           -jle 0x49caf7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49caf7(app, cpu);
    }
    // 0049c919  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c91b  a18cea5600             -mov eax, dword ptr [0x56ea8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */);
    // 0049c920  39c1                   +cmp ecx, eax
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
    // 0049c922  7d10                   -jge 0x49c934
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c934;
    }
    // 0049c924  8b0d94ea5600           -mov ecx, dword ptr [0x56ea94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c92a  39ce                   +cmp esi, ecx
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
    // 0049c92c  0f8ecc010000           -jle 0x49cafe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cafe(app, cpu);
    }
    // 0049c932  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049c934:
    // 0049c934  8b1d98ea5600           -mov ebx, dword ptr [0x56ea98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c93a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c93c  39da                   +cmp edx, ebx
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
    // 0049c93e  0f8ec1010000           -jle 0x49cb05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb05(app, cpu);
    }
    // 0049c944  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c946  8b3d88ea5600           -mov edi, dword ptr [0x56ea88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */);
    // 0049c94c  39f8                   +cmp eax, edi
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
    // 0049c94e  0f8dbf010000           -jge 0x49cb13
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49cb13(app, cpu);
    }
    // 0049c954  a198ea5600             -mov eax, dword ptr [0x56ea98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c959  39c2                   +cmp edx, eax
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
    // 0049c95b  0f8eab010000           -jle 0x49cb0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb0c(app, cpu);
    }
    // 0049c961  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049c963  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c968  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c96a  e849bafeff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049c96f  892d9cea5600           -mov dword ptr [0x56ea9c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */) = cpu.ebp;
    // 0049c975  39f1                   +cmp ecx, esi
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
    // 0049c977  0f849d010000           -je 0x49cb1a
    if (cpu.flags.zf)
    {
        return sub_49cb1a(app, cpu);
    }
    // 0049c97d  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049c982  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049c984  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c986  e8353cfeff             -call 0x4805c0
    cpu.esp -= 4;
    sub_4805c0(app, cpu);
    if (cpu.terminate) return;
    // 0049c98b  3b0d84ea5600           +cmp ecx, dword ptr [0x56ea84]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c991  0f8490010000           -je 0x49cb27
    if (cpu.flags.zf)
    {
        return sub_49cb27(app, cpu);
    }
    // 0049c997  890d84ea5600           -mov dword ptr [0x56ea84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */) = cpu.ecx;
    // 0049c99d  893d80ea5600           -mov dword ptr [0x56ea80], edi
    app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */) = cpu.edi;
    // 0049c9a3  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c9a8  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c9ab  e820bafeff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049c9b0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c9b2  740d                   -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c9b4  833d688a4d0000         +cmp dword ptr [0x4d8a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081704) /* 0x4d8a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9bb  0f8577010000           -jne 0x49cb38
    if (!cpu.flags.zf)
    {
        return sub_49cb38(app, cpu);
    }
L_0x0049c9c1:
    // 0049c9c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c9c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c9a3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c9a3);
    goto L_entry_0x0049c9a3;
    // 0049c8b8  a394ea5600             -mov dword ptr [0x56ea94], eax
    app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */) = cpu.eax;
    // 0049c8bd  891598ea5600           -mov dword ptr [0x56ea98], edx
    app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */) = cpu.edx;
    // 0049c8c3  891d8cea5600           -mov dword ptr [0x56ea8c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */) = cpu.ebx;
    // 0049c8c9  890d88ea5600           -mov dword ptr [0x56ea88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */) = cpu.ecx;
    // 0049c8cf  8b1d9cea5600           -mov ebx, dword ptr [0x56ea9c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */);
    // 0049c8d5  8b1580ea5600           -mov edx, dword ptr [0x56ea80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */);
    // 0049c8db  a184ea5600             -mov eax, dword ptr [0x56ea84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */);
    // 0049c8e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c8e2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0049c8e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c8e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c8e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c8e7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c8ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c8ec  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049c8ee  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049c8f1  833d7c894d0000         +cmp dword ptr [0x4d897c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081468) /* 0x4d897c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c8f8  0f84c3000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c8fe  833d54894d0000         +cmp dword ptr [0x4d8954], 0
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
    // 0049c905  0f84b6000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c90b  8b3d94ea5600           -mov edi, dword ptr [0x56ea94]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c911  39f8                   +cmp eax, edi
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
    // 0049c913  0f8ede010000           -jle 0x49caf7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49caf7(app, cpu);
    }
    // 0049c919  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c91b  a18cea5600             -mov eax, dword ptr [0x56ea8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */);
    // 0049c920  39c1                   +cmp ecx, eax
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
    // 0049c922  7d10                   -jge 0x49c934
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c934;
    }
    // 0049c924  8b0d94ea5600           -mov ecx, dword ptr [0x56ea94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c92a  39ce                   +cmp esi, ecx
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
    // 0049c92c  0f8ecc010000           -jle 0x49cafe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cafe(app, cpu);
    }
    // 0049c932  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049c934:
    // 0049c934  8b1d98ea5600           -mov ebx, dword ptr [0x56ea98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c93a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c93c  39da                   +cmp edx, ebx
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
    // 0049c93e  0f8ec1010000           -jle 0x49cb05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb05(app, cpu);
    }
    // 0049c944  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c946  8b3d88ea5600           -mov edi, dword ptr [0x56ea88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */);
    // 0049c94c  39f8                   +cmp eax, edi
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
    // 0049c94e  0f8dbf010000           -jge 0x49cb13
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49cb13(app, cpu);
    }
    // 0049c954  a198ea5600             -mov eax, dword ptr [0x56ea98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c959  39c2                   +cmp edx, eax
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
    // 0049c95b  0f8eab010000           -jle 0x49cb0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb0c(app, cpu);
    }
    // 0049c961  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049c963  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c968  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c96a  e849bafeff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049c96f  892d9cea5600           -mov dword ptr [0x56ea9c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */) = cpu.ebp;
    // 0049c975  39f1                   +cmp ecx, esi
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
    // 0049c977  0f849d010000           -je 0x49cb1a
    if (cpu.flags.zf)
    {
        return sub_49cb1a(app, cpu);
    }
    // 0049c97d  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049c982  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049c984  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c986  e8353cfeff             -call 0x4805c0
    cpu.esp -= 4;
    sub_4805c0(app, cpu);
    if (cpu.terminate) return;
    // 0049c98b  3b0d84ea5600           +cmp ecx, dword ptr [0x56ea84]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c991  0f8490010000           -je 0x49cb27
    if (cpu.flags.zf)
    {
        return sub_49cb27(app, cpu);
    }
    // 0049c997  890d84ea5600           -mov dword ptr [0x56ea84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */) = cpu.ecx;
    // 0049c99d  893d80ea5600           -mov dword ptr [0x56ea80], edi
    app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */) = cpu.edi;
L_entry_0x0049c9a3:
    // 0049c9a3  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c9a8  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c9ab  e820bafeff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049c9b0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c9b2  740d                   -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c9b4  833d688a4d0000         +cmp dword ptr [0x4d8a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081704) /* 0x4d8a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9bb  0f8577010000           -jne 0x49cb38
    if (!cpu.flags.zf)
    {
        return sub_49cb38(app, cpu);
    }
L_0x0049c9c1:
    // 0049c9c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c9c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c997(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c997);
    goto L_entry_0x0049c997;
    // 0049c8b8  a394ea5600             -mov dword ptr [0x56ea94], eax
    app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */) = cpu.eax;
    // 0049c8bd  891598ea5600           -mov dword ptr [0x56ea98], edx
    app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */) = cpu.edx;
    // 0049c8c3  891d8cea5600           -mov dword ptr [0x56ea8c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */) = cpu.ebx;
    // 0049c8c9  890d88ea5600           -mov dword ptr [0x56ea88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */) = cpu.ecx;
    // 0049c8cf  8b1d9cea5600           -mov ebx, dword ptr [0x56ea9c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */);
    // 0049c8d5  8b1580ea5600           -mov edx, dword ptr [0x56ea80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */);
    // 0049c8db  a184ea5600             -mov eax, dword ptr [0x56ea84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */);
    // 0049c8e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c8e2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0049c8e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c8e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c8e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c8e7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c8ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c8ec  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049c8ee  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049c8f1  833d7c894d0000         +cmp dword ptr [0x4d897c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081468) /* 0x4d897c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c8f8  0f84c3000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c8fe  833d54894d0000         +cmp dword ptr [0x4d8954], 0
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
    // 0049c905  0f84b6000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c90b  8b3d94ea5600           -mov edi, dword ptr [0x56ea94]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c911  39f8                   +cmp eax, edi
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
    // 0049c913  0f8ede010000           -jle 0x49caf7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49caf7(app, cpu);
    }
    // 0049c919  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c91b  a18cea5600             -mov eax, dword ptr [0x56ea8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */);
    // 0049c920  39c1                   +cmp ecx, eax
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
    // 0049c922  7d10                   -jge 0x49c934
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c934;
    }
    // 0049c924  8b0d94ea5600           -mov ecx, dword ptr [0x56ea94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c92a  39ce                   +cmp esi, ecx
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
    // 0049c92c  0f8ecc010000           -jle 0x49cafe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cafe(app, cpu);
    }
    // 0049c932  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049c934:
    // 0049c934  8b1d98ea5600           -mov ebx, dword ptr [0x56ea98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c93a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c93c  39da                   +cmp edx, ebx
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
    // 0049c93e  0f8ec1010000           -jle 0x49cb05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb05(app, cpu);
    }
    // 0049c944  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c946  8b3d88ea5600           -mov edi, dword ptr [0x56ea88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */);
    // 0049c94c  39f8                   +cmp eax, edi
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
    // 0049c94e  0f8dbf010000           -jge 0x49cb13
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49cb13(app, cpu);
    }
    // 0049c954  a198ea5600             -mov eax, dword ptr [0x56ea98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c959  39c2                   +cmp edx, eax
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
    // 0049c95b  0f8eab010000           -jle 0x49cb0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb0c(app, cpu);
    }
    // 0049c961  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049c963  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c968  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c96a  e849bafeff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049c96f  892d9cea5600           -mov dword ptr [0x56ea9c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */) = cpu.ebp;
    // 0049c975  39f1                   +cmp ecx, esi
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
    // 0049c977  0f849d010000           -je 0x49cb1a
    if (cpu.flags.zf)
    {
        return sub_49cb1a(app, cpu);
    }
    // 0049c97d  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049c982  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049c984  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c986  e8353cfeff             -call 0x4805c0
    cpu.esp -= 4;
    sub_4805c0(app, cpu);
    if (cpu.terminate) return;
    // 0049c98b  3b0d84ea5600           +cmp ecx, dword ptr [0x56ea84]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c991  0f8490010000           -je 0x49cb27
    if (cpu.flags.zf)
    {
        return sub_49cb27(app, cpu);
    }
L_entry_0x0049c997:
    // 0049c997  890d84ea5600           -mov dword ptr [0x56ea84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */) = cpu.ecx;
    // 0049c99d  893d80ea5600           -mov dword ptr [0x56ea80], edi
    app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */) = cpu.edi;
    // 0049c9a3  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c9a8  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c9ab  e820bafeff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049c9b0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c9b2  740d                   -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c9b4  833d688a4d0000         +cmp dword ptr [0x4d8a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081704) /* 0x4d8a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9bb  0f8577010000           -jne 0x49cb38
    if (!cpu.flags.zf)
    {
        return sub_49cb38(app, cpu);
    }
L_0x0049c9c1:
    // 0049c9c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c9c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c98b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c98b);
    goto L_entry_0x0049c98b;
    // 0049c8b8  a394ea5600             -mov dword ptr [0x56ea94], eax
    app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */) = cpu.eax;
    // 0049c8bd  891598ea5600           -mov dword ptr [0x56ea98], edx
    app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */) = cpu.edx;
    // 0049c8c3  891d8cea5600           -mov dword ptr [0x56ea8c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */) = cpu.ebx;
    // 0049c8c9  890d88ea5600           -mov dword ptr [0x56ea88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */) = cpu.ecx;
    // 0049c8cf  8b1d9cea5600           -mov ebx, dword ptr [0x56ea9c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */);
    // 0049c8d5  8b1580ea5600           -mov edx, dword ptr [0x56ea80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */);
    // 0049c8db  a184ea5600             -mov eax, dword ptr [0x56ea84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */);
    // 0049c8e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c8e2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0049c8e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c8e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c8e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c8e7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c8ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c8ec  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049c8ee  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049c8f1  833d7c894d0000         +cmp dword ptr [0x4d897c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081468) /* 0x4d897c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c8f8  0f84c3000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c8fe  833d54894d0000         +cmp dword ptr [0x4d8954], 0
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
    // 0049c905  0f84b6000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c90b  8b3d94ea5600           -mov edi, dword ptr [0x56ea94]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c911  39f8                   +cmp eax, edi
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
    // 0049c913  0f8ede010000           -jle 0x49caf7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49caf7(app, cpu);
    }
    // 0049c919  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c91b  a18cea5600             -mov eax, dword ptr [0x56ea8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */);
    // 0049c920  39c1                   +cmp ecx, eax
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
    // 0049c922  7d10                   -jge 0x49c934
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c934;
    }
    // 0049c924  8b0d94ea5600           -mov ecx, dword ptr [0x56ea94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c92a  39ce                   +cmp esi, ecx
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
    // 0049c92c  0f8ecc010000           -jle 0x49cafe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cafe(app, cpu);
    }
    // 0049c932  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049c934:
    // 0049c934  8b1d98ea5600           -mov ebx, dword ptr [0x56ea98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c93a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c93c  39da                   +cmp edx, ebx
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
    // 0049c93e  0f8ec1010000           -jle 0x49cb05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb05(app, cpu);
    }
    // 0049c944  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c946  8b3d88ea5600           -mov edi, dword ptr [0x56ea88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */);
    // 0049c94c  39f8                   +cmp eax, edi
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
    // 0049c94e  0f8dbf010000           -jge 0x49cb13
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49cb13(app, cpu);
    }
    // 0049c954  a198ea5600             -mov eax, dword ptr [0x56ea98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c959  39c2                   +cmp edx, eax
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
    // 0049c95b  0f8eab010000           -jle 0x49cb0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb0c(app, cpu);
    }
    // 0049c961  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049c963  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c968  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c96a  e849bafeff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049c96f  892d9cea5600           -mov dword ptr [0x56ea9c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */) = cpu.ebp;
    // 0049c975  39f1                   +cmp ecx, esi
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
    // 0049c977  0f849d010000           -je 0x49cb1a
    if (cpu.flags.zf)
    {
        return sub_49cb1a(app, cpu);
    }
    // 0049c97d  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049c982  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049c984  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c986  e8353cfeff             -call 0x4805c0
    cpu.esp -= 4;
    sub_4805c0(app, cpu);
    if (cpu.terminate) return;
L_entry_0x0049c98b:
    // 0049c98b  3b0d84ea5600           +cmp ecx, dword ptr [0x56ea84]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c991  0f8490010000           -je 0x49cb27
    if (cpu.flags.zf)
    {
        return sub_49cb27(app, cpu);
    }
    // 0049c997  890d84ea5600           -mov dword ptr [0x56ea84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */) = cpu.ecx;
    // 0049c99d  893d80ea5600           -mov dword ptr [0x56ea80], edi
    app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */) = cpu.edi;
    // 0049c9a3  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c9a8  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c9ab  e820bafeff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049c9b0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c9b2  740d                   -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c9b4  833d688a4d0000         +cmp dword ptr [0x4d8a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081704) /* 0x4d8a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9bb  0f8577010000           -jne 0x49cb38
    if (!cpu.flags.zf)
    {
        return sub_49cb38(app, cpu);
    }
L_0x0049c9c1:
    // 0049c9c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c9c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c97d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c97d);
    goto L_entry_0x0049c97d;
    // 0049c8b8  a394ea5600             -mov dword ptr [0x56ea94], eax
    app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */) = cpu.eax;
    // 0049c8bd  891598ea5600           -mov dword ptr [0x56ea98], edx
    app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */) = cpu.edx;
    // 0049c8c3  891d8cea5600           -mov dword ptr [0x56ea8c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */) = cpu.ebx;
    // 0049c8c9  890d88ea5600           -mov dword ptr [0x56ea88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */) = cpu.ecx;
    // 0049c8cf  8b1d9cea5600           -mov ebx, dword ptr [0x56ea9c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */);
    // 0049c8d5  8b1580ea5600           -mov edx, dword ptr [0x56ea80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */);
    // 0049c8db  a184ea5600             -mov eax, dword ptr [0x56ea84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */);
    // 0049c8e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c8e2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0049c8e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c8e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c8e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c8e7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c8ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c8ec  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049c8ee  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049c8f1  833d7c894d0000         +cmp dword ptr [0x4d897c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081468) /* 0x4d897c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c8f8  0f84c3000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c8fe  833d54894d0000         +cmp dword ptr [0x4d8954], 0
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
    // 0049c905  0f84b6000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c90b  8b3d94ea5600           -mov edi, dword ptr [0x56ea94]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c911  39f8                   +cmp eax, edi
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
    // 0049c913  0f8ede010000           -jle 0x49caf7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49caf7(app, cpu);
    }
    // 0049c919  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c91b  a18cea5600             -mov eax, dword ptr [0x56ea8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */);
    // 0049c920  39c1                   +cmp ecx, eax
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
    // 0049c922  7d10                   -jge 0x49c934
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c934;
    }
    // 0049c924  8b0d94ea5600           -mov ecx, dword ptr [0x56ea94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c92a  39ce                   +cmp esi, ecx
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
    // 0049c92c  0f8ecc010000           -jle 0x49cafe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cafe(app, cpu);
    }
    // 0049c932  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049c934:
    // 0049c934  8b1d98ea5600           -mov ebx, dword ptr [0x56ea98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c93a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c93c  39da                   +cmp edx, ebx
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
    // 0049c93e  0f8ec1010000           -jle 0x49cb05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb05(app, cpu);
    }
    // 0049c944  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c946  8b3d88ea5600           -mov edi, dword ptr [0x56ea88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */);
    // 0049c94c  39f8                   +cmp eax, edi
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
    // 0049c94e  0f8dbf010000           -jge 0x49cb13
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49cb13(app, cpu);
    }
    // 0049c954  a198ea5600             -mov eax, dword ptr [0x56ea98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c959  39c2                   +cmp edx, eax
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
    // 0049c95b  0f8eab010000           -jle 0x49cb0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb0c(app, cpu);
    }
    // 0049c961  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049c963  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c968  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c96a  e849bafeff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049c96f  892d9cea5600           -mov dword ptr [0x56ea9c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */) = cpu.ebp;
    // 0049c975  39f1                   +cmp ecx, esi
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
    // 0049c977  0f849d010000           -je 0x49cb1a
    if (cpu.flags.zf)
    {
        return sub_49cb1a(app, cpu);
    }
L_entry_0x0049c97d:
    // 0049c97d  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049c982  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049c984  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c986  e8353cfeff             -call 0x4805c0
    cpu.esp -= 4;
    sub_4805c0(app, cpu);
    if (cpu.terminate) return;
    // 0049c98b  3b0d84ea5600           +cmp ecx, dword ptr [0x56ea84]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c991  0f8490010000           -je 0x49cb27
    if (cpu.flags.zf)
    {
        return sub_49cb27(app, cpu);
    }
    // 0049c997  890d84ea5600           -mov dword ptr [0x56ea84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */) = cpu.ecx;
    // 0049c99d  893d80ea5600           -mov dword ptr [0x56ea80], edi
    app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */) = cpu.edi;
    // 0049c9a3  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c9a8  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c9ab  e820bafeff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049c9b0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c9b2  740d                   -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c9b4  833d688a4d0000         +cmp dword ptr [0x4d8a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081704) /* 0x4d8a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9bb  0f8577010000           -jne 0x49cb38
    if (!cpu.flags.zf)
    {
        return sub_49cb38(app, cpu);
    }
L_0x0049c9c1:
    // 0049c9c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c9c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c963(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c963);
    goto L_entry_0x0049c963;
    // 0049c8b8  a394ea5600             -mov dword ptr [0x56ea94], eax
    app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */) = cpu.eax;
    // 0049c8bd  891598ea5600           -mov dword ptr [0x56ea98], edx
    app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */) = cpu.edx;
    // 0049c8c3  891d8cea5600           -mov dword ptr [0x56ea8c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */) = cpu.ebx;
    // 0049c8c9  890d88ea5600           -mov dword ptr [0x56ea88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */) = cpu.ecx;
    // 0049c8cf  8b1d9cea5600           -mov ebx, dword ptr [0x56ea9c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */);
    // 0049c8d5  8b1580ea5600           -mov edx, dword ptr [0x56ea80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */);
    // 0049c8db  a184ea5600             -mov eax, dword ptr [0x56ea84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */);
    // 0049c8e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c8e2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0049c8e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c8e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c8e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c8e7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c8ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c8ec  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049c8ee  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049c8f1  833d7c894d0000         +cmp dword ptr [0x4d897c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081468) /* 0x4d897c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c8f8  0f84c3000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c8fe  833d54894d0000         +cmp dword ptr [0x4d8954], 0
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
    // 0049c905  0f84b6000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c90b  8b3d94ea5600           -mov edi, dword ptr [0x56ea94]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c911  39f8                   +cmp eax, edi
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
    // 0049c913  0f8ede010000           -jle 0x49caf7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49caf7(app, cpu);
    }
    // 0049c919  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c91b  a18cea5600             -mov eax, dword ptr [0x56ea8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */);
    // 0049c920  39c1                   +cmp ecx, eax
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
    // 0049c922  7d10                   -jge 0x49c934
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c934;
    }
    // 0049c924  8b0d94ea5600           -mov ecx, dword ptr [0x56ea94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c92a  39ce                   +cmp esi, ecx
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
    // 0049c92c  0f8ecc010000           -jle 0x49cafe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cafe(app, cpu);
    }
    // 0049c932  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049c934:
    // 0049c934  8b1d98ea5600           -mov ebx, dword ptr [0x56ea98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c93a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c93c  39da                   +cmp edx, ebx
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
    // 0049c93e  0f8ec1010000           -jle 0x49cb05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb05(app, cpu);
    }
    // 0049c944  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c946  8b3d88ea5600           -mov edi, dword ptr [0x56ea88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */);
    // 0049c94c  39f8                   +cmp eax, edi
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
    // 0049c94e  0f8dbf010000           -jge 0x49cb13
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49cb13(app, cpu);
    }
    // 0049c954  a198ea5600             -mov eax, dword ptr [0x56ea98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c959  39c2                   +cmp edx, eax
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
    // 0049c95b  0f8eab010000           -jle 0x49cb0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb0c(app, cpu);
    }
    // 0049c961  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_entry_0x0049c963:
    // 0049c963  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c968  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c96a  e849bafeff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049c96f  892d9cea5600           -mov dword ptr [0x56ea9c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */) = cpu.ebp;
    // 0049c975  39f1                   +cmp ecx, esi
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
    // 0049c977  0f849d010000           -je 0x49cb1a
    if (cpu.flags.zf)
    {
        return sub_49cb1a(app, cpu);
    }
    // 0049c97d  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049c982  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049c984  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c986  e8353cfeff             -call 0x4805c0
    cpu.esp -= 4;
    sub_4805c0(app, cpu);
    if (cpu.terminate) return;
    // 0049c98b  3b0d84ea5600           +cmp ecx, dword ptr [0x56ea84]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c991  0f8490010000           -je 0x49cb27
    if (cpu.flags.zf)
    {
        return sub_49cb27(app, cpu);
    }
    // 0049c997  890d84ea5600           -mov dword ptr [0x56ea84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */) = cpu.ecx;
    // 0049c99d  893d80ea5600           -mov dword ptr [0x56ea80], edi
    app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */) = cpu.edi;
    // 0049c9a3  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c9a8  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c9ab  e820bafeff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049c9b0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c9b2  740d                   -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c9b4  833d688a4d0000         +cmp dword ptr [0x4d8a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081704) /* 0x4d8a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9bb  0f8577010000           -jne 0x49cb38
    if (!cpu.flags.zf)
    {
        return sub_49cb38(app, cpu);
    }
L_0x0049c9c1:
    // 0049c9c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c9c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c946(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c946);
    goto L_entry_0x0049c946;
    // 0049c8b8  a394ea5600             -mov dword ptr [0x56ea94], eax
    app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */) = cpu.eax;
    // 0049c8bd  891598ea5600           -mov dword ptr [0x56ea98], edx
    app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */) = cpu.edx;
    // 0049c8c3  891d8cea5600           -mov dword ptr [0x56ea8c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */) = cpu.ebx;
    // 0049c8c9  890d88ea5600           -mov dword ptr [0x56ea88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */) = cpu.ecx;
    // 0049c8cf  8b1d9cea5600           -mov ebx, dword ptr [0x56ea9c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */);
    // 0049c8d5  8b1580ea5600           -mov edx, dword ptr [0x56ea80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */);
    // 0049c8db  a184ea5600             -mov eax, dword ptr [0x56ea84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */);
    // 0049c8e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c8e2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0049c8e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c8e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c8e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c8e7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c8ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c8ec  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049c8ee  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049c8f1  833d7c894d0000         +cmp dword ptr [0x4d897c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081468) /* 0x4d897c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c8f8  0f84c3000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c8fe  833d54894d0000         +cmp dword ptr [0x4d8954], 0
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
    // 0049c905  0f84b6000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c90b  8b3d94ea5600           -mov edi, dword ptr [0x56ea94]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c911  39f8                   +cmp eax, edi
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
    // 0049c913  0f8ede010000           -jle 0x49caf7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49caf7(app, cpu);
    }
    // 0049c919  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c91b  a18cea5600             -mov eax, dword ptr [0x56ea8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */);
    // 0049c920  39c1                   +cmp ecx, eax
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
    // 0049c922  7d10                   -jge 0x49c934
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c934;
    }
    // 0049c924  8b0d94ea5600           -mov ecx, dword ptr [0x56ea94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c92a  39ce                   +cmp esi, ecx
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
    // 0049c92c  0f8ecc010000           -jle 0x49cafe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cafe(app, cpu);
    }
    // 0049c932  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049c934:
    // 0049c934  8b1d98ea5600           -mov ebx, dword ptr [0x56ea98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c93a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c93c  39da                   +cmp edx, ebx
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
    // 0049c93e  0f8ec1010000           -jle 0x49cb05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb05(app, cpu);
    }
    // 0049c944  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_entry_0x0049c946:
    // 0049c946  8b3d88ea5600           -mov edi, dword ptr [0x56ea88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */);
    // 0049c94c  39f8                   +cmp eax, edi
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
    // 0049c94e  0f8dbf010000           -jge 0x49cb13
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49cb13(app, cpu);
    }
    // 0049c954  a198ea5600             -mov eax, dword ptr [0x56ea98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c959  39c2                   +cmp edx, eax
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
    // 0049c95b  0f8eab010000           -jle 0x49cb0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb0c(app, cpu);
    }
    // 0049c961  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049c963  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c968  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c96a  e849bafeff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049c96f  892d9cea5600           -mov dword ptr [0x56ea9c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */) = cpu.ebp;
    // 0049c975  39f1                   +cmp ecx, esi
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
    // 0049c977  0f849d010000           -je 0x49cb1a
    if (cpu.flags.zf)
    {
        return sub_49cb1a(app, cpu);
    }
    // 0049c97d  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049c982  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049c984  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c986  e8353cfeff             -call 0x4805c0
    cpu.esp -= 4;
    sub_4805c0(app, cpu);
    if (cpu.terminate) return;
    // 0049c98b  3b0d84ea5600           +cmp ecx, dword ptr [0x56ea84]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c991  0f8490010000           -je 0x49cb27
    if (cpu.flags.zf)
    {
        return sub_49cb27(app, cpu);
    }
    // 0049c997  890d84ea5600           -mov dword ptr [0x56ea84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */) = cpu.ecx;
    // 0049c99d  893d80ea5600           -mov dword ptr [0x56ea80], edi
    app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */) = cpu.edi;
    // 0049c9a3  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c9a8  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c9ab  e820bafeff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049c9b0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c9b2  740d                   -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c9b4  833d688a4d0000         +cmp dword ptr [0x4d8a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081704) /* 0x4d8a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9bb  0f8577010000           -jne 0x49cb38
    if (!cpu.flags.zf)
    {
        return sub_49cb38(app, cpu);
    }
L_0x0049c9c1:
    // 0049c9c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c9c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c934(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c934);
    goto L_entry_0x0049c934;
    // 0049c8b8  a394ea5600             -mov dword ptr [0x56ea94], eax
    app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */) = cpu.eax;
    // 0049c8bd  891598ea5600           -mov dword ptr [0x56ea98], edx
    app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */) = cpu.edx;
    // 0049c8c3  891d8cea5600           -mov dword ptr [0x56ea8c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */) = cpu.ebx;
    // 0049c8c9  890d88ea5600           -mov dword ptr [0x56ea88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */) = cpu.ecx;
    // 0049c8cf  8b1d9cea5600           -mov ebx, dword ptr [0x56ea9c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */);
    // 0049c8d5  8b1580ea5600           -mov edx, dword ptr [0x56ea80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */);
    // 0049c8db  a184ea5600             -mov eax, dword ptr [0x56ea84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */);
    // 0049c8e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c8e2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0049c8e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c8e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c8e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c8e7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c8ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c8ec  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049c8ee  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049c8f1  833d7c894d0000         +cmp dword ptr [0x4d897c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081468) /* 0x4d897c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c8f8  0f84c3000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c8fe  833d54894d0000         +cmp dword ptr [0x4d8954], 0
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
    // 0049c905  0f84b6000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c90b  8b3d94ea5600           -mov edi, dword ptr [0x56ea94]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c911  39f8                   +cmp eax, edi
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
    // 0049c913  0f8ede010000           -jle 0x49caf7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49caf7(app, cpu);
    }
    // 0049c919  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c91b  a18cea5600             -mov eax, dword ptr [0x56ea8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */);
    // 0049c920  39c1                   +cmp ecx, eax
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
    // 0049c922  7d10                   -jge 0x49c934
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c934;
    }
    // 0049c924  8b0d94ea5600           -mov ecx, dword ptr [0x56ea94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c92a  39ce                   +cmp esi, ecx
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
    // 0049c92c  0f8ecc010000           -jle 0x49cafe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cafe(app, cpu);
    }
    // 0049c932  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049c934:
L_entry_0x0049c934:
    // 0049c934  8b1d98ea5600           -mov ebx, dword ptr [0x56ea98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c93a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c93c  39da                   +cmp edx, ebx
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
    // 0049c93e  0f8ec1010000           -jle 0x49cb05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb05(app, cpu);
    }
    // 0049c944  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c946  8b3d88ea5600           -mov edi, dword ptr [0x56ea88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */);
    // 0049c94c  39f8                   +cmp eax, edi
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
    // 0049c94e  0f8dbf010000           -jge 0x49cb13
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49cb13(app, cpu);
    }
    // 0049c954  a198ea5600             -mov eax, dword ptr [0x56ea98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c959  39c2                   +cmp edx, eax
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
    // 0049c95b  0f8eab010000           -jle 0x49cb0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb0c(app, cpu);
    }
    // 0049c961  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049c963  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c968  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c96a  e849bafeff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049c96f  892d9cea5600           -mov dword ptr [0x56ea9c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */) = cpu.ebp;
    // 0049c975  39f1                   +cmp ecx, esi
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
    // 0049c977  0f849d010000           -je 0x49cb1a
    if (cpu.flags.zf)
    {
        return sub_49cb1a(app, cpu);
    }
    // 0049c97d  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049c982  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049c984  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c986  e8353cfeff             -call 0x4805c0
    cpu.esp -= 4;
    sub_4805c0(app, cpu);
    if (cpu.terminate) return;
    // 0049c98b  3b0d84ea5600           +cmp ecx, dword ptr [0x56ea84]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c991  0f8490010000           -je 0x49cb27
    if (cpu.flags.zf)
    {
        return sub_49cb27(app, cpu);
    }
    // 0049c997  890d84ea5600           -mov dword ptr [0x56ea84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */) = cpu.ecx;
    // 0049c99d  893d80ea5600           -mov dword ptr [0x56ea80], edi
    app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */) = cpu.edi;
    // 0049c9a3  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c9a8  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c9ab  e820bafeff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049c9b0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c9b2  740d                   -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c9b4  833d688a4d0000         +cmp dword ptr [0x4d8a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081704) /* 0x4d8a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9bb  0f8577010000           -jne 0x49cb38
    if (!cpu.flags.zf)
    {
        return sub_49cb38(app, cpu);
    }
L_0x0049c9c1:
    // 0049c9c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c9c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c91b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c91b);
    goto L_entry_0x0049c91b;
    // 0049c8b8  a394ea5600             -mov dword ptr [0x56ea94], eax
    app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */) = cpu.eax;
    // 0049c8bd  891598ea5600           -mov dword ptr [0x56ea98], edx
    app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */) = cpu.edx;
    // 0049c8c3  891d8cea5600           -mov dword ptr [0x56ea8c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */) = cpu.ebx;
    // 0049c8c9  890d88ea5600           -mov dword ptr [0x56ea88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */) = cpu.ecx;
    // 0049c8cf  8b1d9cea5600           -mov ebx, dword ptr [0x56ea9c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */);
    // 0049c8d5  8b1580ea5600           -mov edx, dword ptr [0x56ea80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */);
    // 0049c8db  a184ea5600             -mov eax, dword ptr [0x56ea84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */);
    // 0049c8e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c8e2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0049c8e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c8e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c8e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c8e7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c8ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c8ec  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049c8ee  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049c8f1  833d7c894d0000         +cmp dword ptr [0x4d897c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081468) /* 0x4d897c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c8f8  0f84c3000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c8fe  833d54894d0000         +cmp dword ptr [0x4d8954], 0
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
    // 0049c905  0f84b6000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c90b  8b3d94ea5600           -mov edi, dword ptr [0x56ea94]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c911  39f8                   +cmp eax, edi
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
    // 0049c913  0f8ede010000           -jle 0x49caf7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49caf7(app, cpu);
    }
    // 0049c919  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_entry_0x0049c91b:
    // 0049c91b  a18cea5600             -mov eax, dword ptr [0x56ea8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */);
    // 0049c920  39c1                   +cmp ecx, eax
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
    // 0049c922  7d10                   -jge 0x49c934
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c934;
    }
    // 0049c924  8b0d94ea5600           -mov ecx, dword ptr [0x56ea94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c92a  39ce                   +cmp esi, ecx
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
    // 0049c92c  0f8ecc010000           -jle 0x49cafe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cafe(app, cpu);
    }
    // 0049c932  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049c934:
    // 0049c934  8b1d98ea5600           -mov ebx, dword ptr [0x56ea98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c93a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c93c  39da                   +cmp edx, ebx
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
    // 0049c93e  0f8ec1010000           -jle 0x49cb05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb05(app, cpu);
    }
    // 0049c944  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c946  8b3d88ea5600           -mov edi, dword ptr [0x56ea88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */);
    // 0049c94c  39f8                   +cmp eax, edi
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
    // 0049c94e  0f8dbf010000           -jge 0x49cb13
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49cb13(app, cpu);
    }
    // 0049c954  a198ea5600             -mov eax, dword ptr [0x56ea98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c959  39c2                   +cmp edx, eax
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
    // 0049c95b  0f8eab010000           -jle 0x49cb0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb0c(app, cpu);
    }
    // 0049c961  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049c963  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c968  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c96a  e849bafeff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049c96f  892d9cea5600           -mov dword ptr [0x56ea9c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */) = cpu.ebp;
    // 0049c975  39f1                   +cmp ecx, esi
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
    // 0049c977  0f849d010000           -je 0x49cb1a
    if (cpu.flags.zf)
    {
        return sub_49cb1a(app, cpu);
    }
    // 0049c97d  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049c982  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049c984  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c986  e8353cfeff             -call 0x4805c0
    cpu.esp -= 4;
    sub_4805c0(app, cpu);
    if (cpu.terminate) return;
    // 0049c98b  3b0d84ea5600           +cmp ecx, dword ptr [0x56ea84]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c991  0f8490010000           -je 0x49cb27
    if (cpu.flags.zf)
    {
        return sub_49cb27(app, cpu);
    }
    // 0049c997  890d84ea5600           -mov dword ptr [0x56ea84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */) = cpu.ecx;
    // 0049c99d  893d80ea5600           -mov dword ptr [0x56ea80], edi
    app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */) = cpu.edi;
    // 0049c9a3  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c9a8  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c9ab  e820bafeff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049c9b0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c9b2  740d                   -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c9b4  833d688a4d0000         +cmp dword ptr [0x4d8a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081704) /* 0x4d8a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9bb  0f8577010000           -jne 0x49cb38
    if (!cpu.flags.zf)
    {
        return sub_49cb38(app, cpu);
    }
L_0x0049c9c1:
    // 0049c9c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c9c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c8e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c8e4);
    goto L_entry_0x0049c8e4;
    // 0049c8b8  a394ea5600             -mov dword ptr [0x56ea94], eax
    app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */) = cpu.eax;
    // 0049c8bd  891598ea5600           -mov dword ptr [0x56ea98], edx
    app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */) = cpu.edx;
    // 0049c8c3  891d8cea5600           -mov dword ptr [0x56ea8c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */) = cpu.ebx;
    // 0049c8c9  890d88ea5600           -mov dword ptr [0x56ea88], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */) = cpu.ecx;
    // 0049c8cf  8b1d9cea5600           -mov ebx, dword ptr [0x56ea9c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */);
    // 0049c8d5  8b1580ea5600           -mov edx, dword ptr [0x56ea80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */);
    // 0049c8db  a184ea5600             -mov eax, dword ptr [0x56ea84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */);
    // 0049c8e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c8e2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x0049c8e4:
    // 0049c8e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c8e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c8e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c8e7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c8ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c8ec  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049c8ee  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049c8f1  833d7c894d0000         +cmp dword ptr [0x4d897c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081468) /* 0x4d897c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c8f8  0f84c3000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c8fe  833d54894d0000         +cmp dword ptr [0x4d8954], 0
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
    // 0049c905  0f84b6000000           -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c90b  8b3d94ea5600           -mov edi, dword ptr [0x56ea94]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c911  39f8                   +cmp eax, edi
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
    // 0049c913  0f8ede010000           -jle 0x49caf7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49caf7(app, cpu);
    }
    // 0049c919  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c91b  a18cea5600             -mov eax, dword ptr [0x56ea8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */);
    // 0049c920  39c1                   +cmp ecx, eax
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
    // 0049c922  7d10                   -jge 0x49c934
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c934;
    }
    // 0049c924  8b0d94ea5600           -mov ecx, dword ptr [0x56ea94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049c92a  39ce                   +cmp esi, ecx
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
    // 0049c92c  0f8ecc010000           -jle 0x49cafe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cafe(app, cpu);
    }
    // 0049c932  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049c934:
    // 0049c934  8b1d98ea5600           -mov ebx, dword ptr [0x56ea98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c93a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c93c  39da                   +cmp edx, ebx
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
    // 0049c93e  0f8ec1010000           -jle 0x49cb05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb05(app, cpu);
    }
    // 0049c944  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c946  8b3d88ea5600           -mov edi, dword ptr [0x56ea88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */);
    // 0049c94c  39f8                   +cmp eax, edi
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
    // 0049c94e  0f8dbf010000           -jge 0x49cb13
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_49cb13(app, cpu);
    }
    // 0049c954  a198ea5600             -mov eax, dword ptr [0x56ea98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049c959  39c2                   +cmp edx, eax
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
    // 0049c95b  0f8eab010000           -jle 0x49cb0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_49cb0c(app, cpu);
    }
    // 0049c961  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049c963  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c968  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c96a  e849bafeff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0049c96f  892d9cea5600           -mov dword ptr [0x56ea9c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */) = cpu.ebp;
    // 0049c975  39f1                   +cmp ecx, esi
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
    // 0049c977  0f849d010000           -je 0x49cb1a
    if (cpu.flags.zf)
    {
        return sub_49cb1a(app, cpu);
    }
    // 0049c97d  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049c982  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049c984  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c986  e8353cfeff             -call 0x4805c0
    cpu.esp -= 4;
    sub_4805c0(app, cpu);
    if (cpu.terminate) return;
    // 0049c98b  3b0d84ea5600           +cmp ecx, dword ptr [0x56ea84]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c991  0f8490010000           -je 0x49cb27
    if (cpu.flags.zf)
    {
        return sub_49cb27(app, cpu);
    }
    // 0049c997  890d84ea5600           -mov dword ptr [0x56ea84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */) = cpu.ecx;
    // 0049c99d  893d80ea5600           -mov dword ptr [0x56ea80], edi
    app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */) = cpu.edi;
    // 0049c9a3  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0049c9a8  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c9ab  e820bafeff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049c9b0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c9b2  740d                   -je 0x49c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c9c1;
    }
    // 0049c9b4  833d688a4d0000         +cmp dword ptr [0x4d8a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081704) /* 0x4d8a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9bb  0f8577010000           -jne 0x49cb38
    if (!cpu.flags.zf)
    {
        return sub_49cb38(app, cpu);
    }
L_0x0049c9c1:
    // 0049c9c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c9c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c9c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c9c8);
    // 0049c9c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c9ca  7510                   -jne 0x49c9dc
    if (!cpu.flags.zf)
    {
        goto L_0x0049c9dc;
    }
L_0x0049c9cc:
    // 0049c9cc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049c9ce  7407                   -je 0x49c9d7
    if (cpu.flags.zf)
    {
        goto L_0x0049c9d7;
    }
    // 0049c9d0  a184ea5600             -mov eax, dword ptr [0x56ea84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */);
    // 0049c9d5  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0049c9d7:
    // 0049c9d7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c9d9  750d                   -jne 0x49c9e8
    if (!cpu.flags.zf)
    {
        goto L_0x0049c9e8;
    }
    // 0049c9db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c9dc:
    // 0049c9dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c9dd  8b0d9cea5600           -mov ecx, dword ptr [0x56ea9c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5696156) /* 0x56ea9c */);
    // 0049c9e3  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049c9e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c9e6  ebe4                   -jmp 0x49c9cc
    goto L_0x0049c9cc;
L_0x0049c9e8:
    // 0049c9e8  a180ea5600             -mov eax, dword ptr [0x56ea80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */);
    // 0049c9ed  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049c9ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c9f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c9f0);
    // 0049c9f0  ff15648a4d00           -call dword ptr [0x4d8a64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5081700) /* 0x4d8a64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c9f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c9f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049c9f8);
    // 0049c9f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c9f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c9fa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c9fb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c9fc  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0049c9ff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ca01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ca03  e850b6feff             -call 0x488058
    cpu.esp -= 4;
    sub_488058(app, cpu);
    if (cpu.terminate) return;
    // 0049ca08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ca0a  0f85a4000000           -jne 0x49cab4
    if (!cpu.flags.zf)
    {
        goto L_0x0049cab4;
    }
    // 0049ca10  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0049ca15  e89eb9feff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
L_0x0049ca1a:
    // 0049ca1a  8b1d94ea5600           -mov ebx, dword ptr [0x56ea94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049ca20  39d9                   +cmp ecx, ebx
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
    // 0049ca22  0f8e9d000000           -jle 0x49cac5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cac5;
    }
    // 0049ca28  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0049ca2a:
    // 0049ca2a  8b358cea5600           -mov esi, dword ptr [0x56ea8c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5696140) /* 0x56ea8c */);
    // 0049ca30  39f0                   +cmp eax, esi
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
    // 0049ca32  0f8d9b000000           -jge 0x49cad3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049cad3;
    }
    // 0049ca38  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ca39  8b3d94ea5600           -mov edi, dword ptr [0x56ea94]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696148) /* 0x56ea94 */);
    // 0049ca3f  39f9                   +cmp ecx, edi
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
    // 0049ca41  0f8e85000000           -jle 0x49cacc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cacc;
    }
L_0x0049ca47:
    // 0049ca47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049ca48:
    // 0049ca48  8b2d98ea5600           -mov ebp, dword ptr [0x56ea98]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049ca4e  39ea                   +cmp edx, ebp
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
    // 0049ca50  0f8e84000000           -jle 0x49cada
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cada;
    }
    // 0049ca56  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0049ca58:
    // 0049ca58  8b1d88ea5600           -mov ebx, dword ptr [0x56ea88]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696136) /* 0x56ea88 */);
    // 0049ca5e  39d8                   +cmp eax, ebx
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
    // 0049ca60  7d0c                   -jge 0x49ca6e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ca6e;
    }
    // 0049ca62  8b3598ea5600           -mov esi, dword ptr [0x56ea98]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5696152) /* 0x56ea98 */);
    // 0049ca68  39f2                   +cmp edx, esi
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
    // 0049ca6a  7e75                   -jle 0x49cae1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cae1;
    }
L_0x0049ca6c:
    // 0049ca6c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0049ca6e:
    // 0049ca6e  890d80894d00           -mov dword ptr [0x4d8980], ecx
    app->getMemory<x86::reg32>(x86::reg32(5081472) /* 0x4d8980 */) = cpu.ecx;
    // 0049ca74  a180894d00             -mov eax, dword ptr [0x4d8980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081472) /* 0x4d8980 */);
    // 0049ca79  a384ea5600             -mov dword ptr [0x56ea84], eax
    app->getMemory<x86::reg32>(x86::reg32(5696132) /* 0x56ea84 */) = cpu.eax;
    // 0049ca7e  891d84894d00           -mov dword ptr [0x4d8984], ebx
    app->getMemory<x86::reg32>(x86::reg32(5081476) /* 0x4d8984 */) = cpu.ebx;
    // 0049ca84  a184894d00             -mov eax, dword ptr [0x4d8984]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081476) /* 0x4d8984 */);
    // 0049ca89  a380ea5600             -mov dword ptr [0x56ea80], eax
    app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */) = cpu.eax;
    // 0049ca8e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049ca90  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0049ca95  e8263bfeff             -call 0x4805c0
    cpu.esp -= 4;
    sub_4805c0(app, cpu);
    if (cpu.terminate) return;
    // 0049ca9a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ca9c  e8b7b5feff             -call 0x488058
    cpu.esp -= 4;
    sub_488058(app, cpu);
    if (cpu.terminate) return;
    // 0049caa1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049caa3  7440                   -je 0x49cae5
    if (cpu.flags.zf)
    {
        goto L_0x0049cae5;
    }
    // 0049caa5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049caa7  e818310000             -call 0x49fbc4
    cpu.esp -= 4;
    sub_49fbc4(app, cpu);
    if (cpu.terminate) return;
    // 0049caac  83c470                 +add esp, 0x70
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049caaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cab0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cab1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cab2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cab3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049cab4:
    // 0049cab4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049cab6  e8e5300000             -call 0x49fba0
    cpu.esp -= 4;
    sub_49fba0(app, cpu);
    if (cpu.terminate) return;
    // 0049cabb  e86c3efeff             -call 0x48092c
    cpu.esp -= 4;
    sub_48092c(app, cpu);
    if (cpu.terminate) return;
    // 0049cac0  e955ffffff             -jmp 0x49ca1a
    goto L_0x0049ca1a;
L_0x0049cac5:
    // 0049cac5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049cac7  e95effffff             -jmp 0x49ca2a
    goto L_0x0049ca2a;
L_0x0049cacc:
    // 0049cacc  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049cace  e974ffffff             -jmp 0x49ca47
    goto L_0x0049ca47;
L_0x0049cad3:
    // 0049cad3  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049cad5  e96effffff             -jmp 0x49ca48
    goto L_0x0049ca48;
L_0x0049cada:
    // 0049cada  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cadc  e977ffffff             -jmp 0x49ca58
    goto L_0x0049ca58;
L_0x0049cae1:
    // 0049cae1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049cae3  eb87                   -jmp 0x49ca6c
    goto L_0x0049ca6c;
L_0x0049cae5:
    // 0049cae5  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0049caea  e8e1b8feff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0049caef  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0049caf2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caf4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caf5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049caf6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49caf7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049caf7);
    // 0049caf7  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049caf9  e91dfeffff             -jmp 0x49c91b
    return sub_49c91b(app, cpu);
}

/* align: skip  */
void Application::sub_49cafe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cafe);
    // 0049cafe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049cb00  e92ffeffff             -jmp 0x49c934
    return sub_49c934(app, cpu);
}

/* align: skip  */
void Application::sub_49cb05(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cb05);
    // 0049cb05  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049cb07  e93afeffff             -jmp 0x49c946
    return sub_49c946(app, cpu);
}

/* align: skip  */
void Application::sub_49cb0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cb0c);
    // 0049cb0c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049cb0e  e950feffff             -jmp 0x49c963
    return sub_49c963(app, cpu);
}

/* align: skip  */
void Application::sub_49cb13(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cb13);
    // 0049cb13  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049cb15  e949feffff             -jmp 0x49c963
    return sub_49c963(app, cpu);
}

/* align: skip  */
void Application::sub_49cb1a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cb1a);
    // 0049cb1a  39d3                   +cmp ebx, edx
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
    // 0049cb1c  0f855bfeffff           -jne 0x49c97d
    if (!cpu.flags.zf)
    {
        return sub_49c97d(app, cpu);
    }
    // 0049cb22  e964feffff             -jmp 0x49c98b
    return sub_49c98b(app, cpu);
}

/* align: skip  */
void Application::sub_49cb27(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cb27);
    // 0049cb27  3b3d80ea5600           +cmp edi, dword ptr [0x56ea80]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cb2d  0f8564feffff           -jne 0x49c997
    if (!cpu.flags.zf)
    {
        return sub_49c997(app, cpu);
    }
    // 0049cb33  e96bfeffff             -jmp 0x49c9a3
    return sub_49c9a3(app, cpu);
}

/* align: skip  */
void Application::sub_49cb38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cb38);
    // 0049cb38  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cb3a  ff15688a4d00           -call dword ptr [0x4d8a68]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5081704) /* 0x4d8a68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049cb40  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049cb43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49cb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cb50);
    // 0049cb50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049cb51  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049cb56  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049cb58  e813000000             -call 0x49cb70
    cpu.esp -= 4;
    sub_49cb70(app, cpu);
    if (cpu.terminate) return;
    // 0049cb5d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49cb60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cb60);
    // 0049cb60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049cb61  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049cb66  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cb68  e803000000             -call 0x49cb70
    cpu.esp -= 4;
    sub_49cb70(app, cpu);
    if (cpu.terminate) return;
    // 0049cb6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49cb70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cb70);
    // 0049cb70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049cb71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049cb72  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cb73  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cb74  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049cb75  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049cb78  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049cb7b  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 0049cb80  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049cb82  83f801                 +cmp eax, 1
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
    // 0049cb85  7328                   -jae 0x49cbaf
    if (!cpu.flags.cf)
    {
        goto L_0x0049cbaf;
    }
    // 0049cb87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cb89  751b                   -jne 0x49cba6
    if (!cpu.flags.zf)
    {
        goto L_0x0049cba6;
    }
    // 0049cb8b  b014                   -mov al, 0x14
    cpu.al = 20 /*0x14*/;
    // 0049cb8d  b33a                   -mov bl, 0x3a
    cpu.bl = 58 /*0x3a*/;
L_0x0049cb8f:
    // 0049cb8f  0fb6f0                 -movzx esi, al
    cpu.esi = x86::reg32(cpu.al);
    // 0049cb92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cb93  2eff15c0434c00         -call dword ptr cs:[0x4c43c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998080) /* 0x4c43c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049cb9a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049cb9c  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0049cb9e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049cba1  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0049cba2  39d0                   +cmp eax, edx
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
    // 0049cba4  7525                   -jne 0x49cbcb
    if (!cpu.flags.zf)
    {
        goto L_0x0049cbcb;
    }
L_0x0049cba6:
    // 0049cba6  83c404                 +add esp, 4
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
    // 0049cba9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cbaa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cbab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cbac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cbad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cbae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049cbaf:
    // 0049cbaf  7710                   -ja 0x49cbc1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049cbc1;
    }
    // 0049cbb1  b090                   -mov al, 0x90
    cpu.al = 144 /*0x90*/;
    // 0049cbb3  b345                   -mov bl, 0x45
    cpu.bl = 69 /*0x45*/;
    // 0049cbb5  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0049cbba  bd03000000             -mov ebp, 3
    cpu.ebp = 3 /*0x3*/;
    // 0049cbbf  ebce                   -jmp 0x49cb8f
    goto L_0x0049cb8f;
L_0x0049cbc1:
    // 0049cbc1  39e8                   +cmp eax, ebp
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
    // 0049cbc3  75e1                   -jne 0x49cba6
    if (!cpu.flags.zf)
    {
        goto L_0x0049cba6;
    }
    // 0049cbc5  b091                   -mov al, 0x91
    cpu.al = 145 /*0x91*/;
    // 0049cbc7  b346                   -mov bl, 0x46
    cpu.bl = 70 /*0x46*/;
    // 0049cbc9  ebc4                   -jmp 0x49cb8f
    goto L_0x0049cb8f;
L_0x0049cbcb:
    // 0049cbcb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049cbcd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cbce  0fb6fb                 -movzx edi, bl
    cpu.edi = x86::reg32(cpu.bl);
    // 0049cbd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cbd2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cbd3  2eff151c444c00         -call dword ptr cs:[0x4c441c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998172) /* 0x4c441c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049cbda  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049cbdc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049cbdd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cbde  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cbdf  2eff151c444c00         -call dword ptr cs:[0x4c441c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998172) /* 0x4c441c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049cbe6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049cbe9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cbea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cbeb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cbec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cbed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cbee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49cbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cbf0);
    // 0049cbf0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cbf2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49cc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cc00);
    // 0049cc00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049cc01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cc02  81ec00140000           -sub esp, 0x1400
    (cpu.esp) -= x86::reg32(x86::sreg32(5120 /*0x1400*/));
    // 0049cc08  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049cc0a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049cc0c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049cc0e  ff15a4ee5600           -call dword ptr [0x56eea4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697188) /* 0x56eea4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049cc14  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049cc16  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049cc18  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049cc1a  ff15a0ee5600           -call dword ptr [0x56eea0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697184) /* 0x56eea0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049cc20  81c400140000           -add esp, 0x1400
    (cpu.esp) += x86::reg32(x86::sreg32(5120 /*0x1400*/));
    // 0049cc26  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc28  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49cc2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049cc2c);
    // 0049cc2c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cc2d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cc2e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049cc2f  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049cc32  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049cc34  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049cc38  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0049cc3c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049cc3e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049cc40  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049cc43  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 0049cc49  0fb62d79904d00         -movzx ebp, byte ptr [0x4d9079]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5083257) /* 0x4d9079 */));
    // 0049cc50  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0049cc53  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cc55  8b5920                 -mov ebx, dword ptr [ecx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0049cc58  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049cc5c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049cc60  8915a4ee5600           -mov dword ptr [0x56eea4], edx
    app->getMemory<x86::reg32>(x86::reg32(5697188) /* 0x56eea4 */) = cpu.edx;
    // 0049cc66  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049cc68  7402                   -je 0x49cc6c
    if (cpu.flags.zf)
    {
        goto L_0x0049cc6c;
    }
    // 0049cc6a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0049cc6c:
    // 0049cc6c  837c241000             +cmp dword ptr [esp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cc71  7540                   -jne 0x49ccb3
    if (!cpu.flags.zf)
    {
        goto L_0x0049ccb3;
    }
    // 0049cc73  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049cc75  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049cc7a  39e8                   +cmp eax, ebp
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
    // 0049cc7c  7435                   -je 0x49ccb3
    if (cpu.flags.zf)
    {
        goto L_0x0049ccb3;
    }
    // 0049cc7e  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cc82  0f8464020000           -je 0x49ceec
    if (cpu.flags.zf)
    {
        goto L_0x0049ceec;
    }
    // 0049cc88  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0049cc8d:
    // 0049cc8d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049cc8f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049cc91  e88682ffff             -call 0x494f1c
    cpu.esp -= 4;
    sub_494f1c(app, cpu);
    if (cpu.terminate) return;
    // 0049cc96  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049cc9a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cc9c  0f8451020000           -je 0x49cef3
    if (cpu.flags.zf)
    {
        goto L_0x0049cef3;
    }
    // 0049cca2  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cca6  740b                   -je 0x49ccb3
    if (cpu.flags.zf)
    {
        goto L_0x0049ccb3;
    }
    // 0049cca8  a3a4ee5600             -mov dword ptr [0x56eea4], eax
    app->getMemory<x86::reg32>(x86::reg32(5697188) /* 0x56eea4 */) = cpu.eax;
    // 0049ccad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ccaf  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0049ccb3:
    // 0049ccb3  8d4e10                 -lea ecx, [esi + 0x10]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049ccb6  8b6e02                 -mov ebp, dword ptr [esi + 2]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0049ccb9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ccbb  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049ccbe  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ccc0  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049ccc3  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 0049ccc9  40                     -inc eax
    (cpu.eax)++;
    // 0049ccca  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049cccc  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 0049cccf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049ccd1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049ccd3  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049ccd6  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0049ccd9  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049ccdd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ccdf  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049cce3  e878850000             -call 0x4a5260
    cpu.esp -= 4;
    sub_4a5260(app, cpu);
    if (cpu.terminate) return;
    // 0049cce8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ccea  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049ccee  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049ccf2  a16c904d00             -mov eax, dword ptr [0x4d906c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 0049ccf7  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ccf9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049ccfc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ccfe  7e15                   -jle 0x49cd15
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cd15;
    }
    // 0049cd00  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049cd04  0faff0                 -imul esi, eax
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049cd07  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049cd09  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049cd0d  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049cd0f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cd11  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
L_0x0049cd15:
    // 0049cd15  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049cd19  8b3574904d00           -mov esi, dword ptr [0x4d9074]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */);
    // 0049cd1f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049cd21  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049cd23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cd25  7e02                   -jle 0x49cd29
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cd29;
    }
    // 0049cd27  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049cd29:
    // 0049cd29  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049cd2d  a168904d00             -mov eax, dword ptr [0x4d9068]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 0049cd32  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049cd34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cd36  7e20                   -jle 0x49cd58
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cd58;
    }
    // 0049cd38  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049cd3a  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049cd3d  c1fe03                 -sar esi, 3
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (3 /*0x3*/ % 32));
    // 0049cd40  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0049cd43  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049cd45  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049cd49  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cd4b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049cd4d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049cd50  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0049cd54  01442420               -add dword ptr [esp + 0x20], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049cd58:
    // 0049cd58  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049cd5c  8b3570904d00           -mov esi, dword ptr [0x4d9070]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */);
    // 0049cd62  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049cd64  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049cd66  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cd68  7e0e                   -jle 0x49cd78
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cd78;
    }
    // 0049cd6a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049cd6c  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049cd6f  c1fe03                 -sar esi, 3
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (3 /*0x3*/ % 32));
    // 0049cd72  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cd74  01742420               -add dword ptr [esp + 0x20], esi
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.esi));
L_0x0049cd78:
    // 0049cd78  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049cd7a  0f8e59010000           -jle 0x49ced9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ced9;
    }
    // 0049cd80  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049cd82  0f8e51010000           -jle 0x49ced9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ced9;
    }
    // 0049cd88  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0049cd8b  a17c904d00             -mov eax, dword ptr [0x4d907c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */);
    // 0049cd90  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0049cd94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cd96  a078904d00             -mov al, byte ptr [0x4d9078]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 0049cd9b  40                     -inc eax
    (cpu.eax)++;
    // 0049cd9c  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049cd9e  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0049cda1  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0049cda4  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0049cda7  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049cdab  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0049cdaf  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049cdb3  8b1d88904d00           -mov ebx, dword ptr [0x4d9088]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 0049cdb9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049cdbc  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049cdbe  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049cdc2  8b358c904d00           -mov esi, dword ptr [0x4d908c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 0049cdc8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049cdcb  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049cdcd  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049cdcf  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049cdd1  a184904d00             -mov eax, dword ptr [0x4d9084]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083268) /* 0x4d9084 */);
    // 0049cdd6  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cdd8  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049cddc  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cdde  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049cde2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049cde6  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0049cdea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cdec  0f8542010000           -jne 0x49cf34
    if (!cpu.flags.zf)
    {
        goto L_0x0049cf34;
    }
    // 0049cdf2  a078904d00             -mov al, byte ptr [0x4d9078]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 0049cdf7  3c0f                   +cmp al, 0xf
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049cdf9  0f833e010000           -jae 0x49cf3d
    if (!cpu.flags.cf)
    {
        goto L_0x0049cf3d;
    }
    // 0049cdff  3c04                   +cmp al, 4
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
    // 0049ce01  0f837e010000           -jae 0x49cf85
    if (!cpu.flags.cf)
    {
        goto L_0x0049cf85;
    }
L_0x0049ce07:
    // 0049ce07  833da4ee560000         +cmp dword ptr [0x56eea4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5697188) /* 0x56eea4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ce0e  0f8592010000           -jne 0x49cfa6
    if (!cpu.flags.zf)
    {
        goto L_0x0049cfa6;
    }
L_0x0049ce14:
    // 0049ce14  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049ce18  03442414               -add eax, dword ptr [esp + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0049ce1c  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049ce20  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0049ce24  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049ce28  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049ce2a  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0049ce2e:
    // 0049ce2e  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049ce32  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049ce34  745a                   -je 0x49ce90
    if (cpu.flags.zf)
    {
        goto L_0x0049ce90;
    }
    // 0049ce36  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049ce3a  a190904d00             -mov eax, dword ptr [0x4d9090]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083280) /* 0x4d9090 */);
    // 0049ce3f  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049ce41  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049ce43  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049ce45  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0049ce49  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0049ce4d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ce4f  0f8480010000           -je 0x49cfd5
    if (cpu.flags.zf)
    {
        goto L_0x0049cfd5;
    }
    // 0049ce55  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ce57  895c243c               -mov dword ptr [esp + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
L_0x0049ce5b:
    // 0049ce5b  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049ce5f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0049ce61  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ce63  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049ce65  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ce69  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049ce6d  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049ce71  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049ce75  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ce77  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049ce79  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049ce7b  8b1dfc894d00           -mov ebx, dword ptr [0x4d89fc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081596) /* 0x4d89fc */);
    // 0049ce81  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0049ce85  39da                   +cmp edx, ebx
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
    // 0049ce87  0f8f30010000           -jg 0x49cfbd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049cfbd;
    }
L_0x0049ce8d:
    // 0049ce8d  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049ce8e  75cb                   -jne 0x49ce5b
    if (!cpu.flags.zf)
    {
        goto L_0x0049ce5b;
    }
L_0x0049ce90:
    // 0049ce90  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049ce94  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049ce96  7436                   -je 0x49cece
    if (cpu.flags.zf)
    {
        goto L_0x0049cece;
    }
    // 0049ce98  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0049ce9b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ce9d  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049cea1  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0049cea5  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0049cea7  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049cea9  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049cead  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ceb1  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049ceb5  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049ceb9  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049cebd  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049cebf  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049cec3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049cec5  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049cec7  47                     -inc edi
    (cpu.edi)++;
    // 0049cec8  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ceca  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
L_0x0049cece:
    // 0049cece  837c242800             +cmp dword ptr [esp + 0x28], 0
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
    // 0049ced3  0f8f55ffffff           -jg 0x49ce2e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049ce2e;
    }
L_0x0049ced9:
    // 0049ced9  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049cedd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049cedf  0f8550010000           -jne 0x49d035
    if (!cpu.flags.zf)
    {
        goto L_0x0049d035;
    }
L_0x0049cee5:
    // 0049cee5  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049cee8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cee9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ceea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ceeb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ceec:
    // 0049ceec  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0049ceee  e99afdffff             -jmp 0x49cc8d
    goto L_0x0049cc8d;
L_0x0049cef3:
    // 0049cef3  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cef7  7421                   -je 0x49cf1a
    if (cpu.flags.zf)
    {
        goto L_0x0049cf1a;
    }
    // 0049cef9  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0049cefe:
    // 0049cefe  8b5f1c                 -mov ebx, dword ptr [edi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0049cf01  83fb01                 +cmp ebx, 1
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
    // 0049cf04  7518                   -jne 0x49cf1e
    if (!cpu.flags.zf)
    {
        goto L_0x0049cf1e;
    }
    // 0049cf06  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049cf08  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049cf0a  e84981ffff             -call 0x495058
    cpu.esp -= 4;
    sub_495058(app, cpu);
    if (cpu.terminate) return;
    // 0049cf0f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049cf13  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049cf15  e999fdffff             -jmp 0x49ccb3
    goto L_0x0049ccb3;
L_0x0049cf1a:
    // 0049cf1a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049cf1c  ebe0                   -jmp 0x49cefe
    goto L_0x0049cefe;
L_0x0049cf1e:
    // 0049cf1e  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0049cf20  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049cf22  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049cf24  e82f81ffff             -call 0x495058
    cpu.esp -= 4;
    sub_495058(app, cpu);
    if (cpu.terminate) return;
    // 0049cf29  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049cf2d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049cf2f  e97ffdffff             -jmp 0x49ccb3
    goto L_0x0049ccb3;
L_0x0049cf34:
    // 0049cf34  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049cf38  e9d7feffff             -jmp 0x49ce14
    goto L_0x0049ce14;
L_0x0049cf3d:
    // 0049cf3d  770c                   -ja 0x49cf4b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049cf4b;
    }
    // 0049cf3f  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049cf42  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049cf46  e9bcfeffff             -jmp 0x49ce07
    goto L_0x0049ce07;
L_0x0049cf4b:
    // 0049cf4b  3c18                   +cmp al, 0x18
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049cf4d  7314                   -jae 0x49cf63
    if (!cpu.flags.cf)
    {
        goto L_0x0049cf63;
    }
    // 0049cf4f  3c10                   +cmp al, 0x10
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
    // 0049cf51  0f85b0feffff           -jne 0x49ce07
    if (!cpu.flags.zf)
    {
        goto L_0x0049ce07;
    }
    // 0049cf57  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0049cf5a  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049cf5e  e9a4feffff             -jmp 0x49ce07
    goto L_0x0049ce07;
L_0x0049cf63:
    // 0049cf63  770c                   -ja 0x49cf71
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049cf71;
    }
    // 0049cf65  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0049cf68  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049cf6c  e996feffff             -jmp 0x49ce07
    goto L_0x0049ce07;
L_0x0049cf71:
    // 0049cf71  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049cf73  0f858efeffff           -jne 0x49ce07
    if (!cpu.flags.zf)
    {
        goto L_0x0049ce07;
    }
    // 0049cf79  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0049cf7c  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049cf80  e982feffff             -jmp 0x49ce07
    goto L_0x0049ce07;
L_0x0049cf85:
    // 0049cf85  770b                   -ja 0x49cf92
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049cf92;
    }
    // 0049cf87  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049cf89  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049cf8d  e975feffff             -jmp 0x49ce07
    goto L_0x0049ce07;
L_0x0049cf92:
    // 0049cf92  3c08                   +cmp al, 8
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049cf94  0f856dfeffff           -jne 0x49ce07
    if (!cpu.flags.zf)
    {
        goto L_0x0049ce07;
    }
    // 0049cf9a  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049cf9d  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049cfa1  e961feffff             -jmp 0x49ce07
    goto L_0x0049ce07;
L_0x0049cfa6:
    // 0049cfa6  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049cfaa  bb00cc4900             -mov ebx, 0x49cc00
    cpu.ebx = 4836352 /*0x49cc00*/;
    // 0049cfaf  a3a0ee5600             -mov dword ptr [0x56eea0], eax
    app->getMemory<x86::reg32>(x86::reg32(5697184) /* 0x56eea0 */) = cpu.eax;
    // 0049cfb4  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0049cfb8  e957feffff             -jmp 0x49ce14
    goto L_0x0049ce14;
L_0x0049cfbd:
    // 0049cfbd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cfbf  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0049cfc3  e87054feff             -call 0x482438
    cpu.esp -= 4;
    sub_482438(app, cpu);
    if (cpu.terminate) return;
    // 0049cfc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cfca  0f8415ffffff           -je 0x49cee5
    if (cpu.flags.zf)
    {
        goto L_0x0049cee5;
    }
    // 0049cfd0  e9b8feffff             -jmp 0x49ce8d
    goto L_0x0049ce8d;
L_0x0049cfd5:
    // 0049cfd5  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 0049cfda  7422                   -je 0x49cffe
    if (cpu.flags.zf)
    {
        goto L_0x0049cffe;
    }
L_0x0049cfdc:
    // 0049cfdc  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049cfe0  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0049cfe2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049cfe4  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049cfe6  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049cfea  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049cfee  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049cff2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049cff4  01d1                   +add ecx, edx
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
    // 0049cff6  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049cff7  75e3                   -jne 0x49cfdc
    if (!cpu.flags.zf)
    {
        goto L_0x0049cfdc;
    }
    // 0049cff9  e992feffff             -jmp 0x49ce90
    goto L_0x0049ce90;
L_0x0049cffe:
    // 0049cffe  837c242000             +cmp dword ptr [esp + 0x20], 0
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
    // 0049d003  75d7                   -jne 0x49cfdc
    if (!cpu.flags.zf)
    {
        goto L_0x0049cfdc;
    }
    // 0049d005  817c243800cc4900       +cmp dword ptr [esp + 0x38], 0x49cc00
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4836352 /*0x49cc00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d00d  74cd                   -je 0x49cfdc
    if (cpu.flags.zf)
    {
        goto L_0x0049cfdc;
    }
    // 0049d00f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0049d011  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0049d014  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049d018  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d01a  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049d01c  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d020  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049d024  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0049d027  0faf7c2418             -imul edi, dword ptr [esp + 0x18]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0049d02c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049d02e  01f9                   +add ecx, edi
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
    // 0049d030  e95bfeffff             -jmp 0x49ce90
    goto L_0x0049ce90;
L_0x0049d035:
    // 0049d035  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049d037  e8305dfeff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0049d03c  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049d03f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d040  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d041  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d042  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49d044(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d044);
    // 0049d044  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 0049d045  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d046  a903000000             +test eax, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 3 /*0x3*/));
    // 0049d04b  0f8599000000           -jne 0x49d0ea
    if (!cpu.flags.zf)
    {
        goto L_0x0049d0ea;
    }
L_0x0049d051:
    // 0049d051  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d054  7839                   -js 0x49d08f
    if (cpu.flags.sf)
    {
        goto L_0x0049d08f;
    }
L_0x0049d056:
    // 0049d056  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049d058  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049d05a  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049d05d  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049d060  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049d063  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049d066  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049d069  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049d06c  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049d06f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049d072  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0049d075  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049d078  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049d07b  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0049d07e  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0049d081  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049d084  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049d087  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049d08a  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d08d  79c7                   -jns 0x49d056
    if (!cpu.flags.sf)
    {
        goto L_0x0049d056;
    }
L_0x0049d08f:
    // 0049d08f  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d092  7815                   -js 0x49d0a9
    if (cpu.flags.sf)
    {
        goto L_0x0049d0a9;
    }
L_0x0049d094:
    // 0049d094  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049d096  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049d098  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049d09b  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049d09e  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049d0a1  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049d0a4  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d0a7  79eb                   -jns 0x49d094
    if (!cpu.flags.sf)
    {
        goto L_0x0049d094;
    }
L_0x0049d0a9:
    // 0049d0a9  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d0ac  7502                   -jne 0x49d0b0
    if (!cpu.flags.zf)
    {
        goto L_0x0049d0b0;
    }
    // 0049d0ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d0af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d0b0:
    // 0049d0b0  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d0b3  720d                   -jb 0x49d0c2
    if (cpu.flags.cf)
    {
        goto L_0x0049d0c2;
    }
    // 0049d0b5  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049d0b7  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049d0ba  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049d0bc  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049d0bf  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049d0c2:
    // 0049d0c2  83fb02                 +cmp ebx, 2
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
    // 0049d0c5  720f                   -jb 0x49d0d6
    if (cpu.flags.cf)
    {
        goto L_0x0049d0d6;
    }
    // 0049d0c7  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049d0ca  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049d0cd  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049d0d0  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049d0d3  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049d0d6:
    // 0049d0d6  83fb01                 +cmp ebx, 1
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
    // 0049d0d9  720d                   -jb 0x49d0e8
    if (cpu.flags.cf)
    {
        goto L_0x0049d0e8;
    }
    // 0049d0db  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049d0dd  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049d0e0  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049d0e2  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049d0e5  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049d0e8:
    // 0049d0e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d0e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d0ea:
    // 0049d0ea  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0049d0ef  7412                   -je 0x49d103
    if (cpu.flags.zf)
    {
        goto L_0x0049d103;
    }
    // 0049d0f1  83fb01                 +cmp ebx, 1
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
    // 0049d0f4  7c0d                   -jl 0x49d103
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d103;
    }
    // 0049d0f6  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049d0f8  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049d0fb  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049d0fd  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049d100  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049d103:
    // 0049d103  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0049d108  7414                   -je 0x49d11e
    if (cpu.flags.zf)
    {
        goto L_0x0049d11e;
    }
    // 0049d10a  83fb02                 +cmp ebx, 2
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
    // 0049d10d  7c0f                   -jl 0x49d11e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d11e;
    }
    // 0049d10f  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049d112  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049d115  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049d118  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049d11b  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049d11e:
    // 0049d11e  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0049d123  7412                   -je 0x49d137
    if (cpu.flags.zf)
    {
        goto L_0x0049d137;
    }
    // 0049d125  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d128  7c0d                   -jl 0x49d137
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d137;
    }
    // 0049d12a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049d12c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049d12f  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049d131  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049d134  83eb04                 +sub ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0049d137:
    // 0049d137  e915ffffff             -jmp 0x49d051
    goto L_0x0049d051;
}

/* align: skip  */
void Application::sub_49d045(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d045);
    goto L_entry_0x0049d045;
    // 0049d044  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x0049d045:
    // 0049d045  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d046  a903000000             +test eax, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 3 /*0x3*/));
    // 0049d04b  0f8599000000           -jne 0x49d0ea
    if (!cpu.flags.zf)
    {
        goto L_0x0049d0ea;
    }
L_0x0049d051:
    // 0049d051  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d054  7839                   -js 0x49d08f
    if (cpu.flags.sf)
    {
        goto L_0x0049d08f;
    }
L_0x0049d056:
    // 0049d056  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049d058  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049d05a  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049d05d  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049d060  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049d063  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049d066  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049d069  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049d06c  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049d06f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049d072  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0049d075  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049d078  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049d07b  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0049d07e  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0049d081  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049d084  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049d087  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049d08a  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d08d  79c7                   -jns 0x49d056
    if (!cpu.flags.sf)
    {
        goto L_0x0049d056;
    }
L_0x0049d08f:
    // 0049d08f  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d092  7815                   -js 0x49d0a9
    if (cpu.flags.sf)
    {
        goto L_0x0049d0a9;
    }
L_0x0049d094:
    // 0049d094  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049d096  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049d098  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049d09b  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049d09e  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049d0a1  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049d0a4  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d0a7  79eb                   -jns 0x49d094
    if (!cpu.flags.sf)
    {
        goto L_0x0049d094;
    }
L_0x0049d0a9:
    // 0049d0a9  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d0ac  7502                   -jne 0x49d0b0
    if (!cpu.flags.zf)
    {
        goto L_0x0049d0b0;
    }
    // 0049d0ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d0af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d0b0:
    // 0049d0b0  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d0b3  720d                   -jb 0x49d0c2
    if (cpu.flags.cf)
    {
        goto L_0x0049d0c2;
    }
    // 0049d0b5  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049d0b7  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049d0ba  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049d0bc  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049d0bf  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049d0c2:
    // 0049d0c2  83fb02                 +cmp ebx, 2
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
    // 0049d0c5  720f                   -jb 0x49d0d6
    if (cpu.flags.cf)
    {
        goto L_0x0049d0d6;
    }
    // 0049d0c7  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049d0ca  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049d0cd  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049d0d0  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049d0d3  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049d0d6:
    // 0049d0d6  83fb01                 +cmp ebx, 1
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
    // 0049d0d9  720d                   -jb 0x49d0e8
    if (cpu.flags.cf)
    {
        goto L_0x0049d0e8;
    }
    // 0049d0db  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049d0dd  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049d0e0  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049d0e2  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049d0e5  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049d0e8:
    // 0049d0e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d0e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d0ea:
    // 0049d0ea  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0049d0ef  7412                   -je 0x49d103
    if (cpu.flags.zf)
    {
        goto L_0x0049d103;
    }
    // 0049d0f1  83fb01                 +cmp ebx, 1
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
    // 0049d0f4  7c0d                   -jl 0x49d103
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d103;
    }
    // 0049d0f6  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049d0f8  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049d0fb  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049d0fd  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049d100  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049d103:
    // 0049d103  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0049d108  7414                   -je 0x49d11e
    if (cpu.flags.zf)
    {
        goto L_0x0049d11e;
    }
    // 0049d10a  83fb02                 +cmp ebx, 2
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
    // 0049d10d  7c0f                   -jl 0x49d11e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d11e;
    }
    // 0049d10f  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049d112  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049d115  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049d118  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049d11b  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049d11e:
    // 0049d11e  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0049d123  7412                   -je 0x49d137
    if (cpu.flags.zf)
    {
        goto L_0x0049d137;
    }
    // 0049d125  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d128  7c0d                   -jl 0x49d137
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d137;
    }
    // 0049d12a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049d12c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049d12f  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049d131  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049d134  83eb04                 +sub ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0049d137:
    // 0049d137  e915ffffff             -jmp 0x49d051
    goto L_0x0049d051;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_49d140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d140);
    // 0049d140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d141  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d142  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d143  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d144  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 0049d149  b8a8ee5600             -mov eax, 0x56eea8
    cpu.eax = 5697192 /*0x56eea8*/;
    // 0049d14e  b980000000             -mov ecx, 0x80
    cpu.ecx = 128 /*0x80*/;
    // 0049d153  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049d158  bf00010000             -mov edi, 0x100
    cpu.edi = 256 /*0x100*/;
    // 0049d15d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d15f  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 0049d164  e80604ffff             -call 0x48d56f
    cpu.esp -= 4;
    sub_48d56f(app, cpu);
    if (cpu.terminate) return;
    // 0049d169  ba58464433             -mov edx, 0x33444658
    cpu.edx = 860112472 /*0x33444658*/;
    // 0049d16e  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0049d173  b8ffb54d00             -mov eax, 0x4db5ff
    cpu.eax = 5092863 /*0x4db5ff*/;
    // 0049d178  890dacee5600           -mov dword ptr [0x56eeac], ecx
    app->getMemory<x86::reg32>(x86::reg32(5697196) /* 0x56eeac */) = cpu.ecx;
    // 0049d17e  8935b8ee5600           -mov dword ptr [0x56eeb8], esi
    app->getMemory<x86::reg32>(x86::reg32(5697208) /* 0x56eeb8 */) = cpu.esi;
    // 0049d184  893dbcee5600           -mov dword ptr [0x56eebc], edi
    app->getMemory<x86::reg32>(x86::reg32(5697212) /* 0x56eebc */) = cpu.edi;
    // 0049d18a  8935c0ee5600           -mov dword ptr [0x56eec0], esi
    app->getMemory<x86::reg32>(x86::reg32(5697216) /* 0x56eec0 */) = cpu.esi;
    // 0049d190  8935c4ee5600           -mov dword ptr [0x56eec4], esi
    app->getMemory<x86::reg32>(x86::reg32(5697220) /* 0x56eec4 */) = cpu.esi;
    // 0049d196  893dc8ee5600           -mov dword ptr [0x56eec8], edi
    app->getMemory<x86::reg32>(x86::reg32(5697224) /* 0x56eec8 */) = cpu.edi;
    // 0049d19c  8935ccee5600           -mov dword ptr [0x56eecc], esi
    app->getMemory<x86::reg32>(x86::reg32(5697228) /* 0x56eecc */) = cpu.esi;
    // 0049d1a2  8935d0ee5600           -mov dword ptr [0x56eed0], esi
    app->getMemory<x86::reg32>(x86::reg32(5697232) /* 0x56eed0 */) = cpu.esi;
    // 0049d1a8  892ddcee5600           -mov dword ptr [0x56eedc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5697244) /* 0x56eedc */) = cpu.ebp;
    // 0049d1ae  be09000000             -mov esi, 9
    cpu.esi = 9 /*0x9*/;
    // 0049d1b3  bff4b54d00             -mov edi, 0x4db5f4
    cpu.edi = 5092852 /*0x4db5f4*/;
    // 0049d1b8  b90cb64d00             -mov ecx, 0x4db60c
    cpu.ecx = 5092876 /*0x4db60c*/;
    // 0049d1bd  8915a8ee5600           -mov dword ptr [0x56eea8], edx
    app->getMemory<x86::reg32>(x86::reg32(5697192) /* 0x56eea8 */) = cpu.edx;
    // 0049d1c3  891db0ee5600           -mov dword ptr [0x56eeb0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5697200) /* 0x56eeb0 */) = cpu.ebx;
    // 0049d1c9  a3e0ee5600             -mov dword ptr [0x56eee0], eax
    app->getMemory<x86::reg32>(x86::reg32(5697248) /* 0x56eee0 */) = cpu.eax;
    // 0049d1ce  668b15b4ee5600         -mov dx, word ptr [0x56eeb4]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5697204) /* 0x56eeb4 */);
    // 0049d1d5  8935d4ee5600           -mov dword ptr [0x56eed4], esi
    app->getMemory<x86::reg32>(x86::reg32(5697236) /* 0x56eed4 */) = cpu.esi;
    // 0049d1db  893dd8ee5600           -mov dword ptr [0x56eed8], edi
    app->getMemory<x86::reg32>(x86::reg32(5697240) /* 0x56eed8 */) = cpu.edi;
    // 0049d1e1  890de8ee5600           -mov dword ptr [0x56eee8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5697256) /* 0x56eee8 */) = cpu.ecx;
    // 0049d1e7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d1e9  bfa8ee5600             -mov edi, 0x56eea8
    cpu.edi = 5697192 /*0x56eea8*/;
    // 0049d1ee  be90ef4c00             -mov esi, 0x4cef90
    cpu.esi = 5042064 /*0x4cef90*/;
    // 0049d1f3  81cadf010000           -or edx, 0x1df
    cpu.edx |= x86::reg32(x86::sreg32(479 /*0x1df*/));
    // 0049d1f9  891decee5600           -mov dword ptr [0x56eeec], ebx
    app->getMemory<x86::reg32>(x86::reg32(5697260) /* 0x56eeec */) = cpu.ebx;
    // 0049d1ff  891df0ee5600           -mov dword ptr [0x56eef0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5697264) /* 0x56eef0 */) = cpu.ebx;
    // 0049d205  668915b4ee5600         -mov word ptr [0x56eeb4], dx
    app->getMemory<x86::reg16>(x86::reg32(5697204) /* 0x56eeb4 */) = cpu.dx;
    // 0049d20c  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0049d211  83c74c                 -add edi, 0x4c
    (cpu.edi) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0049d214  8915e4ee5600           -mov dword ptr [0x56eee4], edx
    app->getMemory<x86::reg32>(x86::reg32(5697252) /* 0x56eee4 */) = cpu.edx;
    // 0049d21a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049d21b:
    // 0049d21b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049d21d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049d21f  3c00                   +cmp al, 0
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
    // 0049d221  7410                   -je 0x49d233
    if (cpu.flags.zf)
    {
        goto L_0x0049d233;
    }
    // 0049d223  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049d226  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d229  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049d22c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d22f  3c00                   +cmp al, 0
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
    // 0049d231  75e8                   -jne 0x49d21b
    if (!cpu.flags.zf)
    {
        goto L_0x0049d21b;
    }
L_0x0049d233:
    // 0049d233  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d234  b8a8ee5600             -mov eax, 0x56eea8
    cpu.eax = 5697192 /*0x56eea8*/;
    // 0049d239  891d14ef5600           -mov dword ptr [0x56ef14], ebx
    app->getMemory<x86::reg32>(x86::reg32(5697300) /* 0x56ef14 */) = cpu.ebx;
    // 0049d23f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d240  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d241  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d242  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d243  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49d250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d250);
    // 0049d250  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d251  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d252  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d253  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d254  ba52565750             -mov edx, 0x50575652
    cpu.edx = 1347901010 /*0x50575652*/;
    // 0049d259  b980000000             -mov ecx, 0x80
    cpu.ecx = 128 /*0x80*/;
    // 0049d25e  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0049d263  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 0049d268  bf00010000             -mov edi, 0x100
    cpu.edi = 256 /*0x100*/;
    // 0049d26d  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 0049d272  b891b74d00             -mov eax, 0x4db791
    cpu.eax = 5093265 /*0x4db791*/;
    // 0049d277  891530ef5600           -mov dword ptr [0x56ef30], edx
    app->getMemory<x86::reg32>(x86::reg32(5697328) /* 0x56ef30 */) = cpu.edx;
    // 0049d27d  890d34ef5600           -mov dword ptr [0x56ef34], ecx
    app->getMemory<x86::reg32>(x86::reg32(5697332) /* 0x56ef34 */) = cpu.ecx;
    // 0049d283  891d38ef5600           -mov dword ptr [0x56ef38], ebx
    app->getMemory<x86::reg32>(x86::reg32(5697336) /* 0x56ef38 */) = cpu.ebx;
    // 0049d289  893540ef5600           -mov dword ptr [0x56ef40], esi
    app->getMemory<x86::reg32>(x86::reg32(5697344) /* 0x56ef40 */) = cpu.esi;
    // 0049d28f  893d44ef5600           -mov dword ptr [0x56ef44], edi
    app->getMemory<x86::reg32>(x86::reg32(5697348) /* 0x56ef44 */) = cpu.edi;
    // 0049d295  893548ef5600           -mov dword ptr [0x56ef48], esi
    app->getMemory<x86::reg32>(x86::reg32(5697352) /* 0x56ef48 */) = cpu.esi;
    // 0049d29b  89354cef5600           -mov dword ptr [0x56ef4c], esi
    app->getMemory<x86::reg32>(x86::reg32(5697356) /* 0x56ef4c */) = cpu.esi;
    // 0049d2a1  893d50ef5600           -mov dword ptr [0x56ef50], edi
    app->getMemory<x86::reg32>(x86::reg32(5697360) /* 0x56ef50 */) = cpu.edi;
    // 0049d2a7  893554ef5600           -mov dword ptr [0x56ef54], esi
    app->getMemory<x86::reg32>(x86::reg32(5697364) /* 0x56ef54 */) = cpu.esi;
    // 0049d2ad  892d64ef5600           -mov dword ptr [0x56ef64], ebp
    app->getMemory<x86::reg32>(x86::reg32(5697380) /* 0x56ef64 */) = cpu.ebp;
    // 0049d2b3  a368ef5600             -mov dword ptr [0x56ef68], eax
    app->getMemory<x86::reg32>(x86::reg32(5697384) /* 0x56ef68 */) = cpu.eax;
    // 0049d2b8  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0049d2bd  be07000000             -mov esi, 7
    cpu.esi = 7 /*0x7*/;
    // 0049d2c2  bf88b74d00             -mov edi, 0x4db788
    cpu.edi = 5093256 /*0x4db788*/;
    // 0049d2c7  668b153cef5600         -mov dx, word ptr [0x56ef3c]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5697340) /* 0x56ef3c */);
    // 0049d2ce  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d2d0  81caff010000           -or edx, 0x1ff
    cpu.edx |= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0049d2d6  891d58ef5600           -mov dword ptr [0x56ef58], ebx
    app->getMemory<x86::reg32>(x86::reg32(5697368) /* 0x56ef58 */) = cpu.ebx;
    // 0049d2dc  89355cef5600           -mov dword ptr [0x56ef5c], esi
    app->getMemory<x86::reg32>(x86::reg32(5697372) /* 0x56ef5c */) = cpu.esi;
    // 0049d2e2  893d60ef5600           -mov dword ptr [0x56ef60], edi
    app->getMemory<x86::reg32>(x86::reg32(5697376) /* 0x56ef60 */) = cpu.edi;
    // 0049d2e8  be9cef4c00             -mov esi, 0x4cef9c
    cpu.esi = 5042076 /*0x4cef9c*/;
    // 0049d2ed  8b3d84b74d00           -mov edi, dword ptr [0x4db784]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5093252) /* 0x4db784 */);
    // 0049d2f3  6689153cef5600         -mov word ptr [0x56ef3c], dx
    app->getMemory<x86::reg16>(x86::reg32(5697340) /* 0x56ef3c */) = cpu.dx;
    // 0049d2fa  893d74ef5600           -mov dword ptr [0x56ef74], edi
    app->getMemory<x86::reg32>(x86::reg32(5697396) /* 0x56ef74 */) = cpu.edi;
    // 0049d300  bf30ef5600             -mov edi, 0x56ef30
    cpu.edi = 5697328 /*0x56ef30*/;
    // 0049d305  ba5cb74d00             -mov edx, 0x4db75c
    cpu.edx = 5093212 /*0x4db75c*/;
    // 0049d30a  83c74c                 -add edi, 0x4c
    (cpu.edi) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0049d30d  891578ef5600           -mov dword ptr [0x56ef78], edx
    app->getMemory<x86::reg32>(x86::reg32(5697400) /* 0x56ef78 */) = cpu.edx;
    // 0049d313  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049d314:
    // 0049d314  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049d316  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049d318  3c00                   +cmp al, 0
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
    // 0049d31a  7410                   -je 0x49d32c
    if (cpu.flags.zf)
    {
        goto L_0x0049d32c;
    }
    // 0049d31c  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049d31f  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d322  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049d325  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049d328  3c00                   +cmp al, 0
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
    // 0049d32a  75e8                   -jne 0x49d314
    if (!cpu.flags.zf)
    {
        goto L_0x0049d314;
    }
L_0x0049d32c:
    // 0049d32c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d32d  b830ef5600             -mov eax, 0x56ef30
    cpu.eax = 5697328 /*0x56ef30*/;
    // 0049d332  890d9cef5600           -mov dword ptr [0x56ef9c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5697436) /* 0x56ef9c */) = cpu.ecx;
    // 0049d338  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d339  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d33a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d33b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d33c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49d340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d340);
    // 0049d340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d341  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d342  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d343  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d344  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049d347  8b701c                 -mov esi, dword ptr [eax + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049d34a  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049d34d  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0049d350  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0049d353  83fb10                 +cmp ebx, 0x10
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
    // 0049d356  0f8569000000           -jne 0x49d3c5
    if (!cpu.flags.zf)
    {
        goto L_0x0049d3c5;
    }
    // 0049d35c  81f9007c0000           +cmp ecx, 0x7c00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31744 /*0x7c00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d362  750d                   -jne 0x49d371
    if (!cpu.flags.zf)
    {
        goto L_0x0049d371;
    }
    // 0049d364  81fae0030000           +cmp edx, 0x3e0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(992 /*0x3e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d36a  7505                   -jne 0x49d371
    if (!cpu.flags.zf)
    {
        goto L_0x0049d371;
    }
    // 0049d36c  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d36f  7440                   -je 0x49d3b1
    if (cpu.flags.zf)
    {
        goto L_0x0049d3b1;
    }
L_0x0049d371:
    // 0049d371  81f900f80000           +cmp ecx, 0xf800
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63488 /*0xf800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d377  750d                   -jne 0x49d386
    if (!cpu.flags.zf)
    {
        goto L_0x0049d386;
    }
    // 0049d379  81fae0070000           +cmp edx, 0x7e0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2016 /*0x7e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d37f  7505                   -jne 0x49d386
    if (!cpu.flags.zf)
    {
        goto L_0x0049d386;
    }
    // 0049d381  83f81f                 +cmp eax, 0x1f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d384  7435                   -je 0x49d3bb
    if (cpu.flags.zf)
    {
        goto L_0x0049d3bb;
    }
L_0x0049d386:
    // 0049d386  81f9000f0000           +cmp ecx, 0xf00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3840 /*0xf00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d38c  0f8568000000           -jne 0x49d3fa
    if (!cpu.flags.zf)
    {
        goto L_0x0049d3fa;
    }
    // 0049d392  81faf0000000           +cmp edx, 0xf0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(240 /*0xf0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d398  7560                   -jne 0x49d3fa
    if (!cpu.flags.zf)
    {
        goto L_0x0049d3fa;
    }
    // 0049d39a  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d39d  755b                   -jne 0x49d3fa
    if (!cpu.flags.zf)
    {
        goto L_0x0049d3fa;
    }
    // 0049d39f  81fe00f00000           +cmp esi, 0xf000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61440 /*0xf000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d3a5  7553                   -jne 0x49d3fa
    if (!cpu.flags.zf)
    {
        goto L_0x0049d3fa;
    }
    // 0049d3a7  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0049d3ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d3b1:
    // 0049d3b1  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0049d3b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d3bb:
    // 0049d3bb  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049d3c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d3c5:
    // 0049d3c5  81f90000ff00           +cmp ecx, 0xff0000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d3cb  752d                   -jne 0x49d3fa
    if (!cpu.flags.zf)
    {
        goto L_0x0049d3fa;
    }
    // 0049d3cd  81fa00ff0000           +cmp edx, 0xff00
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65280 /*0xff00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d3d3  7525                   -jne 0x49d3fa
    if (!cpu.flags.zf)
    {
        goto L_0x0049d3fa;
    }
    // 0049d3d5  3dff000000             +cmp eax, 0xff
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
    // 0049d3da  751e                   -jne 0x49d3fa
    if (!cpu.flags.zf)
    {
        goto L_0x0049d3fa;
    }
    // 0049d3dc  83fb18                 +cmp ebx, 0x18
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d3df  740f                   -je 0x49d3f0
    if (cpu.flags.zf)
    {
        goto L_0x0049d3f0;
    }
    // 0049d3e1  83fb20                 +cmp ebx, 0x20
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
    // 0049d3e4  7514                   -jne 0x49d3fa
    if (!cpu.flags.zf)
    {
        goto L_0x0049d3fa;
    }
    // 0049d3e6  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0049d3eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3ef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d3f0:
    // 0049d3f0  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0049d3f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d3fa:
    // 0049d3fa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d3fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d400  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49d404(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d404);
    // 0049d404  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d405  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d406  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d407  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 0049d40d  8b942414020000         -mov edx, dword ptr [esp + 0x214]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0049d414  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049d416  752f                   -jne 0x49d447
    if (!cpu.flags.zf)
    {
        goto L_0x0049d447;
    }
    // 0049d418  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049d41a  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x0049d41d:
    // 0049d41d  e8be0a0000             -call 0x49dee0
    cpu.esp -= 4;
    sub_49dee0(app, cpu);
    if (cpu.terminate) return;
    // 0049d422  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d424  7448                   -je 0x49d46e
    if (cpu.flags.zf)
    {
        goto L_0x0049d46e;
    }
    // 0049d426  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d427  8bb42418020000         -mov esi, dword ptr [esp + 0x218]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0049d42e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d42f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d431  ff155cf05600           -call dword ptr [0x56f05c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697628) /* 0x56f05c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d437  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d43c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d43d  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 0049d443  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d444  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d445  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d446  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d447:
    // 0049d447  8d842418020000         -lea eax, [esp + 0x218]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0049d44e  8d9c2400020000         -lea ebx, [esp + 0x200]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 0049d455  89842400020000         -mov dword ptr [esp + 0x200], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 0049d45c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049d45e  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049d460  e88f270000             -call 0x49fbf4
    cpu.esp -= 4;
    sub_49fbf4(app, cpu);
    if (cpu.terminate) return;
    // 0049d465  898c2400020000         -mov dword ptr [esp + 0x200], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.ecx;
    // 0049d46c  ebaf                   -jmp 0x49d41d
    goto L_0x0049d41d;
L_0x0049d46e:
    // 0049d46e  8b9c2414020000         -mov ebx, dword ptr [esp + 0x214]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0049d475  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d476  2eff1528454c00         -call dword ptr cs:[0x4c4528]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998440) /* 0x4c4528 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d47d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d47f  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 0049d485  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d486  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d487  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d488  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49d48c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d48c);
    // 0049d48c  68a8ef4c00             -push 0x4cefa8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042088 /*0x4cefa8*/;
    cpu.esp -= 4;
    // 0049d491  2eff1518454c00         -call dword ptr cs:[0x4c4518]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998424) /* 0x4c4518 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d498  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d49a  7501                   -jne 0x49d49d
    if (!cpu.flags.zf)
    {
        goto L_0x0049d49d;
    }
    // 0049d49c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d49d:
    // 0049d49d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d49e  2eff1570444c00         -call dword ptr cs:[0x4c4470]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998256) /* 0x4c4470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d4a5  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 0049d4aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49d4ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d4ac);
    // 0049d4ac  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d4ad  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d4b0  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049d4b4  e883160000             -call 0x49eb3c
    cpu.esp -= 4;
    sub_49eb3c(app, cpu);
    if (cpu.terminate) return;
    // 0049d4b9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049d4bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d4be  0f847b000000           -je 0x49d53f
    if (cpu.flags.zf)
    {
        goto L_0x0049d53f;
    }
    // 0049d4c4  83780805               +cmp dword ptr [eax + 8], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d4c8  7561                   -jne 0x49d52b
    if (!cpu.flags.zf)
    {
        goto L_0x0049d52b;
    }
    // 0049d4ca  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x0049d4cf:
    // 0049d4cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d4d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d4d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d4d2  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049d4d5  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049d4d9  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049d4dc  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d4e0  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049d4e2  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049d4e4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d4e8  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049d4ec  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049d4ef  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049d4f1  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0049d4f4  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d4f6  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x0049d4fa:
    // 0049d4fa  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049d4fe  4f                     -dec edi
    (cpu.edi)--;
    // 0049d4ff  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 0049d503  83ffff                 +cmp edi, -1
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
    // 0049d506  742a                   -je 0x49d532
    if (cpu.flags.zf)
    {
        goto L_0x0049d532;
    }
    // 0049d508  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049d50a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049d50c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049d50e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d50f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d511  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049d514  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049d516  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049d518  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049d51b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049d51d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d51e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d522  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049d525  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049d527  01ca                   +add edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d529  ebcf                   -jmp 0x49d4fa
    goto L_0x0049d4fa;
L_0x0049d52b:
    // 0049d52b  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049d530  eb9d                   -jmp 0x49d4cf
    goto L_0x0049d4cf;
L_0x0049d532:
    // 0049d532  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d536  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d537  e8e0160000             -call 0x49ec1c
    cpu.esp -= 4;
    sub_49ec1c(app, cpu);
    if (cpu.terminate) return;
    // 0049d53c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d53d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d53e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049d53f:
    // 0049d53f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d542  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d543  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49d548(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d548);
    // 0049d548  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d549  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d54c  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049d550  e8e7150000             -call 0x49eb3c
    cpu.esp -= 4;
    sub_49eb3c(app, cpu);
    if (cpu.terminate) return;
    // 0049d555  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049d558  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d55a  0f847b000000           -je 0x49d5db
    if (cpu.flags.zf)
    {
        goto L_0x0049d5db;
    }
    // 0049d560  83780805               +cmp dword ptr [eax + 8], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d564  7561                   -jne 0x49d5c7
    if (!cpu.flags.zf)
    {
        goto L_0x0049d5c7;
    }
    // 0049d566  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x0049d56b:
    // 0049d56b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d56c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d56d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d56e  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049d571  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049d575  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049d578  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d57c  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049d57e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049d580  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d584  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049d588  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049d58b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049d58d  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0049d590  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d592  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x0049d596:
    // 0049d596  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049d59a  4f                     -dec edi
    (cpu.edi)--;
    // 0049d59b  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 0049d59f  83ffff                 +cmp edi, -1
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
    // 0049d5a2  742a                   -je 0x49d5ce
    if (cpu.flags.zf)
    {
        goto L_0x0049d5ce;
    }
    // 0049d5a4  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049d5a6  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049d5a8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049d5aa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d5ab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d5ad  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049d5b0  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049d5b2  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049d5b4  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049d5b7  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049d5b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d5ba  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d5be  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049d5c1  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049d5c3  01ca                   +add edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d5c5  ebcf                   -jmp 0x49d596
    goto L_0x0049d596;
L_0x0049d5c7:
    // 0049d5c7  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049d5cc  eb9d                   -jmp 0x49d56b
    goto L_0x0049d56b;
L_0x0049d5ce:
    // 0049d5ce  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d5d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d5d3  e844160000             -call 0x49ec1c
    cpu.esp -= 4;
    sub_49ec1c(app, cpu);
    if (cpu.terminate) return;
    // 0049d5d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d5d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d5da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049d5db:
    // 0049d5db  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d5de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d5df  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49d5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d5f0);
    // 0049d5f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d5f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d5f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d5f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d5f4  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0049d5f7  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049d5fb  8a634c                 -mov ah, byte ptr [ebx + 0x4c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(76) /* 0x4c */);
    // 0049d5fe  8b7354                 -mov esi, dword ptr [ebx + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 0049d601  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 0049d604  7428                   -je 0x49d62e
    if (cpu.flags.zf)
    {
        goto L_0x0049d62e;
    }
    // 0049d606  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049d60b:
    // 0049d60b  8b7c2440               -mov edi, dword ptr [esp + 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049d60f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d611  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d613  740a                   -je 0x49d61f
    if (cpu.flags.zf)
    {
        goto L_0x0049d61f;
    }
    // 0049d615  83fe10                 +cmp esi, 0x10
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
    // 0049d618  7418                   -je 0x49d632
    if (cpu.flags.zf)
    {
        goto L_0x0049d632;
    }
    // 0049d61a  83fe20                 +cmp esi, 0x20
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
    // 0049d61d  7413                   -je 0x49d632
    if (cpu.flags.zf)
    {
        goto L_0x0049d632;
    }
L_0x0049d61f:
    // 0049d61f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d624  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0049d627  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d628  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d629  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d62a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d62b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049d62e:
    // 0049d62e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049d630  ebd9                   -jmp 0x49d60b
    goto L_0x0049d60b;
L_0x0049d632:
    // 0049d632  8d4348                 -lea eax, [ebx + 0x48]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 0049d635  e806fdffff             -call 0x49d340
    cpu.esp -= 4;
    sub_49d340(app, cpu);
    if (cpu.terminate) return;
    // 0049d63a  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049d63e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d640  74dd                   -je 0x49d61f
    if (cpu.flags.zf)
    {
        goto L_0x0049d61f;
    }
    // 0049d642  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0049d645  0faf6b08               -imul ebp, dword ptr [ebx + 8]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */))));
    // 0049d649  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0049d64c  a1f0b74d00             -mov eax, dword ptr [0x4db7f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093360) /* 0x4db7f0 */);
    // 0049d651  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d653  c1ed03                 -shr ebp, 3
    cpu.ebp >>= 3 /*0x3*/ % 32;
    // 0049d656  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049d658  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049d65a  83f802                 +cmp eax, 2
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
    // 0049d65d  7cc0                   -jl 0x49d61f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d61f;
    }
    // 0049d65f  817b0c80020000         +cmp dword ptr [ebx + 0xc], 0x280
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(640 /*0x280*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d666  754f                   -jne 0x49d6b7
    if (!cpu.flags.zf)
    {
        goto L_0x0049d6b7;
    }
    // 0049d668  817b08e0010000         +cmp dword ptr [ebx + 8], 0x1e0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(480 /*0x1e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d66f  7546                   -jne 0x49d6b7
    if (!cpu.flags.zf)
    {
        goto L_0x0049d6b7;
    }
    // 0049d671  83fe10                 +cmp esi, 0x10
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
    // 0049d674  7541                   -jne 0x49d6b7
    if (!cpu.flags.zf)
    {
        goto L_0x0049d6b7;
    }
    // 0049d676  8b0d70ef5600           -mov ecx, dword ptr [0x56ef70]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5697392) /* 0x56ef70 */);
    // 0049d67c  83c118                 -add ecx, 0x18
    (cpu.ecx) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_0x0049d67f:
    // 0049d67f  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0049d682  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0049d684  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049d687  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049d68b  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049d68e  83fa03                 +cmp edx, 3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d691  7505                   -jne 0x49d698
    if (!cpu.flags.zf)
    {
        goto L_0x0049d698;
    }
    // 0049d693  be0f000000             -mov esi, 0xf
    cpu.esi = 15 /*0xf*/;
L_0x0049d698:
    // 0049d698  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0049d69b  896910                 -mov dword ptr [ecx + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0049d69e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049d6a2  896914                 -mov dword ptr [ecx + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0049d6a5  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049d6a8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d6ad  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0049d6b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6b4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049d6b7:
    // 0049d6b7  817b0c20030000         +cmp dword ptr [ebx + 0xc], 0x320
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(800 /*0x320*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d6be  7519                   -jne 0x49d6d9
    if (!cpu.flags.zf)
    {
        goto L_0x0049d6d9;
    }
    // 0049d6c0  817b0858020000         +cmp dword ptr [ebx + 8], 0x258
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(600 /*0x258*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d6c7  7510                   -jne 0x49d6d9
    if (!cpu.flags.zf)
    {
        goto L_0x0049d6d9;
    }
    // 0049d6c9  83fe10                 +cmp esi, 0x10
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
    // 0049d6cc  750b                   -jne 0x49d6d9
    if (!cpu.flags.zf)
    {
        goto L_0x0049d6d9;
    }
    // 0049d6ce  8b0d70ef5600           -mov ecx, dword ptr [0x56ef70]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5697392) /* 0x56ef70 */);
    // 0049d6d4  83c130                 +add ecx, 0x30
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d6d7  eba6                   -jmp 0x49d67f
    goto L_0x0049d67f;
L_0x0049d6d9:
    // 0049d6d9  837c242400             +cmp dword ptr [esp + 0x24], 0
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
    // 0049d6de  749f                   -je 0x49d67f
    if (cpu.flags.zf)
    {
        goto L_0x0049d67f;
    }
    // 0049d6e0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049d6e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d6e3  2eff15f0444c00         -call dword ptr cs:[0x4c44f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998384) /* 0x4c44f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d6ea  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 0049d6ef  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049d6f3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d6f5  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049d6f7  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049d6f9  39d0                   +cmp eax, edx
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
    // 0049d6fb  761d                   -jbe 0x49d71a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049d71a;
    }
    // 0049d6fd  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 0049d704  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d706  a170ef5600             -mov eax, dword ptr [0x56ef70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697392) /* 0x56ef70 */);
    // 0049d70b  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0049d70e  01c1                   +add ecx, eax
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
    // 0049d710  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049d713  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0049d715  e965ffffff             -jmp 0x49d67f
    goto L_0x0049d67f;
L_0x0049d71a:
    // 0049d71a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d71c  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0049d71f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d720  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d721  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d722  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d723  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49d728(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d728);
    // 0049d728  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d729  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d72a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d72b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d72c  81ecdc020000           -sub esp, 0x2dc
    (cpu.esp) -= x86::reg32(x86::sreg32(732 /*0x2dc*/));
    // 0049d732  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d734  8d8424dc020000         -lea eax, [esp + 0x2dc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(732) /* 0x2dc */);
    // 0049d73b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d73c  8b15f8b74d00           -mov edx, dword ptr [0x4db7f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093368) /* 0x4db7f8 */);
    // 0049d742  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d743  e8a85b0200             -call 0x4c32f0
    cpu.esp -= 4;
    sub_4c32f0(app, cpu);
    if (cpu.terminate) return;
    // 0049d748  a39cb74d00             -mov dword ptr [0x4db79c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = cpu.eax;
    // 0049d74d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d74f  742e                   -je 0x49d77f
    if (cpu.flags.zf)
    {
        goto L_0x0049d77f;
    }
L_0x0049d751:
    // 0049d751  8b3decb74d00           -mov edi, dword ptr [0x4db7ec]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5093356) /* 0x4db7ec */);
    // 0049d757  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d758  2eff155c454c00         -call dword ptr cs:[0x4c455c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998492) /* 0x4c455c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d75f  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0049d766  a19cb74d00             -mov eax, dword ptr [0x4db79c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */);
    // 0049d76b  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0049d76d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d772  81c4dc020000           -add esp, 0x2dc
    (cpu.esp) += x86::reg32(x86::sreg32(732 /*0x2dc*/));
    // 0049d778  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d779  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d77a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d77b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d77c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0049d77f:
    // 0049d77f  68c0b74d00             -push 0x4db7c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5093312 /*0x4db7c0*/;
    cpu.esp -= 4;
    // 0049d784  8b8424dc020000         -mov eax, dword ptr [esp + 0x2dc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(732) /* 0x2dc */);
    // 0049d78b  6828064e00             -push 0x4e0628
    app->getMemory<x86::reg32>(cpu.esp-4) = 5113384 /*0x4e0628*/;
    cpu.esp -= 4;
    // 0049d790  8b8c24e0020000         -mov ecx, dword ptr [esp + 0x2e0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(736) /* 0x2e0 */);
    // 0049d797  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d799  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d79a  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d79c  8b9c24d8020000         -mov ebx, dword ptr [esp + 0x2d8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 0049d7a3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d7a4  a39cb74d00             -mov dword ptr [0x4db79c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = cpu.eax;
    // 0049d7a9  ff1554f05600           -call dword ptr [0x56f054]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697620) /* 0x56f054 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d7af  8bb424d8020000         -mov esi, dword ptr [esp + 0x2d8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 0049d7b6  8b8424d8020000         -mov eax, dword ptr [esp + 0x2d8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 0049d7bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d7be  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d7c0  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d7c3  833d9cb74d0000         +cmp dword ptr [0x4db79c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d7ca  7585                   -jne 0x49d751
    if (!cpu.flags.zf)
    {
        goto L_0x0049d751;
    }
    // 0049d7cc  8b2da0b74d00           -mov ebp, dword ptr [0x4db7a0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5093280) /* 0x4db7a0 */);
    // 0049d7d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d7d3  8b0d98b74d00           -mov ecx, dword ptr [0x4db798]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093272) /* 0x4db798 */);
    // 0049d7d9  a1c0b74d00             -mov eax, dword ptr [0x4db7c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093312) /* 0x4db7c0 */);
    // 0049d7de  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d7df  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d7e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d7e2  ff5250                 -call dword ptr [edx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d7e5  a39cb74d00             -mov dword ptr [0x4db79c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = cpu.eax;
    // 0049d7ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d7ec  0f855fffffff           -jne 0x49d751
    if (!cpu.flags.zf)
    {
        goto L_0x0049d751;
    }
    // 0049d7f2  bb6c010000             -mov ebx, 0x16c
    cpu.ebx = 364 /*0x16c*/;
    // 0049d7f7  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049d7f9  a1c0b74d00             -mov eax, dword ptr [0x4db7c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093312) /* 0x4db7c0 */);
    // 0049d7fe  899c246c010000         -mov dword ptr [esp + 0x16c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.ebx;
    // 0049d805  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d806  8d942470010000         -lea edx, [esp + 0x170]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 0049d80d  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049d811  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d812  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d814  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d815  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d818  e934ffffff             -jmp 0x49d751
    goto L_0x0049d751;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49d820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d820);
    // 0049d820  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d821  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d822  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d823  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d824  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0049d827  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0049d82e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049d835  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d837  8b0d70ef5600           -mov ecx, dword ptr [0x56ef70]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5697392) /* 0x56ef70 */);
    // 0049d83d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049d840  8bb42494000000         -mov esi, dword ptr [esp + 0x94]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 0049d847  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049d849  4e                     -dec esi
    (cpu.esi)--;
    // 0049d84a  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049d84d  e8a2020000             -call 0x49daf4
    cpu.esp -= 4;
    sub_49daf4(app, cpu);
    if (cpu.terminate) return;
    // 0049d852  83fa0f                 +cmp edx, 0xf
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d855  7505                   -jne 0x49d85c
    if (!cpu.flags.zf)
    {
        goto L_0x0049d85c;
    }
    // 0049d857  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
L_0x0049d85c:
    // 0049d85c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d85e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d860  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d861  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049d864  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d865  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049d867  a1c0b74d00             -mov eax, dword ptr [0x4db7c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093312) /* 0x4db7c0 */);
    // 0049d86c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d86d  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d86f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d870  ff5354                 -call dword ptr [ebx + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d873  a39cb74d00             -mov dword ptr [0x4db79c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = cpu.eax;
    // 0049d878  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d87a  742b                   -je 0x49d8a7
    if (cpu.flags.zf)
    {
        goto L_0x0049d8a7;
    }
L_0x0049d87c:
    // 0049d87c  8b15ecb74d00           -mov edx, dword ptr [0x4db7ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093356) /* 0x4db7ec */);
    // 0049d882  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d883  2eff155c454c00         -call dword ptr cs:[0x4c455c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998492) /* 0x4c455c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d88a  8b942498000000         -mov edx, dword ptr [esp + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0049d891  a19cb74d00             -mov eax, dword ptr [0x4db79c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */);
    // 0049d896  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0049d898  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d89d  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0049d8a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d8a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d8a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d8a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d8a4  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0049d8a7:
    // 0049d8a7  bb6c000000             -mov ebx, 0x6c
    cpu.ebx = 108 /*0x6c*/;
    // 0049d8ac  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049d8ae  bd6c000000             -mov ebp, 0x6c
    cpu.ebp = 108 /*0x6c*/;
    // 0049d8b3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d8b5  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0049d8b7  e8b3fcfeff             -call 0x48d56f
    cpu.esp -= 4;
    sub_48d56f(app, cpu);
    if (cpu.terminate) return;
    // 0049d8bc  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 0049d8c1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d8c3  ba18420000             -mov edx, 0x4218
    cpu.edx = 16920 /*0x4218*/;
    // 0049d8c8  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0049d8cc  68c4b74d00             -push 0x4db7c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5093316 /*0x4db7c4*/;
    cpu.esp -= 4;
    // 0049d8d1  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0049d8d5  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049d8d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d8da  a1c0b74d00             -mov eax, dword ptr [0x4db7c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093312) /* 0x4db7c0 */);
    // 0049d8df  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 0049d8e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d8e4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d8e6  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d8e9  a39cb74d00             -mov dword ptr [0x4db79c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = cpu.eax;
    // 0049d8ee  3d7c017688             +cmp eax, 0x8876017c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435004 /*0x8876017c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d8f3  7533                   -jne 0x49d928
    if (!cpu.flags.zf)
    {
        goto L_0x0049d928;
    }
L_0x0049d8f5:
    // 0049d8f5  837c241401             +cmp dword ptr [esp + 0x14], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d8fa  762c                   -jbe 0x49d928
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049d928;
    }
    // 0049d8fc  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049d900  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d902  49                     -dec ecx
    (cpu.ecx)--;
    // 0049d903  68c4b74d00             -push 0x4db7c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5093316 /*0x4db7c4*/;
    cpu.esp -= 4;
    // 0049d908  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049d90c  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049d910  a1c0b74d00             -mov eax, dword ptr [0x4db7c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093312) /* 0x4db7c0 */);
    // 0049d915  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d916  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d918  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d919  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d91c  a39cb74d00             -mov dword ptr [0x4db79c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = cpu.eax;
    // 0049d921  3d7c017688             +cmp eax, 0x8876017c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435004 /*0x8876017c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d926  74cd                   -je 0x49d8f5
    if (cpu.flags.zf)
    {
        goto L_0x0049d8f5;
    }
L_0x0049d928:
    // 0049d928  8b35c4b74d00           -mov esi, dword ptr [0x4db7c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5093316) /* 0x4db7c4 */);
    // 0049d92e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d930  740f                   -je 0x49d941
    if (cpu.flags.zf)
    {
        goto L_0x0049d941;
    }
    // 0049d932  68ccb74d00             -push 0x4db7cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5093324 /*0x4db7cc*/;
    cpu.esp -= 4;
    // 0049d937  6838064e00             -push 0x4e0638
    app->getMemory<x86::reg32>(cpu.esp-4) = 5113400 /*0x4e0638*/;
    cpu.esp -= 4;
    // 0049d93c  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049d93e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d93f  ff12                   -call dword ptr [edx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049d941:
    // 0049d941  8b3dccb74d00           -mov edi, dword ptr [0x4db7cc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5093324) /* 0x4db7cc */);
    // 0049d947  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d949  0f842dffffff           -je 0x49d87c
    if (cpu.flags.zf)
    {
        goto L_0x0049d87c;
    }
    // 0049d94f  833dd0b74d0000         +cmp dword ptr [0x4db7d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093328) /* 0x4db7d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d956  0f8520ffffff           -jne 0x49d87c
    if (!cpu.flags.zf)
    {
        goto L_0x0049d87c;
    }
    // 0049d95c  68d0b74d00             -push 0x4db7d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5093328 /*0x4db7d0*/;
    cpu.esp -= 4;
    // 0049d961  8d4c2470               -lea ecx, [esp + 0x70]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0049d965  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049d96a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d96b  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 0049d96f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d970  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049d972  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d975  a39cb74d00             -mov dword ptr [0x4db79c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = cpu.eax;
    // 0049d97a  e9fdfeffff             -jmp 0x49d87c
    goto L_0x0049d87c;
}

/* align: skip 0x90 */
void Application::sub_49d980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d980);
    // 0049d980  e86f010000             -call 0x49daf4
    cpu.esp -= 4;
    sub_49daf4(app, cpu);
    if (cpu.terminate) return;
    // 0049d985  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d987  ff1554f05600           -call dword ptr [0x56f054]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697620) /* 0x56f054 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d98d  a1c0b74d00             -mov eax, dword ptr [0x4db7c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093312) /* 0x4db7c0 */);
    // 0049d992  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d993  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d995  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d998  8b0decb74d00           -mov ecx, dword ptr [0x4db7ec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093356) /* 0x4db7ec */);
    // 0049d99e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d9a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d9a1  8915c0b74d00           -mov dword ptr [0x4db7c0], edx
    app->getMemory<x86::reg32>(x86::reg32(5093312) /* 0x4db7c0 */) = cpu.edx;
    // 0049d9a7  2eff155c454c00         -call dword ptr cs:[0x4c455c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998492) /* 0x4c455c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d9ae  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d9b3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49d9b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049d9b8);
    // 0049d9b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d9b9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d9ba  8b15ecb74d00           -mov edx, dword ptr [0x4db7ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093356) /* 0x4db7ec */);
    // 0049d9c0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049d9c2  7510                   -jne 0x49d9d4
    if (!cpu.flags.zf)
    {
        goto L_0x0049d9d4;
    }
    // 0049d9c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d9c5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d9c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d9c7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d9c8  2eff152c444c00         -call dword ptr cs:[0x4c442c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998188) /* 0x4c442c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d9cf  a3ecb74d00             -mov dword ptr [0x4db7ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5093356) /* 0x4db7ec */) = cpu.eax;
L_0x0049d9d4:
    // 0049d9d4  ff1548f05600           -call dword ptr [0x56f048]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697608) /* 0x56f048 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d9da  a398b74d00             -mov dword ptr [0x4db798], eax
    app->getMemory<x86::reg32>(x86::reg32(5093272) /* 0x4db798 */) = cpu.eax;
    // 0049d9df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d9e1  7512                   -jne 0x49d9f5
    if (!cpu.flags.zf)
    {
        goto L_0x0049d9f5;
    }
    // 0049d9e3  c7059cb74d0078050000   -mov dword ptr [0x4db79c], 0x578
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = 1400 /*0x578*/;
    // 0049d9ed  a19cb74d00             -mov eax, dword ptr [0x4db79c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */);
    // 0049d9f2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d9f5:
    // 0049d9f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d9f6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d9f7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d9f8  6828d74900             -push 0x49d728
    app->getMemory<x86::reg32>(cpu.esp-4) = 4839208 /*0x49d728*/;
    cpu.esp -= 4;
    // 0049d9fd  6864040000             -push 0x464
    app->getMemory<x86::reg32>(cpu.esp-4) = 1124 /*0x464*/;
    cpu.esp -= 4;
    // 0049da02  ff154cf05600           -call dword ptr [0x56f04c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697612) /* 0x56f04c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049da08  6880d94900             -push 0x49d980
    app->getMemory<x86::reg32>(cpu.esp-4) = 4839808 /*0x49d980*/;
    cpu.esp -= 4;
    // 0049da0d  6868040000             -push 0x468
    app->getMemory<x86::reg32>(cpu.esp-4) = 1128 /*0x468*/;
    cpu.esp -= 4;
    // 0049da12  ff154cf05600           -call dword ptr [0x56f04c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697612) /* 0x56f04c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049da18  6820d84900             -push 0x49d820
    app->getMemory<x86::reg32>(cpu.esp-4) = 4839456 /*0x49d820*/;
    cpu.esp -= 4;
    // 0049da1d  6865040000             -push 0x465
    app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 0049da22  ff154cf05600           -call dword ptr [0x56f04c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697612) /* 0x56f04c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049da28  8a25a0b74d00           -mov ah, byte ptr [0x4db7a0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5093280) /* 0x4db7a0 */);
    // 0049da2e  80e4e6                 -and ah, 0xe6
    cpu.ah &= x86::reg8(x86::sreg8(230 /*0xe6*/));
    // 0049da31  8b1d98b74d00           -mov ebx, dword ptr [0x4db798]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5093272) /* 0x4db798 */);
    // 0049da37  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0049da39  8825a0b74d00           -mov byte ptr [0x4db7a0], ah
    app->getMemory<x86::reg8>(x86::reg32(5093280) /* 0x4db7a0 */) = cpu.ah;
    // 0049da3f  80ca11                 -or dl, 0x11
    cpu.dl |= x86::reg8(x86::sreg8(17 /*0x11*/));
    // 0049da42  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049da43  8815a0b74d00           -mov byte ptr [0x4db7a0], dl
    app->getMemory<x86::reg8>(x86::reg32(5093280) /* 0x4db7a0 */) = cpu.dl;
    // 0049da49  2eff15fc434c00         -call dword ptr cs:[0x4c43fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998140) /* 0x4c43fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049da50  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049da52  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049da54  6864040000             -push 0x464
    app->getMemory<x86::reg32>(cpu.esp-4) = 1124 /*0x464*/;
    cpu.esp -= 4;
    // 0049da59  8b3598b74d00           -mov esi, dword ptr [0x4db798]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5093272) /* 0x4db798 */);
    // 0049da5f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049da60  2eff15dc434c00         -call dword ptr cs:[0x4c43dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998108) /* 0x4c43dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049da67  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0049da69  8b3decb74d00           -mov edi, dword ptr [0x4db7ec]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5093356) /* 0x4db7ec */);
    // 0049da6f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049da70  2eff15ac454c00         -call dword ptr cs:[0x4c45ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998572) /* 0x4c45ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049da77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049da78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049da79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049da7a  a19cb74d00             -mov eax, dword ptr [0x4db79c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */);
    // 0049da7f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049da80  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049da81  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49da84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049da84);
    // 0049da84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049da85  833dc0b74d0000         +cmp dword ptr [0x4db7c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093312) /* 0x4db7c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049da8c  7504                   -jne 0x49da92
    if (!cpu.flags.zf)
    {
        goto L_0x0049da92;
    }
    // 0049da8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049da90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049da91  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049da92:
    // 0049da92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049da93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049da94  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049da95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049da96  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049da97  8b0d98b74d00           -mov ecx, dword ptr [0x4db798]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093272) /* 0x4db798 */);
    // 0049da9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049da9e  2eff15fc434c00         -call dword ptr cs:[0x4c43fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998140) /* 0x4c43fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049daa5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049daa7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049daa9  6868040000             -push 0x468
    app->getMemory<x86::reg32>(cpu.esp-4) = 1128 /*0x468*/;
    cpu.esp -= 4;
    // 0049daae  8b1d98b74d00           -mov ebx, dword ptr [0x4db798]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5093272) /* 0x4db798 */);
    // 0049dab4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049dab5  2eff15dc434c00         -call dword ptr cs:[0x4c43dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998108) /* 0x4c43dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dabc  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0049dabe  8b35ecb74d00           -mov esi, dword ptr [0x4db7ec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5093356) /* 0x4db7ec */);
    // 0049dac4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049dac5  2eff15ac454c00         -call dword ptr cs:[0x4c45ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998572) /* 0x4c45ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dacc  8b3decb74d00           -mov edi, dword ptr [0x4db7ec]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5093356) /* 0x4db7ec */);
    // 0049dad2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049dad3  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049dad5  2eff1528444c00         -call dword ptr cs:[0x4c4428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998184) /* 0x4c4428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dadc  a19cb74d00             -mov eax, dword ptr [0x4db79c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */);
    // 0049dae1  892decb74d00           -mov dword ptr [0x4db7ec], ebp
    app->getMemory<x86::reg32>(x86::reg32(5093356) /* 0x4db7ec */) = cpu.ebp;
    // 0049dae7  892d98b74d00           -mov dword ptr [0x4db798], ebp
    app->getMemory<x86::reg32>(x86::reg32(5093272) /* 0x4db798 */) = cpu.ebp;
    // 0049daed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049daee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049daef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049daf0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049daf1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049daf2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049daf3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49daf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049daf4);
    // 0049daf4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049daf5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049daf6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049daf7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049daf8  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
L_0x0049dafd:
    // 0049dafd  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049db00  83fbfc                 +cmp ebx, -4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049db03  741a                   -je 0x49db1f
    if (cpu.flags.zf)
    {
        goto L_0x0049db1f;
    }
    // 0049db05  8b8bc8b74d00           -mov ecx, dword ptr [ebx + 0x4db7c8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5093320) /* 0x4db7c8 */);
    // 0049db0b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049db0d  74ee                   -je 0x49dafd
    if (cpu.flags.zf)
    {
        goto L_0x0049dafd;
    }
    // 0049db0f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049db10  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049db12  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0049db14  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db17  89b3c8b74d00           -mov dword ptr [ebx + 0x4db7c8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5093320) /* 0x4db7c8 */) = cpu.esi;
    // 0049db1d  ebde                   -jmp 0x49dafd
    goto L_0x0049dafd;
L_0x0049db1f:
    // 0049db1f  8b15c4b74d00           -mov edx, dword ptr [0x4db7c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093316) /* 0x4db7c4 */);
    // 0049db25  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049db27  7505                   -jne 0x49db2e
    if (!cpu.flags.zf)
    {
        goto L_0x0049db2e;
    }
    // 0049db29  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db2a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db2c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db2d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049db2e:
    // 0049db2e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049db30  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049db31  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049db33  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db37  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db38  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db39  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db3a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49db3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049db3c);
    // 0049db3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049db3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049db3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049db3f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049db40  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0049db43  8b1560f05600           -mov edx, dword ptr [0x56f060]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049db49  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049db4e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049db50  0f8591010000           -jne 0x49dce7
    if (!cpu.flags.zf)
    {
        goto L_0x0049dce7;
    }
    // 0049db56  68b0ef4c00             -push 0x4cefb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042096 /*0x4cefb0*/;
    cpu.esp -= 4;
    // 0049db5b  2eff1518454c00         -call dword ptr cs:[0x4c4518]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998424) /* 0x4c4518 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db62  a360f05600             -mov dword ptr [0x56f060], eax
    app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */) = cpu.eax;
    // 0049db67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049db69  0f8405020000           -je 0x49dd74
    if (cpu.flags.zf)
    {
        goto L_0x0049dd74;
    }
    // 0049db6f  68b8ef4c00             -push 0x4cefb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042104 /*0x4cefb8*/;
    cpu.esp -= 4;
    // 0049db74  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049db75  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db7c  68d0ef4c00             -push 0x4cefd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042128 /*0x4cefd0*/;
    cpu.esp -= 4;
    // 0049db81  8b0d60f05600           -mov ecx, dword ptr [0x56f060]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049db87  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049db88  a364f05600             -mov dword ptr [0x56f064], eax
    app->getMemory<x86::reg32>(x86::reg32(5697636) /* 0x56f064 */) = cpu.eax;
    // 0049db8d  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db94  68ecef4c00             -push 0x4cefec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042156 /*0x4cefec*/;
    cpu.esp -= 4;
    // 0049db99  8b1d60f05600           -mov ebx, dword ptr [0x56f060]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049db9f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049dba0  a368f05600             -mov dword ptr [0x56f068], eax
    app->getMemory<x86::reg32>(x86::reg32(5697640) /* 0x56f068 */) = cpu.eax;
    // 0049dba5  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dbac  6800f04c00             -push 0x4cf000
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042176 /*0x4cf000*/;
    cpu.esp -= 4;
    // 0049dbb1  8b3d60f05600           -mov edi, dword ptr [0x56f060]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049dbb7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049dbb8  a36cf05600             -mov dword ptr [0x56f06c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697644) /* 0x56f06c */) = cpu.eax;
    // 0049dbbd  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dbc4  681cf04c00             -push 0x4cf01c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042204 /*0x4cf01c*/;
    cpu.esp -= 4;
    // 0049dbc9  8b2d60f05600           -mov ebp, dword ptr [0x56f060]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049dbcf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049dbd0  a370f05600             -mov dword ptr [0x56f070], eax
    app->getMemory<x86::reg32>(x86::reg32(5697648) /* 0x56f070 */) = cpu.eax;
    // 0049dbd5  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dbdc  6830f04c00             -push 0x4cf030
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042224 /*0x4cf030*/;
    cpu.esp -= 4;
    // 0049dbe1  a374f05600             -mov dword ptr [0x56f074], eax
    app->getMemory<x86::reg32>(x86::reg32(5697652) /* 0x56f074 */) = cpu.eax;
    // 0049dbe6  a160f05600             -mov eax, dword ptr [0x56f060]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049dbeb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049dbec  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dbf3  6840f04c00             -push 0x4cf040
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042240 /*0x4cf040*/;
    cpu.esp -= 4;
    // 0049dbf8  8b1560f05600           -mov edx, dword ptr [0x56f060]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049dbfe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049dbff  a378f05600             -mov dword ptr [0x56f078], eax
    app->getMemory<x86::reg32>(x86::reg32(5697656) /* 0x56f078 */) = cpu.eax;
    // 0049dc04  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dc0b  6858f04c00             -push 0x4cf058
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042264 /*0x4cf058*/;
    cpu.esp -= 4;
    // 0049dc10  8b0d60f05600           -mov ecx, dword ptr [0x56f060]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049dc16  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049dc17  a37cf05600             -mov dword ptr [0x56f07c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697660) /* 0x56f07c */) = cpu.eax;
    // 0049dc1c  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dc23  686cf04c00             -push 0x4cf06c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042284 /*0x4cf06c*/;
    cpu.esp -= 4;
    // 0049dc28  8b1d60f05600           -mov ebx, dword ptr [0x56f060]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049dc2e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049dc2f  a380f05600             -mov dword ptr [0x56f080], eax
    app->getMemory<x86::reg32>(x86::reg32(5697664) /* 0x56f080 */) = cpu.eax;
    // 0049dc34  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dc3b  6880f04c00             -push 0x4cf080
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042304 /*0x4cf080*/;
    cpu.esp -= 4;
    // 0049dc40  8b3d60f05600           -mov edi, dword ptr [0x56f060]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049dc46  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049dc47  a384f05600             -mov dword ptr [0x56f084], eax
    app->getMemory<x86::reg32>(x86::reg32(5697668) /* 0x56f084 */) = cpu.eax;
    // 0049dc4c  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dc53  6890f04c00             -push 0x4cf090
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042320 /*0x4cf090*/;
    cpu.esp -= 4;
    // 0049dc58  8b2d60f05600           -mov ebp, dword ptr [0x56f060]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049dc5e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049dc5f  a388f05600             -mov dword ptr [0x56f088], eax
    app->getMemory<x86::reg32>(x86::reg32(5697672) /* 0x56f088 */) = cpu.eax;
    // 0049dc64  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dc6b  68a8f04c00             -push 0x4cf0a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042344 /*0x4cf0a8*/;
    cpu.esp -= 4;
    // 0049dc70  a38cf05600             -mov dword ptr [0x56f08c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */) = cpu.eax;
    // 0049dc75  a160f05600             -mov eax, dword ptr [0x56f060]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049dc7a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049dc7b  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dc82  68bcf04c00             -push 0x4cf0bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042364 /*0x4cf0bc*/;
    cpu.esp -= 4;
    // 0049dc87  8b1560f05600           -mov edx, dword ptr [0x56f060]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049dc8d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049dc8e  a390f05600             -mov dword ptr [0x56f090], eax
    app->getMemory<x86::reg32>(x86::reg32(5697680) /* 0x56f090 */) = cpu.eax;
    // 0049dc93  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dc9a  a394f05600             -mov dword ptr [0x56f094], eax
    app->getMemory<x86::reg32>(x86::reg32(5697684) /* 0x56f094 */) = cpu.eax;
    // 0049dc9f  68ccf04c00             -push 0x4cf0cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042380 /*0x4cf0cc*/;
    cpu.esp -= 4;
    // 0049dca4  8b0d60f05600           -mov ecx, dword ptr [0x56f060]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049dcaa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049dcab  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dcb2  68dcf04c00             -push 0x4cf0dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042396 /*0x4cf0dc*/;
    cpu.esp -= 4;
    // 0049dcb7  8b1d60f05600           -mov ebx, dword ptr [0x56f060]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049dcbd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049dcbe  a398f05600             -mov dword ptr [0x56f098], eax
    app->getMemory<x86::reg32>(x86::reg32(5697688) /* 0x56f098 */) = cpu.eax;
    // 0049dcc3  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dcca  68ecf04c00             -push 0x4cf0ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042412 /*0x4cf0ec*/;
    cpu.esp -= 4;
    // 0049dccf  8b3d60f05600           -mov edi, dword ptr [0x56f060]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049dcd5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049dcd6  a39cf05600             -mov dword ptr [0x56f09c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697692) /* 0x56f09c */) = cpu.eax;
    // 0049dcdb  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dce2  a3a0f05600             -mov dword ptr [0x56f0a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5697696) /* 0x56f0a0 */) = cpu.eax;
L_0x0049dce7:
    // 0049dce7  bb90000000             -mov ebx, 0x90
    cpu.ebx = 144 /*0x90*/;
    // 0049dcec  b8b0ef5600             -mov eax, 0x56efb0
    cpu.eax = 5697456 /*0x56efb0*/;
    // 0049dcf1  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0049dcf6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049dcf8  b90000803f             -mov ecx, 0x3f800000
    cpu.ecx = 1065353216 /*0x3f800000*/;
    // 0049dcfd  e86df8feff             -call 0x48d56f
    cpu.esp -= 4;
    sub_48d56f(app, cpu);
    if (cpu.terminate) return;
    // 0049dd02  ba11000800             -mov edx, 0x80011
    cpu.edx = 524305 /*0x80011*/;
    // 0049dd07  892dd4ef5600           -mov dword ptr [0x56efd4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5697492) /* 0x56efd4 */) = cpu.ebp;
    // 0049dd0d  890db4ef5600           -mov dword ptr [0x56efb4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5697460) /* 0x56efb4 */) = cpu.ecx;
    // 0049dd13  890db8ef5600           -mov dword ptr [0x56efb8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5697464) /* 0x56efb8 */) = cpu.ecx;
    // 0049dd19  890dbcef5600           -mov dword ptr [0x56efbc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5697468) /* 0x56efbc */) = cpu.ecx;
    // 0049dd1f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049dd21  8b0d70ef5600           -mov ecx, dword ptr [0x56ef70]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5697392) /* 0x56ef70 */);
    // 0049dd27  a3c4ef5600             -mov dword ptr [0x56efc4], eax
    app->getMemory<x86::reg32>(x86::reg32(5697476) /* 0x56efc4 */) = cpu.eax;
    // 0049dd2c  8915c8ef5600           -mov dword ptr [0x56efc8], edx
    app->getMemory<x86::reg32>(x86::reg32(5697480) /* 0x56efc8 */) = cpu.edx;
    // 0049dd32  a3d8ef5600             -mov dword ptr [0x56efd8], eax
    app->getMemory<x86::reg32>(x86::reg32(5697496) /* 0x56efd8 */) = cpu.eax;
    // 0049dd37  a3dcef5600             -mov dword ptr [0x56efdc], eax
    app->getMemory<x86::reg32>(x86::reg32(5697500) /* 0x56efdc */) = cpu.eax;
    // 0049dd3c  a3e0ef5600             -mov dword ptr [0x56efe0], eax
    app->getMemory<x86::reg32>(x86::reg32(5697504) /* 0x56efe0 */) = cpu.eax;
    // 0049dd41  a3e4ef5600             -mov dword ptr [0x56efe4], eax
    app->getMemory<x86::reg32>(x86::reg32(5697508) /* 0x56efe4 */) = cpu.eax;
    // 0049dd46  a318f05600             -mov dword ptr [0x56f018], eax
    app->getMemory<x86::reg32>(x86::reg32(5697560) /* 0x56f018 */) = cpu.eax;
    // 0049dd4b  a3ecef5600             -mov dword ptr [0x56efec], eax
    app->getMemory<x86::reg32>(x86::reg32(5697516) /* 0x56efec */) = cpu.eax;
    // 0049dd50  a3f0ef5600             -mov dword ptr [0x56eff0], eax
    app->getMemory<x86::reg32>(x86::reg32(5697520) /* 0x56eff0 */) = cpu.eax;
    // 0049dd55  a3f4ef5600             -mov dword ptr [0x56eff4], eax
    app->getMemory<x86::reg32>(x86::reg32(5697524) /* 0x56eff4 */) = cpu.eax;
    // 0049dd5a  a31cf05600             -mov dword ptr [0x56f01c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697564) /* 0x56f01c */) = cpu.eax;
    // 0049dd5f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049dd61  7504                   -jne 0x49dd67
    if (!cpu.flags.zf)
    {
        goto L_0x0049dd67;
    }
    // 0049dd63  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049dd65  7514                   -jne 0x49dd7b
    if (!cpu.flags.zf)
    {
        goto L_0x0049dd7b;
    }
L_0x0049dd67:
    // 0049dd67  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049dd6c  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0049dd6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd72  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd73  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dd74:
    // 0049dd74  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0049dd76  e96cffffff             -jmp 0x49dce7
    goto L_0x0049dce7;
L_0x0049dd7b:
    // 0049dd7b  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049dd7f  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0049dd83  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049dd87  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049dd89  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049dd8a  2eff15f0444c00         -call dword ptr cs:[0x4c44f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998384) /* 0x4c44f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dd91  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0049dd93  6800300000             -push 0x3000
    app->getMemory<x86::reg32>(cpu.esp-4) = 12288 /*0x3000*/;
    cpu.esp -= 4;
    // 0049dd98  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049dd9c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049dd9d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049dd9f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049dda0  2eff1598454c00         -call dword ptr cs:[0x4c4598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998552) /* 0x4c4598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dda7  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049ddab  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ddad  a370ef5600             -mov dword ptr [0x56ef70], eax
    app->getMemory<x86::reg32>(x86::reg32(5697392) /* 0x56ef70 */) = cpu.eax;
    // 0049ddb2  e8b8f7feff             -call 0x48d56f
    cpu.esp -= 4;
    sub_48d56f(app, cpu);
    if (cpu.terminate) return;
    // 0049ddb7  a170ef5600             -mov eax, dword ptr [0x56ef70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697392) /* 0x56ef70 */);
    // 0049ddbc  c7401880020000         -mov dword ptr [eax + 0x18], 0x280
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 640 /*0x280*/;
    // 0049ddc3  c7401ce0010000         -mov dword ptr [eax + 0x1c], 0x1e0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 480 /*0x1e0*/;
    // 0049ddca  c7402010000000         -mov dword ptr [eax + 0x20], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 16 /*0x10*/;
    // 0049ddd1  c7402404000000         -mov dword ptr [eax + 0x24], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 4 /*0x4*/;
    // 0049ddd8  c7402801000000         -mov dword ptr [eax + 0x28], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 1 /*0x1*/;
    // 0049dddf  c7402c01000000         -mov dword ptr [eax + 0x2c], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 1 /*0x1*/;
    // 0049dde6  c7403020030000         -mov dword ptr [eax + 0x30], 0x320
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 800 /*0x320*/;
    // 0049dded  c7403458020000         -mov dword ptr [eax + 0x34], 0x258
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 600 /*0x258*/;
    // 0049ddf4  c7403810000000         -mov dword ptr [eax + 0x38], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 16 /*0x10*/;
    // 0049ddfb  c7403c04000000         -mov dword ptr [eax + 0x3c], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = 4 /*0x4*/;
    // 0049de02  c7404001000000         -mov dword ptr [eax + 0x40], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 1 /*0x1*/;
    // 0049de09  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049de0b  c7404401000000         -mov dword ptr [eax + 0x44], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = 1 /*0x1*/;
    // 0049de12  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0049de17  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049de18  a36cef5600             -mov dword ptr [0x56ef6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697388) /* 0x56ef6c */) = cpu.eax;
    // 0049de1d  8d44242c               -lea eax, [esp + 0x2c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049de21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049de22  8b15f8b74d00           -mov edx, dword ptr [0x4db7f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093368) /* 0x4db7f8 */);
    // 0049de28  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049de29  e8c2540200             -call 0x4c32f0
    cpu.esp -= 4;
    sub_4c32f0(app, cpu);
    if (cpu.terminate) return;
    // 0049de2e  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049de32  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049de34  0f847f000000           -je 0x49deb9
    if (cpu.flags.zf)
    {
        goto L_0x0049deb9;
    }
    // 0049de3a  8d44242c               -lea eax, [esp + 0x2c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049de3e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049de3f  6828064e00             -push 0x4e0628
    app->getMemory<x86::reg32>(cpu.esp-4) = 5113384 /*0x4e0628*/;
    cpu.esp -= 4;
    // 0049de44  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049de46  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049de47  ff16                   -call dword ptr [esi]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049de49  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049de4d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049de4f  745a                   -je 0x49deab
    if (cpu.flags.zf)
    {
        goto L_0x0049deab;
    }
    // 0049de51  68f0b74d00             -push 0x4db7f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5093360 /*0x4db7f0*/;
    cpu.esp -= 4;
    // 0049de56  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049de5a  bf00400000             -mov edi, 0x4000
    cpu.edi = 16384 /*0x4000*/;
    // 0049de5f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049de60  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049de64  897c2438               -mov dword ptr [esp + 0x38], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edi;
    // 0049de68  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049de69  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049de6d  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0049de6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049de70  ff565c                 -call dword ptr [esi + 0x5c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049de73  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049de75  740a                   -je 0x49de81
    if (cpu.flags.zf)
    {
        goto L_0x0049de81;
    }
    // 0049de77  c705f0b74d0000002000   -mov dword ptr [0x4db7f0], 0x200000
    app->getMemory<x86::reg32>(x86::reg32(5093360) /* 0x4db7f0 */) = 2097152 /*0x200000*/;
L_0x0049de81:
    // 0049de81  68f0d54900             -push 0x49d5f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4838896 /*0x49d5f0*/;
    cpu.esp -= 4;
    // 0049de86  686cef5600             -push 0x56ef6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697388 /*0x56ef6c*/;
    cpu.esp -= 4;
    // 0049de8b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049de8d  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049de91  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049de93  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049de97  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049de99  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049de9a  ff5020                 -call dword ptr [eax + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049de9d  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049dea1  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049dea5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049dea6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049dea8  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049deab:
    // 0049deab  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049deaf  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049deb3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049deb4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049deb6  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049deb9:
    // 0049deb9  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049debd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049debe  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0049dec0  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049dec4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049dec5  8b3d70ef5600           -mov edi, dword ptr [0x56ef70]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5697392) /* 0x56ef70 */);
    // 0049decb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049decc  2eff15a0454c00         -call dword ptr cs:[0x4c45a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998560) /* 0x4c45a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ded3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049ded8  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0049dedb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dedc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dedd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dede  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dedf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49dee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049dee0);
    // 0049dee0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049dee1  833dc4b74d0000         +cmp dword ptr [0x4db7c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093316) /* 0x4db7c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dee8  7547                   -jne 0x49df31
    if (!cpu.flags.zf)
    {
        goto L_0x0049df31;
    }
L_0x0049deea:
    // 0049deea  8b0df4b74d00           -mov ecx, dword ptr [0x4db7f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093364) /* 0x4db7f4 */);
    // 0049def0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049def2  7414                   -je 0x49df08
    if (cpu.flags.zf)
    {
        goto L_0x0049df08;
    }
    // 0049def4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049def5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049def6  ff156cf05600           -call dword ptr [0x56f06c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697644) /* 0x56f06c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049defc  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049defe  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049df01  8935f4b74d00           -mov dword ptr [0x4db7f4], esi
    app->getMemory<x86::reg32>(x86::reg32(5093364) /* 0x4db7f4 */) = cpu.esi;
    // 0049df07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049df08:
    // 0049df08  8b3d60f05600           -mov edi, dword ptr [0x56f060]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */);
    // 0049df0e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049df10  740f                   -je 0x49df21
    if (cpu.flags.zf)
    {
        goto L_0x0049df21;
    }
    // 0049df12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049df13  2eff1570444c00         -call dword ptr cs:[0x4c4470]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998256) /* 0x4c4470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049df1a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049df1c  a360f05600             -mov dword ptr [0x56f060], eax
    app->getMemory<x86::reg32>(x86::reg32(5697632) /* 0x56f060 */) = cpu.eax;
L_0x0049df21:
    // 0049df21  e85efbffff             -call 0x49da84
    cpu.esp -= 4;
    sub_49da84(app, cpu);
    if (cpu.terminate) return;
    // 0049df26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049df28  7515                   -jne 0x49df3f
    if (!cpu.flags.zf)
    {
        goto L_0x0049df3f;
    }
    // 0049df2a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049df2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049df30  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049df31:
    // 0049df31  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049df33  e8700a0000             -call 0x49e9a8
    cpu.esp -= 4;
    sub_49e9a8(app, cpu);
    if (cpu.terminate) return;
    // 0049df38  e8e3090000             -call 0x49e920
    cpu.esp -= 4;
    sub_49e920(app, cpu);
    if (cpu.terminate) return;
    // 0049df3d  ebab                   -jmp 0x49deea
    goto L_0x0049deea;
L_0x0049df3f:
    // 0049df3f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049df41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049df42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49df44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049df44);
    // 0049df44  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049df49  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_49df4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049df4c);
    // 0049df4c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049df4d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049df4e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049df4f  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0049df52  8b74247c               -mov esi, dword ptr [esp + 0x7c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0049df56  833dc0b74d0000         +cmp dword ptr [0x4db7c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093312) /* 0x4db7c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049df5d  0f840f010000           -je 0x49e072
    if (cpu.flags.zf)
    {
        goto L_0x0049e072;
    }
    // 0049df63  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049df65  e83e0a0000             -call 0x49e9a8
    cpu.esp -= 4;
    sub_49e9a8(app, cpu);
    if (cpu.terminate) return;
    // 0049df6a  8b0df4b74d00           -mov ecx, dword ptr [0x4db7f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093364) /* 0x4db7f4 */);
    // 0049df70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049df71  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049df73  ff156cf05600           -call dword ptr [0x56f06c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697644) /* 0x56f06c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049df79  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049df7c  893df4b74d00           -mov dword ptr [0x4db7f4], edi
    app->getMemory<x86::reg32>(x86::reg32(5093364) /* 0x4db7f4 */) = cpu.edi;
L_0x0049df82:
    // 0049df82  833dc0b74d0000         +cmp dword ptr [0x4db7c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093312) /* 0x4db7c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049df89  0f840f010000           -je 0x49e09e
    if (cpu.flags.zf)
    {
        goto L_0x0049e09e;
    }
    // 0049df8f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049df91  7505                   -jne 0x49df98
    if (!cpu.flags.zf)
    {
        goto L_0x0049df98;
    }
    // 0049df93  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x0049df98:
    // 0049df98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049df99  a198b74d00             -mov eax, dword ptr [0x4db798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093272) /* 0x4db798 */);
    // 0049df9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049df9f  2eff15fc434c00         -call dword ptr cs:[0x4c43fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998140) /* 0x4c43fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dfa6  8b942484000000         -mov edx, dword ptr [esp + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0049dfad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049dfae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049dfaf  6865040000             -push 0x465
    app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 0049dfb4  8b0d98b74d00           -mov ecx, dword ptr [0x4db798]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093272) /* 0x4db798 */);
    // 0049dfba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049dfbb  2eff15dc434c00         -call dword ptr cs:[0x4c43dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998108) /* 0x4c43dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dfc2  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0049dfc4  8b35ecb74d00           -mov esi, dword ptr [0x4db7ec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5093356) /* 0x4db7ec */);
    // 0049dfca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049dfcb  2eff15ac454c00         -call dword ptr cs:[0x4c45ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998572) /* 0x4c45ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dfd2  833d9cb74d0000         +cmp dword ptr [0x4db79c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dfd9  0f857b000000           -jne 0x49e05a
    if (!cpu.flags.zf)
    {
        goto L_0x0049e05a;
    }
    // 0049dfdf  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049dfe3  bd6c000000             -mov ebp, 0x6c
    cpu.ebp = 108 /*0x6c*/;
    // 0049dfe8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049dfe9  a1ccb74d00             -mov eax, dword ptr [0x4db7cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093324) /* 0x4db7cc */);
    // 0049dfee  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0049dff2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049dff3  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049dff5  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dff8  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0049dffc  83f810                 +cmp eax, 0x10
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
    // 0049dfff  0f8377000000           -jae 0x49e07c
    if (!cpu.flags.cf)
    {
        goto L_0x0049e07c;
    }
L_0x0049e005:
    // 0049e005  8b742458               -mov esi, dword ptr [esp + 0x58]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0049e009  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e00a  68fcf04c00             -push 0x4cf0fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042428 /*0x4cf0fc*/;
    cpu.esp -= 4;
    // 0049e00f  e8f0f3ffff             -call 0x49d404
    cpu.esp -= 4;
    sub_49d404(app, cpu);
    if (cpu.terminate) return;
    // 0049e014  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0049e017:
    // 0049e017  6840f05600             -push 0x56f040
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697600 /*0x56f040*/;
    cpu.esp -= 4;
    // 0049e01c  68b0e64900             -push 0x49e6b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4843184 /*0x49e6b0*/;
    cpu.esp -= 4;
    // 0049e021  ff1564f05600           -call dword ptr [0x56f064]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697636) /* 0x56f064 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e027  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e02a  a39cb74d00             -mov dword ptr [0x4db79c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = cpu.eax;
    // 0049e02f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e031  7527                   -jne 0x49e05a
    if (!cpu.flags.zf)
    {
        goto L_0x0049e05a;
    }
    // 0049e033  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049e035  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e036  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049e03a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e03b  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049e03f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e040  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e041  ff1568f05600           -call dword ptr [0x56f068]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697640) /* 0x56f068 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e047  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049e04a  a3f4b74d00             -mov dword ptr [0x4db7f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5093364) /* 0x4db7f4 */) = cpu.eax;
    // 0049e04f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e051  7c02                   -jl 0x49e055
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e055;
    }
    // 0049e053  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049e055:
    // 0049e055  a39cb74d00             -mov dword ptr [0x4db79c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = cpu.eax;
L_0x0049e05a:
    // 0049e05a  833d9cb74d0000         +cmp dword ptr [0x4db79c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e061  752f                   -jne 0x49e092
    if (!cpu.flags.zf)
    {
        goto L_0x0049e092;
    }
    // 0049e063  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e068  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e069  83c46c                 +add esp, 0x6c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e06c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e06d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e06e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e06f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049e072:
    // 0049e072  e841f9ffff             -call 0x49d9b8
    cpu.esp -= 4;
    sub_49d9b8(app, cpu);
    if (cpu.terminate) return;
    // 0049e077  e906ffffff             -jmp 0x49df82
    goto L_0x0049df82;
L_0x0049e07c:
    // 0049e07c  7704                   -ja 0x49e082
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049e082;
    }
    // 0049e07e  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0049e080  eb95                   -jmp 0x49e017
    goto L_0x0049e017;
L_0x0049e082:
    // 0049e082  83f820                 +cmp eax, 0x20
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
    // 0049e085  0f857affffff           -jne 0x49e005
    if (!cpu.flags.zf)
    {
        goto L_0x0049e005;
    }
    // 0049e08b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049e090  eb85                   -jmp 0x49e017
    goto L_0x0049e017;
L_0x0049e092:
    // 0049e092  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e094  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e095  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0049e098  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e099  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e09a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e09b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049e09e:
    // 0049e09e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e0a0  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0049e0a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0a6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49e0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e0b0);
    // 0049e0b0  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049e0b4  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049e0b8  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049e0bc  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049e0c0  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049e0c4  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049e0c8  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049e0cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e0cd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e0ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e0cf  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049e0d2  8b35fcb74d00           -mov esi, dword ptr [0x4db7fc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5093372) /* 0x4db7fc */);
    // 0049e0d8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049e0da  741e                   -je 0x49e0fa
    if (cpu.flags.zf)
    {
        goto L_0x0049e0fa;
    }
L_0x0049e0dc:
    // 0049e0dc  8b1d00b84d00           -mov ebx, dword ptr [0x4db800]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5093376) /* 0x4db800 */);
    // 0049e0e2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e0e4  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0049e0e6  a300b84d00             -mov dword ptr [0x4db800], eax
    app->getMemory<x86::reg32>(x86::reg32(5093376) /* 0x4db800 */) = cpu.eax;
    // 0049e0eb  8935fcb74d00           -mov dword ptr [0x4db7fc], esi
    app->getMemory<x86::reg32>(x86::reg32(5093372) /* 0x4db7fc */) = cpu.esi;
    // 0049e0f1  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0049e0f3  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049e0f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e0fa:
    // 0049e0fa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e0fb  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e0ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e100  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 0049e105  2eff15f0444c00         -call dword ptr cs:[0x4c44f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998384) /* 0x4c44f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e10c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e110  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e112  f7f3                   +div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049e114  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0049e116  6800300000             -push 0x3000
    app->getMemory<x86::reg32>(cpu.esp-4) = 12288 /*0x3000*/;
    cpu.esp -= 4;
    // 0049e11b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e11f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e120  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e121  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e123  2eff1598454c00         -call dword ptr cs:[0x4c4598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998552) /* 0x4c4598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e12a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049e12c  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0049e132  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049e133:
    // 0049e133  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049e134  74a6                   -je 0x49e0dc
    if (cpu.flags.zf)
    {
        goto L_0x0049e0dc;
    }
    // 0049e136  83c60c                 +add esi, 0xc
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e139  8d56f4                 -lea edx, [esi - 0xc]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-12) /* -0xc */);
    // 0049e13c  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0049e13e  ebf3                   -jmp 0x49e133
    goto L_0x0049e133;
}

/* align: skip  */
void Application::sub_49e0cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e0cc);
    goto L_entry_0x0049e0cc;
    // 0049e0b0  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0b2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049e0b4  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0b6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049e0b8  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0ba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049e0bc  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0be  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049e0c0  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0c2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049e0c4  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0c6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049e0c8  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049e0ca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x0049e0cc:
    // 0049e0cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e0cd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e0ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e0cf  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049e0d2  8b35fcb74d00           -mov esi, dword ptr [0x4db7fc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5093372) /* 0x4db7fc */);
    // 0049e0d8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049e0da  741e                   -je 0x49e0fa
    if (cpu.flags.zf)
    {
        goto L_0x0049e0fa;
    }
L_0x0049e0dc:
    // 0049e0dc  8b1d00b84d00           -mov ebx, dword ptr [0x4db800]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5093376) /* 0x4db800 */);
    // 0049e0e2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e0e4  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0049e0e6  a300b84d00             -mov dword ptr [0x4db800], eax
    app->getMemory<x86::reg32>(x86::reg32(5093376) /* 0x4db800 */) = cpu.eax;
    // 0049e0eb  8935fcb74d00           -mov dword ptr [0x4db7fc], esi
    app->getMemory<x86::reg32>(x86::reg32(5093372) /* 0x4db7fc */) = cpu.esi;
    // 0049e0f1  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0049e0f3  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049e0f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e0fa:
    // 0049e0fa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e0fb  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e0ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e100  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 0049e105  2eff15f0444c00         -call dword ptr cs:[0x4c44f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998384) /* 0x4c44f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e10c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e110  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e112  f7f3                   +div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049e114  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0049e116  6800300000             -push 0x3000
    app->getMemory<x86::reg32>(cpu.esp-4) = 12288 /*0x3000*/;
    cpu.esp -= 4;
    // 0049e11b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e11f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e120  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e121  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e123  2eff1598454c00         -call dword ptr cs:[0x4c4598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998552) /* 0x4c4598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e12a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049e12c  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0049e132  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049e133:
    // 0049e133  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049e134  74a6                   -je 0x49e0dc
    if (cpu.flags.zf)
    {
        goto L_0x0049e0dc;
    }
    // 0049e136  83c60c                 +add esi, 0xc
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e139  8d56f4                 -lea edx, [esi - 0xc]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-12) /* -0xc */);
    // 0049e13c  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0049e13e  ebf3                   -jmp 0x49e133
    goto L_0x0049e133;
}

/* align: skip  */
void Application::sub_49e140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e140);
    // 0049e140  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e141  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e142  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e143  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e144  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049e147  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e149  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049e14b  0fafdb                 -imul ebx, ebx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049e14e  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x0049e152:
    // 0049e152  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049e156  4a                     -dec edx
    (cpu.edx)--;
    // 0049e157  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049e15b  83faff                 +cmp edx, -1
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
    // 0049e15e  746d                   -je 0x49e1cd
    if (cpu.flags.zf)
    {
        goto L_0x0049e1cd;
    }
    // 0049e160  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0049e162  beb0e04900             -mov esi, 0x49e0b0
    cpu.esi = 4841648 /*0x49e0b0*/;
    // 0049e167  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e169  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e16a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e16b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e16c  be1f000000             -mov esi, 0x1f
    cpu.esi = 31 /*0x1f*/;
L_0x0049e171:
    // 0049e171  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 0049e174  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0049e175  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e177  c1fb0a                 -sar ebx, 0xa
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (10 /*0xa*/ % 32));
    // 0049e17a  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e17d  21f3                   -and ebx, esi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e17f  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e182  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e184  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e186  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0049e189  c1fb05                 -sar ebx, 5
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (5 /*0x5*/ % 32));
    // 0049e18c  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e190  21f3                   -and ebx, esi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e192  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e194  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e196  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e19a  42                     -inc edx
    (cpu.edx)++;
    // 0049e19b  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e19d  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0049e1a1  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049e1a5  83fa04                 +cmp edx, 4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e1a8  7cc7                   -jl 0x49e171
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e171;
    }
    // 0049e1aa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e1ac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049e1ae:
    // 0049e1ae  8b1c04                 -mov ebx, dword ptr [esp + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 1);
    // 0049e1b1  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0049e1b4  c1fb02                 -sar ebx, 2
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (2 /*0x2*/ % 32));
    // 0049e1b7  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049e1ba  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e1bd  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e1bf  83f80c                 +cmp eax, 0xc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e1c2  75ea                   -jne 0x49e1ae
    if (!cpu.flags.zf)
    {
        goto L_0x0049e1ae;
    }
    // 0049e1c4  83c502                 +add ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e1c7  668955fe               -mov word ptr [ebp - 2], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */) = cpu.dx;
    // 0049e1cb  eb85                   -jmp 0x49e152
    goto L_0x0049e152;
L_0x0049e1cd:
    // 0049e1cd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049e1d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e1d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49e1d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e1d8);
    // 0049e1d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e1d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e1da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e1db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e1dc  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049e1df  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e1e1  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049e1e3  0fafdb                 -imul ebx, ebx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049e1e6  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
L_0x0049e1ea:
    // 0049e1ea  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e1ee  4a                     -dec edx
    (cpu.edx)--;
    // 0049e1ef  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0049e1f3  83faff                 +cmp edx, -1
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
    // 0049e1f6  0f8482000000           -je 0x49e27e
    if (cpu.flags.zf)
    {
        goto L_0x0049e27e;
    }
    // 0049e1fc  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0049e1fe  bebce04900             -mov esi, 0x49e0bc
    cpu.esi = 4841660 /*0x49e0bc*/;
    // 0049e203  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e205  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e206  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e207  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e208  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e209  be0f000000             -mov esi, 0xf
    cpu.esi = 15 /*0xf*/;
L_0x0049e20e:
    // 0049e20e  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 0049e211  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0049e212  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e214  c1fb0c                 -sar ebx, 0xc
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (12 /*0xc*/ % 32));
    // 0049e217  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e21a  21f3                   -and ebx, esi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e21c  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e21e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e220  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0049e223  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 0049e226  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e22a  21f3                   -and ebx, esi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e22c  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e22f  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e231  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e233  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0049e237  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 0049e23a  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e23e  21f3                   -and ebx, esi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e240  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e242  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e244  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049e248  42                     -inc edx
    (cpu.edx)++;
    // 0049e249  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e24b  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0049e24f  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049e253  83fa04                 +cmp edx, 4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e256  7cb6                   -jl 0x49e20e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e20e;
    }
    // 0049e258  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e25a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049e25c:
    // 0049e25c  8b1c04                 -mov ebx, dword ptr [esp + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 1);
    // 0049e25f  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0049e262  c1fb02                 -sar ebx, 2
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (2 /*0x2*/ % 32));
    // 0049e265  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0049e268  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e26b  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e26d  83f810                 +cmp eax, 0x10
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
    // 0049e270  75ea                   -jne 0x49e25c
    if (!cpu.flags.zf)
    {
        goto L_0x0049e25c;
    }
    // 0049e272  83c502                 +add ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e275  668955fe               -mov word ptr [ebp - 2], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */) = cpu.dx;
    // 0049e279  e96cffffff             -jmp 0x49e1ea
    goto L_0x0049e1ea;
L_0x0049e27e:
    // 0049e27e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049e281  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e282  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e283  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e284  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e285  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49e288(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e288);
    // 0049e288  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e289  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e28a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e28b  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049e28e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049e292  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049e296  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049e29a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e29f  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0049e2a1  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049e2a3  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049e2a7  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049e2ab  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e2ad  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049e2af  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049e2b2  bdaaaa0000             -mov ebp, 0xaaaa
    cpu.ebp = 43690 /*0xaaaa*/;
L_0x0049e2b7:
    // 0049e2b7  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e2bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e2bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e2bf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049e2c1  7e2e                   -jle 0x49e2f1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e2f1;
    }
    // 0049e2c3  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x0049e2c7:
    // 0049e2c7  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049e2cb  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx);
    // 0049e2ce  31f3                   -xor ebx, esi
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e2d0  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0049e2d2  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e2d4  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049e2d6  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e2d9  0374240c               -add esi, dword ptr [esp + 0xc]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0049e2dd  40                     -inc eax
    (cpu.eax)++;
    // 0049e2de  81c257550000           -add edx, 0x5557
    (cpu.edx) += x86::reg32(x86::sreg32(21847 /*0x5557*/));
    // 0049e2e4  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
    // 0049e2e7  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e2eb  21ea                   -and edx, ebp
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049e2ed  39d8                   +cmp eax, ebx
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
    // 0049e2ef  7cd6                   -jl 0x49e2c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049e2c7;
    }
L_0x0049e2f1:
    // 0049e2f1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e2f4  81c7abaa0000           -add edi, 0xaaab
    (cpu.edi) += x86::reg32(x86::sreg32(43691 /*0xaaab*/));
    // 0049e2fa  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e2fe  81e755550000           -and edi, 0x5555
    cpu.edi &= x86::reg32(x86::sreg32(21845 /*0x5555*/));
    // 0049e304  01c6                   +add esi, eax
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
    // 0049e306  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e30a  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0049e30e  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049e30f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049e313  75a2                   -jne 0x49e2b7
    if (!cpu.flags.zf)
    {
        goto L_0x0049e2b7;
    }
    // 0049e315  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e317  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049e31a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e31b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e31c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e31d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49e320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e320);
    // 0049e320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e322  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e323  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0049e325  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049e32a  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0049e32c  0fafd2                 -imul edx, edx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edx)));
L_0x0049e32f:
    // 0049e32f  4a                     -dec edx
    (cpu.edx)--;
    // 0049e330  83faff                 +cmp edx, -1
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
    // 0049e333  7425                   -je 0x49e35a
    if (cpu.flags.zf)
    {
        goto L_0x0049e35a;
    }
    // 0049e335  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 0049e338  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049e33a  80e1c0                 -and cl, 0xc0
    cpu.cl &= x86::reg8(x86::sreg8(192 /*0xc0*/));
    // 0049e33d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049e33f  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0049e341  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049e347  80e31f                 -and bl, 0x1f
    cpu.bl &= x86::reg8(x86::sreg8(31 /*0x1f*/));
    // 0049e34a  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 0049e34c  0fbfcb                 -movsx ecx, bx
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0049e34f  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e352  09f1                   +or ecx, esi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi))));
    // 0049e354  668948fe               -mov word ptr [eax - 2], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-2) /* -0x2 */) = cpu.cx;
    // 0049e358  ebd5                   -jmp 0x49e32f
    goto L_0x0049e32f;
L_0x0049e35a:
    // 0049e35a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e35b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e35c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e35d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49e374(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e374);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0049e374  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e375  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e376  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049e379  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049e37d  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049e381  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e383  39d0                   +cmp eax, edx
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
    // 0049e385  0f85a0000000           -jne 0x49e42b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e42b;
    }
    // 0049e38b  83fa40                 +cmp edx, 0x40
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
    // 0049e38e  0f83a1000000           -jae 0x49e435
    if (!cpu.flags.cf)
    {
        goto L_0x0049e435;
    }
    // 0049e394  83fa20                 +cmp edx, 0x20
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e397  0f858e000000           -jne 0x49e42b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e42b;
    }
    // 0049e39d  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
L_0x0049e3a1:
    // 0049e3a1  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049e3a5  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049e3a8  83f804                 +cmp eax, 4
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
    // 0049e3ab  0f877a000000           -ja 0x49e42b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049e42b;
    }
    // 0049e3b1  ff248560e34900         -jmp dword ptr [eax*4 + 0x49e360]
    cpu.ip = app->getMemory<x86::reg32>(4842336 + cpu.eax * 4); goto dynamic_jump;
  case 0x0049e3b8:
    // 0049e3b8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0049e3ba:
    // 0049e3ba  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 0049e3bf  7401                   -je 0x49e3c2
    if (cpu.flags.zf)
    {
        goto L_0x0049e3c2;
    }
    // 0049e3c1  43                     -inc ebx
    (cpu.ebx)++;
L_0x0049e3c2:
    // 0049e3c2  c6042450               -mov byte ptr [esp], 0x50
    app->getMemory<x86::reg8>(cpu.esp) = 80 /*0x50*/;
    // 0049e3c6  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e3ca  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049e3cc  88442407               -mov byte ptr [esp + 7], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0049e3d0  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e3d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e3d5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049e3d7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049e3d9  b254                   -mov dl, 0x54
    cpu.dl = 84 /*0x54*/;
    // 0049e3db  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049e3dd  88542415               -mov byte ptr [esp + 0x15], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) = cpu.dl;
    // 0049e3e1  bab0f05600             -mov edx, 0x56f0b0
    cpu.edx = 5697712 /*0x56f0b0*/;
    // 0049e3e6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049e3e8  885c241a               -mov byte ptr [esp + 0x1a], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(26) /* 0x1a */) = cpu.bl;
    // 0049e3ec  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0049e3f0  ff1574f05600           -call dword ptr [0x56f074]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697652) /* 0x56f074 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e3f6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e3f8  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049e3fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e3fd  7422                   -je 0x49e421
    if (cpu.flags.zf)
    {
        goto L_0x0049e421;
    }
    // 0049e3ff  e8c8fcffff             -call 0x49e0cc
    cpu.esp -= 4;
    sub_49e0cc(app, cpu);
    if (cpu.terminate) return;
    // 0049e404  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049e407  885808                 -mov byte ptr [eax + 8], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.bl;
    // 0049e40a  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e40e  885009                 -mov byte ptr [eax + 9], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */) = cpu.dl;
    // 0049e411  8a542428               -mov dl, byte ptr [esp + 0x28]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049e415  88500a                 -mov byte ptr [eax + 0xa], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */) = cpu.dl;
    // 0049e418  8a542430               -mov dl, byte ptr [esp + 0x30]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049e41c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049e41e  88500b                 -mov byte ptr [eax + 0xb], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */) = cpu.dl;
L_0x0049e421:
    // 0049e421  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e423  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049e426  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e427  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e428  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x0049e42b:
    // 0049e42b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e42d  83c414                 +add esp, 0x14
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
    // 0049e430  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e431  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e432  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x0049e435:
    // 0049e435  770d                   -ja 0x49e444
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049e444;
    }
    // 0049e437  c744241001000000       -mov dword ptr [esp + 0x10], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 0049e43f  e95dffffff             -jmp 0x49e3a1
    goto L_0x0049e3a1;
L_0x0049e444:
    // 0049e444  81fa80000000           +cmp edx, 0x80
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e44a  72df                   -jb 0x49e42b
    if (cpu.flags.cf)
    {
        goto L_0x0049e42b;
    }
    // 0049e44c  770d                   -ja 0x49e45b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049e45b;
    }
    // 0049e44e  c744241002000000       -mov dword ptr [esp + 0x10], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 2 /*0x2*/;
    // 0049e456  e946ffffff             -jmp 0x49e3a1
    goto L_0x0049e3a1;
L_0x0049e45b:
    // 0049e45b  81fa00010000           +cmp edx, 0x100
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e461  75c8                   -jne 0x49e42b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e42b;
    }
    // 0049e463  c744241003000000       -mov dword ptr [esp + 0x10], 3
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 3 /*0x3*/;
    // 0049e46b  e931ffffff             -jmp 0x49e3a1
    goto L_0x0049e3a1;
  case 0x0049e470:
    // 0049e470  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0049e475  e940ffffff             -jmp 0x49e3ba
    goto L_0x0049e3ba;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49e490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e490);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0049e490  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e491  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e492  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e493  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e494  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049e496  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049e499  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0049e49c  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0049e49f  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0049e4a2  8a400a                 -mov al, byte ptr [eax + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0049e4a5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e4a7  2c03                   -sub al, 3
    (cpu.al) -= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 0049e4a9  668955fc               -mov word ptr [ebp - 4], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.dx;
    // 0049e4ad  3c04                   +cmp al, 4
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
    // 0049e4af  0f87a7010000           -ja 0x49e65c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049e65c;
    }
    // 0049e4b5  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0049e4ba  ff24857ce44900         -jmp dword ptr [eax*4 + 0x49e47c]
    cpu.ip = app->getMemory<x86::reg32>(4842620 + cpu.eax * 4); goto dynamic_jump;
  case 0x0049e4c1:
    // 0049e4c1  66c745fc00f0           -mov word ptr [ebp - 4], 0xf000
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 61440 /*0xf000*/;
  [[fallthrough]];
  case 0x0049e4c7:
    // 0049e4c7  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049e4ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e4cc  8a4209                 -mov al, byte ptr [edx + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
    // 0049e4cf  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e4d1  83c005                 -add eax, 5
    (cpu.eax) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0049e4d4  8a7a0b                 -mov bh, byte ptr [edx + 0xb]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11) /* 0xb */);
    // 0049e4d7  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0049e4da  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 0049e4dc  7407                   -je 0x49e4e5
    if (cpu.flags.zf)
    {
        goto L_0x0049e4e5;
    }
    // 0049e4de  8b348504b84d00         -mov esi, dword ptr [eax*4 + 0x4db804]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5093380) /* 0x4db804 */ + cpu.eax * 4);
L_0x0049e4e5:
    // 0049e4e5  c645d050               -mov byte ptr [ebp - 0x30], 0x50
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = 80 /*0x50*/;
    // 0049e4e9  b554                   -mov ch, 0x54
    cpu.ch = 84 /*0x54*/;
    // 0049e4eb  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049e4ee  886dd1                 -mov byte ptr [ebp - 0x2f], ch
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-47) /* -0x2f */) = cpu.ch;
    // 0049e4f1  8a4008                 -mov al, byte ptr [eax + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049e4f4  bab0f05600             -mov edx, 0x56f0b0
    cpu.edx = 5697712 /*0x56f0b0*/;
    // 0049e4f9  8845d2                 -mov byte ptr [ebp - 0x2e], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-46) /* -0x2e */) = cpu.al;
    // 0049e4fc  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049e4ff  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0049e502  8b4dfa                 -mov ecx, dword ptr [ebp - 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0049e505  8a4009                 -mov al, byte ptr [eax + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 0049e508  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049e50b  8845d3                 -mov byte ptr [ebp - 0x2d], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-45) /* -0x2d */) = cpu.al;
    // 0049e50e  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0049e511  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 0049e514  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e516  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049e518  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 0049e51b  e868fdffff             -call 0x49e288
    cpu.esp -= 4;
    sub_49e288(app, cpu);
    if (cpu.terminate) return;
    // 0049e520  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049e522  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049e525  80780a04               +cmp byte ptr [eax + 0xa], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e529  750b                   -jne 0x49e536
    if (!cpu.flags.zf)
    {
        goto L_0x0049e536;
    }
    // 0049e52b  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0049e52e  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049e531  e8eafdffff             -call 0x49e320
    cpu.esp -= 4;
    sub_49e320(app, cpu);
    if (cpu.terminate) return;
L_0x0049e536:
    // 0049e536  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049e538  0f84ea000000           -je 0x49e628
    if (cpu.flags.zf)
    {
        goto L_0x0049e628;
    }
    // 0049e53e  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049e541  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e543  8a420b                 -mov al, byte ptr [edx + 0xb]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11) /* 0xb */);
    // 0049e546  48                     -dec eax
    (cpu.eax)--;
    // 0049e547  8a720a                 -mov dh, byte ptr [edx + 0xa]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0049e54a  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0049e54d  80fe07                 +cmp dh, 7
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e550  756f                   -jne 0x49e5c1
    if (!cpu.flags.zf)
    {
        goto L_0x0049e5c1;
    }
    // 0049e552  c745ecd8e14900         -mov dword ptr [ebp - 0x14], 0x49e1d8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 4841944 /*0x49e1d8*/;
L_0x0049e559:
    // 0049e559  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0049e55c  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049e55f  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
L_0x0049e562:
    // 0049e562  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049e565  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0049e568  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e56b  4a                     -dec edx
    (cpu.edx)--;
    // 0049e56c  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0049e56f  8955e0                 -mov dword ptr [ebp - 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edx;
    // 0049e572  83faff                 +cmp edx, -1
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
    // 0049e575  0f84ad000000           -je 0x49e628
    if (cpu.flags.zf)
    {
        goto L_0x0049e628;
    }
    // 0049e57b  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049e57e  8b8004b84d00           -mov eax, dword ptr [eax + 0x4db804]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5093380) /* 0x4db804 */);
    // 0049e584  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049e586  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0049e589  81c6b0f05600           -add esi, 0x56f0b0
    (cpu.esi) += x86::reg32(x86::sreg32(5697712 /*0x56f0b0*/));
    // 0049e58f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049e591  7e37                   -jle 0x49e5ca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e5ca;
    }
    // 0049e593  8b4dfa                 -mov ecx, dword ptr [ebp - 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0049e596  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049e598  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049e59a  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049e59d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049e59f  e8e4fcffff             -call 0x49e288
    cpu.esp -= 4;
    sub_49e288(app, cpu);
    if (cpu.terminate) return;
    // 0049e5a4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049e5a6  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049e5a9  80780a04               +cmp byte ptr [eax + 0xa], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e5ad  750a                   -jne 0x49e5b9
    if (!cpu.flags.zf)
    {
        goto L_0x0049e5b9;
    }
    // 0049e5af  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0049e5b2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e5b4  e867fdffff             -call 0x49e320
    cpu.esp -= 4;
    sub_49e320(app, cpu);
    if (cpu.terminate) return;
L_0x0049e5b9:
    // 0049e5b9  ff4df8                 +dec dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049e5bc  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049e5bf  eba1                   -jmp 0x49e562
    goto L_0x0049e562;
L_0x0049e5c1:
    // 0049e5c1  c745ec40e14900         -mov dword ptr [ebp - 0x14], 0x49e140
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 4841792 /*0x49e140*/;
    // 0049e5c8  eb8f                   -jmp 0x49e559
    goto L_0x0049e559;
L_0x0049e5ca:
    // 0049e5ca  8a4de0                 -mov cl, byte ptr [ebp - 0x20]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0049e5cd  8d1400                 -lea edx, [eax + eax]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 0049e5d0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049e5d5  81c2b0f05600           -add edx, 0x56f0b0
    (cpu.edx) += x86::reg32(x86::sreg32(5697712 /*0x56f0b0*/));
    // 0049e5db  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e5dd  d3e3                   +shl ebx, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049e5df  ff55ec                 -call dword ptr [ebp - 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e5e2  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049e5e5  e978ffffff             -jmp 0x49e562
    goto L_0x0049e562;
  case 0x0049e5ea:
    // 0049e5ea  b449                   -mov ah, 0x49
    cpu.ah = 73 /*0x49*/;
    // 0049e5ec  b24d                   -mov dl, 0x4d
    cpu.dl = 77 /*0x4d*/;
    // 0049e5ee  b350                   -mov bl, 0x50
    cpu.bl = 80 /*0x50*/;
    // 0049e5f0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e5f2  8865d0                 -mov byte ptr [ebp - 0x30], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.ah;
    // 0049e5f5  8855d1                 -mov byte ptr [ebp - 0x2f], dl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-47) /* -0x2f */) = cpu.dl;
    // 0049e5f8  b641                   -mov dh, 0x41
    cpu.dh = 65 /*0x41*/;
    // 0049e5fa  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049e5fd  885dd3                 -mov byte ptr [ebp - 0x2d], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-45) /* -0x2d */) = cpu.bl;
    // 0049e600  8875d2                 -mov byte ptr [ebp - 0x2e], dh
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-46) /* -0x2e */) = cpu.dh;
    // 0049e603  8a4809                 -mov cl, byte ptr [eax + 9]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 0049e606  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049e60b  83c105                 -add ecx, 5
    (cpu.ecx) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0049e60e  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0049e610  8955d4                 -mov dword ptr [ebp - 0x2c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.edx;
    // 0049e613  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e615  8a4809                 -mov cl, byte ptr [eax + 9]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 0049e618  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049e61d  83c105                 -add ecx, 5
    (cpu.ecx) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0049e620  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0049e622  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 0049e625  8955d8                 -mov dword ptr [ebp - 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.edx;
L_0x0049e628:
    // 0049e628  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049e62a  8d45d0                 -lea eax, [ebp - 0x30]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0049e62d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e62e  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049e631  8a780b                 -mov bh, byte ptr [eax + 0xb]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */);
    // 0049e634  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049e636  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 0049e638  7426                   -je 0x49e660
    if (cpu.flags.zf)
    {
        goto L_0x0049e660;
    }
    // 0049e63a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049e63f:
    // 0049e63f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e640  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049e643  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049e646  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e647  ff1578f05600           -call dword ptr [0x56f078]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697656) /* 0x56f078 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e64d  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0049e650  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0049e653:
    // 0049e653  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e655  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e656  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e657  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e658  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e659  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049e65c:
    // 0049e65c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049e65e  ebf3                   -jmp 0x49e653
    goto L_0x0049e653;
L_0x0049e660:
    // 0049e660  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049e662  ebdb                   -jmp 0x49e63f
    goto L_0x0049e63f;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_49e664(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e664);
    // 0049e664  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e665  8b1d00b84d00           -mov ebx, dword ptr [0x4db800]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5093376) /* 0x4db800 */);
    // 0049e66b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049e66d  7431                   -je 0x49e6a0
    if (cpu.flags.zf)
    {
        goto L_0x0049e6a0;
    }
L_0x0049e66f:
    // 0049e66f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e671  8b15fcb74d00           -mov edx, dword ptr [0x4db7fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093372) /* 0x4db7fc */);
    // 0049e677  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e679  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049e67b  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049e67e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e67f  a3fcb74d00             -mov dword ptr [0x4db7fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5093372) /* 0x4db7fc */) = cpu.eax;
    // 0049e684  891d00b84d00           -mov dword ptr [0x4db800], ebx
    app->getMemory<x86::reg32>(x86::reg32(5093376) /* 0x4db800 */) = cpu.ebx;
    // 0049e68a  ff1580f05600           -call dword ptr [0x56f080]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697664) /* 0x56f080 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e690  8b1d00b84d00           -mov ebx, dword ptr [0x4db800]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5093376) /* 0x4db800 */);
    // 0049e696  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e699  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049e69b  75d2                   -jne 0x49e66f
    if (!cpu.flags.zf)
    {
        goto L_0x0049e66f;
    }
    // 0049e69d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049e6a0:
    // 0049e6a0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e6a5  891d00b84d00           -mov dword ptr [0x4db800], ebx
    app->getMemory<x86::reg32>(x86::reg32(5093376) /* 0x4db800 */) = cpu.ebx;
    // 0049e6ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e6ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49e6b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e6b0);
    // 0049e6b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e6b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e6b2  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0049e6b5  8b5c2478               -mov ebx, dword ptr [esp + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0049e6b9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049e6bb  ff1558f05600           -call dword ptr [0x56f058]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697624) /* 0x56f058 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e6c1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049e6c3  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0049e6c8  6a21                   -push 0x21
    app->getMemory<x86::reg32>(cpu.esp-4) = 33 /*0x21*/;
    cpu.esp -= 4;
    // 0049e6ca  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049e6ce  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e6d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e6d3  a1e8b74d00             -mov eax, dword ptr [0x4db7e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093352) /* 0x4db7e8 */);
    // 0049e6d8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049e6da  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e6dc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e6dd  a328b84d00             -mov dword ptr [0x4db828], eax
    app->getMemory<x86::reg32>(x86::reg32(5093416) /* 0x4db828 */) = cpu.eax;
    // 0049e6e2  ff5164                 -call dword ptr [ecx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e6e5  a39cb74d00             -mov dword ptr [0x4db79c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = cpu.eax;
    // 0049e6ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e6ec  7549                   -jne 0x49e737
    if (!cpu.flags.zf)
    {
        goto L_0x0049e737;
    }
    // 0049e6ee  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049e6f2  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049e6f4  a38c9b5900             -mov dword ptr [0x599b8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5872524) /* 0x599b8c */) = cpu.eax;
    // 0049e6f9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e6fd  66894304               -mov word ptr [ebx + 4], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0049e701  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049e706  a3909b5900             -mov dword ptr [0x599b90], eax
    app->getMemory<x86::reg32>(x86::reg32(5872528) /* 0x599b90 */) = cpu.eax;
    // 0049e70b  8a442454               -mov al, byte ptr [esp + 0x54]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049e70f  884306                 -mov byte ptr [ebx + 6], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 0049e712  3c10                   +cmp al, 0x10
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
    // 0049e714  7534                   -jne 0x49e74a
    if (!cpu.flags.zf)
    {
        goto L_0x0049e74a;
    }
    // 0049e716  817c245ce0070000       +cmp dword ptr [esp + 0x5c], 0x7e0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2016 /*0x7e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e71e  741e                   -je 0x49e73e
    if (cpu.flags.zf)
    {
        goto L_0x0049e73e;
    }
    // 0049e720  bd03000000             -mov ebp, 3
    cpu.ebp = 3 /*0x3*/;
    // 0049e725  c643060f               -mov byte ptr [ebx + 6], 0xf
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 15 /*0xf*/;
    // 0049e729  892d949b5900           -mov dword ptr [0x599b94], ebp
    app->getMemory<x86::reg32>(x86::reg32(5872532) /* 0x599b94 */) = cpu.ebp;
L_0x0049e72f:
    // 0049e72f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049e731:
    // 0049e731  83c46c                 +add esp, 0x6c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e734  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e735  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e736  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e737:
    // 0049e737  b80dfcffff             -mov eax, 0xfffffc0d
    cpu.eax = 4294966285 /*0xfffffc0d*/;
    // 0049e73c  ebf3                   -jmp 0x49e731
    goto L_0x0049e731;
L_0x0049e73e:
    // 0049e73e  c705949b590004000000   -mov dword ptr [0x599b94], 4
    app->getMemory<x86::reg32>(x86::reg32(5872532) /* 0x599b94 */) = 4 /*0x4*/;
    // 0049e748  ebe5                   -jmp 0x49e72f
    goto L_0x0049e72f;
L_0x0049e74a:
    // 0049e74a  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e74c  75e1                   -jne 0x49e72f
    if (!cpu.flags.zf)
    {
        goto L_0x0049e72f;
    }
    // 0049e74e  c705949b590005000000   -mov dword ptr [0x599b94], 5
    app->getMemory<x86::reg32>(x86::reg32(5872532) /* 0x599b94 */) = 5 /*0x5*/;
    // 0049e758  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e75a  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0049e75d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e75e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e75f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e760);
    // 0049e760  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e761  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e762  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e763  e8b8010000             -call 0x49e920
    cpu.esp -= 4;
    sub_49e920(app, cpu);
    if (cpu.terminate) return;
    // 0049e768  833d849b590000         +cmp dword ptr [0x599b84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e76f  7404                   -je 0x49e775
    if (cpu.flags.zf)
    {
        goto L_0x0049e775;
    }
    // 0049e771  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e772  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e773  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e774  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e775:
    // 0049e775  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049e77a  ff1584f05600           -call dword ptr [0x56f084]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697668) /* 0x56f084 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e780  a1f8ef5600             -mov eax, dword ptr [0x56eff8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697528) /* 0x56eff8 */);
    // 0049e785  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049e78a  a3709b5900             -mov dword ptr [0x599b70], eax
    app->getMemory<x86::reg32>(x86::reg32(5872496) /* 0x599b70 */) = cpu.eax;
    // 0049e78f  a1fcef5600             -mov eax, dword ptr [0x56effc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697532) /* 0x56effc */);
    // 0049e794  8b1d30b84d00           -mov ebx, dword ptr [0x4db830]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5093424) /* 0x4db830 */);
    // 0049e79a  a3749b5900             -mov dword ptr [0x599b74], eax
    app->getMemory<x86::reg32>(x86::reg32(5872500) /* 0x599b74 */) = cpu.eax;
    // 0049e79f  a100f05600             -mov eax, dword ptr [0x56f000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697536) /* 0x56f000 */);
    // 0049e7a4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e7a7  a3789b5900             -mov dword ptr [0x599b78], eax
    app->getMemory<x86::reg32>(x86::reg32(5872504) /* 0x599b78 */) = cpu.eax;
    // 0049e7ac  a104f05600             -mov eax, dword ptr [0x56f004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697540) /* 0x56f004 */);
    // 0049e7b1  890d849b5900           -mov dword ptr [0x599b84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */) = cpu.ecx;
    // 0049e7b7  a37c9b5900             -mov dword ptr [0x599b7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5872508) /* 0x599b7c */) = cpu.eax;
    // 0049e7bc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049e7be  742c                   -je 0x49e7ec
    if (cpu.flags.zf)
    {
        goto L_0x0049e7ec;
    }
    // 0049e7c0  a1609b5900             -mov eax, dword ptr [0x599b60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872480) /* 0x599b60 */);
    // 0049e7c5  a3f8ef5600             -mov dword ptr [0x56eff8], eax
    app->getMemory<x86::reg32>(x86::reg32(5697528) /* 0x56eff8 */) = cpu.eax;
    // 0049e7ca  a1649b5900             -mov eax, dword ptr [0x599b64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872484) /* 0x599b64 */);
    // 0049e7cf  a3fcef5600             -mov dword ptr [0x56effc], eax
    app->getMemory<x86::reg32>(x86::reg32(5697532) /* 0x56effc */) = cpu.eax;
    // 0049e7d4  a1689b5900             -mov eax, dword ptr [0x599b68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872488) /* 0x599b68 */);
    // 0049e7d9  a300f05600             -mov dword ptr [0x56f000], eax
    app->getMemory<x86::reg32>(x86::reg32(5697536) /* 0x56f000 */) = cpu.eax;
    // 0049e7de  a16c9b5900             -mov eax, dword ptr [0x599b6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872492) /* 0x599b6c */);
    // 0049e7e3  a304f05600             -mov dword ptr [0x56f004], eax
    app->getMemory<x86::reg32>(x86::reg32(5697540) /* 0x56f004 */) = cpu.eax;
    // 0049e7e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e7ec:
    // 0049e7ec  a1f8ef5600             -mov eax, dword ptr [0x56eff8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697528) /* 0x56eff8 */);
    // 0049e7f1  a3609b5900             -mov dword ptr [0x599b60], eax
    app->getMemory<x86::reg32>(x86::reg32(5872480) /* 0x599b60 */) = cpu.eax;
    // 0049e7f6  a1fcef5600             -mov eax, dword ptr [0x56effc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697532) /* 0x56effc */);
    // 0049e7fb  a3649b5900             -mov dword ptr [0x599b64], eax
    app->getMemory<x86::reg32>(x86::reg32(5872484) /* 0x599b64 */) = cpu.eax;
    // 0049e800  a100f05600             -mov eax, dword ptr [0x56f000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697536) /* 0x56f000 */);
    // 0049e805  a3689b5900             -mov dword ptr [0x599b68], eax
    app->getMemory<x86::reg32>(x86::reg32(5872488) /* 0x599b68 */) = cpu.eax;
    // 0049e80a  a104f05600             -mov eax, dword ptr [0x56f004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697540) /* 0x56f004 */);
    // 0049e80f  a36c9b5900             -mov dword ptr [0x599b6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5872492) /* 0x599b6c */) = cpu.eax;
    // 0049e814  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e815  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e816  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e817  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e818(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e818);
    // 0049e818  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e81c  8b1495c8b74d00         -mov edx, dword ptr [edx*4 + 0x4db7c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093320) /* 0x4db7c8 */ + cpu.edx * 4);
    // 0049e823  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e825  740e                   -je 0x49e835
    if (cpu.flags.zf)
    {
        goto L_0x0049e835;
    }
    // 0049e827  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e82c  8915e8b74d00           -mov dword ptr [0x4db7e8], edx
    app->getMemory<x86::reg32>(x86::reg32(5093352) /* 0x4db7e8 */) = cpu.edx;
    // 0049e832  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049e835:
    // 0049e835  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e837  8915e8b74d00           -mov dword ptr [0x4db7e8], edx
    app->getMemory<x86::reg32>(x86::reg32(5093352) /* 0x4db7e8 */) = cpu.edx;
    // 0049e83d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_49e840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e840);
    // 0049e840  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e841  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e842  833de8b74d0000         +cmp dword ptr [0x4db7e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093352) /* 0x4db7e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e849  0f84a2000000           -je 0x49e8f1
    if (cpu.flags.zf)
    {
        goto L_0x0049e8f1;
    }
L_0x0049e84f:
    // 0049e84f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049e851  e852010000             -call 0x49e9a8
    cpu.esp -= 4;
    sub_49e9a8(app, cpu);
    if (cpu.terminate) return;
    // 0049e856  833d2cb84d0000         +cmp dword ptr [0x4db82c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093420) /* 0x4db82c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e85d  740d                   -je 0x49e86c
    if (cpu.flags.zf)
    {
        goto L_0x0049e86c;
    }
    // 0049e85f  6878f14c00             -push 0x4cf178
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042552 /*0x4cf178*/;
    cpu.esp -= 4;
    // 0049e864  e89bebffff             -call 0x49d404
    cpu.esp -= 4;
    sub_49d404(app, cpu);
    if (cpu.terminate) return;
    // 0049e869  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049e86c:
    // 0049e86c  833d28b84d0000         +cmp dword ptr [0x4db828], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093416) /* 0x4db828 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e873  740d                   -je 0x49e882
    if (cpu.flags.zf)
    {
        goto L_0x0049e882;
    }
    // 0049e875  68c4f14c00             -push 0x4cf1c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042628 /*0x4cf1c4*/;
    cpu.esp -= 4;
    // 0049e87a  e885ebffff             -call 0x49d404
    cpu.esp -= 4;
    sub_49d404(app, cpu);
    if (cpu.terminate) return;
    // 0049e87f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049e882:
    // 0049e882  833d849b590000         +cmp dword ptr [0x599b84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e889  7478                   -je 0x49e903
    if (cpu.flags.zf)
    {
        goto L_0x0049e903;
    }
    // 0049e88b  a1709b5900             -mov eax, dword ptr [0x599b70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872496) /* 0x599b70 */);
    // 0049e890  a3f8ef5600             -mov dword ptr [0x56eff8], eax
    app->getMemory<x86::reg32>(x86::reg32(5697528) /* 0x56eff8 */) = cpu.eax;
    // 0049e895  a3609b5900             -mov dword ptr [0x599b60], eax
    app->getMemory<x86::reg32>(x86::reg32(5872480) /* 0x599b60 */) = cpu.eax;
    // 0049e89a  a1749b5900             -mov eax, dword ptr [0x599b74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872500) /* 0x599b74 */);
    // 0049e89f  a3fcef5600             -mov dword ptr [0x56effc], eax
    app->getMemory<x86::reg32>(x86::reg32(5697532) /* 0x56effc */) = cpu.eax;
    // 0049e8a4  a3649b5900             -mov dword ptr [0x599b64], eax
    app->getMemory<x86::reg32>(x86::reg32(5872484) /* 0x599b64 */) = cpu.eax;
    // 0049e8a9  a1789b5900             -mov eax, dword ptr [0x599b78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872504) /* 0x599b78 */);
    // 0049e8ae  a300f05600             -mov dword ptr [0x56f000], eax
    app->getMemory<x86::reg32>(x86::reg32(5697536) /* 0x56f000 */) = cpu.eax;
    // 0049e8b3  a3689b5900             -mov dword ptr [0x599b68], eax
    app->getMemory<x86::reg32>(x86::reg32(5872488) /* 0x599b68 */) = cpu.eax;
    // 0049e8b8  a17c9b5900             -mov eax, dword ptr [0x599b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872508) /* 0x599b7c */);
    // 0049e8bd  a304f05600             -mov dword ptr [0x56f004], eax
    app->getMemory<x86::reg32>(x86::reg32(5697540) /* 0x56f004 */) = cpu.eax;
    // 0049e8c2  a36c9b5900             -mov dword ptr [0x599b6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5872492) /* 0x599b6c */) = cpu.eax;
L_0x0049e8c7:
    // 0049e8c7  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049e8cc  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0049e8d1  ff1588f05600           -call dword ptr [0x56f088]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697672) /* 0x56f088 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e8d7  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049e8d9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e8dc  893d809b5900           -mov dword ptr [0x599b80], edi
    app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */) = cpu.edi;
    // 0049e8e2  892d849b5900           -mov dword ptr [0x599b84], ebp
    app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */) = cpu.ebp;
    // 0049e8e8  892d30b84d00           -mov dword ptr [0x4db830], ebp
    app->getMemory<x86::reg32>(x86::reg32(5093424) /* 0x4db830 */) = cpu.ebp;
    // 0049e8ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e8ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e8f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e8f1:
    // 0049e8f1  6840f14c00             -push 0x4cf140
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042496 /*0x4cf140*/;
    cpu.esp -= 4;
    // 0049e8f6  e809ebffff             -call 0x49d404
    cpu.esp -= 4;
    sub_49d404(app, cpu);
    if (cpu.terminate) return;
    // 0049e8fb  83c404                 +add esp, 4
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
    // 0049e8fe  e94cffffff             -jmp 0x49e84f
    goto L_0x0049e84f;
L_0x0049e903:
    // 0049e903  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049e908  ff1584f05600           -call dword ptr [0x56f084]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697668) /* 0x56f084 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e90e  83c404                 +add esp, 4
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
    // 0049e911  ebb4                   -jmp 0x49e8c7
    goto L_0x0049e8c7;
}

/* align: skip 0x90 */
void Application::sub_49e914(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e914);
    // 0049e914  c705889b590001000000   -mov dword ptr [0x599b88], 1
    app->getMemory<x86::reg32>(x86::reg32(5872520) /* 0x599b88 */) = 1 /*0x1*/;
    // 0049e91e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0049e920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e921  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e928  751d                   -jne 0x49e947
    if (!cpu.flags.zf)
    {
        goto L_0x0049e947;
    }
L_0x0049e92a:
    // 0049e92a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e92c  8b1d28b84d00           -mov ebx, dword ptr [0x4db828]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5093416) /* 0x4db828 */);
    // 0049e932  890d809b5900           -mov dword ptr [0x599b80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */) = cpu.ecx;
    // 0049e938  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049e93a  7521                   -jne 0x49e95d
    if (!cpu.flags.zf)
    {
        goto L_0x0049e95d;
    }
    // 0049e93c  833d889b590000         +cmp dword ptr [0x599b88], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872520) /* 0x599b88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e943  7546                   -jne 0x49e98b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e98b;
    }
    // 0049e945  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e946  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e947:
    // 0049e947  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049e949  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049e94e  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e954  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e957  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e959  74cf                   -je 0x49e92a
    if (cpu.flags.zf)
    {
        goto L_0x0049e92a;
    }
    // 0049e95b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e95c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e95d:
    // 0049e95d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e95e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e95f  8b358c9b5900           -mov esi, dword ptr [0x599b8c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5872524) /* 0x599b8c */);
    // 0049e965  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e966  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e968  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e969  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049e96b  ff9280000000           -call dword ptr [edx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e971  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e972  893d28b84d00           -mov dword ptr [0x4db828], edi
    app->getMemory<x86::reg32>(x86::reg32(5093416) /* 0x4db828 */) = cpu.edi;
    // 0049e978  ff1558f05600           -call dword ptr [0x56f058]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697624) /* 0x56f058 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e97e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e97f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e980  833d889b590000         +cmp dword ptr [0x599b88], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872520) /* 0x599b88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e987  7502                   -jne 0x49e98b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e98b;
    }
    // 0049e989  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e98a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e98b:
    // 0049e98b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049e98d  a1c4b74d00             -mov eax, dword ptr [0x4db7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093316) /* 0x4db7c4 */);
    // 0049e992  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049e994  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e996  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e997  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e99a  a39cb74d00             -mov dword ptr [0x4db79c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = cpu.eax;
    // 0049e99f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e9a1  a3889b5900             -mov dword ptr [0x599b88], eax
    app->getMemory<x86::reg32>(x86::reg32(5872520) /* 0x599b88 */) = cpu.eax;
    // 0049e9a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e920);
    goto L_entry_0x0049e920;
    // 0049e914  c705889b590001000000   -mov dword ptr [0x599b88], 1
    app->getMemory<x86::reg32>(x86::reg32(5872520) /* 0x599b88 */) = 1 /*0x1*/;
    // 0049e91e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x0049e920:
    // 0049e920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e921  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e928  751d                   -jne 0x49e947
    if (!cpu.flags.zf)
    {
        goto L_0x0049e947;
    }
L_0x0049e92a:
    // 0049e92a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e92c  8b1d28b84d00           -mov ebx, dword ptr [0x4db828]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5093416) /* 0x4db828 */);
    // 0049e932  890d809b5900           -mov dword ptr [0x599b80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */) = cpu.ecx;
    // 0049e938  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049e93a  7521                   -jne 0x49e95d
    if (!cpu.flags.zf)
    {
        goto L_0x0049e95d;
    }
    // 0049e93c  833d889b590000         +cmp dword ptr [0x599b88], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872520) /* 0x599b88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e943  7546                   -jne 0x49e98b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e98b;
    }
    // 0049e945  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e946  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e947:
    // 0049e947  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049e949  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049e94e  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e954  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e957  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e959  74cf                   -je 0x49e92a
    if (cpu.flags.zf)
    {
        goto L_0x0049e92a;
    }
    // 0049e95b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e95c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e95d:
    // 0049e95d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e95e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e95f  8b358c9b5900           -mov esi, dword ptr [0x599b8c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5872524) /* 0x599b8c */);
    // 0049e965  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e966  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e968  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e969  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049e96b  ff9280000000           -call dword ptr [edx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e971  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e972  893d28b84d00           -mov dword ptr [0x4db828], edi
    app->getMemory<x86::reg32>(x86::reg32(5093416) /* 0x4db828 */) = cpu.edi;
    // 0049e978  ff1558f05600           -call dword ptr [0x56f058]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697624) /* 0x56f058 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e97e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e97f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e980  833d889b590000         +cmp dword ptr [0x599b88], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872520) /* 0x599b88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e987  7502                   -jne 0x49e98b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e98b;
    }
    // 0049e989  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e98a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e98b:
    // 0049e98b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049e98d  a1c4b74d00             -mov eax, dword ptr [0x4db7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093316) /* 0x4db7c4 */);
    // 0049e992  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049e994  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e996  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e997  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049e99a  a39cb74d00             -mov dword ptr [0x4db79c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = cpu.eax;
    // 0049e99f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e9a1  a3889b5900             -mov dword ptr [0x599b88], eax
    app->getMemory<x86::reg32>(x86::reg32(5872520) /* 0x599b88 */) = cpu.eax;
    // 0049e9a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e9a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049e9a8);
    // 0049e9a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e9a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e9aa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e9ab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e9ac  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049e9b0  8b15c4b74d00           -mov edx, dword ptr [0x4db7c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093316) /* 0x4db7c4 */);
    // 0049e9b6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e9b8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e9ba  743f                   -je 0x49e9fb
    if (cpu.flags.zf)
    {
        goto L_0x0049e9fb;
    }
    // 0049e9bc  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049e9be:
    // 0049e9be  3b3d889b5900           +cmp edi, dword ptr [0x599b88]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5872520) /* 0x599b88 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e9c4  743e                   -je 0x49ea04
    if (cpu.flags.zf)
    {
        goto L_0x0049ea04;
    }
L_0x0049e9c6:
    // 0049e9c6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049e9cb:
    // 0049e9cb  8b2d809b5900           -mov ebp, dword ptr [0x599b80]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
    // 0049e9d1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e9d3  39ef                   +cmp edi, ebp
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
    // 0049e9d5  7545                   -jne 0x49ea1c
    if (!cpu.flags.zf)
    {
        goto L_0x0049ea1c;
    }
L_0x0049e9d7:
    // 0049e9d7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0049e9d9:
    // 0049e9d9  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e9db  a12cb84d00             -mov eax, dword ptr [0x4db82c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093420) /* 0x4db82c */);
    // 0049e9e0  39c7                   +cmp edi, eax
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
    // 0049e9e2  7552                   -jne 0x49ea36
    if (!cpu.flags.zf)
    {
        goto L_0x0049ea36;
    }
    // 0049e9e4  3b0528b84d00           +cmp eax, dword ptr [0x4db828]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5093416) /* 0x4db828 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e9ea  744a                   -je 0x49ea36
    if (cpu.flags.zf)
    {
        goto L_0x0049ea36;
    }
    // 0049e9ec  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049e9f1:
    // 0049e9f1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e9f3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049e9f5  7504                   -jne 0x49e9fb
    if (!cpu.flags.zf)
    {
        goto L_0x0049e9fb;
    }
    // 0049e9f7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049e9f9  753f                   -jne 0x49ea3a
    if (!cpu.flags.zf)
    {
        goto L_0x0049ea3a;
    }
L_0x0049e9fb:
    // 0049e9fb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e9fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea01  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049ea04:
    // 0049ea04  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0049ea06  a1c4b74d00             -mov eax, dword ptr [0x4db7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093316) /* 0x4db7c4 */);
    // 0049ea0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ea0c  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ea0e  ff5348                 -call dword ptr [ebx + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ea11  3d1c027688             +cmp eax, 0x8876021c
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
    // 0049ea16  74ae                   -je 0x49e9c6
    if (cpu.flags.zf)
    {
        goto L_0x0049e9c6;
    }
    // 0049ea18  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049ea1a  ebaf                   -jmp 0x49e9cb
    goto L_0x0049e9cb;
L_0x0049ea1c:
    // 0049ea1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ea1d  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049ea22  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ea28  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ea2b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ea2d  74a8                   -je 0x49e9d7
    if (cpu.flags.zf)
    {
        goto L_0x0049e9d7;
    }
    // 0049ea2f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049ea34  eba3                   -jmp 0x49e9d9
    goto L_0x0049e9d9;
L_0x0049ea36:
    // 0049ea36  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049ea38  ebb7                   -jmp 0x49e9f1
    goto L_0x0049e9f1;
L_0x0049ea3a:
    // 0049ea3a  ff1544f05600           -call dword ptr [0x56f044]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697604) /* 0x56f044 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ea40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ea42  0f8d76ffffff           -jge 0x49e9be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049e9be;
    }
    // 0049ea48  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ea4a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea4b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea4c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea4d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea4e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49ea54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ea54);
    // 0049ea54  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ea55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ea56  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ea57  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049ea5a  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049ea5e  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049ea62  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049ea66  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049ea6a  d90508f05600           -fld dword ptr [0x56f008]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5697544) /* 0x56f008 */)));
    // 0049ea70  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0049ea72  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0049ea74  e8275ffeff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 0049ea79  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049ea7c  d9050cf05600           -fld dword ptr [0x56f00c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5697548) /* 0x56f00c */)));
    // 0049ea82  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0049ea84  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0049ea86  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ea88  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049ea8b  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049ea8e  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049ea90  a3f8ef5600             -mov dword ptr [0x56eff8], eax
    app->getMemory<x86::reg32>(x86::reg32(5697528) /* 0x56eff8 */) = cpu.eax;
    // 0049ea95  a3609b5900             -mov dword ptr [0x599b60], eax
    app->getMemory<x86::reg32>(x86::reg32(5872480) /* 0x599b60 */) = cpu.eax;
    // 0049ea9a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049ea9c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ea9e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049eaa1  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049eaa3  e8f85efeff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 0049eaa8  db5c2404               -fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049eaac  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049eab0  48                     -dec eax
    (cpu.eax)--;
    // 0049eab1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049eab3  a3fcef5600             -mov dword ptr [0x56effc], eax
    app->getMemory<x86::reg32>(x86::reg32(5697532) /* 0x56effc */) = cpu.eax;
    // 0049eab8  a3649b5900             -mov dword ptr [0x599b64], eax
    app->getMemory<x86::reg32>(x86::reg32(5872484) /* 0x599b64 */) = cpu.eax;
    // 0049eabd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049eac0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049eac2  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049eac4  a300f05600             -mov dword ptr [0x56f000], eax
    app->getMemory<x86::reg32>(x86::reg32(5697536) /* 0x56f000 */) = cpu.eax;
    // 0049eac9  a3689b5900             -mov dword ptr [0x599b68], eax
    app->getMemory<x86::reg32>(x86::reg32(5872488) /* 0x599b68 */) = cpu.eax;
    // 0049eace  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049ead0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ead2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049ead5  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049ead7  48                     -dec eax
    (cpu.eax)--;
    // 0049ead8  8b35709b5900           -mov esi, dword ptr [0x599b70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5872496) /* 0x599b70 */);
    // 0049eade  a304f05600             -mov dword ptr [0x56f004], eax
    app->getMemory<x86::reg32>(x86::reg32(5697540) /* 0x56f004 */) = cpu.eax;
    // 0049eae3  a36c9b5900             -mov dword ptr [0x599b6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5872492) /* 0x599b6c */) = cpu.eax;
    // 0049eae8  3b35609b5900           +cmp esi, dword ptr [0x599b60]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5872480) /* 0x599b60 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eaee  7529                   -jne 0x49eb19
    if (!cpu.flags.zf)
    {
        goto L_0x0049eb19;
    }
    // 0049eaf0  a1649b5900             -mov eax, dword ptr [0x599b64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872484) /* 0x599b64 */);
    // 0049eaf5  3b05749b5900           +cmp eax, dword ptr [0x599b74]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5872500) /* 0x599b74 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eafb  751c                   -jne 0x49eb19
    if (!cpu.flags.zf)
    {
        goto L_0x0049eb19;
    }
    // 0049eafd  a1689b5900             -mov eax, dword ptr [0x599b68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872488) /* 0x599b68 */);
    // 0049eb02  3b05789b5900           +cmp eax, dword ptr [0x599b78]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5872504) /* 0x599b78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eb08  750f                   -jne 0x49eb19
    if (!cpu.flags.zf)
    {
        goto L_0x0049eb19;
    }
    // 0049eb0a  a16c9b5900             -mov eax, dword ptr [0x599b6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5872492) /* 0x599b6c */);
    // 0049eb0f  8b157c9b5900           -mov edx, dword ptr [0x599b7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5872508) /* 0x599b7c */);
    // 0049eb15  39d0                   +cmp eax, edx
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
    // 0049eb17  7413                   -je 0x49eb2c
    if (cpu.flags.zf)
    {
        goto L_0x0049eb2c;
    }
L_0x0049eb19:
    // 0049eb19  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049eb1e  a330b84d00             -mov dword ptr [0x4db830], eax
    app->getMemory<x86::reg32>(x86::reg32(5093424) /* 0x4db830 */) = cpu.eax;
    // 0049eb23  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049eb26  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb28  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb29  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0049eb2c:
    // 0049eb2c  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049eb2e  a330b84d00             -mov dword ptr [0x4db830], eax
    app->getMemory<x86::reg32>(x86::reg32(5093424) /* 0x4db830 */) = cpu.eax;
    // 0049eb33  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049eb36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb38  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb39  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_49eb3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049eb3c);
    // 0049eb3c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049eb3d  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0049eb40  833d28b84d0000         +cmp dword ptr [0x4db828], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093416) /* 0x4db828 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eb47  0f8498000000           -je 0x49ebe5
    if (cpu.flags.zf)
    {
        goto L_0x0049ebe5;
    }
L_0x0049eb4d:
    // 0049eb4d  833d2cb84d0000         +cmp dword ptr [0x4db82c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093420) /* 0x4db82c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eb54  740d                   -je 0x49eb63
    if (cpu.flags.zf)
    {
        goto L_0x0049eb63;
    }
    // 0049eb56  6804f24c00             -push 0x4cf204
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042692 /*0x4cf204*/;
    cpu.esp -= 4;
    // 0049eb5b  e8a4e8ffff             -call 0x49d404
    cpu.esp -= 4;
    sub_49d404(app, cpu);
    if (cpu.terminate) return;
    // 0049eb60  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049eb63:
    // 0049eb63  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049eb65  e83efeffff             -call 0x49e9a8
    cpu.esp -= 4;
    sub_49e9a8(app, cpu);
    if (cpu.terminate) return;
L_0x0049eb6a:
    // 0049eb6a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049eb6c  ff1558f05600           -call dword ptr [0x56f058]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697624) /* 0x56f058 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049eb72  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049eb74  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049eb76  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049eb7a  be6c000000             -mov esi, 0x6c
    cpu.esi = 108 /*0x6c*/;
    // 0049eb7f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049eb80  a1e8b74d00             -mov eax, dword ptr [0x4db7e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093352) /* 0x4db7e8 */);
    // 0049eb85  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0049eb89  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049eb8b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049eb8d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049eb8e  a328b84d00             -mov dword ptr [0x4db828], eax
    app->getMemory<x86::reg32>(x86::reg32(5093416) /* 0x4db828 */) = cpu.eax;
    // 0049eb93  ff5264                 -call dword ptr [edx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049eb96  a39cb74d00             -mov dword ptr [0x4db79c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093276) /* 0x4db79c */) = cpu.eax;
    // 0049eb9b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049eb9d  7558                   -jne 0x49ebf7
    if (!cpu.flags.zf)
    {
        goto L_0x0049ebf7;
    }
    // 0049eb9f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049eba0  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049eba4  a38c9b5900             -mov dword ptr [0x599b8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5872524) /* 0x599b8c */) = cpu.eax;
    // 0049eba9  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049ebad  8b7c2458               -mov edi, dword ptr [esp + 0x58]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0049ebb1  a3909b5900             -mov dword ptr [0x599b90], eax
    app->getMemory<x86::reg32>(x86::reg32(5872528) /* 0x599b90 */) = cpu.eax;
    // 0049ebb6  83ff10                 +cmp edi, 0x10
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
    // 0049ebb9  754f                   -jne 0x49ec0a
    if (!cpu.flags.zf)
    {
        goto L_0x0049ec0a;
    }
    // 0049ebbb  817c2460e0070000       +cmp dword ptr [esp + 0x60], 0x7e0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2016 /*0x7e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ebc3  7439                   -je 0x49ebfe
    if (cpu.flags.zf)
    {
        goto L_0x0049ebfe;
    }
    // 0049ebc5  c705949b590003000000   -mov dword ptr [0x599b94], 3
    app->getMemory<x86::reg32>(x86::reg32(5872532) /* 0x599b94 */) = 3 /*0x3*/;
L_0x0049ebcf:
    // 0049ebcf  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ebd4  b88c9b5900             -mov eax, 0x599b8c
    cpu.eax = 5872524 /*0x599b8c*/;
    // 0049ebd9  89352cb84d00           -mov dword ptr [0x4db82c], esi
    app->getMemory<x86::reg32>(x86::reg32(5093420) /* 0x4db82c */) = cpu.esi;
    // 0049ebdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ebe0  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0049ebe3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ebe4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ebe5:
    // 0049ebe5  833d889b590000         +cmp dword ptr [0x599b88], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872520) /* 0x599b88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ebec  0f855bffffff           -jne 0x49eb4d
    if (!cpu.flags.zf)
    {
        goto L_0x0049eb4d;
    }
    // 0049ebf2  e973ffffff             -jmp 0x49eb6a
    goto L_0x0049eb6a;
L_0x0049ebf7:
    // 0049ebf7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ebf9  83c46c                 +add esp, 0x6c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049ebfc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ebfd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ebfe:
    // 0049ebfe  c705949b590004000000   -mov dword ptr [0x599b94], 4
    app->getMemory<x86::reg32>(x86::reg32(5872532) /* 0x599b94 */) = 4 /*0x4*/;
    // 0049ec08  ebc5                   -jmp 0x49ebcf
    goto L_0x0049ebcf;
L_0x0049ec0a:
    // 0049ec0a  83ff20                 +cmp edi, 0x20
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ec0d  75c0                   -jne 0x49ebcf
    if (!cpu.flags.zf)
    {
        goto L_0x0049ebcf;
    }
    // 0049ec0f  c705949b590005000000   -mov dword ptr [0x599b94], 5
    app->getMemory<x86::reg32>(x86::reg32(5872532) /* 0x599b94 */) = 5 /*0x5*/;
    // 0049ec19  ebb4                   -jmp 0x49ebcf
    goto L_0x0049ebcf;
}

/* align: skip 0x90 */
void Application::sub_49ec1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ec1c);
    // 0049ec1c  833d2cb84d0000         +cmp dword ptr [0x4db82c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093420) /* 0x4db82c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ec23  743d                   -je 0x49ec62
    if (cpu.flags.zf)
    {
        goto L_0x0049ec62;
    }
    // 0049ec25  8b0d28b84d00           -mov ecx, dword ptr [0x4db828]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093416) /* 0x4db828 */);
    // 0049ec2b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049ec2d  7433                   -je 0x49ec62
    if (cpu.flags.zf)
    {
        goto L_0x0049ec62;
    }
    // 0049ec2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ec30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ec31  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ec33  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049ec35  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049ec39  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049ec3b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ec3c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ec3d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ec3f  ff9280000000           -call dword ptr [edx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ec45  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ec46  893528b84d00           -mov dword ptr [0x4db828], esi
    app->getMemory<x86::reg32>(x86::reg32(5093416) /* 0x4db828 */) = cpu.esi;
    // 0049ec4c  89352cb84d00           -mov dword ptr [0x4db82c], esi
    app->getMemory<x86::reg32>(x86::reg32(5093420) /* 0x4db82c */) = cpu.esi;
    // 0049ec52  ff1558f05600           -call dword ptr [0x56f058]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697624) /* 0x56f058 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ec58  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049ec5d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec5f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049ec62:
    // 0049ec62  6834f24c00             -push 0x4cf234
    app->getMemory<x86::reg32>(cpu.esp-4) = 5042740 /*0x4cf234*/;
    cpu.esp -= 4;
    // 0049ec67  e898e7ffff             -call 0x49d404
    cpu.esp -= 4;
    sub_49d404(app, cpu);
    if (cpu.terminate) return;
    // 0049ec6c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ec6f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ec71  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49ec80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049ec80);
    // 0049ec80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ec81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ec82  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ec85  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049ec89  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049ec8d  83f90a                 +cmp ecx, 0xa
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ec90  7329                   -jae 0x49ecbb
    if (!cpu.flags.cf)
    {
        goto L_0x0049ecbb;
    }
    // 0049ec92  83f904                 +cmp ecx, 4
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
    // 0049ec95  0f8364010000           -jae 0x49edff
    if (!cpu.flags.cf)
    {
        goto L_0x0049edff;
    }
    // 0049ec9b  83f901                 +cmp ecx, 1
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
    // 0049ec9e  0f8316020000           -jae 0x49eeba
    if (!cpu.flags.cf)
    {
        goto L_0x0049eeba;
    }
    // 0049eca4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049eca6  0f85c5010000           -jne 0x49ee71
    if (!cpu.flags.zf)
    {
        goto L_0x0049ee71;
    }
L_0x0049ecac:
    // 0049ecac  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ecb1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ecb3  83c404                 +add esp, 4
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
    // 0049ecb6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecb7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecb8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ecbb:
    // 0049ecbb  771e                   -ja 0x49ecdb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ecdb;
    }
    // 0049ecbd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049ecbf  0f85cf020000           -jne 0x49ef94
    if (!cpu.flags.zf)
    {
        goto L_0x0049ef94;
    }
    // 0049ecc5  800dc9ef560020         -or byte ptr [0x56efc9], 0x20
    app->getMemory<x86::reg8>(x86::reg32(5697481) /* 0x56efc9 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0049eccc  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ecd1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ecd3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ecd6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecd7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecd8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ecdb:
    // 0049ecdb  81f9ca000000           +cmp ecx, 0xca
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(202 /*0xca*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ece1  7327                   -jae 0x49ed0a
    if (!cpu.flags.cf)
    {
        goto L_0x0049ed0a;
    }
    // 0049ece3  83f911                 +cmp ecx, 0x11
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ece6  0f83b5000000           -jae 0x49eda1
    if (!cpu.flags.cf)
    {
        goto L_0x0049eda1;
    }
    // 0049ecec  83f910                 +cmp ecx, 0x10
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
    // 0049ecef  0f857c010000           -jne 0x49ee71
    if (!cpu.flags.zf)
    {
        goto L_0x0049ee71;
    }
    // 0049ecf5  893520f05600           -mov dword ptr [0x56f020], esi
    app->getMemory<x86::reg32>(x86::reg32(5697568) /* 0x56f020 */) = cpu.esi;
    // 0049ecfb  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ed00  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ed02  83c404                 +add esp, 4
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
    // 0049ed05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed07  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ed0a:
    // 0049ed0a  7722                   -ja 0x49ed2e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ed2e;
    }
    // 0049ed0c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049ed0e  0f8496020000           -je 0x49efaa
    if (cpu.flags.zf)
    {
        goto L_0x0049efaa;
    }
    // 0049ed14  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0049ed19:
    // 0049ed19  890de4ef5600           -mov dword ptr [0x56efe4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5697508) /* 0x56efe4 */) = cpu.ecx;
    // 0049ed1f  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ed24  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ed26  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ed29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed2b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ed2e:
    // 0049ed2e  81f9cc000000           +cmp ecx, 0xcc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(204 /*0xcc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ed34  7315                   -jae 0x49ed4b
    if (!cpu.flags.cf)
    {
        goto L_0x0049ed4b;
    }
    // 0049ed36  8935acb74d00           -mov dword ptr [0x4db7ac], esi
    app->getMemory<x86::reg32>(x86::reg32(5093292) /* 0x4db7ac */) = cpu.esi;
    // 0049ed3c  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ed41  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ed43  83c404                 +add esp, 4
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
    // 0049ed46  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed47  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed48  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ed4b:
    // 0049ed4b  0f8660020000           -jbe 0x49efb1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049efb1;
    }
    // 0049ed51  81f9cd000000           +cmp ecx, 0xcd
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
    // 0049ed57  771e                   -ja 0x49ed77
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ed77;
    }
    // 0049ed59  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049ed5b  0f8479020000           -je 0x49efda
    if (cpu.flags.zf)
    {
        goto L_0x0049efda;
    }
    // 0049ed61  800dcaef560004         -or byte ptr [0x56efca], 4
    app->getMemory<x86::reg8>(x86::reg32(5697482) /* 0x56efca */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 0049ed68  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ed6d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ed6f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ed72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed74  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ed77:
    // 0049ed77  81f9ce000000           +cmp ecx, 0xce
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(206 /*0xce*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ed7d  0f85ee000000           -jne 0x49ee71
    if (!cpu.flags.zf)
    {
        goto L_0x0049ee71;
    }
    // 0049ed83  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049ed85  0f8465020000           -je 0x49eff0
    if (cpu.flags.zf)
    {
        goto L_0x0049eff0;
    }
    // 0049ed8b  800dc9ef560002         -or byte ptr [0x56efc9], 2
    app->getMemory<x86::reg8>(x86::reg32(5697481) /* 0x56efc9 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0049ed92  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ed97  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ed99  83c404                 +add esp, 4
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
    // 0049ed9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed9e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049eda1:
    // 0049eda1  7715                   -ja 0x49edb8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049edb8;
    }
    // 0049eda3  8935a8b74d00           -mov dword ptr [0x4db7a8], esi
    app->getMemory<x86::reg32>(x86::reg32(5093288) /* 0x4db7a8 */) = cpu.esi;
    // 0049eda9  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049edae  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049edb0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049edb3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edb4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edb5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049edb8:
    // 0049edb8  83f913                 +cmp ecx, 0x13
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049edbb  0f82b0000000           -jb 0x49ee71
    if (cpu.flags.cf)
    {
        goto L_0x0049ee71;
    }
    // 0049edc1  771b                   -ja 0x49edde
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049edde;
    }
    // 0049edc3  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 0049edc8  bf44f05600             -mov edi, 0x56f044
    cpu.edi = 5697604 /*0x56f044*/;
    // 0049edcd  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049edcf  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049edd4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049edd6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049edd9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edda  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eddb  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049edde:
    // 0049edde  81f9c9000000           +cmp ecx, 0xc9
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
    // 0049ede4  0f8587000000           -jne 0x49ee71
    if (!cpu.flags.zf)
    {
        goto L_0x0049ee71;
    }
    // 0049edea  89351cf05600           -mov dword ptr [0x56f01c], esi
    app->getMemory<x86::reg32>(x86::reg32(5697564) /* 0x56f01c */) = cpu.esi;
    // 0049edf0  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049edf5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049edf7  83c404                 +add esp, 4
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
    // 0049edfa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edfb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edfc  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049edff:
    // 0049edff  775d                   -ja 0x49ee5e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ee5e;
    }
    // 0049ee01  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049ee03  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049ee06  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049ee0c  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049ee0f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049ee11  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0049ee14  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0049ee17  dd057cf24c00           -fld qword ptr [0x4cf27c]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5042812) /* 0x4cf27c */)));
    // 0049ee1d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049ee1f  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049ee21  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049ee27  81e6ff000000           -and esi, 0xff
    cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049ee2d  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049ee30  d91dd8ef5600           -fstp dword ptr [0x56efd8]
    app->getMemory<float>(x86::reg32(5697496) /* 0x56efd8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049ee36  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0049ee39  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049ee3b  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0049ee3e  d91ddcef5600           -fstp dword ptr [0x56efdc]
    app->getMemory<float>(x86::reg32(5697500) /* 0x56efdc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049ee44  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0049ee47  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049ee49  d91de0ef5600           -fstp dword ptr [0x56efe0]
    app->getMemory<float>(x86::reg32(5697504) /* 0x56efe0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049ee4f  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ee54  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ee56  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ee59  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ee5a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ee5b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ee5e:
    // 0049ee5e  83f907                 +cmp ecx, 7
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ee61  731a                   -jae 0x49ee7d
    if (!cpu.flags.cf)
    {
        goto L_0x0049ee7d;
    }
    // 0049ee63  83f906                 +cmp ecx, 6
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ee66  7509                   -jne 0x49ee71
    if (!cpu.flags.zf)
    {
        goto L_0x0049ee71;
    }
    // 0049ee68  83fe01                 +cmp esi, 1
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
    // 0049ee6b  0f843bfeffff           -je 0x49ecac
    if (cpu.flags.zf)
    {
        goto L_0x0049ecac;
    }
L_0x0049ee71:
    // 0049ee71  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ee73  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ee75  83c404                 +add esp, 4
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
    // 0049ee78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ee79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ee7a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ee7d:
    // 0049ee7d  0f8729feffff           -ja 0x49ecac
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ecac;
    }
    // 0049ee83  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049ee85  0f84d4000000           -je 0x49ef5f
    if (cpu.flags.zf)
    {
        goto L_0x0049ef5f;
    }
    // 0049ee8b  83fe01                 +cmp esi, 1
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
    // 0049ee8e  0f85e1000000           -jne 0x49ef75
    if (!cpu.flags.zf)
    {
        goto L_0x0049ef75;
    }
    // 0049ee94  a0c8ef5600             -mov al, byte ptr [0x56efc8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5697480) /* 0x56efc8 */);
    // 0049ee99  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0049ee9b  a2c8ef5600             -mov byte ptr [0x56efc8], al
    app->getMemory<x86::reg8>(x86::reg32(5697480) /* 0x56efc8 */) = cpu.al;
    // 0049eea0  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 0049eea2  80e4fb                 -and ah, 0xfb
    cpu.ah &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0049eea5  8825c8ef5600           -mov byte ptr [0x56efc8], ah
    app->getMemory<x86::reg8>(x86::reg32(5697480) /* 0x56efc8 */) = cpu.ah;
    // 0049eeab  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049eeb0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049eeb2  83c404                 +add esp, 4
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
    // 0049eeb5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eeb6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eeb7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049eeba:
    // 0049eeba  761e                   -jbe 0x49eeda
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049eeda;
    }
    // 0049eebc  83f902                 +cmp ecx, 2
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eebf  7765                   -ja 0x49ef26
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049ef26;
    }
    // 0049eec1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049eec3  752a                   -jne 0x49eeef
    if (!cpu.flags.zf)
    {
        goto L_0x0049eeef;
    }
    // 0049eec5  8935c4ef5600           -mov dword ptr [0x56efc4], esi
    app->getMemory<x86::reg32>(x86::reg32(5697476) /* 0x56efc4 */) = cpu.esi;
    // 0049eecb  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049eed0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049eed2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049eed5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eed6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eed7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049eeda:
    // 0049eeda  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049eedb  e828010000             -call 0x49f008
    cpu.esp -= 4;
    sub_49f008(app, cpu);
    if (cpu.terminate) return;
    // 0049eee0  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049eee5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049eee7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049eeea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eeeb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eeec  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049eeef:
    // 0049eeef  83fe01                 +cmp esi, 1
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
    // 0049eef2  7515                   -jne 0x49ef09
    if (!cpu.flags.zf)
    {
        goto L_0x0049ef09;
    }
    // 0049eef4  8935c4ef5600           -mov dword ptr [0x56efc4], esi
    app->getMemory<x86::reg32>(x86::reg32(5697476) /* 0x56efc4 */) = cpu.esi;
    // 0049eefa  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049eeff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ef01  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ef04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef06  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ef09:
    // 0049ef09  83fe02                 +cmp esi, 2
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
    // 0049ef0c  0f855fffffff           -jne 0x49ee71
    if (!cpu.flags.zf)
    {
        goto L_0x0049ee71;
    }
    // 0049ef12  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ef14  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ef16  8915c4ef5600           -mov dword ptr [0x56efc4], edx
    app->getMemory<x86::reg32>(x86::reg32(5697476) /* 0x56efc4 */) = cpu.edx;
    // 0049ef1c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ef1e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ef21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef23  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ef26:
    // 0049ef26  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049ef28  7516                   -jne 0x49ef40
    if (!cpu.flags.zf)
    {
        goto L_0x0049ef40;
    }
    // 0049ef2a  8025caef5600f7         -and byte ptr [0x56efca], 0xf7
    app->getMemory<x86::reg8>(x86::reg32(5697482) /* 0x56efca */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0049ef31  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ef36  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ef38  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ef3b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef3c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef3d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ef40:
    // 0049ef40  83fe01                 +cmp esi, 1
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
    // 0049ef43  0f8528ffffff           -jne 0x49ee71
    if (!cpu.flags.zf)
    {
        goto L_0x0049ee71;
    }
    // 0049ef49  800dcaef560008         -or byte ptr [0x56efca], 8
    app->getMemory<x86::reg8>(x86::reg32(5697482) /* 0x56efca */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0049ef50  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ef55  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ef57  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ef5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef5c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ef5f:
    // 0049ef5f  8025c8ef5600fa         -and byte ptr [0x56efc8], 0xfa
    app->getMemory<x86::reg8>(x86::reg32(5697480) /* 0x56efc8 */) &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 0049ef66  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ef6b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ef6d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ef70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef72  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ef75:
    // 0049ef75  83fe02                 +cmp esi, 2
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
    // 0049ef78  0f85f3feffff           -jne 0x49ee71
    if (!cpu.flags.zf)
    {
        goto L_0x0049ee71;
    }
    // 0049ef7e  800dc8ef560005         -or byte ptr [0x56efc8], 5
    app->getMemory<x86::reg8>(x86::reg32(5697480) /* 0x56efc8 */) |= x86::reg8(x86::sreg8(5 /*0x5*/));
    // 0049ef85  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ef8a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ef8c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ef8f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef91  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049ef94:
    // 0049ef94  8025c9ef5600df         -and byte ptr [0x56efc9], 0xdf
    app->getMemory<x86::reg8>(x86::reg32(5697481) /* 0x56efc9 */) &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 0049ef9b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049efa0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049efa2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049efa5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efa6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efa7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049efaa:
    // 0049efaa  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049efac  e968fdffff             -jmp 0x49ed19
    goto L_0x0049ed19;
L_0x0049efb1:
    // 0049efb1  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049efb6  bfb0b74d00             -mov edi, 0x4db7b0
    cpu.edi = 5093296 /*0x4db7b0*/;
    // 0049efbb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049efbc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049efbe  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049efc1  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049efc3  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049efc5  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049efc8  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049efca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efcb  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049efd0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049efd2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049efd5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efd6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efd7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049efda:
    // 0049efda  8025caef5600fb         -and byte ptr [0x56efca], 0xfb
    app->getMemory<x86::reg8>(x86::reg32(5697482) /* 0x56efca */) &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0049efe1  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049efe6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049efe8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049efeb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efed  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049eff0:
    // 0049eff0  8025c9ef5600fd         -and byte ptr [0x56efc9], 0xfd
    app->getMemory<x86::reg8>(x86::reg32(5697481) /* 0x56efc9 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0049eff7  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049effc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049effe  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f001  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f002  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f003  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49f008(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f008);
    // 0049f008  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f00c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f00e  742c                   -je 0x49f03c
    if (cpu.flags.zf)
    {
        goto L_0x0049f03c;
    }
    // 0049f010  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f011  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049f016  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049f019  8a15c8ef5600           -mov dl, byte ptr [0x56efc8]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5697480) /* 0x56efc8 */);
    // 0049f01f  a3ccef5600             -mov dword ptr [0x56efcc], eax
    app->getMemory<x86::reg32>(x86::reg32(5697484) /* 0x56efcc */) = cpu.eax;
    // 0049f024  80ca02                 -or dl, 2
    cpu.dl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0049f027  891df4ef5600           -mov dword ptr [0x56eff4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5697524) /* 0x56eff4 */) = cpu.ebx;
    // 0049f02d  8815c8ef5600           -mov byte ptr [0x56efc8], dl
    app->getMemory<x86::reg8>(x86::reg32(5697480) /* 0x56efc8 */) = cpu.dl;
    // 0049f033  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f034  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f039  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049f03c:
    // 0049f03c  a3ccef5600             -mov dword ptr [0x56efcc], eax
    app->getMemory<x86::reg32>(x86::reg32(5697484) /* 0x56efcc */) = cpu.eax;
    // 0049f041  a3f4ef5600             -mov dword ptr [0x56eff4], eax
    app->getMemory<x86::reg32>(x86::reg32(5697524) /* 0x56eff4 */) = cpu.eax;
    // 0049f046  8025c8ef5600fd         -and byte ptr [0x56efc8], 0xfd
    app->getMemory<x86::reg8>(x86::reg32(5697480) /* 0x56efc8 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0049f04d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f052  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49f060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f060);
    // 0049f060  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049f062  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049f064  0100                   -add dword ptr [eax], eax
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f066  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049f068  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049f06a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049f06c  0300                   -add eax, dword ptr [eax]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 0049f06e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049f070  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049f072  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049f074  0100                   -add dword ptr [eax], eax
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f076  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049f078  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049f07a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049f07c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049f07e  0100                   -add dword ptr [eax], eax
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f080  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f081  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f082  81ec90000000           -sub esp, 0x90
    (cpu.esp) -= x86::reg32(x86::sreg32(144 /*0x90*/));
    // 0049f088  8dbc2480000000         -lea edi, [esp + 0x80]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0049f08f  be60f04900             -mov esi, 0x49f060
    cpu.esi = 4845664 /*0x49f060*/;
    // 0049f094  8b15849b5900           -mov edx, dword ptr [0x599b84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
    // 0049f09a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f09b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f09c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f09d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f09e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f0a0  0f8489000000           -je 0x49f12f
    if (cpu.flags.zf)
    {
        goto L_0x0049f12f;
    }
    // 0049f0a6  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f0ad  756c                   -jne 0x49f11b
    if (!cpu.flags.zf)
    {
        goto L_0x0049f11b;
    }
L_0x0049f0af:
    // 0049f0af  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0049f0b4  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0049f0b6  8bb4249c000000         -mov esi, dword ptr [esp + 0x9c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0049f0bd  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f0bf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049f0c1  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0049f0c6  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049f0ca  8bb424a0000000         -mov esi, dword ptr [esp + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0049f0d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f0d2  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f0d4  8d842484000000         -lea eax, [esp + 0x84]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0049f0db  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0049f0e0  8d7c2444               -lea edi, [esp + 0x44]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049f0e4  8bb424a8000000         -mov esi, dword ptr [esp + 0xa8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 0049f0eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f0ec  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f0ee  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049f0f0  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0049f0f5  8d7c246c               -lea edi, [esp + 0x6c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0049f0f9  8bb424b4000000         -mov esi, dword ptr [esp + 0xb4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0049f100  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f105  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f107  ff1594f05600           -call dword ptr [0x56f094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697684) /* 0x56f094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f10d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049f110  81c490000000           -add esp, 0x90
    (cpu.esp) += x86::reg32(x86::sreg32(144 /*0x90*/));
    // 0049f116  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f117  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f118  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0049f11b:
    // 0049f11b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f11d  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f122  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f128  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f12b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f12d  7580                   -jne 0x49f0af
    if (!cpu.flags.zf)
    {
        goto L_0x0049f0af;
    }
L_0x0049f12f:
    // 0049f12f  e82cf6ffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
    // 0049f134  e976ffffff             -jmp 0x49f0af
    goto L_0x0049f0af;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49f13c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f13c);
    // 0049f13c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f13d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f13e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f13f  833d849b590000         +cmp dword ptr [0x599b84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f146  7440                   -je 0x49f188
    if (cpu.flags.zf)
    {
        goto L_0x0049f188;
    }
    // 0049f148  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f14f  7523                   -jne 0x49f174
    if (!cpu.flags.zf)
    {
        goto L_0x0049f174;
    }
L_0x0049f151:
    // 0049f151  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049f155  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f156  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049f15a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f15b  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049f15f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f160  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f165  ff1594f05600           -call dword ptr [0x56f094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697684) /* 0x56f094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f16b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049f16e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f16f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f170  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f171  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049f174:
    // 0049f174  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f176  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f17b  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f181  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f184  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f186  75c9                   -jne 0x49f151
    if (!cpu.flags.zf)
    {
        goto L_0x0049f151;
    }
L_0x0049f188:
    // 0049f188  e8d3f5ffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
    // 0049f18d  ebc2                   -jmp 0x49f151
    goto L_0x0049f151;
}

/* align: skip 0x90 */
void Application::sub_49f190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f190);
    // 0049f190  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f191  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f192  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f193  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f194  81ec00100000           -sub esp, 0x1000
    (cpu.esp) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 0049f19a  8bb42414100000         -mov esi, dword ptr [esp + 0x1014]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4116) /* 0x1014 */);
    // 0049f1a1  8bac2418100000         -mov ebp, dword ptr [esp + 0x1018]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4120) /* 0x1018 */);
    // 0049f1a8  8b9c241c100000         -mov ebx, dword ptr [esp + 0x101c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4124) /* 0x101c */);
    // 0049f1af  833d849b590000         +cmp dword ptr [0x599b84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f1b6  0f84ba000000           -je 0x49f276
    if (cpu.flags.zf)
    {
        goto L_0x0049f276;
    }
    // 0049f1bc  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f1c3  0f8595000000           -jne 0x49f25e
    if (!cpu.flags.zf)
    {
        goto L_0x0049f25e;
    }
L_0x0049f1c9:
    // 0049f1c9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049f1cb  0f84b6000000           -je 0x49f287
    if (cpu.flags.zf)
    {
        goto L_0x0049f287;
    }
    // 0049f1d1  81fe00010000           +cmp esi, 0x100
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f1d7  0f8ea3000000           -jle 0x49f280
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f280;
    }
    // 0049f1dd  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x0049f1e2:
    // 0049f1e2  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049f1e4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f1e7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049f1ea  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049f1ec  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f1ef  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049f1f3  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049f1f5  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f1f8  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049f1fc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049f1fe  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049f200  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f203  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049f207  83fa01                 +cmp edx, 1
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
    // 0049f20a  7e33                   -jle 0x49f23f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f23f;
    }
    // 0049f20c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049f20e  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0049f213  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
L_0x0049f216:
    // 0049f216  8b5404f4               -mov edx, dword ptr [esp + eax - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.eax * 1);
    // 0049f21a  891404                 -mov dword ptr [esp + eax], edx
    app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 1) = cpu.edx;
    // 0049f21d  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049f21f  89540404               -mov dword ptr [esp + eax + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.edx;
    // 0049f223  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049f226  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049f229  895404f8               -mov dword ptr [esp + eax - 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1) = cpu.edx;
    // 0049f22d  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f230  8b5404e8               -mov edx, dword ptr [esp + eax - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-24) /* -0x18 */ + cpu.eax * 1);
    // 0049f234  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f237  895404fc               -mov dword ptr [esp + eax - 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.edx;
    // 0049f23b  39c8                   +cmp eax, ecx
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
    // 0049f23d  7cd7                   -jl 0x49f216
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f216;
    }
L_0x0049f23f:
    // 0049f23f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f240  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f244  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f245  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f246  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f24b  83eb08                 -sub ebx, 8
    (cpu.ebx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f24e  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f250  ff1594f05600           -call dword ptr [0x56f094]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697684) /* 0x56f094 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f256  83c410                 +add esp, 0x10
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
    // 0049f259  e96bffffff             -jmp 0x49f1c9
    goto L_0x0049f1c9;
L_0x0049f25e:
    // 0049f25e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f260  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f265  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f26b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f26e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f270  0f8553ffffff           -jne 0x49f1c9
    if (!cpu.flags.zf)
    {
        goto L_0x0049f1c9;
    }
L_0x0049f276:
    // 0049f276  e8e5f4ffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
    // 0049f27b  e949ffffff             -jmp 0x49f1c9
    goto L_0x0049f1c9;
L_0x0049f280:
    // 0049f280  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049f282  e95bffffff             -jmp 0x49f1e2
    goto L_0x0049f1e2;
L_0x0049f287:
    // 0049f287  81c400100000           -add esp, 0x1000
    (cpu.esp) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 0049f28d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f28e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f28f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f290  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f291  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_49f294(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f294);
    // 0049f294  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f295  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f296  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0049f299  8d7c2460               -lea edi, [esp + 0x60]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0049f29d  be70f04900             -mov esi, 0x49f070
    cpu.esi = 4845680 /*0x49f070*/;
    // 0049f2a2  8b15849b5900           -mov edx, dword ptr [0x599b84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
    // 0049f2a8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f2a9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f2aa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f2ab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f2ad  746b                   -je 0x49f31a
    if (cpu.flags.zf)
    {
        goto L_0x0049f31a;
    }
    // 0049f2af  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f2b6  754e                   -jne 0x49f306
    if (!cpu.flags.zf)
    {
        goto L_0x0049f306;
    }
L_0x0049f2b8:
    // 0049f2b8  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0049f2bd  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0049f2bf  8b742478               -mov esi, dword ptr [esp + 0x78]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0049f2c3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f2c5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049f2c7  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0049f2cc  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049f2d0  8b74247c               -mov esi, dword ptr [esp + 0x7c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0049f2d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f2d5  8d442464               -lea eax, [esp + 0x64]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0049f2d9  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f2db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f2dc  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0049f2e1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049f2e3  8d7c244c               -lea edi, [esp + 0x4c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049f2e7  8bb4248c000000         -mov esi, dword ptr [esp + 0x8c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0049f2ee  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f2f3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f2f5  ff1590f05600           -call dword ptr [0x56f090]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697680) /* 0x56f090 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f2fb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049f2fe  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0049f301  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f302  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f303  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049f306:
    // 0049f306  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f308  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f30d  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f313  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f316  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f318  759e                   -jne 0x49f2b8
    if (!cpu.flags.zf)
    {
        goto L_0x0049f2b8;
    }
L_0x0049f31a:
    // 0049f31a  e841f4ffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
    // 0049f31f  eb97                   -jmp 0x49f2b8
    goto L_0x0049f2b8;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49f324(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f324);
    // 0049f324  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f325  833d849b590000         +cmp dword ptr [0x599b84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f32c  741d                   -je 0x49f34b
    if (cpu.flags.zf)
    {
        goto L_0x0049f34b;
    }
    // 0049f32e  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f335  7419                   -je 0x49f350
    if (cpu.flags.zf)
    {
        goto L_0x0049f350;
    }
    // 0049f337  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f339  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f33e  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f344  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f347  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f349  7505                   -jne 0x49f350
    if (!cpu.flags.zf)
    {
        goto L_0x0049f350;
    }
L_0x0049f34b:
    // 0049f34b  e810f4ffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
L_0x0049f350:
    // 0049f350  833dacb74d0000         +cmp dword ptr [0x4db7ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093292) /* 0x4db7ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f357  7521                   -jne 0x49f37a
    if (!cpu.flags.zf)
    {
        goto L_0x0049f37a;
    }
    // 0049f359  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049f35d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f35e  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049f362  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f363  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049f367  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f368  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f36d  ff1590f05600           -call dword ptr [0x56f090]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697680) /* 0x56f090 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f373  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049f376  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f377  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049f37a:
    // 0049f37a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f37b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f37c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f37d  68b0b74d00             -push 0x4db7b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5093296 /*0x4db7b0*/;
    cpu.esp -= 4;
    // 0049f382  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049f386  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f387  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049f38b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f38c  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049f390  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f391  a1acb74d00             -mov eax, dword ptr [0x4db7ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093292) /* 0x4db7ac */);
    // 0049f396  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f39b  8b1de4ef5600           -mov ebx, dword ptr [0x56efe4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5697508) /* 0x56efe4 */);
    // 0049f3a1  a3e4ef5600             -mov dword ptr [0x56efe4], eax
    app->getMemory<x86::reg32>(x86::reg32(5697508) /* 0x56efe4 */) = cpu.eax;
    // 0049f3a6  ff15a0f05600           -call dword ptr [0x56f0a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697696) /* 0x56f0a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f3ac  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049f3af  891de4ef5600           -mov dword ptr [0x56efe4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5697508) /* 0x56efe4 */) = cpu.ebx;
    // 0049f3b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f3b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f3b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f3b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f3b9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_49f3bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f3bc);
    // 0049f3bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f3bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f3be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f3bf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f3c0  81ec00080000           -sub esp, 0x800
    (cpu.esp) -= x86::reg32(x86::sreg32(2048 /*0x800*/));
    // 0049f3c6  8bbc2414080000         -mov edi, dword ptr [esp + 0x814]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2068) /* 0x814 */);
    // 0049f3cd  8bac2418080000         -mov ebp, dword ptr [esp + 0x818]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2072) /* 0x818 */);
    // 0049f3d4  8b9c241c080000         -mov ebx, dword ptr [esp + 0x81c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2076) /* 0x81c */);
    // 0049f3db  833d849b590000         +cmp dword ptr [0x599b84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f3e2  741d                   -je 0x49f401
    if (cpu.flags.zf)
    {
        goto L_0x0049f401;
    }
    // 0049f3e4  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f3eb  7419                   -je 0x49f406
    if (cpu.flags.zf)
    {
        goto L_0x0049f406;
    }
    // 0049f3ed  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f3ef  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f3f4  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f3fa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f3fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f3ff  7505                   -jne 0x49f406
    if (!cpu.flags.zf)
    {
        goto L_0x0049f406;
    }
L_0x0049f401:
    // 0049f401  e85af3ffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
L_0x0049f406:
    // 0049f406  800dc9ef560018         -or byte ptr [0x56efc9], 0x18
    app->getMemory<x86::reg8>(x86::reg32(5697481) /* 0x56efc9 */) |= x86::reg8(x86::sreg8(24 /*0x18*/));
    // 0049f40d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049f40f  0f84bd000000           -je 0x49f4d2
    if (cpu.flags.zf)
    {
        goto L_0x0049f4d2;
    }
L_0x0049f415:
    // 0049f415  81ff00010000           +cmp edi, 0x100
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f41b  0f8ec5000000           -jle 0x49f4e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f4e6;
    }
    // 0049f421  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x0049f426:
    // 0049f426  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f429  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f42c  66890424               -mov word ptr [esp], ax
    app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 0049f430  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049f432  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f435  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f438  6689442402             -mov word ptr [esp + 2], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 0049f43d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f43f  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f442  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f445  6689442404             -mov word ptr [esp + 4], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0049f44a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f44f  66894c2406             -mov word ptr [esp + 6], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.cx;
    // 0049f454  39c2                   +cmp edx, eax
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
    // 0049f456  7e5a                   -jle 0x49f4b2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f4b2;
    }
    // 0049f458  ba1f000000             -mov edx, 0x1f
    cpu.edx = 31 /*0x1f*/;
L_0x0049f45d:
    // 0049f45d  668b4cc4fc             -mov cx, word ptr [esp + eax*8 - 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 8);
    // 0049f462  66890cc4               -mov word ptr [esp + eax*8], cx
    app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 8) = cpu.cx;
    // 0049f466  668b4cc4fa             -mov cx, word ptr [esp + eax*8 - 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-6) /* -0x6 */ + cpu.eax * 8);
    // 0049f46b  66894cc402             -mov word ptr [esp + eax*8 + 2], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 8) = cpu.cx;
    // 0049f470  40                     -inc eax
    (cpu.eax)++;
    // 0049f471  668b0b                 -mov cx, word ptr [ebx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f474  66894cc4fc             -mov word ptr [esp + eax*8 - 4], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 8) = cpu.cx;
    // 0049f479  b91e000000             -mov ecx, 0x1e
    cpu.ecx = 30 /*0x1e*/;
    // 0049f47e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f481  66894cc4fe             -mov word ptr [esp + eax*8 - 2], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 8) = cpu.cx;
    // 0049f486  39f0                   +cmp eax, esi
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
    // 0049f488  7d28                   -jge 0x49f4b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f4b2;
    }
    // 0049f48a  668b4cc4f8             -mov cx, word ptr [esp + eax*8 - 8]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-8) /* -0x8 */ + cpu.eax * 8);
    // 0049f48f  66890cc4               -mov word ptr [esp + eax*8], cx
    app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 8) = cpu.cx;
    // 0049f493  668b4cc4fc             -mov cx, word ptr [esp + eax*8 - 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 8);
    // 0049f498  66894cc402             -mov word ptr [esp + eax*8 + 2], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 8) = cpu.cx;
    // 0049f49d  40                     -inc eax
    (cpu.eax)++;
    // 0049f49e  668b0b                 -mov cx, word ptr [ebx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f4a1  66894cc4fc             -mov word ptr [esp + eax*8 - 4], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 8) = cpu.cx;
    // 0049f4a6  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f4a9  668954c4fe             -mov word ptr [esp + eax*8 - 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 8) = cpu.dx;
    // 0049f4ae  39f0                   +cmp eax, esi
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
    // 0049f4b0  7cab                   -jl 0x49f45d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f45d;
    }
L_0x0049f4b2:
    // 0049f4b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f4b3  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f4b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f4b8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f4b9  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f4be  83eb08                 -sub ebx, 8
    (cpu.ebx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f4c1  ff1590f05600           -call dword ptr [0x56f090]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697680) /* 0x56f090 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f4c7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049f4ca  29f7                   +sub edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049f4cc  0f8543ffffff           -jne 0x49f415
    if (!cpu.flags.zf)
    {
        goto L_0x0049f415;
    }
L_0x0049f4d2:
    // 0049f4d2  8025c9ef5600e7         -and byte ptr [0x56efc9], 0xe7
    app->getMemory<x86::reg8>(x86::reg32(5697481) /* 0x56efc9 */) &= x86::reg8(x86::sreg8(231 /*0xe7*/));
    // 0049f4d9  81c400080000           +add esp, 0x800
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2048 /*0x800*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049f4df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f4e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f4e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f4e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f4e3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049f4e6:
    // 0049f4e6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049f4e8  e939ffffff             -jmp 0x49f426
    goto L_0x0049f426;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49f4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f4f0);
    // 0049f4f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f4f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f4f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f4f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f4f4  81ec00080000           -sub esp, 0x800
    (cpu.esp) -= x86::reg32(x86::sreg32(2048 /*0x800*/));
    // 0049f4fa  8bb42414080000         -mov esi, dword ptr [esp + 0x814]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2068) /* 0x814 */);
    // 0049f501  8b9c241c080000         -mov ebx, dword ptr [esp + 0x81c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2076) /* 0x81c */);
    // 0049f508  833d849b590000         +cmp dword ptr [0x599b84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f50f  741d                   -je 0x49f52e
    if (cpu.flags.zf)
    {
        goto L_0x0049f52e;
    }
    // 0049f511  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f518  7419                   -je 0x49f533
    if (cpu.flags.zf)
    {
        goto L_0x0049f533;
    }
    // 0049f51a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f51c  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f521  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f527  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f52a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f52c  7505                   -jne 0x49f533
    if (!cpu.flags.zf)
    {
        goto L_0x0049f533;
    }
L_0x0049f52e:
    // 0049f52e  e82df2ffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
L_0x0049f533:
    // 0049f533  800dc9ef560018         -or byte ptr [0x56efc9], 0x18
    app->getMemory<x86::reg8>(x86::reg32(5697481) /* 0x56efc9 */) |= x86::reg8(x86::sreg8(24 /*0x18*/));
    // 0049f53a  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f53d  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f540  66890424               -mov word ptr [esp], ax
    app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 0049f544  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f547  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f54a  6689442402             -mov word ptr [esp + 2], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 0049f54f  8b3da8b74d00           -mov edi, dword ptr [0x4db7a8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5093288) /* 0x4db7a8 */);
    // 0049f555  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f558  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f55b  6689442404             -mov word ptr [esp + 4], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0049f560  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049f562  0f848c000000           -je 0x49f5f4
    if (cpu.flags.zf)
    {
        goto L_0x0049f5f4;
    }
    // 0049f568  83fe1e                 +cmp esi, 0x1e
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f56b  0f8f83000000           -jg 0x49f5f4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049f5f4;
    }
    // 0049f571  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f573  48                     -dec eax
    (cpu.eax)--;
    // 0049f574  6689442406             -mov word ptr [esp + 6], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.ax;
L_0x0049f579:
    // 0049f579  83fe01                 +cmp esi, 1
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
    // 0049f57c  7e3e                   -jle 0x49f5bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f5bc;
    }
    // 0049f57e  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0049f583  bf1f000000             -mov edi, 0x1f
    cpu.edi = 31 /*0x1f*/;
    // 0049f588  8d0cf500000000         -lea ecx, [esi*8]
    cpu.ecx = x86::reg32(cpu.esi * 8);
L_0x0049f58f:
    // 0049f58f  668b5404f8             -mov dx, word ptr [esp + eax - 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1);
    // 0049f594  66891404               -mov word ptr [esp + eax], dx
    app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 1) = cpu.dx;
    // 0049f598  668b5404fc             -mov dx, word ptr [esp + eax - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0049f59d  6689540402             -mov word ptr [esp + eax + 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 1) = cpu.dx;
    // 0049f5a2  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f5a5  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f5a8  66895404fc             -mov word ptr [esp + eax - 4], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.dx;
    // 0049f5ad  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f5b0  66897c04fe             -mov word ptr [esp + eax - 2], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 1) = cpu.di;
    // 0049f5b5  39c8                   +cmp eax, ecx
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
    // 0049f5b7  7cd6                   -jl 0x49f58f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f58f;
    }
    // 0049f5b9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049f5bc:
    // 0049f5bc  8bac2418080000         -mov ebp, dword ptr [esp + 0x818]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2072) /* 0x818 */);
    // 0049f5c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f5c4  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f5c8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f5c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f5ca  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f5cf  ff1590f05600           -call dword ptr [0x56f090]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697680) /* 0x56f090 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f5d5  8a15c9ef5600           -mov dl, byte ptr [0x56efc9]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5697481) /* 0x56efc9 */);
    // 0049f5db  80e2e7                 -and dl, 0xe7
    cpu.dl &= x86::reg8(x86::sreg8(231 /*0xe7*/));
    // 0049f5de  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049f5e1  8815c9ef5600           -mov byte ptr [0x56efc9], dl
    app->getMemory<x86::reg8>(x86::reg32(5697481) /* 0x56efc9 */) = cpu.dl;
    // 0049f5e7  81c400080000           -add esp, 0x800
    (cpu.esp) += x86::reg32(x86::sreg32(2048 /*0x800*/));
    // 0049f5ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f5ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f5ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f5f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f5f1  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049f5f4:
    // 0049f5f4  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049f5f6  6689542406             -mov word ptr [esp + 6], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 0049f5fb  e979ffffff             -jmp 0x49f579
    goto L_0x0049f579;
}

/* align: skip  */
void Application::sub_49f600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f600);
    // 0049f600  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f601  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f602  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0049f605  a17cf04900             -mov eax, dword ptr [0x49f07c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4845692) /* 0x49f07c */);
    // 0049f60a  8b15849b5900           -mov edx, dword ptr [0x599b84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
    // 0049f610  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0049f614  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f616  7459                   -je 0x49f671
    if (cpu.flags.zf)
    {
        goto L_0x0049f671;
    }
    // 0049f618  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f61f  753c                   -jne 0x49f65d
    if (!cpu.flags.zf)
    {
        goto L_0x0049f65d;
    }
L_0x0049f621:
    // 0049f621  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0049f626  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0049f628  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049f62a  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049f62e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f62f  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049f633  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f635  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f636  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0049f63b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049f63d  8d7c242c               -lea edi, [esp + 0x2c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049f641  8b742460               -mov esi, dword ptr [esp + 0x60]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0049f645  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f64a  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f64c  ff159cf05600           -call dword ptr [0x56f09c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697692) /* 0x56f09c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f652  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049f655  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0049f658  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f659  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f65a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049f65d:
    // 0049f65d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f65f  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f664  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f66a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f66d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f66f  75b0                   -jne 0x49f621
    if (!cpu.flags.zf)
    {
        goto L_0x0049f621;
    }
L_0x0049f671:
    // 0049f671  e8eaf0ffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
    // 0049f676  eba9                   -jmp 0x49f621
    goto L_0x0049f621;
}

/* align: skip  */
void Application::sub_49f678(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f678);
    // 0049f678  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f679  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f67a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f67b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f67c  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049f682  8bb42414040000         -mov esi, dword ptr [esp + 0x414]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 0049f689  8bac2418040000         -mov ebp, dword ptr [esp + 0x418]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1048) /* 0x418 */);
    // 0049f690  8b9c241c040000         -mov ebx, dword ptr [esp + 0x41c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1052) /* 0x41c */);
    // 0049f697  833d849b590000         +cmp dword ptr [0x599b84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f69e  0f8476000000           -je 0x49f71a
    if (cpu.flags.zf)
    {
        goto L_0x0049f71a;
    }
    // 0049f6a4  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f6ab  7559                   -jne 0x49f706
    if (!cpu.flags.zf)
    {
        goto L_0x0049f706;
    }
L_0x0049f6ad:
    // 0049f6ad  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049f6af  0f8470000000           -je 0x49f725
    if (cpu.flags.zf)
    {
        goto L_0x0049f725;
    }
    // 0049f6b5  81fe00010000           +cmp esi, 0x100
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f6bb  7e64                   -jle 0x49f721
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f721;
    }
    // 0049f6bd  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x0049f6c2:
    // 0049f6c2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049f6c4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f6c6  7e25                   -jle 0x49f6ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f6ed;
    }
    // 0049f6c8  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 0049f6cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049f6d1:
    // 0049f6d1  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f6d4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f6d7  66891404               -mov word ptr [esp + eax], dx
    app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 1) = cpu.dx;
    // 0049f6db  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f6de  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f6e1  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f6e4  66895404fe             -mov word ptr [esp + eax - 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 1) = cpu.dx;
    // 0049f6e9  39c8                   +cmp eax, ecx
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
    // 0049f6eb  7ce4                   -jl 0x49f6d1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f6d1;
    }
L_0x0049f6ed:
    // 0049f6ed  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f6ee  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f6f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f6f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f6f4  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f6f9  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f6fb  ff159cf05600           -call dword ptr [0x56f09c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697692) /* 0x56f09c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f701  83c410                 +add esp, 0x10
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
    // 0049f704  eba7                   -jmp 0x49f6ad
    goto L_0x0049f6ad;
L_0x0049f706:
    // 0049f706  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f708  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f70d  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f713  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f716  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f718  7593                   -jne 0x49f6ad
    if (!cpu.flags.zf)
    {
        goto L_0x0049f6ad;
    }
L_0x0049f71a:
    // 0049f71a  e841f0ffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
    // 0049f71f  eb8c                   -jmp 0x49f6ad
    goto L_0x0049f6ad;
L_0x0049f721:
    // 0049f721  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049f723  eb9d                   -jmp 0x49f6c2
    goto L_0x0049f6c2;
L_0x0049f725:
    // 0049f725  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049f72b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f72c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f72d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f72e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f72f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_49f725(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f725);
    goto L_entry_0x0049f725;
    // 0049f678  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f679  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f67a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f67b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f67c  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049f682  8bb42414040000         -mov esi, dword ptr [esp + 0x414]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 0049f689  8bac2418040000         -mov ebp, dword ptr [esp + 0x418]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1048) /* 0x418 */);
    // 0049f690  8b9c241c040000         -mov ebx, dword ptr [esp + 0x41c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1052) /* 0x41c */);
    // 0049f697  833d849b590000         +cmp dword ptr [0x599b84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f69e  0f8476000000           -je 0x49f71a
    if (cpu.flags.zf)
    {
        goto L_0x0049f71a;
    }
    // 0049f6a4  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f6ab  7559                   -jne 0x49f706
    if (!cpu.flags.zf)
    {
        goto L_0x0049f706;
    }
L_0x0049f6ad:
    // 0049f6ad  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049f6af  0f8470000000           -je 0x49f725
    if (cpu.flags.zf)
    {
        goto L_0x0049f725;
    }
    // 0049f6b5  81fe00010000           +cmp esi, 0x100
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f6bb  7e64                   -jle 0x49f721
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f721;
    }
    // 0049f6bd  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x0049f6c2:
    // 0049f6c2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049f6c4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f6c6  7e25                   -jle 0x49f6ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f6ed;
    }
    // 0049f6c8  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 0049f6cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049f6d1:
    // 0049f6d1  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f6d4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f6d7  66891404               -mov word ptr [esp + eax], dx
    app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 1) = cpu.dx;
    // 0049f6db  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f6de  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f6e1  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f6e4  66895404fe             -mov word ptr [esp + eax - 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 1) = cpu.dx;
    // 0049f6e9  39c8                   +cmp eax, ecx
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
    // 0049f6eb  7ce4                   -jl 0x49f6d1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f6d1;
    }
L_0x0049f6ed:
    // 0049f6ed  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f6ee  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f6f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f6f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f6f4  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f6f9  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f6fb  ff159cf05600           -call dword ptr [0x56f09c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697692) /* 0x56f09c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f701  83c410                 +add esp, 0x10
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
    // 0049f704  eba7                   -jmp 0x49f6ad
    goto L_0x0049f6ad;
L_0x0049f706:
    // 0049f706  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f708  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f70d  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f713  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f716  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f718  7593                   -jne 0x49f6ad
    if (!cpu.flags.zf)
    {
        goto L_0x0049f6ad;
    }
L_0x0049f71a:
    // 0049f71a  e841f0ffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
    // 0049f71f  eb8c                   -jmp 0x49f6ad
    goto L_0x0049f6ad;
L_0x0049f721:
    // 0049f721  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049f723  eb9d                   -jmp 0x49f6c2
    goto L_0x0049f6c2;
L_0x0049f725:
L_entry_0x0049f725:
    // 0049f725  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049f72b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f72c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f72d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f72e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f72f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49f734(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f734);
    // 0049f734  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f735  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f736  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f737  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f738  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049f73e  8bb42414040000         -mov esi, dword ptr [esp + 0x414]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 0049f745  8bac2418040000         -mov ebp, dword ptr [esp + 0x418]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1048) /* 0x418 */);
    // 0049f74c  8b9c241c040000         -mov ebx, dword ptr [esp + 0x41c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1052) /* 0x41c */);
    // 0049f753  833d849b590000         +cmp dword ptr [0x599b84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f75a  0f8499000000           -je 0x49f7f9
    if (cpu.flags.zf)
    {
        goto L_0x0049f7f9;
    }
    // 0049f760  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f767  0f8574000000           -jne 0x49f7e1
    if (!cpu.flags.zf)
    {
        goto L_0x0049f7e1;
    }
L_0x0049f76d:
    // 0049f76d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049f76f  74b4                   -je 0x49f725
    if (cpu.flags.zf)
    {
        return sub_49f725(app, cpu);
    }
    // 0049f771  81fe00010000           +cmp esi, 0x100
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f777  0f8e86000000           -jle 0x49f803
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f803;
    }
    // 0049f77d  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x0049f782:
    // 0049f782  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f785  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f788  66890424               -mov word ptr [esp], ax
    app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 0049f78c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049f78e  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f791  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f794  6689442402             -mov word ptr [esp + 2], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 0049f799  83fa01                 +cmp edx, 1
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
    // 0049f79c  7e27                   -jle 0x49f7c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f7c5;
    }
    // 0049f79e  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049f7a3  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
L_0x0049f7aa:
    // 0049f7aa  668b5404fe             -mov dx, word ptr [esp + eax - 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 1);
    // 0049f7af  66891404               -mov word ptr [esp + eax], dx
    app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 1) = cpu.dx;
    // 0049f7b3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f7b6  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 0049f7b9  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f7bc  66895404fe             -mov word ptr [esp + eax - 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 1) = cpu.dx;
    // 0049f7c1  39c8                   +cmp eax, ecx
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
    // 0049f7c3  7ce5                   -jl 0x49f7aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f7aa;
    }
L_0x0049f7c5:
    // 0049f7c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f7c6  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f7ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f7cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f7cc  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f7d1  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f7d4  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f7d6  ff159cf05600           -call dword ptr [0x56f09c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697692) /* 0x56f09c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f7dc  83c410                 +add esp, 0x10
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
    // 0049f7df  eb8c                   -jmp 0x49f76d
    goto L_0x0049f76d;
L_0x0049f7e1:
    // 0049f7e1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f7e3  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f7e8  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f7ee  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f7f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f7f3  0f8574ffffff           -jne 0x49f76d
    if (!cpu.flags.zf)
    {
        goto L_0x0049f76d;
    }
L_0x0049f7f9:
    // 0049f7f9  e862efffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
    // 0049f7fe  e96affffff             -jmp 0x49f76d
    goto L_0x0049f76d;
L_0x0049f803:
    // 0049f803  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049f805  e978ffffff             -jmp 0x49f782
    goto L_0x0049f782;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49f80c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f80c);
    // 0049f80c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f80d  833d849b590000         +cmp dword ptr [0x599b84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f814  7436                   -je 0x49f84c
    if (cpu.flags.zf)
    {
        goto L_0x0049f84c;
    }
    // 0049f816  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f81d  7519                   -jne 0x49f838
    if (!cpu.flags.zf)
    {
        goto L_0x0049f838;
    }
L_0x0049f81f:
    // 0049f81f  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049f823  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f824  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049f826  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f82b  ff1598f05600           -call dword ptr [0x56f098]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697688) /* 0x56f098 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f831  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049f834  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f835  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049f838:
    // 0049f838  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f83a  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f83f  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f845  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f848  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f84a  75d3                   -jne 0x49f81f
    if (!cpu.flags.zf)
    {
        goto L_0x0049f81f;
    }
L_0x0049f84c:
    // 0049f84c  e80fefffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
    // 0049f851  ebcc                   -jmp 0x49f81f
    goto L_0x0049f81f;
}

/* align: skip 0x90 */
void Application::sub_49f854(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f854);
    // 0049f854  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f855  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f856  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f857  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049f85b  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049f85f  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049f863  833d849b590000         +cmp dword ptr [0x599b84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f86a  7429                   -je 0x49f895
    if (cpu.flags.zf)
    {
        goto L_0x0049f895;
    }
    // 0049f86c  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f873  750c                   -jne 0x49f881
    if (!cpu.flags.zf)
    {
        goto L_0x0049f881;
    }
L_0x0049f875:
    // 0049f875  4e                     -dec esi
    (cpu.esi)--;
    // 0049f876  83feff                 +cmp esi, -1
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
    // 0049f879  752b                   -jne 0x49f8a6
    if (!cpu.flags.zf)
    {
        goto L_0x0049f8a6;
    }
    // 0049f87b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f87c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f87d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f87e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049f881:
    // 0049f881  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f883  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f888  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f88e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f891  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f893  75e0                   -jne 0x49f875
    if (!cpu.flags.zf)
    {
        goto L_0x0049f875;
    }
L_0x0049f895:
    // 0049f895  e8c6eeffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
    // 0049f89a  4e                     -dec esi
    (cpu.esi)--;
    // 0049f89b  83feff                 +cmp esi, -1
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
    // 0049f89e  7506                   -jne 0x49f8a6
    if (!cpu.flags.zf)
    {
        goto L_0x0049f8a6;
    }
    // 0049f8a0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8a3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049f8a6:
    // 0049f8a6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049f8a8  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049f8ab  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049f8ad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f8ae  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049f8b0  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f8b5  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f8b8  ff1598f05600           -call dword ptr [0x56f098]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697688) /* 0x56f098 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f8be  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049f8c1  4e                     -dec esi
    (cpu.esi)--;
    // 0049f8c2  83feff                 +cmp esi, -1
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
    // 0049f8c5  75df                   -jne 0x49f8a6
    if (!cpu.flags.zf)
    {
        goto L_0x0049f8a6;
    }
    // 0049f8c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8ca  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49f8d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f8d0);
    // 0049f8d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f8d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f8d2  833d849b590000         +cmp dword ptr [0x599b84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872516) /* 0x599b84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f8d9  743a                   -je 0x49f915
    if (cpu.flags.zf)
    {
        goto L_0x0049f915;
    }
    // 0049f8db  833d809b590000         +cmp dword ptr [0x599b80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5872512) /* 0x599b80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f8e2  751d                   -jne 0x49f901
    if (!cpu.flags.zf)
    {
        goto L_0x0049f901;
    }
L_0x0049f8e4:
    // 0049f8e4  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049f8e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f8e9  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049f8ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f8ee  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f8f3  ff1598f05600           -call dword ptr [0x56f098]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697688) /* 0x56f098 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f8f9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049f8fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8fe  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049f901:
    // 0049f901  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049f903  68b0ef5600             -push 0x56efb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5697456 /*0x56efb0*/;
    cpu.esp -= 4;
    // 0049f908  ff158cf05600           -call dword ptr [0x56f08c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5697676) /* 0x56f08c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f90e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f911  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f913  75cf                   -jne 0x49f8e4
    if (!cpu.flags.zf)
    {
        goto L_0x0049f8e4;
    }
L_0x0049f915:
    // 0049f915  e846eeffff             -call 0x49e760
    cpu.esp -= 4;
    sub_49e760(app, cpu);
    if (cpu.terminate) return;
    // 0049f91a  ebc8                   -jmp 0x49f8e4
    goto L_0x0049f8e4;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_49f920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0049f920);
    // 0049f920  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f921  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f922  2eff15f8444c00         -call dword ptr cs:[0x4c44f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998392) /* 0x4c44f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f929  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f92a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f92b  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
