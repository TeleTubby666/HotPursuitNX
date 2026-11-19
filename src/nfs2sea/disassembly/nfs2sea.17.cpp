#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x8b 0xc0 */
void Application::sub_482fac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00482fac);
    // 00482fac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482fae  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00482fb0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482fb1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482fb3  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00482fb8  e873cc0100             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 00482fbd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482fbf  e810000000             -call 0x482fd4
    cpu.esp -= 4;
    sub_482fd4(app, cpu);
    if (cpu.terminate) return;
    // 00482fc4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482fc6  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00482fcb  e868cc0100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 00482fd0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482fd2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482fd3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482fd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00482fd4);
    // 00482fd4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482fd5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482fd6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482fd7  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00482fdc  3d00030000             +cmp eax, 0x300
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
    // 00482fe1  7456                   -je 0x483039
    if (cpu.flags.zf)
    {
        goto L_0x00483039;
    }
    // 00482fe3  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00482fe6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482fe8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00482feb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00482fed  be501b5600             -mov esi, 0x561b50
    cpu.esi = 5643088 /*0x561b50*/;
    // 00482ff2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00482ff5  8b1520904d00           -mov edx, dword ptr [0x4d9020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083168) /* 0x4d9020 */);
    // 00482ffb  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482ffd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482fff  7541                   -jne 0x483042
    if (!cpu.flags.zf)
    {
        goto L_0x00483042;
    }
L_0x00483001:
    // 00483001  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483002  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483003  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483004  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00483006  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00483009  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048300b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0048300e  8b7f20                 -mov edi, dword ptr [edi + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x00483011:
    // 00483011  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00483013  2b11                   -sub edx, dword ptr [ecx]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 00483015  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00483018  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048301b  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048301d  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048301f  39da                   +cmp edx, ebx
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
    // 00483021  7e02                   -jle 0x483025
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483025;
    }
    // 00483023  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00483025:
    // 00483025  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483027  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0048302a  39f8                   +cmp eax, edi
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
    // 0048302c  75e3                   -jne 0x483011
    if (!cpu.flags.zf)
    {
        goto L_0x00483011;
    }
    // 0048302e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00483030  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483031  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483032  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00483033:
    // 00483033  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483035  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483036  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483037  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483038  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483039:
    // 00483039  e8e2d20100             -call 0x4a0320
    cpu.esp -= 4;
    sub_4a0320(app, cpu);
    if (cpu.terminate) return;
    // 0048303e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483040  ebf1                   -jmp 0x483033
    goto L_0x00483033;
L_0x00483042:
    // 00483042  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00483044  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00483047  e86ccd0100             -call 0x49fdb8
    cpu.esp -= 4;
    sub_49fdb8(app, cpu);
    if (cpu.terminate) return;
    // 0048304c  ebb3                   -jmp 0x483001
    goto L_0x00483001;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483050);
    // 00483050  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483051  8b1508904d00           -mov edx, dword ptr [0x4d9008]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083144) /* 0x4d9008 */);
    // 00483057  81fa981b5600           +cmp edx, 0x561b98
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5643160 /*0x561b98*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048305d  741c                   -je 0x48307b
    if (cpu.flags.zf)
    {
        goto L_0x0048307b;
    }
    // 0048305f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00483061  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483063  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483065  7410                   -je 0x483077
    if (cpu.flags.zf)
    {
        goto L_0x00483077;
    }
L_0x00483067:
    // 00483067  f6401818               +test byte ptr [eax + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 0048306b  7503                   -jne 0x483070
    if (!cpu.flags.zf)
    {
        goto L_0x00483070;
    }
    // 0048306d  035010                 -add edx, dword ptr [eax + 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
L_0x00483070:
    // 00483070  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00483073  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483075  75f0                   -jne 0x483067
    if (!cpu.flags.zf)
    {
        goto L_0x00483067;
    }
L_0x00483077:
    // 00483077  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483079  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048307a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048307b:
    // 0048307b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048307d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048307e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483080);
    // 00483080  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483081  8b1508904d00           -mov edx, dword ptr [0x4d9008]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083144) /* 0x4d9008 */);
    // 00483087  81fa981b5600           +cmp edx, 0x561b98
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5643160 /*0x561b98*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048308d  741c                   -je 0x4830ab
    if (cpu.flags.zf)
    {
        goto L_0x004830ab;
    }
    // 0048308f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00483091  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483093  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483095  7410                   -je 0x4830a7
    if (cpu.flags.zf)
    {
        goto L_0x004830a7;
    }
L_0x00483097:
    // 00483097  f6401810               +test byte ptr [eax + 0x18], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 16 /*0x10*/));
    // 0048309b  7403                   -je 0x4830a0
    if (cpu.flags.zf)
    {
        goto L_0x004830a0;
    }
    // 0048309d  035010                 -add edx, dword ptr [eax + 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
L_0x004830a0:
    // 004830a0  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004830a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004830a5  75f0                   -jne 0x483097
    if (!cpu.flags.zf)
    {
        goto L_0x00483097;
    }
L_0x004830a7:
    // 004830a7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004830a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004830ab:
    // 004830ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004830ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4830b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004830b0);
    // 004830b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004830b1  8b1508904d00           -mov edx, dword ptr [0x4d9008]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083144) /* 0x4d9008 */);
    // 004830b7  81fa981b5600           +cmp edx, 0x561b98
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5643160 /*0x561b98*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004830bd  741c                   -je 0x4830db
    if (cpu.flags.zf)
    {
        goto L_0x004830db;
    }
    // 004830bf  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004830c1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004830c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004830c5  7410                   -je 0x4830d7
    if (cpu.flags.zf)
    {
        goto L_0x004830d7;
    }
L_0x004830c7:
    // 004830c7  f6401808               +test byte ptr [eax + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 004830cb  7403                   -je 0x4830d0
    if (cpu.flags.zf)
    {
        goto L_0x004830d0;
    }
    // 004830cd  035010                 -add edx, dword ptr [eax + 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
L_0x004830d0:
    // 004830d0  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004830d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004830d5  75f0                   -jne 0x4830c7
    if (!cpu.flags.zf)
    {
        goto L_0x004830c7;
    }
L_0x004830d7:
    // 004830d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004830d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004830db:
    // 004830db  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004830dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004830de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4830e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004830e0);
    // 004830e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004830e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004830e2  8b3508904d00           -mov esi, dword ptr [0x4d9008]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083144) /* 0x4d9008 */);
    // 004830e8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004830ea  81fe981b5600           +cmp esi, 0x561b98
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5643160 /*0x561b98*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004830f0  7420                   -je 0x483112
    if (cpu.flags.zf)
    {
        goto L_0x00483112;
    }
    // 004830f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004830f3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004830f4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004830f6  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
L_0x004830f9:
    // 004830f9  3b4604                 +cmp eax, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004830fc  7422                   -je 0x483120
    if (cpu.flags.zf)
    {
        goto L_0x00483120;
    }
    // 004830fe  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00483100  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00483103  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00483105  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00483107  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00483109  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048310b  01d9                   +add ecx, ebx
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
    // 0048310d  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00483110  ebe7                   -jmp 0x4830f9
    goto L_0x004830f9;
L_0x00483112:
    // 00483112  e809d20100             -call 0x4a0320
    cpu.esp -= 4;
    sub_4a0320(app, cpu);
    if (cpu.terminate) return;
    // 00483117  8b3508904d00           -mov esi, dword ptr [0x4d9008]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083144) /* 0x4d9008 */);
    // 0048311d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048311e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048311f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483120:
    // 00483120  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483122  893508904d00           -mov dword ptr [0x4d9008], esi
    app->getMemory<x86::reg32>(x86::reg32(5083144) /* 0x4d9008 */) = cpu.esi;
    // 00483128  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483129  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048312a  8b3508904d00           -mov esi, dword ptr [0x4d9008]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083144) /* 0x4d9008 */);
    // 00483130  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483131  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483132  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483134(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483134);
    // 00483134  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483135  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483136  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483137  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483139  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0048313f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00483141  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483143  81fa00030000           +cmp edx, 0x300
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483149  7450                   -je 0x48319b
    if (cpu.flags.zf)
    {
        goto L_0x0048319b;
    }
    // 0048314b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048314c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048314d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048314e  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00483151  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00483153  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00483156  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483158  bf501b5600             -mov edi, 0x561b50
    cpu.edi = 5643088 /*0x561b50*/;
    // 0048315d  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00483160  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00483162  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00483164  8b7704                 -mov esi, dword ptr [edi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00483167  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0048316a  39f1                   +cmp ecx, esi
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
    // 0048316c  7424                   -je 0x483192
    if (cpu.flags.zf)
    {
        goto L_0x00483192;
    }
L_0x0048316e:
    // 0048316e  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00483170  8b4910                 -mov ecx, dword ptr [ecx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00483173  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00483175  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00483177  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483179  8a4a18                 -mov cl, byte ptr [edx + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048317c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048317e  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00483181  7421                   -je 0x4831a4
    if (cpu.flags.zf)
    {
        goto L_0x004831a4;
    }
    // 00483183  034210                 -add eax, dword ptr [edx + 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)));
L_0x00483186:
    // 00483186  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00483188  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048318b  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0048318e  39e9                   +cmp ecx, ebp
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
    // 00483190  75dc                   -jne 0x48316e
    if (!cpu.flags.zf)
    {
        goto L_0x0048316e;
    }
L_0x00483192:
    // 00483192  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00483194  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483195  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483196  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483197  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483198  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483199  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048319a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048319b:
    // 0048319b  e880d10100             -call 0x4a0320
    cpu.esp -= 4;
    sub_4a0320(app, cpu);
    if (cpu.terminate) return;
    // 004831a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004831a4:
    // 004831a4  39d8                   +cmp eax, ebx
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
    // 004831a6  7e02                   -jle 0x4831aa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004831aa;
    }
    // 004831a8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004831aa:
    // 004831aa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004831ac  ebd8                   -jmp 0x483186
    goto L_0x00483186;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4831b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004831b0);
    // 004831b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004831b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004831b2  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004831b4  a3d41c5600             -mov dword ptr [0x561cd4], eax
    app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */) = cpu.eax;
    // 004831b9  49                     -dec ecx
    (cpu.ecx)--;
    // 004831ba  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004831bc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004831be  7e10                   -jle 0x4831d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004831d0;
    }
L_0x004831c0:
    // 004831c0  8d5828                 -lea ebx, [eax + 0x28]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004831c3  42                     -inc edx
    (cpu.edx)++;
    // 004831c4  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004831c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004831c9  39ca                   +cmp edx, ecx
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
    // 004831cb  7cf3                   -jl 0x4831c0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004831c0;
    }
    // 004831cd  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004831d0:
    // 004831d0  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004831d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4831dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004831dc);
    // 004831dc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004831dd  8b15d41c5600           -mov edx, dword ptr [0x561cd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */);
    // 004831e3  a3d41c5600             -mov dword ptr [0x561cd4], eax
    app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */) = cpu.eax;
    // 004831e8  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004831eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004831ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4831f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004831f0);
    // 004831f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004831f1  a1d41c5600             -mov eax, dword ptr [0x561cd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */);
    // 004831f6  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004831f9  8915d41c5600           -mov dword ptr [0x561cd4], edx
    app->getMemory<x86::reg32>(x86::reg32(5643476) /* 0x561cd4 */) = cpu.edx;
    // 004831ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483200  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483204(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483204);
    // 00483204  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483205  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048320a  e811fbffff             -call 0x482d20
    cpu.esp -= 4;
    sub_482d20(app, cpu);
    if (cpu.terminate) return;
    // 0048320f  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00483212  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483213  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483214(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483214);
    // 00483214  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00483217  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483218(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483218);
    // 00483218  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048321b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48321c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048321c);
    // 0048321c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048321f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483220);
    // 00483220  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483221  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483223  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00483228  e803ca0100             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 0048322d  806218ef               -and byte ptr [edx + 0x18], 0xef
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00483231  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00483236  e8fdc90100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 0048323b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048323c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483240);
    // 00483240  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483241  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483243  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00483248  e8e3c90100             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 0048324d  804a1810               -or byte ptr [edx + 0x18], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00483251  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00483256  e8ddc90100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 0048325b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048325c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483260);
    // 00483260  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483261  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00483263  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00483268  e8b3faffff             -call 0x482d20
    cpu.esp -= 4;
    sub_482d20(app, cpu);
    if (cpu.terminate) return;
    // 0048326d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048326f  e804000000             -call 0x483278
    cpu.esp -= 4;
    sub_483278(app, cpu);
    if (cpu.terminate) return;
    // 00483274  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483275  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483278(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483278);
    // 00483278  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483279  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048327b  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00483280  e8abc90100             -call 0x49fc30
    cpu.esp -= 4;
    sub_49fc30(app, cpu);
    if (cpu.terminate) return;
    // 00483285  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483287  e80c000000             -call 0x483298
    cpu.esp -= 4;
    sub_483298(app, cpu);
    if (cpu.terminate) return;
    // 0048328c  a1d01c5600             -mov eax, dword ptr [0x561cd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643472) /* 0x561cd0 */);
    // 00483291  e8a2c90100             -call 0x49fc38
    cpu.esp -= 4;
    sub_49fc38(app, cpu);
    if (cpu.terminate) return;
    // 00483296  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483297  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483298(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483298);
    // 00483298  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483299  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048329b  7405                   -je 0x4832a2
    if (cpu.flags.zf)
    {
        goto L_0x004832a2;
    }
    // 0048329d  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
L_0x004832a2:
    // 004832a2  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004832a5  80e5df                 -and ch, 0xdf
    cpu.ch &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 004832a8  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004832aa  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004832ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004832ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4832b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004832b0);
    // 004832b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004832b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004832b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004832b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004832b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004832b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004832b7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004832b9:
    // 004832b9  8b96541b5600           -mov edx, dword ptr [esi + 0x561b54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5643092) /* 0x561b54 */);
    // 004832bf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004832c1  7421                   -je 0x4832e4
    if (cpu.flags.zf)
    {
        goto L_0x004832e4;
    }
    // 004832c3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004832c5  8b86501b5600           -mov eax, dword ptr [esi + 0x561b50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5643088) /* 0x561b50 */);
L_0x004832cb:
    // 004832cb  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004832ce  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004832d0  39f9                   +cmp ecx, edi
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
    // 004832d2  7223                   -jb 0x4832f7
    if (cpu.flags.cf)
    {
        goto L_0x004832f7;
    }
    // 004832d4  8b6814                 -mov ebp, dword ptr [eax + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004832d7  8d142f                 -lea edx, [edi + ebp]
    cpu.edx = x86::reg32(cpu.edi + cpu.ebp * 1);
    // 004832da  39d1                   +cmp ecx, edx
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
    // 004832dc  7319                   -jae 0x4832f7
    if (!cpu.flags.cf)
    {
        goto L_0x004832f7;
    }
L_0x004832de:
    // 004832de  f6401980               +test byte ptr [eax + 0x19], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(25) /* 0x19 */) & 128 /*0x80*/));
    // 004832e2  740d                   -je 0x4832f1
    if (cpu.flags.zf)
    {
        goto L_0x004832f1;
    }
L_0x004832e4:
    // 004832e4  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004832e7  81fe80010000           +cmp esi, 0x180
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004832ed  7cca                   -jl 0x4832b9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004832b9;
    }
    // 004832ef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004832f1:
    // 004832f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004832f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004832f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004832f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004832f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004832f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004832f7:
    // 004832f7  39d8                   +cmp eax, ebx
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
    // 004832f9  75d0                   -jne 0x4832cb
    if (!cpu.flags.zf)
    {
        goto L_0x004832cb;
    }
    // 004832fb  ebe1                   -jmp 0x4832de
    goto L_0x004832de;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483300);
    // 00483300  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483301  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00483306  e8a5ffffff             -call 0x4832b0
    cpu.esp -= 4;
    sub_4832b0(app, cpu);
    if (cpu.terminate) return;
    // 0048330b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048330c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483310);
    // 00483310  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483311  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483313  e898ffffff             -call 0x4832b0
    cpu.esp -= 4;
    sub_4832b0(app, cpu);
    if (cpu.terminate) return;
    // 00483318  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483319  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_483360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483360);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00483360  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483361  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483362  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483363  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483365  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00483367  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483369  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048336b  7411                   -je 0x48337e
    if (cpu.flags.zf)
    {
        goto L_0x0048337e;
    }
    // 0048336d  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048336f:
    // 0048336f  48                     -dec eax
    (cpu.eax)--;
    // 00483370  83f8ff                 +cmp eax, -1
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
    // 00483373  7409                   -je 0x48337e
    if (cpu.flags.zf)
    {
        goto L_0x0048337e;
    }
    // 00483375  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483376  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 00483378  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483379  8857ff                 -mov byte ptr [edi - 1], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 0048337c  ebf1                   -jmp 0x48336f
    goto L_0x0048336f;
L_0x0048337e:
    // 0048337e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00483380  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00483382  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00483384  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 00483387  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00483389  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048338b  c1fd06                 -sar ebp, 6
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (6 /*0x6*/ % 32));
    // 0048338e  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00483391  83e303                 -and ebx, 3
    cpu.ebx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00483394  83fe0f                 +cmp esi, 0xf
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483397  0f87c6000000           -ja 0x483463
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00483463;
    }
    // 0048339d  ff24b520334800         -jmp dword ptr [esi*4 + 0x483320]
    cpu.ip = app->getMemory<x86::reg32>(4731680 + cpu.esi * 4); goto dynamic_jump;
  case 0x004833a4:
L_0x004833a4:
    // 004833a4  4d                     -dec ebp
    (cpu.ebp)--;
    // 004833a5  83fdff                 +cmp ebp, -1
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
    // 004833a8  0f84b5000000           -je 0x483463
    if (cpu.flags.zf)
    {
        goto L_0x00483463;
    }
    // 004833ae  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833b1  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004833b3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833b6  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004833b9:
    // 004833b9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833bc  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004833be  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833c1  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004833c4:
    // 004833c4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833c7  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004833c9  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833cc  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004833cf:
    // 004833cf  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833d2  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004833d4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833d7  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004833da:
    // 004833da  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833dd  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004833df  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833e2  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004833e5:
    // 004833e5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833e8  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004833ea  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833ed  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004833f0:
    // 004833f0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833f3  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004833f5  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833f8  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x004833fb:
    // 004833fb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004833fe  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00483400  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483403  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00483406:
    // 00483406  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483409  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048340b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048340e  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00483411:
    // 00483411  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483414  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00483416  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483419  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x0048341c:
    // 0048341c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048341f  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00483421  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483424  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00483427:
    // 00483427  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048342a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0048342c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048342f  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00483432:
    // 00483432  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483435  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00483437  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048343a  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x0048343d:
    // 0048343d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483440  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00483442  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483445  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00483448:
    // 00483448  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048344b  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0048344d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483450  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00483453:
    // 00483453  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483456  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00483458  83c204                 +add edx, 4
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
    // 0048345b  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0048345e  e941ffffff             -jmp 0x4833a4
    goto L_0x004833a4;
L_0x00483463:
    // 00483463  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00483465:
    // 00483465  4b                     -dec ebx
    (cpu.ebx)--;
    // 00483466  83fbff                 +cmp ebx, -1
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
    // 00483469  740d                   -je 0x483478
    if (cpu.flags.zf)
    {
        goto L_0x00483478;
    }
    // 0048346b  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 0048346e  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 00483471  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00483473  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00483474  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 00483476  ebed                   -jmp 0x483465
    goto L_0x00483465;
L_0x00483478:
    // 00483478  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483479  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048347a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048347b  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_48347c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048347c);
    // 0048347c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048347d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048347e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483480  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00483482  83fb04                 +cmp ebx, 4
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
    // 00483485  7d13                   -jge 0x48349a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048349a;
    }
L_0x00483487:
    // 00483487  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00483489  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x0048348b:
    // 0048348b  4b                     -dec ebx
    (cpu.ebx)--;
    // 0048348c  83fbff                 +cmp ebx, -1
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
    // 0048348f  742a                   -je 0x4834bb
    if (cpu.flags.zf)
    {
        goto L_0x004834bb;
    }
    // 00483491  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483492  8a48ff                 -mov cl, byte ptr [eax - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00483495  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483496  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 00483498  ebf1                   -jmp 0x48348b
    goto L_0x0048348b;
L_0x0048349a:
    // 0048349a  39c2                   +cmp edx, eax
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
    // 0048349c  7607                   -jbe 0x4834a5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004834a5;
    }
    // 0048349e  8d0c18                 -lea ecx, [eax + ebx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004834a1  39ca                   +cmp edx, ecx
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
    // 004834a3  72e2                   -jb 0x483487
    if (cpu.flags.cf)
    {
        goto L_0x00483487;
    }
L_0x004834a5:
    // 004834a5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004834a7  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 004834ac  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004834af  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004834b1  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004834b3  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004834b6  e8a5feffff             -call 0x483360
    cpu.esp -= 4;
    sub_483360(app, cpu);
    if (cpu.terminate) return;
L_0x004834bb:
    // 004834bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4834c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004834c0);
    // 004834c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004834c1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004834c3  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 004834c5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004834c7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004834c9  e8aeffffff             -call 0x48347c
    cpu.esp -= 4;
    sub_48347c(app, cpu);
    if (cpu.terminate) return;
    // 004834ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4834d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004834d0);
    // 004834d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004834d1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004834d3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004834d5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004834d7  e8a0ffffff             -call 0x48347c
    cpu.esp -= 4;
    sub_48347c(app, cpu);
    if (cpu.terminate) return;
    // 004834dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4834e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004834e0);
    // 004834e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004834e1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004834e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004834e5  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004834e7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004834e9  e88effffff             -call 0x48347c
    cpu.esp -= 4;
    sub_48347c(app, cpu);
    if (cpu.terminate) return;
    // 004834ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4834f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004834f0);
    // 004834f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004834f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004834f2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004834f4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004834f6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004834f8  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004834fb  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004834fd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004834ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483501  e876ffffff             -call 0x48347c
    cpu.esp -= 4;
    sub_48347c(app, cpu);
    if (cpu.terminate) return;
    // 00483506  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483507  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483508  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48350c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048350c);
    // 0048350c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048350d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048350f  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00483512  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483514  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483516  e861ffffff             -call 0x48347c
    cpu.esp -= 4;
    sub_48347c(app, cpu);
    if (cpu.terminate) return;
    // 0048351b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048351c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483520);
    // 00483520  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483521  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483522  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483523  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483524  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483526  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00483528  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048352a  b938904d00             -mov ecx, 0x4d9038
    cpu.ecx = 5083192 /*0x4d9038*/;
    // 0048352f  e8f8960100             -call 0x49cc2c
    cpu.esp -= 4;
    sub_49cc2c(app, cpu);
    if (cpu.terminate) return;
    // 00483534  6681660c00f0           -and word ptr [esi + 0xc], 0xf000
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) &= x86::reg16(x86::sreg16(61440 /*0xf000*/));
    // 0048353a  81e7ff0f0000           -and edi, 0xfff
    cpu.edi &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00483540  097e0c                 -or dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.edi));
    // 00483543  668b5e0e               -mov bx, word ptr [esi + 0xe]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 00483547  81e300f0ffff           -and ebx, 0xfffff000
    cpu.ebx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 0048354d  81e5ff0f0000           -and ebp, 0xfff
    cpu.ebp &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00483553  66895e0e               -mov word ptr [esi + 0xe], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */) = cpu.bx;
    // 00483557  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 0048355a  096e0c                 -or dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048355d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048355e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048355f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483560  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483561  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483564(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483564);
    // 00483564  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483565  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483566  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00483569  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048356c  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0048356f  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00483572  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00483575  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00483578  e8a3ffffff             -call 0x483520
    cpu.esp -= 4;
    sub_483520(app, cpu);
    if (cpu.terminate) return;
    // 0048357d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048357e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048357f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483580);
    // 00483580  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483581  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00483584  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00483587  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483589  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0048358c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048358f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483591  e88affffff             -call 0x483520
    cpu.esp -= 4;
    sub_483520(app, cpu);
    if (cpu.terminate) return;
    // 00483596  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483597  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483598(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483598);
    // 00483598  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483599  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048359a  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048359d  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004835a0  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004835a3  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004835a6  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004835a9  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004835ac  e86fffffff             -call 0x483520
    cpu.esp -= 4;
    sub_483520(app, cpu);
    if (cpu.terminate) return;
    // 004835b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004835b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004835b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4835b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004835b4);
    // 004835b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004835b5  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004835b8  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004835bb  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004835bd  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004835c0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004835c3  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004835c5  e856ffffff             -call 0x483520
    cpu.esp -= 4;
    sub_483520(app, cpu);
    if (cpu.terminate) return;
    // 004835ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004835cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4835d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004835d0);
    // 004835d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004835d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004835d3  803d38b84d0000         +cmp byte ptr [0x4db838], 0
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
    // 004835da  7507                   -jne 0x4835e3
    if (!cpu.flags.zf)
    {
        goto L_0x004835e3;
    }
    // 004835dc  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004835e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004835e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004835e3:
    // 004835e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004835e5  e89a110000             -call 0x484784
    cpu.esp -= 4;
    sub_484784(app, cpu);
    if (cpu.terminate) return;
    // 004835ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004835ec  751c                   -jne 0x48360a
    if (!cpu.flags.zf)
    {
        goto L_0x0048360a;
    }
    // 004835ee  8b04d5f0a15900         -mov eax, dword ptr [edx*8 + 0x59a1f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */ + cpu.edx * 8);
    // 004835f5  8138424e4b6c           +cmp dword ptr [eax], 0x6c4b4e42
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816874562 /*0x6c4b4e42*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004835fb  7519                   -jne 0x483616
    if (!cpu.flags.zf)
    {
        goto L_0x00483616;
    }
    // 004835fd  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483601  770e                   -ja 0x483611
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00483611;
    }
    // 00483603  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 00483608  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483609  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048360a:
    // 0048360a  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048360f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483610  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483611:
    // 00483611  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00483614  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483615  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483616:
    // 00483616  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0048361b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048361c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483620);
    // 00483620  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483621  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483623  803d38b84d0000         +cmp byte ptr [0x4db838], 0
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
    // 0048362a  7507                   -jne 0x483633
    if (!cpu.flags.zf)
    {
        goto L_0x00483633;
    }
    // 0048362c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00483631  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483632  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483633:
    // 00483633  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483635  e84a110000             -call 0x484784
    cpu.esp -= 4;
    sub_484784(app, cpu);
    if (cpu.terminate) return;
    // 0048363a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048363c  752d                   -jne 0x48366b
    if (!cpu.flags.zf)
    {
        goto L_0x0048366b;
    }
    // 0048363e  8b04cdf0a15900         -mov eax, dword ptr [ecx*8 + 0x59a1f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */ + cpu.ecx * 8);
    // 00483645  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483649  7627                   -jbe 0x483672
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00483672;
    }
    // 0048364b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048364d  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00483651  39ca                   +cmp edx, ecx
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
    // 00483653  7d16                   -jge 0x48366b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048366b;
    }
    // 00483655  8b44900c               -mov eax, dword ptr [eax + edx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.edx * 4);
    // 00483659  6681385054             +cmp word ptr [eax], 0x5450
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0048365e  7520                   -jne 0x483680
    if (!cpu.flags.zf)
    {
        goto L_0x00483680;
    }
    // 00483660  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 00483664  7413                   -je 0x483679
    if (cpu.flags.zf)
    {
        goto L_0x00483679;
    }
    // 00483666  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00483669  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048366a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048366b:
    // 0048366b  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00483670  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483671  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483672:
    // 00483672  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 00483677  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483678  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483679:
    // 00483679  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
    // 0048367e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048367f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483680:
    // 00483680  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00483685  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483686  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483688(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483688);
    // 00483688  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483689  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048368a  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048368d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048368f  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00483693  8a2538b84d00           -mov ah, byte ptr [0x4db838]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
    // 00483699  bd80000000             -mov ebp, 0x80
    cpu.ebp = 128 /*0x80*/;
    // 0048369e  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004836a0  740f                   -je 0x4836b1
    if (cpu.flags.zf)
    {
        goto L_0x004836b1;
    }
    // 004836a2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004836a4  7512                   -jne 0x4836b8
    if (!cpu.flags.zf)
    {
        goto L_0x004836b8;
    }
    // 004836a6  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x004836ab:
    // 004836ab  83c410                 +add esp, 0x10
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
    // 004836ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004836af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004836b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004836b1:
    // 004836b1  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004836b6  ebf3                   -jmp 0x4836ab
    goto L_0x004836ab;
L_0x004836b8:
    // 004836b8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004836ba  e811ffffff             -call 0x4835d0
    cpu.esp -= 4;
    sub_4835d0(app, cpu);
    if (cpu.terminate) return;
    // 004836bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004836c1  7ce8                   -jl 0x4836ab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004836ab;
    }
    // 004836c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004836c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004836c5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004836c6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004836c8  8b14d5f0a15900         -mov edx, dword ptr [edx*8 + 0x59a1f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */ + cpu.edx * 8);
    // 004836cf  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004836d3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004836d5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004836d9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004836db  e820640000             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004836e0  8b14cdf0a15900         -mov edx, dword ptr [ecx*8 + 0x59a1f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */ + cpu.ecx * 8);
    // 004836e7  807a0401               +cmp byte ptr [edx + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004836eb  7204                   -jb 0x4836f1
    if (cpu.flags.cf)
    {
        goto L_0x004836f1;
    }
    // 004836ed  0fb76a06               -movzx ebp, word ptr [edx + 6]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */));
L_0x004836f1:
    // 004836f1  807a0402               +cmp byte ptr [edx + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004836f5  7248                   -jb 0x48373f
    if (cpu.flags.cf)
    {
        goto L_0x0048373f;
    }
    // 004836f7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004836f9  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
L_0x004836fd:
    // 004836fd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004836ff  7e28                   -jle 0x483729
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483729;
    }
    // 00483701  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 00483704  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00483706:
    // 00483706  807a0402               +cmp byte ptr [edx + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048370a  7239                   -jb 0x483745
    if (cpu.flags.cf)
    {
        goto L_0x00483745;
    }
    // 0048370c  8d0c07                 -lea ecx, [edi + eax]
    cpu.ecx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0048370f  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00483712  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00483714  740c                   -je 0x483722
    if (cpu.flags.zf)
    {
        goto L_0x00483722;
    }
    // 00483716  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00483718  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048371c  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048371e  894c030c               -mov dword ptr [ebx + eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.ecx;
L_0x00483722:
    // 00483722  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483725  39e8                   +cmp eax, ebp
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
    // 00483727  7cdd                   -jl 0x483706
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483706;
    }
L_0x00483729:
    // 00483729  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048372d  8934c5f0a15900         -mov dword ptr [eax*8 + 0x59a1f0], esi
    app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */ + cpu.eax * 8) = cpu.esi;
    // 00483734  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483736  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483737  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483738  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483739  83c410                 +add esp, 0x10
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
    // 0048373c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048373d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048373e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048373f:
    // 0048373f  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00483743  ebb8                   -jmp 0x4836fd
    goto L_0x004836fd;
L_0x00483745:
    // 00483745  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00483748  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048374b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048374d  74d3                   -je 0x483722
    if (cpu.flags.zf)
    {
        goto L_0x00483722;
    }
    // 0048374f  29d1                   +sub ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00483751  8d1c0e                 -lea ebx, [esi + ecx]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 00483754  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00483758  895c0108               -mov dword ptr [ecx + eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.eax * 1) = cpu.ebx;
    // 0048375c  ebc4                   -jmp 0x483722
    goto L_0x00483722;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483760);
    // 00483760  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483762  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483764  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00483766  803d38b84d0000         +cmp byte ptr [0x4db838], 0
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
    // 0048376d  740c                   -je 0x48377b
    if (cpu.flags.zf)
    {
        goto L_0x0048377b;
    }
    // 0048376f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00483771  7510                   -jne 0x483783
    if (!cpu.flags.zf)
    {
        goto L_0x00483783;
    }
    // 00483773  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x00483778:
    // 00483778  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483779  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048377a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048377b:
    // 0048377b  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00483780  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483781  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483782  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483783:
    // 00483783  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00483785  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483787  e894feffff             -call 0x483620
    cpu.esp -= 4;
    sub_483620(app, cpu);
    if (cpu.terminate) return;
    // 0048378c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048378e  7ce8                   -jl 0x483778
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483778;
    }
    // 00483790  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483791  8b3cf5f0a15900         -mov edi, dword ptr [esi*8 + 0x59a1f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */ + cpu.esi * 8);
    // 00483798  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0048379b  8a5704                 -mov dl, byte ptr [edi + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048379e  8d341f                 -lea esi, [edi + ebx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 004837a1  80fa01                 +cmp dl, 1
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004837a4  7517                   -jne 0x4837bd
    if (!cpu.flags.zf)
    {
        goto L_0x004837bd;
    }
    // 004837a6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004837a8  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004837ab  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004837ad  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004837af  e84c630000             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004837b4  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004837b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004837b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004837bd:
    // 004837bd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004837bf  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004837c2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004837c4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004837c6  e835630000             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004837cb  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004837ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004837d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4837d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004837d4);
    // 004837d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004837d5  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004837d7  e810100000             -call 0x4847ec
    cpu.esp -= 4;
    sub_4847ec(app, cpu);
    if (cpu.terminate) return;
    // 004837dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4837e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004837e0);
    // 004837e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004837e1  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004837e3  e828cd0100             -call 0x4a0510
    cpu.esp -= 4;
    sub_4a0510(app, cpu);
    if (cpu.terminate) return;
    // 004837e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4837f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004837f0);
    // 004837f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004837f2  7506                   -jne 0x4837fa
    if (!cpu.flags.zf)
    {
        goto L_0x004837fa;
    }
    // 004837f4  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004837f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004837fa:
    // 004837fa  c700ffffffff           -mov dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) = 4294967295 /*0xffffffff*/;
    // 00483800  c64004ff               -mov byte ptr [eax + 4], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = 255 /*0xff*/;
    // 00483804  c640053c               -mov byte ptr [eax + 5], 0x3c
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = 60 /*0x3c*/;
    // 00483808  c640067f               -mov byte ptr [eax + 6], 0x7f
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 127 /*0x7f*/;
    // 0048380c  c6400740               -mov byte ptr [eax + 7], 0x40
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 64 /*0x40*/;
    // 00483810  c640087f               -mov byte ptr [eax + 8], 0x7f
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
    // 00483814  c6400940               -mov byte ptr [eax + 9], 0x40
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */) = 64 /*0x40*/;
    // 00483818  c6400a7f               -mov byte ptr [eax + 0xa], 0x7f
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */) = 127 /*0x7f*/;
    // 0048381c  c6400b00               -mov byte ptr [eax + 0xb], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */) = 0 /*0x0*/;
    // 00483820  66c7400c0000           -mov word ptr [eax + 0xc], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00483826  66c7400e0000           -mov word ptr [eax + 0xe], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 0048382c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048382e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483830);
    // 00483830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483832  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483833  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483835  8a2538b84d00           -mov ah, byte ptr [0x4db838]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
    // 0048383b  b980000000             -mov ecx, 0x80
    cpu.ecx = 128 /*0x80*/;
    // 00483840  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00483842  740d                   -je 0x483851
    if (cpu.flags.zf)
    {
        goto L_0x00483851;
    }
    // 00483844  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483846  7512                   -jne 0x48385a
    if (!cpu.flags.zf)
    {
        goto L_0x0048385a;
    }
L_0x00483848:
    // 00483848  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048384d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048384e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048384f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483850  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483851:
    // 00483851  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00483856  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483857  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483858  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483859  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048385a:
    // 0048385a  8b4201                 -mov eax, dword ptr [edx + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0048385d  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00483860  e81f0f0000             -call 0x484784
    cpu.esp -= 4;
    sub_484784(app, cpu);
    if (cpu.terminate) return;
    // 00483865  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483867  7cdf                   -jl 0x483848
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483848;
    }
    // 00483869  8b4201                 -mov eax, dword ptr [edx + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0048386c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0048386f  8b04c5f0a15900         -mov eax, dword ptr [eax*8 + 0x59a1f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */ + cpu.eax * 8);
    // 00483876  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048387a  7206                   -jb 0x483882
    if (cpu.flags.cf)
    {
        goto L_0x00483882;
    }
    // 0048387c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048387e  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
L_0x00483882:
    // 00483882  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00483884  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483886  7cc0                   -jl 0x483848
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483848;
    }
    // 00483888  39d9                   +cmp ecx, ebx
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
    // 0048388a  7ebc                   -jle 0x483848
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483848;
    }
    // 0048388c  80780402               +cmp byte ptr [eax + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483890  720f                   -jb 0x4838a1
    if (cpu.flags.cf)
    {
        goto L_0x004838a1;
    }
    // 00483892  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00483894  8b44880c               -mov eax, dword ptr [eax + ecx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.ecx * 4);
    // 00483898  e8d3d20100             -call 0x4a0b70
    cpu.esp -= 4;
    sub_4a0b70(app, cpu);
    if (cpu.terminate) return;
    // 0048389d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048389e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048389f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004838a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004838a1:
    // 004838a1  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004838a3  8b448808               -mov eax, dword ptr [eax + ecx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    // 004838a7  e8c4d20100             -call 0x4a0b70
    cpu.esp -= 4;
    sub_4a0b70(app, cpu);
    if (cpu.terminate) return;
    // 004838ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004838ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004838ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004838af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4838b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004838b0);
    // 004838b0  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 004838b3  7507                   -jne 0x4838bc
    if (!cpu.flags.zf)
    {
        goto L_0x004838bc;
    }
    // 004838b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004838ba  c3                     -ret 
    cpu.esp += 4;
    return;
    // 004838bb  90                     -nop 
    ;
L_0x004838bc:
    // 004838bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004838be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4838bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004838bc);
    goto L_entry_0x004838bc;
    // 004838b0  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 004838b3  7507                   -jne 0x4838bc
    if (!cpu.flags.zf)
    {
        goto L_0x004838bc;
    }
    // 004838b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004838ba  c3                     -ret 
    cpu.esp += 4;
    return;
    // 004838bb  90                     -nop 
    ;
L_0x004838bc:
L_entry_0x004838bc:
    // 004838bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004838be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4838c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004838c0);
    // 004838c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004838c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004838c2  8b15e01c5600           -mov edx, dword ptr [0x561ce0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004838c8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004838ca  7434                   -je 0x483900
    if (cpu.flags.zf)
    {
        goto L_0x00483900;
    }
    // 004838cc  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004838cf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004838d1  7407                   -je 0x4838da
    if (cpu.flags.zf)
    {
        goto L_0x004838da;
    }
    // 004838d3  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
L_0x004838da:
    // 004838da  8b15e01c5600           -mov edx, dword ptr [0x561ce0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004838e0  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004838e2  b8e41c5600             -mov eax, 0x561ce4
    cpu.eax = 5643492 /*0x561ce4*/;
    // 004838e7  e8a4490000             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 004838ec  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004838ee:
    // 004838ee  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004838f3  3b10                   +cmp edx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004838f5  7409                   -je 0x483900
    if (cpu.flags.zf)
    {
        goto L_0x00483900;
    }
    // 004838f7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004838f9  7405                   -je 0x483900
    if (cpu.flags.zf)
    {
        goto L_0x00483900;
    }
    // 004838fb  3b4818                 +cmp ecx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004838fe  7403                   -je 0x483903
    if (cpu.flags.zf)
    {
        goto L_0x00483903;
    }
L_0x00483900:
    // 00483900  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483901  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483902  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483903:
    // 00483903  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483905  e802470000             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 0048390a  ebe2                   -jmp 0x4838ee
    goto L_0x004838ee;
}

/* align: skip  */
void Application::sub_48390c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048390c);
    // 0048390c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048390d  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483912  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00483915  e8f2570000             -call 0x48910c
    cpu.esp -= 4;
    sub_48910c(app, cpu);
    if (cpu.terminate) return;
    // 0048391a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048391c  7707                   -ja 0x483925
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00483925;
    }
L_0x0048391e:
    // 0048391e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483920  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483921  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00483924  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483925:
    // 00483925  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 0048392a  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0048392d  e8ce560000             -call 0x489000
    cpu.esp -= 4;
    sub_489000(app, cpu);
    if (cpu.terminate) return;
    // 00483932  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483934  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483936  74e6                   -je 0x48391e
    if (cpu.flags.zf)
    {
        goto L_0x0048391e;
    }
L_0x00483938:
    // 00483938  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0048393b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048393d  740a                   -je 0x483949
    if (cpu.flags.zf)
    {
        goto L_0x00483949;
    }
    // 0048393f  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483944  3b5014                 +cmp edx, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483947  752c                   -jne 0x483975
    if (!cpu.flags.zf)
    {
        goto L_0x00483975;
    }
L_0x00483949:
    // 00483949  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 0048394e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00483950  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x00483953:
    // 00483953  e8e8550000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00483958  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048395b  ff5124                 -call dword ptr [ecx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048395e  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483963  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00483966  e895560000             -call 0x489000
    cpu.esp -= 4;
    sub_489000(app, cpu);
    if (cpu.terminate) return;
    // 0048396b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048396d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048396f  75c7                   -jne 0x483938
    if (!cpu.flags.zf)
    {
        goto L_0x00483938;
    }
    // 00483971  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483973  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483974  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483975:
    // 00483975  83c038                 +add eax, 0x38
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00483978  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048397a  ebd7                   -jmp 0x483953
    goto L_0x00483953;
}

/* align: skip  */
void Application::sub_48397c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048397c);
    // 0048397c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048397d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048397e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483980  8b15e01c5600           -mov edx, dword ptr [0x561ce0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483986  8d3400                 -lea esi, [eax + eax]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00483989  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048398b  0f85dc000000           -jne 0x483a6d
    if (!cpu.flags.zf)
    {
        goto L_0x00483a6d;
    }
L_0x00483991:
    // 00483991  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00483998  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048399a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048399d  8d888c000000           -lea ecx, [eax + 0x8c]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 004839a3  b828d94c00             -mov eax, 0x4cd928
    cpu.eax = 5036328 /*0x4cd928*/;
    // 004839a8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004839aa  e859efffff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 004839af  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004839b1  a3e01c5600             -mov dword ptr [0x561ce0], eax
    app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */) = cpu.eax;
    // 004839b6  e8d14a0000             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 004839bb  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004839c0  e897f3ffff             -call 0x482d5c
    cpu.esp -= 4;
    sub_482d5c(app, cpu);
    if (cpu.terminate) return;
    // 004839c5  8b0de01c5600           -mov ecx, dword ptr [0x561ce0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004839cb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004839cd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004839cf  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004839d2  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004839d5  e812550000             -call 0x488eec
    cpu.esp -= 4;
    sub_488eec(app, cpu);
    if (cpu.terminate) return;
    // 004839da  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004839df  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004839e1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004839e3  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004839e6  e801550000             -call 0x488eec
    cpu.esp -= 4;
    sub_488eec(app, cpu);
    if (cpu.terminate) return;
    // 004839eb  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004839f0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004839f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004839f4  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004839f7  e8f0540000             -call 0x488eec
    cpu.esp -= 4;
    sub_488eec(app, cpu);
    if (cpu.terminate) return;
    // 004839fc  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483a01  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00483a03  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483a05  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00483a08  e8df540000             -call 0x488eec
    cpu.esp -= 4;
    sub_488eec(app, cpu);
    if (cpu.terminate) return;
    // 00483a0d  8b0de01c5600           -mov ecx, dword ptr [0x561ce0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483a13  81c18c000000           -add ecx, 0x8c
    (cpu.ecx) += x86::reg32(x86::sreg32(140 /*0x8c*/));
L_0x00483a19:
    // 00483a19  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483a1e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00483a20  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00483a23  e818550000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00483a28  83c128                 +add ecx, 0x28
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
    // 00483a2b  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483a2c  75eb                   -jne 0x483a19
    if (!cpu.flags.zf)
    {
        goto L_0x00483a19;
    }
    // 00483a2e  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00483a33  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00483a38  b80c394800             -mov eax, 0x48390c
    cpu.eax = 4733196 /*0x48390c*/;
    // 00483a3d  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00483a42  e8f9e7ffff             -call 0x482240
    cpu.esp -= 4;
    sub_482240(app, cpu);
    if (cpu.terminate) return;
    // 00483a47  68e41c5600             -push 0x561ce4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5643492 /*0x561ce4*/;
    cpu.esp -= 4;
    // 00483a4c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00483a51  b8a8404800             -mov eax, 0x4840a8
    cpu.eax = 4735144 /*0x4840a8*/;
    // 00483a56  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483a58  e8f3440000             -call 0x487f50
    cpu.esp -= 4;
    sub_487f50(app, cpu);
    if (cpu.terminate) return;
    // 00483a5d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483a5f  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483a64  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00483a66  39d9                   +cmp ecx, ebx
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
    // 00483a68  740d                   -je 0x483a77
    if (cpu.flags.zf)
    {
        goto L_0x00483a77;
    }
    // 00483a6a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a6c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483a6d:
    // 00483a6d  e81a000000             -call 0x483a8c
    cpu.esp -= 4;
    sub_483a8c(app, cpu);
    if (cpu.terminate) return;
    // 00483a72  e91affffff             -jmp 0x483991
    goto L_0x00483991;
L_0x00483a77:
    // 00483a77  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00483a79  e88e450000             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 00483a7e  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483a83  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00483a85  39d9                   +cmp ecx, ebx
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
    // 00483a87  74ee                   -je 0x483a77
    if (cpu.flags.zf)
    {
        goto L_0x00483a77;
    }
    // 00483a89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a8b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483a8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483a8c);
    // 00483a8c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483a8d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483a8e  8b15e01c5600           -mov edx, dword ptr [0x561ce0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483a94  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483a96  7503                   -jne 0x483a9b
    if (!cpu.flags.zf)
    {
        goto L_0x00483a9b;
    }
    // 00483a98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483a9b:
    // 00483a9b  c7420401000000         -mov dword ptr [edx + 4], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00483aa2  e819feffff             -call 0x4838c0
    cpu.esp -= 4;
    sub_4838c0(app, cpu);
    if (cpu.terminate) return;
    // 00483aa7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00483aa9:
    // 00483aa9  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483aae  3b10                   +cmp edx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483ab0  7409                   -je 0x483abb
    if (cpu.flags.zf)
    {
        goto L_0x00483abb;
    }
    // 00483ab2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483ab4  e853450000             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 00483ab9  ebee                   -jmp 0x483aa9
    goto L_0x00483aa9;
L_0x00483abb:
    // 00483abb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483abc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483abd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483abe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483abf  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00483ac2  e8f5540000             -call 0x488fbc
    cpu.esp -= 4;
    sub_488fbc(app, cpu);
    if (cpu.terminate) return;
    // 00483ac7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483ac9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483acb  743c                   -je 0x483b09
    if (cpu.flags.zf)
    {
        goto L_0x00483b09;
    }
L_0x00483acd:
    // 00483acd  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00483ad0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483ad2  7407                   -je 0x483adb
    if (cpu.flags.zf)
    {
        goto L_0x00483adb;
    }
    // 00483ad4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00483ad6  e891f2ffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
L_0x00483adb:
    // 00483adb  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00483ade  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00483ae0  7407                   -je 0x483ae9
    if (cpu.flags.zf)
    {
        goto L_0x00483ae9;
    }
    // 00483ae2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483ae4  e8aff2ffff             -call 0x482d98
    cpu.esp -= 4;
    sub_482d98(app, cpu);
    if (cpu.terminate) return;
L_0x00483ae9:
    // 00483ae9  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483aee  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00483af1  e84a540000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00483af6  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483afb  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00483afe  e8b9540000             -call 0x488fbc
    cpu.esp -= 4;
    sub_488fbc(app, cpu);
    if (cpu.terminate) return;
    // 00483b03  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483b05  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483b07  75c4                   -jne 0x483acd
    if (!cpu.flags.zf)
    {
        goto L_0x00483acd;
    }
L_0x00483b09:
    // 00483b09  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483b0e  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00483b11  e8a6540000             -call 0x488fbc
    cpu.esp -= 4;
    sub_488fbc(app, cpu);
    if (cpu.terminate) return;
    // 00483b16  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483b18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483b1a  743c                   -je 0x483b58
    if (cpu.flags.zf)
    {
        goto L_0x00483b58;
    }
L_0x00483b1c:
    // 00483b1c  8b7a1c                 -mov edi, dword ptr [edx + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00483b1f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00483b21  7407                   -je 0x483b2a
    if (cpu.flags.zf)
    {
        goto L_0x00483b2a;
    }
    // 00483b23  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00483b25  e842f2ffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
L_0x00483b2a:
    // 00483b2a  8b6a18                 -mov ebp, dword ptr [edx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00483b2d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00483b2f  7407                   -je 0x483b38
    if (cpu.flags.zf)
    {
        goto L_0x00483b38;
    }
    // 00483b31  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00483b33  e860f2ffff             -call 0x482d98
    cpu.esp -= 4;
    sub_482d98(app, cpu);
    if (cpu.terminate) return;
L_0x00483b38:
    // 00483b38  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483b3d  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00483b40  e8fb530000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00483b45  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483b4a  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00483b4d  e86a540000             -call 0x488fbc
    cpu.esp -= 4;
    sub_488fbc(app, cpu);
    if (cpu.terminate) return;
    // 00483b52  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483b54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483b56  75c4                   -jne 0x483b1c
    if (!cpu.flags.zf)
    {
        goto L_0x00483b1c;
    }
L_0x00483b58:
    // 00483b58  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483b5d  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00483b60  e857540000             -call 0x488fbc
    cpu.esp -= 4;
    sub_488fbc(app, cpu);
    if (cpu.terminate) return;
    // 00483b65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483b67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483b69  743c                   -je 0x483ba7
    if (cpu.flags.zf)
    {
        goto L_0x00483ba7;
    }
L_0x00483b6b:
    // 00483b6b  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00483b6e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483b70  7407                   -je 0x483b79
    if (cpu.flags.zf)
    {
        goto L_0x00483b79;
    }
    // 00483b72  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00483b74  e8f3f1ffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
L_0x00483b79:
    // 00483b79  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00483b7c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00483b7e  7407                   -je 0x483b87
    if (cpu.flags.zf)
    {
        goto L_0x00483b87;
    }
    // 00483b80  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483b82  e811f2ffff             -call 0x482d98
    cpu.esp -= 4;
    sub_482d98(app, cpu);
    if (cpu.terminate) return;
L_0x00483b87:
    // 00483b87  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483b8c  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00483b8f  e8ac530000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00483b94  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483b99  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00483b9c  e81b540000             -call 0x488fbc
    cpu.esp -= 4;
    sub_488fbc(app, cpu);
    if (cpu.terminate) return;
    // 00483ba1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483ba3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483ba5  75c4                   -jne 0x483b6b
    if (!cpu.flags.zf)
    {
        goto L_0x00483b6b;
    }
L_0x00483ba7:
    // 00483ba7  b80c394800             -mov eax, 0x48390c
    cpu.eax = 4733196 /*0x48390c*/;
    // 00483bac  e823e7ffff             -call 0x4822d4
    cpu.esp -= 4;
    sub_4822d4(app, cpu);
    if (cpu.terminate) return;
    // 00483bb1  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483bb6  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00483bb9  e86e530000             -call 0x488f2c
    cpu.esp -= 4;
    sub_488f2c(app, cpu);
    if (cpu.terminate) return;
    // 00483bbe  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483bc3  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00483bc6  e861530000             -call 0x488f2c
    cpu.esp -= 4;
    sub_488f2c(app, cpu);
    if (cpu.terminate) return;
    // 00483bcb  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483bd0  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00483bd3  e854530000             -call 0x488f2c
    cpu.esp -= 4;
    sub_488f2c(app, cpu);
    if (cpu.terminate) return;
    // 00483bd8  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483bdd  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00483be0  e847530000             -call 0x488f2c
    cpu.esp -= 4;
    sub_488f2c(app, cpu);
    if (cpu.terminate) return;
    // 00483be5  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483bea  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00483bed  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483bef  7407                   -je 0x483bf8
    if (cpu.flags.zf)
    {
        goto L_0x00483bf8;
    }
    // 00483bf1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483bf3  e8c8210000             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
L_0x00483bf8:
    // 00483bf8  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483bfd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483bff  e868f1ffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 00483c04  890de01c5600           -mov dword ptr [0x561ce0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */) = cpu.ecx;
    // 00483c0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c0e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483c14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483c14);
    // 00483c14  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483c15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483c16  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483c18  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483c1d  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00483c20  e897530000             -call 0x488fbc
    cpu.esp -= 4;
    sub_488fbc(app, cpu);
    if (cpu.terminate) return;
    // 00483c25  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00483c27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483c29  7503                   -jne 0x483c2e
    if (!cpu.flags.zf)
    {
        goto L_0x00483c2e;
    }
    // 00483c2b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c2d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483c2e:
    // 00483c2e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483c2f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483c30  c7450800000000         -mov dword ptr [ebp + 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00483c37  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00483c3e  c7451000000000         -mov dword ptr [ebp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00483c45  c7452001000000         -mov dword ptr [ebp + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 00483c4c  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00483c53  895514                 -mov dword ptr [ebp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00483c56  a104914d00             -mov eax, dword ptr [0x4d9104]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083396) /* 0x4d9104 */);
    // 00483c5b  895d24                 -mov dword ptr [ebp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00483c5e  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00483c60  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00483c63  40                     -inc eax
    (cpu.eax)++;
    // 00483c64  8b1d048a4d00           -mov ebx, dword ptr [0x4d8a04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */);
    // 00483c6a  a304914d00             -mov dword ptr [0x4d9104], eax
    app->getMemory<x86::reg32>(x86::reg32(5083396) /* 0x4d9104 */) = cpu.eax;
    // 00483c6f  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483c71  49                     -dec ecx
    (cpu.ecx)--;
    // 00483c72  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00483c74  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00483c76  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00483c78  49                     -dec ecx
    (cpu.ecx)--;
    // 00483c79  b864d94c00             -mov eax, 0x4cd964
    cpu.eax = 5036388 /*0x4cd964*/;
    // 00483c7e  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00483c81  e882ecffff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 00483c86  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00483c88  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00483c8b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00483c8c:
    // 00483c8c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00483c8e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00483c90  3c00                   +cmp al, 0
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
    // 00483c92  7410                   -je 0x483ca4
    if (cpu.flags.zf)
    {
        goto L_0x00483ca4;
    }
    // 00483c94  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00483c97  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00483c9a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00483c9d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00483ca0  3c00                   +cmp al, 0
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
    // 00483ca2  75e8                   -jne 0x483c8c
    if (!cpu.flags.zf)
    {
        goto L_0x00483c8c;
    }
L_0x00483ca4:
    // 00483ca4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ca5  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483caa  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00483cac  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00483caf  e88c520000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00483cb4  8b15e01c5600           -mov edx, dword ptr [0x561ce0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483cba  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00483cbc  b8e41c5600             -mov eax, 0x561ce4
    cpu.eax = 5643492 /*0x561ce4*/;
    // 00483cc1  e8ca450000             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 00483cc6  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00483cc9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483cca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ccb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ccc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ccd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483cd0);
    // 00483cd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483cd1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00483cd3  e83cffffff             -call 0x483c14
    cpu.esp -= 4;
    sub_483c14(app, cpu);
    if (cpu.terminate) return;
    // 00483cd8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483cd9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483cdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483cdc);
    // 00483cdc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483cdd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483cde  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483ce0  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483ce5  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00483ce8  e8cf520000             -call 0x488fbc
    cpu.esp -= 4;
    sub_488fbc(app, cpu);
    if (cpu.terminate) return;
    // 00483ced  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00483cef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483cf1  7503                   -jne 0x483cf6
    if (!cpu.flags.zf)
    {
        goto L_0x00483cf6;
    }
    // 00483cf3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483cf4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483cf5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483cf6:
    // 00483cf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483cf7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483cf8  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00483cff  c7451000000000         -mov dword ptr [ebp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00483d06  c7452001000000         -mov dword ptr [ebp + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 00483d0d  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00483d14  a104914d00             -mov eax, dword ptr [0x4d9104]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083396) /* 0x4d9104 */);
    // 00483d19  895508                 -mov dword ptr [ebp + 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00483d1c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00483d1e  895d24                 -mov dword ptr [ebp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00483d21  8b15048a4d00           -mov edx, dword ptr [0x4d8a04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */);
    // 00483d27  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00483d2a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00483d2c  40                     -inc eax
    (cpu.eax)++;
    // 00483d2d  895514                 -mov dword ptr [ebp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00483d30  a304914d00             -mov dword ptr [0x4d9104], eax
    app->getMemory<x86::reg32>(x86::reg32(5083396) /* 0x4d9104 */) = cpu.eax;
    // 00483d35  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483d37  49                     -dec ecx
    (cpu.ecx)--;
    // 00483d38  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00483d3a  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00483d3c  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00483d3e  49                     -dec ecx
    (cpu.ecx)--;
    // 00483d3f  b864d94c00             -mov eax, 0x4cd964
    cpu.eax = 5036388 /*0x4cd964*/;
    // 00483d44  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00483d47  e8bcebffff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 00483d4c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00483d4e  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00483d51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00483d52:
    // 00483d52  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00483d54  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00483d56  3c00                   +cmp al, 0
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
    // 00483d58  7410                   -je 0x483d6a
    if (cpu.flags.zf)
    {
        goto L_0x00483d6a;
    }
    // 00483d5a  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00483d5d  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00483d60  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00483d63  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00483d66  3c00                   +cmp al, 0
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
    // 00483d68  75e8                   -jne 0x483d52
    if (!cpu.flags.zf)
    {
        goto L_0x00483d52;
    }
L_0x00483d6a:
    // 00483d6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d6b  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483d70  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00483d72  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00483d75  e8c6510000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00483d7a  8b15e01c5600           -mov edx, dword ptr [0x561ce0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483d80  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00483d82  b8e41c5600             -mov eax, 0x561ce4
    cpu.eax = 5643492 /*0x561ce4*/;
    // 00483d87  e804450000             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 00483d8c  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00483d8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d90  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483d94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483d94);
    // 00483d94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483d95  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00483d97  e840ffffff             -call 0x483cdc
    cpu.esp -= 4;
    sub_483cdc(app, cpu);
    if (cpu.terminate) return;
    // 00483d9c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483da0);
    // 00483da0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483da1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483da2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483da5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00483da7  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483dac  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00483daf  e808520000             -call 0x488fbc
    cpu.esp -= 4;
    sub_488fbc(app, cpu);
    if (cpu.terminate) return;
    // 00483db4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483db6  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00483db9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483dbb  746d                   -je 0x483e2a
    if (cpu.flags.zf)
    {
        goto L_0x00483e2a;
    }
    // 00483dbd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483dbe  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00483dc5  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00483dcc  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00483dd3  c7462002000000         -mov dword ptr [esi + 0x20], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 2 /*0x2*/;
    // 00483dda  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00483de1  a104914d00             -mov eax, dword ptr [0x4d9104]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083396) /* 0x4d9104 */);
    // 00483de6  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00483ded  8b15048a4d00           -mov edx, dword ptr [0x4d8a04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */);
    // 00483df3  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00483df6  40                     -inc eax
    (cpu.eax)++;
    // 00483df7  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00483dfa  a304914d00             -mov dword ptr [0x4d9104], eax
    app->getMemory<x86::reg32>(x86::reg32(5083396) /* 0x4d9104 */) = cpu.eax;
    // 00483dff  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00483e01  752d                   -jne 0x483e30
    if (!cpu.flags.zf)
    {
        goto L_0x00483e30;
    }
    // 00483e03  896e1c                 -mov dword ptr [esi + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebp;
L_0x00483e06:
    // 00483e06  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483e0b  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483e0f  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00483e12  e829510000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00483e17  8b15e01c5600           -mov edx, dword ptr [0x561ce0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483e1d  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00483e1f  b8e41c5600             -mov eax, 0x561ce4
    cpu.eax = 5643492 /*0x561ce4*/;
    // 00483e24  e867440000             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 00483e29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00483e2a:
    // 00483e2a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483e2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483e30:
    // 00483e30  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483e31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483e32  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483e33  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00483e35  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00483e37  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483e39  49                     -dec ecx
    (cpu.ecx)--;
    // 00483e3a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00483e3c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00483e3e  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00483e40  49                     -dec ecx
    (cpu.ecx)--;
    // 00483e41  b864d94c00             -mov eax, 0x4cd964
    cpu.eax = 5036388 /*0x4cd964*/;
    // 00483e46  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00483e49  e8baeaffff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 00483e4e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00483e50  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00483e53  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00483e55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00483e56:
    // 00483e56  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00483e58  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00483e5a  3c00                   +cmp al, 0
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
    // 00483e5c  7410                   -je 0x483e6e
    if (cpu.flags.zf)
    {
        goto L_0x00483e6e;
    }
    // 00483e5e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00483e61  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00483e64  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00483e67  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00483e6a  3c00                   +cmp al, 0
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
    // 00483e6c  75e8                   -jne 0x483e56
    if (!cpu.flags.zf)
    {
        goto L_0x00483e56;
    }
L_0x00483e6e:
    // 00483e6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e72  eb92                   -jmp 0x483e06
    goto L_0x00483e06;
}

/* align: skip  */
void Application::sub_483e74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483e74);
    // 00483e74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483e75  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483e77  e840faffff             -call 0x4838bc
    cpu.esp -= 4;
    sub_4838bc(app, cpu);
    if (cpu.terminate) return;
    // 00483e7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483e80);
    // 00483e80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483e81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483e82  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483e85  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483e87  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00483e8a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00483e8c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00483e8e  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483e93  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00483e96  e821510000             -call 0x488fbc
    cpu.esp -= 4;
    sub_488fbc(app, cpu);
    if (cpu.terminate) return;
    // 00483e9b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483e9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483e9f  7506                   -jne 0x483ea7
    if (!cpu.flags.zf)
    {
        goto L_0x00483ea7;
    }
    // 00483ea1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483ea4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ea5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ea6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483ea7:
    // 00483ea7  a104914d00             -mov eax, dword ptr [0x4d9104]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083396) /* 0x4d9104 */);
    // 00483eac  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00483eaf  40                     -inc eax
    (cpu.eax)++;
    // 00483eb0  8b1de01c5600           -mov ebx, dword ptr [0x561ce0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483eb6  a304914d00             -mov dword ptr [0x4d9104], eax
    app->getMemory<x86::reg32>(x86::reg32(5083396) /* 0x4d9104 */) = cpu.eax;
    // 00483ebb  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00483ebe  c7412003000000         -mov dword ptr [ecx + 0x20], 3
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 3 /*0x3*/;
    // 00483ec5  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00483ecc  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00483ed3  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00483ed5  895124                 -mov dword ptr [ecx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00483ed8  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00483edb  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00483ede  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00483ee1  a1048a4d00             -mov eax, dword ptr [0x4d8a04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */);
    // 00483ee6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00483ee8  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00483eeb  8d4370                 -lea eax, [ebx + 0x70]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 00483eee  897910                 -mov dword ptr [ecx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00483ef1  e84a500000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00483ef6  8b15e01c5600           -mov edx, dword ptr [0x561ce0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483efc  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00483efe  b8e41c5600             -mov eax, 0x561ce4
    cpu.eax = 5643492 /*0x561ce4*/;
    // 00483f03  e888430000             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 00483f08  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00483f0b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483f0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483f14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483f14);
    // 00483f14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483f15  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483f17  e864ffffff             -call 0x483e80
    cpu.esp -= 4;
    sub_483e80(app, cpu);
    if (cpu.terminate) return;
    // 00483f1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483f20);
    // 00483f20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483f21  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00483f23  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00483f25  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483f27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483f29  e852ffffff             -call 0x483e80
    cpu.esp -= 4;
    sub_483e80(app, cpu);
    if (cpu.terminate) return;
    // 00483f2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483f30);
    // 00483f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483f32  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00483f34  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483f36  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483f38  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483f3a  e841ffffff             -call 0x483e80
    cpu.esp -= 4;
    sub_483e80(app, cpu);
    if (cpu.terminate) return;
    // 00483f3f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483f44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00483f44);
    // 00483f44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483f45  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483f46  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483f47  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483f48  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483f4a  bab0384800             -mov edx, 0x4838b0
    cpu.edx = 4733104 /*0x4838b0*/;
    // 00483f4f  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483f54  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00483f56  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00483f59  e872530000             -call 0x4892d0
    cpu.esp -= 4;
    sub_4892d0(app, cpu);
    if (cpu.terminate) return;
    // 00483f5e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483f60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483f62  7438                   -je 0x483f9c
    if (cpu.flags.zf)
    {
        goto L_0x00483f9c;
    }
    // 00483f64  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483f65  8b7020                 -mov esi, dword ptr [eax + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00483f68  83fe01                 +cmp esi, 1
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
    // 00483f6b  7528                   -jne 0x483f95
    if (!cpu.flags.zf)
    {
        goto L_0x00483f95;
    }
L_0x00483f6d:
    // 00483f6d  8b6a1c                 -mov ebp, dword ptr [edx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00483f70  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00483f72  740e                   -je 0x483f82
    if (cpu.flags.zf)
    {
        goto L_0x00483f82;
    }
    // 00483f74  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00483f76  e8f1edffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 00483f7b  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x00483f82:
    // 00483f82  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483f87  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00483f8a  e8b14f0000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00483f8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00483f90:
    // 00483f90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483f95:
    // 00483f95  83fe02                 +cmp esi, 2
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
    // 00483f98  74d3                   -je 0x483f6d
    if (cpu.flags.zf)
    {
        goto L_0x00483f6d;
    }
    // 00483f9a  ebe6                   -jmp 0x483f82
    goto L_0x00483f82;
L_0x00483f9c:
    // 00483f9c  e81ff9ffff             -call 0x4838c0
    cpu.esp -= 4;
    sub_4838c0(app, cpu);
    if (cpu.terminate) return;
    // 00483fa1  bab0384800             -mov edx, 0x4838b0
    cpu.edx = 4733104 /*0x4838b0*/;
    // 00483fa6  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483fab  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00483fad  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00483fb0  e81b530000             -call 0x4892d0
    cpu.esp -= 4;
    sub_4892d0(app, cpu);
    if (cpu.terminate) return;
    // 00483fb5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483fb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483fb9  7516                   -jne 0x483fd1
    if (!cpu.flags.zf)
    {
        goto L_0x00483fd1;
    }
    // 00483fbb  bab0384800             -mov edx, 0x4838b0
    cpu.edx = 4733104 /*0x4838b0*/;
    // 00483fc0  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483fc5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00483fc7  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00483fca  e801530000             -call 0x4892d0
    cpu.esp -= 4;
    sub_4892d0(app, cpu);
    if (cpu.terminate) return;
    // 00483fcf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00483fd1:
    // 00483fd1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483fd3  74bb                   -je 0x483f90
    if (cpu.flags.zf)
    {
        goto L_0x00483f90;
    }
    // 00483fd5  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00483fd8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00483fda  7411                   -je 0x483fed
    if (cpu.flags.zf)
    {
        goto L_0x00483fed;
    }
    // 00483fdc  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483fe1  3b4814                 +cmp ecx, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483fe4  7407                   -je 0x483fed
    if (cpu.flags.zf)
    {
        goto L_0x00483fed;
    }
    // 00483fe6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483fe8  e8abedffff             -call 0x482d98
    cpu.esp -= 4;
    sub_482d98(app, cpu);
    if (cpu.terminate) return;
L_0x00483fed:
    // 00483fed  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00483ff2  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00483ff5  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00483ffc  e83f4f0000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00484001  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484002  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484003  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484004  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484005  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484008(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484008);
    // 00484008  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484009  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048400a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048400b  8b0de01c5600           -mov ecx, dword ptr [0x561ce0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484011  bab0384800             -mov edx, 0x4838b0
    cpu.edx = 4733104 /*0x4838b0*/;
    // 00484016  83c138                 -add ecx, 0x38
    (cpu.ecx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00484019  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048401b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048401d  e8ae520000             -call 0x4892d0
    cpu.esp -= 4;
    sub_4892d0(app, cpu);
    if (cpu.terminate) return;
    // 00484022  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484024  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484026  7506                   -jne 0x48402e
    if (!cpu.flags.zf)
    {
        goto L_0x0048402e;
    }
L_0x00484028:
    // 00484028  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048402a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048402b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048402c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048402d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048402e:
    // 0048402e  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484033  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00484035  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00484038  e8034f0000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 0048403d  83792000               +cmp dword ptr [ecx + 0x20], 0
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
    // 00484041  74e5                   -je 0x484028
    if (cpu.flags.zf)
    {
        goto L_0x00484028;
    }
    // 00484043  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00484046  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484047  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484048  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484049  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48404c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048404c);
    // 0048404c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048404d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048404e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048404f  8b0de01c5600           -mov ecx, dword ptr [0x561ce0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484055  bab0384800             -mov edx, 0x4838b0
    cpu.edx = 4733104 /*0x4838b0*/;
    // 0048405a  83c138                 -add ecx, 0x38
    (cpu.ecx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0048405d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048405f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484061  e86a520000             -call 0x4892d0
    cpu.esp -= 4;
    sub_4892d0(app, cpu);
    if (cpu.terminate) return;
    // 00484066  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484068  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048406a  7504                   -jne 0x484070
    if (!cpu.flags.zf)
    {
        goto L_0x00484070;
    }
    // 0048406c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048406d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048406e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048406f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484070:
    // 00484070  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484075  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00484077  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048407a  e8c14e0000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 0048407f  83792000               +cmp dword ptr [ecx + 0x20], 0
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
    // 00484083  7409                   -je 0x48408e
    if (cpu.flags.zf)
    {
        goto L_0x0048408e;
    }
    // 00484085  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048408a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048408b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048408c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048408d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048408e:
    // 0048408e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00484093  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484094  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484095  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484096  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4840a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004840a8);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004840a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004840a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004840aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004840ab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004840ac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004840ad  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004840ae  81ec08010000           -sub esp, 0x108
    (cpu.esp) -= x86::reg32(x86::sreg32(264 /*0x108*/));
    // 004840b4  e8c3410000             -call 0x48827c
    cpu.esp -= 4;
    sub_48827c(app, cpu);
    if (cpu.terminate) return;
    // 004840b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004840bb  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004840c0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004840c2  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004840c9  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x004840d0:
    // 004840d0  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004840d5  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004840d9  743d                   -je 0x484118
    if (cpu.flags.zf)
    {
        goto L_0x00484118;
    }
    // 004840db  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004840de  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004840e0  0f85b0030000           -jne 0x484496
    if (!cpu.flags.zf)
    {
        goto L_0x00484496;
    }
L_0x004840e6:
    // 004840e6  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004840eb  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004840f2  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004840f9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004840fb  e858420000             -call 0x488358
    cpu.esp -= 4;
    sub_488358(app, cpu);
    if (cpu.terminate) return;
    // 00484100  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484105  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0048410b  81c408010000           -add esp, 0x108
    (cpu.esp) += x86::reg32(x86::sreg32(264 /*0x108*/));
    // 00484111  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484112  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484113  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484114  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484115  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484116  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484117  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484118:
    // 00484118  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0048411b  e8e04e0000             -call 0x489000
    cpu.esp -= 4;
    sub_489000(app, cpu);
    if (cpu.terminate) return;
    // 00484120  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00484122  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 00484129  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048412b  0f8454030000           -je 0x484485
    if (cpu.flags.zf)
    {
        goto L_0x00484485;
    }
    // 00484131  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484136  896818                 -mov dword ptr [eax + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00484139  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0048413c  4a                     -dec edx
    (cpu.edx)--;
    // 0048413d  83fa03                 +cmp edx, 3
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
    // 00484140  760e                   -jbe 0x484150
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00484150;
    }
    // 00484142  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484147  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0048414e  eb80                   -jmp 0x4840d0
    goto L_0x004840d0;
L_0x00484150:
    // 00484150  ff249598404800         -jmp dword ptr [edx*4 + 0x484098]
    cpu.ip = app->getMemory<x86::reg32>(4735128 + cpu.edx * 4); goto dynamic_jump;
  case 0x00484157:
    // 00484157  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00484159  8b751c                 -mov esi, dword ptr [ebp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0048415c  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00484163  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00484164:
    // 00484164  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00484166  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00484168  3c00                   +cmp al, 0
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
    // 0048416a  7410                   -je 0x48417c
    if (cpu.flags.zf)
    {
        goto L_0x0048417c;
    }
    // 0048416c  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048416f  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00484172  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00484175  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00484178  3c00                   +cmp al, 0
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
    // 0048417a  75e8                   -jne 0x484164
    if (!cpu.flags.zf)
    {
        goto L_0x00484164;
    }
L_0x0048417c:
    // 0048417c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048417d  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00484180  8d4d10                 -lea ecx, [ebp + 0x10]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00484183  e8e4ebffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 00484188  8d5d0c                 -lea ebx, [ebp + 0xc]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048418b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048418d  c7451c00000000         -mov dword ptr [ebp + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00484194  e88b1a0000             -call 0x485c24
    cpu.esp -= 4;
    sub_485c24(app, cpu);
    if (cpu.terminate) return;
    // 00484199  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004841a0  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004841a7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004841a9  0f8435010000           -je 0x4842e4
    if (cpu.flags.zf)
    {
        goto L_0x004842e4;
    }
    // 004841af  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004841b2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004841b4  b9c2010000             -mov ecx, 0x1c2
    cpu.ecx = 450 /*0x1c2*/;
    // 004841b9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004841bc  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004841be  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004841c1  8d8890010000           -lea ecx, [eax + 0x190]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(400) /* 0x190 */);
    // 004841c7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004841c9  0f8505010000           -jne 0x4842d4
    if (!cpu.flags.zf)
    {
        goto L_0x004842d4;
    }
    // 004841cf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004841d1  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004841d4  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004841d7  e810e7ffff             -call 0x4828ec
    cpu.esp -= 4;
    sub_4828ec(app, cpu);
    if (cpu.terminate) return;
    // 004841dc  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004841df  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004841e1  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004841e4:
    // 004841e4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004841e6  e8edc90100             -call 0x4a0bd8
    cpu.esp -= 4;
    sub_4a0bd8(app, cpu);
    if (cpu.terminate) return;
    // 004841eb  e8bcca0100             -call 0x4a0cac
    cpu.esp -= 4;
    sub_4a0cac(app, cpu);
    if (cpu.terminate) return;
    // 004841f0  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004841f7  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004841fe  e84d3efdff             -call 0x458050
    cpu.esp -= 4;
    sub_458050(app, cpu);
    if (cpu.terminate) return;
    // 00484203  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048420a  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048420d  8b9c2404010000         -mov ebx, dword ptr [esp + 0x104]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00484214  e8bf1b0000             -call 0x485dd8
    cpu.esp -= 4;
    sub_485dd8(app, cpu);
    if (cpu.terminate) return;
    // 00484219  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00484220  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00484227  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048422a  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048422d  e8961b0000             -call 0x485dc8
    cpu.esp -= 4;
    sub_485dc8(app, cpu);
    if (cpu.terminate) return;
    // 00484232  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484234  750e                   -jne 0x484244
    if (!cpu.flags.zf)
    {
        goto L_0x00484244;
    }
    // 00484236  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048423d  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
L_0x00484244:
    // 00484244  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0048424b  e8c03dfdff             -call 0x458010
    cpu.esp -= 4;
    sub_458010(app, cpu);
    if (cpu.terminate) return;
    // 00484250  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00484257  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00484259  e8621b0000             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
    // 0048425e  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00484265  89b42400010000         -mov dword ptr [esp + 0x100], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.esi;
    // 0048426c  83782000               +cmp dword ptr [eax + 0x20], 0
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
    // 00484270  7530                   -jne 0x4842a2
    if (!cpu.flags.zf)
    {
        goto L_0x004842a2;
    }
    // 00484272  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00484279  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 0048427e  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00484281  3b5014                 +cmp edx, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484284  741c                   -je 0x4842a2
    if (cpu.flags.zf)
    {
        goto L_0x004842a2;
    }
    // 00484286  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048428d  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00484290  e803ebffff             -call 0x482d98
    cpu.esp -= 4;
    sub_482d98(app, cpu);
    if (cpu.terminate) return;
    // 00484295  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048429c  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0048429f  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004842a2:
    // 004842a2  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004842a9  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 004842ad  743a                   -je 0x4842e9
    if (cpu.flags.zf)
    {
        goto L_0x004842e9;
    }
    // 004842af  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004842b4  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004842bb  83c054                 +add eax, 0x54
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(84 /*0x54*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004842be  e87d4c0000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 004842c3  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004842c8  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004842cf  e9fcfdffff             -jmp 0x4840d0
    goto L_0x004840d0;
L_0x004842d4:
    // 004842d4  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004842d9  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004842dc  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004842df  e900ffffff             -jmp 0x4841e4
    goto L_0x004841e4;
L_0x004842e4:
    // 004842e4  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004842e7  ebb9                   -jmp 0x4842a2
    goto L_0x004842a2;
L_0x004842e9:
    // 004842e9  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004842ee  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004842f5  83c038                 +add eax, 0x38
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004842f8  e8434c0000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 004842fd  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484302  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00484309  e9c2fdffff             -jmp 0x4840d0
    goto L_0x004840d0;
  case 0x0048430e:
    // 0048430e  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00484311  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00484313  7407                   -je 0x48431c
    if (cpu.flags.zf)
    {
        goto L_0x0048431c;
    }
    // 00484315  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00484317  e8a41a0000             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
L_0x0048431c:
    // 0048431c  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484321  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00484328  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048432f  83781c00               +cmp dword ptr [eax + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484333  7449                   -je 0x48437e
    if (cpu.flags.zf)
    {
        goto L_0x0048437e;
    }
    // 00484335  b890010000             -mov eax, 0x190
    cpu.eax = 400 /*0x190*/;
    // 0048433a  e899c80100             -call 0x4a0bd8
    cpu.esp -= 4;
    sub_4a0bd8(app, cpu);
    if (cpu.terminate) return;
    // 0048433f  e868c90100             -call 0x4a0cac
    cpu.esp -= 4;
    sub_4a0cac(app, cpu);
    if (cpu.terminate) return;
    // 00484344  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484349  8d4810                 -lea ecx, [eax + 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048434c  8d580c                 -lea ebx, [eax + 0xc]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048434f  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00484352  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00484359  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048435c  e8cb180000             -call 0x485c2c
    cpu.esp -= 4;
    sub_485c2c(app, cpu);
    if (cpu.terminate) return;
    // 00484361  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00484368  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048436b  e8fce9ffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 00484370  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00484377  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x0048437e:
    // 0048437e  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484383  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048438a  83c01c                 +add eax, 0x1c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048438d  e8ae4b0000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00484392  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484397  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0048439e  e92dfdffff             -jmp 0x4840d0
    goto L_0x004840d0;
  case 0x004843a3:
    // 004843a3  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004843a6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004843a8  0f8498000000           -je 0x484446
    if (cpu.flags.zf)
    {
        goto L_0x00484446;
    }
    // 004843ae  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004843b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004843b3  b9c2010000             -mov ecx, 0x1c2
    cpu.ecx = 450 /*0x1c2*/;
    // 004843b8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004843bb  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004843bd  0590010000             -add eax, 0x190
    (cpu.eax) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 004843c2  e811c80100             -call 0x4a0bd8
    cpu.esp -= 4;
    sub_4a0bd8(app, cpu);
    if (cpu.terminate) return;
    // 004843c7  e8e0c80100             -call 0x4a0cac
    cpu.esp -= 4;
    sub_4a0cac(app, cpu);
    if (cpu.terminate) return;
    // 004843cc  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004843d1  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004843d4  e8773cfdff             -call 0x458050
    cpu.esp -= 4;
    sub_458050(app, cpu);
    if (cpu.terminate) return;
    // 004843d9  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004843de  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004843e1  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004843e4  e8ef190000             -call 0x485dd8
    cpu.esp -= 4;
    sub_485dd8(app, cpu);
    if (cpu.terminate) return;
    // 004843e9  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 004843ee  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004843f1  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004843f4  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004843f7  e8cc190000             -call 0x485dc8
    cpu.esp -= 4;
    sub_485dc8(app, cpu);
    if (cpu.terminate) return;
    // 004843fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004843fe  7503                   -jne 0x484403
    if (!cpu.flags.zf)
    {
        goto L_0x00484403;
    }
    // 00484400  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x00484403:
    // 00484403  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484408  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048440b  e8003cfdff             -call 0x458010
    cpu.esp -= 4;
    sub_458010(app, cpu);
    if (cpu.terminate) return;
L_0x00484410:
    // 00484410  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00484417  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 0048441b  0f84c8feffff           -je 0x4842e9
    if (cpu.flags.zf)
    {
        goto L_0x004842e9;
    }
    // 00484421  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484426  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0048442d  83c054                 +add eax, 0x54
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(84 /*0x54*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00484430  e80b4b0000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00484435  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 0048443a  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00484441  e98afcffff             -jmp 0x4840d0
    goto L_0x004840d0;
L_0x00484446:
    // 00484446  897520                 -mov dword ptr [ebp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00484449  ebc5                   -jmp 0x484410
    goto L_0x00484410;
  case 0x0048444b:
    // 0048444b  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048444e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00484450  7407                   -je 0x484459
    if (cpu.flags.zf)
    {
        goto L_0x00484459;
    }
    // 00484452  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484454  e867190000             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
L_0x00484459:
    // 00484459  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 0048445e  83c01c                 +add eax, 0x1c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00484461  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00484468  c740ec00000000         -mov dword ptr [eax - 0x14], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 0048446f  e8cc4a0000             -call 0x488f40
    cpu.esp -= 4;
    sub_488f40(app, cpu);
    if (cpu.terminate) return;
    // 00484474  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 00484479  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00484480  e94bfcffff             -jmp 0x4840d0
    goto L_0x004840d0;
L_0x00484485:
    // 00484485  a1e01c5600             -mov eax, dword ptr [0x561ce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643488) /* 0x561ce0 */);
    // 0048448a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048448c  e83b3e0000             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 00484491  e93afcffff             -jmp 0x4840d0
    goto L_0x004840d0;
L_0x00484496:
    // 00484496  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484498  e823190000             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
    // 0048449d  e944fcffff             -jmp 0x4840e6
    goto L_0x004840e6;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4844b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004844b0);
    // 004844b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004844b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004844b3  803d38b84d0000         +cmp byte ptr [0x4db838], 0
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
    // 004844ba  7507                   -jne 0x4844c3
    if (!cpu.flags.zf)
    {
        goto L_0x004844c3;
    }
    // 004844bc  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004844c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004844c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004844c3:
    // 004844c3  e808ca0100             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 004844c8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004844ca  e80dce0100             -call 0x4a12dc
    cpu.esp -= 4;
    sub_4a12dc(app, cpu);
    if (cpu.terminate) return;
    // 004844cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004844d1  7c0b                   -jl 0x4844de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004844de;
    }
    // 004844d3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004844d5  e80aca0100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 004844da  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004844dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004844dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004844de:
    // 004844de  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004844e3  e8fcc90100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 004844e8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004844ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004844eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4844f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004844f0);
    // 004844f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004844f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004844f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004844f3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004844f5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004844f7  803d38b84d0000         +cmp byte ptr [0x4db838], 0
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
    // 004844fe  7415                   -je 0x484515
    if (cpu.flags.zf)
    {
        goto L_0x00484515;
    }
    // 00484500  83fb7f                 +cmp ebx, 0x7f
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
    // 00484503  7f05                   -jg 0x48450a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048450a;
    }
    // 00484505  83fbff                 +cmp ebx, -1
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
    // 00484508  7d12                   -jge 0x48451c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048451c;
    }
L_0x0048450a:
    // 0048450a  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
L_0x0048450f:
    // 0048450f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484511  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484512  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484513  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484514  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484515:
    // 00484515  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 0048451a  ebf3                   -jmp 0x48450f
    goto L_0x0048450f;
L_0x0048451c:
    // 0048451c  e8afc90100             -call 0x4a0ed0
    cpu.esp -= 4;
    sub_4a0ed0(app, cpu);
    if (cpu.terminate) return;
    // 00484521  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484523  e8b4cd0100             -call 0x4a12dc
    cpu.esp -= 4;
    sub_4a12dc(app, cpu);
    if (cpu.terminate) return;
    // 00484528  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048452a  0f8c6d000000           -jl 0x48459d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048459d;
    }
    // 00484530  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00484537  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00484539  b9f09b5900             -mov ecx, 0x599bf0
    cpu.ecx = 5872624 /*0x599bf0*/;
    // 0048453e  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00484541  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00484543  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00484545  7e66                   -jle 0x4845ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004845ad;
    }
L_0x00484547:
    // 00484547  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484548  0fb6793b               -movzx edi, byte ptr [ecx + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */));
    // 0048454c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048454e  7464                   -je 0x4845b4
    if (cpu.flags.zf)
    {
        goto L_0x004845b4;
    }
    // 00484550  b9f09b5900             -mov ecx, 0x599bf0
    cpu.ecx = 5872624 /*0x599bf0*/;
    // 00484555  8da900060000           -lea ebp, [ecx + 0x600]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(1536) /* 0x600 */);
L_0x0048455b:
    // 0048455b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048455d  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 00484560  39fa                   +cmp edx, edi
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
    // 00484562  7524                   -jne 0x484588
    if (!cpu.flags.zf)
    {
        goto L_0x00484588;
    }
    // 00484564  80790c01               +cmp byte ptr [ecx + 0xc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00484568  751e                   -jne 0x484588
    if (!cpu.flags.zf)
    {
        goto L_0x00484588;
    }
    // 0048456a  833900                 +cmp dword ptr [ecx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048456d  7c19                   -jl 0x484588
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484588;
    }
    // 0048456f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484571  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00484574  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00484577  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484579  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0048457c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048457e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484580  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00484583  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00484585  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00484588:
    // 00484588  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0048458b  39e9                   +cmp ecx, ebp
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
    // 0048458d  75cc                   -jne 0x48455b
    if (!cpu.flags.zf)
    {
        goto L_0x0048455b;
    }
    // 0048458f  e850c90100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 00484594  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00484596  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484597  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484599  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048459a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048459b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048459c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048459d:
    // 0048459d  e842c90100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 004845a2  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 004845a7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004845a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004845aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004845ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004845ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004845ad:
    // 004845ad  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004845b2  eb93                   -jmp 0x484547
    goto L_0x00484547;
L_0x004845b4:
    // 004845b4  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004845b7  89591c                 -mov dword ptr [ecx + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004845ba  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004845bc  8b5920                 -mov ebx, dword ptr [ecx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004845bf  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004845c1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004845c3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004845c6  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004845c8  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004845cb  e814c90100             -call 0x4a0ee4
    cpu.esp -= 4;
    sub_4a0ee4(app, cpu);
    if (cpu.terminate) return;
    // 004845d0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004845d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004845d3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004845d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004845d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004845d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004845d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4845e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004845e0);
    // 004845e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004845e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004845e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004845e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004845e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004845e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004845e6  81ec1c0c0000           -sub esp, 0xc1c
    (cpu.esp) -= x86::reg32(x86::sreg32(3100 /*0xc1c*/));
    // 004845ec  898424100c0000         -mov dword ptr [esp + 0xc10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */) = cpu.eax;
    // 004845f3  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004845f8  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 004845fd  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 00484602  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 00484607  899424140c0000         -mov dword ptr [esp + 0xc14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */) = cpu.edx;
    // 0048460e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00484610  898c24080c0000         -mov dword ptr [esp + 0xc08], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */) = cpu.ecx;
    // 00484617  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00484619:
    // 00484619  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048461c  89740cf4               -mov dword ptr [esp + ecx - 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.ecx * 1) = cpu.esi;
    // 00484620  81f9000c0000           +cmp ecx, 0xc00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3072 /*0xc00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484626  75f1                   -jne 0x484619
    if (!cpu.flags.zf)
    {
        goto L_0x00484619;
    }
    // 00484628  8bb424100c0000         -mov esi, dword ptr [esp + 0xc10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */);
    // 0048462f  8b34f5f0a15900         -mov esi, dword ptr [esi*8 + 0x59a1f0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */ + cpu.esi * 8);
    // 00484636  807e0401               +cmp byte ptr [esi + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048463a  7206                   -jb 0x484642
    if (cpu.flags.cf)
    {
        goto L_0x00484642;
    }
    // 0048463c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048463e  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
L_0x00484642:
    // 00484642  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484644  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00484646  89bc24180c0000         -mov dword ptr [esp + 0xc18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */) = cpu.edi;
    // 0048464d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048464f  0f8ea6000000           -jle 0x4846fb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004846fb;
    }
    // 00484655  8b9424100c0000         -mov edx, dword ptr [esp + 0xc10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */);
    // 0048465c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048465f  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00484662  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484664  899424000c0000         -mov dword ptr [esp + 0xc00], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */) = cpu.edx;
    // 0048466b  8d5608                 -lea edx, [esi + 8]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048466e  8984240c0c0000         -mov dword ptr [esp + 0xc0c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3084) /* 0xc0c */) = cpu.eax;
    // 00484675  899424040c0000         -mov dword ptr [esp + 0xc04], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */) = cpu.edx;
    // 0048467c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x0048467e:
    // 0048467e  807e0402               +cmp byte ptr [esi + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00484682  0f82b8000000           -jb 0x484740
    if (cpu.flags.cf)
    {
        goto L_0x00484740;
    }
    // 00484688  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0048468a  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
L_0x0048468d:
    // 0048468d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048468f  744a                   -je 0x4846db
    if (cpu.flags.zf)
    {
        goto L_0x004846db;
    }
    // 00484691  807e0402               +cmp byte ptr [esi + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00484695  0f82ad000000           -jb 0x484748
    if (cpu.flags.cf)
    {
        goto L_0x00484748;
    }
    // 0048469b  8d0429                 -lea eax, [ecx + ebp]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 0048469e  8d550c                 -lea edx, [ebp + 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004846a1  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004846a4  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004846a6  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004846a8  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x004846ab:
    // 004846ab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004846ad  8b9424000c0000         -mov edx, dword ptr [esp + 0xc00]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 004846b4  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004846b6  8b92f4a15900           -mov edx, dword ptr [edx + 0x59a1f4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5874164) /* 0x59a1f4 */);
    // 004846bc  e8cfc00100             -call 0x4a0790
    cpu.esp -= 4;
    sub_4a0790(app, cpu);
    if (cpu.terminate) return;
    // 004846c1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004846c3  83f807                 +cmp eax, 7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004846c6  740b                   -je 0x4846d3
    if (cpu.flags.zf)
    {
        goto L_0x004846d3;
    }
    // 004846c8  c78424080c000008000000 -mov dword ptr [esp + 0xc08], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */) = 8 /*0x8*/;
L_0x004846d3:
    // 004846d3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004846d5  0f8c86000000           -jl 0x484761
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484761;
    }
L_0x004846db:
    // 004846db  8b8424180c0000         -mov eax, dword ptr [esp + 0xc18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */);
    // 004846e2  8b94240c0c0000         -mov edx, dword ptr [esp + 0xc0c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3084) /* 0xc0c */);
    // 004846e9  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004846ec  40                     -inc eax
    (cpu.eax)++;
    // 004846ed  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004846f0  898424180c0000         -mov dword ptr [esp + 0xc18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */) = cpu.eax;
    // 004846f7  39d1                   +cmp ecx, edx
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
    // 004846f9  7c83                   -jl 0x48467e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048467e;
    }
L_0x004846fb:
    // 004846fb  8b9424140c0000         -mov edx, dword ptr [esp + 0xc14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */);
    // 00484702  83faff                 +cmp edx, -1
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
    // 00484705  7e21                   -jle 0x484728
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484728;
    }
    // 00484707  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484709  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048470b  7c1b                   -jl 0x484728
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484728;
    }
    // 0048470d  8bbc24140c0000         -mov edi, dword ptr [esp + 0xc14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */);
L_0x00484714:
    // 00484714  8b8424100c0000         -mov eax, dword ptr [esp + 0xc10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */);
    // 0048471b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048471d  41                     -inc ecx
    (cpu.ecx)++;
    // 0048471e  e81dbf0100             -call 0x4a0640
    cpu.esp -= 4;
    sub_4a0640(app, cpu);
    if (cpu.terminate) return;
    // 00484723  39f9                   +cmp ecx, edi
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
    // 00484725  7eed                   -jle 0x484714
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484714;
    }
    // 00484727  90                     -nop 
    ;
L_0x00484728:
    // 00484728  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048472a  7c46                   -jl 0x484772
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484772;
    }
    // 0048472c  8b8424080c0000         -mov eax, dword ptr [esp + 0xc08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */);
    // 00484733  81c41c0c0000           +add esp, 0xc1c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3100 /*0xc1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00484739  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048473a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048473b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048473c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048473d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048473e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048473f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484740:
    // 00484740  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00484743  e945ffffff             -jmp 0x48468d
    goto L_0x0048468d;
L_0x00484748:
    // 00484748  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0048474b  8b9424040c0000         -mov edx, dword ptr [esp + 0xc04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */);
    // 00484752  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00484755  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00484757  01da                   +add edx, ebx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00484759  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048475c  e94affffff             -jmp 0x4846ab
    goto L_0x004846ab;
L_0x00484761:
    // 00484761  8b8424180c0000         -mov eax, dword ptr [esp + 0xc18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */);
    // 00484768  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00484769  898424140c0000         -mov dword ptr [esp + 0xc14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */) = cpu.eax;
    // 00484770  eb89                   -jmp 0x4846fb
    goto L_0x004846fb;
L_0x00484772:
    // 00484772  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484774  81c41c0c0000           -add esp, 0xc1c
    (cpu.esp) += x86::reg32(x86::sreg32(3100 /*0xc1c*/));
    // 0048477a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048477b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048477c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048477d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048477e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048477f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484780  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484784(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484784);
    // 00484784  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484786  7c0f                   -jl 0x484797
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484797;
    }
    // 00484788  83f80a                 +cmp eax, 0xa
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
    // 0048478b  7d0a                   -jge 0x484797
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00484797;
    }
    // 0048478d  833cc5f0a1590000       +cmp dword ptr [eax*8 + 0x59a1f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */ + cpu.eax * 8);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484795  7506                   -jne 0x48479d
    if (!cpu.flags.zf)
    {
        goto L_0x0048479d;
    }
L_0x00484797:
    // 00484797  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048479c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048479d:
    // 0048479d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048479f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4847a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004847a0);
    // 004847a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004847a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004847a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004847a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004847a4  81ec000c0000           -sub esp, 0xc00
    (cpu.esp) -= x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 004847aa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004847ac  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004847ae  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004847b3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004847b5:
    // 004847b5  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004847b8  89540cf4               -mov dword ptr [esp + ecx - 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.ecx * 1) = cpu.edx;
    // 004847bc  81f9000c0000           +cmp ecx, 0xc00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3072 /*0xc00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004847c2  75f1                   -jne 0x4847b5
    if (!cpu.flags.zf)
    {
        goto L_0x004847b5;
    }
    // 004847c4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004847c6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004847c8  7e12                   -jle 0x4847dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004847dc;
    }
L_0x004847ca:
    // 004847ca  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004847cc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004847ce  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004847d0  41                     -inc ecx
    (cpu.ecx)++;
    // 004847d1  e85abc0100             -call 0x4a0430
    cpu.esp -= 4;
    sub_4a0430(app, cpu);
    if (cpu.terminate) return;
    // 004847d6  39f9                   +cmp ecx, edi
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
    // 004847d8  7cf0                   -jl 0x4847ca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004847ca;
    }
    // 004847da  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004847dc:
    // 004847dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004847de  81c4000c0000           -add esp, 0xc00
    (cpu.esp) += x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 004847e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004847e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004847e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004847e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004847e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4847ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004847ec);
    // 004847ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004847ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004847ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004847ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004847f0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004847f2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004847f4  8a1538b84d00           -mov dl, byte ptr [0x4db838]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
    // 004847fa  bff7ffffff             -mov edi, 0xfffffff7
    cpu.edi = 4294967287 /*0xfffffff7*/;
    // 004847ff  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00484801  7449                   -je 0x48484c
    if (cpu.flags.zf)
    {
        goto L_0x0048484c;
    }
    // 00484803  8138424e4b6c           +cmp dword ptr [eax], 0x6c4b4e42
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816874562 /*0x6c4b4e42*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484809  754b                   -jne 0x484856
    if (!cpu.flags.zf)
    {
        goto L_0x00484856;
    }
    // 0048480b  baf0a15900             -mov edx, 0x59a1f0
    cpu.edx = 5874160 /*0x59a1f0*/;
    // 00484810  8b2df0a15900           -mov ebp, dword ptr [0x59a1f0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */);
    // 00484816  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484818  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048481a  740e                   -je 0x48482a
    if (cpu.flags.zf)
    {
        goto L_0x0048482a;
    }
L_0x0048481c:
    // 0048481c  41                     -inc ecx
    (cpu.ecx)++;
    // 0048481d  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00484820  83f90a                 +cmp ecx, 0xa
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
    // 00484823  7d46                   -jge 0x48486b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048486b;
    }
    // 00484825  833a00                 +cmp dword ptr [edx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484828  75f2                   -jne 0x48481c
    if (!cpu.flags.zf)
    {
        goto L_0x0048481c;
    }
L_0x0048482a:
    // 0048482a  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0048482c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048482e  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00484831  e8aafdffff             -call 0x4845e0
    cpu.esp -= 4;
    sub_4845e0(app, cpu);
    if (cpu.terminate) return;
    // 00484836  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484838  7c26                   -jl 0x484860
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484860;
    }
    // 0048483a  ba74484800             -mov edx, 0x484874
    cpu.edx = 4737140 /*0x484874*/;
    // 0048483f  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00484841  891550b84d00           -mov dword ptr [0x4db850], edx
    app->getMemory<x86::reg32>(x86::reg32(5093456) /* 0x4db850 */) = cpu.edx;
    // 00484847  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484848  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484849  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048484a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048484b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048484c:
    // 0048484c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00484851  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484852  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484853  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484854  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484855  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484856:
    // 00484856  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0048485b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048485c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048485d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048485e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048485f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484860:
    // 00484860  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00484866  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484867  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484868  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484869  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048486a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048486b:
    // 0048486b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048486d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048486e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048486f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484870  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484871  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484874(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484874);
    // 00484874  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484875  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484876  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484877  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484879  8a2538b84d00           -mov ah, byte ptr [0x4db838]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5093432) /* 0x4db838 */);
    // 0048487f  be80000000             -mov esi, 0x80
    cpu.esi = 128 /*0x80*/;
    // 00484884  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00484886  741a                   -je 0x4848a2
    if (cpu.flags.zf)
    {
        goto L_0x004848a2;
    }
    // 00484888  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048488b  751e                   -jne 0x4848ab
    if (!cpu.flags.zf)
    {
        goto L_0x004848ab;
    }
    // 0048488d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0048488f:
    // 0048488f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484891  42                     -inc edx
    (cpu.edx)++;
    // 00484892  e8ddffffff             -call 0x484874
    cpu.esp -= 4;
    sub_484874(app, cpu);
    if (cpu.terminate) return;
    // 00484897  83fa0a                 +cmp edx, 0xa
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
    // 0048489a  7cf3                   -jl 0x48488f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048488f;
    }
    // 0048489c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048489e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048489f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004848a2:
    // 004848a2  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004848a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004848ab:
    // 004848ab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004848ad  e8d2feffff             -call 0x484784
    cpu.esp -= 4;
    sub_484784(app, cpu);
    if (cpu.terminate) return;
    // 004848b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004848b4  7550                   -jne 0x484906
    if (!cpu.flags.zf)
    {
        goto L_0x00484906;
    }
    // 004848b6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004848b7  baf09b5900             -mov edx, 0x599bf0
    cpu.edx = 5872624 /*0x599bf0*/;
    // 004848bc  8d9a00060000           -lea ebx, [edx + 0x600]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1536) /* 0x600 */);
L_0x004848c2:
    // 004848c2  8b4207                 -mov eax, dword ptr [edx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 004848c5  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004848c8  39c8                   +cmp eax, ecx
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
    // 004848ca  7507                   -jne 0x4848d3
    if (!cpu.flags.zf)
    {
        goto L_0x004848d3;
    }
    // 004848cc  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004848ce  e8dd330000             -call 0x487cb0
    cpu.esp -= 4;
    sub_487cb0(app, cpu);
    if (cpu.terminate) return;
L_0x004848d3:
    // 004848d3  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004848d6  39da                   +cmp edx, ebx
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
    // 004848d8  75e8                   -jne 0x4848c2
    if (!cpu.flags.zf)
    {
        goto L_0x004848c2;
    }
    // 004848da  8b04cdf0a15900         -mov eax, dword ptr [ecx*8 + 0x59a1f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */ + cpu.ecx * 8);
    // 004848e1  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004848e5  7206                   -jb 0x4848ed
    if (cpu.flags.cf)
    {
        goto L_0x004848ed;
    }
    // 004848e7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004848e9  668b7006               -mov si, word ptr [eax + 6]
    cpu.si = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
L_0x004848ed:
    // 004848ed  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004848ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004848f1  e8aafeffff             -call 0x4847a0
    cpu.esp -= 4;
    sub_4847a0(app, cpu);
    if (cpu.terminate) return;
    // 004848f6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004848f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004848fa  8914cdf0a15900         -mov dword ptr [ecx*8 + 0x59a1f0], edx
    app->getMemory<x86::reg32>(x86::reg32(5874160) /* 0x59a1f0 */ + cpu.ecx * 8) = cpu.edx;
    // 00484901  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484902  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484903  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484904  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484905  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484906:
    // 00484906  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048490b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048490c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048490d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048490e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_484910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484910);
    // 00484910  803d38b84d0000         +cmp byte ptr [0x4db838], 0
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
    // 00484917  740f                   -je 0x484928
    if (cpu.flags.zf)
    {
        goto L_0x00484928;
    }
    // 00484919  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048491c  7f04                   -jg 0x484922
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00484922;
    }
    // 0048491e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00484920  7d0c                   -jge 0x48492e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048492e;
    }
L_0x00484922:
    // 00484922  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00484927  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484928:
    // 00484928  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048492d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048492e:
    // 0048492e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048492f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484930  88152aac4d00           -mov byte ptr [0x4dac2a], dl
    app->getMemory<x86::reg8>(x86::reg32(5090346) /* 0x4dac2a */) = cpu.dl;
    // 00484936  8b0db8ab4d00           -mov ecx, dword ptr [0x4dabb8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */);
    // 0048493c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048493e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484940  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484942  e8a9fbffff             -call 0x4844f0
    cpu.esp -= 4;
    sub_4844f0(app, cpu);
    if (cpu.terminate) return;
    // 00484947  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484949  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048494a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048494b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48494c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048494c);
    // 0048494c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048494d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048494e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484950  eb0b                   -jmp 0x48495d
    goto L_0x0048495d;
L_0x00484952:
    // 00484952  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00484954  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00484956  7409                   -je 0x484961
    if (cpu.flags.zf)
    {
        goto L_0x00484961;
    }
    // 00484958  42                     -inc edx
    (cpu.edx)++;
    // 00484959  4b                     -dec ebx
    (cpu.ebx)--;
    // 0048495a  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0048495c  40                     -inc eax
    (cpu.eax)++;
L_0x0048495d:
    // 0048495d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048495f  75f1                   -jne 0x484952
    if (!cpu.flags.zf)
    {
        goto L_0x00484952;
    }
L_0x00484961:
    // 00484961  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00484963  7407                   -je 0x48496c
    if (cpu.flags.zf)
    {
        goto L_0x0048496c;
    }
    // 00484965  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00484966  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00484969  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048496a  ebf5                   -jmp 0x484961
    goto L_0x00484961;
L_0x0048496c:
    // 0048496c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048496e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048496f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484970  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484971(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484971);
    // 00484971  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484973  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484976  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048497a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048497c  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00484980  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00484983  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00484987  e868b20100             -call 0x49fbf4
    cpu.esp -= 4;
    sub_49fbf4(app, cpu);
    if (cpu.terminate) return;
    // 0048498c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048498f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484990  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484991  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484992(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484992);
    // 00484992  83f861                 +cmp eax, 0x61
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484995  7c08                   -jl 0x48499f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048499f;
    }
    // 00484997  83f87a                 +cmp eax, 0x7a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048499a  7f03                   -jg 0x48499f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048499f;
    }
    // 0048499c  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0048499f:
    // 0048499f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4849a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004849a0);
    // 004849a0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004849a1  9b                     -wait 
    /*nothing*/;
    // 004849a2  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004849a5  9b                     -wait 
    /*nothing*/;
    // 004849a6  ff3424                 -push dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp -= 4;
    // 004849a9  c64424011f             -mov byte ptr [esp + 1], 0x1f
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = 31 /*0x1f*/;
    // 004849ae  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004849b1  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 004849b3  d96c2404               -fldcw word ptr [esp + 4]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004849b7  9b                     -wait 
    /*nothing*/;
    // 004849b8  8d642408               -lea esp, [esp + 8]
    cpu.esp = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004849bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4849c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004849c0);
    // 004849c0  0fb68010914d00         -movzx eax, byte ptr [eax + 0x4d9110]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5083408) /* 0x4d9110 */));
    // 004849c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4849c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004849c8);
    // 004849c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4849c9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004849c9);
    // 004849c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4849d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004849d0);
    // 004849d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004849d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004849d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004849d3  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004849d6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004849d8  8b1dd8b44d00           -mov ebx, dword ptr [0x4db4d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5092568) /* 0x4db4d8 */);
    // 004849de  890d5cb54d00           -mov dword ptr [0x4db55c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5092700) /* 0x4db55c */) = cpu.ecx;
    // 004849e4  39d8                   +cmp eax, ebx
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
    // 004849e6  750c                   -jne 0x4849f4
    if (!cpu.flags.zf)
    {
        goto L_0x004849f4;
    }
    // 004849e8  3b15dcb44d00           +cmp edx, dword ptr [0x4db4dc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5092572) /* 0x4db4dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004849ee  0f8439010000           -je 0x484b2d
    if (cpu.flags.zf)
    {
        goto L_0x00484b2d;
    }
L_0x004849f4:
    // 004849f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004849f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004849f6  a3d8b44d00             -mov dword ptr [0x4db4d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5092568) /* 0x4db4d8 */) = cpu.eax;
    // 004849fb  8915dcb44d00           -mov dword ptr [0x4db4dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5092572) /* 0x4db4dc */) = cpu.edx;
    // 00484a01  e81a180100             -call 0x496220
    cpu.esp -= 4;
    sub_496220(app, cpu);
    if (cpu.terminate) return;
    // 00484a06  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484a08  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00484a0b  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00484a11  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00484a15  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484a17  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00484a1c  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00484a20  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484a22  e8f9170100             -call 0x496220
    cpu.esp -= 4;
    sub_496220(app, cpu);
    if (cpu.terminate) return;
    // 00484a27  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484a29  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484a2b  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 00484a2e  897c2438               -mov dword ptr [esp + 0x38], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edi;
    // 00484a32  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00484a38  897c2434               -mov dword ptr [esp + 0x34], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edi;
    // 00484a3c  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00484a40  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484a42  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00484a47  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00484a4a  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00484a4e  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00484a52  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00484a58  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 00484a5f  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00484a63  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484a65  8d2c9500000000         -lea ebp, [edx*4]
    cpu.ebp = x86::reg32(cpu.edx * 4);
    // 00484a6c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00484a6e  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00484a71  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00484a73  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00484a75  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00484a77  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 00484a7a  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 00484a7d  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00484a7f  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00484a83  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00484a89  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00484a90  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00484a94  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484a96  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484a98  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484a9a  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00484a9d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00484a9f  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00484aa1:
    // 00484aa1  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 00484aa4  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00484aa7  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00484aab  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00484aaf  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00484ab1  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00484ab4  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00484ab8  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00484abc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00484abe  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00484ac1  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00484ac5  037c2424               -add edi, dword ptr [esp + 0x24]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 00484ac9  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00484acd  01442438               -add dword ptr [esp + 0x38], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484ad1  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00484ad5  01442434               -add dword ptr [esp + 0x34], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484ad9  2b74242c               -sub esi, dword ptr [esp + 0x2c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 00484add  2b6c2428               -sub ebp, dword ptr [esp + 0x28]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 00484ae1  2b5c2430               -sub ebx, dword ptr [esp + 0x30]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 00484ae5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00484ae9  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00484aec  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484aee  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00484af2  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00484af6  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00484af9  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00484afd  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00484b01  0b442418               -or eax, dword ptr [esp + 0x18]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00484b05  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484b08  0b442410               -or eax, dword ptr [esp + 0x10]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00484b0c  81c100000010           -add ecx, 0x10000000
    (cpu.ecx) += x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
    // 00484b12  e8c5bfffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 00484b17  8982dcb44d00           -mov dword ptr [edx + 0x4db4dc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5092572) /* 0x4db4dc */) = cpu.eax;
    // 00484b1d  83fa40                 +cmp edx, 0x40
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
    // 00484b20  0f857bffffff           -jne 0x484aa1
    if (!cpu.flags.zf)
    {
        goto L_0x00484aa1;
    }
    // 00484b26  e899d30100             -call 0x4a1ec4
    cpu.esp -= 4;
    sub_4a1ec4(app, cpu);
    if (cpu.terminate) return;
    // 00484b2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484b2d:
    // 00484b2d  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00484b30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_484b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484b40);
    // 00484b40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484b41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484b42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484b43  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00484b45  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00484b47  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00484b49  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00484b4b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00484b4d  7436                   -je 0x484b85
    if (cpu.flags.zf)
    {
        goto L_0x00484b85;
    }
L_0x00484b4f:
    // 00484b4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484b51  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00484b53  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00484b56  8d1c07                 -lea ebx, [edi + eax]
    cpu.ebx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 00484b59  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00484b5e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484b60  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00484b64  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00484b66  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00484b6d  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00484b6f  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00484b71  29c1                   +sub ecx, eax
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00484b73  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484b75  7414                   -je 0x484b8b
    if (cpu.flags.zf)
    {
        goto L_0x00484b8b;
    }
    // 00484b77  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00484b79  7e04                   -jle 0x484b7f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484b7f;
    }
    // 00484b7b  4a                     -dec edx
    (cpu.edx)--;
    // 00484b7c  8d3c33                 -lea edi, [ebx + esi]
    cpu.edi = x86::reg32(cpu.ebx + cpu.esi * 1);
L_0x00484b7f:
    // 00484b7f  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00484b81  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00484b83  75ca                   -jne 0x484b4f
    if (!cpu.flags.zf)
    {
        goto L_0x00484b4f;
    }
L_0x00484b85:
    // 00484b85  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484b87  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b8a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484b8b:
    // 00484b8b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484b8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484b94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484b94);
    // 00484b94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484b95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484b96  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484b97  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484b98  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484b9a  8d48e0                 -lea ecx, [eax - 0x20]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-32) /* -0x20 */);
    // 00484b9d  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00484ba4  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484ba6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00484ba9  8b1530b54d00           -mov edx, dword ptr [0x4db530]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092656) /* 0x4db530 */);
    // 00484baf  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484bb1  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00484bb4  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00484bb9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484bbb  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00484bbf  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00484bc1  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00484bc8  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00484bca  39f0                   +cmp eax, esi
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
    // 00484bcc  7507                   -jne 0x484bd5
    if (!cpu.flags.zf)
    {
        goto L_0x00484bd5;
    }
    // 00484bce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484bd0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bd1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bd3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bd4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484bd5:
    // 00484bd5  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 00484bda  8b1d20b54d00           -mov ebx, dword ptr [0x4db520]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5092640) /* 0x4db520 */);
    // 00484be0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00484be2  e859ffffff             -call 0x484b40
    cpu.esp -= 4;
    sub_484b40(app, cpu);
    if (cpu.terminate) return;
    // 00484be7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484be8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484be9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484beb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484bec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484bec);
    // 00484bec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484bed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484bee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484bef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484bf0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484bf3  8b3554b54d00           -mov esi, dword ptr [0x4db554]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5092692) /* 0x4db554 */);
    // 00484bf9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00484bfb  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00484bfe  a158b54d00             -mov eax, dword ptr [0x4db558]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092696) /* 0x4db558 */);
    // 00484c03  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00484c05  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00484c07  7e26                   -jle 0x484c2f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484c2f;
    }
L_0x00484c09:
    // 00484c09  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484c0b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484c0d  6689fb                 -mov bx, di
    cpu.bx = cpu.di;
    // 00484c10  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00484c14  39d9                   +cmp ecx, ebx
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
    // 00484c16  750f                   -jne 0x484c27
    if (!cpu.flags.zf)
    {
        goto L_0x00484c27;
    }
    // 00484c18  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484c1a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484c1c  668b0c24               -mov cx, word ptr [esp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp);
    // 00484c20  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 00484c23  39cb                   +cmp ebx, ecx
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
    // 00484c25  7412                   -je 0x484c39
    if (cpu.flags.zf)
    {
        goto L_0x00484c39;
    }
L_0x00484c27:
    // 00484c27  42                     -inc edx
    (cpu.edx)++;
    // 00484c28  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00484c2b  39f2                   +cmp edx, esi
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
    // 00484c2d  7cda                   -jl 0x484c09
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484c09;
    }
L_0x00484c2f:
    // 00484c2f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484c31  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484c34  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c35  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c36  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c37  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c38  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484c39:
    // 00484c39  8b4001                 -mov eax, dword ptr [eax + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00484c3c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00484c3f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484c42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484c48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484c48);
    // 00484c48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484c49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484c4a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484c4b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484c4c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484c4d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484c4e  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00484c51  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00484c55  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00484c58  a140b54d00             -mov eax, dword ptr [0x4db540]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092672) /* 0x4db540 */);
    // 00484c5d  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 00484c62  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00484c66  a14cb54d00             -mov eax, dword ptr [0x4db54c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092684) /* 0x4db54c */);
    // 00484c6b  8b35b0b44d00           -mov esi, dword ptr [0x4db4b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5092528) /* 0x4db4b0 */);
    // 00484c71  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00484c75  a150b54d00             -mov eax, dword ptr [0x4db550]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092688) /* 0x4db550 */);
    // 00484c7a  8b15b8b44d00           -mov edx, dword ptr [0x4db4b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092536) /* 0x4db4b8 */);
    // 00484c80  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 00484c84  a158b54d00             -mov eax, dword ptr [0x4db558]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092696) /* 0x4db558 */);
    // 00484c89  8b0dbcb44d00           -mov ecx, dword ptr [0x4db4bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5092540) /* 0x4db4bc */);
    // 00484c8f  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00484c93  a1b4b44d00             -mov eax, dword ptr [0x4db4b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092532) /* 0x4db4b4 */);
    // 00484c98  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484c9a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00484c9c  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00484ca0  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00484ca4  a1b0b44d00             -mov eax, dword ptr [0x4db4b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092528) /* 0x4db4b0 */);
    // 00484ca9  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 00484cad  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00484cb1  a144b54d00             -mov eax, dword ptr [0x4db544]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092676) /* 0x4db544 */);
    // 00484cb6  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00484cb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484cba  0f85fe000000           -jne 0x484dbe
    if (!cpu.flags.zf)
    {
        goto L_0x00484dbe;
    }
L_0x00484cc0:
    // 00484cc0  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 00484cc5  e8cafeffff             -call 0x484b94
    cpu.esp -= 4;
    sub_484b94(app, cpu);
    if (cpu.terminate) return;
    // 00484cca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484ccc  0f85f7000000           -jne 0x484dc9
    if (!cpu.flags.zf)
    {
        goto L_0x00484dc9;
    }
L_0x00484cd2:
    // 00484cd2  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00484cd6  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00484cda  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00484cdc  45                     -inc ebp
    (cpu.ebp)++;
    // 00484cdd  ff54240c               -call dword ptr [esp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484ce1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00484ce3  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00484ce7  83f820                 +cmp eax, 0x20
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
    // 00484cea  0f8efc000000           -jle 0x484dec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484dec;
    }
    // 00484cf0  e89ffeffff             -call 0x484b94
    cpu.esp -= 4;
    sub_484b94(app, cpu);
    if (cpu.terminate) return;
    // 00484cf5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484cf7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00484cf9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484cfb  74d5                   -je 0x484cd2
    if (cpu.flags.zf)
    {
        goto L_0x00484cd2;
    }
    // 00484cfd  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00484d02  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484d05  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00484d09  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00484d0b  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00484d12  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00484d14  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00484d19  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00484d1d  8d4206                 -lea eax, [edx + 6]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 00484d20  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00484d24  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00484d26  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00484d2d  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00484d2f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00484d33  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484d35  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00484d39  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00484d3d  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00484d41  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00484d43  740d                   -je 0x484d52
    if (cpu.flags.zf)
    {
        goto L_0x00484d52;
    }
    // 00484d45  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00484d49  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484d4b  e89cfeffff             -call 0x484bec
    cpu.esp -= 4;
    sub_484bec(app, cpu);
    if (cpu.terminate) return;
    // 00484d50  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00484d52:
    // 00484d52  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 00484d55  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00484d58  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 00484d5b  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00484d5f  8b4707                 -mov eax, dword ptr [edi + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(7) /* 0x7 */);
    // 00484d62  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00484d66  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00484d69  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484d6b  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00484d6f  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00484d73  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00484d75  7561                   -jne 0x484dd8
    if (!cpu.flags.zf)
    {
        goto L_0x00484dd8;
    }
L_0x00484d77:
    // 00484d77  8b1d24b54d00           -mov ebx, dword ptr [0x4db524]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5092644) /* 0x4db524 */);
    // 00484d7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484d7f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484d80  8a4703                 -mov al, byte ptr [edi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 00484d83  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00484d87  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484d88  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484d8a  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00484d8e  8a4702                 -mov al, byte ptr [edi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00484d91  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00484d93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484d94  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00484d98  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00484d9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484d9d  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00484da1  8b1d34b54d00           -mov ebx, dword ptr [0x4db534]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5092660) /* 0x4db534 */);
    // 00484da7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00484da9  8b4c2438               -mov ecx, dword ptr [esp + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00484dad  ff542420               -call dword ptr [esp + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484db1  8b4705                 -mov eax, dword ptr [edi + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 00484db4  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00484db7  01c6                   +add esi, eax
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
    // 00484db9  e914ffffff             -jmp 0x484cd2
    goto L_0x00484cd2;
L_0x00484dbe:
    // 00484dbe  ff1544b54d00           -call dword ptr [0x4db544]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5092676) /* 0x4db544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484dc4  e9f7feffff             -jmp 0x484cc0
    goto L_0x00484cc0;
L_0x00484dc9:
    // 00484dc9  8b4005                 -mov eax, dword ptr [eax + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00484dcc  c1f818                 +sar eax, 0x18
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
    // 00484dcf  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00484dd3  e9fafeffff             -jmp 0x484cd2
    goto L_0x00484cd2;
L_0x00484dd8:
    // 00484dd8  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00484ddc  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00484de0  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00484de4  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00484de6  ff54243c               -call dword ptr [esp + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484dea  eb8b                   -jmp 0x484d77
    goto L_0x00484d77;
L_0x00484dec:
    // 00484dec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484dee  7535                   -jne 0x484e25
    if (!cpu.flags.zf)
    {
        goto L_0x00484e25;
    }
    // 00484df0  833d48b54d0000         +cmp dword ptr [0x4db548], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092680) /* 0x4db548 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484df7  0f8598000000           -jne 0x484e95
    if (!cpu.flags.zf)
    {
        goto L_0x00484e95;
    }
L_0x00484dfd:
    // 00484dfd  a1b8b44d00             -mov eax, dword ptr [0x4db4b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092536) /* 0x4db4b8 */);
    // 00484e02  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00484e06  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00484e08  a1bcb44d00             -mov eax, dword ptr [0x4db4bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092540) /* 0x4db4bc */);
    // 00484e0d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00484e0f  8935b0b44d00           -mov dword ptr [0x4db4b0], esi
    app->getMemory<x86::reg32>(x86::reg32(5092528) /* 0x4db4b0 */) = cpu.esi;
    // 00484e15  8915b4b44d00           -mov dword ptr [0x4db4b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5092532) /* 0x4db4b4 */) = cpu.edx;
    // 00484e1b  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00484e1e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e21  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484e25:
    // 00484e25  83f80a                 +cmp eax, 0xa
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
    // 00484e28  7521                   -jne 0x484e4b
    if (!cpu.flags.zf)
    {
        goto L_0x00484e4b;
    }
    // 00484e2a  8b15c8b44d00           -mov edx, dword ptr [0x4db4c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092552) /* 0x4db4c8 */);
    // 00484e30  8b3dccb44d00           -mov edi, dword ptr [0x4db4cc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5092556) /* 0x4db4cc */);
    // 00484e36  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00484e3a  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00484e3c  01d0                   +add eax, edx
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
    // 00484e3e  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00484e42  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00484e46  e987feffff             -jmp 0x484cd2
    goto L_0x00484cd2;
L_0x00484e4b:
    // 00484e4b  833d60934d0000         +cmp dword ptr [0x4d9360], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084000) /* 0x4d9360 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484e52  7509                   -jne 0x484e5d
    if (!cpu.flags.zf)
    {
        goto L_0x00484e5d;
    }
L_0x00484e54:
    // 00484e54  0374241c               +add esi, dword ptr [esp + 0x1c]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00484e58  e975feffff             -jmp 0x484cd2
    goto L_0x00484cd2;
L_0x00484e5d:
    // 00484e5d  83f809                 +cmp eax, 9
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
    // 00484e60  75f2                   -jne 0x484e54
    if (!cpu.flags.zf)
    {
        goto L_0x00484e54;
    }
    // 00484e62  8b1d5c934d00           -mov ebx, dword ptr [0x4d935c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083996) /* 0x4d935c */);
    // 00484e68  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00484e6a  0f8e62feffff           -jle 0x484cd2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484cd2;
    }
    // 00484e70  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00484e73  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00484e75:
    // 00484e75  a160934d00             -mov eax, dword ptr [0x4d9360]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084000) /* 0x4d9360 */);
    // 00484e7a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00484e7c  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00484e7e  39fe                   +cmp esi, edi
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
    // 00484e80  7d07                   -jge 0x484e89
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00484e89;
    }
    // 00484e82  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00484e84  e949feffff             -jmp 0x484cd2
    goto L_0x00484cd2;
L_0x00484e89:
    // 00484e89  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484e8c  39da                   +cmp edx, ebx
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
    // 00484e8e  7ce5                   -jl 0x484e75
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484e75;
    }
    // 00484e90  e93dfeffff             -jmp 0x484cd2
    goto L_0x00484cd2;
L_0x00484e95:
    // 00484e95  ff1548b54d00           -call dword ptr [0x4db548]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5092680) /* 0x4db548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484e9b  e95dffffff             -jmp 0x484dfd
    goto L_0x00484dfd;
}

/* align: skip  */
void Application::sub_484ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484ea0);
    // 00484ea0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484ea1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484ea3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484ea5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00484ea7  e8bc070000             -call 0x485668
    cpu.esp -= 4;
    sub_485668(app, cpu);
    if (cpu.terminate) return;
    // 00484eac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484eae  e895fdffff             -call 0x484c48
    cpu.esp -= 4;
    sub_484c48(app, cpu);
    if (cpu.terminate) return;
    // 00484eb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484eb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484eb5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484eb5);
    // 00484eb5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484eb6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484eb7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484eb8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484eb9  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00484ebf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00484ec1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00484ec3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00484ec5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484ec6  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00484ecb  2eff1594444c00         -call dword ptr cs:[0x4c4494]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998292) /* 0x4c4494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484ed2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484ed4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484ed6  7507                   -jne 0x484edf
    if (!cpu.flags.zf)
    {
        goto L_0x00484edf;
    }
    // 00484ed8  e845d20100             -call 0x4a2122
    cpu.esp -= 4;
    sub_4a2122(app, cpu);
    if (cpu.terminate) return;
    // 00484edd  eb20                   -jmp 0x484eff
    goto L_0x00484eff;
L_0x00484edf:
    // 00484edf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00484ee1  7520                   -jne 0x484f03
    if (!cpu.flags.zf)
    {
        goto L_0x00484f03;
    }
    // 00484ee3  40                     -inc eax
    (cpu.eax)++;
    // 00484ee4  39c6                   +cmp esi, eax
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
    // 00484ee6  7602                   -jbe 0x484eea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00484eea;
    }
    // 00484ee8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00484eea:
    // 00484eea  e844d20100             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 00484eef  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00484ef1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484ef3  7519                   -jne 0x484f0e
    if (!cpu.flags.zf)
    {
        goto L_0x00484f0e;
    }
    // 00484ef5  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
L_0x00484efa:
    // 00484efa  e821d30100             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
L_0x00484eff:
    // 00484eff  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00484f01  eb28                   -jmp 0x484f2b
    goto L_0x00484f2b;
L_0x00484f03:
    // 00484f03  39f0                   +cmp eax, esi
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
    // 00484f05  7607                   -jbe 0x484f0e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00484f0e;
    }
    // 00484f07  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00484f0c  ebec                   -jmp 0x484efa
    goto L_0x00484efa;
L_0x00484f0e:
    // 00484f0e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00484f10  41                     -inc ecx
    (cpu.ecx)++;
    // 00484f11  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00484f13  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00484f14  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00484f16  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00484f18  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484f19  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484f1b  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00484f1e  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00484f20  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00484f22  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00484f25  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00484f27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f28  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00484f29  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00484f2b:
    // 00484f2b  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00484f31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484f35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484f36(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484f36);
    // 00484f36  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484f37  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484f38  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00484f3b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00484f3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484f3f  7419                   -je 0x484f5a
    if (cpu.flags.zf)
    {
        goto L_0x00484f5a;
    }
    // 00484f41  0440                   -add al, 0x40
    (cpu.al) += x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00484f43  b25c                   -mov dl, 0x5c
    cpu.dl = 92 /*0x5c*/;
    // 00484f45  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 00484f48  88542402               -mov byte ptr [esp + 2], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dl;
    // 00484f4c  b43a                   -mov ah, 0x3a
    cpu.ah = 58 /*0x3a*/;
    // 00484f4e  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00484f50  88642401               -mov byte ptr [esp + 1], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.ah;
    // 00484f54  88742403               -mov byte ptr [esp + 3], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */) = cpu.dh;
    // 00484f58  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x00484f5a:
    // 00484f5a  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00484f5e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484f5f  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00484f63  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484f64  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00484f68  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484f69  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00484f6d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484f6e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484f6f  2eff15a8444c00         -call dword ptr cs:[0x4c44a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998312) /* 0x4c44a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484f76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484f78  7507                   -jne 0x484f81
    if (!cpu.flags.zf)
    {
        goto L_0x00484f81;
    }
    // 00484f7a  e8a3d10100             -call 0x4a2122
    cpu.esp -= 4;
    sub_4a2122(app, cpu);
    if (cpu.terminate) return;
    // 00484f7f  eb1d                   -jmp 0x484f9e
    goto L_0x00484f9e;
L_0x00484f81:
    // 00484f81  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00484f85  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00484f87  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00484f8b  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00484f8e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00484f92  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00484f95  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00484f99  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00484f9c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00484f9e:
    // 00484f9e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00484fa1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484fa2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484fa3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_484fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00484fb0);
    // 00484fb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484fb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484fb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484fb3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00484fb5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00484fb7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484fb9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00484fbb  7e41                   -jle 0x484ffe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484ffe;
    }
L_0x00484fbd:
    // 00484fbd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484fbf  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00484fc1  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00484fc3  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00484fc5  743b                   -je 0x485002
    if (cpu.flags.zf)
    {
        goto L_0x00485002;
    }
    // 00484fc7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484fc9  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00484fcb  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
L_0x00484fce:
    // 00484fce  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00484fd0  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00484fd2  7425                   -je 0x484ff9
    if (cpu.flags.zf)
    {
        goto L_0x00484ff9;
    }
    // 00484fd4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484fd6  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00484fd8  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00484fda  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00484fdc  742f                   -je 0x48500d
    if (cpu.flags.zf)
    {
        goto L_0x0048500d;
    }
    // 00484fde  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 00484fe0  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00484fe3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484fe5  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 00484fe7  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00484fed  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
L_0x00484ff0:
    // 00484ff0  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484ff2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484ff4  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00484ff6  881431                 -mov byte ptr [ecx + esi], dl
    app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1) = cpu.dl;
L_0x00484ff9:
    // 00484ff9  40                     -inc eax
    (cpu.eax)++;
    // 00484ffa  39d8                   +cmp eax, ebx
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
    // 00484ffc  7cbf                   -jl 0x484fbd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484fbd;
    }
L_0x00484ffe:
    // 00484ffe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484fff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485000  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485001  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485002:
    // 00485002  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 00485004  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485006  80e20f                 +and dl, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/))));
    // 00485009  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0048500b  ebc1                   -jmp 0x484fce
    goto L_0x00484fce;
L_0x0048500d:
    // 0048500d  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 0048500f  80e6f0                 -and dh, 0xf0
    cpu.dh &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00485012  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485014  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 00485016  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0048501c  ebd2                   -jmp 0x484ff0
    goto L_0x00484ff0;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485020);
    // 00485020  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x00485021:
    // 00485021  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00485023  40                     -inc eax
    (cpu.eax)++;
    // 00485024  80f9ff                 +cmp cl, 0xff
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
    // 00485027  7506                   -jne 0x48502f
    if (!cpu.flags.zf)
    {
        goto L_0x0048502f;
    }
    // 00485029  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048502a  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048502b  75f4                   -jne 0x485021
    if (!cpu.flags.zf)
    {
        goto L_0x00485021;
    }
    // 0048502d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048502e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048502f:
    // 0048502f  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 00485031  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485032  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00485033  75ec                   -jne 0x485021
    if (!cpu.flags.zf)
    {
        goto L_0x00485021;
    }
    // 00485035  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485036  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_485038(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485038);
    // 00485038  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x00485039:
    // 00485039  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 0048503c  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0048503f  750b                   -jne 0x48504c
    if (!cpu.flags.zf)
    {
        goto L_0x0048504c;
    }
    // 00485041  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485044  83c202                 +add edx, 2
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
    // 00485047  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00485048  75ef                   -jne 0x485039
    if (!cpu.flags.zf)
    {
        goto L_0x00485039;
    }
    // 0048504a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048504b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048504c:
    // 0048504c  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 0048504f  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485052  83c202                 +add edx, 2
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
    // 00485055  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00485056  75e1                   -jne 0x485039
    if (!cpu.flags.zf)
    {
        goto L_0x00485039;
    }
    // 00485058  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485059  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48505c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048505c);
    // 0048505c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048505d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048505e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048505f  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 00485064  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00485066:
    // 00485066  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00485068  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048506a  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0048506e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00485070  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00485077  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00485079  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048507b  750d                   -jne 0x48508a
    if (!cpu.flags.zf)
    {
        goto L_0x0048508a;
    }
    // 0048507d  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00485080  83c203                 +add edx, 3
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00485083  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00485084  75e0                   -jne 0x485066
    if (!cpu.flags.zf)
    {
        goto L_0x00485066;
    }
    // 00485086  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485087  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485088  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485089  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048508a:
    // 0048508a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048508c  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0048508e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00485091  884201                 -mov byte ptr [edx + 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00485094  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00485097  884202                 -mov byte ptr [edx + 2], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0048509a  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048509d  83c203                 +add edx, 3
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004850a0  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004850a1  75c3                   -jne 0x485066
    if (!cpu.flags.zf)
    {
        goto L_0x00485066;
    }
    // 004850a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4850a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004850a8);
    // 004850a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004850a9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x004850aa:
    // 004850aa  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004850ac  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004850ae  c1ee18                 -shr esi, 0x18
    cpu.esi >>= 24 /*0x18*/ % 32;
    // 004850b1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004850b3  750c                   -jne 0x4850c1
    if (!cpu.flags.zf)
    {
        goto L_0x004850c1;
    }
    // 004850b5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004850b8  83c204                 +add edx, 4
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
    // 004850bb  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004850bc  75ec                   -jne 0x4850aa
    if (!cpu.flags.zf)
    {
        goto L_0x004850aa;
    }
    // 004850be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004850c1:
    // 004850c1  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004850c3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004850c6  83c204                 +add edx, 4
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
    // 004850c9  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004850ca  75de                   -jne 0x4850aa
    if (!cpu.flags.zf)
    {
        goto L_0x004850aa;
    }
    // 004850cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4850d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004850d0);
    // 004850d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004850d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004850d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004850d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004850d4  81ec04040000           -sub esp, 0x404
    (cpu.esp) -= x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 004850da  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004850dc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004850de  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004850e0  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004850e3  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 004850e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004850eb  83f804                 +cmp eax, 4
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
    // 004850ee  0f8580000000           -jne 0x485174
    if (!cpu.flags.zf)
    {
        goto L_0x00485174;
    }
    // 004850f4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004850f6:
    // 004850f6  8b0cada0ea5600         -mov ecx, dword ptr [ebp*4 + 0x56eaa0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5696160) /* 0x56eaa0 */ + cpu.ebp * 4);
    // 004850fd  898c2400040000         -mov dword ptr [esp + 0x400], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.ecx;
    // 00485104  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485106  890d80934d00           -mov dword ptr [0x4d9380], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084032) /* 0x4d9380 */) = cpu.ecx;
    // 0048510c  890cada0ea5600         -mov dword ptr [ebp*4 + 0x56eaa0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5696160) /* 0x56eaa0 */ + cpu.ebp * 4) = cpu.ecx;
    // 00485113  83fa08                 +cmp edx, 8
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
    // 00485116  752d                   -jne 0x485145
    if (!cpu.flags.zf)
    {
        goto L_0x00485145;
    }
    // 00485118  803d78904d0010         +cmp byte ptr [0x4d9078], 0x10
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
    // 0048511f  7524                   -jne 0x485145
    if (!cpu.flags.zf)
    {
        goto L_0x00485145;
    }
    // 00485121  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00485123  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00485125  b97b000000             -mov ecx, 0x7b
    cpu.ecx = 123 /*0x7b*/;
    // 0048512a  e8d1fc0000             -call 0x494e00
    cpu.esp -= 4;
    sub_494e00(app, cpu);
    if (cpu.terminate) return;
    // 0048512f  ba5c224a00             -mov edx, 0x4a225c
    cpu.edx = 4858460 /*0x4a225c*/;
    // 00485134  a3f81c5600             -mov dword ptr [0x561cf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5643512) /* 0x561cf8 */) = cpu.eax;
    // 00485139  890d88934d00           -mov dword ptr [0x4d9388], ecx
    app->getMemory<x86::reg32>(x86::reg32(5084040) /* 0x4d9388 */) = cpu.ecx;
    // 0048513f  891580934d00           -mov dword ptr [0x4d9380], edx
    app->getMemory<x86::reg32>(x86::reg32(5084032) /* 0x4d9380 */) = cpu.edx;
L_0x00485145:
    // 00485145  b968934d00             -mov ecx, 0x4d9368
    cpu.ecx = 5084008 /*0x4d9368*/;
    // 0048514a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048514c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048514e  e8d97a0100             -call 0x49cc2c
    cpu.esp -= 4;
    sub_49cc2c(app, cpu);
    if (cpu.terminate) return;
    // 00485153  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485155  8b842400040000         -mov eax, dword ptr [esp + 0x400]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 0048515c  891d88934d00           -mov dword ptr [0x4d9388], ebx
    app->getMemory<x86::reg32>(x86::reg32(5084040) /* 0x4d9388 */) = cpu.ebx;
    // 00485162  8904ada0ea5600         -mov dword ptr [ebp*4 + 0x56eaa0], eax
    app->getMemory<x86::reg32>(x86::reg32(5696160) /* 0x56eaa0 */ + cpu.ebp * 4) = cpu.eax;
    // 00485169  81c404040000           +add esp, 0x404
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1028 /*0x404*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048516f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485170  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485171  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485172  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485173  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485174:
    // 00485174  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 00485179  e978ffffff             -jmp 0x4850f6
    goto L_0x004850f6;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485180);
    // 00485180  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485181  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485182  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00485185  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00485188  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0048518b  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0048518e  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00485191  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00485194  e837ffffff             -call 0x4850d0
    cpu.esp -= 4;
    sub_4850d0(app, cpu);
    if (cpu.terminate) return;
    // 00485199  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048519a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048519b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48519c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048519c);
    // 0048519c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048519d  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004851a0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004851a3  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004851a5  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004851a8  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004851ab  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004851ad  e81effffff             -call 0x4850d0
    cpu.esp -= 4;
    sub_4850d0(app, cpu);
    if (cpu.terminate) return;
    // 004851b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004851b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4851b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004851b4);
    // 004851b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004851b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004851b6  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004851b9  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004851bc  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004851bf  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004851c2  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004851c5  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004851c8  e803ffffff             -call 0x4850d0
    cpu.esp -= 4;
    sub_4850d0(app, cpu);
    if (cpu.terminate) return;
    // 004851cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004851ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004851cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4851d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004851d0);
    // 004851d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004851d1  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004851d4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004851d7  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004851d9  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004851dc  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004851df  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004851e1  e8eafeffff             -call 0x4850d0
    cpu.esp -= 4;
    sub_4850d0(app, cpu);
    if (cpu.terminate) return;
    // 004851e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004851e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4851f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004851f0);
    // 004851f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004851f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004851f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004851f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004851f6  83fb3a                 +cmp ebx, 0x3a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004851f9  0f8486000000           -je 0x485285
    if (cpu.flags.zf)
    {
        goto L_0x00485285;
    }
    // 004851ff  803d48914d0000         +cmp byte ptr [0x4d9148], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083464) /* 0x4d9148 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485206  7426                   -je 0x48522e
    if (cpu.flags.zf)
    {
        goto L_0x0048522e;
    }
    // 00485208  b9fc924d00             -mov ecx, 0x4d92fc
    cpu.ecx = 5083900 /*0x4d92fc*/;
L_0x0048520d:
    // 0048520d  8d0419                 -lea eax, [ecx + ebx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebx * 1);
    // 00485210  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00485212  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00485217  3d80000000             +cmp eax, 0x80
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
    // 0048521c  7c0d                   -jl 0x48522b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048522b;
    }
    // 0048521e  3d90000000             +cmp eax, 0x90
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(144 /*0x90*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485223  7c03                   -jl 0x485228
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485228;
    }
    // 00485225  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
L_0x00485228:
    // 00485228  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
L_0x0048522b:
    // 0048522b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048522c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048522d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048522e:
    // 0048522e  803d2d914d0000         +cmp byte ptr [0x4d912d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083437) /* 0x4d912d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00485235  741e                   -je 0x485255
    if (cpu.flags.zf)
    {
        goto L_0x00485255;
    }
    // 00485237  833d08914d0000         +cmp dword ptr [0x4d9108], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083400) /* 0x4d9108 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048523e  7405                   -je 0x485245
    if (cpu.flags.zf)
    {
        goto L_0x00485245;
    }
    // 00485240  83fb01                 +cmp ebx, 1
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
    // 00485243  7407                   -je 0x48524c
    if (cpu.flags.zf)
    {
        goto L_0x0048524c;
    }
L_0x00485245:
    // 00485245  b9a1924d00             -mov ecx, 0x4d92a1
    cpu.ecx = 5083809 /*0x4d92a1*/;
    // 0048524a  ebc1                   -jmp 0x48520d
    goto L_0x0048520d;
L_0x0048524c:
    // 0048524c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048524e  e84e250100             -call 0x4977a1
    cpu.esp -= 4;
    sub_4977a1(app, cpu);
    if (cpu.terminate) return;
    // 00485253  ebb8                   -jmp 0x48520d
    goto L_0x0048520d;
L_0x00485255:
    // 00485255  803d3a914d0000         +cmp byte ptr [0x4d913a], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083450) /* 0x4d913a */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048525c  7407                   -je 0x485265
    if (cpu.flags.zf)
    {
        goto L_0x00485265;
    }
L_0x0048525e:
    // 0048525e  b9eb914d00             -mov ecx, 0x4d91eb
    cpu.ecx = 5083627 /*0x4d91eb*/;
    // 00485263  eba8                   -jmp 0x48520d
    goto L_0x0048520d;
L_0x00485265:
    // 00485265  803d46914d0000         +cmp byte ptr [0x4d9146], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5083462) /* 0x4d9146 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048526c  75f0                   -jne 0x48525e
    if (!cpu.flags.zf)
    {
        goto L_0x0048525e;
    }
    // 0048526e  833d0c914d0000         +cmp dword ptr [0x4d910c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083404) /* 0x4d910c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00485275  7407                   -je 0x48527e
    if (cpu.flags.zf)
    {
        goto L_0x0048527e;
    }
    // 00485277  b946924d00             -mov ecx, 0x4d9246
    cpu.ecx = 5083718 /*0x4d9246*/;
    // 0048527c  eb8f                   -jmp 0x48520d
    goto L_0x0048520d;
L_0x0048527e:
    // 0048527e  b990914d00             -mov ecx, 0x4d9190
    cpu.ecx = 5083536 /*0x4d9190*/;
    // 00485283  eb88                   -jmp 0x48520d
    goto L_0x0048520d;
L_0x00485285:
    // 00485285  833d0c914d0000         +cmp dword ptr [0x4d910c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083404) /* 0x4d910c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048528c  750e                   -jne 0x48529c
    if (!cpu.flags.zf)
    {
        goto L_0x0048529c;
    }
    // 0048528e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00485293  890d0c914d00           -mov dword ptr [0x4d910c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083404) /* 0x4d910c */) = cpu.ecx;
    // 00485299  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048529a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048529b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048529c:
    // 0048529c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048529e  890d0c914d00           -mov dword ptr [0x4d910c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083404) /* 0x4d910c */) = cpu.ecx;
    // 004852a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004852a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004852a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4852a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004852a8);
    // 004852a8  e8f3b1ffff             -call 0x4804a0
    cpu.esp -= 4;
    sub_4804a0(app, cpu);
    if (cpu.terminate) return;
    // 004852ad  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004852b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4852b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004852b4);
    // 004852b4  e8e7b1ffff             -call 0x4804a0
    cpu.esp -= 4;
    sub_4804a0(app, cpu);
    if (cpu.terminate) return;
    // 004852b9  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 004852be  e955d00100             -jmp 0x4a2318
    return sub_4a2318(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4852c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004852c4);
    // 004852c4  a38c934d00             -mov dword ptr [0x4d938c], eax
    app->getMemory<x86::reg32>(x86::reg32(5084044) /* 0x4d938c */) = cpu.eax;
    // 004852c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4852cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004852cc);
    // 004852cc  833d8c934d0000         +cmp dword ptr [0x4d938c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084044) /* 0x4d938c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004852d3  7503                   -jne 0x4852d8
    if (!cpu.flags.zf)
    {
        goto L_0x004852d8;
    }
    // 004852d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004852d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004852d8:
    // 004852d8  ff158c934d00           -call dword ptr [0x4d938c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5084044) /* 0x4d938c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004852de  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
